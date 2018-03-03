---
title: "Compilador (nível 1) de aviso C4186 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4186
dev_langs:
- C++
helpviewer_keywords:
- C4186
ms.assetid: caf3f7d8-f305-426b-8d4e-2b96f5c269ea
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e7277599efd0f8395d2961a08a69e5bd9d2c7cf9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4186"></a>Compilador C4186 de aviso (nível 1)
\#atributo de importação 'attribute' requer argumentos de contagem; ignorado  
  
 Um `#import` atributo tem um número incorreto de argumentos.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4186.cpp  
// compile with: /W1 /c  
#import "stdole2.tlb" no_namespace("abc") rename("a","b","c")  // C4186  
```  
  
 O `no_namespace` atributo não usa nenhum argumento. O **Renomear** atributo tem apenas dois argumentos.