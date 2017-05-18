---
title: C2013 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2013
dev_langs:
- C++
helpviewer_keywords:
- C2013
ms.assetid: 6b5c955c-53da-48ee-8533-64ef5b905173
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 6074a5a9828e261dab5484f0244afed7bfefab1f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2013"></a>C2013 de erro do compilador
faltando '>'  
  
 Um `#include` diretiva não tem um colchete angular de fechamento. Adicione o colchete de fechamento para resolver o erro.  
  
 O exemplo a seguir gera C2013:  
  
```  
// C2013.cpp  
#include <stdio.h    // C2013  
```  
  
 Resolução possível:  
  
```  
// C2013b.cpp  
// compile with: /c  
#include <stdio.h>  
```
