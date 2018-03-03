---
title: C2636 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2636
dev_langs:
- C++
helpviewer_keywords:
- C2636
ms.assetid: 379873ec-8d05-49f8-adf1-b067bc07bdb8
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1fce2884cd8a4d2855f81a1a1accf0f42614039a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2636"></a>C2636 de erro do compilador
'Identificador': ponteiro para membro de referência é inválido  
  
 Um ponteiro para um membro de referência foi declarado.  
  
 O exemplo a seguir gera C2636:  
  
```  
// C2636.cpp  
struct S {};  
int main() {  
   int &S::*prs;   // C2636  
   int S::*prs1;   // OK  
   int *S::*prs2;   // OK  
}  
```