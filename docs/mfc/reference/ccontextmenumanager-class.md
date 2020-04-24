---
title: Classe CContextMenuManager
ms.date: 11/04/2016
f1_keywords:
- CContextMenuManager
- AFXCONTEXTMENUMANAGER/CContextMenuManager
- AFXCONTEXTMENUMANAGER/CContextMenuManager::CContextMenuManager
- AFXCONTEXTMENUMANAGER/CContextMenuManager::AddMenu
- AFXCONTEXTMENUMANAGER/CContextMenuManager::GetMenuById
- AFXCONTEXTMENUMANAGER/CContextMenuManager::GetMenuByName
- AFXCONTEXTMENUMANAGER/CContextMenuManager::GetMenuNames
- AFXCONTEXTMENUMANAGER/CContextMenuManager::LoadState
- AFXCONTEXTMENUMANAGER/CContextMenuManager::ResetState
- AFXCONTEXTMENUMANAGER/CContextMenuManager::SaveState
- AFXCONTEXTMENUMANAGER/CContextMenuManager::SetDontCloseActiveMenu
- AFXCONTEXTMENUMANAGER/CContextMenuManager::ShowPopupMenu
- AFXCONTEXTMENUMANAGER/CContextMenuManager::TrackPopupMenu
helpviewer_keywords:
- CContextMenuManager [MFC], CContextMenuManager
- CContextMenuManager [MFC], AddMenu
- CContextMenuManager [MFC], GetMenuById
- CContextMenuManager [MFC], GetMenuByName
- CContextMenuManager [MFC], GetMenuNames
- CContextMenuManager [MFC], LoadState
- CContextMenuManager [MFC], ResetState
- CContextMenuManager [MFC], SaveState
- CContextMenuManager [MFC], SetDontCloseActiveMenu
- CContextMenuManager [MFC], ShowPopupMenu
- CContextMenuManager [MFC], TrackPopupMenu
ms.assetid: 1de20640-243c-47e1-85de-1baa4153bc83
ms.openlocfilehash: c676355ebf44d6cc02bfa66ac870757627ae5a58
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754812"
---
# <a name="ccontextmenumanager-class"></a>Classe CContextMenuManager

O `CContextMenuManager` objeto gerencia menus de atalho, também conhecidos como menus de contexto.

## <a name="syntax"></a>Sintaxe

```
class CContextMenuManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CContextMenuManager::CContextMenuManager](#ccontextmenumanager)|Constrói um objeto `CContextMenuManager`.|
|`CContextMenuManager::~CContextMenuManager`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CContextMenumanager::AddMenu](#addmenu)|Adiciona um novo menu de atalho.|
|[CContextMenuManager::GetMenuById](#getmenubyid)|Retorna uma alça para o menu associado ao ID de recurso fornecido.|
|[CContextMenumanager::getmenubyname](#getmenubyname)|Retorna uma alça para o menu que corresponde ao nome do menu fornecido.|
|[CContextMenumanager::GetMenuNames](#getmenunames)|Retorna uma lista de nomes do menu.|
|[CContextMenuManager::LoadState](#loadstate)|Carrega menus de atalho armazenados no registro do Windows.|
|[CContextMenuManager::Reset'S](#resetstate)|Limpa os menus de atalho do gerenciador de menus de contexto.|
|[CContextMenuManager::SalvarEstado](#savestate)|Salva menus de atalho no registro do Windows.|
|[CContextMenuManager::SetDontCloseActiveMenu](#setdontcloseactivemenu)|Controla se `CContextMenuManager` o menu de atalho ativo fecha o menu de atalho ativo quando ele mostra um novo menu de atalho.|
|[CContextMenuManager::ShowPopupMenu](#showpopupmenu)|Exibe o menu de atalho especificado.|
|[CContextMenuManager::TrackPopupMenu](#trackpopupmenu)|Exibe o menu de atalho especificado. Retorna o índice do comando menu selecionado.|

## <a name="remarks"></a>Comentários

`CContextMenuManager`gerencia menus de atalho e garante que eles tenham uma aparência consistente.

Você não deve `CContextMenuManager` criar um objeto manualmente. A estrutura do seu `CContextMenuManager` aplicativo cria o objeto. No entanto, você deve ligar para [CWinAppEx::InitContextMenuManager](../../mfc/reference/cwinappex-class.md#initcontextmenumanager) quando seu aplicativo é inicializado. Depois de inicializar o gerenciador de contexto, use o método [CWinAppEx::GetContextMenuManager](../../mfc/reference/cwinappex-class.md#getcontextmenumanager) para obter um ponteiro para o gerenciador de contexto para o seu aplicativo.

Você pode criar menus de `AddMenu`atalho em tempo de execução chamando . Se você quiser mostrar o menu sem `ShowPopupMenu`antes receber a entrada do usuário, ligue . `TrackPopupMenu`é usado quando você deseja criar um menu e esperar pela entrada do usuário. `TrackPopupMenu`retorna o índice do comando selecionado ou 0 se o usuário sair sem selecionar nada.

O `CContextMenuManager` também pode salvar e carregar seu estado para o registro do Windows.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CContextMenuManager` adicionar um menu a um objeto e `CContextMenuManager` como não fechar o menu pop-up ativo quando o objeto exibir um novo menu pop-up. Este trecho de código faz parte da [amostra Páginas Personalizadas](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_CustomPages#4](../../mfc/reference/codesnippet/cpp/ccontextmenumanager-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CContextMenuManager`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcontextmenumanager.h

## <a name="ccontextmenumanageraddmenu"></a><a name="addmenu"></a>CContextMenumanager::AddMenu

Adiciona um novo menu de atalho ao [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md).

```
BOOL AddMenu(
    UINT uiMenuNameResId,
    UINT uiMenuResId);

BOOL AddMenu(
    LPCTSTR lpszName,
    UINT uiMenuResId);
```

### <a name="parameters"></a>Parâmetros

*uiMenuNameResId*<br/>
[em] Um ID de recurso para uma string que contém o nome do novo menu.

*uiMenuResId*<br/>
[em] O id de recurso do menu.

*lpszName*<br/>
[em] Uma seqüência que contém o nome do novo menu.

### <a name="return-value"></a>Valor retornado

Não zero se o método foi bem sucedido; 0 se o método falhar.

### <a name="remarks"></a>Comentários

Este método falha se *uiMenuResId* estiver inválido ou se outro `CContextMenuManager`menu com o mesmo nome já estiver no .

## <a name="ccontextmenumanagerccontextmenumanager"></a><a name="ccontextmenumanager"></a>CContextMenuManager::CContextMenuManager

Constrói um objeto [CContextMenuManager.](../../mfc/reference/ccontextmenumanager-class.md)

```
CContextMenuManager();
```

### <a name="remarks"></a>Comentários

Na maioria dos casos, `CContextMenuManager` você não deve criar uma manualmente. A estrutura do seu `CContextMenuManager` aplicativo cria o objeto. Você deve ligar para [CWinAppEx::InitContextMenuManager](../../mfc/reference/cwinappex-class.md#initcontextmenumanager) durante a inicialização do seu aplicativo. Para obter um ponteiro para o gerenciador de contexto, ligue para [CWinAppEx::GetContextMenuManager](../../mfc/reference/cwinappex-class.md#getcontextmenumanager).

## <a name="ccontextmenumanagergetmenubyid"></a><a name="getmenubyid"></a>CContextMenuManager::GetMenuById

Retorna uma alça para o menu associado a um determinado ID de recurso.

```
HMENU GetMenuById(UINT nMenuResId) const;
```

### <a name="parameters"></a>Parâmetros

*nMenuResId*<br/>
[em] O iD de recurso para o menu.

### <a name="return-value"></a>Valor retornado

Uma alça para o `NULL` menu associado ou se o menu não for encontrado.

## <a name="ccontextmenumanagergetmenubyname"></a><a name="getmenubyname"></a>CContextMenumanager::getmenubyname

Retorna uma alça para um menu específico.

```
HMENU GetMenuByName(
    LPCTSTR lpszName,
    UINT* puiOrigResID = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
[em] Uma seqüência que contém o nome do menu para recuperar.

*puiOrigResID*<br/>
[fora] Um ponteiro para um UINT. Este parâmetro contém o ID de recurso do menu especificado, se encontrado.

### <a name="return-value"></a>Valor retornado

Uma alça para o menu que corresponde ao nome que foi especificado por *lpszName*. NULL se não houver um menu chamado *lpszName*.

### <a name="remarks"></a>Comentários

Se este método encontrar um menu que `GetMenuByName` corresponda *ao lpszName,* armarei o ID de recurso do menu no parâmetro *puiOrigResID*.

## <a name="ccontextmenumanagergetmenunames"></a><a name="getmenunames"></a>CContextMenumanager::GetMenuNames

Retorna a lista de nomes de menu adicionados ao [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md).

```cpp
void GetMenuNames(CStringList& listOfNames) const;
```

### <a name="parameters"></a>Parâmetros

*listOfNames*<br/>
[fora] Uma referência a um parâmetro [CStringList.](../../mfc/reference/cstringlist-class.md) Este método escreve a lista de nomes de menu para este parâmetro.

## <a name="ccontextmenumanagerloadstate"></a><a name="loadstate"></a>CContextMenuManager::LoadState

Carrega informações associadas à [Classe CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md) do registro do Windows.

```
virtual BOOL LoadState(LPCTSTR lpszProfileName = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
[em] Uma seqüência que contém o caminho relativo de uma chave de registro.

### <a name="return-value"></a>Valor retornado

Não zero se o método for bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O parâmetro *lpszProfileName* não é o caminho absoluto para uma entrada de registro. É um caminho relativo que é adicionado ao fim da chave de registro padrão para o seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](../../mfc/reference/cwinappex-class.md#getregistrybase) e [CWinAppEx::SetRegistryBase,](../../mfc/reference/cwinappex-class.md#setregistrybase) respectivamente.

Use o método [CContextMenuManager::SaveState](#savestate) para salvar os menus de atalho no registro.

## <a name="ccontextmenumanagerresetstate"></a><a name="resetstate"></a>CContextMenuManager::Reset'S

Limpa todos os itens dos menus de atalho associados à [Classe CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md).

```
virtual BOOL ResetState();
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método for bem sucedido; FALSO se ocorrer uma falha.

### <a name="remarks"></a>Comentários

Este método limpa os menus pop-up e `CContextMenuManager`os remove do .

## <a name="ccontextmenumanagersavestate"></a><a name="savestate"></a>CContextMenuManager::SalvarEstado

Salva informações associadas à [Classe CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md) no registro do Windows.

```
virtual BOOL SaveState(LPCTSTR lpszProfileName = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
[em] Uma seqüência que contém o caminho relativo de uma chave de registro.

### <a name="return-value"></a>Valor retornado

Não zero se o método for bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O parâmetro *lpszProfileName* não é o caminho absoluto para uma entrada de registro. É um caminho relativo que é adicionado ao fim da chave de registro padrão para o seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](../../mfc/reference/cwinappex-class.md#getregistrybase) e [CWinAppEx::SetRegistryBase,](../../mfc/reference/cwinappex-class.md#setregistrybase) respectivamente.

Use o método [CContextMenuManager::LoadState](#loadstate) para carregar os menus de atalho do registro.

## <a name="ccontextmenumanagersetdontcloseactivemenu"></a><a name="setdontcloseactivemenu"></a>CContextMenuManager::SetDontCloseActiveMenu

Controla se o [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md) fecha o menu pop-up ativo quando exibe um novo menu pop-up.

```cpp
void SetDontCloseActiveMenu (BOOL bSet = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bSet*<br/>
[em] Um parâmetro booleano que controla se deve fechar o menu pop-up ativo. Um valor de TRUE indica que o menu pop-up ativo não está fechado. FALSE indica que o menu pop-up ativo está fechado.

### <a name="remarks"></a>Comentários

Por padrão, `CContextMenuManager` o menu pop-up ativo fecha.

## <a name="ccontextmenumanagershowpopupmenu"></a><a name="showpopupmenu"></a>CContextMenuManager::ShowPopupMenu

Exibe o menu de atalho especificado.

```
virtual BOOL ShowPopupMenu(
    UINT uiMenuResId,
    int x,
    int y,
    CWnd* pWndOwner,
    BOOL bOwnMessage = FALSE,
    BOOL bRightAlign = FALSE);

virtual CMFCPopupMenu* ShowPopupMenu(
    HMENU hmenuPopup,
    int x,
    int y,
    CWnd* pWndOwner,
    BOOL bOwnMessage = FALSE,
    BOOL bAutoDestroy = TRUE,
    BOOL bRightAlign = FALSE);
```

### <a name="parameters"></a>Parâmetros

*uiMenuResId*<br/>
[em] O ID de recurso do menu que este método exibirá.

*x*<br/>
[em] A compensação horizontal para o menu de atalho nas coordenadas do cliente.

*Y*<br/>
[em] A configuração vertical para o menu de atalho nas coordenadas do cliente

*pWndOwner*<br/>
[em] Um ponteiro para a janela pai do menu de atalho.

*Bownmessage*<br/>
[em] Um parâmetro booleano que indica como as mensagens são roteadas. Se *bOwnMessage* for FALSE, o roteamento Padrão do MFC será usado. Caso contrário, *pWndOwner* recebe as mensagens.

*hmenuPopup*<br/>
[em] A alça do menu que este método exibirá.

*bAutoDestroy*<br/>
[em] Um parâmetro booleano que indica se o menu será automaticamente destruído.

*bRightAlign*<br/>
[em] Um parâmetro booleano que indica como os itens do menu estão alinhados. Se *bRightAlign* for TRUE, o menu estará alinhado à direita para ordem de leitura da direita para a esquerda.

### <a name="return-value"></a>Valor retornado

A primeira sobrecarga de método retorna não zero se o método mostrar o menu com sucesso; caso contrário, 0. A segunda sobrecarga de método retorna um ponteiro ao [CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md) se o menu de atalho for exibido corretamente; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Este método se assemelha ao método [CContextMenuManager::TrackPopupMenu](#trackpopupmenu) no qual ambos os métodos exibem um menu de atalho. No `TrackPopupMenu` entanto, retorna o índice do comando menu selecionado.

Se o parâmetro *bAutoDestroy* for FALSE, você deve `DestroyMenu` chamar manualmente o método herdado para liberar recursos de memória. A implementação `ShowPopupMenu` padrão de não usa o parâmetro *bAutoDestroy*. É fornecido para uso futuro ou para classes `CContextMenuManager` personalizadas derivadas da classe .

## <a name="ccontextmenumanagertrackpopupmenu"></a><a name="trackpopupmenu"></a>CContextMenuManager::TrackPopupMenu

Exibe o menu de atalho especificado e retorna o índice do comando menu de atalho selecionado.

```
virtual UINT TrackPopupMenu(
    HMENU hmenuPopup,
    int x,
    int y,
    CWnd* pWndOwner,
    BOOL bRightAlign = FALSE);
```

### <a name="parameters"></a>Parâmetros

*hmenuPopup*<br/>
[em] A alça do menu de atalho que este método exibe.

*x*<br/>
[em] A compensação horizontal para o menu de atalho nas coordenadas do cliente.

*Y*<br/>
[em] O deslocamento vertical para o menu de atalho nas coordenadas do cliente.

*pWndOwner*<br/>
[em] Um ponteiro para a janela pai do menu de atalho.

*bRightAlign*<br/>
[em] Um parâmetro booleano que indica como os itens do menu estão alinhados. Se *bRightAlign* for TRUE, o menu estará alinhado à direita para ordem de leitura da direita para a esquerda. Se *bRightAlign* for FALSE, o menu estará alinhado à esquerda para a ordem de leitura da esquerda para a direita.

### <a name="return-value"></a>Valor retornado

O menu de comando ID do comando que o usuário escolhe; 0 se o usuário fechar o menu de atalho sem selecionar um comando de menu.

### <a name="remarks"></a>Comentários

Este método funciona como uma chamada modal para exibir um menu de atalho. O aplicativo não continuará com a seguinte linha de código até que o usuário feche o menu de atalho ou selecione um comando. Um método alternativo que você pode usar para exibir um menu de atalho é [CContextMenuManager::ShowPopupMenu](#showpopupmenu). Esse método não é uma chamada modal e não retornará o ID do comando selecionado.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe Cwinappex](../../mfc/reference/cwinappex-class.md)
