---
title: Classe IPropertyPageImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- property pages
- IPropertyPage ATL implementation
- IPropertyPageImpl class
ms.assetid: f9b7c8b1-7a04-4eab-aa63-63efddb740fa
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2b07609b792b7080e2c4c432ed435381007ba286
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46075222"
---
# <a name="ipropertypageimpl-class"></a>Classe IPropertyPageImpl

Essa classe implementa `IUnknown` e fornece uma implementação padrão do [IPropertyPage](/windows/desktop/api/ocidl/nn-ocidl-ipropertypage) interface.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class IPropertyPageImpl
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IPropertyPageImpl`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[IPropertyPageImpl::IPropertyPageImpl](#ipropertypageimpl)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IPropertyPageImpl::Activate](#activate)|Cria a janela da caixa de diálogo da página de propriedades.|
|[IPropertyPageImpl::Apply](#apply)|Aplica-se valores da página de propriedade atuais para os objetos subjacentes especificados por meio de `SetObjects`. A implementação de ATL Retorna S_OK.|
|[IPropertyPageImpl::Deactivate](#deactivate)|Destrói a janela criada com `Activate`.|
|[IPropertyPageImpl::GetPageInfo](#getpageinfo)|Recupera informações sobre a página de propriedades.|
|[IPropertyPageImpl::Help](#help)|Chama a Ajuda do Windows para a página de propriedades.|
|[IPropertyPageImpl::IsPageDirty](#ispagedirty)|Indica se a página de propriedades foi alterado desde que ele foi ativado.|
|[IPropertyPageImpl::Move](#move)|Posiciona e redimensiona a caixa de diálogo de página de propriedades.|
|[IPropertyPageImpl::SetDirty](#setdirty)|Sinalizadores de estado da página de propriedades como alterados ou inalterado.|
|[IPropertyPageImpl::SetObjects](#setobjects)|Fornece uma matriz de `IUnknown` ponteiros para os objetos associados com a página de propriedades. Esses objetos recebem os valores atuais de página de propriedade por meio de uma chamada para `Apply`.|
|[IPropertyPageImpl::SetPageSite](#setpagesite)|Fornece a página de propriedade com um `IPropertyPageSite` ponteiro, por meio do qual a página de propriedades se comunica com o quadro de propriedades.|
|[IPropertyPageImpl::Show](#show)|Faz a caixa de diálogo de página de propriedade visível ou invisível.|
|[IPropertyPageImpl::TranslateAccelerator](#translateaccelerator)|Processa um pressionamento de tecla especificado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[IPropertyPageImpl::m_bDirty](#m_bdirty)|Especifica se o estado da página de propriedade foi alterada.|
|[IPropertyPageImpl::m_dwDocString](#m_dwdocstring)|Armazena o identificador do recurso associado com a cadeia de caracteres de texto que descreve a página de propriedades.|
|[IPropertyPageImpl::m_dwHelpContext](#m_dwhelpcontext)|Armazena o identificador de contexto para o tópico de ajuda associado à página de propriedade.|
|[IPropertyPageImpl::m_dwHelpFile](#m_dwhelpfile)|Armazena o identificador do recurso associado com o nome do arquivo de Ajuda que descreve a página de propriedades.|
|[IPropertyPageImpl::m_dwTitle](#m_dwtitle)|Armazena o identificador do recurso associado com a cadeia de caracteres de texto que aparece na guia da página de propriedades.|
|[IPropertyPageImpl::m_nObjects](#m_nobjects)|Armazena o número de objetos associados com a página de propriedades.|
|[IPropertyPageImpl::m_pPageSite](#m_ppagesite)|Aponta para o `IPropertyPageSite` interface por meio do qual a página de propriedades se comunica com o quadro de propriedades.|
|[IPropertyPageImpl::m_ppUnk](#m_ppunk)|Aponta para uma matriz de `IUnknown` ponteiros para os objetos associados com a página de propriedades.|
|[IPropertyPageImpl::m_size](#m_size)|Armazena a altura e largura da caixa de diálogo da página de propriedades, em pixels.|

## <a name="remarks"></a>Comentários

O [IPropertyPage](/windows/desktop/api/ocidl/nn-ocidl-ipropertypage) interface permite que um objeto gerenciar uma página de propriedade específica dentro de uma folha de propriedades. Classe `IPropertyPageImpl` fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.

**Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPropertyPage`

`IPropertyPageImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

##  <a name="activate"></a>  IPropertyPageImpl::Activate

Cria a janela da caixa de diálogo da página de propriedades.

```
HRESULT Activate(  
    HWND hWndParent,
    LPCRECT pRect,
    BOOL bModal);
```

### <a name="remarks"></a>Comentários

Por padrão, a caixa de diálogo sempre é sem janela restrita, independentemente do valor de *bModal* parâmetro.

Ver [IPropertyPage::Activate](/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-activate) no Windows SDK.

##  <a name="apply"></a>  IPropertyPageImpl::Apply

Aplica-se valores da página de propriedade atuais para os objetos subjacentes especificados por meio de `SetObjects`.

```
HRESULT Apply();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Ver [IPropertyPage::Apply](/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-apply) no Windows SDK.

##  <a name="deactivate"></a>  IPropertyPageImpl::Deactivate

Destrói a janela da caixa de diálogo criada com [ativar](#activate).

```
HRESULT Deactivate();
```

### <a name="remarks"></a>Comentários

Ver [IPropertyPage::Deactivate](/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-deactivate) no Windows SDK.

##  <a name="getpageinfo"></a>  IPropertyPageImpl::GetPageInfo

Preenche o *pPageInfo* estrutura com informações contidas nos membros de dados.

```
HRESULT GetPageInfo(PROPPAGEINFO* pPageInfo);
```

### <a name="remarks"></a>Comentários

`GetPageInfo` carrega os recursos de cadeia de caracteres associados [m_dwDocString](#m_dwdocstring), [m_dwHelpFile](#m_dwhelpfile), e [m_dwTitle](#m_dwtitle).

Ver [IPropertyPage::GetPageInfo](/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-getpageinfo) no Windows SDK.

##  <a name="help"></a>  IPropertyPageImpl::Help

Chama a Ajuda do Windows para a página de propriedades.

```
HRESULT Help(PROPPAGEINFO* pPageInfo);
```

### <a name="remarks"></a>Comentários

Ver [IPropertyPage::Help](/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-help) no Windows SDK.

##  <a name="ipropertypageimpl"></a>  IPropertyPageImpl::IPropertyPageImpl

O construtor.

```
IPropertyPageImpl();
```

### <a name="remarks"></a>Comentários

Inicializa todos os membros de dados.

##  <a name="ispagedirty"></a>  IPropertyPageImpl::IsPageDirty

Indica se a página de propriedades foi alterado desde que ele foi ativado.

```
HRESULT IsPageDirty(void);
```

### <a name="remarks"></a>Comentários

`IsPageDirty` Retorna S_OK se a página foi alterado desde que ele foi ativado.

##  <a name="m_bdirty"></a>  IPropertyPageImpl::m_bDirty

Especifica se o estado da página de propriedade foi alterada.

```
BOOL m_bDirty;
```

##  <a name="m_nobjects"></a>  IPropertyPageImpl::m_nObjects

Armazena o número de objetos associados com a página de propriedades.

```
ULONG m_nObjects;
```

##  <a name="m_dwhelpcontext"></a>  IPropertyPageImpl::m_dwHelpContext

Armazena o identificador de contexto para o tópico de ajuda associado à página de propriedade.

```
DWORD m_dwHelpContext;
```

##  <a name="m_dwdocstring"></a>  IPropertyPageImpl::m_dwDocString

Armazena o identificador do recurso associado com a cadeia de caracteres de texto que descreve a página de propriedades.

```
UINT m_dwDocString;
```

##  <a name="m_dwhelpfile"></a>  IPropertyPageImpl::m_dwHelpFile

Armazena o identificador do recurso associado com o nome do arquivo de Ajuda que descreve a página de propriedades.

```
UINT m_dwHelpFile;
```

##  <a name="m_dwtitle"></a>  IPropertyPageImpl::m_dwTitle

Armazena o identificador do recurso associado com a cadeia de caracteres de texto que aparece na guia da página de propriedades.

```
UINT m_dwTitle;
```

##  <a name="m_ppagesite"></a>  IPropertyPageImpl::m_pPageSite

Aponta para o [IPropertyPageSite](/windows/desktop/api/ocidl/nn-ocidl-ipropertypagesite) interface por meio do qual a página de propriedades se comunica com o quadro de propriedades.

```
IPropertyPageSite* m_pPageSite;
```

##  <a name="m_ppunk"></a>  IPropertyPageImpl::m_ppUnk

Aponta para uma matriz de `IUnknown` ponteiros para os objetos associados com a página de propriedades.

```
IUnknown** m_ppUnk;
```

##  <a name="m_size"></a>  IPropertyPageImpl::m_size

Armazena a altura e largura da caixa de diálogo da página de propriedades, em pixels.

```
SIZE m_size;
```

##  <a name="move"></a>  IPropertyPageImpl::Move

Posiciona e redimensiona a caixa de diálogo de página de propriedades.

```
HRESULT Move(LPCRECT pRect);
```

### <a name="remarks"></a>Comentários

Ver [IPropertyPage::Move](/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-move) no Windows SDK.

##  <a name="setdirty"></a>  IPropertyPageImpl::SetDirty

Sinalizadores de estado da página de propriedades como alterados ou inalterado, dependendo do valor de *bDirty*.

```
void SetDirty(BOOL bDirty);
```

### <a name="parameters"></a>Parâmetros

*bDirty*<br/>
[in] Se for TRUE, o estado da página de propriedade é marcado como alterada. Caso contrário, ele é marcado como inalterado.

### <a name="remarks"></a>Comentários

Se necessário, `SetDirty` informa o quadro a que a página de propriedade foi alterada.

##  <a name="setobjects"></a>  IPropertyPageImpl::SetObjects

Fornece uma matriz de `IUnknown` ponteiros para os objetos associados com a página de propriedades.

```
HRESULT SetObjects(ULONG nObjects, IUnknown** ppUnk);
```

### <a name="remarks"></a>Comentários

Ver [IPropertyPage::SetObjects](/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-setobjects) no Windows SDK.

##  <a name="setpagesite"></a>  IPropertyPageImpl::SetPageSite

Fornece a página de propriedade com um [IPropertyPageSite](/windows/desktop/api/ocidl/nn-ocidl-ipropertypagesite) ponteiro, por meio do qual a página de propriedades se comunica com o quadro de propriedades.

```
HRESULT SetPageSite(IPropertyPageSite* pPageSite);
```

### <a name="remarks"></a>Comentários

Ver [IPropertyPage::SetPageSite](/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-setpagesite) no Windows SDK.

##  <a name="show"></a>  IPropertyPageImpl::Show

Faz a caixa de diálogo de página de propriedade visível ou invisível.

```
HRESULT Show(UINT nCmdShow);
```

### <a name="remarks"></a>Comentários

Ver [IPropertyPage::Show](/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-show) no Windows SDK.

##  <a name="translateaccelerator"></a>  IPropertyPageImpl::TranslateAccelerator

Processa o pressionamento de tecla especificado em `pMsg`.

```
HRESULT TranslateAccelerator(MSG* pMsg);
```

### <a name="remarks"></a>Comentários

Ver [IPropertyPage::TranslateAccelerator](/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-translateaccelerator) no Windows SDK.

## <a name="see-also"></a>Consulte também

[Classe IPropertyPage2Impl](../../atl/reference/ipropertypage2impl-class.md)<br/>
[Classe IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md)<br/>
[Classe ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
