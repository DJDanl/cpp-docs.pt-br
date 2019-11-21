---
title: 'How to: Create and use unique_ptr instances'
ms.custom: how-to
ms.date: 11/19/2018
ms.topic: conceptual
ms.assetid: 9a373030-e587-452f-b9a5-c5f9d58b7673
ms.openlocfilehash: 4b3362f71d1ccab0efb03d7e8705c6b3f25f9780
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246531"
---
# <a name="how-to-create-and-use-unique_ptr-instances"></a>How to: Create and use unique_ptr instances

A [unique_ptr](../standard-library/unique-ptr-class.md) does not share its pointer. It cannot be copied to another `unique_ptr`, passed by value to a function, or used in any C++ Standard Library algorithm that requires copies to be made. Um `unique_ptr` só pode ser movido. Isso significa que a propriedade do recurso de memória é transferida para outro `unique_ptr` e que o `unique_ptr` original não a possui mais. É recomendável que você restrinja um objeto a um proprietário, porque a propriedade múltipla adiciona complexidade à lógica do programa. Therefore, when you need a smart pointer for a plain C++ object, use `unique_ptr`, and when you construct a `unique_ptr`, use the [make_unique](../standard-library/memory-functions.md#make_unique) helper function.

O diagrama a seguir ilustra a transferência de propriedade entre duas instâncias de `unique_ptr`.

![Moving the ownership of a unique&#95;ptr](media/unique_ptr.png "Moving the ownership of a unique&#95;ptr")

`unique_ptr` is defined in the `<memory>` header in the C++ Standard Library. It is exactly as efficient as a raw pointer and can be used in C++ Standard Library containers. The addition of `unique_ptr` instances to C++ Standard Library containers is efficient because the move constructor of the `unique_ptr` eliminates the need for a copy operation.

## <a name="example-1"></a>Exemplo 1

O exemplo a seguir mostra como criar instâncias de `unique_ptr` e passá-las entre as funções.

[!code-cpp[stl_smart_pointers#210](codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_1.cpp)]

Esses exemplos demonstram esta característica básica de `unique_ptr`: pode ser movido, mas não copiado. “Mover” transfere a propriedade a um novo `unique_ptr` e redefine o `unique_ptr` antigo.

## <a name="example-2"></a>Exemplo 2

O exemplo a seguir mostra como criar instâncias de `unique_ptr` e usá-las em um vetor.

[!code-cpp[stl_smart_pointers#211](codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_2.cpp)]

No intervalo do loop, observe que `unique_ptr` é passado por referência. Se você tentar passar por valor aqui, o compilador lançará um erro porque o construtor de cópia `unique_ptr` foi excluído.

## <a name="example-3"></a>Exemplo 3:

O exemplo a seguir mostra como inicializar um `unique_ptr` que é membro da classe.

[!code-cpp[stl_smart_pointers#212](codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_3.cpp)]

## <a name="example-4"></a>Exemplo 4

You can use [make_unique](../standard-library/memory-functions.md#make_unique) to create a `unique_ptr` to an array, but you cannot use `make_unique` to initialize the array elements.

[!code-cpp[stl_smart_pointers#213](codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_4.cpp)]

For more examples, see [make_unique](../standard-library/memory-functions.md#make_unique).

## <a name="see-also"></a>Consulte também

[Ponteiros inteligentes (C++ moderno)](smart-pointers-modern-cpp.md)<br/>
[make_unique](../standard-library/memory-functions.md#make_unique)
