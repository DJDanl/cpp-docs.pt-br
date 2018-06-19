---
title: Compilador (nível 1) de aviso C4141 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4141
dev_langs:
- C++
helpviewer_keywords:
- C4141
ms.assetid: 6ce8c058-7f4c-41cf-93e7-90a466744656
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6580557a5713bc7f7faf5e0e086081dcc156d5af
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33271967"
---
# <a name="compiler-warning-level-1-c4141"></a>Compilador C4141 de aviso (nível 1)
'modificador': usado mais de uma vez  
  
## <a name="example"></a>Exemplo  
  
```  
// C4141.cpp  
// compile with: /W1 /LD  
inline inline void func ();   // C4141  
```