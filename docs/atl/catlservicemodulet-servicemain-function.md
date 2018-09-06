---
title: 'Função catlservicemodulet:: Servicemain | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
f1_keywords:
- ServiceMain
- CServiceModule::ServiceMain
- CServiceModule.ServiceMain
dev_langs:
- C++
helpviewer_keywords:
- ServiceMain method
ms.assetid: f21408c1-1919-4dec-88d8-bf5b39ac9808
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bf3455bb5e1f6dca08e01540af92536b2597a4fc
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43761989"
---
# <a name="catlservicemoduletservicemain-function"></a>Função catlservicemodulet:: Servicemain

O Gerenciador de controle de serviços (SCM) chama `ServiceMain` quando você abre o aplicativo de painel de controle de serviços, selecione o serviço e clique em **iniciar**.

Depois do SCM chama `ServiceMain`, um serviço deve fornecer o SCM uma função de manipulador. Essa função permite que o SCM obter o status do serviço e passar as instruções específicas (como pausar ou parar). O SCM obtém essa função quando o serviço passa `_Handler` para a função de API do Win32, [RegisterServiceCtrlHandler](/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlera). (`_Handler` é uma função de membro estático que chama a função de membro não estático [manipulador](../atl/reference/catlservicemodulet-class.md#handler).)

Na inicialização, um serviço também deve informar o SCM de seu status atual. Ele faz isso passando SERVICE_START_PENDING para a função de API do Win32, [SetServiceStatus](/windows/desktop/api/winsvc/nf-winsvc-setservicestatus).

`ServiceMain` em seguida, chama `CAtlExeModuleT::InitializeCom`, que chama a função de API do Win32 [CoInitializeEx](/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex). Por padrão, `InitializeCom` passa o sinalizador COINIT_MULTITHREADED para a função. Esse sinalizador indica que o programa deve ser um servidor de thread livre.

Agora, `CAtlServiceModuleT::Run` é chamado para executar o trabalho principal do serviço. `Run` continua sendo executado até que o serviço está parado.

## <a name="see-also"></a>Consulte também

[serviços](../atl/atl-services.md)   
[Catlservicemodulet:: Servicemain](../atl/reference/catlservicemodulet-class.md#servicemain)

