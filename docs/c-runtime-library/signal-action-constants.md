---
title: Constantes de ação de sinal | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- SIG_IGN
- SIG_DFL
dev_langs:
- C++
helpviewer_keywords:
- signal action constants
- SIG_IGN constant
- SIG_DFL constant
ms.assetid: c3cb4f15-d39e-4d9d-84f9-0d33e3eb5993
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8f2cb8e8ca907081e85be03d7576d0252cdf20ad
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46081306"
---
# <a name="signal-action-constants"></a>Constantes de ação de sinal

A ação tomada quando o sinal de interrupção for recebido depende do valor de `func`.

## <a name="syntax"></a>Sintaxe

```
#include <signal.h>
```

## <a name="remarks"></a>Comentários

O argumento `func` deve ser um endereço de função ou uma das constantes de manifesto listados abaixo e definido no SIGNAL.H.

|||
|-|-|
| `SIG_DFL`  | Usa a resposta padrão do sistema. Se o programa de chamada usa e/s de fluxo, buffers criados pela biblioteca em tempo de execução não são liberados.  |
| `SIG_IGN`  | Ignora o sinal de interrupção. Esse valor nunca deve ser fornecido para `SIGFPE`, uma vez que o estado de ponto flutuante do processo é deixado indefinido.  |
| `SIG_SGE`  | Indica que ocorreu um erro no sinal.  |
| `SIG_ACK`  | Indica que uma confirmação foi recebida.  |
| `SIG_ERR`  | Um tipo de retorno de um sinal que indica que um erro ocorreu.  |

## <a name="see-also"></a>Consulte também

[signal](../c-runtime-library/reference/signal.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)