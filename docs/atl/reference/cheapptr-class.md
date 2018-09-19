---
title: Classe CHeapPtr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CHeapPtr
- ATLCORE/ATL::CHeapPtr
- ATLCORE/ATL::CHeapPtr::CHeapPtr
- ATLCORE/ATL::CHeapPtr::Allocate
- ATLCORE/ATL::CHeapPtr::Reallocate
dev_langs:
- C++
helpviewer_keywords:
- CHeapPtr class
ms.assetid: e5c5bfd4-9bf1-4164-8a83-8155fe253454
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8ea4fd429395fc78f36d1f9b3244068c737be49a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46033973"
---
# <a name="cheapptr-class"></a>Classe CHeapPtr

Uma classe de ponteiro inteligente para gerenciar os ponteiros de pilha.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<typename T, class Allocator=CCRTAllocator>
class CHeapPtr : public CHeapPtrBase<T, Allocator>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de objeto a ser armazenado no heap.

*Alocador*<br/>
A classe de alocação de memória para usar.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeapPtr::CHeapPtr](#cheapptr)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeapPtr::Allocate](#allocate)|Chame esse método para alocar memória no heap para armazenar objetos.|
|[CHeapPtr::Reallocate](#reallocate)|Chame esse método para realocar a memória no heap.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeapPtr::operator =](#operator_eq)|O operador de atribuição.|

## <a name="remarks"></a>Comentários

`CHeapPtr` é derivado de [CHeapPtrBase](../../atl/reference/cheapptrbase-class.md) e, por padrão, usa as rotinas de CRT (no [CCRTAllocator](../../atl/reference/ccrtallocator-class.md)) para alocar e liberar memória. A classe [CHeapPtrList](../../atl/reference/cheapptrlist-class.md) pode ser usado para construir uma lista de ponteiros de pilha. Consulte também [CComHeapPtr](../../atl/reference/ccomheapptr-class.md), que usa rotinas de alocação de memória do COM.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CHeapPtrBase](../../atl/reference/cheapptrbase-class.md)

`CHeapPtr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

##  <a name="allocate"></a>  CHeapPtr::Allocate

Chame esse método para alocar memória no heap para armazenar objetos.

```
bool Allocate(size_t nElements = 1) throw();
```

### <a name="parameters"></a>Parâmetros

*nElements*<br/>
O número de elementos usados para calcular a quantidade de memória para alocar. O valor padrão é 1.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se a memória tiver sido alocada, falso em caso de falha.

### <a name="remarks"></a>Comentários

As rotinas de alocador são usadas para reservar memória suficiente no heap para armazenar *nElement* objetos de um tipo definido no construtor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#77](../../atl/codesnippet/cpp/cheapptr-class_1.cpp)]

##  <a name="cheapptr"></a>  CHeapPtr::CHeapPtr

O construtor.

```
CHeapPtr() throw();
explicit CHeapPtr(T* p) throw();
CHeapPtr(CHeapPtr<T, Allocator>& p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Um ponteiro de heap existente ou `CHeapPtr`.

### <a name="remarks"></a>Comentários

O ponteiro do heap, opcionalmente, pode ser criado usando um ponteiro existente, ou um `CHeapPtr` objeto. Nesse caso, o novo `CHeapPtr` objeto assume a responsabilidade por gerenciar o novo ponteiro e recursos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#78](../../atl/codesnippet/cpp/cheapptr-class_2.cpp)]

##  <a name="operator_eq"></a>  CHeapPtr::operator =

Operador de atribuição.

```
CHeapPtr<T, Allocator>& operator=(
    CHeapPtr<T, Allocator>& p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Um objeto `CHeapPtr` existente.

### <a name="return-value"></a>Valor de retorno

Retorna uma referência para a atualização `CHeapPtr`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#80](../../atl/codesnippet/cpp/cheapptr-class_3.cpp)]

##  <a name="reallocate"></a>  CHeapPtr::Reallocate

Chame esse método para realocar a memória no heap.

```
bool Reallocate(size_t nElements) throw();
```

### <a name="parameters"></a>Parâmetros

*nElements*<br/>
O novo número de elementos usados para calcular a quantidade de memória para alocar.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se a memória tiver sido alocada, falso em caso de falha.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#79](../../atl/codesnippet/cpp/cheapptr-class_4.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CHeapPtrBase](../../atl/reference/cheapptrbase-class.md)<br/>
[Classe CCRTAllocator](../../atl/reference/ccrtallocator-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
