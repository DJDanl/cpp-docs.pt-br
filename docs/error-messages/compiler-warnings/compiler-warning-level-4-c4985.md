---
title: Aviso do compilador (nível 4) C4985
ms.date: 11/04/2016
f1_keywords:
- C4985
helpviewer_keywords:
- C4985
ms.assetid: 832f001c-afe7-403d-a8b4-02334724c79e
ms.openlocfilehash: 87537e960c858cc6741108cf191fbeb2a7a2a8d7
ms.sourcegitcommit: 6e55aeb538b1c39af754f82d6f7738a18f5aa031
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/29/2020
ms.locfileid: "87390007"
---
# <a name="compiler-warning-level-4-c4985"></a>Aviso do compilador (nível 4) C4985

> '*Symbol-Name*': atributos não presentes na declaração anterior.

As anotações de SAL (linguagem de anotação de código-fonte) da Microsoft na declaração ou na definição do método atual diferem das anotações em uma declaração anterior. As mesmas anotações de SAL devem ser usadas na definição e nas declarações de um método.

O SAL fornece um conjunto de anotações que você pode usar para descrever como uma função usa seus parâmetros, as suposições que ele faz sobre eles e as garantias que ele faz na conclusão. As anotações são definidas no arquivo de cabeçalho sal. h.

Observe que as macros SAL não serão expandidas, a menos que o projeto tenha o [`/analyze`](../../build/reference/analyze-code-analysis.md) sinalizador especificado. Quando você especifica **`/analyze`** , o compilador pode lançar C4985, mesmo que nenhum aviso ou erro seja exibido sem **`/analyze`** .

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Use as mesmas anotações de SAL na definição de um método e de todas as suas declarações.

## <a name="see-also"></a>Confira também

[Anotações de SAL](../../c-runtime-library/sal-annotations.md)
