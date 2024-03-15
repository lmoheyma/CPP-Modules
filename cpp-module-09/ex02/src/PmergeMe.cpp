/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 04:45:09 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/15 05:16:06 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Separer le vecteur en 2 veteurs égaux
    // Rappeller la fonction pour chacun des parties tant que le vecteur n'est pas trié
    // Un vecteur de taille 1 est forcement trié donc on continue tant que la taille du vecteur est > 1
    // Une fois que les deux vecteurs sont triés, on appelle la fonction de fusion (merge)
// Recuperer les tailles de left et right
// Comparer les valeurs de left[i] et right[j] -> le min est push dans res
// Verifier si il reste des valeurs dans les vecteurs et les push, puis retourner res (vector)

//Faire la meme chose avec des listes