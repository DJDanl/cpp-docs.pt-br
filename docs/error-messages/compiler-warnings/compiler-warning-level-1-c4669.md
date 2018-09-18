---
title: Compilador aviso (nível 1) C4669 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4669
dev_langs:
- C++
helpviewer_keywords:
- C4669
ms.assetid: 97730679-e3dc-44d4-b2a8-aa65badc17f2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4f96bcf40b1fbc989daceabc810d019d1bb9aa98
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46060844"
---
# <a name="compiler-warning-level-1-c4669"></a>Compilador aviso (nível 1) C4669

'cast': conversão não segura: 'class' é um serviço ou objeto de tipo de WinRT

Uma conversão contém um tempo de execução do Windows ou um tipo gerenciado. O compilador conclui a conversão, executando uma cópia bit a bit de um ponteiro para o outro, mas não fornece nenhuma outra verificação. Para resolver este aviso, não converta as classes que contêm membros gerenciados ou tipos de tempo de execução do Windows.

O exemplo a seguir gera C4669 e mostra como corrigi-lo:

```
// C4669.cpp
// compile with: /clr /W1
ref struct A {
   int i;
   Object ^ pObj;   // remove the managed member to fix the warning
};

ref struct B {
   int j;
};

int main() {
   A ^ a = gcnew A;
   B ^ b = reinterpret_cast<B ^>(a);   // C4669
}
```