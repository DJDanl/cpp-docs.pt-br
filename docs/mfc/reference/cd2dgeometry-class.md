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
ms.openlocfilehash: 2631005fcedfb8d5db69667e22c375f585b4f044
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369254"
---
# <a name="cd2dgeometry-class"></a>Classe CD2DGeometry

Um invólucro para ID2D1Geometry.

## <a name="syntax"></a>Sintaxe

```
class CD2DGeometry : public CD2DResource;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGeometria::CD2DGeometria](#cd2dgeometry)|Constrói um objeto CD2DGeometry.|
|[CD2DGeometria::~CD2DGeometria](#_dtorcd2dgeometry)|O destruidor. Chamado quando um objeto de geometria D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGeometria::Anexar](#attach)|Anexa a interface de recurso existente ao objeto|
|[CD2DGeometria::CombineComGeometry](#combinewithgeometry)|Combina essa geometria com a geometria especificada e armazena o resultado em um ID2D1SimplifiedGeometrySink.|
|[CD2DGeometria::CompareComComGeometria](#comparewithgeometry)|Descreve a intersecção entre esta geometria e a geometria especificada. A comparação é realizada utilizando-se a tolerância de achatamento especificada.|
|[CD2DGeometria::ComputeArea](#computearea)|Calcula a área da geometria depois de ter sido transformada pela matriz especificada e achatada usando a tolerância especificada.|
|[CD2DGeometria::ComputaçãoComprimento](#computelength)|Calcula o comprimento da geometria como se cada segmento fosse desenrolado em uma linha.|
|[CD2DGeometria::ComputePointAtLength](#computepointatlength)|Calcula o vetor de ponto e tangente na distância especificada ao longo da geometria depois de ter sido transformado pela matriz especificada e achatado usando a tolerância especificada.|
|[CD2DGeometria::Destroy](#destroy)|Destrói um objeto CD2DGeometry. (Substitui [cd2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|
|[CD2DGeometria::Detach](#detach)|Destaca a interface de recursos do objeto|
|[CD2DGeometria::PreenchimentoContémPonto](#fillcontainspoint)|Indica se a área preenchida pela geometria conteria o ponto especificado dada a tolerância de achatamento especificada.|
|[CD2DGeometria::Obter](#get)|Retorna interface ID2D1Geometry|
|[CD2DGeometria::GetBounds](#getbounds)||
|[CD2DGeometria::GetWidenedBounds](#getwidenedbounds)|Obtém os limites da geometria depois de ter sido ampliada pela largura e estilo de traçado especificados e transformadopela matriz especificada.|
|[CD2DGeometria::IsValid](#isvalid)|Verifica a validade do recurso (Substitui [cd2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|
|[CD2DGeometria::Contorno](#outline)|Calcula o contorno da geometria e grava o resultado em um ID2D1SimplifiedGeometrySink.|
|[CD2DGeometria::Simplificar](#simplify)|Cria uma versão simplificada da geometria que contém apenas linhas e curvas bezier (opcionalmente) cúbicas e grava o resultado para um ID2D1SimplifiedGeometrySink.|
|[CD2DGeometria::TraçadoContémPoint](#strokecontainspoint)|Determina se o traçado da geometria contém o ponto especificado dada a espessura, estilo e transformação especificados do traçado.|
|[CD2DGeometria::Tessellate](#tessellate)|Cria um conjunto de triângulos abertos em sentido horário que abrangem a geometria depois de ser transformado pela matriz especificada e mesclado com a tolerância especificada.|
|[CD2DGeometria::Ampliar](#widen)|Amplia a geometria pelo traçado especificado e grava o resultado para um ID2D1SimplifiedGeometrySink depois de ter sido transformado pela matriz especificada e achatado usando a tolerância especificada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGeometria:operador ID2D1Geometria*](#operator_id2d1geometry_star)|Retorna interface ID2D1Geometry|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DGeometria::m_pGeometry](#m_pgeometry)|Um ponteiro para um ID2D1Geometry.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

`CD2DGeometry`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dgeometrycd2dgeometry"></a><a name="_dtorcd2dgeometry"></a>CD2DGeometria::~CD2DGeometria

O destruidor. Chamado quando um objeto de geometria D2D está sendo destruído.

```
virtual ~CD2DGeometry();
```

## <a name="cd2dgeometryattach"></a><a name="attach"></a>CD2DGeometria::Anexar

Anexa a interface de recurso existente ao objeto

```
void Attach(ID2D1Geometry* pResource);
```

### <a name="parameters"></a>Parâmetros

*Presource*<br/>
Interface de recurso existente. Não pode ser NULO

## <a name="cd2dgeometrycd2dgeometry"></a><a name="cd2dgeometry"></a>CD2DGeometria::CD2DGeometria

Constrói um objeto CD2DGeometry.

```
CD2DGeometry(
    CRenderTarget* pParentTarget,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o alvo de renderização.

*bAutoDestroy*<br/>
Indica que o objeto será destruído pelo proprietário (pParentTarget).

## <a name="cd2dgeometrycombinewithgeometry"></a><a name="combinewithgeometry"></a>CD2DGeometria::CombineComGeometry

Combina essa geometria com a geometria especificada e armazena o resultado em um ID2D1SimplifiedGeometrySink.

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
A geometria para combinar com esta instância.

*Combinemode*<br/>
O tipo de operação de combinação para realizar.

*inputGeometryTransform*<br/>
A transformação para aplicar à inputGeometry antes de combinar.

*geometriaSink*<br/>
O resultado da operação de combinação.

*achatamentoTolerância*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal das geometrias. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="cd2dgeometrycomparewithgeometry"></a><a name="comparewithgeometry"></a>CD2DGeometria::CompareComComGeometria

Descreve a intersecção entre esta geometria e a geometria especificada. A comparação é realizada utilizando-se a tolerância de achatamento especificada.

```
D2D1_GEOMETRY_RELATION CompareWithGeometry(
    CD2DGeometry& inputGeometry,
    const D2D1_MATRIX_3X2_F& inputGeometryTransform,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*inputGeometry*<br/>
A geometria para testar.

*inputGeometryTransform*<br/>
A transformação para aplicar à inputGeometry.

*achatamentoTolerância*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal das geometrias. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="cd2dgeometrycomputearea"></a><a name="computearea"></a>CD2DGeometria::ComputeArea

Calcula a área da geometria depois de ter sido transformada pela matriz especificada e achatada usando a tolerância especificada.

```
BOOL ComputeArea(
    const D2D1_MATRIX_3X2_F& worldTransform,
    FLOAT& area,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*worldTransform*<br/>
A transformação para aplicar a esta geometria antes de calcular sua área.

*Área*<br/>
Quando este método retorna, contém um ponteiro para a área da versão achatada e transformada desta geometria. Você deve alocar armazenamento para este parâmetro.

*achatamentoTolerância*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal de geometria. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="cd2dgeometrycomputelength"></a><a name="computelength"></a>CD2DGeometria::ComputaçãoComprimento

Calcula o comprimento da geometria como se cada segmento fosse desenrolado em uma linha.

```
BOOL ComputeLength(
    const D2D1_MATRIX_3X2_F& worldTransform,
    FLOAT& length,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*worldTransform*<br/>
A transformação para aplicar à geometria antes de calcular seu comprimento.

*length*<br/>
Quando este método retorna, contém um ponteiro para o comprimento da geometria. Para geometrias fechadas, o comprimento inclui um segmento de fechamento implícito. Você deve alocar armazenamento para este parâmetro.

*achatamentoTolerância*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal de geometria. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="cd2dgeometrycomputepointatlength"></a><a name="computepointatlength"></a>CD2DGeometria::ComputePointAtLength

Calcula o vetor de ponto e tangente na distância especificada ao longo da geometria depois de ter sido transformado pela matriz especificada e achatado usando a tolerância especificada.

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
A distância ao longo da geometria do ponto e tangente para encontrar. Se essa distância for menor que 0, este método calcula o primeiro ponto na geometria. Se essa distância for maior que o comprimento da geometria, este método calcula o último ponto da geometria.

*worldTransform*<br/>
A transformação para aplicar à geometria antes de calcular o ponto e a tangente especificados.

*Ponto*<br/>
A localização na distância especificada ao longo da geometria. Se a geometria estiver vazia, este ponto contém NaN como seus valores x e y.

*unitTangentVector*<br/>
Quando este método retorna, contém um ponteiro para o vetor tangente na distância especificada ao longo da geometria. Se a geometria estiver vazia, este vetor contém NaN como seus valores x e y. Você deve alocar armazenamento para este parâmetro.

*achatamentoTolerância*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal de geometria. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="cd2dgeometrydestroy"></a><a name="destroy"></a>CD2DGeometria::Destroy

Destrói um objeto CD2DGeometry.

```
virtual void Destroy();
```

## <a name="cd2dgeometrydetach"></a><a name="detach"></a>CD2DGeometria::Detach

Destaca a interface de recursos do objeto

```
ID2D1Geometry* Detach();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para interface de recurso separada.

## <a name="cd2dgeometryfillcontainspoint"></a><a name="fillcontainspoint"></a>CD2DGeometria::PreenchimentoContémPonto

Indica se a área preenchida pela geometria conteria o ponto especificado dada a tolerância de achatamento especificada.

```
BOOL FillContainsPoint(
    CD2DPointF point,
    const D2D1_MATRIX_3X2_F& worldTransform,
    BOOL* contains,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
O ponto a ser testado.

*worldTransform*<br/>
A transformação para aplicar à geometria antes do teste para contenção.

*Contém*<br/>
Quando este método retorna, contém um valor bool que é VERDADEIRO se a área preenchida pela geometria contiver ponto; caso contrário, FALSE. Você deve alocar armazenamento para este parâmetro.

*achatamentoTolerância*<br/>
A precisão numérica com que o caminho geométrico preciso e a intersecção do caminho são calculados. Pontos que perdem o preenchimento por menos do que a tolerância ainda são considerados no interior. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="cd2dgeometryget"></a><a name="get"></a>CD2DGeometria::Obter

Retorna interface ID2D1Geometry

```
ID2D1Geometry* Get();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1Geometry ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dgeometrygetbounds"></a><a name="getbounds"></a>CD2DGeometria::GetBounds

```
BOOL GetBounds(
const D2D1_MATRIX_3X2_F& worldTransform,
CD2DRectF& bounds) const;
```

### <a name="parameters"></a>Parâmetros

*worldTransform*<br/>
*Limites*

### <a name="return-value"></a>Valor retornado

## <a name="cd2dgeometrygetwidenedbounds"></a><a name="getwidenedbounds"></a>CD2DGeometria::GetWidenedBounds

Obtém os limites da geometria depois de ter sido ampliada pela largura e estilo de traçado especificados e transformadopela matriz especificada.

```
BOOL GetWidenedBounds(
    FLOAT strokeWidth,
    ID2D1StrokeStyle* strokeStyle,
    const D2D1_MATRIX_3X2_F& worldTransform,
    CD2DRectF& bounds,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*traçadoLargura*<br/>
A quantidade pela qual para ampliar a geometria acariciando seu contorno.

*strokeStyle*<br/>
O estilo do traçado que amplia a geometria.

*worldTransform*<br/>
Uma transformação para aplicar à geometria depois que a geometria é transformada e depois que a geometria foi acariciada.

*Limites*<br/>
Quando este método retorna, contém os limites da geometria ampliada. Você deve alocar armazenamento para este parâmetro.

*achatamentoTolerância*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal das geometrias. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="cd2dgeometryisvalid"></a><a name="isvalid"></a>CD2DGeometria::IsValid

Verifica a validade dos recursos

```
virtual BOOL IsValid() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o recurso for válido; caso contrário, FALSO.

## <a name="cd2dgeometrym_pgeometry"></a><a name="m_pgeometry"></a>CD2DGeometria::m_pGeometry

Um ponteiro para um ID2D1Geometry.

```
ID2D1Geometry* m_pGeometry;
```

## <a name="cd2dgeometryoperator-id2d1geometry"></a><a name="operator_id2d1geometry_star"></a>CD2DGeometria:operador ID2D1Geometria*

Retorna interface ID2D1Geometry

```
operator ID2D1Geometry*();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1Geometry ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dgeometryoutline"></a><a name="outline"></a>CD2DGeometria::Contorno

Calcula o contorno da geometria e grava o resultado em um ID2D1SimplifiedGeometrySink.

```
BOOL Outline(
    const D2D1_MATRIX_3X2_F& worldTransform,
    ID2D1SimplifiedGeometrySink* geometrySink,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*worldTransform*<br/>
A transformação para aplicar ao contorno da geometria.

*geometriaSink*<br/>
O ID2D1SimplifiedGeometrySink ao qual o contorno transformado em geometria é anexado.

*achatamentoTolerância*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal de geometria. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="cd2dgeometrysimplify"></a><a name="simplify"></a>CD2DGeometria::Simplificar

Cria uma versão simplificada da geometria que contém apenas linhas e curvas bezier (opcionalmente) cúbicas e grava o resultado para um ID2D1SimplifiedGeometrySink.

```
BOOL Simplify(
    D2D1_GEOMETRY_SIMPLIFICATION_OPTION simplificationOption,
    const D2D1_MATRIX_3X2_F& worldTransform,
    ID2D1SimplifiedGeometrySink* geometrySink,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*simplificaçãoOpção*<br/>
Um valor que especifica se a geometria simplificada deve conter curvas.

*worldTransform*<br/>
A transformação para aplicar à geometria simplificada.

*geometriaSink*<br/>
O ID2D1SimplifiedGeometrySink ao qual a geometria simplificada é anexada.

*achatamentoTolerância*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal de geometria. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="cd2dgeometrystrokecontainspoint"></a><a name="strokecontainspoint"></a>CD2DGeometria::TraçadoContémPoint

Determina se o traçado da geometria contém o ponto especificado dada a espessura, estilo e transformação especificados do traçado.

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

*Ponto*<br/>
O ponto a ser testado quanto ao confinamento.

*traçadoLargura*<br/>
A espessura do curso para aplicar.

*strokeStyle*<br/>
O estilo do curso para aplicar.

*worldTransform*<br/>
A transformação para aplicar à geometria acariciada.

*Contém*<br/>
Quando este método retornar, contém um valor booleano definido como TRUE se o traçado da geometria contiver o ponto especificado; caso contrário, FALSE. Você deve alocar armazenamento para este parâmetro.

*achatamentoTolerância*<br/>
A precisão numérica com que o caminho geométrico preciso e a intersecção do caminho são calculados. Pontos que perdem o traçado por menos do que a tolerância ainda são considerados no interior. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="cd2dgeometrytessellate"></a><a name="tessellate"></a>CD2DGeometria::Tessellate

Cria um conjunto de triângulos abertos em sentido horário que abrangem a geometria depois de ser transformado pela matriz especificada e mesclado com a tolerância especificada.

```
BOOL Tessellate(
    const D2D1_MATRIX_3X2_F& worldTransform,
    ID2D1TessellationSink* tessellationSink,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*worldTransform*<br/>
A transformação para aplicar a esta geometria, ou NULL.

*tessellationSink*<br/>
O ID2D1TessellationSink ao qual o tessellado é anexado.

*achatamentoTolerância*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal de geometria. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="cd2dgeometrywiden"></a><a name="widen"></a>CD2DGeometria::Ampliar

Amplia a geometria pelo traçado especificado e grava o resultado para um ID2D1SimplifiedGeometrySink depois de ter sido transformado pela matriz especificada e achatado usando a tolerância especificada.

```
BOOL Widen(
    FLOAT strokeWidth,
    ID2D1StrokeStyle* strokeStyle,
    const D2D1_MATRIX_3X2_F& worldTransform,
    ID2D1SimplifiedGeometrySink* geometrySink,
    FLOAT flatteningTolerance = D2D1_DEFAULT_FLATTENING_TOLERANCE) const;
```

### <a name="parameters"></a>Parâmetros

*traçadoLargura*<br/>
A quantidade pela qual para ampliar a geometria.

*strokeStyle*<br/>
O estilo de curso para aplicar à geometria, ou NULL.

*worldTransform*<br/>
A transformação para aplicar à geometria depois de ampliá-la.

*geometriaSink*<br/>
O ID2D1SimplifiedGeometrySink ao qual a geometria ampliada é anexada.

*achatamentoTolerância*<br/>
Os limites máximos na distância entre pontos na aproximação poligonal de geometria. Valores menores produzem resultados mais precisos, mas causam a execução lenta.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
