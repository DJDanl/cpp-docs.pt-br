---
title: Aviso LNK4217 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4217
helpviewer_keywords:
- LNK4217
ms.assetid: 280dc03e-5933-4e8d-bb8c-891fbe788738
ms.openlocfilehash: 12766241832d39f0b47ed85036c0ebeb0447fc75
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50448042"
---
# <a name="linker-tools-warning-lnk4217"></a>Aviso LNK4217 (Ferramentas de Vinculador)

definidas localmente o símbolo 'symbol' importado na função 'function'

[__declspec(DllImport)](../../cpp/dllexport-dllimport.md) foi especificado para um símbolo, embora o símbolo é definido localmente. Remover o `__declspec` modificador para resolver este aviso.

`symbol` é o nome do símbolo que é definido dentro da imagem. `function` é a função que está importando o símbolo.

Esse aviso não aparecerá quando você compila usando a opção [/clr](../../build/reference/clr-common-language-runtime-compilation.md).

LNK4217 também pode ocorrer se você tentar vincular os dois módulos juntas, quando em vez disso, você deve compilar o segundo módulo com a biblioteca de importação do módulo primeiro.

```
// LNK4217.cpp
// compile with: /LD
#include "windows.h"
__declspec(dllexport) void func(unsigned short*) {}
```

E, em seguida,

```
// LNK4217b.cpp
// compile with: /c
#include "windows.h"
__declspec(dllexport) void func(unsigned short*) {}
```

A tentativa de vincular esses dois módulos resultará em LNK4217, compile o segundo exemplo com a biblioteca de importação da primeira amostra para resolver.