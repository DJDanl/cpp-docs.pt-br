---
title: C3862 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3862
dev_langs:
- C++
helpviewer_keywords:
- C3862
ms.assetid: ba547366-4189-4077-8c00-ab45e08a9533
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: af959252ce5b404d8646ad61e02c5e480b41ed83
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3862"></a>C3862 de erro do compilador
'function': não é possível compilar uma função não gerenciada com /clr: pure ou /CLR: safe  
  
 As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
 Uma compilação com **/clr: pure** ou **/CLR: safe** produzirá uma imagem do MSIL somente, uma imagem com nenhuma o código nativo (não gerenciado).  Portanto, você não pode usar o `unmanaged` pragma em um **/clr: pure** ou **/CLR: safe** compilação.  
  
 Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) e [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3862:  
  
```  
// C3862.cpp  
// compile with: /clr:pure /c  
#pragma unmanaged  
void f() {}   // C3862  
```
