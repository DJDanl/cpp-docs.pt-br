---
title: "Compilador aviso (nível 4) C4400 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4400
dev_langs:
- C++
helpviewer_keywords:
- C4400
ms.assetid: f135fe98-4f92-4e07-9d71-2621b36ee755
caps.latest.revision: 4
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
ms.openlocfilehash: 69a85c9d21670d97c9d7a956abf54496719f0875
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4400"></a>Compilador C4400 de aviso (nível 4)
'type': não há suporte para const/volátil qualificadores nesse tipo  
  
 O [const](../../cpp/const-cpp.md)e [volátil](../../cpp/volatile-cpp.md)qualificadores não funcionará com variáveis de tipos common language runtime.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4400.  
  
```  
// C4400.cpp  
// compile with: /clr /W4  
// C4401 expected  
using namespace System;  
#pragma warning (disable : 4101)  
int main() {  
   const String^ str;   // C4400  
   volatile String^ str2;   // C4400  
}  
```
