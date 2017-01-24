---
title: "Instru&#231;&#227;o __if_exists | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__if_exists_cpp"
  - "__if_exists"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __if_exists [C++]"
  - "identificadores, testando existência"
  - "símbolos, testando existência"
ms.assetid: d3eb34b6-f3a9-4063-a286-b62a28c0c7fa
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o __if_exists
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A instrução `__if_exists` testa se o identificador especificado existe.  Se o identificador especificado existir, o bloco de instrução especificado é executado.  
  
## Sintaxe  
  
```  
__if_exists ( identifier ) {   
statements  
};  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`identifier`|O identificador cuja existência você deseja testar.|  
|`statements`|Uma ou mais instruções para executar se `identifier` existir.|  
  
## Comentários  
  
> [!CAUTION]
>  Para obter os resultados mais confiáveis, use a instrução `__if_exists` sob as seguintes restrições.  
  
-   Aplique a instrução `__if_exists` apenas em tipos simples, não em modelos.  
  
-   Aplique a instrução `__if_exists` aos identificadores dentro ou fora de uma classe.  Não aplique a instrução `__if_exists` às variáveis locais.  
  
-   Use a instrução `__if_exists` somente no corpo de uma função.  Fora do corpo de uma função, a instrução `__if_exists` pode testar apenas tipos totalmente definidos.  
  
-   Quando você testa funções sobrecarregadas, não é possível testar um formato específico de sobrecarga.  
  
 O complemento para a instrução `__if_exists` é a instrução [\_\_if\_not\_exists](../cpp/if-not-exists-statement.md).  
  
## Exemplo  
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
  
## Saída  
  
```  
In X<T>::Dump()  
In A::Dump()  
In X<T>::Dump()  
T::Dump does not exist  
g_bFlag = 1  
C::f exists  
```  
  
## Consulte também  
 [Instruções de seleção](../cpp/selection-statements-cpp.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Instrução \_\_if\_not\_exists](../cpp/if-not-exists-statement.md)