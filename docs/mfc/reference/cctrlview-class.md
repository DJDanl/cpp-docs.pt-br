---
title: Classe CCtrlView | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CCtrlView
dev_langs:
- C++
helpviewer_keywords:
- views, and common controls
- controls [MFC], common
- CCtrlView class
ms.assetid: ff488596-1e71-451f-8fec-b0831a7b44e0
caps.latest.revision: 20
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
ms.openlocfilehash: 569044de59dc3ccd73157abc86855beef57cb558
ms.lasthandoff: 02/25/2017

---
# <a name="cctrlview-class"></a>Classe CCtrlView
Se adapta a arquitetura de exibição de documento para os controles comuns com suporte em versões de Windows 98 e Windows NT 3.51 e posteriores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CCtrlView : public CView  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCtrlView::CCtrlView](#cctrlview)|Constrói um objeto `CCtrlView`.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCtrlView::OnDraw](#ondraw)|Chamado pela estrutura para desenhar usando o contexto de dispositivo especificado.|  
|[CCtrlView::PreCreateWindow](#precreatewindow)|Chamado antes da criação da janela do Windows anexada a esta `CCtrlView` objeto.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCtrlView::m_dwDefaultStyle](#m_dwdefaultstyle)|Contém o estilo padrão para a classe de exibição.|  
|[CCtrlView::m_strClass](#m_strclass)|Contém o nome de classe do Windows para a classe de exibição.|  
  
## <a name="remarks"></a>Comentários  
 A classe `CCtrlView` e seus derivados, [CEditView](../../mfc/reference/ceditview-class.md), [CListView](../../mfc/reference/clistview-class.md), [CTreeView](../../mfc/reference/ctreeview-class.md), e [CRichEditView](../../mfc/reference/cricheditview-class.md), adaptar a arquitetura de exibição de documento para os novos controles comuns compatíveis com versões do Windows 95/98 e Windows NT 3.51 e posteriores. Para obter mais informações sobre a arquitetura de exibição de documento, consulte [arquitetura de documento/exibição](../../mfc/document-view-architecture.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CView](../../mfc/reference/cview-class.md)  
  
 `CCtrlView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-namecctrlviewa--cctrlviewcctrlview"></a><a name="cctrlview"></a>CCtrlView::CCtrlView  
 Constrói um objeto `CCtrlView`.  
  
```  
CCtrlView(
    LPCTSTR lpszClass,  
    DWORD dwStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszClass`  
 Nome de classe do Windows de classe de exibição.  
  
 `dwStyle`  
 Estilo de classe de exibição.  
  
### <a name="remarks"></a>Comentários  
 O framework chama o construtor quando é criada uma nova janela de quadro ou uma janela é dividida. Substituir [cview:: Oninitialupdate](../../mfc/reference/cview-class.md#oninitialupdate) para inicializar a exibição depois que o documento é anexado. Chamar [CWnd::Create](../../mfc/reference/cwnd-class.md#create) ou [CWnd::CreateEx](../../mfc/reference/cwnd-class.md#createex) para criar o objeto do Windows.  
  
##  <a name="a-namemstrclassa--cctrlviewmstrclass"></a><a name="m_strclass"></a>CCtrlView::m_strClass  
 Contém o nome de classe do Windows para a classe de exibição.  
  
```  
CString m_strClass;  
```  
  
##  <a name="a-namemdwdefaultstylea--cctrlviewmdwdefaultstyle"></a><a name="m_dwdefaultstyle"></a>CCtrlView::m_dwDefaultStyle  
 Contém o estilo padrão para a classe de exibição.  
  
```  
DWORD m_dwDefaultStyle;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse estilo é aplicado quando uma janela é criada.  
  
##  <a name="a-nameondrawa--cctrlviewondraw"></a><a name="ondraw"></a>CCtrlView::OnDraw  
 Chamado pela estrutura para desenhar o conteúdo a `CCtrlView` objeto usando o contexto de dispositivo especificado.  
  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Um ponteiro para o contexto de dispositivo no qual ocorre o desenho.  
  
### <a name="remarks"></a>Comentários  
 `OnDraw`normalmente é chamado para exibição na tela, passando um contexto de dispositivo da tela especificado por `pDC`.  
  
##  <a name="a-nameprecreatewindowa--cctrlviewprecreatewindow"></a><a name="precreatewindow"></a>CCtrlView::PreCreateWindow  
 Chamado antes da criação da janela do Windows anexada a esta `CWnd` objeto.  
  
```  
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
```  
  
### <a name="parameters"></a>Parâmetros  
 *CS*  
 A [CREATESTRUCT](http://msdn.microsoft.com/library/windows/desktop/ms632603) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a criação da janela deve continuar; 0 para indicar falha na criação.  
  
### <a name="remarks"></a>Comentários  
 Nunca chame essa função diretamente.  
  
 A implementação padrão dessa função verifica um **nulo** nome da classe de janela e substitui um padrão apropriado. Substituir essa função de membro para modificar o `CREATESTRUCT` estrutura antes que a janela é criada.  
  
 Cada classe derivada de `CCtrlView` adiciona sua própria funcionalidade para sua substituição de `PreCreateWindow`. Por design, essas derivações de `PreCreateWindow` não são documentadas. Para determinar os estilos apropriados em cada classe e as interdependências entre os estilos, você pode examinar o código-fonte para a classe base do seu aplicativo MFC. Se você optar por substituir `PreCreateWindow`, você pode determinar se os estilos usados na classe base do aplicativo fornecem a funcionalidade necessária usando informações coletadas do código-fonte do MFC.  
  
 Para obter mais informações sobre como alterar estilos de janela, consulte o [alternando os estilos de uma janela criada por MFC](../../mfc/changing-the-styles-of-a-window-created-by-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CView](../../mfc/reference/cview-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CTreeView](../../mfc/reference/ctreeview-class.md)   
 [Classe CListView](../../mfc/reference/clistview-class.md)   
 [Classe CRichEditView](../../mfc/reference/cricheditview-class.md)

