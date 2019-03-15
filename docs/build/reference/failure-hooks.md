---
title: Ganchos de falha
ms.date: 11/04/2016
helpviewer_keywords:
- delayed loading of DLLs, failure hooks
ms.assetid: 12bb303b-ffe6-4471-bffe-9ef4f8bb2d30
ms.openlocfilehash: 2fc22ae77d729868adbf8c37d40e450e35a8e866
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57811986"
---
# <a name="failure-hooks"></a>Ganchos de falha

O gancho de falha está habilitado da mesma maneira que o [gancho de notificação](notification-hooks.md). As necessidades de rotina de gancho para retornar um valor adequado para que o processamento podem continuar (um HINSTANCE ou FARPROC) ou 0 para indicar que uma exceção deve ser gerada.

A variável de ponteiro que refere-se para a função definida pelo usuário é:

```
// This is the failure hook, dliNotify = {dliFailLoadLib|dliFailGetProc}
ExternC
PfnDliHook   __pfnDliFailureHook2;
```

O **DelayLoadInfo** estrutura contém todos os dados pertinentes necessários para relatórios precisos do erro, incluindo o valor de `GetLastError`.

Se a notificação for **dliFailLoadLib**, a função de gancho pode retornar:

- 0, se ele não pode lidar com falhas.

- Um HMODULE, se o gancho falha corrigiu o problema e carregar a biblioteca em si.

Se a notificação for **dliFailGetProc**, a função de gancho pode retornar:

- 0, se ele não pode lidar com falhas.

- Um endereço de proc válido (endereço de função de importação), se a falha de gancho teve êxito ao obter o endereço em si.

## <a name="see-also"></a>Consulte também

[Tratamento de erro e notificação](error-handling-and-notification.md)
