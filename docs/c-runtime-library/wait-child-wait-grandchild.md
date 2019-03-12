---
title: _WAIT_CHILD, _WAIT_GRANDCHILD
ms.date: 11/04/2016
f1_keywords:
- _WAIT_GRANDCHILD
- WAIT_CHILD
- WAIT_GRANDCHILD
- _WAIT_CHILD
helpviewer_keywords:
- WAIT_CHILD constant
- WAIT_GRANDCHILD constant
- _WAIT_CHILD constant
- _WAIT_GRANDCHILD constant
ms.assetid: 7acd96fa-d118-4339-bb00-e5afaf286945
ms.openlocfilehash: 98858058add6a0a11d4f9331989c6816e38130aa
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57745057"
---
# <a name="waitchild-waitgrandchild"></a>_WAIT_CHILD, _WAIT_GRANDCHILD

## <a name="syntax"></a>Sintaxe

```
#include <process.h>
```

## <a name="remarks"></a>Comentários

A função `_cwait` pode ser usada por qualquer processo para aguardar algum outro processo (se a ID do processo for conhecida). O argumento de ação pode ser um dos seguintes valores:

|Constante|Significado|
|--------------|-------------|
|`_WAIT_CHILD`|O processo de chamada aguarda até que o novo processo especificado seja encerrado.|
|`_WAIT_GRANDCHILD`|O processo de chamada aguarda até que o novo processo especificado e todos os processos criados pelo novo processo sejam encerrados.|

## <a name="see-also"></a>Consulte também

[_cwait](../c-runtime-library/reference/cwait.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)
