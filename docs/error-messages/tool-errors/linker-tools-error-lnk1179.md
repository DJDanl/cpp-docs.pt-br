---
title: Erro das Ferramentas de Vinculador LNK1179
ms.date: 11/04/2016
f1_keywords:
- LNK1179
helpviewer_keywords:
- LNK1179
ms.assetid: 4b1536d7-0d3d-4f29-a9c1-6fa5cf6cb665
ms.openlocfilehash: a267019f1be08cc8dcffdff3b4ba0b73357cccd4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183951"
---
# <a name="linker-tools-error-lnk1179"></a>Erro das Ferramentas de Vinculador LNK1179

arquivo inválido ou corrompido: duplicado COMDAT ' FileName '

Um módulo de objeto contém dois ou mais COMDATs com o mesmo nome.

Esse erro pode ser causado pelo uso de [/h](../../build/reference/h-restrict-length-of-external-names.md), que limita o comprimento de nomes externos e [/GY](../../build/reference/gy-enable-function-level-linking.md), que agrupa funções em COMDATs.

## <a name="example"></a>Exemplo

No código a seguir, `function1` e `function2` são idênticos nos oito primeiros caracteres. A compilação com **/GY** e **/H8** produz um erro de link.

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
