---
title: "Compilador aviso (nível 1) C4096 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4096
dev_langs:
- C++
helpviewer_keywords:
- C4096
ms.assetid: abf3cca2-2f21-45d8-b025-6b513b00681e
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 38ba5ca53ea2939a6532df47cfd85741c87d24cc
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4096"></a>Compilador C4096 de aviso (nível 1)
'a': não é uma interface COM; não será emitido para IDL  
  
 Uma definição de interface desejada como uma interface COM não foi definida como uma interface COM e, portanto, não será emitida para o arquivo IDL.  
  
 Consulte [atributos de Interface](../../windows/interface-attributes.md) para atributos uma lista que indicam uma interface é uma interface COM.  
  
 O exemplo a seguir gera C4096:  
  
```  
// C4096.cpp  
// compile with: /W1 /LD  
#include "windows.h"  
[module(name="xx")];  
  
// [object, uuid("00000000-0000-0000-0000-000000000001")]  
__interface a  
{  
};  
  
[coclass, uuid("00000000-0000-0000-0000-000000000002")]  
struct b : a  
{  
};   // C4096, remove coclass or uncomment object  
```
