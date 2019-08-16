---
title: 'Função CAtlServiceModuleT:: usermain'
ms.date: 11/04/2016
helpviewer_keywords:
- ServiceMain method
ms.assetid: f21408c1-1919-4dec-88d8-bf5b39ac9808
ms.openlocfilehash: b79767d4c1696174f90a325ea152ccc7939ed9fe
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491719"
---
# <a name="catlservicemoduletservicemain-function"></a>Função CAtlServiceModuleT:: usermain

As chamadas `ServiceMain` do Gerenciador de controle de serviço (SCM) quando você abre o aplicativo do painel de controle de serviços, selecionam o serviço e clicam em **Iniciar**.

Após as chamadas `ServiceMain`de SCM, um serviço deve dar ao SCM uma função de manipulador. Essa função permite que o SCM obtenha o status do serviço e passe instruções específicas (como pausar ou parar). O SCM obtém essa função quando o serviço passa `_Handler` para a função de API do Win32, [RegisterServiceCtrlHandler](/windows/win32/api/winsvc/nf-winsvc-registerservicectrlhandlerw). (`_Handler` é uma função de membro estático que chama o [manipulador](../atl/reference/catlservicemodulet-class.md#handler)de função de membro não estático.)

Na inicialização, um serviço também deve informar o SCM de seu status atual. Ele faz isso passando SERVICE_START_PENDING para a função de API do Win32, [falha em SetServiceStatus](/windows/win32/api/winsvc/nf-winsvc-setservicestatus).

`ServiceMain`em seguida `CAtlExeModuleT::InitializeCom`, chama, que chama a função de API do Win32 [CoInitializeEx](/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex). Por padrão, `InitializeCom` o passa o sinalizador COINIT_MULTITHREADED para a função. Esse sinalizador indica que o programa deve ser um servidor de thread livre.

Agora, `CAtlServiceModuleT::Run` é chamado para executar o trabalho principal do serviço. `Run`continua a ser executado até que o serviço seja interrompido.

## <a name="see-also"></a>Consulte também

[Serviços](../atl/atl-services.md)<br/>
[CAtlServiceModuleT::ServiceMain](../atl/reference/catlservicemodulet-class.md#servicemain)
