---
title: C3205 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3205
dev_langs:
- C++
helpviewer_keywords:
- C3205
ms.assetid: 802d306e-5ff3-4491-8a22-c5f1c072d005
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3419643e846bab394ab032dc428d4f06a1040164
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33249703"
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