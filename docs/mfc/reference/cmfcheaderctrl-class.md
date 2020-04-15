---
title: Classe CMFCHeaderCtrl
ms.date: 11/04/2016
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
ms.openlocfilehash: 0a6b0cf39861ba995acff71fc40cf44ae5114642
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367456"
---
# <a name="cmfcheaderctrl-class"></a>Classe CMFCHeaderCtrl

A `CMFCHeaderCtrl` classe suporta a classificação de várias colunas em um controle de cabeçalho.

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
|[CMFCHeaderCtrl:EnableMultipleSort](#enablemultiplesort)|Ativa ou desativa o modo *de classificação de várias colunas* para o controle de cabeçalho atual.|
|[CMFCHeaderCtrl::GetColumnState](#getcolumnstate)|Indica se uma coluna não está classificada ou classificada em ordem ascendente ou descendente.|
|[CMFCHeaderCtrl::GetSortColumn](#getsortcolumn)|Recupera o índice baseado em zero da primeira coluna classificada no controle de cabeçalho.|
|`CMFCHeaderCtrl::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCHeaderCtrl::IsAscending](#isascending)|Indica se qualquer coluna no controle de cabeçalho está classificada em ordem crescente.|
|[CMFCHeaderCtrl::IsDialogControl](#isdialogcontrol)|Indica se a janela pai do controle de cabeçalho atual é uma caixa de diálogo.|
|[CMFCHeaderCtrl::IsMultipleSort](#ismultiplesort)|Indica se o controle de cabeçalho atual está no modo *de classificação de várias colunas.*|
|[CMFCHeaderCtrl:RemoveSortColumn](#removesortcolumn)|Remove a coluna especificada da lista de colunas de tipo.|
|[CMFCHeaderCtrl::SetSortColumn](#setsortcolumn)|Define a ordem de tipo de uma coluna especificada em um controle de cabeçalho.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCHeaderCtrl::OnDrawItem](#ondrawitem)|Chamado pela estrutura para desenhar uma coluna de controle de cabeçalho.|
|[CMFCHeaderCtrl::OnDrawSortArrow](#ondrawsortarrow)|Chamado pela estrutura para desenhar a seta de classificação.|
|[CMFCHeaderCtrl::OnFillBackground](#onfillbackground)|Chamado pela estrutura para preencher o plano de fundo de uma coluna de controle de cabeçalho.|

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCHeaderCtrl` construir um objeto da classe e como ativar o modo *de classificação de várias colunas* para o controle de cabeçalho atual.

[!code-cpp[NVC_MFC_RibbonApp#24](../../mfc/reference/codesnippet/cpp/cmfcheaderctrl-class_1.cpp)]

## <a name="remarks"></a>Comentários

A `CMFCHeaderCtrl` classe desenha uma seta de classificação em uma coluna de controle de cabeçalho para indicar que a coluna está classificada. Use o modo *de classificação de várias colunas* se um conjunto de colunas no controle da lista dos pais [(CMFCListCtrl Class)](../../mfc/reference/cmfclistctrl-class.md)puder ser classificado ao mesmo tempo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cheaderctrl](../../mfc/reference/cheaderctrl-class.md)

[CMFCHeaderCtrl](../../mfc/reference/cmfcheaderctrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxheaderctrl.h

## <a name="cmfcheaderctrlcmfcheaderctrl"></a><a name="cmfcheaderctrl"></a>CMFCHeaderCtrl::CMFCHeaderCtrl

Constrói um objeto `CMFCHeaderCtrl`.

```
CMFCHeaderCtrl::CMFCHeaderCtrl()
```

### <a name="remarks"></a>Comentários

Este construtor inicializa as seguintes variáveis de membro para os valores especificados:

|Variável de membro|Valor|
|---------------------|-----------|
|`m_bIsMousePressed`|FALSE|
|`m_bMultipleSort`|FALSE|
|`m_bAscending`|TRUE|
|`m_nHighlightedItem`|-1|
|`m_bTracked`|FALSE|
|`m_bIsDlgControl`|FALSE|
|`m_hFont`|NULO|

## <a name="cmfcheaderctrlenablemultiplesort"></a><a name="enablemultiplesort"></a>CMFCHeaderCtrl:EnableMultipleSort

Ativa ou desativa o modo *de classificação de várias colunas* para o controle de cabeçalho atual.

```
void EnableMultipleSort(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] TRUE para habilitar o modo de classificação de várias colunas; FALSO para desativar o modo de classificação de várias colunas e remover quaisquer colunas da lista de colunas classificadas. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

Use este método para ativar ou desativar o modo de classificação de várias colunas. Duas ou mais colunas podem participar de uma espécie se o controle de cabeçalho estiver no modo de classificação de várias colunas.

## <a name="cmfcheaderctrlgetcolumnstate"></a><a name="getcolumnstate"></a>CMFCHeaderCtrl::GetColumnState

Indica se uma coluna não é classificada ou está classificada em ordem ascendente ou descendente.

```
int GetColumnState(int iColumn) const;
```

### <a name="parameters"></a>Parâmetros

*Icolumn*<br/>
[em] O índice baseado em zero de uma coluna.

### <a name="return-value"></a>Valor retornado

Um valor que indique o status de tipo da coluna especificada. A tabela a seguir lista os valores possíveis: 

|Valor|Descrição|
|-----------|-----------------|
|-1|Ordenado em ordem descendente.|
|0|Não está resolvido.|
|1|Ordenado em ordem ascendente.|

### <a name="remarks"></a>Comentários

## <a name="cmfcheaderctrlgetsortcolumn"></a><a name="getsortcolumn"></a>CMFCHeaderCtrl::GetSortColumn

Recupera o índice baseado em zero da primeira coluna classificada no controle de cabeçalho.

```
int GetSortColumn() const;
```

### <a name="return-value"></a>Valor retornado

O índice de uma coluna classificada, ou -1, se nenhuma coluna classificada for encontrada.

### <a name="remarks"></a>Comentários

Se o controle de cabeçalho estiver no modo *de classificação de várias colunas* e você tiver compilado o aplicativo no modo de depuração, este método afirma e aconselha que você use o método [CMFCHeaderCtrl::GetColumnState](#getcolumnstate) em vez disso. Se o controle de cabeçalho estiver no modo de classificação de várias colunas e você tiver compilado o aplicativo no modo de varejo, este método reame -1.

## <a name="cmfcheaderctrlisascending"></a><a name="isascending"></a>CMFCHeaderCtrl::IsAscending

Indica se qualquer coluna no controle de cabeçalho está classificada em ordem crescente.

```
BOOL IsAscending() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se qualquer coluna no controle de cabeçalho for classificada em ordem crescente; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O valor que este método retorna é usado para exibir a seta de classificação apropriada no item de controle de cabeçalho. Use o método [CMFCHeaderCtrl:SetSortColumn](#setsortcolumn) para definir a ordem de classificação.

## <a name="cmfcheaderctrlisdialogcontrol"></a><a name="isdialogcontrol"></a>CMFCHeaderCtrl::IsDialogControl

Indica se a janela pai do controle de cabeçalho atual é uma caixa de diálogo.

```
BOOL IsDialogControl() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se a janela pai do controle de cabeçalho atual for uma caixa de diálogo; caso contrário, FALSE.

## <a name="cmfcheaderctrlismultiplesort"></a><a name="ismultiplesort"></a>CMFCHeaderCtrl::IsMultipleSort

Indica se o controle de cabeçalho atual está no modo *de classificação de várias colunas.*

```
BOOL IsMultipleSort() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o modo de classificação de várias colunas estiver ativado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use o [método CMFCHeaderCtrl::EnableMultipleSort](#enablemultiplesort) para ativar ou desativar o modo de classificação de várias colunas. Duas ou mais colunas podem participar de uma espécie se o controle de cabeçalho estiver no modo de classificação de várias colunas.

## <a name="cmfcheaderctrlondrawitem"></a><a name="ondrawitem"></a>CMFCHeaderCtrl::OnDrawItem

Chamado pela estrutura para desenhar uma coluna de controle de cabeçalho.

```
virtual void OnDrawItem(
    CDC* pDC,
    int iItem,
    CRect rect,
    BOOL bIsPressed,
    BOOL bIsHighlighted);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*Iitem*<br/>
[em] O índice baseado em zero do item a ser sorteado.

*Rect*<br/>
[em] O retângulo delimitador do item para desenhar.

*bIspressed*<br/>
[em] TRUE para desenhar o item em estado pressionado; caso contrário, FALSE.

*bIshighlighted*<br/>
[em] TRUE para desenhar o item em estado destacado; caso contrário, FALSE.

## <a name="cmfcheaderctrlondrawsortarrow"></a><a name="ondrawsortarrow"></a>CMFCHeaderCtrl::OnDrawSortArrow

Chamado pela estrutura para desenhar a seta de classificação.

```
virtual void OnDrawSortArrow(
    CDC* pDC,
    CRect rectArrow);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*rectArrow*<br/>
[em] O retângulo delimitador da seta do tipo.

## <a name="cmfcheaderctrlonfillbackground"></a><a name="onfillbackground"></a>CMFCHeaderCtrl::OnFillBackground

Chamado pela estrutura para preencher o plano de fundo de uma coluna de controle de cabeçalho.

```
virtual void OnFillBackground(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

### <a name="remarks"></a>Comentários

## <a name="cmfcheaderctrlremovesortcolumn"></a><a name="removesortcolumn"></a>CMFCHeaderCtrl:RemoveSortColumn

Remove a coluna especificada da lista de colunas de tipo.

```
void RemoveSortColumn(int iColumn);
```

### <a name="parameters"></a>Parâmetros

*Icolumn*<br/>
[em] O índice baseado em zero da coluna para remover.

## <a name="cmfcheaderctrlsetsortcolumn"></a><a name="setsortcolumn"></a>CMFCHeaderCtrl::SetSortColumn

Define a ordem de tipo de uma coluna especificada em um controle de cabeçalho.

```
void SetSortColumn(
    int iColumn,
    BOOL bAscending=TRUE,
    BOOL bAdd=FALSE);
```

### <a name="parameters"></a>Parâmetros

*Icolumn*<br/>
[em] O índice baseado em zero de uma coluna de controle de cabeçalho. Se este parâmetro for menor que zero, este método removerá todas as colunas da lista de colunas de tipo.

*bAscendente*<br/>
[em] Especifica a ordem de classificação da coluna que o parâmetro *iColumn* especifica. VERDADE para definir ordem ascendente; FALSO para definir ordem descendente. O valor padrão é TRUE.

*bAdd*<br/>
[em] TRUE para definir a ordem de classificação da coluna que o parâmetro *iColumn* especifica.

Se o controle de cabeçalho atual estiver no modo *de classificação de várias colunas,* este método adicionará a coluna especificada à lista de colunas de tipo. Use [CMFCHeaderCtrl::EnableMultipleSort](#enablemultiplesort) para definir o modo de classificação de várias colunas.

Se o modo de classificação de várias colunas não estiver definido e este método for compilado no modo de depuração, este método será afirmado. Se o modo de classificação de várias colunas não estiver definido e esse método for compilado no modo de varejo, este método primeiro removerá todas as colunas da lista de colunas de tipo e, em seguida, adicionará a coluna especificada à lista.

FALSE para primeiro remover todas as colunas da lista de colunas de tipo e, em seguida, adicionar a coluna especificada à lista. O valor padrão é FALSE.

### <a name="remarks"></a>Comentários

Use este método para definir a ordem de tipo de uma coluna. Se necessário, este método adiciona a coluna à lista de colunas de tipo. O controle de cabeçalho usa a ordem de classificação para desenhar uma seta de classificação que aponta para cima ou para baixo.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCListCtrl](../../mfc/reference/cmfclistctrl-class.md)
