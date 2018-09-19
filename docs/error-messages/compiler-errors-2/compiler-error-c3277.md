---
title: Erro do compilador C3277 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3277
dev_langs:
- C++
helpviewer_keywords:
- C3277
ms.assetid: 8ac5f476-e30c-4879-92c6-f03cdbd74045
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5a346f6b2abce22a1238a1f9bc6f8ea9f961cb43
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46059051"
---
# <a name="compiler-error-c3277"></a>Erro do compilador C3277

não é possível definir uma enumeração não gerenciada 'enum' dentro de 'tipo' gerenciado

Uma enumeração estava definida incorretamente dentro de um tipo gerenciado.

O exemplo a seguir gera C3277:

```
// C3277a.cpp
// compile with: /clr
ref class A
{
   enum E {e1,e2};   // C3277
   // try the following line instead
   // enum class E {e1,e2};
};

int main()
{
}
```
