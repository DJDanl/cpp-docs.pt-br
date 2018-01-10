---
title: C2082 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C2082
dev_langs: C++
helpviewer_keywords: C2082
ms.assetid: 87a6d442-157c-46e8-9bff-8388f8338ae0
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 43336d881e56cc3f02330e0201b4020d8ba15ee5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2082"></a>C2082 de erro do compilador
redefinição de parâmetro formal 'Identificador'  
  
 Um parâmetro formal para uma função é declarado novamente dentro do corpo de função. Para resolver o erro, remova a redefinição.  
  
 O exemplo a seguir gera C2082:  
  
```  
// C2082.cpp  
void func(int i) {  
   int i;   // C2082  
   int ii;   // OK  
}  
```