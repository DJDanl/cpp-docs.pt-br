---
title: Ganchos de falha | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- delayed loading of DLLs, failure hooks
ms.assetid: 12bb303b-ffe6-4471-bffe-9ef4f8bb2d30
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e4c69759034dbb7233970bd89616a062a369cc13
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45721273"
---
# <a name="failure-hooks"></a>Ganchos de falha

O gancho de falha está habilitado da mesma maneira que o [gancho de notificação](../../build/reference/notification-hooks.md). As necessidades de rotina de gancho para retornar um valor adequado para que o processamento podem continuar (um HINSTANCE ou FARPROC) ou 0 para indicar que uma exceção deve ser gerada.

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

[Tratamento de erro e notificação](../../build/reference/error-handling-and-notification.md)