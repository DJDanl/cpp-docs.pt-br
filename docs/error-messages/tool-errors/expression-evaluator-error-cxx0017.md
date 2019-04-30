---
title: Erro CXX0017 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0017
helpviewer_keywords:
- CAN0017
- CXX0017
ms.assetid: af74db02-a64d-49ca-8363-3e044a107580
ms.openlocfilehash: bbf16ae9a503a8525edb42d6bf1fc4336c3f5267
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62397127"
---
# <a name="expression-evaluator-error-cxx0017"></a>Erro CXX0017 (avaliador de expressão)

símbolo não encontrado

Não foi possível encontrar um símbolo especificado em uma expressão.

Uma possível causa desse erro é uma incompatibilidade de caso do nome do símbolo. Como C e C++ são linguagens diferencia maiusculas de minúsculas, um nome de símbolo deve ser fornecido em diferencie maiusculas de minúsculas no qual ele é definido na fonte.

Esse erro pode ocorrer durante a tentativa de conversão de tipo uma variável para assisti a variável durante a depuração. O `typedef` declara um novo nome para um tipo, mas não define um novo tipo. A conversão de tipo tentada no depurador requer um nome de um tipo definido.

Esse erro é idêntico ao CAN0017.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Verifique se que o símbolo já está declarado no ponto no programa onde ele está sendo usado.

1. Use um nome de tipo real para converter variáveis no depurador, em vez de um `typedef`-nome definido.