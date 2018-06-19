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
ms.openlocfilehash: c2b8a79978528493e02ac5a272dafe8da6fdc1d9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32360437"
---
# <a name="running-the-program-as-a-local-server"></a>Executar o programa como um servidor Local
Se executar o programa como um serviço é inconveniente, você poderá alterar temporariamente o registro para que o programa é executado como um servidor de local normal. Simplesmente renomear o `LocalService` valor em sua AppID `_LocalService` e verifique se o `LocalServer32` chave em sua CLSID está definida corretamente. (Observe que usando DCOMCNFG para especificar que seu aplicativo deve ser executado em um computador diferente renomeia o `LocalServer32` chave para `_LocalServer32`.) Executar o programa como um servidor local leva alguns segundos mais na inicialização porque a chamada para **StartServiceCtrlDispatcher** na `CAtlServiceModuleT::Start` leva alguns segundos antes de falhar.  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de depuração](../atl/debugging-tips.md)

