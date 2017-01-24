---
title: "Classe allocator | Microsoft Docs"
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
  - "std::allocator"
  - "allocator"
  - "memory/std::allocator"
  - "std.allocator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe allocator"
ms.assetid: 3fd58076-56cc-43bb-ad58-b4b7c9c6b410
caps.latest.revision: 20
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe allocator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo descreve um objeto que gerencia a alocação de armazenamento e liberando matrizes de objetos do tipo **tipo**. Um objeto da classe **alocador** é o objeto de alocador padrão especificado em construtores para várias classes de modelo de contêiner na biblioteca C\+\+ padrão.  
  
## Sintaxe  
  
```  
  
template <class   
Type  
>  
class allocator  
  
```  
  
#### Parâmetros  
 *Tipo*  
 O tipo de objeto para o qual o armazenamento está sendo alocadas ou desalocadas.  
  
## Comentários  
 Todos os contêineres da biblioteca de modelos padrão têm um parâmetro de modelo padrão é **alocador**. Criando um contêiner com um alocador personalizado fornecem controle sobre a alocação e a liberação dos elementos do contêiner.  
  
 Por exemplo, um objeto de alocador pode alocar o armazenamento em um heap particular ou na memória compartilhada, ou ele pode otimizar para tamanhos de objeto grandes ou pequenos. Ele pode também especificar, por meio de definições de tipo fornece, que elementos ser acessados por meio de objetos de acessador especial que gerenciam a memória compartilhada, ou executam coleta de lixo automática. Portanto, uma classe que aloca armazenamento usando um objeto de alocador deve usar esses tipos para declarar um ponteiro e fazer referência a objetos, assim como os contêineres na biblioteca C\+\+ padrão.  
  
 **\(C \_ \+ \+ 98\/03 somente\)**quando você derivar da classe do alocador, você precisa fornecer um [reassociar](../Topic/allocator::rebind.md) struct, cujo `_Other` typedef referencia sua classe derivada recentemente.  
  
 Portanto, um alocador define os seguintes tipos:  
  
-   [ponteiro](../Topic/allocator::pointer.md) se comporta como um ponteiro para **tipo**.  
  
-   [const\_pointer](../Topic/allocator::const_pointer.md) se comporta como um ponteiro const para **tipo**.  
  
-   [referência](../Topic/allocator::reference.md) se comporta como uma referência a **tipo**.  
  
-   [const\_reference](../Topic/allocator::const_reference.md) se comporta como uma referência constante a **tipo**.  
  
 Essas **tipo**s especificar o formulário ponteiros e referências devem tomar para elementos alocados. \([allocator:: Pointer](../Topic/allocator::pointer.md) não é necessariamente o mesmo que **tipo**\* para todos os objetos do alocador, mesmo que ele tem essa definição óbvia para a classe **alocador**.\)  
  
 **C \+ \+ 11 e posterior:**  para permitir operações de movimentação em seu alocador, use a interface de alocador mínimo e implementar o construtor de cópia, \= \= e\! \= operadores, alocar e desalocar. Para obter mais informações e um exemplo, consulte [alocadores](../Topic/Allocators.md)  
  
## Membros  
  
### Construtores  
  
|||  
|-|-|  
|[allocator](../Topic/allocator::allocator.md)|Construtores usados para criar `allocator` objetos.|  
  
### Typedefs  
  
|||  
|-|-|  
|[const\_pointer](../Topic/allocator::const_pointer.md)|Um tipo que fornece um ponteiro para o tipo de objeto gerenciado pelo alocador de constante.|  
|[const\_reference](../Topic/allocator::const_reference.md)|Um tipo que fornece uma referência ao tipo de objeto gerenciado pelo alocador de constante.|  
|[difference\_type](../Topic/allocator::difference_type.md)|Um tipo integral assinado que pode representar a diferença entre valores de ponteiros para o tipo de objeto gerenciado pelo alocador.|  
|[pointer](../Topic/allocator::pointer.md)|Um tipo que fornece um ponteiro para o tipo de objeto gerenciado pelo alocador.|  
|[reference](../Topic/allocator::reference.md)|Um tipo que fornece uma referência para o tipo de objeto gerenciado pelo alocador.|  
|[size\_type](../Topic/allocator::size_type.md)|Um tipo integral não assinado que pode representar o comprimento de qualquer seqüência que um objeto da classe de modelo `allocator` pode alocar.|  
|[value\_type](../Topic/allocator::value_type.md)|Um tipo que é gerenciado pelo alocador.|  
  
### Funções membro  
  
|||  
|-|-|  
|[endereço](../Topic/allocator::address.md)|Localiza o endereço de um objeto cujo valor é especificado.|  
|[allocate](../Topic/allocator::allocate.md)|Aloca um bloco de memória grande o suficiente para armazenar pelo menos um número especificado de elementos.|  
|[Construir](../Topic/allocator::construct.md)|Constrói um tipo específico de objeto em um endereço especificado que é inicializado com um valor especificado.|  
|[desalocar](../Topic/allocator::deallocate.md)|Libera um número especificado de objetos desde o início do armazenamento em uma posição especificada.|  
|[destruir](../Topic/allocator::destroy.md)|Chama um destruidor de objetos sem desalocar a memória em que o objeto foi armazenado.|  
|[max\_size](../Topic/allocator::max_size.md)|Retorna o número de elementos do tipo `Type` que pode ser alocada por um objeto da classe `allocator` antes da memória livre é usada.|  
|[Reassociar](../Topic/allocator::rebind.md)|Uma estrutura que permite que um alocador para objetos de um tipo alocar armazenamento para objetos de outro tipo.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\=](../Topic/allocator::operator=.md)|Atribui um `allocator` objeto para outro `allocator` objeto.|  
  
## Requisitos  
 **Cabeçalho:** \< memória \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)