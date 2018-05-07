---
title: C4936 de aviso do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4936
dev_langs:
- C++
helpviewer_keywords:
- C4936
ms.assetid: 6676de35-bf1b-4d0b-a70f-b5734130336c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dcf9f32a4a1b1e43cb4bd69c754e3ae3a98bff3d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-c4936"></a>C4936 de aviso do compilador
Este declspec é suportado apenas quando compilado com /clr ou /clr: pure  
  
 O **/clr: pure** opção de compilador foi preterida no Visual Studio 2015.  
  
 Um `__declspec` modificador foi usado, mas que `__declspec` modificador só é válido quando compilado com uma da [/clr](../../build/reference/clr-common-language-runtime-compilation.md) opções.  
  
 Para obter mais informações, consulte [appdomain](../../cpp/appdomain.md) e [processo](../../cpp/process.md).  
  
 C4936 sempre é emitido como um erro.  Você pode desabilitar C4936 com o [aviso](../../preprocessor/warning.md) pragma.  
  
 O exemplo a seguir gera C4936:  
  
```  
// C4936.cpp  
// compile with: /c  
// #pragma warning (disable : 4936)  
__declspec(process) int i;   // C4936  
__declspec(appdomain) int j;   // C4936  
```