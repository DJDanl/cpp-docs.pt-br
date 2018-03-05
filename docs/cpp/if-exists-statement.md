---
title: "instrução if_exists | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __if_exists_cpp
dev_langs:
- C++
helpviewer_keywords:
- identifiers, testing for existence
- symbols, testing for existence
- __if_exists keyword [C++]
ms.assetid: d3eb34b6-f3a9-4063-a286-b62a28c0c7fa
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c7950e2fcd933bd4748c06adf93f5ce1c271b162
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ifexists-statement"></a>Instrução __if_exists
A instrução `__if_exists` testa se o identificador especificado existe. Se o identificador especificado existir, o bloco de instrução especificado é executado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__if_exists ( identifier ) {   
statements  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`identifier`|O identificador cuja existência você deseja testar.|  
|`statements`|Uma ou mais instruções para executar se `identifier` existe.|  
  
## <a name="remarks"></a>Comentários  
  
> [!CAUTION]
>  Para obter os resultados mais confiáveis, use a instrução `__if_exists` sob as seguintes restrições.  
  
-   Aplique a instrução `__if_exists` apenas em tipos simples, não em modelos.  
  
-   Aplique a instrução `__if_exists` aos identificadores dentro ou fora de uma classe. Não aplique a instrução `__if_exists` às variáveis locais.  
  
-   Use a instrução `__if_exists` somente no corpo de uma função. Fora do corpo de uma função, a instrução `__if_exists` pode testar apenas tipos totalmente definidos.  
  
-   Quando você testa funções sobrecarregadas, não é possível testar um formato específico de sobrecarga.  
  
 O complemento para o `__if_exists` instrução é a [if_not_exists](../cpp/if-not-exists-statement.md) instrução.  
  
## <a name="example"></a>Exemplo  
 Observe que este exemplo usa modelos, o que não é recomendável.  
  
```  
// the__if_exists_statement.cpp  
// compile with: /EHsc  
#include <iostream>  
  
template<typename T>  
class X : public T {  
public:  
   void Dump() {  
      std::cout << "In X<T>::Dump()" << std::endl;  
  
      __if_exists(T::Dump) {  
         T::Dump();  
      }  
  
      __if_not_exists(T::Dump) {  
         std::cout << "T::Dump does not exist" << std::endl;  
      }  
   }     
};  
  
class A {  
public:  
   void Dump() {  
      std::cout << "In A::Dump()" << std::endl;  
   }  
};  
  
class B {};  
  
bool g_bFlag = true;  
  
class C {  
public:  
   void f(int);  
   void f(double);  
};  
  
int main() {   
   X<A> x1;  
   X<B> x2;  
  
   x1.Dump();  
   x2.Dump();  
  
   __if_exists(::g_bFlag) {  
      std::cout << "g_bFlag = " << g_bFlag << std::endl;  
   }  
  
   __if_exists(C::f) {  
      std::cout << "C::f exists" << std::endl;  
   }  
  
   return 0;  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
In X<T>::Dump()  
In A::Dump()  
In X<T>::Dump()  
T::Dump does not exist  
g_bFlag = 1  
C::f exists  
```  
  
## <a name="see-also"></a>Consulte também  
 [Instruções de seleção](../cpp/selection-statements-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Instrução __if_not_exists](../cpp/if-not-exists-statement.md)