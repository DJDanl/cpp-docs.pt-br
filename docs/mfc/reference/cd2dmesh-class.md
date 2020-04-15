---
title: Classe CD2DMesh
ms.date: 11/04/2016
f1_keywords:
- CD2DMesh
- AFXRENDERTARGET/CD2DMesh
- AFXRENDERTARGET/CD2DMesh::CD2DMesh
- AFXRENDERTARGET/CD2DMesh::Attach
- AFXRENDERTARGET/CD2DMesh::Create
- AFXRENDERTARGET/CD2DMesh::Destroy
- AFXRENDERTARGET/CD2DMesh::Detach
- AFXRENDERTARGET/CD2DMesh::Get
- AFXRENDERTARGET/CD2DMesh::IsValid
- AFXRENDERTARGET/CD2DMesh::Open
- AFXRENDERTARGET/CD2DMesh::m_pMesh
helpviewer_keywords:
- CD2DMesh [MFC], CD2DMesh
- CD2DMesh [MFC], Attach
- CD2DMesh [MFC], Create
- CD2DMesh [MFC], Destroy
- CD2DMesh [MFC], Detach
- CD2DMesh [MFC], Get
- CD2DMesh [MFC], IsValid
- CD2DMesh [MFC], Open
- CD2DMesh [MFC], m_pMesh
ms.assetid: 11a2c78a-1367-40e8-a34f-44aa0509a4c9
ms.openlocfilehash: 64f5dd7b40853a86dc7f964ecd3701f132a94e16
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369188"
---
# <a name="cd2dmesh-class"></a>Classe CD2DMesh

Um invólucro para ID2D1Mesh.

## <a name="syntax"></a>Sintaxe

```
class CD2DMesh : public CD2DResource;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DMesh::CD2DMesh](#cd2dmesh)|Constrói um objeto CD2DMesh.|
|[CD2DMesh::~CD2DMesh](#_dtorcd2dmesh)|O destruidor. Chamado quando um objeto de malha D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DMesh::Anexar](#attach)|Anexa a interface de recurso existente ao objeto|
|[CD2DMesh::Criar](#create)|Cria um CD2DMesh. (Substitui [cd2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|
|[CD2DMesh::Destroy](#destroy)|Destrói um objeto CD2DMesh. (Substitui [cd2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|
|[CD2DMesh::Detach](#detach)|Destaca a interface de recursos do objeto|
|[CD2DMesh::Get](#get)|Retorna interface ID2D1Mesh|
|[CD2DMesh::isValid](#isvalid)|Verifica a validade do recurso (Substitui [cd2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|
|[CD2DMesh::Aberto](#open)|Abre a malha para a população.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DMesh::operador ID2D1Mesh*](#operator_id2d1mesh_star)|Retorna interface ID2D1Mesh|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DMesh::m_pMesh](#m_pmesh)|Um ponteiro para um ID2D1Mesh.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

`CD2DMesh`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dmeshcd2dmesh"></a><a name="_dtorcd2dmesh"></a>CD2DMesh::~CD2DMesh

O destruidor. Chamado quando um objeto de malha D2D está sendo destruído.

```
virtual ~CD2DMesh();
```

## <a name="cd2dmeshattach"></a><a name="attach"></a>CD2DMesh::Anexar

Anexa a interface de recurso existente ao objeto

```
void Attach(ID2D1Mesh* pResource);
```

### <a name="parameters"></a>Parâmetros

*Presource*<br/>
Interface de recurso existente. Não pode ser NULO

## <a name="cd2dmeshcd2dmesh"></a><a name="cd2dmesh"></a>CD2DMesh::CD2DMesh

Constrói um objeto CD2DMesh.

```
CD2DMesh(
    CRenderTarget* pParentTarget,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o alvo de renderização.

*bAutoDestroy*<br/>
Indica que o objeto será destruído pelo proprietário (pParentTarget).

## <a name="cd2dmeshcreate"></a><a name="create"></a>CD2DMesh::Criar

Cria um CD2DMesh.

```
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```

### <a name="parameters"></a>Parâmetros

*pRenderTarget*<br/>
Um ponteiro para o alvo de renderização.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="cd2dmeshdestroy"></a><a name="destroy"></a>CD2DMesh::Destroy

Destrói um objeto CD2DMesh.

```
virtual void Destroy();
```

## <a name="cd2dmeshdetach"></a><a name="detach"></a>CD2DMesh::Detach

Destaca a interface de recursos do objeto

```
ID2D1Mesh* Detach();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para interface de recurso separada.

## <a name="cd2dmeshget"></a><a name="get"></a>CD2DMesh::Get

Retorna interface ID2D1Mesh

```
ID2D1Mesh* Get();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1Mesh ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dmeshisvalid"></a><a name="isvalid"></a>CD2DMesh::isValid

Verifica a validade dos recursos

```
virtual BOOL IsValid() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o recurso for válido; caso contrário, FALSO.

## <a name="cd2dmeshm_pmesh"></a><a name="m_pmesh"></a>CD2DMesh::m_pMesh

Um ponteiro para um ID2D1Mesh.

```
ID2D1Mesh* m_pMesh;
```

## <a name="cd2dmeshopen"></a><a name="open"></a>CD2DMesh::Aberto

Abre a malha para a população.

```
ID2D1TessellationSink* Open();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um ID2D1TessellationSink que é usado para preencher a malha.

## <a name="cd2dmeshoperator-id2d1mesh"></a><a name="operator_id2d1mesh_star"></a>CD2DMesh::operador ID2D1Mesh*

Retorna interface ID2D1Mesh

```
operator ID2D1Mesh*();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1Mesh ou NULL se o objeto ainda não estiver inicializado.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
