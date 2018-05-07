---
title: Compilador aviso (nível 2) C4099 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4099
dev_langs:
- C++
helpviewer_keywords:
- C4099
ms.assetid: 00bb803d-cae7-4ab8-8969-b46f54139ac8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: afecb3fb2420d27bedf16c81894f224a1119a67b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-2-c4099"></a>Aviso do compilador (nível 2) C4099
'Identificador': nome de tipo visto primeiro usando 'objecttype1' agora visto usando 'objecttype2'  
  
 Um objeto declarado como uma estrutura é definido como uma classe ou um objeto declarado como uma classe é definido como uma estrutura. O compilador usa o tipo de dado na definição.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4099.  
  
```  
// C4099.cpp  
// compile with: /W2 /c  
struct A;  
class A {};   // C4099, use different identifer or use same object type  
```