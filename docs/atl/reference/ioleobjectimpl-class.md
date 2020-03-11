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
ms.openlocfilehash: ded158b0ec862de5b0d0b23dd4b9edb50ad577ef
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78863338"
---
# <a name="ioleobjectimpl-class"></a>Classe IOleObjectImpl

Essa classe implementa `IUnknown` e é a interface principal por meio da qual um contêiner se comunica com um controle.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class ATL_NO_VTABLE IOleObjectImpl : public IOleObject
```

#### <a name="parameters"></a>parâmetros

*T*<br/>
Sua classe, derivada de `IOleObjectImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[IOleObjectImpl:: Advise](#advise)|Estabelece uma conexão de consultoria com o controle.|
|[IOleObjectImpl:: fechar](#close)|Altera o estado do controle de sendo executado para carregado.|
|[IOleObjectImpl::D oVerb](#doverb)|Informa o controle para executar uma de suas ações enumeradas.|
|[IOleObjectImpl::D oVerbDiscardUndo](#doverbdiscardundo)|Informa o controle para descartar qualquer estado de desfazer que esteja mantendo.|
|[IOleObjectImpl::D oVerbHide](#doverbhide)|Informa o controle para remover a interface do usuário da exibição.|
|[IOleObjectImpl::D oVerbInPlaceActivate](#doverbinplaceactivate)|Executa o controle e instala sua janela, mas não instala a interface do usuário do controle.|
|[IOleObjectImpl::D overbabrir](#doverbopen)|Faz com que o controle seja aberto-editado em uma janela separada.|
|[IOleObjectImpl::D oVerbPrimary](#doverbprimary)|Executa a ação especificada quando o usuário clica duas vezes no controle. O controle define a ação, geralmente para ativar o controle in-loco.|
|[IOleObjectImpl::D oVerbShow](#doverbshow)|Mostra um controle recém-inserido para o usuário.|
|[IOleObjectImpl::D oVerbUIActivate](#doverbuiactivate)|Ativa o controle in-loco e mostra a interface do usuário do controle, como menus e barras de ferramentas.|
|[IOleObjectImpl::EnumAdvise](#enumadvise)|Enumera as conexões de consultoria do controle.|
|[IOleObjectImpl::EnumVerbs](#enumverbs)|Enumera ações para o controle.|
|[IOleObjectImpl::GetClientSite](#getclientsite)|Recupera o site do cliente do controle.|
|[IOleObjectImpl::GetClipboardData](#getclipboarddata)|Recupera dados da área de transferência. A implementação da ATL retorna E_NOTIMPL.|
|[IOleObjectImpl:: getextensão](#getextent)|Recupera a extensão da área de exibição do controle.|
|[IOleObjectImpl::GetMiscStatus](#getmiscstatus)|Recupera o status do controle.|
|[IOleObjectImpl:: GetMoniker](#getmoniker)|Recupera o moniker do controle. A implementação da ATL retorna E_NOTIMPL.|
|[IOleObjectImpl::GetUserClassID](#getuserclassid)|Recupera o identificador de classe do controle.|
|[IOleObjectImpl:: GetUserType](#getusertype)|Recupera o nome do tipo de usuário do controle.|
|[IOleObjectImpl::InitFromData](#initfromdata)|Inicializa o controle dos dados selecionados. A implementação da ATL retorna E_NOTIMPL.|
|[IOleObjectImpl::IsUpToDate](#isuptodate)|Verifica se o controle está atualizado. A implementação da ATL retorna S_OK.|
|[IOleObjectImpl::OnPostVerbDiscardUndo](#onpostverbdiscardundo)|Chamado por [DoVerbDiscardUndo](#doverbdiscardundo) após o estado de desfazer ser Descartado.|
|[IOleObjectImpl::OnPostVerbHide](#onpostverbhide)|Chamado por [DoVerbHide](#doverbhide) depois que o controle é ocultado.|
|[IOleObjectImpl::OnPostVerbInPlaceActivate](#onpostverbinplaceactivate)|Chamado por [DoVerbInPlaceActivate](#doverbinplaceactivate) depois que o controle é ativado no local.|
|[IOleObjectImpl::OnPostVerbOpen](#onpostverbopen)|Chamado por [DoVerbOpen](#doverbopen) depois que o controle foi aberto para edição em uma janela separada.|
|[IOleObjectImpl::OnPostVerbShow](#onpostverbshow)|Chamado por [DoVerbShow](#doverbshow) depois que o controle fica visível.|
|[IOleObjectImpl::OnPostVerbUIActivate](#onpostverbuiactivate)|Chamado por [DoVerbUIActivate](#doverbuiactivate) depois que a interface do usuário do controle foi ativada.|
|[IOleObjectImpl::OnPreVerbDiscardUndo](#onpreverbdiscardundo)|Chamado por [DoVerbDiscardUndo](#doverbdiscardundo) antes de o estado de desfazer ser Descartado.|
|[IOleObjectImpl::OnPreVerbHide](#onpreverbhide)|Chamado por [DoVerbHide](#doverbhide) antes de o controle ser ocultado.|
|[IOleObjectImpl::OnPreVerbInPlaceActivate](#onpreverbinplaceactivate)|Chamado por [DoVerbInPlaceActivate](#doverbinplaceactivate) antes de o controle ser ativado no local.|
|[IOleObjectImpl::OnPreVerbOpen](#onpreverbopen)|Chamado por [DoVerbOpen](#doverbopen) antes de o controle ser aberto para edição em uma janela separada.|
|[IOleObjectImpl::OnPreVerbShow](#onpreverbshow)|Chamado por [DoVerbShow](#doverbshow) antes que o controle fique visível.|
|[IOleObjectImpl::OnPreVerbUIActivate](#onpreverbuiactivate)|Chamado por [DoVerbUIActivate](#doverbuiactivate) antes da interface do usuário do controle ser ativada.|
|[IOleObjectImpl::SetClientSite](#setclientsite)|Informa o controle sobre o site do cliente no contêiner.|
|[IOleObjectImpl::SetColorScheme](#setcolorscheme)|Recomenda um esquema de cores para o aplicativo do controle, se houver. A implementação da ATL retorna E_NOTIMPL.|
|[IOleObjectImpl::SetExtent](#setextent)|Define a extensão da área de exibição do controle.|
|[IOleObjectImpl:: SetHostNames](#sethostnames)|Informa ao controle os nomes do aplicativo de contêiner e o documento de contêiner.|
|[IOleObjectImpl:: SetMoniker](#setmoniker)|Informa ao controle qual é seu moniker. A implementação da ATL retorna E_NOTIMPL.|
|[IOleObjectImpl:: Unadvise](#unadvise)|Exclui uma conexão de consultoria com o controle.|
|[IOleObjectImpl:: atualizar](#update)|Atualiza o controle. A implementação da ATL retorna S_OK.|

## <a name="remarks"></a>Comentários

A interface [IOleObject](/windows/win32/api/oleidl/nn-oleidl-ioleobject) é a interface principal por meio da qual um contêiner se comunica com um controle. A classe `IOleObjectImpl` fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração.

**Artigos relacionados** - [tutorial do ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IOleObject`

`IOleObjectImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl. h

##  <a name="advise"></a>IOleObjectImpl:: Advise

Estabelece uma conexão de consultoria com o controle.

```
STDMETHOD(Advise)(
    IAdviseSink* pAdvSink,
    DWORD* pdwConnection);
```

### <a name="remarks"></a>Comentários

Consulte [IOleObject:: Advise](/windows/win32/api/oleidl/nf-oleidl-ioleobject-advise) na SDK do Windows.

##  <a name="close"></a>IOleObjectImpl:: fechar

Altera o estado do controle de sendo executado para carregado.

```
STDMETHOD(Close)(DWORD dwSaveOption);
```

### <a name="remarks"></a>Comentários

Desativa o controle e destrói a janela de controle, se ela existir. Se o membro de dados da classe de controle [CComControlBase:: m_bRequiresSave](../../atl/reference/ccomcontrolbase-class.md#m_brequiressave) for true e o parâmetro *dwSaveOption* for OLECLOSE_SAVEIFDIRTY ou OLECLOSE_PROMPTSAVE, as propriedades de controle serão salvas antes de fechar.

Os ponteiros mantidos nos membros de dados da classe de controle [CComControlBase:: m_spInPlaceSite](../../atl/reference/ccomcontrolbase-class.md#m_spinplacesite) e [CComControlBase:: m_spAdviseSink](../../atl/reference/ccomcontrolbase-class.md#m_spadvisesink) são liberados e os membros de dados [CComControlBase:: m_bNegotiatedWnd](../../atl/reference/ccomcontrolbase-class.md#m_bnegotiatedwnd), [CComControlBase:: m_bWndLess](../../atl/reference/ccomcontrolbase-class.md#m_bwndless)e [CComControlBase:: m_bInPlaceSiteEx](../../atl/reference/ccomcontrolbase-class.md#m_binplacesiteex) são definidos como false.

Consulte [IOleObject:: Close](/windows/win32/api/oleidl/nf-oleidl-ioleobject-close) na SDK do Windows.

##  <a name="doverb"></a>IOleObjectImpl::D oVerb

Informa o controle para executar uma de suas ações enumeradas.

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

Dependendo do valor de `iVerb`, uma das funções auxiliares de `DoVerb` do ATL é chamada da seguinte maneira:

|*iVerb* Valor|Função auxiliar DoVerb chamada|
|-------------------|-----------------------------------|
|OLEIVERB_DISCARDUNDOSTATE|[DoVerbDiscardUndo](#doverbdiscardundo)|
|OLEIVERB_HIDE|[DoVerbHide](#doverbhide)|
|OLEIVERB_INPLACEACTIVATE|[DoVerbInPlaceActivate](#doverbinplaceactivate)|
|OLEIVERB_OPEN|[DoVerbOpen](#doverbopen)|
|OLEIVERB_PRIMARY|[DoVerbPrimary](#doverbprimary)|
|OLEIVERB_PROPERTIES|[CComControlBase::D oVerbProperties](../../atl/reference/ccomcontrolbase-class.md#doverbproperties)|
|OLEIVERB_SHOW|[DoVerbShow](#doverbshow)|
|OLEIVERB_UIACTIVATE|[DoVerbUIActivate](#doverbuiactivate)|

Consulte [IOleObject::D overb](/windows/win32/api/oleidl/nf-oleidl-ioleobject-doverb) no SDK do Windows.

##  <a name="doverbdiscardundo"></a>IOleObjectImpl::D oVerbDiscardUndo

Informa o controle para descartar qualquer estado de desfazer que esteja mantendo.

```
HRESULT DoVerbDiscardUndo(LPCRECT /* prcPosRect */, HWND /* hwndParent */);
```

### <a name="parameters"></a>parâmetros

*prcPosRec*<br/>
no Ponteiro para o retângulo no qual o contêiner deseja que o controle desenhe.

*hwndParent*<br/>
no Identificador da janela que contém o controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

##  <a name="doverbhide"></a>IOleObjectImpl::D oVerbHide

Desativa e remove a interface do usuário do controle e oculta o controle.

```
HRESULT DoVerbHide(LPCRECT /* prcPosRect */, HWND /* hwndParent */);
```

### <a name="parameters"></a>parâmetros

*prcPosRec*<br/>
no Ponteiro para o retângulo no qual o contêiner deseja que o controle desenhe.

*hwndParent*<br/>
no Identificador da janela que contém o controle. Não usado na implementação da ATL.

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

##  <a name="doverbinplaceactivate"></a>IOleObjectImpl::D oVerbInPlaceActivate

Executa o controle e instala sua janela, mas não instala a interface do usuário do controle.

```
HRESULT DoVerbInPlaceActivate(LPCRECT prcPosRect, HWND /* hwndParent */);
```

### <a name="parameters"></a>parâmetros

*prcPosRec*<br/>
no Ponteiro para o retângulo no qual o contêiner deseja que o controle desenhe.

*hwndParent*<br/>
no Identificador da janela que contém o controle. Não usado na implementação da ATL.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Ativa o controle no local chamando [CComControlBase:: InPlaceActivate](../../atl/reference/ccomcontrolbase-class.md#inplaceactivate). A menos que o membro de dados da classe de controle `m_bWindowOnly` seja verdadeiro, `DoVerbInPlaceActivate` primeiro tenta ativar o controle como um controle sem janela (possível somente se o contêiner oferecer suporte a [IOleInPlaceSiteWindowless](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesitewindowless)). Se isso falhar, a função tentará ativar o controle com recursos estendidos (possível somente se o contêiner oferecer suporte a [IOleInPlaceSiteEx](/windows/win32/api/ocidl/nn-ocidl-ioleinplacesiteex)). Se isso falhar, a função tentará ativar o controle sem recursos estendidos (possível somente se o contêiner oferecer suporte a [IOleInPlaceSite](/windows/win32/api/oleidl/nn-oleidl-ioleinplacesite)). Se a ativação for realizada com sucesso, a função notificará o contêiner de que o controle foi ativado.

##  <a name="doverbopen"></a>IOleObjectImpl::D overbabrir

Faz com que o controle seja aberto-editado em uma janela separada.

```
HRESULT DoVerbOpen(LPCRECT /* prcPosRect */, HWND /* hwndParent */);
```

### <a name="parameters"></a>parâmetros

*prcPosRec*<br/>
no Ponteiro para o retângulo no qual o contêiner deseja que o controle desenhe.

*hwndParent*<br/>
no Identificador da janela que contém o controle.

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

##  <a name="doverbprimary"></a>IOleObjectImpl::D oVerbPrimary

Define a ação executada quando o usuário clica duas vezes no controle.

```
HRESULT DoVerbPrimary(LPCRECT prcPosRect, HWND hwndParent);
```

### <a name="parameters"></a>parâmetros

*prcPosRec*<br/>
no Ponteiro para o retângulo no qual o contêiner deseja que o controle desenhe.

*hwndParent*<br/>
no Identificador da janela que contém o controle.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Por padrão, defina para exibir as páginas de propriedades. Você pode substituir isso em sua classe de controle para invocar um comportamento diferente ao clicar duas vezes; por exemplo, reproduza um vídeo ou vá para o local ativo.

##  <a name="doverbshow"></a>IOleObjectImpl::D oVerbShow

Informa ao contêiner para tornar o controle visível.

```
HRESULT DoVerbShow(LPCRECT prcPosRect, HWND /* hwndParent */);
```

### <a name="parameters"></a>parâmetros

*prcPosRec*<br/>
no Ponteiro para o retângulo no qual o contêiner deseja que o controle desenhe.

*hwndParent*<br/>
no Identificador da janela que contém o controle. Não usado na implementação da ATL.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

##  <a name="doverbuiactivate"></a>IOleObjectImpl::D oVerbUIActivate

Ativa a interface do usuário do controle e notifica o contêiner de que seus menus estão sendo substituídos por menus compostos.

```
HRESULT DoVerbUIActivate(LPCRECT prcPosRect, HWND /* hwndParent */);
```

### <a name="parameters"></a>parâmetros

*prcPosRec*<br/>
no Ponteiro para o retângulo no qual o contêiner deseja que o controle desenhe.

*hwndParent*<br/>
no Identificador da janela que contém o controle. Não usado na implementação da ATL.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

##  <a name="enumadvise"></a>IOleObjectImpl::EnumAdvise

Fornece uma enumeração de conexões de consultoria registradas para este controle.

```
STDMETHOD(EnumAdvise)(IEnumSTATDATA** ppenumAdvise);
```

### <a name="remarks"></a>Comentários

Consulte [IOleObject:: EnumAdvise](/windows/win32/api/oleidl/nf-oleidl-ioleobject-enumadvise) na SDK do Windows.

##  <a name="enumverbs"></a>IOleObjectImpl::EnumVerbs

Fornece uma enumeração de ações registradas (verbos) para esse controle chamando `OleRegEnumVerbs`.

```
STDMETHOD(EnumVerbs)(IEnumOLEVERB** ppEnumOleVerb);
```

### <a name="remarks"></a>Comentários

Você pode adicionar verbos ao arquivo. rgs do projeto. Por exemplo, consulte CIRCCTL. RGS no exemplo de [CIRC](../../overview/visual-cpp-samples.md) .

Consulte [IOleObject:: EnumVerbs](/windows/win32/api/oleidl/nf-oleidl-ioleobject-enumverbs) na SDK do Windows.

##  <a name="getclientsite"></a>IOleObjectImpl::GetClientSite

Coloca o ponteiro no membro de dados da classe de controle [CComControlBase:: m_spClientSite](../../atl/reference/ccomcontrolbase-class.md#m_spclientsite) em *ppClientSite* e incrementa a contagem de referência no ponteiro.

```
STDMETHOD(GetClientSite)(IOleClientSite** ppClientSite);
```

### <a name="remarks"></a>Comentários

Consulte [IOleObject:: GetClientSite](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getclientsite) na SDK do Windows.

##  <a name="getclipboarddata"></a>IOleObjectImpl::GetClipboardData

Recupera dados da área de transferência.

```
STDMETHOD(GetClipboardData)(
    DWORD /* dwReserved */,
    IDataObject** /* ppDataObject */);
```

### <a name="return-value"></a>Valor retornado

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IOleObject:: GetClipboardData](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getclipboarddata) na SDK do Windows.

##  <a name="getextent"></a>IOleObjectImpl:: getextensão

Recupera o tamanho de exibição de um controle em execução em unidades HIMETRIC (0, 1 milímetros por unidade).

```
STDMETHOD(GetExtent)(
    DWORD dwDrawAspect,
    SIZEL* psizel);
```

### <a name="remarks"></a>Comentários

O tamanho é armazenado no membro de dados da classe de controle [CComControlBase:: m_sizeExtent](../../atl/reference/ccomcontrolbase-class.md#m_sizeextent).

Consulte [IOleObject:: getextensão](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getextent) no SDK do Windows.

##  <a name="getmiscstatus"></a>IOleObjectImpl::GetMiscStatus

Retorna um ponteiro para informações de status registradas para o controle chamando `OleRegGetMiscStatus`.

```
STDMETHOD(GetMiscStatus)(
    DWORD dwAspect,
    DWORD* pdwStatus);
```

### <a name="remarks"></a>Comentários

As informações de status incluem comportamentos com suporte dos dados de controle e apresentação. Você pode adicionar informações de status ao arquivo. rgs do projeto.

Consulte [IOleObject:: GetMiscStatus](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getmiscstatus) na SDK do Windows.

##  <a name="getmoniker"></a>IOleObjectImpl:: GetMoniker

Recupera o moniker do controle.

```
STDMETHOD(GetMoniker)(
    DWORD /* dwAssign */,
    DWORD /* dwWhichMoniker */,
    IMoniker** /* ppmk */);
```

### <a name="return-value"></a>Valor retornado

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IOleObject:: GetMoniker](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getmoniker) no SDK do Windows.

##  <a name="getuserclassid"></a>IOleObjectImpl::GetUserClassID

Retorna o identificador de classe do controle.

```
STDMETHOD(GetUserClassID)(CLSID* pClsid);
```

### <a name="remarks"></a>Comentários

Consulte [IOleObject:: GetUserClassID](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getuserclassid) na SDK do Windows.

##  <a name="getusertype"></a>IOleObjectImpl:: GetUserType

Retorna o nome do tipo de usuário do controle chamando `OleRegGetUserType`.

```
STDMETHOD(GetUserType)(
    DWORD dwFormOfType,
    LPOLESTR* pszUserType);
```

### <a name="remarks"></a>Comentários

O nome do tipo de usuário é usado para exibição em elementos de interfaces do usuário, como menus e caixas de diálogo. Você pode alterar o nome do tipo de usuário no arquivo. rgs do projeto.

Consulte [IOleObject:: GetUserType](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getusertype) na SDK do Windows.

##  <a name="initfromdata"></a>IOleObjectImpl::InitFromData

Inicializa o controle dos dados selecionados.

```
STDMETHOD(InitFromData)(
    IDataObject* /* pDataObject */,
    BOOL /* fCreation */,
    DWORD /* dwReserved */);
```

### <a name="return-value"></a>Valor retornado

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IOleObject:: InitFromData](/windows/win32/api/oleidl/nf-oleidl-ioleobject-initfromdata) na SDK do Windows.

##  <a name="isuptodate"></a>IOleObjectImpl::IsUpToDate

Verifica se o controle está atualizado.

```
STDMETHOD(IsUpToDate)(void);
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IOleObject:: IsUpToDate](/windows/win32/api/oleidl/nf-oleidl-ioleobject-isuptodate) na SDK do Windows.

##  <a name="onpostverbdiscardundo"></a>IOleObjectImpl::OnPostVerbDiscardUndo

Chamado por [DoVerbDiscardUndo](#doverbdiscardundo) após o estado de desfazer ser Descartado.

```
HRESULT OnPostVerbDiscardUndo();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método pelo código que você deseja executar depois que o estado de desfazer for descartado.

##  <a name="onpostverbhide"></a>IOleObjectImpl::OnPostVerbHide

Chamado por [DoVerbHide](#doverbhide) depois que o controle é ocultado.

```
HRESULT OnPostVerbHide();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método pelo código que você deseja executar depois que o controle estiver oculto.

##  <a name="onpostverbinplaceactivate"></a>IOleObjectImpl::OnPostVerbInPlaceActivate

Chamado por [DoVerbInPlaceActivate](#doverbinplaceactivate) depois que o controle é ativado no local.

```
HRESULT OnPostVerbInPlaceActivate();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método pelo código que você deseja executar depois que o controle for ativado no local.

##  <a name="onpostverbopen"></a>IOleObjectImpl::OnPostVerbOpen

Chamado por [DoVerbOpen](#doverbopen) depois que o controle foi aberto para edição em uma janela separada.

```
HRESULT OnPostVerbOpen();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método pelo código que você deseja executar depois que o controle tiver sido aberto para edição em uma janela separada.

##  <a name="onpostverbshow"></a>IOleObjectImpl::OnPostVerbShow

Chamado por [DoVerbShow](#doverbshow) depois que o controle fica visível.

```
HRESULT OnPostVerbShow();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método pelo código que você deseja executar depois que o controle tiver sido tornado visível.

##  <a name="onpostverbuiactivate"></a>IOleObjectImpl::OnPostVerbUIActivate

Chamado por [DoVerbUIActivate](#doverbuiactivate) depois que a interface do usuário do controle foi ativada.

```
HRESULT OnPostVerbUIActivate();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método pelo código que você deseja executar depois que a interface do usuário do controle tiver sido ativada.

##  <a name="onpreverbdiscardundo"></a>IOleObjectImpl::OnPreVerbDiscardUndo

Chamado por [DoVerbDiscardUndo](#doverbdiscardundo) antes de o estado de desfazer ser Descartado.

```
HRESULT OnPreVerbDiscardUndo();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para impedir que o estado de desfazer seja descartado, substitua esse método para retornar um erro HRESULT.

##  <a name="onpreverbhide"></a>IOleObjectImpl::OnPreVerbHide

Chamado por [DoVerbHide](#doverbhide) antes de o controle ser ocultado.

```
HRESULT OnPreVerbHide();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para impedir que o controle seja ocultado, substitua esse método para retornar um erro HRESULT.

##  <a name="onpreverbinplaceactivate"></a>IOleObjectImpl::OnPreVerbInPlaceActivate

Chamado por [DoVerbInPlaceActivate](#doverbinplaceactivate) antes de o controle ser ativado no local.

```
HRESULT OnPreVerbInPlaceActivate();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para impedir que o controle seja ativado no local, substitua esse método para retornar um erro HRESULT.

##  <a name="onpreverbopen"></a>IOleObjectImpl::OnPreVerbOpen

Chamado por [DoVerbOpen](#doverbopen) antes de o controle ser aberto para edição em uma janela separada.

```
HRESULT OnPreVerbOpen();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para impedir que o controle seja aberto para edição em uma janela separada, substitua esse método para retornar um erro HRESULT.

##  <a name="onpreverbshow"></a>IOleObjectImpl::OnPreVerbShow

Chamado por [DoVerbShow](#doverbshow) antes que o controle fique visível.

```
HRESULT OnPreVerbShow();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para impedir que o controle fique visível, substitua esse método para retornar um erro HRESULT.

##  <a name="onpreverbuiactivate"></a>IOleObjectImpl::OnPreVerbUIActivate

Chamado por [DoVerbUIActivate](#doverbuiactivate) antes da interface do usuário do controle ser ativada.

```
HRESULT OnPreVerbUIActivate();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para impedir que a interface do usuário do controle seja ativada, substitua esse método para retornar um erro HRESULT.

##  <a name="setclientsite"></a>IOleObjectImpl::SetClientSite

Informa o controle sobre o site do cliente no contêiner.

```
STDMETHOD(SetClientSite)(IOleClientSite* pClientSite);
```

### <a name="remarks"></a>Comentários

Em seguida, o método retorna S_OK.

Consulte [IOleObject:: SetClientSite](/windows/win32/api/oleidl/nf-oleidl-ioleobject-setclientsite) na SDK do Windows.

##  <a name="setcolorscheme"></a>IOleObjectImpl::SetColorScheme

Recomenda um esquema de cores para o aplicativo do controle, se houver.

```
STDMETHOD(SetColorScheme)(LOGPALETTE* /* pLogPal */);
```

### <a name="return-value"></a>Valor retornado

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IOleObject:: SetColorScheme](/windows/win32/api/oleidl/nf-oleidl-ioleobject-setcolorscheme) na SDK do Windows.

##  <a name="setextent"></a>IOleObjectImpl::SetExtent

Define a extensão da área de exibição do controle.

```
STDMETHOD(SetExtent)(
    DWORD dwDrawAspect,
    SIZEL* psizel);
```

### <a name="remarks"></a>Comentários

Caso contrário, `SetExtent` armazena o valor apontado por `psizel` no membro de dados da classe de controle [CComControlBase:: m_sizeExtent](../../atl/reference/ccomcontrolbase-class.md#m_sizeextent). Esse valor está em unidades HIMETRIC (0, 1 milímetros por unidade).

Se o membro de dados da classe de controle [CComControlBase:: m_bResizeNatural](../../atl/reference/ccomcontrolbase-class.md#m_bresizenatural) for TRUE, `SetExtent` também armazenará o valor apontado por `psizel` no membro de dados da classe de controle [CComControlBase:: m_sizeNatural](../../atl/reference/ccomcontrolbase-class.md#m_sizenatural).

Se o membro de dados da classe de controle [CComControlBase:: m_bRecomposeOnResize](../../atl/reference/ccomcontrolbase-class.md#m_brecomposeonresize) for TRUE, `SetExtent` chamará `SendOnDataChange` e `SendOnViewChange` para notificar todos os coletores de consultoria registrados com o titular do aviso de que o tamanho do controle foi alterado.

Consulte [IOleObject:: SetExtent](/windows/win32/api/oleidl/nf-oleidl-ioleobject-setextent) na SDK do Windows.

##  <a name="sethostnames"></a>IOleObjectImpl:: SetHostNames

Informa ao controle os nomes do aplicativo de contêiner e o documento de contêiner.

```
STDMETHOD(SetHostNames)(LPCOLESTR /* szContainerApp */, LPCOLESTR /* szContainerObj */);
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IOleObject:: SetHostNames](/windows/win32/api/oleidl/nf-oleidl-ioleobject-sethostnames) na SDK do Windows.

##  <a name="setmoniker"></a>IOleObjectImpl:: SetMoniker

Informa ao controle qual é seu moniker.

```
STDMETHOD(SetMoniker)(
    DWORD /* dwWhichMoniker */,
    IMoniker** /* pmk */);
```

### <a name="return-value"></a>Valor retornado

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IOleObject:: SetMoniker](/windows/win32/api/oleidl/nf-oleidl-ioleobject-setmoniker) na SDK do Windows.

##  <a name="unadvise"></a>IOleObjectImpl:: Unadvise

Exclui a conexão de consultoria armazenada no membro de dados `m_spOleAdviseHolder` da classe de controle.

```
STDMETHOD(Unadvise)(DWORD dwConnection);
```

### <a name="remarks"></a>Comentários

Consulte [IOleObject:: Unadvise](/windows/win32/api/oleidl/nf-oleidl-ioleobject-unadvise) na SDK do Windows.

##  <a name="update"></a>IOleObjectImpl:: atualizar

Atualiza o controle.

```
STDMETHOD(Update)(void);
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IOleObject:: Update](/windows/win32/api/oleidl/nf-oleidl-ioleobject-update) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Interfaces de controles ActiveX](/windows/win32/com/activex-controls-interfaces)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
