---
title: C3747 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3747
dev_langs:
- C++
helpviewer_keywords:
- C3747
ms.assetid: a9a4be67-5d9c-4dcc-9ae9-baae46cbecde
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: f68363a0d3a6c5b9354f89993fd658cf227edd0f
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3747"></a>C3747 de erro do compilador
parâmetro de tipo padrão ausente: parâmetro param  
  
 Genérico ou modelo de parâmetros com valores padrão não podem ser seguidos na lista de parâmetros parâmetros que não têm valores padrão.  
  
 O exemplo a seguir gera C3747:  
  
```  
// C3747.cpp  
template <class T1 = int, class T2>   // C3747  
struct MyStruct {};  
```  
  
 Possível solução:  
  
```  
// C3747b.cpp  
// compile with: /c  
template <class T1, class T2 = int>  
struct MyStruct {};  
```
