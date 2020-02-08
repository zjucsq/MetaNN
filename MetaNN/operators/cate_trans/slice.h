#pragma once

#include <MetaNN/data/facilities/traits.h>
#include <MetaNN/evaluate/eval_plan.h>
#include <MetaNN/operators/facilities/tail_calculator.h>
#include <cassert>
#include <type_traits>

namespace MetaNN::OpTags
{
    struct Slice;
}

namespace MetaNN
{
namespace OperSlice::NSCaseGen
{
    template <typename TInputHandle, typename TOutputHandle>
    class EvalItem : public BaseEvalItem<DeviceTypeFromHandle<TOutputHandle>>
    {
        using BaseType = BaseEvalItem<DeviceTypeFromHandle<TOutputHandle>>;
    public:
        using CategoryTag = CategoryTagFromHandle<TOutputHandle>;

        template <typename TAuxParams>
        EvalItem(TInputHandle oriHandle, TOutputHandle outputHandle, const Shape<CategoryTag::DimNum>&, const TAuxParams& p_params)
            : BaseType(std::type_index(typeid(EvalItem)),
                       {oriHandle.DataPtr()}, outputHandle.DataPtr())
            , m_inputHandle(std::move(oriHandle))
            , m_id(p_params.m_elemID)
            , m_outputHandle(std::move(outputHandle))
        {}

        const TInputHandle m_inputHandle;
        const size_t m_id;
        TOutputHandle m_outputHandle;
    };

    template <typename TInputHandle, typename TOutputHandle>
    class EvalGroup : public TrivalEvalGroup<EvalItem<TInputHandle, TOutputHandle>>
    {
        using EvalItemType = EvalItem<TInputHandle, TOutputHandle>;
    protected:
        virtual void EvalInternalLogic(EvalItemType& evalItem) final override
        {
            const auto& in = evalItem.m_inputHandle.Data();
            evalItem.m_outputHandle.SetData(in[evalItem.m_id]);
        }
    };
}

    template <typename TPolicy, typename TOperand>
    struct OperCategory_<OpTags::Slice, TPolicy, TOperand>
    {
        using type = CategoryTags::Tensor<TOperand::DimNum - 1>;
    };
    
    template <typename TCate>
    struct OperAuxParams<OpTags::Slice, TCate>
    {
        OperAuxParams(size_t p_elemID)
            : m_elemID(p_elemID) {}
        
        const size_t m_elemID;
        
        bool operator == (const OperAuxParams& val) const
        {
            return (m_elemID == val.m_elemID);
        }
    };
    
    template <typename TCate, typename TPolicies>
    class OperShapeInfo<OpTags::Slice, TCate, TPolicies>
    {
    public:
        template <typename TOperand>
        OperShapeInfo(const OperAuxParams<OpTags::Slice, TCate>&, const TOperand& operand)
        {
            static_assert(TCate::DimNum + 1 == DataCategory<TOperand>::DimNum);
            if constexpr (TCate::DimNum != 0)
            {
                for (size_t i = 0; i < TCate::DimNum; ++i)
                {
                    m_shape[i] = operand.Shape()[i + 1];
                }
            }
        }
    
        const auto& Shape() const
        {
            return m_shape;
        }
    
    private:
        MetaNN::Shape<TCate::DimNum> m_shape;
    };
    
    template <>
    struct OperSeq_<OpTags::Slice>
    {
        using type = OperCalAlgoChain<TailCalculator<OperSlice::NSCaseGen::EvalItem, OperSlice::NSCaseGen::EvalGroup>>;
    };
}