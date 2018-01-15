---
title: Classe COleBusyDialog | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleBusyDialog
- AFXODLGS/COleBusyDialog
- AFXODLGS/COleBusyDialog::COleBusyDialog
- AFXODLGS/COleBusyDialog::DoModal
- AFXODLGS/COleBusyDialog::GetSelectionType
- AFXODLGS/COleBusyDialog::m_bz
dev_langs: C++
helpviewer_keywords:
- COleBusyDialog [MFC], COleBusyDialog
- COleBusyDialog [MFC], DoModal
- COleBusyDialog [MFC], GetSelectionType
- COleBusyDialog [MFC], m_bz
ms.assetid: c881a532-9672-4c41-b51b-5ce4a7246a6b
caps.latest.revision: "22"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0e57881dad305a5a0d5cec25ddcc93f82eca5f26
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="colebusydialog-class"></a>Classe COleBusyDialog
Usado para as caixas de diálogo OLE servidor não está respondendo ou servidor ocupado.  
  
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
|[COleBusyDialog::m_bz](#m_bz)|Estrutura do tipo **OLEUIBUSY** que controla o comportamento da caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
 Criar um objeto da classe `COleBusyDialog` quando quiser chamar essas caixas de diálogo. Após um `COleBusyDialog` objeto foi construído, você pode usar o [m_bz](#m_bz) estrutura para inicializar os valores ou os estados de controles da caixa de diálogo. O `m_bz` estrutura é do tipo **OLEUIBUSY**. Para obter mais informações sobre como usar essa classe de caixa de diálogo, consulte o [DoModal](#domodal) função de membro.  
  
> [!NOTE]
>  Código gerado pelo Assistente de contêiner do aplicativo usa essa classe.  
  
 Para obter mais informações, consulte o [OLEUIBUSY](http://msdn.microsoft.com/library/windows/desktop/ms682493) estrutura no SDK do Windows.  
  
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
  
##  <a name="colebusydialog"></a>COleBusyDialog::COleBusyDialog  
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
 Se **TRUE**, chame a caixa de diálogo não está respondendo em vez da caixa de diálogo servidor ocupado. O texto na caixa de diálogo não está respondendo é ligeiramente diferente da frase na caixa de diálogo servidor ocupado e o botão Cancelar está desabilitado.  
  
 `dwFlags`  
 Sinalizador de criação. Pode conter zero ou mais dos seguintes valores combinados com o operador OR bit a bit:  
  
- **BZ_DISABLECANCELBUTTON** desabilitar o botão Cancelar ao chamar a caixa de diálogo.  
  
- **BZ_DISABLESWITCHTOBUTTON** desabilitar o botão de opção para ao chamar a caixa de diálogo.  
  
- **BZ_DISABLERETRYBUTTON** desabilitar o botão de repetição ao chamar a caixa de diálogo.  
  
 `pParentWnd`  
 Aponta para o objeto de janela pai ou o proprietário (do tipo `CWnd`) ao qual pertence o objeto de caixa de diálogo. Se for **nulo**, a janela pai do objeto de caixa de diálogo é definida como a janela principal do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Para exibir a caixa de diálogo, chame [DoModal](#domodal).  
  
 Para obter mais informações, consulte o [OLEUIBUSY](http://msdn.microsoft.com/library/windows/desktop/ms682493) estrutura no SDK do Windows.  
  
##  <a name="domodal"></a>COleBusyDialog::DoModal  
 Chame essa função para exibir a caixa de diálogo OLE servidor ocupado ou o servidor não está respondendo.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Status de conclusão para a caixa de diálogo. Um dos seguintes valores:  
  
- **IDOK** se a caixa de diálogo foi exibida com êxito.  
  
- **IDCANCEL** se o usuário cancelou a caixa de diálogo.  
  
- **IDABORT** se ocorreu um erro. Se **IDABORT** é retornado, chame o `COleDialog::GetLastError` a função de membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte o [OleUIBusy](http://msdn.microsoft.com/library/windows/desktop/ms680125) função no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar os vários controles de caixa de diálogo definindo membros do [m_bz](#m_bz) estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
 Se `DoModal` retorna **IDOK**, você pode chamar outro membro funções para recuperar as configurações ou informações que foi inseridas pelo usuário na caixa de diálogo.  
  
##  <a name="getselectiontype"></a>COleBusyDialog::GetSelectionType  
 Chame essa função para obter o tipo de seleção escolhido pelo usuário na caixa de diálogo servidor ocupado.  
  
```  
UINT GetSelectionType() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Tipo de seleção feita.  
  
### <a name="remarks"></a>Comentários  
 Os valores de tipo de retorno são especificados pelo **seleção** tipo de enumeração declarado no `COleBusyDialog` classe.  
  
```  
enum Selection {
    switchTo,
    retry,
    callUnblocked
    };
```  
  
 Execute as breves descrições desses valores:  
  
- **COleBusyDialog::switchTo** alternar para o botão foi pressionado.  
  
- **COleBusyDialog::retry** foi pressionado o botão de repetição.  
  
- **COleBusyDialog::callUnblocked** chamada para ativar o servidor agora está desbloqueado.  
  
##  <a name="m_bz"></a>COleBusyDialog::m_bz  
 Estrutura do tipo **OLEUIBUSY** usado para controlar o comportamento da caixa de diálogo servidor ocupado.  
  
```  
OLEUIBUSY m_bz;  
```  
  
### <a name="remarks"></a>Comentários  
 Membros dessa estrutura podem ser modificados diretamente ou por meio de funções de membro.  
  
 Para obter mais informações, consulte o [OLEUIBUSY](http://msdn.microsoft.com/library/windows/desktop/ms682493) estrutura no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)
