---
title: C2289 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2289
dev_langs:
- C++
helpviewer_keywords:
- C2289
ms.assetid: cb41a29e-1b06-47dc-bfce-8d73bd63a0df
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4d351bffc33fc754ffcb66d2428a77fb040089a3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2289"></a>C2289 de erro do compilador
mesmo qualificador de tipo usado mais de uma vez  
  
 Uma declaração de tipo ou definição usa um qualificador de tipo (`const`, `volatile`, `signed`, ou `unsigned`) mais de uma vez, causando um erro em compatibilidade ANSI (**/Za**).  
  
 O exemplo a seguir gera C2286:  
  
```  
// C2289.cpp  
// compile with: /Za /c  
volatile volatile int i;   // C2289  
volatile int j;   // OK  
```