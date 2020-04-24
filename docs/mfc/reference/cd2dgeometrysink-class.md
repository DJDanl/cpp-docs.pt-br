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
ms.openlocfilehash: bb5d2b53fa5899ac84608dc4ace6a84a3e5a7575
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754771"
---
# <a name="cd2dgeometrysink-class"></a>Classe CD2DGeometrySink

Um invólucro para ID2D1GeometrySink.

## <a name="syntax"></a>Sintaxe

```
class CD2DGeometrySink;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGeometrySink::CD2DGeometrySink](#cd2dgeometrysink)|Constrói um objeto CD2DGeometrySink a partir do objeto CD2DPathGeometry.|
|[CD2DGeometrySink::~CD2DGeometrySink](#_dtorcd2dgeometrysink)|O destruidor. Chamado quando um objeto da pia de geometria D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGeometrySink::AddArc](#addarc)|Adiciona um único arco à geometria do caminho|
|[CD2DGeometrySink::AddBezier](#addbezier)|Cria uma curva de Bézier cúbica entre o ponto atual e o ponto final especificado.|
|[CD2DGeometrySink::AddBeziers](#addbeziers)|Cria uma seqüência de curvas cubas de Bezier e as adiciona à pia de geometria.|
|[CD2DGeometrySink::AddLine](#addline)|Cria um segmento de linha entre o ponto atual e o ponto final especificado e adiciona-o à pia de geometria.|
|[CD2DGeometrySink::AddLines](#addlines)|Cria uma seqüência de linhas usando os pontos especificados e adiciona-os ao dissipador de geometria.|
|[CD2DGeometrySink::AddQuadraticBezier](#addquadraticbezier)|Cria uma curva de Bezier quadrática entre o ponto atual e o ponto final especificado.|
|[CD2DGeometrySink::AddQuadraticBeziers](#addquadraticbeziers)|Adiciona uma seqüência de segmentos quadráticos de Bezier como uma matriz em uma única chamada.|
|[CD2DGeometrySink::BeginFigure](#beginfigure)|Inicia uma nova figura no ponto especificado.|
|[CD2DGeometrySink::Fechar](#close)|Fecha a pia de geometria|
|[CD2DGeometrySink::EndFigure](#endfigure)|Termina a figura atual; opcionalmente, fecha.|
|[CD2DGeometrySink::Get](#get)|Retorna interface ID2D1GeometrySink|
|[CD2DGeometrySink::IsValid](#isvalid)|Verifica a validade da pia de geometria|
|[CD2DGeometrySink::SetFillMode](#setfillmode)|Especifica o método usado para determinar quais pontos estão dentro da geometria descrita por esta pia de geometria e quais pontos estão fora.|
|[CD2DGeometrySink::SetSegmentFlags](#setsegmentflags)|Especifica o traçado e as opções de adesão a serem aplicadas a novos segmentos adicionados ao dissipador de geometria.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGeometrySink:operador ID2D1GeometrySink*](#operator_id2d1geometrysink_star)|Retorna interface ID2D1GeometrySink|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGeometrySink::m_pSink](#m_psink)|Um ponteiro para um ID2D1GeometrySink.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CD2DGeometrySink`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dgeometrysinkcd2dgeometrysink"></a><a name="_dtorcd2dgeometrysink"></a>CD2DGeometrySink::~CD2DGeometrySink

O destruidor. Chamado quando um objeto da pia de geometria D2D está sendo destruído.

```
virtual ~CD2DGeometrySink();
```

## <a name="cd2dgeometrysinkaddarc"></a><a name="addarc"></a>CD2DGeometrySink::AddArc

Adiciona um único arco à geometria do caminho

```cpp
void AddArc(const D2D1_ARC_SEGMENT& arc);
```

### <a name="parameters"></a>Parâmetros

*Arco*<br/>
O segmento de arco para adicionar à figura

## <a name="cd2dgeometrysinkaddbezier"></a><a name="addbezier"></a>CD2DGeometrySink::AddBezier

Cria uma curva de Bézier cúbica entre o ponto atual e o ponto final especificado.

```cpp
void AddBezier(const D2D1_BEZIER_SEGMENT& bezier);
```

### <a name="parameters"></a>Parâmetros

*Bézier*<br/>
Uma estrutura que descreve os pontos de controle e o ponto final da curva de Bezier para adicionar.

## <a name="cd2dgeometrysinkaddbeziers"></a><a name="addbeziers"></a>CD2DGeometrySink::AddBeziers

Cria uma seqüência de curvas cubas de Bezier e as adiciona à pia de geometria.

```cpp
void AddBeziers(
    const CArray<D2D1_BEZIER_SEGMENT,
    D2D1_BEZIER_SEGMENT>& beziers);
```

### <a name="parameters"></a>Parâmetros

*Beziers*<br/>
Uma matriz de segmentos de Bezier que descreve as curvas de Bezier para criar. Uma curva é desenhada do ponto atual da pia de geometria (o ponto final do último segmento desenhado ou o local especificado por BeginFigure) até o ponto final do primeiro segmento bezier na matriz. se a matriz contiver segmentos adicionais de Bezier, cada segmento bezier subseqüente usará o ponto final do segmento Bezier anterior como ponto de partida.

## <a name="cd2dgeometrysinkaddline"></a><a name="addline"></a>CD2DGeometrySink::AddLine

Cria um segmento de linha entre o ponto atual e o ponto final especificado e adiciona-o à pia de geometria.

```cpp
void AddLine(CD2DPointF point);
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
O ponto final da linha para desenhar.

## <a name="cd2dgeometrysinkaddlines"></a><a name="addlines"></a>CD2DGeometrySink::AddLines

Cria uma seqüência de linhas usando os pontos especificados e adiciona-os ao dissipador de geometria.

```cpp
void AddLines(
    const CArray<CD2DPointF,
    CD2DPointF>& points);
```

### <a name="parameters"></a>Parâmetros

*Pontos*<br/>
Uma matriz de um ou mais pontos que descrevem as linhas a desenhar. Uma linha é desenhada do ponto atual da pia de geometria (o ponto final do último segmento desenhado ou o local especificado por BeginFigure) até o primeiro ponto da matriz. se a matriz contém pontos adicionais, uma linha é desenhada do primeiro ponto para o segundo ponto na matriz, do segundo ponto ao terceiro ponto, e assim por diante. Uma matriz de uma seqüência dos pontos finais das linhas para desenhar.

## <a name="cd2dgeometrysinkaddquadraticbezier"></a><a name="addquadraticbezier"></a>CD2DGeometrySink::AddQuadraticBezier

Cria uma curva de Bezier quadrática entre o ponto atual e o ponto final especificado.

```cpp
void AddQuadraticBezier(const D2D1_QUADRATIC_BEZIER_SEGMENT& bezier);
```

### <a name="parameters"></a>Parâmetros

*Bézier*<br/>
Uma estrutura que descreve o ponto de controle e o ponto final da curva quadrática de Bezier para adicionar.

## <a name="cd2dgeometrysinkaddquadraticbeziers"></a><a name="addquadraticbeziers"></a>CD2DGeometrySink::AddQuadraticBeziers

Adiciona uma seqüência de segmentos quadráticos de Bezier como uma matriz em uma única chamada.

```cpp
void AddQuadraticBeziers(
    const CArray<D2D1_QUADRATIC_BEZIER_SEGMENT,
    D2D1_QUADRATIC_BEZIER_SEGMENT>& beziers);
```

### <a name="parameters"></a>Parâmetros

*Beziers*<br/>
Uma matriz de uma seqüência de segmentos quadráticos de Bezier.

## <a name="cd2dgeometrysinkbeginfigure"></a><a name="beginfigure"></a>CD2DGeometrySink::BeginFigure

Inicia uma nova figura no ponto especificado.

```cpp
void BeginFigure(
    CD2DPointF startPoint,
    D2D1_FIGURE_BEGIN figureBegin);
```

### <a name="parameters"></a>Parâmetros

*startPoint*<br/>
O ponto em que começar a nova figura.

*figureBegin*<br/>
Se a nova figura deve ser oca ou preenchida.

## <a name="cd2dgeometrysinkcd2dgeometrysink"></a><a name="cd2dgeometrysink"></a>CD2DGeometrySink::CD2DGeometrySink

Constrói um objeto CD2DGeometrySink a partir do objeto CD2DPathGeometry.

```
CD2DGeometrySink(CD2DPathGeometry& pathGeometry);
```

### <a name="parameters"></a>Parâmetros

*Pathgeometry*<br/>
Um objeto CD2DPathGeometry existente.

## <a name="cd2dgeometrysinkclose"></a><a name="close"></a>CD2DGeometrySink::Fechar

Fecha a pia de geometria

```
BOOL Close();
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, FALSO.

## <a name="cd2dgeometrysinkendfigure"></a><a name="endfigure"></a>CD2DGeometrySink::EndFigure

Termina a figura atual; opcionalmente, fecha.

```cpp
void EndFigure(D2D1_FIGURE_END figureEnd);
```

### <a name="parameters"></a>Parâmetros

*figureEnd*<br/>
Um valor que indica se a figura atual está fechada. Se a figura estiver fechada, uma linha será traçada entre o ponto atual e o ponto de partida especificado por BeginFigure.

## <a name="cd2dgeometrysinkget"></a><a name="get"></a>CD2DGeometrySink::Get

Retorna interface ID2D1GeometrySink

```
ID2D1GeometrySink* Get();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1GeometrySink ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dgeometrysinkisvalid"></a><a name="isvalid"></a>CD2DGeometrySink::IsValid

Verifica a validade da pia de geometria

```
BOOL IsValid() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se a pia de geometria for válida; caso contrário, FALSO.

## <a name="cd2dgeometrysinkm_psink"></a><a name="m_psink"></a>CD2DGeometrySink::m_pSink

Um ponteiro para um ID2D1GeometrySink.

```
ID2D1GeometrySink* m_pSink;
```

## <a name="cd2dgeometrysinkoperator-id2d1geometrysink"></a><a name="operator_id2d1geometrysink_star"></a>CD2DGeometrySink:operador ID2D1GeometrySink*

Retorna interface ID2D1GeometrySink

```
operator ID2D1GeometrySink*();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1GeometrySink ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dgeometrysinksetfillmode"></a><a name="setfillmode"></a>CD2DGeometrySink::SetFillMode

Especifica o método usado para determinar quais pontos estão dentro da geometria descrita por esta pia de geometria e quais pontos estão fora.

```cpp
void SetFillMode(D2D1_FILL_MODE fillMode);
```

### <a name="parameters"></a>Parâmetros

*Fillmode*<br/>
O método usado para determinar se um determinado ponto faz parte da geometria.

## <a name="cd2dgeometrysinksetsegmentflags"></a><a name="setsegmentflags"></a>CD2DGeometrySink::SetSegmentFlags

Especifica o traçado e as opções de adesão a serem aplicadas a novos segmentos adicionados ao dissipador de geometria.

```cpp
void SetSegmentFlags(D2D1_PATH_SEGMENT vertexFlags);
```

### <a name="parameters"></a>Parâmetros

*vertexFlags*<br/>
Traçado e junte opções a serem aplicadas a novos segmentos adicionados ao dissipador de geometria.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
