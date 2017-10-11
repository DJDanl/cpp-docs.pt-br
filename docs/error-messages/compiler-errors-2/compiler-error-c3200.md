---
title: Compilador erro C3200 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3200
dev_langs:
- C++
helpviewer_keywords:
- C3200
ms.assetid: 44bb5e77-f0ec-421c-a732-b9ee7c0a3529
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: e4e1df5fb5c3da260ec5eba75d25e74207fbf8e2
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3200"></a>C3200 de erro do compilador
'template': argumento de template inválido para parâmetro de modelo 'parameter', esperado um modelo de classe  
  
 Você passou um argumento inválido para um modelo de classe. O modelo de classe espera modelo como um parâmetro. No exemplo a seguir, chamando `Y<int, int> aY` gerará C3200. O primeiro parâmetro deve ser um modelo, como `Y<X, int> aY`.  
  
```  
// C3200.cpp  
template<typename T>  
class X  
{  
};  
  
template<template<typename U> class T1, typename T2>  
class Y  
{  
};  
  
int main()  
{  
   Y<int, int> y;   // C3200  
}  
```
