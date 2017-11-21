---
title: Executar o programa como um servidor Local | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- debugging [ATL], running services as local server
- ATL services, running as local servers
ms.assetid: eb9701e6-e2a8-4666-897f-0c893aec8ac7
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 131bfefb35164b2d1e53f5671016235e5426c096
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="running-the-program-as-a-local-server"></a>Executar o programa como um servidor Local
Se executar o programa como um serviço é inconveniente, você poderá alterar temporariamente o registro para que o programa é executado como um servidor de local normal. Simplesmente renomear o `LocalService` valor em sua AppID `_LocalService` e verifique se o `LocalServer32` chave em sua CLSID está definida corretamente. (Observe que usando DCOMCNFG para especificar que seu aplicativo deve ser executado em um computador diferente renomeia o `LocalServer32` chave para `_LocalServer32`.) Executar o programa como um servidor local leva alguns segundos mais na inicialização porque a chamada para **StartServiceCtrlDispatcher** na `CAtlServiceModuleT::Start` leva alguns segundos antes de falhar.  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de depuração](../atl/debugging-tips.md)

