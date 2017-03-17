---
title: Classe CMFCHeaderCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCHeaderCtrl
- AFXHEADERCTRL/CMFCHeaderCtrl
- AFXHEADERCTRL/CMFCHeaderCtrl::CMFCHeaderCtrl
- AFXHEADERCTRL/CMFCHeaderCtrl::EnableMultipleSort
- AFXHEADERCTRL/CMFCHeaderCtrl::GetColumnState
- AFXHEADERCTRL/CMFCHeaderCtrl::GetSortColumn
- AFXHEADERCTRL/CMFCHeaderCtrl::IsAscending
- AFXHEADERCTRL/CMFCHeaderCtrl::IsDialogControl
- AFXHEADERCTRL/CMFCHeaderCtrl::IsMultipleSort
- AFXHEADERCTRL/CMFCHeaderCtrl::RemoveSortColumn
- AFXHEADERCTRL/CMFCHeaderCtrl::SetSortColumn
- AFXHEADERCTRL/CMFCHeaderCtrl::OnDrawItem
- AFXHEADERCTRL/CMFCHeaderCtrl::OnDrawSortArrow
- AFXHEADERCTRL/CMFCHeaderCtrl::OnFillBackground
dev_langs:
- C++
helpviewer_keywords:
- CMFCHeaderCtrl class
ms.assetid: 2f5fbf7b-5c75-42db-9216-640b1628f777
caps.latest.revision: 29
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: c49ee61b6441e79a0c3c4c1aa133b4bce1578103
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcheaderctrl-class"></a>Classe CMFCHeaderCtrl
O `CMFCHeaderCtrl` classe dá suporte à classificação de várias colunas em um controle de cabeçalho.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCHeaderCtrl : public CHeaderCtrl  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCHeaderCtrl::CMFCHeaderCtrl](#cmfcheaderctrl)|Constrói um objeto `CMFCHeaderCtrl`.|  
|`CMFCHeaderCtrl::~CMFCHeaderCtrl`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCHeaderCtrl::EnableMultipleSort](#enablemultiplesort)|Habilita ou desabilita *classificação de várias colunas* modo para o controle de cabeçalho atual.|  
|[CMFCHeaderCtrl::GetColumnState](#getcolumnstate)|Indica se uma coluna não está classificada, ou é classificada em ordem crescente ou decrescente.|  
|[CMFCHeaderCtrl::GetSortColumn](#getsortcolumn)|Retorna o índice baseado em zero da primeira coluna classificada no controle de cabeçalho.|  
|`CMFCHeaderCtrl::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCHeaderCtrl::IsAscending](#isascending)|Indica se qualquer coluna no controle de cabeçalho é classificada em ordem crescente.|  
|[CMFCHeaderCtrl::IsDialogControl](#isdialogcontrol)|Indica se a janela pai do controle de cabeçalho atual é uma caixa de diálogo.|  
|[CMFCHeaderCtrl::IsMultipleSort](#ismultiplesort)|Indica se o controle de cabeçalho atual é *classificação de várias colunas* modo.|  
|[CMFCHeaderCtrl::RemoveSortColumn](#removesortcolumn)|Remove a coluna especificada da lista de colunas de classificação.|  
|[CMFCHeaderCtrl::SetSortColumn](#setsortcolumn)|Define a ordem de classificação de uma coluna especificada em um controle de cabeçalho.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCHeaderCtrl::OnDrawItem](#ondrawitem)|Chamado pela estrutura para desenhar uma coluna do controle de cabeçalho.|  
|[CMFCHeaderCtrl::OnDrawSortArrow](#ondrawsortarrow)|Chamado pela estrutura para desenhar a direção de classificação.|  
|[CMFCHeaderCtrl::OnFillBackground](#onfillbackground)|Chamado pela estrutura para preencher o plano de fundo de uma coluna do controle de cabeçalho.|  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um objeto de `CMFCHeaderCtrl` classe e como habilitar *classificação de várias colunas* modo para o controle de cabeçalho atual.  
  
 [!code-cpp[NVC_MFC_RibbonApp&#24;](../../mfc/reference/codesnippet/cpp/cmfcheaderctrl-class_1.cpp)]  
  
## <a name="remarks"></a>Comentários  
 O `CMFCHeaderCtrl` classe desenha uma seta de classificação em uma coluna de controle de cabeçalho para indicar que a coluna está classificada. Use *classificação de várias colunas* modo se um conjunto de colunas no controle de lista pai ( [CMFCListCtrl classe](../../mfc/reference/cmfclistctrl-class.md)) podem ser classificados ao mesmo tempo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CHeaderCtrl](../../mfc/reference/cheaderctrl-class.md)  
  
 [CMFCHeaderCtrl](../../mfc/reference/cmfcheaderctrl-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxheaderctrl.h  
  
##  <a name="cmfcheaderctrl"></a>CMFCHeaderCtrl::CMFCHeaderCtrl  
 Constrói um objeto `CMFCHeaderCtrl`.  
  
```  
CMFCHeaderCtrl::CMFCHeaderCtrl()  
```  
  
### <a name="remarks"></a>Comentários  
 Este construtor inicializa as seguintes variáveis de membro com os valores especificados:  
  
|Variável de membro|Valor|  
|---------------------|-----------|  
|`m_bIsMousePressed`|`FALSE`|  
|`m_bMultipleSort`|`FALSE`|  
|`m_bAscending`|`TRUE`|  
|`m_nHighlightedItem`|-1|  
|`m_bTracked`|`FALSE`|  
|`m_bIsDlgControl`|`FALSE`|  
|`m_hFont`|`NULL`|  
  
##  <a name="enablemultiplesort"></a>CMFCHeaderCtrl::EnableMultipleSort  
 Habilita ou desabilita *classificação de várias colunas* modo para o controle de cabeçalho atual.  
  
```  
void EnableMultipleSort(BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar o modo de classificação de coluna vários; `FALSE` para desabilitar o modo de classificar várias colunas e remover todas as colunas da lista de colunas classificadas. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para habilitar ou desabilitar o modo de classificar várias colunas. Duas ou mais colunas podem participar em uma classificação, se o controle de cabeçalho está em modo de classificar várias colunas.  
  
##  <a name="getcolumnstate"></a>CMFCHeaderCtrl::GetColumnState  
 Indica se uma coluna é classificada, ou é classificada em ordem crescente ou decrescente.  
  
```  
int GetColumnState(int iColumn) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iColumn`  
 O índice com base em zero de uma coluna.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que indica o status de classificação da coluna especificada. A tabela a seguir lista os valores possíveis:  
  
|Valor|Descrição|  
|-----------|-----------------|  
|-1|Classificado em ordem decrescente.|  
|0|Não classificado.|  
|1|Classificada em ordem crescente.|  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getsortcolumn"></a>CMFCHeaderCtrl::GetSortColumn  
 Retorna o índice baseado em zero da primeira coluna classificada no controle de cabeçalho.  
  
```  
int GetSortColumn() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de uma coluna classificada ou -1 não se for encontrada nenhuma coluna classificada.  
  
### <a name="remarks"></a>Comentários  
 Se o controle de cabeçalho está em *classificação de várias colunas* modo e você compilou o aplicativo no modo de depuração, esse método declara e recomenda que você use o [CMFCHeaderCtrl::GetColumnState](#getcolumnstate) método em vez disso. Se o controle de cabeçalho está em modo de classificar várias colunas e você tiver compilado o aplicativo no modo de varejo, esse método retornará -1.  
  
##  <a name="isascending"></a>CMFCHeaderCtrl::IsAscending  
 Indica se qualquer coluna no controle de cabeçalho é classificada em ordem crescente.  
  
```  
BOOL IsAscending() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se qualquer coluna no controle de cabeçalho é classificada em ordem crescente; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O valor retornado por esse método é usado para exibir a seta de classificação apropriado no item de controle de cabeçalho. Use o [CMFCHeaderCtrl::SetSortColumn](#setsortcolumn) método para definir a ordem de classificação.  
  
##  <a name="isdialogcontrol"></a>CMFCHeaderCtrl::IsDialogControl  
 Indica se a janela pai do controle de cabeçalho atual é uma caixa de diálogo.  
  
```  
BOOL IsDialogControl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela pai do controle de cabeçalho atual é uma caixa de diálogo. Caso contrário, `FALSE`.  
  
##  <a name="ismultiplesort"></a>CMFCHeaderCtrl::IsMultipleSort  
 Indica se o controle de cabeçalho atual é *classificação de várias colunas* modo.  
  
```  
BOOL IsMultipleSort() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o modo de classificar várias colunas estiver habilitado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use o [CMFCHeaderCtrl::EnableMultipleSort](#enablemultiplesort) método para habilitar ou desabilitar o modo de classificar várias colunas. Duas ou mais colunas podem participar em uma classificação, se o controle de cabeçalho está em modo de classificar várias colunas.  
  
##  <a name="ondrawitem"></a>CMFCHeaderCtrl::OnDrawItem  
 Chamado pela estrutura para desenhar uma coluna do controle de cabeçalho.  
  
```  
virtual void OnDrawItem(
    CDC* pDC,  
    int iItem,  
    CRect rect,  
    BOOL bIsPressed,  
    BOOL bIsHighlighted);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `iItem`  
 O índice baseado em zero do item para desenhar.  
  
 [in] `rect`  
 O retângulo delimitador de item para desenhar.  
  
 [in] `bIsPressed`  
 `TRUE`Para desenhar o item no estado pressionado. Caso contrário, `FALSE`.  
  
 [in] `bIsHighlighted`  
 `TRUE`Para desenhar o item realçado estado; Caso contrário, `FALSE`.  
  
##  <a name="ondrawsortarrow"></a>CMFCHeaderCtrl::OnDrawSortArrow  
 Chamado pela estrutura para desenhar a direção de classificação.  
  
```  
virtual void OnDrawSortArrow(
    CDC* pDC,  
    CRect rectArrow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rectArrow`  
 O retângulo delimitador da seta de classificação.  
  
##  <a name="onfillbackground"></a>CMFCHeaderCtrl::OnFillBackground  
 Chamado pela estrutura para preencher o plano de fundo de uma coluna do controle de cabeçalho.  
  
```  
virtual void OnFillBackground(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="removesortcolumn"></a>CMFCHeaderCtrl::RemoveSortColumn  
 Remove a coluna especificada da lista de colunas de classificação.  
  
```  
void RemoveSortColumn(int iColumn);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iColumn`  
 O índice baseado em zero da coluna a ser removida.  
  
##  <a name="setsortcolumn"></a>CMFCHeaderCtrl::SetSortColumn  
 Define a ordem de classificação de uma coluna especificada em um controle de cabeçalho.  
  
```  
void SetSortColumn(
    int iColumn,  
    BOOL bAscending=TRUE,  
    BOOL bAdd=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iColumn`  
 O índice com base em zero de uma coluna do controle de cabeçalho. Se esse parâmetro for menor que zero, esse método Remove todas as colunas da lista de colunas de classificação.  
  
 [in] `bAscending`  
 Especifica a ordem de classificação da coluna que o `iColumn` parâmetro especifica. `TRUE`Para definir a ordem crescente; `FALSE` para definir a ordem decrescente. O valor padrão é `TRUE`.  
  
 [in] `bAdd`  
 `TRUE`Para definir a ordem de classificação da coluna que o `iColumn` parâmetro especifica.  
  
 Se o controle de cabeçalho atual está em *classificação de várias colunas* modo, este método adiciona a coluna especificada à lista de colunas de classificação. Use [CMFCHeaderCtrl::EnableMultipleSort](#enablemultiplesort) para definir o modo de classificar várias colunas.  
  
 Se vários modo de classificação de coluna não está definido e esse método é compilado no modo de depuração, esse método declara. Se vários modo de classificação de coluna não está definido e esse método é compilado no modo de varejo, esse método primeiramente remove todas as colunas da lista de colunas de classificação e, em seguida, adiciona a coluna especificada à lista.  
  
 `FALSE`primeiro remova todas as colunas da lista de colunas de classificação e, em seguida, adicionar a coluna especificada à lista. O valor padrão é `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para definir a ordem de classificação de uma coluna. Se necessário, este método adiciona a coluna à lista de colunas de classificação. O controle de cabeçalho usa a ordem de classificação para desenhar uma seta que aponta para cima ou para baixo para classificação.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)

