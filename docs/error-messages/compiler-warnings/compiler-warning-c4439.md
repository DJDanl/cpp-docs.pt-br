---
title: C4439 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4439
dev_langs: C++
helpviewer_keywords: C4439
ms.assetid: 9449958f-f407-4824-829b-9e092f2af97d
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 150690bc5d2778945eec95c8576b2cc57050bbe8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-c4439"></a>C4439 de aviso do compilador
'function': definição de função com um tipo gerenciado na assinatura deve ter um clrcall convenção de chamada  
  
 O compilador implicitamente substituído uma convenção de chamada com [clrcall](../../cpp/clrcall.md). Para resolver este aviso, remova o `__cdecl` ou `__stdcall` convenção de chamada.  
  
 C4439 sempre é emitido como um erro. Você pode desativar esse aviso com a `#pragma warning` ou **/wd**; consulte [aviso](../../preprocessor/warning.md) ou [/w, /W0, /W1, /W2, /W3, /W4, /w1, /w2, /w3, /w4, /Wall, /wd, /, /wo, /Wv, /WX (nível de aviso)](../../build/reference/compiler-option-warning-level.md)para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4439.  
  
```  
// C4439.cpp  
// compile with: /clr  
void __stdcall f( System::String^ arg ) {}   // C4439  
void __clrcall f2( System::String^ arg ) {}   // OK  
void f3( System::String^ arg ) {}   // OK  
```