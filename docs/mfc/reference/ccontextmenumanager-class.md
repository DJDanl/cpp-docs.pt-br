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
ms.openlocfilehash: c8a51a33c69b09d0ecd61520b5f1c9ff18c290a0
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78868984"
---
# <a name="ccontextmenumanager-class"></a>Classe CContextMenuManager

O objeto `CContextMenuManager` gerencia menus de atalho, também conhecidos como menus de contexto.

## <a name="syntax"></a>Sintaxe

```
class CContextMenuManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CContextMenuManager::CContextMenuManager](#ccontextmenumanager)|Constrói um objeto `CContextMenuManager`.|
|`CContextMenuManager::~CContextMenuManager`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CContextMenuManager:: AddMenu](#addmenu)|Adiciona um novo menu de atalho.|
|[CContextMenuManager::GetMenuById](#getmenubyid)|Retorna um identificador para o menu associado à ID de recurso fornecida.|
|[CContextMenuManager::GetMenuByName](#getmenubyname)|Retorna um identificador para o menu que corresponde ao nome de menu fornecido.|
|[CContextMenuManager:: getmenunames](#getmenunames)|Retorna uma lista de nomes de menu.|
|[CContextMenuManager:: LoadState](#loadstate)|Carrega menus de atalho armazenados no registro do Windows.|
|[CContextMenuManager:: ResetState](#resetstate)|Limpa os menus de atalho no Gerenciador do menu de contexto.|
|[CContextMenuManager:: SaveState](#savestate)|Salva os menus de atalho no registro do Windows.|
|[CContextMenuManager::SetDontCloseActiveMenu](#setdontcloseactivemenu)|Controla se o `CContextMenuManager` fecha o menu de atalho ativo quando ele mostra um novo menu de atalho.|
|[CContextMenuManager::ShowPopupMenu](#showpopupmenu)|Exibe o menu de atalho especificado.|
|[CContextMenuManager::TrackPopupMenu](#trackpopupmenu)|Exibe o menu de atalho especificado. Retorna o índice do comando de menu selecionado.|

## <a name="remarks"></a>Comentários

o `CContextMenuManager` gerencia menus de atalho e garante que eles tenham uma aparência consistente.

Você não deve criar um objeto `CContextMenuManager` manualmente. A estrutura do seu aplicativo cria o objeto `CContextMenuManager`. No entanto, você deve chamar [CWinAppEx:: InitContextMenuManager](../../mfc/reference/cwinappex-class.md#initcontextmenumanager) quando seu aplicativo for inicializado. Depois de inicializar o Gerenciador de contexto, use o método [CWinAppEx:: GetContextMenuManager](../../mfc/reference/cwinappex-class.md#getcontextmenumanager) para obter um ponteiro para o Gerenciador de contexto do seu aplicativo.

Você pode criar menus de atalho em tempo de execução chamando `AddMenu`. Se você quiser mostrar o menu sem primeiro receber a entrada do usuário, chame `ShowPopupMenu`. `TrackPopupMenu` é usado quando você deseja criar um menu e aguardar a entrada do usuário. `TrackPopupMenu` retorna o índice do comando selecionado ou 0 se o usuário saiu sem selecionar nada.

O `CContextMenuManager` também pode salvar e carregar seu estado no registro do Windows.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como adicionar um menu a um objeto `CContextMenuManager` e como não fechar o menu pop-up ativo quando o objeto `CContextMenuManager` exibe um novo menu pop-up. Este trecho de código faz parte do [exemplo de páginas personalizadas](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_CustomPages#4](../../mfc/reference/codesnippet/cpp/ccontextmenumanager-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CContextMenuManager`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcontextmenumanager. h

##  <a name="addmenu"></a>CContextMenuManager:: AddMenu

Adiciona um novo menu de atalho ao [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md).

```
BOOL AddMenu(
    UINT uiMenuNameResId,
    UINT uiMenuResId);

BOOL AddMenu(
    LPCTSTR lpszName,
    UINT uiMenuResId);
```

### <a name="parameters"></a>parâmetros

*uiMenuNameResId*<br/>
no Uma ID de recurso para uma cadeia de caracteres que contém o nome do novo menu.

*uiMenuResId*<br/>
no A ID de recurso do menu.

*lpszName*<br/>
no Uma cadeia de caracteres que contém o nome do novo menu.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o método foi bem-sucedido; 0 se o método falhar.

### <a name="remarks"></a>Comentários

Esse método falhará se *uiMenuResId* for inválido ou se outro menu com o mesmo nome já estiver na `CContextMenuManager`.

##  <a name="ccontextmenumanager"></a>CContextMenuManager::CContextMenuManager

Constrói um objeto [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md) .

```
CContextMenuManager();
```

### <a name="remarks"></a>Comentários

Na maioria dos casos, você não deve criar um `CContextMenuManager` manualmente. A estrutura do seu aplicativo cria o objeto `CContextMenuManager`. Você deve chamar [CWinAppEx:: InitContextMenuManager](../../mfc/reference/cwinappex-class.md#initcontextmenumanager) durante a inicialização do seu aplicativo. Para obter um ponteiro para o Gerenciador de contexto, chame [CWinAppEx:: GetContextMenuManager](../../mfc/reference/cwinappex-class.md#getcontextmenumanager).

##  <a name="getmenubyid"></a>CContextMenuManager::GetMenuById

Retorna um identificador para o menu associado a uma determinada ID de recurso.

```
HMENU GetMenuById(UINT nMenuResId) const;
```

### <a name="parameters"></a>parâmetros

*nMenuResId*<br/>
no A ID do recurso do menu.

### <a name="return-value"></a>Valor retornado

Um identificador para o menu ou `NULL` associado se o menu não for encontrado.

##  <a name="getmenubyname"></a>CContextMenuManager::GetMenuByName

Retorna um identificador para um menu específico.

```
HMENU GetMenuByName(
    LPCTSTR lpszName,
    UINT* puiOrigResID = NULL) const;
```

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
no Uma cadeia de caracteres que contém o nome do menu a ser recuperado.

*puiOrigResID*<br/>
fora Um ponteiro para um UINT. Esse parâmetro contém a ID de recurso do menu especificado, se encontrada.

### <a name="return-value"></a>Valor retornado

Um identificador para o menu que corresponde ao nome especificado por *lpszName*. NULL se não houver nenhum menu chamado *lpszName*.

### <a name="remarks"></a>Comentários

Se esse método encontrar um menu que corresponda a *lpszName*, `GetMenuByName` armazenará a ID de recurso de menu no parâmetro *puiOrigResID*.

##  <a name="getmenunames"></a>CContextMenuManager:: getmenunames

Retorna a lista de nomes de menu adicionados ao [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md).

```
void GetMenuNames(CStringList& listOfNames) const;
```

### <a name="parameters"></a>parâmetros

*listOfNames*<br/>
fora Uma referência a um parâmetro [CStringList](../../mfc/reference/cstringlist-class.md) . Esse método grava a lista de nomes de menu para esse parâmetro.

##  <a name="loadstate"></a>CContextMenuManager:: LoadState

Carrega informações associadas à [classe CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md) do registro do Windows.

```
virtual BOOL LoadState(LPCTSTR lpszProfileName = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszProfileName*<br/>
no Uma cadeia de caracteres que contém o caminho relativo de uma chave do registro.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o método for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O parâmetro *lpszProfileName* não é o caminho absoluto para uma entrada de registro. É um caminho relativo que é adicionado ao final da chave do registro padrão para seu aplicativo. Para obter ou definir a chave do registro padrão, use os métodos [CWinAppEx:: GetRegistryBase](../../mfc/reference/cwinappex-class.md#getregistrybase) e [CWinAppEx:: SetRegistryBase](../../mfc/reference/cwinappex-class.md#setregistrybase) , respectivamente.

Use o método [CContextMenuManager:: SaveState](#savestate) para salvar os menus de atalho no registro.

##  <a name="resetstate"></a>CContextMenuManager:: ResetState

Limpa todos os itens dos menus de atalho associados à [classe CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md).

```
virtual BOOL ResetState();
```

### <a name="return-value"></a>Valor retornado

TRUE se o método for bem-sucedido; FALSE se ocorrer uma falha.

### <a name="remarks"></a>Comentários

Esse método limpa os menus pop-up e os remove da `CContextMenuManager`.

##  <a name="savestate"></a>CContextMenuManager:: SaveState

Salva as informações associadas à [classe CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md) no registro do Windows.

```
virtual BOOL SaveState(LPCTSTR lpszProfileName = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszProfileName*<br/>
no Uma cadeia de caracteres que contém o caminho relativo de uma chave do registro.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o método for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O parâmetro *lpszProfileName* não é o caminho absoluto para uma entrada de registro. É um caminho relativo que é adicionado ao final da chave do registro padrão para seu aplicativo. Para obter ou definir a chave do registro padrão, use os métodos [CWinAppEx:: GetRegistryBase](../../mfc/reference/cwinappex-class.md#getregistrybase) e [CWinAppEx:: SetRegistryBase](../../mfc/reference/cwinappex-class.md#setregistrybase) , respectivamente.

Use o método [CContextMenuManager:: LoadState](#loadstate) para carregar os menus de atalho do registro.

##  <a name="setdontcloseactivemenu"></a>CContextMenuManager::SetDontCloseActiveMenu

Controla se o [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md) fecha o menu pop-up ativo quando ele exibe um novo menu pop-up.

```
void SetDontCloseActiveMenu (BOOL bSet = TRUE);
```

### <a name="parameters"></a>parâmetros

*bSet*<br/>
no Um parâmetro booliano que controla se o menu pop-up ativo deve ser fechado. Um valor TRUE indica que o menu pop-up ativo não está fechado. FALSO indica que o menu pop-up ativo está fechado.

### <a name="remarks"></a>Comentários

Por padrão, o `CContextMenuManager` fecha o menu pop-up ativo.

##  <a name="showpopupmenu"></a>CContextMenuManager::ShowPopupMenu

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

### <a name="parameters"></a>parâmetros

*uiMenuResId*<br/>
no A ID de recurso do menu que será exibido neste método.

*x*<br/>
no O deslocamento horizontal do menu de atalho nas coordenadas do cliente.

*y*<br/>
no O deslocamento vertical do menu de atalho nas coordenadas do cliente

*pWndOwner*<br/>
no Um ponteiro para a janela pai do menu de atalho.

*bOwnMessage*<br/>
no Um parâmetro booliano que indica como as mensagens são roteadas. Se *bOwnMessage* for false, o roteamento padrão do MFC será usado. Caso contrário, o *pWndOwner* receberá as mensagens.

*hmenuPopup*<br/>
no O identificador do menu que será exibido neste método.

*bAutoDestroy*<br/>
no Um parâmetro booliano que indica se o menu será destruído automaticamente.

*bRightAlign*<br/>
no Um parâmetro booliano que indica como os itens de menu são alinhados. Se *bRightAlign* for true, o menu será alinhado à direita para a ordem de leitura da direita para a esquerda.

### <a name="return-value"></a>Valor retornado

A sobrecarga do primeiro método retornará zero se o método mostrar o menu com êxito; caso contrário, 0. A sobrecarga do segundo método retornará um ponteiro para [CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md) se o menu de atalho for exibido corretamente; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Esse método é semelhante ao método [CContextMenuManager:: TrackPopupMenu](#trackpopupmenu) , pois ambos os métodos exibem um menu de atalho. No entanto, `TrackPopupMenu` retorna o índice do comando de menu selecionado.

Se o parâmetro *bAutoDestroy* for false, você deverá chamar manualmente o método herdado `DestroyMenu` para liberar recursos de memória. A implementação padrão de `ShowPopupMenu` não usa o parâmetro *bAutoDestroy*. Ele é fornecido para uso futuro ou para classes personalizadas derivadas da classe `CContextMenuManager`.

##  <a name="trackpopupmenu"></a>CContextMenuManager::TrackPopupMenu

Exibe o menu de atalho especificado e retorna o índice do comando de menu de atalho selecionado.

```
virtual UINT TrackPopupMenu(
    HMENU hmenuPopup,
    int x,
    int y,
    CWnd* pWndOwner,
    BOOL bRightAlign = FALSE);
```

### <a name="parameters"></a>parâmetros

*hmenuPopup*<br/>
no O identificador do menu de atalho que esse método exibe.

*x*<br/>
no O deslocamento horizontal do menu de atalho nas coordenadas do cliente.

*y*<br/>
no O deslocamento vertical do menu de atalho nas coordenadas do cliente.

*pWndOwner*<br/>
no Um ponteiro para a janela pai do menu de atalho.

*bRightAlign*<br/>
no Um parâmetro booliano que indica como os itens de menu são alinhados. Se *bRightAlign* for true, o menu será alinhado à direita para a ordem de leitura da direita para a esquerda. Se *bRightAlign* for false, o menu será alinhado à esquerda para a ordem de leitura da esquerda para a direita.

### <a name="return-value"></a>Valor retornado

A ID de comando de menu do comando escolhido pelo usuário; 0 se o usuário fechar o menu de atalho sem selecionar um comando de menu.

### <a name="remarks"></a>Comentários

Esse método funciona como uma chamada modal para exibir um menu de atalho. O aplicativo não continuará na linha a seguir no código até que o usuário feche o menu de atalho ou selecione um comando. Um método alternativo que você pode usar para exibir um menu de atalho é [CContextMenuManager:: ShowPopupMenu](#showpopupmenu). Esse método não é uma chamada modal e não retornará a ID do comando selecionado.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CWinAppEx](../../mfc/reference/cwinappex-class.md)
