---
title: CAtlServiceModuleT::Função iniciar
ms.date: 11/04/2016
helpviewer_keywords:
- Start method
ms.assetid: b5193a23-41bc-42d2-8d55-3eb43dc62238
ms.openlocfilehash: 50054bbb34bcc31a1d11dd8bfab797f98e4e82f0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317285"
---
# <a name="catlservicemoduletstart-function"></a>CAtlServiceModuleT::Função iniciar

Quando o serviço `_tWinMain` é `CAtlServiceModuleT::WinMain`executado, chamadas `CAtlServiceModuleT::Start`, que por sua vez chama .

`CAtlServiceModuleT::Start`configura uma matriz `SERVICE_TABLE_ENTRY` de estruturas que mapeiam cada serviço para sua função de inicialização. Essa matriz é então passada para a função API do Win32, [StartServiceCtrlDispatcher](/windows/win32/api/winsvc/nf-winsvc-startservicectrldispatcherw). Em teoria, um EXE poderia lidar com `SERVICE_TABLE_ENTRY` vários serviços e a matriz poderia ter múltiplas estruturas. Atualmente, no entanto, um serviço gerado pela ATL suporta apenas um serviço por EXE. Portanto, a matriz tem uma única entrada `_ServiceMain` que contém o nome do serviço e como função de inicialização. `_ServiceMain`é uma função `CAtlServiceModuleT` de membro estático que `ServiceMain`chama a função de membro não estático, .

> [!NOTE]
> A `StartServiceCtrlDispatcher` falha de se conectar ao gerenciador de controle de serviço (SCM) provavelmente significa que o programa não está funcionando como um serviço. Neste caso, o `CAtlServiceModuleT::Run` programa liga diretamente para que o programa possa ser executado como um servidor local. Para obter mais informações sobre a execução do programa como servidor local, consulte [Dicas de depuração](../atl/debugging-tips.md).

## <a name="see-also"></a>Confira também

[Serviços](../atl/atl-services.md)<br/>
[CAtlServiceModuleT::Iniciar](../atl/reference/catlservicemodulet-class.md#start)
