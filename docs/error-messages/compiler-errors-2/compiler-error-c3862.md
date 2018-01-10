---
title: C3862 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3862
dev_langs: C++
helpviewer_keywords: C3862
ms.assetid: ba547366-4189-4077-8c00-ab45e08a9533
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 63fa12348ee2ab58782fad02719918bfe7929ff8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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