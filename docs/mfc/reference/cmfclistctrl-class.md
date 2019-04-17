---
title: Classe CMFCListCtrl
ms.date: 11/04/2016
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
ms.openlocfilehash: 4cd1bb7787f8797984bdce5f9a5b3080d69ea5f2
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58767932"
---
# <a name="cmfclistctrl-class"></a>Classe CMFCListCtrl

O `CMFCListCtrl` classe estende a funcionalidade do [classe CListCtrl](../../mfc/reference/clistctrl-class.md) classe dando suporte a funcionalidade de controle de cabeçalho avançada dos [classe CMFCHeaderCtrl](../../mfc/reference/cmfcheaderctrl-class.md).

## <a name="syntax"></a>Sintaxe

```
class CMFCListCtrl : public CListCtrl
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCListCtrl::EnableMarkSortedColumn](#enablemarksortedcolumn)|Habilita a capacidade de marcar uma coluna classificada com uma cor de plano de fundo diferente.|
|[CMFCListCtrl::EnableMultipleSort](#enablemultiplesort)|Habilita o modo de classificação de várias.|
|[CMFCListCtrl::GetHeaderCtrl](#getheaderctrl)|Retorna uma referência ao controle de cabeçalho de sublinhado.|
|[CMFCListCtrl::IsMultipleSort](#ismultiplesort)|Verifica se o controle de lista está no modo de classificação de várias.|
|[CMFCListCtrl::OnCompareItems](#oncompareitems)|Chamado pelo framework quando ele deve comparar dois itens de controle de lista.|
|[CMFCListCtrl::OnGetCellBkColor](#ongetcellbkcolor)|Chamado pelo framework quando precisar determinar a cor do plano de fundo de uma célula individual.|
|[CMFCListCtrl::OnGetCellFont](#ongetcellfont)|Chamado pelo framework quando ele deve obter a fonte para a célula que está sendo desenhada.|
|[CMFCListCtrl::OnGetCellTextColor](#ongetcelltextcolor)|Chamado pelo framework quando precisar determinar a cor do texto de uma célula individual.|
|[CMFCListCtrl::RemoveSortColumn](#removesortcolumn)|Remove uma coluna de classificação da lista de colunas classificadas.|
|[CMFCListCtrl::SetSortColumn](#setsortcolumn)|Define a coluna classificada atual e a ordem de classificação.|
|[CMFCListCtrl::Sort](#sort)|Classifica o controle de lista.|

## <a name="remarks"></a>Comentários

`CMFCListCtrl` oferece dois aprimoramentos [classe CListCtrl](../../mfc/reference/clistctrl-class.md) classe. Primeiro, indica que a classificação de coluna é uma opção disponível automaticamente desenhando uma seta de classificação no cabeçalho. Em segundo lugar, ele dá suporte a dados de classificação em várias colunas ao mesmo tempo.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos no `CMFCListCtrl` classe. O exemplo mostra como criar um controle de lista, colunas de inserção, inserir itens, definir o texto de um item e definir a fonte do controle de lista. Este trecho de código faz parte do [amostra de demonstração do Visual Studio](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#25](../../mfc/codesnippet/cpp/cmfclistctrl-class_1.h)]
[!code-cpp[NVC_MFC_VisualStudioDemo#26](../../mfc/codesnippet/cpp/cmfclistctrl-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CListCtrl](../../mfc/reference/clistctrl-class.md)

[CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)

## <a name="requirements"></a>Requisitos

**Header:** afxlistctrl.h

##  <a name="enablemarksortedcolumn"></a>  CMFCListCtrl::EnableMarkSortedColumn

Marca colunas classificadas com uma cor de plano de fundo diferente.

```
void EnableMarkSortedColumn(
    BOOL bMark = TRUE,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bMark*<br/>
[in] Um parâmetro booliano que determina se é necessário habilitar uma cor de plano de fundo diferente.

*bRedraw*<br/>
[in] Um parâmetro booliano que determina se é redesenhar o controle imediatamente.

### <a name="remarks"></a>Comentários

`EnableMarkSortedColumn` usa o método `CDrawingManager::PixelAlpha` calcular a cor que será usada para colunas de classificados. A cor escolhida baseia-se a cor de fundo regular.

##  <a name="enablemultiplesort"></a>  CMFCListCtrl::EnableMultipleSort

Permite que as linhas de dados na lista de controle de classificação por várias colunas.

```
void EnableMultipleSort(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
[in] Um booliano que especifica se é necessário habilitar o modo de classificar várias colunas.

### <a name="remarks"></a>Comentários

Quando você habilita a classificação com base em várias colunas, as colunas têm uma hierarquia. As linhas de dados serão classificadas primeiro pela coluna principal. Todos os valores equivalentes, em seguida, são classificados por cada coluna subsequente com base na prioridade.

##  <a name="getheaderctrl"></a>  CMFCListCtrl::GetHeaderCtrl

Retorna uma referência ao controle de cabeçalho.

```
virtual CMFCHeaderCtrl& GetHeaderCtrl();
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao subjacente [CMFCHeaderCtrl](../../mfc/reference/cmfcheaderctrl-class.md) objeto.

### <a name="remarks"></a>Comentários

O controle de cabeçalho para um controle de lista é a janela que contém os títulos das colunas. Ele geralmente é posicionado diretamente acima das colunas.

##  <a name="ismultiplesort"></a>  CMFCListCtrl::IsMultipleSort

Verifica se o controle de lista atualmente suporta a classificação em várias colunas.

```
BOOL IsMultipleSort() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o controle de lista oferece suporte a vários classificação; FALSE caso contrário.

### <a name="remarks"></a>Comentários

Quando um [classe CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md) dá suporte à classificação de várias, o usuário pode classificar os dados no controle de lista por várias colunas. Para habilitar a classificação de várias, chame [CMFCListCtrl::EnableMultipleSort](#enablemultiplesort).

##  <a name="oncompareitems"></a>  CMFCListCtrl::OnCompareItems

O framework chama esse método quando ele compara dois itens.

```
virtual int OnCompareItems(
    LPARAM lParam1,
    LPARAM lParam2,
    int iColumn);
```

### <a name="parameters"></a>Parâmetros

*lParam1*<br/>
[in] O primeiro item a ser comparado.

*lParam2*<br/>
[in] O segundo item a ser comparado.

*iColumn*<br/>
[in] O índice da coluna que esse método é a classificação.

### <a name="return-value"></a>Valor de retorno

Um inteiro que indica a posição relativa dos dois itens. Um valor negativo indica que o primeiro item deve preceder o segundo, o valor positivo indica que o primeiro item deve seguir o segundo, e zero significa que os dois itens são equivalentes.

### <a name="remarks"></a>Comentários

A implementação padrão sempre retorna 0. Você deve substituir essa função para fornecer um algoritmo de classificação.

##  <a name="ongetcellbkcolor"></a>  CMFCListCtrl::OnGetCellBkColor

O framework chama esse método quando ele deve determinar a cor do plano de fundo de uma célula individual.

```
virtual COLORREF OnGetCellBkColor(
    int nRow,
    int nColumn);
```

### <a name="parameters"></a>Parâmetros

*nRow*<br/>
[in] A linha da célula em questão.

*nColumn*<br/>
[in] A coluna da célula em questão.

### <a name="return-value"></a>Valor de retorno

Um valor COLOREF que especifica a cor do plano de fundo da célula.

### <a name="remarks"></a>Comentários

A implementação padrão de `OnGetCellBkColor` não usa os parâmetros de entrada fornecidos e em vez disso, simplesmente chama `GetBkColor`. Portanto, por padrão, o controle de toda a lista terá a mesma cor do plano de fundo. Você pode substituir `OnGetCellBkColor` em uma classe derivada para marcar a células individuais com uma cor de plano de fundo separada.

##  <a name="ongetcellfont"></a>  CMFCListCtrl::OnGetCellFont

O framework chama esse método quando ele obtém a fonte de uma célula individual.

```
virtual HFONT OnGetCellFont(
    int nRow,
    int nColumn,
    DWORD dwData = 0);
```

### <a name="parameters"></a>Parâmetros

*nRow*<br/>
[in] A linha da célula em questão.

*nColumn*<br/>
[in] A coluna da célula em questão.

*dwData*<br/>
[in] Dados definidos pelo usuário. A implementação padrão não usa esse parâmetro.

### <a name="return-value"></a>Valor de retorno

Um identificador para a fonte que é usada para a célula atual.

### <a name="remarks"></a>Comentários

Por padrão, esse método retornará nulo. Todas as células em um controle de lista tem a mesma fonte. Substitua este método para fornecer fontes diferentes para células diferentes.

##  <a name="ongetcelltextcolor"></a>  CMFCListCtrl::OnGetCellTextColor

O framework chama esse método quando ele deve determinar a cor do texto de uma célula individual.

```
virtual COLORREF OnGetCellTextColor(
    int nRow,
    int nColumn);
```

### <a name="parameters"></a>Parâmetros

*nRow*<br/>
[in] A linha da célula em questão.

*nColumn*<br/>
[in] A coluna da célula em questão.

### <a name="return-value"></a>Valor de retorno

Um valor COLOREF que especifica a cor do texto da célula.

### <a name="remarks"></a>Comentários

Por padrão, esse método chama `GetTextColor` independentemente de parâmetros de entrada. O controle de toda a lista terá a mesma cor do texto. Você pode substituir `OnGetCellTextColor` em uma classe derivada para marcar a células individuais com uma cor de texto separado.

##  <a name="removesortcolumn"></a>  CMFCListCtrl::RemoveSortColumn

Remove uma coluna de classificação da lista de colunas classificadas.

```
void RemoveSortColumn(int iColumn);
```

### <a name="parameters"></a>Parâmetros

*iColumn*<br/>
[in] A coluna a ser removido.

### <a name="remarks"></a>Comentários

Esse método Remove uma coluna de classificação do controle de cabeçalho. Ele chama [CMFCHeaderCtrl::RemoveSortColumn](../../mfc/reference/cmfcheaderctrl-class.md#removesortcolumn).

##  <a name="setsortcolumn"></a>  CMFCListCtrl::SetSortColumn

Define a coluna classificada atual e a ordem de classificação.

```
void SetSortColumn(
    int iColumn,
    BOOL bAscending = TRUE,
    BOOL bAdd = FALSE);
```

### <a name="parameters"></a>Parâmetros

*iColumn*<br/>
[in] A coluna para classificar.

*bAscending*<br/>
[in] Um booliano que especifica a ordem de classificação.

*bAdd*<br/>
[in] Um valor booleano que especifica se o método adiciona a coluna indicada por *iColumn* à lista de colunas de classificação.

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

*iColumn*<br/>
[in] A coluna para classificar.

*bAscending*<br/>
[in] Um booliano que especifica a ordem de classificação.

*bAdd*<br/>
[in] Um valor booleano que especifica se esse método adiciona a coluna indicada por *iColumn* à lista de colunas de classificação.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CListCtrl](../../mfc/reference/clistctrl-class.md)
