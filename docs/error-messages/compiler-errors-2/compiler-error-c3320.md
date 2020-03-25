---
title: Erro do compilador C3320
ms.date: 11/04/2016
f1_keywords:
- C3320
helpviewer_keywords:
- C3320
ms.assetid: 2ef72d9a-1f1d-4b2e-b244-9fd3f3e70cb6
ms.openlocfilehash: 0289d49ebbb0e30153beb6b0b2bc758bff5ef118
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201299"
---
# <a name="compiler-error-c3320"></a>Erro do compilador C3320

' type ': o tipo não pode ter o mesmo nome que a propriedade ' name ' do módulo

Um UDT (tipo definido pelo usuário) exportado, que pode ser uma struct, Class, enum ou Union, não pode ter o mesmo nome que o parâmetro passado para a propriedade Name do atributo de [módulo](../../windows/module-cpp.md) .

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3320:

```cpp
// C3320.cpp
#include "unknwn.h"
[module(name="xx")];

[export] struct xx {   // C3320
// Try the following line instead
// [export] struct yy {
   int i;
};
```
