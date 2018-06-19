---
title: Classe CMFCToolTipInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCToolTipInfo
- AFXTOOLTIPCTRL/CMFCToolTipInfo
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_bBalloonTooltip
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_bBoldLabel
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_bDrawDescription
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_bDrawIcon
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_bDrawSeparator
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_bRoundedCorners
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_bVislManagerTheme
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_clrBorder
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_clrFill
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_clrFillGradient
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_clrText
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_nGradientAngle
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_nMaxDescrWidth
dev_langs:
- C++
helpviewer_keywords:
- CMFCToolTipInfo [MFC], m_bBalloonTooltip
- CMFCToolTipInfo [MFC], m_bBoldLabel
- CMFCToolTipInfo [MFC], m_bDrawDescription
- CMFCToolTipInfo [MFC], m_bDrawIcon
- CMFCToolTipInfo [MFC], m_bDrawSeparator
- CMFCToolTipInfo [MFC], m_bRoundedCorners
- CMFCToolTipInfo [MFC], m_bVislManagerTheme
- CMFCToolTipInfo [MFC], m_clrBorder
- CMFCToolTipInfo [MFC], m_clrFill
- CMFCToolTipInfo [MFC], m_clrFillGradient
- CMFCToolTipInfo [MFC], m_clrText
- CMFCToolTipInfo [MFC], m_nGradientAngle
- CMFCToolTipInfo [MFC], m_nMaxDescrWidth
ms.assetid: f9d3d7f8-1f08-4342-a7b2-683860e5d2a5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 325650f35d097b54eda160bbdbbd5c877dbd0242
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33368368"
---
# <a name="cmfctooltipinfo-class"></a>Classe CMFCToolTipInfo
Armazena informações sobre a aparência visual de dicas de ferramentas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCToolTipInfo  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolTipInfo::operator =](#operator_eq)||  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolTipInfo::m_bBalloonTooltip](#m_bballoontooltip)|Uma variável booleana que indica se a dica de ferramenta tem uma aparência de balão.|  
|[CMFCToolTipInfo::m_bBoldLabel](#m_bboldlabel)|Uma variável booleana que indica se a dica de ferramenta rótulos são exibidos em uma fonte em negrito.|  
|[CMFCToolTipInfo::m_bDrawDescription](#m_bdrawdescription)|Uma variável booleana que indica se a dica de ferramenta contém uma descrição.|  
|[CMFCToolTipInfo::m_bDrawIcon](#m_bdrawicon)|Uma variável booleana que indica se a dica de ferramenta contém um ícone.|  
|[CMFCToolTipInfo::m_bDrawSeparator](#m_bdrawseparator)|Uma variável booleana que indica se um separador é exibido entre o rótulo de dica de ferramenta e a descrição de dica de ferramenta.|  
|[CMFCToolTipInfo::m_bRoundedCorners](#m_broundedcorners)|Uma variável booleana que indica se a dica de ferramenta tiver cantos arredondados.|  
|[CMFCToolTipInfo::m_bVislManagerTheme](#m_bvislmanagertheme)|Uma variável booleana que indica se a aparência da dica de ferramenta deve ser controlada por um Gerenciador de visual (consulte [CMFCVisualManager classe](../../mfc/reference/cmfcvisualmanager-class.md)).|  
|[CMFCToolTipInfo::m_clrBorder](#m_clrborder)|A cor da borda da dica de ferramenta.|  
|[CMFCToolTipInfo::m_clrFill](#m_clrfill)|A cor do plano de fundo da dica de ferramenta.|  
|[CMFCToolTipInfo::m_clrFillGradient](#m_clrfillgradient)|A cor de preenchimento de gradiente na dica de ferramenta.|  
|[CMFCToolTipInfo::m_clrText](#m_clrtext)|A cor do texto na dica de ferramenta.|  
|[CMFCToolTipInfo::m_nGradientAngle](#m_ngradientangle)|O ângulo de preenchimento de gradiente na dica de ferramenta.|  
|[CMFCToolTipInfo::m_nMaxDescrWidth](#m_nmaxdescrwidth)|A máximo possível largura, em pixels, da descrição na dica de ferramenta.|  
  
## <a name="remarks"></a>Comentários  
 Use [CMFCToolTipCtrl classe](../../mfc/reference/cmfctooltipctrl-class.md), `CMFCToolTipInfo`, e [CTooltipManager classe](../../mfc/reference/ctooltipmanager-class.md) juntas para implementar dicas de ferramenta personalizadas em seu aplicativo. Para obter um exemplo de como usar essas classes de dica de ferramenta, consulte o [CMFCToolTipCtrl classe](../../mfc/reference/cmfctooltipctrl-class.md) tópico.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como definir os valores das variáveis de membro de vários no `CMFCToolTipInfo` classe.  
  
 [!code-cpp[NVC_MFC_RibbonApp#42](../../mfc/reference/codesnippet/cpp/cmfctooltipinfo-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtooltipctrl.h  
  
##  <a name="m_bballoontooltip"></a>  CMFCToolTipInfo::m_bBalloonTooltip  
 Especifica o estilo de exibição de todas as dicas de ferramentas.  
  
```  
BOOL m_bBalloonTooltip;  
```  
  
### <a name="remarks"></a>Comentários  
 `TRUE` Indica se as dicas de ferramenta usam o estilo de balão, `FALSE` indica que as dicas de ferramenta usam o estilo retangular.  
  
##  <a name="m_bboldlabel"></a>  CMFCToolTipInfo::m_bBoldLabel  
 Especifica se a fonte do texto de dica de ferramenta está em negrito.  
  
```  
BOOL m_bBoldLabel;  
```  
  
### <a name="remarks"></a>Comentários  
 Definir esse membro como `TRUE` para exibir o texto de dica de ferramenta com a fonte em negrito, ou `FALSE` para exibir rótulos de dica de ferramenta com a fonte negrito.  
  
##  <a name="m_bdrawdescription"></a>  CMFCToolTipInfo::m_bDrawDescription  
 Especifica se cada dica de ferramenta exibe o texto de descrição.  
  
```  
BOOL m_bDrawDescription;  
```  
  
### <a name="remarks"></a>Comentários  
 Definir esse membro como `TRUE` para exibir a descrição ou `FALSE` para ocultar a descrição. Você pode especificar a descrição em uma dica de ferramenta chamando [CMFCToolTipCtrl::SetDescription](../../mfc/reference/cmfctooltipctrl-class.md#setdescription)  
  
##  <a name="m_bdrawicon"></a>  CMFCToolTipInfo::m_bDrawIcon  
 Especifica se todas as dicas de ferramenta exibem ícones.  
  
```  
BOOL m_bDrawIcon;  
```  
  
### <a name="remarks"></a>Comentários  
 Definir esse membro como `TRUE` para exibir um ícone em cada dica de ferramenta ou `FALSE` para exibir dicas de ferramenta sem ícones.  
  
##  <a name="m_bdrawseparator"></a>  CMFCToolTipInfo::m_bDrawSeparator  
 Especifica se cada dica de ferramenta tem um separador entre seu rótulo e sua descrição.  
  
```  
BOOL m_bDrawSeparator;  
```  
  
### <a name="remarks"></a>Comentários  
 Definir esse membro como `TRUE` para exibir o separador entre o rótulo de dica de ferramenta e a descrição, ou `FALSE` para exibir dicas de ferramenta sem nenhum separador.  
  
##  <a name="m_broundedcorners"></a>  CMFCToolTipInfo::m_bRoundedCorners  
 Especifica se todas as dicas de ferramenta tem cantos arredondados.  
  
```  
BOOL m_bRoundedCorners;  
```  
  
### <a name="remarks"></a>Comentários  
 Definir esse membro como `TRUE` para exibir os cantos arredondados em dicas de ferramenta ou `FALSE` para exibir os cantos retangulares em dicas de ferramenta.  
  
##  <a name="m_clrborder"></a>  CMFCToolTipInfo::m_clrBorder  
 Especifica a cor das bordas em todas as dicas de ferramenta.  
  
```  
COLORREF m_clrBorder;  
```  
  
##  <a name="m_clrfill"></a>  CMFCToolTipInfo::m_clrFill  
 Especifica a cor de fundo da dica de ferramenta.  
  
```  
COLORREF m_clrFill;  
```  
  
### <a name="remarks"></a>Comentários  
 Se [CMFCToolTipInfo::m_clrFillGradient](#m_clrfillgradient) é -1, a cor de fundo da dica de ferramenta é `m_clrFill`. Caso contrário, `m_clrFill` Especifica a cor do início do gradiente e `m_clrFillGradient` Especifica a cor do final do gradiente. [CMFCToolTipInfo::m_nGradientAngle](#m_ngradientangle) determina a direção do gradiente.  
  
##  <a name="m_clrfillgradient"></a>  CMFCToolTipInfo::m_clrFillGradient  
 Especifica a cor final de um plano de fundo gradiente para dicas de ferramenta.  
  
```  
COLORREF m_clrFillGradient;  
```  
  
### <a name="remarks"></a>Comentários  
 Se `m_clrFillGradient` é -1, não há nenhum gradiente. Caso contrário, a cor inicial do gradiente é especificada pelo [CMFCToolTipInfo::m_clrFill](#m_clrfill) e a cor do gradiente concluir é especificada pelo `m_clrFillGradient`. [CMFCToolTipInfo::m_nGradientAngle](#m_ngradientangle) determina a direção do gradiente.  
  
##  <a name="m_clrtext"></a>  CMFCToolTipInfo::m_clrText  
 Especifica a cor do texto de todas as dicas de ferramentas.  
  
```  
COLORREF m_clrText;  
```  
  
##  <a name="m_ngradientangle"></a>  CMFCToolTipInfo::m_nGradientAngle  
 Especifica o ângulo no qual um gradiente é desenhado no plano de fundo de dicas de ferramenta.  
  
```  
int m_nGradientAngle;  
```  
  
### <a name="remarks"></a>Comentários  
 `m_nGradientAngle` Especifica o ângulo em graus, deslocamento de gradiente do plano de fundo de dicas de ferramentas de horizontal. Se `m_nGradientAngle` for 0, o gradiente é desenhado da esquerda para a direita. Se `m_nGradientAngle` está entre 1 e 360, o gradiente é girando no sentido horário por esse número de graus. Se `m_nGradientAngle` é -1, que é o valor padrão, o gradiente é desenhado de cima para baixo. Isso é o mesmo que a configuração `m_nGradientAngle` como 90.  
  
 [CMFCToolTipInfo::m_clrFill](#m_clrfill) `clrFill` Especifica a cor do início do gradiente e [CMFCToolTipInfo::m_clrFillGradient](#m_clrfillgradient) `clrFillGradient` Especifica a cor do final do gradiente. Se `m_clrFillGradient` é -1, não há nenhum gradiente.  
  
##  <a name="m_nmaxdescrwidth"></a>  CMFCToolTipInfo::m_nMaxDescrWidth  
 Especifica a largura máxima da descrição de ele ser exibido em cada dica de ferramenta. Se a largura de descrição excede o valor especificado, o texto é quebrado.  
  
```  
int m_nMaxDescrWidth;  
```  
  
##  <a name="m_bvislmanagertheme"></a>  CMFCToolTipInfo::m_bVislManagerTheme  
 Especifica se o Gerenciador de visual do aplicativo controla a aparência de todas as dicas de ferramentas.  
  
```  
BOOL m_bVislManagerTheme;  
```  
  
### <a name="remarks"></a>Comentários  
 Se `m_bVislManagerTheme` é `TRUE`, cada dica de ferramenta solicita um novo [CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md) do Gerenciador de visual do aplicativo antes que eles aparecem na tela e usa os valores nesse objeto para determinar sua aparência. Os outros membros da sua [CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md) são ignorados.  
  
##  <a name="operator_eq"></a>  CMFCToolTipInfo::operator =  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CMFCToolTipInfo& operator=(CMFCToolTipInfo& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `src`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CTooltipManager](../../mfc/reference/ctooltipmanager-class.md)   
 [Classe CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md)
