---
title: 'Função CAtlServiceModuleT:: Start'
ms.date: 11/04/2016
helpviewer_keywords:
- Start method
ms.assetid: b5193a23-41bc-42d2-8d55-3eb43dc62238
ms.openlocfilehash: e6de15f40e89bfffba504db04ee7a16b2a68cac9
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491659"
---
# <a name="catlservicemoduletstart-function"></a>Função CAtlServiceModuleT:: Start

Quando o serviço é executado, `_tWinMain` o `CAtlServiceModuleT::WinMain`chama, que, por `CAtlServiceModuleT::Start`sua vez, chama.

`CAtlServiceModuleT::Start`configura uma matriz de `SERVICE_TABLE_ENTRY` estruturas que mapeia cada serviço para sua função de inicialização. Essa matriz é passada para a função de API do Win32, [StartServiceCtrlDispatcher](/windows/win32/api/winsvc/nf-winsvc-startservicectrldispatcherw). Teoricamente, um exe poderia lidar com vários serviços e a matriz poderia ter `SERVICE_TABLE_ENTRY` várias estruturas. Atualmente, no entanto, um serviço gerado pelo ATL dá suporte a apenas um serviço por EXE. Portanto, a matriz tem uma única entrada que contém o nome do serviço `_ServiceMain` e como a função de inicialização. `_ServiceMain`é uma função membro estática do `CAtlServiceModuleT` que chama a função de membro não estática, `ServiceMain`.

> [!NOTE]
>  A falha `StartServiceCtrlDispatcher` de se conectar ao SCM (Gerenciador de controle de serviço) provavelmente significa que o programa não está sendo executado como um serviço. Nesse caso, o programa chama `CAtlServiceModuleT::Run` diretamente para que o programa possa ser executado como um servidor local. Para obter mais informações sobre como executar o programa como um servidor local, consulte [dicas de depuração](../atl/debugging-tips.md).

## <a name="see-also"></a>Consulte também

[Serviços](../atl/atl-services.md)<br/>
[CAtlServiceModuleT::Start](../atl/reference/catlservicemodulet-class.md#start)
