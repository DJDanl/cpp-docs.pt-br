---
title: Classe CMFCRibbonProgressBar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCRibbonProgressBar
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::CMFCRibbonProgressBar
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::GetPos
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::GetRangeMax
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::GetRangeMin
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::GetRegularSize
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::IsInfiniteMode
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::OnDraw
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::SetInfiniteMode
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::SetPos
- AFXRIBBONPROGRESSBAR/CMFCRibbonProgressBar::SetRange
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonProgressBar [MFC], CMFCRibbonProgressBar
- CMFCRibbonProgressBar [MFC], GetPos
- CMFCRibbonProgressBar [MFC], GetRangeMax
- CMFCRibbonProgressBar [MFC], GetRangeMin
- CMFCRibbonProgressBar [MFC], GetRegularSize
- CMFCRibbonProgressBar [MFC], IsInfiniteMode
- CMFCRibbonProgressBar [MFC], OnDraw
- CMFCRibbonProgressBar [MFC], SetInfiniteMode
- CMFCRibbonProgressBar [MFC], SetPos
- CMFCRibbonProgressBar [MFC], SetRange
ms.assetid: de3d9f2e-ed59-480e-aa7d-08a33ab36c67
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2b9d0d1ab9722b14caddc3935d820301ae229f5a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cmfcribbonprogressbar-class"></a>Classe CMFCRibbonProgressBar
Implementa um controle que indica visualmente o andamento de uma operação demorada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonProgressBar : public CMFCRibbonBaseElement  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonProgressBar::CMFCRibbonProgressBar](#cmfcribbonprogressbar)|Constrói e inicializa um objeto `CMFCRibbonProgressBar`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonProgressBar::GetPos](#getpos)|Retorna o progresso atual.|  
|[CMFCRibbonProgressBar::GetRangeMax](#getrangemax)|Retorna o valor máximo do intervalo atual.|  
|[CMFCRibbonProgressBar::GetRangeMin](#getrangemin)|Retorna o valor mínimo do intervalo atual.|  
|[CMFCRibbonProgressBar::GetRegularSize](#getregularsize)|Retorna o tamanho normal do elemento de faixa de opções. (Substitui [CMFCRibbonBaseElement::GetRegularSize](../../mfc/reference/cmfcribbonbaseelement-class.md#getregularsize).)|  
|[CMFCRibbonProgressBar::IsInfiniteMode](#isinfinitemode)|Especifica se a barra de progresso está funcionando no modo de infinito.|  
|[CMFCRibbonProgressBar::OnDraw](#ondraw)|Chamado pelo framework para desenhar o elemento de faixa de opções. (Substitui [CMFCRibbonBaseElement::OnDraw](../../mfc/reference/cmfcribbonbaseelement-class.md#ondraw).)|  
|[CMFCRibbonProgressBar::SetInfiniteMode](#setinfinitemode)|Define a barra de progresso para funcionar no modo de infinito.|  
|[CMFCRibbonProgressBar::SetPos](#setpos)|Define o progresso atual.|  
|[CMFCRibbonProgressBar::SetRange](#setrange)|Define os valores mínimos e máximo.|  
  
## <a name="remarks"></a>Comentários  
 Um `CMFCRibbonProgressBar` pode operar em dois modos: regular e infinito. No modo normal, a barra de progresso é preenchida da esquerda para a direita e para quando alcança o valor máximo. No modo de infinito, a barra de progresso é preenchida repetidamente do valor mínimo para o valor máximo. Você pode usar o modo de infinito para indicar que uma operação está em andamento, mas que o tempo de conclusão é desconhecido.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCRibbonProgressBar` classe. O exemplo mostra como definir a barra de progresso para funcionar no modo de infinito (onde o tempo de conclusão de uma operação é desconhecido), defina os valores mínimos e máximo para a barra de progresso e definir a posição atual da barra de progresso. Este trecho de código é parte do [exemplo de demonstração do MS Office 2007](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MSOffice2007Demo#11](../../mfc/reference/codesnippet/cpp/cmfcribbonprogressbar-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonProgressBar](../../mfc/reference/cmfcribbonprogressbar-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxRibbonProgressBar.h  
  
##  <a name="cmfcribbonprogressbar"></a>  CMFCRibbonProgressBar::CMFCRibbonProgressBar  
 Cria e inicializa um [CMFCRibbonProgressBar](../../mfc/reference/cmfcribbonprogressbar-class.md) objeto.  
  
```  
CMFCRibbonProgressBar();

 
CMFCRibbonProgressBar(
    UINT nID,  
    int nWidth = 90,  
    int nHeight = 22);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 Especifica a ID de comando para a barra de progresso da faixa de opções.  
  
 [in] `nWidth`  
 Especifica a largura, em pixels, da barra de progresso da faixa de opções.  
  
 [in] `nHeight`  
 Especifica a altura, em pixels, da barra de progresso da faixa de opções.  
  
##  <a name="getpos"></a>  CMFCRibbonProgressBar::GetPos  
 Retorna a posição atual da barra de progresso.  
  
```  
int GetPos () const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que representa a posição atual da barra de progresso.  
  
### <a name="remarks"></a>Comentários  
 O intervalo que está sendo definido deve estar dentro do intervalo especificado pelo [CMFCRibbonProgressBar::SetRange](#setrange) método.  
  
##  <a name="getrangemax"></a>  CMFCRibbonProgressBar::GetRangeMax  
 Retorna a barra de progresso atual do valor máximo.  
  
```  
int GetRangeMax() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor máximo do intervalo atual.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getrangemin"></a>  CMFCRibbonProgressBar::GetRangeMin  
 Retorna a barra de progresso atual do valor mínimo do intervalo.  
  
```  
int GetRangeMin() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor mínimo do intervalo atual.  
  
##  <a name="getregularsize"></a>  CMFCRibbonProgressBar::GetRegularSize  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual CSize GetRegularSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isinfinitemode"></a>  CMFCRibbonProgressBar::IsInfiniteMode  
 Especifica se a barra de progresso está funcionando no modo de infinito.  
  
```  
BOOL IsInfiniteMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se a barra de progresso está no modo de infinito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 No modo de infinito, a barra de progresso é preenchido repetidamente do valor mínimo para o valor máximo. Você pode usar o modo de infinito para indicar que uma operação está em andamento, mas que o tempo de conclusão é desconhecido.  
  
##  <a name="ondraw"></a>  CMFCRibbonProgressBar::OnDraw  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setinfinitemode"></a>  CMFCRibbonProgressBar::SetInfiniteMode  
 Define a barra de progresso para funcionar no modo de infinito.  
  
```  
void SetInfiniteMode(BOOL bSet = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSet`  
 `TRUE` para especificar que a barra de progresso é no modo de infinito. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Geralmente, se a barra de progresso está no modo de infinito, o usuário está informando que uma operação está em andamento, mas que o tempo de conclusão é desconhecido. Portanto, a barra de progresso preenche repetidamente do valor mínimo para o valor máximo.  
  
##  <a name="setpos"></a>  CMFCRibbonProgressBar::SetPos  
 Define a posição atual da barra de progresso.  
  
```  
void SetPos(
    int nPos,  
    BOOL bRedraw = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nPos`  
 Especifica a posição em que a barra de progresso é definida.  
  
 [in] `bRedraw`  
 Especifica se a barra de progresso deve ser redesenhada.  
  
### <a name="remarks"></a>Comentários  
 O intervalo que está sendo definido deve estar dentro do intervalo especificado pelo [CMFCRibbonProgressBar::SetRange](#setrange) método.  
  
##  <a name="setrange"></a>  CMFCRibbonProgressBar::SetRange  
 Define os valores mínimos e máximo para a barra de progresso.  
  
```  
void SetRange(
    int nMin,  
    int nMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nMin`  
 Especifica o valor mínimo do intervalo.  
  
 [in] `nMax`  
 Especifica o valor máximo do intervalo.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para definir o intervalo da barra de progresso, definindo os valores mínimo e máximo.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)   
 [Classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)
