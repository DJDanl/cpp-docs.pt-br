---
title: Exemplo de Classe de Contêiner
ms.date: 11/04/2016
helpviewer_keywords:
- container classes [C++]
ms.assetid: 5b1451f2-c708-45da-bbf0-9e42fd687a1a
ms.openlocfilehash: 2024574633069cc70f0885fdce63f3afc09227c0
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68451103"
---
# <a name="sample-container-class"></a>Exemplo de Classe de Contêiner

> [!NOTE]
> Este tópico está na documentação da C++ Microsoft como um exemplo não funcional de contêineres usados na biblioteca C++ padrão. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

Descreve um objeto que controla uma sequência de comprimento variável de elementos, normalmente do tipo `Ty`. A sequência é armazenada de diferentes maneiras, dependendo do contêiner real.

Uma função de construtor ou membro de contêiner pode ser a ocasião para chamar o construtor **Ty**(**const Ty&** ) ou a função **Ty::operator=** (**const Ty&** ). Se tal chamada gerar uma exceção, o objeto de contêiner é obrigado a manter sua integridade e a relançar as exceções que ele captura. É possível trocar, atribuir, apagar ou destruir um objeto de contêiner com segurança depois que ele gera uma dessas exceções. Em geral, no entanto, não é possível prever de outra forma o estado da sequência controlada pelo objeto de contêiner.

Algumas limitações adicionais:

- Se a expressão `~Ty` lançar uma exceção, o estado resultante do objeto de contêiner será indefinido.

- Se o contêiner armazenar um objeto de alocador *Al*e *Al* lançar uma exceção diferente de como resultado de uma chamada para `al.allocate`, o estado resultante do objeto de contêiner será indefinido.

- Se o contêiner armazenar um objeto de função *comp*, para determinar como ordenar a sequência controlada, *comp* gera uma exceção de qualquer tipo, o estado resultante do objeto de contêiner é indefinido.

As classes de contêiner definidas pela Biblioteca Padrão C++ satisfazem a vários requisitos adicionais, conforme descrito nos parágrafos a seguir.

A classe de modelo de contêiner [lista](../standard-library/list-class.md) fornece comportamento determinístico e útil, mesmo na presença das exceções descritas acima. Pro exemplo, se uma exceção for gerada durante a inserção de um ou mais elementos, o contêiner permanecerá inalterado e a exceção será gerada novamente.

Para *todas* as classes de contêiner definidas C++ pela biblioteca padrão, se uma exceção for lançada durante chamadas para as seguintes `insert` `push_back`funções de membro,, `push_front`ou, o contêiner for deixado inalterado e a exceção for relançadas.

Para *todas* as classes de contêiner definidas C++ pela biblioteca padrão, nenhuma exceção é lançada durante chamadas para as seguintes funções de `pop_back`membro `pop_front`:,.

A função membro [erase](../standard-library/container-class-erase.md) gera uma exceção apenas se uma operação de cópia (construção de atribuição ou cópia) gerar uma exceção.

Além disso, nenhuma exceção é gerada ao copiar um iterador retornado por uma função membro.

A função de membro [swap](../standard-library/container-class-swap.md) faz promessas adicionais para *todas* as classes de contêiner definidas pela Biblioteca Padrão C++:

- A função de membro gera uma exceção apenas se o contêiner armazenar um objeto al alocador e `al` gera uma exceção quando copiado.

- Referências, ponteiros e iteradores que designam elementos das sequências controladas sendo trocados permanecem válidos.

Um objeto de uma classe de contêiner definido pela Biblioteca Padrão C++ aloca e libera armazenamento para a sequência controlada por meio de um objeto armazenado do tipo `Alloc`, que normalmente é um parâmetro de modelo. Esse objeto de alocador deve ter a mesma interface externa que um objeto de `allocator<Ty>`classe. Em particular, `Alloc` deve ser o mesmo tipo que`Alloc::rebind<value_type>::other`

Para *todas as* classes de contêiner C++ definidas pela biblioteca padrão, a `Alloc get_allocator const;` função membro retorna uma cópia do objeto alocador armazenado. Observe que o objeto alocador armazenado *não* é copiado quando o objeto de contêiner é atribuído. Todos os construtores inicializam o valor armazenado `allocator`em, `Alloc` para se o construtor não contiver nenhum parâmetro de alocador.

Segundo o Padrão C++, uma classe de contêiner definida pela Biblioteca Padrão C++ pode assumir que:

- Todos os objetos da classe `Alloc` são comparados igualmente.

- O `Alloc::const_pointer` tipo é o mesmo `const Ty *`que.

- O `Alloc::const_reference` tipo é o mesmo `const Ty&`que.

- O `Alloc::pointer` tipo é o mesmo `Ty *`que.

- O `Alloc::reference` tipo é o mesmo `Ty&`que.

Nessa implementação, no entanto, os contêineres não fazem essas pressuposições simplistas. Dessa forma, eles funcionam corretamente com objetos alocadores que são mais ambiciosos:

- Todos os objetos da classe `Alloc` não precisa ter comparação igual. (Você pode manter vários pools de armazenamento.)

- O `Alloc::const_pointer` tipo não precisa ser o mesmo que `const Ty *`. (Um ponteiro const pode ser uma classe.)

- O `Alloc::pointer` tipo não precisa ser o mesmo que `Ty *`. (Um ponteiro pode ser uma classe.)

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<sample container>

## <a name="see-also"></a>Consulte também

[\<sample container>](../standard-library/sample-container.md)
