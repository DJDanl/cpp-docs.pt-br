---
title: "C4959 de aviso do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C4959"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4959"
ms.assetid: 3a128f3e-4d8a-4565-ba1a-5d32fdeb5982
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C4959 de aviso do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível definir struct não gerenciado 'type' no \/CLR: safe como acessar seus membros resulta em código não verificado  
  
 Acessar um membro de um tipo não gerenciado produzirá uma imagem \(peverify.exe\) não verificável.  
  
 Para obter mais informações, consulte [Código puro e verificável](../../dotnet/pure-and-verifiable-code-cpp-cli.md).  
  
 Esse aviso é emitido como um erro e pode ser desabilitado com o [Aviso](../../preprocessor/warning.md) pragma ou [\/wd](../../build/reference/compiler-option-warning-level.md) opção de compilador.  
  
 O exemplo a seguir gera C4959:  
  
```  
// C4959.cpp // compile with: /clr:safe // Uncomment the following line to resolve. // #pragma warning( disable : 4959 ) struct X { int data; }; int main() { X x; x.data = 10;   // C4959 }  
```