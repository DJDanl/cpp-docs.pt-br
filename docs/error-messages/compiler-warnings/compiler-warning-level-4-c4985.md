---
title: Aviso do compilador (nível 4) C4985
ms.date: 11/04/2016
f1_keywords:
- C4985
helpviewer_keywords:
- C4985
ms.assetid: 832f001c-afe7-403d-a8b4-02334724c79e
ms.openlocfilehash: 75feda6fb2c88b663aa6ade0efdfffc7def1568f
ms.sourcegitcommit: 8762a3f9b5476b4dee03f0ee8064ea606550986e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/04/2019
ms.locfileid: "74810725"
---
# <a name="compiler-warning-level-4-c4985"></a>Aviso do compilador (nível 4) C4985

' Symbol Name ': atributos não presentes na declaração anterior.

As anotações de SAL (linguagem de anotação de código-fonte) da Microsoft na declaração ou na definição do método atual diferem das anotações em uma declaração anterior. As mesmas anotações de SAL devem ser usadas na definição e nas declarações de um método.

O SAL fornece um conjunto de anotações que você pode usar para descrever como uma função usa seus parâmetros, as suposições que ele faz sobre eles e as garantias que ele faz na conclusão. As anotações são definidas no arquivo de cabeçalho sal. h.

Observe que as macros SAL não serão expandidas, a menos que o projeto tenha o sinalizador [/Analyze](../../build/reference/analyze-code-analysis.md) especificado. Quando você especifica **/Analyze**, o compilador pode lançar C4985, mesmo que nenhum aviso ou erro apareça sem **/Analyze**.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

1. Use as mesmas anotações de SAL na definição de um método e de todas as suas declarações.

## <a name="see-also"></a>Consulte também

[Anotações de SAL](../../c-runtime-library/sal-annotations.md)