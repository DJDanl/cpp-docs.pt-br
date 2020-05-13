---
title: Classes de módulo ATL
ms.date: 11/04/2016
helpviewer_keywords:
- CComModule class, what's changed
- ATL, module classes
- module classes
ms.assetid: fd75382d-c955-46ba-a38e-37728b7fa00f
ms.openlocfilehash: 2b72cac0da06b70a40e01fcc75da52f1678f3f64
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317369"
---
# <a name="atl-module-classes"></a>Classes de módulo ATL

Este tópico discute as classes de módulo que eram novas no ATL 7.0.

## <a name="ccommodule-replacement-classes"></a>Classes de substituição do CComModule

Versões anteriores `CComModule`do ATL usado . No ATL 7.0, `CComModule` a funcionalidade é substituída por várias classes:

- [CAtlBaseMódulo](../atl/reference/catlbasemodule-class.md) Contém informações exigidas pela maioria dos aplicativos que usam ATL. Contém o HINSTANCE do módulo e a instância de recurso.

- [CAtlComModule](../atl/reference/catlcommodule-class.md) Contém informações exigidas pelas classes COM no ATL.

- [CAtlWinModule](../atl/reference/catlwinmodule-class.md) Contém informações exigidas pelas classes de janelas no ATL.

- [CAtlDebugInterfacesMódulo](../atl/reference/catldebuginterfacesmodule-class.md) Contém suporte para depuração de interface.

- [CAtlModule](../atl/reference/catlmodule-class.md) As `CAtlModule`classes derivadas a seguir são personalizadas para conter as informações exigidas em um determinado tipo de aplicativo. A maioria dos membros nestas classes pode ser substituída:

  - [CAtlDllModuleT](../atl/reference/catldllmodulet-class.md) Usado em aplicações DLL. Fornece código para as exportações padrão.

  - [CAtlExeModuleT](../atl/reference/catlexemodulet-class.md) Usado em aplicações EXE. Fornece código necessário em um EXE.

  - [CAtlServiceModuleT](../atl/reference/catlservicemodulet-class.md) Fornece suporte para criar serviços windows NT e Windows 2000.

`CComModule`ainda está disponível para compatibilidade retrógrada.

## <a name="reasons-for-distributing-ccommodule-functionality"></a>Razões para distribuir a funcionalidade do CComModule

A funcionalidade `CComModule` foi distribuída em várias novas classes pelas seguintes razões:

- Faça a funcionalidade `CComModule` em granular.

   O suporte para recursos COM, windowing, depuração de interface e dll (exe) específico de aplicativo está agora em classes separadas.

- Declare automaticamente a instância global de cada um desses módulos.

   Uma instância global das classes de módulos necessárias está vinculada ao projeto.

- Remova a necessidade de chamar métodos Init e Term.

   Os métodos Init e Term passaram para os construtores e destruidores para as aulas de módulo; não há mais necessidade de chamar Init e Term.

## <a name="see-also"></a>Confira também

[Conceitos](../atl/active-template-library-atl-concepts.md)<br/>
[Visão geral da classe](../atl/atl-class-overview.md)
