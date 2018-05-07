---
title: Classe CMFCRibbonCheckBox | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCRibbonCheckBox
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::CMFCRibbonCheckBox
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::GetCompactSize
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::GetIntermediateSize
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::GetRegularSize
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::IsDrawTooltipImage
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::OnDraw
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::OnDrawMenuImage
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::OnDrawOnList
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::SetACCData
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonCheckBox [MFC], CMFCRibbonCheckBox
- CMFCRibbonCheckBox [MFC], GetCompactSize
- CMFCRibbonCheckBox [MFC], GetIntermediateSize
- CMFCRibbonCheckBox [MFC], GetRegularSize
- CMFCRibbonCheckBox [MFC], IsDrawTooltipImage
- CMFCRibbonCheckBox [MFC], OnDraw
- CMFCRibbonCheckBox [MFC], OnDrawMenuImage
- CMFCRibbonCheckBox [MFC], OnDrawOnList
- CMFCRibbonCheckBox [MFC], SetACCData
ms.assetid: 3a6c3891-c8d1-4af0-b954-7b9ab048782a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 109c3b2f6337adece6c371f1fafa98291468485e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cmfcribboncheckbox-class"></a>Classe CMFCRibbonCheckBox
O `CMFCRibbonCheckBox` classe implementa uma caixa de seleção que você pode adicionar a um menu pop-up, ferramentas de acesso rápido ou painel de faixa de opções.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonCheckBox : public CMFCRibbonButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonCheckBox::CMFCRibbonCheckBox](#cmfcribboncheckbox)|O construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonCheckBox::GetCompactSize](#getcompactsize)|(Substitui [CMFCRibbonButton::GetCompactSize](../../mfc/reference/cmfcribbonbutton-class.md#getcompactsize).)|  
|[CMFCRibbonCheckBox::GetIntermediateSize](#getintermediatesize)|(Substitui [CMFCRibbonButton::GetIntermediateSize](../../mfc/reference/cmfcribbonbutton-class.md#getintermediatesize).)|  
|[CMFCRibbonCheckBox::GetRegularSize](#getregularsize)|(Substitui [CMFCRibbonButton::GetRegularSize](../../mfc/reference/cmfcribbonbutton-class.md#getregularsize).)|  
|[CMFCRibbonCheckBox::IsDrawTooltipImage](#isdrawtooltipimage)|(Substitui `CMFCRibbonButton::IsDrawTooltipImage`.)|  
|[CMFCRibbonCheckBox::OnDraw](#ondraw)|(Substitui [CMFCRibbonButton::OnDraw](../../mfc/reference/cmfcribbonbutton-class.md#ondraw).)|  
|[CMFCRibbonCheckBox::OnDrawMenuImage](#ondrawmenuimage)|(Substitui [CMFCRibbonBaseElement::OnDrawMenuImage](../../mfc/reference/cmfcribbonbaseelement-class.md#ondrawmenuimage).)|  
|[CMFCRibbonCheckBox::OnDrawOnList](#ondrawonlist)|(Substitui `CMFCRibbonButton::OnDrawOnList`.)|  
|[CMFCRibbonCheckBox::SetACCData](#setaccdata)|(Substitui [CMFCRibbonButton::SetACCData](../../mfc/reference/cmfcribbonbutton-class.md#setaccdata).)|  
  
## <a name="remarks"></a>Comentários  
 Para usar um `CMFCRibbonCheckBox` em seu aplicativo, adicione o seguinte construtor no seu código:  
  
```  
CMFCRibbonCheckBox (UINT nID, LPCTSTR lpszText)  
```  
onde `nID` é a ID de comando da caixa de seleção e `lpszText` é o rótulo de texto da caixa de seleção.  
  
 Você pode adicionar uma caixa de seleção para um painel de faixa de opções usando [CMFCRibbonPanel::Add](../../mfc/reference/cmfcribbonpanel-class.md#add).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonCheckBox](../../mfc/reference/cmfcribboncheckbox-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxribboncheckbox.h  
  
##  <a name="cmfcribboncheckbox"></a>  CMFCRibbonCheckBox::CMFCRibbonCheckBox  
 Construtor de um objeto de caixa de seleção de faixa de opções  
  
```  
CMFCRibbonCheckBox(
    UINT nID,  
    LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 Especifica a ID de comando.  
  
 [in] `lpszText`  
 Especifica o rótulo de texto.  
  
### <a name="return-value"></a>Valor de retorno  
 Constrói um objeto de caixa de seleção de faixa de opções.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um objeto de `CMFCRibbonCheckBox` classe.  
  
 [!code-cpp[NVC_MFC_RibbonApp#17](../../mfc/reference/codesnippet/cpp/cmfcribboncheckbox-class_1.cpp)]  
  
##  <a name="getcompactsize"></a>  CMFCRibbonCheckBox::GetCompactSize  
 Quando substituído, obtém o tamanho compact da caixa de seleção.  
  
```  
virtual CSize GetCompactSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para o `CDC` associado com a caixa de seleção.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um `CSize` objeto que contém o compact tamanho da caixa de seleção.  
  
### <a name="remarks"></a>Comentários  
 Se não for substituída, retorna o tamanho intermediário da caixa de seleção.  
  
##  <a name="getintermediatesize"></a>  CMFCRibbonCheckBox::GetIntermediateSize  
 Obtém o tamanho intermediário da caixa de seleção.  
  
```  
virtual CSize GetIntermediateSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para o `CDC` associado a esta caixa de seleção.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CSize` objeto que contém o tamanho intermediário da caixa de seleção.  
  
### <a name="remarks"></a>Comentários  
 Se não for substituída, calcula o tamanho intermediário, como o tamanho da caixa de seleção padrão ( `AFX_CHECK_BOX_DEFAULT_SIZE`) mais o tamanho do texto, além de margens.  
  
##  <a name="getregularsize"></a>  CMFCRibbonCheckBox::GetRegularSize  
 Obtém o tamanho normal da caixa de seleção.  
  
```  
virtual CSize GetRegularSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para o `CDC` objeto associado a esta caixa de seleção.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um `CSize` objeto que contém o tamanho normal da caixa de seleção.  
  
### <a name="remarks"></a>Comentários  
 Se não for substituída, retorna o tamanho intermediário da caixa de seleção.  
  
##  <a name="isdrawtooltipimage"></a>  CMFCRibbonCheckBox::IsDrawTooltipImage  
 Indica se há uma imagem de dica de ferramenta associada a caixa de seleção.  
  
```  
virtual BOOL IsDrawTooltipImage() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se não houver uma imagem de dica de ferramenta associada a caixa de seleção, ou `FALSE` se não for.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondraw"></a>  CMFCRibbonCheckBox::OnDraw  
 Chamado pelo framework para desenhar a caixa de seleção usando um contexto de dispositivo especificado.  
  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para o `CDC` no qual desenhar a caixa de seleção.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawmenuimage"></a>  CMFCRibbonCheckBox::OnDrawMenuImage  
 Chamado pelo framework para desenhar uma imagem de menu para a caixa de seleção.  
  
```  
virtual BOOL OnDrawMenuImage(CDC*, CRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `CDC*`  
 Ponteiro para o `CDC` associado com a caixa de seleção.  
  
 [in] `CRect`  
 Um `CRect` objeto especificando o retângulo na qual desenhar a imagem do menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se a imagem foi desenhada, ou `FALSE` se não for.  
  
### <a name="remarks"></a>Comentários  
 Se não for substituída, retorna `FALSE`.  
  
##  <a name="ondrawonlist"></a>  CMFCRibbonCheckBox::OnDrawOnList  
 Chamado pelo framework para desenhar a caixa de seleção em uma caixa de lista de comandos.  
  
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
 [in] `pDC`  
 Ponteiro para o contexto de dispositivo no qual desenhar a caixa de seleção.  
  
 [in] `strText`  
 O texto de exibição.  
  
 [in] `nTextOffset`  
 A distância, em pixels, do lado esquerdo da caixa de listagem para o texto de exibição.  
  
 [in] `rect`  
 O retângulo de exibição da caixa de seleção.  
  
 [in] `bIsSelected`  
 `TRUE` Se a caixa de seleção estiver marcada, ou `FALSE` se não for.  
  
 [in] `bHighlighted`  
 `TRUE` Se a caixa de seleção é realçada, ou `FALSE` se não for.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setaccdata"></a>  CMFCRibbonCheckBox::SetACCData  
 Define os dados de acessibilidade para a caixa de seleção.  
  
```  
virtual BOOL SetACCData(
    CWnd* pParent,  
    CAccessibilityData& data);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParent`  
 A janela pai da caixa de seleção.  
  
 `data`  
 Os dados de acessibilidade para a caixa de seleção.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão este método define os dados de acessibilidade para a caixa de seleção e sempre retorna `TRUE`. Substitua este método para definir os dados de acessibilidade e retornar um valor que indica êxito ou falha.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCRibbonPanel](../../mfc/reference/cmfcribbonpanel-class.md)
