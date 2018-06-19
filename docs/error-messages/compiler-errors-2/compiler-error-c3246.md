---
title: C3246 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3246
dev_langs:
- C++
helpviewer_keywords:
- C3246
ms.assetid: ad85224a-e540-479b-a5eb-a3bc3964c30b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fb7feedafc4c965912bcb8ee022601e52d0c0f3a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33253246"
---
# <a name="compiler-error-c3246"></a>C3246 de erro do compilador
'class': não pode herdar de 'type', pois ele foi declarado como 'sealed'  
  
Uma classe que está marcada como [lacrado](../../windows/sealed-cpp-component-extensions.md) não pode ser a classe base para outras classes.  
  
O exemplo a seguir gera C3246:  
  
```  
// C3246_2.cpp  
// compile with: /clr /LD  
ref class X sealed {};  
  
ref class Y : public X {}; // C3246  
```  
