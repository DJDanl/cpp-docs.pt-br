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
ms.openlocfilehash: 59c5657dcd892544f7e790b52325cb9ecba0dd56
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326336"
---
# <a name="iviewobjecteximpl-class"></a>Classe IViewObjectExImpl

Essa classe `IUnknown` implementa e fornece implementações padrão das interfaces [IViewObject,](/windows/win32/api/oleidl/nn-oleidl-iviewobject) [IViewObject2](/windows/win32/api/oleidl/nn-oleidl-iviewobject2)e [IViewObjectEx.](/windows/win32/api/ocidl/nn-ocidl-iviewobjectex)

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

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

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IViewObjectExImpl::Draw](#draw)|Desenha uma representação do controle em um contexto de dispositivo.|
|[IViewObjectExImpl::Freeze](#freeze)|Congela a representação desenhada de um controle para `Unfreeze`que ele não mude até que um . A implementação da ATL retorna E_NOTIMPL.|
|[IViewObjectExImpl::GetAdvise](#getadvise)|Recupera uma conexão de afundamento de aviso existente no controle, se houver uma.|
|[IViewObjectExImpl::GetColorSet](#getcolorset)|Retorna a paleta lógica usada pelo controle para desenhar. A implementação da ATL retorna E_NOTIMPL.|
|[IViewObjectExImpl::GetExtent](#getextent)|Recupera o tamanho de exibição do controle em unidades HIMETRIC (0,01 milímetros por unidade) do membro de dados da classe de controle [CComControlBase::m_sizeExtent](../../atl/reference/ccomcontrolbase-class.md#m_sizeextent).|
|[IViewObjectExImpl::GetNaturalExtent](#getnaturalextent)|Fornece dicas de dimensionamento do recipiente para o objeto usá-lo à medida que o usuário redimensioná-lo.|
|[IViewObjectExImpl::GetRect](#getrect)|Retorna um retângulo descrevendo um aspecto de desenho solicitado. A implementação da ATL retorna E_NOTIMPL.|
|[IViewObjectExImpl::GetViewStatus](#getviewstatus)|Retorna informações sobre a opacidade do objeto e quais aspectos de desenho são suportados.|
|[IViewObjectExImpl::QueryHitPoint](#queryhitpoint)|Verifica se o ponto especificado está no retângulo especificado `pHitResult`e retorna um valor [HITRESULT](/windows/win32/api/ocidl/ne-ocidl-hitresult) em .|
|[IViewObjectExImpl::QueryHitRect](#queryhitrect)|Verifica se o retângulo de exibição do controle se sobrepõe a qualquer ponto `pHitResult`no retângulo de localização especificado e retorna um valor HITRESULT em .|
|[IViewObjectExImpl::SetAdvise](#setadvise)|Configura uma conexão entre o controle e uma pia de aconselhamento para que a pia possa ser notificada sobre alterações na visão do controle.|
|[IViewObjectExImpl::Descongelar](#unfreeze)|Descongela a representação desenhada do controle. A implementação da ATL retorna E_NOTIMPL.|

## <a name="remarks"></a>Comentários

As interfaces [IViewObject,](/windows/win32/api/oleidl/nn-oleidl-iviewobject) [IViewObject2](/windows/win32/api/oleidl/nn-oleidl-iviewobject2)e [IViewObjectEx](/windows/win32/api/ocidl/nn-ocidl-iviewobjectex) permitem que um controle se exiba diretamente e crie e gerencie um dissipador de aconselhamento para notificar o contêiner de alterações no visor de controle. A `IViewObjectEx` interface oferece suporte para recursos de controle estendido, como desenho sem cintilação, controles não retangulares e transparentes e testes de hit (por exemplo, quão perto um clique do mouse deve ser considerado no controle). A `IViewObjectExImpl` classe fornece uma implementação padrão `IUnknown` dessas interfaces e implementações enviando informações para o dispositivo de despejo em compilações de depuração.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IViewObjectEx`

`IViewObjectExImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="iviewobjecteximpldraw"></a><a name="draw"></a>IViewObjectExImpl::Draw

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

Este método `CComControl::OnDrawAdvanced` chama o que, por `OnDraw` sua vez, chama o método da sua classe de controle. Um `OnDraw` método é adicionado automaticamente à sua classe de controle quando você cria seu controle com o Assistente de Controle ATL. O padrão `OnDraw` do Assistente desenha um retângulo com o rótulo "ATL 3.0".

Consulte [IViewObject::Draw](/windows/win32/api/oleidl/nf-oleidl-iviewobject-draw) no SDK do Windows.

## <a name="iviewobjecteximplfreeze"></a><a name="freeze"></a>IViewObjectExImpl::Freeze

Congela a representação desenhada de um controle para `Unfreeze`que ele não mude até que um . A implementação da ATL retorna E_NOTIMPL.

```
STDMETHOD(Freeze)(
    DWORD /* dwAspect */,
    LONG /* lindex */,
    void* /* pvAspect */,
    DWORD* /* pdwFreeze */);
```

### <a name="remarks"></a>Comentários

Veja [IViewObject::Congelar](/windows/win32/api/oleidl/nf-oleidl-iviewobject-freeze) no SDK do Windows.

## <a name="iviewobjecteximplgetadvise"></a><a name="getadvise"></a>IViewObjectExImpl::GetAdvise

Recupera uma conexão de afundamento de aviso existente no controle, se houver uma.

```
STDMETHOD(GetAdvise)(
    DWORD* /* pAspects */,
    DWORD* /* pAdvf */,
    IAdviseSink** /* ppAdvSink */);
```

### <a name="remarks"></a>Comentários

O dissipador de avisos é armazenado no membro de dados da classe de controle [CComControlBase::m_spAdviseSink](../../atl/reference/ccomcontrolbase-class.md#m_spadvisesink).

Consulte [IViewObject::GetAdvise](/windows/win32/api/oleidl/nf-oleidl-iviewobject-getadvise) no Windows SDK.

## <a name="iviewobjecteximplgetcolorset"></a><a name="getcolorset"></a>IViewObjectExImpl::GetColorSet

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

Veja [IViewObject::GetColorSet](/windows/win32/api/oleidl/nf-oleidl-iviewobject-getcolorset) no Windows SDK.

## <a name="iviewobjecteximplgetextent"></a><a name="getextent"></a>IViewObjectExImpl::GetExtent

Recupera o tamanho de exibição do controle em unidades HIMETRIC (0,01 milímetros por unidade) do membro de dados da classe de controle [CComControlBase::m_sizeExtent](../../atl/reference/ccomcontrolbase-class.md#m_sizeextent).

```
STDMETHOD(GetExtent)(
    DWORD /* dwDrawAspect */,
    LONG /* lindex */,
    DVTARGETDEVICE* /* ptd */,
    LPSIZEL* lpsizel);
```

### <a name="remarks"></a>Comentários

Consulte [IViewObject2::GetExtent](/windows/win32/api/oleidl/nf-oleidl-iviewobject2-getextent) no Windows SDK.

## <a name="iviewobjecteximplgetnaturalextent"></a><a name="getnaturalextent"></a>IViewObjectExImpl::GetNaturalExtent

Fornece dicas de dimensionamento do recipiente para o objeto usá-lo à medida que o usuário redimensioná-lo.

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

Se `dwAspect` for DVASPECT_CONTENT e *pExtentInfo->dwExtentMode* está DVEXTENT_CONTENT, define * `psizel` para o membro de dados da classe de controle [CComControlBase::m_sizeNatural](../../atl/reference/ccomcontrolbase-class.md#m_sizenatural). Caso contrário, retorna um erro HRESULT.

Consulte [IViewObjectEx::GetNaturalExtent](/windows/win32/api/ocidl/nf-ocidl-iviewobjectex-getnaturalextent) no Windows SDK.

## <a name="iviewobjecteximplgetrect"></a><a name="getrect"></a>IViewObjectExImpl::GetRect

Retorna um retângulo descrevendo um aspecto de desenho solicitado. A implementação da ATL retorna E_NOTIMPL.

```
STDMETHOD(GetRect)(DWORD /* dwAspect */, LPRECTL /* pRect */);
```

### <a name="remarks"></a>Comentários

Consulte [IViewObjectEx::GetRect](/windows/win32/api/ocidl/nf-ocidl-iviewobjectex-getrect) no Windows SDK.

## <a name="iviewobjecteximplgetviewstatus"></a><a name="getviewstatus"></a>IViewObjectExImpl::GetViewStatus

Retorna informações sobre a opacidade do objeto e quais aspectos de desenho são suportados.

```
STDMETHOD(GetViewStatus)(DWORD* pdwStatus);
```

### <a name="remarks"></a>Comentários

Por padrão, o `pdwStatus` ATL define para indicar que o controle suporta VIEWSTATUS_OPAQUE (os valores possíveis estão na enumeração [VIEWSTATUS).](/windows/win32/api/ocidl/ne-ocidl-viewstatus)

Consulte [IViewObjectEx::GetViewStatus](/windows/win32/api/ocidl/nf-ocidl-iviewobjectex-getviewstatus) no Windows SDK.

## <a name="iviewobjecteximplqueryhitpoint"></a><a name="queryhitpoint"></a>IViewObjectExImpl::QueryHitPoint

Verifica se o ponto especificado está no retângulo especificado `pHitResult`e retorna um valor [HITRESULT](/windows/win32/api/ocidl/ne-ocidl-hitresult) em .

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

Se `dwAspect` for igual [a DVASPECT_CONTENT,](/windows/win32/api/wtypes/ne-wtypes-dvaspect)o método retorna S_OK. Caso contrário, o método retorna E_FAIL.

Consulte [IViewObjectEx::QueryHitPoint](/windows/win32/api/ocidl/nf-ocidl-iviewobjectex-queryhitpoint) no Windows SDK.

## <a name="iviewobjecteximplqueryhitrect"></a><a name="queryhitrect"></a>IViewObjectExImpl::QueryHitRect

Verifica se o retângulo de exibição do controle se sobrepõe a qualquer ponto `pHitResult`no retângulo de localização especificado e retorna um valor [HITRESULT](/windows/win32/api/ocidl/ne-ocidl-hitresult) em .

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

Se `dwAspect` for igual [a DVASPECT_CONTENT,](/windows/win32/api/wtypes/ne-wtypes-dvaspect)o método retorna S_OK. Caso contrário, o método retorna E_FAIL.

Consulte [IViewObjectEx::QueryHitRect](/windows/win32/api/ocidl/nf-ocidl-iviewobjectex-queryhitrect) no Windows SDK.

## <a name="iviewobjecteximplsetadvise"></a><a name="setadvise"></a>IViewObjectExImpl::SetAdvise

Configura uma conexão entre o controle e uma pia de aconselhamento para que a pia possa ser notificada sobre alterações na visão do controle.

```
STDMETHOD(SetAdvise)(
    DWORD /* aspects */,
    DWORD /* advf */,
    IAdviseSink* pAdvSink);
```

### <a name="remarks"></a>Comentários

O ponteiro para a interface [IAdviseSink](/windows/win32/api/objidl/nn-objidl-iadvisesink) no dissipador de conselhos é armazenado no membro de dados da classe de controle [CComControlBase::m_spAdviseSink](ccomcontrolbase-class.md#m_spadvisesink).

Consulte [IViewObject::SetAdvise](/windows/win32/api/oleidl/nf-oleidl-iviewobject-setadvise) no Windows SDK.

## <a name="iviewobjecteximplunfreeze"></a><a name="unfreeze"></a>IViewObjectExImpl::Descongelar

Descongela a representação desenhada do controle. A implementação da ATL retorna E_NOTIMPL.

```
STDMETHOD(Unfreeze)(DWORD /* dwFreeze */);
```

### <a name="remarks"></a>Comentários

Veja [IViewObject::Descongelar](/windows/win32/api/oleidl/nf-oleidl-iviewobject-unfreeze) no SDK do Windows.

## <a name="iworkerthreadclientclosehandle"></a><a name="closehandle"></a>iWorkerThreadClient::CloseHandle

Implemente este método para fechar a alça associada a este objeto.

```
HRESULT CloseHandle(HANDLE hHandle);
```

### <a name="parameters"></a>Parâmetros

*Hhandle*<br/>
A alça será fechada.

### <a name="return-value"></a>Valor retornado

O retorno S_OK no sucesso ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

A alça passada para este método foi anteriormente associada a este objeto por uma chamada para [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).

### <a name="example"></a>Exemplo

O código a seguir `IWorkerThreadClient::CloseHandle`mostra uma implementação simples de .

[!code-cpp[NVC_ATL_Utilities#135](../../atl/codesnippet/cpp/iviewobjecteximpl-class_1.cpp)]

## <a name="iworkerthreadclientexecute"></a><a name="execute"></a>iWorkerThreadClient::execute

Implemente este método para executar o código quando a alça associada a este objeto for sinalizada.

```
HRESULT Execute(DWORD_PTR dwParam, HANDLE hObject);
```

### <a name="parameters"></a>Parâmetros

*Dwparam*<br/>
O parâmetro do usuário.

*Hobject*<br/>
A alça que se tornou sinalizada.

### <a name="return-value"></a>Valor retornado

O retorno S_OK no sucesso ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

A alça e o DWORD/ponteiro passados para este método foram previamente associados a este objeto por uma chamada para [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).

### <a name="example"></a>Exemplo

O código a seguir `IWorkerThreadClient::Execute`mostra uma implementação simples de .

[!code-cpp[NVC_ATL_Utilities#136](../../atl/codesnippet/cpp/iviewobjecteximpl-class_2.cpp)]

## <a name="see-also"></a>Confira também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Interfaces de controles ActiveX](/windows/win32/com/activex-controls-interfaces)<br/>
[Tutorial](../../atl/active-template-library-atl-tutorial.md)<br/>
[Como criar um projeto da ATL](../../atl/reference/creating-an-atl-project.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
