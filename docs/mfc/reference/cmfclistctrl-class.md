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
ms.openlocfilehash: 599a00af28ee5b8effbabbe5b334022ceb49f91a
ms.sourcegitcommit: 725e86dabe2901175ecc63261c3bf05802dddff4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/31/2019
ms.locfileid: "68682339"
---
# <a name="cmfclistctrl-class"></a>Classe CMFCListCtrl

A `CMFCListCtrl` classe estende a funcionalidade da classe de [classe CListCtrl](../../mfc/reference/clistctrl-class.md) dando suporte à funcionalidade de controle de cabeçalho avançado da [classe CMFCHeaderCtrl](../../mfc/reference/cmfcheaderctrl-class.md).

## <a name="syntax"></a>Sintaxe

```
class CMFCListCtrl : public CListCtrl
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCListCtrl::EnableMarkSortedColumn](#enablemarksortedcolumn)|Habilita a capacidade de marcar uma coluna classificada com uma cor de plano de fundo diferente.|
|[CMFCListCtrl::EnableMultipleSort](#enablemultiplesort)|Habilita o modo de classificação múltipla.|
|[CMFCListCtrl::GetHeaderCtrl](#getheaderctrl)|Retorna uma referência ao controle de cabeçalho sublinhado.|
|[CMFCListCtrl::IsMultipleSort](#ismultiplesort)|Verifica se o controle de lista está em modo de classificação múltipla.|
|[CMFCListCtrl::OnCompareItems](#oncompareitems)|Chamado pelo Framework quando ele deve comparar dois itens de controle de lista.|
|[CMFCListCtrl::OnGetCellBkColor](#ongetcellbkcolor)|Chamado pelo Framework quando ele deve determinar a cor do plano de fundo de uma célula individual.|
|[CMFCListCtrl::OnGetCellFont](#ongetcellfont)|Chamado pelo Framework quando ele deve obter a fonte da célula que está sendo desenhada.|
|[CMFCListCtrl::OnGetCellTextColor](#ongetcelltextcolor)|Chamado pelo Framework quando ele deve determinar a cor do texto de uma célula individual.|
|[CMFCListCtrl::RemoveSortColumn](#removesortcolumn)|Remove uma coluna de classificação da lista de colunas classificadas.|
|[CMFCListCtrl::SetSortColumn](#setsortcolumn)|Define a coluna classificada atual e a ordem de classificação.|
|[CMFCListCtrl::Sort](#sort)|Classifica o controle de lista.|

## <a name="remarks"></a>Comentários

`CMFCListCtrl`oferece dois aprimoramentos à classe de [classe CListCtrl](../../mfc/reference/clistctrl-class.md) . Primeiro, ele indica que a classificação de coluna é uma opção disponível ao desenhar automaticamente uma seta de classificação no cabeçalho. Em segundo lugar, ele dá suporte à classificação de dados em várias colunas ao mesmo tempo.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos na `CMFCListCtrl` classe. O exemplo mostra como criar um controle de lista, inserir colunas, inserir itens, definir o texto de um item e definir a fonte do controle de lista. Este trecho de código faz parte do [exemplo de demonstração do Visual Studio](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#25](../../mfc/codesnippet/cpp/cmfclistctrl-class_1.h)]
[!code-cpp[NVC_MFC_VisualStudioDemo#26](../../mfc/codesnippet/cpp/cmfclistctrl-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CListCtrl](../../mfc/reference/clistctrl-class.md)

[CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxlistctrl. h

##  <a name="enablemarksortedcolumn"></a>  CMFCListCtrl::EnableMarkSortedColumn

Marca as colunas classificadas com uma cor de plano de fundo diferente.

```
void EnableMarkSortedColumn(
    BOOL bMark = TRUE,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bMark*<br/>
no Um parâmetro booliano que determina se uma cor de plano de fundo diferente deve ser habilitada.

*bRedraw*<br/>
no Um parâmetro booliano que determina se o controle deve ser redesenhado imediatamente.

### <a name="remarks"></a>Comentários

`EnableMarkSortedColumn`usa o método `CDrawingManager::PixelAlpha` para calcular a cor a ser usada para colunas classificadas. A cor escolhida é baseada na cor normal do plano de fundo.

##  <a name="enablemultiplesort"></a>  CMFCListCtrl::EnableMultipleSort

Permite classificar as linhas de dados no controle de lista por várias colunas.

```
void EnableMultipleSort(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
no Um booliano que especifica se o modo de classificação de vários colunas deve ser habilitado.

### <a name="remarks"></a>Comentários

Quando você habilita a classificação com base em várias colunas, as colunas têm uma hierarquia. As linhas de dados serão classificadas primeiro pela coluna primária. Todos os valores equivalentes são então classificados por cada coluna subsequente com base na prioridade.

##  <a name="getheaderctrl"></a>  CMFCListCtrl::GetHeaderCtrl

Retorna uma referência ao controle de cabeçalho.

```
virtual CMFCHeaderCtrl& GetHeaderCtrl();
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao objeto [CMFCHeaderCtrl](../../mfc/reference/cmfcheaderctrl-class.md) subjacente.

### <a name="remarks"></a>Comentários

O controle de cabeçalho de um controle de lista é a janela que contém os títulos das colunas. Em geral, ele é posicionado diretamente acima das colunas.

##  <a name="ismultiplesort"></a>  CMFCListCtrl::IsMultipleSort

Verifica se o controle de lista atualmente dá suporte à classificação em várias colunas.

```
BOOL IsMultipleSort() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o controle de lista der suporte a várias classificações; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Quando uma [Classe CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md) dá suporte a várias classificações, o usuário pode classificar os dados no controle de lista por várias colunas. Para habilitar várias classificações, chame [CMFCListCtrl:: EnableMultipleSort](#enablemultiplesort).

##  <a name="oncompareitems"></a>  CMFCListCtrl::OnCompareItems

A estrutura chama esse método quando ele compara dois itens.

```
virtual int OnCompareItems(
    LPARAM lParam1,
    LPARAM lParam2,
    int iColumn);
```

### <a name="parameters"></a>Parâmetros

*lParam1*<br/>
no O primeiro item a ser comparado.

*lParam2*<br/>
no O segundo item a ser comparado.

*iColumn*<br/>
no O índice da coluna que este método está classificando.

### <a name="return-value"></a>Valor de retorno

Um inteiro que indica a posição relativa dos dois itens. Um valor negativo indica que o primeiro item deve anteceder o segundo, um valor positivo indica que o primeiro item deve seguir o segundo e zero significa que os dois itens são equivalentes.

### <a name="remarks"></a>Comentários

A implementação padrão sempre retorna 0. Substitua essa função para fornecer seu próprio algoritmo de classificação.

##  <a name="ongetcellbkcolor"></a>  CMFCListCtrl::OnGetCellBkColor

A estrutura chama esse método quando ele deve determinar a cor do plano de fundo de uma célula individual.

```
virtual COLORREF OnGetCellBkColor(
    int nRow,
    int nColumn);
```

### <a name="parameters"></a>Parâmetros

*nRow*<br/>
no A linha da célula em questão.

*nColumn*<br/>
no A coluna da célula em questão.

### <a name="return-value"></a>Valor de retorno

Um valor COLOREF que especifica a cor do plano de fundo da célula.

### <a name="remarks"></a>Comentários

A implementação padrão do `OnGetCellBkColor` não usa os parâmetros de entrada fornecidos e, em vez `GetBkColor`disso, simplesmente chama. Portanto, por padrão, o controle de lista inteiro terá a mesma cor de plano de fundo. Você pode substituir `OnGetCellBkColor` em uma classe derivada para marcar células individuais com uma cor de plano de fundo separada.

##  <a name="ongetcellfont"></a>  CMFCListCtrl::OnGetCellFont

A estrutura chama esse método quando Obtém a fonte de uma célula individual.

```
virtual HFONT OnGetCellFont(
    int nRow,
    int nColumn,
    DWORD dwData = 0);
```

### <a name="parameters"></a>Parâmetros

*nRow*<br/>
no A linha da célula em questão.

*nColumn*<br/>
no A coluna da célula em questão.

*dwData*<br/>
no Dados definidos pelo usuário. A implementação padrão não usa esse parâmetro.

### <a name="return-value"></a>Valor de retorno

Um identificador para a fonte usada para a célula atual.

### <a name="remarks"></a>Comentários

Por padrão, esse método retorna NULL. Todas as células em um controle de lista têm a mesma fonte. Substitua esse método para fornecer diferentes fontes para células diferentes.

##  <a name="ongetcelltextcolor"></a>  CMFCListCtrl::OnGetCellTextColor

A estrutura chama esse método quando ele deve determinar a cor do texto de uma célula individual.

```
virtual COLORREF OnGetCellTextColor(
    int nRow,
    int nColumn);
```

### <a name="parameters"></a>Parâmetros

*nRow*<br/>
no A linha da célula em questão.

*nColumn*<br/>
no A coluna da célula em questão.

### <a name="return-value"></a>Valor de retorno

Um valor COLOREF que especifica a cor do texto da célula.

### <a name="remarks"></a>Comentários

Por padrão, esse método chama `GetTextColor` , independentemente dos parâmetros de entrada. O controle de lista inteiro terá a mesma cor de texto. Você pode substituir `OnGetCellTextColor` em uma classe derivada para marcar células individuais com uma cor de texto separada.

##  <a name="removesortcolumn"></a>  CMFCListCtrl::RemoveSortColumn

Remove uma coluna de classificação da lista de colunas classificadas.

```
void RemoveSortColumn(int iColumn);
```

### <a name="parameters"></a>Parâmetros

*iColumn*<br/>
no A coluna a ser removida.

### <a name="remarks"></a>Comentários

Esse método remove uma coluna de classificação do controle de cabeçalho. Ele chama [CMFCHeaderCtrl:: RemoveSortColumn](../../mfc/reference/cmfcheaderctrl-class.md#removesortcolumn).

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
no A coluna a ser classificada.

*bAscending*<br/>
no Um booliano que especifica a ordem de classificação.

*bAdd*<br/>
no Um booliano que especifica se o método adiciona a coluna indicada por *IColumn* à lista de colunas de classificação.

### <a name="remarks"></a>Comentários

Esse método passa os parâmetros de entrada para o controle de cabeçalho usando o método [CMFCHeaderCtrl:: SetSortColumn](../../mfc/reference/cmfcheaderctrl-class.md#setsortcolumn).

##  <a name="sort"></a>CMFCListCtrl:: Sort

Classifica o controle de lista.

```
virtual void Sort(
    int iColumn,
    BOOL bAscending = TRUE,
    BOOL bAdd = FALSE);
```

### <a name="parameters"></a>Parâmetros

*iColumn*<br/>
no A coluna a ser classificada.

*bAscending*<br/>
no Um booliano que especifica a ordem de classificação.

*bAdd*<br/>
no Um booliano que especifica se esse método adiciona a coluna indicada por *IColumn* à lista de colunas de classificação.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CListCtrl](../../mfc/reference/clistctrl-class.md)
