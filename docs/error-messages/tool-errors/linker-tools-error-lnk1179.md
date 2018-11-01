---
title: Erro das Ferramentas de Vinculador LNK1179
ms.date: 11/04/2016
f1_keywords:
- LNK1179
helpviewer_keywords:
- LNK1179
ms.assetid: 4b1536d7-0d3d-4f29-a9c1-6fa5cf6cb665
ms.openlocfilehash: 71aba1f20cfaf5b6b9ec33d43ebde594e381921f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50594084"
---
# <a name="linker-tools-error-lnk1179"></a>Erro das Ferramentas de Vinculador LNK1179

arquivo inválido ou corrompido: duplicate COMDAT 'filename'

Um módulo de objeto contém duas ou mais COMDATs com o mesmo nome.

Esse erro pode ser causado por meio [/H](../../build/reference/h-restrict-length-of-external-names.md), que limita o comprimento dos nomes externos, e [/Gy](../../build/reference/gy-enable-function-level-linking.md), que empacota funções em COMDATs.

## <a name="example"></a>Exemplo

No código a seguir `function1` e `function2` são idênticos em oito primeiros caracteres. Compilando com **/Gy** e **/H8** produz um erro de link.

```
void function1(void);
void function2(void);

int main() {
    function1();
    function2();
}

void function1(void) {}
void function2(void) {}
```