---
title: "Expressões primárias | Microsoft Docs"
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
- primary expressions
- expressions [C++], name
- expressions [C++], literal
- expressions [C++], primary
- expressions [C++], qualified names
ms.assetid: 8ef9a814-6058-4b93-9b6e-e8eb8350b1ca
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0a6e811e1fe074ce488b09fca29926989bc7f355
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="primary-expressions"></a>Expressões primárias
As expressões primárias são os blocos de construção de expressões mais complexas. Elas são literais, nomes e nomes qualificados pelo operador de resolução de escopo (`::`).  Uma expressão primária pode ter qualquer uma das seguintes formas:  
  
```  
  
      literal  
      this  
:: namename( expression )  
```  
  
 Um *literal* é uma expressão de constante primária. Seu tipo depende da forma de sua especificação. Consulte [literais](../cpp/numeric-boolean-and-pointer-literals-cpp.md) para obter informações completas sobre como especificar literais.  
  
 O **isso** palavra-chave é um ponteiro para um objeto de classe. Ela está disponível nas funções membro não estáticas e aponta para a instância da classe para a qual a função foi invocada. O **isso** palavra-chave não pode ser usado fora do corpo de uma função de membro de classe.  
  
 O tipo do **isso** ponteiro é `type`  **\*const** (onde `type` é o nome de classe) em funções não especificamente modificando o **este** ponteiro. O exemplo a seguir mostra o membro declarações de função e os tipos de **isso**:  
  
```  
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
  
 Consulte [esse ponteiro](this-pointer.md) para obter mais informações sobre como modificar o tipo do **isso** ponteiro.  
  
 O operador de resolução de escopo (`::`) seguido por um nome constitui uma expressão primária.  Tais nomes devem estar no escopo global, não em nomes de membro.  O tipo dessa expressão é determinado pela declaração do nome. Será um l-value (isto é, pode aparecer à esquerda de uma expressão de operador de atribuição) se o nome declarativo for um l-value. O operador de resolução de escopo permite que um nome global seja referenciado, mesmo se esse nome estiver oculto no escopo atual. Consulte [escopo](../cpp/scope-visual-cpp.md) para obter um exemplo de como usar o operador de resolução do escopo.  
  
 Uma expressão entre parênteses é uma expressão primária cujo tipo e valor são idênticos aos da expressão fora dos parênteses. Será um l-value se a expressão fora dos parênteses for um l-value.  
  
 No contexto da sintaxe de expressão primária acima, *nome* significa qualquer coisa a sintaxe descrita para [nomes](http://msdn.microsoft.com/en-us/1c49cc24-08d5-4884-b170-ba8ed42d80db), embora quando usando o operador de resolução do escopo antes do nome, tipos de nomes que só pode ocorrer em uma classe não são permitidas.  Isso inclui os nomes de função de conversão definida pelo usuário e nomes de destruidor.  
  
 Os exemplos de expressões primárias incluem:  
  
```  
100 // literal  
'c' // literal  
this // in a member function, a pointer to the class instance  
::func // a global function  
::operator + // a global operator function  
::A::B // a global qualified name  
( i + 1 ) // a parenthesized expression  
```  
  
 Os exemplos a seguir são considerados *nomes*e, portanto, primárias expressões, de várias formas:  
  
```  
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