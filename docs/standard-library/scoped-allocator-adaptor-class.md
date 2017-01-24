---
title: "Classe scoped_allocator_adaptor | Microsoft Docs"
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
  - "std.scoped_allocator_adaptor"
  - "scoped_allocator_adaptor"
  - "scoped_allocator/std::scoped_allocator_adaptor"
  - "std::scoped_allocator_adaptor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe scoped_allocator_adaptor"
ms.assetid: 0d9b06a1-9a4a-4669-9470-8805cae48e89
caps.latest.revision: 10
caps.handback.revision: 1
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe scoped_allocator_adaptor
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa um aninhamento de alocadores.  
  
## Sintaxe  
  
```cpp  
template<class Outer, class... Inner>  
    class scoped_allocator_adaptor;  
```  
  
## Comentários  
 A classe do modelo encapsula um aninhamento de um ou mais alocadores.  Cada uma dessas classe tiver um alocador externo do tipo `outer_allocator_type`, um sinônimo para `Outer`, que é uma base pública do objeto de `scoped_allocator_adaptor` .  `Outer` é usado para alocar memória a ser usada por um contêiner.  Você pode obter uma referência a esse objeto base do alocador chamando `outer_allocator`.  
  
 O restante de aninhamento tem o tipo `inner_allocator_type`.  Um alocador interno é usado para alocar memória para elementos dentro de um contêiner.  Você pode obter uma referência ao objeto armazenado desse tipo chamando `inner_allocator`.  Se `Inner...` não estiver vazia, `inner_allocator_type` tem o tipo `scoped_allocator_adaptor<Inner...>`, e `inner_allocator` designa um objeto do membro.  Caso contrário, `inner_allocator_type` tem o tipo `scoped_allocator_adaptor<Outer>`, e `inner_allocator` designa o objeto inteiro.  
  
 O aninhamento se comportará como se tivesse a profundidade arbitrária replicando, o alocador encapsulado interno quando necessário.  
  
 Vários conceitos que não é uma parte de auxílio da interface visível ao descrever o comportamento dessa classe do modelo.  *Um alocador externo* negocia todas as chamadas para a construção e destrói métodos.  É definida com eficiência pela função recursiva `OUTERMOST(X)`, onde é `OUTERMOST(X)` um destes valores.  
  
-   Se `X.outer_allocator()` está bem formado, então `OUTERMOST(X)` é `OUTERMOST(X.outer_allocator())`.  
  
-   Caso contrário, `OUTERMOST(X)` é `X`.  
  
 Três tipos são definidos para a exposição:  
  
|Tipo|Descrição|  
|----------|---------------|  
|`Outermost`|O tipo de `OUTERMOST(*this)`.|  
|`Outermost_traits`|`allocator_traits<Outermost>`|  
|`Outer_traits`|`allocator_traits<Outer>`|  
  
### Construtores  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor scoped\_allocator\_adaptor::scoped\_allocator\_adaptor](../Topic/scoped_allocator_adaptor::scoped_allocator_adaptor%20Constructor.md)|Constrói um objeto `scoped_allocator_adaptor`.|  
  
### Typedefs  
  
|Nome|Descrição|  
|----------|---------------|  
|`const_pointer`|Esse é um sinônimo para `const_pointer` associado ao alocador `Outer`.|  
|`const_void_pointer`|Esse é um sinônimo para `const_void_pointer` associado ao alocador `Outer`.|  
|`difference_type`|Esse é um sinônimo para `difference_type` associado ao alocador `Outer`.|  
|`inner_allocator_type`|Esse é um sinônimo para o tipo do adaptador aninhado `scoped_allocator_adaptor<Inner...>`.|  
|`outer_allocator_type`|Esse é um sinônimo para o tipo do alocador de base `Outer`.|  
|`pointer`|Esse é um sinônimo para `pointer` associado ao alocador `Outer`.|  
|`propagate_on_container_copy_assignment`|O tipo se aplica apenas se `Outer_traits::propagate_on_container_copy_assignment` contém as propriedades verdadeiro ou de `inner_allocator_type::propagate_on_container_copy_assignment` verdadeiras.|  
|`propagate_on_container_move_assignment`|O tipo se aplica apenas se `Outer_traits::propagate_on_container_move_assignment` contém as propriedades verdadeiro ou de `inner_allocator_type::propagate_on_container_move_assignment` verdadeiras.|  
|`propagate_on_container_swap`|O tipo se aplica apenas se `Outer_traits::propagate_on_container_swap` contém as propriedades verdadeiro ou de `inner_allocator_type::propagate_on_container_swap` verdadeiras.|  
|`size_type`|Esse é um sinônimo para `size_type` associado ao alocador `Outer`.|  
|`value_type`|Esse é um sinônimo para `value_type` associado ao alocador `Outer`.|  
|`void_pointer`|Esse é um sinônimo para `void_pointer` associado ao alocador `Outer`.|  
  
### Structs  
  
|Nome|Descrição|  
|----------|---------------|  
|[Struct scoped\_allocator\_adaptor::rebind](../Topic/scoped_allocator_adaptor::rebind%20Struct.md)|Define o tipo `Outer::rebind<Other>::other` como um sinônimo para `scoped_allocator_adaptor<Other, Inner...>`.|  
  
### Métodos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método scoped\_allocator\_adaptor::allocate](../Topic/scoped_allocator_adaptor::allocate%20Method.md)|Aloca memória usando o alocador de `Outer` .|  
|[Método scoped\_allocator\_adaptor::construct](../Topic/scoped_allocator_adaptor::construct%20Method.md)|Constrói um objeto.|  
|[Método scoped\_allocator\_adaptor::deallocate](../Topic/scoped_allocator_adaptor::deallocate%20Method.md)|Desaloca objetos usando o alocador externa.|  
|[Método scoped\_allocator\_adaptor::destroy](../Topic/scoped_allocator_adaptor::destroy%20Method.md)|Destrói um objeto especificado.|  
|[Método scoped\_allocator\_adaptor::inner\_allocator](../Topic/scoped_allocator_adaptor::inner_allocator%20Method.md)|Recupera uma referência ao objeto armazenado do tipo `inner_allocator_type`.|  
|[Método scoped\_allocator\_adaptor::max\_size](../Topic/scoped_allocator_adaptor::max_size%20Method.md)|Determina o número máximo de objetos que podem ser atribuídos pelo alocador externa.|  
|[Método scoped\_allocator\_adaptor::outer\_allocator](../Topic/scoped_allocator_adaptor::outer_allocator%20Method.md)|Recupera uma referência ao objeto armazenado do tipo `outer_allocator_type`.|  
|[Método scoped\_allocator\_adaptor::select\_on\_container\_copy\_construction](../Topic/scoped_allocator_adaptor::select_on_container_copy_construction%20Method.md)|Cria um novo objeto a partir de `scoped_allocator_adaptor` com cada objeto armazenado do alocador inicializado chamando `select_on_container_copy_construction` para cada alocador correspondente.|  
  
## Requisitos  
 scoped\_allocator \<de**Cabeçalho:** \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)