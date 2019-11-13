---
title: Aviso do compilador (nível 3) C4359
ms.date: 11/04/2016
f1_keywords:
- C4359
helpviewer_keywords:
- C4359
ms.assetid: d8fe993c-ef82-45a0-a43d-c29f9d1bacdb
ms.openlocfilehash: 7da4d231a341f8d4d4e8c1e82fc1fc8b9893778a
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051603"
---
# <a name="compiler-warning-level-3-c4359"></a>Aviso do compilador (nível 3) C4359

' type ': o alinhamento real (8) é maior que o valor especificado em __declspec (align ())

O alinhamento especificado para um tipo é menor do que o alinhamento do tipo de um de seus membros de dados.  Para obter mais informações, consulte [alinhar](../../cpp/align-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4359.

```cpp
// C4359.cpp
// compile with: /W3 /c
struct __declspec(align(8)) C8 { __int64 i; };
struct __declspec(align(4)) C4  { C8 m8; };   // C4359
struct __declspec(align(8)) C8_b  { C8 m8; };   // OK
struct __declspec(align(16)) C16  { C8 m8; };   // OK
```