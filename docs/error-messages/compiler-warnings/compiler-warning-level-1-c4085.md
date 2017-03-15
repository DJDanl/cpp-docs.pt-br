---
title: "Compilador aviso (nível 1) C4085 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4085
dev_langs:
- C++
helpviewer_keywords:
- C4085
ms.assetid: 2bc6eb25-058f-4597-b351-fd69587b5170
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d787f1a1fe0e40c79ee144d7aba63adb2bd6d35b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4085"></a>Compilador C4085 de aviso (nível 1)
esperado parâmetro de pragma como 'on' ou 'off'  
  
 O pragma requer um **na** ou **off** parâmetro. O pragma é ignorado.  
  
 O exemplo a seguir gera C4085:  
  
```  
// C4085.cpp  
// compile with: /W1 /LD  
#pragma optimize( "t", maybe )  // C4085  
```
