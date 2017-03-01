---
title: Classe IPointerInactiveImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IPointerInactiveImpl
dev_langs:
- C++
helpviewer_keywords:
- IPointerInactive ATL implementation
- inactive objects
- IPointerInactiveImpl class
ms.assetid: e1fe9ea6-d38a-4527-9112-eb344771e0b7
caps.latest.revision: 21
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
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 05cf4b2247cabe713cfc6b0dd54c95c01e5bbddc
ms.lasthandoff: 02/25/2017

---
# <a name="ipointerinactiveimpl-class"></a>Classe IPointerInactiveImpl
Essa classe implementa **IUnknown** e [IPointerInactive](http://msdn.microsoft.com/library/windows/desktop/ms693712) métodos de interface.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class IPointerInactiveImpl
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `IPointerInactiveImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IPointerInactiveImpl::GetActivationPolicy](#getactivationpolicy)|Recupera a política de ativação atual do objeto. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IPointerInactiveImpl::OnInactiveMouseMove](#oninactivemousemove)|Notifica o objeto que o ponteiro do mouse foi movido, indicando que o objeto pode disparar eventos de mouse. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IPointerInactiveImpl::OnInactiveSetCursor](#oninactivesetcursor)|Define o ponteiro do mouse para o objeto inativo. Retorna a implementação de ATL **E_NOTIMPL**.|  
  
## <a name="remarks"></a>Comentários  
 Um objeto inativo é aquele que é simplesmente carregado ou está em execução. Ao contrário de um objeto de ativo, um objeto inativo não pode receber mensagens de mouse e teclado do Windows. Assim, os objetos inativos usam menos recursos e são geralmente mais eficientes.  
  
 O [IPointerInactive](http://msdn.microsoft.com/library/windows/desktop/ms693712) interface permite que um objeto dar suporte a um nível mínimo de interação do mouse enquanto permanecem inativos. Essa funcionalidade é particularmente útil para controles.  
  
 Classe `IPointerInactiveImpl` implementa o `IPointerInactive` métodos simplesmente retornando **E_NOTIMPL**. No entanto, ele implementa **IUnknown** enviando informações para o despejo de compilações de dispositivo no modo de depuração.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IPointerInactive`  
  
 `IPointerInactiveImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="a-namegetactivationpolicya--ipointerinactiveimplgetactivationpolicy"></a><a name="getactivationpolicy"></a>IPointerInactiveImpl::GetActivationPolicy  
 Recupera a política de ativação atual do objeto.  
  
```
HRESULT GetActivationPolicy(DWORD* pdwPolicy);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPointerInactive::GetActivationPolicy](http://msdn.microsoft.com/library/windows/desktop/ms692470) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameoninactivemousemovea--ipointerinactiveimploninactivemousemove"></a><a name="oninactivemousemove"></a>IPointerInactiveImpl::OnInactiveMouseMove  
 Notifica o objeto que o ponteiro do mouse foi movido, indicando que o objeto pode disparar eventos de mouse.  
  
```
HRESULT OnInactiveMouseMove(
    LPCRECT pRectBounds,
    long x,
    long y,
    DWORD dwMouseMsg);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPointerInactive::OnInactiveMouseMove](http://msdn.microsoft.com/library/windows/desktop/ms693374) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameoninactivesetcursora--ipointerinactiveimploninactivesetcursor"></a><a name="oninactivesetcursor"></a>IPointerInactiveImpl::OnInactiveSetCursor  
 Define o ponteiro do mouse para o objeto inativo.  
  
```
HRESULT OnInactiveSetCursor(
    LPCRECT pRectBounds,
    long x,
    long y,
    DWORD dwMouseMsg,
    BOOL fSetAlways);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPointerInactive::OnInactiveSetCursor](http://msdn.microsoft.com/library/windows/desktop/ms694336) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

