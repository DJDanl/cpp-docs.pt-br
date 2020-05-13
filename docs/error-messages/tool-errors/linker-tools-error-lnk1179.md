---
title: Erro das Ferramentas de Vinculador LNK1179
ms.date: 11/04/2016
f1_keywords:
- LNK1179
helpviewer_keywords:
- LNK1179
ms.assetid: 4b1536d7-0d3d-4f29-a9c1-6fa5cf6cb665
ms.openlocfilehash: d85693cec11ef53a6bbbb60d8ced716d2a0bb131
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754339"
---
# <a name="linker-tools-error-lnk1179"></a>Erro das Ferramentas de Vinculador LNK1179

arquivo inválido ou corrompido: duplicar o 'nome de arquivo' do COMDAT

Um módulo de objeto contém dois ou mais COMDATs com o mesmo nome.

Esse erro pode ser causado pelo uso [de /H](../../build/reference/h-restrict-length-of-external-names.md), que limita o comprimento dos nomes externos, e [/Gy](../../build/reference/gy-enable-function-level-linking.md), que embala funções em COMDATs.

## <a name="example"></a>Exemplo

No código a `function1` `function2` seguir, e são idênticos nos primeiros oito caracteres. Compilar com **/Gy** e **/H8** produz um erro de link.

```cpp
void function1(void);
void function2(void);

int main() {
    function1();
    function2();
}

void function1(void) {}
void function2(void) {}
```
