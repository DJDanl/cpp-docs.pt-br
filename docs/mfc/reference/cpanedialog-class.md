---
title: Classe CPaneDialog
ms.date: 11/04/2016
f1_keywords:
- CPaneDialog
- AFXPANEDIALOG/CPaneDialog
- AFXPANEDIALOG/CPaneDialog::Create
- AFXPANEDIALOG/CPaneDialog::HandleInitDialog
- AFXPANEDIALOG/CPaneDialog::SetOccDialogInfo
helpviewer_keywords:
- CPaneDialog [MFC], Create
- CPaneDialog [MFC], HandleInitDialog
- CPaneDialog [MFC], SetOccDialogInfo
ms.assetid: 48a6bb91-4b92-40f5-8907-b3270b146cf6
ms.openlocfilehash: e7ff55e37194d0fa405925e4b3895428cfcaf9eb
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502991"
---
# <a name="cpanedialog-class"></a>Classe CPaneDialog

A `CPaneDialog` classe dá suporte a uma caixa de diálogo sem janela restrita, encaixáveis.

## <a name="syntax"></a>Sintaxe

```
class CPaneDialog : public CDockablePane
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CPaneDialog::CPaneDialog`|Construtor padrão.|
|`CPaneDialog::~CPaneDialog`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPaneDialog::Create](#create)|Cria uma caixa de diálogo encaixáveis e a anexa a um `CPaneDialog` objeto.|
|`CPaneDialog::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|`CPaneDialog::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|[CPaneDialog::HandleInitDialog](#handleinitdialog)|Manipula a mensagem [WM_INITDIALOG](/windows/win32/dlgbox/wm-initdialog) . (Redefine `CBasePane::HandleInitDialog`.)|
|`CPaneDialog::OnEraseBkgnd`|Manipula a mensagem [WM_ERASEBKGND](/windows/win32/winmsg/wm-erasebkgnd) . (Redefine [CWnd:: OnEraseBkgnd](../../mfc/reference/cwnd-class.md#onerasebkgnd).)|
|`CPaneDialog::OnLButtonDblClk`|Manipula a mensagem [WM_LBUTTONDBLCLK](/windows/win32/inputdev/wm-lbuttondblclk) . (Redefine [CWnd:: OnLButtonDblClk](../../mfc/reference/cwnd-class.md#onlbuttondblclk).)|
|`CPaneDialog::OnLButtonDown`|Manipula a mensagem [WM_LBUTTONDOWN](/windows/win32/inputdev/wm-lbuttondown) . (Redefine [CWnd:: OnLButtonDown](../../mfc/reference/cwnd-class.md#onlbuttondown).)|
|`CPaneDialog::OnUpdateCmdUI`|Chamado pelo Framework para atualizar a janela da caixa de diálogo. (Substitui [CDockablePane:: OnUpdateCmdUI](cdockablepane-class.md).)|
|`CPaneDialog::OnWindowPosChanging`|Manipula a mensagem [WM_WINDOWPOSCHANGING](/windows/win32/winmsg/wm-windowposchanging) . (Redefine [CWnd:: OnWindowPosChanging](../../mfc/reference/cwnd-class.md#onwindowposchanging).)|
|[CPaneDialog::SetOccDialogInfo](#setoccdialoginfo)|Especifica o modelo para uma caixa de diálogo que é um contêiner de controle OLE.|

## <a name="remarks"></a>Comentários

Construa um `CPaneDialog` objeto em duas etapas. Primeiro, construa o objeto em seu código. Em segundo lugar, chame [CPaneDialog:: Create](#create). Você deve especificar um nome de modelo de recurso ou ID de modelo válido e passar um ponteiro para a janela pai. Caso contrário, o processo de criação falhará. A caixa de diálogo deve especificar o estilo WS_CHILD e WS_VISIBLE. É recomendável que você também especifique os estilos WS_CLIPCHILDREN e WS_CLIPSIBLINGS. Para obter mais informações, consulte [estilos de janela](styles-used-by-mfc.md#window-styles).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CBasePane](../../mfc/reference/cbasepane-class.md)

[CPane](../../mfc/reference/cpane-class.md)

[CDockablePane](../../mfc/reference/cdockablepane-class.md)

[CPaneDialog](../../mfc/reference/cpanedialog-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpanedialog. h

##  <a name="create"></a>  CPaneDialog::Create

Cria uma caixa de diálogo de encaixe e a anexa a um `CPaneDialog` objeto.

```
BOOL Create(
    LPCTSTR lpszWindowName,
    CWnd* pParentWnd,
    BOOL bHasGripper,
    LPCTSTR lpszTemplateName,
    UINT nStyle,
    UINT nID,
    DWORD dwTabbedStyle= AFX_CBRS_REGULAR_TABS,
    DWORD dwControlBarStyle=AFX_DEFAULT_DOCKING_PANE_STYLE);

BOOL Create(
    LPCTSTR lpszWindowName,
    CWnd* pParentWnd,
    BOOL bHasGripper,
    UINT nIDTemplate,
    UINT nStyle,
    UINT nID);

BOOL Create(
    CWnd* pParentWnd,
    LPCTSTR lpszTemplateName,
    UINT nStyle,
    UINT nID);

BOOL Create(
    CWnd* pParentWnd,
    UINT nIDTemplate,
    UINT nStyle,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*lpszWindowName*<br/>
no O nome da caixa de diálogo de encaixe.

*pParentWnd*<br/>
no Aponta para a janela pai.

*bHasGripper*<br/>
no TRUE para criar a caixa de diálogo de encaixe com uma legenda (garra); caso contrário, FALSE.

*lpszTemplateName*<br/>
no O nome do modelo de caixa de diálogo de recurso.

*nStyle*<br/>
no O estilo do Windows.

*nID*<br/>
no A ID de controle.

*nIDTemplate*<br/>
no A ID de recurso do modelo de caixa de diálogo.

*dwTabbedStyle*<br/>
no O estilo da janela com guias que ocorre quando o usuário arrasta outro painel de controle para a legenda desse painel de controle. O valor padrão é AFX_CBRS_REGULAR_TABS. Para obter mais informações, consulte a seção comentários do método [CBasePane:: CreateEx](../../mfc/reference/cbasepane-class.md#createex) .

*dwControlBarStyle*<br/>
no Atributos de estilo adicionais. O valor padrão é AFX_DEFAULT_DOCKING_PANE_STYLE. Para obter mais informações, consulte a seção comentários do método [CBasePane:: CreateEx](../../mfc/reference/cbasepane-class.md#createex) .

### <a name="return-value"></a>Valor de retorno

TRUE se esse método tiver sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `Create` método `CPaneDialog` na classe. Este exemplo faz parte da [amostra definir tamanho do painel](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_SetPaneSize#2](../../mfc/reference/codesnippet/cpp/cpanedialog-class_1.h)]
[!code-cpp[NVC_MFC_SetPaneSize#3](../../mfc/reference/codesnippet/cpp/cpanedialog-class_2.cpp)]

##  <a name="handleinitdialog"></a>  CPaneDialog::HandleInitDialog

Manipula a mensagem [WM_INITDIALOG](/windows/win32/dlgbox/wm-initdialog) .

```
afx_msg LRESULT HandleInitDialog(
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*wParam*<br/>
no Identificador para o controle que deve receber o foco padrão do teclado.

*lParam*<br/>
no Especifica dados de inicialização adicionais.

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedido; caso contrário, FALSE. Além disso, TRUE define o foco do teclado para o controle especificado pelo parâmetro *wParam* ; FALSE impede a definição do foco padrão do teclado.

### <a name="remarks"></a>Comentários

A estrutura usa esse método para inicializar controles e a aparência de uma caixa de diálogo. A estrutura chama esse método antes de exibir a caixa de diálogo.

##  <a name="setoccdialoginfo"></a>  CPaneDialog::SetOccDialogInfo

Especifica o modelo para uma caixa de diálogo que é um contêiner de controle OLE.

```
virtual BOOL SetOccDialogInfo(_AFX_OCC_DIALOG_INFO* pOccDialogInfo);
```

### <a name="parameters"></a>Parâmetros

*pOccDialogInfo*<br/>
no Ponteiro para um modelo de caixa de diálogo que é usado para criar o objeto da caixa de diálogo. O valor desse parâmetro é posteriormente passado para o método [COccManager:: CreateDlgControls](../../mfc/reference/coccmanager-class.md#createdlgcontrols) .

### <a name="return-value"></a>Valor de retorno

Sempre verdadeiro.

### <a name="remarks"></a>Comentários

Esse método dá suporte à classe [COccManager](../../mfc/reference/coccmanager-class.md) , que gerencia sites de controle OLE e controles ActiveX. A estrutura _AFX_OCC_DIALOG_INFO é definida no arquivo de Cabeçalho afxocc. h.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)<br/>
[Estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles)
