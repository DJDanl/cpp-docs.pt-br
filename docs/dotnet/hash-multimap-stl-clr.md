---
title: "hash_multimap (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_multimap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho &lt;cliext/hash_map&gt; [STL/CLR]"
  - "Cabeçalho &lt;hash_map&gt; [STL/CLR]"
  - "Classe hash_multimap [STL/CLR]"
ms.assetid: cd78687b-8a05-48e0-9d22-8b8194ae3b0b
caps.latest.revision: 19
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_multimap (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um objeto que controla uma sequência de variar\- comprimento de elementos que tenha acesso bidirecional.  Você usa o contêiner `hash_multimap` para gerenciar uma sequência de elementos como uma tabela de hash, cada entrada da tabela para armazenar uma lista vinculada bidirecional de nós, e cada nó armazenando um elemento.  Um elemento consiste em uma chave, para ordenar a sequência, e um valor mapeado, desde que vai para o passeio.  
  
 Na descrição abaixo, `GValue` é o mesmo que:  
  
 `Microsoft::VisualC::StlClr::GenericPair<GKey, GMapped>`  
  
 onde:  
  
 `GKey` é o mesmo que `Key` a menos que o último é um tipo de referência, nesse caso é `Key^`  
  
 `GMapped` é o mesmo que `Mapped` a menos que o último é um tipo de referência, nesse caso é `Mapped^`  
  
## Sintaxe  
  
```  
template<typename Key,  
    typename Mapped>  
    ref class hash_multimap  
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
  
 Mapeado  
 O tipo de componente adicional de um elemento na sequência controlada.  
  
## Membros  
  
|Definição de tipo|Descrição|  
|-----------------------|---------------|  
|[hash\_multimap::const\_iterator](../dotnet/hash-multimap-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[hash\_multimap::const\_reference](../dotnet/hash-multimap-const-reference-stl-clr.md)|O tipo de uma referência constante para um elemento.|  
|[hash\_multimap::const\_reverse\_iterator](../Topic/hash_multimap::const_reverse_iterator%20\(STL-CLR\).md)|O tipo de um iterador invertido constante para a sequência controlada.|  
|[hash\_multimap::difference\_type](../dotnet/hash-multimap-difference-type-stl-clr.md)|O tipo de distância de possivelmente \(assinado\) entre dois elementos.|  
|[hash\_multimap::generic\_container](../dotnet/hash-multimap-generic-container-stl-clr.md)|O tipo de interface genérica para o contêiner.|  
|[hash\_multimap::generic\_iterator](../dotnet/hash-multimap-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[hash\_multimap::generic\_reverse\_iterator](../dotnet/hash-multimap-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a interface genérica para o contêiner.|  
|[hash\_multimap::generic\_value](../dotnet/hash-multimap-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[hash\_multimap::hasher](../dotnet/hash-multimap-hasher-stl-clr.md)|A delegação de hash de uma chave.|  
|[hash\_multimap::iterator](../dotnet/hash-multimap-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[hash\_multimap::key\_compare](../dotnet/hash-multimap-key-compare-stl-clr.md)|O delegado de ordenação para duas chaves.|  
|[hash\_multimap::key\_type](../dotnet/hash-multimap-key-type-stl-clr.md)|O tipo de uma chave classificação.|  
|[hash\_multimap::mapped\_type](../Topic/hash_multimap::mapped_type%20\(STL-CLR\).md)|O tipo do valor mapeado associado a cada chave.|  
|[hash\_multimap::reference](../dotnet/hash-multimap-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[hash\_multimap::reverse\_iterator](../dotnet/hash-multimap-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a sequência controlada.|  
|[hash\_multimap::size\_type](../dotnet/hash-multimap-size-type-stl-clr.md)|O tipo de distância \(não negativo\) de entre dois elementos.|  
|[hash\_multimap::value\_compare](../dotnet/hash-multimap-value-compare-stl-clr.md)|O delegado de ordenação para dois valores do elemento.|  
|[hash\_multimap::value\_type](../dotnet/hash-multimap-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função de membro|Descrição|  
|----------------------|---------------|  
|[hash\_multimap::begin](../dotnet/hash-multimap-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[hash\_multimap::bucket\_count](../dotnet/hash-multimap-bucket-count-stl-clr.md)|Conta o número de segmentos.|  
|[hash\_multimap::clear](../dotnet/hash-multimap-clear-stl-clr.md)|Remove todos os elementos.|  
|[hash\_multimap::count](../dotnet/hash-multimap-count-stl-clr.md)|Conta os elementos que correspondem a uma chave especificada.|  
|[hash\_multimap::empty](../dotnet/hash-multimap-empty-stl-clr.md)|Testa se nenhum elemento estiver presente.|  
|[hash\_multimap::end](../dotnet/hash-multimap-end-stl-clr.md)|Designa o término da sequência controlada.|  
|[hash\_multimap::equal\_range](../dotnet/hash-multimap-equal-range-stl-clr.md)|Encontra variam que corresponde a uma chave especificada.|  
|[hash\_multimap::erase](../dotnet/hash-multimap-erase-stl-clr.md)|Remove os elementos nas posições especificadas.|  
|[hash\_multimap::find](../dotnet/hash-multimap-find-stl-clr.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[hash\_multimap::hash\_delegate](../dotnet/hash-multimap-hash-delegate-stl-clr.md)|Copia a delegação de hash de uma chave.|  
|[hash\_multimap::hash\_multimap](../dotnet/hash-multimap-hash-multimap-stl-clr.md)|Cria um objeto contêiner.|  
|[hash\_multimap::insert](../dotnet/hash-multimap-insert-stl-clr.md)|Adiciona os elementos.|  
|[hash\_multimap::key\_comp](../dotnet/hash-multimap-key-comp-stl-clr.md)|Copia o representante de ordenação para duas chaves.|  
|[hash\_multimap::load\_factor](../dotnet/hash-multimap-load-factor-stl-clr.md)|Conta os elementos médio por segmento.|  
|[hash\_multimap::lower\_bound](../Topic/hash_multimap::lower_bound%20\(STL-CLR\).md)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[hash\_multimap::make\_value](../dotnet/hash-multimap-make-value-stl-clr.md)|Cria um objeto de valor.|  
|[hash\_multimap::max\_load\_factor](../Topic/hash_multimap::max_load_factor%20\(STL-CLR\).md)|Obtém ou define os elementos máximo pelo segmento.|  
|[hash\_multimap::rbegin](../dotnet/hash-multimap-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[hash\_multimap::rehash](../dotnet/hash-multimap-rehash-stl-clr.md)|Recria a tabela de hash.|  
|[hash\_multimap::rend](../dotnet/hash-multimap-rend-stl-clr.md)|Designa o término da sequência controlada invertida.|  
|[hash\_multimap::size](../dotnet/hash-multimap-size-stl-clr.md)|Conta o número de elementos.|  
|[hash\_multimap::swap](../dotnet/hash-multimap-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[hash\_multimap::to\_array](../dotnet/hash-multimap-to-array-stl-clr.md)|Copia a sequência controlada a uma nova matriz.|  
|[hash\_multimap::upper\_bound](../Topic/hash_multimap::upper_bound%20\(STL-CLR\).md)|Localiza de extremidade do intervalo que corresponde a uma chave especificada.|  
|[hash\_multimap::value\_comp](../dotnet/hash-multimap-value-comp-stl-clr.md)|Copia o representante de ordenação para dois valores do elemento.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|[hash\_multimap::operator\=](../dotnet/hash-multimap-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
  
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
  
 Observe que o contêiner garante que apenas elementos cujas chaves têm a ordenação de equivalente \(e quais picam com o mesmo valor inteiro\) são adjacentes em um segmento.  Ao contrário da classe [hash\_map](../dotnet/hash-map-stl-clr.md)do modelo, um objeto da classe `hash_multimap` do modelo não exige que as chaves para todos os elementos são exclusivos. \(Dois ou mais chaves podem ter ordenação equivalente.\)  
  
 O objeto determina qual segmento deve conter uma chave de classificação especificada chamando um objeto armazenado delegado do tipo [hash\_set::hasher](../Topic/hash_set::hasher%20\(STL-CLR\).md).  Você acessa esse objeto armazenado chamando a função de membro [hash\_set::hash\_delegate](../Topic/hash_set::hash_delegate%20\(STL-CLR\).md)`()` para obter um valor inteiro que depende do valor da chave.  Você pode especificar o objeto armazenado delegado quando você constrói o hash\_set; se você não especificar um objeto de delegação, o padrão será a função `System::Object::hash_value(key_type)`.  Isso significa que, para algumas chaves `X` e `Y`:  
  
 `hash_delegate()(X)` retorna o mesmo resultado inteiro em cada chamada.  
  
 Se `X` e `Y` tem a ordenação equivalente, então `hash_delegate()(X)` deve retornar o mesmo resultado inteiro que `hash_delegate()(Y)`.  
  
 Cada elemento contém uma chave separada e um valor mapeado.  A sequência é representada de forma a permitir que a pesquisa, inserir, e a remoção de um elemento com um número arbitrário de operações que é independente do número de elementos na sequência \(o tempo constantes\) \-\- pelo menos no melhor dos casos.  Além disso, inserindo um elemento não invalida iteradores, e removendo um elemento invalida apenas os iteradores que apontam no elemento removido.  
  
 Se os valores com hash não são distribuídos uniformemente, porém, um hash a tabela pode degenerar.  Em extremamente \-\- para uma função de hash que sempre retorna o mesmo valor \-\- a pesquisa, inserir, e a remoção é proporcional ao número de elementos na sequência \(hora lineares\).  O contêiner esforça\-se escolher uma função de hash razoável, um tamanho médio do segmento, e uma tabela de hash \(número total de blocos\), mas você pode substituir algumas ou todas estas escolhas.  Consulte, por exemplo, as funções [hash\_set::max\_load\_factor](../Topic/hash_set::max_load_factor%20\(STL-CLR\).md) e [hash\_set::rehash](../Topic/hash_set::rehash%20\(STL-CLR\).md).  
  
 Um hash\_multimap oferece suporte aos iteradores bidirecionais, o que significa que você pode avançar para os elementos adjacentes um iterador dados que designa um elemento na sequência controlada.  Um nó principal especial corresponde ao iterador retornado por [hash\_multimap::end](../dotnet/hash-multimap-end-stl-clr.md)`()`.  Você pode diminuir este iterador para alcançar o elemento o mais recente na sequência controlada, se houver.  É possível incrementar um iterador de hash\_multimap para alcançar o nó principal, e comparará no igual a `end()`.  Mas você não pode desreferenciar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento de hash\_multimap determinado diretamente a posição numérica \-\- isso requer um iterador de acesso aleatório.  
  
 Um iterador de hash\_multimap armazena um identificador para o nó associado de hash\_multimap, por sua vez que armazena um identificador para o contêiner associado.  Você pode usar iteradores apenas com seus objetos de contêiner associados.  Um iterador de hash\_multimap permanece válido desde que o nó associado de hash\_multimap é associado a um hash\_multimap.  Além disso, um iterador válido é dereferencable \-\- você pode usá\-lo para acessar ou modificar o valor do elemento que designa \-\- contanto que não é igual a `end()`.  
  
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