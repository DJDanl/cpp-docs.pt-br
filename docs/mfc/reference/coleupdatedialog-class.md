---
title: Classe COleUpdateDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleUpdateDialog
- AFXODLGS/COleUpdateDialog
- AFXODLGS/COleUpdateDialog::COleUpdateDialog
- AFXODLGS/COleUpdateDialog::DoModal
dev_langs:
- C++
helpviewer_keywords:
- COleUpdateDialog [MFC], COleUpdateDialog
- COleUpdateDialog [MFC], DoModal
ms.assetid: 699ca980-52b1-4cf8-9ab1-ac6767ad5b0e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 54088de4c07f1c58656aad468160ef58f0e41398
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="coleupdatedialog-class"></a>Classe COleUpdateDialog
Usado para um caso especial da caixa de diálogo Editar Links OLE, que deve ser usado quando você precisa atualizar existente apenas objetos vinculados ou incorporados em um documento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleUpdateDialog : public COleLinksDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
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
  
##  <a name="coleupdatedialog"></a>  COleUpdateDialog::COleUpdateDialog  
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
 Sinalizador que determina se os objetos inseridos devem ser atualizadas.  
  
 `pParentWnd`  
 Aponta para o objeto de janela pai ou o proprietário (do tipo `CWnd`) ao qual pertence o objeto de caixa de diálogo. Se for **nulo**, a janela pai da caixa de diálogo será definida para a janela principal do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Essa função só constrói um `COleUpdateDialog` objeto. Para exibir a caixa de diálogo, chame [DoModal](../../mfc/reference/colelinksdialog-class.md#domodal). Essa classe deve ser usada em vez de `COleLinksDialog` quando desejar atualizar somente existente vinculados ou incorporados itens.  
  
##  <a name="domodal"></a>  COleUpdateDialog::DoModal  
 Exibe a caixa de diálogo Editar Links caixa no modo de atualização.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Status de conclusão para a caixa de diálogo. Um dos seguintes valores:  
  
- **IDOK** se a caixa de diálogo retornado com êxito.  
  
- **IDCANCEL** se nenhum dos itens vinculados ou inseridos no documento atual precisam ser atualizados.  
  
- **IDABORT** se ocorreu um erro. Se **IDABORT** é retornado, chame o [COleDialog::GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) a função de membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte o [OleUIEditLinks](http://msdn.microsoft.com/library/windows/desktop/ms679703) função no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Todos os links e/ou objetos incorporados são atualizados, a menos que o usuário seleciona o botão Cancelar.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC OCLIENT](../../visual-cpp-samples.md)   
 [Classe COleLinksDialog](../../mfc/reference/colelinksdialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleLinksDialog](../../mfc/reference/colelinksdialog-class.md)
