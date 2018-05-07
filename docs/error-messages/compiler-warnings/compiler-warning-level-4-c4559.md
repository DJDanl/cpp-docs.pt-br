---
title: Compilador (nível 4) de aviso C4559 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4559
dev_langs:
- C++
helpviewer_keywords:
- C4559
ms.assetid: ed542f60-454d-45cb-85da-987ede61b1ab
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c853fa55482604d97c29653fadb06b0afdd44977
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4559"></a>Compilador C4559 de aviso (nível 4)
'function': redefinição; a função obtém __declspec(modifier)  
  
 Uma função foi redefinida ou declarado novamente e a segunda definição ou declaração adicionado um _**declspec** modificador (***modificador***). Esse aviso é informativo. Para corrigir esse aviso, exclua uma das definições.  
  
 O exemplo a seguir gera C4559:  
  
```  
// C4559.cpp  
// compile with: /W4 /LD  
void f();  
__declspec(noalias) void f();   // C4559  
```