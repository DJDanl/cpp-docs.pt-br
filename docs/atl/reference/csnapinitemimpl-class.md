---
title: Classe CSnapInItemImpl
ms.date: 11/04/2016
f1_keywords:
- CSnapInItemImpl
- ATLSNAP/ATL::CSnapInItemImpl
- ATLSNAP/ATL::CSnapInItemImpl::CSnapInItemImpl
- ATLSNAP/ATL::CSnapInItemImpl::AddMenuItems
- ATLSNAP/ATL::CSnapInItemImpl::Command
- ATLSNAP/ATL::CSnapInItemImpl::CreatePropertyPages
- ATLSNAP/ATL::CSnapInItemImpl::FillData
- ATLSNAP/ATL::CSnapInItemImpl::GetResultPaneInfo
- ATLSNAP/ATL::CSnapInItemImpl::GetResultViewType
- ATLSNAP/ATL::CSnapInItemImpl::GetScopePaneInfo
- ATLSNAP/ATL::CSnapInItemImpl::Notify
- ATLSNAP/ATL::CSnapInItemImpl::QueryPagesFor
- ATLSNAP/ATL::CSnapInItemImpl::SetMenuInsertionFlags
- ATLSNAP/ATL::CSnapInItemImpl::SetToolbarButtonInfo
- ATLSNAP/ATL::CSnapInItemImpl::UpdateMenuState
- ATLSNAP/ATL::CSnapInItemImpl::UpdateToolbarButton
- ATLSNAP/ATL::CSnapInItemImpl::m_bstrDisplayName
- ATLSNAP/ATL::CSnapInItemImpl::m_resultDataItem
- ATLSNAP/ATL::CSnapInItemImpl::m_scopeDataItem
helpviewer_keywords:
- snap-ins, data items
- snap-ins, ATL support for
- CSnapInItemImpl class
- snap-ins
ms.assetid: 52caefbd-9eae-49b0-add2-d55524271aa7
ms.openlocfilehash: a9ebcf8827d79a9613ce14251d361dd607aa6af3
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496555"
---
# <a name="csnapinitemimpl-class"></a>Classe CSnapInItemImpl

Essa classe fornece métodos para implementar um objeto de nó de snap-in.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <class T, BOOL bIsExtension = FALSE>
class ATL_NO_VTABLE CSnapInItemImpl : public CSnapInItem
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `CSnapInItemImpl`.

*bIsExtension*<br/>
TRUE se o objeto for uma extensão de snap-in; caso contrário, FALSE.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSnapInItemImpl::CSnapInItemImpl](#csnapinitemimpl)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSnapInItemImpl::AddMenuItems](#addmenuitems)|Adiciona itens de menu a um menu de contexto.|
|[CSnapInItemImpl:: comando](#command)|Chamado pelo console do quando um item de menu personalizado é selecionado.|
|[CSnapInItemImpl::CreatePropertyPages](#createpropertypages)|Adiciona páginas à folha de propriedades do snap-in.|
|[CSnapInItemImpl::FillData](#filldata)|Copia informações sobre o objeto de snap-in em um fluxo especificado.|
|[CSnapInItemImpl::GetResultPaneInfo](#getresultpaneinfo)|Recupera a `RESULTDATAITEM` estrutura do snap-in.|
|[CSnapInItemImpl::GetResultViewType](#getresultviewtype)|Determina o tipo de exibição usado pelo painel de resultados.|
|[CSnapInItemImpl::GetScopePaneInfo](#getscopepaneinfo)|Recupera a `SCOPEDATAITEM` estrutura do snap-in.|
|[CSnapInItemImpl::Notify](#notify)|Chamado pelo console do para notificar o snap-in de ações executadas pelo usuário.|
|[CSnapInItemImpl::QueryPagesFor](#querypagesfor)|Chamado para ver se o nó do snap-in dá suporte a páginas de propriedades.|
|[CSnapInItemImpl::SetMenuInsertionFlags](#setmenuinsertionflags)|Modifica os sinalizadores de inserção de menu para um objeto de snap-in.|
|[CSnapInItemImpl::SetToolbarButtonInfo](#settoolbarbuttoninfo)|Define as informações do botão da barra de ferramentas especificado.|
|[CSnapInItemImpl::UpdateMenuState](#updatemenustate)|Atualiza o estado de um item de menu de contexto.|
|[CSnapInItemImpl::UpdateToolbarButton](#updatetoolbarbutton)|Atualiza o estado do botão da barra de ferramentas especificado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSnapInItemImpl::m_bstrDisplayName](#m_bstrdisplayname)|O nome do objeto do snap-in.|
|[CSnapInItemImpl::m_resultDataItem](#m_resultdataitem)|A estrutura `RESULTDATAITEM` do Windows usada `CSnapInItemImpl` pelo objeto.|
|[CSnapInItemImpl::m_scopeDataItem](#m_scopedataitem)|A estrutura `SCOPEDATAITEM` do Windows usada `CSnapInItemImpl` pelo objeto.|

## <a name="remarks"></a>Comentários

`CSnapInItemImpl`fornece uma implementação básica para um objeto de nó de snap-in, como adicionar itens de menu e barras de ferramentas, e encaminhar comandos para o nó de snap-in para a função de manipulador apropriada. Esses recursos são implementados usando várias interfaces e tipos de mapa diferentes. A implementação padrão manipula as notificações enviadas ao objeto node determinando a instância correta da classe derivada e, em seguida, encaminhando a mensagem para a instância correta.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CSnapInItem`

`CSnapInItemImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsnap. h

##  <a name="addmenuitems"></a>  CSnapInItemImpl::AddMenuItems

Esse método implementa a função Win32 [IExtendContextMenu::](/windows/win32/api/mmc/nf-mmc-iextendcontextmenu-addmenuitems)AddMenuItems.

```
AddMenuItems(
    LPCONTEXTMENUCALLBACK piCallback,
    long* pInsertionAllowed,
    DATA_OBJECT_TYPES type);
```

### <a name="parameters"></a>Parâmetros

*piCallback*<br/>
no Ponteiro para o `IContextMenuCallback` que pode adicionar itens ao menu de contexto.

*pInsertionAllowed*<br/>
[entrada, saída] Identifica os pontos de inserção do console de gerenciamento Microsoft (MMC), definidos por um menu, que podem ser usados. Isso pode ser uma combinação dos seguintes sinalizadores:

- Os itens CCM_INSERTIONALLOWED_TOP podem ser inseridos na parte superior de um menu de contexto.

- CCM_INSERTIONALLOWED_NEW itens podem ser inseridos no submenu criar novo.

- CCM_INSERTIONALLOWED_TASK itens podem ser inseridos no submenu tarefa.

- Os itens CCM_INSERTIONALLOWED_VIEW podem ser inseridos no menu Exibir da barra de ferramentas ou no submenu Exibir do menu de contexto do painel de resultados.

*type*<br/>
no Especifica o tipo de objeto. Ele pode ter um dos seguintes valores:

- Objeto de dados CCT_SCOPE para o contexto do painel de escopo.

- Objeto de dados CCT_RESULT para o contexto do painel de resultados.

- Objeto de dados CCT_SNAPIN_MANAGER para o contexto do Gerenciador de snap-in.

- O objeto de dados CCT_UNINITIALIZED tem um tipo inválido.

##  <a name="command"></a>CSnapInItemImpl:: comando

Esse método implementa a função Win32 [IExtendContextMenu:: Command](/windows/win32/api/mmc/nf-mmc-iextendcontextmenu-command).

```
Command(long lCommandID, DATA_OBJECT_TYPES type);
```

### <a name="parameters"></a>Parâmetros

*lCommandID*<br/>
no Especifica o identificador de comando do item de menu.

*type*<br/>
no Especifica o tipo de objeto. Ele pode ter um dos seguintes valores:

- Objeto de dados CCT_SCOPE para o contexto do painel de escopo.

- Objeto de dados CCT_RESULT para o contexto do painel de resultados.

- Objeto de dados CCT_SNAPIN_MANAGER para o contexto do Gerenciador de snap-in.

- O objeto de dados CCT_UNINITIALIZED tem um tipo inválido.

##  <a name="createpropertypages"></a>CSnapInItemImpl::CreatePropertyPages

Esse método implementa a função Win32 [IExtendPropertySheet:: CreatePropertyPages](/windows/win32/api/mmc/nn-mmc-iextendpropertysheet2).

```
CreatePropertyPages(
    LPPROPERTYSHEETCALLBACK lpProvider,
    long handle,
    IUnknown* pUnk,
    DATA_OBJECT_TYPES type);
```

### <a name="parameters"></a>Parâmetros

*lpProvider*<br/>
no Ponteiro para a `IPropertySheetCallback` interface.

*processamento*<br/>
no Especifica o identificador usado para rotear a mensagem de notificação MMCN_PROPERTY_CHANGE para a classe de dados apropriada.

*pUnk*<br/>
no Ponteiro para a `IExtendPropertySheet` interface no objeto que contém informações de contexto sobre o nó.

*type*<br/>
no Especifica o tipo de objeto. Ele pode ter um dos seguintes valores:

- Objeto de dados CCT_SCOPE para o contexto do painel de escopo.

- Objeto de dados CCT_RESULT para o contexto do painel de resultados.

- Objeto de dados CCT_SNAPIN_MANAGER para o contexto do Gerenciador de snap-in.

- O objeto de dados CCT_UNINITIALIZED tem um tipo inválido.

##  <a name="csnapinitemimpl"></a>  CSnapInItemImpl::CSnapInItemImpl

Constrói um objeto `CSnapInItemImpl`.

```
CSnapInItemImpl();
```

##  <a name="filldata"></a>  CSnapInItemImpl::FillData

Essa função é chamada para recuperar informações sobre o item.

```
FillData(CLIPFORMAT cf, LPSTREAM pStream);
```

### <a name="parameters"></a>Parâmetros

*cf*<br/>
no O formato (texto, Rich Text ou Rich Text com itens OLE) da área de transferência.

*pStream*<br/>
no Um ponteiro para o fluxo que contém os dados do objeto.

### <a name="remarks"></a>Comentários

Para implementar corretamente essa função, copie as informações corretas para o fluxo (*pStream*), dependendo do formato da área de transferência indicado pelo *CF*.

##  <a name="getresultviewtype"></a>  CSnapInItemImpl::GetResultViewType

Chame essa função para recuperar o tipo de exibição do painel de resultados do objeto do snap-in.

```
GetResultViewType(
    LPOLESTR* ppViewType,
    long* pViewOptions);
```

### <a name="parameters"></a>Parâmetros

*ppViewType*<br/>
fora Ponteiro para o endereço do tipo de exibição retornado.

*pViewOptions*<br/>
fora Ponteiro para a enumeração MMC_VIEW_OPTIONS, que fornece ao console as opções especificadas pelo snap-in proprietário. Esse valor pode ser um dos seguintes:

- MMC_VIEW_OPTIONS_NOLISTVIEWS = 0x00000001 instrui o console a evitar a apresentação de opções de exibição de lista padrão no menu **Exibir** . Permite que o snap-in exiba suas próprias exibições personalizadas somente no painel exibição de resultado. Esse é o único sinalizador de opção definido neste momento.

- MMC_VIEW_OPTIONS_NONE = 0 permite as opções de exibição padrão.

##  <a name="getscopepaneinfo"></a>  CSnapInItemImpl::GetScopePaneInfo

Chame essa função para recuperar a `SCOPEDATAITEM` estrutura do snap-in.

```
GetScopePaneInfo (SCOPEDATAITEM* pScopeDataItem);
```

### <a name="parameters"></a>Parâmetros

*pScopeDataItem*<br/>
fora Um ponteiro para a `SCOPEDATAITEM` estrutura `CSnapInItemImpl` do objeto.

##  <a name="getresultpaneinfo"></a>  CSnapInItemImpl::GetResultPaneInfo

Chame essa função para recuperar a `RESULTDATAITEM` estrutura do snap-in.

```
GetResultPaneInfo (RESULTDATAITEM* pResultDataItem);
```

### <a name="parameters"></a>Parâmetros

*pResultDataItem*<br/>
fora Um ponteiro para a `RESULTDATAITEM` estrutura `CSnapInItemImpl` do objeto.

##  <a name="m_bstrdisplayname"></a>  CSnapInItemImpl::m_bstrDisplayName

Contém a cadeia de caracteres exibida para o item de nó.

```
CComBSTR m_bstrDisplayName;
```

##  <a name="m_scopedataitem"></a>  CSnapInItemImpl::m_scopeDataItem

A `SCOPEDATAITEM` estrutura do objeto de dados do snap-in.

```
SCOPEDATAITEM m_scopeDataItem;
```

##  <a name="m_resultdataitem"></a>  CSnapInItemImpl::m_resultDataItem

A estrutura [RESULTDATAITEM](/windows/win32/api/mmc/ns-mmc-resultdataitem) do objeto de dados do snap-in.

```
RESULTDATAITEM m_resultDataItem;
```

##  <a name="notify"></a>  CSnapInItemImpl::Notify

Chamado quando o objeto do snap-in é acionado pelo usuário.

```
STDMETHOD(Notify)(
    MMC_NOTIFY_TYPE event,
    long arg,
    long param,
    IComponentData* pComponentData,
    IComponent* pComponent,
    DATA_OBJECT_TYPES type) = 0;
```

### <a name="parameters"></a>Parâmetros

*event*<br/>
no Identifica uma ação realizada por um usuário. As seguintes notificações são possíveis:

- MMCN_ACTIVATE enviado quando uma janela está sendo ativada e desativada.

- MMCN_ADD_IMAGES enviado para adicionar imagens ao painel de resultados.

- MMCN_BTN_CLICK enviado quando o usuário clica em um dos botões da barra de ferramentas.

- MMCN_CLICK enviado quando um usuário clica em um botão do mouse em um item de exibição de lista.

- MMCN_DBLCLICK enviado quando um usuário clica duas vezes com um botão do mouse em um item de exibição de lista.

- MMCN_DELETE enviado para informar ao snap-in que o objeto deve ser excluído.

- MMCN_EXPAND enviado quando uma pasta precisa ser expandida ou contratada.

- MMCN_MINIMIZED enviado quando uma janela está sendo minimizada ou maximizada.

- MMCN_PROPERTY_CHANGE enviado para notificar um objeto de snap-in que o modo de exibição do objeto do snap-in está prestes a ser alterado.

- MMCN_REMOVE_CHILDREN enviado quando o snap-in deve excluir a subárvore inteira que foi adicionada abaixo do nó especificado.

- MMCN_RENAME enviou a primeira vez para consultar uma renomeação e a segunda vez para fazer a renomeação.

- MMCN_SELECT enviado quando um item no painel exibição de escopo ou resultado é selecionado.

- MMCN_SHOW enviado quando um item de escopo é selecionado ou desmarcado pela primeira vez.

- MMCN_VIEW_CHANGE enviado quando o snap-in pode atualizar todas as exibições quando ocorre uma alteração.

*arg*<br/>
no Depende do tipo de notificação.

*param*<br/>
no Depende do tipo de notificação.

*pComponentData*<br/>
fora Um ponteiro para o objeto que `IComponentData`está implementando. Esse parâmetro será nulo se a notificação não estiver sendo encaminhada do `IComponentData::Notify`.

*pComponent*<br/>
fora Um ponteiro para o objeto que implementa `IComponent`. Esse parâmetro será nulo se a notificação não estiver sendo encaminhada do `IComponent::Notify`.

*type*<br/>
no Especifica o tipo de objeto. Ele pode ter um dos seguintes valores:

- Objeto de dados CCT_SCOPE para o contexto do painel de escopo.

- Objeto de dados CCT_RESULT para o contexto do painel de resultados.

- Objeto de dados CCT_SNAPIN_MANAGER para o contexto do Gerenciador de snap-in.

- O objeto de dados CCT_UNINITIALIZED tem um tipo inválido.

##  <a name="querypagesfor"></a>  CSnapInItemImpl::QueryPagesFor

Chamado para ver se o nó do snap-in dá suporte a páginas de propriedades.

```
QueryPagesFor(DATA_OBJECT_TYPES type);
```

##  <a name="setmenuinsertionflags"></a>  CSnapInItemImpl::SetMenuInsertionFlags

Chame essa função para modificar os sinalizadores de inserção de menu, especificados por *pInsertionAllowed*, para o objeto de snap-in.

```
void SetMenuInsertionFlags(
    bool bBeforeInsertion,
    long* pInsertionAllowed);
```

### <a name="parameters"></a>Parâmetros

*bBeforeInsertion*<br/>
no Diferente de zero se a função deve ser chamada antes de os itens serem adicionados ao menu de contexto; caso contrário, 0.

*pInsertionAllowed*<br/>
[entrada, saída] Identifica os pontos de inserção do console de gerenciamento Microsoft (MMC), definidos por um menu, que podem ser usados. Isso pode ser uma combinação dos seguintes sinalizadores:

- Os itens CCM_INSERTIONALLOWED_TOP podem ser inseridos na parte superior de um menu de contexto.

- CCM_INSERTIONALLOWED_NEW itens podem ser inseridos no submenu criar novo.

- CCM_INSERTIONALLOWED_TASK itens podem ser inseridos no submenu tarefa.

- Os itens CCM_INSERTIONALLOWED_VIEW podem ser inseridos no menu Exibir da barra de ferramentas ou no submenu Exibir do menu de contexto do painel de resultados.

### <a name="remarks"></a>Comentários

Se você estiver desenvolvendo um snap-in primário, poderá redefinir qualquer um dos sinalizadores de inserção como uma forma de restringir o tipo de itens de menu que uma extensão de terceiros pode adicionar. Por exemplo, o snap-in primário pode limpar o sinalizador CCM_INSERTIONALLOWED_NEW para impedir que as extensões adicionem seus próprios itens de menu criar novos.

Você não deve tentar definir bits em *pInsertionAllowed* que foram originalmente limpos. Versões futuras do MMC podem usar bits não definidas no momento, portanto, você não deve alterar os bits que não estão definidos no momento.

##  <a name="settoolbarbuttoninfo"></a>  CSnapInItemImpl::SetToolbarButtonInfo

Chame essa função para modificar os estilos de botão da barra de ferramentas, do objeto do snap-in, antes da criação da barra de ferramentas.

```
void SetToolbarButtonInfo(
    UINT id,
    BYTE* fsState,
    BYTE* fsType);
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
no A ID do botão da barra de ferramentas a ser definida.

*fsState*<br/>
no Os sinalizadores de estado do botão. Pode ser um ou mais dos seguintes:

- TBSTATE_CHECKED o botão tem o estilo TBSTYLE_CHECKED e está sendo pressionado.

- TBSTATE_ENABLED o botão aceita a entrada do usuário. Um botão que não tem esse estado não aceita a entrada do usuário e está acinzentado.

- TBSTATE_HIDDEN o botão não está visível e não pode receber a entrada do usuário.

- TBSTATE_INDETERMINATE o botão está acinzentado.

- TBSTATE_PRESSED o botão está sendo pressionado.

- TBSTATE_WRAP uma quebra de linha após o botão. O botão também deve ter o TBSTATE_ENABLED.

*fsType*<br/>
no Os sinalizadores de estado do botão. Pode ser um ou mais dos seguintes:

- TBSTYLE_BUTTON Cria um botão de ação padrão.

- TBSTYLE_CHECK cria um botão que alterna entre os Estados pressionados e não pressionados sempre que o usuário clica nele. O botão tem uma cor de plano de fundo diferente quando está no estado pressionado.

- TBSTYLE_CHECKGROUP Cria um botão de seleção que permanece pressionado até que outro botão no grupo seja pressionado.

- TBSTYLE_GROUP cria um botão que permanece pressionado até que outro botão no grupo seja pressionado.

- TBSTYLE_SEP Cria um separador, fornecendo uma pequena lacuna entre os grupos de botões. Um botão que tem esse estilo não recebe a entrada do usuário.

##  <a name="updatemenustate"></a>  CSnapInItemImpl::UpdateMenuState

Chame essa função para modificar um item de menu antes que ele seja inserido no menu de contexto do objeto de snap-in.

```
void UpdateMenuState(
    UINT id,
    LPTSTR pBuf,
    UINT* flags);
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
no A ID do item de menu a ser definido.

*pBuf*<br/>
no Um ponteiro para a cadeia de caracteres do item de menu a ser atualizado.

*flags*<br/>
no Especifica os novos sinalizadores de estado. Isso pode ser uma combinação dos seguintes sinalizadores:

- MF_POPUP especifica que este é um submenu dentro do menu de contexto. Itens de menu, pontos de inserção e submenus adicionais podem ser adicionados a esse submenu usando `lCommandID` seu `IInsertionPointID`como.

- MF_BITMAP e MF_OWNERDRAW esses sinalizadores não são permitidos e resultarão em um valor de retorno de E_INVALIDARG.

- MF_SEPARATOR desenha uma linha divisória horizontal. Somente `IContextMenuProvider` é permitido adicionar itens de menu com MF_SEPARATOR definido.

- MF_CHECKED Coloca uma marca de seleção ao lado do item de menu.

- MF_DISABLED desabilita o item de menu para que ele não possa ser selecionado, mas o sinalizador não o torna cinza.

- MF_ENABLED habilita o item de menu para que ele possa ser selecionado, restaurando-o a partir de seu estado acinzentado.

- MF_GRAYED desabilita o item de menu, acinzentando-o para que não possa ser selecionado.

- MF_MENUBARBREAK funciona da mesma forma que o sinalizador MF_MENUBREAK para uma barra de menus. Para um menu suspenso, submenu ou menu de atalho, a nova coluna é separada da coluna antiga por uma linha vertical.

- MF_MENUBREAK coloca o item em uma nova linha (para uma barra de menus) ou em uma nova coluna (para um menu suspenso, submenu ou menu de atalho) sem separar colunas.

- MF_UNCHECKED não coloca uma marca de seleção ao lado do item (padrão).

Os seguintes grupos de sinalizadores não podem ser usados juntos:

- MF_DISABLED, MF_ENABLED e MF_GRAYED.

- MF_MENUBARBREAK e MF_MENUBREAK.

- MF_CHECKED e MF_UNCHECKED.

##  <a name="updatetoolbarbutton"></a>  CSnapInItemImpl::UpdateToolbarButton

Chame essa função para modificar um botão da barra de ferramentas, do objeto do snap-in, antes de ser exibido.

```
BOOL UpdateToolbarButton(UINT id, BYTE fsState);
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
Especifica a ID do botão da barra de ferramentas a ser atualizada.

*fsState*<br/>
Especifica um estado de botão da barra de ferramentas. Se esse estado for para ser definido, retornará TRUE. Isso pode ser uma combinação dos seguintes sinalizadores:

- HABILITADO o botão aceita a entrada do usuário. Um botão que não tem esse estado não aceita a entrada do usuário e está acinzentado.

- MARCADO o botão tem o estilo marcado e está sendo pressionado.

- OCULTO o botão não está visível e não pode receber entrada do usuário.

- Indeterminado que o botão está acinzentado.

- BUTTONPRESSED o botão está sendo pressionado.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
