---
title: CFirePropNotificarClasse de evento
ms.date: 11/04/2016
f1_keywords:
- CFirePropNotifyEvent
- ATLCTL/ATL::CFirePropNotifyEvent
- ATLCTL/ATL::CFirePropNotifyEvent::FireOnChanged
- ATLCTL/ATL::CFirePropNotifyEvent::FireOnRequestEdit
helpviewer_keywords:
- sinks, notifying of ATL events
- CFirePropNotifyEvent class
- connection points [C++], notifying of events
ms.assetid: eb7a563e-6bce-4cdf-8d20-8c6a5307781b
ms.openlocfilehash: 1dfce42176341d74ffc7d9b42f856e71b17bf4f5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326965"
---
# <a name="cfirepropnotifyevent-class"></a>CFirePropNotificarClasse de evento

Esta classe fornece métodos para notificar a pia do contêiner sobre alterações na propriedade de controle.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CFirePropNotifyEvent
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Cfirepropnotifyevent::FireonChanged](#fireonchanged)|(Estática) Notifica a pia do contêiner que uma propriedade de controle mudou.|
|[Cfirepropnotificarevento::Fireonrequestedit](#fireonrequestedit)|(Estática) Notifica a pia do contêiner que uma propriedade de controle está prestes a mudar.|

## <a name="remarks"></a>Comentários

`CFirePropNotifyEvent`tem dois métodos que notificam a pia do contêiner que uma propriedade de controle mudou ou está prestes a mudar.

Se a classe que implementa `IPropertyNotifySink`seu `CFirePropNotifyEvent` controle for derivada, `FireOnRequestEdit` os `FireOnChanged`métodos serão invocados quando você ligar ou . Se sua classe de controle `IPropertyNotifySink`não for derivada, as chamadas para essas funções retornam S_OK.

Para obter mais informações sobre a criação de controles, consulte o [Tutorial ATL](../../atl/active-template-library-atl-tutorial.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="cfirepropnotifyeventfireonchanged"></a><a name="fireonchanged"></a>Cfirepropnotifyevent::FireonChanged

Notifica todas as interfaces [IPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink) conectadas (em cada ponto de conexão do objeto) que a propriedade do objeto especificado foi alterada.

```
static HRESULT FireOnChanged(IUnknown* pUnk, DISPID dispID);
```

### <a name="parameters"></a>Parâmetros

*Punk*<br/>
[em] Ponteiro para `IUnknown` o objeto que envia a notificação.

*Dispid*<br/>
[em] Identificador da propriedade que mudou.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Esta função é segura para chamar mesmo que seu controle não suporte pontos de conexão.

## <a name="cfirepropnotifyeventfireonrequestedit"></a><a name="fireonrequestedit"></a>Cfirepropnotificarevento::Fireonrequestedit

Notifica todas as interfaces [iPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink) conectadas (em cada ponto de conexão do objeto) que a propriedade do objeto especificado está prestes a ser alterada.

```
static HRESULT FireOnRequestEdit(IUnknown* pUnk, DISPID dispID);
```

### <a name="parameters"></a>Parâmetros

*Punk*<br/>
[em] Ponteiro para `IUnknown` o objeto que envia a notificação.

*Dispid*<br/>
[em] Identificador da propriedade prestes a mudar.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Esta função é segura para chamar mesmo que seu controle não suporte pontos de conexão.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
