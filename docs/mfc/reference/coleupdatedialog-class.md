---
title: Classe COleUpdateDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleUpdateDialog
- AFXODLGS/COleUpdateDialog
- AFXODLGS/COleUpdateDialog::COleUpdateDialog
- AFXODLGS/COleUpdateDialog::DoModal
dev_langs:
- C++
helpviewer_keywords:
- Update dialog
- links [C++], updating
- updating OLE links
- OLE dialog boxes, Edit Link
- OLE link updating
- COleUpdateDialog class
ms.assetid: 699ca980-52b1-4cf8-9ab1-ac6767ad5b0e
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 8066a8dc9e572c14e9423af62d340e249351ac11
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="coleupdatedialog-class"></a>Classe COleUpdateDialog
Usado para um caso especial de caixa de diálogo Editar Links OLE, que deve ser usado quando você precisa atualizar existente apenas objetos vinculados ou incorporados em um documento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleUpdateDialog : public COleLinksDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleUpdateDialog::COleUpdateDialog](#coleupdatedialog)|Constrói um objeto `COleUpdateDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleUpdateDialog::DoModal](#domodal)|Exibe o **Editar Links** caixa de diálogo em um modo de atualização.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre caixas de diálogo OLE específico, consulte o artigo [caixas de diálogo em OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 [COleLinksDialog](../../mfc/reference/colelinksdialog-class.md)  
  
 `COleUpdateDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
##  <a name="coleupdatedialog"></a>COleUpdateDialog::COleUpdateDialog  
 Constrói um objeto `COleUpdateDialog`.  
  
```  
explicit COleUpdateDialog(
    COleDocument* pDoc,  
    BOOL bUpdateLinks = TRUE,  
    BOOL bUpdateEmbeddings = FALSE,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDoc`  
 Aponta para o documento que contém os links que talvez precisem ser atualizados.  
  
 *bUpdateLinks*  
 Sinalizador que determina se os objetos vinculados devem ser atualizadas.  
  
 *bUpdateEmbeddings*  
 Sinalizador que determina se os objetos incorporados serão atualizados.  
  
 `pParentWnd`  
 Aponta para o objeto de janela pai ou proprietário (do tipo `CWnd`) ao qual pertence o objeto de caixa de diálogo. Se for **nulo**, a janela pai da caixa de diálogo será definida como a janela principal do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Essa função só constrói uma `COleUpdateDialog` objeto. Para exibir a caixa de diálogo, chame [DoModal](../../mfc/reference/colelinksdialog-class.md#domodal). Essa classe deve ser usada em vez de `COleLinksDialog` quando quiser atualizar apenas existentes vinculados ou incorporados itens.  
  
##  <a name="domodal"></a>COleUpdateDialog::DoModal  
 Exibe a caixa de diálogo Editar Links caixa no modo de atualização.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Status de conclusão para a caixa de diálogo. Um dos seguintes valores:  
  
- **IDOK** se a caixa de diálogo retornado com êxito.  
  
- **IDCANCEL** se nenhum dos itens vinculados ou incorporados no documento atual precisam ser atualizados.  
  
- **IDABORT** se ocorreu um erro. Se **IDABORT** é retornado, chame o [COleDialog::GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) a função de membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte o [OleUIEditLinks](http://msdn.microsoft.com/library/windows/desktop/ms679703) funcionar a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Todos os links e/ou objetos incorporados são atualizados a menos que o usuário seleciona o botão Cancelar.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC OCLIENT](../../visual-cpp-samples.md)   
 [Classe COleLinksDialog](../../mfc/reference/colelinksdialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleLinksDialog](../../mfc/reference/colelinksdialog-class.md)

