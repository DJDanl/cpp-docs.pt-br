---
title: Classe CMFCPreviewCtrlImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCPreviewCtrlImpl
- afxwin/CMFCPreviewCtrlImpl
dev_langs:
- C++
helpviewer_keywords:
- CMFCPreviewCtrlImpl class
ms.assetid: 06257fa0-54c9-478d-9d68-c9698c3f93ed
caps.latest.revision: 28
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
ms.openlocfilehash: b3ccd0d6e03f652798b45ac35d36f8bc2f63e048
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcpreviewctrlimpl-class"></a>Classe CMFCPreviewCtrlImpl
Essa classe implementa uma janela que é colocada em uma janela de host fornecida pelo Shell para visualização avançada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCPreviewCtrlImpl : public CWnd;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCPreviewCtrlImpl:: ~ CMFCPreviewCtrlImpl](#dtor)|Destructs um objeto de controle de visualização.|  
|[CMFCPreviewCtrlImpl::CMFCPreviewCtrlImpl](#cmfcpreviewctrlimpl)|Constrói um objeto de controle de visualização.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCPreviewCtrlImpl::Create](#create)|Sobrecarregado. Chamado por um manipulador de visualização avançada para criar a janela do Windows.|  
|[CMFCPreviewCtrlImpl::Destroy](#destroy)|Chamado por um Gerenciador de visualização avançada quando precisa destruir este controle.|  
|[CMFCPreviewCtrlImpl::Focus](#focus)|Conjuntos de foco de entrada para este controle.|  
|[CMFCPreviewCtrlImpl::GetDocument](#getdocument)|Retorna um documento conectado a este controle de visualização.|  
|[CMFCPreviewCtrlImpl::Redraw](#redraw)|Informa a este controle para redesenhar.|  
|[CMFCPreviewCtrlImpl::SetDocument](#setdocument)|Chamado pelo Gerenciador de visualização para criar uma relação entre a implementação de documento e o controle de visualização.|  
|[CMFCPreviewCtrlImpl::SetHost](#sethost)|Define um novo pai para este controle.|  
|[CMFCPreviewCtrlImpl::SetPreviewVisuals](#setpreviewvisuals)|Chamado por um Gerenciador de visualização avançada quando precisa definir os elementos visuais de visualização avançada conteúdo.|  
|[CMFCPreviewCtrlImpl::SetRect](#setrect)|Define um novo retângulo delimitador para este controle.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCPreviewCtrlImpl::DoPaint](#dopaint)|Chamado pela estrutura para renderizar a visualização.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCPreviewCtrlImpl::m_clrBackColor](#m_clrbackcolor)|Cor de plano de fundo da janela de visualização.|  
|[CMFCPreviewCtrlImpl::m_clrTextColor](#m_clrtextcolor)|Cor do texto da janela de visualização.|  
|[CMFCPreviewCtrlImpl::m_font](#m_font)|Fonte usada para exibir texto na janela de visualização.|  
|[CMFCPreviewCtrlImpl::m_pDocument](#m_pdocument)|Um ponteiro para um documento cujo conteúdo é visualizado no controle.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h    
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CMFCPreviewCtrlImpl](../../mfc/reference/cmfcpreviewctrlimpl-class.md)

## <a name="a-namecmfcpreviewctrlimpla-cmfcpreviewctrlimplcmfcpreviewctrlimpl"></a><a name="cmfcpreviewctrlimpl"></a>CMFCPreviewCtrlImpl::CMFCPreviewCtrlImpl
Constrói um objeto de controle de visualização.

### <a name="syntax"></a>Sintaxe
CMFCPreviewCtrlImpl();  

## <a name="a-namecreatea-cmfcpreviewctrlimplcreate"></a><a name="create"></a>CMFCPreviewCtrlImpl::Create
Sobrecarregado. Chamado por um manipulador de visualização avançada para criar a janela do Windows.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
virtual BOOL Create(  
   HWND hWndParent,  
   const RECT* prc  
);  
virtual BOOL Create(  
   HWND hWndParent,  
   const RECT* prc,  
   CCreateContext* pContext  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWndParent`  
 Um identificador para a janela de host fornecido pelo Shell para visualização avançada.  
  
 `prc`  
 Especifica o tamanho inicial e a posição da janela.  
  
 `pContext`  
 Um ponteiro para um contexto de criação.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a criação bem-sucedida; Caso contrário, `FALSE`.  
  
## <a name="a-namedestroya-cmfcpreviewctrlimpldestroy"></a><a name="destroy"></a>CMFCPreviewCtrlImpl::Destroy
Chamado por um Gerenciador de visualização avançada quando precisa destruir este controle.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
virtual void Destroy();  
```  
  
## <a name="a-namedopainta-cmfcpreviewctrlimpldopaint"></a><a name="dopaint"></a>CMFCPreviewCtrlImpl::DoPaint  
Chamado pela estrutura para renderizar a visualização.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
virtual void DoPaint(  
   CPaintDC* pDC  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Um ponteiro para um contexto de dispositivo para pintura.  


## <a name="a-namefocusa-cmfcpreviewctrlimplfocus"></a><a name="focus"></a>CMFCPreviewCtrlImpl::Focus  
Conjuntos de foco de entrada para este controle.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
virtual void Focus();  
```  
## <a name="a-namegetdocumenta-cmfcpreviewctrlimplgetdocument"></a><a name="getdocument"></a>CMFCPreviewCtrlImpl::GetDocument
Retorna um documento conectado a este controle de visualização.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ATL::IDocument* GetDocument();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um documento, cujo conteúdo é visualizado no controle.

## <a name="a-namemclrbackcolora-cmfcpreviewctrlimplmclrbackcolor"></a><a name="m_clrbackcolor"></a>CMFCPreviewCtrlImpl::m_clrBackColor  
Cor de plano de fundo da janela de visualização.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
COLORREF m_clrBackColor;  
```  

## <a name="a-namemclrtextcolora-cmfcpreviewctrlimplmclrtextcolor"></a><a name="m_clrtextcolor"></a>CMFCPreviewCtrlImpl::m_clrTextColor
Cor do texto da janela de visualização.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
COLORREF m_clrTextColor;  
```  
## <a name="a-namemfonta-cmfcpreviewctrlimplmfont--font-used-to-display-text-in-the-preview-window"></a><a name="m_font"></a>CMFCPreviewCtrlImpl::m_font fonte usada para exibir texto na janela de visualização.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
CFont m_font;  
```  
## <a name="a-namempdocumenta-cmfcpreviewctrlimplmpdocument"></a><a name="m_pdocument"></a>CMFCPreviewCtrlImpl::m_pDocument  
Um ponteiro para um documento cujo conteúdo é visualizado no controle.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ATL::IDocument* m_pDocument;  
```  

## <a name="a-nameredrawa-cmfcpreviewctrlimplredraw"></a><a name="redraw"></a>CMFCPreviewCtrlImpl::Redraw  
Informa a este controle para redesenhar.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
virtual void Redraw();  
```  
## <a name="a-namesetdocumenta-cmfcpreviewctrlimplsetdocument"></a><a name="setdocument"></a>CMFCPreviewCtrlImpl::SetDocument 
Chamado pelo Gerenciador de visualização para criar uma relação entre a implementação de documento e o controle de visualização.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void SetDocument(  
   IDocument* pDocument  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDocument`  
 Um ponteiro para a implementação do documento.  

## <a name="a-namesethosta-cmfcpreviewctrlimplsethost"></a><a name="sethost"></a>CMFCPreviewCtrlImpl::SetHost  
Define um novo pai para este controle.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
virtual void SetHost(  
   HWND hWndParent  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWndParent`  
 Um identificador para a nova janela pai.  

## <a name="a-namesetpreviewvisualsa-cmfcpreviewctrlimplsetpreviewvisuals"></a><a name="setpreviewvisuals"></a>CMFCPreviewCtrlImpl::SetPreviewVisuals  
Chamado por um Gerenciador de visualização avançada quando precisa definir os elementos visuais de visualização avançada conteúdo.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
virtual void SetPreviewVisuals(  
   COLORREF clrBack,  
   COLORREF clrText,  
   const LOGFONTW *plf  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `clrBack`  
 Cor de plano de fundo da janela de visualização.  
  
 `clrText`  
 Cor do texto da janela de visualização.  
  
 `plf`  
 Fonte usada para exibir texto na janela de visualização. 

##  <a name="a-namesetrecta-cmfcpreviewctrlimplsetrect"></a><a name="setrect"></a>CMFCPreviewCtrlImpl::SetRect  
Define um novo retângulo delimitador para este controle.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
virtual void SetRect(  
   const RECT* prc,  
   BOOL bRedraw  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `prc`  
 Especifica o novo tamanho e posição do controle de visualização.  
  
 `bRedraw`  
 Especifica se o controle deve ser redesenhado.  
  
### <a name="remarks"></a>Comentários  
 Normalmente um novo retângulo delimitador é definido quando o controle de host é redimensionado.  

## <a name="a-namedtora-cmfcpreviewctrlimplcmfcpreviewctrlimpl"></a><a name="dtor"></a>CMFCPreviewCtrlImpl:: ~ CMFCPreviewCtrlImpl  
Destructs um objeto de controle de visualização.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
virtual ~CMFCPreviewCtrlImpl();  
```  
  

