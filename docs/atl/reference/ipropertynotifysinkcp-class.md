---
title: Classe IPropertyNotifySinkCP | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IPropertyNotifySinkCP
- atlctl/ATL::IPropertyNotifySinkCP
dev_langs:
- C++
helpviewer_keywords:
- connection points [C++], managing
- sinks, notifying of changes
- IPropertyNotifySinkCP class
ms.assetid: 1b41445e-bc88-4fa6-bb62-d68aacec2bd5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0b5afa1543b5d06a115b70fee3d48d12dcbb79da
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50076939"
---
# <a name="ipropertynotifysinkcp-class"></a>Classe IPropertyNotifySinkCP

Essa classe expõe [IPropertyNotifySink](/windows/desktop/api/ocidl/nn-ocidl-ipropertynotifysink) interface como uma interface de saída em um objeto conectável.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T, class CDV = CComDynamicUnkArray>
class IPropertyNotifySinkCP
   : public IConnectionPointImpl<T, &IID_IPropertyNotifySink, CDV>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IPropertyNotifySinkCP`.

*CDV*<br/>
Uma classe que gerencia as conexões entre um ponto de conexão e seus coletores. O valor padrão é [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md), que permite conexões ilimitadas. Você também pode usar [CComUnkArray](../../atl/reference/ccomunkarray-class.md), que especifica um número fixo de conexões.

## <a name="remarks"></a>Comentários

`IPropertyNotifySinkCP` herda todos os métodos por meio de sua classe base, [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md).

O [IPropertyNotifySink](/windows/desktop/api/ocidl/nn-ocidl-ipropertynotifysink) interface permite que um objeto de coletor para receber notificações sobre alterações de propriedade. Classe `IPropertyNotifySinkCP` expõe essa interface como uma interface de saída em um objeto conectável. O cliente deve implementar o `IPropertyNotifySink` métodos no coletor.

Derive sua classe de `IPropertyNotifySinkCP` quando você deseja criar um ponto de conexão que representa o `IPropertyNotifySink` interface.

Para obter mais informações sobre como usar pontos de conexão no ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="see-also"></a>Consulte também

[Classe IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md)<br/>
[Classe IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
