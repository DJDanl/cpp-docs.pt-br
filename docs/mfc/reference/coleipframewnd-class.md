---
title: Classe COleIPFrameWnd | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
- COleIPFrameWnd class
- OLE, editing
- OLE, in-place activation
- in-place editing
ms.assetid: 24abb2cb-826c-4dda-a287-d8a8900a5763
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 85ce028bb5d72c06a0e228abba1bd08a7f6526cb
ms.lasthandoff: 02/25/2017

---
# <a name="coleipframewnd-class"></a>Classe COleIPFrameWnd
A base para a janela de edição do seu aplicativo no local.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleIPFrameWnd : public CFrameWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleIPFrameWnd::COleIPFrameWnd](#coleipframewnd)|Constrói um objeto `COleIPFrameWnd`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleIPFrameWnd::OnCreateControlBars](#oncreatecontrolbars)|Chamado pela estrutura quando um item é ativado para edição in-loco.|  
|[COleIPFrameWnd::RepositionFrame](#repositionframe)|Chamado pela estrutura para reposicionar a janela de edição in-loco.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe cria e posições de barras na janela de documento do aplicativo de contêiner de controle. Ele também manipula notificações geradas por inserida [COleResizeBar](../../mfc/reference/coleresizebar-class.md) objeto quando o usuário redimensiona a janela de edição in-loco.  
  
 Para obter mais informações sobre como usar o `COleIPFrameWnd`, consulte o artigo [ativação](../../mfc/activation-cpp.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 `COleIPFrameWnd`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="coleipframewnd"></a>COleIPFrameWnd::COleIPFrameWnd  
 Constrói uma `COleIPFrameWnd` de objeto e inicializa suas informações de estado no local, que são armazenadas em uma estrutura do tipo **OLEINPLACEFRAMEINFO**.  
  
```  
COleIPFrameWnd();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [OLEINPLACEFRAMEINFO](http://msdn.microsoft.com/library/windows/desktop/ms693737) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="oncreatecontrolbars"></a>COleIPFrameWnd::OnCreateControlBars  
 O framework chama o `OnCreateControlBars` funcionar quando um item é ativado para edição in-loco.  
  
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
 Ponteiro para a janela do quadro do aplicativo de contêiner.  
  
 *pWndDoc*  
 Ponteiro para a janela de nível de documento do contêiner. Pode ser **nulo** se o contêiner for um aplicativo SDI.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero em caso de êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não faz nada. Substitua essa função para executar qualquer processamento especial exigido quando as barras de controle são criadas.  
  
##  <a name="repositionframe"></a>COleIPFrameWnd::RepositionFrame  
 O framework chama o `RepositionFrame` a função de membro para dispor barras de controle e reposicionar a janela de edição in-loco para que tudo fique visível.  
  
```  
virtual void RepositionFrame(
    LPCRECT lpPosRect,  
    LPCRECT lpClipRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPosRect`  
 Ponteiro para uma `RECT` estrutura ou um `CRect` coordenadas de posição atual da janela, em pixels, em relação a área do cliente do quadro que contém o local do objeto.  
  
 `lpClipRect`  
 Ponteiro para uma `RECT` estrutura ou um `CRect` coordenadas do retângulo de corte atual da janela, em pixels, em relação a área do cliente do quadro que contém o local do objeto.  
  
### <a name="remarks"></a>Comentários  
 Layout das barras de controle na janela do contêiner difere executadas por uma janela de quadro não são OLE. A janela do quadro não são OLE calcula as posições das barras de controle e outros objetos de um tamanho de janela com moldura determinado, como em uma chamada para [CFrameWnd::RecalcLayout](../../mfc/reference/cframewnd-class.md#recalclayout). A área do cliente é o que permanece depois que o espaço para as barras de controle e outros objetos é subtraído. Um `COleIPFrameWnd` janela, por outro lado, posiciona barras de ferramentas de acordo com uma área do cliente. Em outras palavras, `CFrameWnd::RecalcLayout` funciona "de fora para dentro," enquanto `COleIPFrameWnd::RepositionFrame` funciona "de dentro para fora."  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)

