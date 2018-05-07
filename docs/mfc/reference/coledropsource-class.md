---
title: Classe COleDropSource | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleDropSource
- AFXOLE/COleDropSource
- AFXOLE/COleDropSource::COleDropSource
- AFXOLE/COleDropSource::GiveFeedback
- AFXOLE/COleDropSource::OnBeginDrag
- AFXOLE/COleDropSource::QueryContinueDrag
dev_langs:
- C++
helpviewer_keywords:
- COleDropSource [MFC], COleDropSource
- COleDropSource [MFC], GiveFeedback
- COleDropSource [MFC], OnBeginDrag
- COleDropSource [MFC], QueryContinueDrag
ms.assetid: d3eecc5f-a70b-4a01-b705-7d2c098ebe17
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e510811fcaac81aa54699250ef37f48ffe1f40e2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="coledropsource-class"></a>Classe COleDropSource
Permite que os dados ser arrastado para um destino de soltar.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleDropSource : public CCmdTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDropSource::COleDropSource](#coledropsource)|Constrói um objeto `COleDropSource`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDropSource::GiveFeedback](#givefeedback)|Altera o cursor durante uma operação de arrastar e soltar.|  
|[COleDropSource::OnBeginDrag](#onbegindrag)|Lida com a captura do mouse durante uma operação de arrastar e soltar.|  
|[COleDropSource::QueryContinueDrag](#querycontinuedrag)|Verifica se arrastando deve continuar.|  
  
## <a name="remarks"></a>Comentários  
 O [COleDropTarget](../../mfc/reference/coledroptarget-class.md) classe manipula a parte receptora da operação de arrastar e soltar. O `COleDropSource` objeto é responsável por determinar quando começa uma operação de arrastar, fornecendo comentários durante a operação de arrastar e determinar quando a operação de arrastar termina.  
  
 Para usar um `COleDropSource` de objeto, basta chamar o construtor. Isso simplifica o processo de determinar quais eventos, como um clique do mouse, iniciar uma operação de arrastar usando [COleDataSource::DoDragDrop](../../mfc/reference/coledatasource-class.md#dodragdrop), [COleClientItem::DoDragDrop](../../mfc/reference/coleclientitem-class.md#dodragdrop), ou [ COleServerItem::DoDragDrop](../../mfc/reference/coleserveritem-class.md#dodragdrop) função. Essas funções criará uma `COleDropSource` objeto para você. Você pode querer modificar o comportamento padrão da `COleDropSource` funções substituíveis. Essas funções de membro serão chamadas nos momentos apropriados do Framework.  
  
 Para obter mais informações sobre operações de arrastar e soltar usando OLE, consulte o artigo [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).  
  
 Para obter mais informações, consulte [IDropSource](http://msdn.microsoft.com/library/windows/desktop/ms690071) no SDK do Windows.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `COleDropSource`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="coledropsource"></a>  COleDropSource::COleDropSource  
 Constrói um objeto `COleDropSource`.  
  
```  
COleDropSource();
```  
  
##  <a name="givefeedback"></a>  COleDropSource::GiveFeedback  
 Chamado pelo framework depois de chamar [COleDropTarget::OnDragOver](../../mfc/reference/coledroptarget-class.md#ondragover) ou [COleDropTarget::DragEnter](../../mfc/reference/coledroptarget-class.md#ondragenter).  
  
```  
virtual SCODE GiveFeedback(DROPEFFECT dropEffect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dropEffect`  
 O efeito que você deseja exibir para o usuário, que geralmente indica o que aconteceria se uma queda ocorreu neste ponto com os dados selecionados. Normalmente, este é o valor retornado pela chamada mais recente para [CView::OnDragEnter](../../mfc/reference/cview-class.md#ondragenter) ou [CView::OnDragOver](../../mfc/reference/cview-class.md#ondragover). Pode ser uma ou mais das seguintes opções:  
  
- `DROPEFFECT_NONE` Um descarte não será permitido.  
  
- `DROPEFFECT_COPY` Uma operação de cópia deve ser executada.  
  
- `DROPEFFECT_MOVE` Uma operação de movimentação deve ser executada.  
  
- `DROPEFFECT_LINK` Um link de dados descartados para os dados originais seja estabelecido.  
  
- `DROPEFFECT_SCROLL` Uma operação de arrastar rolagem está prestes a ocorrer ou está ocorrendo no destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **DRAGDROP_S_USEDEFAULTCURSORS** se arrastando estiver em andamento, **NOERROR** se não for.  
  
### <a name="remarks"></a>Comentários  
 Substitua esta função para fornecer comentários ao usuário sobre o que aconteceria se uma queda ocorreu neste momento. A implementação padrão usa os cursores de padrão OLE. Para obter mais informações sobre operações de arrastar e soltar usando OLE, consulte o artigo [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).  
  
 Para obter mais informações, consulte [IDropSource::GiveFeedback](http://msdn.microsoft.com/library/windows/desktop/ms693723), [IDropTarget::DragOver](http://msdn.microsoft.com/library/windows/desktop/ms680129), e [IDropTarget::DragEnter](http://msdn.microsoft.com/library/windows/desktop/ms680106) no SDK do Windows.  
  
##  <a name="onbegindrag"></a>  COleDropSource::OnBeginDrag  
 Chamado pelo framework quando ocorre um evento que pode começar uma operação de arrastar, como pressionar o botão esquerdo do mouse.  
  
```  
virtual BOOL OnBeginDrag(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para a janela que contém os dados selecionados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se arrastando for permitida, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se você quiser modificar o modo como o processo de arrastar é iniciado. A implementação padrão de captura o mouse e permanece em modo de arraste até que o usuário clica no botão esquerdo ou direito do mouse ou atinge ESC, momento em que ele libera o mouse.  
  
##  <a name="querycontinuedrag"></a>  COleDropSource::QueryContinueDrag  
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
 Contém o estado das teclas modificadoras do teclado. Esta é uma combinação de qualquer número das seguintes opções: **MK_CONTROL**, **MK_SHIFT**, **MK_ALT**, **MK_LBUTTON**, **MK_ MBUTTON**, e **MK_RBUTTON**.  
  
### <a name="return-value"></a>Valor de retorno  
 **DRAGDROP_S_CANCEL** se a tecla ESC ou o botão direito é pressionado ou botão esquerdo é gerado antes de arrastar inicia. **DRAGDROP_S_DROP** se ocorrer uma operação de soltar. Caso contrário, `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Substituir que essa função se desejar alterar o ponto no qual arrastando será cancelada ou um descarte ocorre.  
  
 A implementação padrão inicia o descarte ou cancela a operação de arrastar da seguinte maneira. Cancela uma operação de arrastar quando a tecla ESC ou o botão direito do mouse é pressionado. Ele inicia uma operação de soltar quando o botão esquerdo do mouse é gerado depois de arrastar foi iniciado. Caso contrário, retornará `S_OK` e não executa nenhuma outra operação.  
  
 Como essa função é chamada com frequência, ele deve ser otimizado tanto quanto possível.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Exemplo MFC OCLIENT](../../visual-cpp-samples.md)   
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



