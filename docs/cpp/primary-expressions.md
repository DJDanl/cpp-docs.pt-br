---
title: "Express&#245;es prim&#225;rias | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "expressões [C++], literal"
  - "expressões [C++], nome"
  - "expressões [C++], primários"
  - "expressões [C++], nomes qualificados"
  - "expressões primárias"
ms.assetid: 8ef9a814-6058-4b93-9b6e-e8eb8350b1ca
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Express&#245;es prim&#225;rias
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As expressões primárias são os blocos de construção de expressões mais complexas.  Elas são literais, nomes e nomes qualificados pelo operador de resolução de escopo \(`::`\).  Uma expressão primária pode ter qualquer uma das seguintes formas:  
  
```  
  
        literal  
this  
:: name  
name   
( expression )  
```  
  
 Um *literal* é uma expressão primária constante.  Seu tipo depende da forma de sua especificação.  Consulte [Literais](../cpp/numeric-boolean-and-pointer-literals-cpp.md) para obter informações completas sobre como especificar literais.  
  
 A palavra\-chave **this** é um ponteiro para um objeto de classe.  Ela está disponível nas funções membro não estáticas e aponta para a instância da classe para a qual a função foi invocada.  A palavra\-chave **this** não pode ser usada fora do corpo de uma função membro de classe.  
  
 O tipo do ponteiro **this** é `type` **\*const** \(em que `type` é o nome da classe\) com funções que não modificam especificamente o ponteiro **this**.  O exemplo a seguir mostra declarações de função membro e os tipos de **this**:  
  
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
  
 Consulte [Tipo desse ponteiro](../misc/type-of-this-pointer.md) para obter mais informações sobre como modificar o tipo do ponteiro **this**.  
  
 O operador de resolução de escopo \(`::`\) seguido por um nome constitui uma expressão primária.  Tais nomes devem estar no escopo global, não em nomes de membro.  O tipo dessa expressão é determinado pela declaração do nome.  Será um l\-value \(isto é, pode aparecer à esquerda de uma expressão de operador de atribuição\) se o nome declarativo for um l\-value.  O operador de resolução de escopo permite que um nome global seja referenciado, mesmo se esse nome estiver oculto no escopo atual.  Consulte [Escopo](../cpp/scope-visual-cpp.md) para obter um exemplo de como usar o operador de resolução de escopo.  
  
 Uma expressão entre parênteses é uma expressão primária cujo tipo e valor são idênticos aos da expressão fora dos parênteses.  Será um l\-value se a expressão fora dos parênteses for um l\-value.  
  
 No contexto da sintaxe da expressão primária fornecida acima, *name* significa qualquer coisa na sintaxe descrita para [Nomes](http://msdn.microsoft.com/pt-br/1c49cc24-08d5-4884-b170-ba8ed42d80db), embora ao usar o operador de resolução de escopo antes do nome, os tipos de nome que podem ocorrer apenas em uma classe não são permitidos.  Isso inclui os nomes de função de conversão definida pelo usuário e nomes de destruidor.  
  
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
  
 Os exemplos abaixo são todos *names* considerados e, portanto, expressões primárias, em várias formas:  
  
```  
MyClass // a identifier  
MyClass::f // a qualified name  
operator = // an operator function name  
operator char* // a conversion operator function name  
~MyClass // a destructor name  
A::B   // a qualified name  
A<int> // a template id  
```  
  
## Consulte também  
 [Tipos de expressões](../cpp/types-of-expressions.md)