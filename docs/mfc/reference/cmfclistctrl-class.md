---
title: Classe CMFCListCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCListCtrl
dev_langs:
- C++
helpviewer_keywords:
- CMFCListCtrl class
ms.assetid: 50d16aee-138c-4f34-8690-cb75d544ef2e
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
ms.openlocfilehash: 3a4c67b2d7ea2a5356f7c053403edf414319a928
ms.lasthandoff: 02/25/2017

---
# <a name="cmfclistctrl-class"></a>Classe CMFCListCtrl
O `CMFCListCtrl` classe estende a funcionalidade do [classe CListCtrl](../../mfc/reference/clistctrl-class.md) classe, dando suporte a funcionalidade de controle de cabeçalho avançada do [CMFCHeaderCtrl classe](../../mfc/reference/cmfcheaderctrl-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCListCtrl : public CListCtrl  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCListCtrl::EnableMarkSortedColumn](#enablemarksortedcolumn)|Habilita a capacidade de marcar uma coluna classificada com uma cor de plano de fundo diferente.|  
|[CMFCListCtrl::EnableMultipleSort](#enablemultiplesort)|Habilita o modo de classificação de vários.|  
|[CMFCListCtrl::GetHeaderCtrl](#getheaderctrl)|Retorna uma referência ao controle de cabeçalho sublinhado.|  
|[CMFCListCtrl::IsMultipleSort](#ismultiplesort)|Verifica se o controle de lista está no modo de classificação de vários.|  
|[CMFCListCtrl::OnCompareItems](#oncompareitems)|Chamado pela estrutura quando ele deve comparar dois itens de controle de lista.|  
|[CMFCListCtrl::OnGetCellBkColor](#ongetcellbkcolor)|Chamado pela estrutura quando ele deve determinar a cor de plano de fundo de uma célula individual.|  
|[CMFCListCtrl::OnGetCellFont](#ongetcellfont)|Chamado pela estrutura quando ele deve obter a fonte para a célula que está sendo desenhada.|  
|[CMFCListCtrl::OnGetCellTextColor](#ongetcelltextcolor)|Chamado pela estrutura quando ele deve determinar a cor do texto de uma célula individual.|  
|[CMFCListCtrl::RemoveSortColumn](#removesortcolumn)|Remove uma coluna de classificação da lista de colunas classificadas.|  
|[CMFCListCtrl::SetSortColumn](#setsortcolumn)|Define a coluna de classificação atual e a ordem de classificação.|  
|[CMFCListCtrl::Sort](#sort)|Classifica o controle de lista.|  
  
## <a name="remarks"></a>Comentários  
 `CMFCListCtrl`oferece dois aprimoramentos [classe CListCtrl](../../mfc/reference/clistctrl-class.md) classe. Primeiro, ele indica que a coluna de classificação é uma opção disponível automaticamente desenhando uma direção de classificação no cabeçalho. Em segundo lugar, ele oferece suporte a dados de classificação em várias colunas ao mesmo tempo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCListCtrl` classe. O exemplo mostra como criar um controle de lista, colunas de inserção, inserir itens, definir o texto de um item e definir a fonte do controle de lista. Este trecho de código é parte do [exemplo de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[25 NVC_MFC_VisualStudioDemo](../../mfc/codesnippet/cpp/cmfclistctrl-class_1.h)]  
[!code-cpp[NVC_MFC_VisualStudioDemo&#26;](../../mfc/codesnippet/cpp/cmfclistctrl-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CListCtrl](../../mfc/reference/clistctrl-class.md)  
  
 [CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxlistctrl.h  
  
##  <a name="a-nameenablemarksortedcolumna--cmfclistctrlenablemarksortedcolumn"></a><a name="enablemarksortedcolumn"></a>CMFCListCtrl::EnableMarkSortedColumn  
 Marca colunas classificadas com uma cor de plano de fundo diferente.  
  
```  
void EnableMarkSortedColumn(
    BOOL bMark = TRUE,  
    BOOL bRedraw = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bMark`  
 Um parâmetro booleano que determina se é para habilitar uma cor de plano de fundo diferente.  
  
 [in] `bRedraw`  
 Um parâmetro booleano que determina se o controle para redesenhar imediatamente.  
  
### <a name="remarks"></a>Comentários  
 `EnableMarkSortedColumn`usa o método `CDrawingManager::PixelAlpha` calcular a cor a ser usado para colunas de classificados. A cor escolhida baseia-se a cor de plano de fundo regulares.  
  
##  <a name="a-nameenablemultiplesorta--cmfclistctrlenablemultiplesort"></a><a name="enablemultiplesort"></a>CMFCListCtrl::EnableMultipleSort  
 Permite que as linhas de dados na lista de controle de classificação por várias colunas.  
  
```  
void EnableMultipleSort(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 Um valor booleano que especifica se é para habilitar o modo de classificar várias colunas.  
  
### <a name="remarks"></a>Comentários  
 Quando você ativar a classificação com base em várias colunas, as colunas têm uma hierarquia. As linhas de dados serão classificadas primeiro pela coluna principal. Quaisquer valores equivalentes, em seguida, são classificados por cada coluna subsequente com base na prioridade.  
  
##  <a name="a-namegetheaderctrla--cmfclistctrlgetheaderctrl"></a><a name="getheaderctrl"></a>CMFCListCtrl::GetHeaderCtrl  
 Retorna uma referência ao controle de cabeçalho.  
  
```  
virtual CMFCHeaderCtrl& GetHeaderCtrl();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao subjacente [CMFCHeaderCtrl](../../mfc/reference/cmfcheaderctrl-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 O controle de cabeçalho para um controle de lista é a janela que contém os títulos de colunas. Ele geralmente é posicionado diretamente acima das colunas.  
  
##  <a name="a-nameismultiplesorta--cmfclistctrlismultiplesort"></a><a name="ismultiplesort"></a>CMFCListCtrl::IsMultipleSort  
 Verifica se o controle de lista atualmente suporta classificação em várias colunas.  
  
```  
BOOL IsMultipleSort() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o controle de lista oferece suporte a vários classificação; `FALSE` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Quando um [CMFCListCtrl classe](../../mfc/reference/cmfclistctrl-class.md) dá suporte à classificação vários, o usuário pode classificar os dados no controle de lista por várias colunas. Para permitir a classificação de vários, chame [CMFCListCtrl::EnableMultipleSort](#enablemultiplesort).  
  
##  <a name="a-nameoncompareitemsa--cmfclistctrloncompareitems"></a><a name="oncompareitems"></a>CMFCListCtrl::OnCompareItems  
 O framework chama esse método quando ele compara dois itens.  
  
```  
virtual int OnCompareItems(
    LPARAM lParam1,  
    LPARAM lParam2,  
    int iColumn);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lParam1`  
 O primeiro item a ser comparado.  
  
 [in] `lParam2`  
 O segundo item a ser comparado.  
  
 [in] `iColumn`  
 O índice da coluna que está classificando este método.  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro que indica a posição relativa dos dois itens. Um valor negativo indica que o primeiro item deve preceder o segundo, o valor positivo indica que o primeiro item deve seguir o segundo, e zero significa que os dois itens são equivalentes.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão sempre retorna 0. Você deve substituir essa função para fornecer um algoritmo de classificação.  
  
##  <a name="a-nameongetcellbkcolora--cmfclistctrlongetcellbkcolor"></a><a name="ongetcellbkcolor"></a>CMFCListCtrl::OnGetCellBkColor  
 O framework chama esse método quando ele deve determinar a cor de plano de fundo de uma célula individual.  
  
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
  
##  <a name="a-nameongetcellfonta--cmfclistctrlongetcellfont"></a><a name="ongetcellfont"></a>CMFCListCtrl::OnGetCellFont  
 O framework chama esse método quando ele obtém a fonte de uma célula individual.  
  
```  
virtual HFONT OnGetCellFont(
    int nRow,  
    int nColumn,  
    DWORD dwData = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nRow`  
 A linha da célula em questão.  
  
 [in] `nColumn`  
 A coluna da célula em questão.  
  
 [in] `dwData`  
 Dados definidos pelo usuário. A implementação padrão não usa esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para a fonte usada para a célula atual.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método retornará `NULL`. Todas as células em um controle de lista tem a mesma fonte. Substitua esse método para fornecer fontes diferentes para células diferentes.  
  
##  <a name="a-nameongetcelltextcolora--cmfclistctrlongetcelltextcolor"></a><a name="ongetcelltextcolor"></a>CMFCListCtrl::OnGetCellTextColor  
 O framework chama esse método quando ele deve determinar a cor do texto de uma célula individual.  
  
```  
virtual COLORREF OnGetCellTextColor(
    int nRow,  
    int nColumn);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nRow`  
 A linha da célula em questão.  
  
 [in] `nColumn`  
 A coluna da célula em questão.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `COLOREF` valor que especifica a cor do texto da célula.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método chama `GetTextColor` independentemente de parâmetros de entrada. O controle de toda a lista terá a mesma cor do texto. Você pode substituir `OnGetCellTextColor` em uma classe derivada para marcar células individuais com uma cor de texto separado.  
  
##  <a name="a-nameremovesortcolumna--cmfclistctrlremovesortcolumn"></a><a name="removesortcolumn"></a>CMFCListCtrl::RemoveSortColumn  
 Remove uma coluna de classificação da lista de colunas classificadas.  
  
```  
void RemoveSortColumn(int iColumn);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iColumn`  
 Coluna a ser removida.  
  
### <a name="remarks"></a>Comentários  
 Esse método Remove uma coluna de classificação do controle de cabeçalho. Ele chama [CMFCHeaderCtrl::RemoveSortColumn](../../mfc/reference/cmfcheaderctrl-class.md#removesortcolumn).  
  
##  <a name="a-namesetsortcolumna--cmfclistctrlsetsortcolumn"></a><a name="setsortcolumn"></a>CMFCListCtrl::SetSortColumn  
 Define a coluna de classificação atual e a ordem de classificação.  
  
```  
void SetSortColumn(
    int iColumn,  
    BOOL bAscending = TRUE,  
    BOOL bAdd = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iColumn`  
 A coluna para classificar.  
  
 [in] `bAscending`  
 Um valor booleano que especifica a ordem de classificação.  
  
 [in] `bAdd`  
 Um valor booleano que especifica se o método adiciona a coluna indicada pelo `iColumn` à lista de colunas de classificação.  
  
### <a name="remarks"></a>Comentários  
 Esse método passa os parâmetros de entrada para o controle de cabeçalho usando o método [CMFCHeaderCtrl::SetSortColumn](../../mfc/reference/cmfcheaderctrl-class.md#setsortcolumn).  
  
##  <a name="a-namesorta--cmfclistctrlsort"></a><a name="sort"></a>CMFCListCtrl::Sort  
 Classifica o controle de lista.  
  
```  
virtual void Sort(
    int iColumn,  
    BOOL bAscending = TRUE,  
    BOOL bAdd = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iColumn`  
 A coluna para classificar.  
  
 [in] `bAscending`  
 Um valor booleano que especifica a ordem de classificação.  
  
 [in] `bAdd`  
 Um valor booleano que especifica se este método adiciona a coluna indicada pelo `iColumn` à lista de colunas de classificação.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CListCtrl](../../mfc/reference/clistctrl-class.md)

