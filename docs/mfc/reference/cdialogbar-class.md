---
title: Classe CDialogBar
ms.date: 11/04/2016
f1_keywords:
- CDialogBar
- AFXEXT/CDialogBar
- AFXEXT/CDialogBar::CDialogBar
- AFXEXT/CDialogBar::Create
helpviewer_keywords:
- CDialogBar [MFC], CDialogBar
- CDialogBar [MFC], Create
ms.assetid: da2f7a30-970c-44e3-87f0-6094bd002cab
ms.openlocfilehash: cf9a2658807959108b3bb0af672d4c1835b58bc5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375669"
---
# <a name="cdialogbar-class"></a>Classe CDialogBar

Fornece a funcionalidade de uma caixa de diálogo modeless do Windows em uma barra de controle.

## <a name="syntax"></a>Sintaxe

```
class CDialogBar : public CControlBar
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Cdialogbar::CDialogBar](#cdialogbar)|Constrói um objeto `CDialogBar`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDialogBar::Criar](#create)|Cria uma barra de diálogo do `CDialogBar` Windows e a anexa ao objeto.|

## <a name="remarks"></a>Comentários

Uma barra de diálogo se assemelha a uma caixa de diálogo na de que contém controles padrão do Windows que o usuário pode fazer uma guia entre. Outra semelhança é que você cria um modelo de diálogo para representar a barra de diálogo.

Criar e usar uma barra de diálogo `CFormView` é semelhante à criação e uso de um objeto. Primeiro, use o [editor de diálogo](../../windows/dialog-editor.md) para definir um modelo de diálogo com o estilo WS_CHILD e nenhum outro estilo. O modelo não deve ter o estilo WS_VISIBLE. No código do aplicativo, chame o `CDialogBar` construtor para `Create` construir o objeto e, em `CDialogBar` seguida, ligue para criar a janela da barra de diálogo e anexe-o ao objeto.

Para obter `CDialogBar`mais informações, consulte o artigo [Barras de Diálogo](../../mfc/dialog-bars.md) e [Nota Técnica 31](../../mfc/tn031-control-bars.md), Barras de Controle.

> [!NOTE]
> Na versão atual, `CDialogBar` um objeto não pode hospedar controles do Windows Forms. Para obter mais informações sobre os controles do Windows Forms no Visual C++, consulte [Usando um Controle de Usuário do Formulário Do Windows em MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Ccontrolbar](../../mfc/reference/ccontrolbar-class.md)

`CDialogBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

## <a name="cdialogbarcdialogbar"></a><a name="cdialogbar"></a>Cdialogbar::CDialogBar

Constrói um objeto `CDialogBar`.

```
CDialogBar();
```

## <a name="cdialogbarcreate"></a><a name="create"></a>CDialogBar::Criar

Carrega o modelo de recurso caixa `lpszTemplateName` `nIDTemplate`de diálogo especificado por ou , cria a `CDialogBar` janela da barra de diálogo, define seu estilo e o associa ao objeto.

```
virtual BOOL Create(
    CWnd* pParentWnd,
    LPCTSTR lpszTemplateName,
    UINT nStyle,
    UINT nID);

virtual BOOL Create(
    CWnd* pParentWnd,
    UINT nIDTemplate,
    UINT nStyle,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Um ponteiro para `CWnd` o objeto pai.

*lpszTemplateName*<br/>
Um ponteiro para o `CDialogBar` nome do modelo de recurso caixa de diálogo do objeto.

*nStyle*<br/>
O estilo da barra de ferramentas. Os estilos adicionais de barra de ferramentas suportados são:

- CBRS_TOP barra de controle está no topo da janela da moldura.

- CBRS_BOTTOM barra de controle está na parte inferior da janela da moldura.

- CBRS_NOALIGN barra de controle não é reposicionada quando o pai é redimensionado.

- CBRS_TOOLTIPS barra de controle exibe dicas de ferramentas.

- CBRS_SIZE_DYNAMIC barra de controle é dinâmica.

- CBRS_SIZE_FIXED barra de controle está fixa.

- CBRS_FLOATING barra de controle está flutuando.

- CBRS_FLYBY Barra de status exibe informações sobre o botão.

- CBRS_HIDE_INPLACE barra de controle não é exibida para o usuário.

*nID*<br/>
A id de controle da barra de diálogo.

*Nidtemplate*<br/>
O ID de `CDialogBar` recurso do modelo caixa de diálogo do objeto.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se você especificar o estilo de alinhamento CBRS_TOP ou CBRS_BOTTOM, a largura da barra de diálogo é a da janela do quadro e sua altura é a do recurso especificado pelo *nIDTemplate*. Se você especificar o estilo de alinhamento CBRS_LEFT ou CBRS_RIGHT, a altura da barra de diálogo é a da janela do quadro e sua largura é a do recurso especificado pelo *nIDTemplate*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCMessageMaps#13](../../mfc/reference/codesnippet/cpp/cdialogbar-class_1.cpp)]

## <a name="see-also"></a>Confira também

[Amostra de MFC CTRLBARS](../../overview/visual-cpp-samples.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFormView](../../mfc/reference/cformview-class.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)
