---
title: Constantes de ação de sinal
ms.date: 11/04/2016
f1_keywords:
- SIG_IGN
- SIG_DFL
helpviewer_keywords:
- signal action constants
- SIG_IGN constant
- SIG_DFL constant
ms.assetid: c3cb4f15-d39e-4d9d-84f9-0d33e3eb5993
ms.openlocfilehash: a7448730501d6f3b50008966134f708ae99ddb5b
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88830755"
---
# <a name="signal-action-constants"></a>Constantes de ação de sinal

A ação tomada quando o sinal de interrupção for recebido depende do valor de `func`.

## <a name="syntax"></a>Sintaxe

```
#include <signal.h>
```

## <a name="remarks"></a>Comentários

O argumento `func` deve ser um endereço de função ou uma das constantes de manifesto listados abaixo e definido no SIGNAL.H.

|Constante|DESCRIÇÃO|
|-|-|
| `SIG_DFL`  | Usa a resposta padrão do sistema. Se o programa de chamada usa e/s de fluxo, buffers criados pela biblioteca em tempo de execução não são liberados.  |
| `SIG_IGN`  | Ignora o sinal de interrupção. Esse valor nunca deve ser fornecido para `SIGFPE`, uma vez que o estado de ponto flutuante do processo é deixado indefinido.  |
| `SIG_SGE`  | Indica que ocorreu um erro no sinal.  |
| `SIG_ACK`  | Indica que uma confirmação foi recebida.  |
| `SIG_ERR`  | Um tipo de retorno de um sinal que indica que um erro ocorreu.  |

## <a name="see-also"></a>Confira também

[signal](../c-runtime-library/reference/signal.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)
