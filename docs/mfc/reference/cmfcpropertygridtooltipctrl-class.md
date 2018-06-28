---
title: Classe CMFCPropertyGridToolTipCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCPropertyGridToolTipCtrl
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl::Create
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl::Deactivate
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl::GetLastRect
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl::Hide
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl::SetTextMargin
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl::Track
dev_langs:
- C++
helpviewer_keywords:
- CMFCPropertyGridToolTipCtrl [MFC], CMFCPropertyGridToolTipCtrl
- CMFCPropertyGridToolTipCtrl [MFC], Create
- CMFCPropertyGridToolTipCtrl [MFC], Deactivate
- CMFCPropertyGridToolTipCtrl [MFC], GetLastRect
- CMFCPropertyGridToolTipCtrl [MFC], Hide
- CMFCPropertyGridToolTipCtrl [MFC], SetTextMargin
- CMFCPropertyGridToolTipCtrl [MFC], Track
ms.assetid: 84b436e5-6695-4da0-9569-1a875e087711
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c284f5d5fdfee09349cc6eb9cbde38da21918d25
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37040955"
---
# <a name="cmfcpropertygridtooltipctrl-class"></a>Classe CMFCPropertyGridToolTipCtrl
Implementa uma dica de ferramenta de controle que o [CMFCPropertyGridCtrl classe](../../mfc/reference/cmfcpropertygridctrl-class.md) usa para exibir dicas de ferramenta.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCPropertyGridToolTipCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl](#cmfcpropertygridtooltipctrl)|Constrói um objeto `CMFCPropertyGridToolTipCtrl`.|  
|`CMFCPropertyGridToolTipCtrl::~CMFCPropertyGridToolTipCtrl`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCPropertyGridToolTipCtrl::Create](#create)|Cria uma janela para o controle de dica de ferramenta.|  
|[CMFCPropertyGridToolTipCtrl::Deactivate](#deactivate)|Desativa e oculta o controle de dica de ferramenta.|  
|[CMFCPropertyGridToolTipCtrl::GetLastRect](#getlastrect)|Retorna as coordenadas da última posição do controle tooltip.|  
|[CMFCPropertyGridToolTipCtrl::Hide](#hide)|Oculta o controle de dica de ferramenta.|  
|`CMFCPropertyGridToolTipCtrl::PreTranslateMessage`|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para converter as mensagens de janela antes de serem distribuídos para o [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) funções do Windows. (Substitui [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|  
|[CMFCPropertyGridToolTipCtrl::SetTextMargin](#settextmargin)|Define o espaçamento entre o texto de dica de ferramenta e a borda da janela de dica de ferramenta.|  
|[CMFCPropertyGridToolTipCtrl::Track](#track)|Exibe o controle de dica de ferramenta.|  
  
## <a name="remarks"></a>Comentários  
 Dicas de ferramenta são exibidas quando o ponteiro permanece em um nome de propriedade. O [CMFCPropertyGridToolTipCtrl](../../mfc/reference/cmfcpropertygridtooltipctrl-class.md) classe exibe uma dica de ferramenta para que seja facilmente legível pelo usuário. Normalmente, a posição de uma dica de ferramenta é determinada pela posição do ponteiro. Ao usar essa classe, a dica de ferramenta aparece sobre o nome da propriedade e é semelhante a extensão de propriedade natural, para que o nome da propriedade está completamente visível.  
  
 MFC automaticamente cria esse controle e usa-na [CMFCPropertyGridCtrl classe](../../mfc/reference/cmfcpropertygridctrl-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um objeto de `CMFCPropertyGridToolTipCtrl` classe e como exibir o controle de dica de ferramenta.  
  
 [!code-cpp[NVC_MFC_RibbonApp#23](../../mfc/reference/codesnippet/cpp/cmfcpropertygridtooltipctrl-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CMFCPropertyGridToolTipCtrl](../../mfc/reference/cmfcpropertygridtooltipctrl-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpropertygridtooltipctrl.h  
  
##  <a name="cmfcpropertygridtooltipctrl"></a>  CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl  
 Constrói um objeto `CMFCPropertyGridToolTipCtrl`.  
  
```  
CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl();
```  
  
##  <a name="create"></a>  CMFCPropertyGridToolTipCtrl::Create  
 Cria uma janela para o controle de dica de ferramenta.  
  
```  
BOOL Create(CWnd* pWndParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pWndParent*  
 Um ponteiro para a janela pai.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a janela foi criada com êxito; Caso contrário, FALSE.  
  
##  <a name="deactivate"></a>  CMFCPropertyGridToolTipCtrl::Deactivate  
 Desativa e oculta o controle de dica de ferramenta.  
  
```  
void Deactivate();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método define a última posição e o texto para valores vazios, para que as chamadas futuras para [CMFCPropertyGridToolTipCtrl::Track](#track) exibir a dica de ferramenta.  
  
##  <a name="getlastrect"></a>  CMFCPropertyGridToolTipCtrl::GetLastRect  
 Retorna as coordenadas da última posição do controle tooltip.  
  
```  
void GetLastRect(CRect& rect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] *rect*  
 Contém a última posição do controle tooltip.  
  
##  <a name="hide"></a>  CMFCPropertyGridToolTipCtrl::Hide  
 Oculta o controle de dica de ferramenta.  
  
```  
void Hide();
```  
  
##  <a name="settextmargin"></a>  CMFCPropertyGridToolTipCtrl::SetTextMargin  
 Define o espaçamento entre o texto de dica de ferramenta e a borda da janela de dica de ferramenta.  
  
```  
void SetTextMargin(int nTextMargin);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *nTextMargin*  
 Especifica o espaçamento entre o texto do controle de dica de ferramenta e a borda da janela de dica de ferramenta. O valor padrão é 10 pixels.  
  
##  <a name="track"></a>  CMFCPropertyGridToolTipCtrl::Track  
 Exibe o controle de dica de ferramenta.  
  
```  
void Track(
    CRect rect,  
    const CString& strText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *rect*  
 Especifica a posição e o tamanho do controle tooltip.  
  
 [in] *strText*  
 Especifica o texto a ser mostrado na dica de ferramenta.  
  
### <a name="remarks"></a>Comentários  
 Esse método exibe o controle de dica de ferramenta na posição e tamanho especificado por *rect*. Se a posição, o tamanho e o texto não foram alterados desde a última vez em que esse método foi chamado, esse método não terá efeito.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)
