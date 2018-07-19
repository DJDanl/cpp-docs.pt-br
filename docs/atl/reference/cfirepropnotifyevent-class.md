---
title: Classe CFirePropNotifyEvent | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CFirePropNotifyEvent
- ATLCTL/ATL::CFirePropNotifyEvent
- ATLCTL/ATL::CFirePropNotifyEvent::FireOnChanged
- ATLCTL/ATL::CFirePropNotifyEvent::FireOnRequestEdit
dev_langs:
- C++
helpviewer_keywords:
- sinks, notifying of ATL events
- CFirePropNotifyEvent class
- connection points [C++], notifying of events
ms.assetid: eb7a563e-6bce-4cdf-8d20-8c6a5307781b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 20fd9c660f036c04ea2ca7d06d04315391504e3e
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37881523"
---
# <a name="cfirepropnotifyevent-class"></a>Classe CFirePropNotifyEvent
Essa classe fornece métodos para notificar o coletor do contêiner em relação às alterações de propriedade do controle.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CFirePropNotifyEvent
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFirePropNotifyEvent::FireOnChanged](#fireonchanged)|(Estático) Notifica o coletor do contêiner que uma propriedade de controle foi alterado.|  
|[CFirePropNotifyEvent::FireOnRequestEdit](#fireonrequestedit)|(Estático) Notifica o coletor do contêiner que uma propriedade de controle está prestes a ser alterada.|  
  
## <a name="remarks"></a>Comentários  
 `CFirePropNotifyEvent` tem dois métodos que notificam o coletor do contêiner que uma propriedade de controle foi alterado ou que está prestes a ser alterada.  
  
 Se a classe que implementa o controle é derivada de `IPropertyNotifySink`, o `CFirePropNotifyEvent` métodos são chamados quando você chama `FireOnRequestEdit` ou `FireOnChanged`. Se sua classe de controle não é derivado de `IPropertyNotifySink`, chamadas para essas funções retornam S_OK.  
  
 Para obter mais informações sobre a criação de controles, consulte o [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="fireonchanged"></a>  CFirePropNotifyEvent::FireOnChanged  
 Notifica todos conectados [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) interfaces (em cada ponto de conexão do objeto) que a propriedade do objeto especificado foi alterado.  
  
```
static HRESULT FireOnChanged(IUnknown* pUnk, DISPID dispID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnk*  
 [in] Ponteiro para o `IUnknown` do objeto que está enviando a notificação.  
  
 *dispID*  
 [in] Identificador da propriedade que foi alterado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Essa função é segura chamar o mesmo que o controle não dá suporte aos pontos de conexão.  
  
##  <a name="fireonrequestedit"></a>  CFirePropNotifyEvent::FireOnRequestEdit  
 Notifica todos conectados [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) interfaces (em cada ponto de conexão do objeto) que a propriedade do objeto especificado está prestes a ser alterada.  
  
```
static HRESULT FireOnRequestEdit(IUnknown* pUnk, DISPID dispID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnk*  
 [in] Ponteiro para o `IUnknown` do objeto que está enviando a notificação.  
  
 *dispID*  
 [in] Identificador da propriedade prestes a ser alterada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Essa função é segura chamar o mesmo que o controle não dá suporte aos pontos de conexão.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
