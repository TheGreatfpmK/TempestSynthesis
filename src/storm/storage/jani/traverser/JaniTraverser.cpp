#include "storm/storage/jani/traverser/JaniTraverser.h"


namespace storm {
    namespace jani {
        void JaniTraverser::traverse(Model const& model, boost::any& data) const {
            for (auto const& act : model.getActions()) {
                traverse(act, data);
            }
            for (auto const& c : model.getConstants()) {
                traverse(c, data);
            }
            traverse(model.getGlobalVariables(), data);
            for (auto const& aut : model.getAutomata()) {
                traverse(aut, data);
            }
            traverse(model.getInitialStatesRestriction(), data);
        }
        
        void JaniTraverser::traverse(Action const& action, boost::any& data) const {
            // Intentionally left empty.
        }
            
        void JaniTraverser::traverse(Automaton const& automaton, boost::any& data) const {
            traverse(automaton.getVariables(), data);
            for (auto const& loc : automaton.getLocations()) {
                traverse(loc, data);
            }
            traverse(automaton.getEdgeContainer(), data);
            traverse(automaton.getInitialStatesRestriction(), data);
        }
            
        void JaniTraverser::traverse(Constant const& constant, boost::any& data) const {
            traverse(constant.getExpression(), data);
        }
            
        void JaniTraverser::traverse(VariableSet const& variableSet, boost::any& data) const {
            for (auto const& v : variableSet.getBooleanVariables()) {
                traverse(v, data);
            }
            for (auto const& v : variableSet.getBoundedIntegerVariables()) {
                traverse(v, data);
            }
            for (auto const& v : variableSet.getUnboundedIntegerVariables()) {
                traverse(v, data);
            }
            for (auto const& v : variableSet.getRealVariables()) {
                traverse(v, data);
            }
        }
            
        void JaniTraverser::traverse(Location const& location, boost::any& data) const {
            traverse(location.getAssignments(), data)
        }
            
        void JaniTraverser::traverse(BooleanVariable const& variable, boost::any& data) const {
            if (variable.hasInitExpression()) {
                traverse(variable.getInitExpression());
            }
        }
        
        void JaniTraverser::traverse(BoundedIntegerVariable const& variable, boost::any& data) const {
            if (variable.hasInitExpression()) {
                traverse(variable.getInitExpression());
            }
            traverse(variable.getLowerBound());
            traverse(variable.getUpperBound());
        }
        
        void JaniTraverser::traverse(UnboundedIntegerVariable const& variable, boost::any& data) const {
            if (variable.hasInitExpression()) {
                traverse(variable.getInitExpression());
            }
        }
        
        void JaniTraverser::traverse(RealVariable const& variable, boost::any& data) const {
             if (variable.hasInitExpression()) {
                traverse(variable.getInitExpression());
            }
        }
        
        void JaniTraverser::traverse(EdgeContainer const& edgeContainer, boost::any& data) const {
            for (auto const& templateEdge : edgeContainer.getTemplateEdges()) {
                traverse(templateEdge, data);
            }
            for (auto const& concreteEdge : edgeContainer.getConcreteEdges()) {
                traverse(concreteEdge, data);
            }
        }
        
        void JaniTraverser::traverse(TemplateEdge const& templateEdge, boost::any& data) const {
            traverse(templateEdge.getGuard(), data);
            for (auto const& dest : templateEdge.getDestinations()) {
                traverse(dest, data);
            }
            traverse(templateEdge.getAssignments(), data);
        }
            
        void JaniTraverser::traverse(TemplateEdgeDestination const& templateEdgeDestination, boost::any& data) const {
            traverse(templateEdgeDestination.getOrderedAssignments(), data);
        }
            
        void JaniTraverser::traverse(Edge const& edge, boost::any& data) const {
            traverse(edge.getRate(), data);
            for (auto const& dest : edge.getDestinations()) {
                traverse(dest, data);
            }
        }
            
        void JaniTraverser::traverse(EdgeDestination const& edgeDestination, boost::any& data) const {
            traverse(edgeDestination.getProbability());
        }
            
        void JaniTraverser::traverse(OrderedAssignments const& orderedAssignments, boost::any& data) const {
            for (auto const& assignment : orderedAssignments) {
                traverse(assignment, data);
            }
        }
            
        void JaniTraverser::traverse(Assignment const& assignment, boost::any& data) const {
            traverse(assignment.getAssignedExpression(), data);
        }
            
        void JaniTraverser::traverse(storm::expressions::Expression const& expression, boost::any& data) const {
            // intentionally left empty.
        }
                
    }
}

