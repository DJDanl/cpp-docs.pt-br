---
title: Classe IOleObjectImpl
ms.date: 11/04/2016
f1_keywords:
- IOleObjectImpl
- ATLCTL/ATL::IOleObjectImpl
- ATLCTL/ATL::IOleObjectImpl::Advise
- ATLCTL/ATL::IOleObjectImpl::Close
- ATLCTL/ATL::IOleObjectImpl::DoVerb
- ATLCTL/ATL::IOleObjectImpl::DoVerbDiscardUndo
- ATLCTL/ATL::IOleObjectImpl::DoVerbHide
- ATLCTL/ATL::IOleObjectImpl::DoVerbInPlaceActivate
- ATLCTL/ATL::IOleObjectImpl::DoVerbOpen
- ATLCTL/ATL::IOleObjectImpl::DoVerbPrimary
- ATLCTL/ATL::IOleObjectImpl::DoVerbShow
- ATLCTL/ATL::IOleObjectImpl::DoVerbUIActivate
- ATLCTL/ATL::IOleObjectImpl::EnumAdvise
- ATLCTL/ATL::IOleObjectImpl::EnumVerbs
- ATLCTL/ATL::IOleObjectImpl::GetClientSite
- ATLCTL/ATL::IOleObjectImpl::GetClipboardData
- ATLCTL/ATL::IOleObjectImpl::GetExtent
- ATLCTL/ATL::IOleObjectImpl::GetMiscStatus
- ATLCTL/ATL::IOleObjectImpl::GetMoniker
- ATLCTL/ATL::IOleObjectImpl::GetUserClassID
- ATLCTL/ATL::IOleObjectImpl::GetUserType
- ATLCTL/ATL::IOleObjectImpl::InitFromData
- ATLCTL/ATL::IOleObjectImpl::IsUpToDate
- ATLCTL/ATL::IOleObjectImpl::OnPostVerbDiscardUndo
- ATLCTL/ATL::IOleObjectImpl::OnPostVerbHide
- ATLCTL/ATL::IOleObjectImpl::OnPostVerbInPlaceActivate
- ATLCTL/ATL::IOleObjectImpl::OnPostVerbOpen
- ATLCTL/ATL::IOleObjectImpl::OnPostVerbShow
- ATLCTL/ATL::IOleObjectImpl::OnPostVerbUIActivate
- ATLCTL/ATL::IOleObjectImpl::OnPreVerbDiscardUndo
- ATLCTL/ATL::IOleObjectImpl::OnPreVerbHide
- ATLCTL/ATL::IOleObjectImpl::OnPreVerbInPlaceActivate
- ATLCTL/ATL::IOleObjectImpl::OnPreVerbOpen
- ATLCTL/ATL::IOleObjectImpl::OnPreVerbShow
- ATLCTL/ATL::IOleObjectImpl::OnPreVerbUIActivate
- ATLCTL/ATL::IOleObjectImpl::SetClientSite
- ATLCTL/ATL::IOleObjectImpl::SetColorScheme
- ATLCTL/ATL::IOleObjectImpl::SetExtent
- ATLCTL/ATL::IOleObjectImpl::SetHostNames
- ATLCTL/ATL::IOleObjectImpl::SetMoniker
- ATLCTL/ATL::IOleObjectImpl::Unadvise
- ATLCTL/ATL::IOleObjectImpl::Update
helpviewer_keywords:
- ActiveX controls [C++], communication between container and control
- IOleObject, ATL implementation
- IOleObjectImpl class
ms.assetid: 59750b2d-1633-4a51-a4c2-6455b6b90c45
ms.openlocfilehash: 86d82aea2e92eb99903284abe4ac03478369616c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326520"
---
# <a name="ioleobjectimpl-class"></a>Classe IOleObjectImpl

Esta classe `IUnknown` implementa e é a interface principal através da qual um contêiner se comunica com um controle.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class ATL_NO_VTABLE IOleObjectImpl : public IOleObject
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IOleObjectImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IOleObjectImpl:::Aconselhar](#advise)|Estabelece uma conexão consultiva com o controle.|
|[IOleObjectImpl::Fechar](#close)|Muda o estado de controle de correr para carregado.|
|[IOleObjectImpl::DoVerb](#doverb)|Diz ao controle para realizar uma de suas ações enumeradas.|
|[IOleObjectImpl::DoVerbDiscardUndo](#doverbdiscardundo)|Diz ao controle para descartar qualquer estado de desfaçata que está mantendo.|
|[IOleObjectImpl::DoVerbHide](#doverbhide)|Diz ao controle para remover sua interface de usuário da exibição.|
|[IOleObjectImpl::DoVerbInPlaceActivate](#doverbinplaceactivate)|Executa o controle e instala sua janela, mas não instala a interface de usuário do controle.|
|[IOleObjectImpl::DoVerbOpen](#doverbopen)|Faz com que o controle seja aberto em uma janela separada.|
|[IOleObjectImpl::DoVerbPrimary](#doverbprimary)|Executa a ação especificada quando o usuário clica duas vezes no controle. O controle define a ação, geralmente para ativar o controle no local.|
|[IOleObjectImpl::DoVerbShow](#doverbshow)|Mostra um controle recém-inserido ao usuário.|
|[IOleObjectImpl::DoVerbUIActivate](#doverbuiactivate)|Ativa o controle no local e mostra a interface do usuário do controle, como menus e barras de ferramentas.|
|[IOleObjectImpl::EnumAdvise](#enumadvise)|Enumera as conexões consultivas do controle.|
|[IOleObjectImpl::EnumVerbs](#enumverbs)|Enumera ações para o controle.|
|[IOleObjectImpl::GetClientSite](#getclientsite)|Recupera o site do cliente do controle.|
|[IOleObjectImpl::GetClipboardData](#getclipboarddata)|Recupera dados da Área de Transferência. A implementação da ATL retorna E_NOTIMPL.|
|[IOleObjectImpl::GetExtent](#getextent)|Recupera a extensão da área de exibição do controle.|
|[IOleObjectImpl::GetMiscStatus](#getmiscstatus)|Recupera o status do controle.|
|[IOleObjectImpl::GetMoniker](#getmoniker)|Recupera o apelido do controle. A implementação da ATL retorna E_NOTIMPL.|
|[IOleObjectImpl::GetUserClassID](#getuserclassid)|Recupera o identificador de classe do controle.|
|[IOleObjectImpl::GetUserType](#getusertype)|Recupera o nome do tipo de usuário do controle.|
|[IOleObjectImpl::InitFromData](#initfromdata)|Inicializa o controle a partir de dados selecionados. A implementação da ATL retorna E_NOTIMPL.|
|[IOleObjectImpl::IsUpToDate](#isuptodate)|Verifica se o controle está atualizado. A implementação da ATL retorna S_OK.|
|[IOleObjectImpl::OnPostVerbDiscardUndo](#onpostverbdiscardundo)|Chamado por [DoVerbDiscardUndo](#doverbdiscardundo) depois que o estado de desfazer é descartado.|
|[IOleObjectImpl::OnPostVerbHide](#onpostverbhide)|Chamado por [DoVerbHide](#doverbhide) depois que o controle é escondido.|
|[IOleObjectImpl::OnPostVerbInPlaceActivate](#onpostverbinplaceactivate)|Chamado por [DoVerbInPlaceActivate](#doverbinplaceactivate) depois que o controle é ativado no lugar.|
|[IOleObjectImpl::OnPostVerbOpen](#onpostverbopen)|Chamado por [DoVerbOpen](#doverbopen) depois que o controle foi aberto para edição em uma janela separada.|
|[IOleObjectImpl::OnPostVerbShow](#onpostverbshow)|Chamado pelo [DoVerbShow](#doverbshow) depois que o controle foi tornado visível.|
|[IOleObjectImpl::OnPostVerbUIActivate](#onpostverbuiactivate)|Chamado por [DoVerbUIActivate](#doverbuiactivate) depois que a interface de usuário do controle foi ativada.|
|[IOleObjectImpl::OnPreVerbDiscardUndo](#onpreverbdiscardundo)|Chamado por [DoVerbDiscardUndo](#doverbdiscardundo) antes que o estado de desfazer seja descartado.|
|[IOleObjectImpl::OnPreVerbHide](#onpreverbhide)|Chamado por [DoVerbHide](#doverbhide) antes que o controle seja escondido.|
|[IOleObjectImpl::OnPreVerbInPlaceActivate](#onpreverbinplaceactivate)|Chamado por [DoVerbInPlaceActivate](#doverbinplaceactivate) antes que o controle seja ativado no lugar.|
|[IOleObjectImpl::OnPreVerbOpen](#onpreverbopen)|Chamado por [DoVerbOpen](#doverbopen) antes que o controle tenha sido aberto para edição em uma janela separada.|
|[IOleObjectImpl::OnPreVerbShow](#onpreverbshow)|Chamado por [DoVerbShow](#doverbshow) antes que o controle seja visível.|
|[IOleObjectImpl::OnPreVerbUIActivate](#onpreverbuiactivate)|Chamado por [DoVerbUIActivate](#doverbuiactivate) antes que a interface de usuário do controle seja ativada.|
|[IOleObjectImpl::SetClientSite](#setclientsite)|Conta o controle sobre o local do cliente no contêiner.|
|[IOleObjectImpl::SetColorScheme](#setcolorscheme)|Recomenda um esquema de cores para a aplicação do controle, se houver. A implementação da ATL retorna E_NOTIMPL.|
|[IOleObjectImpl::SetExtent](#setextent)|Define a extensão da área de exibição do controle.|
|[IOleObjectImpl::SetHostNames](#sethostnames)|Informa ao controle os nomes da aplicação do contêiner e do documento do contêiner.|
|[IOleObjectImpl::SetMoniker](#setmoniker)|Diz ao controle qual é o seu apelido. A implementação da ATL retorna E_NOTIMPL.|
|[IOleObjectImpl::Unadvise](#unadvise)|Exclui uma conexão de aviso com o controle.|
|[IOleObjectImpl::Atualização](#update)|Atualiza o controle. A implementação da ATL retorna S_OK.|

## <a name="remarks"></a>Comentários

A interface [IOleObject](/windows/win32/api/oleidl/nn-oleidl-ioleobject) é a interface principal através da qual um contêiner se comunica com um controle. A `IOleObjectImpl` classe fornece uma implementação `IUnknown` padrão dessa interface e implementa enviando informações para o dispositivo de despejo em compilações de depuração.

**Artigos relacionados** [ATL Tutorial](../../atl/active-template-library-atl-tutorial.md), Criando um Projeto [ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IOleObject`

`IOleObjectImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="ioleobjectimpladvise"></a><a name="advise"></a>IOleObjectImpl:::Aconselhar

Estabelece uma conexão consultiva com o controle.

```
STDMETHOD(Advise)(
    IAdviseSink* pAdvSink,
    DWORD* pdwConnection);
```

### <a name="remarks"></a>Comentários

Consulte [IOleObject::Aconselhar](/windows/win32/api/oleidl/nf-oleidl-ioleobject-advise) no Windows SDK.

## <a name="ioleobjectimplclose"></a><a name="close"></a>IOleObjectImpl::Fechar

Muda o estado de controle de correr para carregado.

```
STDMETHOD(Close)(DWORD dwSaveOption);
```

### <a name="remarks"></a>Comentários

Desativa o controle e destrói a janela de controle se ela existir. Se o membro da classe de controle [CComControlBase::m_bRequiresSave](../../atl/reference/ccomcontrolbase-class.md#m_brequiressave) é TRUE e o parâmetro *dwSaveOption* estiver OLECLOSE_SAVEIFDIRTY ou OLECLOSE_PROMPTSAVE, as propriedades de controle serão salvas antes de fechar.

Os ponteiros mantidos nos membros da classe de controle [CComControlBase::m_spInPlaceSite](../../atl/reference/ccomcontrolbase-class.md#m_spinplacesite) e [CComControlBase:m_spAdviseSink](../../atl/reference/ccomcontrolbase-class.md#m_spadvisesink) são lançados e os membros de dados [CComControlBase:m_bNegotiatedWnd,](../../atl/reference/ccomcontrolbase-class.md#m_bnegotiatedwnd) [CComControlBase:m_bWndless](../../atl/reference/ccomcontrolbase-class.md#m_bwndless)e [CComControlBase:m_bInPlaceSiteEx](../../atl/reference/ccomcontrolbase-class.md#m_binplacesiteex) são definidos como FALSE.

Consulte [IOleObject::Fechar](/windows/win32/api/oleidl/nf-oleidl-ioleobject-close) no SDK do Windows.

## <a name="ioleobjectimpldoverb"></a><a name="doverb"></a>IOleObjectImpl::DoVerb

Diz ao controle para realizar uma de suas ações enumeradas.

```
STDMETHOD(DoVerb)(
    LONG iVerb,
    LPMSG /* pMsg */,
    IOleClientSite* pActiveSite,
    LONG /* lindex */,
    HWND hwndParent,
    LPCRECT lprcPosRect);
```

### <a name="remarks"></a>Comentários

Dependendo do valor `iVerb`de , uma `DoVerb` das funções de ajudante ATL é chamada da seguinte forma:

|*iVerb* Valor|Função auxiliar do Verb chamada|
|-------------------|-----------------------------------|
|OLEIVERB_DISCARDUNDOSTATE|[Doverbdiscardundo](#doverbdiscardundo)|
|OLEIVERB_HIDE|[Doverbhide](#doverbhide)|
|OLEIVERB_INPLACEACTIVATE|[Doverbinplaceactivate](#doverbinplaceactivate)|
|OLEIVERB_OPEN|[DoVerbOpen](#doverbopen)|
|OLEIVERB_PRIMARY|[DoVerbPrimary](#doverbprimary)|
|OLEIVERB_PROPERTIES|[CComControlBase::DoVerbProperties](../../atl/reference/ccomcontrolbase-class.md#doverbproperties)|
|Oleiverb_show|[Doverbshow](#doverbshow)|
|Oleiverb_uiactivate|[Doverbuiactivate](#doverbuiactivate)|

Consulte [IOleObject::DoVerb](/windows/win32/api/oleidl/nf-oleidl-ioleobject-doverb) no Windows SDK.

## <a name="ioleobjectimpldoverbdiscardundo"></a><a name="doverbdiscardundo"></a>IOleObjectImpl::DoVerbDiscardUndo

Diz ao controle para descartar qualquer estado de desfaçata que está mantendo.

```
HRESULT DoVerbDiscardUndo(LPCRECT /* prcPosRect */, HWND /* hwndParent */);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
[em] Ponteiro para o retângulo que o recipiente quer que o controle atraia.

*Hwndparent*<br/>
[em] Alça da janela contendo o controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="ioleobjectimpldoverbhide"></a><a name="doverbhide"></a>IOleObjectImpl::DoVerbHide

Desativa e remove a interface de usuário do controle e oculta o controle.

```
HRESULT DoVerbHide(LPCRECT /* prcPosRect */, HWND /* hwndParent */);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
[em] Ponteiro para o retângulo que o recipiente quer que o controle atraia.

*Hwndparent*<br/>
[em] Alça da janela contendo o controle. Não utilizado na implementação do ATL.

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="ioleobjectimpldoverbinplaceactivate"></a><a name="doverbinplaceactivate"></a>IOleObjectImpl::DoVerbInPlaceActivate

Executa o controle e instala sua janela, mas não instala a interface de usuário do controle.

```
HRESULT DoVerbInPlaceActivate(LPCRECT prcPosRect, HWND /* hwndParent */);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
[em] Ponteiro para o retângulo que o recipiente quer que o controle atraia.

*Hwndparent*<br/>
[em] Alça da janela contendo o controle. Não utilizado na implementação do ATL.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Ativa o controle no lugar ligando para [CComControlBase::InPlaceActivate](../../atl/reference/ccomcontrolbase-class.md#inplaceactivate). A menos que o `m_bWindowOnly` membro de `DoVerbInPlaceActivate` dados da classe de controle seja TRUE, primeiro tenta ativar o controle como um controle sem janelas (possível apenas se o contêiner suportar [IOleInPlaceSiteWindowless](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesitewindowless)). Se isso falhar, a função tentará ativar o controle com recursos estendidos (possível apenas se o contêiner suportar [IOleInPlaceSiteEx](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesiteex)). Se isso falhar, a função tentará ativar o controle sem recursos estendidos (possível apenas se o contêiner suportar [IOleInPlaceSite](/windows/win32/api/oleidl/nn-oleidl-ioleinplacesite)). Se a ativação for bem sucedida, a função notifica o recipiente de que o controle foi ativado.

## <a name="ioleobjectimpldoverbopen"></a><a name="doverbopen"></a>IOleObjectImpl::DoVerbOpen

Faz com que o controle seja aberto em uma janela separada.

```
HRESULT DoVerbOpen(LPCRECT /* prcPosRect */, HWND /* hwndParent */);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
[em] Ponteiro para o retângulo que o recipiente quer que o controle atraia.

*Hwndparent*<br/>
[em] Alça da janela contendo o controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="ioleobjectimpldoverbprimary"></a><a name="doverbprimary"></a>IOleObjectImpl::DoVerbPrimary

Define a ação tomada quando o usuário clica duas vezes no controle.

```
HRESULT DoVerbPrimary(LPCRECT prcPosRect, HWND hwndParent);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
[em] Ponteiro para o retângulo que o recipiente quer que o controle atraia.

*Hwndparent*<br/>
[em] Alça da janela contendo o controle.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Por padrão, defina para exibir as páginas de propriedade. Você pode substituir isso em sua classe de controle para invocar um comportamento diferente em clique duplo; por exemplo, reproduzir um vídeo ou entrar ativo no local.

## <a name="ioleobjectimpldoverbshow"></a><a name="doverbshow"></a>IOleObjectImpl::DoVerbShow

Diz ao recipiente para tornar o controle visível.

```
HRESULT DoVerbShow(LPCRECT prcPosRect, HWND /* hwndParent */);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
[em] Ponteiro para o retângulo que o recipiente quer que o controle atraia.

*Hwndparent*<br/>
[em] Alça da janela contendo o controle. Não utilizado na implementação do ATL.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ioleobjectimpldoverbuiactivate"></a><a name="doverbuiactivate"></a>IOleObjectImpl::DoVerbUIActivate

Ativa a interface do usuário do controle e notifica o contêiner de que seus menus estão sendo substituídos por menus compostos.

```
HRESULT DoVerbUIActivate(LPCRECT prcPosRect, HWND /* hwndParent */);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
[em] Ponteiro para o retângulo que o recipiente quer que o controle atraia.

*Hwndparent*<br/>
[em] Alça da janela contendo o controle. Não utilizado na implementação do ATL.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="ioleobjectimplenumadvise"></a><a name="enumadvise"></a>IOleObjectImpl::EnumAdvise

Fornece uma enumeração de conexões de assessoria registradas para este controle.

```
STDMETHOD(EnumAdvise)(IEnumSTATDATA** ppenumAdvise);
```

### <a name="remarks"></a>Comentários

Consulte [IOleObject::EnumAdvise](/windows/win32/api/oleidl/nf-oleidl-ioleobject-enumadvise) no Windows SDK.

## <a name="ioleobjectimplenumverbs"></a><a name="enumverbs"></a>IOleObjectImpl::EnumVerbs

Fornece uma enumeração de ações registradas (verbos) `OleRegEnumVerbs`para este controle por chamada .

```
STDMETHOD(EnumVerbs)(IEnumOLEVERB** ppEnumOleVerb);
```

### <a name="remarks"></a>Comentários

Você pode adicionar verbos ao arquivo .rgs do seu projeto. Por exemplo, consulte CIRCCTL. RGS na amostra [CIRC.](../../overview/visual-cpp-samples.md)

Consulte [IOleObject::EnumVerbs](/windows/win32/api/oleidl/nf-oleidl-ioleobject-enumverbs) no Windows SDK.

## <a name="ioleobjectimplgetclientsite"></a><a name="getclientsite"></a>IOleObjectImpl::GetClientSite

Coloca o ponteiro no membro de dados da classe de controle [CComControlBase::m_spClientSite](../../atl/reference/ccomcontrolbase-class.md#m_spclientsite) no *ppClientSite* e incrementa a contagem de referência no ponteiro.

```
STDMETHOD(GetClientSite)(IOleClientSite** ppClientSite);
```

### <a name="remarks"></a>Comentários

Consulte [IOleObject::GetClientSite](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getclientsite) no Windows SDK.

## <a name="ioleobjectimplgetclipboarddata"></a><a name="getclipboarddata"></a>IOleObjectImpl::GetClipboardData

Recupera dados da Área de Transferência.

```
STDMETHOD(GetClipboardData)(
    DWORD /* dwReserved */,
    IDataObject** /* ppDataObject */);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IOleObject::GetClipboardData](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getclipboarddata) no Windows SDK.

## <a name="ioleobjectimplgetextent"></a><a name="getextent"></a>IOleObjectImpl::GetExtent

Recupera o tamanho do display de um controle em execução em unidades HIMETRIC (0,01 milímetros por unidade).

```
STDMETHOD(GetExtent)(
    DWORD dwDrawAspect,
    SIZEL* psizel);
```

### <a name="remarks"></a>Comentários

O tamanho é armazenado no membro de dados da classe de controle [CComControlBase:m_sizeExtent](../../atl/reference/ccomcontrolbase-class.md#m_sizeextent).

Consulte [IOleObject::GetExtent](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getextent) no Windows SDK.

## <a name="ioleobjectimplgetmiscstatus"></a><a name="getmiscstatus"></a>IOleObjectImpl::GetMiscStatus

Retorna um ponteiro para informações de status `OleRegGetMiscStatus`registradas para o controle ligando .

```
STDMETHOD(GetMiscStatus)(
    DWORD dwAspect,
    DWORD* pdwStatus);
```

### <a name="remarks"></a>Comentários

As informações de status incluem comportamentos suportados pelos dados de controle e apresentação. Você pode adicionar informações de status ao arquivo .rgs do seu projeto.

Consulte [IOleObject::GetMiscStatus](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getmiscstatus) no Windows SDK.

## <a name="ioleobjectimplgetmoniker"></a><a name="getmoniker"></a>IOleObjectImpl::GetMoniker

Recupera o apelido do controle.

```
STDMETHOD(GetMoniker)(
    DWORD /* dwAssign */,
    DWORD /* dwWhichMoniker */,
    IMoniker** /* ppmk */);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IOleObject::GetMoniker](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getmoniker) no Windows SDK.

## <a name="ioleobjectimplgetuserclassid"></a><a name="getuserclassid"></a>IOleObjectImpl::GetUserClassID

Retorna o identificador de classe do controle.

```
STDMETHOD(GetUserClassID)(CLSID* pClsid);
```

### <a name="remarks"></a>Comentários

Consulte [IOleObject::GetUserClassID](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getuserclassid) no Windows SDK.

## <a name="ioleobjectimplgetusertype"></a><a name="getusertype"></a>IOleObjectImpl::GetUserType

Retorna o nome do tipo de `OleRegGetUserType`usuário do controle chamando .

```
STDMETHOD(GetUserType)(
    DWORD dwFormOfType,
    LPOLESTR* pszUserType);
```

### <a name="remarks"></a>Comentários

O nome do tipo de usuário é usado para exibição em elementos de interface suscitados pelo usuário, como menus e caixas de diálogo. Você pode alterar o nome do tipo de usuário no arquivo .rgs do seu projeto.

Consulte [IOleObject::GetUserType](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getusertype) no Windows SDK.

## <a name="ioleobjectimplinitfromdata"></a><a name="initfromdata"></a>IOleObjectImpl::InitFromData

Inicializa o controle a partir de dados selecionados.

```
STDMETHOD(InitFromData)(
    IDataObject* /* pDataObject */,
    BOOL /* fCreation */,
    DWORD /* dwReserved */);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IOleObject::InitFromData](/windows/win32/api/oleidl/nf-oleidl-ioleobject-initfromdata) no Windows SDK.

## <a name="ioleobjectimplisuptodate"></a><a name="isuptodate"></a>IOleObjectImpl::IsUpToDate

Verifica se o controle está atualizado.

```
STDMETHOD(IsUpToDate)(void);
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IOleObject::IsUpToDate](/windows/win32/api/oleidl/nf-oleidl-ioleobject-isuptodate) no Windows SDK.

## <a name="ioleobjectimplonpostverbdiscardundo"></a><a name="onpostverbdiscardundo"></a>IOleObjectImpl::OnPostVerbDiscardUndo

Chamado por [DoVerbDiscardUndo](#doverbdiscardundo) depois que o estado de desfazer é descartado.

```
HRESULT OnPostVerbDiscardUndo();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substituir este método com o código que você deseja executar depois que o estado de desfazer for descartado.

## <a name="ioleobjectimplonpostverbhide"></a><a name="onpostverbhide"></a>IOleObjectImpl::OnPostVerbHide

Chamado por [DoVerbHide](#doverbhide) depois que o controle é escondido.

```
HRESULT OnPostVerbHide();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substituir este método com o código que você deseja executar depois que o controle estiver escondido.

## <a name="ioleobjectimplonpostverbinplaceactivate"></a><a name="onpostverbinplaceactivate"></a>IOleObjectImpl::OnPostVerbInPlaceActivate

Chamado por [DoVerbInPlaceActivate](#doverbinplaceactivate) depois que o controle é ativado no lugar.

```
HRESULT OnPostVerbInPlaceActivate();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substituir este método com o código que você deseja executar depois que o controle é ativado no lugar.

## <a name="ioleobjectimplonpostverbopen"></a><a name="onpostverbopen"></a>IOleObjectImpl::OnPostVerbOpen

Chamado por [DoVerbOpen](#doverbopen) depois que o controle foi aberto para edição em uma janela separada.

```
HRESULT OnPostVerbOpen();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substituir este método com o código que você deseja executar depois que o controle foi aberto para edição em uma janela separada.

## <a name="ioleobjectimplonpostverbshow"></a><a name="onpostverbshow"></a>IOleObjectImpl::OnPostVerbShow

Chamado pelo [DoVerbShow](#doverbshow) depois que o controle foi tornado visível.

```
HRESULT OnPostVerbShow();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substituir este método com o código que você deseja executar depois que o controle for tornado visível.

## <a name="ioleobjectimplonpostverbuiactivate"></a><a name="onpostverbuiactivate"></a>IOleObjectImpl::OnPostVerbUIActivate

Chamado por [DoVerbUIActivate](#doverbuiactivate) depois que a interface de usuário do controle foi ativada.

```
HRESULT OnPostVerbUIActivate();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substituir este método com o código que você deseja executar depois que a interface de usuário do controle foi ativada.

## <a name="ioleobjectimplonpreverbdiscardundo"></a><a name="onpreverbdiscardundo"></a>IOleObjectImpl::OnPreVerbDiscardUndo

Chamado por [DoVerbDiscardUndo](#doverbdiscardundo) antes que o estado de desfazer seja descartado.

```
HRESULT OnPreVerbDiscardUndo();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para evitar que o estado de desfaça seja descartado, anule este método para retornar um erro HRESULT.

## <a name="ioleobjectimplonpreverbhide"></a><a name="onpreverbhide"></a>IOleObjectImpl::OnPreVerbHide

Chamado por [DoVerbHide](#doverbhide) antes que o controle seja escondido.

```
HRESULT OnPreVerbHide();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para evitar que o controle seja oculto, anule este método para retornar um erro HRESULT.

## <a name="ioleobjectimplonpreverbinplaceactivate"></a><a name="onpreverbinplaceactivate"></a>IOleObjectImpl::OnPreVerbInPlaceActivate

Chamado por [DoVerbInPlaceActivate](#doverbinplaceactivate) antes que o controle seja ativado no lugar.

```
HRESULT OnPreVerbInPlaceActivate();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para evitar que o controle seja ativado no local, anule este método para retornar um Erro HRESULT.

## <a name="ioleobjectimplonpreverbopen"></a><a name="onpreverbopen"></a>IOleObjectImpl::OnPreVerbOpen

Chamado por [DoVerbOpen](#doverbopen) antes que o controle tenha sido aberto para edição em uma janela separada.

```
HRESULT OnPreVerbOpen();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para evitar que o controle seja aberto para edição em uma janela separada, anule este método para retornar um Erro HRESULT.

## <a name="ioleobjectimplonpreverbshow"></a><a name="onpreverbshow"></a>IOleObjectImpl::OnPreVerbShow

Chamado por [DoVerbShow](#doverbshow) antes que o controle seja visível.

```
HRESULT OnPreVerbShow();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para evitar que o controle seja visível, anule este método para retornar um erro HRESULT.

## <a name="ioleobjectimplonpreverbuiactivate"></a><a name="onpreverbuiactivate"></a>IOleObjectImpl::OnPreVerbUIActivate

Chamado por [DoVerbUIActivate](#doverbuiactivate) antes que a interface de usuário do controle seja ativada.

```
HRESULT OnPreVerbUIActivate();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para evitar que a interface de usuário do controle seja ativada, anule este método para retornar um Erro HRESULT.

## <a name="ioleobjectimplsetclientsite"></a><a name="setclientsite"></a>IOleObjectImpl::SetClientSite

Conta o controle sobre o local do cliente no contêiner.

```
STDMETHOD(SetClientSite)(IOleClientSite* pClientSite);
```

### <a name="remarks"></a>Comentários

O método então retorna S_OK.

Consulte [IOleObject::SetClientSite](/windows/win32/api/oleidl/nf-oleidl-ioleobject-setclientsite) no Windows SDK.

## <a name="ioleobjectimplsetcolorscheme"></a><a name="setcolorscheme"></a>IOleObjectImpl::SetColorScheme

Recomenda um esquema de cores para a aplicação do controle, se houver.

```
STDMETHOD(SetColorScheme)(LOGPALETTE* /* pLogPal */);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IOleObject::SetColorScheme](/windows/win32/api/oleidl/nf-oleidl-ioleobject-setcolorscheme) no Windows SDK.

## <a name="ioleobjectimplsetextent"></a><a name="setextent"></a>IOleObjectImpl::SetExtent

Define a extensão da área de exibição do controle.

```
STDMETHOD(SetExtent)(
    DWORD dwDrawAspect,
    SIZEL* psizel);
```

### <a name="remarks"></a>Comentários

Caso contrário, `SetExtent` armazena o `psizel` valor apontado pelo membro da classe de controle [CComControlBase::m_sizeExtent](../../atl/reference/ccomcontrolbase-class.md#m_sizeextent). Este valor está em unidades HIMETRIC (0,01 milímetros por unidade).

Se o membro de dados da classe de `SetExtent` controle [CComControlBase::m_bResizeNatural](../../atl/reference/ccomcontrolbase-class.md#m_bresizenatural) é TRUE, também armazena o valor apontado pelo `psizel` membro da classe de controle [CComControlBase::m_sizeNatural](../../atl/reference/ccomcontrolbase-class.md#m_sizenatural).

Se o membro da classe de controle [CComControlBase::m_bRecomposeOnResize](../../atl/reference/ccomcontrolbase-class.md#m_brecomposeonresize) for TRUE, `SetExtent` chamadas `SendOnDataChange` e `SendOnViewChange` notificar todos os saques de aviso registrados com o titular do conselho de que o tamanho do controle foi alterado.

Consulte [IOleObject::SetExtent](/windows/win32/api/oleidl/nf-oleidl-ioleobject-setextent) no Windows SDK.

## <a name="ioleobjectimplsethostnames"></a><a name="sethostnames"></a>IOleObjectImpl::SetHostNames

Informa ao controle os nomes da aplicação do contêiner e do documento do contêiner.

```
STDMETHOD(SetHostNames)(LPCOLESTR /* szContainerApp */, LPCOLESTR /* szContainerObj */);
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IOleObject::SetHostNames](/windows/win32/api/oleidl/nf-oleidl-ioleobject-sethostnames) no Windows SDK.

## <a name="ioleobjectimplsetmoniker"></a><a name="setmoniker"></a>IOleObjectImpl::SetMoniker

Diz ao controle qual é o seu apelido.

```
STDMETHOD(SetMoniker)(
    DWORD /* dwWhichMoniker */,
    IMoniker** /* pmk */);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IOleObject::SetMoniker](/windows/win32/api/oleidl/nf-oleidl-ioleobject-setmoniker) no Windows SDK.

## <a name="ioleobjectimplunadvise"></a><a name="unadvise"></a>IOleObjectImpl::Unadvise

Exclui a conexão consultiva armazenada no `m_spOleAdviseHolder` membro de dados da classe de controle.

```
STDMETHOD(Unadvise)(DWORD dwConnection);
```

### <a name="remarks"></a>Comentários

Consulte [IOleObject::Unadvise](/windows/win32/api/oleidl/nf-oleidl-ioleobject-unadvise) no Windows SDK.

## <a name="ioleobjectimplupdate"></a><a name="update"></a>IOleObjectImpl::Atualização

Atualiza o controle.

```
STDMETHOD(Update)(void);
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IOleObject::Atualização](/windows/win32/api/oleidl/nf-oleidl-ioleobject-update) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Interfaces de controles ActiveX](/windows/win32/com/activex-controls-interfaces)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
