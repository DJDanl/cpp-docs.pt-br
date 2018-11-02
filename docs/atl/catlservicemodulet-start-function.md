---
title: 'Função catlservicemodulet:: Start'
ms.date: 11/04/2016
f1_keywords:
- CServiceModule.Start
- CServiceModule::Start
helpviewer_keywords:
- Start method
ms.assetid: b5193a23-41bc-42d2-8d55-3eb43dc62238
ms.openlocfilehash: 0730bad600190ed06c6f40a4a7cf396f0924a5fc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50476605"
---
# <a name="catlservicemoduletstart-function"></a>Função catlservicemodulet:: Start

Quando o serviço é executado, `_tWinMain` chamadas `CAtlServiceModuleT::WinMain`, que por sua vez chama `CAtlServiceModuleT::Start`.

`CAtlServiceModuleT::Start` define uma matriz de `SERVICE_TABLE_ENTRY` estruturas que mapeiam cada serviço para sua função de inicialização. Essa matriz é então passado para a função de API do Win32 [StartServiceCtrlDispatcher](/windows/desktop/api/winsvc/nf-winsvc-startservicectrldispatchera). Em teoria, um EXE pudesse lidar com vários serviços e a matriz pode ter vários `SERVICE_TABLE_ENTRY` estruturas. Atualmente, no entanto, um serviço gerado pelo ATL dá suporte a apenas um serviço por EXE. Portanto, a matriz tem uma única entrada que contém o nome do serviço e `_ServiceMain` como a função de inicialização. `_ServiceMain` é uma função de membro estático do `CAtlServiceModuleT` que chama a função de membro não estático, `ServiceMain`.

> [!NOTE]
>  Falha de `StartServiceCtrlDispatcher` para conectar-se para o controle do service manager (SCM) provavelmente significa que o programa não está em execução como um serviço. Nesse caso, o programa chama `CAtlServiceModuleT::Run` diretamente para que o programa pode ser executado como um servidor local. Para obter mais informações sobre como executar o programa como um servidor local, consulte [dicas de depuração](../atl/debugging-tips.md).

## <a name="see-also"></a>Consulte também

[Serviços](../atl/atl-services.md)<br/>
[Catlservicemodulet:: Start](../atl/reference/catlservicemodulet-class.md#start)

