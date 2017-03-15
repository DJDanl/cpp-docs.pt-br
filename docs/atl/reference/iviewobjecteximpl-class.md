---
title: Classe IViewObjectExImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::IViewObjectExImpl<T>
- ATL.IViewObjectExImpl
- ATL::IViewObjectExImpl
- ATL.IViewObjectExImpl<T>
- IViewObjectExImpl
dev_langs:
- C++
helpviewer_keywords:
- ActiveX controls [C++], drawing
- IViewObjectEx ATL implementation
- advise sinks
- IViewObjectExImpl class
ms.assetid: ad6de760-1ee5-4883-b033-ae57beffc369
caps.latest.revision: 20
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
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 2b585a056324507cc631e64e6dbe9d0ed610361d
ms.lasthandoff: 02/25/2017

---
# <a name="iviewobjecteximpl-class"></a>Classe IViewObjectExImpl
Essa classe implementa **IUnknown** e fornece implementações padrão de [IViewObject](http://msdn.microsoft.com/library/windows/desktop/ms680763), [IViewObject2](http://msdn.microsoft.com/library/windows/desktop/ms691318), e [IViewObjectEx](http://msdn.microsoft.com/library/windows/desktop/ms682375) interfaces.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>  
class ATL_NO_VTABLE IViewObjectExImpl 
   : public IViewObjectEx
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `IViewObjectExImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IViewObjectExImpl::Draw](#draw)|Desenha uma representação do controle em um contexto de dispositivo.|  
|[IViewObjectExImpl::Freeze](#freeze)|Congela a representação de desenhada de um controle para que ele não mudará até um `Unfreeze`. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IViewObjectExImpl::GetAdvise](#getadvise)|Recupera uma conexão do coletor comunicado existente no controle, se houver.|  
|[IViewObjectExImpl::GetColorSet](#getcolorset)|Retorna a paleta lógica usada pelo controle para o desenho. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IViewObjectExImpl::GetExtent](#getextent)|Recupera o tamanho da exibição do controle em unidades HIMETRIC (0,01 milímetro por unidade) do membro de dados da classe de controle [CComControlBase::m_sizeExtent](../../atl/reference/ccomcontrolbase-class.md#m_sizeextent).|  
|[IViewObjectExImpl::GetNaturalExtent](#getnaturalextent)|Fornece dicas de dimensionamento do contêiner para o objeto a ser usado como o usuário a redimensiona.|  
|[IViewObjectExImpl::GetRect](#getrect)|Retorna um retângulo que descreve um aspecto do desenho solicitado. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IViewObjectExImpl::GetViewStatus](#getviewstatus)|Retorna informações sobre a opacidade do objeto e quais aspectos do desenho são suportados.|  
|[IViewObjectExImpl::QueryHitPoint](#queryhitpoint)|Verifica se o ponto especificado é o retângulo especificado e retorna um [HITRESULT](http://msdn.microsoft.com/library/windows/desktop/ms682187) o valor `pHitResult`.|  
|[IViewObjectExImpl::QueryHitRect](#queryhitrect)|Verifica se o retângulo de exibição do controle se sobrepõe a qualquer ponto no retângulo local especificado e retorna um **HITRESULT** o valor `pHitResult`.|  
|[IViewObjectExImpl::SetAdvise](#setadvise)|Configura uma conexão entre o controle e um coletor de aviso para que o coletor pode ser notificado sobre alterações no modo de exibição do controle.|  
|[IViewObjectExImpl::Unfreeze](#unfreeze)|Descongela a representação desenhada do controle. Retorna a implementação de ATL **E_NOTIMPL**.|  
  
## <a name="remarks"></a>Comentários  
 O [IViewObject](http://msdn.microsoft.com/library/windows/desktop/ms680763), [IViewObject2](http://msdn.microsoft.com/library/windows/desktop/ms691318), e [IViewObjectEx](http://msdn.microsoft.com/library/windows/desktop/ms682375) interfaces permitem um controle para exibir próprio diretamente e criar e gerenciar um coletor de aviso para notificar o contêiner de alterações na exibição de controle. O **IViewObjectEx** interface oferece suporte para recursos de controle estendido como desenho cintilação, controles não retangulares e transparentes e testes de colisão (por exemplo, como fechar um clique do mouse deve ser considerado no controle). Classe `IViewObjectExImpl` fornece uma implementação padrão dessas interfaces e implementa **IUnknown** enviando informações para o despejo de compilações de dispositivo no modo de depuração.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IViewObjectEx`  
  
 `IViewObjectExImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="a-namedrawa--iviewobjecteximpldraw"></a><a name="draw"></a>IViewObjectExImpl::Draw  
 Desenha uma representação do controle em um contexto de dispositivo.  
  
```
STDMETHOD(Draw)(
    DWORD dwDrawAspect,
    LONG lindex,
    void* pvAspect,
    DVTARGETDEVICE* ptd,
    HDC hicTargetDev,
    LPCRECTL prcBounds,
    LPCRECTL prcWBounds,
    BOOL(_stdcall* /* pfnContinue*/) (DWORD_PTR dwContinue),
    DWORD_PTR /* dwContinue */);
```  
  
### <a name="remarks"></a>Comentários  
 Esse método chama **CComControl::OnDrawAdvanced** que por sua vez, chama sua classe de controle `OnDraw` método. Um `OnDraw` método é adicionado automaticamente à sua classe de controle quando você cria o controle com o Assistente de controle ATL. Padrão do assistente `OnDraw` desenha um retângulo com o rótulo "ATL 3.0".  
  
 Consulte [IViewObject::Draw](http://msdn.microsoft.com/library/windows/desktop/ms688655) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namefreezea--iviewobjecteximplfreeze"></a><a name="freeze"></a>IViewObjectExImpl::Freeze  
 Congela a representação de desenhada de um controle para que ele não mudará até um `Unfreeze`. Retorna a implementação de ATL **E_NOTIMPL**.  
  
```
STDMETHOD(Freeze)(
    DWORD /* dwAspect */,
    LONG /* lindex */,
    void* /* pvAspect */,
    DWORD* /* pdwFreeze */);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IViewObject::Freeze](http://msdn.microsoft.com/library/windows/desktop/ms688728) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetadvisea--iviewobjecteximplgetadvise"></a><a name="getadvise"></a>IViewObjectExImpl::GetAdvise  
 Recupera uma conexão do coletor comunicado existente no controle, se houver.  
  
```
STDMETHOD(GetAdvise)(
    DWORD* /* pAspects */,
    DWORD* /* pAdvf */,
    IAdviseSink** /* ppAdvSink */);
```  
  
### <a name="remarks"></a>Comentários  
 O coletor de consultoria é armazenado no membro de dados da classe de controle [CComControlBase::m_spAdviseSink](../../atl/reference/ccomcontrolbase-class.md#m_spadvisesink).  
  
 Consulte [IViewObject::GetAdvise](http://msdn.microsoft.com/library/windows/desktop/ms692772) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetcolorseta--iviewobjecteximplgetcolorset"></a><a name="getcolorset"></a>IViewObjectExImpl::GetColorSet  
 Retorna a paleta lógica usada pelo controle para o desenho. Retorna a implementação de ATL **E_NOTIMPL**.  
  
```
STDMETHOD(GetColorSet)(
    DWORD /* dwAspect */,
    LONG /* lindex */,
    void* /* pvAspect */,
    DVTARGETDEVICE* /* ptd */,
    HDC /* hicTargetDevice */,
    LOGPALETTE** /* ppColorSet */);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IViewObject::GetColorSet](http://msdn.microsoft.com/library/windows/desktop/ms686553) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetextenta--iviewobjecteximplgetextent"></a><a name="getextent"></a>IViewObjectExImpl::GetExtent  
 Recupera o tamanho da exibição do controle em unidades HIMETRIC (0,01 milímetro por unidade) do membro de dados da classe de controle [CComControlBase::m_sizeExtent](../../atl/reference/ccomcontrolbase-class.md#m_sizeextent).  
  
```
STDMETHOD(GetExtent)(
    DWORD /* dwDrawAspect */,
    LONG /* lindex */,
    DVTARGETDEVICE* /* ptd */,
    LPSIZEL* lpsizel);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IViewObject2::GetExtent](http://msdn.microsoft.com/library/windows/desktop/ms684032) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetnaturalextenta--iviewobjecteximplgetnaturalextent"></a><a name="getnaturalextent"></a>IViewObjectExImpl::GetNaturalExtent  
 Fornece dicas de dimensionamento do contêiner para o objeto a ser usado como o usuário a redimensiona.  
  
```
STDMETHOD(GetNaturalExtent)(
    DWORD dwAspect,
    LONG /* lindex */,
    DVTARGETDEVICE* /* ptd */,
    HDC /* hicTargetDevice */,
    DVEXTENTINFO* pExtentInfo,
    LPSIZEL psizel);
```  
  
### <a name="remarks"></a>Comentários  
 Se `dwAspect` é `DVASPECT_CONTENT` e *pExtentInfo-> dwExtentMode* é **DVEXTENT_CONTENT**, define * `psizel` ao membro de dados da classe de controle [CComControlBase::m_sizeNatural](../../atl/reference/ccomcontrolbase-class.md#m_sizenatural). Caso contrário, retornará um erro `HRESULT`.  
  
 Consulte [IViewObjectEx::GetNaturalExtent](http://msdn.microsoft.com/library/windows/desktop/ms683718) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetrecta--iviewobjecteximplgetrect"></a><a name="getrect"></a>IViewObjectExImpl::GetRect  
 Retorna um retângulo que descreve um aspecto do desenho solicitado. Retorna a implementação de ATL **E_NOTIMPL**.  
  
```
STDMETHOD(GetRect)(DWORD /* dwAspect */, LPRECTL /* pRect */);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IViewObjectEx::GetRect](http://msdn.microsoft.com/library/windows/desktop/ms695246) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetviewstatusa--iviewobjecteximplgetviewstatus"></a><a name="getviewstatus"></a>IViewObjectExImpl::GetViewStatus  
 Retorna informações sobre a opacidade do objeto e quais aspectos do desenho são suportados.  
  
```
STDMETHOD(GetViewStatus)(DWORD* pdwStatus);
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o ATL define `pdwStatus` para indicar que o controle suporta **VIEWSTATUS_OPAQUE** (valores possíveis estão no [VIEWSTATUS](http://msdn.microsoft.com/library/windows/desktop/ms687201) enumeração).  
  
 Consulte [IViewObjectEx::GetViewStatus](http://msdn.microsoft.com/library/windows/desktop/ms693371) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namequeryhitpointa--iviewobjecteximplqueryhitpoint"></a><a name="queryhitpoint"></a>IViewObjectExImpl::QueryHitPoint  
 Verifica se o ponto especificado é o retângulo especificado e retorna um [HITRESULT](http://msdn.microsoft.com/library/windows/desktop/ms682187) o valor `pHitResult`.  
  
```
STDMETHOD(QueryHitPoint)(
    DWORD dwAspect,
    LPCRECT pRectBounds,
    POINT ptlLoc,
    LONG /* lCloseHit */,
    DWORD* /* pHitResult */);
```  
  
### <a name="remarks"></a>Comentários  
 O valor pode ser **HITRESULT_HIT** ou **HITRESULT_OUTSIDE**.  
  
 Se `dwAspect` é igual a [DVASPECT_CONTENT](http://msdn.microsoft.com/library/windows/desktop/ms690318), o método retorna `S_OK`. Caso contrário, o método retorna **E_FAIL**.  
  
 Consulte [IViewObjectEx::QueryHitPoint](http://msdn.microsoft.com/library/windows/desktop/ms691209) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namequeryhitrecta--iviewobjecteximplqueryhitrect"></a><a name="queryhitrect"></a>IViewObjectExImpl::QueryHitRect  
 Verifica se o retângulo de exibição do controle se sobrepõe a qualquer ponto no retângulo local especificado e retorna um [HITRESULT](http://msdn.microsoft.com/library/windows/desktop/ms682187) o valor `pHitResult`.  
  
```
STDMETHOD(QueryHitRect)(
    DWORD dwAspect,
    LPCRECT pRectBounds,
    LPRECT prcLoc,
    LONG /* lCloseHit */,
    DWORD* /* pHitResult */);
```  
  
### <a name="remarks"></a>Comentários  
 O valor pode ser **HITRESULT_HIT** ou **HITRESULT_OUTSIDE**.  
  
 Se `dwAspect` é igual a [DVASPECT_CONTENT](http://msdn.microsoft.com/library/windows/desktop/ms690318), o método retorna `S_OK`. Caso contrário, o método retorna **E_FAIL**.  
  
 Consulte [IViewObjectEx::QueryHitRect](http://msdn.microsoft.com/library/windows/desktop/ms693797) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetadvisea--iviewobjecteximplsetadvise"></a><a name="setadvise"></a>IViewObjectExImpl::SetAdvise  
 Configura uma conexão entre o controle e um coletor de aviso para que o coletor pode ser notificado sobre alterações no modo de exibição do controle.  
  
```
STDMETHOD(SetAdvise)(
    DWORD /* aspects */,
    DWORD /* advf */,
    IAdviseSink* pAdvSink);
```  
  
### <a name="remarks"></a>Comentários  

 O ponteiro para o [IAdviseSink](http://msdn.microsoft.com/library/windows/desktop/ms692513) interface do coletor de advise é armazenado no membro de dados da classe de controle [CComControlBase::m_spAdviseSink](ccomcontrolbase-class.md#m_spadvisesink).  

  
 Consulte [IViewObject::SetAdvise](http://msdn.microsoft.com/library/windows/desktop/ms683950) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameunfreezea--iviewobjecteximplunfreeze"></a><a name="unfreeze"></a>IViewObjectExImpl::Unfreeze  
 Descongela a representação desenhada do controle. Retorna a implementação de ATL **E_NOTIMPL**.  
  
```
STDMETHOD(Unfreeze)(DWORD /* dwFreeze */);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IViewObject::Unfreeze](http://msdn.microsoft.com/library/windows/desktop/ms686641) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameclosehandlea--iworkerthreadclientclosehandle"></a><a name="closehandle"></a>IWorkerThreadClient::CloseHandle  
 Implemente esse método para fechar um identificador associado a este objeto.  
  
```
HRESULT CloseHandle(HANDLE hHandle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hHandle*  
 O identificador seja fechado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no sucesso ou erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O identificador passado para esse método foi previamente associado a este objeto por uma chamada a [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).  
  
### <a name="example"></a>Exemplo  
 O código a seguir mostra uma implementação simples de `IWorkerThreadClient::CloseHandle`.  
  
 [!code-cpp[NVC_ATL_Utilities&#135;](../../atl/codesnippet/cpp/iviewobjecteximpl-class_1.cpp)]  
  
##  <a name="a-nameexecutea--iworkerthreadclientexecute"></a><a name="execute"></a>IWorkerThreadClient::Execute  
 Implemente esse método para executar código quando um identificador associado a esse objeto se torna sinalizado.  
  
```
HRESULT Execute(DWORD_PTR dwParam, HANDLE hObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwParam`  
 O parâmetro de usuário.  
  
 `hObject`  
 O identificador que tornou-se sinalizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no sucesso ou erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O identificador e passado para este método DWORD/ponteiro foram previamente associado a este objeto por uma chamada a [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).  
  
### <a name="example"></a>Exemplo  
 O código a seguir mostra uma implementação simples de `IWorkerThreadClient::Execute`.  
  
 [!code-cpp[NVC_ATL_Utilities&#136;](../../atl/codesnippet/cpp/iviewobjecteximpl-class_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe de CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Interfaces de controles ActiveX](http://msdn.microsoft.com/library/windows/desktop/ms692724)   
 [Tutorial](../../atl/active-template-library-atl-tutorial.md)   
 [Criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

