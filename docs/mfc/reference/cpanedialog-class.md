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
ms.openlocfilehash: ad1225034cc5eca8ca53b042ebe3b55db4a2cf09
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364132"
---
# <a name="cpanedialog-class"></a>Classe CPaneDialog

A `CPaneDialog` classe suporta uma caixa de diálogo modelada e ancorável.

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
|[CPaneDialog::Criar](#create)|Cria uma caixa de diálogo ancorável e a anexa a um `CPaneDialog` objeto.|
|`CPaneDialog::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|`CPaneDialog::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[cpaneDialog::HandleInitDialog](#handleinitdialog)|Lida com a mensagem [WM_INITDIALOG.](/windows/win32/dlgbox/wm-initdialog) (Redefine `CBasePane::HandleInitDialog`.)|
|`CPaneDialog::OnEraseBkgnd`|Lida com a mensagem [WM_ERASEBKGND.](/windows/win32/winmsg/wm-erasebkgnd) (Redefine [CWnd::OnEraseBkgnd](../../mfc/reference/cwnd-class.md#onerasebkgnd).)|
|`CPaneDialog::OnLButtonDblClk`|Lida com a mensagem [WM_LBUTTONDBLCLK.](/windows/win32/inputdev/wm-lbuttondblclk) (Redefine [CWnd::OnLButtonDblClk](../../mfc/reference/cwnd-class.md#onlbuttondblclk).)|
|`CPaneDialog::OnLButtonDown`|Lida com a mensagem [WM_LBUTTONDOWN.](/windows/win32/inputdev/wm-lbuttondown) (Redefine [CWnd::OnLButtonDown](../../mfc/reference/cwnd-class.md#onlbuttondown).)|
|`CPaneDialog::OnUpdateCmdUI`|Chamado pelo framework para atualizar a janela da caixa de diálogo. (Substitui [cdockablepane::OnUpdateCmdUI](cdockablepane-class.md).)|
|`CPaneDialog::OnWindowPosChanging`|Lida com a mensagem [WM_WINDOWPOSCHANGING.](/windows/win32/winmsg/wm-windowposchanging) (Redefine [CWnd::OnWindowPosChanging](../../mfc/reference/cwnd-class.md#onwindowposchanging).)|
|[cpaneDialog::SetOccDialogInfo](#setoccdialoginfo)|Especifica o modelo para uma caixa de diálogo que é um recipiente de controle OLE.|

## <a name="remarks"></a>Comentários

Construa `CPaneDialog` um objeto em dois passos. Primeiro, construa o objeto em seu código. Em segundo lugar, ligue para [CPaneDialog::Create](#create). Você deve especificar um nome de modelo de recurso válido ou um ID de modelo e passar um ponteiro para a janela pai. Caso contrário, o processo de criação falha. A caixa de diálogo deve especificar o estilo WS_CHILD e WS_VISIBLE. Recomendamos que você também especifique os estilos WS_CLIPCHILDREN e WS_CLIPSIBLINGS. Para obter mais informações, consulte [Estilos de janela](styles-used-by-mfc.md#window-styles).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cpane](../../mfc/reference/cpane-class.md)

[Cdockablepane](../../mfc/reference/cdockablepane-class.md)

[Cpanedialog](../../mfc/reference/cpanedialog-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpanedialog.h

## <a name="cpanedialogcreate"></a><a name="create"></a>CPaneDialog::Criar

Cria uma caixa de diálogo de `CPaneDialog` encaixe e a anexa a um objeto.

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
[em] O nome da caixa de diálogo de acoplamento.

*Pparentwnd*<br/>
[em] Aponta para a janela dos pais.

*bHasGripper*<br/>
[em] TRUE para criar a caixa de diálogo de encaixe com uma legenda (gripper); caso contrário, FALSE.

*lpszTemplateName*<br/>
[em] O nome do modelo de diálogo de recursos.

*nStyle*<br/>
[em] O estilo Windows.

*nID*<br/>
[em] A id de controle.

*Nidtemplate*<br/>
[em] O ID de recurso do modelo de diálogo.

*Dwtabbedstyle*<br/>
[em] O estilo da janela com guias que resulta quando o usuário arrasta outro painel de controle para a legenda deste painel de controle. O valor padrão é AFX_CBRS_REGULAR_TABS. Para obter mais informações, consulte a seção Observações do método [CBasePane::CreateEx.](../../mfc/reference/cbasepane-class.md#createex)

*dwControlBarStyle*<br/>
[em] Atributos adicionais de estilo. O valor padrão é AFX_DEFAULT_DOCKING_PANE_STYLE. Para obter mais informações, consulte a seção Observações do método [CBasePane::CreateEx.](../../mfc/reference/cbasepane-class.md#createex)

### <a name="return-value"></a>Valor retornado

VERDADEIRO se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

O exemplo a seguir `Create` demonstra como `CPaneDialog` usar o método na classe. Este exemplo faz parte da amostra Tamanho do [painel de conjunto](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_SetPaneSize#2](../../mfc/reference/codesnippet/cpp/cpanedialog-class_1.h)]
[!code-cpp[NVC_MFC_SetPaneSize#3](../../mfc/reference/codesnippet/cpp/cpanedialog-class_2.cpp)]

## <a name="cpanedialoghandleinitdialog"></a><a name="handleinitdialog"></a>cpaneDialog::HandleInitDialog

Lida com a mensagem [WM_INITDIALOG.](/windows/win32/dlgbox/wm-initdialog)

```
afx_msg LRESULT HandleInitDialog(
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*wParam*<br/>
[em] Manuseie o controle que é para receber o foco padrão do teclado.

*lParam*<br/>
[em] Especifica dados adicionais de inicialização.

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE. Além disso, TRUE define o foco do teclado para o controle especificado pelo parâmetro *wParam;* FALSE impede a definição do foco padrão do teclado.

### <a name="remarks"></a>Comentários

A estrutura usa esse método para inicializar controles e o aparecimento de uma caixa de diálogo. A estrutura chama esse método antes de exibir a caixa de diálogo.

## <a name="cpanedialogsetoccdialoginfo"></a><a name="setoccdialoginfo"></a>cpaneDialog::SetOccDialogInfo

Especifica o modelo para uma caixa de diálogo que é um recipiente de controle OLE.

```
virtual BOOL SetOccDialogInfo(_AFX_OCC_DIALOG_INFO* pOccDialogInfo);
```

### <a name="parameters"></a>Parâmetros

*pOccDialogInfo*<br/>
[em] Ponteiro para um modelo de caixa de diálogo que é usado para criar o objeto caixa de diálogo. O valor deste parâmetro é posteriormente passado para o método [COccManager::CreateDlgControls.](../../mfc/reference/coccmanager-class.md#createdlgcontrols)

### <a name="return-value"></a>Valor retornado

Sempre TRUE.

### <a name="remarks"></a>Comentários

Este método suporta a classe [COccManager,](../../mfc/reference/coccmanager-class.md) que gerencia sites de controle OLE e controles ActiveX. A estrutura _AFX_OCC_DIALOG_INFO é definida no arquivo de cabeçalho afxocc.h.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)<br/>
[Estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles)
