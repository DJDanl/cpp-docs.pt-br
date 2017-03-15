---
title: Classe COleDropSource | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleDropSource
dev_langs:
- C++
helpviewer_keywords:
- drag operations
- drop target, dragging data to
- COleDropSource class
- drag and drop, drop source
ms.assetid: d3eecc5f-a70b-4a01-b705-7d2c098ebe17
caps.latest.revision: 24
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: f3d0e5b7184cf305459173065b8e1cc07e032aef
ms.lasthandoff: 02/25/2017

---
# <a name="coledropsource-class"></a>Classe COleDropSource
Permite que os dados ser arrastado para um destino de soltar.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleDropSource : public CCmdTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDropSource::COleDropSource](#coledropsource)|Constrói um objeto `COleDropSource`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDropSource::GiveFeedback](#givefeedback)|Altera o cursor durante uma operação de arrastar e soltar.|  
|[COleDropSource::OnBeginDrag](#onbegindrag)|Manipula a captura do mouse durante uma operação de arrastar e soltar.|  
|[COleDropSource::QueryContinueDrag](#querycontinuedrag)|Verifica se arrastar deve continuar.|  
  
## <a name="remarks"></a>Comentários  
 O [COleDropTarget](../../mfc/reference/coledroptarget-class.md) classe trata a parte receptora da operação de arrastar e soltar. O `COleDropSource` objeto é responsável por determinar quando começa uma operação de arrastar, fornecendo comentários durante a operação de arrastar e determinar quando a operação de arrastar termina.  
  
 Para usar um `COleDropSource` de objeto, basta chamar o construtor. Isso simplifica o processo de determinar quais eventos, como um clique do mouse, iniciar uma operação de arrastar usando [COleDataSource::DoDragDrop](../../mfc/reference/coledatasource-class.md#dodragdrop), [COleClientItem::DoDragDrop](../../mfc/reference/coleclientitem-class.md#dodragdrop), ou [COleServerItem::DoDragDrop](../../mfc/reference/coleserveritem-class.md#dodragdrop) função. Essas funções criará uma `COleDropSource` objeto para você. Você talvez queira modificar o comportamento padrão de `COleDropSource` funções substituíveis. Essas funções de membro serão chamadas nos momentos apropriados do Framework.  
  
 Para obter mais informações sobre operações de arrastar e soltar usando OLE, consulte o artigo [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).  
  
 Para obter mais informações, consulte [IDropSource](http://msdn.microsoft.com/library/windows/desktop/ms690071) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `COleDropSource`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="a-namecoledropsourcea--coledropsourcecoledropsource"></a><a name="coledropsource"></a>COleDropSource::COleDropSource  
 Constrói um objeto `COleDropSource`.  
  
```  
COleDropSource();
```  
  
##  <a name="a-namegivefeedbacka--coledropsourcegivefeedback"></a><a name="givefeedback"></a>COleDropSource::GiveFeedback  
 Chamado pela estrutura depois de chamar [COleDropTarget::OnDragOver](../../mfc/reference/coledroptarget-class.md#ondragover) ou [COleDropTarget::DragEnter](../../mfc/reference/coledroptarget-class.md#ondragenter).  
  
```  
virtual SCODE GiveFeedback(DROPEFFECT dropEffect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dropEffect`  
 O efeito que você deseja exibir para o usuário, que geralmente indica o que aconteceria se uma queda ocorreu neste ponto, com os dados selecionados. Normalmente, esse é o valor retornado pela chamada mais recente para [CView::OnDragEnter](../../mfc/reference/cview-class.md#ondragenter) ou [CView::OnDragOver](../../mfc/reference/cview-class.md#ondragover). Ele pode ser um ou mais destes procedimentos:  
  
- `DROPEFFECT_NONE`Uma lista não seria permitida.  
  
- `DROPEFFECT_COPY`Uma operação de cópia seria realizada.  
  
- `DROPEFFECT_MOVE`Uma operação de movimentação seria realizada.  
  
- `DROPEFFECT_LINK`Seria possível estabelecer um vínculo de dados eliminados para os dados originais.  
  
- `DROPEFFECT_SCROLL`Uma operação de arrastar rolagem está prestes a ocorrer ou está ocorrendo no destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **DRAGDROP_S_USEDEFAULTCURSORS** se arrastar estiver em andamento, **NOERROR** se não for.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para fornecer comentários ao usuário sobre o que aconteceria se uma queda ocorreu neste momento. A implementação padrão usa cursores de padrão de OLE. Para obter mais informações sobre operações de arrastar e soltar usando OLE, consulte o artigo [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).  
  
 Para obter mais informações, consulte [IDropSource::GiveFeedback](http://msdn.microsoft.com/library/windows/desktop/ms693723), [IDropTarget::DragOver](http://msdn.microsoft.com/library/windows/desktop/ms680129), e [IDropTarget::DragEnter](http://msdn.microsoft.com/library/windows/desktop/ms680106) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameonbegindraga--coledropsourceonbegindrag"></a><a name="onbegindrag"></a>COleDropSource::OnBeginDrag  
 Chamado pela estrutura quando ocorre um evento que pode começar uma operação de arrastar, como pressionar o botão esquerdo do mouse.  
  
```  
virtual BOOL OnBeginDrag(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para a janela que contém os dados selecionados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se arrastar for permitida, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se você quiser modificar o modo como o processo de arrastar é iniciado. A implementação padrão de captura do mouse e permanece no modo arrastar até que o usuário clica no botão esquerdo ou direito do mouse ou pressiona ESC, momento em que ele libera o mouse.  
  
##  <a name="a-namequerycontinuedraga--coledropsourcequerycontinuedrag"></a><a name="querycontinuedrag"></a>COleDropSource::QueryContinueDrag  
 Depois de arrastar iniciada, essa função é chamada repetidamente pela estrutura até que a operação de arrastar seja cancelada ou concluída.  
  
```  
virtual SCODE QueryContinueDrag(
    BOOL bEscapePressed, 
    DWORD dwKeyState);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bEscapePressed*  
 Indica se a tecla ESC foi pressionada desde a última chamada para `COleDropSource::QueryContinueDrag`.  
  
 `dwKeyState`  
 Contém o estado das teclas modificadoras do teclado. Isso é uma combinação de qualquer número das seguintes opções: **MK_CONTROL**, **MK_SHIFT**, **MK_ALT**, **MK_LBUTTON**, **MK_MBUTTON**, e **MK_RBUTTON**.  
  
### <a name="return-value"></a>Valor de retorno  
 **DRAGDROP_S_CANCEL** se a tecla ESC ou o botão direito é pressionado ou botão esquerdo é gerado antes de arrastar inicia. **DRAGDROP_S_DROP** se uma operação de soltar ocorrer. Caso contrário, `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Substituir que essa função se você quiser alterar o ponto no qual arrastando é cancelada ou soltar ocorre.  
  
 A implementação padrão inicia o descarte ou cancela a arrastar da seguinte maneira. Quando a tecla ESC ou o botão direito do mouse é pressionado, ele cancela uma operação de arrastar. Ele inicia uma operação de soltar quando o botão esquerdo é gerado depois de arrastar foi iniciado. Caso contrário, ele retorna `S_OK` e executa sem outras operações.  
  
 Como essa função é chamada com frequência, ele deve ser otimizado tanto quanto possível.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Exemplo MFC OCLIENT](../../visual-cpp-samples.md)   
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




