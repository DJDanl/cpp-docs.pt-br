---
title: "Classe basic_string | Microsoft Docs"
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
  - "std.basic_string"
  - "std::basic_string"
  - "basic_string"
  - "xstring/std::basic_string"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe basic_string"
ms.assetid: a9c3e0a2-39bf-4c8a-b093-9abe30839591
caps.latest.revision: 19
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe basic_string
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As sequências controladas por um objeto da classe de modelos `basic_string` são a classe de cadeia C \+\+ Padrão e geralmente são conhecidas como cadeias de caracteres, mas não devem ser confundidas com as cadeias de estilo C de terminação nula usadas ​​em toda a biblioteca C \+\+ Padrão.  A cadeia de caracteres C\+\+ Padrão é um contêiner que permite o uso de cadeias de caracteres como tipos de normais, como operações de comparação e concatenação, iteradores, algoritmos STL e cópia e atribuição com memória gerenciada por alocador de classe.  Se você precisar converter uma cadeia de caracteres C\+\+ Padrão em uma cadeia de caracteres de estilo C de terminação nula, use o membro [basic\_string::c\_str](../Topic/basic_string::c_str.md).  
  
## Sintaxe  
  
```  
template <class CharType, class Traits = char_traits<CharType>, class Allocator = allocator<CharType>> class basic_string;  
```  
  
#### Parâmetros  
 `CharType`  
 O tipo de dados de um único caractere a ser armazenado na cadeia de caracteres.  A biblioteca C \+\+ Padrão oferece especializações desta classe de modelo, com a [cadeia](../Topic/string%20\(C++%20STL%20%3Cstring%3E\).md) de definições de tipo para elementos do tipo `char`, [wstring](../Topic/wstring.md), para `wchar_t`, [u16string](../Topic/u16string.md) para `char16_t`, e [u32string](../Topic/u32string.md) para `char32_t`.  
  
 `Traits`  
 Várias propriedades importantes dos elementos **CharType** em uma especialização basic\_string são descritas pela classe **Traits**.  O valor padrão é `char_traits`\<`CharType`\>.  
  
 `Allocator`  
 O tipo que representa o objeto alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória da cadeia de caracteres.  O valor padrão é **allocator**\<`CharType`\>.  
  
### Construtores  
  
|||  
|-|-|  
|[basic\_string](../Topic/basic_string::basic_string.md)|Cria uma cadeia de caracteres vazia ou iniciada por caracteres específicos ou que seja uma cópia de todos ou parte de algum outro objeto da cadeia de caracteres ou da cadeia de caracteres C.|  
  
### Typedefs  
  
|||  
|-|-|  
|[allocator\_type](../Topic/basic_string::allocator_type.md)|Um tipo que representa a classe `allocator` para um objeto da cadeia de caracteres.|  
|[const\_iterator](../Topic/basic_string::const_iterator.md)|Um tipo que fornece um iterador de acesso aleatório que pode acessar e ler um elemento `const` na cadeia de caracteres.|  
|[const\_pointer](../Topic/basic_string::const_pointer.md)|Um tipo que fornece um ponteiro para um elemento `const` em uma cadeia de caracteres.|  
|[const\_reference](../Topic/basic_string::const_reference.md)|Um tipo que fornece uma referência para um elemento `const` armazenado em um cadeia para leitura e execução de operações `const`.|  
|[const\_reverse\_iterator](../Topic/basic_string::const_reverse_iterator.md)|Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento `const` na cadeia de caracteres.|  
|[difference\_type](../Topic/basic_string::difference_type.md)|Um tipo que fornece a diferença entre dois iteradores que se referem a elementos na mesma cadeia.|  
|[iterator](../Topic/basic_string::iterator.md)|Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em uma cadeia de caracteres.|  
|[npos](../Topic/basic_string::npos.md)|Um valor integral não assinado inicializado como – 1 que indica "não encontrado" ou "todos os demais caracteres" quando uma função de pesquisa falha.|  
|[pointer](../Topic/basic_string::pointer.md)|Um tipo que fornece um ponteiro para um elemento de caracteres em uma matriz de cadeia de caracteres ou caractere.|  
|[reference](../Topic/basic_string::reference.md)|Um tipo que fornece uma referência a um elemento armazenado em uma cadeia de caracteres.|  
|[reverse\_iterator](../Topic/basic_string::reverse_iterator.md)|Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em uma cadeia de caracteres invertida.|  
|[size\_type](../Topic/basic_string::size_type.md)|Um tipo integral não assinado para o número de elementos em uma cadeia.|  
|[traits\_type](../Topic/basic_string::traits_type.md)|Um tipo para as características dos elementos armazenados em uma cadeia de caracteres.|  
|[value\_type](../Topic/basic_string::value_type.md)|Um tipo que representa o tipo de caracteres armazenados em uma cadeia de caracteres.|  
  
### Funções membro  
  
|||  
|-|-|  
|[acrescentar](../Topic/basic_string::append.md)|Acrescenta caracteres ao final de uma cadeia de caracteres.|  
|[assign](../Topic/basic_string::assign.md)|Atribui novos valores de caracteres ao conteúdo de uma cadeia de caracteres.|  
|[at](../Topic/basic_string::at.md)|Retorna uma referência ao elemento em um local especificado na cadeia de caracteres.|  
|[back](../Topic/basic_string::back.md)||  
|[begin](../Topic/basic_string::begin.md)|Retorna um iterador que trata o primeiro elemento na cadeia de caracteres.|  
|[c\_str](../Topic/basic_string::c_str.md)|Converte o conteúdo de uma cadeia de caracteres em uma cadeia de estilo C, com terminação nula.|  
|[capacity](../Topic/basic_string::capacity.md)|Retorna o maior número de elementos que podem ser armazenados em uma cadeia de caracteres sem aumentar a alocação de memória da cadeia.|  
|[cbegin](../Topic/basic_string::cbegin.md)|Retorna um iterador const que trata o primeiro elemento na cadeia.|  
|[cend](../Topic/basic_string::cend.md)|Retorna um iterador const que trata o local após o último elemento em uma cadeia.|  
|[clear](../Topic/basic_string::clear.md)|Apaga todos os elementos de uma cadeia de caracteres.|  
|[compare](../Topic/basic_string::compare.md)|Compara uma cadeia de caracteres com uma cadeia especificada para determinar se duas cadeias são iguais ou se uma é lexicograficamente menor do que a outra.|  
|[copy](../Topic/basic_string::copy.md)|Copia, no máximo, um número específico de caracteres de uma posição indexada em uma cadeia de caracteres de origem em um conjunto de caracteres de destino.  Preterido.  Use [basic\_string::\_Copy\_s](../Topic/basic_string::_Copy_s.md) em seu lugar.|  
|[crbegin](../Topic/basic_string::crbegin.md)|Retorna um iterador const que trata o primeiro elemento em uma cadeia de caracteres invertida.|  
|[crend](../Topic/basic_string::crend.md)|Retorna um iterador const que trata o local após o último elemento em uma cadeia invertida.|  
|[\_Copy\_s](../Topic/basic_string::_Copy_s.md)|Copia, no máximo, um número específico de caracteres de uma posição indexada em uma cadeia de caracteres de origem em um conjunto de caracteres de destino.|  
|[dados](../Topic/basic_string::data.md)|Converte o conteúdo de uma cadeia de caracteres em uma matriz de caracteres.|  
|[empty](../Topic/basic_string::empty.md)|Testa se a cadeia de caracteres contém caracteres.|  
|[end](../Topic/basic_string::end.md)|Retorna um iterador que trata o local após o último elemento em uma cadeia de caracteres.|  
|[erase](../Topic/basic_string::erase.md)|Remove um elemento ou um intervalo de elementos em uma cadeia de caracteres de uma posição especificada.|  
|[find](../Topic/basic_string::find.md)|Pesquisa, para frente, em uma cadeia de caracteres, a primeira ocorrência de uma subcadeia que corresponde a uma sequência de caracteres especificada.|  
|[find\_first\_not\_of](../Topic/basic_string::find_first_not_of.md)|Pesquisa, em uma cadeia de caracteres, o primeiro caractere que não seja um elemento de uma cadeia de caracteres especificada.|  
|[find\_first\_of](../Topic/basic_string::find_first_of.md)|Pesquisa, em uma cadeia de caracteres, o primeiro caractere que corresponda a qualquer elemento de uma cadeia de caracteres especificada.|  
|[find\_last\_not\_of](../Topic/basic_string::find_last_not_of.md)|Pesquisa, em uma cadeia de caracteres, o último caractere que não seja um elemento de uma cadeia de caracteres especificada.|  
|[find\_last\_of](../Topic/basic_string::find_last_of.md)|Pesquisa, em uma cadeia de caracteres, o último caractere que seja um elemento de uma cadeia de caracteres especificada.|  
|[front](../Topic/basic_string::front.md)|Retorna uma referência ao primeiro elemento em uma cadeia de caracteres.|  
|[get\_allocator](../Topic/basic_string::get_allocator.md)|Retorna uma cópia do objeto `allocator` usado para construir a cadeia.|  
|[insert](../Topic/basic_string::insert.md)|Insere um elemento ou um número de elementos ou um intervalo de elementos na cadeia de caracteres na posição especificada.|  
|[length](../Topic/basic_string::length.md)|Retorna o número de elementos em uma cadeia de caracteres.|  
|[max\_size](../Topic/basic_string::max_size.md)|Retorna o número máximo de caracteres que uma cadeia de caracteres pode conter.|  
|[pop\_back](../Topic/basic_string::pop_back.md)|Apaga o último elemento da cadeia de caracteres.|  
|[push\_back](../Topic/basic_string::push_back.md)|Adiciona um elemento ao final de uma cadeia de caracteres.|  
|[rbegin](../Topic/basic_string::rbegin.md)|Retorna um iterador ao primeiro elemento em uma cadeia invertida.|  
|[rend](../Topic/basic_string::rend.md)|Retorna um iterador que aponta além do último elemento em uma cadeia de caracteres invertida.|  
|[replace](../Topic/basic_string::replace.md)|Substitui elementos em uma cadeia de caractere em uma posição especificada por caracteres especificados ou copiados de outros intervalos de cadeia de caracteres ou cadeias C.|  
|[reserve](../Topic/basic_string::reserve.md)|Define a capacidade da cadeia de caracteres para um número pelo menos tão grande quanto um número especificado.|  
|[resize](../Topic/basic_string::resize.md)|Especifica um novo tamanho para uma cadeia de caracteres, acrescentando ou apagando elementos conforme necessário.|  
|[rfind](../Topic/basic_string::rfind.md)|Pesquisa, para trás, em uma cadeia de caracteres, a primeira ocorrência de uma subcadeia que corresponde a uma sequência de caracteres especificada.|  
|[shrink\_to\_fit](../Topic/basic_string::shrink_to_fit.md)|Descarta a capacidade excedente da cadeia de caracteres.|  
|[size](../Topic/basic_string::size.md)|Retorna o número de elementos em uma cadeia de caracteres.|  
|[substr](../Topic/basic_string::substr.md)|Copia uma subcadeia de, no máximo, um número de caracteres, de uma cadeia com início em uma posição especificada.|  
|[swap](../Topic/basic_string::swap.md)|Troca o conteúdo das duas cadeias de caracteres.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\+\=](../Topic/basic_string::operator+=.md)|Acrescenta caracteres a uma cadeia de caracteres.|  
|[operator\=](../Topic/basic_string::operator=.md)|Atribui novos valores de caracteres ao conteúdo de uma cadeia de caracteres.|  
|[operator&#91;&#93;](../Topic/basic_string::operator.md)|Fornece uma referência ao caractere com um índice especificado em uma cadeia de caracteres.|  
  
## Comentários  
 Se uma função for solicitada a gerar uma sequência mais longa do que os elementos [max\_size](../Topic/basic_string::max_size.md), a função relatará um erro de duração utilizando um objeto do tipo [length\_error](../Topic/length_error%20Class.md).  
  
 Referências, ponteiros e iteradores que designam elementos da sequência controlada podem se tornar inválidos após qualquer chamada de uma função que altera a sequência controlada ou após a primeira chamada de função de um membro não **const**.  
  
## Requisitos  
 **Cabeçalho:** \<string\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<string\>](../standard-library/string.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)