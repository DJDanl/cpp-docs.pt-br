---
title: Classe CD2DGeometrySink
ms.date: 11/04/2016
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
helpviewer_keywords:
- CD2DGeometrySink [MFC], CD2DGeometrySink
- CD2DGeometrySink [MFC], AddArc
- CD2DGeometrySink [MFC], AddBezier
- CD2DGeometrySink [MFC], AddBeziers
- CD2DGeometrySink [MFC], AddLine
- CD2DGeometrySink [MFC], AddLines
- CD2DGeometrySink [MFC], AddQuadraticBezier
- CD2DGeometrySink [MFC], AddQuadraticBeziers
- CD2DGeometrySink [MFC], BeginFigure
- CD2DGeometrySink [MFC], Close
- CD2DGeometrySink [MFC], EndFigure
- CD2DGeometrySink [MFC], Get
- CD2DGeometrySink [MFC], IsValid
- CD2DGeometrySink [MFC], SetFillMode
- CD2DGeometrySink [MFC], SetSegmentFlags
- CD2DGeometrySink [MFC], m_pSink
ms.assetid: e5e07f41-0343-4ab1-9d6b-8c62ed33c04a
ms.openlocfilehash: ff68cc737f28763e5545b0ccaf2c0122e78cb051
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50654658"
---
# <a name="cd2dgeometrysink-class"></a>Classe CD2DGeometrySink

Um wrapper para ID2D1GeometrySink.

## <a name="syntax"></a>Sintaxe

```
class CD2DGeometrySink;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGeometrySink::CD2DGeometrySink](#cd2dgeometrysink)|Constrói um objeto CD2DGeometrySink CD2DPathGeometry objeto.|
|[CD2DGeometrySink:: ~ CD2DGeometrySink](#_dtorcd2dgeometrysink)|O destruidor. Chamado quando um objeto de coletor de geometry D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGeometrySink::AddArc](#addarc)|Adiciona um único arco a geometria de caminho|
|[CD2DGeometrySink::AddBezier](#addbezier)|Cria uma curva de Bézier cúbica entre o ponto atual e o ponto final especificado.|
|[CD2DGeometrySink::AddBeziers](#addbeziers)|Cria uma sequência de curvas de Bézier cúbicas e os adiciona ao coletor de geometria.|
|[CD2DGeometrySink::AddLine](#addline)|Cria um segmento de linha entre o ponto atual e o ponto de extremidade especificado e adiciona-o para o coletor de geometria.|
|[CD2DGeometrySink::AddLines](#addlines)|Cria uma sequência de linhas usando os pontos especificados e os adiciona ao coletor de geometria.|
|[CD2DGeometrySink::AddQuadraticBezier](#addquadraticbezier)|Cria uma curva de Bezier quadrática entre o ponto atual e o ponto final especificado.|
|[CD2DGeometrySink::AddQuadraticBeziers](#addquadraticbeziers)|Adiciona uma sequência de segmentos de Bézier quadráticas como uma matriz em uma única chamada.|
|[CD2DGeometrySink::BeginFigure](#beginfigure)|Inicia uma nova figura no ponto especificado.|
|[CD2DGeometrySink::Close](#close)|Fecha o coletor de geometria|
|[CD2DGeometrySink::EndFigure](#endfigure)|Termina a figura atual; Opcionalmente, ele fecha.|
|[CD2DGeometrySink::Get](#get)|Interface de ID2D1GeometrySink retorna|
|[CD2DGeometrySink::IsValid](#isvalid)|Verifica a validade do coletor de geometria|
|[CD2DGeometrySink::SetFillMode](#setfillmode)|Especifica o método usado para determinar quais pontos estão dentro da geometria descrita por esse coletor de geometria e quais pontos estão fora.|
|[CD2DGeometrySink::SetSegmentFlags](#setsegmentflags)|Especifica as opções de borda e associação a ser aplicado a novos segmentos adicionados para o coletor de geometria.|

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

##  <a name="_dtorcd2dgeometrysink"></a>  CD2DGeometrySink:: ~ CD2DGeometrySink

O destruidor. Chamado quando um objeto de coletor de geometry D2D está sendo destruído.

```
virtual ~CD2DGeometrySink();
```

##  <a name="addarc"></a>  CD2DGeometrySink::AddArc

Adiciona um único arco a geometria de caminho

```
void AddArc(const D2D1_ARC_SEGMENT& arc);
```

### <a name="parameters"></a>Parâmetros

*Arco*<br/>
O segmento de arco para adicionar à Figura

##  <a name="addbezier"></a>  CD2DGeometrySink::AddBezier

Cria uma curva de Bézier cúbica entre o ponto atual e o ponto final especificado.

```
void AddBezier(const D2D1_BEZIER_SEGMENT& bezier);
```

### <a name="parameters"></a>Parâmetros

*Bézier*<br/>
Uma estrutura que descreve os pontos de controle e o ponto de extremidade da curva de Bézier para adicionar.

##  <a name="addbeziers"></a>  CD2DGeometrySink::AddBeziers

Cria uma sequência de curvas de Bézier cúbicas e os adiciona ao coletor de geometria.

```
void AddBeziers(
    const CArray<D2D1_BEZIER_SEGMENT,
    D2D1_BEZIER_SEGMENT>& beziers);
```

### <a name="parameters"></a>Parâmetros

*Bézier*<br/>
Uma matriz de segmentos de Bézier que descreve as curvas de Bézier para criar. A curva é desenhada do ponto do coletor geometria atual (o ponto de extremidade do último segmento desenhado ou o local especificado pelo BeginFigure) para o ponto de extremidade do segmento de Bézier primeiro na matriz. Se a matriz contém os segmentos de Bézier adicionais, cada segmento de Bézier subsequente usa o ponto de extremidade do segmento de Bézier anterior como seu ponto de início.

##  <a name="addline"></a>  CD2DGeometrySink::AddLine

Cria um segmento de linha entre o ponto atual e o ponto de extremidade especificado e adiciona-o para o coletor de geometria.

```
void AddLine(CD2DPointF point);
```

### <a name="parameters"></a>Parâmetros

*ponto*<br/>
O ponto de extremidade da linha para desenhar.

##  <a name="addlines"></a>  CD2DGeometrySink::AddLines

Cria uma sequência de linhas usando os pontos especificados e os adiciona ao coletor de geometria.

```
void AddLines(
    const CArray<CD2DPointF,
    CD2DPointF>& points);
```

### <a name="parameters"></a>Parâmetros

*Pontos*<br/>
Uma matriz de um ou mais pontos que descrevem as linhas para desenhar. Uma linha é desenhada do ponto do coletor geometria atual (o ponto de extremidade do último segmento desenhado ou o local especificado pelo BeginFigure) até o primeiro ponto na matriz. Se a matriz contiver pontos adicionais, uma linha é desenhada no primeiro ponto até o segundo ponto na matriz, partir do segundo ponto para o terceiro ponto e assim por diante. Uma matriz de uma sequência de pontos de extremidade para desenhar as linhas.

##  <a name="addquadraticbezier"></a>  CD2DGeometrySink::AddQuadraticBezier

Cria uma curva de Bezier quadrática entre o ponto atual e o ponto final especificado.

```
void AddQuadraticBezier(const D2D1_QUADRATIC_BEZIER_SEGMENT& bezier);
```

### <a name="parameters"></a>Parâmetros

*Bézier*<br/>
Uma estrutura que descreve o ponto de controle e o ponto de extremidade da curva de Bézier quadrática para adicionar.

##  <a name="addquadraticbeziers"></a>  CD2DGeometrySink::AddQuadraticBeziers

Adiciona uma sequência de segmentos de Bézier quadráticas como uma matriz em uma única chamada.

```
void AddQuadraticBeziers(
    const CArray<D2D1_QUADRATIC_BEZIER_SEGMENT,
    D2D1_QUADRATIC_BEZIER_SEGMENT>& beziers);
```

### <a name="parameters"></a>Parâmetros

*Bézier*<br/>
Uma matriz de uma sequência de segmentos de Bézier quadráticas.

##  <a name="beginfigure"></a>  CD2DGeometrySink::BeginFigure

Inicia uma nova figura no ponto especificado.

```
void BeginFigure(
    CD2DPointF startPoint,
    D2D1_FIGURE_BEGIN figureBegin);
```

### <a name="parameters"></a>Parâmetros

*startPoint*<br/>
O ponto no qual começar a nova figura.

*figureBegin*<br/>
Se a nova figura deve ser vazio ou preenchido.

##  <a name="cd2dgeometrysink"></a>  CD2DGeometrySink::CD2DGeometrySink

Constrói um objeto CD2DGeometrySink CD2DPathGeometry objeto.

```
CD2DGeometrySink(CD2DPathGeometry& pathGeometry);
```

### <a name="parameters"></a>Parâmetros

*pathGeometry*<br/>
Um objeto CD2DPathGeometry existente.

##  <a name="close"></a>  CD2DGeometrySink::Close

Fecha o coletor de geometria

```
BOOL Close();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, FALSE.

##  <a name="endfigure"></a>  CD2DGeometrySink::EndFigure

Termina a figura atual; Opcionalmente, ele fecha.

```
void EndFigure(D2D1_FIGURE_END figureEnd);
```

### <a name="parameters"></a>Parâmetros

*figureEnd*<br/>
Um valor que indica se a figura atual está fechada. Se a figura for fechada, uma linha é desenhada entre o ponto atual e o ponto inicial especificado pelo BeginFigure.

##  <a name="get"></a>  CD2DGeometrySink::Get

Interface de ID2D1GeometrySink retorna

```
ID2D1GeometrySink* Get();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma interface ID2D1GeometrySink ou NULL se o objeto ainda não foi inicializado.

##  <a name="isvalid"></a>  CD2DGeometrySink::IsValid

Verifica a validade do coletor de geometria

```
BOOL IsValid() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o coletor de geometria é válido. Caso contrário, FALSE.

##  <a name="m_psink"></a>  CD2DGeometrySink::m_pSink

Um ponteiro para um ID2D1GeometrySink.

```
ID2D1GeometrySink* m_pSink;
```

##  <a name="operator_id2d1geometrysink_star"></a>  CD2DGeometrySink::Operator ID2D1GeometrySink *

Interface de ID2D1GeometrySink retorna

```
operator ID2D1GeometrySink*();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma interface ID2D1GeometrySink ou NULL se o objeto ainda não foi inicializado.

##  <a name="setfillmode"></a>  CD2DGeometrySink::SetFillMode

Especifica o método usado para determinar quais pontos estão dentro da geometria descrita por esse coletor de geometria e quais pontos estão fora.

```
void SetFillMode(D2D1_FILL_MODE fillMode);
```

### <a name="parameters"></a>Parâmetros

*fillMode*<br/>
O método usado para determinar se um determinado ponto é parte da geometria.

##  <a name="setsegmentflags"></a>  CD2DGeometrySink::SetSegmentFlags

Especifica as opções de borda e associação a ser aplicado a novos segmentos adicionados para o coletor de geometria.

```
void SetSegmentFlags(D2D1_PATH_SEGMENT vertexFlags);
```

### <a name="parameters"></a>Parâmetros

*vertexFlags*<br/>
Opções de borda e a associação a ser aplicado a novos segmentos adicionados para o coletor de geometria.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
