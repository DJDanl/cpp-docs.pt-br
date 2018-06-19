---
title: C3672 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3672
dev_langs:
- C++
helpviewer_keywords:
- C3672
ms.assetid: da971041-1766-467a-aecf-1d8655c6cb7a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: aaea09d89c192a1820c2a384144ce758fde90476
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33263941"
---
# <a name="compiler-error-c3672"></a>C3672 de erro do compilador
expressão de pseudo-destruidor só pode ser usado como parte de uma chamada de função  
  
 Um destruidor foi chamado incorretamente.  Para obter mais informações, consulte [Destruidores](../../cpp/destructors-cpp.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3672.  
  
```  
// C3672.cpp  
template<typename T>  
void f(T* pT) {  
   &pT->T::~T;   // C3672  
   pT->T::~T();   // OK  
};  
  
int main() {  
   int i;  
   f(&i);  
}  
```