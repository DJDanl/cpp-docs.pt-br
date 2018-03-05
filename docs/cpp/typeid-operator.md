---
title: Operador TypeId | Microsoft Docs
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
- typeid operator
ms.assetid: 8871cee6-d6b9-4301-a5cb-bf3dc9798d61
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b27f3bcb7358b3ea05907df1a4372c107538dfb4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="typeid-operator"></a>Operador typeid
## <a name="syntax"></a>Sintaxe  
  
```  
  
      typeid(   
      type-id  
       )  
typeid( expression )  
```  
  
## <a name="remarks"></a>Comentários  
 O operador `typeid` permite que o tipo de um objeto seja determinado em tempo de execução.  
  
 O resultado de `typeid` é um **type_info const &**. O valor é uma referência a um **type_info** que representa o objeto a *id do tipo* ou o tipo do *expressão*, dependendo de qual forma de `typeid` é usado . Consulte [classe type_info](../cpp/type-info-class.md) para obter mais informações.  
  
 O `typeid` operador não funciona com tipos gerenciados (declaradores abstratos ou instâncias), consulte [typeid](../windows/typeid-cpp-component-extensions.md) para obter informações sobre como obter o <xref:System.Type> de um tipo especificado.  
  
 O operador `typeid` faz uma verificação de tempo de execução quando aplicado a um l-value de um tipo de classe polimórfica, onde o tipo true de objeto não pode ser determinado pelas informações estáticas fornecidas. Tais casos são:  
  
-   Uma referência à classe  
  
-   Um ponteiro, desreferenciado com *  
  
-   Um ponteiro subscrito (isto é, []). (Geralmente, não é seguro usar um subscrito com um ponteiro para um tipo polimórfico.)  
  
 Se o *expressão* aponta para um tipo de classe base, mas o objeto na verdade é de um tipo derivado da classe base, um **type_info** referência para a classe derivada é o resultado. O *expressão* deve apontar para um tipo polimórfico (uma classe com funções virtuais). Caso contrário, o resultado é o **type_info** para a classe estática referida a *expressão*. Além disso, o ponteiro deve ser desreferenciado de forma que o objeto para o qual ele aponta seja usado. Sem o ponteiro de referência, o resultado será a **type_info** para o ponteiro não que ele aponte para. Por exemplo:  
  
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
  
 Se o *expressão* cancelar a referência de um ponteiro, e o valor do ponteiro for zero, **typeid** lança um [exceção bad_typeid](../cpp/bad-typeid-exception.md). Se o ponteiro não aponta para um objeto válido, um `__non_rtti_object` exceção for lançada, o que indica uma tentativa de analisar o RTTI que disparou uma falha (como a violação de acesso), porque o objeto de alguma forma é inválido (ponteiro inválido ou o código não foi compilado com [/GR](../build/reference/gr-enable-run-time-type-information.md)).  
  
 Se o *expressão* não é um ponteiro ou uma referência a uma classe base do objeto, o resultado é um **type_info** referência que representa o tipo estático do *expressão*. O *tipo estático* de uma expressão se refere ao tipo de uma expressão como é conhecido em tempo de compilação. A semântica da execução é ignorada ao avaliar o tipo estático de uma expressão. Além disso, as referências são ignoradas quando possível para determinar o tipo estático de uma expressão:  
  
```  
// expre_typeid_Operator_2.cpp  
#include <typeinfo>  
  
int main()  
{  
   typeid(int) == typeid(int&); // evaluates to true  
}  
```  
  
 **TypeId** também pode ser usado em modelos para determinar o tipo de um parâmetro de modelo:  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Informações de tipo em tempo de execução](../cpp/run-time-type-information.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)