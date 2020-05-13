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
ms.openlocfilehash: 154bfb5beb258ff26649f44f0bd4c23fb8708977
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81745868"
---
# <a name="ipropertypageimpl-class"></a>Classe IPropertyPageImpl

Essa classe `IUnknown` implementa e fornece uma implementação padrão da interface [IPropertyPage.](/windows/win32/api/ocidl/nn-ocidl-ipropertypage)

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

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
|[IPropertyPageImpl::Ativar](#activate)|Cria a janela caixa de diálogo para a página de propriedade.|
|[IPropertyPageImpl::Aplicar](#apply)|Aplica valores atuais da página de `SetObjects`propriedade aos objetos subjacentes especificados através de . A implementação da ATL retorna S_OK.|
|[IPropertyPageImpl::Deactivate](#deactivate)|Destrói a janela criada `Activate`com .|
|[IPropertyPageImpl::GetPageInfo](#getpageinfo)|Recupera informações sobre a página da propriedade.|
|[IPropertyPageImpl::Ajuda](#help)|Invoca ajuda do Windows para a página de propriedade.|
|[IPropertyPageImpl::IsPageDirty](#ispagedirty)|Indica se a página de propriedade mudou desde que foi ativada.|
|[IPropertyPageImpl::Move](#move)|Posiciona e redimensiona a caixa de diálogo da página de propriedade.|
|[IPropertyPageImpl::SetDirty](#setdirty)|Sinaliza o estado da página de propriedade como alterado ou inalterado.|
|[IPropertyPageImpl::SetObjects](#setobjects)|Fornece uma `IUnknown` matriz de ponteiros para os objetos associados à página de propriedade. Esses objetos recebem os valores `Apply`atuais da página de propriedade através de uma chamada para .|
|[IPropertyPageImpl::SetPageSite](#setpagesite)|Fornece a página `IPropertyPageSite` da propriedade com um ponteiro, através do qual a página da propriedade se comunica com o quadro da propriedade.|
|[IPropertyPageImpl::Mostrar](#show)|Torna a caixa de diálogo da página de propriedade visível ou invisível.|
|[IPropertyPageImpl::TranslateAccelerator](#translateaccelerator)|Processa uma tecla especificada.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[IPropertyPageImpl::m_bDirty](#m_bdirty)|Especifica se o estado da página de propriedade foi alterado.|
|[IPropertyPageImpl::m_dwDocString](#m_dwdocstring)|Armazena o identificador de recursos associado à seqüência de texto que descreve a página de propriedade.|
|[IPropertyPageImpl::m_dwHelpContext](#m_dwhelpcontext)|Armazena o identificador de contexto para o tópico de ajuda associado à página de propriedade.|
|[IPropertyPageImpl::m_dwHelpFile](#m_dwhelpfile)|Armazena o identificador de recursos associado ao nome do arquivo de ajuda descrevendo a página da propriedade.|
|[IPropertyPageImpl::m_dwTitle](#m_dwtitle)|Armazena o identificador de recursos associado à seqüência de texto que aparece na guia para a página de propriedade.|
|[IPropertyPageImpl::m_nObjects](#m_nobjects)|Armazena o número de objetos associados à página da propriedade.|
|[IPropertyPageImpl::m_pPageSite](#m_ppagesite)|Aponta para `IPropertyPageSite` a interface através da qual a página de propriedade se comunica com o quadro da propriedade.|
|[IPropertyPageImpl::m_ppUnk](#m_ppunk)|Aponta para uma `IUnknown` matriz de ponteiros para os objetos associados à página de propriedade.|
|[IPropertyPageImpl::m_size](#m_size)|Armazena a altura e a largura da caixa de diálogo da página da propriedade, em pixels.|

## <a name="remarks"></a>Comentários

A interface [IPropertyPage](/windows/win32/api/ocidl/nn-ocidl-ipropertypage) permite que um objeto gerencie uma página de propriedade específica dentro de uma planilha de propriedades. A `IPropertyPageImpl` classe fornece uma implementação `IUnknown` padrão dessa interface e implementa enviando informações para o dispositivo de despejo em compilações de depuração.

**Artigos relacionados** [ATL Tutorial](../../atl/active-template-library-atl-tutorial.md), Criando um Projeto [ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPropertyPage`

`IPropertyPageImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="ipropertypageimplactivate"></a><a name="activate"></a>IPropertyPageImpl::Ativar

Cria a janela caixa de diálogo para a página de propriedade.

```
HRESULT Activate(
    HWND hWndParent,
    LPCRECT pRect,
    BOOL bModal);
```

### <a name="remarks"></a>Comentários

Por padrão, a caixa de diálogo é sempre modelada, independentemente do valor do parâmetro *bModal.*

Consulte [IPropertyPage::Ativar](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-activate) no Windows SDK.

## <a name="ipropertypageimplapply"></a><a name="apply"></a>IPropertyPageImpl::Aplicar

Aplica valores atuais da página de `SetObjects`propriedade aos objetos subjacentes especificados através de .

```
HRESULT Apply();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage::Aplicar](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-apply) no Windows SDK.

## <a name="ipropertypageimpldeactivate"></a><a name="deactivate"></a>IPropertyPageImpl::Deactivate

Destrói a janela da caixa de diálogo criada com [o Activate](#activate).

```
HRESULT Deactivate();
```

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage::Deactivate](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-deactivate) no Windows SDK.

## <a name="ipropertypageimplgetpageinfo"></a><a name="getpageinfo"></a>IPropertyPageImpl::GetPageInfo

Preenche a estrutura *pPageInfo* com informações contidas nos membros dos dados.

```
HRESULT GetPageInfo(PROPPAGEINFO* pPageInfo);
```

### <a name="remarks"></a>Comentários

`GetPageInfo`carrega os recursos de string associados [ao m_dwDocString,](#m_dwdocstring) [m_dwHelpFile](#m_dwhelpfile)e [m_dwTitle.](#m_dwtitle)

Consulte [IPropertyPage::GetPageInfo](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-getpageinfo) no Windows SDK.

## <a name="ipropertypageimplhelp"></a><a name="help"></a>IPropertyPageImpl::Ajuda

Invoca ajuda do Windows para a página de propriedade.

```
HRESULT Help(PROPPAGEINFO* pPageInfo);
```

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage::Ajuda](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-help) no Windows SDK.

## <a name="ipropertypageimplipropertypageimpl"></a><a name="ipropertypageimpl"></a>IPropertyPageImpl::IPropertyPageImpl

O construtor.

```
IPropertyPageImpl();
```

### <a name="remarks"></a>Comentários

Inicializa todos os membros de dados.

## <a name="ipropertypageimplispagedirty"></a><a name="ispagedirty"></a>IPropertyPageImpl::IsPageDirty

Indica se a página de propriedade mudou desde que foi ativada.

```
HRESULT IsPageDirty(void);
```

### <a name="remarks"></a>Comentários

`IsPageDirty`retorna S_OK se a página foi alterada desde que foi ativada.

## <a name="ipropertypageimplm_bdirty"></a><a name="m_bdirty"></a>IPropertyPageImpl::m_bDirty

Especifica se o estado da página de propriedade foi alterado.

```
BOOL m_bDirty;
```

## <a name="ipropertypageimplm_nobjects"></a><a name="m_nobjects"></a>IPropertyPageImpl::m_nObjects

Armazena o número de objetos associados à página da propriedade.

```
ULONG m_nObjects;
```

## <a name="ipropertypageimplm_dwhelpcontext"></a><a name="m_dwhelpcontext"></a>IPropertyPageImpl::m_dwHelpContext

Armazena o identificador de contexto para o tópico de ajuda associado à página de propriedade.

```
DWORD m_dwHelpContext;
```

## <a name="ipropertypageimplm_dwdocstring"></a><a name="m_dwdocstring"></a>IPropertyPageImpl::m_dwDocString

Armazena o identificador de recursos associado à seqüência de texto que descreve a página de propriedade.

```
UINT m_dwDocString;
```

## <a name="ipropertypageimplm_dwhelpfile"></a><a name="m_dwhelpfile"></a>IPropertyPageImpl::m_dwHelpFile

Armazena o identificador de recursos associado ao nome do arquivo de ajuda descrevendo a página da propriedade.

```
UINT m_dwHelpFile;
```

## <a name="ipropertypageimplm_dwtitle"></a><a name="m_dwtitle"></a>IPropertyPageImpl::m_dwTitle

Armazena o identificador de recursos associado à seqüência de texto que aparece na guia para a página de propriedade.

```
UINT m_dwTitle;
```

## <a name="ipropertypageimplm_ppagesite"></a><a name="m_ppagesite"></a>IPropertyPageImpl::m_pPageSite

Aponta para a interface [IPropertyPageSite](/windows/win32/api/ocidl/nn-ocidl-ipropertypagesite) através da qual a página de propriedade se comunica com o quadro da propriedade.

```
IPropertyPageSite* m_pPageSite;
```

## <a name="ipropertypageimplm_ppunk"></a><a name="m_ppunk"></a>IPropertyPageImpl::m_ppUnk

Aponta para uma `IUnknown` matriz de ponteiros para os objetos associados à página de propriedade.

```
IUnknown** m_ppUnk;
```

## <a name="ipropertypageimplm_size"></a><a name="m_size"></a>IPropertyPageImpl::m_size

Armazena a altura e a largura da caixa de diálogo da página da propriedade, em pixels.

```
SIZE m_size;
```

## <a name="ipropertypageimplmove"></a><a name="move"></a>IPropertyPageImpl::Move

Posiciona e redimensiona a caixa de diálogo da página de propriedade.

```
HRESULT Move(LPCRECT pRect);
```

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage::Move](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-move) no Windows SDK.

## <a name="ipropertypageimplsetdirty"></a><a name="setdirty"></a>IPropertyPageImpl::SetDirty

Sinaliza o estado da página de propriedade como alterado ou inalterado, dependendo do valor de *bDirty*.

```cpp
void SetDirty(BOOL bDirty);
```

### <a name="parameters"></a>Parâmetros

*Bdirty*<br/>
[em] Se TRUE, o estado da página de propriedade será marcado como alterado. Caso contrário, está marcado como inalterado.

### <a name="remarks"></a>Comentários

Se necessário, `SetDirty` informa o quadro que a página da propriedade foi alterada.

## <a name="ipropertypageimplsetobjects"></a><a name="setobjects"></a>IPropertyPageImpl::SetObjects

Fornece uma `IUnknown` matriz de ponteiros para os objetos associados à página de propriedade.

```
HRESULT SetObjects(ULONG nObjects, IUnknown** ppUnk);
```

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage::SetObjects](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-setobjects) no Windows SDK.

## <a name="ipropertypageimplsetpagesite"></a><a name="setpagesite"></a>IPropertyPageImpl::SetPageSite

Fornece a página da propriedade com um ponteiro [IPropertyPageSite,](/windows/win32/api/ocidl/nn-ocidl-ipropertypagesite) através do qual a página da propriedade se comunica com o quadro da propriedade.

```
HRESULT SetPageSite(IPropertyPageSite* pPageSite);
```

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage::SetPageSite](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-setpagesite) no Windows SDK.

## <a name="ipropertypageimplshow"></a><a name="show"></a>IPropertyPageImpl::Mostrar

Torna a caixa de diálogo da página de propriedade visível ou invisível.

```
HRESULT Show(UINT nCmdShow);
```

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage::Mostrar](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-show) no Windows SDK.

## <a name="ipropertypageimpltranslateaccelerator"></a><a name="translateaccelerator"></a>IPropertyPageImpl::TranslateAccelerator

Processa o tecla `pMsg`digitado especificado em .

```
HRESULT TranslateAccelerator(MSG* pMsg);
```

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage::TranslateAccelerator](/windows/win32/api/ocidl/nf-ocidl-ipropertypage-translateaccelerator) no Windows SDK.

## <a name="see-also"></a>Confira também

[Classe IPropertyPage2Impl](../../atl/reference/ipropertypage2impl-class.md)<br/>
[Classe IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md)<br/>
[ISpecifiePropertyPagesImpl Class](../../atl/reference/ispecifypropertypagesimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
