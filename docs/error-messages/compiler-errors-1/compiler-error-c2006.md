---
title: C2006 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2006
dev_langs:
- C++
helpviewer_keywords:
- C2006
ms.assetid: caaed6f7-ceb9-4742-8820-d66657c0b04d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 93880e7d767de3101cd7a292af5fa2874cae86bf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33165565"
---
# <a name="compiler-error-c2006"></a>C2006 de erro do compilador
'diretiva' esperado um nome de arquivo, encontrado 'token'  
  
 Diretivas como [#include](../../preprocessor/hash-include-directive-c-cpp.md) ou [#import](../../preprocessor/hash-import-directive-cpp.md) requer um nome de arquivo. Para resolver o erro, certifique-se de *token* é um nome de arquivo válido. Além disso, coloque o nome de arquivo em aspas duplas ou colchetes angulares.  
  
 O exemplo a seguir gera C2006:  
  
```  
// C2006.cpp  
#include stdio.h   // C2006  
```  
  
 Possível solução:  
  
```  
// C2006b.cpp  
// compile with: /c  
#include <stdio.h>  
```