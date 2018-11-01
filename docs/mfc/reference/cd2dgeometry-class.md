---
title: Classe CD2DGeometry
ms.date: 11/04/2016
f1_keywords:
- CD2DGeometry
- AFXRENDERTARGET/CD2DGeometry
- AFXRENDERTARGET/CD2DGeometry::CD2DGeometry
- AFXRENDERTARGET/CD2DGeometry::Attach
- AFXRENDERTARGET/CD2DGeometry::CombineWithGeometry
- AFXRENDERTARGET/CD2DGeometry::CompareWithGeometry
- AFXRENDERTARGET/CD2DGeometry::ComputeArea
- AFXRENDERTARGET/CD2DGeometry::ComputeLength
- AFXRENDERTARGET/CD2DGeometry::ComputePointAtLength
- AFXRENDERTARGET/CD2DGeometry::Destroy
- AFXRENDERTARGET/CD2DGeometry::Detach
- AFXRENDERTARGET/CD2DGeometry::FillContainsPoint
- AFXRENDERTARGET/CD2DGeometry::Get
- AFXRENDERTARGET/CD2DGeometry::GetBounds
- AFXRENDERTARGET/CD2DGeometry::GetWidenedBounds
- AFXRENDERTARGET/CD2DGeometry::IsValid
- AFXRENDERTARGET/CD2DGeometry::Outline
- AFXRENDERTARGET/CD2DGeometry::Simplify
- AFXRENDERTARGET/CD2DGeometry::StrokeContainsPoint
- AFXRENDERTARGET/CD2DGeometry::Tessellate
- AFXRENDERTARGET/CD2DGeometry::Widen
- AFXRENDERTARGET/CD2DGeometry::m_pGeometry
helpviewer_keywords:
- CD2DGeometry [MFC], CD2DGeometry
- CD2DGeometry [MFC], Attach
- CD2DGeometry [MFC], CombineWithGeometry
- CD2DGeometry [MFC], CompareWithGeometry
- CD2DGeometry [MFC], ComputeArea
- CD2DGeometry [MFC], ComputeLength
- CD2DGeometry [MFC], ComputePointAtLength
- CD2DGeometry [MFC], Destroy
- CD2DGeometry [MFC], Detach
- CD2DGeometry [MFC], FillContainsPoint
- CD2DGeometry [MFC], Get
- CD2DGeometry [MFC], GetBounds
- CD2DGeometry [MFC], GetWidenedBounds
- CD2DGeometry [MFC], IsValid
- CD2DGeometry [MFC], Outline
- CD2DGeometry [MFC], Simplify
- CD2DGeometry [MFC], StrokeContainsPoint
- CD2DGeometry [MFC], Tessellate
- CD2DGeometry [MFC], Widen
- CD2DGeometry [MFC], m_pGeometry
ms.assetid: 3f95054b-fdb8-4e87-87f2-9fc3df7279ec
ms.openlocfilehash: 929926129ddee0efdee4f1b02494b503755811d7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50610685"
---
# <a name="cd2dgeometry-class"></a>Classe CD2DGeometry

Um wrapper para ID2D1Geometry.

## <a name="syntax"></a>Sintaxe

```
class CD2DGeometry : public CD2DResource;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGeometry::CD2DGeometry](#cd2dgeometry)|Constrói um objeto CD2DGeometry.|
|[CD2DGeometry:: ~ CD2DGeometry](#_dtorcd2dgeometry)|O destruidor. Chamado quando um objeto de geometria D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGeometry::Attach](#attach)|Anexa existente de interface de recurso para o objeto|
|[CD2DGeometry::CombineWithGeometry](#combinewithgeometry)|Combina este geometria com a geometria especificada e armazena o resultado em um ID2D1SimplifiedGeometrySink.|
|[CD2DGeometry::CompareWithGeometry](#comparewithgeometry)|Descreve a interseção entre este geometria e a geometria especificada. A comparação é executada com a tolerância de mesclagem especificada.|
|[CD2DGeometry::ComputeArea](#computearea)|Calcula a área da geometria depois que ele foi transformado pela matriz especificada e mesclado com a tolerância especificada.|
|[CD2DGeometry::ComputeLength](#computelength)|Calcula o comprimento da geometria, como se fosse de cada segmento desenrolado em uma linha.|
|[CD2DGeometry::ComputePointAtLength](#computepointatlength)|Calcula o vetor de ponto e tangente à distância especificada ao longo da geometria depois que ele foi transformado pela matriz especificada e mesclado com a tolerância especificada.|
|[CD2DGeometry::Destroy](#destroy)|Destrói um objeto CD2DGeometry. (Substitui [CD2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|
|[CD2DGeometry::Detach](#detach)|Desanexa a interface do recurso do objeto|
|[CD2DGeometry::FillContainsPoint](#fillcontainspoint)|Indica se a área preenchida pela geometria contém o ponto especificado, dado a tolerância de mesclagem especificada.|
|[CD2DGeometry::Get](#get)|Interface do ID2D1Geometry retorna|
|[CD2DGeometry::GetBounds](#getbounds)||
|[CD2DGeometry::GetWidenedBounds](#getwidenedbounds)|Obtém os limites da geometria depois que ele foi ampliado pela largura do traço especificado e o estilo e transformado pela matriz especificada.|
|[CD2DGeometry::IsValid](#isvalid)|Verifica a validade de recurso (substitui [CD2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|
|[CD2DGeometry::Outline](#outline)|Calcula o contorno de geometry e grava o resultado em um ID2D1SimplifiedGeometrySink.|
|[CD2DGeometry::Simplify](#simplify)|Cria uma versão simplificada da geometria contém apenas linhas e curvas de Bézier cúbicas (opcionalmente) e grava o resultado em um ID2D1SimplifiedGeometrySink.|
|[CD2DGeometry::StrokeContainsPoint](#strokecontainspoint)|Determina se o traço da geometria contém o ponto especificado, dado a espessura do traço especificado, o estilo e a transformação.|
|[CD2DGeometry::Tessellate](#tessellate)|Cria um conjunto de triângulos abertos em sentido horário que abrangem a geometria depois que ele foi transformado pela matriz especificada e mesclado com a tolerância especificada.|
|[CD2DGeometry::Widen](#widen)|Amplia a geometria pelo traço especificado e grava o resultado em um ID2D1SimplifiedGeometrySink depois que ele foi transformado pela matriz especificada e mesclado com a tolerância especificada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGeometry::Operator ID2D1Geometry *](#operator_id2d1geometry_star)|Interface do ID2D1Geometry retorna|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGeometry::m_pGeometry](#m_pgeometry)|Um ponteiro para um ID2D1Geometry.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

`CD2DGeometry`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="_dtorcd2dgeometry"></a>  CD2DGeometry:: ~ CD2DGeometry

O destruidor. Chamado quando um objeto de geometria D2D está sendo destruído.

```
virtual ~CD2DGeometry();
```

##  <a name="attach"></a>  CD2DGeometry::Attach

Anexa existente de interface de recurso para o objeto

```
void Attach(ID2D1Geometry* pResource);
```

### <a name="parameters"></a>Parâmetros

*pResource*<br/>
Interface de recursos existente. Não pode ser NULL

##  <a name="cd2dgeometry"></a>  CD2DGeometry::CD2DGeometry

Constrói um objeto CD2DGeometry.

```
CD2DGeometry(
    CRenderTarget* pParentTarget,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o destino de renderização.

*bAutoDestroy*<br/>
Indica se o objeto será destruído pelo proprietário (pParentTarget).

##  <a name="combinewithgeometry"></a>  CD2DGeometry::CombineWithGeometry

Combina este geometria com a geometria especificada e armazena o resultado em um ID2D1SimplifiedGeometrySink.

```
BOOL CombineWithGeometry(
    CD2DGeometry& inputGeometry,
    D2D1_COMBINE_MODE combineMode,
    const D2D1_MATRIX_3X2_F& inputGeometryTransform,
    ID2D1SimplifiedGeometrySink* geometrySink,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*inputGeometry*<br/>
A geometria a combinar com essa instância.

*combineMode*<br/>
O tipo de operação de combinar para executar.

*inputGeometryTransform*<br/>
A transformação a aplicar ao inputGeometry antes da combinação.

*geometrySink*<br/>
O resultado da operação combinar.

*flatteningTolerance*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal das geometrias. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

##  <a name="comparewithgeometry"></a>  CD2DGeometry::CompareWithGeometry

Descreve a interseção entre este geometria e a geometria especificada. A comparação é executada com a tolerância de mesclagem especificada.

```
D2D1_GEOMETRY_RELATION CompareWithGeometry(
    CD2DGeometry& inputGeometry,
    const D2D1_MATRIX_3X2_F& inputGeometryTransform,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*inputGeometry*<br/>
A geometria de teste.

*inputGeometryTransform*<br/>
A transformação a aplicar ao inputGeometry.

*flatteningTolerance*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal das geometrias. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

##  <a name="computearea"></a>  CD2DGeometry::ComputeArea

Calcula a área da geometria depois que ele foi transformado pela matriz especificada e mesclado com a tolerância especificada.

```
BOOL ComputeArea(
    const D2D1_MATRIX_3X2_F& worldTransform,
    FLOAT& area,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*worldTransform*<br/>
A transformação para aplicar a esta geometria antes de computar sua área.

*Área*<br/>
Quando este método retorna, contém um ponteiro para a área da versão dessa geometria transformada, bidimensional. Você deve alocar armazenamento para esse parâmetro.

*flatteningTolerance*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal da geometria. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

##  <a name="computelength"></a>  CD2DGeometry::ComputeLength

Calcula o comprimento da geometria, como se fosse de cada segmento desenrolado em uma linha.

```
BOOL ComputeLength(
    const D2D1_MATRIX_3X2_F& worldTransform,
    FLOAT& length,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*worldTransform*<br/>
A transformação a ser aplicada à geometria antes de calcular seu comprimento.

*length*<br/>
Quando este método retorna, contém um ponteiro para o comprimento da geometria. Para geometrias fechadas, o comprimento inclui um segmento de fechamento implícita. Você deve alocar armazenamento para esse parâmetro.

*flatteningTolerance*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal da geometria. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

##  <a name="computepointatlength"></a>  CD2DGeometry::ComputePointAtLength

Calcula o vetor de ponto e tangente à distância especificada ao longo da geometria depois que ele foi transformado pela matriz especificada e mesclado com a tolerância especificada.

```
BOOL ComputePointAtLength(
    FLOAT length,
    const D2D1_MATRIX_3X2_F& worldTransform,
    CD2DPointF& point,
    CD2DPointF& unitTangentVector,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*length*<br/>
A distância ao longo da tangente para localizar e ponto de geometria. Se essa distância é menor, em seguida, 0, esse método calcula o primeiro ponto na geometria. Se essa distância é maior que o comprimento da geometria, esse método calcula o último ponto na geometria.

*worldTransform*<br/>
A transformação a ser aplicada à geometria antes de calcular o ponto especificado e a tangente.

*ponto*<br/>
O local à distância especificada ao longo da geometria. Se a geometria estiver vazia, esse ponto contém NaN como x e y valores.

*unitTangentVector*<br/>
Quando este método retorna, contém um ponteiro para o vetor de tangente à distância especificada ao longo da geometria. Se a geometria estiver vazia, esse vetor contém NaN como x e y valores. Você deve alocar armazenamento para esse parâmetro.

*flatteningTolerance*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal da geometria. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

##  <a name="destroy"></a>  CD2DGeometry::Destroy

Destrói um objeto CD2DGeometry.

```
virtual void Destroy();
```

##  <a name="detach"></a>  CD2DGeometry::Detach

Desanexa a interface do recurso do objeto

```
ID2D1Geometry* Detach();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para interface de recurso desanexado.

##  <a name="fillcontainspoint"></a>  CD2DGeometry::FillContainsPoint

Indica se a área preenchida pela geometria contém o ponto especificado, dado a tolerância de mesclagem especificada.

```
BOOL FillContainsPoint(
    CD2DPointF point,
    const D2D1_MATRIX_3X2_F& worldTransform,
    BOOL* contains,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*ponto*<br/>
Ponto a ser testado.

*worldTransform*<br/>
A transformação a ser aplicada à geometria antes do teste de confinamento.

*Contém*<br/>
Quando este método retorna, contém um valor booliano que será TRUE se a área preenchida pela geometria contém o ponto; Caso contrário, FALSE. Você deve alocar armazenamento para esse parâmetro.

*flatteningTolerance*<br/>
A precisão numérica com a qual o caminho geométrico preciso e a interseção de caminho é calculado. Falta o preenchimento pelo menor que a tolerância de pontos ainda são considerados dentro. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

##  <a name="get"></a>  CD2DGeometry::Get

Interface do ID2D1Geometry retorna

```
ID2D1Geometry* Get();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma interface do ID2D1Geometry ou NULL se o objeto ainda não foi inicializado.

##  <a name="getbounds"></a>  CD2DGeometry::GetBounds

```
BOOL GetBounds(
const D2D1_MATRIX_3X2_F& worldTransform,
CD2DRectF& bounds) const;
```

### <a name="parameters"></a>Parâmetros

*worldTransform*<br/>
*Limites*

### <a name="return-value"></a>Valor de retorno

##  <a name="getwidenedbounds"></a>  CD2DGeometry::GetWidenedBounds

Obtém os limites da geometria depois que ele foi ampliado pela largura do traço especificado e o estilo e transformado pela matriz especificada.

```
BOOL GetWidenedBounds(
    FLOAT strokeWidth,
    ID2D1StrokeStyle* strokeStyle,
    const D2D1_MATRIX_3X2_F& worldTransform,
    CD2DRectF& bounds,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*strokeWidth*<br/>
A quantidade pela qual ampliar a geometria ao traçar seu contorno.

*strokeStyle*<br/>
O estilo de traço que amplia a geometria.

*worldTransform*<br/>
Uma transformação a ser aplicada à geometria, depois que a geometria é transformada e depois a geometria tem sido feita.

*Limites*<br/>
Quando este método retorna, contém os limites da geometria largo. Você deve alocar armazenamento para esse parâmetro.

*flatteningTolerance*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal das geometrias. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

##  <a name="isvalid"></a>  CD2DGeometry::IsValid

Verificações de validade de recurso

```
virtual BOOL IsValid() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o recurso for válido. Caso contrário, FALSE.

##  <a name="m_pgeometry"></a>  CD2DGeometry::m_pGeometry

Um ponteiro para um ID2D1Geometry.

```
ID2D1Geometry* m_pGeometry;
```

##  <a name="operator_id2d1geometry_star"></a>  CD2DGeometry::Operator ID2D1Geometry *

Interface do ID2D1Geometry retorna

```
operator ID2D1Geometry*();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma interface do ID2D1Geometry ou NULL se o objeto ainda não foi inicializado.

##  <a name="outline"></a>  CD2DGeometry::Outline

Calcula o contorno de geometry e grava o resultado em um ID2D1SimplifiedGeometrySink.

```
BOOL Outline(
    const D2D1_MATRIX_3X2_F& worldTransform,
    ID2D1SimplifiedGeometrySink* geometrySink,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*worldTransform*<br/>
A transformação para aplicar a estrutura de tópicos de geometria.

*geometrySink*<br/>
O ID2D1SimplifiedGeometrySink à qual o contorno de geometry transformado é acrescentado.

*flatteningTolerance*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal da geometria. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

##  <a name="simplify"></a>  CD2DGeometry::Simplify

Cria uma versão simplificada da geometria contém apenas linhas e curvas de Bézier cúbicas (opcionalmente) e grava o resultado em um ID2D1SimplifiedGeometrySink.

```
BOOL Simplify(
    D2D1_GEOMETRY_SIMPLIFICATION_OPTION simplificationOption,
    const D2D1_MATRIX_3X2_F& worldTransform,
    ID2D1SimplifiedGeometrySink* geometrySink,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*simplificationOption*<br/>
Um valor que especifica se a geometria simplificada deve conter curvas.

*worldTransform*<br/>
A transformação a ser aplicada à geometria simplificada.

*geometrySink*<br/>
O ID2D1SimplifiedGeometrySink à qual a geometria simplificada é acrescentada.

*flatteningTolerance*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal da geometria. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

##  <a name="strokecontainspoint"></a>  CD2DGeometry::StrokeContainsPoint

Determina se o traço da geometria contém o ponto especificado, dado a espessura do traço especificado, o estilo e a transformação.

```
BOOL StrokeContainsPoint(
    CD2DPointF point,
    FLOAT strokeWidth,
    ID2D1StrokeStyle* strokeStyle,
    const D2D1_MATRIX_3X2_F& worldTransform,
    BOOL* contains,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*ponto*<br/>
O ponto a ser testado quanto ao confinamento.

*strokeWidth*<br/>
A espessura do traço para aplicar.

*strokeStyle*<br/>
O estilo do traço para aplicar.

*worldTransform*<br/>
A transformação a ser aplicada à geometria traçada.

*Contém*<br/>
Quando este método retorna, contém um valor booliano definido como TRUE se o traço da geometria contém o ponto especificado; Caso contrário, FALSE. Você deve alocar armazenamento para esse parâmetro.

*flatteningTolerance*<br/>
A precisão numérica com a qual o caminho geométrico preciso e a interseção de caminho é calculado. Falta o traço pelo menor que a tolerância de pontos ainda são considerados dentro. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

##  <a name="tessellate"></a>  CD2DGeometry::Tessellate

Cria um conjunto de triângulos abertos em sentido horário que abrangem a geometria depois que ele foi transformado pela matriz especificada e mesclado com a tolerância especificada.

```
BOOL Tessellate(
    const D2D1_MATRIX_3X2_F& worldTransform,
    ID2D1TessellationSink* tessellationSink,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*worldTransform*<br/>
A transformação para aplicar esta geometria, ou nulo.

*tessellationSink*<br/>
O ID2D1TessellationSink à qual o mosaico é acrescentado.

*flatteningTolerance*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal da geometria. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

##  <a name="widen"></a>  CD2DGeometry::Widen

Amplia a geometria pelo traço especificado e grava o resultado em um ID2D1SimplifiedGeometrySink depois que ele foi transformado pela matriz especificada e mesclado com a tolerância especificada.

```
BOOL Widen(
    FLOAT strokeWidth,
    ID2D1StrokeStyle* strokeStyle,
    const D2D1_MATRIX_3X2_F& worldTransform,
    ID2D1SimplifiedGeometrySink* geometrySink,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*strokeWidth*<br/>
A quantidade pela qual ampliar a geometria.

*strokeStyle*<br/>
O estilo de traço para aplicar a geometria, ou nulo.

*worldTransform*<br/>
A transformação a ser aplicada à geometria após ele de ampliação.

*geometrySink*<br/>
O ID2D1SimplifiedGeometrySink à qual a geometria ampliou é acrescentada.

*flatteningTolerance*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal da geometria. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
