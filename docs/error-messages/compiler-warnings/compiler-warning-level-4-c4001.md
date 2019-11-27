---
title: Aviso do compilador (nível 4) C4001
ms.date: 11/04/2016
f1_keywords:
- C4001
helpviewer_keywords:
- C4001
ms.assetid: 414a47fe-d597-425e-9374-6a569231dc0a
ms.openlocfilehash: fc4ae55c5d25719e930a7435e0f9bf3ee2071a21
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541636"
---
# <a name="compiler-warning-level-4-c4001"></a>Aviso do compilador (nível 4) C4001

a extensão não padrão ' comentário de linha única ' foi usada

> [!NOTE]
> Esse aviso é removido no Visual Studio 2017 versão 15,5 porque os comentários de linha única são padrão em C99.

Os comentários de linha única são Standard C++ e Standard em C, começando com C99.
Em[/za](../../build/reference/za-ze-disable-language-extensions.md)(compatibilidade ANSI estrita), os arquivos C que contêm comentários de linha única, geram C4001 devido ao uso de uma extensão não padrão. Como os comentários de linha única são padrão C++no, os arquivos C que contêm comentários de linha única não produzem C4001 durante a compilação com extensões da Microsoft (/Ze).

## <a name="example"></a>Exemplo

Para desabilitar o aviso, remova a marca de comentário [#pragma Aviso (desabilitar: 4001)](../../preprocessor/warning.md).

```cpp
// C4001.cpp
// compile with: /W4 /Za /TC
// #pragma warning(disable:4001)
int main()
{
   // single-line comment in main
   // C4001
}
```