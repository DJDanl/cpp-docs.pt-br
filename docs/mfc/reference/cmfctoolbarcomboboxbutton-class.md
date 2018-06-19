---
title: Classe CMFCToolBarComboBoxButton | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCToolBarComboBoxButton
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::CMFCToolBarComboBoxButton
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::AddItem
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::AddSortedItem
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::Compare
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::CreateEdit
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::DeleteItem
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::FindItem
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetByCmd
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetComboBox
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetCount
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetCountAll
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetCurSel
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetCurSelAll
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetEditCtrl
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetItem
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetItemAll
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetItemData
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetItemDataAll
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetItemDataPtrAll
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetText
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetTextAll
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::IsCenterVert
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::IsFlatMode
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::RemoveAllItems
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::SelectItem
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::SelectItemAll
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::SetCenterVert
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::SetDropDownHeight
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::SetFlatMode
dev_langs:
- C++
helpviewer_keywords:
- CMFCToolBarComboBoxButton [MFC], CMFCToolBarComboBoxButton
- CMFCToolBarComboBoxButton [MFC], AddItem
- CMFCToolBarComboBoxButton [MFC], AddSortedItem
- CMFCToolBarComboBoxButton [MFC], Compare
- CMFCToolBarComboBoxButton [MFC], CreateEdit
- CMFCToolBarComboBoxButton [MFC], DeleteItem
- CMFCToolBarComboBoxButton [MFC], FindItem
- CMFCToolBarComboBoxButton [MFC], GetByCmd
- CMFCToolBarComboBoxButton [MFC], GetComboBox
- CMFCToolBarComboBoxButton [MFC], GetCount
- CMFCToolBarComboBoxButton [MFC], GetCountAll
- CMFCToolBarComboBoxButton [MFC], GetCurSel
- CMFCToolBarComboBoxButton [MFC], GetCurSelAll
- CMFCToolBarComboBoxButton [MFC], GetEditCtrl
- CMFCToolBarComboBoxButton [MFC], GetItem
- CMFCToolBarComboBoxButton [MFC], GetItemAll
- CMFCToolBarComboBoxButton [MFC], GetItemData
- CMFCToolBarComboBoxButton [MFC], GetItemDataAll
- CMFCToolBarComboBoxButton [MFC], GetItemDataPtrAll
- CMFCToolBarComboBoxButton [MFC], GetText
- CMFCToolBarComboBoxButton [MFC], GetTextAll
- CMFCToolBarComboBoxButton [MFC], IsCenterVert
- CMFCToolBarComboBoxButton [MFC], IsFlatMode
- CMFCToolBarComboBoxButton [MFC], RemoveAllItems
- CMFCToolBarComboBoxButton [MFC], SelectItem
- CMFCToolBarComboBoxButton [MFC], SelectItemAll
- CMFCToolBarComboBoxButton [MFC], SetCenterVert
- CMFCToolBarComboBoxButton [MFC], SetDropDownHeight
- CMFCToolBarComboBoxButton [MFC], SetFlatMode
ms.assetid: 32fa39f7-8e4e-4f0a-a31d-7b540d969a6c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ddfa4d26ed0a4328714fbd1a921fe7c204ca3752
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33377360"
---
# <a name="cmfctoolbarcomboboxbutton-class"></a>Classe CMFCToolBarComboBoxButton
Um botão de barra de ferramentas que contém um controle de caixa de combinação ( [classe CComboBox](../../mfc/reference/ccombobox-class.md)).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCToolBarComboBoxButton : public CMFCToolBarButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarComboBoxButton::CMFCToolBarComboBoxButton](#cmfctoolbarcomboboxbutton)|Constrói um `CMFCToolBarComboBoxButton`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarComboBoxButton::AddItem](#additem)|Adiciona um item ao final da lista da caixa de combinação.|  
|[CMFCToolBarComboBoxButton::AddSortedItem](#addsorteditem)|Adiciona um item à lista de caixa de combinação. A ordem dos itens na lista é especificada pelo `Compare`.|  
|[CMFCToolBarComboBoxButton::Compare](#compare)|Compara dois itens. Chamado classificar os itens que `AddSortedItems` adiciona à lista de caixa de combinação.|  
|[CMFCToolBarComboBoxButton::CreateEdit](#createedit)|Cria um novo controle de edição para o botão da caixa de combinação.|  
|[CMFCToolBarComboBoxButton::DeleteItem](#deleteitem)|Exclui um item de lista da caixa de combinação.|  
|[CMFCToolBarComboBoxButton::FindItem](#finditem)|Retorna o índice do item que contém uma cadeia de caracteres especificada.|  
|[CMFCToolBarComboBoxButton::GetByCmd](#getbycmd)|Retorna um ponteiro para o botão da caixa de combinação com uma ID de comando especificado.|  
|[CMFCToolBarComboBoxButton::GetComboBox](#getcombobox)|Retorna um ponteiro para o controle de caixa de combinação que é inserido no botão da caixa de combinação.|  
|[CMFCToolBarComboBoxButton::GetCount](#getcount)|Retorna o número de itens na caixa de combinação de lista de caixa.|  
|[CMFCToolBarComboBoxButton::GetCountAll](#getcountall)|Localiza a caixa de combinação botão caixa que tenha uma ID de comando especificado. Retorna o número de itens na caixa de combinação de lista de caixa do botão.|  
|[CMFCToolBarComboBoxButton::GetCurSel](#getcursel)|Retorna o índice do item selecionado na caixa de combinação de lista de caixa.|  
|[CMFCToolBarComboBoxButton::GetCurSelAll](#getcurselall)|Localiza a caixa de combinação botão caixa que tem uma ID de comando especificado e retorna o índice do item selecionado na caixa de combinação de lista da caixa do botão.|  
|[CMFCToolBarComboBoxButton::GetEditCtrl](#geteditctrl)|Retorna um ponteiro para o controle de edição é inserido no botão da caixa de combinação.|  
|[CMFCToolBarComboBoxButton::GetItem](#getitem)|Retorna a cadeia de caracteres que está associada um índice especificado na caixa de combinação de lista de caixa.|  
|[CMFCToolBarComboBoxButton::GetItemAll](#getitemall)|Localiza a caixa de combinação botão caixa que tem uma ID de comando especificado e retorna a cadeia de caracteres que está associada um índice na lista da caixa de combinação do botão.|  
|[CMFCToolBarComboBoxButton::GetItemData](#getitemdata)|Retorna o valor de 32 bits que está associado um índice especificado na caixa de combinação de lista de caixa.|  
|[CMFCToolBarComboBoxButton::GetItemDataAll](#getitemdataall)|Localiza a caixa de combinação botão caixa que tem uma ID de comando especificado e retorna o valor de 32 bits que é associado um índice na lista da caixa de combinação do botão.|  
|[CMFCToolBarComboBoxButton::GetItemDataPtrAll](#getitemdataptrall)|Localiza a caixa de combinação botão caixa que tenha uma ID de comando especificado. Recupera o valor de 32 bits que é associado a um índice na lista da caixa de combinação do botão e retorna o valor de 32 bits como um ponteiro.|  
|[CMFCToolBarComboBoxButton::GetText](#gettext)|Retorna o texto do controle de edição da caixa de combinação.|  
|[CMFCToolBarComboBoxButton::GetTextAll](#gettextall)|Localiza a caixa de combinação botão caixa que tem uma ID de comando especificado e retorna o texto do controle de edição do botão.|  
|[CMFCToolBarComboBoxButton::IsCenterVert](#iscentervert)|Determina se os botões da caixa de combinação no aplicativo são centralizadas ou alinhadas com a parte superior da barra de ferramentas.|  
|[CMFCToolBarComboBoxButton::IsFlatMode](#isflatmode)|Determina se os botões da caixa de combinação no aplicativo tem uma aparência plana.|  
|[CMFCToolBarComboBoxButton::RemoveAllItems](#removeallitems)|Remove todos os itens da lista de caixa e editar o controle da caixa de combinação.|  
|[CMFCToolBarComboBoxButton::SelectItem](#selectitem)|Seleciona um item na caixa de combinação de acordo com seu índice, um valor de 32 bits ou uma cadeia de caracteres e notifica sobre a seleção no controle de caixa de combinação.|  
|[CMFCToolBarComboBoxButton::SelectItemAll](#selectitemall)|Localiza a caixa de combinação botão caixa que tenha uma ID de comando especificado. Chamadas `SelectItem` para selecionar um item na caixa de combinação de botão de acordo com sua cadeia de caracteres, um índice ou um valor de 32 bits.|  
|[CMFCToolBarComboBoxButton::SetCenterVert](#setcentervert)|Especifica se os botões da caixa de combinação no aplicativo são centralizados verticalmente ou alinhados com a parte superior da barra de ferramentas.|  
|[CMFCToolBarComboBoxButton::SetDropDownHeight](#setdropdownheight)|Define a altura da caixa de listagem suspensa.|  
|[CMFCToolBarComboBoxButton::SetFlatMode](#setflatmode)|Especifica se os botões da caixa de combinação no aplicativo tem uma aparência plana.|  
  
## <a name="remarks"></a>Comentários  
 Para adicionar um botão de caixa de combinação a uma barra de ferramentas, siga estas etapas:  
  
 1. Reserve uma ID de recurso fictício do botão no recurso pai da barra de ferramentas.  
  
 2. Construir um `CMFCToolBarComboBoxButton` objeto.  
  
 3. No manipulador de mensagens que processa o `AFX_WM_RESETTOOLBAR` mensagem, substitua o botão fictício com o novo botão de caixa de combinação usando [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton).  
  
 Para obter mais informações, consulte [passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md). Para obter um exemplo de um botão de barra de ferramentas de caixa de combinação, consulte o projeto de exemplo VisualStudioDemo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCToolBarComboBoxButton` classe. O exemplo mostra como habilitar as caixas de combinação e edição, definir a posição vertical da caixa de combinação botões de caixa no aplicativo, defina a altura da caixa de listagem quando ele é removido para baixo, definir a aparência de estilo plano dos botões da caixa de combinação no aplicativo e definir o texto na caixa de edição da caixa de combinação de botão da caixa. Este trecho de código é parte do [exemplo de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#36](../../mfc/codesnippet/cpp/cmfctoolbarcomboboxbutton-class_1.cpp)]  
[!code-cpp[NVC_MFC_VisualStudioDemo#37](../../mfc/codesnippet/cpp/cmfctoolbarcomboboxbutton-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
 [CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtoolbarcomboboxbutton.h  
  
##  <a name="additem"></a>  CMFCToolBarComboBoxButton::AddItem  
 Acrescenta um item exclusivo para a caixa de listagem.  
  
```  
virtual INT_PTR AddItem(
    LPCTSTR lpszItem,  
    DWORD_PTR dwData=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszItem`  
 O texto do item a ser adicionado à caixa de listagem.  
  
 [in] `dwData`  
 Os dados associados ao item a ser adicionado à caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do último item na caixa de listagem.  
  
### <a name="remarks"></a>Comentários  
 Não use esse método quando o estilo da caixa de lista é classificado.  
  
 Se o texto do item já está na caixa de listagem, os novos dados são armazenados com o item existente. A pesquisa para o item diferencia maiusculas de minúsculas.  
  
##  <a name="addsorteditem"></a>  CMFCToolBarComboBoxButton::AddSortedItem  
 Adiciona um item à caixa de listagem na ordem em que é definido pelo [comparar](#compare) método.  
  
```  
virtual INT_PTR AddSortedItem(
    LPCTSTR lpszItem,  
    DWORD_PTR dwData=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszItem`  
 O texto do item a ser adicionado à caixa de listagem.  
  
 [in] `dwData`  
 Os dados associados ao item a ser adicionado à caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Índice do item que foi adicionado à caixa de listagem.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para adicionar itens à caixa de listagem em uma ordem específica.  
  
##  <a name="canbestretched"></a>  CMFCToolBarComboBoxButton::CanBeStretched  
 Indica se o tamanho de botão da caixa de combinação pode mudar.  
  
```  
virtual BOOL CanBeStretched() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE`.  
  
##  <a name="cmfctoolbarcomboboxbutton"></a>  CMFCToolBarComboBoxButton::CMFCToolBarComboBoxButton  
 Constrói um [CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md) objeto.  
  
```  
CMFCToolBarComboBoxButton(
    UINT uiID,  
    int iImage,  
    DWORD dwStyle=CBS_DROPDOWNLIST,  
    int iWidth=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiID`  
 A ID de comando do botão novo.  
  
 [in] `iImage`  
 O índice de imagem da imagem associada ao novo botão.  
  
 [in] `dwStyle`  
 O estilo do botão novo.  
  
 [in] `iWidth`  
 A largura, em pixels, do botão novo.  
  
### <a name="remarks"></a>Comentários  
 A largura padrão é de 150 pixels.  
  
 Para obter uma lista de estilos de botão da barra de ferramentas, consulte [estilos de controle de barra de ferramentas](../../mfc/reference/toolbar-control-styles.md)  
  
##  <a name="cleardata"></a>  CMFCToolBarComboBoxButton::ClearData  
 Exclui os dados definidos pelo usuário.  
  
```  
virtual void ClearData();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método não fará nada. Substitua este método em uma classe derivada, se você quiser excluir quaisquer dados definidos pelo usuário.  
  
##  <a name="compare"></a>  CMFCToolBarComboBoxButton::Compare  
 Compara duas cadeias de caracteres.  
  
```  
virtual int Compare(
    LPCTSTR lpszItem1,  
    LPCTSTR lpszItem2);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszItem1`  
 A primeira cadeia de caracteres a ser comparada.  
  
 [in] `lpszItem2`  
 A segunda cadeia de caracteres a ser comparada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que indica a relação lexicográfica diferencia maiusculas de minúsculas entre as cadeias de caracteres. A tabela a seguir lista os valores possíveis:  
  
|Valor|Descrição|  
|-----------|-----------------|  
|\<0|A primeira cadeia de caracteres é menor que o segundo.|  
|0|A primeira cadeia de caracteres é igual a segunda.|  
|>0|A primeira cadeia de caracteres é maior que o segundo.|  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para alterar como os itens são classificados na caixa de listagem.  
  
 A comparação diferencia maiusculas de minúsculas.  
  
 Este método é chamado somente a partir de [AddSortedItem](#addsorteditem) método.  
  
##  <a name="copyfrom"></a>  CMFCToolBarComboBoxButton::CopyFrom  
 Copia o estado do `CMFCToolBarComboBoxButton` ao objeto atual.  
  
```  
virtual void CopyFrom(const CMFCToolBarButton& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `src`  
 A fonte `CMFCToolBarComboBoxButton` objeto.  
  
##  <a name="createcombo"></a>  CMFCToolBarComboBoxButton::CreateCombo  
 Cria uma nova caixa de combinação do botão da caixa de combinação.  
  
```  
virtual CComboBox* CreateCombo(
    CWnd* pWndParent,  
    const CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 Um ponteiro para a janela pai do botão.  
  
 [in] `rect`  
 Retângulo delimitador da caixa de combinação.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a nova caixa de combinação se o método teve êxito; Caso contrário, `NULL`.  
  
##  <a name="createedit"></a>  CMFCToolBarComboBoxButton::CreateEdit  
 Cria uma nova caixa de edição para o botão da caixa de combinação.  
  
```  
virtual CMFCToolBarComboBoxEdit* CreateEdit(
    CWnd* pWndParent,  
    const CRect& rect,  
    DWORD dwEditStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 Um ponteiro para a janela pai do botão.  
  
 [in] `rect`  
 Retângulo delimitador da nova caixa de edição.  
  
 [in] `dwEditStyle`  
 Estilo de controle da caixa de edição de novo.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a nova caixa de edição se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama este método quando ele cria uma nova caixa de edição para um botão da caixa de combinação. Substitua este método para alterar como [CMFCToolBarComboBoxEdit](../../mfc/reference/cmfctoolbarcomboboxedit-class.md) é criado.  
  
##  <a name="deleteitem"></a>  CMFCToolBarComboBoxButton::DeleteItem  
 Exclui um item especificado na caixa de listagem.  
  
```  
BOOL DeleteItem(int iIndex);  
BOOL DeleteItem(DWORD_PTR dwData);  
  BOOL DeleteItem(LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iIndex`  
 O índice de base zero do item a ser excluído.  
  
 [in] `dwData`  
 Os dados associados ao item a ser excluído.  
  
 [in] `lpszText`  
 O texto do item a ser excluído. Se houver vários itens com o mesmo texto, o primeiro item é excluído.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o item foi localizado e excluído com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="duplicatedata"></a>  CMFCToolBarComboBoxButton::DuplicateData  
 Dados definidos pelo usuário duplicatas.  
  
```  
virtual void DuplicateData();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método não fará nada. Substitua este método em uma classe derivada, se você quiser copiar quaisquer dados definidos pelo usuário.  
  
##  <a name="enablewindow"></a>  CMFCToolBarComboBoxButton::EnableWindow  
 Habilita ou desabilita as caixas de combinação e edição.  
  
```  
virtual void EnableWindow(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE` Para habilitar as caixas de combinação e edição; `FALSE` para desabilitar as caixas de combinação e edição.  
  
### <a name="remarks"></a>Comentários  
 Quando desabilitado, os controles não podem se tornar ativos e não podem aceitar a entrada do usuário.  
  
##  <a name="exporttomenubutton"></a>  CMFCToolBarComboBoxButton::ExportToMenuButton  
 Uma cadeia de caracteres da tabela de cadeia de caracteres de aplicativo para o menu especificado usando o comando de botão de caixa de combinação de cópias de ID.  
  
```  
virtual BOOL ExportToMenuButton(CMFCToolBarMenuButton& menuButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `menuButton`  
 Referência a um botão de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre `TRUE`.  
  
##  <a name="finditem"></a>  CMFCToolBarComboBoxButton::FindItem  
 Retorna o índice do primeiro item na caixa de listagem que contém uma cadeia de caracteres especificada.  
  
```  
int FindItem(LPCTSTR lpszText) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszText`  
 O texto a ser pesquisado na caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do item; ou `CB_ERR` se o item não for encontrado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getbycmd"></a>  CMFCToolBarComboBoxButton::GetByCmd  
 Obtém um ponteiro para o botão de caixa de combinação que tem uma ID de comando especificado.  
  
```  
static CMFCToolBarComboBoxButton* GetByCmd(
    UINT uiCmd,  
    BOOL bIsFocus=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID de comando de um botão da caixa de combinação.  
  
 [in] `bIsFocus`  
 `TRUE` para pesquisar somente focalizado botões; `FALSE` para pesquisar todos os botões.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um botão de caixa de combinação. ou `NULL` se o botão não encontrado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcombobox"></a>  CMFCToolBarComboBoxButton::GetComboBox  
 Retorna um ponteiro para a caixa de combinação na caixa de combinação de botão da caixa.  
  
```  
CComboBox* GetComboBox() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [classe CComboBox](../../mfc/reference/ccombobox-class.md) objeto se o método foi bem-sucedida; caso contrário `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcontextmenuid"></a>  CMFCToolBarComboBoxButton::GetContextMenuID  
 Obtém a ID de recurso de menu de atalho para o botão da caixa de combinação.  
  
```  
UINT GetContextMenuID();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de recurso de menu de atalho.  
  
##  <a name="getcount"></a>  CMFCToolBarComboBoxButton::GetCount  
 Retorna o número de itens na caixa de listagem.  
  
```  
INT_PTR GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens na caixa de listagem.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcountall"></a>  CMFCToolBarComboBoxButton::GetCountAll  
 Obtém o número de itens na caixa de listagem de um botão de caixa de combinação que tem uma ID de comando especificado.  
  
```  
static int GetCountAll(UINT uiCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID de comando de um botão da caixa de combinação.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens na caixa de listagem; Caso contrário, `CB_ERR` se não for encontrado no botão da caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcursel"></a>  CMFCToolBarComboBoxButton::GetCurSel  
 Obtém o índice do item atualmente selecionado na caixa de listagem.  
  
```  
int GetCurSel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do item atualmente selecionado na caixa de listagem; ou `CB_ERR` se nenhum item selecionado.  
  
### <a name="remarks"></a>Comentários  
 O índice de caixa de lista é baseada em zero.  
  
##  <a name="getcurselall"></a>  CMFCToolBarComboBoxButton::GetCurSelAll  
 Retorna o índice do item atualmente selecionado na caixa de listagem de uma caixa de combinação botão caixa que tenha uma ID de comando especificado.  
  
```  
static int GetCurSelAll(UINT uiCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID de comando de um botão da caixa de combinação.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do item atualmente selecionado na caixa de listagem; Caso contrário, `CB_ERR` se nenhum item selecionado ou não foi encontrado um botão da caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
 O índice de caixa de lista é baseada em zero.  
  
##  <a name="geteditctrl"></a>  CMFCToolBarComboBoxButton::GetEditCtrl  
 Retorna um ponteiro para a caixa de edição na caixa de combinação de botão da caixa.  
  
```  
virtual CEdit* GetEditCtrl();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a caixa de edição, se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gethwnd"></a>  CMFCToolBarComboBoxButton::GetHwnd  
 Retorna o identificador de janela da caixa de combinação.  
  
```  
virtual HWND GetHwnd();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de janela, ou `NULL` se a caixa de combinação não está associada um objeto de janela.  
  
##  <a name="getitem"></a>  CMFCToolBarComboBoxButton::GetItem  
 Retorna a cadeia de caracteres associada a um item em um índice especificado na caixa de listagem.  
  
```  
LPCTSTR GetItem(int iIndex=-1) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iIndex`  
 Índice de base zero de um item na caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a cadeia de caracteres que é associado ao item; Caso contrário, `NULL` se o parâmetro de índice é inválido, ou se o parâmetro de índice é -1 e não há nenhum item selecionado na caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
 Um parâmetro de índice-1 retorna a cadeia de caracteres do item selecionado no momento.  
  
##  <a name="getitemall"></a>  CMFCToolBarComboBoxButton::GetItemAll  
 Retorna a cadeia de caracteres associada a um item em um índice especificado na caixa de listagem de um botão de caixa de combinação que tem uma ID de comando especificado.  
  
```  
static LPCTSTR GetItemAll(
    UINT uiCmd,  
    int iIndex=-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID de comando de um botão da caixa de combinação.  
  
 [in] `iIndex`  
 O índice de base zero de um item na caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a cadeia de caracteres do item se o método teve êxito; Caso contrário, `NULL` se o índice é inválido, um botão de caixa de combinação não é encontrado, ou se o índice é -1 e não há nenhum item selecionado na caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
 Um valor de índice-1 retorna a cadeia de caracteres do item selecionado no momento.  
  
##  <a name="getitemdata"></a>  CMFCToolBarComboBoxButton::GetItemData  
 Retorna os dados associados a um item em um índice específico na caixa de listagem.  
  
```  
DWORD_PTR GetItemData(int iIndex=-1) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iIndex`  
 O índice de base zero de um item na caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Os dados associados ao item; ou 0 se o item não existe.  
  
### <a name="remarks"></a>Comentários  
 Um parâmetro de índice-1 retorna os dados associados ao item selecionado no momento.  
  
##  <a name="getitemdataall"></a>  CMFCToolBarComboBoxButton::GetItemDataAll  
 Retorna os dados associados a um item em um índice específico na caixa de listagem de um botão de caixa de combinação que tem uma ID de comando específico.  
  
```  
static DWORD_PTR GetItemDataAll(
    UINT uiCmd,  
    int iIndex=-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID de comando de um botão da caixa de combinação.  
  
 [in] `iIndex`  
 O índice de base zero de um item na caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Os dados associados ao item se o método teve êxito; Caso contrário, 0 se o índice especificado não é válido ou CB_ERR se a caixa de combinação caixa botão não foi encontrado.  
  
### <a name="remarks"></a>Comentários  
 Um parâmetro de índice-1 retorna os dados associados ao item selecionado no momento.  
  
##  <a name="getitemdataptrall"></a>  CMFCToolBarComboBoxButton::GetItemDataPtrAll  
 Retorna os dados associados a um item em um índice específico na caixa de listagem de um botão de caixa de combinação que tem uma ID de comando específico. Esses dados são retornados como um ponteiro.  
  
```  
static void* GetItemDataPtrAll(
    UINT uiCmd,  
    int iIndex=-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID de comando do botão da caixa de combinação.  
  
 [in] `iIndex`  
 O índice de base zero de um item na caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro associado ao item se o método teve êxito; Caso contrário, -1 se ocorrer um erro, ou `NULL` se não for encontrado no botão da caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getprompt"></a>  CMFCToolBarComboBoxButton::GetPrompt  
 Retorna a cadeia de caracteres de prompt para a caixa de combinação botão da caixa.  
  
```  
virtual CString GetPrompt() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cadeia de caracteres de prompt.  
  
### <a name="remarks"></a>Comentários  
 Este método não está implementado atualmente.  
  
##  <a name="gettext"></a>  CMFCToolBarComboBoxButton::GetText  
 Obtém o texto na caixa de edição.  
  
```  
LPCTSTR GetText() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O texto na caixa de edição.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gettextall"></a>  CMFCToolBarComboBoxButton::GetTextAll  
 Obtém o texto na caixa de edição de um botão de caixa de combinação que tem uma ID de comando especificado.  
  
```  
static LPCTSTR GetTextAll(UINT uiCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID de comando de um botão da caixa de combinação específica.  
  
### <a name="return-value"></a>Valor de retorno  
 O texto na caixa de edição, se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="hasfocus"></a>  CMFCToolBarComboBoxButton::HasFocus  
 Indica se a caixa de combinação atualmente tem o foco.  
  
```  
virtual BOOL HasFocus() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se a caixa de combinação atualmente tem foco. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método também retorna `TRUE` se qualquer janela filho da caixa de combinação tem o foco no momento.  
  
##  <a name="iscentervert"></a>  CMFCToolBarComboBoxButton::IsCenterVert  
 Retorna a posição vertical dos botões da caixa de combinação no aplicativo.  
  
```  
static BOOL IsCenterVert();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se os botões são centralizados; `FALSE` se os botões são alinhados na parte superior.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isflatmode"></a>  CMFCToolBarComboBoxButton::IsFlatMode  
 Retorna a aparência de estilo plano dos botões da caixa de combinação no aplicativo.  
  
```  
static BOOL IsFlatMode();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se os botões têm um estilo simples; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O estilo de padrão simples para os botões da caixa de combinação é `FALSE.`  
  
##  <a name="isownerof"></a>  CMFCToolBarComboBoxButton::IsOwnerOf  
 Indica se o identificador especificado está associado com o botão da caixa de combinação ou um de seus filhos.  
  
```  
virtual BOOL IsOwnerOf(HWND hwnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hwnd`  
 Um identificador de janela.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o identificador é associado com o botão da caixa de combinação ou um de seus filhos; Caso contrário, `FALSE`.  
  
##  <a name="isribbonbutton"></a>  CMFCToolBarComboBoxButton::IsRibbonButton  
 Indica se o botão da caixa de combinação reside em um painel de faixa de opções.  
  
```  
BOOL IsRibbonButton() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método sempre retorna `FALSE`, que significa que a caixa de combinação botão caixa nunca é exibido em um painel de faixa de opções.  
  
##  <a name="iswindowvisible"></a>  CMFCToolBarComboBoxButton::IsWindowVisible  
 Retorna o estado de visibilidade da caixa de combinação de botão da caixa.  
  
```  
virtual BOOL IsWindowVisible();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O estado de visibilidade do botão da caixa de combinação.  
  
##  <a name="notifycommand"></a>  CMFCToolBarComboBoxButton::NotifyCommand  
 Indica se o botão da caixa de combinação processa a mensagem.  
  
```  
virtual BOOL NotifyCommand(int iNotifyCode);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iNotifyCode`  
 A mensagem de notificação que está associada com o comando.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o botão da caixa de combinação processa a mensagem.  
  
##  <a name="onaddtocustomizepage"></a>  CMFCToolBarComboBoxButton::OnAddToCustomizePage  
 Chamado pelo framework quando o botão é adicionado para o **personalizar** caixa de diálogo.  
  
```  
virtual void OnAddToCustomizePage();
```  
  
##  <a name="oncalculatesize"></a>  CMFCToolBarComboBoxButton::OnCalculateSize  
 Chamado pelo framework para calcular o tamanho do botão.  
  
```  
virtual SIZE OnCalculateSize(
    CDC* pDC,  
    const CSize& sizeDefault,  
    BOOL bHorz);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 O contexto de dispositivo que exibe o botão da caixa de combinação.  
  
 [in] `sizeDefault`  
 O tamanho padrão do botão da caixa de combinação.  
  
 [in] `bHorz`  
 O estado de encaixe da barra de ferramentas do pai. `TRUE` Quando a barra de ferramentas estiver encaixada horizontalmente e `FALSE` quando a barra de ferramentas está encaixada verticalmente.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `SIZE` estrutura que contém as dimensões do botão da caixa de combinação, em pixels.  
  
##  <a name="onchangeparentwnd"></a>  CMFCToolBarComboBoxButton::OnChangeParentWnd  
 Chamado pelo framework quando o botão da caixa de combinação é inserido em uma nova barra de ferramentas.  
  
```  
virtual void OnChangeParentWnd(CWnd* pWndParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 Ponteiro para a nova barra de ferramentas do pai.  
  
##  <a name="onclick"></a>  CMFCToolBarComboBoxButton::OnClick  
 Chamado pelo framework quando o usuário clica no botão da caixa de combinação.  
  
```  
virtual BOOL OnClick(
    CWnd* pWnd,  
    BOOL bDelay = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 Ponteiro para a janela pai do botão da caixa de combinação.  
  
 [in] `bDelay`  
 Reservado para uso em uma classe derivada.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o método manipula o evento; Caso contrário, `FALSE`.  
  
##  <a name="onctlcolor"></a>  CMFCToolBarComboBoxButton::OnCtlColor  
 Chamado pelo framework quando o usuário altera a cor de barra de ferramentas do pai para definir a caixa de combinação de cor do botão de caixa.  
  
```  
virtual HBRUSH OnCtlColor(
    CDC* pDC,  
    UINT nCtlColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 O contexto de dispositivo que exibe o botão da caixa de combinação.  
  
 [in] `nCtlColor`  
 Não utilizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador para o pincel que usa a estrutura para pintar o plano de fundo do botão da caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
 Esse método também define a cor de texto do botão de caixa de combinação.  
  
##  <a name="ondraw"></a>  CMFCToolBarComboBoxButton::OnDraw  
 Chamado pelo framework para desenhar o botão da caixa de combinação usando as opções e estilos especificados.  
  
```  
virtual void OnDraw(
    CDC* pDC,  
    const CRect& rect,  
    CMFCToolBarImages* pImages,  
    BOOL bHorz = TRUE,  
    BOOL bCustomizeMode = FALSE,  
    BOOL bHighlight = FALSE,  
    BOOL bDrawBorder = TRUE,  
    BOOL bGrayDisabledButtons = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `Pdc`  
 O contexto de dispositivo que exibe o botão.  
  
 [in] `rect`  
 O retângulo delimitador do botão.  
  
 [in] `pImages`  
 A coleção de imagens que está associada com o botão.  
  
 [in] `bHorz`  
 O estado de encaixe da barra de ferramentas do pai. `TRUE` Quando a barra de ferramentas estiver encaixada horizontalmente e `FALSE` quando a barra de ferramentas está encaixada verticalmente.  
  
 [in] `bCustomizeMode`  
 Se o aplicativo está no modo de personalização.  
  
 [in] `bHighlight`  
 Se desenhar o botão da caixa de combinação realçado.  
  
 [in] `bDrawBorder`  
 Se desenhar o botão de caixa de combinação com uma borda.  
  
 [in] `bGrayDisabledButtons`  
 `TRUE` Para desenhar sombreada botões desabilitado; `FALSE` usar o desabilitado as imagens de coleção.  
  
##  <a name="ondrawoncustomizelist"></a>  CMFCToolBarComboBoxButton::OnDrawOnCustomizeList  
 Chamado pelo framework para desenhar o botão de caixa de combinação no **comandos** painel do **personalizar** caixa de diálogo.  
  
```  
virtual int OnDrawOnCustomizeList(
    CDC* pDC,  
    const CRect& rect,  
    BOOL bSelected);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 O contexto de dispositivo que exibe o botão da caixa de combinação.  
  
 [in] `rect`  
 O retângulo delimitador do botão da caixa de combinação.  
  
 [in] `bSelected`  
 `TRUE` Se o botão de caixa de combinação é selecionada. Caso contrário, `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 A largura, em pixels, do botão da caixa de combinação.  
  
##  <a name="onglobalfontschanged"></a>  CMFCToolBarComboBoxButton::OnGlobalFontsChanged  
 Chamado pelo framework para definir a caixa de combinação de fonte de botão de caixa quando altera a fonte do aplicativo.  
  
```  
virtual void OnGlobalFontsChanged();
```  
  
##  <a name="onmove"></a>  CMFCToolBarComboBoxButton::OnMove  
 Chamado pelo framework para alterar o local do botão da caixa de combinação quando move a barra de ferramentas do pai.  
  
```  
virtual void OnMove();
```  
  
##  <a name="onshow"></a>  CMFCToolBarComboBoxButton::OnShow  
 Chamado pelo framework quando o botão da caixa de combinação é oculto ou exibido.  
  
```  
virtual void OnShow(BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bShow`  
 Se deseja ocultar ou exibir o botão de caixa de combinação.  
  
##  <a name="onsize"></a>  CMFCToolBarComboBoxButton::OnSize  
 Chamado pelo framework para alterar o tamanho do botão da caixa de combinação quando a barra de ferramentas do pai altera o tamanho.  
  
```  
virtual void OnSize(int iSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iSize`  
 A nova largura do botão da caixa de combinação.  
  
##  <a name="onupdatetooltip"></a>  CMFCToolBarComboBoxButton::OnUpdateToolTip  
 Chamado pelo framework quando o usuário altera a dica de ferramenta do botão da caixa de combinação.  
  
```  
virtual BOOL OnUpdateToolTip(
    CWnd* pWndParent,  
    int iButtonIndex,  
    CToolTipCtrl& wndToolTip,  
    CString& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 Ponteiro para a janela pai do botão da caixa de combinação.  
  
 [in] `iButtonIndex`  
 ID do botão da caixa de combinação.  
  
 [in] `wndToolTip`  
 A dica de ferramenta a ser associado com o botão da caixa de combinação.  
  
 [in] `str`  
 O texto da dica de ferramenta.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o método manipula o evento; Caso contrário, `FALSE`.  
  
##  <a name="removeallitems"></a>  CMFCToolBarComboBoxButton::RemoveAllItems  
 Exclui todos os itens de caixas de lista e editar.  
  
```  
void RemoveAllItems();
```  
  
### <a name="remarks"></a>Comentários  
 Remove todos os itens da lista de caixa e controle de uma caixa de combinação de edição.  
  
##  <a name="selectitem"></a>  CMFCToolBarComboBoxButton::SelectItem  
 Seleciona um item na caixa de listagem.  
  
```  
BOOL SelectItem(
    int iIndex,  
    BOOL bNotify=TRUE);  
  
BOOL SelectItem(DWORD_PTR dwData);  
BOOL SelectItem(LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iIndex`  
 O índice de base zero de um item na caixa de listagem.  
  
 [in] `bNotify`  
 `TRUE` para notificar o botão da caixa de combinação de seleção; Caso contrário, `FALSE`.  
  
 [in] `dwData`  
 Os dados associados a um item na caixa de listagem.  
  
 [in] `lpszText`  
 O texto de um item na caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o método teve êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="selectitemall"></a>  CMFCToolBarComboBoxButton::SelectItemAll  
 Seleciona um item na caixa de listagem de um botão de caixa de combinação que tem uma ID de comando especificado.  
  
```  
static BOOL SelectItemAll(
    UINT uiCmd,  
    int iIndex);

 
static BOOL SelectItemAll(
    UINT uiCmd,  
    DWORD_PTR dwData);

 
static BOOL SelectItemAll(
    UINT uiCmd,  
    LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID de comando do botão da caixa de combinação que contém a caixa de listagem.  
  
 [in] `iIndex`  
 O índice de base zero do item na caixa de listagem. Um valor de -1 remove qualquer seleção atual na caixa de listagem e desmarca a caixa de edição.  
  
 [in] `dwData`  
 Os dados de um item na caixa de listagem.  
  
 [in] `lpszText`  
 O texto de um item na caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o método teve êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="serialize"></a>  CMFCToolBarComboBoxButton::Serialize  
 Lê esse objeto de um arquivo ou grava em um arquivo morto.  
  
```  
virtual void Serialize(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in, out] `ar`  
 O objeto `CArchive` a ser serializado.  
  
### <a name="remarks"></a>Comentários  
 Configurações de `CArchive` objeto determinar se esse método lê ou grava o arquivo morto.  
  
##  <a name="setaccdata"></a>  CMFCToolBarComboBoxButton::SetACCData  
 Popula especificado `CAccessibilityData` objeto usando dados de acessibilidade do botão de caixa de combinação.  
  
```  
virtual BOOL SetACCData(
    CWnd* pParent,  
    CAccessibilityData& data);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParent`  
 A janela pai do botão da caixa de combinação.  
  
 [out] `data`  
 Um `CAccessibilityData` objeto que recebe os dados de acessibilidade do botão de caixa de combinação.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o método teve êxito; Caso contrário, `FALSE`.  
  
##  <a name="setcentervert"></a>  CMFCToolBarComboBoxButton::SetCenterVert  
 Define a posição vertical dos botões da caixa de combinação no aplicativo.  
  
```  
static void SetCenterVert(BOOL bCenterVert=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bCenterVert`  
 `TRUE` para o centro do botão da caixa de combinação na barra de ferramentas. `FALSE` para alinhar o botão da caixa de combinação para a parte superior da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, os botões da caixa de combinação são alinhados para a parte superior.  
  
##  <a name="setcontextmenuid"></a>  CMFCToolBarComboBoxButton::SetContextMenuID  
 Define a ID de recurso de menu de atalho para a caixa de combinação botão da caixa.  
  
```  
void SetContextMenuID(UINT uiResID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiResID`  
 A ID de recurso de menu de atalho.  
  
##  <a name="setdropdownheight"></a>  CMFCToolBarComboBoxButton::SetDropDownHeight  
 Define a altura da caixa de listagem quando ele é removido para baixo.  
  
```  
void SetDropDownHeight(int nHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nHeight`  
 A altura, em pixels, da caixa de listagem.  
  
### <a name="remarks"></a>Comentários  
 A altura padrão é 150 pixels.  
  
##  <a name="setflatmode"></a>  CMFCToolBarComboBoxButton::SetFlatMode  
 Define a aparência de estilo plano dos botões da caixa de combinação no aplicativo.  
  
```  
static void SetFlatMode(BOOL bFlat=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bFlat`  
 `TRUE` para uma aparência de estilo plano; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O estilo de padrão simples para os botões da caixa de combinação é `FALSE`.  
  
##  <a name="setstyle"></a>  CMFCToolBarComboBoxButton::SetStyle  
 Define o estilo especificado para a caixa de combinação botão caixa e redesenha o controle se ele não estiver desabilitado.  
  
```  
virtual void SetStyle(UINT nStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nStyle`  
 Uma combinação bit a bit (ou) de estilos de barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Para obter uma lista de estilos de botão da barra de ferramentas, consulte [estilos de controle de barra de ferramentas](../../mfc/reference/toolbar-control-styles.md)  
  
##  <a name="settext"></a>  CMFCToolBarComboBoxButton::SetText  
 Define o texto na caixa de edição da caixa de combinação de botão da caixa.  
  
```  
void SetText(LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszText`  
 Ponteiro para uma cadeia de caracteres que que contém o texto da caixa de edição.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)   
 [Classe CComboBox](../../mfc/reference/ccombobox-class.md)   
 [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton)   
 [Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)



