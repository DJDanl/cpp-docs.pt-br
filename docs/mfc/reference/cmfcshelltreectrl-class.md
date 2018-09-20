---
title: Classe CMFCShellTreeCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 038cd1caa1dcac3c2af406f9ca770a2220c9e013
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46423294"
---
# <a name="cmfcshelltreectrl-class"></a>Classe CMFCShellTreeCtrl

O `CMFCShellTreeCtrl` classe estende [classe CTreeCtrl](../../mfc/reference/ctreectrl-class.md) funcionalidade exibindo uma hierarquia de itens de Shell.

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.
## <a name="syntax"></a>Sintaxe

```
class CMFCShellTreeCtrl : public CTreeCtrl
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCShellTreeCtrl::EnableShellContextMenu](#enableshellcontextmenu)|Habilita ou desabilita o menu de atalho.|
|[CMFCShellTreeCtrl::GetFlags](#getflags)|Retorna uma combinação de sinalizadores que são passados para [IShellFolder::EnumObjects](https://msdn.microsoft.com/library/windows/desktop/bb775066).|
|[CMFCShellTreeCtrl::GetItemPath](#getitempath)|Recupera o caminho para um item.|
|[CMFCShellTreeCtrl::GetRelatedList](#getrelatedlist)|Retorna um ponteiro para o [classe CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto que é usado junto com isso `CMFCShellTreeCtrl` objeto para criar uma janela semelhante ao Explorer.|
|[CMFCShellTreeCtrl::OnChildNotify](#onchildnotify)|Essa função membro é chamada pela janela pai desta janela quando recebe uma mensagem de notificação que se aplica a esta janela. (Substitui [CWnd::OnChildNotify](../../mfc/reference/cwnd-class.md#onchildnotify).)|
|[CMFCShellTreeCtrl::OnGetItemIcon](#ongetitemicon)||
|[CMFCShellTreeCtrl::OnGetItemText](#ongetitemtext)||
|[CMFCShellTreeCtrl::Refresh](#refresh)|Atualiza e redesenha atual `CMFCShellTreeCtrl` objeto.|
|[CMFCShellTreeCtrl::SelectPath](#selectpath)|Seleciona o item de controle de árvore apropriada com base em um caminho de cadeia de caracteres ou PIDL fornecido.|
|[CMFCShellTreeCtrl::SetFlags](#setflags)|Define os sinalizadores para o contexto da árvore de filtro (semelhante aos sinalizadores usados pelos `IShellFolder::EnumObjects`).|
|[CMFCShellTreeCtrl::SetRelatedList](#setrelatedlist)|Define uma relação entre o atual `CMFCShellTreeCtrl` objeto e um `CMFCShellListCtrl` objeto.|

## <a name="remarks"></a>Comentários

Essa classe estende a `CTreeCtrl` classe, permitindo que seu programa incluir itens de Shell do Windows na árvore. Essa classe pode ser associada com um `CMFCShellListCtrl` objeto para criar uma janela do Explorer completa. Em seguida, selecionando um item na árvore exibirá uma lista de itens de Shell do Windows na lista associada.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CTreeCtrl](../../mfc/reference/ctreectrl-class.md)

`CMFCShellTreeCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxshelltreeCtrl.h

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar um objeto do `CMFCShellTreeCtrl` classe. Este trecho de código faz parte de [amostra do Gerenciador de](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_Explorer#4](../../mfc/reference/codesnippet/cpp/cmfcshelltreectrl-class_1.h)]
[!code-cpp[NVC_MFC_Explorer#5](../../mfc/reference/codesnippet/cpp/cmfcshelltreectrl-class_2.cpp)]

##  <a name="enableshellcontextmenu"></a>  CMFCShellTreeCtrl::EnableShellContextMenu

Permite que o menu de atalho.

```
void EnableShellContextMenu(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
[in] Um booliano que especifica se deseja habilitar o menu de atalho.

##  <a name="getflags"></a>  CMFCShellTreeCtrl::GetFlags

Retorna os sinalizadores definidos para o [classe CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) objeto.

```
DWORD GetFlags() const;
```

### <a name="return-value"></a>Valor de retorno

Defina um valor DWORD que especifica a combinação de sinalizadores no momento.

### <a name="remarks"></a>Comentários

Os sinalizadores definidos `CMFCShellTreeCtrl` são enviados para o método [IShellFolder::EnumObjects](https://msdn.microsoft.com/library/windows/desktop/bb775066) sempre que o objeto é atualizado. Você pode alterar os sinalizadores com os [CMFCShellTreeCtrl::SetFlags](#setflags) método.

##  <a name="getitempath"></a>  CMFCShellTreeCtrl::GetItemPath

Recupera o caminho de um item na [classe CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) objeto.

```
BOOL GetItemPath(
    CString& strPath,
    HTREEITEM htreeItem = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*strPath*<br/>
[out] Uma referência a um parâmetro de cadeia de caracteres. O método grava o caminho do item para esse parâmetro.

*htreeItem*<br/>
[in] O método recupera o caminho para este item de controle de árvore.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se esse método falhar, *strPath* contém a cadeia de caracteres vazia.

Se você não especificar *hTreeItem*, esse método tenta obter a cadeia de caracteres para o item selecionado no momento. Se nenhum item está selecionado e *hTreeItem* for NULL, esse método falhar.

##  <a name="getrelatedlist"></a>  CMFCShellTreeCtrl::GetRelatedList

Retorna um ponteiro para o [classe CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) objeto está associado a este [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) objeto.

```
CMFCShellListCtrl* GetRelatedList() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `CMFCShellListCtrl` objeto que está associado este objeto de controle de árvore.

### <a name="remarks"></a>Comentários

Usando um `CMFCShellListCtrl` do objeto junto com um `CMFCShellTreeCtrl` do objeto, você pode criar uma janela semelhante ao Explorer. Use o método [CMFCShellTreeCtrl::SetRelatedList](#setrelatedlist) para associar as duas classes. Depois que eles são associados, o framework atualiza automaticamente a `CMFCShellListCtrl` se a seleção no `CMFCShellTreeCtrl` alterações.

##  <a name="onchildnotify"></a>  CMFCShellTreeCtrl::OnChildNotify


```
virtual BOOL OnChildNotify(
    UINT message,
    WPARAM wParam,
    LPARAM lParam,
    LRESULT* pLResult);
```

### <a name="parameters"></a>Parâmetros

*message*<br/>
[in] [in] *wParam*
*lParam*<br/>
[in] [in] *pLResult*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="ongetitemicon"></a>  CMFCShellTreeCtrl::OnGetItemIcon


```
virtual int OnGetItemIcon(
    LPAFX_SHELLITEMINFO pItem,
    BOOL bSelected);
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
[in] [in] *bSelected*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="ongetitemtext"></a>  CMFCShellTreeCtrl::OnGetItemText


```
virtual CString OnGetItemText(LPAFX_SHELLITEMINFO pItem);
```

### <a name="parameters"></a>Parâmetros

[in] *pItem*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="refresh"></a>  CMFCShellTreeCtrl::Refresh

Atualiza e redesenha o [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md).

```
void Refresh();
```

### <a name="remarks"></a>Comentários

Chame esse método para atualizar a hierarquia dos itens exibidos no `CMFCShellTreeCtrl`.

##  <a name="selectpath"></a>  CMFCShellTreeCtrl::SelectPath

Seleciona um item na [classe CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) com base no caminho fornecido.

```
BOOL SelectPath(LPCTSTR lpszPath);
BOOL SelectPath(LPCITEMIDLIST lpidl);
```

### <a name="parameters"></a>Parâmetros

*lpszPath*<br/>
[in] Uma cadeia de caracteres que especifica o caminho de um item.

*lpidl*<br/>
[in] Um PIDL que especifica o item

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; E_FAIL caso contrário.

##  <a name="setflags"></a>  CMFCShellTreeCtrl::SetFlags

Define os sinalizadores para o contexto da árvore de filtro.

```
void SetFlags(
    DWORD dwFlags,
    BOOL bRefresh = TRUE);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
[in] Os sinalizadores a serem definidos.

*bRefresh*<br/>
[in] Um valor booleano que especifica se o `CMFCShellTreeCtrl` deve ser atualizado imediatamente.

### <a name="remarks"></a>Comentários

O `CMFCShellTreeCtrl` passa tudo definir sinalizadores para [IShellFolder::EnumObjects](https://msdn.microsoft.com/library/windows/desktop/bb775066). Para obter mais informações sobre os valores dos sinalizadores diferentes, consulte [IShellFolder::EnumObjects](https://msdn.microsoft.com/library/windows/desktop/bb775066).

##  <a name="setrelatedlist"></a>  CMFCShellTreeCtrl::SetRelatedList

Associa um [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) do objeto com um [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) objeto.

```
void SetRelatedList(CMFCShellListCtrl* pShellList);
```

### <a name="parameters"></a>Parâmetros

*pShellList*<br/>
[in] Um ponteiro para um `CMFCShellListCtrl` objeto.

### <a name="remarks"></a>Comentários

Esse método associa um `CMFCShellListCtrl` com um `CMFCShellTreeCtrl`. Esses objetos podem ser exibidos como uma janela do Explorer como: se o usuário seleciona um objeto na `CMFCShellTreeCtrl`, o itens em associados a `CMFCShellListCtrl` será atualizado automaticamente.

Use o método [CMFCShellTreeCtrl::GetRelatedList](#getrelatedlist) para recuperar o `CMFCShellListCtrl` associado com um `CMFCShellTreeCtrl`.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CTreeCtrl](../../mfc/reference/ctreectrl-class.md)<br/>
[Classe CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md)
