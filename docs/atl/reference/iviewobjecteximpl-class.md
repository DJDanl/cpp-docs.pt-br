---
title: Classe IViewObjectExImpl
ms.date: 11/04/2016
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
helpviewer_keywords:
- ActiveX controls [C++], drawing
- IViewObjectEx ATL implementation
- advise sinks
- IViewObjectExImpl class
ms.assetid: ad6de760-1ee5-4883-b033-ae57beffc369
ms.openlocfilehash: 3aead41f317d175eac9dcb094aa2070d82dc6185
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495497"
---
# <a name="iviewobjecteximpl-class"></a>Classe IViewObjectExImpl

Essa classe implementa `IUnknown` e fornece implementações padrão das interfaces [IViewObject](/windows/win32/api/oleidl/nn-oleidl-iviewobject), [IViewObject2](/windows/win32/api/oleidl/nn-oleidl-iviewobject2)e [IViewObjectEx](/windows/win32/api/ocidl/nn-ocidl-iviewobjectex) .

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class ATL_NO_VTABLE IViewObjectExImpl
   : public IViewObjectEx
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IViewObjectExImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IViewObjectExImpl::Draw](#draw)|Desenha uma representação do controle em um contexto de dispositivo.|
|[IViewObjectExImpl::Freeze](#freeze)|Congela a representação desenhada de um controle para que ele não mude `Unfreeze`até um. A implementação da ATL retorna E_NOTIMPL.|
|[IViewObjectExImpl::GetAdvise](#getadvise)|Recupera uma conexão de coletor de consultoria existente no controle, se houver uma.|
|[IViewObjectExImpl::GetColorSet](#getcolorset)|Retorna a paleta lógica usada pelo controle para desenhar. A implementação da ATL retorna E_NOTIMPL.|
|[IViewObjectExImpl::GetExtent](#getextent)|Recupera o tamanho de exibição do controle em unidades HIMETRIC (0, 1 milímetros por unidade) do membro de dados da classe de controle [CComControlBase:: m_sizeExtent](../../atl/reference/ccomcontrolbase-class.md#m_sizeextent).|
|[IViewObjectExImpl::GetNaturalExtent](#getnaturalextent)|Fornece dicas de dimensionamento do contêiner para o objeto usar à medida que o usuário o redimensiona.|
|[IViewObjectExImpl::GetRect](#getrect)|Retorna um retângulo que descreve um aspecto de desenho solicitado. A implementação da ATL retorna E_NOTIMPL.|
|[IViewObjectExImpl::GetViewStatus](#getviewstatus)|Retorna informações sobre a opacidade do objeto e quais aspectos de desenho têm suporte.|
|[IViewObjectExImpl::QueryHitPoint](#queryhitpoint)|Verifica se o ponto especificado está no retângulo especificado e retorna um valor de [HITRESULT](/windows/win32/api/ocidl/ne-ocidl-hitresult) em `pHitResult`.|
|[IViewObjectExImpl::QueryHitRect](#queryhitrect)|Verifica se o retângulo de exibição do controle sobrepõe qualquer ponto no retângulo de local especificado e retorna um valor de HITRESULT `pHitResult`em.|
|[IViewObjectExImpl::SetAdvise](#setadvise)|Configura uma conexão entre o controle e um coletor de aviso para que o coletor possa ser notificado sobre alterações na exibição do controle.|
|[IViewObjectExImpl::Unfreeze](#unfreeze)|Descongela a representação desenhada do controle. A implementação da ATL retorna E_NOTIMPL.|

## <a name="remarks"></a>Comentários

As interfaces [IViewObject](/windows/win32/api/oleidl/nn-oleidl-iviewobject), [IViewObject2](/windows/win32/api/oleidl/nn-oleidl-iviewobject2)e [IViewObjectEx](/windows/win32/api/ocidl/nn-ocidl-iviewobjectex) permitem que um controle seja exibido diretamente e crie e gerencie um coletor de aviso para notificar o contêiner das alterações na exibição do controle. A `IViewObjectEx` interface fornece suporte para recursos de controle estendidos, como desenho sem cintilação, controles não retangulares e transparentes, e teste de impacto (por exemplo, como fechar um clique do mouse deve ser considerado no controle). Fornece uma implementação padrão dessas interfaces e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração. `IViewObjectExImpl`

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IViewObjectEx`

`IViewObjectExImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl. h

##  <a name="draw"></a>IViewObjectExImpl::D bruto

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

Esse método chama `CComControl::OnDrawAdvanced` o que, por sua vez, chama `OnDraw` o método da classe de controle. Um `OnDraw` método é adicionado automaticamente à sua classe de controle quando você cria seu controle com o assistente de controle do ATL. O padrão `OnDraw` do assistente desenha um retângulo com o rótulo "ATL 3,0".

Consulte [IViewObject::D RAW](/windows/win32/api/oleidl/nf-oleidl-iviewobject-draw) no SDK do Windows.

##  <a name="freeze"></a>  IViewObjectExImpl::Freeze

Congela a representação desenhada de um controle para que ele não mude `Unfreeze`até um. A implementação da ATL retorna E_NOTIMPL.

```
STDMETHOD(Freeze)(
    DWORD /* dwAspect */,
    LONG /* lindex */,
    void* /* pvAspect */,
    DWORD* /* pdwFreeze */);
```

### <a name="remarks"></a>Comentários

Consulte [IViewObject:: Freeze](/windows/win32/api/oleidl/nf-oleidl-iviewobject-freeze) no SDK do Windows.

##  <a name="getadvise"></a>  IViewObjectExImpl::GetAdvise

Recupera uma conexão de coletor de consultoria existente no controle, se houver uma.

```
STDMETHOD(GetAdvise)(
    DWORD* /* pAspects */,
    DWORD* /* pAdvf */,
    IAdviseSink** /* ppAdvSink */);
```

### <a name="remarks"></a>Comentários

O coletor de consultoria é armazenado no membro de dados da classe de controle [CComControlBase:: m_spAdviseSink](../../atl/reference/ccomcontrolbase-class.md#m_spadvisesink).

Consulte [IViewObject:: getaconselhe](/windows/win32/api/oleidl/nf-oleidl-iviewobject-getadvise) na SDK do Windows.

##  <a name="getcolorset"></a>  IViewObjectExImpl::GetColorSet

Retorna a paleta lógica usada pelo controle para desenhar. A implementação da ATL retorna E_NOTIMPL.

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

Consulte [IViewObject:: GetColorSet](/windows/win32/api/oleidl/nf-oleidl-iviewobject-getcolorset) na SDK do Windows.

##  <a name="getextent"></a>  IViewObjectExImpl::GetExtent

Recupera o tamanho de exibição do controle em unidades HIMETRIC (0, 1 milímetros por unidade) do membro de dados da classe de controle [CComControlBase:: m_sizeExtent](../../atl/reference/ccomcontrolbase-class.md#m_sizeextent).

```
STDMETHOD(GetExtent)(
    DWORD /* dwDrawAspect */,
    LONG /* lindex */,
    DVTARGETDEVICE* /* ptd */,
    LPSIZEL* lpsizel);
```

### <a name="remarks"></a>Comentários

Consulte [IViewObject2:: getextensão](/windows/win32/api/oleidl/nf-oleidl-iviewobject2-getextent) no SDK do Windows.

##  <a name="getnaturalextent"></a>  IViewObjectExImpl::GetNaturalExtent

Fornece dicas de dimensionamento do contêiner para o objeto usar à medida que o usuário o redimensiona.

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

Se `dwAspect` for DVASPECT_CONTENT e *pExtentInfo-> dwExtentMode* for DVEXTENT_CONTENT, o definirá * `psizel` para o membro de dados da classe de controle [CComControlBase:: m_sizeNatural](../../atl/reference/ccomcontrolbase-class.md#m_sizenatural). Caso contrário, retorna um erro HRESULT.

Consulte [IViewObjectEx:: GetNaturalExtent](/windows/win32/api/ocidl/nf-ocidl-iviewobjectex-getnaturalextent) na SDK do Windows.

##  <a name="getrect"></a>  IViewObjectExImpl::GetRect

Retorna um retângulo que descreve um aspecto de desenho solicitado. A implementação da ATL retorna E_NOTIMPL.

```
STDMETHOD(GetRect)(DWORD /* dwAspect */, LPRECTL /* pRect */);
```

### <a name="remarks"></a>Comentários

Consulte [IViewObjectEx:: GetRect](/windows/win32/api/ocidl/nf-ocidl-iviewobjectex-getrect) no SDK do Windows.

##  <a name="getviewstatus"></a>  IViewObjectExImpl::GetViewStatus

Retorna informações sobre a opacidade do objeto e quais aspectos de desenho têm suporte.

```
STDMETHOD(GetViewStatus)(DWORD* pdwStatus);
```

### <a name="remarks"></a>Comentários

Por padrão, a ATL `pdwStatus` define para indicar que o controle dá suporte a VIEWSTATUS_OPAQUE (os valores possíveis estão na enumeração [VIEWSTATUS](/windows/win32/api/ocidl/ne-ocidl-viewstatus) ).

Consulte [IViewObjectEx:: GetViewStatus](/windows/win32/api/ocidl/nf-ocidl-iviewobjectex-getviewstatus) na SDK do Windows.

##  <a name="queryhitpoint"></a>  IViewObjectExImpl::QueryHitPoint

Verifica se o ponto especificado está no retângulo especificado e retorna um valor de [HITRESULT](/windows/win32/api/ocidl/ne-ocidl-hitresult) em `pHitResult`.

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

Se `dwAspect` for igual a [DVASPECT_CONTENT](/windows/win32/api/wtypes/ne-wtypes-dvaspect), o método retornará S_OK. Caso contrário, o método retorna E_FAIL.

Consulte [IViewObjectEx:: QueryHitPoint](/windows/win32/api/ocidl/nf-ocidl-iviewobjectex-queryhitpoint) na SDK do Windows.

##  <a name="queryhitrect"></a>  IViewObjectExImpl::QueryHitRect

Verifica se o retângulo de exibição do controle sobrepõe qualquer ponto no retângulo de local especificado e retorna um valor de [HITRESULT](/windows/win32/api/ocidl/ne-ocidl-hitresult) em `pHitResult`.

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

Se `dwAspect` for igual a [DVASPECT_CONTENT](/windows/win32/api/wtypes/ne-wtypes-dvaspect), o método retornará S_OK. Caso contrário, o método retorna E_FAIL.

Consulte [IViewObjectEx:: QueryHitRect](/windows/win32/api/ocidl/nf-ocidl-iviewobjectex-queryhitrect) na SDK do Windows.

##  <a name="setadvise"></a>  IViewObjectExImpl::SetAdvise

Configura uma conexão entre o controle e um coletor de aviso para que o coletor possa ser notificado sobre alterações na exibição do controle.

```
STDMETHOD(SetAdvise)(
    DWORD /* aspects */,
    DWORD /* advf */,
    IAdviseSink* pAdvSink);
```

### <a name="remarks"></a>Comentários

O ponteiro para a interface [IAdviseSink](/windows/win32/api/objidl/nn-objidl-iadvisesink) no coletor de aviso é armazenado no membro de dados da classe de controle [CComControlBase:: m_spAdviseSink](ccomcontrolbase-class.md#m_spadvisesink).

Consulte [IViewObject:: setaconselhe](/windows/win32/api/oleidl/nf-oleidl-iviewobject-setadvise) no SDK do Windows.

##  <a name="unfreeze"></a>  IViewObjectExImpl::Unfreeze

Descongela a representação desenhada do controle. A implementação da ATL retorna E_NOTIMPL.

```
STDMETHOD(Unfreeze)(DWORD /* dwFreeze */);
```

### <a name="remarks"></a>Comentários

Consulte [IViewObject:: descongelar](/windows/win32/api/oleidl/nf-oleidl-iviewobject-unfreeze) no SDK do Windows.

##  <a name="closehandle"></a>IWorkerThreadClient:: CloseHandle

Implemente este método para fechar o identificador associado a este objeto.

```
HRESULT CloseHandle(HANDLE hHandle);
```

### <a name="parameters"></a>Parâmetros

*hHandle*<br/>
O identificador a ser fechado.

### <a name="return-value"></a>Valor de retorno

Retornar S_OK em caso de êxito ou erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

O identificador passado para esse método foi anteriormente associado a esse objeto por uma chamada para [CWorkerThread:: AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).

### <a name="example"></a>Exemplo

O código a seguir mostra uma implementação simples `IWorkerThreadClient::CloseHandle`do.

[!code-cpp[NVC_ATL_Utilities#135](../../atl/codesnippet/cpp/iviewobjecteximpl-class_1.cpp)]

##  <a name="execute"></a>IWorkerThreadClient:: execute

Implemente esse método para executar o código quando o identificador associado a esse objeto for sinalizado.

```
HRESULT Execute(DWORD_PTR dwParam, HANDLE hObject);
```

### <a name="parameters"></a>Parâmetros

*dwParam*<br/>
O parâmetro User.

*hObject*<br/>
O identificador que se tornou sinalizado.

### <a name="return-value"></a>Valor de retorno

Retornar S_OK em caso de êxito ou erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

O identificador e o DWORD/ponteiro passados para esse método foram associados anteriormente a esse objeto por uma chamada para [CWorkerThread:: AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).

### <a name="example"></a>Exemplo

O código a seguir mostra uma implementação simples `IWorkerThreadClient::Execute`do.

[!code-cpp[NVC_ATL_Utilities#136](../../atl/codesnippet/cpp/iviewobjecteximpl-class_2.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Interfaces de controles ActiveX](/windows/win32/com/activex-controls-interfaces)<br/>
[Tutorial](../../atl/active-template-library-atl-tutorial.md)<br/>
[Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
