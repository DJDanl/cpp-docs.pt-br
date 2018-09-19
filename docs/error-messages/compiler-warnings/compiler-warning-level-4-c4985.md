---
title: Compilador aviso (nível 4) C4985 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
dev_langs:
- C++
helpviewer_keywords:
- C4985
ms.assetid: 832f001c-afe7-403d-a8b4-02334724c79e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4d67b7394ef9bd38409ca45abe6ed7d347f5a37d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46092655"
---
# <a name="compiler-warning-level-4-c4985"></a>Compilador aviso (nível 4) C4985

'nome do símbolo': atributos não presentes em declaração anterior.

As anotações de SAL (linguagem) de anotação do código-fonte código na definição ou declaração de método atual diferem das anotações em uma declaração anterior. As anotações de SAL mesmas devem ser usadas na definição e as declarações de um método.

O SAL fornece um conjunto de anotações que você pode usar para descrever como uma função usa seus parâmetros, as premissas faz sobre eles e as garantias terminar. As anotações são definidas no arquivo de cabeçalho de sal.

Observe que as macros SAL não expandirá a menos que o projeto tem o [/ANALYZE](../../build/reference/analyze-code-analysis.md) sinalizador especificado. Quando você especifica **/ANALYZE**, o compilador pode gerar C4985, mesmo se nenhum aviso ou erro apareceu sem **/ANALYZE**.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Use as anotações de SAL mesmas na definição de um método e todas as suas declarações.

## <a name="see-also"></a>Consulte também

[Anotações de SAL](../../c-runtime-library/sal-annotations.md)