---
title: Classe CMFCRibbonSeparator | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonSeparator
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::CMFCRibbonSeparator
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::AddToListBox
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::CopyFrom
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::GetRegularSize
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::IsSeparator
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::IsTabStop
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::OnDraw
- AFXBASERIBBONELEMENT/CMFCRibbonSeparator::OnDrawOnList
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonSeparator class
- GetThisClass method
- CreateObject method
ms.assetid: bedb1a53-cb07-4c3c-be12-698c5409e7cf
caps.latest.revision: 21
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
ms.openlocfilehash: 98a58d43b5e6299f26521d873caec06d4581f7b3
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcribbonseparator-class"></a>Classe CMFCRibbonSeparator
Implementa o separador de faixa de opções.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonSeparator : public CMFCRibbonBaseElement  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCRibbonSeparator::CMFCRibbonSeparator](#cmfcribbonseparator)|Constrói um objeto `CMFCRibbonSeparator`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCRibbonSeparator::AddToListBox](#addtolistbox)|Adiciona um separador para o **comandos** lista no **personalizar** caixa de diálogo. (Substitui [CMFCRibbonBaseElement::AddToListBox](../../mfc/reference/cmfcribbonbaseelement-class.md#addtolistbox).)|  
|`CMFCRibbonSeparator::CreateObject`|Usado pelo framework para criar uma instância desse tipo de classe dinâmica.|  
|`CMFCRibbonSeparator::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCRibbonSeparator::CopyFrom](#copyfrom)|Um método de cópia que define as variáveis membro do separador de outro objeto.|  
|[CMFCRibbonSeparator::GetRegularSize](#getregularsize)|Retorna o tamanho de um separador.|  
|[CMFCRibbonSeparator::IsSeparator](#isseparator)|Indica se este é um separador.|  
|[CMFCRibbonSeparator::IsTabStop](#istabstop)|Indica se esta é uma parada de tabulação.|  
|[CMFCRibbonSeparator::OnDraw](#ondraw)|Chamado pelo sistema para desenhar o separador na faixa de opções ou a barra de ferramentas de acesso rápido.|  
|[CMFCRibbonSeparator::OnDrawOnList](#ondrawonlist)|Chamado pelo sistema para desenhar o separador de **comandos** lista.|  
  
## <a name="remarks"></a>Comentários  
 Um separador de faixa de opções é uma linha vertical ou horizontal, que logicamente separa faixa elementos. Um separador pode ser desenhado no controle da faixa de opções, no menu principal do aplicativo, a barra de status da faixa de opções e a barra de ferramentas de acesso rápido.  
  
 Para usar um separador em seu aplicativo, criar o novo objeto e adicioná-lo ao menu principal do aplicativo, como mostrado aqui:  
  
```  
CMFCRibbonMainPanel* pMainPanel = m_wndRibbonBar.AddMainCategory(_T("Main Menu"),
    IDB_FILESMALL,
    IDB_FILELARGE);

...  
pMainPanel->Add(new CMFCRibbonSeparator(TRUE));
```  
Chamar [CMFCRibbonPanel::AddSeparator](../../mfc/reference/cmfcribbonpanel-class.md#addseparator) adicionar separadores para painéis de faixa de opções. Os separadores são alocados e adicionados internamente pelo `AddSeparator` método.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonSeparator](../../mfc/reference/cmfcribbonseparator-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxbaseribbonelement.h  
  
##  <a name="addtolistbox"></a>CMFCRibbonSeparator::AddToListBox  
 Adiciona um separador para o **comandos** lista no **personalizar** caixa de diálogo.  
  
```  
virtual int AddToListBox(
    CMFCRibbonCommandsListBox* pWndListBox,  
    BOOL bDeep);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndListBox`  
 Um ponteiro para o **comandos** lista onde o separador é adicionado.  
  
 [in] `bDeep`  
 Ignorado.  
  
### <a name="return-value"></a>Valor de retorno  
 Índice baseado em zero para a cadeia de caracteres na caixa de listagem especificada pelo `pWndListBox`.  
  
##  <a name="cmfcribbonseparator"></a>CMFCRibbonSeparator::CMFCRibbonSeparator  
 Constrói um objeto `CMFCRibbonSeparator`.  
  
```  
CMFCRibbonSeparator(BOOL bIsHoriz = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bIsHoriz`  
 Se `TRUE`, o separador é horizontal; se `FALSE`, o separador é vertical.  
  
### <a name="remarks"></a>Comentários  
 Horizontais separadores são usados nos menus do aplicativo. Separadores verticais são usados em barras de ferramentas.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um objeto de `CMFCRibbonSeparator` classe.  
  
 [!code-cpp[19 NVC_MFC_RibbonApp](../../mfc/reference/codesnippet/cpp/cmfcribbonseparator-class_1.cpp)]  
  
##  <a name="copyfrom"></a>CMFCRibbonSeparator::CopyFrom  
 Um método de cópia que define as variáveis membro do separador de outro objeto.  
  
```  
virtual void CopyFrom(const CMFCRibbonBaseElement& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `Src`  
 O elemento de faixa de opções de origem para copiar de.  
  
##  <a name="getregularsize"></a>CMFCRibbonSeparator::GetRegularSize  
 Retorna o tamanho de um separador.  
  
```  
virtual CSize GetRegularSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um conteúdo de dispositivo.  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho do separador no contexto de determinado dispositivo.  
  
##  <a name="isseparator"></a>CMFCRibbonSeparator::IsSeparator  
 Indica se este é um separador.  
  
```  
virtual BOOL IsSeparator() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre `TRUE` para essa classe.  
  
##  <a name="istabstop"></a>CMFCRibbonSeparator::IsTabStop  
 Indica se esta é uma parada de tabulação.  
  
```  
virtual BOOL IsTabStop() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre `FALSE` para essa classe.  
  
### <a name="remarks"></a>Comentários  
 Um separador de faixa de opções não é uma parada de tabulação.  
  
##  <a name="ondraw"></a>CMFCRibbonSeparator::OnDraw  
 Chamado pelo sistema para desenhar o separador na faixa de opções ou a barra de ferramentas de acesso rápido.  
  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
##  <a name="ondrawonlist"></a>CMFCRibbonSeparator::OnDrawOnList  
 Chamado pelo sistema para desenhar o separador de **comandos** lista.  
  
```  
virtual void OnDrawOnList(
    CDC* pDC,  
    CString strText,  
    int nTextOffset,  
    CRect rect,  
    BOOL bIsSelected,  
    BOOL bHighlighted);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pDC`|Um ponteiro para um contexto de dispositivo.|  
|[in] `strText`|Texto exibido na lista.|  
|[in] `nTextOffset`|Espaçamento entre o texto e o lado esquerdo do retângulo delimitador.|  
|[in] `rect`|Especifica o retângulo delimitador.|  
|[in] `bIsSelected`|Ignorado.|  
|[in] `bHighlighted`|Ignorado.|  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)

