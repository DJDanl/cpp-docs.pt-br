---
title: Compilador (nível 1) de aviso C4085 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4085
dev_langs:
- C++
helpviewer_keywords:
- C4085
ms.assetid: 2bc6eb25-058f-4597-b351-fd69587b5170
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f9b8f1cfdb1cb8cc699b71a08afc417d2d1bd87f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33271821"
---
# <a name="compiler-warning-level-1-c4085"></a>Compilador C4085 de aviso (nível 1)
parâmetro pragma esperado para ser 'on' ou 'off'  
  
 O pragma requer um **na** ou **off** parâmetro. O pragma é ignorado.  
  
 O exemplo a seguir gera C4085:  
  
```  
// C4085.cpp  
// compile with: /W1 /LD  
#pragma optimize( "t", maybe )  // C4085  
```