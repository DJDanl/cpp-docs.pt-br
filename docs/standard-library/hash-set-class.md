---
title: "Classe hash_set | Microsoft Docs"
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
  - "hash_set/stdext::hash_set"
  - "std::hash_set"
  - "std.hash_set"
  - "stdext::hash_set"
  - "hash_set"
  - "stdext.hash_set"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe hash_set"
ms.assetid: c765c06e-cbb6-48c2-93ca-d15468eb28d7
caps.latest.revision: 22
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe hash_set
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Esta API está obsoleta.  A alternativa é[Classe unordered\_set](../standard-library/unordered-set-class.md).  
  
 O hash\_set da classe de contêiner é uma extensão do modelo Biblioteca STL \(Standard\) e é usado para o armazenamento e recuperação rápida de dados de uma coleção na qual os valores dos elementos contidos são exclusivos e servem como os valores de chave.  
  
## Sintaxe  
  
```  
template <  
   class Key,   
   class Traits=hash_compare<Key, less<Key> >,   
   class Allocator=allocator<Key>   
>  
class hash_set  
```  
  
#### Parâmetros  
 `Key`  
 O tipo de dados do elemento a ser armazenado na hash\_set.  
  
 `Traits`  
 O tipo que inclui dois objetos de função, uma classe comparar que é um predicado binário capaz de comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa e uma função de hash que é um predicado unário mapeamento de valores de chave dos elementos inteiros sem sinal do tipo**size\_t**.  Esse argumento é opcional e o`hash_compare`*\< chave,***menos***\< chave \>\>*é o valor padrão.  
  
 `Allocator`  
 O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre o hash\_set alocação e desalocação de memória.  Esse argumento é opcional e o valor padrão é **allocator***\<Key\>.*  
  
## Comentários  
 O hash\_set é:  
  
-   Um contêiner associativo, que é um contêiner de tamanho variável que oferece suporte à recuperação eficiente dos valores de elemento com base em um valor de chave associado.  Além disso, é um contêiner associativo simples, pois seus valores de elemento são seus valores de chave.  
  
-   Reversível, pois fornece um iterador bidirecional para acessar seus elementos.  
  
-   Hashed, pois seus elementos são agrupados em blocos com base no valor de uma função de hash aplicado aos valores de chave de elementos.  
  
-   Exclusivo no sentido de que cada um de seus elementos deve ter uma chave exclusiva.  Como hash\_set também é um contêiner associativo simples, seus elementos também são exclusivos.  
  
-   Uma classe de modelo porque a funcionalidade fornecida por ela é genérica e portanto, independente do tipo específico de dados contido como elementos ou chaves.  Os tipos de dados a serem usados para elementos e chaves são especificados como parâmetros no modelo de classe juntamente com o alocador e a função de comparação.  
  
 A principal vantagem de hashing sobre a classificação é maior eficiência; um hash bem\-sucedida executa inserções, exclusões e localiza em constante tempo médio, em comparação com um tempo proporcional para o logaritmo do número de elementos no contêiner de técnicas de classificação.  O valor de um elemento em um conjunto não pode ser alterado diretamente.  Em vez disso, você deve excluir valores antigos e inserir elementos com novos valores.  
  
 A escolha do tipo de contêiner deve se basear, de modo geral, no tipo de pesquisa e inserção exigido pelo aplicativo.  Hash contêineres associativos são otimizados para as operações de pesquisa, inserção e remoção.  As funções de membro que oferecem suporte explicitamente essas operações são eficientes quando usado com uma função de hash bem projetado, executando\-as em um horário em média constante e não depende do número de elementos no contêiner.  Uma função de hash bem projetado produz uma distribuição uniforme de valores de hash e minimiza o número de conflitos, onde uma colisão é considerada ocorrem quando os valores de chave distintos são mapeados para o mesmo valor de hash.  Na pior das hipóteses, com a função de hash possíveis pior, o número de operações é proporcional ao número de elementos na sequência \(tempo linear\).  
  
 O hash\_set deve ser o contêiner associativo escolhido quando as condições que associam os valores às respectivas chaves forem atendidas pelo aplicativo.  Os elementos de um hash\_set são exclusivos e servem como suas próprias chaves de classificação.  Um modelo para esse tipo de estrutura é uma lista ordenada de palavras, por exemplo, na qual as palavras podem ocorrer apenas uma vez.  Se foram permitidas várias ocorrências das palavras, um hash\_multiset seria a estrutura contêiner apropriado.  Se precisarem de valores a ser anexado a uma lista de palavras\-chave exclusivas, um hash\_map seria uma estrutura apropriada para conter esses dados.  Se em vez disso, as chaves não forem exclusivas, um hash\_multimap seria o contêiner ideal.  
  
 O hash\_set ordena a sequência que controla chamando um hash armazenado**características**objeto do tipo[value\_compare](../Topic/hash_set::value_compare.md).  Esse objeto armazenado pode ser acessado chamando a função de membro[key\_comp](../Topic/hash_set::key_comp.md).  Esse é um objeto de função deve se comportar da mesma como um objeto da classe*hash\_compare \< chave, menos \< chave \>\>.* Especificamente, para todos os valores`_Key`do tipo de chave, a característica de chamada \(`_Key`\) produz uma distribuição de valores do tipo size\_t.  
  
 De modo geral, os elementos precisam ser simplesmente menores que os comparáveis para estabelecer essa ordem: desse modo, considerando dois elementos, pode ser determinado que, ou eles são equivalentes \(no sentido de que nenhum deles é menor que o outro\), ou que um é menor que o outro.  Isso resulta em uma ordenação entre os elementos não equivalentes.  Fazendo uma observação mais técnica, a função de comparação é um predicado binário que induz a uma ordenação fraca restrita no sentido matemático padrão.  Um predicado binário*f*\(*x**y*\) é um objeto de função que possui dois objetos de argumento x e y e um valor de retorno de true ou false.  Uma ordenação imposta em um hash\_set será uma ordenação fraca restrita se o predicado binário for irreflexivo, antissimétrico e transitivo e se a equivalência for transitiva, onde dois objetos*x*e*y*são definidos para serem equivalentes quando ambos*f*\(*x**y*\) e*f*\(*y**x*\) são falsos.  Se a condição mais forte de igualdade entre as chaves substituir essa equivalência, a ordenação será total \(no sentido de que todos os elementos serão ordenados um em relação ao outro\) e as chaves correspondentes não poderão ser diferenciadas uma da outra.  
  
 A ordem real dos elementos na sequência controlada depende da função de hash, a função de classificação e o tamanho atual da tabela de hash armazenado no objeto de contêiner.  Você não pode determinar o tamanho atual da tabela de hash, portanto, em geral, você não pode prever a ordem dos elementos na sequência controlada.  A inserção de elementos não invalida iteradores e a remoção de elementos invalida apenas os iteradores que apontavam especificamente os elementos removidos.  
  
 O iterador fornecido pela classe hash\_set é um iterador bidirecional, mas as funções de membro de classe[Inserir](../Topic/hash_set::insert.md)e[hash\_set](../Topic/hash_set::hash_set.md)possuem versões que usam como parâmetros de modelo um iterador de entrada mais fraco, cujos requisitos de funcionalidade são mais minimalistas do que os garantidos pela classe de iteradores bidirecionais.  Os conceitos de iterador diferente formam uma família relacionada por refinamentos em sua funcionalidade.  Cada conceito de iterador tem seu próprio conjunto de requisitos e os algoritmos que funcionam com eles devem limitar suas suposições para os requisitos fornecidos por esse tipo de iterador.  Pode ser pressuposto que um iterador de entrada possa ser desreferenciado para fazer referência a algum objeto e que possa ser incrementado para o próximo iterador na sequência.  Isso é um conjunto mínimo de funcionalidade, mas é suficiente para poder expressar de forma significativa um intervalo de iteradores \[`_First``_Last`\) no contexto das funções de membro de classe.  
  
 No Visual C\+\+ .NET 2003, membros de[\< hash\_map \>](../standard-library/hash-map.md)e[\< hash\_set \>](../standard-library/hash-set.md)arquivos de cabeçalho não estão mais no namespace padrão, mas em vez disso, foram movidos para o namespace stdext.  Consulte [O namespace stdext](../Topic/stdext%20Namespace.md) para obter mais informações.  
  
### Construtores  
  
|||  
|-|-|  
|[hash\_set](../Topic/hash_set::hash_set.md)|Constrói um `hash_set` que está vazio ou que é uma cópia de todo ou parte de algum outro `hash_set`.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[allocator\_type](../Topic/hash_set::allocator_type.md)|Um tipo que representa a classe `allocator` para o objeto `hash_set`.|  
|[const\_iterator](../Topic/hash_set::const_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler um elemento `const` no `hash_set`.|  
|[const\_pointer](../Topic/hash_set::const_pointer.md)|Um tipo que fornece um ponteiro para um elemento `const` em um `hash_set`.|  
|[const\_reference](../Topic/hash_set::const_reference.md)|Um tipo que fornece uma referência para um elemento `const` armazenado em um `hash_set` para leitura e execução de operações `const`.|  
|[const\_reverse\_iterator](../Topic/hash_set::const_reverse_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento `const` no `hash_set`.|  
|[difference\_type](../Topic/hash_set::difference_type.md)|Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de um `hash_set` em um intervalo entre os elementos apontado pelos iteradores.|  
|[iterator](../Topic/hash_set::iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em um`hash_set`.|  
|[key\_compare](../Topic/hash_set::key_compare.md)|Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no `hash_set`.|  
|[key\_type](../Topic/hash_set::key_type.md)|Um tipo que descreve um objeto armazenado como um elemento de uma`hash_set`em sua capacidade como chave de classificação.|  
|[pointer](../Topic/hash_set::pointer.md)|Um tipo que fornece um ponteiro para um elemento em um`hash_set`.|  
|[referência](../Topic/hash_set::reference.md)|Um tipo que fornece uma referência a um elemento armazenado em um `hash_set`.|  
|[reverse\_iterator](../Topic/hash_set::reverse_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um `hash_set` invertido.|  
|[size\_type](../Topic/hash_set::size_type.md)|Um tipo de inteiro sem sinal que pode representar o número de elementos em um `hash_set`.|  
|[value\_compare](../Topic/hash_set::value_compare.md)|Um tipo que fornece dois objetos de função, um predicado binário de comparação de classe que pode comparar dois valores de elemento de um`hash_set`para determinar suas relativos à ordem e um unário predicado que mistura os elementos.|  
|[value\_type](../Topic/hash_set::value_type.md)|Um tipo que descreve um objeto armazenado como um elemento de uma`hash_set`em sua capacidade como um valor.|  
  
### Funções membro  
  
|||  
|-|-|  
|[begin](../Topic/hash_set::begin.md)|Retorna um iterador que trata o primeiro elemento de`hash_set`.|  
|[hash\_set::cbegin](../Topic/hash_set::cbegin.md)|Retorna um iterador const que trata o primeiro elemento no `hash_set`.|  
|[hash\_set::cend](../Topic/hash_set::cend.md)|Retorna um iterador const que trata o local após o último elemento em um `hash_set`.|  
|[limpar](../Topic/hash_set::clear.md)|Apaga todos os elementos de um `hash_set`.|  
|[count](../Topic/hash_set::count.md)|Retorna o número de elementos em um `hash_set` cuja chave corresponde a uma chave especificada pelo parâmetro.|  
|[hash\_set::crbegin](../Topic/hash_set::crbegin.md)|Retorna um iterador const que trata o primeiro elemento em um `hash_set` invertido.|  
|[hash\_set::crend](../Topic/hash_set::crend.md)|Retorna um iterador const que trata o local após o último elemento em um `hash_set` invertido.|  
|[hash\_set::emplace](../Topic/hash_set::emplace.md)|Insere um elemento construído adequadamente em um `hash_set`.|  
|[hash\_set::emplace\_hint](../Topic/hash_set::emplace_hint.md)|Insere um elemento construído adequadamente em um `hash_set`, com uma dica de posicionamento.|  
|[vazio](../Topic/hash_set::empty.md)|Testa se `hash_set` está vazio.|  
|[end](../Topic/hash_set::end.md)|Retorna um iterador que trata o local após o último elemento em um `hash_set`.|  
|[equal\_range](../Topic/hash_set::equal_range.md)|Retorna um par de iteradores respectivamente para o primeiro elemento em um`hash_set`com uma chave que é maior do que uma chave especificada e o primeiro elemento de`hash_set`com uma chave que é igual ou maior que a chave.|  
|[erase](../Topic/hash_set::erase.md)|Remove um elemento ou um intervalo de elementos em um `hash_set` das posições especificadas ou remove elementos que correspondem a uma chave especificada.|  
|[find](../Topic/hash_set::find.md)|Retorna um iterador que trata o local de um elemento em um`hash_set`que tem uma chave equivalente a uma chave especificada.|  
|[get\_allocator](../Topic/hash_set::get_allocator.md)|Retorna uma cópia do objeto `allocator` usada para construir o `hash_set`.|  
|[inserir](../Topic/hash_set::insert.md)|Insere um elemento ou um intervalo de elementos em um `hash_set`.|  
|[key\_comp](../Topic/hash_set::key_comp.md)|Recupera uma cópia do objeto de comparação usada para ordenar chaves em um `hash_set`.|  
|[lower\_bound](../Topic/hash_set::lower_bound.md)|Retorna um iterador para o primeiro elemento em um `hash_set` com uma chave que é igual ou maior que uma chave especificada.|  
|[max\_size](../Topic/hash_set::max_size.md)|Retorna o comprimento máximo do `hash_set`.|  
|[rbegin](../Topic/hash_set::rbegin.md)|Retorna um iterador que trata o primeiro elemento em um `hash_set` invertido.|  
|[rend](../Topic/hash_set::rend.md)|Retorna um iterador que trata o local após o último elemento em um `hash_set` invertido.|  
|[size](../Topic/hash_set::size.md)|Retorna o número de elementos no `hash_set`.|  
|[swap](../Topic/hash_set::swap.md)|Troca os elementos de dois `hash_set`s.|  
|[upper\_bound](../Topic/hash_set::upper_bound.md)|Retorna um iterador para o primeiro elemento em um `hash_set` com uma chave que é igual ou maior que uma chave especificada.|  
|[value\_comp](../Topic/hash_set::value_comp.md)|Recupera uma cópia do objeto de características de hash usado para hash e solicitar o elemento valores de chave em um`hash_set`.|  
  
### Operadores  
  
|||  
|-|-|  
|[hash\_set::operator\=](../Topic/hash_set::operator=.md)|Substitui os elementos de um `hash_set` por uma cópia de outro `hash_set`.|  
  
## Requisitos  
 **Cabeçalho:**\< hash\_set \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)