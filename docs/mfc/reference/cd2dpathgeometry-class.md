---
title: Classe CD2DPathGeometry
ms.date: 11/04/2016
f1_keywords:
- CD2DPathGeometry
- AFXRENDERTARGET/CD2DPathGeometry
- AFXRENDERTARGET/CD2DPathGeometry::CD2DPathGeometry
- AFXRENDERTARGET/CD2DPathGeometry::Attach
- AFXRENDERTARGET/CD2DPathGeometry::Create
- AFXRENDERTARGET/CD2DPathGeometry::Destroy
- AFXRENDERTARGET/CD2DPathGeometry::Detach
- AFXRENDERTARGET/CD2DPathGeometry::GetFigureCount
- AFXRENDERTARGET/CD2DPathGeometry::GetSegmentCount
- AFXRENDERTARGET/CD2DPathGeometry::Open
- AFXRENDERTARGET/CD2DPathGeometry::Stream
- AFXRENDERTARGET/CD2DPathGeometry::m_pPathGeometry
helpviewer_keywords:
- CD2DPathGeometry [MFC], CD2DPathGeometry
- CD2DPathGeometry [MFC], Attach
- CD2DPathGeometry [MFC], Create
- CD2DPathGeometry [MFC], Destroy
- CD2DPathGeometry [MFC], Detach
- CD2DPathGeometry [MFC], GetFigureCount
- CD2DPathGeometry [MFC], GetSegmentCount
- CD2DPathGeometry [MFC], Open
- CD2DPathGeometry [MFC], Stream
- CD2DPathGeometry [MFC], m_pPathGeometry
ms.assetid: 686216eb-5080-4242-ace5-8fa1ce96307c
ms.openlocfilehash: 59ef82151983720b654502ccf3ca647e55366268
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369178"
---
# <a name="cd2dpathgeometry-class"></a>Classe CD2DPathGeometry

Um invólucro para ID2D1PathGeometry.

## <a name="syntax"></a>Sintaxe

```
class CD2DPathGeometry : public CD2DGeometry;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DPathGeometry::CD2DPathGeometry](#cd2dpathgeometry)|Constrói um objeto CD2DPathGeometry.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DPathGeometry::Anexar](#attach)|Anexa a interface de recurso existente ao objeto|
|[CD2DPathGeometry::Criar](#create)|Cria uma Geometria CD2DPath. (Substitui [cd2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|
|[CD2DPathGeometria::Destroy](#destroy)|Destrói um objeto CD2DPathGeometry. (Substitui [cd2DGeometria::Destroy](../../mfc/reference/cd2dgeometry-class.md#destroy).)|
|[CD2DPathGeometry::Detach](#detach)|Destaca a interface de recursos do objeto|
|[CD2DPathGeometry::GetFigureCount](#getfigurecount)|Recupera o número de figuras na geometria do caminho.|
|[CD2DPathGeometry::GetSegmentCount](#getsegmentcount)|Recupera o número de segmentos na geometria do caminho.|
|[CD2DPathGeometry::Aberto](#open)|Recupera a pia de geometria que é usada para preencher a geometria do caminho com figuras e segmentos.|
|[CD2DPathGeometry::Stream](#stream)|Copia o conteúdo da geometria do caminho para o ID2D1GeometrySink especificado.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DPathGeometry::m_pPathGeometry](#m_ppathgeometry)|Um ponteiro para um ID2D1PathGeometry.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

[CD2DGeometria](../../mfc/reference/cd2dgeometry-class.md)

`CD2DPathGeometry`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dpathgeometryattach"></a><a name="attach"></a>CD2DPathGeometry::Anexar

Anexa a interface de recurso existente ao objeto

```
void Attach(ID2D1PathGeometry* pResource);
```

### <a name="parameters"></a>Parâmetros

*Presource*<br/>
Interface de recurso existente. Não pode ser NULO

## <a name="cd2dpathgeometrycd2dpathgeometry"></a><a name="cd2dpathgeometry"></a>CD2DPathGeometry::CD2DPathGeometry

Constrói um objeto CD2DPathGeometry.

```
CD2DPathGeometry(
    CRenderTarget* pParentTarget,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o alvo de renderização.

*bAutoDestroy*<br/>
Indica que o objeto será destruído pelo proprietário (pParentTarget).

## <a name="cd2dpathgeometrycreate"></a><a name="create"></a>CD2DPathGeometry::Criar

Cria uma Geometria CD2DPath.

```
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```

### <a name="parameters"></a>Parâmetros

*pRenderTarget*<br/>
Um ponteiro para o alvo de renderização.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="cd2dpathgeometrydestroy"></a><a name="destroy"></a>CD2DPathGeometria::Destroy

Destrói um objeto CD2DPathGeometry.

```
virtual void Destroy();
```

## <a name="cd2dpathgeometrydetach"></a><a name="detach"></a>CD2DPathGeometry::Detach

Destaca a interface de recursos do objeto

```
ID2D1PathGeometry* Detach();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para interface de recurso separada.

## <a name="cd2dpathgeometrygetfigurecount"></a><a name="getfigurecount"></a>CD2DPathGeometry::GetFigureCount

Recupera o número de figuras na geometria do caminho.

```
int GetFigureCount() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o número de figuras na geometria do caminho.

## <a name="cd2dpathgeometrygetsegmentcount"></a><a name="getsegmentcount"></a>CD2DPathGeometry::GetSegmentCount

Recupera o número de segmentos na geometria do caminho.

```
int GetSegmentCount() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o número de segmentos na geometria do caminho.

## <a name="cd2dpathgeometrym_ppathgeometry"></a><a name="m_ppathgeometry"></a>CD2DPathGeometry::m_pPathGeometry

Um ponteiro para um ID2D1PathGeometry.

```
ID2D1PathGeometry* m_pPathGeometry;
```

## <a name="cd2dpathgeometryopen"></a><a name="open"></a>CD2DPathGeometry::Aberto

Recupera a pia de geometria que é usada para preencher a geometria do caminho com figuras e segmentos.

```
ID2D1GeometrySink* Open();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o ID2D1GeometrySink que é usado para preencher a geometria do caminho com figuras e segmentos.

## <a name="cd2dpathgeometrystream"></a><a name="stream"></a>CD2DPathGeometry::Stream

Copia o conteúdo da geometria do caminho para o ID2D1GeometrySink especificado.

```
BOOL Stream(ID2D1GeometrySink* geometrySink);
```

### <a name="parameters"></a>Parâmetros

*geometriaSink*<br/>
A pia para a qual o conteúdo da geometria do caminho é copiado. Modificar esta pia não altera o conteúdo desta geometria do caminho.

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
