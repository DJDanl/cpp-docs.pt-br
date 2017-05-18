---
title: Classe CDataExchange | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDataExchange
- AFXWIN/CDataExchange
- AFXWIN/CDataExchange::CDataExchange
- AFXWIN/CDataExchange::Fail
- AFXWIN/CDataExchange::PrepareCtrl
- AFXWIN/CDataExchange::PrepareEditCtrl
- AFXWIN/CDataExchange::PrepareOleCtrl
- AFXWIN/CDataExchange::m_bSaveAndValidate
- AFXWIN/CDataExchange::m_pDlgWnd
dev_langs:
- C++
helpviewer_keywords:
- DDX/DDV, Technical Note 26
- DDX/DDV, CDataExchange class
- DDX (dialog data exchange), direction of exchange
- DDX (dialog data exchange), between dialog and CDialog
- DDX (dialog data exchange), custom DDX routines
- DDV (dialog data validation)
- m_bSaveAndValidate
- CDataExchange class
- exchanging data between dialogs and CDialogs
- DDV (dialog data validation), custom DDV routines
- DDX/DDV
- DDX (dialog data exchange)
- validating data, dialog box data entry
ms.assetid: 84ed6113-325d-493e-a75d-223f03a992b8
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 8f35e87d562a894411401755ccd4fdd54e43b58a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cdataexchange-class"></a>Classe CDataExchange
Suporta a troca de dados de caixa de diálogo (DDX) e rotinas de validação (DDV) de dados de caixa de diálogo usadas pelo Microsoft Foundation classes.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDataExchange  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDataExchange::CDataExchange](#cdataexchange)|Constrói um objeto `CDataExchange`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDataExchange::Fail](#fail)|Chamado quando a validação falhar. Redefine o foco para o controle anterior e gera uma exceção.|  
|[CDataExchange::PrepareCtrl](#preparectrl)|Prepara o controle especificado para a troca de dados ou validação. Uso de controles de nonedit.|  
|[CDataExchange::PrepareEditCtrl](#prepareeditctrl)|Prepara o controle de edição especificada para a troca de dados ou validação.|  
|[CDataExchange::PrepareOleCtrl](#prepareolectrl)|Prepara o controle OLE especificado para troca de dados ou de validação. Uso de controles de nonedit.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDataExchange::m_bSaveAndValidate](#m_bsaveandvalidate)|Sinalizador de direção de DDX e DDV.|  
|[CDataExchange::m_pDlgWnd](#m_pdlgwnd)|A caixa de diálogo ou janela onde os dados do exchange ocorre.|  
  
## <a name="remarks"></a>Comentários  
 `CDataExchange`não tem uma classe base.  
  
 Use essa classe, se você estiver escrevendo rotinas de troca de dados para tipos de dados personalizados ou controles, ou se você estiver escrevendo suas próprias rotinas de validação de dados. Para obter mais informações sobre como escrever suas próprias rotinas DDX e DDV, consulte [26 de nota técnica](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral de DDX e DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md) e [caixas de diálogo](../../mfc/dialog-boxes.md).  
  
 Um `CDataExchange` objeto fornece as informações de contexto necessárias para colocam DDX e DDV. O sinalizador `m_bSaveAndValidate` é **FALSE** quando DDX é usado para preencher os valores iniciais dos controles de caixa de diálogo de membros de dados. O sinalizador `m_bSaveAndValidate` é **TRUE** quando DDX é usado para definir os valores atuais dos controles de caixa de diálogo em membros de dados e quando DDV é usado para validar os valores de dados. Se a validação de DDV falhar, o procedimento DDV exibirá uma caixa de mensagem explicando o erro de entrada. Em seguida, chamará o procedimento DDV **falha** para redefinir o foco para o controle incorreto e lançar uma exceção para interromper o processo de validação.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CDataExchange`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="cdataexchange"></a>CDataExchange::CDataExchange  
 Chame essa função de membro para construir uma `CDataExchange` objeto.  
  
```  
CDataExchange(
    CWnd* pDlgWnd,  
    BOOL bSaveAndValidate);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDlgWnd*  
 Um ponteiro para a janela pai que contém o controle. Geralmente isso é uma [CDialog](../../mfc/reference/cdialog-class.md)-objeto derivado.  
  
 `bSaveAndValidate`  
 Se **TRUE**, esse objeto valida os dados, em seguida, grava os dados dos controles para os membros. Se **FALSE**, esse objeto move dados de membros para controles.  
  
### <a name="remarks"></a>Comentários  
 Construir uma `CDataExchange` objeto para armazenar informações adicionais no objeto do exchange de dados para passar para a janela [CWnd::DoDataExchange](../../mfc/reference/cwnd-class.md#dodataexchange) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog&#70;](../../mfc/codesnippet/cpp/cdataexchange-class_1.cpp)]  
  
##  <a name="fail"></a>CDataExchange::Fail  
 O framework chama essa função membro quando uma operação de validação (DDV) de dados de caixa de diálogo falha.  
  
```  
void Fail();
```  
  
### <a name="remarks"></a>Comentários  
 **Falha** restaura o foco e a seleção para o controle cuja validação falhou (se houver um controle para restaurar). **Falha na** lança uma exceção do tipo [CUserException](../../mfc/reference/cuserexception-class.md) para interromper o processo de validação. A exceção faz com que uma caixa de mensagem explicando o erro a ser exibido. Depois de DDV validação falhar, o usuário pode novamente dados no controle incorreto.  
  
 Os implementadores das rotinas DDV personalizadas podem chamar **falha** de suas rotinas quando uma validação falha.  
  
 Para obter mais informações sobre como escrever suas próprias rotinas DDX e DDV, consulte [26 de nota técnica](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral de DDX e DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md) e [tópicos da caixa de diálogo](../../mfc/dialog-boxes.md).  
  
##  <a name="m_bsaveandvalidate"></a>CDataExchange::m_bSaveAndValidate  
 Esse sinalizador indica a direção de uma operação de exchange (DDX) de dados de caixa de diálogo.  
  
```  
BOOL m_bSaveAndValidate;  
```  
  
### <a name="remarks"></a>Comentários  
 O sinalizador é diferente de zero se o `CDataExchange` objeto está sendo usado para mover dados dos controles de caixa de diálogo para membros de dados de classe de diálogo depois que o usuário edita os controles. O sinalizador é zero se o objeto está sendo usado para inicializar os controles de caixa de diálogo de membros de dados de classe de caixa de diálogo.  
  
 O sinalizador também é diferente de zero durante a validação de dados de caixa de diálogo (DDV).  
  
 Para obter mais informações sobre como escrever suas próprias rotinas DDX e DDV, consulte [26 de nota técnica](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral de DDX e DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md) e [tópicos da caixa de diálogo](../../mfc/dialog-boxes.md).  
  
##  <a name="m_pdlgwnd"></a>CDataExchange::m_pDlgWnd  
 Contém um ponteiro para o [CWnd](../../mfc/reference/cwnd-class.md) objeto para o qual caixa de diálogo (DDX) de troca de dados ou de validação (DDV) está em andamento.  
  
```  
CWnd* m_pDlgWnd;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse objeto é geralmente um [CDialog](../../mfc/reference/cdialog-class.md) objeto. Os implementadores das rotinas DDX ou DDV personalizadas podem usar esse ponteiro para obter acesso à caixa de diálogo janela que contém os controles que estejam operando em.  
  
 Para obter mais informações sobre como escrever suas próprias rotinas DDX e DDV, consulte [26 de nota técnica](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral de DDX e DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md) e [tópicos da caixa de diálogo](../../mfc/dialog-boxes.md).  
  
##  <a name="preparectrl"></a>CDataExchange::PrepareCtrl  
 O framework chama essa função de membro para preparar o controle especificado para troca de dados de caixa de diálogo (DDX) e validação (DDV).  
  
```  
HWND PrepareCtrl(int nIDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDC`  
 A ID do controle para estar preparado para DDX ou DDV.  
  
### <a name="return-value"></a>Valor de retorno  
 O `HWND` do controle estar preparado para DDX ou DDV.  
  
### <a name="remarks"></a>Comentários  
 Use [PrepareEditCtrl](#prepareeditctrl) para controles de edição; usaremos essa função de membro para todos os outros controles.  
  
 Preparação consiste em armazenar o controle `HWND` na `CDataExchange` classe. A estrutura usa esse identificador para restaurar o foco para o controle anteriormente focalizado em caso de falha DDX ou DDV.  
  
 Os implementadores das rotinas DDX ou DDV personalizados devem chamar `PrepareCtrl` para todos os controles de edição não para os quais eles estão trocando dados por meio de DDX ou validação de dados via DDV.  
  
 Para obter mais informações sobre como escrever suas próprias rotinas DDX e DDV, consulte [26 de nota técnica](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral de DDX e DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md) e [tópicos da caixa de diálogo](../../mfc/dialog-boxes.md).  
  
##  <a name="prepareeditctrl"></a>CDataExchange::PrepareEditCtrl  
 O framework chama essa função de membro para preparar o controle de edição especificada para troca de dados de caixa de diálogo (DDX) e validação (DDV).  
  
```  
HWND PrepareEditCtrl(int nIDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDC`  
 A ID do controle de edição para estar preparado para DDX ou DDV.  
  
### <a name="return-value"></a>Valor de retorno  
 O `HWND` do controle de edição que está sendo preparado para DDX ou DDV.  
  
### <a name="remarks"></a>Comentários  
 Use [PrepareCtrl](#preparectrl) em vez disso, para todos os controles de edição não.  
  
 Preparação consiste em duas coisas. Primeiro, `PrepareEditCtrl` armazena o controle `HWND` na `CDataExchange` classe. A estrutura usa esse identificador para restaurar o foco para o controle anteriormente focalizado em caso de falha DDX ou DDV. Segundo, `PrepareEditCtrl` define um sinalizador de `CDataExchange` classe para indicar que o controle cujos dados está sendo trocados ou validado é um controle de edição.  
  
 Os implementadores das rotinas DDX ou DDV personalizados devem chamar `PrepareEditCtrl` para todos os controles para os quais eles estão trocando dados por meio de DDX ou validação de dados via DDV de edição.  
  
 Para obter mais informações sobre como escrever suas próprias rotinas DDX e DDV, consulte [26 de nota técnica](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral de DDX e DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md) e [tópicos da caixa de diálogo](../../mfc/dialog-boxes.md).  
  
##  <a name="prepareolectrl"></a>CDataExchange::PrepareOleCtrl  
 O framework chama essa função de membro para preparar o controle OLE especificado para troca de dados de caixa de diálogo (DDX) e validação (DDV).  
  
```  
COleControlSite* PrepareOleCtrl(int nIDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDC`  
 A ID do controle OLE para estar preparado para DDX ou DDV.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o site de controle OLE.  
  
### <a name="remarks"></a>Comentários  
 Use [PrepareEditCtrl](#prepareeditctrl) em vez disso, para controles de edição ou [PrepareCtrl](#preparectrl) para todos os outros controles não são OLE.  
  
 Os implementadores das rotinas DDX ou DDV personalizados devem chamar `PrepareOleCtrl` para todos os controles OLE para o qual eles estão trocando dados por meio de DDX ou validação de dados via DDV.  
  
 Para obter mais informações sobre como escrever suas próprias rotinas DDX e DDV, consulte [26 de nota técnica](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral de DDX e DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md) e [tópicos da caixa de diálogo](../../mfc/dialog-boxes.md).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC VIEWEX](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [CWnd::DoDataExchange](../../mfc/reference/cwnd-class.md#dodataexchange)   
 [CWnd::UpdateData](../../mfc/reference/cwnd-class.md#updatedata)


