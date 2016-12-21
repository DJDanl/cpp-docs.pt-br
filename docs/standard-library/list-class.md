---
title: "Classe list | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std.list"
  - "list"
  - "std::list"
  - "list/std::list"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe list"
ms.assetid: d3707f4a-10fd-444f-b856-f9ca2077c1cd
caps.latest.revision: 20
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe list
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de lista STL é uma classe de modelo de contêineres de sequência que mantém seus elementos em uma organização linear e permite inserções e exclusões eficientes em qualquer local na sequência.  A sequência é armazenada como uma lista vinculada bidirecional de elementos, cada um contendo um membro de algum tipo de *Type*.  
  
## Sintaxe  
  
```cpp  
  
template <    class Type,     class Allocator=allocator<Type>  > class list  
```  
  
#### Parâmetros  
 *Tipo*  
 O tipo de dados do elemento a ser armazenado na lista.  
  
 `Allocator`  
 O tipo que representa o objeto alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória da lista.  Esse argumento é opcional e o valor padrão é **allocator**\<*Type*\>*.*  
  
## Comentários  
 A escolha do tipo de contêiner deve se basear, de modo geral, no tipo de pesquisa e inserção exigido pelo aplicativo.  Vetores devem ser o contêiner preferencial para gerenciar uma sequência quando o acesso aleatório a qualquer elemento é alto e inserção e exclusões de elementos apenas são necessárias no final de uma sequência.  O desempenho do contêiner de deque de classe é superior quando o acesso aleatório é necessário e as inserções e exclusões no início e final de uma sequência são essenciais.  
  
 As funções de membro da lista [mesclar](../Topic/list::merge.md), [inverter](../Topic/list::reverse.md), [exclusiva](../Topic/list::unique.md), [remover](../Topic/list::remove.md), e [remove\_if](../Topic/list::remove_if.md) foram otimizadas para funcionar com objetos da lista e oferecer uma alternativa de alto desempenho para os seus correspondentes genéricos.  
  
 A realocação da lista ocorre quando uma função de membro deve inserir ou apagar elementos da lista.  Nesses casos, somente iteradores ou referências que apontem para partes apagadas da sequência controladas tornam\-se inválidos.  
  
 Inclua o cabeçalho padrão STL \<list\> para definir a lista da classe de modelo do [contêiner](../standard-library/stl-containers.md) e vários modelos de suporte.  
  
### Construtores  
  
|||  
|-|-|  
|[list](../Topic/list::list.md)|Constrói uma lista de um tamanho específico, ou com elementos de um valor específico, ou com um `allocator` específico, ou como uma cópia de alguma outra lista.|  
  
### Typedefs  
  
|||  
|-|-|  
|[allocator\_type](../Topic/list::allocator_type.md)|Um tipo que representa a classe `allocator` para um objeto de lista.|  
|[const\_iterator](../Topic/list::const_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler um elemento `const` em uma lista.|  
|[const\_pointer](../Topic/list::const_pointer.md)|Um tipo que fornece um ponteiro para um elemento `const` em uma lista.|  
|[const\_reference](../Topic/list::const_reference.md)|Um tipo que fornece uma referência para um elemento `const` armazenado em uma lista para leitura e execução de operações `const`.|  
|[const\_reverse\_iterator](../Topic/list::const_reverse_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento `const` em uma lista.|  
|[difference\_type](../Topic/list::difference_type.md)|Um tipo que fornece a diferença entre dois iteradores que se referem a elementos na mesma lista.|  
|[iterator](../Topic/list::iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em uma lista.|  
|[pointer](../Topic/list::pointer.md)|Um tipo que fornece um ponteiro para um elemento em uma lista.|  
|[reference](../Topic/list::reference.md)|Um tipo que fornece uma referência para um elemento `const` armazenado em uma lista para leitura e execução de operações `const`.|  
|[reverse\_iterator](../Topic/list::reverse_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em uma lista invertida.|  
|[size\_type](../Topic/list::size_type.md)|Um tipo que conta o número de elementos em uma lista.|  
|[value\_type](../Topic/list::value_type.md)|Um tipo que representa o tipo de dados armazenado em uma lista.|  
  
### Funções membro  
  
|||  
|-|-|  
|[assign](../Topic/list::assign.md)|Apaga os elementos de uma lista e copia um novo conjunto de elementos na lista de destino.|  
|[back](../Topic/list::back.md)|Retorna uma referência ao último elemento de uma lista.|  
|[begin](../Topic/list::begin.md)|Retorna um iterador que trata o primeiro elemento em uma lista.|  
|[list::cbegin](../Topic/list::cbegin.md)|Retorna um iterador const que trata o primeiro elemento em uma lista.|  
|[list::cend](../Topic/list::cend.md)|Retorna um iterador const que trata o local após o último elemento em uma lista.|  
|[list::clear](../Topic/list::clear.md)|Apaga todos os elementos de uma lista.|  
|[list::crbegin](../Topic/list::crbegin.md)|Retorna um iterador const que trata o primeiro elemento em uma lista invertida.|  
|[list::crend](../Topic/list::crend.md)|Retorna um iterador const que trata o local após o último elemento em uma lista invertida.|  
|[list::emplace](../Topic/list::emplace.md)|Insere um elemento construído no local em uma lista na posição especificada.|  
|[list::emplace\_back](../Topic/list::emplace_back.md)|Adiciona um elemento construído no local ao final de uma lista.|  
|[list::emplace\_front](../Topic/list::emplace_front.md)|Adiciona um elemento construído no local ao início de uma lista.|  
|[empty](../Topic/list::empty.md)|Testa se uma lista está vazia.|  
|[end](../Topic/list::end.md)|Retorna um iterador que trata o local após o último elemento em uma lista.|  
|[erase](../Topic/list::erase.md)|Remove um elemento ou um intervalo de elementos das posições especificadas.|  
|[front](../Topic/list::front.md)|Retorna uma referência ao primeiro elemento em uma lista.|  
|[get\_allocator](../Topic/list::get_allocator.md)|Retorna uma cópia do objeto `allocator` usada para construir uma lista.|  
|[insert](../Topic/list::insert.md)|Insere um elemento ou um número de elementos ou um intervalo de elementos em uma lista, na posição especificada.|  
|[max\_size](../Topic/list::max_size.md)|Retorna o tamanho máximo de uma lista.|  
|[merge](../Topic/list::merge.md)|Remove os elementos da lista de argumentos, insere\-os na lista de destino e organiza o conjunto novo e combinado de elementos em ordem crescente ou em alguma outra ordem especificada.|  
|[pop\_back](../Topic/list::pop_back.md)|Exclui o elemento no final de uma lista.|  
|[pop\_front](../Topic/list::pop_front.md)|Exclui o elemento no começo de uma lista.|  
|[push\_back](../Topic/list::push_back.md)|Adiciona um elemento ao fim da lista.|  
|[push\_front](../Topic/list::push_front.md)|Adiciona um elemento ao começo da lista.|  
|[rbegin](../Topic/list::rbegin.md)|Retorna um iterador que trata o primeiro elemento em uma lista inversa.|  
|[remove](../Topic/list::remove.md)|Apaga elementos em uma lista que correspondem a um valor especificado.|  
|[remove\_if](../Topic/list::remove_if.md)|Apaga os elementos da lista para a qual um predicado especificado foi atendido.|  
|[rend](../Topic/list::rend.md)|Retorna um iterador que trata o local após o último elemento em uma lista invertida.|  
|[resize](../Topic/list::resize.md)|Especifica um novo tamanho para uma lista.|  
|[reverse](../Topic/list::reverse.md)|Reverte a ordem na qual os elementos ocorrem em uma lista.|  
|[size](../Topic/list::size.md)|Retorna o número de elementos em uma lista.|  
|[sort](../Topic/list::sort.md)|Organiza os elementos de uma lista em ordem crescente ou com respeito a alguma outra relação de ordem.|  
|[splice](../Topic/list::splice.md)|Remove os elementos da lista de argumentos e os insere na lista de destino.|  
|[swap](../Topic/list::swap.md)|Troca os elementos das duas listas.|  
|[unique](../Topic/list::unique.md)|Remove elementos duplicados adjacentes ou elementos adjacentes que satisfazem algum predicado binário da lista.|  
  
### Operadores  
  
|||  
|-|-|  
|[list::operator\=](../Topic/list::operator=.md)|Substitui os elementos da lista por uma cópia de outra lista.|  
  
## Requisitos  
 **Cabeçalho**: \<list\>  
  
## Consulte também  
 [\<list\>](../standard-library/list.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)