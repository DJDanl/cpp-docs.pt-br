---
title: C3389 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3389
dev_langs:
- C++
helpviewer_keywords:
- C3389
ms.assetid: eaaffe17-23f2-413c-b1ad-f7220cfa1334
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6f0f60a1096c070d28be3b7af161bbb924fb20dd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3389"></a>C3389 de erro do compilador
__declspec(Keyword) não pode ser usado com /clr: pure ou /CLR: safe  
  
 As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
 Um [declspec](../../cpp/declspec.md) modificador usado implica um por estado de processo.  [/CLR: pure](../../build/reference/clr-common-language-runtime-compilation.md) implica um por [appdomain](../../cpp/appdomain.md) estado.  Assim, declarando uma variável com o `keyword` **declspec** modificador e compilar com **/clr: pure** não é permitido.  
  
 O exemplo a seguir gera C3389:  
  
```  
// C3389.cpp  
// compile with: /clr:pure /c  
__declspec(dllexport) int g2 = 0;   // C3389  
```