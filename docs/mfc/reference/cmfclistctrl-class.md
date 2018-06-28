---
title: Classe CMFCListCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCListCtrl
- AFXLISTCTRL/CMFCListCtrl
- AFXLISTCTRL/CMFCListCtrl::EnableMarkSortedColumn
- AFXLISTCTRL/CMFCListCtrl::EnableMultipleSort
- AFXLISTCTRL/CMFCListCtrl::GetHeaderCtrl
- AFXLISTCTRL/CMFCListCtrl::IsMultipleSort
- AFXLISTCTRL/CMFCListCtrl::OnCompareItems
- AFXLISTCTRL/CMFCListCtrl::OnGetCellBkColor
- AFXLISTCTRL/CMFCListCtrl::OnGetCellFont
- AFXLISTCTRL/CMFCListCtrl::OnGetCellTextColor
- AFXLISTCTRL/CMFCListCtrl::RemoveSortColumn
- AFXLISTCTRL/CMFCListCtrl::SetSortColumn
- AFXLISTCTRL/CMFCListCtrl::Sort
dev_langs:
- C++
helpviewer_keywords:
- CMFCListCtrl [MFC], EnableMarkSortedColumn
- CMFCListCtrl [MFC], EnableMultipleSort
- CMFCListCtrl [MFC], GetHeaderCtrl
- CMFCListCtrl [MFC], IsMultipleSort
- CMFCListCtrl [MFC], OnCompareItems
- CMFCListCtrl [MFC], OnGetCellBkColor
- CMFCListCtrl [MFC], OnGetCellFont
- CMFCListCtrl [MFC], OnGetCellTextColor
- CMFCListCtrl [MFC], RemoveSortColumn
- CMFCListCtrl [MFC], SetSortColumn
- CMFCListCtrl [MFC], Sort
ms.assetid: 50d16aee-138c-4f34-8690-cb75d544ef2e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 00933a392486064fac7c9a526d8b0c096703460c
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37037718"
---
# <a name="cmfclistctrl-class"></a>Classe CMFCListCtrl
O `CMFCListCtrl` classe estende a funcionalidade do [classe CListCtrl](../../mfc/reference/clistctrl-class.md) classe, dando suporte a funcionalidade de controle de cabeçalho avançadas do [CMFCHeaderCtrl classe](../../mfc/reference/cmfcheaderctrl-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCListCtrl : public CListCtrl  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCListCtrl::EnableMarkSortedColumn](#enablemarksortedcolumn)|Habilita a capacidade de marcar uma coluna classificada com uma cor de plano de fundo diferentes.|  
|[CMFCListCtrl::EnableMultipleSort](#enablemultiplesort)|Habilita o modo de classificação de vários.|  
|[CMFCListCtrl::GetHeaderCtrl](#getheaderctrl)|Retorna uma referência ao controle de cabeçalho sublinhado.|  
|[CMFCListCtrl::IsMultipleSort](#ismultiplesort)|Verifica se o controle de lista está no modo de classificação de vários.|  
|[CMFCListCtrl::OnCompareItems](#oncompareitems)|Chamado pelo framework quando ele precisa comparar dois itens de controle de lista.|  
|[CMFCListCtrl::OnGetCellBkColor](#ongetcellbkcolor)|Chamado pelo framework quando ele deve determinar a cor de plano de fundo de uma célula individual.|  
|[CMFCListCtrl::OnGetCellFont](#ongetcellfont)|Chamado pelo framework quando ela deve obter a fonte para a célula que está sendo desenhada.|  
|[CMFCListCtrl::OnGetCellTextColor](#ongetcelltextcolor)|Chamado pelo framework quando ele deve determinar a cor do texto de uma célula individual.|  
|[CMFCListCtrl::RemoveSortColumn](#removesortcolumn)|Remove uma coluna de classificação da lista de colunas classificadas.|  
|[CMFCListCtrl::SetSortColumn](#setsortcolumn)|Define a coluna classificada atual e a ordem de classificação.|  
|[CMFCListCtrl::Sort](#sort)|Classifica o controle de lista.|  
  
## <a name="remarks"></a>Comentários  
 `CMFCListCtrl` oferece dois aprimoramentos [classe CListCtrl](../../mfc/reference/clistctrl-class.md) classe. Primeiro, indica que a coluna de classificação é uma opção disponível desenhando automaticamente uma direção de classificação no cabeçalho. Em segundo lugar, ele oferece suporte a dados de classificação em várias colunas ao mesmo tempo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCListCtrl` classe. O exemplo mostra como criar um controle de lista, colunas de inserção, inserir itens, definir o texto de um item e definir a fonte do controle de lista. Este trecho de código é parte do [exemplo de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#25](../../mfc/codesnippet/cpp/cmfclistctrl-class_1.h)]  
[!code-cpp[NVC_MFC_VisualStudioDemo#26](../../mfc/codesnippet/cpp/cmfclistctrl-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CListCtrl](../../mfc/reference/clistctrl-class.md)  
  
 [CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxlistctrl.h  
  
##  <a name="enablemarksortedcolumn"></a>  CMFCListCtrl::EnableMarkSortedColumn  
 Marca as colunas classificadas com uma cor de plano de fundo diferentes.  
  
```  
void EnableMarkSortedColumn(
    BOOL bMark = TRUE,  
    BOOL bRedraw = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bMark*  
 Um parâmetro booliano que determina se é necessário habilitar uma cor de plano de fundo diferentes.  
  
 [in] *bRedraw*  
 Um parâmetro booliano que determina se deve redesenhar o controle imediatamente.  
  
### <a name="remarks"></a>Comentários  
 `EnableMarkSortedColumn` usa o método `CDrawingManager::PixelAlpha` calcular a cor a ser usado para colunas de classificados. A cor escolhida baseia-se a cor de plano de fundo regulares.  
  
##  <a name="enablemultiplesort"></a>  CMFCListCtrl::EnableMultipleSort  
 Permite que as linhas de dados na lista de controle de classificação por várias colunas.  
  
```  
void EnableMultipleSort(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bAtivar*  
 Um valor booleano que especifica se é para habilitar o modo de classificar várias colunas.  
  
### <a name="remarks"></a>Comentários  
 Quando você ativar a classificação com base em várias colunas, as colunas têm uma hierarquia. As linhas de dados serão classificadas primeiro pela coluna principal. Quaisquer valores equivalentes, em seguida, são classificados por cada coluna subsequente com base na prioridade.  
  
##  <a name="getheaderctrl"></a>  CMFCListCtrl::GetHeaderCtrl  
 Retorna uma referência ao controle de cabeçalho.  
  
```  
virtual CMFCHeaderCtrl& GetHeaderCtrl();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para o subjacente [CMFCHeaderCtrl](../../mfc/reference/cmfcheaderctrl-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 O controle de cabeçalho para um controle de lista é a janela que contém os títulos de colunas. Geralmente é posicionado diretamente acima das colunas.  
  
##  <a name="ismultiplesort"></a>  CMFCListCtrl::IsMultipleSort  
 Verifica se o controle de lista atualmente suporta classificação em várias colunas.  
  
```  
BOOL IsMultipleSort() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o controle de lista dá suporte a vários classificação; `FALSE` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Quando um [CMFCListCtrl classe](../../mfc/reference/cmfclistctrl-class.md) dá suporte à classificação de várias, o usuário pode classificar os dados no controle de lista por várias colunas. Para habilitar a classificação de várias, chame [CMFCListCtrl::EnableMultipleSort](#enablemultiplesort).  
  
##  <a name="oncompareitems"></a>  CMFCListCtrl::OnCompareItems  
 O framework chama este método quando ele se compara dois itens.  
  
```  
virtual int OnCompareItems(
    LPARAM lParam1,  
    LPARAM lParam2,  
    int iColumn);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lParam1*  
 O primeiro item a ser comparado.  
  
 [in] *lParam2*  
 O segundo item a ser comparado.  
  
 [in] *iColumn*  
 O índice da coluna que está classificando este método.  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro que indica a posição relativa dos dois itens. Um valor negativo indica que o primeiro item deve preceder o segundo, um valor positivo indica que o primeiro item deve seguir o segundo e zero significa que os dois itens são equivalentes.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão sempre retorna 0. Você deve substituir essa função para fornecer um algoritmo de classificação.  
  
##  <a name="ongetcellbkcolor"></a>  CMFCListCtrl::OnGetCellBkColor  
 O framework chama este método quando ele deve determinar a cor de plano de fundo de uma célula individual.  
  
```  
virtual COLORREF OnGetCellBkColor(
    int nRow,  
    int nColumn);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nRow`  
 A linha da célula em questão.  
  
 [in] `nColumn`  
 A coluna da célula em questão.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `COLOREF` valor que especifica a cor de plano de fundo da célula.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão de `OnGetCellBkColor` não usa os parâmetros de entrada fornecidos e em vez disso, simplesmente chama `GetBkColor`. Portanto, por padrão, o controle de toda a lista terá a mesma cor de plano de fundo. Você pode substituir `OnGetCellBkColor` em uma classe derivada para marcar células individuais com uma cor de plano de fundo separada.  
  
##  <a name="ongetcellfont"></a>  CMFCListCtrl::OnGetCellFont  
 O framework chama este método quando ele obtém a fonte de uma célula individual.  
  
```  
virtual HFONT OnGetCellFont(
    int nRow,  
    int nColumn,  
    DWORD dwData = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *nRow*  
 A linha da célula em questão.  
  
 [in] *nColumn*  
 A coluna da célula em questão.  
  
 [in] *dwData*  
 Dados definidos pelo usuário. A implementação padrão não use esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para a fonte que é usado para a célula atual.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método retorna `NULL`. Todas as células em um controle de lista tem a mesma fonte. Substitua este método para fornecer diferentes fontes de células diferentes.  
  
##  <a name="ongetcelltextcolor"></a>  CMFCListCtrl::OnGetCellTextColor  
 O framework chama este método quando ele deve determinar a cor do texto de uma célula individual.  
  
```  
virtual COLORREF OnGetCellTextColor(
    int nRow,  
    int nColumn);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *nRow*  
 A linha da célula em questão.  
  
 [in] *nColumn*  
 A coluna da célula em questão.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `COLOREF` valor que especifica a cor do texto da célula.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, este método chama `GetTextColor` independentemente de parâmetros de entrada. O controle de toda a lista terá a mesma cor do texto. Você pode substituir `OnGetCellTextColor` em uma classe derivada para marcar células individuais com uma cor de texto separado.  
  
##  <a name="removesortcolumn"></a>  CMFCListCtrl::RemoveSortColumn  
 Remove uma coluna de classificação da lista de colunas classificadas.  
  
```  
void RemoveSortColumn(int iColumn);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *iColumn*  
 A coluna a ser removida.  
  
### <a name="remarks"></a>Comentários  
 Este método Remove uma coluna de classificação do controle de cabeçalho. Ele chama [CMFCHeaderCtrl::RemoveSortColumn](../../mfc/reference/cmfcheaderctrl-class.md#removesortcolumn).  
  
##  <a name="setsortcolumn"></a>  CMFCListCtrl::SetSortColumn  
 Define a coluna classificada atual e a ordem de classificação.  
  
```  
void SetSortColumn(
    int iColumn,  
    BOOL bAscending = TRUE,  
    BOOL bAdd = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *iColumn*  
 A coluna a ser classificada.  
  
 [in] *bAscending*  
 Um booliano que especifica a ordem de classificação.  
  
 [in] *bAdicionar*  
 Um valor booleano que especifica se o método adiciona a coluna indicada pelo *iColumn* à lista de colunas de classificação.  
  
### <a name="remarks"></a>Comentários  
 Esse método passa os parâmetros de entrada para o controle de cabeçalho usando o método [CMFCHeaderCtrl::SetSortColumn](../../mfc/reference/cmfcheaderctrl-class.md#setsortcolumn).  
  
##  <a name="sort"></a>  CMFCListCtrl::Sort  
 Classifica o controle de lista.  
  
```  
virtual void Sort(
    int iColumn,  
    BOOL bAscending = TRUE,  
    BOOL bAdd = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *iColumn*  
 A coluna a ser classificada.  
  
 [in] *bAscending*  
 Um booliano que especifica a ordem de classificação.  
  
 [in] *bAdicionar*  
 Um valor booleano que especifica se este método adiciona a coluna indicada pelo *iColumn* à lista de colunas de classificação.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CListCtrl](../../mfc/reference/clistctrl-class.md)
