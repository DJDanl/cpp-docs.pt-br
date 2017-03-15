---
title: "hash_set (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_set"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho &lt;cliext/hash_set&gt; [STL/CLR]"
  - "Cabeçalho &lt;hash_set&gt; [STL/CLR]"
  - "Classe hash_set [STL/CLR]"
ms.assetid: d110e356-ba3e-4e52-9e2d-d997bf975c96
caps.latest.revision: 18
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_set (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um objeto que controla uma sequência de variar\- comprimento de elementos que tenha acesso bidirecional.  Você usa o contêiner `hash_set` para gerenciar uma sequência de elementos como uma tabela de hash, cada entrada da tabela para armazenar uma lista vinculada bidirecional de nós, e cada nó armazenando um elemento.  O valor de cada elemento é usado como uma chave, a ordenação a sequência.  
  
 Na descrição abaixo, `GValue` é o mesmo que `GKey`, que é por sua vez o mesmo que `Key` a menos que o último é um tipo de referência, nesse caso é `Key^`.  
  
## Sintaxe  
  
```  
template<typename Key>  
    ref class hash_set  
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
|[hash\_set::const\_iterator](../dotnet/hash-set-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[hash\_set::const\_reference](../dotnet/hash-set-const-reference-stl-clr.md)|O tipo de uma referência constante para um elemento.|  
|[hash\_set::const\_reverse\_iterator](../dotnet/hash-set-const-reverse-iterator-stl-clr.md)|O tipo de um iterador invertido constante para a sequência controlada.|  
|[hash\_set::difference\_type](../dotnet/hash-set-difference-type-stl-clr.md)|O tipo de distância de possivelmente \(assinado\) entre dois elementos.|  
|[hash\_set::generic\_container](../Topic/hash_set::generic_container%20\(STL-CLR\).md)|O tipo de interface genérica para o contêiner.|  
|[hash\_set::generic\_iterator](../Topic/hash_set::generic_iterator%20\(STL-CLR\).md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[hash\_set::generic\_reverse\_iterator](../Topic/hash_set::generic_reverse_iterator%20\(STL-CLR\).md)|O tipo de um iterador de cima para baixo para a interface genérica para o contêiner.|  
|[hash\_set::generic\_value](../dotnet/hash-set-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[hash\_set::hasher](../Topic/hash_set::hasher%20\(STL-CLR\).md)|A delegação de hash de uma chave.|  
|[hash\_set::iterator](../dotnet/hash-set-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[hash\_set::key\_compare](../Topic/hash_set::key_compare%20\(STL-CLR\).md)|O delegado de ordenação para duas chaves.|  
|[hash\_set::key\_type](../dotnet/hash-set-key-type-stl-clr.md)|O tipo de uma chave classificação.|  
|[hash\_set::reference](../dotnet/hash-set-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[hash\_set::reverse\_iterator](../dotnet/hash-set-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a sequência controlada.|  
|[hash\_set::size\_type](../dotnet/hash-set-size-type-stl-clr.md)|O tipo de distância \(não negativo\) de entre dois elementos.|  
|[hash\_set::value\_compare](../dotnet/hash-set-value-compare-stl-clr.md)|O delegado de ordenação para dois valores do elemento.|  
|[hash\_set::value\_type](../dotnet/hash-set-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função de membro|Descrição|  
|----------------------|---------------|  
|[hash\_set::begin](../dotnet/hash-set-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[hash\_set::bucket\_count](../dotnet/hash-set-bucket-count-stl-clr.md)|Conta o número de segmentos.|  
|[hash\_set::clear](../dotnet/hash-set-clear-stl-clr.md)|Remove todos os elementos.|  
|[hash\_set::count](../dotnet/hash-set-count-stl-clr.md)|Conta os elementos que correspondem a uma chave especificada.|  
|[hash\_set::empty](../dotnet/hash-set-empty-stl-clr.md)|Testa se nenhum elemento estiver presente.|  
|[hash\_set::end](../dotnet/hash-set-end-stl-clr.md)|Designa o término da sequência controlada.|  
|[hash\_set::equal\_range](../dotnet/hash-set-equal-range-stl-clr.md)|Encontra variam que corresponde a uma chave especificada.|  
|[hash\_set::erase](../dotnet/hash-set-erase-stl-clr.md)|Remove os elementos nas posições especificadas.|  
|[hash\_set::find](../Topic/hash_set::find%20\(STL-CLR\).md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[hash\_set::hash\_delegate](../Topic/hash_set::hash_delegate%20\(STL-CLR\).md)|Copia a delegação de hash de uma chave.|  
|[hash\_set::hash\_set](../dotnet/hash-set-hash-set-stl-clr.md)|Cria um objeto contêiner.|  
|[hash\_set::insert](../dotnet/hash-set-insert-stl-clr.md)|Adiciona os elementos.|  
|[hash\_set::key\_comp](../dotnet/hash-set-key-comp-stl-clr.md)|Copia o representante de ordenação para duas chaves.|  
|[hash\_set::load\_factor](../dotnet/hash-set-load-factor-stl-clr.md)|Conta os elementos médio por segmento.|  
|[hash\_set::lower\_bound](../dotnet/hash-set-lower-bound-stl-clr.md)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[hash\_set::make\_value](../Topic/hash_set::make_value%20\(STL-CLR\).md)|Cria um objeto de valor.|  
|[hash\_set::max\_load\_factor](../Topic/hash_set::max_load_factor%20\(STL-CLR\).md)|Obtém ou define os elementos máximo pelo segmento.|  
|[hash\_set::rbegin](../dotnet/hash-set-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[hash\_set::rehash](../Topic/hash_set::rehash%20\(STL-CLR\).md)|Recria a tabela de hash.|  
|[hash\_set::rend](../dotnet/hash-set-rend-stl-clr.md)|Designa o término da sequência controlada invertida.|  
|[hash\_set::size](../dotnet/hash-set-size-stl-clr.md)|Conta o número de elementos.|  
|[hash\_set::swap](../dotnet/hash-set-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[hash\_set::to\_array](../dotnet/hash-set-to-array-stl-clr.md)|Copia a sequência controlada a uma nova matriz.|  
|[hash\_set::upper\_bound](../dotnet/hash-set-upper-bound-stl-clr.md)|Localiza de extremidade do intervalo que corresponde a uma chave especificada.|  
|[hash\_set::value\_comp](../dotnet/hash-set-value-comp-stl-clr.md)|Copia o representante de ordenação para dois valores do elemento.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|[hash\_set::operator\=](../dotnet/hash-set-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
  
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
  
 Observe que o contêiner garante que apenas elementos cujas chaves têm a ordenação de equivalente \(e quais picam com o mesmo valor inteiro\) são adjacentes em um segmento.  Ao contrário da classe [hash\_multiset](../dotnet/hash-multiset-stl-clr.md)do modelo, um objeto da classe `hash_set` do modelo garante que as chaves para todos os elementos sejam exclusivos. \(Nenhuma duas chaves têm equivalente a ordenação.\)  
  
 O objeto determina qual segmento deve conter uma chave de classificação especificada chamando um objeto armazenado delegado do tipo [hash\_set::hasher](../Topic/hash_set::hasher%20\(STL-CLR\).md).  Você acessa esse objeto armazenado chamando a função de membro [hash\_set::hash\_delegate](../Topic/hash_set::hash_delegate%20\(STL-CLR\).md)`()` para obter um valor inteiro que depende do valor da chave.  Você pode especificar o objeto armazenado delegado quando você constrói o hash\_set; se você não especificar um objeto de delegação, o padrão será a função `System::Object::hash_value(key_type)`.  Isso significa que, para algumas chaves `X` e `Y`:  
  
 `hash_delegate()(X)` retorna o mesmo resultado inteiro em cada chamada.  
  
 Se `X` e `Y` tem a ordenação equivalente, então `hash_delegate()(X)` deve retornar o mesmo resultado inteiro que `hash_delegate()(Y)`.  
  
 Cada elemento serve como uma chave e um valor.  A sequência é representada de forma a permitir que a pesquisa, inserir, e a remoção de um elemento com um número arbitrário de operações que é independente do número de elementos na sequência \(o tempo constantes\) \-\- pelo menos no melhor dos casos.  Além disso, inserindo um elemento não invalida iteradores, e removendo um elemento invalida apenas os iteradores que apontam no elemento removido.  
  
 Se os valores com hash não são distribuídos uniformemente, porém, um hash a tabela pode degenerar.  Em extremamente \-\- para uma função de hash que sempre retorna o mesmo valor \-\- a pesquisa, inserir, e a remoção é proporcional ao número de elementos na sequência \(hora lineares\).  O contêiner esforça\-se escolher uma função de hash razoável, um tamanho médio do segmento, e uma tabela de hash \(número total de blocos\), mas você pode substituir algumas ou todas estas escolhas.  Consulte, por exemplo, as funções [hash\_set::max\_load\_factor](../Topic/hash_set::max_load_factor%20\(STL-CLR\).md) e [hash\_set::rehash](../Topic/hash_set::rehash%20\(STL-CLR\).md).  
  
 Um hash\_set oferece suporte aos iteradores bidirecionais, o que significa que você pode avançar para os elementos adjacentes um iterador dados que designa um elemento na sequência controlada.  Um nó principal especial corresponde ao iterador retornado por [hash\_set::end](../dotnet/hash-set-end-stl-clr.md)`()`.  Você pode diminuir este iterador para alcançar o elemento o mais recente na sequência controlada, se houver.  É possível incrementar um iterador de hash\_set para alcançar o nó principal, e comparará no igual a `end()`.  Mas você não pode desreferenciar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento de hash\_set determinado diretamente a posição numérica \-\- isso requer um iterador de acesso aleatório.  
  
 Um iterador de hash\_set armazena um identificador para o nó associado de hash\_set, por sua vez que armazena um identificador para o contêiner associado.  Você pode usar iteradores apenas com seus objetos de contêiner associados.  Um iterador de hash\_set permanece válido desde que o nó associado de hash\_set é associado a um hash\_set.  Além disso, um iterador válido é dereferencable \-\- você pode usá\-lo para acessar ou modificar o valor do elemento que designa \-\- contanto que não é igual a `end()`.  
  
 Apagando ou removendo um elemento chama o destruidor para seu valor armazenado.  Destruir o contêiner apaga todos os elementos.  Assim, um contêiner cujo tipo de elemento é uma classe de referência garante que nenhum elemento é maior que o contêiner.  A observe, entretanto, que manipula um contêiner faz `not` destrói seus elementos.  
  
## Requisitos  
 cliext \<\/hash\_set de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_map](../dotnet/hash-map-stl-clr.md)   
 [hash\_set](../dotnet/hash-set-stl-clr.md)   
 [hash\_set](../dotnet/hash-set-stl-clr.md)   
 [map](../dotnet/map-stl-clr.md)   
 [set](../dotnet/set-stl-clr.md)   
 [set](../dotnet/set-stl-clr.md)   
 [set](../dotnet/set-stl-clr.md)   
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)