---
title: Erro das LNK1179 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1179
dev_langs:
- C++
helpviewer_keywords:
- LNK1179
ms.assetid: 4b1536d7-0d3d-4f29-a9c1-6fa5cf6cb665
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d22ebb329d390d44aea44ff9dc6f3bf2f86a1d26
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46117446"
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