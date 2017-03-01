---
title: Classe COleLinksDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleLinksDialog
dev_langs:
- C++
helpviewer_keywords:
- Edit Links dialog box
- COleLinksDialog class
- dialog boxes, OLE
- OLE Edit Links dialog box
ms.assetid: fb2eb638-2809-46db-ac74-392a732affc7
caps.latest.revision: 22
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
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: ed256b3a4d3236863e3dcccb7614949f650f058b
ms.lasthandoff: 02/25/2017

---
# <a name="colelinksdialog-class"></a>Classe COleLinksDialog
Usado para a caixa de diálogo Editar Links OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleLinksDialog : public COleDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleLinksDialog::COleLinksDialog](#colelinksdialog)|Constrói um objeto `COleLinksDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleLinksDialog::DoModal](#domodal)|Exibe a caixa de diálogo Editar Links OLE.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleLinksDialog::m_el](#m_el)|Uma estrutura do tipo **OLEUIEDITLINKS** que controla o comportamento da caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
 Criar um objeto da classe `COleLinksDialog` quando você deseja chamar essa caixa de diálogo. Após um `COleLinksDialog` objeto foi construído, você pode usar o [m_el](#m_el) estrutura para inicializar os valores ou os estados de controles na caixa de diálogo. O `m_el` estrutura é do tipo **OLEUIEDITLINKS**. Para obter mais informações sobre como usar essa classe de caixa de diálogo, consulte o [DoModal](#domodal) função de membro.  
  
> [!NOTE]
>  Código do contêiner gerado pelo Assistente de aplicativo usa essa classe.  
  
 Para obter mais informações, consulte o [OLEUIEDITLINKS](http://msdn.microsoft.com/library/windows/desktop/ms678492) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
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
  
##  <a name="a-namedomodala--colelinksdialogdomodal"></a><a name="domodal"></a>COleLinksDialog::DoModal  
 Exibe a caixa de diálogo Editar Links OLE.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Status de conclusão para a caixa de diálogo. Um dos seguintes valores:  
  
- **IDOK** se a caixa de diálogo foi exibida com êxito.  
  
- **IDCANCEL** se o usuário cancelou a caixa de diálogo.  
  
- **IDABORT** se ocorreu um erro. Se **IDABORT** é retornado, chame o `COleDialog::GetLastError` a função de membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte o [OleUIEditLinks](http://msdn.microsoft.com/library/windows/desktop/ms679703) funcionar a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar os vários controles de caixa de diálogo definindo membros do [m_el](#m_el) estrutura, você deve fazê-lo antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
##  <a name="a-namecolelinksdialoga--colelinksdialogcolelinksdialog"></a><a name="colelinksdialog"></a>COleLinksDialog::COleLinksDialog  
 Constrói um objeto `COleLinksDialog`.  
  
```  
COleLinksDialog (
    COleDocument* pDoc,  
    CView* pView,  
    DWORD dwFlags = 0,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDoc`  
 Aponta para o documento OLE que contém os links a ser editada.  
  
 `pView`  
 Aponta para a exibição atual em `pDoc`.  
  
 `dwFlags`  
 Sinalizador de criação, que contém 0 ou **ELF_SHOWHELP** para especificar se o botão de Ajuda será exibido quando a caixa de diálogo é exibida.  
  
 `pParentWnd`  
 Aponta para o objeto de janela pai ou proprietário (do tipo `CWnd`) ao qual pertence o objeto de caixa de diálogo. Se for **nulo**, a janela pai da caixa de diálogo é definida para a janela principal do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Essa função só constrói uma `COleLinksDialog` objeto. Para exibir a caixa de diálogo, chame o [DoModal](#domodal) função.  
  
##  <a name="a-namemela--colelinksdialogmel"></a><a name="m_el"></a>COleLinksDialog::m_el  
 Estrutura do tipo **OLEUIEDITLINKS** usado para controlar o comportamento da caixa de diálogo Editar vínculos.  
  
```  
OLEUIEDITLINKS m_el;  
```  
  
### <a name="remarks"></a>Comentários  
 Membros dessa estrutura podem ser modificados diretamente ou através de funções de membro.  
  
 Para obter mais informações, consulte o [OLEUIEDITLINKS](http://msdn.microsoft.com/library/windows/desktop/ms678492) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)

