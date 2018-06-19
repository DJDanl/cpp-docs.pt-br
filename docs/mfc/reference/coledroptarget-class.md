---
title: Classe COleDropTarget | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleDropTarget
- AFXOLE/COleDropTarget
- AFXOLE/COleDropTarget::COleDropTarget
- AFXOLE/COleDropTarget::OnDragEnter
- AFXOLE/COleDropTarget::OnDragLeave
- AFXOLE/COleDropTarget::OnDragOver
- AFXOLE/COleDropTarget::OnDragScroll
- AFXOLE/COleDropTarget::OnDrop
- AFXOLE/COleDropTarget::OnDropEx
- AFXOLE/COleDropTarget::Register
- AFXOLE/COleDropTarget::Revoke
dev_langs:
- C++
helpviewer_keywords:
- COleDropTarget [MFC], COleDropTarget
- COleDropTarget [MFC], OnDragEnter
- COleDropTarget [MFC], OnDragLeave
- COleDropTarget [MFC], OnDragOver
- COleDropTarget [MFC], OnDragScroll
- COleDropTarget [MFC], OnDrop
- COleDropTarget [MFC], OnDropEx
- COleDropTarget [MFC], Register
- COleDropTarget [MFC], Revoke
ms.assetid: a58c9a48-6a93-4357-b078-4594df258311
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eb52739977b641cd5d52f018efcd30a51ecf1e32
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33373127"
---
# <a name="coledroptarget-class"></a>Classe COleDropTarget
Fornece o mecanismo de comunicação entre uma janela e das bibliotecas OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleDropTarget : public CCmdTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDropTarget::COleDropTarget](#coledroptarget)|Constrói um objeto `COleDropTarget`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDropTarget::OnDragEnter](#ondragenter)|Chamado quando o cursor entra primeiro na janela.|  
|[COleDropTarget::OnDragLeave](#ondragleave)|Chamado quando o cursor é arrastado para fora da janela.|  
|[COleDropTarget::OnDragOver](#ondragover)|Chamado repetidamente quando o cursor é arrastado sobre a janela.|  
|[COleDropTarget::OnDragScroll](#ondragscroll)|Chamado para determinar se o cursor é arrastado para a região de rolagem da janela.|  
|[COleDropTarget::OnDrop](#ondrop)|Chamado quando dados são descartados para a janela, o manipulador padrão.|  
|[COleDropTarget::OnDropEx](#ondropex)|Chamado quando dados são descartados para a janela, o manipulador inicial.|  
|[COleDropTarget::Register](#register)|Registra a janela como um destino válido.|  
|[COleDropTarget::Revoke](#revoke)|Faz com que a janela pare de ser um destino válido.|  
  
## <a name="remarks"></a>Comentários  
 Criação de um objeto dessa classe permite que uma janela aceitar dados por meio do mecanismo de arrastar e soltar OLE.  
  
 Para obter uma janela para aceitar comandos drop, você deve primeiro criar um objeto do `COleDropTarget` classe e, em seguida, chame o [registrar](#register) função com um ponteiro para o desejado `CWnd` objeto como o único parâmetro.  
  
 Para obter mais informações sobre operações de arrastar e soltar usando OLE, consulte o artigo [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `COleDropTarget`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="coledroptarget"></a>  COleDropTarget::COleDropTarget  
 Constrói um objeto da classe `COleDropTarget`.  
  
```  
COleDropTarget();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar [registrar](#register) para associar o objeto uma janela.  
  
##  <a name="ondragenter"></a>  COleDropTarget::OnDragEnter  
 Chamado pelo framework quando o cursor é arrastado primeiro na janela.  
  
```  
virtual DROPEFFECT OnDragEnter(
    CWnd* pWnd,  
    COleDataObject* pDataObject,  
    DWORD dwKeyState,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Inserção de pontos para a janela do cursor.  
  
 `pDataObject`  
 Aponta para o objeto de dados que contém os dados que podem ser descartados.  
  
 `dwKeyState`  
 Contém o estado das teclas modificadoras. Esta é uma combinação de qualquer número das seguintes opções: **MK_CONTROL**, **MK_SHIFT**, **MK_ALT**, **MK_LBUTTON**, **MK_ MBUTTON**, e **MK_RBUTTON**.  
  
 `point`  
 Contém o local atual do cursor em coordenadas do cliente.  
  
### <a name="return-value"></a>Valor de retorno  
 O efeito que ocorreria se foram tentada uma queda no local especificado por `point`. Pode ser uma ou mais das seguintes opções:  
  
- `DROPEFFECT_NONE` Um descarte não será permitido.  
  
- `DROPEFFECT_COPY` Uma operação de cópia deve ser executada.  
  
- `DROPEFFECT_MOVE` Uma operação de movimentação deve ser executada.  
  
- `DROPEFFECT_LINK` Um link de dados descartados para os dados originais seja estabelecido.  
  
- `DROPEFFECT_SCROLL` Uma operação de arrastar rolagem está prestes a ocorrer ou está ocorrendo no destino.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para permitir operações de soltar ocorra na janela. A implementação padrão chama [CView::OnDragEnter](../../mfc/reference/cview-class.md#ondragenter), que retorna apenas `DROPEFFECT_NONE` por padrão.  
  
 Para obter mais informações, consulte [IDropTarget::DragEnter](http://msdn.microsoft.com/library/windows/desktop/ms680106) no SDK do Windows.  
  
##  <a name="ondragleave"></a>  COleDropTarget::OnDragLeave  
 Chamado pelo framework quando o cursor sai a janela enquanto uma operação de arrastar estiver em vigor.  
  
```  
virtual void OnDragLeave(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para a janela que está deixando o cursor.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se desejar um comportamento especial quando a operação de arrastar deixa a janela especificada. A implementação padrão Esta função chama [CView::OnDragLeave](../../mfc/reference/cview-class.md#ondragleave).  
  
 Para obter mais informações, consulte [IDropTarget::DragLeave](http://msdn.microsoft.com/library/windows/desktop/ms680110) no SDK do Windows.  
  
##  <a name="ondragover"></a>  COleDropTarget::OnDragOver  
 Chamado pelo framework quando o cursor é arrastado sobre a janela.  
  
```  
virtual DROPEFFECT OnDragOver(
    CWnd* pWnd,  
    COleDataObject* pDataObject,  
    DWORD dwKeyState,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para a janela que o cursor está sobre.  
  
 `pDataObject`  
 Aponta para o objeto de dados que contém os dados a ser removido.  
  
 `dwKeyState`  
 Contém o estado das teclas modificadoras. Esta é uma combinação de qualquer número das seguintes opções: **MK_CONTROL**, **MK_SHIFT**, **MK_ALT**, **MK_LBUTTON**, **MK_ MBUTTON**, e **MK_RBUTTON**.  
  
 `point`  
 Contém o local atual do cursor em coordenadas do cliente.  
  
### <a name="return-value"></a>Valor de retorno  
 O efeito que ocorreria se foram tentada uma queda no local especificado por `point`. Pode ser uma ou mais das seguintes opções:  
  
- `DROPEFFECT_NONE` Um descarte não será permitido.  
  
- `DROPEFFECT_COPY` Uma operação de cópia deve ser executada.  
  
- `DROPEFFECT_MOVE` Uma operação de movimentação deve ser executada.  
  
- `DROPEFFECT_LINK` Um link de dados descartados para os dados originais seja estabelecido.  
  
- `DROPEFFECT_SCROLL` Indica que uma operação de arrastar rolagem está prestes a ocorrer ou se está ocorrendo no destino.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser substituída para permitir operações de soltar ocorra na janela. A implementação padrão Esta função chama [CView::OnDragOver](../../mfc/reference/cview-class.md#ondragover), que retorna `DROPEFFECT_NONE` por padrão. Como essa função é chamada com frequência durante uma operação de arrastar e soltar, ele deve ser otimizado tanto quanto possível.  
  
 Para obter mais informações, consulte [IDropTarget::DragOver](http://msdn.microsoft.com/library/windows/desktop/ms680129) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer#21](../../mfc/codesnippet/cpp/coledroptarget-class_1.cpp)]  
  
##  <a name="ondragscroll"></a>  COleDropTarget::OnDragScroll  
 Chamado pelo framework antes de chamar [OnDragEnter](#ondragenter) ou [OnDragOver](#ondragover) para determinar se `point` está em uma região de rolagem.  
  
```  
virtual DROPEFFECT OnDragScroll(
    CWnd* pWnd,  
    DWORD dwKeyState,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para a janela que o cursor está atualmente posicionado.  
  
 `dwKeyState`  
 Contém o estado das teclas modificadoras. Esta é uma combinação de qualquer número das seguintes opções: **MK_CONTROL**, **MK_SHIFT**, **MK_ALT**, **MK_LBUTTON**, **MK_ MBUTTON**, e **MK_RBUTTON**.  
  
 `point`  
 Contém o local do cursor, em pixels, em relação à tela.  
  
### <a name="return-value"></a>Valor de retorno  
 O efeito que ocorreria se foram tentada uma queda no local especificado por `point`. Pode ser uma ou mais das seguintes opções:  
  
- `DROPEFFECT_NONE` Um descarte não será permitido.  
  
- `DROPEFFECT_COPY` Uma operação de cópia deve ser executada.  
  
- `DROPEFFECT_MOVE` Uma operação de movimentação deve ser executada.  
  
- `DROPEFFECT_LINK` Um link de dados descartados para os dados originais seja estabelecido.  
  
- `DROPEFFECT_SCROLL` Indica que uma operação de arrastar rolagem está prestes a ocorrer ou se está ocorrendo no destino.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função quando desejar fornecer um comportamento especial para esse evento. A implementação padrão Esta função chama [CView::OnDragScroll](../../mfc/reference/cview-class.md#ondragscroll), que retorna `DROPEFFECT_NONE` e rolar a janela quando o cursor é arrastado para a região de rolagem padrão dentro da borda da janela.  
  
##  <a name="ondrop"></a>  COleDropTarget::OnDrop  
 Chamado pelo framework quando uma operação de soltar está ocorrer.  
  
```  
virtual BOOL OnDrop(
    CWnd* pWnd,  
    COleDataObject* pDataObject,  
    DROPEFFECT dropEffect,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para a janela que o cursor está atualmente posicionado.  
  
 `pDataObject`  
 Aponta para o objeto de dados que contém os dados a ser removido.  
  
 `dropEffect`  
 O efeito que o usuário escolheu para a operação de remoção. Pode ser uma ou mais das seguintes opções:  
  
- `DROPEFFECT_COPY` Uma operação de cópia deve ser executada.  
  
- `DROPEFFECT_MOVE` Uma operação de movimentação deve ser executada.  
  
- `DROPEFFECT_LINK` Um link de dados descartados para os dados originais seja estabelecido.  
  
 `point`  
 Contém o local do cursor, em pixels, em relação à tela.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o descarte for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A estrutura do primeiro chama [OnDropEx](#ondropex). Se o `OnDropEx` função não processa o descarte, o framework chama esta função de membro, `OnDrop`. Normalmente, o aplicativo substitui [OnDropEx](../../mfc/reference/cview-class.md#ondropex) na classe de exibição para lidar com o botão direito do mouse, arraste e solte. Normalmente, a classe de exibição [OnDrop](../../mfc/reference/cview-class.md#ondrop) é usado para tratar simple arrastar e soltar.  
  
 A implementação padrão de `COleDropTarget::OnDrop` chamadas [CView::OnDrop](../../mfc/reference/cview-class.md#ondrop), que retorna apenas **FALSE** por padrão.  
  
 Para obter mais informações, consulte [IDropTarget::Drop](http://msdn.microsoft.com/library/windows/desktop/ms687242) no SDK do Windows.  
  
##  <a name="ondropex"></a>  COleDropTarget::OnDropEx  
 Chamado pelo framework quando uma operação de soltar está ocorrer.  
  
```  
virtual DROPEFFECT OnDropEx(
    CWnd* pWnd,  
    COleDataObject* pDataObject,  
    DROPEFFECT dropDefault,  
    DROPEFFECT dropList,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para a janela que o cursor está atualmente posicionado.  
  
 `pDataObject`  
 Aponta para o objeto de dados que contém os dados a ser removido.  
  
 `dropDefault`  
 O efeito que o usuário escolheu para a operação de soltar padrão com base no estado atual da chave. Ele pode ser `DROPEFFECT_NONE`. Efeitos de soltar são discutidos na seção comentários.  
  
 `dropList`  
 Uma lista dos efeitos drop que oferece suporte a origem de soltar. Soltar efeito valores podem ser combinados usando o OR bit a bit ( **&#124;**) operação. Efeitos de soltar são discutidos na seção comentários.  
  
 `point`  
 Contém o local do cursor, em pixels, em relação à tela.  
  
### <a name="return-value"></a>Valor de retorno  
 O efeito de soltar que resultaram da tentativa de descarte no local especificado por `point`. Efeitos de soltar são discutidos na seção comentários.  
  
### <a name="remarks"></a>Comentários  
 Primeiro, o framework chama essa função. Se ele não lidar com o posicionamento, o framework chama [OnDrop](#ondrop). Normalmente, você substituirá [OnDropEx](../../mfc/reference/cview-class.md#ondropex) na classe de exibição para dar suporte ao botão direito do mouse, arraste e solte. Normalmente, a classe de exibição [OnDrop](../../mfc/reference/cview-class.md#ondrop) é usado para tratar o caso de suporte para simple arrastar e soltar.  
  
 A implementação padrão de `COleDropTarget::OnDropEx` chamadas [CView::OnDropEx](../../mfc/reference/cview-class.md#ondropex). Por padrão, [CView::OnDropEx](../../mfc/reference/cview-class.md#ondropex) simplesmente retorna um valor fictício para indicar o [OnDrop](#ondrop) função de membro deve ser chamada.  
  
 Efeitos de soltar descrevem a ação associada a uma operação de soltar. Consulte a seguinte lista de soltar efeitos:  
  
- `DROPEFFECT_NONE` Um descarte não será permitido.  
  
- `DROPEFFECT_COPY` Uma operação de cópia deve ser executada.  
  
- `DROPEFFECT_MOVE` Uma operação de movimentação deve ser executada.  
  
- `DROPEFFECT_LINK` Um link de dados descartados para os dados originais seja estabelecido.  
  
- `DROPEFFECT_SCROLL` Indica que uma operação de arrastar rolagem está prestes a ocorrer ou se está ocorrendo no destino.  
  
 Para obter mais informações, consulte [IDropTarget::Drop](http://msdn.microsoft.com/library/windows/desktop/ms687242) no SDK do Windows.  
  
##  <a name="register"></a>  COleDropTarget::Register  
 Chame essa função para registrar sua janela com DLLs OLE como um destino válido.  
  
```  
BOOL Register(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para a janela que deve ser registrado como um destino de soltar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o registro for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada para operações de soltar seja aceito.  
  
 Para obter mais informações, consulte [RegisterDragDrop](http://msdn.microsoft.com/library/windows/desktop/ms678405) no SDK do Windows.  
  
##  <a name="revoke"></a>  COleDropTarget::Revoke  
 Chamar essa função antes de destruir qualquer janela que foi registrada como um destino de soltar por meio de uma chamada para [registrar](#register) para removê-lo da lista de destinos de soltar.  
  
```  
virtual void Revoke();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada automaticamente do [OnDestroy](../../mfc/reference/cwnd-class.md#ondestroy) manipulador para a janela que foi registrada, geralmente não é necessário chamar essa função explicitamente.  
  
 Para obter mais informações, consulte [RevokeDragDrop](http://msdn.microsoft.com/library/windows/desktop/ms692643) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Exemplo MFC OCLIENT](../../visual-cpp-samples.md)   
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDropSource](../../mfc/reference/coledropsource-class.md)
