---
title: Erro do compilador C3168
ms.date: 11/04/2016
f1_keywords:
- C3168
helpviewer_keywords:
- C3168
ms.assetid: 4c36fcfb-c351-48ff-b4eb-78d2aa1b4d55
ms.openlocfilehash: f39160cc09825c6d87d56ff5ba80d21a35f41e12
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62174153"
---
# <a name="compiler-error-c3168"></a>Erro do compilador C3168

'type': tipo subjacente inválido para enumeração

Subjacente de tipo especificado para o `enum` tipo não era válido. O tipo subjacente deve ser um tipo integral de C++ ou um tipo CLR correspondente.

O exemplo a seguir gera C3168:

```
// C3168.cpp
// compile with: /clr /c
ref class G{};

enum class E : G { e };   // C3168
enum class F { f };   // OK
```
