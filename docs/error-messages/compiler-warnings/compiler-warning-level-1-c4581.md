---
title: "Compilador aviso (nível 1) C4581 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4581
dev_langs:
- C++
helpviewer_keywords:
- C4581
ms.assetid: 598bcd87-257d-4eb3-94e4-15bb31aadc99
caps.latest.revision: 12
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
ms.openlocfilehash: ca3e8fb8fdb3db7356dea9ce0be25136c8f23385
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4581"></a>Compilador C4581 de aviso (nível 1)
preterido comportamento: '"string1" ' substituído por string2 ao atributo de processo  
  
 Esse erro pode ser gerado como resultado de trabalho de conformidade do compilador que foi feito no Visual C++ 2005: parâmetro procurando atributos do Visual C++.  
  
 Nas versões anteriores, os valores de atributo foram aceitos se eles foram colocados entre aspas ou não. Se o valor é uma enumeração, não deve estar entre aspas.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4581.  
  
```  
// C4581.cpp  
// compile with: /c /W1  
#include "unknwn.h"  
[object, uuid("00000000-0000-0000-0000-000000000001")]  
__interface IMyI : IUnknown {};  
  
[coclass, uuid(12345678-1111-2222-3333-123456789012), threading("free")]   // C4581  
// try the following line instead  
// [coclass, uuid(12345678-1111-2222-3333-123456789012), threading(free)]  
class CSample : public IMyI {};  
```
