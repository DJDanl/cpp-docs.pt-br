---
title: "Compilador aviso (nível 1) C4272 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4272
dev_langs:
- C++
helpviewer_keywords:
- C4272
ms.assetid: 0d6c1de4-2eef-42c4-b861-c221f8b495ef
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 98e1003067a542a2b22c30091ecd8d45ea410062
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4272"></a>Compilador aviso (nível 1) C4272
'function': está marcado como __declspec(dllimport); deve especificar a convenção de chamada nativa ao importar uma função.  
  
 Erro ao exportar uma função marcada com o [clrcall](../../cpp/clrcall.md) chamada convenção e o compilador emite esse aviso se você tentar importar uma função marcada como `__clrcall`.  
  
 O exemplo a seguir gera C4272:  
  
```  
// C4272.cpp  
// compile with: /c /W1 /clr  
__declspec(dllimport) void __clrcall Test();   // C4272  
__declspec(dllimport) void Test2();   // OK  
```
