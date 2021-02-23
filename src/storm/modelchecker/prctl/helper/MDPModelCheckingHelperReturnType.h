#ifndef MDPMODELCHECKINGHELPERRETURNTYPE_H
#define	MDPMODELCHECKINGHELPERRETURNTYPE_H

#include <vector>
#include <memory>
#include "storm/storage/Scheduler.h"

namespace storm {
    namespace storage {
        class BitVector;
    }

    namespace modelchecker {
        namespace helper {
            template<typename ValueType>
            struct MDPSparseModelCheckingHelperReturnType {

                MDPSparseModelCheckingHelperReturnType(MDPSparseModelCheckingHelperReturnType const&) = delete;
                MDPSparseModelCheckingHelperReturnType(MDPSparseModelCheckingHelperReturnType&&) = default;

                MDPSparseModelCheckingHelperReturnType(std::vector<ValueType>&& values, std::unique_ptr<storm::storage::Scheduler<ValueType>>&& scheduler = nullptr) : values(std::move(values)), scheduler(std::move(scheduler)) {
                    // Intentionally left empty.
                }

                virtual ~MDPSparseModelCheckingHelperReturnType() {
                    // Intentionally left empty.
                }

                // The values computed for the states.
                std::vector<ValueType> values;

                // The values computed for the available choices.
                std::vector<ValueType> choiceValues;

                // A scheduler, if it was computed.
                std::unique_ptr<storm::storage::Scheduler<ValueType>> scheduler;
            };
        }

    }
}

#endif	/* MDPMODELCHECKINGRETURNTYPE_H */
