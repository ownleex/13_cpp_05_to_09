/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:51:41 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/29 23:15:23 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    // Constructeurs et destructeur
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& src);
    ~Bureaucrat();
    
    // Opérateur d'affectation
    Bureaucrat& operator=(const Bureaucrat& rhs);
    
    // Getters
    const std::string& getName() const;
    int getGrade() const;
    
    // Fonctions de modification du grade
    void incrementGrade();
    void decrementGrade();
    
    // Classes d'exception
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// Surcharge de l'opérateur de flux
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif