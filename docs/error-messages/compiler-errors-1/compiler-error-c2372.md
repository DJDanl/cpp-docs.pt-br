---
title: C2372 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2372
dev_langs:
- C++
helpviewer_keywords:
- C2372
ms.assetid: 406bea63-c8d3-4231-9d26-c70af6980840
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 864162b02a2c7575809887bb638bb703219eea71
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33194860"
---
# <a name="compiler-error-c2372"></a>C2372 de erro do compilador
'Identificador': redefinição; tipos de indireção diferentes  
  
 O identificador já está definido com um tipo derivado diferente.  
  
 O exemplo a seguir gera C2326:  
  
```  
// C2372.cpp  
// compile with: /c  
extern int *fp;  
extern int fp[];   // C2372  
extern int fp2[];   // OK  
```