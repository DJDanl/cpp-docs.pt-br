---
title: C2812 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2812
dev_langs:
- C++
helpviewer_keywords:
- C2812
ms.assetid: 22aadb8c-7232-489d-a3ad-60662dda30a8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 28d46b0f9744f192d677d7b2df27b67e734de1b8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2812"></a>C2812 de erro do compilador
\#Não há suporte para a importação com /clr: pure e /CLR: safe  
  
 As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
 [#import diretiva](../../preprocessor/hash-import-directive-cpp.md) não é compatível com **/clr: pure** e **/CLR: safe** porque `#import` requer o uso de bibliotecas de suporte do compilador nativo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2812.  
  
```  
// C2812.cpp  
// compile with: /clr:pure /c  
#import "importlib.tlb"   // C2812  
```