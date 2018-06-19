---
title: Classes de módulo ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CComModule class, what's changed
- ATL, module classes
- module classes
ms.assetid: fd75382d-c955-46ba-a38e-37728b7fa00f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 777d81fbe1de48289863fda00591a5328b40cf4c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32356599"
---
# <a name="atl-module-classes"></a>Classes de módulo ATL
Este tópico discute as classes de módulo que eram novas no ATL 7.0.  
  
## <a name="ccommodule-replacement-classes"></a>Classes de substituição CComModule  
 Versões anteriores do ATL usado `CComModule`. No ATL 7.0, `CComModule` funcionalidade é substituída por várias classes:  
  
-   [CAtlBaseModule](../atl/reference/catlbasemodule-class.md) contém informações necessárias para a maioria dos aplicativos que usam ATL. Contém o HINSTANCE do módulo e a instância do recurso.  
  
-   [CAtlComModule](../atl/reference/catlcommodule-class.md) contém informações necessárias para as classes COM em ATL.  
  
-   [CAtlWinModule](../atl/reference/catlwinmodule-class.md) contém informações necessárias para as classes de janelas em ATL.  
  
-   [CAtlDebugInterfacesModule](../atl/reference/catldebuginterfacesmodule-class.md) contém suporte para depuração de interface.  
  
-   [CAtlModule](../atl/reference/catlmodule-class.md) o seguinte `CAtlModule`-classes derivadas são personalizadas para conter as informações necessárias em um tipo de aplicativo específico. A maioria dos membros nessas classes podem ser substituídas:  
  
    -   [CAtlDllModuleT](../atl/reference/catldllmodulet-class.md) usados em aplicativos de DLL. Fornece código para as exportações padrão.  
  
    -   [CAtlExeModuleT](../atl/reference/catlexemodulet-class.md) usados em aplicativos EXE. Fornece o código necessário em um EXE.  
  
    -   [CAtlServiceModuleT](../atl/reference/catlservicemodulet-class.md) oferece suporte à criação do Windows NT e serviços do Windows 2000.  
  
 `CComModule` ainda está disponível para compatibilidade com versões anteriores.  
  
## <a name="reasons-for-distributing-ccommodule-functionality"></a>Motivos para a distribuição de funcionalidade CComModule  
 A funcionalidade de `CComModule` distribuído em várias classes novas pelos seguintes motivos:  
  
-   Verifique a funcionalidade no `CComModule` granular.  
  
     Suporte de COM, janelas, depuração de interface, específico do aplicativo (DLL ou EXE) recursos e está agora em classes separadas.  
  
-   Declare automaticamente instância global de cada um desses módulos.  
  
     Uma instância global das classes de módulo requerido é vinculada ao projeto.  
  
-   Remova a necessidade de chamar métodos Init e termo.  
  
     Métodos Init e termo tem movido para os construtores e destruidores para classes de módulo; não é mais a necessidade de chamar Init e termo.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)   
 [Visão geral da classe](../atl/atl-class-overview.md)

