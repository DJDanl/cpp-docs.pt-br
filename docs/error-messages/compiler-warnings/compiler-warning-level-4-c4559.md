---
title: "Compilador aviso (nível 4) C4559 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4559
dev_langs:
- C++
helpviewer_keywords:
- C4559
ms.assetid: ed542f60-454d-45cb-85da-987ede61b1ab
caps.latest.revision: 6
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
ms.openlocfilehash: eecca22e7344dc97235475e502a1e2315ecd42a5
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4559"></a>Compilador C4559 de aviso (nível 4)
'function': redefinição; a função obtém __declspec(modifier)  
  
 Uma função foi redefinida ou declarado novamente e a segunda definição ou declaração adicionado um _**declspec** modificador (***modificador***). Esse aviso é informativo. Para corrigir esse aviso, exclua uma das definições.  
  
 O exemplo a seguir gera C4559:  
  
```  
// C4559.cpp  
// compile with: /W4 /LD  
void f();  
__declspec(noalias) void f();   // C4559  
```
