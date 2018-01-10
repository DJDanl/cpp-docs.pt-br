---
title: C2372 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2372
dev_langs: C++
helpviewer_keywords: C2372
ms.assetid: 406bea63-c8d3-4231-9d26-c70af6980840
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2680a22c1668f2d609b9b3ad291904d4b1509916
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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