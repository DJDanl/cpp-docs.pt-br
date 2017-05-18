---
title: Classe CSplitterWndEx | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSplitterWndEx
- AFXSPLITTERWNDEX/CSplitterWndEx
- AFXSPLITTERWNDEX/CSplitterWndEx::OnDrawSplitter
dev_langs:
- C++
helpviewer_keywords:
- CSplitterWndEx
ms.assetid: 33e5eef3-05e1-4a07-a968-bf9207ce8598
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
ms.sourcegitcommit: 73410ae17465880f455e5b15026f6cc010803c19
ms.openlocfilehash: 08b26bc2321485181941dbaaa9a903de9a401ef8
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="csplitterwndex-class"></a>Classe CSplitterWndEx



Representa uma janela separadora personalizada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSplitterWndEx : public CSplitterWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CSplitterWndEx::CSplitterWndEx`|Construtor padrão.|  
|`CSplitterWndEx::~CSplitterWndEx`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSplitterWndEx::OnDrawSplitter](#ondrawsplitter)|Chamado pela estrutura para desenhar uma janela separadora. (Substitui [CSplitterWnd::OnDrawSplitter](csplitterwnd-class.md#ondrawsplitter).)|  
  
## <a name="remarks"></a>Comentários  
 Substituir o `OnDrawSplitter` método para personalizar a aparência dos componentes de gráfico de uma janela separadora.  
  
 O `CSplitterWndEx` classe é usada junto com o [OnDrawSplitterBorder](cmfcvisualmanager-class.md#ondrawsplitterborder), [OnDrawSplitterBox](cmfcvisualmanager-class.md#ondrawsplitterbox), e [OnFillSplitterBackground](cmfcvisualmanager-class.md#onfillsplitterbackground) métodos, que são implementados por um gerente visual. Para fazer com que um Gerenciador visual desenhar uma janela separadora em seu aplicativo, substitua as declarações do `CSplitterWnd` de classe com o `CSplitterWndEx` classe. Para aplicativos de janela de quadro, a classe de janela divisor é declarada na classe CMainFrame que está localizada em mainfrm.h. Para obter um exemplo, consulte o `OutlookDemo` no diretório de exemplos.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](cobject-class.md)  
  
 [CCmdTarget](ccmdtarget-class.md)  
  
 [CWnd](cwnd-class.md)  
  
 [CSplitterWnd](csplitterwnd-class.md)  
   
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxsplitterwndex.h  
  
##  <a name="ondrawsplitter"></a>CSplitterWndEx::OnDrawSplitter  
 Chamado pela estrutura para desenhar uma janela separadora.  
  
```  
virtual void OnDrawSplitter(  
   CDC* pDC,  
   ESplitType nType,  
   const CRect& rect   
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para o contexto do dispositivo. Se esse parâmetro for `NULL`, o framework redesenha a janela ativa.  
  
 [in] `nType`  
 Um do `CSplitterWnd::ESplitType` valores de enumeração que especifica o elemento de janela divisor para desenhar. Os valores válidos são `splitBox`, `splitBar`, `splitIntersection`, e `splitBorder`.  
  
 [in] `rect`  
 Um retângulo que especifica as dimensões e locais para desenhar o elemento da janela de divisão especificada.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../hierarchy-chart.md)   
 [Classes](mfc-classes.md)   
 [Classe CSplitterWnd](csplitterwnd-class.md)   
 [Classe CMFCVisualManager](cmfcvisualmanager-class.md)
