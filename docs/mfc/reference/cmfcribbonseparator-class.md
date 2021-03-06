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
ms.openlocfilehash: f435dc5ae8821a6d5626af2f93710a1672fd374c
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831795"
---
# <a name="cmfcribbonseparator-class"></a>Classe CMFCRibbonSeparator

Implementa o separador de faixa de faixas.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonSeparator : public CMFCRibbonBaseElement
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|-|-|
|[CMFCRibbonSeparator::CMFCRibbonSeparator](#cmfcribbonseparator)|Constrói um objeto `CMFCRibbonSeparator`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|-|-|
|[CMFCRibbonSeparator::AddToListBox](#addtolistbox)|Adiciona um separador à lista de **comandos** na caixa de diálogo **Personalizar** . (Substitui [CMFCRibbonBaseElement:: AddToListBox](../../mfc/reference/cmfcribbonbaseelement-class.md#addtolistbox).)|
|`CMFCRibbonSeparator::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|`CMFCRibbonSeparator::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|-|-|
|[CMFCRibbonSeparator::CopyFrom](#copyfrom)|Um método de cópia que define as variáveis de membro de um separador de outro objeto.|
|[CMFCRibbonSeparator::GetRegularSize](#getregularsize)|Retorna o tamanho de um separador.|
|[CMFCRibbonSeparator:: isseparatorr](#isseparator)|Indica se este é um separador.|
|[CMFCRibbonSeparator:: IsTabStop](#istabstop)|Indica se esta é uma parada de tabulação.|
|[CMFCRibbonSeparator:: OnDraw](#ondraw)|Chamado pelo sistema para desenhar o separador na faixa de opções ou na barra de ferramentas de acesso rápido.|
|[CMFCRibbonSeparator::OnDrawOnList](#ondrawonlist)|Chamado pelo sistema para desenhar o separador na lista de **comandos** .|

## <a name="remarks"></a>Comentários

Um separador de faixa de forma é uma linha vertical ou horizontal que separa logicamente os elementos da faixa de uma. Um separador pode ser desenhado no controle da faixa de faixas, no menu principal do aplicativo, na barra de status da faixa de medida e na barra de ferramentas de acesso rápido.

Para usar um separador em seu aplicativo, construa o novo objeto e adicione-o ao menu principal do aplicativo, conforme mostrado aqui:

```
CMFCRibbonMainPanel* pMainPanel = m_wndRibbonBar.AddMainCategory(_T("Main Menu"),
    IDB_FILESMALL,
    IDB_FILELARGE);

...
pMainPanel->Add(new CMFCRibbonSeparator(TRUE));
```

Chame [CMFCRibbonPanel:: AddSeparator](../../mfc/reference/cmfcribbonpanel-class.md#addseparator) para adicionar separadores aos painéis da faixa de faixas. Os separadores são alocados e adicionados internamente pelo `AddSeparator` método.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonSeparator](../../mfc/reference/cmfcribbonseparator-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxbaseribbonelement. h

## <a name="cmfcribbonseparatoraddtolistbox"></a><a name="addtolistbox"></a> CMFCRibbonSeparator::AddToListBox

Adiciona um separador à lista de **comandos** na caixa de diálogo **Personalizar** .

```
virtual int AddToListBox(
    CMFCRibbonCommandsListBox* pWndListBox,
    BOOL bDeep);
```

### <a name="parameters"></a>parâmetros

*pWndListBox*<br/>
no Um ponteiro para a lista de **comandos** onde o separador é adicionado.

*bDeep*<br/>
no Aceita.

### <a name="return-value"></a>Valor Retornado

Índice de base zero para a cadeia de caracteres na caixa de listagem especificada por *pWndListBox*.

## <a name="cmfcribbonseparatorcmfcribbonseparator"></a><a name="cmfcribbonseparator"></a> CMFCRibbonSeparator::CMFCRibbonSeparator

Constrói um objeto `CMFCRibbonSeparator`.

```
CMFCRibbonSeparator(BOOL bIsHoriz = FALSE);
```

### <a name="parameters"></a>parâmetros

*bIsHoriz*<br/>
no Se for TRUE, o separador será horizontal; Se for FALSE, o separador será vertical.

### <a name="remarks"></a>Comentários

Os separadores horizontais são usados nos menus do aplicativo. Os separadores verticais são usados em barras de ferramentas.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto da `CMFCRibbonSeparator` classe.

[!code-cpp[NVC_MFC_RibbonApp#19](../../mfc/reference/codesnippet/cpp/cmfcribbonseparator-class_1.cpp)]

## <a name="cmfcribbonseparatorcopyfrom"></a><a name="copyfrom"></a> CMFCRibbonSeparator::CopyFrom

Um método de cópia que define as variáveis de membro de um separador de outro objeto.

```
virtual void CopyFrom(const CMFCRibbonBaseElement& src);
```

### <a name="parameters"></a>parâmetros

*Orig*<br/>
no O elemento da faixa de faixas de origem para o qual copiar.

## <a name="cmfcribbonseparatorgetregularsize"></a><a name="getregularsize"></a> CMFCRibbonSeparator::GetRegularSize

Retorna o tamanho de um separador.

```
virtual CSize GetRegularSize(CDC* pDC);
```

### <a name="parameters"></a>parâmetros

*Primário*<br/>
no Um ponteiro para um conteúdo de dispositivo.

### <a name="return-value"></a>Valor Retornado

O tamanho do separador no contexto do dispositivo fornecido.

## <a name="cmfcribbonseparatorisseparator"></a><a name="isseparator"></a> CMFCRibbonSeparator:: isseparatorr

Indica se este é um separador.

```
virtual BOOL IsSeparator() const;
```

### <a name="return-value"></a>Valor Retornado

Sempre verdadeiro para esta classe.

## <a name="cmfcribbonseparatoristabstop"></a><a name="istabstop"></a> CMFCRibbonSeparator:: IsTabStop

Indica se esta é uma parada de tabulação.

```
virtual BOOL IsTabStop() const;
```

### <a name="return-value"></a>Valor Retornado

Sempre FALSE para esta classe.

### <a name="remarks"></a>Comentários

Um separador de faixa não é uma parada de tabulação.

## <a name="cmfcribbonseparatorondraw"></a><a name="ondraw"></a> CMFCRibbonSeparator:: OnDraw

Chamado pelo sistema para desenhar o separador na faixa de opções ou na barra de ferramentas de acesso rápido.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>parâmetros

*Primário*<br/>
no Um ponteiro para um contexto de dispositivo.

## <a name="cmfcribbonseparatorondrawonlist"></a><a name="ondrawonlist"></a> CMFCRibbonSeparator::OnDrawOnList

Chamado pelo sistema para desenhar o separador na lista de **comandos** .

```
virtual void OnDrawOnList(
    CDC* pDC,
    CString strText,
    int nTextOffset,
    CRect rect,
    BOOL bIsSelected,
    BOOL bHighlighted);
```

### <a name="parameters"></a>parâmetros

*Primário*\
no Um ponteiro para um contexto de dispositivo.

*strText*\
no Texto exibido na lista.

*nTextOffset*\
no Espaçamento entre o texto e o lado esquerdo do retângulo delimitador.

*Rect*\
no Especifica o retângulo delimitador.

*bIsSelected*\
no Aceita.

*bHighlighted*\
no Aceita.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
