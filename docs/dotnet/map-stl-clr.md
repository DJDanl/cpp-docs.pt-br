---
title: "map (STL/CLR) | Microsoft Docs"
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
  - "cliext::map"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho &lt;cliext/map&gt; [STL/CLR]"
  - "Cabeçalho &lt;map&gt; [STL/CLR]"
  - "classe de mapa [STL/CLR]"
ms.assetid: 8b0a7764-b5e4-4175-a802-82b72eb8662a
caps.latest.revision: 18
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# map (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um objeto que controla uma sequência de variar\- comprimento de elementos que tenha acesso bidirecional.  Você usa o contêiner `map` para gerenciar uma sequência de elementos como \(quase\) equilibrou a árvore ordenada de nós, cada um elemento armazenando.  Um elemento consiste em uma chave, para ordenar a sequência, e um valor mapeado, desde que vai para o passeio.  
  
 Na descrição abaixo, `GValue` é o mesmo que:  
  
 `Microsoft::VisualC::StlClr::GenericPair<GKey, GMapped>`  
  
 onde:  
  
 `GKey` é o mesmo que `Key` a menos que o último é um tipo de referência, nesse caso é `Key^`  
  
 `GMapped` é o mesmo que `Mapped` a menos que o último é um tipo de referência, nesse caso é `Mapped^`  
  
## Sintaxe  
  
```  
template<typename Key,  
    typename Mapped>  
    ref class map  
        :   public  
        System::ICloneable,  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<GValue>,  
        System::Collections::Generic::ICollection<GValue>,  
        System::Collections::Generic::IList<GValue>,  
        System::Collections::Generic::IDictionary<Gkey, GMapped>,  
        Microsoft::VisualC::StlClr::ITree<Gkey, GValue>  
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
|[map::const\_iterator](../dotnet/map-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[map::const\_reference](../dotnet/map-const-reference-stl-clr.md)|O tipo de uma referência constante para um elemento.|  
|[map::const\_reverse\_iterator](../dotnet/map-const-reverse-iterator-stl-clr.md)|O tipo de um iterador invertido constante para a sequência controlada.|  
|[map::difference\_type](../dotnet/map-difference-type-stl-clr.md)|O tipo de distância de possivelmente \(assinado\) entre dois elementos.|  
|[map::generic\_container](../Topic/map::generic_container%20\(STL-CLR\).md)|O tipo de interface genérica para o contêiner.|  
|[map::generic\_iterator](../dotnet/map-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[map::generic\_reverse\_iterator](../dotnet/map-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a interface genérica para o contêiner.|  
|[map::generic\_value](../dotnet/map-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[map::iterator](../dotnet/map-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[map::key\_compare](../dotnet/map-key-compare-stl-clr.md)|O delegado de ordenação para duas chaves.|  
|[map::key\_type](../dotnet/map-key-type-stl-clr.md)|O tipo de uma chave classificação.|  
|[map::mapped\_type](../dotnet/map-mapped-type-stl-clr.md)|O tipo do valor mapeado associado a cada chave.|  
|[map::reference \(STL\/CLR\)](../dotnet/map-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[map::reverse\_iterator](../dotnet/map-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a sequência controlada.|  
|[map::size\_type](../dotnet/map-size-type-stl-clr.md)|O tipo de distância \(não negativo\) de entre dois elementos.|  
|[map::value\_compare](../dotnet/map-value-compare-stl-clr.md)|O delegado de ordenação para dois valores do elemento.|  
|[map::value\_type](../dotnet/map-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função de membro|Descrição|  
|----------------------|---------------|  
|[map::begin](../dotnet/map-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[map::clear](../dotnet/map-clear-stl-clr.md)|Remove todos os elementos.|  
|[map::count](../dotnet/map-count-stl-clr.md)|Conta os elementos que correspondem a uma chave especificada.|  
|[map::empty](../dotnet/map-empty-stl-clr.md)|Testa se nenhum elemento estiver presente.|  
|[map::end](../dotnet/map-end-stl-clr.md)|Designa o término da sequência controlada.|  
|[map::equal\_range \(STL\/CLR\)](../dotnet/map-equal-range-stl-clr.md)|Encontra variam que corresponde a uma chave especificada.|  
|[map::erase](../dotnet/map-erase-stl-clr.md)|Remove os elementos nas posições especificadas.|  
|[map::find](../Topic/map::find%20\(STL-CLR\).md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[map::insert](../dotnet/map-insert-stl-clr.md)|Adiciona os elementos.|  
|[map::key\_comp](../dotnet/map-key-comp-stl-clr.md)|Copia o representante de ordenação para duas chaves.|  
|[map::lower\_bound](../dotnet/map-lower-bound-stl-clr.md)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[map::make\_value](../dotnet/map-make-value-stl-clr.md)|Cria um objeto de valor.|  
|[map::map](../dotnet/map-map-stl-clr.md)|Cria um objeto contêiner.|  
|[map::rbegin](../dotnet/map-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[map::rend](../dotnet/map-rend-stl-clr.md)|Designa o término da sequência controlada invertida.|  
|[map::size](../Topic/map::size%20\(STL-CLR\).md)|Conta o número de elementos.|  
|[map::swap](../dotnet/map-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[map::to\_array](../Topic/map::to_array%20\(STL-CLR\).md)|Copia a sequência controlada a uma nova matriz.|  
|[map::upper\_bound](../dotnet/map-upper-bound-stl-clr.md)|Localiza de extremidade do intervalo que corresponde a uma chave especificada.|  
|[map::value\_comp](../dotnet/map-value-comp-stl-clr.md)|Copia o representante de ordenação para dois valores do elemento.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|[map::operator\=](../dotnet/map-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[map::operator](../dotnet/map-operator-stl-clr.md)|Mapeia uma chave para o valor mapeado associado.|  
|[operador\!\= \(map\)](../dotnet/operator-inequality-map-stl-clr.md)|Determina se um objeto de `map` não é igual a outro objeto de `map` .|  
|[operador\< \(map\)](../Topic/operator%3C%20\(map\)%20\(STL-CLR\).md)|Determina se um objeto de `map` é menor que outro objeto de `map` .|  
|[operador\<\= \(map\)](../dotnet/operator-less-or-equal-map-stl-clr.md)|Determina se um objeto de `map` é menor ou igual a outro objeto de `map` .|  
|[operador\=\= \(map\)](../dotnet/operator-equality-map-stl-clr.md)|Determina se um objeto de `map` é igual a outro objeto de `map` .|  
|[operador\> \(map\)](../dotnet/operator-greater-than-map-stl-clr.md)|Determina se um objeto de `map` é maior que outro objeto de `map` .|  
|[operador\>\= \(map\)](../dotnet/operator-greater-or-equal-map-stl-clr.md)|Determina se um objeto de `map` é maior ou igual a outro objeto de `map` .|  
  
## Interfaces  
  
|Interface|Descrição|  
|---------------|---------------|  
|<xref:System.ICloneable>|Duplica um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência por meio dos elementos.|  
|<xref:System.Collections.ICollection>|Mantenha o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência por meio dos elementos digitados.|  
|<xref:System.Collections.Generic.ICollection%601>|Mantenha o grupo de elementos de tipo.|  
|<xref:System.Collections.Generic.IDictionary%602>|Mantenha o grupo {} valor de chave, o par.|  
|ITreeKey\<, valor\>|Mantenha o contêiner genérico.|  
  
## Comentários  
 O objeto aloca e libera armazenamento para a sequência que controla como nós individuais.  Insere os elementos da \(quase\) equilibrou a árvore que mantém ordenado alterando os links entre nós, nunca copiar o conteúdo de um nó para outro.  Isso significa que você pode inserir e remover os elementos livremente sem os outros elementos de perturbação.  
  
 O objeto classifica a sequência que controla chamando um objeto armazenado delegado do tipo [map::key\_compare](../dotnet/map-key-compare-stl-clr.md).  Você pode especificar o objeto armazenado delegado quando você constrói o mapa; se você não especificar um objeto de delegação, o padrão será a comparação `operator<(key_type, key_type)`.  Você acessa esse objeto armazenado chamando a função de membro [map::key\_comp](../dotnet/map-key-comp-stl-clr.md)`()`.  
  
 Esse objeto de delegação restrita deve impor a ordenação fraco em chaves do tipo [map::key\_type](../dotnet/map-key-type-stl-clr.md).  Isso significa que, para algumas duas chaves `X` e `Y`:  
  
 `key_comp()(X, Y)` retorna o mesmo resultado booliano em cada chamada.  
  
 Se `key_comp()(X, Y)` é true, então `key_comp()(Y, X)` deve ser false.  
  
 Se `key_comp()(X, Y)` é true, então `X` seriam ordenado antes de `Y`.  
  
 Se `!key_comp()(X, Y) && !key_comp()(Y, X)` é true, então `X` e `Y` são ditos ter ordenação equivalente.  
  
 Para qualquer elemento `X` que preceder `Y` na sequência controlada, `key_comp()(Y, X)` será false. \(Para o objeto padrão de delegação, as chaves nunca diminuem em valor.\) Ao contrário da classe [map](../dotnet/map-stl-clr.md)do modelo, um objeto da classe `map` do modelo não exige que as chaves para todos os elementos são exclusivos. \(Dois ou mais chaves podem ter ordenação equivalente.\)  
  
 Cada elemento contém uma chave separada e um valor mapeado.  A sequência é representada de forma a permitir que a pesquisa, inserir, e a remoção de um elemento com um número arbitrário de operações proporcionais ao logaritmo o número de elementos na sequência \(hora logarítmicos\).  Além disso, inserindo um elemento não invalida iteradores, e removendo um elemento invalida apenas os iteradores que apontam no elemento removido.  
  
 Um mapa oferece suporte aos iteradores bidirecionais, o que significa que você pode avançar para os elementos adjacentes um iterador dados que designa um elemento na sequência controlada.  Um nó principal especial corresponde ao iterador retornado por [map::end](../dotnet/map-end-stl-clr.md)`()`.  Você pode diminuir este iterador para alcançar o elemento o mais recente na sequência controlada, se houver.  É possível incrementar um iterador do mapa para alcançar o nó principal, e comparará no igual a `end()`.  Mas você não pode desreferenciar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento do mapa determinado diretamente a posição numérica \-\- isso requer um iterador de acesso aleatório.  
  
 Um iterador do mapa armazena um identificador para o nó associado do mapa, por sua vez que armazena um identificador para o contêiner associado.  Você pode usar iteradores apenas com seus objetos de contêiner associados.  Um iterador do mapa permanece válido desde que o nó associado do mapa é associado a um mapa.  Além disso, um iterador válido é dereferencable \-\- você pode usá\-lo para acessar ou modificar o valor do elemento que designa \-\- contanto que não é igual a `end()`.  
  
 Apagando ou removendo um elemento chama o destruidor para seu valor armazenado.  Destruir o contêiner apaga todos os elementos.  Assim, um contêiner cujo tipo de elemento é uma classe de referência garante que nenhum elemento é maior que o contêiner.  A observe, entretanto, que manipula um contêiner faz `not` destrói seus elementos.  
  
## Requisitos  
 cliext \<\/mapa de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_map](../dotnet/hash-map-stl-clr.md)   
 [hash\_map](../dotnet/hash-map-stl-clr.md)   
 [hash\_multiset](../dotnet/hash-multiset-stl-clr.md)   
 [hash\_set](../dotnet/hash-set-stl-clr.md)   
 [map](../dotnet/map-stl-clr.md)   
 [multiset](../dotnet/multiset-stl-clr.md)   
 [set](../dotnet/set-stl-clr.md)   
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)