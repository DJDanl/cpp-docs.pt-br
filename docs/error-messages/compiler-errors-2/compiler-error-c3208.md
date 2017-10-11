---
title: C3208 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3208
dev_langs:
- C++
helpviewer_keywords:
- C3208
ms.assetid: 6d060bfe-52cf-4599-8f70-bdeb5a670df3
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 5078264a615aa3dd998e2e71f366e8062054e6d4
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3208"></a>C3208 de erro do compilador
'function': lista de parâmetros de modelo de classe modelo 'class' não corresponde a lista de parâmetros de template para parâmetro de modelo 'parameter'  
  
 Um parâmetro de modelo não tem o mesmo número de parâmetros de modelo, como o modelo de classe fornecida.  
  
 O exemplo a seguir gera C3208:  
  
```  
// C3208.cpp  
template <template <class T> class TT >  
int f();  
  
template <class T1, class T2>  
struct S;  
  
template <class T1>  
struct R;  
  
int i = f<S>();   // C3208  
// try the following line instead  
// int i = f<R>();  
```
