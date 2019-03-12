---
title: Constantes spawn
ms.date: 11/04/2016
f1_keywords:
- _P_NOWAIT
- _P_OVERLAY
- _P_WAIT
- _P_DETACH
- _P_NOWAITO
helpviewer_keywords:
- _P_OVERLAY constant
- P_DETACH constant
- P_OVERLAY constant
- P_NOWAIT constant
- _P_DETACH constant
- _P_NOWAIT constant
- _P_NOWAITO constant
- P_NOWAITO constant
- spawn constants
- P_WAIT constant
- _P_WAIT constant
ms.assetid: e0533e88-d362-46fc-b53c-5f193226d879
ms.openlocfilehash: 988cc5e1b982f0c5577db77ae94f1df46c95ec0e
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57742762"
---
# <a name="spawn-constants"></a>Constantes spawn

## <a name="syntax"></a>Sintaxe

```
#include <process.h>
```

## <a name="remarks"></a>Comentários

O argumento `mode` determina a ação tomada pelo processo de chamada antes e durante uma operação de spawn. Os seguintes valores para `mode` são possíveis:

|Constante|Significado|
|--------------|-------------|
|`_P_OVERLAY`|Sobrepõe processo de chamada com um novo processo, que é destruído (o mesmo efeito resultante de chamadas `_exec`).|
|`_P_WAIT`|Suspende um thread de chamada até que a execução do novo processo seja concluída (`_spawn` síncrono).|
|`_P_NOWAIT`, `_P_NOWAITO`|Continua a executar um processo de chamada simultaneamente com o novo processo (`_spawn` assíncrono).|
|`_P_DETACH`|Continua a executar o processo de chamada; o novo processo é executado em segundo plano sem acesso ao console ou ao teclado. Chamadas para `_cwait` no novo processo falhará. Está é uma `_spawn` assíncrona.|

## <a name="see-also"></a>Consulte também

[Funções _spawn, _wspawn](../c-runtime-library/spawn-wspawn-functions.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)
