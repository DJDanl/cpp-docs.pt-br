---
title: "Classe multimap | Microsoft Docs"
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
  - "multimap"
  - "std.multimap"
  - "map/std::multimap"
  - "std::multimap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe multimap"
ms.assetid: 8796ae05-37c4-475a-9e61-75fde9d4a463
caps.latest.revision: 23
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe multimap
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de multimapa da Biblioteca Modelo Padrão é usada para o armazenamento e a recuperação de dados de uma coleção em que cada elemento é um par que contém um valor de dados e uma chave de classificação.  O valor da chave não precisa ser exclusivo e é usado para ordenar os dados automaticamente.  O valor de um elemento em um multimapa, mas não seu valor de chave associado, pode ser alterado diretamente.  Em vez disso, os valores de chave associados aos elementos antigos devem ser excluídos e os novos valores de chave associados aos novos elementos inseridos.  
  
## Sintaxe  
  
```  
template <  
   class Key,   
   class Type,   
   class Traits=less<Key>,   
   class Allocator=allocator<pair <const Key, Type> >   
> class multimap;  
```  
  
#### Parâmetros  
 `Key`  
 O tipo de dados da chave a ser armazenado no multimapa.  
  
 `Type`  
 O tipo de dados do elemento a ser armazenado no multimapa.  
  
 `Traits`  
 O tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no multimapa.  O predicado binário `less<Key>` é o valor padrão.  
  
 No C\+\+ 14, você pode habilitar pesquisa heterogênea, especificando a `std::less<>` ou `std::greater<>` predicado que não tem nenhum parâmetro de tipo.  Para obter mais informações, consulte [pesquisa heterogêneos em contêineres associativos](../standard-library/stl-containers.md#sequence_containers)  
  
 `Allocator`  
 O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre a alocação e a desalocação do mapa da memória.  Esse argumento é opcional e o valor padrão é `allocator<pair <const Key, Type> >`.  
  
## Comentários  
 A classe de multimapa da STL é  
  
-   Um contêiner associativo, que é um contêiner de tamanho variável que oferece suporte à recuperação eficiente dos valores de elemento com base em um valor de chave associado.  
  
-   Reversível, pois fornece iteradores bidirecionais para acessar seus elementos.  
  
-   Classificada, pois seus elementos são ordenados por valores de chave no contêiner, de acordo com uma função de comparação especificada.  
  
-   Múltipla, pois seus elementos não precisam ter chaves exclusivas para que um valor de chave possa ter muitos valores de dados de elemento associados a ele.  
  
-   Um contêiner de par associativo, pois seus valores de dados de elemento são distintos de seus valores de chave.  
  
-   Uma classe de modelo, pois a funcionalidade fornecida por ela é genérica e, portanto, independente do tipo de dados específico contido como elementos ou chaves.  Os tipos de dados a serem usados para elementos e chaves são especificados como parâmetros no modelo de classe juntamente com o alocador e a função de comparação.  
  
 O iterador fornecido pela classe de mapa é um iterador bidirecional, mas as funções membro de classe [insert](../Topic/multimap::insert.md) e [multimap](../Topic/multimap::multimap.md) possuem versões que usam como parâmetros de modelo um iterador de entrada mais fraco, cujos requisitos de funcionalidade são mais minimalistas do que os garantidos pela classe de iteradores bidirecionais.  Os conceitos de iterador diferente formam uma família relacionada por refinamentos em sua funcionalidade.  Cada conceito de iterador tem seu próprio conjunto de requisitos e os algoritmos que funcionam com eles devem limitar suas suposições para os requisitos fornecidos por esse tipo de iterador.  Pode ser pressuposto que um iterador de entrada possa ser desreferenciado para fazer referência a algum objeto e que possa ser incrementado para o próximo iterador na sequência.  Esse é um conjunto mínimo de funcionalidade, mas é suficiente para poder expressar de forma significativa um intervalo de iteradores `[First, Last)` no contexto de funções membro da classe.  
  
 A escolha do tipo de contêiner deve se basear, de modo geral, no tipo de pesquisa e inserção exigido pelo aplicativo.  Os contêineres associativos são otimizados para as operações de pesquisa, inserção e remoção.  As funções membro que oferecem suporte explicitamente a essas operações são eficientes, executando\-as em um tempo que está na média proporcional para o logaritmo do número de elementos no contêiner.  A inserção de elementos não invalida iteradores e a remoção de elementos invalida apenas os iteradores que apontavam especificamente os elementos removidos.  
  
 O multimapa deve ser o contêiner associativo escolhido quando as condições que associam os valores às respectivas chaves forem atendidas pelo aplicativo.  Um modelo para esse tipo de estrutura é uma lista ordenada de palavras\-chave com valores de cadeia de caracteres associados que fornecem, por exemplo, definições, em que as palavras nem sempre foram definidas exclusivamente.  Se, em vez disso, as palavras\-chave foram definidas exclusivamente para que essas chaves fossem exclusivas, um mapa seria o contêiner ideal.  Se, por outro lado, apenas as listas de palavras foram sendo armazenadas, um conjunto seria o contêiner correto.  Se não foram permitidas as várias ocorrências das palavras, um multiset seria a estrutura de contêiner apropriada.  
  
 O multimapa ordena a sequência que controla chamando um objeto de função armazenado do tipo [key\_compare](../Topic/multimap::key_compare.md).  Esse objeto armazenado é uma função de comparação que pode ser acessada chamando a função membro [key\_comp](../Topic/multimap::key_comp.md).  De modo geral, os elementos precisam ser simplesmente menores que os comparáveis para estabelecer essa ordem: desse modo, considerando dois elementos, pode ser determinado que, ou eles são equivalentes \(no sentido de que nenhum deles é menor que o outro\), ou que um é menor que o outro.  Isso resulta em uma ordenação entre os elementos não equivalentes.  Fazendo uma observação mais técnica, a função de comparação é um predicado binário que induz a uma ordenação fraca restrita no sentido matemático padrão.  Um predicado binário `f(x,y)` é um objeto de função que possui dois objetos de argumento, `x` e `y`, e um valor de retorno de true ou false.  Uma ordenação imposta em um conjunto será uma ordenação fraca restrita se o predicado binário for irreflexivo, antissimétrico e transitivo, e se a equivalência for transitiva, onde dois objetos `x` e `y` são definidos para serem equivalentes quando ambos, `f(x,y)` e `f(y,x)` são false.  Se a condição mais forte de igualdade entre as chaves substituir essa equivalência, a ordenação será total \(no sentido de que todos os elementos serão ordenados um em relação ao outro\) e as chaves correspondentes não poderão ser diferenciadas uma da outra.  
  
 No C\+\+ 14, você pode habilitar pesquisa heterogênea, especificando a `std::less<>` ou `std::greater<>` predicado que não tem nenhum parâmetro de tipo.  Para obter mais informações, consulte [pesquisa heterogêneos em contêineres associativos](../standard-library/stl-containers.md#sequence_containers)  
  
## Membros  
  
### Construtores  
  
|||  
|-|-|  
|[multimap](../Topic/multimap::multimap.md)|Constrói um `multimap` que está vazio ou que é uma cópia de todo ou parte de algum outro `multimap`.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[allocator\_type](../Topic/multimap::allocator_type.md)|Um tipo que representa a classe `allocator` para o objeto `multimap`.|  
|[const\_iterator](../Topic/multimap::const_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler um elemento `const` no `multimap`.|  
|[const\_pointer](../Topic/multimap::const_pointer.md)|Um tipo que fornece um ponteiro para um elemento `const` em um `multimap`.|  
|[const\_reference](../Topic/multimap::const_reference.md)|Um tipo que fornece uma referência para um elemento `const` armazenado em um `multimap` para leitura e execução de operações `const`.|  
|[const\_reverse\_iterator](../Topic/multimap::const_reverse_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento `const` no `multimap`.|  
|[difference\_type](../Topic/multimap::difference_type.md)|Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de um `multimap` em um intervalo entre os elementos apontado pelos iteradores.|  
|[iterator](../Topic/multimap::iterator.md)|Um tipo que fornece a diferença entre dois iteradores que se referem a elementos no mesmo `multimap`.|  
|[key\_compare](../Topic/multimap::key_compare.md)|Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no `multimap`.|  
|[key\_type](../Topic/multimap::key_type.md)|Um tipo que descreve o objeto de chave de classificação que constitui cada elemento do `multimap`.|  
|[mapped\_type](../Topic/multimap::mapped_type.md)|Um tipo que representa o tipo de dados armazenado em um `multimap`.|  
|[pointer](../Topic/multimap::pointer.md)|Um tipo que fornece um ponteiro para um elemento `const` em um `multimap`.|  
|[referência](../Topic/multimap::reference.md)|Um tipo que fornece uma referência a um elemento armazenado em um `multimap`.|  
|[reverse\_iterator](../Topic/multimap::reverse_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um `multimap` invertido.|  
|[size\_type](../Topic/multimap::size_type.md)|Um tipo de inteiro sem sinal que fornece um ponteiro para um elemento `const` em um `multimap`.|  
|[value\_type](../Topic/multimap::value_type.md)|Um tipo que fornece um objeto de função que pode comparar dois elementos como chaves de classificação para determinar sua ordem relativa no `multimap`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[begin](../Topic/multimap::begin.md)|Retorna um iterador que trata o primeiro elemento no `multimap`.|  
|[cbegin](../Topic/multimap::cbegin.md)|Retorna um iterador const que trata o primeiro elemento no `multimap`.|  
|[cend](../Topic/multimap::cend.md)|Retorna um iterador const que trata o local após o último elemento em um `multimap`.|  
|[limpar](../Topic/multimap::clear.md)|Apaga todos os elementos de um `multimap`.|  
|[count](../Topic/multimap::count.md)|Retorna o número de elementos em um `multimap` cuja chave corresponde a uma chave especificada pelo parâmetro.|  
|[crbegin](../Topic/multimap::crbegin.md)|Retorna um iterador const que trata o primeiro elemento em um `multimap` invertido.|  
|[crend](../Topic/multimap::crend.md)|Retorna um iterador const que trata o local após o último elemento em um `multimap` invertido.|  
|[emplace](../Topic/multimap::emplace.md)|Insere um elemento construído adequadamente em um `multimap`.|  
|[emplace\_hint](../Topic/multimap::emplace_hint.md)|Insere um elemento construído adequadamente em um `multimap`, com uma dica de posicionamento|  
|[vazio](../Topic/multimap::empty.md)|Testa se `multimap` está vazio.|  
|[end](../Topic/multimap::end.md)|Retorna um iterador que trata o local após o último elemento em um `multimap`.|  
|[equal\_range](../Topic/multimap::equal_range.md)|Localiza o intervalo de elementos em que a chave do elemento corresponde a um valor especificado.|  
|[erase](../Topic/multimap::erase.md)|Remove um elemento ou um intervalo de elementos em um `multimap` das posições especificadas ou remove elementos que correspondem a uma chave especificada.|  
|[find](../Topic/multimap::find.md)|Retorna um iterador que trata o primeiro local de um elemento em um `multimap` que tem uma chave equivalente a uma chave especificada.|  
|[get\_allocator](../Topic/multimap::get_allocator.md)|Retorna uma cópia do objeto `allocator` usada para construir o `multimap`.|  
|[inserir](../Topic/multimap::insert.md)|Insere um elemento ou um intervalo de elementos em um `multimap`.|  
|[key\_comp](../Topic/multimap::key_comp.md)|Recupera uma cópia do objeto de comparação usada para ordenar chaves em um `multimap`.|  
|[lower\_bound](../Topic/multimap::lower_bound.md)|Retorna um iterador para o primeiro elemento em um `multimap` com uma chave que é igual ou maior que uma chave especificada.|  
|[max\_size](../Topic/multimap::max_size.md)|Retorna o comprimento máximo do `multimap`.|  
|[rbegin](../Topic/multimap::rbegin.md)|Retorna um iterador que trata o primeiro elemento em um `multimap` invertido.|  
|[rend](../Topic/multimap::rend.md)|Retorna um iterador que trata o local após o último elemento em um `multimap` invertido.|  
|[size](../Topic/multimap::size.md)|Retorna o número de elementos no `multimap`.|  
|[swap](../Topic/multimap::swap.md)|Troca os elementos de dois `multimap`s.|  
|[upper\_bound](../Topic/multimap::upper_bound.md)|Retorna um iterador para o primeiro elemento em um `multimap` com uma chave que é maior que uma chave especificada.|  
|[value\_comp](../Topic/multimap::value_comp.md)|A função membro retorna um objeto de função que determina a ordem dos elementos em um `multimap` comparando os respectivos valores de chave.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\=](../Topic/multimap::operator=.md)|Substitui os elementos de um `multimap` por uma cópia de outro `multimap`.|  
  
## Requisitos  
 **Cabeçalho:** \<map\>  
  
 **Namespace:** std  
  
 Os pares \(**chave**, **valor**\) são armazenados em um multimapa como objetos do tipo `pair`.  A classe de par exige o cabeçalho \<utility\>, que é automaticamente incluído por \<map\>.  
  
## Consulte também  
 [\<map\> Membros](http://msdn.microsoft.com/pt-br/7e8f0bc2-6034-40f6-9d14-76d4cef86308)   
 [contêineres](../Topic/Containers%20\(Modern%20C++\).md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)