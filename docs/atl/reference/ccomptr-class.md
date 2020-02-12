---
title: Classe CComPtr
description: Guia de referência para a C++ classe Microsoft Active Template Library (ATL) CComPtr.
ms.date: 02/07/2020
f1_keywords:
- CComPtr
- ATLBASE/ATL::CComPtr
- ATLBASE/ATL::CComPtr::CComPtr
helpviewer_keywords:
- CComPtr class
ms.assetid: 22d9ea8d-ed66-4c34-940f-141db11e83bd
ms.openlocfilehash: 74a12b460f55a782fa2747b02f7d00287786fae6
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127393"
---
# <a name="ccomptr-class"></a>Classe CComPtr

Uma classe de ponteiro inteligente para gerenciar ponteiros de interface COM.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T>
class CComPtr
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma interface COM especificando o tipo de ponteiro a ser armazenado.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CComPtr:: CComPtr](#ccomptr)|O construtor.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CComPtr:: Operator =](#operator_eq)|Atribui um ponteiro para o ponteiro do membro.|

## <a name="remarks"></a>Comentários

A ATL usa `CComPtr` e [CComQIPtr](../../atl/reference/ccomqiptr-class.md) para gerenciar ponteiros de interface com. Ambos são derivados de [CComPtrBase](../../atl/reference/ccomptrbase-class.md)e ambos fazem contagem de referência automática.

As classes `CComPtr` e [CComQIPtr](../../atl/reference/ccomqiptr-class.md) podem ajudar a eliminar vazamentos de memória executando a contagem de referência automática.  As funções a seguir fazem as mesmas operações lógicas. No entanto, a segunda versão pode ser menos propenso a erros porque usa a classe `CComPtr`:

[!code-cpp[NVC_ATL_Utilities#130](../../atl/codesnippet/cpp/ccomptr-class_1.cpp)]

[!code-cpp[NVC_ATL_Utilities#131](../../atl/codesnippet/cpp/ccomptr-class_2.cpp)]

Em compilações de depuração, vincule atlsd. lib ao rastreamento de código.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CComPtrBase](../../atl/reference/ccomptrbase-class.md)

`CComPtr`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlbase. h

## <a name="ccomptr"></a>CComPtr:: CComPtr

O construtor.

```cpp
CComPtr() throw ();
CComPtr(T* lp) throw ();
CComPtr (const CComPtr<T>& lp) throw ();
```

### <a name="parameters"></a>Parâmetros

*LP*<br/>
Usado para inicializar o ponteiro de interface.

*T*<br/>
Uma interface COM.

### <a name="remarks"></a>Comentários

Os construtores que usam uma chamada de argumento `AddRef` em *LP*, se não for um ponteiro nulo. Um objeto de propriedade não nulo Obtém uma chamada de `Release` sobre a destruição do objeto CComPtr ou se um novo objeto é atribuído ao objeto CComPtr.

## <a name="operator_eq"></a>CComPtr:: Operator =

Operador de atribuição.

```cpp
T* operator= (T* lp) throw ();
T* operator= (const CComPtr<T>& lp) throw ();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o objeto `CComPtr` atualizado

### <a name="remarks"></a>Comentários

Essa operação AddRef o novo objeto e libera o objeto existente, se houver.

## <a name="see-also"></a>Consulte também

[CComPtr:: CComPtr](#ccomptr)<br/>
[CComQIPtr::CComQIPtr](../../atl/reference/ccomqiptr-class.md#ccomqiptr)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
