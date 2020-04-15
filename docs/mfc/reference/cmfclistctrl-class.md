---
title: Classe CMFCListCtrl
ms.date: 07/30/2019
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
ms.openlocfilehash: 63fbfd236ed98eee3b90f4a20b191817026903c7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370766"
---
# <a name="cmfclistctrl-class"></a>Classe CMFCListCtrl

A `CMFCListCtrl` classe amplia a funcionalidade da classe [CListCtrl,](../../mfc/reference/clistctrl-class.md) suportando a funcionalidade avançada de controle de cabeçalho da [Classe CMFCHeaderCtrl](../../mfc/reference/cmfcheaderctrl-class.md).

## <a name="syntax"></a>Sintaxe

```
class CMFCListCtrl : public CListCtrl
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCListCtrl:EnableMarkSortedColumn](#enablemarksortedcolumn)|Permite a capacidade de marcar uma coluna classificada com uma cor de fundo diferente.|
|[CMFCListCtrl:HabilitarMultipleSort](#enablemultiplesort)|Habilita o modo de classificação múltipla.|
|[CMFCListCtrl::GetHeaderCtrl](#getheaderctrl)|Retorna uma referência ao controle de cabeçalho sublinhado.|
|[CMFCListCtrl::IsMultipleSort](#ismultiplesort)|Verifica se o controle da lista está no modo de classificação múltipla.|
|[CMFCListCtrl::OnCompareItems](#oncompareitems)|Chamado pelo framework quando deve comparar dois itens de controle de lista.|
|[CMFCListCtrl::OnGetCellBkColor](#ongetcellbkcolor)|Chamado pela estrutura quando deve determinar a cor de fundo de uma célula individual.|
|[CMFCListCtrl::OnGetCellFont](#ongetcellfont)|Chamado pela estrutura quando deve obter a fonte para a célula que está sendo desenhada.|
|[CMFCListCtrl::OnGetCellTextColor](#ongetcelltextcolor)|Chamado pela estrutura quando deve determinar a cor do texto de uma célula individual.|
|[CMFCListCtrl:RemoveSortColumn](#removesortcolumn)|Remove uma coluna de classificação da lista de colunas classificadas.|
|[CMFCListCtrl:SetSortColumn](#setsortcolumn)|Define a coluna classificada atual e a ordem de classificação.|
|[CMFCListCtrl::Classificar](#sort)|Classifica o controle da lista.|

## <a name="remarks"></a>Comentários

`CMFCListCtrl`oferece dois aprimoramentos para a classe [CListCtrl](../../mfc/reference/clistctrl-class.md) Class. Primeiro, ele indica que a classificação da coluna é uma opção disponível, desenhando automaticamente uma seta de classificação no cabeçalho. Em segundo lugar, ele suporta a classificação de dados em várias colunas ao mesmo tempo.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCListCtrl` usar vários métodos na classe. O exemplo mostra como criar um controle de lista, inserir colunas, inserir itens, definir o texto de um item e definir a fonte do controle da lista. Este trecho de código faz parte da [amostra visual studio demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#25](../../mfc/codesnippet/cpp/cmfclistctrl-class_1.h)]
[!code-cpp[NVC_MFC_VisualStudioDemo#26](../../mfc/codesnippet/cpp/cmfclistctrl-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CListCtrl](../../mfc/reference/clistctrl-class.md)

[CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxlistctrl.h

## <a name="cmfclistctrlenablemarksortedcolumn"></a><a name="enablemarksortedcolumn"></a>CMFCListCtrl:EnableMarkSortedColumn

Marca as colunas classificadas com uma cor de fundo diferente.

```
void EnableMarkSortedColumn(
    BOOL bMark = TRUE,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bMark*<br/>
[em] Um parâmetro booleano que determina se habilita uma cor de fundo diferente.

*Bredraw*<br/>
[em] Um parâmetro booleano que determina se deve redesenhar o controle imediatamente.

### <a name="remarks"></a>Comentários

`EnableMarkSortedColumn`usa o `CDrawingManager::PixelAlpha` método para calcular qual cor usar para colunas classificadas. A cor escolhida é baseada na cor de fundo regular.

## <a name="cmfclistctrlenablemultiplesort"></a><a name="enablemultiplesort"></a>CMFCListCtrl:HabilitarMultipleSort

Permite classificar as linhas de dados no controle de lista por várias colunas.

```
void EnableMultipleSort(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] Um booleano que especifica se deve ativar o modo de classificação de várias colunas.

### <a name="remarks"></a>Comentários

Quando você habilita a classificação com base em várias colunas, as colunas têm uma hierarquia. As linhas de dados serão classificadas pela primeira coluna principal. Quaisquer valores equivalentes são então classificados por cada coluna subseqüente com base na prioridade.

## <a name="cmfclistctrlgetheaderctrl"></a><a name="getheaderctrl"></a>CMFCListCtrl::GetHeaderCtrl

Retorna uma referência ao controle de cabeçalho.

```
virtual CMFCHeaderCtrl& GetHeaderCtrl();
```

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto [CMFCHeaderCtrl](../../mfc/reference/cmfcheaderctrl-class.md) subjacente.

### <a name="remarks"></a>Comentários

O controle de cabeçalho para um controle de lista é a janela que contém os títulos das colunas. Geralmente está posicionado diretamente acima das colunas.

## <a name="cmfclistctrlismultiplesort"></a><a name="ismultiplesort"></a>CMFCListCtrl::IsMultipleSort

Verifica se o controle de lista atualmente suporta classificação em várias colunas.

```
BOOL IsMultipleSort() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o controle de lista suportar vários tipos; FALSO de outra forma.

### <a name="remarks"></a>Comentários

Quando uma [classe CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md) suporta várias classificações, o usuário pode classificar os dados no controle da lista por várias colunas. Para habilitar a classificação múltipla, ligue para [CMFCListCtrl::EnableMultipleSort](#enablemultiplesort).

## <a name="cmfclistctrloncompareitems"></a><a name="oncompareitems"></a>CMFCListCtrl::OnCompareItems

A estrutura chama esse método quando compara dois itens.

```
virtual int OnCompareItems(
    LPARAM lParam1,
    LPARAM lParam2,
    int iColumn);
```

### <a name="parameters"></a>Parâmetros

*Lparam1*<br/>
[em] O primeiro item a ser comparado.

*LParam2*<br/>
[em] O segundo item a ser comparado.

*Icolumn*<br/>
[em] O índice da coluna que este método está classificando.

### <a name="return-value"></a>Valor retornado

Um inteiro que indica a posição relativa dos dois itens. Um valor negativo indica que o primeiro item deve preceder o segundo, um valor positivo indica que o primeiro item deve seguir o segundo, e zero significa que os dois itens são equivalentes.

### <a name="remarks"></a>Comentários

A implementação padrão sempre retorna 0. Anular esta função para fornecer seu próprio algoritmo de classificação.

## <a name="cmfclistctrlongetcellbkcolor"></a><a name="ongetcellbkcolor"></a>CMFCListCtrl::OnGetCellBkColor

A estrutura chama este método quando deve determinar a cor de fundo de uma célula individual.

```
virtual COLORREF OnGetCellBkColor(
    int nRow,
    int nColumn);
```

### <a name="parameters"></a>Parâmetros

*nRow*<br/>
[em] A linha da cela em questão.

*nColuna*<br/>
[em] A coluna da célula em questão.

### <a name="return-value"></a>Valor retornado

Um valor COLOREF que especifica a cor de fundo da célula.

### <a name="remarks"></a>Comentários

A implementação `OnGetCellBkColor` padrão não usa os parâmetros `GetBkColor`de entrada fornecidos e, em vez disso, simplesmente chama . Portanto, por padrão, todo o controle de lista terá a mesma cor de fundo. Você pode `OnGetCellBkColor` substituir em uma classe derivada para marcar células individuais com uma cor de fundo separada.

## <a name="cmfclistctrlongetcellfont"></a><a name="ongetcellfont"></a>CMFCListCtrl::OnGetCellFont

A estrutura chama esse método quando obtém a fonte para uma célula individual.

```
virtual HFONT OnGetCellFont(
    int nRow,
    int nColumn,
    DWORD dwData = 0);
```

### <a name="parameters"></a>Parâmetros

*nRow*<br/>
[em] A linha da cela em questão.

*nColuna*<br/>
[em] A coluna da célula em questão.

*Dwdata*<br/>
[em] Dados definidos pelo usuário. A implementação padrão não usa este parâmetro.

### <a name="return-value"></a>Valor retornado

Uma alça para a fonte que é usada para a célula atual.

### <a name="remarks"></a>Comentários

Por padrão, este método retorna NULL. Todas as células em um controle de lista têm a mesma fonte. Substituir este método para fornecer fontes diferentes para diferentes células.

## <a name="cmfclistctrlongetcelltextcolor"></a><a name="ongetcelltextcolor"></a>CMFCListCtrl::OnGetCellTextColor

A estrutura chama esse método quando deve determinar a cor do texto de uma célula individual.

```
virtual COLORREF OnGetCellTextColor(
    int nRow,
    int nColumn);
```

### <a name="parameters"></a>Parâmetros

*nRow*<br/>
[em] A linha da cela em questão.

*nColuna*<br/>
[em] A coluna da célula em questão.

### <a name="return-value"></a>Valor retornado

Um valor COLOREF que especifica a cor do texto da célula.

### <a name="remarks"></a>Comentários

Por padrão, este `GetTextColor` método chama independentemente dos parâmetros de entrada. Todo o controle da lista terá a mesma cor de texto. Você pode `OnGetCellTextColor` substituir em uma classe derivada para marcar células individuais com uma cor de texto separada.

## <a name="cmfclistctrlremovesortcolumn"></a><a name="removesortcolumn"></a>CMFCListCtrl:RemoveSortColumn

Remove uma coluna de classificação da lista de colunas classificadas.

```
void RemoveSortColumn(int iColumn);
```

### <a name="parameters"></a>Parâmetros

*Icolumn*<br/>
[em] A coluna para remover.

### <a name="remarks"></a>Comentários

Este método remove uma coluna de classificação do controle de cabeçalho. Chama [CMFCHeaderCtrl::RemoveSortColumn](../../mfc/reference/cmfcheaderctrl-class.md#removesortcolumn).

## <a name="cmfclistctrlsetsortcolumn"></a><a name="setsortcolumn"></a>CMFCListCtrl:SetSortColumn

Define a coluna classificada atual e a ordem de classificação.

```
void SetSortColumn(
    int iColumn,
    BOOL bAscending = TRUE,
    BOOL bAdd = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Icolumn*<br/>
[em] A coluna para classificar.

*bAscendente*<br/>
[em] Um booleano que especifica a ordem de classificação.

*bAdd*<br/>
[em] Um booleano que especifica se o método adiciona a coluna indicada por *iColumn* à lista de colunas de tipo.

### <a name="remarks"></a>Comentários

Este método passa os parâmetros de entrada para o controle de cabeçalho usando o método [CMFCHeaderCtrl::SetSortColumn](../../mfc/reference/cmfcheaderctrl-class.md#setsortcolumn).

## <a name="cmfclistctrlsort"></a><a name="sort"></a>CMFCListCtrl::Classificar

Classifica o controle da lista.

```
virtual void Sort(
    int iColumn,
    BOOL bAscending = TRUE,
    BOOL bAdd = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Icolumn*<br/>
[em] A coluna para classificar.

*bAscendente*<br/>
[em] Um booleano que especifica a ordem de classificação.

*bAdd*<br/>
[em] Um booleano que especifica se este método adiciona a coluna indicada por *iColumn* à lista de colunas de tipo.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CListCtrl](../../mfc/reference/clistctrl-class.md)
