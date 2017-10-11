---
title: C3205 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3205
dev_langs:
- C++
helpviewer_keywords:
- C3205
ms.assetid: 802d306e-5ff3-4491-8a22-c5f1c072d005
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 46b42d19bd42bafbb6baf6b8af368bd10c9dd1ec
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

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
