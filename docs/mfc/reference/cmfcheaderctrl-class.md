---
title: Classe CMFCHeaderCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CMFCHeaderCtrl [MFC], CMFCHeaderCtrl
- CMFCHeaderCtrl [MFC], EnableMultipleSort
- CMFCHeaderCtrl [MFC], GetColumnState
- CMFCHeaderCtrl [MFC], GetSortColumn
- CMFCHeaderCtrl [MFC], IsAscending
- CMFCHeaderCtrl [MFC], IsDialogControl
- CMFCHeaderCtrl [MFC], IsMultipleSort
- CMFCHeaderCtrl [MFC], RemoveSortColumn
- CMFCHeaderCtrl [MFC], SetSortColumn
- CMFCHeaderCtrl [MFC], OnDrawItem
- CMFCHeaderCtrl [MFC], OnDrawSortArrow
- CMFCHeaderCtrl [MFC], OnFillBackground
ms.assetid: 2f5fbf7b-5c75-42db-9216-640b1628f777
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3a1c10cd6242f2845d64965d914093455da21c8a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cmfcheaderctrl-class"></a>Classe CMFCHeaderCtrl
O `CMFCHeaderCtrl` classe dá suporte à classificação de várias colunas em um controle de cabeçalho.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCHeaderCtrl : public CHeaderCtrl  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCHeaderCtrl::CMFCHeaderCtrl](#cmfcheaderctrl)|Constrói um objeto `CMFCHeaderCtrl`.|  
|`CMFCHeaderCtrl::~CMFCHeaderCtrl`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCHeaderCtrl::EnableMultipleSort](#enablemultiplesort)|Habilita ou desabilita *classificação de várias colunas* modo para o controle de cabeçalho atual.|  
|[CMFCHeaderCtrl::GetColumnState](#getcolumnstate)|Indica se uma coluna não está classificada, ou é classificada em ordem crescente ou decrescente.|  
|[CMFCHeaderCtrl::GetSortColumn](#getsortcolumn)|Recupera o índice com base em zero da primeira coluna classificada no controle de cabeçalho.|  
|`CMFCHeaderCtrl::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCHeaderCtrl::IsAscending](#isascending)|Indica se qualquer coluna no controle de cabeçalho é classificada em ordem crescente.|  
|[CMFCHeaderCtrl::IsDialogControl](#isdialogcontrol)|Indica se a janela pai do controle de cabeçalho atual é uma caixa de diálogo.|  
|[CMFCHeaderCtrl::IsMultipleSort](#ismultiplesort)|Indica se o controle de cabeçalho atual está em *classificação de várias colunas* modo.|  
|[CMFCHeaderCtrl::RemoveSortColumn](#removesortcolumn)|Remove a coluna especificada na lista de colunas de classificação.|  
|[CMFCHeaderCtrl::SetSortColumn](#setsortcolumn)|Define a ordem de classificação de uma coluna especificada em um controle de cabeçalho.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCHeaderCtrl::OnDrawItem](#ondrawitem)|Chamado pelo framework para desenhar uma coluna do controle de cabeçalho.|  
|[CMFCHeaderCtrl::OnDrawSortArrow](#ondrawsortarrow)|Chamado pelo framework para desenhar a direção de classificação.|  
|[CMFCHeaderCtrl::OnFillBackground](#onfillbackground)|Chamado pelo framework para preencher o plano de fundo de uma coluna de controle de cabeçalho.|  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um objeto de `CMFCHeaderCtrl` classe e como habilitar *classificação de várias colunas* modo para o controle de cabeçalho atual.  
  
 [!code-cpp[NVC_MFC_RibbonApp#24](../../mfc/reference/codesnippet/cpp/cmfcheaderctrl-class_1.cpp)]  
  
## <a name="remarks"></a>Comentários  
 O `CMFCHeaderCtrl` classe desenha uma seta de classificação em uma coluna de controle de cabeçalho para indicar que a coluna está classificada. Use *classificação de várias colunas* modo, se um conjunto de colunas no controle de lista pai ( [CMFCListCtrl classe](../../mfc/reference/cmfclistctrl-class.md)) podem ser classificados ao mesmo tempo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CHeaderCtrl](../../mfc/reference/cheaderctrl-class.md)  
  
 [CMFCHeaderCtrl](../../mfc/reference/cmfcheaderctrl-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxheaderctrl.h  
  
##  <a name="cmfcheaderctrl"></a>  CMFCHeaderCtrl::CMFCHeaderCtrl  
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
  
##  <a name="enablemultiplesort"></a>  CMFCHeaderCtrl::EnableMultipleSort  
 Habilita ou desabilita *classificação de várias colunas* modo para o controle de cabeçalho atual.  
  
```  
void EnableMultipleSort(BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE` Para habilitar o modo de classificação de coluna vários; `FALSE` para desabilitar o modo de classificar várias colunas e remova todas as colunas da lista de colunas classificadas. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para habilitar ou desabilitar o modo de classificar várias colunas. Duas ou mais colunas podem participar em uma classificação, se o controle de cabeçalho estiver no modo de classificar várias colunas.  
  
##  <a name="getcolumnstate"></a>  CMFCHeaderCtrl::GetColumnState  
 Indica se uma coluna não está classificada ou é classificada em ordem crescente ou decrescente.  
  
```  
int GetColumnState(int iColumn) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iColumn`  
 O índice de base zero de uma coluna.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que indica o status de classificação da coluna especificada. A tabela a seguir lista os valores possíveis:  
  
|Valor|Descrição|  
|-----------|-----------------|  
|-1|Classificado em ordem decrescente.|  
|0|Não classificada.|  
|1|Classificada em ordem crescente.|  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getsortcolumn"></a>  CMFCHeaderCtrl::GetSortColumn  
 Recupera o índice com base em zero da primeira coluna classificada no controle de cabeçalho.  
  
```  
int GetSortColumn() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de uma coluna classificada ou -1 se nenhuma coluna classificada foi encontrada.  
  
### <a name="remarks"></a>Comentários  
 Se o controle de cabeçalho está *classificação de várias colunas* modo e o aplicativo no modo de depuração, esse método declara e compilado aconselha a usar o [CMFCHeaderCtrl::GetColumnState](#getcolumnstate) método em vez disso. Se o controle de cabeçalho está em modo de classificar várias colunas e você compilou o aplicativo no modo de varejo, esse método retornará -1.  
  
##  <a name="isascending"></a>  CMFCHeaderCtrl::IsAscending  
 Indica se qualquer coluna no controle de cabeçalho é classificada em ordem crescente.  
  
```  
BOOL IsAscending() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se qualquer coluna no controle de cabeçalho é classificada em ordem crescente; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O valor retornado por esse método é usado para exibir a seta de classificação apropriado no item de controle de cabeçalho. Use o [CMFCHeaderCtrl::SetSortColumn](#setsortcolumn) método para definir a ordem de classificação.  
  
##  <a name="isdialogcontrol"></a>  CMFCHeaderCtrl::IsDialogControl  
 Indica se a janela pai do controle de cabeçalho atual é uma caixa de diálogo.  
  
```  
BOOL IsDialogControl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se a janela pai do controle de cabeçalho atual é uma caixa de diálogo Caso contrário, `FALSE`.  
  
##  <a name="ismultiplesort"></a>  CMFCHeaderCtrl::IsMultipleSort  
 Indica se o controle de cabeçalho atual está em *classificação de várias colunas* modo.  
  
```  
BOOL IsMultipleSort() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se vários modo de classificação de coluna estiver habilitado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use o [CMFCHeaderCtrl::EnableMultipleSort](#enablemultiplesort) método para habilitar ou desabilitar o modo de classificar várias colunas. Duas ou mais colunas podem participar em uma classificação, se o controle de cabeçalho estiver no modo de classificar várias colunas.  
  
##  <a name="ondrawitem"></a>  CMFCHeaderCtrl::OnDrawItem  
 Chamado pelo framework para desenhar uma coluna do controle de cabeçalho.  
  
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
 O índice de base zero do item para desenhar.  
  
 [in] `rect`  
 O retângulo delimitador de item para desenhar.  
  
 [in] `bIsPressed`  
 `TRUE` Para desenhar o item em um estado pressionado; Caso contrário, `FALSE`.  
  
 [in] `bIsHighlighted`  
 `TRUE` Para desenhar o item realçado estado; Caso contrário, `FALSE`.  
  
##  <a name="ondrawsortarrow"></a>  CMFCHeaderCtrl::OnDrawSortArrow  
 Chamado pelo framework para desenhar a direção de classificação.  
  
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
  
##  <a name="onfillbackground"></a>  CMFCHeaderCtrl::OnFillBackground  
 Chamado pelo framework para preencher o plano de fundo de uma coluna de controle de cabeçalho.  
  
```  
virtual void OnFillBackground(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="removesortcolumn"></a>  CMFCHeaderCtrl::RemoveSortColumn  
 Remove a coluna especificada na lista de colunas de classificação.  
  
```  
void RemoveSortColumn(int iColumn);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iColumn`  
 O índice baseado em zero da coluna a ser removida.  
  
##  <a name="setsortcolumn"></a>  CMFCHeaderCtrl::SetSortColumn  
 Define a ordem de classificação de uma coluna especificada em um controle de cabeçalho.  
  
```  
void SetSortColumn(
    int iColumn,  
    BOOL bAscending=TRUE,  
    BOOL bAdd=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iColumn`  
 O índice de base zero de uma coluna de controle de cabeçalho. Se esse parâmetro for menor que zero, este método Remove todas as colunas da lista de colunas de classificação.  
  
 [in] `bAscending`  
 Especifica a ordem de classificação da coluna que o `iColumn` parâmetro especifica. `TRUE` Para definir a ordem crescente; `FALSE` para definir a ordem decrescente. O valor padrão é `TRUE`.  
  
 [in] `bAdd`  
 `TRUE` Para definir a ordem de classificação da coluna que o `iColumn` parâmetro especifica.  
  
 Se o controle de cabeçalho atual está no *classificação de várias colunas* modo, este método adiciona a coluna especificada à lista de colunas de classificação. Use [CMFCHeaderCtrl::EnableMultipleSort](#enablemultiplesort) para definir o modo de classificar várias colunas.  
  
 Se vários modo de classificação de coluna não está definido e esse método é compilado no modo de depuração, use esse método. Se vários modo de classificação de coluna não está definido e esse método é compilado no modo de varejo, este método primeiro remove todas as colunas da lista de colunas de classificação e, em seguida, adiciona a coluna especificada à lista.  
  
 `FALSE` primeiro remova todas as colunas da lista de colunas de classificação e, em seguida, adicionar a coluna especificada à lista. O valor padrão é `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para definir a ordem de classificação de uma coluna. Se necessário, este método adiciona a coluna à lista de colunas de classificação. O controle de cabeçalho usa a ordem de classificação para desenhar uma seta que aponta para cima ou para baixo para classificação.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)
