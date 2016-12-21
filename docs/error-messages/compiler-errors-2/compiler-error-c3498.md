---
title: "Compiler Error C3498 | Microsoft Docs"
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
  - "C3498"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3498"
ms.assetid: 0a5a7817-0872-4119-83bf-980a19113374
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compiler Error C3498
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'var': não será possível capturar uma variável que tem um gerenciado ou um tipo WinRT  
  
 Você não pode capturar uma variável que possui um tipo gerenciado ou um tipo de tempo de execução do Windows em um lambda.  
  
### Para corrigir este erro  
  
-   Passar o gerenciado ou variável de tempo de execução do Windows à lista de parâmetros da expressão lambda.  
  
## Exemplo  
 O exemplo a seguir gera C3498 porque uma variável que possui um tipo gerenciado aparece na lista de captura de uma expressão lambda:  
  
```  
// C3498a.cpp  
// compile with: /clr  
using namespace System;  
  
int main()  
{  
   String ^ s = "Hello";  
   [&s](String ^ r)   
      { return String::Concat(s, r); } (", World!"); // C3498  
}  
```  
  
## Exemplo  
 O exemplo a seguir resolve C3498, passando a variável gerenciada `s` à lista de parâmetros da expressão lambda:  
  
```  
// C3498b.cpp  
// compile with: /clr  
using namespace System;  
  
int main()  
{  
   String ^ s = "Hello";  
   [](String ^ s, String ^ r)   
      { return String::Concat(s, r); } (s, ", World!");  
}  
```  
  
## Consulte também  
 [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)