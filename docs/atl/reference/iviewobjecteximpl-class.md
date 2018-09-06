---
title: Classe IViewObjectExImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IViewObjectExImpl
- ATLCTL/ATL::IViewObjectExImpl
- ATLCTL/ATL::IViewObjectExImpl::Draw
- ATLCTL/ATL::IViewObjectExImpl::Freeze
- ATLCTL/ATL::IViewObjectExImpl::GetAdvise
- ATLCTL/ATL::IViewObjectExImpl::GetColorSet
- ATLCTL/ATL::IViewObjectExImpl::GetExtent
- ATLCTL/ATL::IViewObjectExImpl::GetNaturalExtent
- ATLCTL/ATL::IViewObjectExImpl::GetRect
- ATLCTL/ATL::IViewObjectExImpl::GetViewStatus
- ATLCTL/ATL::IViewObjectExImpl::QueryHitPoint
- ATLCTL/ATL::IViewObjectExImpl::QueryHitRect
- ATLCTL/ATL::IViewObjectExImpl::SetAdvise
- ATLCTL/ATL::IViewObjectExImpl::Unfreeze
dev_langs:
- C++
helpviewer_keywords:
- ActiveX controls [C++], drawing
- IViewObjectEx ATL implementation
- advise sinks
- IViewObjectExImpl class
ms.assetid: ad6de760-1ee5-4883-b033-ae57beffc369
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5d47c017a178d0a222780532b74db4135447f062
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43760442"
---
# <a name="iviewobjecteximpl-class"></a>Classe IViewObjectExImpl

Essa classe implementa `IUnknown` e fornece implementações padrão de [IViewObject](/windows/desktop/api/oleidl/nn-oleidl-iviewobject), [IViewObject2](/windows/desktop/api/oleidl/nn-oleidl-iviewobject2), e [IViewObjectEx](/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex) interfaces.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>  
class ATL_NO_VTABLE IViewObjectExImpl 
   : public IViewObjectEx
```

#### <a name="parameters"></a>Parâmetros

*T*  
Sua classe, derivada de `IViewObjectExImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IViewObjectExImpl::Draw](#draw)|Desenha uma representação do controle em um contexto de dispositivo.|
|[IViewObjectExImpl::Freeze](#freeze)|Congela a representação de desenhada de um controle para que ele não será alterado até que um `Unfreeze`. A implementação de ATL retornará E_NOTIMPL.|
|[IViewObjectExImpl::GetAdvise](#getadvise)|Recupera uma conexão existente do coletor de consultoria no controle, se houver um.|
|[IViewObjectExImpl::GetColorSet](#getcolorset)|Retorna a paleta lógica usada pelo controle para o desenho. A implementação de ATL retornará E_NOTIMPL.|
|[IViewObjectExImpl::GetExtent](#getextent)|Recupera o tamanho da exibição do controle em unidades HIMETRIC (corresponde a 0,01 milímetro por unidade) do membro de dados da classe de controle [CComControlBase::m_sizeExtent](../../atl/reference/ccomcontrolbase-class.md#m_sizeextent).|
|[IViewObjectExImpl::GetNaturalExtent](#getnaturalextent)|Fornece dicas de dimensionamento do contêiner para o objeto a ser usado como o usuário o redimensiona.|
|[IViewObjectExImpl::GetRect](#getrect)|Retorna um retângulo que descreve um aspecto do desenho solicitado. A implementação de ATL retornará E_NOTIMPL.|
|[IViewObjectExImpl::GetViewStatus](#getviewstatus)|Retorna informações sobre a opacidade do objeto e quais aspectos do desenho são suportados.|
|[IViewObjectExImpl::QueryHitPoint](#queryhitpoint)|Verifica se o ponto especificado está no retângulo especificado e retorna um [HITRESULT](/windows/desktop/api/ocidl/ne-ocidl-taghitresult) valor em `pHitResult`.|
|[IViewObjectExImpl::QueryHitRect](#queryhitrect)|Verifica se o retângulo de exibição do controle se sobrepõe a qualquer ponto no retângulo do local especificado e retorna um valor HITRESULT em `pHitResult`.|
|[IViewObjectExImpl::SetAdvise](#setadvise)|Configura uma conexão entre o controle e um coletor de aviso para que o coletor pode ser notificado sobre alterações no modo de exibição do controle.|
|[IViewObjectExImpl::Unfreeze](#unfreeze)|Descongela a representação desenhada do controle. A implementação de ATL retornará E_NOTIMPL.|

## <a name="remarks"></a>Comentários

O [IViewObject](/windows/desktop/api/oleidl/nn-oleidl-iviewobject), [IViewObject2](/windows/desktop/api/oleidl/nn-oleidl-iviewobject2), e [IViewObjectEx](/windows/desktop/api/ocidl/nn-ocidl-iviewobjectex) interfaces permitem um controle para exibir a mesmo diretamente e criar e gerenciar um coletor de aviso para notificar o contêiner das alterações na exibição do controle. O `IViewObjectEx` interface oferece suporte para recursos de controle estendido, como o desenho sem cintilação, controles não retangulares e transparentes e teste de clique (por exemplo, como fechar um clique do mouse deve ser considerado no controle). Classe `IViewObjectExImpl` fornece uma implementação padrão dessas interfaces e implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IViewObjectEx`

`IViewObjectExImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

##  <a name="draw"></a>  IViewObjectExImpl::Draw

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

Este método chama `CComControl::OnDrawAdvanced` que por sua vez chama sua classe de controle `OnDraw` método. Um `OnDraw` método é adicionado automaticamente à sua classe de controle quando você cria o controle com o Assistente de controle do ATL. Padrão do assistente `OnDraw` desenha um retângulo com o rótulo "ATL 3.0".

Ver [IViewObject::Draw](/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw) no Windows SDK.

##  <a name="freeze"></a>  IViewObjectExImpl::Freeze

Congela a representação de desenhada de um controle para que ele não será alterado até que um `Unfreeze`. A implementação de ATL retornará E_NOTIMPL.

```
STDMETHOD(Freeze)(
    DWORD /* dwAspect */,
    LONG /* lindex */,
    void* /* pvAspect */,
    DWORD* /* pdwFreeze */);
```

### <a name="remarks"></a>Comentários

Ver [IViewObject::Freeze](/windows/desktop/api/oleidl/nf-oleidl-iviewobject-freeze) no Windows SDK.

##  <a name="getadvise"></a>  IViewObjectExImpl::GetAdvise

Recupera uma conexão existente do coletor de consultoria no controle, se houver um.

```
STDMETHOD(GetAdvise)(
    DWORD* /* pAspects */,
    DWORD* /* pAdvf */,
    IAdviseSink** /* ppAdvSink */);
```

### <a name="remarks"></a>Comentários

O coletor de consultoria é armazenado no membro de dados de classe de controle [CComControlBase::m_spAdviseSink](../../atl/reference/ccomcontrolbase-class.md#m_spadvisesink).

Ver [IViewObject::GetAdvise](/windows/desktop/api/oleidl/nf-oleidl-iviewobject-getadvise) no Windows SDK.

##  <a name="getcolorset"></a>  IViewObjectExImpl::GetColorSet

Retorna a paleta lógica usada pelo controle para o desenho. A implementação de ATL retornará E_NOTIMPL.

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

Ver [IViewObject::GetColorSet](/windows/desktop/api/oleidl/nf-oleidl-iviewobject-getcolorset) no Windows SDK.

##  <a name="getextent"></a>  IViewObjectExImpl::GetExtent

Recupera o tamanho da exibição do controle em unidades HIMETRIC (corresponde a 0,01 milímetro por unidade) do membro de dados da classe de controle [CComControlBase::m_sizeExtent](../../atl/reference/ccomcontrolbase-class.md#m_sizeextent).

```
STDMETHOD(GetExtent)(
    DWORD /* dwDrawAspect */,
    LONG /* lindex */,
    DVTARGETDEVICE* /* ptd */,
    LPSIZEL* lpsizel);
```

### <a name="remarks"></a>Comentários

Ver [IViewObject2::GetExtent](/windows/desktop/api/oleidl/nf-oleidl-iviewobject2-getextent) no Windows SDK.

##  <a name="getnaturalextent"></a>  IViewObjectExImpl::GetNaturalExtent

Fornece dicas de dimensionamento do contêiner para o objeto a ser usado como o usuário o redimensiona.

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

Se `dwAspect` é DVASPECT_CONTENT e *pExtentInfo -> dwExtentMode* DVEXTENT_CONTENT, define * `psizel` ao membro de dados da classe do controle [CComControlBase::m_sizeNatural](../../atl/reference/ccomcontrolbase-class.md#m_sizenatural). Caso contrário, retornará um erro HRESULT.

Ver [IViewObjectEx::GetNaturalExtent](/windows/desktop/api/ocidl/nf-ocidl-iviewobjectex-getnaturalextent) no Windows SDK.

##  <a name="getrect"></a>  IViewObjectExImpl::GetRect

Retorna um retângulo que descreve um aspecto do desenho solicitado. A implementação de ATL retornará E_NOTIMPL.

```
STDMETHOD(GetRect)(DWORD /* dwAspect */, LPRECTL /* pRect */);
```

### <a name="remarks"></a>Comentários

Ver [IViewObjectEx::GetRect](/windows/desktop/api/ocidl/nf-ocidl-iviewobjectex-getrect) no Windows SDK.

##  <a name="getviewstatus"></a>  IViewObjectExImpl::GetViewStatus

Retorna informações sobre a opacidade do objeto e quais aspectos do desenho são suportados.

```
STDMETHOD(GetViewStatus)(DWORD* pdwStatus);
```

### <a name="remarks"></a>Comentários

Por padrão, o ATL define `pdwStatus` para indicar que o controle dá suporte a VIEWSTATUS_OPAQUE (os valores possíveis são em de [VIEWSTATUS](/windows/desktop/api/ocidl/ne-ocidl-tagviewstatus) enumeração).

Ver [IViewObjectEx::GetViewStatus](/windows/desktop/api/ocidl/nf-ocidl-iviewobjectex-getviewstatus) no Windows SDK.

##  <a name="queryhitpoint"></a>  IViewObjectExImpl::QueryHitPoint

Verifica se o ponto especificado está no retângulo especificado e retorna um [HITRESULT](/windows/desktop/api/ocidl/ne-ocidl-taghitresult) valor em `pHitResult`.

```
STDMETHOD(QueryHitPoint)(
    DWORD dwAspect,
    LPCRECT pRectBounds,
    POINT ptlLoc,
    LONG /* lCloseHit */,
    DWORD* /* pHitResult */);
```

### <a name="remarks"></a>Comentários

O valor pode ser HITRESULT_HIT ou HITRESULT_OUTSIDE.

Se `dwAspect` é igual a [DVASPECT_CONTENT](/windows/desktop/api/wtypes/ne-wtypes-tagdvaspect), o método retorna S_OK. Caso contrário, o método retornará E_FAIL.

Ver [IViewObjectEx::QueryHitPoint](/windows/desktop/api/ocidl/nf-ocidl-iviewobjectex-queryhitpoint) no Windows SDK.

##  <a name="queryhitrect"></a>  IViewObjectExImpl::QueryHitRect

Verifica se o retângulo de exibição do controle se sobrepõe a qualquer ponto no retângulo do local especificado e retorna um [HITRESULT](/windows/desktop/api/ocidl/ne-ocidl-taghitresult) valor em `pHitResult`.

```
STDMETHOD(QueryHitRect)(
    DWORD dwAspect,
    LPCRECT pRectBounds,
    LPRECT prcLoc,
    LONG /* lCloseHit */,
    DWORD* /* pHitResult */);
```

### <a name="remarks"></a>Comentários

O valor pode ser HITRESULT_HIT ou HITRESULT_OUTSIDE.

Se `dwAspect` é igual a [DVASPECT_CONTENT](/windows/desktop/api/wtypes/ne-wtypes-tagdvaspect), o método retorna S_OK. Caso contrário, o método retornará E_FAIL.

Ver [IViewObjectEx::QueryHitRect](/windows/desktop/api/ocidl/nf-ocidl-iviewobjectex-queryhitrect) no Windows SDK.

##  <a name="setadvise"></a>  IViewObjectExImpl::SetAdvise

Configura uma conexão entre o controle e um coletor de aviso para que o coletor pode ser notificado sobre alterações no modo de exibição do controle.

```
STDMETHOD(SetAdvise)(
    DWORD /* aspects */,
    DWORD /* advf */,
    IAdviseSink* pAdvSink);
```

### <a name="remarks"></a>Comentários

O ponteiro para o [IAdviseSink](/windows/desktop/api/objidl/nn-objidl-iadvisesink) interface em que o coletor de aviso é armazenado no membro de dados de classe de controle [CComControlBase::m_spAdviseSink](ccomcontrolbase-class.md#m_spadvisesink).  

Ver [IViewObject::SetAdvise](/windows/desktop/api/oleidl/nf-oleidl-iviewobject-setadvise) no Windows SDK.

##  <a name="unfreeze"></a>  IViewObjectExImpl::Unfreeze

Descongela a representação desenhada do controle. A implementação de ATL retornará E_NOTIMPL.

```
STDMETHOD(Unfreeze)(DWORD /* dwFreeze */);
```

### <a name="remarks"></a>Comentários

Ver [IViewObject::Unfreeze](/windows/desktop/api/oleidl/nf-oleidl-iviewobject-unfreeze) no Windows SDK.

##  <a name="closehandle"></a>  IWorkerThreadClient::CloseHandle

Implemente este método para fechar o identificador associado a este objeto.

```
HRESULT CloseHandle(HANDLE hHandle);
```

### <a name="parameters"></a>Parâmetros

*hHandle*  
O identificador seja fechado.

### <a name="return-value"></a>Valor de retorno

Retorne S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

O identificador passado para esse método era anteriormente associado ao objeto por uma chamada para [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).

### <a name="example"></a>Exemplo

O código a seguir mostra uma implementação simples de `IWorkerThreadClient::CloseHandle`.

[!code-cpp[NVC_ATL_Utilities#135](../../atl/codesnippet/cpp/iviewobjecteximpl-class_1.cpp)]

##  <a name="execute"></a>  IWorkerThreadClient::Execute

Implemente este método para executar o código quando um identificador associado a este objeto é sinalizado.

```
HRESULT Execute(DWORD_PTR dwParam, HANDLE hObject);
```

### <a name="parameters"></a>Parâmetros

*dwParam*  
O parâmetro de usuário.

*hObject*  
O identificador que foi sinalizado.

### <a name="return-value"></a>Valor de retorno

Retorne S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

O identificador e DWORD/ponteiro passado para esse método foram associada anteriormente com esse objeto por uma chamada para [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).

### <a name="example"></a>Exemplo

O código a seguir mostra uma implementação simples de `IWorkerThreadClient::Execute`.

[!code-cpp[NVC_ATL_Utilities#136](../../atl/codesnippet/cpp/iviewobjecteximpl-class_2.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)   
[Interfaces de controles ActiveX](/windows/desktop/com/activex-controls-interfaces)   
[Tutorial](../../atl/active-template-library-atl-tutorial.md)   
[Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)   
[Visão geral da classe](../../atl/atl-class-overview.md)
