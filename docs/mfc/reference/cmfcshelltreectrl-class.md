---
title: Classe CMFCShellTreeCtrl
ms.date: 11/04/2016
f1_keywords:
- CMFCShellTreeCtrl
- AFXSHELLTREECTRL/CMFCShellTreeCtrl
- AFXSHELLTREECTRL/CMFCShellTreeCtrl::EnableShellContextMenu
- AFXSHELLTREECTRL/CMFCShellTreeCtrl::GetFlags
- AFXSHELLTREECTRL/CMFCShellTreeCtrl::GetItemPath
- AFXSHELLTREECTRL/CMFCShellTreeCtrl::GetRelatedList
- AFXSHELLTREECTRL/CMFCShellTreeCtrl::OnChildNotify
- AFXSHELLTREECTRL/CMFCShellTreeCtrl::OnGetItemIcon
- AFXSHELLTREECTRL/CMFCShellTreeCtrl::OnGetItemText
- AFXSHELLTREECTRL/CMFCShellTreeCtrl::Refresh
- AFXSHELLTREECTRL/CMFCShellTreeCtrl::SelectPath
- AFXSHELLTREECTRL/CMFCShellTreeCtrl::SetFlags
- AFXSHELLTREECTRL/CMFCShellTreeCtrl::SetRelatedList
helpviewer_keywords:
- CMFCShellTreeCtrl [MFC], EnableShellContextMenu
- CMFCShellTreeCtrl [MFC], GetFlags
- CMFCShellTreeCtrl [MFC], GetItemPath
- CMFCShellTreeCtrl [MFC], GetRelatedList
- CMFCShellTreeCtrl [MFC], OnChildNotify
- CMFCShellTreeCtrl [MFC], OnGetItemIcon
- CMFCShellTreeCtrl [MFC], OnGetItemText
- CMFCShellTreeCtrl [MFC], Refresh
- CMFCShellTreeCtrl [MFC], SelectPath
- CMFCShellTreeCtrl [MFC], SetFlags
- CMFCShellTreeCtrl [MFC], SetRelatedList
ms.assetid: 3d1da715-9554-4ed7-968c-055c48146267
ms.openlocfilehash: c6f5856e92c2aca1d23ee6a37b99ea9700ea6db0
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753446"
---
# <a name="cmfcshelltreectrl-class"></a>Classe CMFCShellTreeCtrl

A `CMFCShellTreeCtrl` classe amplia a funcionalidade [da Classe CTreeCtrl](../../mfc/reference/ctreectrl-class.md) exibindo uma hierarquia de itens Shell.

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMFCShellTreeCtrl : public CTreeCtrl
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCShellTreeCtrl::EnableShellContextMenu](#enableshellcontextmenu)|Ativa ou desativa o menu de atalho.|
|[CMFCShellTreeCtrl::GetFlags](#getflags)|Retorna uma combinação de sinalizadores que são passados para [IShellFolder::EnumObjects](/windows/win32/api/shobjidl_core/nf-shobjidl_core-ishellfolder-enumobjects).|
|[CMFCShellTreeCtrl::GetItemPath](#getitempath)|Recupera o caminho para um item.|
|[CMFCShellTreeCtrl::GetRelatedList](#getrelatedlist)|Retorna um ponteiro para o objeto [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) `CMFCShellTreeCtrl` Class que é usado em conjunto com este objeto para criar uma janela semelhante ao Explorer.|
|[CMFCShellTreeCtrl::OnChildNotificar](#onchildnotify)|Essa função de membro é chamada pela janela pai desta janela quando recebe uma mensagem de notificação que se aplica a essa janela. (Substitui [cwnd::OnChildNotificar](../../mfc/reference/cwnd-class.md#onchildnotify).)|
|[CMFCShellTreeCtrl::OnGetItemIcon](#ongetitemicon)||
|[CMFCShellTreeCtrl::OnGetItemText](#ongetitemtext)||
|[CMFCShellTreeCtrl::Atualização](#refresh)|Atualiza e repinta o `CMFCShellTreeCtrl` objeto atual.|
|[CMFCShellTreeCtrl::SelectPath](#selectpath)|Seleciona o item de controle de árvore apropriado com base em um PIDL ou caminho de string fornecidos.|
|[CMFCShellTreeCtrl::SetFlags](#setflags)|Define bandeiras para filtrar o contexto `IShellFolder::EnumObjects`da árvore (semelhante às bandeiras usadas por ).|
|[CMFCShellTreeCtrl::SetRelatedList](#setrelatedlist)|Define uma relação `CMFCShellTreeCtrl` entre o `CMFCShellListCtrl` objeto atual e um objeto.|

## <a name="remarks"></a>Comentários

Esta classe `CTreeCtrl` estende a classe permitindo que seu programa inclua itens do Windows Shell na árvore. Esta classe pode ser `CMFCShellListCtrl` associada a um objeto para criar uma janela explorer completa. Em seguida, a seleção de um item na árvore exibirá uma lista de itens do Windows Shell na lista associada.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CTreeCtrl](../../mfc/reference/ctreectrl-class.md)

`CMFCShellTreeCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxshelltreeCtrl.h

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCShellTreeCtrl` criar um objeto da classe. Este trecho de código faz parte da [amostra do Explorer](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_Explorer#4](../../mfc/reference/codesnippet/cpp/cmfcshelltreectrl-class_1.h)]
[!code-cpp[NVC_MFC_Explorer#5](../../mfc/reference/codesnippet/cpp/cmfcshelltreectrl-class_2.cpp)]

## <a name="cmfcshelltreectrlenableshellcontextmenu"></a><a name="enableshellcontextmenu"></a>CMFCShellTreeCtrl::EnableShellContextMenu

Habilita o menu de atalho.

```cpp
void EnableShellContextMenu(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] Um booleano que especifica se deve ativar o menu de atalho.

## <a name="cmfcshelltreectrlgetflags"></a><a name="getflags"></a>CMFCShellTreeCtrl::GetFlags

Retorna as bandeiras definidas para o objeto [CMFCShellTreeCtrl Class.](../../mfc/reference/cmfcshelltreectrl-class.md)

```
DWORD GetFlags() const;
```

### <a name="return-value"></a>Valor retornado

Um valor DWORD que especifica a combinação de sinalizadores atualmente definidos.

### <a name="remarks"></a>Comentários

Os sinalizadores `CMFCShellTreeCtrl` definidos no local são enviados para o método [IShellFolder::EnumObjects](/windows/win32/api/shobjidl_core/nf-shobjidl_core-ishellfolder-enumobjects) sempre que o objeto é atualizado. Você pode alterar as bandeiras com o método [CMFCShellTreeCtrl::SetFlags.](#setflags)

## <a name="cmfcshelltreectrlgetitempath"></a><a name="getitempath"></a>CMFCShellTreeCtrl::GetItemPath

Recupera o caminho de um item no objeto [CMFCShellTreeCtrl Class.](../../mfc/reference/cmfcshelltreectrl-class.md)

```
BOOL GetItemPath(
    CString& strPath,
    HTREEITEM htreeItem = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*strPath*<br/>
[fora] Uma referência a um parâmetro de seqüência. O método escreve o caminho do item para este parâmetro.

*Htreeitem*<br/>
[em] O método recupera o caminho para este item de controle de árvore.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; 0 caso contrário.

### <a name="remarks"></a>Comentários

Se este método falhar, *o strPath* contém a seqüência de string vazia.

Se você não especificar *hTreeItem,* este método tentará obter a seqüência para o item selecionado no momento. Se nenhum item for selecionado e *hTreeItem* for NULL, este método falhará.

## <a name="cmfcshelltreectrlgetrelatedlist"></a><a name="getrelatedlist"></a>CMFCShellTreeCtrl::GetRelatedList

Retorna um ponteiro para o objeto [CMFCShellListCtrl Class](../../mfc/reference/cmfcshelllistctrl-class.md) que está associado a este objeto [CMFCShellTreeCtrl.](../../mfc/reference/cmfcshelltreectrl-class.md)

```
CMFCShellListCtrl* GetRelatedList() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `CMFCShellListCtrl` para o objeto que está associado a este objeto de controle de árvore.

### <a name="remarks"></a>Comentários

Usando um `CMFCShellListCtrl` objeto junto `CMFCShellTreeCtrl` com um objeto, você pode criar uma janela semelhante ao Explorer. Use o método [CMFCShellTreeCtrl::SetRelatedList](#setrelatedlist) para associar as duas classes. Depois que eles são associados, o `CMFCShellListCtrl` framework atualiza `CMFCShellTreeCtrl` automaticamente o se a seleção nas alterações.

## <a name="cmfcshelltreectrlonchildnotify"></a><a name="onchildnotify"></a>CMFCShellTreeCtrl::OnChildNotificar

```
virtual BOOL OnChildNotify(
    UINT message,
    WPARAM wParam,
    LPARAM lParam,
    LRESULT* pLResult);
```

### <a name="parameters"></a>Parâmetros

[em] *mensagem*<br/>
[em] *wParam*<br/>
[em] *IParam*<br/>
[em] *pLResult*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcshelltreectrlongetitemicon"></a><a name="ongetitemicon"></a>CMFCShellTreeCtrl::OnGetItemIcon

```
virtual int OnGetItemIcon(
    LPAFX_SHELLITEMINFO pItem,
    BOOL bSelected);
```

### <a name="parameters"></a>Parâmetros

[em] *pItem*<br/>
[em] *bSelecionado*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcshelltreectrlongetitemtext"></a><a name="ongetitemtext"></a>CMFCShellTreeCtrl::OnGetItemText

```
virtual CString OnGetItemText(LPAFX_SHELLITEMINFO pItem);
```

### <a name="parameters"></a>Parâmetros

[em] *pItem*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcshelltreectrlrefresh"></a><a name="refresh"></a>CMFCShellTreeCtrl::Atualização

Atualiza e repinta o [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md).

```cpp
void Refresh();
```

### <a name="remarks"></a>Comentários

Chame este método para atualizar a hierarquia dos itens `CMFCShellTreeCtrl`exibidos no .

## <a name="cmfcshelltreectrlselectpath"></a><a name="selectpath"></a>CMFCShellTreeCtrl::SelectPath

Seleciona um item na [classe CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) com base no caminho fornecido.

```
BOOL SelectPath(LPCTSTR lpszPath);
BOOL SelectPath(LPCITEMIDLIST lpidl);
```

### <a name="parameters"></a>Parâmetros

*lpszPath*<br/>
[em] Uma seqüência que especifica o caminho de um item.

*Rio Ipidl*<br/>
[em] Um PIDL que especifica o item

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; E_FAIL o contrário.

## <a name="cmfcshelltreectrlsetflags"></a><a name="setflags"></a>CMFCShellTreeCtrl::SetFlags

Define bandeiras para filtrar o contexto da árvore.

```cpp
void SetFlags(
    DWORD dwFlags,
    BOOL bRefresh = TRUE);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
[em] As bandeiras para definir.

*bRefresh*<br/>
[em] Um booleano que `CMFCShellTreeCtrl` especifica se o deve ser atualizado imediatamente.

### <a name="remarks"></a>Comentários

O `CMFCShellTreeCtrl` passe todas as bandeiras definidas para [IShellFolder::EnumObjects](/windows/win32/api/shobjidl_core/nf-shobjidl_core-ishellfolder-enumobjects). Para obter mais informações sobre os valores de diferentes sinalizadores, consulte [IShellFolder::EnumObjects](/windows/win32/api/shobjidl_core/nf-shobjidl_core-ishellfolder-enumobjects).

## <a name="cmfcshelltreectrlsetrelatedlist"></a><a name="setrelatedlist"></a>CMFCShellTreeCtrl::SetRelatedList

Associa um objeto [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) com um objeto [CMFCShellTreeCtrl.](../../mfc/reference/cmfcshelltreectrl-class.md)

```cpp
void SetRelatedList(CMFCShellListCtrl* pShellList);
```

### <a name="parameters"></a>Parâmetros

*pShellList*<br/>
[em] Um ponteiro `CMFCShellListCtrl` para um objeto.

### <a name="remarks"></a>Comentários

Este método `CMFCShellListCtrl` associa `CMFCShellTreeCtrl`a com a . Esses objetos podem ser exibidos como uma janela semelhante ao `CMFCShellTreeCtrl`Explorer: se o usuário `CMFCShellListCtrl` selecionar um objeto no , os itens associados no serão atualizados automaticamente.

Use o método [CMFCShellTreeCtrl::GetRelatedList](#getrelatedlist) para recuperar o `CMFCShellListCtrl` associado a um `CMFCShellTreeCtrl`.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CTreeCtrl](../../mfc/reference/ctreectrl-class.md)<br/>
[Classe CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md)
