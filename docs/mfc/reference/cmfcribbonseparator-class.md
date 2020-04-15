---
title: Classe CMFCRibbonSeparator
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonSeparator
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::CMFCRibbonSeparator
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::AddToListBox
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::CopyFrom
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::GetRegularSize
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::IsSeparator
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::IsTabStop
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::OnDraw
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::OnDrawOnList
helpviewer_keywords:
- CMFCRibbonSeparator [MFC], CMFCRibbonSeparator
- CMFCRibbonSeparator [MFC], AddToListBox
- CMFCRibbonSeparator [MFC], CopyFrom
- CMFCRibbonSeparator [MFC], GetRegularSize
- CMFCRibbonSeparator [MFC], IsSeparator
- CMFCRibbonSeparator [MFC], IsTabStop
- CMFCRibbonSeparator [MFC], OnDraw
- CMFCRibbonSeparator [MFC], OnDrawOnList
ms.assetid: bedb1a53-cb07-4c3c-be12-698c5409e7cf
ms.openlocfilehash: 41a958c78719f6aedf1cc02f8e3ff5a2dbbf0e1b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368846"
---
# <a name="cmfcribbonseparator-class"></a>Classe CMFCRibbonSeparator

Implementa o separador da fita.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonSeparator : public CMFCRibbonBaseElement
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCRibbonSeparator::CMFCRibbonSeparator](#cmfcribbonseparator)|Constrói um objeto `CMFCRibbonSeparator`.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCRibbonSeparator::AddToListBox](#addtolistbox)|Adiciona um separador à lista **Comandos** na caixa de diálogo **Personalizar.** (Substitui [cmfcribbonbaseelement:addToListBox](../../mfc/reference/cmfcribbonbaseelement-class.md#addtolistbox).)|
|`CMFCRibbonSeparator::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|`CMFCRibbonSeparator::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|

### <a name="protected-methods"></a>Métodos Protegidos

|||
|-|-|
|Nome|Descrição|
|[CMFCRibbonSeparator::CopyFrom](#copyfrom)|Um método de cópia que define as variáveis de membro de um separador de outro objeto.|
|[CMFCRibbonSeparator::GetRegularSize](#getregularsize)|Retorna do tamanho de um separador.|
|[CMFCRibbonSeparator::IsSeparator](#isseparator)|Indica se é um separador.|
|[CMFCRibbonSeparator::IsTabStop](#istabstop)|Indica se isso é uma parada de guia.|
|[CMFCRibbonSeparator::OnDraw](#ondraw)|Chamado pelo sistema para desenhar o separador na fita ou na barra de ferramentas de acesso rápido.|
|[CMFCRibbonseparator::OnDrawOnList](#ondrawonlist)|Chamado pelo sistema para desenhar o separador na lista **de comandos.**|

## <a name="remarks"></a>Comentários

Um separador de fita é uma linha vertical ou horizontal que logicamente separa elementos da fita. Um separador pode ser desenhado no controle da fita, no menu principal do aplicativo, na barra de status da fita e na barra de ferramentas de acesso rápido.

Para usar um separador em sua aplicação, construa o novo objeto e adicione-o ao menu principal do aplicativo, conforme mostrado aqui:

```
CMFCRibbonMainPanel* pMainPanel = m_wndRibbonBar.AddMainCategory(_T("Main Menu"),
    IDB_FILESMALL,
    IDB_FILELARGE);

...
pMainPanel->Add(new CMFCRibbonSeparator(TRUE));
```

Chamada [CMFCRibbonPanel::AddSeparator](../../mfc/reference/cmfcribbonpanel-class.md#addseparator) para adicionar separadores aos painéis de fita. Os separadores são alocados e `AddSeparator` adicionados internamente pelo método.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcribbonbaseelement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonSeparator](../../mfc/reference/cmfcribbonseparator-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxbaseribbonelement.h

## <a name="cmfcribbonseparatoraddtolistbox"></a><a name="addtolistbox"></a>CMFCRibbonSeparator::AddToListBox

Adiciona um separador à lista **Comandos** na caixa de diálogo **Personalizar.**

```
virtual int AddToListBox(
    CMFCRibbonCommandsListBox* pWndListBox,
    BOOL bDeep);
```

### <a name="parameters"></a>Parâmetros

*pWndListBox*<br/>
[em] Um ponteiro para a lista **de comandos** onde o separador é adicionado.

*Bdeep*<br/>
[em] Ignorado.

### <a name="return-value"></a>Valor retornado

Índice baseado em zero para a seqüência na caixa de lista especificada por *pWndListBox*.

## <a name="cmfcribbonseparatorcmfcribbonseparator"></a><a name="cmfcribbonseparator"></a>CMFCRibbonSeparator::CMFCRibbonSeparator

Constrói um objeto `CMFCRibbonSeparator`.

```
CMFCRibbonSeparator(BOOL bIsHoriz = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bIsHoriz*<br/>
[em] Se VERDADEIRO, o separador é horizontal; se FALSO, o separador é vertical.

### <a name="remarks"></a>Comentários

Separadores horizontais são usados em menus de aplicativos. Separadores verticais são usados em barras de ferramentas.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCRibbonSeparator` construir um objeto da classe.

[!code-cpp[NVC_MFC_RibbonApp#19](../../mfc/reference/codesnippet/cpp/cmfcribbonseparator-class_1.cpp)]

## <a name="cmfcribbonseparatorcopyfrom"></a><a name="copyfrom"></a>CMFCRibbonSeparator::CopyFrom

Um método de cópia que define as variáveis de membro de um separador de outro objeto.

```
virtual void CopyFrom(const CMFCRibbonBaseElement& src);
```

### <a name="parameters"></a>Parâmetros

*Src*<br/>
[em] O elemento da fita de origem para copiar.

## <a name="cmfcribbonseparatorgetregularsize"></a><a name="getregularsize"></a>CMFCRibbonSeparator::GetRegularSize

Retorna do tamanho de um separador.

```
virtual CSize GetRegularSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para o conteúdo de um dispositivo.

### <a name="return-value"></a>Valor retornado

O tamanho do separador no contexto do dispositivo dado.

## <a name="cmfcribbonseparatorisseparator"></a><a name="isseparator"></a>CMFCRibbonSeparator::IsSeparator

Indica se é um separador.

```
virtual BOOL IsSeparator() const;
```

### <a name="return-value"></a>Valor retornado

Sempre VERDADEIRO para esta aula.

## <a name="cmfcribbonseparatoristabstop"></a><a name="istabstop"></a>CMFCRibbonSeparator::IsTabStop

Indica se isso é uma parada de guia.

```
virtual BOOL IsTabStop() const;
```

### <a name="return-value"></a>Valor retornado

Sempre FALSO para esta classe.

### <a name="remarks"></a>Comentários

Um separador de fita não é uma parada de guia.

## <a name="cmfcribbonseparatorondraw"></a><a name="ondraw"></a>CMFCRibbonSeparator::OnDraw

Chamado pelo sistema para desenhar o separador na fita ou na barra de ferramentas de acesso rápido.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

## <a name="cmfcribbonseparatorondrawonlist"></a><a name="ondrawonlist"></a>CMFCRibbonseparator::OnDrawOnList

Chamado pelo sistema para desenhar o separador na lista **de comandos.**

```
virtual void OnDrawOnList(
    CDC* pDC,
    CString strText,
    int nTextOffset,
    CRect rect,
    BOOL bIsSelected,
    BOOL bHighlighted);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pDC*|[em] Um ponteiro para um contexto de dispositivo.|
|*strText*|[em] Texto exibido na lista.|
|*nTextOffset*|[em] Espaçamento entre o texto e o lado esquerdo do retângulo delimitador.|
|*Rect*|[em] Especifica o retângulo delimitador.|
|*bIsSelected*|[em] Ignorado.|
|*bHighlighted*|[em] Ignorado.|

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
