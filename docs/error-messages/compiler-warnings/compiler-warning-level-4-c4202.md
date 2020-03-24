---
title: Aviso do compilador (nível 4) C4202
ms.date: 11/04/2016
f1_keywords:
- C4202
helpviewer_keywords:
- C4202
ms.assetid: 253293aa-97a3-4878-a2e8-c6cc9e20b1cb
ms.openlocfilehash: 8a449ee7650196d34d30df646ebdc333c1333af2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80161420"
---
# <a name="compiler-warning-level-4-c4202"></a>Aviso do compilador (nível 4) C4202

extensão não padrão usada: '... ': o parâmetro de protótipo na lista de nomes é inválido

Uma definição de função de estilo antigo contém argumentos variáveis. Essas definições geram um erro em compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)).

## <a name="example"></a>Exemplo

```c
// C4202.c
// compile with: /W4
void func( a, b, ...)   // C4202
int a, b;
{}

int main()
{
}
```
