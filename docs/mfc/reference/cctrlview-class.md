---
title: Classe CCtrlView | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CCtrlView
- AFXWIN/CCtrlView
- AFXWIN/CCtrlView::CCtrlView
- AFXWIN/CCtrlView::OnDraw
- AFXWIN/CCtrlView::PreCreateWindow
- AFXWIN/CCtrlView::m_dwDefaultStyle
- AFXWIN/CCtrlView::m_strClass
dev_langs: C++
helpviewer_keywords:
- CCtrlView [MFC], CCtrlView
- CCtrlView [MFC], OnDraw
- CCtrlView [MFC], PreCreateWindow
- CCtrlView [MFC], m_dwDefaultStyle
- CCtrlView [MFC], m_strClass
ms.assetid: ff488596-1e71-451f-8fec-b0831a7b44e0
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 484abaf5344400e03b53038d2c137497c202345f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cctrlview-class"></a>Classe CCtrlView
Se adapta a arquitetura do modo de exibição de documentos para os controles comuns com suporte em versões do Windows 98 e Windows NT 3.51 e posteriores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CCtrlView : public CView  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCtrlView::CCtrlView](#cctrlview)|Constrói um objeto `CCtrlView`.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCtrlView::OnDraw](#ondraw)|Chamado pelo framework para desenhar usando o contexto de dispositivo especificado.|  
|[CCtrlView::PreCreateWindow](#precreatewindow)|Chamado antes da criação da janela Windows anexada a este `CCtrlView` objeto.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCtrlView::m_dwDefaultStyle](#m_dwdefaultstyle)|Contém o estilo padrão para a classe de exibição.|  
|[CCtrlView::m_strClass](#m_strclass)|Contém o nome de classe do Windows para a classe de exibição.|  
  
## <a name="remarks"></a>Comentários  
 A classe `CCtrlView` e seus derivados [CEditView](../../mfc/reference/ceditview-class.md), [CListView](../../mfc/reference/clistview-class.md), [CTreeView](../../mfc/reference/ctreeview-class.md), e [CRichEditView](../../mfc/reference/cricheditview-class.md), adaptar o arquitetura de modo de exibição de documentos para os novos controles comuns versões com suporte pelo Windows 95/98 e Windows NT 3.51 e posteriores. Para obter mais informações sobre a arquitetura do modo de exibição de documentos, consulte [arquitetura de documento/exibição](../../mfc/document-view-architecture.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CView](../../mfc/reference/cview-class.md)  
  
 `CCtrlView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="cctrlview"></a>CCtrlView::CCtrlView  
 Constrói um objeto `CCtrlView`.  
  
```  
CCtrlView(
    LPCTSTR lpszClass,  
    DWORD dwStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszClass`  
 Nome da classe de exibição da classe Windows.  
  
 `dwStyle`  
 Estilo da classe de exibição.  
  
### <a name="remarks"></a>Comentários  
 O framework chama o construtor quando uma nova janela do quadro é criada ou uma janela é dividida. Substituir [CView::OnInitialUpdate](../../mfc/reference/cview-class.md#oninitialupdate) para inicializar a exibição depois que o documento está anexado. Chamar [CWnd::Create](../../mfc/reference/cwnd-class.md#create) ou [CWnd::CreateEx](../../mfc/reference/cwnd-class.md#createex) para criar o objeto do Windows.  
  
##  <a name="m_strclass"></a>CCtrlView::m_strClass  
 Contém o nome de classe do Windows para a classe de exibição.  
  
```  
CString m_strClass;  
```  
  
##  <a name="m_dwdefaultstyle"></a>CCtrlView::m_dwDefaultStyle  
 Contém o estilo padrão para a classe de exibição.  
  
```  
DWORD m_dwDefaultStyle;  
```  
  
### <a name="remarks"></a>Comentários  
 Este estilo é aplicado quando uma janela é criada.  
  
##  <a name="ondraw"></a>CCtrlView::OnDraw  
 Chamado pelo framework para desenhar o conteúdo do `CCtrlView` usando o contexto de dispositivo especificado do objeto.  
  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Um ponteiro para o contexto de dispositivo no qual ocorre o desenho.  
  
### <a name="remarks"></a>Comentários  
 `OnDraw`geralmente é chamado para a exibição de tela, passando um contexto de dispositivo de tela especificado pelo `pDC`.  
  
##  <a name="precreatewindow"></a>CCtrlView::PreCreateWindow  
 Chamado antes da criação da janela Windows anexada a este `CWnd` objeto.  
  
```  
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
```  
  
### <a name="parameters"></a>Parâmetros  
 *CS*  
 Um [CREATESTRUCT](http://msdn.microsoft.com/library/windows/desktop/ms632603) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se deve continuar a criação de janela; 0 para indicar falha na criação.  
  
### <a name="remarks"></a>Comentários  
 Nunca chame diretamente essa função.  
  
 A implementação padrão desta função verifica um **nulo** nome da classe de janela e substitui um padrão apropriado. Substituir esta função de membro para modificar o `CREATESTRUCT` estrutura antes que a janela é criada.  
  
 Cada classe derivada de `CCtrlView` adiciona sua própria funcionalidade para sua substituição de `PreCreateWindow`. Por design, essas derivações de `PreCreateWindow` não estão documentados. Para determinar os estilos apropriados para cada classe e as interdependências entre os estilos, você pode examinar o código-fonte MFC para a classe base do aplicativo. Se você optar por substituir `PreCreateWindow`, você pode determinar se os estilos usados na classe base do aplicativo fornecerem a funcionalidade necessária usando informações coletadas do código-fonte do MFC.  
  
 Para obter mais informações sobre como alterar estilos de janela, consulte o [alternando os estilos de uma janela criada por MFC](../../mfc/changing-the-styles-of-a-window-created-by-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CView](../../mfc/reference/cview-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CTreeView](../../mfc/reference/ctreeview-class.md)   
 [Classe CListView](../../mfc/reference/clistview-class.md)   
 [Classe CRichEditView](../../mfc/reference/cricheditview-class.md)
