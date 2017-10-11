---
title: C3197 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3197
dev_langs:
- C++
helpviewer_keywords:
- C3197
ms.assetid: 4e385c3b-222e-425c-9612-46e83ed41650
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 52c5287171cb162e66b39bb464ed7a464d571136
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3197"></a>C3197 de erro do compilador
'palavra-chave': só pode ser usado em definições  
  
 Uma palavra-chave foi usada em uma declaração, mas só é válida em uma definição.  
  
 O exemplo a seguir gera C3197:  
  
```  
// C3197.cpp  
// compile with: /clr /c  
ref struct R abstract;   // C3197  
ref struct R abstract {};   // OK  
  
public ref class MyObject;   // C3197  
ref class MyObject;   // OK  
public ref class MyObject {};   // OK  
```
