---
title: C2434 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2434
dev_langs:
- C++
helpviewer_keywords:
- C2434
ms.assetid: 01329e26-7c74-4219-b74f-69e3a40c9738
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 543884392698a7a713dbc4c0bfd10dd19fcb0b1c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2434"></a>C2434 de erro do compilador
'symbol': um símbolo declarado com __declspec(process) não pode ser inicializado dinamicamente em /clr: pure modo  
  
 As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
 Não é possível inicializar dinamicamente uma variável de cada processo em **/clr: pure**. Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) e [processo](../../cpp/process.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2434.  
  
```  
// C2434.cpp  
// compile with: /clr:pure /c  
int f() { return 0; }  
__declspec(process) int i = f();   // C2434  
__declspec(process) int i2 = 0;   // OK  
```