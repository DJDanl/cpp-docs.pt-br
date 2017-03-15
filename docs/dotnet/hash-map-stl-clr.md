---
title: "hash_map (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_map"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho &lt;cliext/hash_map&gt; [STL/CLR]"
  - "Cabeçalho &lt;hash_map&gt; [STL/CLR]"
  - "Classe hash_map [STL/CLR]"
ms.assetid: c3cfc69b-04c6-42ae-a30e-0eda953fe883
caps.latest.revision: 20
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_map (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um objeto que controla uma sequência de variar\- comprimento de elementos que tenha acesso bidirecional.  Você usa o contêiner `hash_map` para gerenciar uma sequência de elementos como uma tabela de hash, cada entrada da tabela para armazenar uma lista vinculada bidirecional de nós, e cada nó armazenando um elemento.  Um elemento consiste em uma chave, para ordenar a sequência, e um valor mapeado, desde que vai para o passeio.  
  
 Na descrição abaixo, `GValue` é o mesmo que:  
  
 `Microsoft::VisualC::StlClr::GenericPair<GKey, GMapped>`  
  
 onde:  
  
 `GKey` é o mesmo que `Key` a menos que o último é um tipo de referência, nesse caso é `Key^`  
  
 `GMapped` é o mesmo que `Mapped` a menos que o último é um tipo de referência, nesse caso é `Mapped^`  
  
## Sintaxe  
  
```  
template<typename Key,  
    typename Mapped>  
    ref class hash_map  
        :   public  
        System::ICloneable,  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<GValue>,  
        System::Collections::Generic::ICollection<GValue>,  
        System::Collections::Generic::IList<GValue>,  
        System::Collections::Generic::IDictionary<Gkey, GMapped>,  
        Microsoft::VisualC::StlClr::IHash<Gkey, GValue>  
    { ..... };  
```  
  
#### Parâmetros  
 Chave  
 O tipo de componente principal de um elemento na sequência controlada.  
  
 Mapeado  
 O tipo de componente adicional de um elemento na sequência controlada.  
  
## Membros  
  
|Definição de tipo|Descrição|  
|-----------------------|---------------|  
|[hash\_map::const\_iterator](../dotnet/hash-map-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[hash\_map::const\_reference](../dotnet/hash-map-const-reference-stl-clr.md)|O tipo de uma referência constante para um elemento.|  
|[hash\_map::const\_reverse\_iterator](../dotnet/hash-map-const-reverse-iterator-stl-clr.md)|O tipo de um iterador invertido constante para a sequência controlada.|  
|[hash\_map::difference\_type](../dotnet/hash-map-difference-type-stl-clr.md)|O tipo de distância de possivelmente \(assinado\) entre dois elementos.|  
|[hash\_map::generic\_container](../dotnet/hash-map-generic-container-stl-clr.md)|O tipo de interface genérica para o contêiner.|  
|[hash\_map::generic\_iterator](../dotnet/hash-map-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[hash\_map::generic\_reverse\_iterator](../dotnet/hash-map-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a interface genérica para o contêiner.|  
|[hash\_map::generic\_value](../dotnet/hash-map-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[hash\_map::hasher](../dotnet/hash-map-hasher-stl-clr.md)|A delegação de hash de uma chave.|  
|[hash\_map::iterator](../dotnet/hash-map-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[hash\_map::key\_compare](../Topic/hash_map::key_compare%20\(STL-CLR\).md)|O delegado de ordenação para duas chaves.|  
|[hash\_map::key\_type](../Topic/hash_map::key_type%20\(STL-CLR\).md)|O tipo de uma chave classificação.|  
|[hash\_map::mapped\_type](../Topic/hash_map::mapped_type%20\(STL-CLR\).md)|O tipo do valor mapeado associado a cada chave.|  
|[hash\_map::reference](../dotnet/hash-map-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[hash\_map::reverse\_iterator](../dotnet/hash-map-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a sequência controlada.|  
|[hash\_map::size\_type](../Topic/hash_map::size_type%20\(STL-CLR\).md)|O tipo de distância \(não negativo\) de entre dois elementos.|  
|[hash\_map::value\_compare](../dotnet/hash-map-value-compare-stl-clr.md)|O delegado de ordenação para dois valores do elemento.|  
|[hash\_map::value\_type](../dotnet/hash-map-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função de membro|Descrição|  
|----------------------|---------------|  
|[hash\_map::begin](../dotnet/hash-map-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[hash\_map::bucket\_count](../dotnet/hash-map-bucket-count-stl-clr.md)|Conta o número de segmentos.|  
|[hash\_map::clear](../Topic/hash_map::clear%20\(STL-CLR\).md)|Remove todos os elementos.|  
|[hash\_map::count](../dotnet/hash-map-count-stl-clr.md)|Conta os elementos que correspondem a uma chave especificada.|  
|[hash\_map::empty](../dotnet/hash-map-empty-stl-clr.md)|Testa se nenhum elemento estiver presente.|  
|[hash\_map::end](../dotnet/hash-map-end-stl-clr.md)|Designa o término da sequência controlada.|  
|[hash\_map::equal\_range](../dotnet/hash-map-equal-range-stl-clr.md)|Encontra variam que corresponde a uma chave especificada.|  
|[hash\_map::erase](../dotnet/hash-map-erase-stl-clr.md)|Remove os elementos nas posições especificadas.|  
|[hash\_map::find](../dotnet/hash-map-find-stl-clr.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[hash\_map::hash\_delegate](../dotnet/hash-map-hash-delegate-stl-clr.md)|Copia a delegação de hash de uma chave.|  
|[hash\_map::hash\_map](../dotnet/hash-map-hash-map-stl-clr.md)|Cria um objeto contêiner.|  
|[hash\_map::insert](../Topic/hash_map::insert%20\(STL-CLR\).md)|Adiciona os elementos.|  
|[hash\_map::key\_comp](../dotnet/hash-map-key-comp-stl-clr.md)|Copia o representante de ordenação para duas chaves.|  
|[hash\_map::load\_factor](../dotnet/hash-map-load-factor-stl-clr.md)|Conta os elementos médio por segmento.|  
|[hash\_map::lower\_bound](../dotnet/hash-map-lower-bound-stl-clr.md)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[hash\_map::make\_value](../dotnet/hash-map-make-value-stl-clr.md)|Cria um objeto de valor.|  
|[hash\_map::max\_load\_factor](../dotnet/hash-map-max-load-factor-stl-clr.md)|Obtém ou define os elementos máximo pelo segmento.|  
|[hash\_map::rbegin](../dotnet/hash-map-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[hash\_map::rehash](../dotnet/hash-map-rehash-stl-clr.md)|Recria a tabela de hash.|  
|[hash\_map::rend](../Topic/hash_map::rend%20\(STL-CLR\).md)|Designa o término da sequência controlada invertida.|  
|[hash\_map::size](../dotnet/hash-map-size-stl-clr.md)|Conta o número de elementos.|  
|[hash\_map::swap](../dotnet/hash-map-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[hash\_map::to\_array](../dotnet/hash-map-to-array-stl-clr.md)|Copia a sequência controlada a uma nova matriz.|  
|[hash\_map::upper\_bound](../dotnet/hash-map-upper-bound-stl-clr.md)|Localiza de extremidade do intervalo que corresponde a uma chave especificada.|  
|[hash\_map::value\_comp](../dotnet/hash-map-value-comp-stl-clr.md)|Copia o representante de ordenação para dois valores do elemento.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|[hash\_map::operator\=](../dotnet/hash-map-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[hash\_map::operator](../dotnet/hash-map-operator-stl-clr.md)|Mapeia uma chave para o valor mapeado associado.|  
  
## Interfaces  
  
|Interface|Descrição|  
|---------------|---------------|  
|<xref:System.ICloneable>|Duplica um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência por meio dos elementos.|  
|<xref:System.Collections.ICollection>|Mantenha o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência por meio dos elementos digitados.|  
|<xref:System.Collections.Generic.ICollection%601>|Mantenha o grupo de elementos de tipo.|  
|<xref:System.Collections.Generic.IDictionary%602>|Mantenha o grupo {} valor de chave, o par.|  
|IHashKey\<, valor\>|Mantenha o contêiner genérico.|  
  
## Comentários  
 O objeto aloca e libera armazenamento para a sequência que controla como nós individuais em uma lista vinculada bidirecional.  Para acelerar o acesso, o objeto também mantém uma matriz de variar\- comprimento dos ponteiros na lista \(a tabela de hash\), gerenciando efetivamente a lista inteiro com uma sequência de sublists, ou blocos.  Insere os elementos em um segmento que mantém ordenado alterando os links entre nós, nunca copiar o conteúdo de um nó para outro.  Isso significa que você pode inserir e remover os elementos livremente sem os outros elementos de perturbação.  
  
 O objeto classifica cada partição que controla chamando um objeto armazenado delegado do tipo [hash\_set::key\_compare](../Topic/hash_set::key_compare%20\(STL-CLR\).md).  Você pode especificar o objeto armazenado delegado quando você constrói o hash\_set; se você não especificar um objeto de delegação, o padrão será a comparação `operator<=(key_type, key_type)`.  
  
 Você acessa o objeto armazenado delegado chamando a função de membro [hash\_set::key\_comp](../dotnet/hash-set-key-comp-stl-clr.md)`()`.  Esse objeto de delegação deve definir o equivalente de ordenação de chaves entre do tipo [hash\_set::key\_type](../dotnet/hash-set-key-type-stl-clr.md).  Isso significa que, para algumas duas chaves `X` e `Y`:  
  
 `key_comp()(X, Y)` retorna o mesmo resultado booliano em cada chamada.  
  
 Se `key_comp()(X, Y) && key_comp()(Y, X)` é true, então `X` e `Y` são ditos ter ordenação equivalente.  
  
 Qualquer regra de ordenação que se comportar como `operator<=(key_type, key_type)`, `operator>=(key_type, key_type)``operator==(key_type, key_type)` ou define a ordenação eqivalent.  
  
 Observe que o contêiner garante que apenas elementos cujas chaves têm a ordenação de equivalente \(e quais picam com o mesmo valor inteiro\) são adjacentes em um segmento.  Ao contrário da classe [hash\_multimap](../dotnet/hash-multimap-stl-clr.md)do modelo, um objeto da classe `hash_map` do modelo garante que as chaves para todos os elementos sejam exclusivos. \(Nenhuma duas chaves têm equivalente a ordenação.\)  
  
 O objeto determina qual segmento deve conter uma chave de classificação especificada chamando um objeto armazenado delegado do tipo [hash\_set::hasher](../Topic/hash_set::hasher%20\(STL-CLR\).md).  Você acessa esse objeto armazenado chamando a função de membro [hash\_set::hash\_delegate](../Topic/hash_set::hash_delegate%20\(STL-CLR\).md)`()` para obter um valor inteiro que depende do valor da chave.  Você pode especificar o objeto armazenado delegado quando você constrói o hash\_set; se você não especificar um objeto de delegação, o padrão será a função `System::Object::hash_value(key_type)`.  Isso significa que, para algumas chaves `X` e `Y`:  
  
 `hash_delegate()(X)` retorna o mesmo resultado inteiro em cada chamada.  
  
 Se `X` e `Y` tem a ordenação equivalente, então `hash_delegate()(X)` deve retornar o mesmo resultado inteiro que `hash_delegate()(Y)`.  
  
 Cada elemento contém uma chave separada e um valor mapeado.  A sequência é representada de forma a permitir que a pesquisa, inserir, e a remoção de um elemento com um número arbitrário de operações que é independente do número de elementos na sequência \(o tempo constantes\) \-\- pelo menos no melhor dos casos.  Além disso, inserindo um elemento não invalida iteradores, e removendo um elemento invalida apenas os iteradores que apontam no elemento removido.  
  
 Se os valores com hash não são distribuídos uniformemente, porém, um hash a tabela pode degenerar.  Em extremamente \-\- para uma função de hash que sempre retorna o mesmo valor \-\- a pesquisa, inserir, e a remoção é proporcional ao número de elementos na sequência \(hora lineares\).  O contêiner esforça\-se escolher uma função de hash razoável, um tamanho médio do segmento, e uma tabela de hash \(número total de blocos\), mas você pode substituir algumas ou todas estas escolhas.  Consulte, por exemplo, as funções [hash\_set::max\_load\_factor](../Topic/hash_set::max_load_factor%20\(STL-CLR\).md) e [hash\_set::rehash](../Topic/hash_set::rehash%20\(STL-CLR\).md).  
  
 Um hash\_map oferece suporte aos iteradores bidirecionais, o que significa que você pode avançar para os elementos adjacentes um iterador dados que designa um elemento na sequência controlada.  Um nó principal especial corresponde ao iterador retornado por [hash\_map::end](../dotnet/hash-map-end-stl-clr.md)`()`.  Você pode diminuir este iterador para alcançar o elemento o mais recente na sequência controlada, se houver.  É possível incrementar um iterador de hash\_map para alcançar o nó principal, e comparará no igual a `end()`.  Mas você não pode desreferenciar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento de hash\_map determinado diretamente a posição numérica \-\- isso requer um iterador de acesso aleatório.  
  
 Um iterador de hash\_map armazena um identificador para o nó associado de hash\_map, por sua vez que armazena um identificador para o contêiner associado.  Você pode usar iteradores apenas com seus objetos de contêiner associados.  Um iterador de hash\_map permanece válido desde que o nó associado de hash\_map é associado a um hash\_map.  Além disso, um iterador válido é dereferencable \-\- você pode usá\-lo para acessar ou modificar o valor do elemento que designa \-\- contanto que não é igual a `end()`.  
  
 Apagando ou removendo um elemento chama o destruidor para seu valor armazenado.  Destruir o contêiner apaga todos os elementos.  Assim, um contêiner cujo tipo de elemento é uma classe de referência garante que nenhum elemento é maior que o contêiner.  A observe, entretanto, que manipula um contêiner faz `not` destrói seus elementos.  
  
## Requisitos  
 cliext \<\/hash\_map de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_map](../dotnet/hash-map-stl-clr.md)   
 [hash\_multiset](../dotnet/hash-multiset-stl-clr.md)   
 [hash\_set](../dotnet/hash-set-stl-clr.md)   
 [map](../dotnet/map-stl-clr.md)   
 [multimapa](../dotnet/multimap-stl-clr.md)   
 [multiset](../dotnet/multiset-stl-clr.md)   
 [set](../dotnet/set-stl-clr.md)   
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)