---
title: Aviso LNK4217 (Ferramentas de Vinculador)
ms.date: 04/15/2019
f1_keywords:
- LNK4217
helpviewer_keywords:
- LNK4217
ms.assetid: 280dc03e-5933-4e8d-bb8c-891fbe788738
ms.openlocfilehash: f1ea3cd0a8770571ae5c55d29a901c134311550f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410220"
---
# <a name="linker-tools-warning-lnk4217"></a>Aviso LNK4217 (Ferramentas de Vinculador)

> símbolo de '*símbolo*'definido em'*filename_1.obj*'é importado por'*filename_2.obj*'na função'*função*'

[__declspec(DllImport)](../../cpp/dllexport-dllimport.md) foi especificado para um símbolo, embora o símbolo é definido em um arquivo de objetos na mesma imagem. Remover o `__declspec(dllimport)` modificador para resolver este aviso.

## <a name="remarks"></a>Comentários

*símbolo* é o nome do símbolo que é definido dentro da imagem. *função* é a função que está importando o símbolo.

Esse aviso não aparece quando você compila usando o [/clr](../../build/reference/clr-common-language-runtime-compilation.md) opção.

LNK4217 também pode ocorrer se você tentar vincular os dois módulos juntas, quando em vez disso, você deve compilar o segundo módulo com a biblioteca de importação do módulo primeiro.

```cpp
// LNK4217.cpp
// compile with: /LD
#include "windows.h"
__declspec(dllexport) void func(unsigned short*) {}
```

E, em seguida,

```cpp
// LNK4217b.cpp
// compile with: /c
#include "windows.h"
__declspec(dllexport) void func(unsigned short*) {}
```

A tentativa de vincular esses dois módulos resultará em LNK4217. Compile o segundo exemplo com a biblioteca de importação da primeira amostra para resolver.

## <a name="see-also"></a>Consulte também

[Aviso LNK4049 ferramentas de vinculador](linker-tools-warning-lnk4049.md) \
[Aviso LNK4286 ferramentas de vinculador](linker-tools-warning-lnk4286.md) \
[dllexport, dllimport](../../cpp/dllexport-dllimport.md)