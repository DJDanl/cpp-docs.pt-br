---
title: "Compilador aviso (nível 1) C4939 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4939
dev_langs:
- C++
helpviewer_keywords:
- C4939
ms.assetid: 07096008-ba47-436c-a84c-2b03ad90d0b3
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
ms.openlocfilehash: ec751d960d26c3bb064a2899ecbad929138d0890
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4939"></a>Compilador C4939 de aviso (nível 1)
\#pragma vtordisp foi substituído e será removido em uma versão futura do Visual C++  
  
 O [vtordisp](../../preprocessor/vtordisp.md) pragma será removido em uma versão futura do Visual C++.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4939.  
  
```  
// C4939.cpp  
// compile with: /c /W1  
#pragma vtordisp(off)   // C4939  
```
