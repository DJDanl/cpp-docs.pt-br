---
title: Notação de conversão e introdução de safe_cast&lt; &gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- casting
- C-style casts and /clr, motivation for new cast notation
- safe_cast keyword [C++]
ms.assetid: 4eb1d000-3b93-4394-a37b-8b8563f8dc4d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 88e8165bde08b65b4f078c4b48863c2088132fca
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46427856"
---
# <a name="cast-notation-and-introduction-of-safecastltgt"></a>Notação de conversão e introdução de safe_cast&lt;&gt;

A notação de conversão foi alterado de extensões gerenciadas para C++ para Visual C++.

Modificar uma estrutura existente é uma experiência diferente e mais difícil de criar a estrutura inicial. Há menos graus de liberdade e a solução tende a um meio-termo entre uma reestruturação ideal e o que é for praticável de acordo fornecido as dependências estruturais existentes.

Extensão da linguagem é outro exemplo. Volta na década de 1990 antecipada programação orientada a objetos se tornou um importante paradigma, a necessidade de um recurso de tipo seguro baixá-los em C++ tornou-se urgentes. Baixar é a conversão explícita de usuário de uma classe base de ponteiro ou referência a um ponteiro ou referência de uma classe derivada. Baixar requer uma conversão explícita. O motivo é que o tipo real do ponteiro de classe base é um aspecto do tempo de execução; o compilador, portanto, não é possível verificá-lo. Ou, para reformular que, um recurso de baixá-los, assim como uma chamada de função virtual, requer alguma forma de resolução dinâmica. Isso gera duas perguntas:

- Por que um downcast é necessário no paradigma orientado a objeto? Não é o mecanismo de função virtual suficiente? Ou seja, por que não é uma declaração que qualquer necessidade de um downcast (ou uma conversão de qualquer tipo) é uma falha de design?

- Por que o suporte de um downcast deve ser um problema no C++? Afinal, não é um problema em linguagens orientadas a objeto, como o Smalltalk (ou, subsequentemente, Java e c#)? O que é sobre o C++ que faz com que dão suporte a um recurso downcast difícil?

Uma função virtual representa um algoritmo de dependentes de tipo comum para uma família de tipos. (Estamos não considerando interfaces, que não têm suporte no ISO-c, mas estão disponíveis na programação de CLR e que representam uma alternativa interessante de design). O design dessa família normalmente é representado por uma hierarquia de classe em que há uma classe base abstrata declarar a interface comum (funções virtuais) e um conjunto de classes derivadas concretas que representam os tipos de família reais no aplicativo domínio.

Um `Light` hierarquia em um domínio de aplicativo computador gerado imagens (CGI), por exemplo, terá como atributos comuns `color`, `intensity`, `position`, `on`, `off`e assim por diante. Um pode controlar várias luzes, usando a interface comum, sem se preocupar se uma luz específica é um destaque, uma luz direcional, uma luz de não-direcional (Imagine o sol) ou talvez uma luz celeiro-door. Nesse caso, baixar até um determinado tipo de luz para exercitar seu interface virtual é desnecessária. No entanto, em um ambiente de produção, velocidade é essencial. Um pode baixá-los e invocar explicitamente cada método se, fazendo isso, a execução embutida das chamadas pode ser executada em vez de usar o mecanismo virtual.

Portanto, é um motivo para baixá-los em C++ para suprimir o mecanismo virtual como compensação por um ganho significativo no desempenho de tempo de execução. (Observe que a automação dessa otimização manual é uma área ativa de pesquisa. No entanto, é mais difícil de resolver que substituir o uso explícito do `register` ou `inline` palavra-chave.)

Uma segunda razão para baixá-los de fica sem a dupla natureza de polimorfismo. Uma maneira de pensar polimorfismo está sendo dividida em um par de passivo e dinâmico dos formulários.

Uma invocação virtual (e um recurso downcast) representam usa dinâmica de polimorfismo: um está executando uma ação com base no tipo real no ponteiro de classe base àquela instância específica na execução do programa.

No entanto, a atribuição de um objeto de classe derivada em ponteiro sua classe base, é uma forma passiva de polimorfismo; ele está usando o polimorfismo como um mecanismo de transporte. Este é o principal uso de `Object`, por exemplo, na programação de CLR previamente genérica. Quando usado passivamente, o ponteiro de classe base escolhido para o transporte e armazenamento normalmente oferece uma interface que é muito, abstrata. `Object`, por exemplo, fornece aproximadamente cinco métodos por meio da interface; qualquer comportamento mais específico requer uma explícita baixá-los. Por exemplo, se quisermos ajustar o ângulo da nossa área de destaque ou sua taxa de outono desativado, teríamos para baixá-los explicitamente. Uma interface virtual dentro de uma família de subtipos practicably não pode ser um superconjunto de todos os métodos possíveis de seus filhos muitos e, portanto, um recurso downcast sempre serão necessários dentro de uma linguagem orientada a objeto.

Se um cofre downcast recurso é necessário em uma linguagem orientada a objeto, em seguida, por que ele levou C++ tanto tempo para adicionar um? O problema está em como disponibilizar as informações sobre o tipo de tempo de execução do ponteiro. No caso de uma função virtual, as informações de tempo de execução estão configuradas em duas partes pelo compilador:

- O objeto de classe contém um membro do ponteiro de tabela virtual adicional (no início ou no final do objeto da classe; que tem uma história interessante em si) que aborda a tabela virtual apropriada. Por exemplo, um objeto de destaque endereços uma tabela virtual de destaque, uma luz direcional, uma tabela virtual de luz direcional e assim por diante

- Cada função virtual possui um tipo fixo de slot na tabela e a instância real para invocar é representada por endereço armazenado dentro da tabela. Por exemplo, o virtual `Light` destruidor pode ser associado ao slot 0, `Color` com o slot 1 e assim por diante. Isso é uma estratégia eficiente se inflexíveis, porque ele é configurado em tempo de compilação e representa uma sobrecarga mínima.

O problema, em seguida, é como disponibilizar as informações de tipo para o ponteiro sem alterar o tamanho de ponteiros de C++, adicionando um segundo endereço ou adicionando diretamente a algum tipo de codificação de tipo. Isso não seria aceitável para os programadores (e programas) que decidir não usar o paradigma orientado a objeto - ainda era a comunidade de usuários predominante. Outra possibilidade era apresentar um ponteiro especial para tipos de classe polimórfica, mas isso seria confuso e dificultar a combinação entre os dois, particularmente com problemas de aritmética de ponteiro. Ele também não seria aceitável para manter uma tabela de tempo de execução que associa cada ponteiro de seu tipo associado no momento e atualizando-o dinamicamente.

O problema, em seguida, é um par de comunidades de usuários que têm diferentes, mas legítimos às aspirações programação. A solução deve ser um meio-termo entre as duas comunidades, permitindo que cada um, não apenas seu aspiração, mas a capacidade de interoperar. Isso significa que as soluções oferecidas por ambos os lados são provavelmente inviável e a solução é implementada, por fim, ser menor que perfeito. A resolução real gira em torno de definição de uma classe polimórfica: uma classe polimórfica é aquele que contém uma função virtual. Uma classe polimórfica dá suporte a um cofre tipo dinâmico baixá-los. Isso resolve o problema de manter-the--como-endereço de ponteiro, porque todas as classes polimórficas contém esse membro do ponteiro adicional para a tabela virtual associada. As informações de tipo associado, portanto, podem ser armazenadas em uma estrutura de tabela virtual expandido. O custo de fortemente tipados downcast (quase) está localizado para os usuários do recurso.

O próximo problema com o downcast de tipo seguro foi sua sintaxe. Porque é uma conversão, a proposta original para o Comitê de ISO-c + + usado a sintaxe de conversão não adornado, como neste exemplo:

```
spot = ( SpotLight* ) plight;
```

mas isso foi rejeitado pelo Comitê de porque ele não permitiu que o usuário controle o custo da conversão. Se dinâmico fortemente tipados downcast tem a mesma sintaxe que anteriormente não seguro, mas estático notação de conversão, em seguida, ele se torna uma substituição, e o usuário não tem capacidade suprimir a sobrecarga de tempo de execução quando ele é desnecessário e talvez muito cara.

Em geral, em C++, sempre há um mecanismo pelo qual se suprimir a funcionalidade com suporte do compilador. Por exemplo, podemos desativá-la o mecanismo virtual usando o operador de escopo de classe (`Box::rotate(angle)`) ou invocando o método virtual por meio de um objeto de classe (em vez de um ponteiro ou referência de classe). Esse último supressão não é necessário pelo idioma, mas é uma qualidade de problema de implementação, semelhante a supressão da construção de um temporário em uma declaração do formulário:

```
// compilers are free to optimize away the temporary
X x = X::X( 10 );
```

Portanto, a proposta foi levada de volta para fazer mais considerações e várias notações alternativas foram consideradas e aquela trazidas de volta para o comitê estava no formato (`?type`), que indicou indeterminado - ou seja, a natureza dinâmica. Isso forneceu o usuário a capacidade de alternar entre as duas formas - estáticas ou dinâmicas - mas ninguém estava muito satisfeito com ele. Portanto, ele foi volta à prancheta de desenho. A notação de terceira e bem-sucedida é o agora padrão `dynamic_cast<type>`, que foi generalizado para um conjunto de quatro notações de novo estilo cast.

No ISO-c `dynamic_cast` retorna `0` quando aplicado a um tipo de ponteiro inadequado e lança um `std::bad_cast` exceção quando aplicado a um tipo de referência. Nas extensões gerenciadas para C++, aplicando `dynamic_cast` para um tipo de referência gerenciada (por causa de sua representação de ponteiro) sempre retornado `0`. `__try_cast<type>` foi introduzido como um análogo à exceção lançando variante do `dynamic_cast`, exceto que ele gera `System::InvalidCastException` se a conversão falhar.

```
public __gc class ItemVerb;
public __gc class ItemVerbCollection {
public:
   ItemVerb *EnsureVerbArray() [] {
      return __try_cast<ItemVerb *[]>
         (verbList->ToArray(__typeof(ItemVerb *)));
   }
};
```

Na nova sintaxe `__try_cast` foi reconvertida como `safe_cast`. Aqui está o mesmo fragmento de código na nova sintaxe:

```
public ref class ItemVerb;
public ref class ItemVerbCollection {
public:
   array<ItemVerb^>^ EnsureVerbArray() {
      return safe_cast<array<ItemVerb^>^>
         ( verbList->ToArray( ItemVerb::typeid ));
   }
};
```

No mundo gerenciado, é importante permitir código verificável, limitando a capacidade de programadores de conversão entre tipos de maneiras que deixar o código não verificável. Isso é um aspecto importante do que o paradigma de programação dinâmico representado pela nova sintaxe. Por esse motivo, instâncias de conversões de estilo antigo são reconvertidas internamente como conversões de tempo de execução, portanto, que, por exemplo:

```
// internally recast into the
// equivalent safe_cast expression above
( array<ItemVerb^>^ ) verbList->ToArray( ItemVerb::typeid );
```

Por outro lado, porque o polimorfismo fornece um ativo e um modo passivo, às vezes, é necessário executar um lançamento decrescente apenas para acessar a API não virtual de um subtipo. Isso pode ocorrer, por exemplo, com os membros de uma classe que desejo abordar qualquer tipo dentro da hierarquia (passivo polimorfismo como um mecanismo de transporte), mas para o qual a instância real em um contexto específico do programa é conhecida. Nesse caso, a ter uma verificação de tempo de execução da conversão pode ser uma sobrecarga inaceitável. Se a nova sintaxe é servir como os linguagem de programação de sistemas gerenciados, ele deve fornecer alguns meios de permitir que um tempo de compilação (isto é, estáticas) baixá-los. É por isso que o aplicativo do `static_cast` notação pode permanecer um tempo de compilação baixá-los:

```
// ok: cast performed at compile-time.
// No run-time check for type correctness
static_cast< array<ItemVerb^>^>(verbList->ToArray(ItemVerb::typeid));
```

O problema é que não há nenhuma maneira de garantir que o programador fazendo o `static_cast` está correto e bem-intencionados; ou seja, não há nenhuma maneira de forçar o código gerenciado seja verificável. Isso é uma preocupação mais urgente no paradigma dinâmico do programa que sob nativo, mas não é suficiente dentro de um sistema a capacidade de alternar entre um estático e conversão de tempo de execução de linguagem para impedir que o usuário de programação.

Há uma interceptação de desempenho e a armadilha na nova sintaxe, no entanto. Na programação nativa, não há nenhuma diferença no desempenho entre a notação de conversão de estilo antigo e o novo estilo `static_cast` notação. Mas, na nova sintaxe, a notação de conversão de estilo antigo é significativamente mais cara do que o uso do novo estilo `static_cast` notação. O motivo é que o compilador transforma internamente o uso da notação de estilo antigo em uma verificação de tempo de execução que gera uma exceção. Além disso, ele também altera o perfil de execução do código porque ele faz com que uma exceção não percebida trazer o aplicativo – talvez sabiamente, mas o mesmo erro não faria com que essa exceção se o `static_cast` notação foram usados. Alguém pode perguntar isso o ajudará a prod usuários em usando a notação de estilo de novo. Mas somente quando ele falha; Caso contrário, ela fará com que os programas que usam a notação de estilo antigo seja executado mais lentamente sem uma compreensão visível do porquê, semelhante para as seguintes armadilhas do programador de C:

```
// pitfall # 1:
// initialization can remove a temporary class object,
// assignment cannot
Matrix m;
m = another_matrix;

// pitfall # 2: declaration of class objects far from their use
Matrix m( 2000, 2000 ), n( 2000, 2000 );
if ( ! mumble ) return;
```

## <a name="see-also"></a>Consulte também

[Alterações gerais na linguagem (C++/CLI)](../dotnet/general-language-changes-cpp-cli.md)<br/>
[Conversões C-Style com /clr (C + + / CLI)](../windows/c-style-casts-with-clr-cpp-cli.md)<br/>
[Safe_cast](../windows/safe-cast-cpp-component-extensions.md)