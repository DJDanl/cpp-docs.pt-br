---
title: Classe CHtmlEditView | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CHtmlEditView
- AFXHTML/CHtmlEditView
- AFXHTML/CHtmlEditView::CHtmlEditView
- AFXHTML/CHtmlEditView::Create
- AFXHTML/CHtmlEditView::GetDHtmlDocument
- AFXHTML/CHtmlEditView::GetStartDocument
dev_langs:
- C++
helpviewer_keywords:
- CHtmlEditView [MFC], CHtmlEditView
- CHtmlEditView [MFC], Create
- CHtmlEditView [MFC], GetDHtmlDocument
- CHtmlEditView [MFC], GetStartDocument
ms.assetid: 166c8ba8-3fb5-4dd7-a9ea-5bca662d00f6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 10f474ce860bf5d9071a93f17654123f4777efa7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33367338"
---
# <a name="chtmleditview-class"></a>Classe CHtmlEditView
Fornece a funcionalidade da plataforma de edição de WebBrowser dentro do contexto de arquitetura de documento/exibição do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CHtmlEditView : public CHtmlView, public CHtmlEditCtrlBase<CHtmlEditView>  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHtmlEditView::CHtmlEditView](#chtmleditview)|Constrói um objeto `CHtmlEditView`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHtmlEditView::Create](#create)|Cria um novo objeto de janela.|  
|[CHtmlEditView::GetDHtmlDocument](#getdhtmldocument)|Retorna o **IHTMLDocument2** interface no documento atual.|  
|[CHtmlEditView::GetStartDocument](#getstartdocument)|Recupera o nome do documento padrão para esta exibição.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CView](../../mfc/reference/cview-class.md)  
  
 [CScrollView](../../mfc/reference/cscrollview-class.md)  
  
 [CFormView](../../mfc/reference/cformview-class.md)  
  
 [CHtmlEditCtrlBase](../../mfc/reference/chtmleditctrlbase-class.md)  
  
 [CHtmlView](../../mfc/reference/chtmlview-class.md)  
  
 `CHtmlEditView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxhtml.h  
  
##  <a name="chtmleditview"></a>  CHtmlEditView::CHtmlEditView  
 Constrói um objeto `CHtmlEditView`.  
  
```  
CHtmlEditView();
```  
  
##  <a name="create"></a>  CHtmlEditView::Create  
 Cria um novo objeto de janela.  
  
```  
virtual BOOL Create(
    LPCTSTR lpszClassName,  
    LPCTSTR lpszWindowName,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID,  
    CCreateContext* pContext = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszClassName`  
 Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe do Windows. O nome da classe pode ser qualquer nome registrado com o [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) função global ou **RegisterClass** função do Windows. Se **nulo**, usa o padrão predefinido [CFrameWnd](../../mfc/reference/cframewnd-class.md) atributos.  
  
 `lpszWindowName`  
 Aponta para uma cadeia de caracteres terminada em nulo que representa o nome da janela.  
  
 `dwStyle`  
 Especifica os atributos de estilo de janela. Por padrão, o **WS_VISIBLE** e **WS_CHILD** estilos do Windows são definidos.  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura especificando o tamanho e a posição da janela. O `rectDefault` valor permite que o Windows especificar o tamanho e a posição da nova janela.  
  
 `pParentWnd`  
 Um ponteiro para a janela pai do controle.  
  
 `nID`  
 O número de identificação do modo de exibição. Por padrão, definido como **AFX_IDW_PANE_FIRST**.  
  
 `pContext`  
 Um ponteiro para um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md). **NULO** por padrão.  
  
### <a name="remarks"></a>Comentários  
 Esse método também chamará o WebBrowser independente **navegar** método para carregar um documento padrão (consulte [CHtmlEditView::GetStartDocument](#getstartdocument)).  
  
##  <a name="getdhtmldocument"></a>  CHtmlEditView::GetDHtmlDocument  
 Retorna o **IHTMLDocument2** interface no documento atual.  
  
```  
BOOL GetDHtmlDocument(IHTMLDocument2** ppDocument) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppDocument`  
 O [IHTMLDocument2](https://msdn.microsoft.com/library/aa752574.aspx) interface.  
  
##  <a name="getstartdocument"></a>  CHtmlEditView::GetStartDocument  
 Recupera o nome do documento padrão para esta exibição.  
  
```  
virtual LPCTSTR GetStartDocument();
```  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de HTMLEdit](../../visual-cpp-samples.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)


