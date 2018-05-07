---
title: C3202 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3202
dev_langs:
- C++
helpviewer_keywords:
- C3202
ms.assetid: 23528a0c-5493-4804-9789-cd3c38e49fb9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b6f7f059173e88bf9e76dde3f8448de218400a31
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3202"></a>C3202 de erro do compilador
'arg name': argumento padrão inválido para parâmetro de modelo 'parameter', esperado um modelo de classe  
  
 Passou um argumento padrão inválido para um parâmetro de modelo.  
  
 O exemplo a seguir gera C3202:  
  
```  
// C3202.cpp  
template<typename T>  
class X  
{  
};  
  
class Z  
{  
};  
  
template<template<typename U> class T1 = Z, typename T2> // C3202  
class Y  
{  
};  
```