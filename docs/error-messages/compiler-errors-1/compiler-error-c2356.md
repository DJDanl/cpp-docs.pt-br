---
title: "Erro do Compilador C2356 | Microsoft Docs"
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
  - "C2356"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2356"
ms.assetid: 84d5a816-9a61-4d45-9978-38e485bbf767
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2356
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o segmento de inicialização não deve ser alterado durante a unidade de tradução  
  
 Causas possíveis:  
  
-   `#pragma init_seg` precedeu pelo código de inicialização do segmento  
  
-   `#pragma init_seg` precedeu por outro `#pragma init_seg`  
  
 Para resolver, mova o código de inicialização do segmento ao início do módulo.  Se várias áreas devem ser inicializadas, movê\-las para separar os módulos.  
  
 O seguinte exemplo gera C2356:  
  
```  
// C2356.cpp  
#pragma warning(disable : 4075)  
  
int __cdecl myexit(void (__cdecl *)());  
int __cdecl myexit2(void (__cdecl *)());  
  
#pragma init_seg(".mine$m",myexit)  
#pragma init_seg(".mine$m",myexit2)   // C2356  
```