---
title: C3553 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3553
dev_langs:
- C++
helpviewer_keywords:
- C3553
ms.assetid: 7f84bf37-6419-4ad3-ab30-64266100b930
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3a4ed8c2776015f9d9c6aedbe7a9da93f404f680
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33255992"
---
# <a name="compiler-error-c3553"></a>C3553 de erro do compilador
decltype espera uma expressão não é um tipo  
  
 O `decltype()` palavra-chave exige uma expressão como um argumento, não o nome de um tipo. Por exemplo, a última instrução no fragmento de código a seguir gera erro C3553.  
  
 `int x = 0;`  
  
 `decltype(x+1);`  
  
 `decltype(int); // C3553`