---
title: C3201 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3201
dev_langs: C++
helpviewer_keywords: C3201
ms.assetid: ec19cd64-1789-40a3-b2db-dff2852b9d98
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2a2bcae07f4e66fec1ed6fb9eb95e87e83557e53
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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