---
title: C3507 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3507
dev_langs:
- C++
helpviewer_keywords:
- C3507
ms.assetid: 75f89767-f6f9-40f6-9820-81a49e09abdf
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 697732f9e9c37735db591fc5a90d2380806fb7eb
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3507"></a>C3507 de erro do compilador
um ProgID pode ter não mais do que 39 caracteres 'id'; nem conter pontuações, exceto '.'; nem começar com um dígito  
  
 O [progid](../../windows/progid.md) atributo tem restrições nos valores que podem ser necessários.  
  
 O exemplo a seguir gera C3507:  
  
```  
// C3507.cpp  
[module(name="x")];  
[  
coclass,  
progid("0123456789012345678901234567890123456789"),  
uuid("00000000-0000-0000-0000-000000000001") // C3507 expected  
]  
struct CMyStruct {  
};  
int main() {  
}  
```
