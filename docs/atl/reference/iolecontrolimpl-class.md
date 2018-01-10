---
title: Classe IOleControlImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IOleControlImpl
- ATLCTL/ATL::IOleControlImpl
- ATLCTL/ATL::IOleControlImpl::FreezeEvents
- ATLCTL/ATL::IOleControlImpl::GetControlInfo
- ATLCTL/ATL::IOleControlImpl::OnAmbientPropertyChange
- ATLCTL/ATL::IOleControlImpl::OnMnemonic
dev_langs: C++
helpviewer_keywords: IOleControlImpl class
ms.assetid: 5a4255ad-ede4-49ca-ba9a-07c2e919fa85
caps.latest.revision: "22"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 23375f8f76e1a58bf29e3e3e269077fea4ae8d61
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="iolecontrolimpl-class"></a>Classe IOleControlImpl
Essa classe fornece uma implementação padrão de **IOleControl** interface e implementa **IUnknown**.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class IOleControlImpl
```   
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IOleControlImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IOleControlImpl::FreezeEvents](#freezeevents)|Indica se o contêiner ignora ou aceita eventos do controle.|  
|[IOleControlImpl::GetControlInfo](#getcontrolinfo)|Preenche informações sobre o comportamento do controle teclado. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IOleControlImpl::OnAmbientPropertyChange](#onambientpropertychange)|Informa um controle que um ou mais das propriedades de ambiente do contêiner foi alterado. Retorna a implementação de ATL `S_OK`.|  
|[IOleControlImpl::OnMnemonic](#onmnemonic)|Informa o controle que um usuário pressionou uma tecla especificada. Retorna a implementação de ATL **E_NOTIMPL**.|  
  
## <a name="remarks"></a>Comentários  
 Classe `IOleControlImpl` fornece uma implementação padrão da [IOleControl](http://msdn.microsoft.com/library/windows/desktop/ms694320) interface e implementa **IUnknown** enviando informações para o despejo compilações dispositivo na depuração.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IOleControl`  
  
 `IOleControlImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="freezeevents"></a>IOleControlImpl::FreezeEvents  
 Na implementação do ATL, `FreezeEvents` incrementa a classe de controle `m_nFreezeEvents` membro de dados se `bFreeze` é **TRUE**e diminui `m_nFreezeEvents` se `bFreeze` é **FALSE**.  
  
```
HRESULT FreezeEvents(BOOL bFreeze);
```  
  
### <a name="remarks"></a>Comentários  
 `FreezeEvents`em seguida, retorna `S_OK`.  
  
 Consulte [IOleControl:: FreezeEvents](http://msdn.microsoft.com/library/windows/desktop/ms678482) no SDK do Windows.  
  
##  <a name="getcontrolinfo"></a>IOleControlImpl::GetControlInfo  
 Preenche informações sobre o comportamento do controle teclado.  
  
```
HRESULT GetControlInfo(LPCONTROLINFO pCI);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleControl:GetControlInfo](http://msdn.microsoft.com/library/windows/desktop/ms693730) no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
##  <a name="onambientpropertychange"></a>IOleControlImpl::OnAmbientPropertyChange  
 Informa um controle que um ou mais das propriedades de ambiente do contêiner foi alterado.  
  
```
HRESULT OnAmbientPropertyChange(DISPID dispid);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleControl::OnAmbientPropertyChange](http://msdn.microsoft.com/library/windows/desktop/ms690175) no SDK do Windows.  
  
##  <a name="onmnemonic"></a>IOleControlImpl::OnMnemonic  
 Informa o controle que um usuário pressionou uma tecla especificada.  
  
```
HRESULT OnMnemonic(LPMSG pMsg);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleControl::OnMnemonic](http://msdn.microsoft.com/library/windows/desktop/ms680699) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe IOleObjectImpl](../../atl/reference/ioleobjectimpl-class.md)   
 [Interfaces de controles ActiveX](http://msdn.microsoft.com/library/windows/desktop/ms692724)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
