---
title: Erro do compilador C3050
ms.date: 11/04/2016
f1_keywords:
- C3050
helpviewer_keywords:
- C3050
ms.assetid: ee090a0b-29cc-4215-a2f9-d82af79b8e82
ms.openlocfilehash: 255647a2e603b5a71855374dba3248ffef1e025e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62187453"
---
# <a name="compiler-error-c3050"></a>Erro do compilador C3050

'type1': uma classe ref não pode herdar de 'type1'

`System::ValueType` não pode ser uma classe base para um tipo de referência.

O exemplo a seguir gera C3050:

```
// C3050.cpp
// compile with: /clr /LD
ref struct X : System::ValueType {};   // C3050
ref struct Y {};   // OK
```