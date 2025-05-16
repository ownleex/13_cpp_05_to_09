/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:21:24 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/16 23:07:36 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
public:
    // Constructeurs et destructeur
    Intern();
    Intern(const Intern& src);
    ~Intern();
    
    // Opérateur d'affectation
    Intern& operator=(const Intern& rhs);
    
    // Méthode pour créer un formulaire
    AForm* makeForm(const std::string& formName, const std::string& target);
    
    // Exception personnalisée
    class InvalidForm : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif