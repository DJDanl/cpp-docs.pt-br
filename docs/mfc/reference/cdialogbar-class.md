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
ms.openlocfilehash: af84c5239a9cb3cbddb1ab4f0230e5b1a3373573
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78883611"
---
# <a name="cdialogbar-class"></a>Classe CDialogBar

Fornece a funcionalidade de uma caixa de diálogo sem janela restrita do Windows em uma barra de controle.

## <a name="syntax"></a>Sintaxe

```
class CDialogBar : public CControlBar
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CDialogBar:: CDialogBar](#cdialogbar)|Constrói um objeto `CDialogBar`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CDialogBar:: criar](#create)|Cria uma barra de diálogo do Windows e a anexa ao objeto `CDialogBar`.|

## <a name="remarks"></a>Comentários

Uma barra de diálogo é semelhante a uma caixa de diálogo na qual ela contém controles padrão do Windows que o usuário pode Tab. Outra similaridade é que você crie um modelo de caixa de diálogo para representar a barra de diálogo.

Criar e usar uma barra de diálogo é semelhante a criar e usar um objeto `CFormView`. Primeiro, use o [Editor de caixa de diálogo](../../windows/dialog-editor.md) para definir um modelo de caixa de diálogo com o estilo WS_CHILD e nenhum outro estilo. O modelo não deve ter o estilo WS_VISIBLE. No código do aplicativo, chame o construtor para construir o objeto `CDialogBar`, em seguida, chame `Create` para criar a janela da barra de caixas de diálogo e anexe-a ao objeto `CDialogBar`.

Para obter mais informações sobre `CDialogBar`, consulte as [barras de diálogo](../../mfc/dialog-bars.md) do artigo e a [Nota técnica 31](../../mfc/tn031-control-bars.md), barras de controle.

> [!NOTE]
>  Na versão atual, um objeto `CDialogBar` não pode hospedar Windows Forms controles. Para obter mais informações sobre controles de Windows Forms C++no Visual, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CControlBar](../../mfc/reference/ccontrolbar-class.md)

`CDialogBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext. h

##  <a name="cdialogbar"></a>CDialogBar:: CDialogBar

Constrói um objeto `CDialogBar`.

```
CDialogBar();
```

##  <a name="create"></a>CDialogBar:: criar

Carrega o modelo de recurso de caixa de diálogo especificado por `lpszTemplateName` ou `nIDTemplate`, cria a janela de barras de diálogo, define seu estilo e o associa ao objeto `CDialogBar`.

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

### <a name="parameters"></a>parâmetros

*pParentWnd*<br/>
Um ponteiro para o objeto de `CWnd` pai.

*lpszTemplateName*<br/>
Um ponteiro para o nome do modelo de recurso de caixa de diálogo do objeto de `CDialogBar`.

*nStyle*<br/>
O estilo da barra de ferramentas. Os estilos de barra de ferramentas adicionais com suporte são:

- CBRS_TOP Barra de controle está na parte superior da janela do quadro.

- CBRS_BOTTOM barra de controle está na parte inferior da janela do quadro.

- CBRS_NOALIGN Barra de controle não é reposicionada quando o pai é redimensionado.

- CBRS_TOOLTIPS barra de controle exibe dicas de ferramenta.

- CBRS_SIZE_DYNAMIC barra de controle é dinâmica.

- CBRS_SIZE_FIXED barra de controle é fixa.

- CBRS_FLOATING barra de controle está flutuante.

- CBRS_FLYBY Barra de status exibe informações sobre o botão.

- CBRS_HIDE_INPLACE barra de controle não é exibida para o usuário.

*nID*<br/>
A ID de controle da barra de diálogo.

*nIDTemplate*<br/>
A ID de recurso do modelo de caixa de diálogo do objeto de `CDialogBar`.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se você especificar o estilo de alinhamento CBRS_TOP ou CBRS_BOTTOM, a largura da barra de diálogo será a da janela do quadro e sua altura será a do recurso especificado por *nIDTemplate*. Se você especificar o CBRS_LEFT ou o estilo de alinhamento de CBRS_RIGHT, a altura da barra de diálogo será aquela da janela do quadro e sua largura será a do recurso especificado por *nIDTemplate*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCMessageMaps#13](../../mfc/reference/codesnippet/cpp/cdialogbar-class_1.cpp)]

## <a name="see-also"></a>Confira também

[Exemplo de CTRLBARS do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFormView](../../mfc/reference/cformview-class.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)
