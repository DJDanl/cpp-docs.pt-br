---
title: Compilador aviso (nível 1) C4964
ms.date: 11/04/2016
f1_keywords:
- C4964
helpviewer_keywords:
- C4964
ms.assetid: b89c9274-8a92-4b7c-aa30-3fbb1b68ac73
ms.openlocfilehash: 556c6e0963fc41d76cd123373cc4cd85edc66962
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62384134"
---
# <a name="compiler-warning-level-1-c4964"></a>Compilador aviso (nível 1) C4964

Não há opções de otimização foram especificadas; informações de perfil não serão coletadas

[/GL](../../build/reference/gl-whole-program-optimization.md) e [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) foram especificados, mas sem otimizações foram solicitados, portanto, nenhum arquivo. PGC será gerado e, portanto, não será possível nenhuma Otimização Guiada por perfil.

Se você quiser arquivos. PGC para ser gerado quando você executar o aplicativo, especifique um dos [/O](../../build/reference/o-options-optimize-code.md) opções do compilador.

O exemplo a seguir gera C4964:

```
// C4964.cpp
// compile with: /W1 /GL /link /ltcg:pgi
// C4964 expected
// Add /O2, for example, to the command line to resolve this warning.
int main() {
   int i;
}
```