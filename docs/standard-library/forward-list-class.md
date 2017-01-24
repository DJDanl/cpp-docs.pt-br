---
title: "Classe forward_list | Microsoft Docs"
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
  - "std::forward_list"
  - "forward_list"
  - "forward_list/std::forward_list"
  - "std.forward_list"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe forward_list"
ms.assetid: 89a3b805-ab60-4858-b772-5855130c11b1
caps.latest.revision: 25
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe forward_list
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto que controla uma sequência de comprimento variável de elementos.  A sequência é armazenada como uma lista vinculada isoladamente de nós, cada um contendo um membro do tipo`Type`.  
  
## Sintaxe  
  
```  
template<  
    class Type,   
    class Allocator = allocator<Type>   
>  
class forward_list   
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`Type`|O tipo de dados do elemento a ser armazenado na forward\_list de.|  
|`Allocator`|O objeto de alocador armazenado que encapsula os detalhes sobre a alocação de forward\_list e desalocação de memória.  Esse parâmetro é opcional.  O valor padrão é alocador \<`Type`\>.|  
  
## Comentários  
 Um`forward_list`objeto aloca e libera armazenamento para a sequência que controla por meio de um objeto armazenado da classe`Allocator`baseado em[Classe allocator](../standard-library/allocator-class.md)\(normalmente conhecido como`std::allocator)`.  Para obter mais informações, consulte[Alocadores](../Topic/Allocators.md).  Um objeto de alocador deve ter a mesma interface externa, como um objeto da classe de modelo`allocator`.  
  
> [!NOTE]
>  O objeto de alocador armazenado não é copiado quando o objeto de contêiner é atribuído.  
  
 Iteradores, ponteiros e referências poderão se tornar inválidas quando são apagados elementos da sua sequência controlada por meio de`forward_list`.  Inserções e subpadrão executadas em sequência controlada por meio de`forward_list`não invalida iteradores.  
  
 Adições à sequência controlada podem ocorrer por chamadas para[forward\_list::insert\_after](../Topic/forward_list::insert_after.md)que é a única função de membro que chama o construtor`Type(const _Type&)`.  `forward_list`pode também chamada mover construtores.  Se uma expressão lançar uma exceção, o objeto de contêiner não insere nenhum novos elementos e Relança a exceção.  Portanto, um objeto da classe de modelo`forward_list`for deixado em um estado conhecido quando essas exceções ocorrem.  
  
### Construtores  
  
|||  
|-|-|  
|[forward\_list](../Topic/forward_list::forward_list.md)|Constrói um objeto do tipo`forward_list`.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[allocator\_type](../Topic/forward_list::allocator_type.md)|Um tipo que representa a classe do alocador de um objeto de lista de encaminhamento.|  
|[const\_iterator](../Topic/forward_list::const_iterator.md)|Um tipo que fornece um iterador constante para a lista de encaminhamento.|  
|[const\_pointer](../Topic/forward_list::const_pointer.md)|Um tipo que fornece um ponteiro para um`const`elemento em uma lista de encaminhamento.|  
|[const\_reference](../Topic/forward_list::const_reference.md)|Um tipo que fornece uma referência constante a um elemento na lista de encaminhamento.|  
|[difference\_type](../Topic/forward_list::difference_type.md)|Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de uma lista de encaminhamento em um intervalo entre os elementos apontado pelos iteradores.|  
|[iterator](../Topic/forward_list::iterator.md)|Um tipo que fornece um iterador para a lista de encaminhamento.|  
|[pointer](../Topic/forward_list::pointer.md)|Um tipo que fornece um ponteiro para um elemento na lista de encaminhamento.|  
|[referência](../Topic/forward_list::reference.md)|Um tipo que fornece uma referência a um elemento na lista de encaminhamento.|  
|[size\_type](../Topic/forward_list::size_type.md)|Um tipo que representa a distância sem sinal entre dois elementos.|  
|[value\_type](../Topic/forward_list::value_type.md)|Um tipo que representa o tipo de elemento armazenado em uma lista de encaminhamento.|  
  
### Funções membro  
  
|||  
|-|-|  
|[assign](../Topic/forward_list::assign.md)|Apaga os elementos de uma lista de encaminhamento e copia um novo conjunto de elementos em uma lista de encaminhamento de destino.|  
|[before\_begin](../Topic/forward_list::before_begin.md)|Retorna um iterador que trata da posição antes do primeiro elemento em uma lista de encaminhamento.|  
|[begin](../Topic/forward_list::begin.md)|Retorna um iterador que trata o primeiro elemento em uma lista de encaminhamento.|  
|[cbefore\_begin](../Topic/forward_list::cbefore_begin.md)|Retorna um iterador const que trata da posição antes do primeiro elemento em uma lista de encaminhamento.|  
|[cbegin](../Topic/forward_list::cbegin.md)|Retorna um iterador const que trata o primeiro elemento em uma lista de encaminhamento.|  
|[cend](../Topic/forward_list::cend.md)|Retorna um iterador const que trata o local após o último elemento em uma lista de encaminhamento.|  
|[limpar](../Topic/forward_list::clear.md)|Apaga todos os elementos de uma lista de encaminhamento.|  
|[emplace\_after](../Topic/forward_list::emplace_after.md)|Mover constrói um novo elemento após uma posição especificada.|  
|[emplace\_front](../Topic/forward_list::emplace_front.md)|Adiciona um elemento construído adequadamente para o início da lista.|  
|[vazio](../Topic/forward_list::empty.md)|Testa se uma lista de encaminhamento está vazia.|  
|[end](../Topic/forward_list::end.md)|Retorna um iterador que trata o local após o último elemento em uma lista de encaminhamento.|  
|[erase\_after](../Topic/forward_list::erase_after.md)|Remove os elementos da lista direta após uma posição especificada.|  
|[front](../Topic/forward_list::front.md)|Retorna uma referência para o primeiro elemento em uma lista de encaminhamento.|  
|[get\_allocator](../Topic/forward_list::get_allocator.md)|Retorna uma cópia do objeto alocador usado para construir uma lista de encaminhamento.|  
|[insert\_after](../Topic/forward_list::insert_after.md)|Adiciona elementos à lista de encaminhamento após uma posição especificada.|  
|[max\_size](../Topic/forward_list::max_size.md)|Retorna o comprimento máximo de uma lista de encaminhamento.|  
|[mesclar](../Topic/forward_list::merge.md)|Remove os elementos da lista de argumentos, insere\-os na lista de encaminhamento de destino e ordena o conjunto de novo, combinado de elementos em ordem crescente ou em alguma outra ordem especificada.|  
|[pop\_front](../Topic/forward_list::pop_front.md)|Exclui o elemento no início de uma lista de encaminhamento.|  
|[push\_front](../Topic/forward_list::push_front.md)|Adiciona um elemento no início de uma lista de encaminhamento.|  
|[remover](../Topic/forward_list::remove.md)|Apaga os elementos em uma lista de encaminhamento que corresponde a um valor especificado.|  
|[remove\_if](../Topic/forward_list::remove_if.md)|Apaga os elementos de uma lista de encaminhamento para o qual um predicado especificado for satisfeito.|  
|[redimensionar](../Topic/forward_list::resize.md)|Especifica um novo tamanho para uma lista de encaminhamento.|  
|[reverse](../Topic/forward_list::reverse.md)|Inverte a ordem na qual os elementos ocorrerem em uma lista de encaminhamento.|  
|[sort](../Topic/forward_list::sort.md)|Organiza os elementos em ordem crescente ou com uma ordem especificada por um predicado.|  
|[splice\_after](../Topic/forward_list::splice_after.md)|Restitches links entre nós.|  
|[swap](../Topic/forward_list::swap.md)|Troca os elementos das duas listas de encaminhamento.|  
|[unique](../Topic/forward_list::unique.md)|Remove elementos adjacentes que passa um teste especificado.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\=](../Topic/forward_list::operator=.md)|Substitui os elementos da lista de encaminhamento com uma cópia de outra lista de encaminhamento.|  
  
## Requisitos  
 **Cabeçalho:** \<forward\_list\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<forward\_list\>](../standard-library/forward-list.md)