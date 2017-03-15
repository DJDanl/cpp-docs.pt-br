---
title: C2007 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2007
dev_langs:
- C++
helpviewer_keywords:
- C2007
ms.assetid: ecd09d99-5036-408b-9e46-bc15488f049e
caps.latest.revision: 7
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
ms.openlocfilehash: 0348c76e0a7a4e78eb4b2928443e7fecbc9853b1
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2007"></a>C2007 de erro do compilador
\#definir a sintaxe  
  
 Nenhum identificador aparece após um `#define`. Para resolver o erro, use um identificador.  
  
 O exemplo a seguir gera C2007:  
  
```  
// C2007.cpp  
#define   // C2007  
```  
  
 Resolução possível:  
  
```  
// C2007b.cpp  
// compile with: /c  
#define true 1  
```
