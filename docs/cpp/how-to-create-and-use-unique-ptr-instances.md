---
title: 'Como: Criar e usar instâncias unique_ptr'
ms.custom: how-to
ms.date: 11/19/2018
ms.topic: conceptual
ms.assetid: 9a373030-e587-452f-b9a5-c5f9d58b7673
ms.openlocfilehash: 48e459b69592bf4c231407c2a378a7b7e01ff4ae
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62153640"
---
# <a name="how-to-create-and-use-uniqueptr-instances"></a>Como: Criar e usar instâncias unique_ptr

Um [unique_ptr](../standard-library/unique-ptr-class.md) não compartilha seu ponteiro. Ele não pode ser copiado para outro `unique_ptr`, passado por valor para uma função ou usado em qualquer algoritmo da biblioteca padrão C++ que exija que cópias sejam feitas. Um `unique_ptr` só pode ser movido. Isso significa que a propriedade do recurso de memória é transferida para outro `unique_ptr` e que o `unique_ptr` original não a possui mais. É recomendável que você restrinja um objeto a um proprietário, porque a propriedade múltipla adiciona complexidade à lógica do programa. Portanto, quando você precisa um ponteiro inteligente para um simples C++ do objeto, use `unique_ptr`, e quando você construir um `unique_ptr`, use o [make_unique](../standard-library/memory-functions.md#make_unique) função auxiliar.

O diagrama a seguir ilustra a transferência de propriedade entre duas instâncias de `unique_ptr`.

![Movendo a propriedade de um único&#95;ptr](../cpp/media/unique_ptr.png "movendo a propriedade de um único&#95;ptr")

`unique_ptr` é definido no `<memory>` cabeçalho na biblioteca padrão C++. Ele é exatamente tão eficiente quanto um ponteiro bruto e pode ser usado em contêineres da biblioteca padrão C++. A adição de `unique_ptr` instâncias para contêineres da biblioteca padrão C++ é eficiente porque o construtor de movimentação do `unique_ptr` elimina a necessidade de uma operação de cópia.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como criar instâncias de `unique_ptr` e passá-las entre as funções.

[!code-cpp[stl_smart_pointers#210](../cpp/codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_1.cpp)]

Esses exemplos demonstram esta característica básica de `unique_ptr`: pode ser movido, mas não copiado. “Mover” transfere a propriedade a um novo `unique_ptr` e redefine o `unique_ptr` antigo.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como criar instâncias de `unique_ptr` e usá-las em um vetor.

[!code-cpp[stl_smart_pointers#211](../cpp/codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_2.cpp)]

No intervalo do loop, observe que `unique_ptr` é passado por referência. Se você tentar passar por valor aqui, o compilador lançará um erro porque o construtor de cópia `unique_ptr` foi excluído.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como inicializar um `unique_ptr` que é membro da classe.

[!code-cpp[stl_smart_pointers#212](../cpp/codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_3.cpp)]

## <a name="example"></a>Exemplo

Você pode usar [make_unique](../standard-library/memory-functions.md#make_unique) para criar um `unique_ptr` em uma matriz, mas não é possível usar `make_unique` para inicializar os elementos da matriz.

[!code-cpp[stl_smart_pointers#213](../cpp/codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_4.cpp)]

Para obter mais exemplos, consulte [make_unique](../standard-library/memory-functions.md#make_unique).

## <a name="see-also"></a>Consulte também

[Ponteiros inteligentes (C++ moderno)](../cpp/smart-pointers-modern-cpp.md)<br/>
[make_unique](../standard-library/memory-functions.md#make_unique)
