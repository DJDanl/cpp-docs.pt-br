---
title: "Erro do Compilador C3672 | Microsoft Docs"
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
  - "C3672"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3672"
ms.assetid: da971041-1766-467a-aecf-1d8655c6cb7a
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3672
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a expressão do pseudo de destruidor só pode ser usada como parte de uma chamada de função  
  
 Um destruidor foi chamado incorretamente.  Para obter mais informações, consulte [Destruidores](../../cpp/destructors-cpp.md).  
  
## Exemplo  
 O exemplo a seguir produz C3672.  
  
```  
// C3672.cpp  
template<typename T>  
void f(T* pT) {  
   &pT->T::~T;   // C3672  
   pT->T::~T();   // OK  
};  
  
int main() {  
   int i;  
   f(&i);  
}  
```