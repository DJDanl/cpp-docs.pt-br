---
title: Classe CFirePropNotifyEvent | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c9571ad4ba928c208c6c028f6e30cf7c27c196d4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cfirepropnotifyevent-class"></a>Classe CFirePropNotifyEvent
Essa classe fornece métodos para notificar o coletor do contêiner sobre as alterações de propriedade do controle.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CFirePropNotifyEvent
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFirePropNotifyEvent::FireOnChanged](#fireonchanged)|(Estático) Notifica o coletor do contêiner que uma propriedade de controle foi alterado.|  
|[CFirePropNotifyEvent::FireOnRequestEdit](#fireonrequestedit)|(Estático) Notifica o coletor do contêiner que uma propriedade do controle está prestes a alterar.|  
  
## <a name="remarks"></a>Comentários  
 `CFirePropNotifyEvent`tem dois métodos que notificam o coletor do contêiner que uma propriedade de controle foi alterado ou está prestes a ser alterada.  
  
 Se a classe que implementa o controle for derivada de `IPropertyNotifySink`, o `CFirePropNotifyEvent` métodos são chamados quando você chamar `FireOnRequestEdit` ou `FireOnChanged`. Se sua classe de controle não é derivado de `IPropertyNotifySink`, chamadas para essas funções retornam `S_OK`.  
  
 Para obter mais informações sobre a criação de controles, consulte o [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="fireonchanged"></a>CFirePropNotifyEvent::FireOnChanged  
 Notifica todos conectado [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) interfaces (em cada ponto de conexão do objeto) que a propriedade do objeto especificado foi alterado.  
  
```
static HRESULT FireOnChanged(IUnknown* pUnk, DISPID dispID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnk*  
 [in] Ponteiro para o **IUnknown** do objeto ao enviar a notificação.  
  
 *dispID*  
 [in] Identificador da propriedade que foi alterada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valores.  
  
### <a name="remarks"></a>Comentários  
 Essa função é segura chamar mesmo se o controle não oferece suporte a pontos de conexão.  
  
##  <a name="fireonrequestedit"></a>CFirePropNotifyEvent::FireOnRequestEdit  
 Notifica todos conectado [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) interfaces (em cada ponto de conexão do objeto) que a propriedade do objeto especificado está prestes a alterar.  
  
```
static HRESULT FireOnRequestEdit(IUnknown* pUnk, DISPID dispID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnk*  
 [in] Ponteiro para o **IUnknown** do objeto ao enviar a notificação.  
  
 *dispID*  
 [in] Identificador da propriedade prestes a ser alterada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valores.  
  
### <a name="remarks"></a>Comentários  
 Essa função é segura chamar mesmo se o controle não oferece suporte a pontos de conexão.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
