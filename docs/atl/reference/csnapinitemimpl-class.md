---
title: Classe CSnapInItemImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- snap-ins, data items
- snap-ins, ATL support for
- CSnapInItemImpl class
- snap-ins
ms.assetid: 52caefbd-9eae-49b0-add2-d55524271aa7
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 9148ee71ba03a1a0492d390378c64f988e6e0f39
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="csnapinitemimpl-class"></a>Classe CSnapInItemImpl
Essa classe fornece métodos para a implementação de um objeto de snap-in do nó.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T, BOOL bIsExtension = FALSE>  
class ATL_NO_VTABLE CSnapInItemImpl : public CSnapInItem
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `CSnapInItemImpl`.  
  
 *bIsExtension*  
 **TRUE** se o objeto é uma extensão de snap-in; caso contrário, **FALSE**.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSnapInItemImpl::CSnapInItemImpl](#csnapinitemimpl)|Construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSnapInItemImpl::AddMenuItems](#addmenuitems)|Adiciona itens de menu a um menu de contexto.|  
|[CSnapInItemImpl::Command](#command)|Chamado pelo console quando um item de menu personalizado é selecionado.|  
|[CSnapInItemImpl::CreatePropertyPages](#createpropertypages)|Adiciona páginas à folha de propriedades do snap-in.|  
|[CSnapInItemImpl::FillData](#filldata)|Informações de cópias no snap-in do objeto em um fluxo especificado.|  
|[CSnapInItemImpl::GetResultPaneInfo](#getresultpaneinfo)|Recupera o **RESULTDATAITEM** estrutura do snap-in.|  
|[CSnapInItemImpl::GetResultViewType](#getresultviewtype)|Determina o tipo de exibição usada pelo painel de resultados.|  
|[CSnapInItemImpl::GetScopePaneInfo](#getscopepaneinfo)|Recupera o **SCOPEDATAITEM** estrutura do snap-in.|  
|[CSnapInItemImpl::Notify](#notify)|Chamado pelo console para notificar o snap-in de ações executadas pelo usuário.|  
|[CSnapInItemImpl::QueryPagesFor](#querypagesfor)|Chamado para ver se o nó de snap-in dá suporte a páginas de propriedades.|  
|[CSnapInItemImpl::SetMenuInsertionFlags](#setmenuinsertionflags)|Modifica os sinalizadores de inserção de menu para um objeto de snap-in.|  
|[CSnapInItemImpl::SetToolbarButtonInfo](#settoolbarbuttoninfo)|Define as informações do botão da barra de ferramentas especificada.|  
|[CSnapInItemImpl::UpdateMenuState](#updatemenustate)|Atualiza o estado de um item de menu de contexto.|  
|[CSnapInItemImpl::UpdateToolbarButton](#updatetoolbarbutton)|Atualiza o estado do botão de barra de ferramentas especificada.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSnapInItemImpl::m_bstrDisplayName](#m_bstrdisplayname)|O nome do objeto snap-in.|  
|[CSnapInItemImpl::m_resultDataItem](#m_resultdataitem)|O Windows **RESULTDATAITEM** estrutura usada pelo `CSnapInItemImpl` objeto.|  
|[CSnapInItemImpl::m_scopeDataItem](#m_scopedataitem)|O Windows **SCOPEDATAITEM** estrutura usada pelo `CSnapInItemImpl` objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CSnapInItemImpl`Fornece uma implementação básica de um objeto de snap-in de nó, como adicionar itens de menu e barras de ferramentas e comandos para o nó de snap-in para a função de manipulador apropriado de encaminhamento. Esses recursos são implementados usando várias interfaces diferentes e mapeiam tipos. A implementação padrão manipula notificações enviadas para o objeto de nó, determinando a instância correta da classe derivada e, em seguida, encaminhar a mensagem para a instância correta.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CSnapInItem`  
  
 `CSnapInItemImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsnap.h  
  
##  <a name="addmenuitems"></a>CSnapInItemImpl::AddMenuItems  
 Este método implementa a função Win32 [IExtendContextMenu::AddMenuItems](http://msdn.microsoft.com/library/aa814841).  
  
```
AddMenuItems(  
    LPCONTEXTMENUCALLBACK piCallback,
    long* pInsertionAllowed,
    DATA_OBJECT_TYPES type);
```  
  
### <a name="parameters"></a>Parâmetros  
 *piCallback*  
 [in] Ponteiro para o **IContextMenuCallback** que pode adicionar itens ao menu de contexto.  
  
 `pInsertionAllowed`  
 [no, out] Identifica definidos pelo Microsoft Management Console MMC, item de menu pontos de inserção que podem ser usados. Isso pode ser uma combinação dos sinalizadores a seguir:  
  
- **CCM_INSERTIONALLOWED_TOP** itens podem ser inseridos na parte superior de um menu de contexto.  
  
- **CCM_INSERTIONALLOWED_NEW** itens podem ser inseridos no submenu criar novo.  
  
- **CCM_INSERTIONALLOWED_TASK** itens podem ser inseridos no submenu tarefas.  
  
- **CCM_INSERTIONALLOWED_VIEW** itens podem ser inseridos no menu de exibição da barra de ferramentas ou no submenu exibição do menu de contexto do painel de resultados.  
  
 `type`  
 [in] Especifica o tipo de objeto. Ele pode ter um dos seguintes valores:  
  
- **CCT_SCOPE** o objeto de dados para o contexto do painel de escopo.  
  
- **CCT_RESULT** o objeto de dados para o contexto do painel de resultados.  
  
- **CCT_SNAPIN_MANAGER** o objeto de dados para o contexto do snap-in Gerenciador.  
  
- **CCT_UNINITIALIZED** o objeto de dados tem um tipo inválido.  
  
##  <a name="command"></a>CSnapInItemImpl::Command  
 Este método implementa a função Win32 [IExtendContextMenu::Command](http://msdn.microsoft.com/library/aa814842).  
  
```
Command(long lCommandID, DATA_OBJECT_TYPES type);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lCommandID*  
 [in] Especifica o identificador do item de menu do comando.  
  
 `type`  
 [in] Especifica o tipo de objeto. Ele pode ter um dos seguintes valores:  
  
- **CCT_SCOPE** o objeto de dados para o contexto do painel de escopo.  
  
- **CCT_RESULT** o objeto de dados para o contexto do painel de resultados.  
  
- **CCT_SNAPIN_MANAGER** o objeto de dados para o contexto do snap-in Gerenciador.  
  
- **CCT_UNINITIALIZED** o objeto de dados tem um tipo inválido.  
  
##  <a name="createpropertypages"></a>CSnapInItemImpl::CreatePropertyPages  
 Este método implementa a função Win32 [IExtendPropertySheet::CreatePropertyPages](http://msdn.microsoft.com/library/aa814846).  
  
```
CreatePropertyPages(  
    LPPROPERTYSHEETCALLBACK lpProvider,
    long handle,
    IUnknown* pUnk,
    DATA_OBJECT_TYPES type);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpProvider*  
 [in] Ponteiro para o **IPropertySheetCallback** interface.  
  
 *Identificador*  
 [in] Especifica o identificador usado para rotear o **MMCN_PROPERTY_CHANGE** mensagem de notificação para a classe de dados apropriado.  
  
 *pUnk*  
 [in] Ponteiro para o **IExtendPropertySheet** interface no objeto que contém informações sobre o nó de contexto.  
  
 `type`  
 [in] Especifica o tipo de objeto. Ele pode ter um dos seguintes valores:  
  
- **CCT_SCOPE** o objeto de dados para o contexto do painel de escopo.  
  
- **CCT_RESULT** o objeto de dados para o contexto do painel de resultados.  
  
- **CCT_SNAPIN_MANAGER** o objeto de dados para o contexto do snap-in Gerenciador.  
  
- **CCT_UNINITIALIZED** o objeto de dados tem um tipo inválido.  
  
##  <a name="csnapinitemimpl"></a>CSnapInItemImpl::CSnapInItemImpl  
 Constrói um objeto `CSnapInItemImpl`.  
  
```
CSnapInItemImpl();
```  
  
##  <a name="filldata"></a>CSnapInItemImpl::FillData  
 Essa função é chamada para recuperar informações sobre o item.  
  
```
FillData(CLIPFORMAT cf, LPSTREAM pStream);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cf`  
 [in] O formato (texto, RTF ou rich text com itens OLE) da área de transferência.  
  
 `pStream`  
 [in] Um ponteiro para o fluxo que contém os dados do objeto.  
  
### <a name="remarks"></a>Comentários  
 Para implementar corretamente essa função, copie as informações corretas para o fluxo ( `pStream`), dependendo do formato da área de transferência indicado pelo `cf`.  
  
##  <a name="getresultviewtype"></a>CSnapInItemImpl::GetResultViewType  
 Chame essa função para recuperar o tipo da exibição do painel de resultados do snap-in do objeto.  
  
```
GetResultViewType(
    LPOLESTR* ppViewType,
    long* pViewOptions);
```  
  
### <a name="parameters"></a>Parâmetros  
 *ppViewType*  
 [out] Ponteiro para o endereço do tipo retornado de modo de exibição.  
  
 *pViewOptions*  
 [out] Ponteiro para o **MMC_VIEW_OPTIONS** enumeração, que fornece o console com opções especificadas pelo proprietário snap-in. Esse valor pode ser um dos seguintes:  
  
- **MMC_VIEW_OPTIONS_NOLISTVIEWS** = 0x00000001 informa o console para impedir a apresentar as opções de exibição de lista padrão no **exibição** menu. Permite que o snap-in exibir suas próprias exibições personalizadas somente no painel de exibição de resultados. Esse é o único sinalizador de opção definido no momento.  
  
- **MMC_VIEW_OPTIONS_NONE** = 0 permite as opções de exibição padrão.  
  
##  <a name="getscopepaneinfo"></a>CSnapInItemImpl::GetScopePaneInfo  
 Chame essa função para recuperar o **SCOPEDATAITEM** estrutura do snap-in.  
  
```
GetScopePaneInfo (SCOPEDATAITEM* pScopeDataItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pScopeDataItem*  
 [out] Um ponteiro para o **SCOPEDATAITEM** estrutura do `CSnapInItemImpl` objeto.  
  
##  <a name="getresultpaneinfo"></a>CSnapInItemImpl::GetResultPaneInfo  
 Chame essa função para recuperar o **RESULTDATAITEM** estrutura do snap-in.  
  
```
GetResultPaneInfo (RESULTDATAITEM* pResultDataItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pResultDataItem*  
 [out] Um ponteiro para o **RESULTDATAITEM** estrutura do `CSnapInItemImpl` objeto.  
  
##  <a name="m_bstrdisplayname"></a>CSnapInItemImpl::m_bstrDisplayName  
 Contém a cadeia de caracteres exibida para o item de nó.  
  
```
CComBSTR m_bstrDisplayName;
```  
  
##  <a name="m_scopedataitem"></a>CSnapInItemImpl::m_scopeDataItem  
 O `SCOPEDATAITEM` estrutura o snap-in do objeto de dados.  
  
```
SCOPEDATAITEM m_scopeDataItem;
```  
  
##  <a name="m_resultdataitem"></a>CSnapInItemImpl::m_resultDataItem  
 O [RESULTDATAITEM](http://msdn.microsoft.com/library/aa815165) estrutura o snap-in do objeto de dados.  
  
```
RESULTDATAITEM m_resultDataItem;
```  
  
##  <a name="notify"></a>CSnapInItemImpl::Notify  
 Chamado quando o objeto de snap-in é tratado pelo usuário.  
  
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
 `event`  
 [in] Identifica uma ação executada por um usuário. As notificações a seguir são possíveis:  
  
- **MMCN_ACTIVATE** enviado quando uma janela está sendo ativado e desativado.  
  
- **MMCN_ADD_IMAGES** enviados para adicionar imagens ao painel de resultados.  
  
- **MMCN_BTN_CLICK** enviado quando o usuário clica em um dos botões da barra de ferramentas.  
  
- **MMCN_CLICK** enviado quando um usuário clica em um botão do mouse em um item de exibição de lista.  
  
- **MMCN_DBLCLICK** enviado quando um usuário clicar duas vezes um botão do mouse em um item de exibição de lista.  
  
- **MMCN_DELETE** enviada para informar o snap-in que o objeto deve ser excluído.  
  
- **MMCN_EXPAND** enviado quando uma pasta precisa ser expandido ou contratado.  
  
- **MMCN_MINIMIZED** enviado quando uma janela é minimizado ou maximizado.  
  
- **MMCN_PROPERTY_CHANGE** enviado para notificar um objeto de snap-in que exibir o snap-in do objeto está prestes a ser alterada.  
  
- **MMCN_REMOVE_CHILDREN** enviado quando o snap-in deve excluir a subárvore inteira ele adicionado abaixo do nó especificado.  
  
- **MMCN_RENAME** enviados na primeira vez para consultar uma renomeação e a segunda vez para fazer a renomeação.  
  
- **MMCN_SELECT** enviado quando um item no painel de exibição de escopo ou resultado é selecionado.  
  
- **MMCN_SHOW** enviado quando um item de escopo é selecionado ou desmarcado pela primeira vez.  
  
- **MMCN_VIEW_CHANGE** enviado quando o snap-in pode atualizar todos os modos de exibição quando ocorre uma alteração.  
  
 `arg`  
 [in] Depende do tipo de notificação.  
  
 `param`  
 [in] Depende do tipo de notificação.  
  
 *pComponentData*  
 [out] Um ponteiro para o objeto que implementa **IComponentData**. Esse parâmetro é **nulo** se a notificação não está sendo encaminhada de **IComponentData::Notify**.  
  
 *pComponent*  
 [out] Um ponteiro para o objeto que implementa **IComponent**. Esse parâmetro é **nulo** se a notificação não está sendo encaminhada de **IComponent::Notify**.  
  
 `type`  
 [in] Especifica o tipo de objeto. Ele pode ter um dos seguintes valores:  
  
- **CCT_SCOPE** o objeto de dados para o contexto do painel de escopo.  
  
- **CCT_RESULT** o objeto de dados para o contexto do painel de resultados.  
  
- **CCT_SNAPIN_MANAGER** o objeto de dados para o contexto do snap-in Gerenciador.  
  
- **CCT_UNINITIALIZED** o objeto de dados tem um tipo inválido.  
  
##  <a name="querypagesfor"></a>CSnapInItemImpl::QueryPagesFor  
 Chamado para ver se o nó de snap-in dá suporte a páginas de propriedades.  
  
```
QueryPagesFor(DATA_OBJECT_TYPES type);
```  
  
##  <a name="setmenuinsertionflags"></a>CSnapInItemImpl::SetMenuInsertionFlags  
 Chame essa função para modificar os sinalizadores de inserção do menu, especificados por `pInsertionAllowed`, para o snap-in do objeto.  
  
```
void SetMenuInsertionFlags(  
    bool bBeforeInsertion,
    long* pInsertionAllowed);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bBeforeInsertion*  
 [in] Diferente de zero se a função deve ser chamada antes que os itens são adicionados ao menu de contexto; Caso contrário, 0.  
  
 `pInsertionAllowed`  
 [no, out] Identifica definidos pelo Microsoft Management Console MMC, item de menu pontos de inserção que podem ser usados. Isso pode ser uma combinação dos sinalizadores a seguir:  
  
- **CCM_INSERTIONALLOWED_TOP** itens podem ser inseridos na parte superior de um menu de contexto.  
  
- **CCM_INSERTIONALLOWED_NEW** itens podem ser inseridos no submenu criar novo.  
  
- **CCM_INSERTIONALLOWED_TASK** itens podem ser inseridos no submenu tarefas.  
  
- **CCM_INSERTIONALLOWED_VIEW** itens podem ser inseridos no menu de exibição da barra de ferramentas ou no submenu exibição do menu de contexto do painel de resultados.  
  
### <a name="remarks"></a>Comentários  
 Se você estiver desenvolvendo um snap-in primário, você pode redefinir qualquer um dos sinalizadores de inserção como uma maneira de restringir o tipo de itens de menu que pode adicionar uma extensão de terceiros. Por exemplo, o snap-in primário pode limpar o **CCM_INSERTIONALLOWED_NEW** sinalizador para impedir que as extensões de adicionar seus próprios criar novos itens de menu.  
  
 Você não deve tentar definir os bits em `pInsertionAllowed` que foram originalmente limpas. Versões futuras do MMC podem usar o bits não está definidos para que você não deve alterar bits que atualmente não definidos.  
  
##  <a name="settoolbarbuttoninfo"></a>CSnapInItemImpl::SetToolbarButtonInfo  
 Chame essa função para modificar qualquer estilo de botão da barra de ferramentas, do objeto snap-in, antes que a barra de ferramentas é criada.  
  
```
void SetToolbarButtonInfo(  
    UINT id,
    BYTE* fsState,
    BYTE* fsType);
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] A ID do botão da barra de ferramentas a ser definido.  
  
 `fsState`  
 [in] Os sinalizadores de estado do botão. Pode ser um ou mais destes procedimentos:  
  
- `TBSTATE_CHECKED`O botão tem o **TBSTYLE_CHECKED** de estilo e está sendo pressionado.  
  
- `TBSTATE_ENABLED`O botão aceita entrada do usuário. Um botão que não tenha esse estado não aceita entrada do usuário e ficará indisponível.  
  
- `TBSTATE_HIDDEN`O botão não estiver visível e não pode receber entrada do usuário.  
  
- `TBSTATE_INDETERMINATE`O botão ficará indisponível.  
  
- `TBSTATE_PRESSED`O botão está sendo pressionado.  
  
- `TBSTATE_WRAP`Uma quebra de linha segue o botão. O botão também deve ter o `TBSTATE_ENABLED`.  
  
 *fsType*  
 [in] Os sinalizadores de estado do botão. Pode ser um ou mais destes procedimentos:  
  
- `TBSTYLE_BUTTON`Cria um botão de ação padrão.  
  
- `TBSTYLE_CHECK`Cria um botão que alterna entre os estados pressionados e pressionado não cada vez que o usuário clica nele. O botão tem uma cor de plano de fundo diferente quando ele estiver no estado pressionado.  
  
- `TBSTYLE_CHECKGROUP`Cria um botão de seleção permanece pressionado até que o outro no grupo é pressionado.  
  
- `TBSTYLE_GROUP`Cria um botão que permanece pressionado até que o outro no grupo é pressionado.  
  
- `TBSTYLE_SEP`Cria um separador, fornecendo um pequeno intervalo entre grupos de botões. Um botão que possui este estilo não recebe entrada do usuário.  
  
##  <a name="updatemenustate"></a>CSnapInItemImpl::UpdateMenuState  
 Chame essa função para modificar um item de menu antes de ser inserido no menu de contexto do objeto snap-in.  
  
```
void UpdateMenuState(  
    UINT id,
    LPTSTR pBuf,
    UINT* flags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] A ID do item de menu a ser definido.  
  
 `pBuf`  
 [in] Um ponteiro para a cadeia de caracteres para o item de menu a ser atualizado.  
  
 `flags`  
 [in] Especifica os sinalizadores de estado novo. Isso pode ser uma combinação dos sinalizadores a seguir:  
  
- **MF_POPUP** Especifica que se trata de um submenu dentro do menu de contexto. Itens de menu, pontos de inserção e submenus adicionais podem ser adicionados para esse submenu usando seu **lCommandID** como seus **IInsertionPointID**.  
  
- **MF_BITMAP** e `MF_OWNERDRAW` esses sinalizadores não são permitidos e resultará em um valor de retorno de `E_INVALIDARG`.  
  
- **MF_SEPARATOR** desenha uma linha divisória horizontal. Somente **IContextMenuProvider** tem permissão para adicionar itens de menu com **MF_SEPARATOR** definido.  
  
- **MF_CHECKED** coloca uma marca de seleção ao lado do item de menu.  
  
- **MF_DISABLED** desabilita o item de menu para que ele não pode ser selecionado, mas o sinalizador não cinza.  
  
- `MF_ENABLED`Permite que o item de menu para que ele possa ser selecionado, a restauração do estado esmaecido.  
  
- **MF_GRAYED** desabilita o item de menu esmaecê-la para que ela não pode ser selecionada.  
  
- **MF_MENUBARBREAK** funciona como o **MF_MENUBREAK** sinalizador para uma barra de menus. Para um menu suspenso, submenu ou menu de atalho, a nova coluna é separada da coluna antiga por uma linha vertical.  
  
- **MF_MENUBREAK** coloca o item em uma nova linha (para uma barra de menus) ou em uma nova coluna (para um menu suspenso, submenu ou menu de atalho) sem separar colunas.  
  
- **MF_UNCHECKED** não coloque uma marca de seleção ao lado do item (padrão).  
  
 Os seguintes grupos de sinalizadores não podem ser usados juntos:  
  
- **MF_DISABLED**, `MF_ENABLED`, e **MF_GRAYED**.  
  
- **MF_MENUBARBREAK** e **MF_MENUBREAK**.  
  
- **MF_CHECKED** e **MF_UNCHECKED**.  
  
##  <a name="updatetoolbarbutton"></a>CSnapInItemImpl::UpdateToolbarButton  
 Chame essa função para modificar um botão de barra de ferramentas, do objeto snap-in, antes que ele seja exibido.  
  
```
BOOL UpdateToolbarButton(UINT id, BYTE fsState);
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 Especifica a identificação de botão do botão da barra de ferramentas a ser atualizado.  
  
 `fsState`  
 Especifica um estado de botão da barra de ferramentas. Se esse estado deve ser definido, retornar **TRUE**. Isso pode ser uma combinação dos sinalizadores a seguir:  
  
- **HABILITADO** botão aceita entrada do usuário. Um botão que não tenha esse estado não aceita entrada do usuário e ficará indisponível.  
  
- **VERIFICADO** o botão tem o **check** estilo e está sendo pressionado.  
  
- **OCULTO** o botão não estiver visível e não pode receber entrada do usuário.  
  
- **INDETERMINADA** o botão ficará indisponível.  
  
- **BUTTONPRESSED** o botão está sendo pressionado.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

