---
title: C3201 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3201
dev_langs:
- C++
helpviewer_keywords:
- C3201
ms.assetid: ec19cd64-1789-40a3-b2db-dff2852b9d98
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: c398d3251c63a763af0fdf965e4c7f2e8c5bb3c4
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3201"></a>C3201 de erro do compilador
a lista de parâmetros de template para template de classe 'template' não coincide com a lista de parâmetros de template para parâmetro de modelo 'template'  
  
 Passado um modelo de classe no argumento para um modelo de classe que não tem um parâmetro de modelo, ou passou um número incompatível de argumentos de modelo para o argumento de modelo padrão.  
  
```  
// C3201.cpp  
template<typename T1, typename T2>  
class X1  
{  
};  
  
template<template<typename T> class U = X1>   // C3201  
class X2  
{  
};  
  
template<template<typename T, typename V> class U = X1>   // OK  
class X3  
{  
};  
```
