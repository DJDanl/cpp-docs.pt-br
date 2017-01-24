---
title: "&lt;memory&gt; | Microsoft Docs"
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
  - "memory/std::<memory>"
  - "std.<memory>"
  - "<memory>"
  - "std::<memory>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho memory"
ms.assetid: ef8e38da-7c9d-4037-9ad1-20c99febf5dc
caps.latest.revision: 22
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;memory&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define uma classe, um operador e vários modelos que ajudam a alocar e a liberar objetos.  
  
## Sintaxe  
  
```  
  
#include <memory>  
  
```  
  
## Membros  
  
### Funções  
  
|||  
|-|-|  
|[addressof](../Topic/addressof.md)|Obtém o endereço verdadeiro de um objeto.|  
|[align](../Topic/align.md)|Retorna um ponteiro para um intervalo de um determinado tamanho, com base no endereço de início e alinhamento fornecidos.|  
|[allocate\_shared](../Topic/allocate_shared.md)|Cria um `shared_ptr` para objetos atribuídos e construídos para um determinado tipo com um alocador especificado.|  
|[checked\_uninitialized\_copy](../misc/checked-uninitialized-copy.md)|Mesmo que `uninitialized_copy`, mas força o uso de um iterador verificado como iterador de saída.|  
|[checked\_uninitialized\_fill\_n](../misc/checked-uninitialized-fill-n.md)|Mesmo que `uninitialized_fill_n`, mas força o uso de um iterador verificado como iterador de saída.|  
|[const\_pointer\_cast](../Topic/const_pointer_cast.md)|Conversão constante para `shared_ptr`.|  
|[declare\_no\_pointers](../Topic/declare_no_pointers.md)|Informa a um coletor de lixo que os caracteres começando em um endereço especificado e recaindo no tamanho de bloco indicado não contêm ponteiros rastreáveis.|  
|[declare\_reachable](../Topic/declare_reachable.md)|Informa a coleta de lixo que o endereço indicado é para armazenamento alocado e é alcançável.|  
|[default\_delete](../Topic/default_delete.md)|Exclui objetos alocados com `operator new`.  Adequado para uso com `unique_ptr`.|  
|[dynamic\_pointer\_cast](../Topic/dynamic_pointer_cast.md)|Conversão dinâmica para `shared_ptr`.|  
|[get\_deleter](../Topic/get_deleter%20Function.md)|Obtenha o deletor de `shared_ptr`.|  
|[get\_pointer\_safety](../Topic/get_pointer_safety.md)|Retorna o tipo de segurança do ponteiro pressuposto por qualquer coletor de lixo.|  
|[get\_temporary\_buffer](../Topic/get_temporary_buffer.md)|Atribui o armazenamento temporário para uma sequência de elementos que não excede um número especificado de elementos.|  
|[make\_shared](../Topic/make_shared%20\(%3Cmemory%3E\).md)|Cria e retorna um `shared_ptr` que aponta para o objeto alocado construído do zero ou mais argumentos usando o alocador padrão.|  
|[make\_unique](../Topic/make_unique.md)|Cria e retorna um [unique\_ptr](../standard-library/unique-ptr-class.md) que aponta para o objeto alocado construído do zero ou mais argumentos.|  
|[owner\_less](../Topic/owner_less.md)|Permite comparações mistas baseadas em propriedade de ponteiros compartilhados e fracos.|  
|[pointer\_safety](../Topic/pointer_safety%20Enumeration.md)|Uma enumeração de todos os possíveis valores de retorno para `get_pointer_safety`.|  
|[return\_temporary\_buffer](../Topic/return_temporary_buffer.md)|Desaloca a memória temporária que foi alocada usando a função de modelo `get_temporary_buffer`.|  
|[static\_pointer\_cast](../Topic/static_pointer_cast.md)|Conversão estática para `shared_ptr`.|  
|[swap](../Topic/swap%20\(C++%20Standard%20Library\).md)|Troca dois objetos `shared_ptr` ou `weak_ptr`.|  
|[unchecked\_uninitialized\_copy](../Topic/unchecked_uninitialized_copy.md)|Igual a `uninitialized_copy`, mas permite o uso de um iterador não verificado como iterador de saída quando \_SECURE\_SCL\=1 é definido.|  
|[unchecked\_uninitialized\_fill\_n](../misc/unchecked-uninitialized-fill-n.md)|Igual a `uninitialized_fill_n`, mas permite o uso de um iterador não verificado como iterador de saída quando \_SECURE\_SCL\=1 é definido.|  
|[undeclare\_no\_pointers](../Topic/undeclare_no_pointers.md)|Informa um coletor de lixo que os caracteres no bloco de memória definido por um ponteiro de endereço básico e o tamanho de bloco agora podem conter ponteiros rastreáveis.|  
|[undeclare\_reachable](../Topic/undeclare_reachable.md)|Informa um `garbage_collector` que um local de memória especificado não é alcançável.|  
|[uninitialized\_copy](../Topic/uninitialized_copy.md)|Copia objetos de um intervalo de entrada especificado em um intervalo de destino não inicializado.|  
|[uninitialized\_copy\_n](../Topic/uninitialized_copy_n.md)|Cria uma cópia de um número especificado de elementos de um iterador de entrada.  As cópias são colocadas em um iterador de avanço.|  
|[uninitialized\_fill](../Topic/uninitialized_fill.md)|Copia objetos de um valor especificado em um intervalo de destino não inicializado.|  
|[uninitialized\_fill\_n](../Topic/uninitialized_fill_n.md)|Copia objetos de um valor especificado em um número especificado de elementos de um intervalo de destino não inicializado.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\!\=](../Topic/operator!=%20\(%3Cmemory%3E\).md)|Testa a desigualdade entre objetos do alocador de uma classe especificada.|  
|[operator\=\=](../Topic/operator==%20\(%3Cmemory%3E\).md)|Testa a igualdade entre objetos do alocador de uma classe especificada.|  
|[Operador \>\=](../Topic/operator%3E=%20\(%3Cmemory%3E\).md)|Testa um objeto do alocador que é maior ou igual a um segundo objeto do alocador de uma classe especificada.|  
|[Operador \<](../Topic/operator%3C%20\(%3Cmemory%3E\).md)|Testa um objeto que é menor que um segundo objeto de uma classe especificada.|  
|[Operador \<\=](../Topic/operator%3C=%20\(%3Cmemory%3E\).md)|Testa um objeto que é menor ou igual a um segundo objeto de uma classe especificada.|  
|[Operador \>](../Topic/operator%3E%20\(%3Cmemory%3E\).md)|Testa um objeto que é maior que um segundo objeto de uma classe especificada.|  
|[Operador \<\<](../Topic/operator%3C%3C%20\(%3Cmemory%3E\).md)|Inserção de `shared_ptr`.|  
  
### Classes  
  
|||  
|-|-|  
|[allocator](../standard-library/allocator-class.md)|A classe de modelo descreve um objeto que gerencia a alocação de armazenamento e libera matrizes de objetos do tipo **Type**.|  
|[allocator\_traits](../Topic/allocator_traits%20Class.md)|Descreve um objeto que determina todas as informações necessárias a um contêiner habilitado para alocador.|  
|[auto\_ptr](../standard-library/auto-ptr-class.md)|A classe de modelo descreve um objeto que armazena um ponteiro para um objeto alocado do tipo **Type \*** que garante que o objeto para o qual ele aponta é excluído quando seu auto\_ptr delimitador é destruído.|  
|[bad\_weak\_ptr](../standard-library/bad-weak-ptr-class.md)|Relata a exceção weak\_ptr incorreta.|  
|[enabled\_shared\_from\_this](../standard-library/enable-shared-from-this-class.md)|Ajuda a gerar um `shared_ptr`.|  
|[pointer\_traits](../standard-library/pointer-traits-struct.md)|Fornece informações que são necessárias a um objeto da classe de modelo `allocator_traits` para descrever um alocador com o tipo de ponteiro `Ptr`.|  
|[raw\_storage\_iterator](../Topic/raw_storage_iterator%20Class.md)|Uma classe de adaptador que é fornecida para permitir que algoritmos armazenem seus resultados na memória não inicializada.|  
|[shared\_ptr](../standard-library/shared-ptr-class.md)|Encapsula um ponteiro inteligente de contagem de referência em torno de um objeto alocado dinamicamente.|  
|[unique\_ptr](../standard-library/unique-ptr-class.md)|Armazena um ponteiro para um objeto possuído.  O ponteiro não é possuído por nenhum outro `unique_ptr`.  O `unique_ptr` é destruído quando o proprietário é destruído.|  
|[weak\_ptr](../standard-library/weak-ptr-class.md)|Encapsula um ponteiro vinculado de modo fraco.|  
  
### Especializações  
  
|||  
|-|-|  
|[allocator\<void\>](../standard-library/allocator-void-class.md)|Uma especialização do alocador de classe de modelo para o tipo void, definindo os únicos tipos de membro que fazem sentido neste contexto especializado.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)