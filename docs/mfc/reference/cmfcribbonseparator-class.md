---
title: Classe CMFCRibbonSeparator | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CMFCRibbonSeparator [MFC], CMFCRibbonSeparator
- CMFCRibbonSeparator [MFC], AddToListBox
- CMFCRibbonSeparator [MFC], CopyFrom
- CMFCRibbonSeparator [MFC], GetRegularSize
- CMFCRibbonSeparator [MFC], IsSeparator
- CMFCRibbonSeparator [MFC], IsTabStop
- CMFCRibbonSeparator [MFC], OnDraw
- CMFCRibbonSeparator [MFC], OnDrawOnList
ms.assetid: bedb1a53-cb07-4c3c-be12-698c5409e7cf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 12f4b9019a79b6ff57da6905b6ad9329788b4ec9
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37849757"
---
# <a name="cmfcribbonseparator-class"></a>Classe CMFCRibbonSeparator
Implementa o separador de faixa de opções.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonSeparator : public CMFCRibbonBaseElement  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCRibbonSeparator::CMFCRibbonSeparator](#cmfcribbonseparator)|Constrói um objeto `CMFCRibbonSeparator`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCRibbonSeparator::AddToListBox](#addtolistbox)|Adiciona um separador para o **comandos** lista os **personalizar** caixa de diálogo. (Substitui [CMFCRibbonBaseElement::AddToListBox](../../mfc/reference/cmfcribbonbaseelement-class.md#addtolistbox).)|  
|`CMFCRibbonSeparator::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|  
|`CMFCRibbonSeparator::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCRibbonSeparator::CopyFrom](#copyfrom)|Um método de cópia que define as variáveis de membro de um separador de outro objeto.|  
|[CMFCRibbonSeparator::GetRegularSize](#getregularsize)|Retorna o tamanho de um separador.|  
|[CMFCRibbonSeparator::IsSeparator](#isseparator)|Indica se este é um separador.|  
|[CMFCRibbonSeparator::IsTabStop](#istabstop)|Indica se esta é uma parada de tabulação.|  
|[CMFCRibbonSeparator::OnDraw](#ondraw)|Chamado pelo sistema para desenhar o separador na faixa de opções ou a barra de ferramentas de acesso rápido.|  
|[CMFCRibbonSeparator::OnDrawOnList](#ondrawonlist)|Chamado pelo sistema para desenhar o separador na **comandos** lista.|  
  
## <a name="remarks"></a>Comentários  
 Um separador de faixa de opções é uma linha vertical ou horizontal, que logicamente separa elementos de fita. Um separador pode ser desenhado no controle da faixa de opções, no menu principal do aplicativo, a barra de status da faixa de opções e ferramentas de acesso rápido.  
  
 Para usar um separador em seu aplicativo, construa o novo objeto e adicioná-lo ao menu principal do aplicativo, conforme mostrado aqui:  
  
```  
CMFCRibbonMainPanel* pMainPanel = m_wndRibbonBar.AddMainCategory(_T("Main Menu"),
    IDB_FILESMALL,
    IDB_FILELARGE);

...  
pMainPanel->Add(new CMFCRibbonSeparator(TRUE));
```  
Chame [CMFCRibbonPanel::AddSeparator](../../mfc/reference/cmfcribbonpanel-class.md#addseparator) adicionar separadores a painéis de faixa de opções. Os separadores são alocados e adicionados internamente pelo `AddSeparator` método.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonSeparator](../../mfc/reference/cmfcribbonseparator-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxbaseribbonelement.h  
  
##  <a name="addtolistbox"></a>  CMFCRibbonSeparator::AddToListBox  
 Adiciona um separador para o **comandos** lista os **personalizar** caixa de diálogo.  
  
```  
virtual int AddToListBox(
    CMFCRibbonCommandsListBox* pWndListBox,  
    BOOL bDeep);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pWndListBox*  
 Um ponteiro para o **comandos** lista em que o separador é adicionado.  
  
 [in] *bDeep*  
 Ignorado.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero na cadeia de caracteres na caixa de listagem especificada por *pWndListBox*.  
  
##  <a name="cmfcribbonseparator"></a>  CMFCRibbonSeparator::CMFCRibbonSeparator  
 Constrói um objeto `CMFCRibbonSeparator`.  
  
```  
CMFCRibbonSeparator(BOOL bIsHoriz = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bIsHoriz*  
 Se for TRUE, o separador é horizontal; Se for FALSE, o separador é vertical.  
  
### <a name="remarks"></a>Comentários  
 Horizontais separadores são usados nos menus do aplicativo. Separadores verticais são usados em barras de ferramentas.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um objeto do `CMFCRibbonSeparator` classe.  
  
 [!code-cpp[NVC_MFC_RibbonApp#19](../../mfc/reference/codesnippet/cpp/cmfcribbonseparator-class_1.cpp)]  
  
##  <a name="copyfrom"></a>  CMFCRibbonSeparator::CopyFrom  
 Um método de cópia que define as variáveis de membro de um separador de outro objeto.  
  
```  
virtual void CopyFrom(const CMFCRibbonBaseElement& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *Src*  
 O elemento de faixa de opções de origem para copiar de.  
  
##  <a name="getregularsize"></a>  CMFCRibbonSeparator::GetRegularSize  
 Retorna o tamanho de um separador.  
  
```  
virtual CSize GetRegularSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 Um ponteiro para o conteúdo de um dispositivo.  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho do separador no contexto de determinado dispositivo.  
  
##  <a name="isseparator"></a>  CMFCRibbonSeparator::IsSeparator  
 Indica se este é um separador.  
  
```  
virtual BOOL IsSeparator() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre TRUE para essa classe.  
  
##  <a name="istabstop"></a>  CMFCRibbonSeparator::IsTabStop  
 Indica se esta é uma parada de tabulação.  
  
```  
virtual BOOL IsTabStop() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre FALSE para essa classe.  
  
### <a name="remarks"></a>Comentários  
 Um separador de faixa de opções não é uma parada de tabulação.  
  
##  <a name="ondraw"></a>  CMFCRibbonSeparator::OnDraw  
 Chamado pelo sistema para desenhar o separador na faixa de opções ou a barra de ferramentas de acesso rápido.  
  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 Um ponteiro para um contexto de dispositivo.  
  
##  <a name="ondrawonlist"></a>  CMFCRibbonSeparator::OnDrawOnList  
 Chamado pelo sistema para desenhar o separador na **comandos** lista.  
  
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
|[in] *pDC*|Um ponteiro para um contexto de dispositivo.|  
|[in] *strText*|Texto exibido na lista.|  
|[in] *nTextOffset*|Espaçamento entre o texto e o lado esquerdo do retângulo delimitador.|  
|[in] *rect*|Especifica o retângulo delimitador.|  
|[in] *bIsSelected*|Ignorado.|  
|[in] *bHighlighted*|Ignorado.|  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)
