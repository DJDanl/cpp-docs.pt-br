---
title: "Função CAtlServiceModuleT::ServiceMain | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ServiceMain
- CServiceModule::ServiceMain
- CServiceModule.ServiceMain
dev_langs:
- C++
helpviewer_keywords:
- ServiceMain method
ms.assetid: f21408c1-1919-4dec-88d8-bf5b39ac9808
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 633e9bc4689ced93e1c22151b32654f7ae9d7ece
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="catlservicemoduletservicemain-function"></a>Função CAtlServiceModuleT::ServiceMain
O Gerenciador de controle de serviços (SCM) chama `ServiceMain` quando você abre o aplicativo de painel de controle de serviços, selecione o serviço e clique em **iniciar**.  
  
 Após o SCM chama `ServiceMain`, um serviço deve fornecer o SCM uma função de manipulador. Esta função permite que o SCM obter o status do serviço e passar as instruções específicas (como pausar ou parar). O SCM obtém essa função quando o serviço passa **_Handler** para a função de API do Win32, [RegisterServiceCtrlHandler](http://msdn.microsoft.com/library/windows/desktop/ms685054). (**_Handler** é uma função de membro estático que chama a função de membro não estático [manipulador](../atl/reference/catlservicemodulet-class.md#handler).)  
  
 Na inicialização, um serviço também deve informar o SCM do seu status atual. Ele faz isso passando **SERVICE_START_PENDING** para a função de API do Win32, [SetServiceStatus](http://msdn.microsoft.com/library/windows/desktop/ms686241).  
  
 `ServiceMain`em seguida, chama `CAtlExeModuleT::InitializeCom`, que chama a função de API do Win32 [CoInitializeEx](http://msdn.microsoft.com/library/windows/desktop/ms695279). Por padrão, `InitializeCom` passa o **COINIT_MULTITHREADED** sinalizador para a função. Esse sinalizador indica que o programa deve ser um servidor free-thread.  
  
 Agora, `CAtlServiceModuleT::Run` é chamado para executar o trabalho principal do serviço. **Executar** continuarão sendo executadas até que o serviço está parado.  
  
## <a name="see-also"></a>Consulte também  
 [Serviços](../atl/atl-services.md)   
 [CAtlServiceModuleT::ServiceMain](../atl/reference/catlservicemodulet-class.md#servicemain)

