---
title: Classe IPropertyPageImpl
ms.date: 11/04/2016
f1_keywords:
- IPropertyPageImpl
- ATLCTL/ATL::IPropertyPageImpl
- ATLCTL/ATL::IPropertyPageImpl::IPropertyPageImpl
- ATLCTL/ATL::IPropertyPageImpl::Activate
- ATLCTL/ATL::IPropertyPageImpl::Apply
- ATLCTL/ATL::IPropertyPageImpl::Deactivate
- ATLCTL/ATL::IPropertyPageImpl::GetPageInfo
- ATLCTL/ATL::IPropertyPageImpl::Help
- ATLCTL/ATL::IPropertyPageImpl::IsPageDirty
- ATLCTL/ATL::IPropertyPageImpl::Move
- ATLCTL/ATL::IPropertyPageImpl::SetDirty
- ATLCTL/ATL::IPropertyPageImpl::SetObjects
- ATLCTL/ATL::IPropertyPageImpl::SetPageSite
- ATLCTL/ATL::IPropertyPageImpl::Show
- ATLCTL/ATL::IPropertyPageImpl::TranslateAccelerator
- ATLCTL/ATL::IPropertyPageImpl::m_bDirty
- ATLCTL/ATL::IPropertyPageImpl::m_dwDocString
- ATLCTL/ATL::IPropertyPageImpl::m_dwHelpContext
- ATLCTL/ATL::IPropertyPageImpl::m_dwHelpFile
- ATLCTL/ATL::IPropertyPageImpl::m_dwTitle
- ATLCTL/ATL::IPropertyPageImpl::m_nObjects
- ATLCTL/ATL::IPropertyPageImpl::m_pPageSite
- ATLCTL/ATL::IPropertyPageImpl::m_ppUnk
- ATLCTL/ATL::IPropertyPageImpl::m_size
helpviewer_keywords:
- property pages
- IPropertyPage ATL implementation
- IPropertyPageImpl class
ms.assetid: f9b7c8b1-7a04-4eab-aa63-63efddb740fa
ms.openlocfilehash: 69842e77aecaa94be66432e5fbba437a6fa3c5a4
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495574"
---
# <a name="ipropertypageimpl-class"></a>Classe IPropertyPageImpl

Essa classe implementa `IUnknown` e fornece uma implementação padrão da interface [IPropertyPage](/windows/win32/api/ocidl/nn-ocidl-ipropertypage) .

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class IPropertyPageImpl
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IPropertyPageImpl`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[IPropertyPageImpl::IPropertyPageImpl](#ipropertypageimpl)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IPropertyPageImpl::Activate](#activate)|Cria a janela da caixa de diálogo da página de propriedades.|
|[IPropertyPageImpl::Apply](#apply)|Aplica valores da página de propriedades atual aos objetos subjacentes `SetObjects`especificados por meio de. A implementação da ATL retorna S_OK.|
|[IPropertyPageImpl::Deactivate](#deactivate)|Destrói a janela criada com `Activate`.|
|[IPropertyPageImpl::GetPageInfo](#getpageinfo)|Recupera informações sobre a página de propriedades.|
|[IPropertyPageImpl::Help](#help)|Chama a ajuda do Windows para a página de propriedades.|
|[IPropertyPageImpl::IsPageDirty](#ispagedirty)|Indica se a página de propriedades foi alterada desde que foi ativada.|
|[IPropertyPageImpl::Move](#move)|Posiciona e redimensiona a caixa de diálogo página de propriedades.|
|[IPropertyPageImpl::SetDirty](#setdirty)|Sinaliza o estado da página de propriedades como alterado ou inalterado.|
|[IPropertyPageImpl::SetObjects](#setobjects)|Fornece uma matriz de `IUnknown` ponteiros para os objetos associados à página de propriedades. Esses objetos recebem os valores da página de propriedades atual por meio `Apply`de uma chamada para.|
|[IPropertyPageImpl::SetPageSite](#setpagesite)|Fornece a página de propriedades com `IPropertyPageSite` um ponteiro, por meio do qual a página de propriedades se comunica com o quadro de propriedades.|
|[IPropertyPageImpl::Show](#show)|Torna a caixa de diálogo página de propriedades visível ou invisível.|
|[IPropertyPageImpl::TranslateAccelerator](#translateaccelerator)|Processa um pressionamento de tecla especificado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[IPropertyPageImpl::m_bDirty](#m_bdirty)|Especifica se o estado da página de propriedades foi alterado.|
|[IPropertyPageImpl::m_dwDocString](#m_dwdocstring)|Armazena o identificador de recurso associado à cadeia de texto que descreve a página de propriedades.|
|[IPropertyPageImpl::m_dwHelpContext](#m_dwhelpcontext)|Armazena o identificador de contexto do tópico da ajuda associado à página de propriedades.|
|[IPropertyPageImpl::m_dwHelpFile](#m_dwhelpfile)|Armazena o identificador de recurso associado ao nome do arquivo de ajuda que descreve a página de propriedades.|
|[IPropertyPageImpl::m_dwTitle](#m_dwtitle)|Armazena o identificador de recurso associado à cadeia de texto que aparece na guia da página de propriedades.|
|[IPropertyPageImpl::m_nObjects](#m_nobjects)|Armazena o número de objetos associados à página de propriedades.|
|[IPropertyPageImpl::m_pPageSite](#m_ppagesite)|Aponta para a `IPropertyPageSite` interface por meio da qual a página de propriedades se comunica com o quadro de propriedade.|
|[IPropertyPageImpl::m_ppUnk](#m_ppunk)|Aponta para uma matriz de `IUnknown` ponteiros para os objetos associados à página de propriedades.|
|[IPropertyPageImpl::m_size](#m_size)|Armazena a altura e a largura da caixa de diálogo da página de propriedades, em pixels.|

## <a name="remarks"></a>Comentários

A interface [IPropertyPage](/windows/win32/api/ocidl/nn-ocidl-ipropertypage) permite que um objeto gerencie uma página de propriedades específica dentro de uma folha de propriedades. Fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração. `IPropertyPageImpl`

**Artigos relacionados** [Tutorial do ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPropertyPage`

`IPropertyPageImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl. h

##  <a name="activate"></a>  IPropertyPageImpl::Activate

Cria a janela da caixa de diálogo da página de propriedades.

```
HRESULT Activate(
    HWND hWndParent,
    LPCRECT pRect,
    BOOL bModal);
```

### <a name="remarks"></a>Comentários

Por padrão, a caixa de diálogo sempre é sem janela restrita, independentemente do valor do parâmetro *bModal* .

Consulte [IPropertyPage:: Activate](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-activate) no SDK do Windows.

##  <a name="apply"></a>IPropertyPageImpl:: aplicar

Aplica valores da página de propriedades atual aos objetos subjacentes `SetObjects`especificados por meio de.

```
HRESULT Apply();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage:: apply](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-apply) no SDK do Windows.

##  <a name="deactivate"></a>  IPropertyPageImpl::Deactivate

Destrói a janela da caixa de diálogo criada com [Activate](#activate).

```
HRESULT Deactivate();
```

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage::D eactivate](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-deactivate) no SDK do Windows.

##  <a name="getpageinfo"></a>IPropertyPageImpl::GetPageInfo

Preenche a estrutura *pPageInfo* com informações contidas nos membros de dados.

```
HRESULT GetPageInfo(PROPPAGEINFO* pPageInfo);
```

### <a name="remarks"></a>Comentários

`GetPageInfo`carrega os recursos de cadeia de caracteres associados a [m_dwDocString](#m_dwdocstring), [m_dwHelpFile](#m_dwhelpfile)e [m_dwTitle](#m_dwtitle).

Consulte [IPropertyPage:: GetPageInfo](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-getpageinfo) na SDK do Windows.

##  <a name="help"></a>IPropertyPageImpl:: ajuda

Chama a ajuda do Windows para a página de propriedades.

```
HRESULT Help(PROPPAGEINFO* pPageInfo);
```

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage:: help](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-help) na SDK do Windows.

##  <a name="ipropertypageimpl"></a>IPropertyPageImpl::IPropertyPageImpl

O construtor.

```
IPropertyPageImpl();
```

### <a name="remarks"></a>Comentários

Inicializa todos os membros de dados.

##  <a name="ispagedirty"></a>IPropertyPageImpl::IsPageDirty

Indica se a página de propriedades foi alterada desde que foi ativada.

```
HRESULT IsPageDirty(void);
```

### <a name="remarks"></a>Comentários

`IsPageDirty`retornará S_OK se a página tiver sido alterada desde que foi ativada.

##  <a name="m_bdirty"></a>  IPropertyPageImpl::m_bDirty

Especifica se o estado da página de propriedades foi alterado.

```
BOOL m_bDirty;
```

##  <a name="m_nobjects"></a>  IPropertyPageImpl::m_nObjects

Armazena o número de objetos associados à página de propriedades.

```
ULONG m_nObjects;
```

##  <a name="m_dwhelpcontext"></a>  IPropertyPageImpl::m_dwHelpContext

Armazena o identificador de contexto do tópico da ajuda associado à página de propriedades.

```
DWORD m_dwHelpContext;
```

##  <a name="m_dwdocstring"></a>  IPropertyPageImpl::m_dwDocString

Armazena o identificador de recurso associado à cadeia de texto que descreve a página de propriedades.

```
UINT m_dwDocString;
```

##  <a name="m_dwhelpfile"></a>  IPropertyPageImpl::m_dwHelpFile

Armazena o identificador de recurso associado ao nome do arquivo de ajuda que descreve a página de propriedades.

```
UINT m_dwHelpFile;
```

##  <a name="m_dwtitle"></a>  IPropertyPageImpl::m_dwTitle

Armazena o identificador de recurso associado à cadeia de texto que aparece na guia da página de propriedades.

```
UINT m_dwTitle;
```

##  <a name="m_ppagesite"></a>  IPropertyPageImpl::m_pPageSite

Aponta para a interface [IPropertyPageSite](/windows/win32/api/ocidl/nn-ocidl-ipropertypagesite) por meio da qual a página de propriedades se comunica com o quadro de propriedades.

```
IPropertyPageSite* m_pPageSite;
```

##  <a name="m_ppunk"></a>  IPropertyPageImpl::m_ppUnk

Aponta para uma matriz de `IUnknown` ponteiros para os objetos associados à página de propriedades.

```
IUnknown** m_ppUnk;
```

##  <a name="m_size"></a>  IPropertyPageImpl::m_size

Armazena a altura e a largura da caixa de diálogo da página de propriedades, em pixels.

```
SIZE m_size;
```

##  <a name="move"></a>  IPropertyPageImpl::Move

Posiciona e redimensiona a caixa de diálogo página de propriedades.

```
HRESULT Move(LPCRECT pRect);
```

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage:: move](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-move) no SDK do Windows.

##  <a name="setdirty"></a>  IPropertyPageImpl::SetDirty

Sinaliza o estado da página de propriedades como alterado ou inalterado, dependendo do valor de *bDirty*.

```
void SetDirty(BOOL bDirty);
```

### <a name="parameters"></a>Parâmetros

*bDirty*<br/>
no Se for TRUE, o estado da página de propriedades será marcado como alterado. Caso contrário, ele será marcado como inalterado.

### <a name="remarks"></a>Comentários

Se necessário, `SetDirty` informa ao quadro que a página de propriedades foi alterada.

##  <a name="setobjects"></a>  IPropertyPageImpl::SetObjects

Fornece uma matriz de `IUnknown` ponteiros para os objetos associados à página de propriedades.

```
HRESULT SetObjects(ULONG nObjects, IUnknown** ppUnk);
```

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage::](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-setobjects) SetObjects no SDK do Windows.

##  <a name="setpagesite"></a>IPropertyPageImpl::SetPageSite

Fornece a página de propriedades com um ponteiro [IPropertyPageSite](/windows/win32/api/ocidl/nn-ocidl-ipropertypagesite) , por meio do qual a página de propriedades se comunica com o quadro de propriedades.

```
HRESULT SetPageSite(IPropertyPageSite* pPageSite);
```

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage:: SetPageSite](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-setpagesite) na SDK do Windows.

##  <a name="show"></a>  IPropertyPageImpl::Show

Torna a caixa de diálogo página de propriedades visível ou invisível.

```
HRESULT Show(UINT nCmdShow);
```

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage:: show](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-show) na SDK do Windows.

##  <a name="translateaccelerator"></a>  IPropertyPageImpl::TranslateAccelerator

Processa a tecla de pressionamento especificada em `pMsg`.

```
HRESULT TranslateAccelerator(MSG* pMsg);
```

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage:: TranslateAccelerator](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-translateaccelerator) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe IPropertyPage2Impl](../../atl/reference/ipropertypage2impl-class.md)<br/>
[Classe IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md)<br/>
[Classe ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
