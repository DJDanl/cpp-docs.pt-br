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
ms.openlocfilehash: 04eeba0239789b9f3220b7bfece3eb41dc7f2826
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81746420"
---
# <a name="csnapinitemimpl-class"></a>Classe CSnapInItemImpl

Esta classe fornece métodos para implementar um objeto de nó snap-in.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T, BOOL bIsExtension = FALSE>
class ATL_NO_VTABLE CSnapInItemImpl : public CSnapInItem
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `CSnapInItemImpl`.

*bIsExtension*<br/>
TRUE se o objeto for uma extensão snap-in; caso contrário, FALSO.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSnapInItemImpl::CSnapInItemImpl](#csnapinitemimpl)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSnapInItemImpl::AddMenuItems](#addmenuitems)|Adiciona itens do menu a um menu de contexto.|
|[CSnapInItemImpl::Comando](#command)|Chamado pelo console quando um item de menu personalizado é selecionado.|
|[CSnapInItemImpl::CreatePropertyPages](#createpropertypages)|Adiciona páginas à folha de propriedades do snap-in.|
|[CSnapInItemImpl::FillData](#filldata)|Copia informações sobre o objeto snap-in em um fluxo especificado.|
|[CSnapInItemImpl::GetResultPaneInfo](#getresultpaneinfo)|Recupera a `RESULTDATAITEM` estrutura do snap-in.|
|[CSnapInItemImpl::GetResultViewType](#getresultviewtype)|Determina o tipo de visão usado pelo painel de resultados.|
|[CSnapInItemImpl::GetScopePaneInfo](#getscopepaneinfo)|Recupera a `SCOPEDATAITEM` estrutura do snap-in.|
|[CSnapInItemImpl::Notificar](#notify)|Chamado pelo console para notificar o snap-in das ações tomadas pelo usuário.|
|[CSnapInItemImpl::QueryPagesFor](#querypagesfor)|Chamado para ver se o nó snap-in suporta páginas de propriedade.|
|[CSnapInItemImpl::SetMenuInsertionFlags](#setmenuinsertionflags)|Modifica as bandeiras de inserção do menu para um objeto snap-in.|
|[CSnapInItemImpl::SetToolbarButtonInfo](#settoolbarbuttoninfo)|Define as informações do botão de barra de ferramentas especificado.|
|[CSnapInItemImpl::UpdateMenuState](#updatemenustate)|Atualiza o estado de um item do menu de contexto.|
|[CSnapInItemImpl::UpdateToolbarButton](#updatetoolbarbutton)|Atualiza o estado do botão de barra de ferramentas especificado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSnapInItemImpl::m_bstrDisplayName](#m_bstrdisplayname)|O nome do objeto snap-in.|
|[CSnapInItemImpl::m_resultDataItem](#m_resultdataitem)|A `RESULTDATAITEM` estrutura do `CSnapInItemImpl` Windows usada pelo objeto.|
|[CSnapInItemImpl::m_scopeDataItem](#m_scopedataitem)|A `SCOPEDATAITEM` estrutura do `CSnapInItemImpl` Windows usada pelo objeto.|

## <a name="remarks"></a>Comentários

`CSnapInItemImpl`fornece uma implementação básica para um objeto de nó snap-in, como adicionar itens de menu e barras de ferramentas e comandos de encaminhamento para o nó snap-in para a função de manipulador apropriado. Esses recursos são implementados usando várias interfaces diferentes e tipos de mapas. A implementação padrão lida com notificações enviadas ao objeto nó determinando a instância correta da classe derivada e, em seguida, encaminhando a mensagem para a instância correta.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CSnapInItem`

`CSnapInItemImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsnap.h

## <a name="csnapinitemimpladdmenuitems"></a><a name="addmenuitems"></a>CSnapInItemImpl::AddMenuItems

Este método implementa a função [Win32 IExtendContextMenu::AddMenuItems](/windows/win32/api/mmc/nf-mmc-iextendcontextmenu-addmenuitems).

```
AddMenuItems(
    LPCONTEXTMENUCALLBACK piCallback,
    long* pInsertionAllowed,
    DATA_OBJECT_TYPES type);
```

### <a name="parameters"></a>Parâmetros

*piCallback*<br/>
[em] Ponteiro para `IContextMenuCallback` o que pode adicionar itens ao menu de contexto.

*pInserçãopermitida*<br/>
[dentro, fora] Identifica os pontos de inserção do Microsoft Management Console (MMC) definidos pelo menu que podem ser usados. Esta pode ser uma combinação das seguintes bandeiras:

- CCM_INSERTIONALLOWED_TOP Itens podem ser inseridos na parte superior de um menu de contexto.

- CCM_INSERTIONALLOWED_NEW Itens podem ser inseridos no submenu Criar novo.

- CCM_INSERTIONALLOWED_TASK Itens podem ser inseridos no submenu Tarefa.

- CCM_INSERTIONALLOWED_VIEW Itens podem ser inseridos no menu de exibição da barra de ferramentas ou no submenu Exibir do menu de contexto do painel de resultados.

*tipo*<br/>
[em] Especifica o tipo de objeto. Pode ter um dos seguintes valores:

- CCT_SCOPE objeto Data para o contexto do painel de escopo.

- CCT_RESULT objeto Data para o contexto do painel de resultados.

- CCT_SNAPIN_MANAGER objeto Data para o contexto do gerenciador snap-in.

- CCT_UNINITIALIZED objeto Data tem um tipo inválido.

## <a name="csnapinitemimplcommand"></a><a name="command"></a>CSnapInItemImpl::Comando

Este método implementa a função Win32 [IExtendContextMenu::Comando](/windows/win32/api/mmc/nf-mmc-iextendcontextmenu-command).

```
Command(long lCommandID, DATA_OBJECT_TYPES type);
```

### <a name="parameters"></a>Parâmetros

*lCommandID*<br/>
[em] Especifica o identificador de comando do item do menu.

*tipo*<br/>
[em] Especifica o tipo de objeto. Pode ter um dos seguintes valores:

- CCT_SCOPE objeto Data para o contexto do painel de escopo.

- CCT_RESULT objeto Data para o contexto do painel de resultados.

- CCT_SNAPIN_MANAGER objeto Data para o contexto do gerenciador snap-in.

- CCT_UNINITIALIZED objeto Data tem um tipo inválido.

## <a name="csnapinitemimplcreatepropertypages"></a><a name="createpropertypages"></a>CSnapInItemImpl::CreatePropertyPages

Este método implementa a função Win32 [IExtendPropertySheet::CreatePropertyPages](/windows/win32/api/mmc/nn-mmc-iextendpropertysheet2).

```
CreatePropertyPages(
    LPPROPERTYSHEETCALLBACK lpProvider,
    long handle,
    IUnknown* pUnk,
    DATA_OBJECT_TYPES type);
```

### <a name="parameters"></a>Parâmetros

*lpProvider*<br/>
[em] Ponteiro para `IPropertySheetCallback` a interface.

*Lidar com*<br/>
[em] Especifica o identificador usado para encaminhar a mensagem de notificação MMCN_PROPERTY_CHANGE para a classe de dados apropriada.

*Punk*<br/>
[em] Ponteiro para `IExtendPropertySheet` a interface no objeto que contém informações de contexto sobre o nó.

*tipo*<br/>
[em] Especifica o tipo de objeto. Pode ter um dos seguintes valores:

- CCT_SCOPE objeto Data para o contexto do painel de escopo.

- CCT_RESULT objeto Data para o contexto do painel de resultados.

- CCT_SNAPIN_MANAGER objeto Data para o contexto do gerenciador snap-in.

- CCT_UNINITIALIZED objeto Data tem um tipo inválido.

## <a name="csnapinitemimplcsnapinitemimpl"></a><a name="csnapinitemimpl"></a>CSnapInItemImpl::CSnapInItemImpl

Constrói um objeto `CSnapInItemImpl`.

```
CSnapInItemImpl();
```

## <a name="csnapinitemimplfilldata"></a><a name="filldata"></a>CSnapInItemImpl::FillData

Esta função é chamada para recuperar informações sobre o item.

```
FillData(CLIPFORMAT cf, LPSTREAM pStream);
```

### <a name="parameters"></a>Parâmetros

*Cf*<br/>
[em] O formato (texto, texto rico ou texto rico com itens OLE) da Área de Transferência.

*pStream*<br/>
[em] Um ponteiro para o fluxo contendo os dados do objeto.

### <a name="remarks"></a>Comentários

Para implementar corretamente esta função, copie as informações corretas no fluxo *(pStream),* dependendo do formato de área de transferência indicado por *cf*.

## <a name="csnapinitemimplgetresultviewtype"></a><a name="getresultviewtype"></a>CSnapInItemImpl::GetResultViewType

Chame esta função para recuperar o tipo de exibição para o painel de resultado do objeto snap-in.

```
GetResultViewType(
    LPOLESTR* ppViewType,
    long* pViewOptions);
```

### <a name="parameters"></a>Parâmetros

*ppViewType*<br/>
[fora] Ponteiro para o endereço do tipo de exibição retornado.

*pViewOptions*<br/>
[fora] Ponteiro para a enumeração MMC_VIEW_OPTIONS, que fornece ao console opções especificadas pelo snap-in de propriedade. Este valor pode ser um dos seguintes:

- MMC_VIEW_OPTIONS_NOLISTVIEWS = 0x00000001 Informa o console para não apresentar opções de exibição de lista padrão no menu **Exibir.** Permite que o snap-in exiba suas próprias exibições personalizadas apenas no painel de exibição de resultados. Esta é a única opção de bandeira definida no momento.

- MMC_VIEW_OPTIONS_NONE = 0 Permite as opções de exibição padrão.

## <a name="csnapinitemimplgetscopepaneinfo"></a><a name="getscopepaneinfo"></a>CSnapInItemImpl::GetScopePaneInfo

Chame esta função `SCOPEDATAITEM` para recuperar a estrutura do snap-in.

```
GetScopePaneInfo (SCOPEDATAITEM* pScopeDataItem);
```

### <a name="parameters"></a>Parâmetros

*pScopeDataItem*<br/>
[fora] Um ponteiro `SCOPEDATAITEM` para a `CSnapInItemImpl` estrutura do objeto.

## <a name="csnapinitemimplgetresultpaneinfo"></a><a name="getresultpaneinfo"></a>CSnapInItemImpl::GetResultPaneInfo

Chame esta função `RESULTDATAITEM` para recuperar a estrutura do snap-in.

```
GetResultPaneInfo (RESULTDATAITEM* pResultDataItem);
```

### <a name="parameters"></a>Parâmetros

*pResultDataItem*<br/>
[fora] Um ponteiro `RESULTDATAITEM` para a `CSnapInItemImpl` estrutura do objeto.

## <a name="csnapinitemimplm_bstrdisplayname"></a><a name="m_bstrdisplayname"></a>CSnapInItemImpl::m_bstrDisplayName

Contém a seqüência exibida para o item nó.

```
CComBSTR m_bstrDisplayName;
```

## <a name="csnapinitemimplm_scopedataitem"></a><a name="m_scopedataitem"></a>CSnapInItemImpl::m_scopeDataItem

A `SCOPEDATAITEM` estrutura do objeto de dados snap-in.

```
SCOPEDATAITEM m_scopeDataItem;
```

## <a name="csnapinitemimplm_resultdataitem"></a><a name="m_resultdataitem"></a>CSnapInItemImpl::m_resultDataItem

A estrutura [RESULTDATAITEM](/windows/win32/api/mmc/ns-mmc-resultdataitem) do objeto de dados snap-in.

```
RESULTDATAITEM m_resultDataItem;
```

## <a name="csnapinitemimplnotify"></a><a name="notify"></a>CSnapInItemImpl::Notificar

Chamado quando o objeto snap-in é acionado pelo usuário.

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
[em] Identifica uma ação tomada por um usuário. As seguintes notificações são possíveis:

- MMCN_ACTIVATE Enviado quando uma janela está sendo ativada e desativada.

- MMCN_ADD_IMAGES enviado para adicionar imagens ao painel de resultados.

- MMCN_BTN_CLICK Enviado quando o usuário clica em um dos botões da barra de ferramentas.

- MMCN_CLICK Enviado quando um usuário clica em um botão do mouse em um item de exibição de lista.

- MMCN_DBLCLICK Enviado quando um usuário clica duas vezes em um botão do mouse em um item de exibição de lista.

- MMCN_DELETE Enviado para informar o snap-in de que o objeto deve ser excluído.

- MMCN_EXPAND Enviado quando uma pasta precisa ser expandida ou contratada.

- MMCN_MINIMIZED Enviado quando uma janela está sendo minimizada ou maximizada.

- MMCN_PROPERTY_CHANGE Enviado para notificar um objeto snap-in que a exibição do objeto snap-in está prestes a ser alterada.

- MMCN_REMOVE_CHILDREN Enviado quando o snap-in deve excluir toda a subárvore adicionada abaixo do nó especificado.

- MMCN_RENAME Enviei a primeira vez para consultar um renomee e a segunda vez para fazer o renome.

- MMCN_SELECT Enviado quando um item no escopo ou painel de exibição de resultados é selecionado.

- MMCN_SHOW Enviado quando um item de escopo é selecionado ou desselecionado pela primeira vez.

- MMCN_VIEW_CHANGE Enviado quando o snap-in pode atualizar todas as exibições quando uma alteração ocorre.

*Arg*<br/>
[em] Depende do tipo de notificação.

*param*<br/>
[em] Depende do tipo de notificação.

*pComponentData*<br/>
[fora] Um ponteiro para a `IComponentData`implementação do objeto . Este parâmetro é NULO se a notificação `IComponentData::Notify`não estiver sendo encaminhada de .

*pComponente*<br/>
[fora] Um ponteiro para o `IComponent`objeto que implementa . Este parâmetro é NULO se a notificação `IComponent::Notify`não estiver sendo encaminhada de .

*tipo*<br/>
[em] Especifica o tipo de objeto. Pode ter um dos seguintes valores:

- CCT_SCOPE objeto Data para o contexto do painel de escopo.

- CCT_RESULT objeto Data para o contexto do painel de resultados.

- CCT_SNAPIN_MANAGER objeto Data para o contexto do gerenciador snap-in.

- CCT_UNINITIALIZED objeto Data tem um tipo inválido.

## <a name="csnapinitemimplquerypagesfor"></a><a name="querypagesfor"></a>CSnapInItemImpl::QueryPagesFor

Chamado para ver se o nó snap-in suporta páginas de propriedade.

```
QueryPagesFor(DATA_OBJECT_TYPES type);
```

## <a name="csnapinitemimplsetmenuinsertionflags"></a><a name="setmenuinsertionflags"></a>CSnapInItemImpl::SetMenuInsertionFlags

Chame esta função para modificar os sinalizadores de inserção do menu, especificados por *pInsertionAllowed*, para o objeto snap-in.

```cpp
void SetMenuInsertionFlags(
    bool bBeforeInsertion,
    long* pInsertionAllowed);
```

### <a name="parameters"></a>Parâmetros

*bAntes da inserção*<br/>
[em] Não zero se a função deve ser chamada antes que os itens sejam adicionados ao menu de contexto; caso contrário, 0.

*pInserçãopermitida*<br/>
[dentro, fora] Identifica os pontos de inserção do Microsoft Management Console (MMC) definidos pelo menu que podem ser usados. Esta pode ser uma combinação das seguintes bandeiras:

- CCM_INSERTIONALLOWED_TOP Itens podem ser inseridos na parte superior de um menu de contexto.

- CCM_INSERTIONALLOWED_NEW Itens podem ser inseridos no submenu Criar novo.

- CCM_INSERTIONALLOWED_TASK Itens podem ser inseridos no submenu Tarefa.

- CCM_INSERTIONALLOWED_VIEW Itens podem ser inseridos no menu de exibição da barra de ferramentas ou no submenu Exibir do menu de contexto do painel de resultados.

### <a name="remarks"></a>Comentários

Se você estiver desenvolvendo um snap-in primário, você pode redefinir qualquer um dos sinalizadores de inserção como uma maneira de restringir o tipo de itens de menu que uma extensão de terceiros pode adicionar. Por exemplo, o snap-in principal pode limpar o sinalizador CCM_INSERTIONALLOWED_NEW para evitar que as extensões adicionem seus próprios itens de menu Criar novos.

Você não deve tentar definir bits em *pInsertionAllowed* que foram originalmente limpos. Versões futuras do MMC podem usar bits não definidos no momento, então você não deve alterar bits que ainda não estão definidos.

## <a name="csnapinitemimplsettoolbarbuttoninfo"></a><a name="settoolbarbuttoninfo"></a>CSnapInItemImpl::SetToolbarButtonInfo

Chame esta função para modificar qualquer estilo de botão da barra de ferramentas do objeto snap-in, antes que a barra de ferramentas seja criada.

```cpp
void SetToolbarButtonInfo(
    UINT id,
    BYTE* fsState,
    BYTE* fsType);
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] O ID do botão da barra de ferramentas a ser definido.

*fsState*<br/>
[em] As bandeiras estaduais do botão. Pode ser um ou mais dos seguintes:

- TBSTATE_CHECKED O botão tem o estilo TBSTYLE_CHECKED e está sendo pressionado.

- TBSTATE_ENABLED O botão aceita a entrada do usuário. Um botão que não tem esse estado não aceita entrada do usuário e é acinzentado.

- TBSTATE_HIDDEN O botão não é visível e não pode receber a entrada do usuário.

- TBSTATE_INDETERMINATE O botão está acinzentado.

- TBSTATE_PRESSED O botão está sendo pressionado.

- TBSTATE_WRAP Uma quebra de linha segue o botão. O botão também deve ter o TBSTATE_ENABLED.

*Fstype*<br/>
[em] As bandeiras estaduais do botão. Pode ser um ou mais dos seguintes:

- TBSTYLE_BUTTON Cria um botão padrão.

- TBSTYLE_CHECK Cria um botão que alterna entre os estados pressionados e não pressionados cada vez que o usuário clica nele. O botão tem uma cor de fundo diferente quando está no estado pressionado.

- TBSTYLE_CHECKGROUP Cria um botão de verificação que permanece pressionado até que outro botão do grupo seja pressionado.

- TBSTYLE_GROUP Cria um botão que permanece pressionado até que outro botão do grupo seja pressionado.

- TBSTYLE_SEP Cria um separador, proporcionando uma pequena lacuna entre os grupos de botões. Um botão que tem esse estilo não recebe entrada do usuário.

## <a name="csnapinitemimplupdatemenustate"></a><a name="updatemenustate"></a>CSnapInItemImpl::UpdateMenuState

Chame esta função para modificar um item do menu antes de ser inserido no menu de contexto do objeto snap-in.

```cpp
void UpdateMenuState(
    UINT id,
    LPTSTR pBuf,
    UINT* flags);
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] O ID do item do menu a ser definido.

*pBuf*<br/>
[em] Um ponteiro para a seqüência para que o item do menu seja atualizado.

*Sinalizadores*<br/>
[em] Especifica as novas bandeiras estaduais. Esta pode ser uma combinação das seguintes bandeiras:

- MF_POPUP Especifica que este é um submenu dentro do menu de contexto. Itens de menu, pontos de inserção e outros submenus `lCommandID` podem `IInsertionPointID`ser adicionados a este submenu usando-o como seu .

- MF_BITMAP e MF_OWNERDRAW Essas bandeiras não são permitidas e resultarão em um valor de retorno de E_INVALIDARG.

- MF_SEPARATOR desenha uma linha divisória horizontal. Somente `IContextMenuProvider` é permitido adicionar itens de menu com MF_SEPARATOR definido.

- MF_CHECKED Coloca uma marca de seleção ao lado do item do menu.

- MF_DISABLED Desativa o item do menu para que não possa ser selecionado, mas o sinalizador não o acinzenta.

- MF_ENABLED Habilita o item do menu para que possa ser selecionado, restaurando-o de seu estado cinza.

- MF_GRAYED Desabilita o item do menu, acinzentando-o para que não possa ser selecionado.

- MF_MENUBARBREAK funciona o mesmo que a bandeira MF_MENUBREAK para uma barra de menu. Para um menu suspenso, submenu ou menu de atalho, a nova coluna é separada da coluna antiga por uma linha vertical.

- MF_MENUBREAK Coloca o item em uma nova linha (para uma barra de menu) ou em uma nova coluna (para um menu suspenso, submenu ou menu de atalho) sem separar colunas.

- MF_UNCHECKED Não coloque uma marca de seleção ao lado do item (padrão).

Os seguintes grupos de bandeiras não podem ser usados juntos:

- MF_DISABLED, MF_ENABLED e MF_GRAYED.

- MF_MENUBARBREAK e MF_MENUBREAK.

- MF_CHECKED e MF_UNCHECKED.

## <a name="csnapinitemimplupdatetoolbarbutton"></a><a name="updatetoolbarbutton"></a>CSnapInItemImpl::UpdateToolbarButton

Chame esta função para modificar um botão de barra de ferramentas do objeto snap-in, antes de ser exibido.

```
BOOL UpdateToolbarButton(UINT id, BYTE fsState);
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
Especifica o ID do botão da barra de ferramentas a ser atualizado.

*fsState*<br/>
Especifica um estado de botão da barra de ferramentas. Se este estado for definido, retorne TRUE. Esta pode ser uma combinação das seguintes bandeiras:

- ATIVADO O botão aceita a entrada do usuário. Um botão que não tem esse estado não aceita entrada do usuário e é acinzentado.

- VERIFICADO O botão tem o estilo CHECKED e está sendo pressionado.

- OCULTA O botão não é visível e não pode receber a entrada do usuário.

- INDETER O botão está acinzentado.

- BOTÃO PRESSIONADO O botão está sendo pressionado.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
