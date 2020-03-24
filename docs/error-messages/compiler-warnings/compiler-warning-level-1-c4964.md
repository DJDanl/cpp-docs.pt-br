---
title: Aviso do compilador (nível 1) C4964
ms.date: 11/04/2016
f1_keywords:
- C4964
helpviewer_keywords:
- C4964
ms.assetid: b89c9274-8a92-4b7c-aa30-3fbb1b68ac73
ms.openlocfilehash: 7852340bc056e126238a2d9c7493887ef3caf93e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174486"
---
# <a name="compiler-warning-level-1-c4964"></a>Aviso do compilador (nível 1) C4964

Nenhuma opção de otimização foi especificada; as informações de perfil não serão coletadas

[/GL](../../build/reference/gl-whole-program-optimization.md) e [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) foram especificados, mas nenhuma otimização foi solicitada, portanto, nenhum arquivo. PGC será gerado e, portanto, nenhuma otimização guiada por perfil será possível.

Se você quiser que os arquivos. pgc sejam gerados quando você executar o aplicativo, especifique uma das opções do compilador [/o](../../build/reference/o-options-optimize-code.md) .

O exemplo a seguir gera C4964:

```cpp
// C4964.cpp
// compile with: /W1 /GL /link /ltcg:pgi
// C4964 expected
// Add /O2, for example, to the command line to resolve this warning.
int main() {
   int i;
}
```
