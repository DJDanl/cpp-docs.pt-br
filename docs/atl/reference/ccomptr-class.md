---
title: Classe CComPtr
description: Guia de referência para a classe C++ Active Template Library (ATL) da Microsoft C++.
ms.date: 02/07/2020
f1_keywords:
- CComPtr
- ATLBASE/ATL::CComPtr
- ATLBASE/ATL::CComPtr::CComPtr
helpviewer_keywords:
- CComPtr class
ms.assetid: 22d9ea8d-ed66-4c34-940f-141db11e83bd
ms.openlocfilehash: 855466225db2672755658dcbbc9a266d09e0e7be
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327520"
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

|Nome|Descrição|
|----------|-----------------|
|[CComPtr::CComPtr](#ccomptr)|O construtor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComPtr::operador =](#operator_eq)|Atribui um ponteiro ao ponteiro do membro.|

## <a name="remarks"></a>Comentários

O ATL usa `CComPtr` e o [CComQIPtr](../../atl/reference/ccomqiptr-class.md) para gerenciar ponteiros de interface COM. Ambos são derivados do [CComPtrBase](../../atl/reference/ccomptrbase-class.md), e ambos fazem contagem automática de referências.

As `CComPtr` classes [CComQIPtr e CComQIPtr](../../atl/reference/ccomqiptr-class.md) podem ajudar a eliminar vazamentos de memória realizando contagem automática de referências.  As funções a seguir fazem as mesmas operações lógicas. No entanto, a segunda versão pode ser `CComPtr` menos propensa a erros porque usa a classe:

[!code-cpp[NVC_ATL_Utilities#130](../../atl/codesnippet/cpp/ccomptr-class_1.cpp)]

[!code-cpp[NVC_ATL_Utilities#131](../../atl/codesnippet/cpp/ccomptr-class_2.cpp)]

Em compilações de depuração, link atlsd.lib para rastreamento de código.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Ccomptrbase](../../atl/reference/ccomptrbase-class.md)

`CComPtr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccomptrccomptr"></a><a name="ccomptr"></a>CComPtr::CComPtr

O construtor.

```cpp
CComPtr() throw ();
CComPtr(T* lp) throw ();
CComPtr (const CComPtr<T>& lp) throw ();
```

### <a name="parameters"></a>Parâmetros

*Lp*<br/>
Usado para inicializar o ponteiro de interface.

*T*<br/>
Uma interface COM.

### <a name="remarks"></a>Comentários

Os construtores que tomam `AddRef` uma chamada de argumento em *lp*, se não é um ponteiro nulo. Um objeto de propriedade `Release` não nula recebe uma chamada sobre a destruição do objeto CComPtr ou se um novo objeto for atribuído ao objeto CComPtr.

## <a name="ccomptroperator-"></a><a name="operator_eq"></a>CComPtr::operador =

Operador de atribuição.

```cpp
T* operator= (T* lp) throw ();
T* operator= (const CComPtr<T>& lp) throw ();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro `CComPtr` para o objeto atualizado

### <a name="remarks"></a>Comentários

Esta operação adiciona o novo objeto e libera o objeto existente, se existir.

## <a name="see-also"></a>Confira também

[CComPtr::CComPtr](#ccomptr)<br/>
[CComQIPtr::CComQIPtr](../../atl/reference/ccomqiptr-class.md#ccomqiptr)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
