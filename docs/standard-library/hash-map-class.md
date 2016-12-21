---
title: "Classe hash_map | Microsoft Docs"
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
  - "stdext::hash_map"
  - "hash_map/stdext::hash_map"
  - "std.hash_map"
  - "stdext.hash_map"
  - "std::hash_map"
  - "hash_map"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe hash_map"
ms.assetid: 40879dfc-51ba-4a59-9f9e-26208de568a8
caps.latest.revision: 25
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe hash_map
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Esta API está obsoleta.  A alternativa é[Classe unordered\_map](../standard-library/unordered-map-class.md).  
  
 Armazena e recupera dados rapidamente de uma coleção na qual cada elemento é um par que contém uma chave de classificação cujo valor é exclusivo e um valor de dados associados.  
  
## Sintaxe  
  
```  
template <  
   class Key,   
   class Type,   
   class Traits=hash_compare<Key, less<Key> >,   
   class Allocator=allocator<pair <const Key, Type> >   
>  
class hash_map  
```  
  
#### Parâmetros  
 `Key`  
 O tipo de dados de chave a ser armazenado na hash\_map.  
  
 `Type`  
 O tipo de dados do elemento a ser armazenado na hash\_map.  
  
 `Traits`  
 O tipo que inclui dois objetos de função, uma comparação de classe capaz de comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa e um hash de função que é um predicado unário mapeando principais valores dos elementos para números inteiros sem sinal do tipo`size_t`.  Esse argumento é opcional e hash\_compare \<`Key`menos \<`Key`\>\> é o valor padrão.  
  
 `Allocator`  
 O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre o hash\_map alocação e desalocação de memória.  Esse argumento é opcional e o valor padrão é alocador \< par \< const`Key``Type`\>\>.  
  
## Comentários  
 O hash\_map é:  
  
-   Um contêiner associativo, que é um contêiner de tamanho variável que oferece suporte à recuperação eficiente dos valores de elemento com base em um valor de chave associado.  
  
-   Reversível, pois fornece um iterador bidirecional para acessar seus elementos.  
  
-   Hashed, pois seus elementos são agrupados em blocos com base no valor de uma função de hash aplicado aos valores de chave de elementos.  
  
-   Exclusivo no sentido de que cada um de seus elementos deve ter uma chave exclusiva.  
  
-   Um contêiner de par associativo, pois seus valores de dados de elemento são distintos de seus valores de chave.  
  
-   Uma classe de modelo, pois a funcionalidade fornecida por ela é genérica e, portanto, independente do tipo de dados específico contido como elementos ou chaves.  Os tipos de dados a serem usados para elementos e chaves são especificados como parâmetros no modelo de classe juntamente com o alocador e a função de comparação.  
  
 A principal vantagem de hashing sobre a classificação é maior eficiência; um hash bem\-sucedida executa inserções, exclusões e localiza em constante tempo médio, em comparação com um tempo proporcional para o logaritmo do número de elementos no contêiner de técnicas de classificação.  O valor de um elemento em um hash\_map, mas não seu valor de chave associado, pode ser alterado diretamente.  Em vez disso, os valores de chave associados aos elementos antigos devem ser excluídos e os novos valores de chave associados aos novos elementos inseridos.  
  
 A escolha do tipo de contêiner deve se basear, de modo geral, no tipo de pesquisa e inserção exigido pelo aplicativo.  Hash contêineres associativos são otimizados para as operações de pesquisa, inserção e remoção.  As funções de membro que oferecem suporte explicitamente essas operações são eficientes quando usado com uma função de hash bem projetado, executando\-as em um horário em média constante e não depende do número de elementos no contêiner.  Uma função de hash bem projetado produz uma distribuição uniforme de valores de hash e minimiza o número de conflitos, onde uma colisão é considerada ocorrem quando os valores de chave distintos são mapeados para o mesmo valor de hash.  Na pior das hipóteses, com a função de hash possíveis pior, o número de operações é proporcional ao número de elementos na sequência \(tempo linear\).  
  
 O hash\_map deve ser o contêiner associativo escolhido quando as condições que associam os valores às respectivas chaves forem atendidas pelo aplicativo.  Um modelo para esse tipo de estrutura é uma lista ordenada de palavras\-chave que ocorrem exclusivamente com valores de cadeia de caracteres associado fornecer, digamos, definições.  Se, em vez disso, as palavras tivessem mais de uma definição correta, para que as chaves não forem exclusivas, um hash\_multimap seria o contêiner ideal.  Se, por outro lado, apenas a lista de palavras foram sendo armazenada, um hash\_set seria o contêiner correto.  Se foram permitidas várias ocorrências das palavras, um hash\_multiset seria a estrutura contêiner apropriado.  
  
 O hash\_map ordena a sequência que controla chamando um hash armazenado`Traits`objeto da classe[value\_compare](../Topic/value_compare%20Class.md).  Esse objeto armazenado pode ser acessado chamando a função de membro[key\_comp](../Topic/hash_map::key_comp.md).  Esse é um objeto de função deve se comportar da mesma como um objeto da classe[hash\_compare](../standard-library/hash-compare-class.md)\< chave, menos \< chave \>\>.  Especificamente, para todos os valores`Key`do tipo`Key`a chamada`Traits`\(`Key`\) produz uma distribuição de valores do tipo`size_t`.  
  
 De modo geral, os elementos precisam ser simplesmente menores que os comparáveis para estabelecer essa ordem: desse modo, considerando dois elementos, pode ser determinado que, ou eles são equivalentes \(no sentido de que nenhum deles é menor que o outro\), ou que um é menor que o outro.  Isso resulta em uma ordenação entre os elementos não equivalentes.  Fazendo uma observação mais técnica, a função de comparação é um predicado binário que induz a uma ordenação fraca restrita no sentido matemático padrão.  Um binário f\(x y\) predicado é um objeto de função que possui dois objetos de argumento`x`e`y`e um valor de retorno`true`ou`false`.  Uma ordenação imposta em um hash\_map será uma ordenação fraca restrita se o predicado binário for irreflexivo, antissimétrico e transitivo e se a equivalência for transitiva, onde dois objetos x e y são definidos para serem equivalentes quando f \(x, y\) e f \(y, x\) são falsos.  Se a condição mais forte de igualdade entre as chaves substituir essa equivalência, a ordenação será total \(no sentido de que todos os elementos serão ordenados um em relação ao outro\) e as chaves correspondentes não poderão ser diferenciadas uma da outra.  
  
 A ordem real dos elementos na sequência controlada depende da função de hash, a função de classificação e o tamanho atual da tabela de hash armazenado no objeto de contêiner.  Você não pode determinar o tamanho atual da tabela de hash, portanto, em geral, você não pode prever a ordem dos elementos na sequência controlada.  A inserção de elementos não invalida iteradores e a remoção de elementos invalida apenas os iteradores que apontavam especificamente os elementos removidos.  
  
 O iterador fornecido pela classe hash\_map é um iterador bidirecional, mas as funções de membro de classe[Inserir](../Topic/hash_map::insert.md)e[hash\_map](../Topic/hash_map::hash_map.md)possuem versões que usam como parâmetros de modelo um iterador de entrada mais fraco, cujos requisitos de funcionalidade são mais minimalistas do que os garantidos pela classe de iteradores bidirecionais.  Os conceitos de iterador diferente formam uma família relacionada por refinamentos em sua funcionalidade.  Cada conceito de iterador tem seu próprio conjunto de requisitos e os algoritmos que funcionam com eles devem limitar suas suposições para os requisitos fornecidos por esse tipo de iterador.  Pode ser pressuposto que um iterador de entrada possa ser desreferenciado para fazer referência a algum objeto e que possa ser incrementado para o próximo iterador na sequência.  Isso é um conjunto mínimo de funcionalidade, mas é suficiente para poder expressar de forma significativa um intervalo de iteradores`[First, Last)`no contexto das funções de membro de classe.  
  
 No Visual C\+\+ .NET 2003, membros de[\< hash\_map \>](../standard-library/hash-map.md)e[\< hash\_set \>](../standard-library/hash-set.md)arquivos de cabeçalho não estão mais no namespace padrão, mas em vez disso, foram movidos para o namespace stdext.  Consulte [O namespace stdext](../Topic/stdext%20Namespace.md) para obter mais informações.  
  
### Construtores  
  
|||  
|-|-|  
|[hash\_map](../Topic/hash_map::hash_map.md)|Constrói um `hash_map` que está vazio ou que é uma cópia de todo ou parte de algum outro `hash_map`.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[allocator\_type](../Topic/hash_map::allocator_type.md)|Um tipo que representa a classe `allocator` para o objeto `hash_map`.|  
|[const\_iterator](../Topic/hash_map::const_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler um elemento `const` no `hash_map`.|  
|[const\_pointer](../Topic/hash_map::const_pointer.md)|Um tipo que fornece um ponteiro para um elemento `const` em um `hash_map`.|  
|[const\_reference](../Topic/hash_map::const_reference.md)|Um tipo que fornece uma referência para um elemento `const` armazenado em um `hash_map` para leitura e execução de operações `const`.|  
|[const\_reverse\_iterator](../Topic/hash_map::const_reverse_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento `const` no `hash_map`.|  
|[difference\_type](../Topic/hash_map::difference_type.md)|Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de um `hash_map` em um intervalo entre os elementos apontado pelos iteradores.|  
|[iterator](../Topic/hash_map::iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em um`hash_map`.|  
|[key\_compare](../Topic/hash_map::key_compare.md)|Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no `hash_map`.|  
|[key\_type](../Topic/hash_map::key_type.md)|Um tipo descreve o objeto de chave de classificação que constitui cada elemento do`hash_map`.|  
|[mapped\_type](../Topic/hash_map::mapped_type.md)|Um tipo que representa o tipo de dados armazenado em um `hash_map`.|  
|[pointer](../Topic/hash_map::pointer.md)|Um tipo que fornece um ponteiro para um elemento em um`hash_map`.|  
|[referência](../Topic/hash_map::reference.md)|Um tipo que fornece uma referência a um elemento armazenado em um `hash_map`.|  
|[reverse\_iterator](../Topic/hash_map::reverse_iterator.md)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um `hash_map` invertido.|  
|[size\_type](../Topic/hash_map::size_type.md)|Um tipo de inteiro sem sinal que pode representar o número de elementos em um `hash_map`.|  
|[value\_type](../Topic/hash_map::value_type.md)|Um tipo que fornece um objeto de função que pode comparar dois elementos como chaves de classificação para determinar sua ordem relativa no `hash_map`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[hash\_map::at](../Topic/hash_map::at.md)|Localiza um elemento em um`hash_map`com um valor de chave especificado.|  
|[begin](../Topic/hash_map::begin.md)|Retorna um iterador que trata o primeiro elemento no `hash_map`.|  
|[hash\_map::cbegin](../Topic/hash_map::cbegin.md)|Retorna um iterador const que trata o primeiro elemento no `hash_map`.|  
|[hash\_map::cend](../Topic/hash_map::cend.md)|Retorna um iterador const que trata o local após o último elemento em um `hash_map`.|  
|[limpar](../Topic/hash_map::clear.md)|Apaga todos os elementos de um `hash_map`.|  
|[count](../Topic/hash_map::count.md)|Retorna o número de elementos em um `hash_map` cuja chave corresponde a uma chave especificada pelo parâmetro.|  
|[hash\_map::crbegin](../Topic/hash_map::crbegin.md)|Retorna um iterador const que trata o primeiro elemento em um `hash_map` invertido.|  
|[hash\_map::crend](../Topic/hash_map::crend.md)|Retorna um iterador const que trata o local após o último elemento em um `hash_map` invertido.|  
|[hash\_map::emplace](../Topic/hash_map::emplace.md)|Insere um elemento construído adequadamente em um `hash_map`.|  
|[hash\_map::emplace\_hint](../Topic/hash_map::emplace_hint.md)|Insere um elemento construído adequadamente em um `hash_map`, com uma dica de posicionamento.|  
|[vazio](../Topic/hash_map::empty.md)|Testa se `hash_map` está vazio.|  
|[end](../Topic/hash_map::end.md)|Retorna um iterador que trata o local após o último elemento em um `hash_map`.|  
|[equal\_range](../Topic/hash_map::equal_range.md)|Retorna um par de iteradores, respectivamente, para o primeiro elemento em um`hash_map`com uma chave que é maior do que uma chave especificada e o primeiro elemento de`hash_map`com uma chave que é igual ou maior que a chave.|  
|[erase](../Topic/hash_map::erase.md)|Remove um elemento ou um intervalo de elementos em um`hash_map`das posições especificadas|  
|[find](../Topic/hash_map::find.md)|Retorna um iterador que trata o local de um elemento em um`hash_map`que tem uma chave equivalente a uma chave especificada.|  
|[get\_allocator](../Topic/hash_map::get_allocator.md)|Retorna uma cópia do objeto `allocator` usada para construir o `hash_map`.|  
|[inserir](../Topic/hash_map::insert.md)|Insere um elemento ou um intervalo de elementos em um `hash_map`.|  
|[key\_comp](../Topic/hash_map::key_comp.md)|Retorna um iterador para o primeiro elemento em um`hash_map`com um valor de chave é igual ou maior do que uma chave especificada.|  
|[lower\_bound](../Topic/hash_map::lower_bound.md)|Retorna um iterador para o primeiro elemento em um`hash_map`com um valor de chave é igual ou maior do que uma chave especificada.|  
|[max\_size](../Topic/hash_map::max_size.md)|Retorna o comprimento máximo do `hash_map`.|  
|[rbegin](../Topic/hash_map::rbegin.md)|Retorna um iterador que trata o primeiro elemento em um `hash_map` invertido.|  
|[rend](../Topic/hash_map::rend.md)|Retorna um iterador que trata o local após o último elemento em um `hash_map` invertido.|  
|[size](../Topic/hash_map::size.md)|Retorna o número de elementos no `hash_map`.|  
|[swap](../Topic/hash_map::swap.md)|Troca os elementos de dois `hash_map`s.|  
|[upper\_bound](../Topic/hash_map::upper_bound.md)|Retorna um iterador para o primeiro elemento em um`hash_map`que com uma chave de valor que é maior do que uma chave especificada.|  
|[value\_comp](../Topic/hash_map::value_comp.md)|Recupera uma cópia do objeto de comparação usada para ordenar valores de elemento em um`hash_map`.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator&#91;&#93;](../Topic/hash_map::operator.md)|Insere um elemento em um`hash_map`com um valor de chave especificado.|  
|[hash\_map::operator\=](../Topic/hash_map::operator=.md)|Substitui os elementos de um `hash_map` por uma cópia de outro `hash_map`.|  
  
## Requisitos  
 **Cabeçalho:**\< hash\_map \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)