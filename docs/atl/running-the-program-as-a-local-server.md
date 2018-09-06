---
title: Executar o programa como um servidor Local | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- debugging [ATL], running services as local server
- ATL services, running as local servers
ms.assetid: eb9701e6-e2a8-4666-897f-0c893aec8ac7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e7ff7c2f7564a5da2c7a1db3913526a95660fe1d
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43754650"
---
# <a name="running-the-program-as-a-local-server"></a>Executar o programa como um servidor Local

Se executar o programa como um serviço é inconveniente, você poderá alterar temporariamente o registro para que o programa é executado como um servidor de local normal. Simplesmente renomear o `LocalService` valor sob sua AppID `_LocalService` e certifique-se a `LocalServer32` chave em sua CLSID está definida corretamente. (Observe que usando DCOMCNFG para especificar que seu aplicativo deve ser executado em um computador diferente renomeia seu `LocalServer32` chave `_LocalServer32`.) Executar o programa como um servidor local leva mais alguns segundos na inicialização porque a chamada para `StartServiceCtrlDispatcher` em `CAtlServiceModuleT::Start` leva alguns segundos antes de falhar.

## <a name="see-also"></a>Consulte também

[Dicas de depuração](../atl/debugging-tips.md)

