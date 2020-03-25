---
title: Erro CXX0017 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0017
helpviewer_keywords:
- CAN0017
- CXX0017
ms.assetid: af74db02-a64d-49ca-8363-3e044a107580
ms.openlocfilehash: 64ebce0161d67c298d55095f6bc409820120c34a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80196008"
---
# <a name="expression-evaluator-error-cxx0017"></a>Erro CXX0017 (avaliador de expressão)

símbolo não encontrado

Não foi possível encontrar um símbolo especificado em uma expressão.

Uma possível causa desse erro é uma incompatibilidade entre maiúsculas e minúsculas no nome do símbolo. Como C e C++ são linguagens que diferenciam maiúsculas de minúsculas, um nome de símbolo deve ser fornecido no caso exato em que é definido na origem.

Esse erro pode ocorrer ao tentar conversão uma variável a fim de observar a variável durante a depuração. O `typedef` declara um novo nome para um tipo, mas não define um novo tipo. A tentativa de conversão no depurador requer o nome de um tipo definido.

Esse erro é idêntico a CAN0017.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Verifique se o símbolo já está declarado no ponto do programa em que ele está sendo usado.

1. Use um nome de tipo real para converter variáveis no depurador, em vez de um nome definido pelo `typedef`.
