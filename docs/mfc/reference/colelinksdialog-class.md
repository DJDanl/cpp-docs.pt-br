---
title: Classe COleLinksDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleLinksDialog
- AFXODLGS/COleLinksDialog
- AFXODLGS/COleLinksDialog::COleLinksDialog
- AFXODLGS/COleLinksDialog::DoModal
- AFXODLGS/COleLinksDialog::m_el
dev_langs:
- C++
helpviewer_keywords:
- COleLinksDialog [MFC], COleLinksDialog
- COleLinksDialog [MFC], DoModal
- COleLinksDialog [MFC], m_el
ms.assetid: fb2eb638-2809-46db-ac74-392a732affc7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5dd17c0541b573cba40146c55b46d14143209c87
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37853872"
---
# <a name="colelinksdialog-class"></a>Classe COleLinksDialog
Usado para a caixa de diálogo Editar Links do OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleLinksDialog : public COleDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleLinksDialog::COleLinksDialog](#colelinksdialog)|Constrói um objeto `COleLinksDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleLinksDialog::DoModal](#domodal)|Exibe a caixa de diálogo Editar Links do OLE.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleLinksDialog::m_el](#m_el)|Uma estrutura do tipo OLEUIEDITLINKS que controla o comportamento da caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
 Criar um objeto da classe `COleLinksDialog` quando você deseja chamar essa caixa de diálogo. Depois de um `COleLinksDialog` objeto foi construído, você pode usar o [m_el](#m_el) estrutura para inicializar os valores ou os estados dos controles na caixa de diálogo. O `m_el` estrutura é do tipo OLEUIEDITLINKS. Para obter mais informações sobre como usar essa classe de caixa de diálogo, consulte a [DoModal](#domodal) função de membro.  
  
> [!NOTE]
>  Código do contêiner gerado pelo Assistente de aplicativo usa essa classe.  
  
 Para obter mais informações, consulte o [OLEUIEDITLINKS](http://msdn.microsoft.com/library/windows/desktop/ms678492) estrutura no SDK do Windows.  
  
 Para obter mais informações sobre caixas de diálogo OLE específico, consulte o artigo [caixas de diálogo em OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COleLinksDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
##  <a name="domodal"></a>  COleLinksDialog::DoModal  
 Exibe a caixa de diálogo Editar Links do OLE.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Status de conclusão para a caixa de diálogo. Um dos seguintes valores:  
  
- IDOK se a caixa de diálogo foi exibida com êxito.  
  
- IDCANCEL se o usuário cancelou a caixa de diálogo.  
  
- IDABORT se ocorreu um erro. Se IDABORT for retornado, chame o `COleDialog::GetLastError` a função de membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte o [OleUIEditLinks](http://msdn.microsoft.com/library/windows/desktop/ms679703) função no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar os vários controles de caixa de diálogo definindo membros do [m_el](#m_el) estrutura, você deve fazê-lo antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
##  <a name="colelinksdialog"></a>  COleLinksDialog::COleLinksDialog  
 Constrói um objeto `COleLinksDialog`.  
  
```  
COleLinksDialog (
    COleDocument* pDoc,  
    CView* pView,  
    DWORD dwFlags = 0,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDoc*  
 Aponta para o documento OLE que contém os links a serem editados.  
  
 *pView*  
 Aponta para o modo de exibição atual na *pDoc*.  
  
 *dwFlags*  
 Sinalizador de criação, que contém 0 ou ELF_SHOWHELP para especificar se o botão de Ajuda será exibido quando a caixa de diálogo é exibida.  
  
 *pParentWnd*  
 Aponta para o objeto de janela pai ou proprietária (do tipo `CWnd`) ao qual pertence o objeto de caixa de diálogo. Se for NULL, a janela pai da caixa de diálogo é definida para a janela principal do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Essa função só constrói um `COleLinksDialog` objeto. Para exibir a caixa de diálogo, chame o [DoModal](#domodal) função.  
  
##  <a name="m_el"></a>  COleLinksDialog::m_el  
 Estrutura do tipo OLEUIEDITLINKS usado para controlar o comportamento da caixa de diálogo Editar Links.  
  
```  
OLEUIEDITLINKS m_el;  
```  
  
### <a name="remarks"></a>Comentários  
 Os membros dessa estrutura podem ser modificados diretamente ou através de funções de membro.  
  
 Para obter mais informações, consulte o [OLEUIEDITLINKS](http://msdn.microsoft.com/library/windows/desktop/ms678492) estrutura no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)
