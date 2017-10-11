---
title: C2833 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2833
dev_langs:
- C++
helpviewer_keywords:
- C2833
ms.assetid: b9418ce1-e2ee-4599-8959-6fde89c27569
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 2d3adf42ddb4df4365a45fd3ef24bccd682ac3c9
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2833"></a>C2833 de erro do compilador
'operator operador' não é um operador ou tipo reconhecido  
  
 A palavra `operator` deve ser seguido por um operador que você deseja substituir ou um tipo que você deseja converter.  
  
 Para obter uma lista dos operadores que você pode definir um tipo gerenciado, consulte [operadores definidos pelo usuário](../../dotnet/user-defined-operators-cpp-cli.md).  
  
 O exemplo a seguir gera C2833:  
  
```  
// C2833.cpp  
// compile with: /c  
class A {};  
  
void operator ::* ();   // C2833  
void operator :: ();   // OK  
```
