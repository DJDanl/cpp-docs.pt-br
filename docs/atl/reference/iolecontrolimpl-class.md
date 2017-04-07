---
title: Classe IOleControlImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
caps.latest.revision: 22
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 5e63849a504b931de30141dd91af557f16c67fd8
ms.lasthandoff: 02/25/2017

---
# <a name="iolecontrolimpl-class"></a>Classe IOleControlImpl
Essa classe fornece uma implementação padrão da **IOleControl** interface e implementa **IUnknown**.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class IOleControlImpl
```   
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `IOleControlImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IOleControlImpl::FreezeEvents](#freezeevents)|Indica se o contêiner ignora ou aceita eventos do controle.|  
|[IOleControlImpl::GetControlInfo](#getcontrolinfo)|Preenche informações sobre o comportamento do teclado do controle. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IOleControlImpl::OnAmbientPropertyChange](#onambientpropertychange)|Informa um controle que uma ou mais das propriedades de ambiente do contêiner foi alterado. Retorna a implementação de ATL `S_OK`.|  
|[IOleControlImpl::OnMnemonic](#onmnemonic)|Informa o controle que um usuário pressionou um pressionamento de tecla especificado. Retorna a implementação de ATL **E_NOTIMPL**.|  
  
## <a name="remarks"></a>Comentários  
 Classe `IOleControlImpl` fornece uma implementação padrão de [IOleControl](http://msdn.microsoft.com/library/windows/desktop/ms694320) interface e implementa **IUnknown** enviando informações para o despejo de compilações de dispositivo no modo de depuração.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IOleControl`  
  
 `IOleControlImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="freezeevents"></a>IOleControlImpl::FreezeEvents  
 Na implementação da ATL, `FreezeEvents` incrementa a classe de controle `m_nFreezeEvents` membro de dados se `bFreeze` é **TRUE**e decrementa `m_nFreezeEvents` se `bFreeze` é **FALSE**.  
  
```
HRESULT FreezeEvents(BOOL bFreeze);
```  
  
### <a name="remarks"></a>Comentários  
 `FreezeEvents`em seguida, retorna `S_OK`.  
  
 Consulte [IOleControl:: FreezeEvents](http://msdn.microsoft.com/library/windows/desktop/ms678482) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getcontrolinfo"></a>IOleControlImpl::GetControlInfo  
 Preenche informações sobre o comportamento do teclado do controle.  
  
```
HRESULT GetControlInfo(LPCONTROLINFO pCI);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleControl:GetControlInfo](http://msdn.microsoft.com/library/windows/desktop/ms693730) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
##  <a name="onambientpropertychange"></a>IOleControlImpl::OnAmbientPropertyChange  
 Informa um controle que uma ou mais das propriedades de ambiente do contêiner foi alterado.  
  
```
HRESULT OnAmbientPropertyChange(DISPID dispid);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleControl::OnAmbientPropertyChange](http://msdn.microsoft.com/library/windows/desktop/ms690175) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="onmnemonic"></a>IOleControlImpl::OnMnemonic  
 Informa o controle que um usuário pressionou um pressionamento de tecla especificado.  
  
```
HRESULT OnMnemonic(LPMSG pMsg);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleControl::OnMnemonic](http://msdn.microsoft.com/library/windows/desktop/ms680699) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Classe IOleObjectImpl](../../atl/reference/ioleobjectimpl-class.md)   
 [Interfaces de controles ActiveX](http://msdn.microsoft.com/library/windows/desktop/ms692724)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

