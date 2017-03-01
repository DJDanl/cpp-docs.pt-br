---
title: "Compilador aviso (nível 1) C4068 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4068
dev_langs:
- C++
helpviewer_keywords:
- C4068
ms.assetid: 96a7397a-4eab-44ab-b3bb-36747503f7e5
caps.latest.revision: 7
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
ms.openlocfilehash: 1f5e4fcb45de4a2900220c831f4916bf1a021616
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4068"></a>Compilador C4068 de aviso (nível 1)
pragma desconhecido  
  
 O compilador ignorado uma reconhecida [pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md). Verifique se o **pragma** é permitido pelo compilador que você está usando. O exemplo a seguir gera C4068:  
  
```  
// C4068.cpp  
// compile with: /W1  
#pragma NotAValidPragmaName   // C4068, use valid name to resolve  
int main()  
{  
}  
```
