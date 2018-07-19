---
title: Classe IOleControlImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IOleControlImpl
- ATLCTL/ATL::IOleControlImpl
- ATLCTL/ATL::IOleControlImpl::FreezeEvents
- ATLCTL/ATL::IOleControlImpl::GetControlInfo
- ATLCTL/ATL::IOleControlImpl::OnAmbientPropertyChange
- ATLCTL/ATL::IOleControlImpl::OnMnemonic
dev_langs:
- C++
helpviewer_keywords:
- IOleControlImpl class
ms.assetid: 5a4255ad-ede4-49ca-ba9a-07c2e919fa85
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 34bdb0af5965b300e77a02858af3708c90fa63d0
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37879277"
---
# <a name="iolecontrolimpl-class"></a>Classe IOleControlImpl
Essa classe fornece uma implementação padrão do `IOleControl` interface e implementa `IUnknown`.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class IOleControlImpl
```   
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de `IOleControlImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IOleControlImpl::FreezeEvents](#freezeevents)|Indica se o contêiner ignora ou aceita a eventos do controle.|  
|[IOleControlImpl::GetControlInfo](#getcontrolinfo)|Preencha as informações sobre o comportamento de teclado do controle. A implementação de ATL retornará E_NOTIMPL.|  
|[IOleControlImpl::OnAmbientPropertyChange](#onambientpropertychange)|Informa um controle que uma ou mais das propriedades de ambiente do contêiner foi alterado. A implementação de ATL Retorna S_OK.|  
|[IOleControlImpl::OnMnemonic](#onmnemonic)|Informa o controle que um usuário pressiona um pressionamento de tecla especificado. A implementação de ATL retornará E_NOTIMPL.|  
  
## <a name="remarks"></a>Comentários  
 Classe `IOleControlImpl` fornece uma implementação padrão do [IOleControl](http://msdn.microsoft.com/library/windows/desktop/ms694320) interface e implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IOleControl`  
  
 `IOleControlImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="freezeevents"></a>  IOleControlImpl::FreezeEvents  
 Na implementação da ATL, `FreezeEvents` incrementa a classe de controle `m_nFreezeEvents` membro de dados se `bFreeze` for TRUE e decrementa `m_nFreezeEvents` se `bFreeze` é FALSE.  
  
```
HRESULT FreezeEvents(BOOL bFreeze);
```  
  
### <a name="remarks"></a>Comentários  
 `FreezeEvents` em seguida, Retorna S_OK.  
  
 Ver [IOleControl:: FreezeEvents](http://msdn.microsoft.com/library/windows/desktop/ms678482) no Windows SDK.  
  
##  <a name="getcontrolinfo"></a>  IOleControlImpl::GetControlInfo  
 Preencha as informações sobre o comportamento de teclado do controle.  
  
```
HRESULT GetControlInfo(LPCONTROLINFO pCI);
```  
  
### <a name="remarks"></a>Comentários  
 Ver [IOleControl:GetControlInfo](http://msdn.microsoft.com/library/windows/desktop/ms693730) no Windows SDK.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará E_NOTIMPL.  
  
##  <a name="onambientpropertychange"></a>  IOleControlImpl::OnAmbientPropertyChange  
 Informa um controle que uma ou mais das propriedades de ambiente do contêiner foi alterado.  
  
```
HRESULT OnAmbientPropertyChange(DISPID dispid);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
### <a name="remarks"></a>Comentários  
 Ver [IOleControl::OnAmbientPropertyChange](http://msdn.microsoft.com/library/windows/desktop/ms690175) no Windows SDK.  
  
##  <a name="onmnemonic"></a>  IOleControlImpl::OnMnemonic  
 Informa o controle que um usuário pressiona um pressionamento de tecla especificado.  
  
```
HRESULT OnMnemonic(LPMSG pMsg);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará E_NOTIMPL.  
  
### <a name="remarks"></a>Comentários  
 Ver [IOleControl::OnMnemonic](http://msdn.microsoft.com/library/windows/desktop/ms680699) no Windows SDK.  
  
## <a name="see-also"></a>Consulte também  
 [Classe IOleObjectImpl](../../atl/reference/ioleobjectimpl-class.md)   
 [Interfaces de controles ActiveX](http://msdn.microsoft.com/library/windows/desktop/ms692724)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
