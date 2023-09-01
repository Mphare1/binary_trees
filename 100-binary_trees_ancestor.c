#include "binary_trees.h"

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mom, *pops;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mom = first->parent, pops = second->parent;
  
	if (first == pops || !mom || (!mom->parent && pops))
		return (binary_trees_ancestor(first, pops));
	else if (mom == second || !pops || (!pops->parent && mom))
		return (binary_trees_ancestor(mom, second));
	return (binary_trees_ancestor(mom, pops));
}
