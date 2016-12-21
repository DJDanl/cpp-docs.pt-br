---
title: "Erro do Compilador C3201 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C3201"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3201"
ms.assetid: ec19cd64-1789-40a3-b2db-dff2852b9d98
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3201
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a lista de parâmetros de modelo para o modelo de classe 'template' não coincide com a lista de parâmetros de modelo para o parâmetro de modelo 'template'  
  
 Você passou um modelo de classe no argumento para um modelo de classe que não utilize um parâmetro de modelo, ou você passou um número incompatível de argumentos de modelo para o argumento de modelo padrão.  
  
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