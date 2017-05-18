---
title: "Compilador aviso (nível 1 e nível 4) C4949 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4949
dev_langs:
- C++
helpviewer_keywords:
- C4949
ms.assetid: 34f45a05-c115-49cb-9f67-0bd4f0735d9b
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
ms.openlocfilehash: b7785b24525e04daeab7db842d5cad988f95d2c4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-and-level-4-c4949"></a>Compilador C4949 de aviso (nível 1 e nível 4)
Os pragmas '' e 'gerenciados' são significativos apenas quando compilado com ' / clr [: opção]'  
  
 O compilador ignora o [gerenciado](../../preprocessor/managed-unmanaged.md) e não gerenciados pragmas se o código-fonte não é compilado com [/clr](../../build/reference/clr-common-language-runtime-compilation.md). Esse aviso é informativo.  
  
 O exemplo a seguir gera C4949:  
  
```  
// C4949.cpp  
// compile with: /LD /W1  
#pragma managed   // C4949  
```  
  
 Quando **#pragma não gerenciado** for usado sem **/clr**, C4949 é um aviso de nível 4.  
  
 O exemplo a seguir gera C4949:  
  
```  
// C4949b.cpp  
// compile with: /LD /W4  
#pragma unmanaged   // C4949  
```
