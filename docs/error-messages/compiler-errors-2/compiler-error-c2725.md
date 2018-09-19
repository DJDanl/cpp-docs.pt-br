---
title: Erro do compilador C2725 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2725
dev_langs:
- C++
helpviewer_keywords:
- C2725
ms.assetid: 13cd5b1b-e906-4cd8-9b2b-510d587c665a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 969ddd9343073dff3732204eb4b17375bb5ab9cc
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46056034"
---
# <a name="compiler-error-c2725"></a>Erro do compilador C2725

'exceções': não é possível usar throw ou catch gerenciado ou WinRT objeto por valor ou referência

O tipo de um ou uma exceção do WinRT não está correta.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2725 e mostra como corrigi-lo.

```
// C2725.cpp
// compile with: /clr
ref class R {
public:
   int i;
};

int main() {
   R % r1 = *gcnew R;
   throw r1;   // C2725

   R ^ r2 = gcnew R;
   throw r2;   // OK
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2725 e mostra como corrigi-lo.

```
// C2725b.cpp
// compile with: /clr
using namespace System;
int main() {
   try {}
   catch( System::Exception%) {}   // C2725
   // try the following line instead
   // catch( System::Exception ^e) {}
}
```
