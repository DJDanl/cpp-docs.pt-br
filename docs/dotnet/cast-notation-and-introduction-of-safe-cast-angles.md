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
ms.openlocfilehash: 6b9432b40099f9893d7fd270faf5375646fb0493
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33111634"
---
# <a name="cast-notation-and-introduction-of-safecastltgt"></a>Notação de conversão e introdução de safe_cast&lt;&gt;
A notação de conversão foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
 Modificar uma estrutura existente é uma experiência diferente e mais difícil de criar a estrutura inicial. Há menos graus de liberdade e tende a solução para um compromisso entre uma reestruturação ideal e o que é for praticável de acordo recebe as dependências estruturais existentes.  
  
 Extensão de idioma é outro exemplo. Na década de 1990 antecipado como a orientação de objeto de programação se tornou uma paradigma importante, a necessidade de um recurso de segurança de tipo baixá-los em C++ tornou-se pressionando. Baixar é a conversão explícita do usuário de um ponteiro de classe base ou uma referência a um ponteiro ou referência de uma classe derivada. Baixar requer uma conversão explícita. O motivo é que o tipo real do ponteiro de classe base é um aspecto do tempo de execução; o compilador, portanto, não é possível verificar. Ou, para reformular que, um recurso de baixá-los, assim como uma chamada de função virtual requer alguma forma de resolução dinâmica. Isso gera duas perguntas:  
  
-   Por que deve um rebaixada ser necessário no paradigma orientada a objeto? Não é o mecanismo de função virtual suficiente? Isto é, por que não é uma declaração necessidade de um lançamento decrescente (ou uma conversão de qualquer tipo) é uma falha de design?  
  
-   Por que o suporte de um lançamento decrescente deve ser um problema em C++? Afinal, não é um problema em idiomas orientada a objeto, como Smalltalk (ou, em seguida, Java e c#)? O que é sobre C++ que faz com que um recurso de baixá-los difíceis de suporte?  
  
 Uma função virtual representa um algoritmo de tipo dependente comuns para uma família de tipos. (Estamos não considerando as interfaces, que não têm suporte no ISO C++, mas estão disponíveis na programação de CLR e que representam uma alternativa de design interessante). O design da família normalmente é representado por uma hierarquia de classe em que há uma classe base abstrata declarar a interface comum (funções virtuais) e um conjunto de classes derivadas concretas que representam os tipos de família reais no aplicativo domínio.  
  
 Um `Light` hierarquia em um domínio de aplicativo computador gerado imagens CGI (), por exemplo, ter atributos comuns, como `color`, `intensity`, `position`, `on`, `off`e assim por diante. Uma pode controlar vários luzes, usando a interface comum sem se preocupar se uma determinada luz é um destaque, uma luz direcional, uma não-direcional luz (Imagine a sun) ou talvez clara celeiro porta. Nesse caso, baixar para um tipo específico de luz para exercer sua interface virtual é desnecessária. No entanto, em um ambiente de produção, velocidade é essencial. Um pode baixá-los e chamar explicitamente cada método se fazendo isso embutido execução das chamadas pode ser executada em vez de usar o mecanismo virtual.  
  
 Portanto, é um motivo para baixá-los em C++ para suprimir o mecanismo virtual em troca de um ganho significativo no desempenho de tempo de execução. (Observe que a automação dessa otimização manual é uma área ativa de pesquisa. No entanto, é mais difícil de resolver que substitui o uso explícito do `register` ou `inline` palavra-chave.)  
  
 Uma segunda razão para baixá-los está fora da natureza dupla do polimorfismo. Uma maneira de pensar polimorfismo está sendo dividida em um par de passivo e dinâmico de formulários.  
  
 Uma invocação virtual (e um recurso de baixá-los) representam usa dinâmica de polimorfismo: uma é executar uma ação com base no tipo real do ponteiro de classe base nessa instância específica na execução do programa.  
  
 No entanto, a atribuição de um objeto de classe derivada para o ponteiro de classe base, é uma forma passiva de polimorfismo; ele está usando o polimorfismo como um mecanismo de transporte. Este é o principal uso de `Object`, por exemplo, na programação de CLR previamente genérica. Quando usado passivamente, o ponteiro de classe base escolhido para o transporte e armazenamento normalmente oferece uma interface que é muito abstrata. `Object`, por exemplo, fornece aproximadamente cinco métodos através de sua interface; qualquer comportamento mais específico requer uma explícita baixá-los. Por exemplo, se quisermos ajustar o ângulo de nosso destaque ou sua taxa de fallback off, podemos precisaria baixá-los explicitamente. Uma interface virtual dentro de uma família de subtipos practicably não pode ser um superconjunto de todos os métodos possíveis de seus filhos muitos, e assim um recurso downcast sempre será necessário dentro de uma linguagem orientada a objeto.  
  
 Se um cofre baixá-los de recurso é necessária em uma linguagem orientada a objeto, então por que demorou C++ muito tempo para adicionar um? O problema está em como disponibilizar as informações sobre o tipo de tempo de execução do ponteiro. No caso de uma função virtual, as informações de tempo de execução estão configuradas de duas partes pelo compilador:  
  
-   O objeto da classe contém um membro de ponteiro de tabela virtual adicional (no início ou no fim do objeto de classe; que tem um histórico interessante por si só) que lida com a tabela virtual apropriada. Por exemplo, um objeto de destaque atende a uma tabela virtual destaque, uma luz direcional, uma tabela virtual luz direcional e assim por diante  
  
-   Cada função virtual possui um tipo fixo de slot da tabela e a instância real para invocar é representada pelo endereço armazenado dentro da tabela. Por exemplo, o virtual `Light` destruidor possam estar associado ao slot 0, `Color` com slot 1 e assim por diante. Isso é uma estratégia eficiente se inflexíveis porque ele está configurado no tempo de compilação e representa uma sobrecarga mínima.  
  
 O problema, em seguida, é como disponibilizar as informações de tipo para o ponteiro sem alterar o tamanho de ponteiros de C++, adicionando um segundo endereço ou adicionando diretamente algum tipo de codificação de tipo. Isso não for aceitável para os programadores (e programas) que decidir não usar o paradigma orientado a objeto - ainda era a comunidade de usuários predominantes. Outra possibilidade foi apresentar um ponteiro especial para tipos de classe polimórfico, mas isso seria confuso e tornar difícil misturar entre os dois, particularmente com problemas de aritmética de ponteiro. Ele também não for aceitável para manter uma tabela de tempo de execução que associa cada ponteiro ao seu tipo atualmente associado e atualizá-lo dinamicamente.  
  
 O problema, em seguida, é um par de comunidades de usuários que têm diferentes, mas legítimas às aspirações programação. A solução deve ser um compromisso entre as duas comunidades, permitindo que cada um, não apenas seu aspiração, mas a capacidade de interagir. Isso significa que as soluções oferecidas por cada lado têm probabilidade de ser inviável e a solução ser implementada por último será perfeito menor. A resolução real envolve a definição de uma classe polimórfica: uma classe polimórfica é aquele que contém uma função virtual. Uma classe polimórfica dá suporte a um cofre tipo dinâmico baixá-los. Isso resolve o problema de manter-a--como-endereço do ponteiro porque todas as classes polimórficas contém esse membro ponteiro adicional para a tabela virtual associada. As informações de tipo associado, portanto, podem ser armazenadas em uma estrutura de tabela virtual expandido. O custo de baixá-los o fortemente tipado (quase) está localizado para os usuários do recurso.  
  
 O próximo problema com a segurança de tipo rebaixada foi sua sintaxe. Como é uma conversão, a proposta original para o Comitê de ISO C++ usada a sintaxe de conversão acrescidos, como neste exemplo:  
  
```  
spot = ( SpotLight* ) plight;  
```  
  
 mas isso foi rejeitado pelo comitê porque ele não permitiu que o usuário controle o custo da conversão. Se o dinâmico fortemente tipado rebaixado tem a mesma sintaxe que anteriormente não segura, mas estático notação de conversão, ele se torna uma substituição, e o usuário não tem capacidade suprimir a sobrecarga de tempo de execução quando é desnecessário e talvez muito cara.  
  
 Em geral, em C++, sempre há um mecanismo pelo qual suprimir a funcionalidade com suporte ao compilador. Por exemplo, podemos pode desativar o mecanismo virtual usando o operador de escopo de classe (`Box::rotate(angle)`) ou chamando o método virtual por meio de um objeto de classe (em vez de um ponteiro ou referência de classe). Este último supressão não é necessário o idioma, mas é uma qualidade de problema de implementação, semelhante a supressão da construção de um temporário em uma declaração do formulário:  
  
```  
// compilers are free to optimize away the temporary  
X x = X::X( 10 );  
```  
  
 Para que a proposta foi tirada de volta para mais considerações e várias notações alternativas foram consideradas e aquela trazidas de volta para o comitê estava no formato (`?type`), que indicado indeterminado - ou seja, a natureza dinâmica. Isso fornecia ao usuário a capacidade de alternar entre as duas formas - estáticas ou dinâmicas - mas não era muito satisfeito com ele. Por isso, foi volta para o quadro de desenho. A notação de terceira e bem-sucedida é o agora padrão `dynamic_cast<type>`, que foi generalizado para um conjunto de quatro notações de conversão de novo estilo.  
  
 No ISO C++, `dynamic_cast` retorna `0` quando aplicado a um tipo de ponteiro inadequado e lança um `std::bad_cast` exceção quando aplicado a um tipo de referência. Em extensões gerenciadas para C++, aplicando `dynamic_cast` para um tipo de referência gerenciada (por causa de sua representação de ponteiro) sempre retornado `0`. `__try_cast<type>` foi introduzido como um analógico à exceção lançando a variante do `dynamic_cast`, exceto que ele lança `System::InvalidCastException` se a conversão falhar.  
  
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
  
 Na sintaxe de novo, `__try_cast` foi reconvertida como `safe_cast`. Aqui está o mesmo fragmento de código na nova sintaxe:  
  
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
  
 No mundo gerenciado, é importante permitir que o código verificável, limitando a capacidade dos programadores de conversão entre tipos de maneiras que deixam o código não verificável. Este é um aspecto crítico do dinâmico paradigma de programação representado pela nova sintaxe. Por esse motivo, instâncias de conversões de estilo antigo são reconvertidas internamente como conversões de tempo de execução, para que, por exemplo:  
  
```  
// internally recast into the   
// equivalent safe_cast expression above  
( array<ItemVerb^>^ ) verbList->ToArray( ItemVerb::typeid );   
```  
  
 Por outro lado, como polimorfismo fornece um ativo e um modo passivo, às vezes é necessário executar um baixá-los apenas para acessar a API não virtual de um subtipo. Isso pode ocorrer, por exemplo, com os membros de uma classe que deseja endereço qualquer tipo dentro da hierarquia (passivo polimorfismo como um mecanismo de transporte), mas para o qual a instância real em um contexto de programa específico é conhecida. Nesse caso, a ter uma verificação de tempo de execução da conversão pode ser uma sobrecarga inaceitável. Se a nova sintaxe é servir como os linguagem de programação de sistemas gerenciados, ele deve fornecer alguma maneira de permitir que um tempo de compilação (ou seja, estático) baixá-los. É por isso que o aplicativo do `static_cast` notação pode permanecer um tempo de compilação baixá-los:  
  
```  
// ok: cast performed at compile-time.   
// No run-time check for type correctness  
static_cast< array<ItemVerb^>^>(verbList->ToArray(ItemVerb::typeid));  
```  
  
 O problema é que não há nenhuma maneira de garantir que o programador fazendo o `static_cast` está correto e bem intencionados; ou seja, não é possível forçar o código gerenciado para ser verificado. Isso é uma preocupação mais urgente no paradigma dinâmico do programa que em nativo, mas não é suficiente dentro de um sistema a capacidade de alternar entre um static e conversão de tempo de execução de linguagem para impedir que o usuário de programação.  
  
 Há uma interceptação de desempenho e armadilha na nova sintaxe, no entanto. Na programação nativa, não há nenhuma diferença no desempenho entre a notação de conversão de estilo antigo e o novo estilo `static_cast` notação. Mas a nova sintaxe, a notação de conversão de estilo antigo é significativamente mais cara do que o uso do novo estilo `static_cast` notação. O motivo é que o compilador internamente transforma o uso da notação de estilo antigo em uma verificação de tempo de execução que gera uma exceção. Além disso, ele também altera o perfil de execução do código porque ele faz com que uma exceção não percebida colocando o aplicativo - talvez criteriosamente, mas o mesmo erro não faria com que essa exceção se o `static_cast` notação foram usados. Alguém pode argumentar que isso ajudará os usuários de produção em usando a notação de novo estilo. Apenas quando ele falha; Caso contrário, ela fará com que os programas que usam a notação de estilo antigo seja executado mais lentamente sem uma compreensão visível do motivo, como as seguintes armadilhas de programador de C:  
  
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
 [Alterações gerais em linguagens (C + + CLI)](../dotnet/general-language-changes-cpp-cli.md)   
 [Conversões do estilo C com /clr (C + + CLI)](../windows/c-style-casts-with-clr-cpp-cli.md)   
 [Safe_cast](../windows/safe-cast-cpp-component-extensions.md)