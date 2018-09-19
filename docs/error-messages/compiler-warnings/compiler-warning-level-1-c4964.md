---
title: Compilador aviso (nível 1) C4964 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4964
dev_langs:
- C++
helpviewer_keywords:
- C4964
ms.assetid: b89c9274-8a92-4b7c-aa30-3fbb1b68ac73
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7f1644e4603bae36ec9d407294dea78a27e60539
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46086662"
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