---
title: "Compilador aviso (nível 2) C4099 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4099
dev_langs:
- C++
helpviewer_keywords:
- C4099
ms.assetid: 00bb803d-cae7-4ab8-8969-b46f54139ac8
caps.latest.revision: 9
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
ms.openlocfilehash: 855b31903ba36f6c1ab3030e91354175441451a9
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-2-c4099"></a>Aviso do compilador (nível 2) C4099
'identifier': nome do tipo visto pela primeira vez usando 'objecttype1' agora visto usando 'objecttype2'  
  
 Um objeto declarado como uma estrutura é definido como uma classe ou um objeto declarado como uma classe é definido como uma estrutura. O compilador usa o tipo de dado na definição.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4099.  
  
```  
// C4099.cpp  
// compile with: /W2 /c  
struct A;  
class A {};   // C4099, use different identifer or use same object type  
```
