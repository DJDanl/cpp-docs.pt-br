---
title: Classe scoped_d3d_access_lock
ms.date: 11/04/2016
f1_keywords:
- scoped_d3d_access_lock
- AMPRT/scoped_d3d_access_lock
- AMPRT/concurrency::direct3d::scoped_d3d_access_lock::scoped_d3d_access_lock
ms.assetid: 0ad333e6-9839-4736-a722-16d95d70c4b1
ms.openlocfilehash: b5a2d9dab9cba7b19fa0d0b1627f653f2c7fdc57
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77126390"
---
# <a name="scoped_d3d_access_lock-class"></a>Classe scoped_d3d_access_lock

RAII wrapper para um bloqueio de acesso do D3D em um objeto accelerator_view.

## <a name="syntax"></a>Sintaxe

```cpp
class scoped_d3d_access_lock;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor de scoped_d3d_access_lock](#ctor)|Sobrecarregado. Constrói um objeto `scoped_d3d_access_lock`. O bloqueio é liberado quando esse objeto sai do escopo.|
|[~ scoped_d3d_access_lock destruidor](#dtor)|Libera o bloqueio de acesso do D3D no objeto `accelerator_view` associado.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator=](#operator_eq)|Apropria-se de um bloqueio de outro `scoped_d3d_access_lock`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`scoped_d3d_access_lock`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amprt. h

**Namespace:** concurrency::d irect3d

## <a name="ctor"></a>scoped_d3d_access_lock

Constrói um objeto `scoped_d3d_access_lock`. O bloqueio é liberado quando esse objeto sai do escopo.

```cpp
explicit scoped_d3d_access_lock(// [1] constructor
    accelerator_view& _Av);

explicit scoped_d3d_access_lock(// [2] constructor
    accelerator_view& _Av,
    adopt_d3d_access_lock_t _T);

scoped_d3d_access_lock(// [3] move constructor
    scoped_d3d_access_lock&& _Other);
```

### <a name="parameters"></a>Parâmetros

*_Av*<br/>
O `accelerator_view` para o bloqueio adotar.

*_T*<br/>
O objeto `adopt_d3d_access_lock_t`.

*_Other*<br/>
O objeto `scoped_d3d_access_lock` do qual mover um bloqueio existente.

## <a name="construction"></a>Construção

[1] o construtor adquire um bloqueio de acesso do D3D no objeto [accelerator_view](accelerator-view-class.md) fornecido. Blocos de construção até que o bloqueio seja adquirido.

[2] o Construtor adota um bloqueio de acesso do D3D do objeto [accelerator_view](accelerator-view-class.md) fornecido.

[3] o Construtor move usa um bloqueio de acesso do D3D existente de outro objeto `scoped_d3d_access_lock`. A construção não é bloqueada.

## <a name="dtor"></a>~ scoped_d3d_access_lock

Libera o bloqueio de acesso do D3D no objeto `accelerator_view` associado.

```cpp
~scoped_d3d_access_lock();
```

## <a name="operator_eq"></a>operador =

Apropria-se de um bloqueio de acesso do D3D de outro objeto `scoped_d3d_access_lock`, liberando o bloqueio anterior.

```cpp
scoped_d3d_access_lock& operator= (scoped_d3d_access_lock&& _Other);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O accelerator_view do qual mover o bloqueio de acesso do D3D.

### <a name="return-value"></a>Valor retornado

Uma referência a este `scoped_accelerator_view_lock`.

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::direct3d](concurrency-direct3d-namespace.md)
