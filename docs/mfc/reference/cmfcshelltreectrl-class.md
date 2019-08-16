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
ms.openlocfilehash: 97136342049a54d45af893962025f01eda4366d4
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504905"
---
# <a name="cmfcshelltreectrl-class"></a>Classe CMFCShellTreeCtrl

A `CMFCShellTreeCtrl` classe estende a funcionalidade da [classe CTreeCtrl](../../mfc/reference/ctreectrl-class.md) exibindo uma hierarquia de itens do Shell.

Para obter mais detalhes, consulte o código-fonte localizado na pasta **vc\\atlmfc\\src\\MFC** da instalação do Visual Studio.
## <a name="syntax"></a>Sintaxe

```
class CMFCShellTreeCtrl : public CTreeCtrl
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCShellTreeCtrl::EnableShellContextMenu](#enableshellcontextmenu)|Habilita ou desabilita o menu de atalho.|
|[CMFCShellTreeCtrl::GetFlags](#getflags)|Retorna uma combinação de sinalizadores que são passados para [IShellFolder:: EnumObjects](/windows/win32/api/shobjidl_core/nf-shobjidl_core-ishellfolder-enumobjects).|
|[CMFCShellTreeCtrl::GetItemPath](#getitempath)|Recupera o caminho para um item.|
|[CMFCShellTreeCtrl::GetRelatedList](#getrelatedlist)|Retorna um ponteiro para o objeto da [classe CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) que é usado junto com `CMFCShellTreeCtrl` esse objeto para criar uma janela semelhante a um Gerenciador.|
|[CMFCShellTreeCtrl::OnChildNotify](#onchildnotify)|Essa função de membro é chamada por essa janela pai da janela quando recebe uma mensagem de notificação que se aplica a essa janela. (Substitui [CWnd:: OnChildNotify](../../mfc/reference/cwnd-class.md#onchildnotify).)|
|[CMFCShellTreeCtrl::OnGetItemIcon](#ongetitemicon)||
|[CMFCShellTreeCtrl::OnGetItemText](#ongetitemtext)||
|[CMFCShellTreeCtrl::Refresh](#refresh)|Atualiza e redesenha o objeto atual `CMFCShellTreeCtrl` .|
|[CMFCShellTreeCtrl::SelectPath](#selectpath)|Seleciona o item de controle de árvore apropriado com base em um PIDL ou caminho de cadeia de caracteres fornecido.|
|[CMFCShellTreeCtrl::SetFlags](#setflags)|Define sinalizadores para filtrar o contexto de árvore (semelhante aos sinalizadores usados pelo `IShellFolder::EnumObjects`).|
|[CMFCShellTreeCtrl::SetRelatedList](#setrelatedlist)|Define uma relação entre o objeto `CMFCShellTreeCtrl` atual e um `CMFCShellListCtrl` objeto.|

## <a name="remarks"></a>Comentários

Essa classe estende a `CTreeCtrl` classe habilitando seu programa para incluir itens de shell do Windows na árvore. Essa classe pode ser associada a um `CMFCShellListCtrl` objeto para criar uma janela completa do Explorer. Em seguida, selecionar um item na árvore exibirá uma lista de itens de shell do Windows na lista associada.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CTreeCtrl](../../mfc/reference/ctreectrl-class.md)

`CMFCShellTreeCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxshelltreeCtrl. h

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar um objeto da `CMFCShellTreeCtrl` classe. Este trecho de código faz parte do [exemplo do Explorer](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_Explorer#4](../../mfc/reference/codesnippet/cpp/cmfcshelltreectrl-class_1.h)]
[!code-cpp[NVC_MFC_Explorer#5](../../mfc/reference/codesnippet/cpp/cmfcshelltreectrl-class_2.cpp)]

##  <a name="enableshellcontextmenu"></a>  CMFCShellTreeCtrl::EnableShellContextMenu

Habilita o menu de atalho.

```
void EnableShellContextMenu(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
no Um booliano que especifica se o menu de atalho deve ser habilitado.

##  <a name="getflags"></a>  CMFCShellTreeCtrl::GetFlags

Retorna os sinalizadores definidos para o objeto da [classe CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) .

```
DWORD GetFlags() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor DWORD que especifica a combinação de sinalizadores atualmente definidos.

### <a name="remarks"></a>Comentários

Os sinalizadores definidos no `CMFCShellTreeCtrl` são enviados para o método [IShellFolder:: EnumObjects](/windows/win32/api/shobjidl_core/nf-shobjidl_core-ishellfolder-enumobjects) sempre que o objeto é atualizado. Você pode alterar os sinalizadores com o método [CMFCShellTreeCtrl:: SetFlags](#setflags) .

##  <a name="getitempath"></a>  CMFCShellTreeCtrl::GetItemPath

Recupera o caminho de um item no objeto da [classe CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) .

```
BOOL GetItemPath(
    CString& strPath,
    HTREEITEM htreeItem = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*strPath*<br/>
fora Uma referência a um parâmetro de cadeia de caracteres. O método grava o caminho do item para esse parâmetro.

*htreeItem*<br/>
no O método recupera o caminho para este item de controle de árvore.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se esse método falhar, *strPath* conterá a cadeia de caracteres vazia.

Se você não especificar *HTREEITEM*, esse método tentará obter a cadeia de caracteres para o item selecionado no momento. Se nenhum item for selecionado e *HTREEITEM* for NULL, esse método falhará.

##  <a name="getrelatedlist"></a>  CMFCShellTreeCtrl::GetRelatedList

Retorna um ponteiro para o objeto da [classe CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) que está associado a este objeto [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) .

```
CMFCShellListCtrl* GetRelatedList() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `CMFCShellListCtrl` objeto que está associado a este objeto de controle de árvore.

### <a name="remarks"></a>Comentários

Usando um `CMFCShellListCtrl` objeto junto com um `CMFCShellTreeCtrl` objeto, você pode criar uma janela semelhante a um Gerenciador. Use o método [CMFCShellTreeCtrl::](#setrelatedlist) setrelacionadolist para associar as duas classes. Depois que eles estiverem associados, a estrutura atualizará `CMFCShellListCtrl` automaticamente o se a seleção `CMFCShellTreeCtrl` nas alterações.

##  <a name="onchildnotify"></a>  CMFCShellTreeCtrl::OnChildNotify

```
virtual BOOL OnChildNotify(
    UINT message,
    WPARAM wParam,
    LPARAM lParam,
    LRESULT* pLResult);
```

### <a name="parameters"></a>Parâmetros

no *mensagem* de<br/>
no *wParam*<br/>
[in] *lParam*<br/>
[in] *pLResult*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="ongetitemicon"></a>  CMFCShellTreeCtrl::OnGetItemIcon

```
virtual int OnGetItemIcon(
    LPAFX_SHELLITEMINFO pItem,
    BOOL bSelected);
```

### <a name="parameters"></a>Parâmetros

no *pItem*<br/>
no *bSelected*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="ongetitemtext"></a>  CMFCShellTreeCtrl::OnGetItemText

```
virtual CString OnGetItemText(LPAFX_SHELLITEMINFO pItem);
```

### <a name="parameters"></a>Parâmetros

no *pItem*<br/>

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
no Uma cadeia de caracteres que especifica o caminho de um item.

*lpidl*<br/>
no Um PIDL que especifica o item

### <a name="return-value"></a>Valor de retorno

S_OK se for bem-sucedido; Em caso contrário, E_FAIL.

##  <a name="setflags"></a>  CMFCShellTreeCtrl::SetFlags

Define sinalizadores para filtrar o contexto de árvore.

```
void SetFlags(
    DWORD dwFlags,
    BOOL bRefresh = TRUE);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
no Os sinalizadores a serem definidos.

*bRefresh*<br/>
no Um booliano que especifica se `CMFCShellTreeCtrl` o deve ser atualizado imediatamente.

### <a name="remarks"></a>Comentários

O `CMFCShellTreeCtrl` passa todos os sinalizadores de conjunto para [IShellFolder:: EnumObjects](/windows/win32/api/shobjidl_core/nf-shobjidl_core-ishellfolder-enumobjects). Para obter mais informações sobre os valores de sinalizadores diferentes, consulte [IShellFolder:: EnumObjects](/windows/win32/api/shobjidl_core/nf-shobjidl_core-ishellfolder-enumobjects).

##  <a name="setrelatedlist"></a>  CMFCShellTreeCtrl::SetRelatedList

Associa um objeto [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) a um objeto [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) .

```
void SetRelatedList(CMFCShellListCtrl* pShellList);
```

### <a name="parameters"></a>Parâmetros

*pShellList*<br/>
no Um ponteiro para um `CMFCShellListCtrl` objeto.

### <a name="remarks"></a>Comentários

Esse método associa um `CMFCShellListCtrl` `CMFCShellTreeCtrl`a. Esses objetos podem ser exibidos como uma janela semelhante a um Gerenciador: se o usuário selecionar um objeto no `CMFCShellTreeCtrl`, os itens associados `CMFCShellListCtrl` no serão atualizados automaticamente.

Use o método [CMFCShellTreeCtrl::](#getrelatedlist) getrelacionalist para recuperar o `CMFCShellListCtrl` associado `CMFCShellTreeCtrl`a.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CTreeCtrl](../../mfc/reference/ctreectrl-class.md)<br/>
[Classe CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md)
