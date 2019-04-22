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
ms.openlocfilehash: 5a815023d340839068873c32f1477d33053b13b4
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58775927"
---
# <a name="ioleobjectimpl-class"></a>Classe IOleObjectImpl

Essa classe implementa `IUnknown` e é a principal interface por meio do qual um contêiner se comunica com um controle.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class ATL_NO_VTABLE IOleObjectImpl : public IOleObject
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IOleObjectImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IOleObjectImpl::Advise](#advise)|Estabelece uma conexão de consultoria com o controle.|
|[IOleObjectImpl::Close](#close)|Altera o estado do controle de execução para carregar.|
|[IOleObjectImpl::DoVerb](#doverb)|Informa o controle para executar uma das suas ações enumeradas.|
|[IOleObjectImpl::DoVerbDiscardUndo](#doverbdiscardundo)|Informa o controle para descartar qualquer estado de desfazer que ele mantém.|
|[IOleObjectImpl::DoVerbHide](#doverbhide)|Informa o controle para remover sua interface do usuário do modo de exibição.|
|[IOleObjectImpl::DoVerbInPlaceActivate](#doverbinplaceactivate)|Executa o controle e instala sua janela, mas não instala a interface do usuário do controle.|
|[IOleObjectImpl::DoVerbOpen](#doverbopen)|Faz com que o controle a ser editado em aberto em uma janela separada.|
|[IOleObjectImpl::DoVerbPrimary](#doverbprimary)|Executa a ação especificada quando o usuário clica duas vezes no controle. O controle define a ação, normalmente, para ativar o controle no local.|
|[IOleObjectImpl::DoVerbShow](#doverbshow)|Mostra um controle recentemente inserido para o usuário.|
|[IOleObjectImpl::DoVerbUIActivate](#doverbuiactivate)|Ativa o controle no local e mostra a interface do usuário do controle, como menus e barras de ferramentas.|
|[IOleObjectImpl::EnumAdvise](#enumadvise)|Enumera as conexões de consultoria do controle.|
|[IOleObjectImpl::EnumVerbs](#enumverbs)|Enumera as ações para o controle.|
|[IOleObjectImpl::GetClientSite](#getclientsite)|Recupera um site do cliente do controle.|
|[IOleObjectImpl::GetClipboardData](#getclipboarddata)|Recupera dados da área de transferência. A implementação de ATL retornará E_NOTIMPL.|
|[IOleObjectImpl::GetExtent](#getextent)|Recupera a extensão da área de exibição do controle.|
|[IOleObjectImpl::GetMiscStatus](#getmiscstatus)|Recupera o status do controle.|
|[IOleObjectImpl::GetMoniker](#getmoniker)|Recupera o identificador de origem do controle. A implementação de ATL retornará E_NOTIMPL.|
|[IOleObjectImpl::GetUserClassID](#getuserclassid)|Recupera o identificador de classe do controle.|
|[IOleObjectImpl::GetUserType](#getusertype)|Recupera o nome do tipo de usuário do controle.|
|[IOleObjectImpl::InitFromData](#initfromdata)|Inicializa o controle de dados selecionada. A implementação de ATL retornará E_NOTIMPL.|
|[IOleObjectImpl::IsUpToDate](#isuptodate)|Verifica se o controle está atualizado. A implementação de ATL Retorna S_OK.|
|[IOleObjectImpl::OnPostVerbDiscardUndo](#onpostverbdiscardundo)|Chamado pelo [DoVerbDiscardUndo](#doverbdiscardundo) depois que o estado de desfazer é descartado.|
|[IOleObjectImpl::OnPostVerbHide](#onpostverbhide)|Chamado pelo [DoVerbHide](#doverbhide) depois que o controle está oculto.|
|[IOleObjectImpl::OnPostVerbInPlaceActivate](#onpostverbinplaceactivate)|Chamado pelo [DoVerbInPlaceActivate](#doverbinplaceactivate) depois que o controle é ativado em vigor.|
|[IOleObjectImpl::OnPostVerbOpen](#onpostverbopen)|Chamado pelo [DoVerbOpen](#doverbopen) depois que o controle foi aberto para edição em uma janela separada.|
|[IOleObjectImpl::OnPostVerbShow](#onpostverbshow)|Chamado pelo [DoVerbShow](#doverbshow) depois que o controle foi feito visível.|
|[IOleObjectImpl::OnPostVerbUIActivate](#onpostverbuiactivate)|Chamado pelo [DoVerbUIActivate](#doverbuiactivate) após a ativação de interface do usuário do controle.|
|[IOleObjectImpl::OnPreVerbDiscardUndo](#onpreverbdiscardundo)|Chamado pelo [DoVerbDiscardUndo](#doverbdiscardundo) antes de desfazer o estado será descartado.|
|[IOleObjectImpl::OnPreVerbHide](#onpreverbhide)|Chamado pelo [DoVerbHide](#doverbhide) antes que o controle está oculto.|
|[IOleObjectImpl::OnPreVerbInPlaceActivate](#onpreverbinplaceactivate)|Chamado pelo [DoVerbInPlaceActivate](#doverbinplaceactivate) antes do controle é ativado em vigor.|
|[IOleObjectImpl::OnPreVerbOpen](#onpreverbopen)|Chamado pelo [DoVerbOpen](#doverbopen) antes do controle foi aberto para edição em uma janela separada.|
|[IOleObjectImpl::OnPreVerbShow](#onpreverbshow)|Chamado pelo [DoVerbShow](#doverbshow) antes do controle foi feito visível.|
|[IOleObjectImpl::OnPreVerbUIActivate](#onpreverbuiactivate)|Chamado pelo [DoVerbUIActivate](#doverbuiactivate) antes de interface do usuário do controle foi ativado.|
|[IOleObjectImpl::SetClientSite](#setclientsite)|Informa o controle sobre seu site de cliente no contêiner.|
|[IOleObjectImpl::SetColorScheme](#setcolorscheme)|Recomenda um esquema de cores para o aplicativo do controle, se houver. A implementação de ATL retornará E_NOTIMPL.|
|[IOleObjectImpl::SetExtent](#setextent)|Define a extensão da área de exibição do controle.|
|[IOleObjectImpl::SetHostNames](#sethostnames)|Informa o controle os nomes do aplicativo de contêiner e do documento contêiner.|
|[IOleObjectImpl::SetMoniker](#setmoniker)|Informa ao controle qual é seu identificador de origem. A implementação de ATL retornará E_NOTIMPL.|
|[IOleObjectImpl::Unadvise](#unadvise)|Exclui uma conexão de consultoria com o controle.|
|[IOleObjectImpl::Update](#update)|Atualiza o controle. A implementação de ATL Retorna S_OK.|

## <a name="remarks"></a>Comentários

O [IOleObject](/windows/desktop/api/oleidl/nn-oleidl-ioleobject) interface é a principal interface por meio do qual um contêiner se comunica com um controle. Classe `IOleObjectImpl` fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.

**Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IOleObject`

`IOleObjectImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

##  <a name="advise"></a>  IOleObjectImpl::Advise

Estabelece uma conexão de consultoria com o controle.

```
STDMETHOD(Advise)(
    IAdviseSink* pAdvSink,
    DWORD* pdwConnection);
```

### <a name="remarks"></a>Comentários

Ver [IOleObject::Advise](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-advise) no Windows SDK.

##  <a name="close"></a>  IOleObjectImpl::Close

Altera o estado do controle de execução para carregar.

```
STDMETHOD(Close)(DWORD dwSaveOption);
```

### <a name="remarks"></a>Comentários

Desativa o controle e destrói a janela de controle se ele existir. Se o controle de membro de dados de classe [CComControlBase::m_bRequiresSave](../../atl/reference/ccomcontrolbase-class.md#m_brequiressave) for TRUE e o *dwSaveOption* parâmetro é OLECLOSE_SAVEIFDIRTY ou OLECLOSE_PROMPTSAVE, são as propriedades de controle salvo antes de ser fechado.

Os ponteiros são mantidos nos membros de dados de classe de controle [CComControlBase::m_spInPlaceSite](../../atl/reference/ccomcontrolbase-class.md#m_spinplacesite) e [CComControlBase::m_spAdviseSink](../../atl/reference/ccomcontrolbase-class.md#m_spadvisesink) são lançadas e os membros de dados [CComControlBase:: m_bNegotiatedWnd](../../atl/reference/ccomcontrolbase-class.md#m_bnegotiatedwnd), [CComControlBase::m_bWndless](../../atl/reference/ccomcontrolbase-class.md#m_bwndless), e [CComControlBase::m_bInPlaceSiteEx](../../atl/reference/ccomcontrolbase-class.md#m_binplacesiteex) estiverem definidas como FALSE.

Ver [IOleObject::Close](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close) no Windows SDK.

##  <a name="doverb"></a>  IOleObjectImpl::DoVerb

Informa o controle para executar uma das suas ações enumeradas.

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

Dependendo do valor de `iVerb`, um dos ATL `DoVerb` funções auxiliares é chamado da seguinte maneira:

|*iVerb* Value|Função de auxiliar DoVerb chamada|
|-------------------|-----------------------------------|
|OLEIVERB_DISCARDUNDOSTATE|[DoVerbDiscardUndo](#doverbdiscardundo)|
|OLEIVERB_HIDE|[DoVerbHide](#doverbhide)|
|OLEIVERB_INPLACEACTIVATE|[DoVerbInPlaceActivate](#doverbinplaceactivate)|
|OLEIVERB_OPEN|[DoVerbOpen](#doverbopen)|
|OLEIVERB_PRIMARY|[DoVerbPrimary](#doverbprimary)|
|OLEIVERB_PROPERTIES|[CComControlBase::DoVerbProperties](../../atl/reference/ccomcontrolbase-class.md#doverbproperties)|
|OLEIVERB_SHOW|[DoVerbShow](#doverbshow)|
|OLEIVERB_UIACTIVATE|[DoVerbUIActivate](#doverbuiactivate)|

Ver [IOleObject:: DoVerb](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) no Windows SDK.

##  <a name="doverbdiscardundo"></a>  IOleObjectImpl::DoVerbDiscardUndo

Informa o controle para descartar qualquer estado de desfazer que ele mantém.

```
HRESULT DoVerbDiscardUndo(LPCRECT /* prcPosRect */, HWND /* hwndParent */);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
[in] Ponteiro para o contêiner de retângulo deseja desenhar o controle.

*hwndParent*<br/>
[in] Identificador da janela que contém o controle.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

##  <a name="doverbhide"></a>  IOleObjectImpl::DoVerbHide

Desativa e remove a interface do usuário do controle e oculta o controle.

```
HRESULT DoVerbHide(LPCRECT /* prcPosRect */, HWND /* hwndParent */);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
[in] Ponteiro para o contêiner de retângulo deseja desenhar o controle.

*hwndParent*<br/>
[in] Identificador da janela que contém o controle. Não é usado na implementação do ATL.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

##  <a name="doverbinplaceactivate"></a>  IOleObjectImpl::DoVerbInPlaceActivate

Executa o controle e instala sua janela, mas não instala a interface do usuário do controle.

```
HRESULT DoVerbInPlaceActivate(LPCRECT prcPosRect, HWND /* hwndParent */);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
[in] Ponteiro para o contêiner de retângulo deseja desenhar o controle.

*hwndParent*<br/>
[in] Identificador da janela que contém o controle. Não é usado na implementação do ATL.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Ativa o controle em vigor, chamando [CComControlBase::InPlaceActivate](../../atl/reference/ccomcontrolbase-class.md#inplaceactivate). A menos que o membro de dados da classe de controle `m_bWindowOnly` for TRUE, `DoVerbInPlaceActivate` primeiro tenta ativar o controle como um controle sem janelas (possível somente se o contêiner dá suporte a [IOleInPlaceSiteWindowless](/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)). Se isso falhar, a função tenta ativar o controle com os recursos estendidos (possível somente se o contêiner dá suporte a [IOleInPlaceSiteEx](/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesiteex)). Se isso falhar, a função tenta ativar o controle sem nenhum recurso estendido (possível somente se o contêiner dá suporte a [IOleInPlaceSite](/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)). Se a ativação for bem-sucedida, a função notifica o contêiner de que controle foi ativado.

##  <a name="doverbopen"></a>  IOleObjectImpl::DoVerbOpen

Faz com que o controle a ser editado em aberto em uma janela separada.

```
HRESULT DoVerbOpen(LPCRECT /* prcPosRect */, HWND /* hwndParent */);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
[in] Ponteiro para o contêiner de retângulo deseja desenhar o controle.

*hwndParent*<br/>
[in] Identificador da janela que contém o controle.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

##  <a name="doverbprimary"></a>  IOleObjectImpl::DoVerbPrimary

Define a ação executada quando o usuário clica duas vezes no controle.

```
HRESULT DoVerbPrimary(LPCRECT prcPosRect, HWND hwndParent);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
[in] Ponteiro para o contêiner de retângulo deseja desenhar o controle.

*hwndParent*<br/>
[in] Identificador da janela que contém o controle.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Por padrão, definido para exibir as páginas de propriedades. Você pode substituí-lo em sua classe de controle para invocar um comportamento diferente ao clicar duas vezes; Por exemplo, reproduzir um vídeo ou vá ativo no local.

##  <a name="doverbshow"></a>  IOleObjectImpl::DoVerbShow

Informa o contêiner para tornar o controle visível.

```
HRESULT DoVerbShow(LPCRECT prcPosRect, HWND /* hwndParent */);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
[in] Ponteiro para o contêiner de retângulo deseja desenhar o controle.

*hwndParent*<br/>
[in] Identificador da janela que contém o controle. Não é usado na implementação do ATL.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="doverbuiactivate"></a>  IOleObjectImpl::DoVerbUIActivate

Ativa a interface do usuário do controle e notifica o contêiner que seus menus estão sendo substituídos pelos menus de composição.

```
HRESULT DoVerbUIActivate(LPCRECT prcPosRect, HWND /* hwndParent */);
```

### <a name="parameters"></a>Parâmetros

*prcPosRec*<br/>
[in] Ponteiro para o contêiner de retângulo deseja desenhar o controle.

*hwndParent*<br/>
[in] Identificador da janela que contém o controle. Não é usado na implementação do ATL.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="enumadvise"></a>  IOleObjectImpl::EnumAdvise

Fornece uma enumeração das conexões de consultoria registradas para este controle.

```
STDMETHOD(EnumAdvise)(IEnumSTATDATA** ppenumAdvise);
```

### <a name="remarks"></a>Comentários

Ver [IOleObject::EnumAdvise](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumadvise) no Windows SDK.

##  <a name="enumverbs"></a>  IOleObjectImpl::EnumVerbs

Fornece uma enumeração de ações registradas (verbos) para esse controle chamando `OleRegEnumVerbs`.

```
STDMETHOD(EnumVerbs)(IEnumOLEVERB** ppEnumOleVerb);
```

### <a name="remarks"></a>Comentários

Você pode adicionar verbos para o arquivo do projeto. rgs. Por exemplo, consulte CIRCCTL. RGS na [c](../../overview/visual-cpp-samples.md) exemplo.

Ver [IOleObject:: Enumverbs](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumverbs) no Windows SDK.

##  <a name="getclientsite"></a>  IOleObjectImpl::GetClientSite

Coloca o ponteiro em membro de dados da classe de controle [CComControlBase::m_spClientSite](../../atl/reference/ccomcontrolbase-class.md#m_spclientsite) em *ppClientSite* e incrementa a contagem de referência no ponteiro.

```
STDMETHOD(GetClientSite)(IOleClientSite** ppClientSite);
```

### <a name="remarks"></a>Comentários

Ver [IOleObject::GetClientSite](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getclientsite) no Windows SDK.

##  <a name="getclipboarddata"></a>  IOleObjectImpl::GetClipboardData

Recupera dados da área de transferência.

```
STDMETHOD(GetClipboardData)(
    DWORD /* dwReserved */,
    IDataObject** /* ppDataObject */);
```

### <a name="return-value"></a>Valor de retorno

Returns E_NOTIMPL.

### <a name="remarks"></a>Comentários

Ver [IOleObject::GetClipboardData](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getclipboarddata) no Windows SDK.

##  <a name="getextent"></a>  IOleObjectImpl::GetExtent

Recupera o tamanho de exibição do controle em execução em unidades HIMETRIC (corresponde a 0,01 milímetro por unidade).

```
STDMETHOD(GetExtent)(
    DWORD dwDrawAspect,
    SIZEL* psizel);
```

### <a name="remarks"></a>Comentários

O tamanho é armazenado no membro de dados de classe de controle [CComControlBase::m_sizeExtent](../../atl/reference/ccomcontrolbase-class.md#m_sizeextent).

Ver [IOleObject::GetExtent](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getextent) no Windows SDK.

##  <a name="getmiscstatus"></a>  IOleObjectImpl::GetMiscStatus

Retorna um ponteiro para informações de status registrado para o controle chamando `OleRegGetMiscStatus`.

```
STDMETHOD(GetMiscStatus)(
    DWORD dwAspect,
    DWORD* pdwStatus);
```

### <a name="remarks"></a>Comentários

As informações de status incluem comportamentos de suporte de controle e a apresentação de dados. Você pode adicionar informações de status para o arquivo do projeto. rgs.

Ver [IOleObject::GetMiscStatus](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmiscstatus) no Windows SDK.

##  <a name="getmoniker"></a>  IOleObjectImpl::GetMoniker

Recupera o identificador de origem do controle.

```
STDMETHOD(GetMoniker)(
    DWORD /* dwAssign */,
    DWORD /* dwWhichMoniker */,
    IMoniker** /* ppmk */);
```

### <a name="return-value"></a>Valor de retorno

Returns E_NOTIMPL.

### <a name="remarks"></a>Comentários

Ver [IOleObject::GetMoniker](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmoniker) no Windows SDK.

##  <a name="getuserclassid"></a>  IOleObjectImpl::GetUserClassID

Retorna o identificador de classe do controle.

```
STDMETHOD(GetUserClassID)(CLSID* pClsid);
```

### <a name="remarks"></a>Comentários

Ver [IOleObject::GetUserClassID](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getuserclassid) no Windows SDK.

##  <a name="getusertype"></a>  IOleObjectImpl::GetUserType

Retorna o nome do tipo de usuário do controle chamando `OleRegGetUserType`.

```
STDMETHOD(GetUserType)(
    DWORD dwFormOfType,
    LPOLESTR* pszUserType);
```

### <a name="remarks"></a>Comentários

O nome do tipo de usuário é usado para exibição em elementos de interfaces do usuário, como menus e caixas de diálogo. Você pode alterar o nome do tipo de usuário no arquivo. rgs do seu projeto.

Ver [IOleObject::GetUserType](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getusertype) no Windows SDK.

##  <a name="initfromdata"></a>  IOleObjectImpl::InitFromData

Inicializa o controle de dados selecionada.

```
STDMETHOD(InitFromData)(
    IDataObject* /* pDataObject */,
    BOOL /* fCreation */,
    DWORD /* dwReserved */);
```

### <a name="return-value"></a>Valor de retorno

Returns E_NOTIMPL.

### <a name="remarks"></a>Comentários

Ver [IOleObject::InitFromData](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-initfromdata) no Windows SDK.

##  <a name="isuptodate"></a>  IOleObjectImpl::IsUpToDate

Verifica se o controle está atualizado.

```
STDMETHOD(IsUpToDate)(void);
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Ver [IOleObject::IsUpToDate](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-isuptodate) no Windows SDK.

##  <a name="onpostverbdiscardundo"></a>  IOleObjectImpl::OnPostVerbDiscardUndo

Chamado pelo [DoVerbDiscardUndo](#doverbdiscardundo) depois que o estado de desfazer é descartado.

```
HRESULT OnPostVerbDiscardUndo();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método com o código a que ser executado depois que o estado de desfazer é descartado.

##  <a name="onpostverbhide"></a>  IOleObjectImpl::OnPostVerbHide

Chamado pelo [DoVerbHide](#doverbhide) depois que o controle está oculto.

```
HRESULT OnPostVerbHide();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método com o código a que ser executado depois que o controle está oculto.

##  <a name="onpostverbinplaceactivate"></a>  IOleObjectImpl::OnPostVerbInPlaceActivate

Chamado pelo [DoVerbInPlaceActivate](#doverbinplaceactivate) depois que o controle é ativado em vigor.

```
HRESULT OnPostVerbInPlaceActivate();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método com o código a que ser executado depois que o controle é ativado em vigor.

##  <a name="onpostverbopen"></a>  IOleObjectImpl::OnPostVerbOpen

Chamado pelo [DoVerbOpen](#doverbopen) depois que o controle foi aberto para edição em uma janela separada.

```
HRESULT OnPostVerbOpen();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método com o código a que ser executado depois que o controle foi aberto para edição em uma janela separada.

##  <a name="onpostverbshow"></a>  IOleObjectImpl::OnPostVerbShow

Chamado pelo [DoVerbShow](#doverbshow) depois que o controle foi feito visível.

```
HRESULT OnPostVerbShow();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método com o código a que ser executado depois que o controle foi feito visível.

##  <a name="onpostverbuiactivate"></a>  IOleObjectImpl::OnPostVerbUIActivate

Chamado pelo [DoVerbUIActivate](#doverbuiactivate) após a ativação de interface do usuário do controle.

```
HRESULT OnPostVerbUIActivate();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método com o código a que ser executado após a ativação de interface do usuário do controle.

##  <a name="onpreverbdiscardundo"></a>  IOleObjectImpl::OnPreVerbDiscardUndo

Chamado pelo [DoVerbDiscardUndo](#doverbdiscardundo) antes de desfazer o estado será descartado.

```
HRESULT OnPreVerbDiscardUndo();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para impedir que o estado de desfazer que está sendo descartado, substitua este método para retornar um erro HRESULT.

##  <a name="onpreverbhide"></a>  IOleObjectImpl::OnPreVerbHide

Chamado pelo [DoVerbHide](#doverbhide) antes que o controle está oculto.

```
HRESULT OnPreVerbHide();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para impedir que o controle que está sendo ocultada, substitua este método para retornar um erro HRESULT.

##  <a name="onpreverbinplaceactivate"></a>  IOleObjectImpl::OnPreVerbInPlaceActivate

Chamado pelo [DoVerbInPlaceActivate](#doverbinplaceactivate) antes do controle é ativado em vigor.

```
HRESULT OnPreVerbInPlaceActivate();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para impedir que o controle que está sendo ativado no local, substitua este método para retornar um erro HRESULT.

##  <a name="onpreverbopen"></a>  IOleObjectImpl::OnPreVerbOpen

Chamado pelo [DoVerbOpen](#doverbopen) antes do controle foi aberto para edição em uma janela separada.

```
HRESULT OnPreVerbOpen();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para impedir que o controle que está sendo aberto para edição em uma janela separada, substitua este método para retornar um erro HRESULT.

##  <a name="onpreverbshow"></a>  IOleObjectImpl::OnPreVerbShow

Chamado pelo [DoVerbShow](#doverbshow) antes do controle foi feito visível.

```
HRESULT OnPreVerbShow();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para impedir que o controle que está sendo feita visível, substitua este método para retornar um erro HRESULT.

##  <a name="onpreverbuiactivate"></a>  IOleObjectImpl::OnPreVerbUIActivate

Chamado pelo [DoVerbUIActivate](#doverbuiactivate) antes de interface do usuário do controle foi ativado.

```
HRESULT OnPreVerbUIActivate();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para impedir que a interface do usuário do controle que está sendo ativado, substitua este método para retornar um erro HRESULT.

##  <a name="setclientsite"></a>  IOleObjectImpl::SetClientSite

Informa o controle sobre seu site de cliente no contêiner.

```
STDMETHOD(SetClientSite)(IOleClientSite* pClientSite);
```

### <a name="remarks"></a>Comentários

O método, em seguida, Retorna S_OK.

Ver [IOleObject::SetClientSite](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setclientsite) no Windows SDK.

##  <a name="setcolorscheme"></a>  IOleObjectImpl::SetColorScheme

Recomenda um esquema de cores para o aplicativo do controle, se houver.

```
STDMETHOD(SetColorScheme)(LOGPALETTE* /* pLogPal */);
```

### <a name="return-value"></a>Valor de retorno

Returns E_NOTIMPL.

### <a name="remarks"></a>Comentários

Ver [IOleObject::SetColorScheme](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setcolorscheme) no Windows SDK.

##  <a name="setextent"></a>  IOleObjectImpl::SetExtent

Define a extensão da área de exibição do controle.

```
STDMETHOD(SetExtent)(
    DWORD dwDrawAspect,
    SIZEL* psizel);
```

### <a name="remarks"></a>Comentários

Caso contrário, `SetExtent` armazena o valor apontado por `psizel` no membro de dados de classe de controle [CComControlBase::m_sizeExtent](../../atl/reference/ccomcontrolbase-class.md#m_sizeextent). Esse valor é em unidades HIMETRIC (corresponde a 0,01 milímetro por unidade).

Se o controle de membro de dados de classe [CComControlBase::m_bResizeNatural](../../atl/reference/ccomcontrolbase-class.md#m_bresizenatural) for TRUE, `SetExtent` também armazena o valor apontado pela `psizel` no membro de dados de classe de controle [CComControlBase::m_sizeNatural ](../../atl/reference/ccomcontrolbase-class.md#m_sizenatural).

Se o controle de membro de dados de classe [CComControlBase::m_bRecomposeOnResize](../../atl/reference/ccomcontrolbase-class.md#m_brecomposeonresize) for TRUE, `SetExtent` chamadas `SendOnDataChange` e `SendOnViewChange` para notificar o comunicado de todos os coletores registrados com o detentor da advise que tem o tamanho do controle alterado.

Ver [IOleObject::SetExtent](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setextent) no Windows SDK.

##  <a name="sethostnames"></a>  IOleObjectImpl::SetHostNames

Informa o controle os nomes do aplicativo de contêiner e do documento contêiner.

```
STDMETHOD(SetHostNames)(LPCOLESTR /* szContainerApp */, LPCOLESTR /* szContainerObj */);
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Ver [IOleObject::SetHostNames](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-sethostnames) no Windows SDK.

##  <a name="setmoniker"></a>  IOleObjectImpl::SetMoniker

Informa ao controle qual é seu identificador de origem.

```
STDMETHOD(SetMoniker)(
    DWORD /* dwWhichMoniker */,
    IMoniker** /* pmk */);
```

### <a name="return-value"></a>Valor de retorno

Returns E_NOTIMPL.

### <a name="remarks"></a>Comentários

Ver [IOleObject::SetMoniker](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setmoniker) no Windows SDK.

##  <a name="unadvise"></a>  IOleObjectImpl::Unadvise

Exclui a conexão de consultoria armazenado na classe de controle `m_spOleAdviseHolder` membro de dados.

```
STDMETHOD(Unadvise)(DWORD dwConnection);
```

### <a name="remarks"></a>Comentários

Ver [IOleObject::Unadvise](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-unadvise) no Windows SDK.

##  <a name="update"></a>  IOleObjectImpl::Update

Atualiza o controle.

```
STDMETHOD(Update)(void);
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Ver [IOleObject::Update](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-update) no Windows SDK.

## <a name="see-also"></a>Consulte também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Interfaces de controles ActiveX](/windows/desktop/com/activex-controls-interfaces)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
