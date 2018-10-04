---
title: Classe MakeAllocator | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::MakeAllocator
- implements/Microsoft::WRL::Details::MakeAllocator::Allocate
- implements/Microsoft::WRL::Details::MakeAllocator::Detach
- implements/Microsoft::WRL::Details::MakeAllocator::MakeAllocator
- implements/Microsoft::WRL::Details::MakeAllocator::~MakeAllocator
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Details::MakeAllocator class
- Microsoft::WRL::Details::MakeAllocator::Allocate method
- Microsoft::WRL::Details::MakeAllocator::Detach method
- Microsoft::WRL::Details::MakeAllocator::MakeAllocator, constructor
- Microsoft::WRL::Details::MakeAllocator::~MakeAllocator, destructor
ms.assetid: a1114615-abd7-4a56-9bc3-750c118f0fa1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 94c094fe21127592bd8756d0f0b467e2c74df487
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48789235"
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
`true` ao alocar memória para um objeto que dá suporte a referências fracas; `false` alocar memória para um objeto que não dá suporte a referências fracas.

## <a name="remarks"></a>Comentários

Aloca memória para uma classe ativável, com ou sem suporte fraco de referência.

Substituir o `MakeAllocator` classe para implementar um modelo de alocação de memória definido pelo usuário.

`MakeAllocator` normalmente é usado para impedir vazamentos de memória, se um objeto gera durante a construção.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

Nome                                                  | Descrição
----------------------------------------------------- | ----------------------------------------------------------------
[Makeallocator:: Makeallocator](#makeallocator)        | Inicializa uma nova instância da classe `MakeAllocator`.
[MakeAllocator:: ~ MakeAllocator](#tilde-makeallocator) | A instância atual do realiza o desligamento de `MakeAllocator` classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                 | Descrição
------------------------------------ | -----------------------------------------------------------------------------------------------------------
[Makeallocator:: allocate](#allocate) | Aloca memória e o associa ao atual `MakeAllocator` objeto.
[Makeallocator:: Detach](#detach)     | Desassocia a memória alocada pelo [Allocate](#allocate) método atuais `MakeAllocator` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`MakeAllocator`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="allocate"></a>Makeallocator:: allocate

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

## <a name="detach"></a>Makeallocator:: Detach

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
__forceinline void Detach();
```

### <a name="remarks"></a>Comentários

Desassocia a memória alocada pelo [Allocate](#allocate) método atuais `MakeAllocator` objeto.

Se você chamar `Detach()`, você é responsável pela exclusão da memória fornecida pelo `Allocate` método.

## <a name="makeallocator"></a>Makeallocator:: Makeallocator

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
