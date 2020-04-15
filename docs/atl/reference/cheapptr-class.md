---
title: Classe CHeapPtr
ms.date: 11/04/2016
f1_keywords:
- CHeapPtr
- ATLCORE/ATL::CHeapPtr
- ATLCORE/ATL::CHeapPtr::CHeapPtr
- ATLCORE/ATL::CHeapPtr::Allocate
- ATLCORE/ATL::CHeapPtr::Reallocate
helpviewer_keywords:
- CHeapPtr class
ms.assetid: e5c5bfd4-9bf1-4164-8a83-8155fe253454
ms.openlocfilehash: a512aa974cb57072915f887f0c2a20ed1263ffa3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326909"
---
# <a name="cheapptr-class"></a>Classe CHeapPtr

Uma classe de ponteiro inteligente para gerenciar ponteiros de pilha.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

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

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeapPtr::CHeapPtr](#cheapptr)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeapPtr::Alocar](#allocate)|Chame este método para alocar memória no heap para armazenar objetos.|
|[CHeapPtr::Realocação](#reallocate)|Chame este método para realocar a memória no monte.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeapPtr::operador =](#operator_eq)|O operador de atribuição.|

## <a name="remarks"></a>Comentários

`CHeapPtr`é derivado de [CHeapPtrBase](../../atl/reference/cheapptrbase-class.md) e, por padrão, usa as rotinas de CRT (no [CCRTAllocator)](../../atl/reference/ccrtallocator-class.md)para alocar e liberar a memória. A classe [CHeapPtrList](../../atl/reference/cheapptrlist-class.md) pode ser usada para construir uma lista de ponteiros de pilha. Consulte também [CComHeapPtr](../../atl/reference/ccomheapptr-class.md), que usa rotinas de alocação de memória COM.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cheapptrbase](../../atl/reference/cheapptrbase-class.md)

`CHeapPtr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

## <a name="cheapptrallocate"></a><a name="allocate"></a>CHeapPtr::Alocar

Chame este método para alocar memória no heap para armazenar objetos.

```
bool Allocate(size_t nElements = 1) throw();
```

### <a name="parameters"></a>Parâmetros

*nElementos*<br/>
O número de elementos usados para calcular a quantidade de memória a alocar. O valor padrão é 1.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se a memória foi alocada com sucesso, falsa em falha.

### <a name="remarks"></a>Comentários

As rotinas alocadoras são usadas para reservar memória suficiente no heap para armazenar objetos *nElement* de um tipo definido no construtor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#77](../../atl/codesnippet/cpp/cheapptr-class_1.cpp)]

## <a name="cheapptrcheapptr"></a><a name="cheapptr"></a>CHeapPtr::CHeapPtr

O construtor.

```
CHeapPtr() throw();
explicit CHeapPtr(T* p) throw();
CHeapPtr(CHeapPtr<T, Allocator>& p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Um ponteiro de `CHeapPtr`pilha existente ou .

### <a name="remarks"></a>Comentários

O ponteiro de pilha pode ser criado opcionalmente `CHeapPtr` usando um ponteiro existente ou um objeto. Nesse caso, o `CHeapPtr` novo objeto assume a responsabilidade de gerenciar o novo ponteiro e os recursos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#78](../../atl/codesnippet/cpp/cheapptr-class_2.cpp)]

## <a name="cheapptroperator-"></a><a name="operator_eq"></a>CHeapPtr::operador =

Operador de atribuição.

```
CHeapPtr<T, Allocator>& operator=(
    CHeapPtr<T, Allocator>& p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Um objeto `CHeapPtr` existente.

### <a name="return-value"></a>Valor retornado

Retorna uma referência `CHeapPtr`à atualização .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#80](../../atl/codesnippet/cpp/cheapptr-class_3.cpp)]

## <a name="cheapptrreallocate"></a><a name="reallocate"></a>CHeapPtr::Realocação

Chame este método para realocar a memória no monte.

```
bool Reallocate(size_t nElements) throw();
```

### <a name="parameters"></a>Parâmetros

*nElementos*<br/>
O novo número de elementos usados para calcular a quantidade de memória para alocar.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se a memória foi alocada com sucesso, falsa em falha.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#79](../../atl/codesnippet/cpp/cheapptr-class_4.cpp)]

## <a name="see-also"></a>Confira também

[Classe CHeapptrBase](../../atl/reference/cheapptrbase-class.md)<br/>
[Classe CCRTAlocador](../../atl/reference/ccrtallocator-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
