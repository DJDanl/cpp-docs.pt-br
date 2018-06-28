---
title: Classe COleIPFrameWnd | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleIPFrameWnd
- AFXOLE/COleIPFrameWnd
- AFXOLE/COleIPFrameWnd::COleIPFrameWnd
- AFXOLE/COleIPFrameWnd::OnCreateControlBars
- AFXOLE/COleIPFrameWnd::RepositionFrame
dev_langs:
- C++
helpviewer_keywords:
- COleIPFrameWnd [MFC], COleIPFrameWnd
- COleIPFrameWnd [MFC], OnCreateControlBars
- COleIPFrameWnd [MFC], RepositionFrame
ms.assetid: 24abb2cb-826c-4dda-a287-d8a8900a5763
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9136f3c57358a71186b196a4223b401e6abad2a9
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37040019"
---
# <a name="coleipframewnd-class"></a>Classe COleIPFrameWnd
A base para a janela de edição do seu aplicativo no local.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleIPFrameWnd : public CFrameWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleIPFrameWnd::COleIPFrameWnd](#coleipframewnd)|Constrói um objeto `COleIPFrameWnd`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleIPFrameWnd::OnCreateControlBars](#oncreatecontrolbars)|Chamado pelo framework quando um item é ativado para edição no local.|  
|[COleIPFrameWnd::RepositionFrame](#repositionframe)|Chamado pelo framework para reposicionar a janela de edição no local.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe cria e posições controlam barras na janela de documento do aplicativo recipiente. Ele também lida com notificações geradas por inserida [COleResizeBar](../../mfc/reference/coleresizebar-class.md) quando o usuário o redimensiona a janela de edição no local do objeto.  
  
 Para obter mais informações sobre como usar `COleIPFrameWnd`, consulte o artigo [ativação](../../mfc/activation-cpp.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 `COleIPFrameWnd`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="coleipframewnd"></a>  COleIPFrameWnd::COleIPFrameWnd  
 Constrói um `COleIPFrameWnd` de objeto e inicializa as suas informações de estado no local, que são armazenadas em uma estrutura de tipo **OLEINPLACEFRAMEINFO**.  
  
```  
COleIPFrameWnd();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [OLEINPLACEFRAMEINFO](http://msdn.microsoft.com/library/windows/desktop/ms693737) no SDK do Windows.  
  
##  <a name="oncreatecontrolbars"></a>  COleIPFrameWnd::OnCreateControlBars  
 O framework chama o `OnCreateControlBars` funciona quando um item é ativado para edição no local.  
  
```  
virtual BOOL OnCreateControlBars(
    CWnd* pWndFrame,  
    CWnd* pWndDoc);

 
virtual BOOL OnCreateControlBars(
    CFrameWnd* pWndFrame,  
    CFrameWnd* pWndDoc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pWndFrame*  
 Ponteiro para a janela do quadro do aplicativo recipiente.  
  
 *pWndDoc*  
 Ponteiro para a janela de nível de documento do contêiner. Pode ser **nulo** se o contêiner for um aplicativo SDI.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero em caso de sucesso; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não fará nada. Substitua esta função para executar qualquer processamento especial necessário quando as barras de controle são criadas.  
  
##  <a name="repositionframe"></a>  COleIPFrameWnd::RepositionFrame  
 O framework chama o `RepositionFrame` a função de membro para dispor barras de controle e reposicionar a janela de edição no local para que tudo fique visível.  
  
```  
virtual void RepositionFrame(
    LPCRECT lpPosRect,  
    LPCRECT lpClipRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpPosRect*  
 Ponteiro para um `RECT` estrutura ou um `CRect` objeto que contém o local do quadro coordenadas de posição atual da janela, em pixels, relativas à área do cliente.  
  
 *lpClipRect*  
 Ponteiro para um `RECT` estrutura ou um `CRect` objeto que contém o local do quadro coordenadas do retângulo de recorte atual da janela, em pixels, relativas à área do cliente.  
  
### <a name="remarks"></a>Comentários  
 O layout das barras de controle na janela do contêiner é diferente do que é executada por uma janela do quadro não OLE. A janela do quadro de OLE não calcula as posições das barras de controle e outros objetos de um tamanho de janela com moldura determinado, como em uma chamada para [CFrameWnd::RecalcLayout](../../mfc/reference/cframewnd-class.md#recalclayout). A área do cliente é o que permanece depois que o espaço para outros objetos e barras de controle é subtraído. Um `COleIPFrameWnd` janela, por outro lado, posiciona barras de ferramentas de acordo com uma área do cliente. Em outras palavras, `CFrameWnd::RecalcLayout` funciona "de fora," enquanto `COleIPFrameWnd::RepositionFrame` funciona "de dentro para fora."  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)
