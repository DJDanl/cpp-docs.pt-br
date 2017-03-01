---
title: "Compilador aviso (nível 1) C4083 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4083
dev_langs:
- C++
helpviewer_keywords:
- C4083
ms.assetid: e7d3344e-5645-4d56-8460-d1acc9145ada
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
ms.openlocfilehash: db58b8713566203ec92782723d875f09510f7651
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4083"></a>Compilador C4083 de aviso (nível 1)
esperado 'token'; encontrado o identificador 'Identificador'  
  
 Um identificador ocorre no lugar errado em um **#pragma** instrução.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4083.cpp  
// compile with: /W1 /LD  
#pragma warning disable:4083    // C4083  
#pragma warning(disable:4083)   //correct  
```  
  
 Verifique a sintaxe do [#pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md) diretivas.
