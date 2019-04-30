---
title: Compilador aviso (nível 4) C4001
ms.date: 11/04/2016
f1_keywords:
- C4001
helpviewer_keywords:
- C4001
ms.assetid: 414a47fe-d597-425e-9374-6a569231dc0a
ms.openlocfilehash: dd18dc27ee13eab05ea0253c8ebcc990105c15c9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401482"
---
# <a name="compiler-warning-level-4-c4001"></a>Compilador aviso (nível 4) C4001

extensão não padrão 'comentário de linha única' foi usado

> [!NOTE]
> Esse aviso é removido no Visual Studio 2017 versão 15.5, como comentários de linha única são padrão em C99.

Comentários de linha única estão em C++ padrão e em C começando com C99.
Em compatibilidade de ANSI estrita ([/Za](../../build/reference/za-ze-disable-language-extensions.md)), arquivos de C que contêm comentários de linha única, gerar C4001 devido ao uso de uma extensão não padrão. Como os comentários de linha única são padrão em C++, que contém comentários de linha única de arquivos de C não produzem C4001 ao compilar com extensões da Microsoft (/Ze).

## <a name="example"></a>Exemplo

Para desabilitar o aviso, remova [#pragma warning(disable:4001)](../../preprocessor/warning.md).

```
// C4001.cpp
// compile with: /W4 /Za /TC
// #pragma warning(disable:4001)
int main()
{
   // single-line comment in main
   // C4001
}
```