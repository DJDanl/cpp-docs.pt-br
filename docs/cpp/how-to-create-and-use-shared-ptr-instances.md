---
title: 'Como: Criar e usar instâncias shared_ptr'
ms.custom: how-to
ms.date: 11/19/2018
ms.topic: conceptual
ms.assetid: 7d6ebb73-fa0d-4b0b-a528-bf05de96518e
ms.openlocfilehash: 8363139efddb2fa64057fdb995ab7bd5dfbcfd9b
ms.sourcegitcommit: a1fad0a266b20b313364a74b16c9ac45d089b1e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/11/2019
ms.locfileid: "54220589"
---
# <a name="how-to-create-and-use-sharedptr-instances"></a>Como: Criar e usar instâncias shared_ptr

O `shared_ptr` tipo é um ponteiro inteligente na biblioteca padrão C++ que foi projetado para cenários em que mais de um proprietário pode ter que gerenciar o tempo de vida do objeto na memória. Depois de inicializar uma `shared_ptr` copiá-lo, passá-lo pelo valor em argumentos de função e atribuí-la a outro `shared_ptr` instâncias. Todas as instâncias de apontar para o mesmo objeto e compartilhar o acesso a um "bloco de controle" que incrementa e decrementa a contagem de referência sempre que um novo `shared_ptr` é adicionado, sai do escopo ou é redefinido. Quando a contagem de referência atinge zero, o bloco de controle exclui o recurso de memória e ela mesma.

A ilustração a seguir mostra várias `shared_ptr` instâncias que apontam para um local de memória.

![Diagrama de ponteiro compartilhado](../cpp/media/shared_ptr.png "diagrama de ponteiro compartilhado")

## <a name="example-1"></a>Exemplo 1

Sempre que possível, use o [make_shared](../standard-library/memory-functions.md#make_shared) função para criar um `shared_ptr` quando o recurso de memória é criado pela primeira vez. `make_shared` é à prova de exceções. Ele usa a mesma chamada para alocar a memória para o bloco de controle e o recurso e, assim, reduz a sobrecarga de construção. Se você não usar `make_shared`, em seguida, você precisa usar uma expressão explícita de novo para criar o objeto antes de transmiti-lo para o `shared_ptr` construtor. O exemplo a seguir mostra várias maneiras de declarar e inicializar um `shared_ptr` junto com um novo objeto.

[!code-cpp[stl_smart_pointers#1](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_1.cpp)]

## <a name="example-2"></a>Exemplo 2

O exemplo a seguir mostra como declarar e inicializar `shared_ptr` instâncias que assumir a propriedade compartilhada de um objeto que já foi alocado por outro `shared_ptr`. Suponha que `sp2` é um inicializado `shared_ptr`.

[!code-cpp[stl_smart_pointers#2](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_2.cpp)]

## <a name="example-3"></a>Exemplo 3:

`shared_ptr` também é útil em contêineres da biblioteca padrão C++ quando você estiver usando algoritmos que copiar elementos. Você pode encapsular os elementos em um `shared_ptr`e, em seguida, copiá-lo para outros contêineres com o entendimento de que a memória subjacente é válido desde que você precisa e não está mais. O exemplo a seguir mostra como usar o `replace_copy_if` algoritmo em `shared_ptr` instâncias em um vetor.

[!code-cpp[stl_smart_pointers#4](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_3.cpp)]

## <a name="example-4"></a>Exemplo 4

Você pode usar `dynamic_pointer_cast`, `static_pointer_cast`, e `const_pointer_cast` converter um `shared_ptr`. Essas funções se parecer com o `dynamic_cast`, `static_cast`, e `const_cast` operadores. O exemplo a seguir mostra como testar o tipo derivado de cada elemento em um vetor de `shared_ptr` de classes, base e, em seguida, copiar os elementos e exibir informações sobre eles.

[!code-cpp[stl_smart_pointers#5](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_4.cpp)]

## <a name="example-5"></a>Exemplo 5

Você pode passar um `shared_ptr` para outra função das seguintes maneiras:

- Passar o `shared_ptr` por valor. Isso invoca o construtor de cópia, incrementa a contagem de referência e torna o receptor um proprietário. Há uma pequena quantidade de sobrecarga nessa operação, que pode ser significativa, dependendo de quantos `shared_ptr` objetos que você está passando. Use essa opção quando o contrato de código (implícito ou explícito) entre o chamador e o receptor requer que o receptor seja um proprietário.

- Passar o `shared_ptr` por referência ou uma referência const. Nesse caso, a contagem de referência não é incrementada e o receptor pode acessar o ponteiro, desde que o chamador não saem do escopo. Ou, o receptor pode optar por criar um `shared_ptr` com base na referência e, portanto, se tornar um proprietário compartilhado. Use esta opção quando o chamador não tem conhecimento do receptor, ou quando você deve passar um `shared_ptr` e quiser evitar a operação de cópia por motivos de desempenho.

- Passe o ponteiro subjacente ou uma referência ao objeto subjacente. Isso permite que o receptor usar o objeto, mas não habilitá-la compartilhar a propriedade ou estender o tempo de vida. Se o receptor cria uma `shared_ptr` de ponteiro bruto, o novo `shared_ptr` é independente do original e não controla o recurso subjacente. Use essa opção quando o contrato entre o chamador e o receptor claramente Especifica que o chamador retém a propriedade do `shared_ptr` tempo de vida.

- Ao decidir como passar um `shared_ptr`, determinar se o receptor deve compartilhar a propriedade do recurso subjacente. Um "proprietário" é um objeto ou função que pode manter o recurso subjacente ativas para desde que ele precisa. Se o chamador deve garantir que o receptor pode estender a vida útil do ponteiro além do seu tempo de vida (da função), use a primeira opção. Se você não se importa se o receptor estende o tempo de vida, em seguida, passar por referência e permitir que o receptor copiá-lo ou não.

- Se você tiver que fornecem um acesso de função auxiliar para o ponteiro subjacente e você sabe que a função auxiliar apenas usar o ponteiro e retornar antes da função retorna a chamada e, em seguida, essa função não precisa compartilhar a propriedade do ponteiro subjacente. Ele tem apenas acessar o ponteiro de dentro do tempo de vida do chamador `shared_ptr`. Nesse caso, é seguro passar o `shared_ptr` por referência ou passe o ponteiro bruto ou uma referência a subjacentes do objeto. Passando dessa maneira fornece um benefício de desempenho pequeno e também pode ajudar a expressar sua intenção de programação.

- Às vezes, por exemplo em um `std:vector<shared_ptr<T>>`, talvez você precise passar cada `shared_ptr` a um objeto de função nomeada ou o corpo da expressão lambda. Se o lambda ou função não armazena o ponteiro, em seguida, passar o `shared_ptr` por referência para evitar invocar o construtor de cópia para cada elemento.

## <a name="example-6"></a>Exemplo 6

A exemplo a seguir mostra como `shared_ptr` sobrecargas de vários operadores de comparação para habilitar comparações do ponteiro na memória que pertence ao `shared_ptr` instâncias.

[!code-cpp[stl_smart_pointers#3](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_6.cpp)]

## <a name="see-also"></a>Consulte também

[Ponteiros inteligentes (C++ moderno)](../cpp/smart-pointers-modern-cpp.md)
