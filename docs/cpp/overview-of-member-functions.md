---
title: Visão geral das funções de membro
ms.date: 11/04/2016
helpviewer_keywords:
- this pointer, and nonstatic member functions
- nonstatic member functions [C++]
- inline functions [C++], treating member functions as
- member functions [C++], definition in class declaration
ms.assetid: 9f77a438-500e-40bb-a6c6-544678f3f4c8
ms.openlocfilehash: d1c3e069325363276e58a617d6ba21cb0b6e4ff0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188461"
---
# <a name="overview-of-member-functions"></a>Visão geral das funções de membro

As funções membro são estáticas ou não estáticas. O comportamento de funções de membro estáticos difere de outras funções de membro porque as funções de membro static não têm **nenhum argumento implícito** . Funções **de membro** não static têm um ponteiro. As funções membro, sejam elas estáticas ou não estáticas, podem ser definidas dentro ou fora da declaração da classe.

Se uma função membro for definida dentro de uma declaração de classe, ela será tratada como uma função embutida, e não há necessidade de qualificar o nome da função com o nome da sua classe. Embora as funções definidas nas declarações de classe já sejam tratadas como funções embutidas, você pode usar a palavra-chave **inline** para documentar o código.

Este é um exemplo de declaração de uma função dentro de uma declaração de classe:

```cpp
// overview_of_member_functions1.cpp
class Account
{
public:
    // Declare the member function Deposit within the declaration
    //  of class Account.
    double Deposit( double HowMuch )
    {
        balance += HowMuch;
        return balance;
    }
private:
    double balance;
};

int main()
{
}
```

Se a definição de uma função de membro estiver fora da declaração de classe, ela será tratada como uma função embutida somente se ela for explicitamente declarada como **embutida**. Além disso, o nome da função na definição deve ser qualificado com o nome da sua classe usando o operador de resolução de escopo (`::`).

O exemplo a seguir é idêntico à declaração de classe `Account`anterior, com exceção da função `Deposit`, que é definida fora de declaração da classe:

```cpp
// overview_of_member_functions2.cpp
class Account
{
public:
    // Declare the member function Deposit but do not define it.
    double Deposit( double HowMuch );
private:
    double balance;
};

inline double Account::Deposit( double HowMuch )
{
    balance += HowMuch;
    return balance;
}

int main()
{
}
```

> [!NOTE]
>  Embora as funções membro possam ser definidas dentro de uma declaração de classe ou separadamente, nenhuma função membro pode ser adicionada a uma classe depois que a classe é definida.

As classes que contêm funções membro podem ter muitas declarações, mas as próprias funções membro devem ter apenas uma definição em um programa. Várias definições geram uma mensagem de erro em tempo de vinculação. Se uma classe contiver definições de função embutidas, as definições de função devem ser idênticas para observar a regra de "uma definição".
