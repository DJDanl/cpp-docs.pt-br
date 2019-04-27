---
title: Classe MakeAllocator
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::MakeAllocator
- implements/Microsoft::WRL::Details::MakeAllocator::Allocate
- implements/Microsoft::WRL::Details::MakeAllocator::Detach
- implements/Microsoft::WRL::Details::MakeAllocator::MakeAllocator
- implements/Microsoft::WRL::Details::MakeAllocator::~MakeAllocator
helpviewer_keywords:
- Microsoft::WRL::Details::MakeAllocator class
- Microsoft::WRL::Details::MakeAllocator::Allocate method
- Microsoft::WRL::Details::MakeAllocator::Detach method
- Microsoft::WRL::Details::MakeAllocator::MakeAllocator, constructor
- Microsoft::WRL::Details::MakeAllocator::~MakeAllocator, destructor
ms.assetid: a1114615-abd7-4a56-9bc3-750c118f0fa1
ms.openlocfilehash: 805f0c09b0490d8cec1a0be96dcb1fc99a051371
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62161232"
---
# <a name="makeallocator-class"></a>Classe MakeAllocator

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<
    typename T,
    bool hasWeakReferenceSupport =
          !__is_base_of(RuntimeClassFlags<InhibitWeakReference>,
                        T)
>
class MakeAllocator;

template<typename T>
class MakeAllocator<T, false>;

template<typename T>
class MakeAllocator<T, true>;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O nome de um tipo.

*hasWeakReferenceSupport*<br/>
**True** alocar memória para um objeto que dá suporte a referências fracas; **falsos** alocar memória para um objeto que não dá suporte a referências fracas.

## <a name="remarks"></a>Comentários

Aloca memória para uma classe ativável, com ou sem suporte fraco de referência.

Substituir o `MakeAllocator` classe para implementar um modelo de alocação de memória definido pelo usuário.

`MakeAllocator` normalmente é usado para impedir vazamentos de memória, se um objeto gera durante a construção.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                  | Descrição
----------------------------------------------------- | ----------------------------------------------------------------
[MakeAllocator::MakeAllocator](#makeallocator)        | Inicializa uma nova instância da classe `MakeAllocator`.
[MakeAllocator:: ~ MakeAllocator](#tilde-makeallocator) | A instância atual do realiza o desligamento de `MakeAllocator` classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                 | Descrição
------------------------------------ | -----------------------------------------------------------------------------------------------------------
[MakeAllocator::Allocate](#allocate) | Aloca memória e o associa ao atual `MakeAllocator` objeto.
[MakeAllocator::Detach](#detach)     | Desassocia a memória alocada pelo [Allocate](#allocate) método atuais `MakeAllocator` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`MakeAllocator`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="allocate"></a>MakeAllocator::Allocate

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
__forceinline void* Allocate();
```

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, um ponteiro para a memória alocada; Caso contrário, `nullptr`.

### <a name="remarks"></a>Comentários

Aloca memória e o associa ao atual `MakeAllocator` objeto.

O tamanho da memória alocada é o tamanho do tipo especificado pelo atual `MakeAllocator` parâmetro de modelo.

Um desenvolvedor precisar substituir apenas a `Allocate()` método para implementar um modelo de alocação de memória diferentes.

## <a name="detach"></a>MakeAllocator::Detach

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
__forceinline void Detach();
```

### <a name="remarks"></a>Comentários

Desassocia a memória alocada pelo [Allocate](#allocate) método atuais `MakeAllocator` objeto.

Se você chamar `Detach()`, você é responsável pela exclusão da memória fornecida pelo `Allocate` método.

## <a name="makeallocator"></a>MakeAllocator::MakeAllocator

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
MakeAllocator();
```

### <a name="remarks"></a>Comentários

Inicializa uma nova instância da classe `MakeAllocator`.

## <a name="tilde-makeallocator"></a>MakeAllocator:: ~ MakeAllocator

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
~MakeAllocator();
```

### <a name="remarks"></a>Comentários

A instância atual do realiza o desligamento de `MakeAllocator` classe.

Este destruidor também exclui a memória alocada subjacente, se necessário.
