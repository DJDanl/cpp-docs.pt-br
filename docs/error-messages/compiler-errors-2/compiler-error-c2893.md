---
title: "Erro do Compilador C2893 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2893"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2893"
ms.assetid: ec0cbe43-005d-45da-8742-aaeb9b81d28e
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2893
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Não especializam o modelo de “nome da função modelo”  
  
 O compilador não são qualificados um modelo da função.  Pode haver muitas causas para esse erro.  
  
 Em geral, a forma de resolver um erro C2893 é verificar a assinatura da função e garantir você pode criar uma instância de cada tipo.  
  
## Exemplo  
 C2893 ocorre porque o parâmetro `T` do modelo de `f` é deduzido para ser `std::map<int,int>`, mas `std::map<int,int>` não tem nenhum membro `data_type` \(`T::data_type` não pode ser criada uma instância com `T = std::map<int,int>`.\).  O exemplo a seguir produz C2893.  
  
```  
// C2893.cpp  
// compile with: /c /EHsc  
#include<map>  
using namespace std;  
class MyClass {};  
  
template<class T>   
inline typename T::data_type  
// try the following line instead  
// inline typename  T::mapped_type  
f(T const& p1, MyClass const& p2);  
  
template<class T>  
void bar(T const& p1) {  
    MyClass r;  
    f(p1,r);   // C2893  
}  
  
int main() {  
   map<int,int> m;  
   bar(m);  
}  
```