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
ms.openlocfilehash: 8657421e67239cdeb782cffbbd42e0c50f6c0e96
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57258873"
---
# <a name="cd2dpathgeometry-class"></a>Classe CD2DPathGeometry

Um wrapper para ID2D1PathGeometry.

## <a name="syntax"></a>Sintaxe

```
class CD2DPathGeometry : public CD2DGeometry;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DPathGeometry::CD2DPathGeometry](#cd2dpathgeometry)|Constrói um objeto CD2DPathGeometry.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DPathGeometry::Attach](#attach)|Anexa existente de interface de recurso para o objeto|
|[CD2DPathGeometry::Create](#create)|Cria um CD2DPathGeometry. (Substitui [CD2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|
|[CD2DPathGeometry::Destroy](#destroy)|Destrói um objeto CD2DPathGeometry. (Substitui [CD2DGeometry::Destroy](../../mfc/reference/cd2dgeometry-class.md#destroy).)|
|[CD2DPathGeometry::Detach](#detach)|Desanexa a interface do recurso do objeto|
|[CD2DPathGeometry::GetFigureCount](#getfigurecount)|Recupera o número de figuras na geometria de caminho.|
|[CD2DPathGeometry::GetSegmentCount](#getsegmentcount)|Recupera o número de segmentos na geometria de caminho.|
|[CD2DPathGeometry::Open](#open)|Recupera o coletor de geometria que é usado para preencher a geometria de caminho com figuras e segmentos.|
|[CD2DPathGeometry::Stream](#stream)|Copia o conteúdo de geometria de caminho para o ID2D1GeometrySink especificado.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DPathGeometry::m_pPathGeometry](#m_ppathgeometry)|Um ponteiro para um ID2D1PathGeometry.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

[CD2DGeometry](../../mfc/reference/cd2dgeometry-class.md)

`CD2DPathGeometry`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="attach"></a>  CD2DPathGeometry::Attach

Anexa existente de interface de recurso para o objeto

```
void Attach(ID2D1PathGeometry* pResource);
```

### <a name="parameters"></a>Parâmetros

*pResource*<br/>
Interface de recursos existente. Não pode ser NULL

##  <a name="cd2dpathgeometry"></a>  CD2DPathGeometry::CD2DPathGeometry

Constrói um objeto CD2DPathGeometry.

```
CD2DPathGeometry(
    CRenderTarget* pParentTarget,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o destino de renderização.

*bAutoDestroy*<br/>
Indica se o objeto será destruído pelo proprietário (pParentTarget).

##  <a name="create"></a>  CD2DPathGeometry::Create

Cria um CD2DPathGeometry.

```
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```

### <a name="parameters"></a>Parâmetros

*pRenderTarget*<br/>
Um ponteiro para o destino de renderização.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retornará um código de erro HRESULT.

##  <a name="destroy"></a>  CD2DPathGeometry::Destroy

Destrói um objeto CD2DPathGeometry.

```
virtual void Destroy();
```

##  <a name="detach"></a>  CD2DPathGeometry::Detach

Desanexa a interface do recurso do objeto

```
ID2D1PathGeometry* Detach();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para interface de recurso desanexado.

##  <a name="getfigurecount"></a>  CD2DPathGeometry::GetFigureCount

Recupera o número de figuras na geometria de caminho.

```
int GetFigureCount() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de figuras na geometria de caminho.

##  <a name="getsegmentcount"></a>  CD2DPathGeometry::GetSegmentCount

Recupera o número de segmentos na geometria de caminho.

```
int GetSegmentCount() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de segmentos na geometria de caminho.

##  <a name="m_ppathgeometry"></a>  CD2DPathGeometry::m_pPathGeometry

Um ponteiro para um ID2D1PathGeometry.

```
ID2D1PathGeometry* m_pPathGeometry;
```

##  <a name="open"></a>  CD2DPathGeometry::Open

Recupera o coletor de geometria que é usado para preencher a geometria de caminho com figuras e segmentos.

```
ID2D1GeometrySink* Open();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o ID2D1GeometrySink que é usado para preencher a geometria de caminho com figuras e segmentos.

##  <a name="stream"></a>  CD2DPathGeometry::Stream

Copia o conteúdo de geometria de caminho para o ID2D1GeometrySink especificado.

```
BOOL Stream(ID2D1GeometrySink* geometrySink);
```

### <a name="parameters"></a>Parâmetros

*geometrySink*<br/>
O coletor para o qual o conteúdo da geometria de caminho é copiado. Modificar esse coletor não altera o conteúdo dessa geometria de caminho.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
