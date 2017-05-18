---
title: C2006 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2006
dev_langs:
- C++
helpviewer_keywords:
- C2006
ms.assetid: caaed6f7-ceb9-4742-8820-d66657c0b04d
caps.latest.revision: 8
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
ms.openlocfilehash: d1e68940ade568abaeea68ddf62f49b49588b915
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2006"></a>C2006 de erro do compilador
'diretiva' esperado um nome de arquivo, encontrado 'token'  
  
 Diretivas como [#include](../../preprocessor/hash-include-directive-c-cpp.md) ou [#import](../../preprocessor/hash-import-directive-cpp.md) requer um nome de arquivo. Para resolver o erro, certifique-se de *token* é um nome de arquivo válido. Além disso, colocar o nome de arquivo em aspas duplas ou colchetes angulares.  
  
 O exemplo a seguir gera C2006:  
  
```  
// C2006.cpp  
#include stdio.h   // C2006  
```  
  
 Resolução possível:  
  
```  
// C2006b.cpp  
// compile with: /c  
#include <stdio.h>  
```
