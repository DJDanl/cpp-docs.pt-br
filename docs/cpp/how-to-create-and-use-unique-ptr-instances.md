---
title: Como criar e usar instâncias de unique_ptr
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
# <a name="how-to-create-and-use-unique_ptr-instances"></a>Como criar e usar instâncias de unique_ptr

Um [unique_ptr](../standard-library/unique-ptr-class.md) não compartilha seu ponteiro. Ele não pode ser copiado para outro `unique_ptr`, passado pelo valor para uma função ou usado em C++ qualquer algoritmo de biblioteca padrão que exija a tomada de cópias. Um `unique_ptr` só pode ser movido. Isso significa que a propriedade do recurso de memória é transferida para outro `unique_ptr` e que o `unique_ptr` original não a possui mais. É recomendável que você restrinja um objeto a um proprietário, porque a propriedade múltipla adiciona complexidade à lógica do programa. Portanto, quando você precisar de um ponteiro inteligente para um C++ objeto simples, use `unique_ptr`e, ao construir um `unique_ptr`, use a função auxiliar [make_unique](../standard-library/memory-functions.md#make_unique) .

O diagrama a seguir ilustra a transferência de propriedade entre duas instâncias de `unique_ptr`.

![Movendo a propriedade de um PTR&#95;exclusivo](media/unique_ptr.png "Movendo a propriedade de um PTR&#95;exclusivo")

`unique_ptr` é definido no cabeçalho `<memory>` na biblioteca C++ padrão. Ele é exatamente tão eficiente quanto um ponteiro bruto e pode ser usado em C++ contêineres de biblioteca padrão. A adição de instâncias de `unique_ptr` C++ para contêineres de biblioteca padrão é eficiente porque o construtor de movimentação do `unique_ptr` elimina a necessidade de uma operação de cópia.

## <a name="example-1"></a>Exemplo 1

O exemplo a seguir mostra como criar instâncias de `unique_ptr` e passá-las entre as funções.

[!code-cpp[stl_smart_pointers#210](codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_1.cpp)]

Esses exemplos demonstram esta característica básica de `unique_ptr`: pode ser movido, mas não copiado. “Mover” transfere a propriedade a um novo `unique_ptr` e redefine o `unique_ptr` antigo.

## <a name="example-2"></a>Exemplo 2

O exemplo a seguir mostra como criar instâncias de `unique_ptr` e usá-las em um vetor.

[!code-cpp[stl_smart_pointers#211](codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_2.cpp)]

No intervalo do loop, observe que `unique_ptr` é passado por referência. Se você tentar passar por valor aqui, o compilador lançará um erro porque o construtor de cópia `unique_ptr` foi excluído.

## <a name="example-3"></a>Exemplo 3

O exemplo a seguir mostra como inicializar um `unique_ptr` que é membro da classe.

[!code-cpp[stl_smart_pointers#212](codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_3.cpp)]

## <a name="example-4"></a>Exemplo 4

Você pode usar [make_unique](../standard-library/memory-functions.md#make_unique) para criar um `unique_ptr` a uma matriz, mas não pode usar `make_unique` para inicializar os elementos da matriz.

[!code-cpp[stl_smart_pointers#213](codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_4.cpp)]

Para obter mais exemplos, consulte [make_unique](../standard-library/memory-functions.md#make_unique).

## <a name="see-also"></a>Consulte também

[Ponteiros inteligentes (C++ moderno)](smart-pointers-modern-cpp.md)<br/>
[make_unique](../standard-library/memory-functions.md#make_unique)
