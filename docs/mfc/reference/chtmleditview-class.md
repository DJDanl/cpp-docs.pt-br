---
title: Classe CHtmlEditView | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
- CHtmlEditView class
ms.assetid: 166c8ba8-3fb5-4dd7-a9ea-5bca662d00f6
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: d0194d48fe214d7c90b24ff8ce4ef10116cd536a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="chtmleditview-class"></a>Classe CHtmlEditView
Fornece a funcionalidade da plataforma WebBrowser edição dentro do contexto da arquitetura de documento/exibição do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CHtmlEditView : public CHtmlView, public CHtmlEditCtrlBase<CHtmlEditView>  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHtmlEditView::CHtmlEditView](#chtmleditview)|Constrói um objeto `CHtmlEditView`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHtmlEditView::Create](#create)|Cria um novo objeto de janela.|  
|[CHtmlEditView::GetDHtmlDocument](#getdhtmldocument)|Retorna o **IHTMLDocument2** interface no documento atual.|  
|[CHtmlEditView::GetStartDocument](#getstartdocument)|Recupera o nome do documento padrão para este modo de exibição.|  
  
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
  
##  <a name="chtmleditview"></a>CHtmlEditView::CHtmlEditView  
 Constrói um objeto `CHtmlEditView`.  
  
```  
CHtmlEditView();
```  
  
##  <a name="create"></a>CHtmlEditView::Create  
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
 Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe do Windows. O nome da classe pode ser qualquer nome registrado com o [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) função global ou o **RegisterClass** função do Windows. Se **nulo**, usa o padrão predefinido [CFrameWnd](../../mfc/reference/cframewnd-class.md) atributos.  
  
 `lpszWindowName`  
 Aponta para uma cadeia de caracteres terminada em nulo que representa o nome da janela.  
  
 `dwStyle`  
 Especifica os atributos de estilo da janela. Por padrão, o **WS_VISIBLE** e **WS_CHILD** estilos do Windows são definidos.  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura especificando o tamanho e a posição da janela. O `rectDefault` valor permite ao Windows especificar o tamanho e a posição da nova janela.  
  
 `pParentWnd`  
 Um ponteiro para a janela pai do controle.  
  
 `nID`  
 O número de identificação do modo de exibição. Por padrão, definido como **AFX_IDW_PANE_FIRST**.  
  
 `pContext`  
 Um ponteiro para um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md). **NULO** por padrão.  
  
### <a name="remarks"></a>Comentários  
 Esse método também chamará o WebBrowser independente **Navigate** método para carregar um documento padrão (consulte [CHtmlEditView::GetStartDocument](#getstartdocument)).  
  
##  <a name="getdhtmldocument"></a>CHtmlEditView::GetDHtmlDocument  
 Retorna o **IHTMLDocument2** interface no documento atual.  
  
```  
BOOL GetDHtmlDocument(IHTMLDocument2** ppDocument) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppDocument`  
 O [IHTMLDocument2](https://msdn.microsoft.com/library/aa752574.aspx) interface.  
  
##  <a name="getstartdocument"></a>CHtmlEditView::GetStartDocument  
 Recupera o nome do documento padrão para este modo de exibição.  
  
```  
virtual LPCTSTR GetStartDocument();
```  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de HTMLEdit](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)



