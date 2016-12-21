---
title: "Operador typeid | Microsoft Docs"
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
  - "Operador typeid"
ms.assetid: 8871cee6-d6b9-4301-a5cb-bf3dc9798d61
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador typeid
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
      typeid(   
      type-id  
       )  
typeid( expression )  
```  
  
## Comentários  
 O operador `typeid` permite que o tipo de um objeto seja determinado em tempo de execução.  
  
 O resultado de `typeid` é **const type\_info&**.  O valor é uma referência a um objeto **type\_info** que representa o *type\-ID* ou o tipo da *expressão*, dependendo do formato de `typeid` usado.  Consulte a [classe type\_info](../cpp/type-info-class.md) para obter mais informações.  
  
 O operador `typeid` não funciona com tipos gerenciados \(declarators abstratos ou instâncias\). Consulte [typeid](../Topic/typeid%20%20\(C++%20Component%20Extensions\).md) para obter informações sobre como obter <xref:System.Type> de um tipo especificado.  
  
 O operador `typeid` faz uma verificação de tempo de execução quando aplicado a um l\-value de um tipo de classe polimórfica, onde o tipo true de objeto não pode ser determinado pelas informações estáticas fornecidas.  Tais casos são:  
  
-   Uma referência à classe  
  
-   Um ponteiro, desreferenciado com \*  
  
-   Um ponteiro subscrito \(isto é, \[\]\). \(Geralmente, não é seguro usar um subscrito com um ponteiro para um tipo polimórfico.\)  
  
 Se a *expressão* aponta para um tipo de classe base, mas o objeto é na realidade um tipo derivado dessa classe base, uma referência a **type\_info** para a classe derivada é o resultado.  A *expressão* deve apontar para um tipo polimórfico \(uma classe com funções virtuais\).  Caso contrário, o resultado será **type\_info** para a classe estática referenciada na *expressão*.  Além disso, o ponteiro deve ser desreferenciado de forma que o objeto para o qual ele aponta seja usado.  Sem desreferenciar o ponteiro, o resultado será **type\_info** para o ponteiro, não para o que ele aponta.  Por exemplo:  
  
```  
// expre_typeid_Operator.cpp  
// compile with: /GR /EHsc  
#include <iostream>  
#include <typeinfo.h>  
  
class Base {  
public:  
   virtual void vvfunc() {}  
};  
  
class Derived : public Base {};  
  
using namespace std;  
int main() {  
   Derived* pd = new Derived;  
   Base* pb = pd;  
   cout << typeid( pb ).name() << endl;   //prints "class Base *"  
   cout << typeid( *pb ).name() << endl;   //prints "class Derived"  
   cout << typeid( pd ).name() << endl;   //prints "class Derived *"  
   cout << typeid( *pd ).name() << endl;   //prints "class Derived"  
   delete pd;  
}  
```  
  
 Se a *expressão* estiver desreferenciando um ponteiro e o valor desse ponteiro for zero, **typeid** lançará uma [exceção bad\_typeid](../cpp/bad-typeid-exception.md).  Se o ponteiro não apontar para um objeto válido, uma exceção `__non_rtti_object` será lançada, indicando uma tentativa de analisar o RTTI que acionou uma falha \(como violação de acesso\), pois o objeto é de algum modo inválido \(o ponteiro incorreto ou o código não foram compilados com [\/GR](../Topic/-GR%20\(Enable%20Run-Time%20Type%20Information\).md)\).  
  
 Se a *expressão* não é um ponteiro ou uma referência a uma classe base do objeto, o resultado será uma referência a **type\_info** que representa o tipo estático da *expressão*.  O *tipo estático* de uma expressão se refere ao tipo de uma expressão, como se sabe no tempo de compilação.  A semântica da execução é ignorada ao avaliar o tipo estático de uma expressão.  Além disso, as referências são ignoradas quando possível para determinar o tipo estático de uma expressão:  
  
```  
// expre_typeid_Operator_2.cpp  
#include <typeinfo>  
  
int main()  
{  
   typeid(int) == typeid(int&); // evaluates to true  
}  
```  
  
 **typeid** também pode ser usado em modelos para determinar o tipo de um parâmetro do modelo:  
  
```  
// expre_typeid_Operator_3.cpp  
// compile with: /c  
#include <typeinfo>  
template < typename T >   
T max( T arg1, T arg2 ) {  
   cout << typeid( T ).name() << "s compared." << endl;  
   return ( arg1 > arg2 ? arg1 : arg2 );  
}  
```  
  
## Consulte também  
 [Informações de tipo de tempo de execução](../Topic/Run-Time%20Type%20Information.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)