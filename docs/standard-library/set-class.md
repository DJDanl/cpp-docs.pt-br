---
title: "Classe set | Microsoft Docs"
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
  - "std::set"
  - "set"
  - "set/std::set"
  - "std.set"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe set"
ms.assetid: 8991f9aa-5509-4440-adc1-371512d32018
caps.latest.revision: 22
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe set
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O conjunto de classes de contêiner da STL é usado para o armazenamento e a recuperação de dados de uma coleção na qual os valores dos elementos contidos são exclusivos e funcionam como os valores de chave, de acordo com os quais os dados são automaticamente ordenados.  O valor de um elemento em um conjunto não pode ser alterado diretamente.  Em vez disso, você deve excluir valores antigos e inserir elementos com novos valores.  
  
## Sintaxe  
  
```  
template <  
    class Key,   
    class Traits=less<Key>,   
    class Allocator=allocator<Key>   
>  
class set  
```  
  
#### Parâmetros  
 `Key`  
 O tipo de dados do elemento a ser armazenado no conjunto.  
  
 `Traits`  
 O tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no conjunto.  Esse argumento é opcional e o predicado binário **menos** *\< chave \>* é o valor padrão.  
  
 No C\+\+ 14, você pode habilitar pesquisa heterogênea, especificando a `std::less<>` ou `std::greater<>` predicado que não tem nenhum parâmetro de tipo.  Para obter mais informações, consulte [pesquisa heterogêneos em contêineres associativos](../standard-library/stl-containers.md#sequence_containers)  
  
 `Allocator`  
 O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre a alocação e a desalocação do conjunto da memória.  Esse argumento é opcional e o valor padrão é **allocator***\<Key\>.*  
  
## Comentários  
 Um conjunto da STL é:  
  
-   Um contêiner associativo, que é um contêiner de tamanho variável que oferece suporte à recuperação eficiente dos valores de elemento com base em um valor de chave associado.  Além disso, é um contêiner associativo simples, pois seus valores de elemento são seus valores de chave.  
  
-   Reversível, pois fornece um iterador bidirecional para acessar seus elementos.  
  
-   Classificada, pois seus elementos são ordenados por valores de chave no contêiner, de acordo com uma função de comparação especificada.  
  
-   Exclusivo no sentido de que cada um de seus elementos deve ter uma chave exclusiva.  Uma vez que o conjunto também é um contêiner associativo simples, seus elementos também são exclusivos.  
  
 Um conjunto também é descrito como uma classe de modelo, pois a funcionalidade fornecida por ele é genérica e independente do tipo de dados específico contido como elementos.  O tipo de dados a ser usado é especificado como um parâmetro no modelo de classe juntamente com a função de comparação e o alocador.  
  
 A escolha do tipo de contêiner deve se basear, de modo geral, no tipo de pesquisa e inserção exigido pelo aplicativo.  Os contêineres associativos são otimizados para as operações de pesquisa, inserção e remoção.  As funções membro que oferecem suporte explicitamente a essas operações são eficientes, executando\-as em um tempo que está na média proporcional para o logaritmo do número de elementos no contêiner.  A inserção de elementos não invalida iteradores e a remoção de elementos invalida apenas os iteradores que apontavam especificamente os elementos removidos.  
  
 O conjunto deve ser o contêiner associativo escolhido quando as condições que associam os valores às respectivas chaves forem atendidas pelo aplicativo.  Os elementos de um conjunto são exclusivos e servem como suas próprias chaves de classificação.  Um modelo para esse tipo de estrutura é uma lista ordenada de palavras, por exemplo, na qual as palavras podem ocorrer apenas uma vez.  Se não foram permitidas as várias ocorrências das palavras, um multiset seria a estrutura de contêiner apropriada.  Se for preciso anexar valores a uma lista de palavras\-chave exclusivas, um mapa será uma estrutura apropriada para conter esses dados.  Se, em vez disso, as chaves não forem exclusivas, um multimapa será o contêiner ideal.  
  
 O conjunto ordena a sequência que controla chamando um objeto de função armazenado do tipo [key\_compare](../Topic/set::key_compare.md).  Esse objeto armazenado é uma função de comparação que pode ser acessada chamando a função membro [key\_comp](../Topic/set::key_comp.md).  De modo geral, os elementos precisam ser simplesmente menores que os comparáveis para estabelecer essa ordem, de modo que, considerando dois elementos quaisquer, pode ser determinado que, ou eles são equivalentes \(no sentido de que nenhum deles é menor que o outro\), ou que um é menor que o outro.  Isso resulta em uma ordenação entre os elementos não equivalentes.  Fazendo uma observação mais técnica, a função de comparação é um predicado binário que induz a uma ordenação fraca restrita no sentido matemático padrão.  Um predicado binário *f*\(*x,y*\) é um objeto de função que possui dois objetos de argumento *x* e *y* e um valor de retorno de **true** ou **false**.  Uma ordenação imposta em um conjunto será uma ordenação fraca restrita se o predicado binário for irreflexivo, antissimétrico e transitivo, e se a equivalência for transitiva, onde dois objetos *x* e *y* são definidos para serem equivalentes quando ambos, *f*\(*x,y*\) e *f*\(*y,x*\) são falsos.  Se a condição mais forte de igualdade entre as chaves substituir essa equivalência, a ordenação será total \(no sentido de que todos os elementos serão ordenados um em relação ao outro\) e as chaves correspondentes não poderão ser diferenciadas uma da outra.  
  
 No C\+\+ 14, você pode habilitar pesquisa heterogênea, especificando a `std::less<>` ou `std::greater<>` predicado que não tem nenhum parâmetro de tipo.  Para obter mais informações, consulte [pesquisa heterogêneos em contêineres associativos](../standard-library/stl-containers.md#sequence_containers)  
  
 O iterador fornecido pela classe de conjunto é um iterador bidirecional, mas as funções membro de classe [insert](../Topic/set::insert.md) e [set](../Topic/set::set.md) possuem versões que usam como parâmetros de modelo um iterador de entrada mais fraco, cujos requisitos de funcionalidade são mais minimalistas do que os garantidos pela classe de iteradores bidirecionais.  Os conceitos de iterador diferente formam uma família relacionada por refinamentos em sua funcionalidade.  Cada conceito de iterador tem seu próprio conjunto de requisitos e os algoritmos que funcionam com eles devem limitar suas suposições para os requisitos fornecidos por esse tipo de iterador.  Pode ser pressuposto que um iterador de entrada possa ser desreferenciado para fazer referência a algum objeto e que possa ser incrementado para o próximo iterador na sequência.  Esse é um conjunto mínimo de funcionalidade, mas é suficiente para poder expressar de forma significativa um intervalo de iteradores \[`First`, `Last`\) no contexto de funções membro da classe.  
  
### Construtores  
  
|||  
|-|-|  
|[definir](../Topic/set::set.md)|Constrói um conjunto que está vazio ou que é uma cópia de todo ou parte de algum outro conjunto.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[allocator\_type](../Topic/set::allocator_type.md)|Um tipo que representa a classe `allocator` para o objeto de conjunto.|  
|[const\_iterator](../Topic/set::const_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler um elemento `const` no conjunto.|  
|[const\_pointer](../Topic/set::const_pointer.md)|Um tipo que fornece um ponteiro para um elemento `const` em um conjunto.|  
|[const\_reference](../Topic/set::const_reference.md)|Um tipo que fornece uma referência para um elemento `const` armazenado em um conjunto para leitura e execução de operações `const`.|  
|[const\_reverse\_iterator](../Topic/set::const_reverse_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento `const` no conjunto.|  
|[difference\_type](../Topic/set::difference_type.md)|Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de um conjunto em um intervalo entre os elementos apontado pelos iteradores.|  
|[iterator](../Topic/set::iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em um conjunto.|  
|[key\_compare](../Topic/set::key_compare.md)|Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no conjunto.|  
|[key\_type](../Topic/set::key_type.md)|O tipo descreve um objeto armazenado como um elemento de um conjunto em sua capacidade como chave de classificação.|  
|[pointer](../Topic/set::pointer.md)|Um tipo que fornece um ponteiro para um elemento em um conjunto.|  
|[referência](../Topic/set::reference.md)|Um tipo que fornece uma referência a um elemento armazenado em um conjunto.|  
|[reverse\_iterator](../Topic/set::reverse_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um conjunto invertido.|  
|[size\_type](../Topic/set::size_type.md)|Um tipo de inteiro sem sinal que pode representar o número de elementos em um conjunto.|  
|[value\_compare](../Topic/set::value_compare.md)|O tipo que fornece um objeto de função que pode comparar dois elementos para determinar sua ordem relativa no conjunto.|  
|[value\_type](../Topic/set::value_type.md)|O tipo descreve um objeto armazenado como um elemento de um conjunto em sua capacidade como um valor.|  
  
### Funções membro  
  
|||  
|-|-|  
|[begin](../Topic/set::begin.md)|Retorna um iterador que trata o primeiro elemento no conjunto.|  
|[cbegin](../Topic/set::cbegin.md)|Retorna um iterador const que trata o primeiro elemento no conjunto.|  
|[cend](../Topic/set::cend.md)|Retorna um iterador const que trata o local após o último elemento em um conjunto.|  
|[limpar](../Topic/set::clear.md)|Apaga todos os elementos de um conjunto.|  
|[count](../Topic/set::count.md)|Retorna o número de elementos em um conjunto cuja chave corresponde a uma chave especificada pelo parâmetro.|  
|[crbegin](../Topic/set::rbegin.md)|Retorna um iterador const que trata o primeiro elemento em um conjunto invertido.|  
|[crend](../Topic/set::rend.md)|Retorna um iterador const que trata o local após o último elemento em um conjunto invertido.|  
|[emplace](../Topic/set::emplace.md)|Insere um elemento construído adequadamente em um conjunto.|  
|[emplace\_hint](../Topic/set::emplace_hint.md)|Insere um elemento construído adequadamente em um conjunto, com uma dica de posicionamento.|  
|[vazio](../Topic/set::empty.md)|Testa se um conjunto está vazio.|  
|[end](../Topic/set::end.md)|Retorna um iterador que trata o local após o último elemento em um conjunto.|  
|[equal\_range](../Topic/set::equal_range.md)|Retorna um par de iteradores respectivamente para o primeiro elemento em um conjunto com uma chave que é maior do que uma chave especificada e para o primeiro elemento no conjunto com uma chave igual ou maior que a chave.|  
|[erase](../Topic/set::erase.md)|Remove um elemento ou um intervalo de elementos em um conjunto das posições especificadas ou remove elementos que correspondem a uma chave especificada.|  
|[find](../Topic/set::find.md)|Retorna um iterador que trata o local de um elemento em um conjunto que tem uma chave equivalente a uma chave especificada.|  
|[get\_allocator](../Topic/set::get_allocator.md)|Retorna uma cópia do objeto `allocator` usada para construir o conjunto.|  
|[inserir](../Topic/set::insert.md)|Insere um elemento ou um intervalo de elementos em um conjunto.|  
|[key\_comp](../Topic/set::key_comp.md)|Recupera uma cópia do objeto de comparação usada para ordenar chaves em um conjunto.|  
|[lower\_bound](../Topic/set::lower_bound.md)|Retorna um iterador para o primeiro elemento em um conjunto com uma chave que é igual ou maior que uma chave especificada.|  
|[max\_size](../Topic/set::max_size.md)|Retorna o comprimento máximo do conjunto.|  
|[rbegin](../Topic/set::rbegin.md)|Retorna um iterador que trata o primeiro elemento em um conjunto invertido.|  
|[rend](../Topic/set::rend.md)|Retorna um iterador que trata o local após o último elemento em um conjunto invertido.|  
|[size](../Topic/set::size.md)|Retorna o número de elementos no conjunto.|  
|[swap](../Topic/set::swap.md)|Troca os elementos de dois conjuntos.|  
|[upper\_bound](../Topic/set::upper_bound.md)|Retorna um iterador para o primeiro elemento em um conjunto com uma chave que é maior que uma chave especificada.|  
|[value\_comp](../Topic/set::value_comp.md)|Recupera uma cópia do objeto de comparação usada para ordenar valores de elemento em um conjunto.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\=](../Topic/set::operator=.md)|Substitui os elementos de um conjunto por uma cópia de outro conjunto.|  
  
## Requisitos  
 **Cabeçalho:** \<set\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<set\>](../standard-library/set.md)   
 [contêineres](../Topic/Containers%20\(Modern%20C++\).md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)