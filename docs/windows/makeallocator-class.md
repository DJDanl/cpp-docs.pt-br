---
title: Classe MakeAllocator | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::MakeAllocator
dev_langs:
- C++
helpviewer_keywords:
- MakeAllocator class
ms.assetid: a1114615-abd7-4a56-9bc3-750c118f0fa1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 460e2cdef4d0ba4252ceb8a4b7fe6defc25c183a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46375366"
---
# <a name="makeallocator-class"></a>Classe MakeAllocator

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<
   typename T,
   bool hasWeakReferenceSupport =
         !__is_base_of(RuntimeClassFlags<InhibitWeakReference>, T)>
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

Substituir a **MakeAllocator** classe para implementar um modelo de alocação de memória definido pelo usuário.

**MakeAllocator** normalmente é usado para evitar vazamentos de memória, se um objeto gera durante a construção.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor MakeAllocator::MakeAllocator](../windows/makeallocator-makeallocator-constructor.md)|Inicializa uma nova instância dos **MakeAllocator** classe.|
|[Destruidor MakeAllocator::~MakeAllocator](../windows/makeallocator-tilde-makeallocator-destructor.md)|Realiza o desligamento da instância atual do **MakeAllocator** classe.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Método MakeAllocator::Allocate](../windows/makeallocator-allocate-method.md)|Aloca memória e o associa ao atual **MakeAllocator** objeto.|
|[Método MakeAllocator::Detach](../windows/makeallocator-detach-method.md)|Desassocia a memória alocada pelo [Allocate](../windows/makeallocator-allocate-method.md) método atuais **MakeAllocator** objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`MakeAllocator`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)