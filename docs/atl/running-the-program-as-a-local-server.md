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
ms.openlocfilehash: 5ae2e44ba51a878d293ad5b497a1638cc9d7dc76
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37848477"
---
# <a name="running-the-program-as-a-local-server"></a>Executar o programa como um servidor Local
Se executar o programa como um serviço é inconveniente, você poderá alterar temporariamente o registro para que o programa é executado como um servidor de local normal. Simplesmente renomear o `LocalService` valor sob sua AppID `_LocalService` e certifique-se a `LocalServer32` chave em sua CLSID está definida corretamente. (Observe que usando DCOMCNFG para especificar que seu aplicativo deve ser executado em um computador diferente renomeia seu `LocalServer32` chave `_LocalServer32`.) Executar o programa como um servidor local leva mais alguns segundos na inicialização porque a chamada para `StartServiceCtrlDispatcher` em `CAtlServiceModuleT::Start` leva alguns segundos antes de falhar.  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de depuração](../atl/debugging-tips.md)

