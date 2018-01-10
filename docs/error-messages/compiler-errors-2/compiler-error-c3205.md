---
title: C3205 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3205
dev_langs: C++
helpviewer_keywords: C3205
ms.assetid: 802d306e-5ff3-4491-8a22-c5f1c072d005
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e86f78c5c473b1722e3a3738c1f96b5f5133d3b0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3205"></a>C3205 de erro do compilador
lista de argumentos para o parâmetro de modelo 'parameter' está ausente  
  
Um [modelo](../../cpp/templates-cpp.md) parâmetro está ausente.  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3205:  
  
```cpp  
// C3205.cpp  
template<template<class> class T> struct A {  
   typedef T unparameterized_type;   // C3205  
   // try the following line instead  
   // typedef T<int> unparameterized_type;  
};  
  
template <class T>  
struct B {  
   typedef int value_type;  
};  
  
int main() {  
   A<B> x;  
}  
```