#ifndef STORM_MODELCHECKER_SPARSESMGRPATLMODELCHECKER_H_
#define STORM_MODELCHECKER_SPARSESMGRPATLMODELCHECKER_H_

#include "storm/modelchecker/propositional/SparsePropositionalModelChecker.h"
#include "storm/models/sparse/Smg.h"
#include "storm/utility/solver.h"
#include "storm/solver/LinearEquationSolver.h"
#include "storm/storage/StronglyConnectedComponent.h"

namespace storm {
    namespace modelchecker {

        template<class SparseSmgModelType>
        class SparseSmgRpatlModelChecker : public SparsePropositionalModelChecker<SparseSmgModelType> {
        public:
            typedef typename SparseSmgModelType::ValueType ValueType;
            typedef typename SparseSmgModelType::RewardModelType RewardModelType;

            explicit SparseSmgRpatlModelChecker(SparseSmgModelType const& model);

            /*!
             * Returns false, if this task can certainly not be handled by this model checker (independent of the concrete model).
             * @param requiresSingleInitialState if not nullptr, this flag is set to true iff checking this formula requires a model with a single initial state
             */
            static bool canHandleStatic(CheckTask<storm::logic::Formula, ValueType> const& checkTask, bool* requiresSingleInitialState = nullptr);

            // The implemented methods of the AbstractModelChecker interface.
            virtual bool canHandle(CheckTask<storm::logic::Formula, ValueType> const& checkTask) const override;
            virtual std::unique_ptr<CheckResult> checkGameFormula(Environment const& env, CheckTask<storm::logic::GameFormula, ValueType> const& checkTask) override;
            virtual std::unique_ptr<CheckResult> checkRewardOperatorFormula(Environment const& env, CheckTask<storm::logic::RewardOperatorFormula, ValueType> const& checkTask) override;

            virtual std::unique_ptr<CheckResult> computeLongRunAverageProbabilities(Environment const& env, CheckTask<storm::logic::StateFormula, ValueType> const& checkTask) override;
            virtual std::unique_ptr<CheckResult> computeLongRunAverageRewards(Environment const& env, storm::logic::RewardMeasureType rewardMeasureType, CheckTask<storm::logic::LongRunAverageRewardFormula, ValueType> const& checkTask) override;

            void coalitionIndicator(Environment& env, CheckTask<storm::logic::GameFormula, ValueType> const& checkTask);
        };
    } // namespace modelchecker
} // namespace storm

#endif /* STORM_MODELCHECKER_SPARSESMGRPATLMODELCHECKER_H_ */
