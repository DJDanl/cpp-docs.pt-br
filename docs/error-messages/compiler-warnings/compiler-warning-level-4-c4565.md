---
title: "Compilador aviso (nível 4) C4565 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4565
dev_langs:
- C++
helpviewer_keywords:
- C4565
ms.assetid: a71f1341-a4a1-4060-ad1e-9322531883ed
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 70b0311ff02fc9c5fb2b06005a639d0a3dca21e4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4565"></a>Compilador C4565 de aviso (nível 4)
'function': redefinição; o símbolo foi declarado anteriormente com __declspec(modifier)  
  
 Um símbolo foi redefinido ou declarado novamente e a segunda definição ou declaração, ao contrário da primeira definição ou declaração, não tinha um `__declspec` modificador (***modificador***). Esse aviso é informativo. Para corrigir esse aviso, exclua uma das definições.  
  
 O exemplo a seguir gera C4565:  
  
```  
// C4565.cpp  
// compile with: /W4 /LD  
__declspec(noalias) void f();  
void f();   // C4565  
```
