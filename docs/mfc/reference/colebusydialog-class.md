---
title: Classe COleBusyDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleBusyDialog
- AFXODLGS/COleBusyDialog
- AFXODLGS/COleBusyDialog::COleBusyDialog
- AFXODLGS/COleBusyDialog::DoModal
- AFXODLGS/COleBusyDialog::GetSelectionType
- AFXODLGS/COleBusyDialog::m_bz
dev_langs:
- C++
helpviewer_keywords:
- COleBusyDialog [MFC], COleBusyDialog
- COleBusyDialog [MFC], DoModal
- COleBusyDialog [MFC], GetSelectionType
- COleBusyDialog [MFC], m_bz
ms.assetid: c881a532-9672-4c41-b51b-5ce4a7246a6b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f5b99266d465629853361c07ea16f9ae620b0e24
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43210822"
---
# <a name="colebusydialog-class"></a>Classe COleBusyDialog
Usado para as caixas de diálogo OLE servidor não respondendo ou servidor ocupado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleBusyDialog : public COleDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleBusyDialog::COleBusyDialog](#colebusydialog)|Constrói um objeto `COleBusyDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleBusyDialog::DoModal](#domodal)|Exibe a caixa de diálogo OLE servidor ocupado.|  
|[COleBusyDialog::GetSelectionType](#getselectiontype)|Determina a escolha feita na caixa de diálogo.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleBusyDialog::m_bz](#m_bz)|Estrutura do tipo OLEUIBUSY que controla o comportamento da caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
 Criar um objeto da classe `COleBusyDialog` quando você deseja chamar essas caixas de diálogo. Depois de um `COleBusyDialog` objeto foi construído, você pode usar o [m_bz](#m_bz) estrutura para inicializar os valores ou os estados dos controles na caixa de diálogo. O `m_bz` estrutura é do tipo OLEUIBUSY. Para obter mais informações sobre como usar essa classe de caixa de diálogo, consulte a [DoModal](#domodal) função de membro.  
  
> [!NOTE]
>  Código do contêiner gerado pelo Assistente de aplicativo usa essa classe.  
  
 Para obter mais informações, consulte o [OLEUIBUSY](/windows/desktop/api/oledlg/ns-oledlg-tagoleuibusya) estrutura no SDK do Windows.  
  
 Para obter mais informações sobre caixas de diálogo OLE específico, consulte o artigo [caixas de diálogo em OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COleBusyDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
##  <a name="colebusydialog"></a>  COleBusyDialog::COleBusyDialog  
 Essa função só constrói um `COleBusyDialog` objeto.  
  
```  
explicit COleBusyDialog(
    HTASK htaskBusy,  
    BOOL bNotResponding = FALSE,  
    DWORD dwFlags = 0,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *htaskBusy*  
 Identificador para a tarefa do servidor está ocupada.  
  
 *bNotResponding*  
 Se for TRUE, chame a caixa de diálogo não está respondendo em vez da caixa de diálogo servidor ocupado. O texto na caixa de diálogo não está respondendo é ligeiramente diferente do que o texto na caixa de diálogo servidor ocupado e o botão Cancelar está desabilitado.  
  
 *dwFlags*  
 Sinalizador de criação. Pode conter zero ou mais dos seguintes valores combinados com o operador OR bit a bit:  
  
- BZ_DISABLECANCELBUTTON desabilitar o botão Cancelar ao chamar a caixa de diálogo.  
  
- BZ_DISABLESWITCHTOBUTTON desabilitar o botão Alternar para ao chamar a caixa de diálogo.  
  
- BZ_DISABLERETRYBUTTON desabilitar o botão de repetição ao chamar a caixa de diálogo.  
  
 *pParentWnd*  
 Aponta para o objeto de janela pai ou proprietária (do tipo `CWnd`) ao qual pertence o objeto de caixa de diálogo. Se for NULL, a janela pai do objeto de caixa de diálogo é definida para a janela principal do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Para exibir a caixa de diálogo, chame [DoModal](#domodal).  
  
 Para obter mais informações, consulte o [OLEUIBUSY](/windows/desktop/api/oledlg/ns-oledlg-tagoleuibusya) estrutura no SDK do Windows.  
  
##  <a name="domodal"></a>  COleBusyDialog::DoModal  
 Chame essa função para exibir a caixa de diálogo OLE servidor ocupado ou servidor não está respondendo.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Status de conclusão para a caixa de diálogo. Um dos seguintes valores:  
  
- IDOK se a caixa de diálogo foi exibida com êxito.  
  
- IDCANCEL se o usuário cancelou a caixa de diálogo.  
  
- IDABORT se ocorreu um erro. Se IDABORT for retornado, chame o `COleDialog::GetLastError` a função de membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte o [OleUIBusy](/windows/desktop/api/oledlg/nf-oledlg-oleuibusya) função no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar os vários controles de caixa de diálogo definindo membros do [m_bz](#m_bz) estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
 Se `DoModal` retorna IDOK, você pode chamar outro membro funções para recuperar as configurações ou informações que era inseridas pelo usuário na caixa de diálogo.  
  
##  <a name="getselectiontype"></a>  COleBusyDialog::GetSelectionType  
 Chame essa função para obter o tipo de seleção escolhido pelo usuário na caixa de diálogo servidor ocupado.  
  
```  
UINT GetSelectionType() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Tipo de seleção feita.  
  
### <a name="remarks"></a>Comentários  
 Os valores de tipo de retorno são especificados pela `Selection` tipo de enumeração declarado no `COleBusyDialog` classe.  
  
```  
enum Selection {
    switchTo,
    retry,
    callUnblocked
    };
```  
  
 Execute as breves descrições desses valores:  
  
- `COleBusyDialog::switchTo` Alternar para o botão foi pressionado.  
  
- `COleBusyDialog::retry` Botão de repetição foi pressionado.  
  
- `COleBusyDialog::callUnblocked` Chamada para ativar o servidor agora está desbloqueado.  
  
##  <a name="m_bz"></a>  COleBusyDialog::m_bz  
 Estrutura do tipo OLEUIBUSY usado para controlar o comportamento da caixa de diálogo servidor ocupado.  
  
```  
OLEUIBUSY m_bz;  
```  
  
### <a name="remarks"></a>Comentários  
 Os membros dessa estrutura podem ser modificados diretamente ou por meio de funções de membro.  
  
 Para obter mais informações, consulte o [OLEUIBUSY](/windows/desktop/api/oledlg/ns-oledlg-tagoleuibusya) estrutura no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)
