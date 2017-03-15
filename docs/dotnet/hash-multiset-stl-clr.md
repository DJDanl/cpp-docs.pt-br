---
title: "hash_multiset (STL/CLR) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "cliext::hash_multiset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho &lt;cliext/hash_set&gt; [STL/CLR]"
  - "Cabeçalho &lt;hash_set&gt; [STL/CLR]"
  - "Classe hash_multiset [STL/CLR]"
ms.assetid: 8462bd21-6829-4dd3-ac81-c42d6fdf92f0
caps.latest.revision: 19
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_multiset (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um objeto que controla uma sequência de variar\- comprimento de elementos que tenha acesso bidirecional.  Você usa o contêiner `hash_multiset` para gerenciar uma sequência de elementos como uma tabela de hash, cada entrada da tabela para armazenar uma lista vinculada bidirecional de nós, e cada nó armazenando um elemento.  O valor de cada elemento é usado como uma chave, a ordenação a sequência.  
  
 Na descrição abaixo, `GValue` é o mesmo que `GKey`, que é por sua vez o mesmo que `Key` a menos que o último é um tipo de referência, nesse caso é `Key^`.  
  
## Sintaxe  
  
```  
template<typename Key>  
    ref class hash_multiset  
        :   public  
        System::ICloneable,  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<GValue>,  
        System::Collections::Generic::ICollection<GValue>,  
        System::Collections::Generic::IList<GValue>,  
        Microsoft::VisualC::StlClr::IHash<Gkey, GValue>  
    { ..... };  
```  
  
#### Parâmetros  
 Chave  
 O tipo de componente principal de um elemento na sequência controlada.  
  
## Membros  
  
|Definição de tipo|Descrição|  
|-----------------------|---------------|  
|[hash\_multiset::const\_iterator](../dotnet/hash-multiset-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[hash\_multiset::const\_reference](../dotnet/hash-multiset-const-reference-stl-clr.md)|O tipo de uma referência constante para um elemento.|  
|[hash\_multiset::const\_reverse\_iterator](../dotnet/hash-multiset-const-reverse-iterator-stl-clr.md)|O tipo de um iterador invertido constante para a sequência controlada.|  
|[hash\_multiset::difference\_type](../dotnet/hash-multiset-difference-type-stl-clr.md)|O tipo de distância de possivelmente \(assinado\) entre dois elementos.|  
|[hash\_multiset::generic\_container](../dotnet/hash-multiset-generic-container-stl-clr.md)|O tipo de interface genérica para o contêiner.|  
|[hash\_multiset::generic\_iterator](../dotnet/hash-multiset-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[hash\_multiset::generic\_reverse\_iterator](../dotnet/hash-multiset-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a interface genérica para o contêiner.|  
|[hash\_multiset::generic\_value](../dotnet/hash-multiset-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[hash\_multiset::hasher](../dotnet/hash-multiset-hasher-stl-clr.md)|A delegação de hash de uma chave.|  
|[hash\_multiset::iterator](../dotnet/hash-multiset-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[hash\_multiset::key\_compare](../dotnet/hash-multiset-key-compare-stl-clr.md)|O delegado de ordenação para duas chaves.|  
|[hash\_multiset::key\_type](../dotnet/hash-multiset-key-type-stl-clr.md)|O tipo de uma chave classificação.|  
|[hash\_multiset::reference](../dotnet/hash-multiset-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[hash\_multiset::reverse\_iterator](../dotnet/hash-multiset-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a sequência controlada.|  
|[hash\_multiset::size\_type](../dotnet/hash-multiset-size-type-stl-clr.md)|O tipo de distância \(não negativo\) de entre dois elementos.|  
|[hash\_multiset::value\_compare](../dotnet/hash-multiset-value-compare-stl-clr.md)|O delegado de ordenação para dois valores do elemento.|  
|[hash\_multiset::value\_type](../dotnet/hash-multiset-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função de membro|Descrição|  
|----------------------|---------------|  
|[hash\_multiset::begin](../dotnet/hash-multiset-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[hash\_multiset::bucket\_count](../dotnet/hash-multiset-bucket-count-stl-clr.md)|Conta o número de segmentos.|  
|[hash\_multiset::clear](../dotnet/hash-multiset-clear-stl-clr.md)|Remove todos os elementos.|  
|[hash\_multiset::count](../dotnet/hash-multiset-count-stl-clr.md)|Conta os elementos que correspondem a uma chave especificada.|  
|[hash\_multiset::empty](../dotnet/hash-multiset-empty-stl-clr.md)|Testa se nenhum elemento estiver presente.|  
|[hash\_multiset::end](../dotnet/hash-multiset-end-stl-clr.md)|Designa o término da sequência controlada.|  
|[hash\_multiset::equal\_range](../Topic/hash_multiset::equal_range%20\(STL-CLR\).md)|Encontra variam que corresponde a uma chave especificada.|  
|[hash\_multiset::erase](../dotnet/hash-multiset-erase-stl-clr.md)|Remove os elementos nas posições especificadas.|  
|[hash\_multiset::find](../dotnet/hash-multiset-find-stl-clr.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[hash\_multiset::hash\_delegate](../dotnet/hash-multiset-hash-delegate-stl-clr.md)|Copia a delegação de hash de uma chave.|  
|[hash\_multiset::hash\_multiset](../dotnet/hash-multiset-hash-multiset-stl-clr.md)|Cria um objeto contêiner.|  
|[hash\_multiset::insert](../Topic/hash_multiset::insert%20\(STL-CLR\).md)|Adiciona os elementos.|  
|[hash\_multiset::key\_comp](../dotnet/hash-multiset-key-comp-stl-clr.md)|Copia o representante de ordenação para duas chaves.|  
|[hash\_multiset::load\_factor](../Topic/hash_multiset::load_factor%20\(STL-CLR\).md)|Conta os elementos médio por segmento.|  
|[hash\_multiset::lower\_bound](../Topic/hash_multiset::lower_bound%20\(STL-CLR\).md)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[hash\_multiset::make\_value](../dotnet/hash-multiset-make-value-stl-clr.md)|Cria um objeto de valor.|  
|[hash\_multiset::max\_load\_factor](../dotnet/hash-multiset-max-load-factor-stl-clr.md)|Obtém ou define os elementos máximo pelo segmento.|  
|[hash\_multiset::rbegin](../Topic/hash_multiset::rbegin%20\(STL-CLR\).md)|Designa o início da sequência controlada invertida.|  
|[hash\_multiset::rehash](../Topic/hash_multiset::rehash%20\(STL-CLR\).md)|Recria a tabela de hash.|  
|[hash\_multiset::rend](../dotnet/hash-multiset-rend-stl-clr.md)|Designa o término da sequência controlada invertida.|  
|[hash\_multiset::size](../Topic/hash_multiset::size%20\(STL-CLR\).md)|Conta o número de elementos.|  
|[hash\_multiset::swap](../dotnet/hash-multiset-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[hash\_multiset::to\_array](../dotnet/hash-multiset-to-array-stl-clr.md)|Copia a sequência controlada a uma nova matriz.|  
|[hash\_multiset::upper\_bound](../dotnet/hash-multiset-upper-bound-stl-clr.md)|Localiza de extremidade do intervalo que corresponde a uma chave especificada.|  
|[hash\_multiset::value\_comp \(STL\/CLR\)](../dotnet/hash-multiset-value-comp-stl-clr.md)|Copia o representante de ordenação para dois valores do elemento.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|[hash\_multiset::operator\=](../dotnet/hash-multiset-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
  
## Interfaces  
  
|Interface|Descrição|  
|---------------|---------------|  
|<xref:System.ICloneable>|Duplica um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência por meio dos elementos.|  
|<xref:System.Collections.ICollection>|Mantenha o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência por meio dos elementos digitados.|  
|<xref:System.Collections.Generic.ICollection%601>|Mantenha o grupo de elementos de tipo.|  
|IHashKey\<, valor\>|Mantenha o contêiner genérico.|  
  
## Comentários  
 O objeto aloca e libera armazenamento para a sequência que controla como nós individuais em uma lista vinculada bidirecional.  Para acelerar o acesso, o objeto também mantém uma matriz de variar\- comprimento dos ponteiros na lista \(a tabela de hash\), gerenciando efetivamente a lista inteiro com uma sequência de sublists, ou blocos.  Insere os elementos em um segmento que mantém ordenado alterando os links entre nós, nunca copiar o conteúdo de um nó para outro.  Isso significa que você pode inserir e remover os elementos livremente sem os outros elementos de perturbação.  
  
 O objeto classifica cada partição que controla chamando um objeto armazenado delegado do tipo [hash\_set::key\_compare](../Topic/hash_set::key_compare%20\(STL-CLR\).md).  Você pode especificar o objeto armazenado delegado quando você constrói o hash\_set; se você não especificar um objeto de delegação, o padrão será a comparação `operator<=(key_type, key_type)`.  
  
 Você acessa o objeto armazenado delegado chamando a função de membro [hash\_set::key\_comp](../dotnet/hash-set-key-comp-stl-clr.md)`()`.  Esse objeto de delegação deve definir o equivalente de ordenação de chaves entre do tipo [hash\_set::key\_type](../dotnet/hash-set-key-type-stl-clr.md).  Isso significa que, para algumas duas chaves `X` e `Y`:  
  
 `key_comp()(X, Y)` retorna o mesmo resultado booliano em cada chamada.  
  
 Se `key_comp()(X, Y) && key_comp()(Y, X)` é true, então `X` e `Y` são ditos ter ordenação equivalente.  
  
 Qualquer regra de ordenação que se comportar como `operator<=(key_type, key_type)`, `operator>=(key_type, key_type)``operator==(key_type, key_type)` ou define a ordenação eqivalent.  
  
 Observe que o contêiner garante que apenas elementos cujas chaves têm a ordenação de equivalente \(e quais picam com o mesmo valor inteiro\) são adjacentes em um segmento.  Ao contrário da classe [hash\_set](../dotnet/hash-set-stl-clr.md)do modelo, um objeto da classe `hash_multiset` do modelo não exige que as chaves para todos os elementos são exclusivos. \(Dois ou mais chaves podem ter ordenação equivalente.\)  
  
 O objeto determina qual segmento deve conter uma chave de classificação especificada chamando um objeto armazenado delegado do tipo [hash\_set::hasher](../Topic/hash_set::hasher%20\(STL-CLR\).md).  Você acessa esse objeto armazenado chamando a função de membro [hash\_set::hash\_delegate](../Topic/hash_set::hash_delegate%20\(STL-CLR\).md)`()` para obter um valor inteiro que depende do valor da chave.  Você pode especificar o objeto armazenado delegado quando você constrói o hash\_set; se você não especificar um objeto de delegação, o padrão será a função `System::Object::hash_value(key_type)`.  Isso significa que, para algumas chaves `X` e `Y`:  
  
 `hash_delegate()(X)` retorna o mesmo resultado inteiro em cada chamada.  
  
 Se `X` e `Y` tem a ordenação equivalente, então `hash_delegate()(X)` deve retornar o mesmo resultado inteiro que `hash_delegate()(Y)`.  
  
 Cada elemento serve como uma chave e um valor.  A sequência é representada de forma a permitir que a pesquisa, inserir, e a remoção de um elemento com um número arbitrário de operações que é independente do número de elementos na sequência \(o tempo constantes\) \-\- pelo menos no melhor dos casos.  Além disso, inserindo um elemento não invalida iteradores, e removendo um elemento invalida apenas os iteradores que apontam no elemento removido.  
  
 Se os valores com hash não são distribuídos uniformemente, porém, um hash a tabela pode degenerar.  Em extremamente \-\- para uma função de hash que sempre retorna o mesmo valor \-\- a pesquisa, inserir, e a remoção é proporcional ao número de elementos na sequência \(hora lineares\).  O contêiner esforça\-se escolher uma função de hash razoável, um tamanho médio do segmento, e uma tabela de hash \(número total de blocos\), mas você pode substituir algumas ou todas estas escolhas.  Consulte, por exemplo, as funções [hash\_set::max\_load\_factor](../Topic/hash_set::max_load_factor%20\(STL-CLR\).md) e [hash\_set::rehash](../Topic/hash_set::rehash%20\(STL-CLR\).md).  
  
 Um hash\_multiset oferece suporte aos iteradores bidirecionais, o que significa que você pode avançar para os elementos adjacentes um iterador dados que designa um elemento na sequência controlada.  Um nó principal especial corresponde ao iterador retornado por [hash\_multiset::end](../dotnet/hash-multiset-end-stl-clr.md)`()`.  Você pode diminuir este iterador para alcançar o elemento o mais recente na sequência controlada, se houver.  É possível incrementar um iterador de hash\_multiset para alcançar o nó principal, e comparará no igual a `end()`.  Mas você não pode desreferenciar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento de hash\_multiset determinado diretamente a posição numérica \-\- isso requer um iterador de acesso aleatório.  
  
 Um iterador de hash\_multiset armazena um identificador para o nó associado de hash\_multiset, por sua vez que armazena um identificador para o contêiner associado.  Você pode usar iteradores apenas com seus objetos de contêiner associados.  Um iterador de hash\_multiset permanece válido desde que o nó associado de hash\_multiset é associado a um hash\_multiset.  Além disso, um iterador válido é dereferencable \-\- você pode usá\-lo para acessar ou modificar o valor do elemento que designa \-\- contanto que não é igual a `end()`.  
  
 Apagando ou removendo um elemento chama o destruidor para seu valor armazenado.  Destruir o contêiner apaga todos os elementos.  Assim, um contêiner cujo tipo de elemento é uma classe de referência garante que nenhum elemento é maior que o contêiner.  A observe, entretanto, que manipula um contêiner faz `not` destrói seus elementos.  
  
## Requisitos  
 cliext \<\/hash\_set de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_map](../dotnet/hash-map-stl-clr.md)   
 [hash\_multiset](../dotnet/hash-multiset-stl-clr.md)   
 [hash\_set](../dotnet/hash-set-stl-clr.md)   
 [map](../dotnet/map-stl-clr.md)   
 [multiset](../dotnet/multiset-stl-clr.md)   
 [multiset](../dotnet/multiset-stl-clr.md)   
 [set](../dotnet/set-stl-clr.md)   
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)