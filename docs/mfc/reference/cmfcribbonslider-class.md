---
title: Classe CMFCRibbonSlider | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonSlider
- AFXRIBBONSLIDER/CMFCRibbonSlider
- AFXRIBBONSLIDER/CMFCRibbonSlider::CMFCRibbonSlider
- AFXRIBBONSLIDER/CMFCRibbonSlider::GetPos
- AFXRIBBONSLIDER/CMFCRibbonSlider::GetRangeMax
- AFXRIBBONSLIDER/CMFCRibbonSlider::GetRangeMin
- AFXRIBBONSLIDER/CMFCRibbonSlider::GetRegularSize
- AFXRIBBONSLIDER/CMFCRibbonSlider::GetZoomIncrement
- AFXRIBBONSLIDER/CMFCRibbonSlider::HasZoomButtons
- AFXRIBBONSLIDER/CMFCRibbonSlider::OnDraw
- AFXRIBBONSLIDER/CMFCRibbonSlider::SetPos
- AFXRIBBONSLIDER/CMFCRibbonSlider::SetRange
- AFXRIBBONSLIDER/CMFCRibbonSlider::SetZoomButtons
- AFXRIBBONSLIDER/CMFCRibbonSlider::SetZoomIncrement
dev_langs: C++
helpviewer_keywords:
- CMFCRibbonSlider [MFC], CMFCRibbonSlider
- CMFCRibbonSlider [MFC], GetPos
- CMFCRibbonSlider [MFC], GetRangeMax
- CMFCRibbonSlider [MFC], GetRangeMin
- CMFCRibbonSlider [MFC], GetRegularSize
- CMFCRibbonSlider [MFC], GetZoomIncrement
- CMFCRibbonSlider [MFC], HasZoomButtons
- CMFCRibbonSlider [MFC], OnDraw
- CMFCRibbonSlider [MFC], SetPos
- CMFCRibbonSlider [MFC], SetRange
- CMFCRibbonSlider [MFC], SetZoomButtons
- CMFCRibbonSlider [MFC], SetZoomIncrement
ms.assetid: 9351ac34-f234-4e42-91e2-763f1989c8ff
caps.latest.revision: "43"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e485afac346be1f21a0b3088367be5b9bf02e2ab
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfcribbonslider-class"></a>Classe CMFCRibbonSlider
O `CMFCRibbonSlider` classe implementa um controle deslizante que você pode adicionar uma barra de faixa de opções ou na barra de status da faixa de opções. O controle deslizante de faixa de opções se parece com os controles deslizantes de zoom que aparecem em aplicativos do Office 2007.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonSlider : public CMFCRibbonBaseElement  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonSlider::CMFCRibbonSlider](#cmfcribbonslider)|Cria e inicializa um controle deslizante de faixa de opções.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonSlider::GetPos](#getpos)|Retorna a posição atual do controle deslizante.|  
|[CMFCRibbonSlider::GetRangeMax](#getrangemax)|Retorna o valor máximo do controle deslizante.|  
|[CMFCRibbonSlider::GetRangeMin](#getrangemin)|Retorna o valor mínimo do controle deslizante.|  
|[CMFCRibbonSlider::GetRegularSize](#getregularsize)|Retorna o tamanho normal do elemento de faixa de opções. (Substitui [CMFCRibbonBaseElement::GetRegularSize](../../mfc/reference/cmfcribbonbaseelement-class.md#getregularsize).)|  
|[CMFCRibbonSlider::GetZoomIncrement](#getzoomincrement)|Retorna o tamanho do incremento de zoom para o controle deslizante.|  
|[CMFCRibbonSlider::HasZoomButtons](#haszoombuttons)|Especifica se o controle deslizante tem os botões de zoom.|  
|[CMFCRibbonSlider::OnDraw](#ondraw)|Chamado pelo framework para desenhar o elemento de faixa de opções. (Substitui [CMFCRibbonBaseElement::OnDraw](../../mfc/reference/cmfcribbonbaseelement-class.md#ondraw).)|  
|[CMFCRibbonSlider::SetPos](#setpos)|Define a posição atual do controle deslizante.|  
|[CMFCRibbonSlider::SetRange](#setrange)|Especifica o intervalo do controle deslizante, definindo os valores mínimo e máximo.|  
|[CMFCRibbonSlider::SetZoomButtons](#setzoombuttons)|Mostra ou oculta os botões de zoom.|  
|[CMFCRibbonSlider::SetZoomIncrement](#setzoomincrement)|Define o tamanho do incremento de zoom para o controle deslizante.|  
  
## <a name="remarks"></a>Comentários  
 Você pode usar o `SetRange` método para configurar o intervalo de incrementos de zoom para o controle deslizante. Você pode definir a posição atual do controle deslizante usando o `SetPos` método.  
  
 Você pode exibir botões de zoom circular à esquerda e direita do controle deslizante, usando o `SetZoomButtons` método. Por padrão, o controle deslizante é horizontal, botão zoom à esquerda exibe um sinal de menos e o botão de zoom à direita exibe um sinal de adição.  
  
 O `SetZoomIncrement` método define o incremento para adicionar ou subtrair a partir da posição atual quando um usuário clica nos botões de zoom.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCRibbonSlider` classe para definir as propriedades do controle deslizante. O exemplo mostra como construir um `CMFCRibbonSlider` do objeto, exibir botões de zoom, defina a posição atual do controle deslizante e definir o intervalo de valores para o controle deslizante.  
  
 [!code-cpp[NVC_MFC_RibbonApp#12](../../mfc/reference/codesnippet/cpp/cmfcribbonslider-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonSlider](../../mfc/reference/cmfcribbonslider-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxribbonslider.h  
  
##  <a name="cmfcribbonslider"></a>CMFCRibbonSlider::CMFCRibbonSlider  
 Construa um controle deslizante de faixa de opções.  
  
```  
CMFCRibbonSlider(
    UINT nID,  
    int nWidth=100);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 ID do controle deslizante.  
  
 [in]. `nWidth`  
 Largura do controle deslizante em pixels.  
  
### <a name="remarks"></a>Comentários  
 Constrói um seletor de faixa de opções é `nWidth` pixels de largura na categoria de painel em que o controle deslizante é adicionado. Por padrão, o controle deslizante é horizontal.  
  
##  <a name="getpos"></a>CMFCRibbonSlider::GetPos  
 Retorna a posição atual do controle deslizante.  
  
```  
int GetPos() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A posição atual do controle deslizante, que é uma posição relativa ao início do controle deslizante.  
  
##  <a name="getrangemax"></a>CMFCRibbonSlider::GetRangeMax  
 Obtém o incremento máximo do controle deslizante que o controle deslizante de tráfego o controle deslizante.  
  
```  
int GetRangeMax() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O incremento máximo do controle deslizante que o controle deslizante de tráfego o controle deslizante.  
  
##  <a name="getrangemin"></a>CMFCRibbonSlider::GetRangeMin  
 Retorna o menor incremento pode percorrer o controle deslizante no controle deslizante.  
  
```  
int GetRangeMin() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O incremento mínimo que o controle deslizante de tráfego o controle deslizante.  
  
##  <a name="getregularsize"></a>CMFCRibbonSlider::GetRegularSize  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual CSize GetRegularSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getzoomincrement"></a>CMFCRibbonSlider::GetZoomIncrement  
 Obtenha o incremento de zoom para o controle deslizante.  
  
```  
int GetZoomIncrement() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O incremento de zoom para o controle deslizante.  
  
##  <a name="haszoombuttons"></a>CMFCRibbonSlider::HasZoomButtons  
 Especifica se o controle deslizante tem os botões de zoom.  
  
```  
BOOL HasZoomButtons() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o controle deslizante tem os botões de zoom; `FALSE` caso contrário.  
  
##  <a name="ondraw"></a>CMFCRibbonSlider::OnDraw  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setpos"></a>CMFCRibbonSlider::SetPos  
 Defina a posição atual do controle deslizante.  
  
```  
void SetPos(
    int nPos,  
    BOOL bRedraw=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nPos`  
 Especifica a posição a ser definido para o controle deslizante. A posição é relativo ao início do controle deslizante.  
  
 [in] `bRedraw`  
 Se `TRUE`, o controle deslizante irá redesenhado.  
  
##  <a name="setrange"></a>CMFCRibbonSlider::SetRange  
 Defina o intervalo de valores para o controle deslizante.  
  
```  
void SetRange(
    int nMin,  
    int nMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nMin`  
 Especifica o valor mínimo do controle deslizante.  
  
 [in] `nMax`  
 Especifica o valor máximo do controle deslizante.  
  
### <a name="remarks"></a>Comentários  
 Especifica o intervalo de valores para o controle deslizante, definindo os valores mínimo e máximo.  
  
##  <a name="setzoombuttons"></a>CMFCRibbonSlider::SetZoomButtons  
 Exibir ou ocultar os botões de zoom.  
  
```  
void SetZoomButtons(BOOL bSet=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in]. `bSet`  
 `TRUE`Para exibir botões de zoom; `FALSE` para ocultá-las.  
  
##  <a name="setzoomincrement"></a>CMFCRibbonSlider::SetZoomIncrement  
 Defina o incremento de zoom para o controle deslizante.  
  
```  
void SetZoomIncrement(int nZoomIncrement);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nZoomIncrement`  
 Especifica o incremento de zoom do controle deslizante.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)
