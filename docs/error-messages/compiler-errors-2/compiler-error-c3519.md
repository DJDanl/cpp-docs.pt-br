---
title: "Erro do Compilador C3519 | Microsoft Docs"
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
  - "C3519"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3519"
ms.assetid: ca24b2bc-7e90-4448-ae84-3fedddf9bca7
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3519
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“invalid\_param”: parâmetro inválido ao atributo de embedded\_idl  
  
 Um parâmetro transmitido ao atributo de `embedded_idl` de [\#import](../Topic/%23import%20Directive%20\(C++\).md), mas o compilador não confirmou o parâmetro.  
  
 Os únicos parâmetros que são permitidos `embedded_idl` são `emitidl` e `no_emitidl`.  
  
 O seguinte exemplo gera C3519:  
  
```  
// C3519.cpp  
// compile with: /LD  
[module(name="MyLib2")];  
#import "C:\testdir\bin\importlib.tlb" embedded_idl("no_emitidcl")     
// C3519  
#import "C:\testdir\bin\importlib.tlb" embedded_idl("no_emitidl")     
// OK  
```