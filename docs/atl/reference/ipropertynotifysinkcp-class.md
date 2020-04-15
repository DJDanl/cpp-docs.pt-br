---
title: Classe IPropertyNotifySinkCP
ms.date: 11/04/2016
f1_keywords:
- IPropertyNotifySinkCP
- atlctl/ATL::IPropertyNotifySinkCP
helpviewer_keywords:
- connection points [C++], managing
- sinks, notifying of changes
- IPropertyNotifySinkCP class
ms.assetid: 1b41445e-bc88-4fa6-bb62-d68aacec2bd5
ms.openlocfilehash: c6d98bf5a6dfe5566839eb22bcd2bab2a9c28e4d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329603"
---
# <a name="ipropertynotifysinkcp-class"></a>Classe IPropertyNotifySinkCP

Esta classe expõe a interface [IPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink) como uma interface de saída em um objeto conectável.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T, class CDV = CComDynamicUnkArray>
class IPropertyNotifySinkCP
   : public IConnectionPointImpl<T, &IID_IPropertyNotifySink, CDV>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IPropertyNotifySinkCP`.

*Cdv*<br/>
Uma classe que gerencia as conexões entre um ponto de conexão e suas pias. O valor padrão é [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md), que permite conexões ilimitadas. Você também pode usar [CComUnkArray](../../atl/reference/ccomunkarray-class.md), que especifica um número fixo de conexões.

## <a name="remarks"></a>Comentários

`IPropertyNotifySinkCP`herda todos os métodos através de sua classe base, [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md).

A interface [IPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink) permite que um objeto de sumidouro receba notificações sobre alterações de propriedade. A `IPropertyNotifySinkCP` classe expõe essa interface como uma interface de saída em um objeto conectável. O cliente deve `IPropertyNotifySink` implementar os métodos na pia.

Obtenha sua `IPropertyNotifySinkCP` classe de quando você deseja criar `IPropertyNotifySink` um ponto de conexão que represente a interface.

Para obter mais informações sobre o uso de pontos de conexão no ATL, consulte o artigo [Pontos de Conexão](../../atl/atl-connection-points.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="see-also"></a>Confira também

[Classe IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md)<br/>
[Classe IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
