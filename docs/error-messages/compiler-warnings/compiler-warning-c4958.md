---
title: C4958 de aviso do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4958
dev_langs:
- C++
helpviewer_keywords:
- C4958
ms.assetid: e79b9e9c-d572-4a3a-a3b6-60962b70864a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 27fd2802144fb64f38bb3f76c818981fa0f6a493
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-c4958"></a>C4958 de aviso do compilador
'operação de ': aritmética de ponteiro não é verificável  
  
 Usar aritmética de ponteiro produzirá uma imagem não verificável.  
  
 Para obter mais informações, consulte [puro e código verificável (C + + CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).  
  
 Esse aviso é emitido como um erro e pode ser desabilitado com o [aviso](../../preprocessor/warning.md) pragma ou [/wd](../../build/reference/compiler-option-warning-level.md) opção de compilador.  
  
 O exemplo a seguir gera C4958:  
  
```  
// C4958.cpp  
// compile with: /clr:safe  
// #pragma warning( disable : 4958 )  
using namespace System;  
  
int main( ) {  
   Int32 arr[] = new Int32[10];  
   Int32* p = &arr[0];  
   p++;   // C4958  
}  
```  
  
 O compilador implementa operações de matriz com aritmética de ponteiro. Portanto, não são verificáveis; matrizes nativo Use uma matriz CLR. Para obter mais informações, consulte [matriz](../../windows/arrays-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C4958:  
  
```  
// C4958b.cpp  
// compile with: /clr:safe  
// #pragma warning( disable : 4958 )  
  
int main() {  
   int array[5];  
   array[4] = 0;   // C4958  
}  
```