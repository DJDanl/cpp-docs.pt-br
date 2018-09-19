---
title: Compilador aviso (nível 4) C4001 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4001
dev_langs:
- C++
helpviewer_keywords:
- C4001
ms.assetid: 414a47fe-d597-425e-9374-6a569231dc0a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c325656b9e61ee324a3b9f171413f1020440f9ab
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46025406"
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