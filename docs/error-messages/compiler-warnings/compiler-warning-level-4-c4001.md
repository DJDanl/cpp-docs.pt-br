---
title: Aviso do compilador (nível 4) C4001
ms.date: 11/04/2016
f1_keywords:
- C4001
helpviewer_keywords:
- C4001
ms.assetid: 414a47fe-d597-425e-9374-6a569231dc0a
ms.openlocfilehash: ceb7e65a292e5b9e9ef960ca9553183b703c93f0
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991689"
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
