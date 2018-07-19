---
title: Classe CPaneDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CPaneDialog
- AFXPANEDIALOG/CPaneDialog
- AFXPANEDIALOG/CPaneDialog::Create
- AFXPANEDIALOG/CPaneDialog::HandleInitDialog
- AFXPANEDIALOG/CPaneDialog::SetOccDialogInfo
dev_langs:
- C++
helpviewer_keywords:
- CPaneDialog [MFC], Create
- CPaneDialog [MFC], HandleInitDialog
- CPaneDialog [MFC], SetOccDialogInfo
ms.assetid: 48a6bb91-4b92-40f5-8907-b3270b146cf6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b0edc3a255d3778711b2b8e74bde448dc34c814c
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37849078"
---
# <a name="cpanedialog-class"></a>Classe CPaneDialog
O `CPaneDialog` classe dá suporte a uma caixa de diálogo sem modo e encaixável.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPaneDialog : public CDockablePane  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CPaneDialog::CPaneDialog`|Construtor padrão.|  
|`CPaneDialog::~CPaneDialog`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPaneDialog::Create](#create)|Cria uma caixa de diálogo encaixáveis e anexa-o para um `CPaneDialog` objeto.|  
|`CPaneDialog::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|  
|`CPaneDialog::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|  
|[CPaneDialog::HandleInitDialog](#handleinitdialog)|Manipula o [WM_INITDIALOG](http://msdn.microsoft.com/library/windows/desktop/ms645428) mensagem. (Redefine `CBasePane::HandleInitDialog`.)|  
|`CPaneDialog::OnEraseBkgnd`|Manipula o [WM_ERASEBKGND](http://msdn.microsoft.com/library/windows/desktop/ms648055) mensagem. (Redefine [CWnd::OnEraseBkgnd](../../mfc/reference/cwnd-class.md#onerasebkgnd).)|  
|`CPaneDialog::OnLButtonDblClk`|Manipula o [WM_LBUTTONDBLCLK](http://msdn.microsoft.com/library/windows/desktop/ms645606) mensagem. (Redefine [CWnd::OnLButtonDblClk](../../mfc/reference/cwnd-class.md#onlbuttondblclk).)|  
|`CPaneDialog::OnLButtonDown`|Manipula o [WM_LBUTTONDOWN](http://msdn.microsoft.com/library/windows/desktop/ms645607) mensagem. (Redefine [CWnd::OnLButtonDown](../../mfc/reference/cwnd-class.md#onlbuttondown).)|  
|`CPaneDialog::OnUpdateCmdUI`|Chamado pelo framework para atualizar a janela da caixa de diálogo. (Substitui [CDockablePane::OnUpdateCmdUI](http://msdn.microsoft.com/5dd61606-1c12-40d4-b024-f3839aa5e2e0).)|  
|`CPaneDialog::OnWindowPosChanging`|Manipula o [WM_WINDOWPOSCHANGING](http://msdn.microsoft.com/library/windows/desktop/ms632653) mensagem. (Redefine [CWnd::OnWindowPosChanging](../../mfc/reference/cwnd-class.md#onwindowposchanging).)|  
|[CPaneDialog::SetOccDialogInfo](#setoccdialoginfo)|Especifica o modelo para uma caixa de diálogo que é um contêiner de controle OLE.|  
  
## <a name="remarks"></a>Comentários  
 Construir um `CPaneDialog` objeto em duas etapas. Primeiro, construa o objeto em seu código. Em segundo lugar, chame [CPaneDialog::Create](#create). Você deve especificar um nome ou o modelo de ID do modelo de recurso válido e passe um ponteiro para a janela pai. Caso contrário, o processo de criação falhará. A caixa de diálogo deve especificar os estilos WS_CHILD e WS_VISIBLE. É recomendável que você também pode especificar os estilos WS_CLIPCHILDREN e WS_CLIPSIBLINGS. Para obter mais informações, consulte [estilos de janela](styles-used-by-mfc.md#window-styles).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CDockablePane](../../mfc/reference/cdockablepane-class.md)  
  
 [CPaneDialog](../../mfc/reference/cpanedialog-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpanedialog.h  
  
##  <a name="create"></a>  CPaneDialog::Create  
 Cria uma caixa de diálogo de encaixe e anexa-o para um `CPaneDialog` objeto.  
  
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
 [in] *lpszWindowName*  
 O nome da caixa de diálogo de encaixe.  
  
 [in] *pParentWnd*  
 Aponta para a janela pai.  
  
 [in] *bHasGripper*  
 TRUE para criar a caixa de diálogo de encaixe com uma legenda (garra); Caso contrário, FALSE.  
  
 [in] *lpszTemplateName*  
 O nome do modelo de caixa de diálogo do recurso.  
  
 [in] *nStyle*  
 O estilo do Windows.  
  
 [in] *nID*  
 A ID do controle.  
  
 [in] *nIDTemplate*  
 A ID de recurso do modelo de caixa de diálogo.  
  
 [in] *dwTabbedStyle*  
 O estilo da janela com guias que resulta quando o usuário arrasta o outro painel de controle para a legenda deste painel de controle. O valor padrão é AFX_CBRS_REGULAR_TABS. Para obter mais informações, consulte a seção de comentários do [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex) método.  
  
 [in] *dwControlBarStyle*  
 Atributos de estilo adicionais. O valor padrão é AFX_DEFAULT_DOCKING_PANE_STYLE. Para obter mais informações, consulte a seção de comentários do [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex) método.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se este método for bem-sucedido; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `Create` método no `CPaneDialog` classe. Este exemplo é parte do [exemplo de definir o tamanho do painel](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_SetPaneSize#2](../../mfc/reference/codesnippet/cpp/cpanedialog-class_1.h)]  
[!code-cpp[NVC_MFC_SetPaneSize#3](../../mfc/reference/codesnippet/cpp/cpanedialog-class_2.cpp)]  
  
##  <a name="handleinitdialog"></a>  CPaneDialog::HandleInitDialog  
 Manipula o [WM_INITDIALOG](http://msdn.microsoft.com/library/windows/desktop/ms645428) mensagem.  
  
```  
afx_msg LRESULT HandleInitDialog(
    WPARAM wParam,  
    LPARAM lParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *wParam*  
 Identificador para o controle que deve receber o foco do teclado padrão.  
  
 [in] *lParam*  
 Especifica os dados de inicialização adicionais.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE. Além disso, TRUE, define o foco do teclado para o controle especificado o *wParam* parâmetro; FALSE impede que definir o foco do teclado padrão.  
  
### <a name="remarks"></a>Comentários  
 A estrutura usa esse método para inicializar a aparência de uma caixa de diálogo e controles. O framework chama esse método antes de exibir a caixa de diálogo.  
  
##  <a name="setoccdialoginfo"></a>  CPaneDialog::SetOccDialogInfo  
 Especifica o modelo para uma caixa de diálogo que é um contêiner de controle OLE.  
  
```  
virtual BOOL SetOccDialogInfo(_AFX_OCC_DIALOG_INFO* pOccDialogInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pOccDialogInfo*  
 Ponteiro para um modelo de caixa de diálogo que é usado para criar o objeto de caixa de diálogo. Subsequentemente, o valor desse parâmetro é passado para o [COccManager::CreateDlgControls](../../mfc/reference/coccmanager-class.md#createdlgcontrols) método.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre TRUE.  
  
### <a name="remarks"></a>Comentários  
 Este método dá suporte a [COccManager](../../mfc/reference/coccmanager-class.md) classe, que gerencia sites de controle OLE e controles ActiveX. A estrutura _AFX_OCC_DIALOG_INFO é definida no arquivo de cabeçalho afxocc.h.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)   
 [Estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles)



