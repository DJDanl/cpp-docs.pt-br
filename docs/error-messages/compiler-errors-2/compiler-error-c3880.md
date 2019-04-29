---
title: Erro do compilador C3880
ms.date: 11/04/2016
f1_keywords:
- C3880
helpviewer_keywords:
- C3880
ms.assetid: b0e05d1e-32d0-4034-9246-f37d23573ea9
ms.openlocfilehash: 0b169309db88291f8a83b6d1192787b6396e84a5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62338461"
---
# <a name="compiler-error-c3880"></a>Erro do compilador C3880

'var': não pode ser um membro de dados literal

O tipo de um [literal](../../extensions/literal-cpp-component-extensions.md) atributo deve ser, ou podem ser convertidas em tempo de compilação para um dos seguintes tipos:

- tipo integral

- cadeia de caracteres

- enumeração com um tipo integral ou subjacente

O exemplo a seguir gera C3880:

```
// C3880.cpp
// compile with: /clr /c
ref struct Y1 {
   literal System::Decimal staticConst1 = 10;   // C3880
   literal int staticConst2 = 10;   // OK
};
```