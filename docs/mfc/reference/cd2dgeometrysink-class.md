---
title: Classe CD2DGeometrySink | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DGeometrySink
- AFXRENDERTARGET/CD2DGeometrySink
- AFXRENDERTARGET/CD2DGeometrySink::CD2DGeometrySink
- AFXRENDERTARGET/CD2DGeometrySink::AddArc
- AFXRENDERTARGET/CD2DGeometrySink::AddBezier
- AFXRENDERTARGET/CD2DGeometrySink::AddBeziers
- AFXRENDERTARGET/CD2DGeometrySink::AddLine
- AFXRENDERTARGET/CD2DGeometrySink::AddLines
- AFXRENDERTARGET/CD2DGeometrySink::AddQuadraticBezier
- AFXRENDERTARGET/CD2DGeometrySink::AddQuadraticBeziers
- AFXRENDERTARGET/CD2DGeometrySink::BeginFigure
- AFXRENDERTARGET/CD2DGeometrySink::Close
- AFXRENDERTARGET/CD2DGeometrySink::EndFigure
- AFXRENDERTARGET/CD2DGeometrySink::Get
- AFXRENDERTARGET/CD2DGeometrySink::IsValid
- AFXRENDERTARGET/CD2DGeometrySink::SetFillMode
- AFXRENDERTARGET/CD2DGeometrySink::SetSegmentFlags
- AFXRENDERTARGET/CD2DGeometrySink::m_pSink
dev_langs:
- C++
helpviewer_keywords:
- CD2DGeometrySink class
ms.assetid: e5e07f41-0343-4ab1-9d6b-8c62ed33c04a
caps.latest.revision: 17
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
ms.openlocfilehash: 8a51d9475437ae460340d419a88bc46effa81f5f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cd2dgeometrysink-class"></a>Classe CD2DGeometrySink
Um wrapper para ID2D1GeometrySink.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DGeometrySink;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DGeometrySink::CD2DGeometrySink](#cd2dgeometrysink)|Constrói um objeto CD2DGeometrySink do objeto CD2DPathGeometry.|  
|[CD2DGeometrySink:: ~ CD2DGeometrySink](#_dtorcd2dgeometrysink)|O destruidor. Chamado quando um objeto de coletor de geometry D2D está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DGeometrySink::AddArc](#addarc)|Adiciona um arco único para o caminho da geometria|  
|[CD2DGeometrySink::AddBezier](#addbezier)|Cria uma curva de Bézier cúbica entre o ponto atual e o ponto final especificado.|  
|[CD2DGeometrySink::AddBeziers](#addbeziers)|Cria uma sequência de curvas de Bézier cúbicas e os adiciona ao coletor de geometria.|  
|[CD2DGeometrySink::AddLine](#addline)|Cria um segmento de linha entre o ponto atual e o ponto de extremidade especificado e o adiciona ao coletor de geometria.|  
|[CD2DGeometrySink::AddLines](#addlines)|Cria uma sequência de linhas usando pontos especificados e os adiciona ao coletor de geometria.|  
|[CD2DGeometrySink::AddQuadraticBezier](#addquadraticbezier)|Cria uma curva de Bezier quadrática entre o ponto atual e o ponto final especificado.|  
|[CD2DGeometrySink::AddQuadraticBeziers](#addquadraticbeziers)|Adiciona uma sequência de segmentos de Bezier quadráticas como uma matriz em uma única chamada.|  
|[CD2DGeometrySink::BeginFigure](#beginfigure)|Inicia uma nova figura no ponto especificado.|  
|[CD2DGeometrySink::Close](#close)|Fecha o coletor de geometria|  
|[CD2DGeometrySink::EndFigure](#endfigure)|Termina a figura atual; Opcionalmente, ele fecha.|  
|[CD2DGeometrySink::Get](#get)|Interface de ID2D1GeometrySink retorna|  
|[CD2DGeometrySink::IsValid](#isvalid)|Verifica a validade do coletor de geometria|  
|[CD2DGeometrySink::SetFillMode](#setfillmode)|Especifica o método usado para determinar quais pontos estão dentro da geometria descrita por esse coletor de geometria e quais pontos estão fora.|  
|[CD2DGeometrySink::SetSegmentFlags](#setsegmentflags)|Especifica as opções de borda e associação a ser aplicado a novos segmentos adicionados ao coletor de geometria.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DGeometrySink::Operator ID2D1GeometrySink *](#operator_id2d1geometrysink_star)|Interface de ID2D1GeometrySink retorna|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DGeometrySink::m_pSink](#m_psink)|Um ponteiro para um ID2D1GeometrySink.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CD2DGeometrySink`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="_dtorcd2dgeometrysink"></a>CD2DGeometrySink:: ~ CD2DGeometrySink  
 O destruidor. Chamado quando um objeto de coletor de geometry D2D está sendo destruído.  
  
```  
virtual ~CD2DGeometrySink();
```  
  
##  <a name="addarc"></a>CD2DGeometrySink::AddArc  
 Adiciona um arco único para o caminho da geometria  
  
```  
void AddArc(const D2D1_ARC_SEGMENT& arc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `arc`  
 O segmento de arco para adicionar a Figura  
  
##  <a name="addbezier"></a>CD2DGeometrySink::AddBezier  
 Cria uma curva de Bézier cúbica entre o ponto atual e o ponto final especificado.  
  
```  
void AddBezier(const D2D1_BEZIER_SEGMENT& bezier);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bezier`  
 Uma estrutura que descreve os pontos de controle e o ponto final da curva de Bezier para adicionar.  
  
##  <a name="addbeziers"></a>CD2DGeometrySink::AddBeziers  
 Cria uma sequência de curvas de Bézier cúbicas e os adiciona ao coletor de geometria.  
  
```  
void AddBeziers(
    const CArray<D2D1_BEZIER_SEGMENT,  
    D2D1_BEZIER_SEGMENT>& beziers);
```  
  
### <a name="parameters"></a>Parâmetros  
 `beziers`  
 Uma matriz de segmentos de Bézier que descreve as curvas de Bezier para criar. A curva é desenhada do ponto atual do coletor de geometria (o ponto de extremidade do último segmento desenhado ou o local especificado por BeginFigure) para o ponto de extremidade do segmento de Bézier primeiro na matriz. Se a matriz contém segmentos de Bezier adicionais, cada segmento de Bézier subsequente usa o ponto de extremidade do segmento de Bézier anterior como seu ponto inicial.  
  
##  <a name="addline"></a>CD2DGeometrySink::AddLine  
 Cria um segmento de linha entre o ponto atual e o ponto de extremidade especificado e o adiciona ao coletor de geometria.  
  
```  
void AddLine(CD2DPointF point);
```  
  
### <a name="parameters"></a>Parâmetros  
 `point`  
 O ponto de extremidade da linha para desenhar.  
  
##  <a name="addlines"></a>CD2DGeometrySink::AddLines  
 Cria uma sequência de linhas usando pontos especificados e os adiciona ao coletor de geometria.  
  
```  
void AddLines(
    const CArray<CD2DPointF,  
    CD2DPointF>& points);
```  
  
### <a name="parameters"></a>Parâmetros  
 `points`  
 Uma matriz de um ou mais pontos que descrevem as linhas para desenhar. Uma linha é desenhada do ponto atual do coletor de geometria (o ponto de extremidade do último segmento desenhado ou o local especificado por BeginFigure) até o primeiro ponto na matriz. Se a matriz contém pontos adicionais, uma linha é desenhada do primeiro ponto até o segundo ponto na matriz, do segundo ponto para o terceiro ponto e assim por diante. Uma matriz de uma sequência de pontos de extremidade para desenhar as linhas.  
  
##  <a name="addquadraticbezier"></a>CD2DGeometrySink::AddQuadraticBezier  
 Cria uma curva de Bezier quadrática entre o ponto atual e o ponto final especificado.  
  
```  
void AddQuadraticBezier(const D2D1_QUADRATIC_BEZIER_SEGMENT& bezier);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bezier`  
 Uma estrutura que descreve o ponto de controle e o ponto final da curva de Bezier quadrática para adicionar.  
  
##  <a name="addquadraticbeziers"></a>CD2DGeometrySink::AddQuadraticBeziers  
 Adiciona uma sequência de segmentos de Bezier quadráticas como uma matriz em uma única chamada.  
  
```  
void AddQuadraticBeziers(
    const CArray<D2D1_QUADRATIC_BEZIER_SEGMENT,  
    D2D1_QUADRATIC_BEZIER_SEGMENT>& beziers);
```  
  
### <a name="parameters"></a>Parâmetros  
 `beziers`  
 Uma matriz de uma sequência de segmentos de Bezier quadráticas.  
  
##  <a name="beginfigure"></a>CD2DGeometrySink::BeginFigure  
 Inicia uma nova figura no ponto especificado.  
  
```  
void BeginFigure(
    CD2DPointF startPoint,  
    D2D1_FIGURE_BEGIN figureBegin);
```  
  
### <a name="parameters"></a>Parâmetros  
 `startPoint`  
 O ponto no qual começar a nova figura.  
  
 `figureBegin`  
 Se a nova figura deve ser preenchidos ou vazios.  
  
##  <a name="cd2dgeometrysink"></a>CD2DGeometrySink::CD2DGeometrySink  
 Constrói um objeto CD2DGeometrySink do objeto CD2DPathGeometry.  
  
```  
CD2DGeometrySink(CD2DPathGeometry& pathGeometry);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pathGeometry`  
 Um objeto CD2DPathGeometry existente.  
  
##  <a name="close"></a>CD2DGeometrySink::Close  
 Fecha o coletor de geometria  
  
```  
BOOL Close();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, FALSE.  
  
##  <a name="endfigure"></a>CD2DGeometrySink::EndFigure  
 Termina a figura atual; Opcionalmente, ele fecha.  
  
```  
void EndFigure(D2D1_FIGURE_END figureEnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `figureEnd`  
 Um valor que indica se a figura atual é fechada. Se a figura for fechada, uma linha é desenhada entre o ponto atual e o ponto de início especificado por BeginFigure.  
  
##  <a name="get"></a>CD2DGeometrySink::Get  
 Interface de ID2D1GeometrySink retorna  
  
```  
ID2D1GeometrySink* Get();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1GeometrySink ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="isvalid"></a>CD2DGeometrySink::IsValid  
 Verifica a validade do coletor de geometria  
  
```  
BOOL IsValid() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o coletor de geometry é válido. Caso contrário, FALSE.  
  
##  <a name="m_psink"></a>CD2DGeometrySink::m_pSink  
 Um ponteiro para um ID2D1GeometrySink.  
  
```  
ID2D1GeometrySink* m_pSink;  
```  
  
##  <a name="operator_id2d1geometrysink_star"></a>CD2DGeometrySink::Operator ID2D1GeometrySink *  
 Interface de ID2D1GeometrySink retorna  
  
```  
operator ID2D1GeometrySink*();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1GeometrySink ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="setfillmode"></a>CD2DGeometrySink::SetFillMode  
 Especifica o método usado para determinar quais pontos estão dentro da geometria descrita por esse coletor de geometria e quais pontos estão fora.  
  
```  
void SetFillMode(D2D1_FILL_MODE fillMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `fillMode`  
 O método usado para determinar se um determinado ponto é parte de geometria.  
  
##  <a name="setsegmentflags"></a>CD2DGeometrySink::SetSegmentFlags  
 Especifica as opções de borda e associação a ser aplicado a novos segmentos adicionados ao coletor de geometria.  
  
```  
void SetSegmentFlags(D2D1_PATH_SEGMENT vertexFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `vertexFlags`  
 Opções de borda e associação a ser aplicado a novos segmentos adicionados ao coletor de geometria.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

