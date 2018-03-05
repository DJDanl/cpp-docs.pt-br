---
title: "Visão geral das funções de membro | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- this pointer, and nonstatic member functions
- nonstatic member functions [C++]
- inline functions [C++], treating member functions as
- member functions [C++], definition in class declaration
ms.assetid: 9f77a438-500e-40bb-a6c6-544678f3f4c8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6389197119135e7e800a4f5ec142bf42b1ef6d39
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="overview-of-member-functions"></a>Visão geral das funções de membro
As funções membro são estáticas ou não estáticas. O comportamento de funções de membro estático é diferente de outras funções de membro porque funções membro static tem implícita não **isso** argumento. Funções de membro não estático têm um **isso** ponteiro. As funções membro, sejam elas estáticas ou não estáticas, podem ser definidas dentro ou fora da declaração da classe.  
  
 Se uma função membro for definida dentro de uma declaração de classe, ela será tratada como uma função embutida, e não há necessidade de qualificar o nome da função com o nome da sua classe. Embora as funções definidas dentro de declarações de classe já são tratadas como funções embutidas, você pode usar o **embutido** palavra-chave para o código do documento.  
  
 Este é um exemplo de declaração de uma função dentro de uma declaração de classe:  
  
```  
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
  
 Se a definição da função um membro está fora da declaração de classe, ele é tratado como uma função embutida somente se ele é declarado explicitamente como **embutido**. Além disso, o nome da função na definição deve ser qualificado com o nome da sua classe usando o operador de resolução de escopo (`::`).  
  
 O exemplo a seguir é idêntico à declaração de classe `Account`anterior, com exceção da função `Deposit`, que é definida fora de declaração da classe:  
  
```  
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
  
