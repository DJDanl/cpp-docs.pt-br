---
title: Expressões primárias | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- primary expressions
- expressions [C++], name
- expressions [C++], literal
- expressions [C++], primary
- expressions [C++], qualified names
ms.assetid: 8ef9a814-6058-4b93-9b6e-e8eb8350b1ca
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3a178510c02cd7ae0238686c6ff6634466715ddf
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39408340"
---
# <a name="primary-expressions"></a>Expressões primárias
As expressões primárias são os blocos de construção de expressões mais complexas. Elas são literais, nomes e nomes qualificados pelo operador de resolução de escopo (`::`).  Uma expressão primária pode ter qualquer uma das seguintes formas:  
  
```  
literal  
this
name  
::name ( expression )  
```  
  
 Um *literal* é uma expressão primária constante. Seu tipo depende da forma de sua especificação. Ver [literais](../cpp/numeric-boolean-and-pointer-literals-cpp.md) para obter informações completas sobre como especificar literais.  
  
 O **isso** palavra-chave é um ponteiro para um objeto de classe. Ela está disponível nas funções membro não estáticas e aponta para a instância da classe para a qual a função foi invocada. O **isso** palavra-chave não pode ser usado fora do corpo de uma função de membro de classe.  
  
 O tipo dos **isso** ponteiro é `type`  **\*const** (onde `type` é o nome de classe) dentro de funções que não modificam especificamente o **este** ponteiro. O exemplo a seguir mostra o membro de declarações de função e os tipos de **isso**:  
  
```cpp 
// expre_Primary_Expressions.cpp  
// compile with: /LD  
class Example  
{  
public:  
    void Func();          //  * const this  
    void Func() const;    //  const * const this  
    void Func() volatile; //  volatile * const this  
};  
```  
  
 Ver [esse ponteiro](this-pointer.md) para obter mais informações sobre como modificar o tipo dos **isso** ponteiro.  
  
 O operador de resolução de escopo (`::`) seguido por um nome constitui uma expressão primária.  Tais nomes devem estar no escopo global, não em nomes de membro.  O tipo dessa expressão é determinado pela declaração do nome. Será um l-value (isto é, pode aparecer à esquerda de uma expressão de operador de atribuição) se o nome declarativo for um l-value. O operador de resolução de escopo permite que um nome global seja referenciado, mesmo se esse nome estiver oculto no escopo atual. Ver [escopo](../cpp/scope-visual-cpp.md) para obter um exemplo de como usar o operador de resolução de escopo.  
  
 Uma expressão entre parênteses é uma expressão primária cujo tipo e valor são idênticos aos da expressão fora dos parênteses. Será um l-value se a expressão fora dos parênteses for um l-value.  
  
 Os exemplos de expressões primárias incluem:  
  
```cpp 
100 // literal  
'c' // literal  
this // in a member function, a pointer to the class instance  
::func // a global function  
::operator + // a global operator function  
::A::B // a global qualified name  
( i + 1 ) // a parenthesized expression  
```  
  
 Os exemplos a seguir são considerados *nomes*, primárias, portanto, expressões e, em várias formas:  
  
```cpp 
MyClass // a identifier  
MyClass::f // a qualified name  
operator = // an operator function name  
operator char* // a conversion operator function name  
~MyClass // a destructor name  
A::B   // a qualified name  
A<int> // a template id  
```  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de expressões](../cpp/types-of-expressions.md)