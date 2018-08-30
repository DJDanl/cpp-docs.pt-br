---
title: Classe CCtrlView | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CCtrlView
- AFXWIN/CCtrlView
- AFXWIN/CCtrlView::CCtrlView
- AFXWIN/CCtrlView::OnDraw
- AFXWIN/CCtrlView::PreCreateWindow
- AFXWIN/CCtrlView::m_dwDefaultStyle
- AFXWIN/CCtrlView::m_strClass
dev_langs:
- C++
helpviewer_keywords:
- CCtrlView [MFC], CCtrlView
- CCtrlView [MFC], OnDraw
- CCtrlView [MFC], PreCreateWindow
- CCtrlView [MFC], m_dwDefaultStyle
- CCtrlView [MFC], m_strClass
ms.assetid: ff488596-1e71-451f-8fec-b0831a7b44e0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fdcec255c7d2398e1bb0efa7f86a31fc5dd938e4
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43210197"
---
# <a name="cctrlview-class"></a>Classe CCtrlView
Se adapta a arquitetura de exibição de documento para controles comuns aceitos pelo Windows 98 e Windows NT versões 3.51 e posterior.  
  
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
|[CCtrlView::PreCreateWindow](#precreatewindow)|Chamado antes da criação da janela Windows anexada a esta `CCtrlView` objeto.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCtrlView::m_dwDefaultStyle](#m_dwdefaultstyle)|Contém o estilo padrão para a classe de exibição.|  
|[CCtrlView::m_strClass](#m_strclass)|Contém o nome de classe do Windows para a classe de exibição.|  
  
## <a name="remarks"></a>Comentários  
 A classe `CCtrlView` e seus derivativos [CEditView](../../mfc/reference/ceditview-class.md), [CListView](../../mfc/reference/clistview-class.md), [CTreeView](../../mfc/reference/ctreeview-class.md), e [CRichEditView](../../mfc/reference/cricheditview-class.md), adaptar o arquitetura de exibição de documento para os novos controles comuns compatíveis com Windows 95/98 e Windows NT versões 3.51 e posterior. Para obter mais informações sobre a arquitetura de exibição de documento, consulte [arquitetura de documento/exibição](../../mfc/document-view-architecture.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CView](../../mfc/reference/cview-class.md)  
  
 `CCtrlView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="cctrlview"></a>  CCtrlView::CCtrlView  
 Constrói um objeto `CCtrlView`.  
  
```  
CCtrlView(
    LPCTSTR lpszClass,  
    DWORD dwStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszClass*  
 Nome de classe do Windows de classe de exibição.  
  
 *dwStyle*  
 Estilo da classe de exibição.  
  
### <a name="remarks"></a>Comentários  
 O framework chama o construtor quando uma nova janela do quadro é criada ou uma janela é dividida. Substituir [cview:: Oninitialupdate](../../mfc/reference/cview-class.md#oninitialupdate) para inicializar a exibição depois que o documento é anexado. Chame [CWnd::Create](../../mfc/reference/cwnd-class.md#create) ou [CWnd::CreateEx](../../mfc/reference/cwnd-class.md#createex) para criar o objeto do Windows.  
  
##  <a name="m_strclass"></a>  CCtrlView::m_strClass  
 Contém o nome de classe do Windows para a classe de exibição.  
  
```  
CString m_strClass;  
```  
  
##  <a name="m_dwdefaultstyle"></a>  CCtrlView::m_dwDefaultStyle  
 Contém o estilo padrão para a classe de exibição.  
  
```  
DWORD m_dwDefaultStyle;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse estilo é aplicado quando uma janela é criada.  
  
##  <a name="ondraw"></a>  CCtrlView::OnDraw  
 Chamado pelo framework para desenhar o conteúdo do `CCtrlView` usando o contexto de dispositivo especificado do objeto.  
  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDC*  
 Um ponteiro para o contexto de dispositivo no qual o desenho ocorre.  
  
### <a name="remarks"></a>Comentários  
 `OnDraw` Normalmente, é chamada para exibição na tela, passando um contexto de dispositivo da tela especificado por *pDC*.  
  
##  <a name="precreatewindow"></a>  CCtrlView::PreCreateWindow  
 Chamado antes da criação da janela Windows anexada a esta `CWnd` objeto.  
  
```  
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
```  
  
### <a name="parameters"></a>Parâmetros  
 *cs*  
 Um [CREATESTRUCT](https://msdn.microsoft.com/library/windows/desktop/ms632603) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a criação da janela deve continuar; 0 para indicar falha na criação.  
  
### <a name="remarks"></a>Comentários  
 Nunca chame essa função diretamente.  
  
 A implementação padrão dessa função verifica se há um nome de classe de janela NULL e substitui um padrão apropriado. Substituir essa função de membro para modificar o `CREATESTRUCT` estrutura antes que a janela é criada.  
  
 Cada classe derivada de `CCtrlView` adiciona sua própria funcionalidade à sua substituição do `PreCreateWindow`. Por design, essas derivações de `PreCreateWindow` não estão documentados. Para determinar os estilos apropriados para cada classe e as interdependências entre os estilos, você pode examinar o código-fonte para a classe de base do seu aplicativo MFC. Se você optar por substituir `PreCreateWindow`, você pode determinar se os estilos usados na classe de base do seu aplicativo fornecem a funcionalidade necessária, usando as informações obtidas do código-fonte MFC.  
  
 Para obter mais informações sobre como alterar estilos de janela, consulte a [alternando os estilos de uma janela criada por MFC](../../mfc/changing-the-styles-of-a-window-created-by-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CView](../../mfc/reference/cview-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CTreeView](../../mfc/reference/ctreeview-class.md)   
 [Classe CListView](../../mfc/reference/clistview-class.md)   
 [Classe CRichEditView](../../mfc/reference/cricheditview-class.md)
