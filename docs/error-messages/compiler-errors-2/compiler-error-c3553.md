---
title: C3553 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3553
dev_langs:
- C++
helpviewer_keywords:
- C3553
ms.assetid: 7f84bf37-6419-4ad3-ab30-64266100b930
caps.latest.revision: 4
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 9ad1e4d6f59d0cad99935eda97b8a7d7ac358666
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3553"></a>C3553 de erro do compilador
decltype espera uma expressão não é um tipo  
  
 O `decltype()` palavra-chave exige uma expressão como um argumento, não o nome de um tipo. Por exemplo, a última instrução no fragmento de código a seguir gera erro C3553.  
  
 `int x = 0;`  
  
 `decltype(x+1);`  
  
 `decltype(int); // C3553`
