#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm
{
public:
    AForm();
    AForm(const std::string& name, const std::string& target,
        int signGrade, int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string& getName() const;
    const std::string& getTarget() const;
    bool               getIsSigned() const;
    int                getSignGrade() const;
    int                getExecGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);
    void execute(Bureaucrat const& executor) const;

    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
    public:
        const char* what() const throw();
    };

protected:
    // Each concrete form provides its own execution behavior here.
    virtual void executeAction() const = 0;

private:
    const std::string _name;
    const std::string _target;
    bool              _isSigned;
    const int         _signGrade;
    const int         _execGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
