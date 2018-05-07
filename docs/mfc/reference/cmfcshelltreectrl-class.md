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
ms.openlocfilehash: fdd7e13e74fc3ae739c825f8aff95a79db8b5e29
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cmfcshelltreectrl-class"></a>Classe CMFCShellTreeCtrl
O `CMFCShellTreeCtrl` estende a classe [classe CTreeCtrl](../../mfc/reference/ctreectrl-class.md) funcionalidade exibindo uma hierarquia de itens de Shell.  

 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]    
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCShellTreeCtrl : public CTreeCtrl  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCShellTreeCtrl::EnableShellContextMenu](#enableshellcontextmenu)|Habilita ou desabilita o menu de atalho.|  
|[CMFCShellTreeCtrl::GetFlags](#getflags)|Retorna uma combinação de sinalizadores que são passados para [IShellFolder::EnumObjects](http://msdn.microsoft.com/library/windows/desktop/bb775066).|  
|[CMFCShellTreeCtrl::GetItemPath](#getitempath)|Recupera o caminho para um item.|  
|[CMFCShellTreeCtrl::GetRelatedList](#getrelatedlist)|Retorna um ponteiro para o [CMFCShellListCtrl classe](../../mfc/reference/cmfcshelllistctrl-class.md) objeto que é usado junto com isso `CMFCShellTreeCtrl` objeto para criar uma janela do Explorer como.|  
|[CMFCShellTreeCtrl::OnChildNotify](#onchildnotify)|Essa função de membro é chamada por esta janela pai do quando ele recebe uma mensagem de notificação que se aplica a esta janela. (Substitui [CWnd::OnChildNotify](../../mfc/reference/cwnd-class.md#onchildnotify).)|  
|[CMFCShellTreeCtrl::OnGetItemIcon](#ongetitemicon)||  
|[CMFCShellTreeCtrl::OnGetItemText](#ongetitemtext)||  
|[CMFCShellTreeCtrl::Refresh](#refresh)|Atualiza e redesenha atual `CMFCShellTreeCtrl` objeto.|  
|[CMFCShellTreeCtrl::SelectPath](#selectpath)|Seleciona o item de controle de árvore apropriada com base em um caminho de cadeia de caracteres ou PIDL fornecido.|  
|[CMFCShellTreeCtrl::SetFlags](#setflags)|Define os sinalizadores para filtrar o contexto da árvore (semelhante aos sinalizadores usados por `IShellFolder::EnumObjects`).|  
|[CMFCShellTreeCtrl::SetRelatedList](#setrelatedlist)|Define uma relação entre atual `CMFCShellTreeCtrl` objeto e um `CMFCShellListCtrl` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe estende a `CTreeCtrl` classe, permitindo que seu programa incluir itens de Shell do Windows na árvore. Essa classe pode ser associada com um `CMFCShellListCtrl` objeto para criar uma janela do Explorer concluída. Em seguida, selecionando um item na árvore exibirá uma lista de itens de Shell do Windows na lista associada.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CTreeCtrl](../../mfc/reference/ctreectrl-class.md)  
  
 `CMFCShellTreeCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxshelltreeCtrl.h  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um objeto de `CMFCShellTreeCtrl` classe. Este trecho de código é parte do [exemplo do Gerenciador de](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_Explorer#4](../../mfc/reference/codesnippet/cpp/cmfcshelltreectrl-class_1.h)]  
[!code-cpp[NVC_MFC_Explorer#5](../../mfc/reference/codesnippet/cpp/cmfcshelltreectrl-class_2.cpp)]  
  
##  <a name="enableshellcontextmenu"></a>  CMFCShellTreeCtrl::EnableShellContextMenu  
 Permite que o menu de atalho.  
  
```  
void EnableShellContextMenu(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 Um valor booleano que especifica se deseja habilitar o menu de atalho.  
  
##  <a name="getflags"></a>  CMFCShellTreeCtrl::GetFlags  
 Retorna os sinalizadores definidos para o [CMFCShellTreeCtrl classe](../../mfc/reference/cmfcshelltreectrl-class.md) objeto.  
  
```  
DWORD GetFlags() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `DWORD` valor que especifica a combinação de sinalizadores atualmente definido.  
  
### <a name="remarks"></a>Comentários  
 Os sinalizadores definidos `CMFCShellTreeCtrl` são enviadas para o método [IShellFolder::EnumObjects](http://msdn.microsoft.com/library/windows/desktop/bb775066) sempre que o objeto é atualizado. Você pode alterar os sinalizadores com o [CMFCShellTreeCtrl::SetFlags](#setflags) método.  
  
##  <a name="getitempath"></a>  CMFCShellTreeCtrl::GetItemPath  
 Recupera o caminho de um item de [CMFCShellTreeCtrl classe](../../mfc/reference/cmfcshelltreectrl-class.md) objeto.  
  
```  
BOOL GetItemPath(
    CString& strPath,  
    HTREEITEM htreeItem = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `strPath`  
 Uma referência a um parâmetro de cadeia de caracteres. O método grava o caminho do item para esse parâmetro.  
  
 [in] `htreeItem`  
 O método recupera o caminho para este item de controle de árvore.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se esse método falhar, `strPath` contém a cadeia de caracteres vazia.  
  
 Se você não especificar `hTreeItem`, esse método tentará obter a cadeia de caracteres para o item atualmente selecionado. Se nenhum item selecionado e `hTreeItem` é `NULL`, esse método falhar.  
  
##  <a name="getrelatedlist"></a>  CMFCShellTreeCtrl::GetRelatedList  
 Retorna um ponteiro para o [CMFCShellListCtrl classe](../../mfc/reference/cmfcshelllistctrl-class.md) objeto que está associado com esta [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) objeto.  
  
```  
CMFCShellListCtrl* GetRelatedList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `CMFCShellListCtrl` objeto que está associado este objeto de controle de árvore.  
  
### <a name="remarks"></a>Comentários  
 Usando um `CMFCShellListCtrl` objeto junto com um `CMFCShellTreeCtrl` do objeto, você pode criar uma janela do Explorer como. Use o método [CMFCShellTreeCtrl::SetRelatedList](#setrelatedlist) para associar duas classes. Depois que eles estão associados, o framework atualiza automaticamente o `CMFCShellListCtrl` se a seleção no `CMFCShellTreeCtrl` alterações.  
  
##  <a name="onchildnotify"></a>  CMFCShellTreeCtrl::OnChildNotify  

  
```  
virtual BOOL OnChildNotify(
    UINT message,  
    WPARAM wParam,  
    LPARAM lParam,  
    LRESULT* pLResult);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `message`  
 [in] `wParam`  
 [in] `lParam`  
 [in] `pLResult`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ongetitemicon"></a>  CMFCShellTreeCtrl::OnGetItemIcon  

  
```  
virtual int OnGetItemIcon(
    LPAFX_SHELLITEMINFO pItem,  
    BOOL bSelected);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pItem`  
 [in] `bSelected`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ongetitemtext"></a>  CMFCShellTreeCtrl::OnGetItemText  

  
```  
virtual CString OnGetItemText(LPAFX_SHELLITEMINFO pItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pItem`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="refresh"></a>  CMFCShellTreeCtrl::Refresh  
 Atualiza e redesenha o [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md).  
  
```  
void Refresh();
```  
  
### <a name="remarks"></a>Comentários  
 Chame este método para atualizar a hierarquia dos itens exibidos no `CMFCShellTreeCtrl`.  
  
##  <a name="selectpath"></a>  CMFCShellTreeCtrl::SelectPath  
 Seleciona um item de [CMFCShellTreeCtrl classe](../../mfc/reference/cmfcshelltreectrl-class.md) com base no caminho fornecido.  
  
```  
BOOL SelectPath(LPCTSTR lpszPath);
BOOL SelectPath(LPCITEMIDLIST lpidl);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszPath`  
 Uma cadeia de caracteres que especifica o caminho de um item.  
  
 [in] `lpidl`  
 Um PIDL que especifica o item  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK` Se for bem-sucedida; `E_FAIL` caso contrário.  
  
##  <a name="setflags"></a>  CMFCShellTreeCtrl::SetFlags  
 Define os sinalizadores para filtrar o contexto da árvore.  
  
```  
void SetFlags(
    DWORD dwFlags,  
    BOOL bRefresh = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwFlags`  
 Os sinalizadores a serem definidos.  
  
 [in] `bRefresh`  
 Um valor booleano que especifica se o `CMFCShellTreeCtrl` devem ser atualizadas imediatamente.  
  
### <a name="remarks"></a>Comentários  
 O `CMFCShellTreeCtrl` passa todos definir sinalizadores para [IShellFolder::EnumObjects](http://msdn.microsoft.com/library/windows/desktop/bb775066). Para obter mais informações sobre os valores de sinalizadores diferentes, consulte [IShellFolder::EnumObjects](http://msdn.microsoft.com/library/windows/desktop/bb775066).  
  
##  <a name="setrelatedlist"></a>  CMFCShellTreeCtrl::SetRelatedList  
 Associa um [CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md) do objeto com um [CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md) objeto.  
  
```  
void SetRelatedList(CMFCShellListCtrl* pShellList);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pShellList`  
 Um ponteiro para um `CMFCShellListCtrl` objeto.  
  
### <a name="remarks"></a>Comentários  
 Esse método associa um `CMFCShellListCtrl` com um `CMFCShellTreeCtrl`. Esses objetos podem ser exibidos como uma janela do Explorer como: se o usuário selecionar um objeto no `CMFCShellTreeCtrl`, o itens em associados a `CMFCShellListCtrl` será atualizado automaticamente.  
  
 Use o método [CMFCShellTreeCtrl::GetRelatedList](#getrelatedlist) para recuperar o `CMFCShellListCtrl` associado com um `CMFCShellTreeCtrl`.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CTreeCtrl](../../mfc/reference/ctreectrl-class.md)   
 [Classe CMFCShellListCtrl](../../mfc/reference/cmfcshelllistctrl-class.md)
