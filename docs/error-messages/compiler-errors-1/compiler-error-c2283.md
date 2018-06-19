---
title: C2283 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2283
dev_langs:
- C++
helpviewer_keywords:
- C2283
ms.assetid: 8a5b3175-b480-4598-a1f7-0b50504c5caa
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bb602d1fa330876820cc7e1fe75fcfe7b736b81e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33170850"
---
# <a name="compiler-error-c2283"></a>C2283 de erro do compilador
'Identificador': especificador puro ou abstrato especificador de substituição não permitido no struct sem nome  
  
 Uma função de membro de uma estrutura ou classe sem nome foi declarada com um especificador puro, que não é permitido.  
  
 O exemplo a seguir gera C2283:  
  
```  
// C2283.cpp  
// compile with: /c  
struct {  
   virtual void func() = 0;   // C2283  
};  
struct T {  
   virtual void func() = 0;   // OK  
};  
```