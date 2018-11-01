---
title: Coprocessador de ponto flutuante e convenções de chamada
ms.date: 11/04/2016
helpviewer_keywords:
- floating-point numbers [C++]
- floating-point coprocessor
ms.assetid: 3cc6615a-b308-4cf7-9570-83e192a832b3
ms.openlocfilehash: 7e9184d66bde26ab0e2b345f8f10c2e28619fd2b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50625102"
---
# <a name="floating-point-coprocessor-and-calling-conventions"></a>Coprocessador de ponto flutuante e convenções de chamada

Se você estiver escrevendo assembly rotinas para flutuante coprocessador de ponto, você deve preservar flutuante palavra de controle de ponto e limpar a pilha do coprocessador a menos que você está retornando um **float** ou **duplo** valor (que sua função deve retornar no ST(0)).

## <a name="see-also"></a>Consulte também

[Convenções de chamada](../cpp/calling-conventions.md)