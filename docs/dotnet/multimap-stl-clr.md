---
title: "multimapa (STL/CLR) | Microsoft Docs"
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
  - "cliext::multimap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho &lt;cliext/map&gt; [STL/CLR]"
  - "Cabeçalho &lt;map&gt; [STL/CLR]"
  - "classe multimapa [STL/CLR]"
ms.assetid: 3dfe329d-a078-462a-b050-7999ce6110ad
caps.latest.revision: 17
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# multimapa (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um objeto que controla uma sequência de variar\- comprimento de elementos que tenha acesso bidirecional.  Você usa o contêiner `multimap` para gerenciar uma sequência de elementos como \(quase\) equilibrou a árvore ordenada de nós, cada um elemento armazenando.  Um elemento consiste em uma chave, para ordenar a sequência, e um valor mapeado, desde que vai para o passeio.  
  
 Na descrição abaixo, `GValue` é o mesmo que:  
  
 `Microsoft::VisualC::StlClr::GenericPair<GKey, GMapped>`  
  
 onde:  
  
 `GKey` é o mesmo que `Key` a menos que o último é um tipo de referência, nesse caso é `Key^`  
  
 `GMapped` é o mesmo que `Mapped` a menos que o último é um tipo de referência, nesse caso é `Mapped^`  
  
## Sintaxe  
  
```  
template<typename Key,  
    typename Mapped>  
    ref class multimap  
        :   public  
        System::ICloneable,  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<GValue>,  
        System::Collections::Generic::ICollection<GValue>,  
        System::Collections::Generic::IList<GValue>,  
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
|[multimap::const\_iterator](../dotnet/multimap-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[multimap::const\_reference](../dotnet/multimap-const-reference-stl-clr.md)|O tipo de uma referência constante para um elemento.|  
|[multimap::const\_reverse\_iterator](../Topic/multimap::const_reverse_iterator%20\(STL-CLR\).md)|O tipo de um iterador invertido constante para a sequência controlada.|  
|[multimap::difference\_type](../dotnet/multimap-difference-type-stl-clr.md)|O tipo de distância de possivelmente \(assinado\) entre dois elementos.|  
|[multimap::generic\_container](../dotnet/multimap-generic-container-stl-clr.md)|O tipo de interface genérica para o contêiner.|  
|[multimap::generic\_iterator](../dotnet/multimap-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[multimap::generic\_reverse\_iterator](../dotnet/multimap-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a interface genérica para o contêiner.|  
|[multimap::generic\_value](../dotnet/multimap-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[multimap::iterator](../dotnet/multimap-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[multimap::key\_compare](../dotnet/multimap-key-compare-stl-clr.md)|O delegado de ordenação para duas chaves.|  
|[multimap::key\_type](../dotnet/multimap-key-type-stl-clr.md)|O tipo de uma chave classificação.|  
|[multimap::mapped\_type](../dotnet/multimap-mapped-type-stl-clr.md)|O tipo do valor mapeado associado a cada chave.|  
|[multimap::reference](../dotnet/multimap-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[multimap::reverse\_iterator](../Topic/multimap::reverse_iterator%20\(STL-CLR\).md)|O tipo de um iterador de cima para baixo para a sequência controlada.|  
|[multimap::size\_type](../Topic/multimap::size_type%20\(STL-CLR\).md)|O tipo de distância \(não negativo\) de entre dois elementos.|  
|[multimap::value\_compare](../Topic/multimap::value_compare%20\(STL-CLR\).md)|O delegado de ordenação para dois valores do elemento.|  
|[multimap::value\_type](../dotnet/multimap-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função de membro|Descrição|  
|----------------------|---------------|  
|[multimap::begin](../dotnet/multimap-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[multimap::clear](../Topic/multimap::clear%20\(STL-CLR\).md)|Remove todos os elementos.|  
|[multimap::count](../dotnet/multimap-count-stl-clr.md)|Conta os elementos que correspondem a uma chave especificada.|  
|[multimap::empty](../dotnet/multimap-empty-stl-clr.md)|Testa se nenhum elemento estiver presente.|  
|[multimap::end](../dotnet/multimap-end-stl-clr.md)|Designa o término da sequência controlada.|  
|[multimap::equal\_range](../dotnet/multimap-equal-range-stl-clr.md)|Encontra variam que corresponde a uma chave especificada.|  
|[multimap::erase](../dotnet/multimap-erase-stl-clr.md)|Remove os elementos nas posições especificadas.|  
|[multimap::find](../dotnet/multimap-find-stl-clr.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[multimap::insert](../dotnet/multimap-insert-stl-clr.md)|Adiciona os elementos.|  
|[multimap::key\_comp](../dotnet/multimap-key-comp-stl-clr.md)|Copia o representante de ordenação para duas chaves.|  
|[multimap::lower\_bound](../dotnet/multimap-lower-bound-stl-clr.md)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[multimap::make\_value](../dotnet/multimap-make-value-stl-clr.md)|Cria um objeto de valor.|  
|[multimap::multimap](../dotnet/multimap-multimap-stl-clr.md)|Cria um objeto contêiner.|  
|[multimap::rbegin](../dotnet/multimap-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[multimap::rend](../dotnet/multimap-rend-stl-clr.md)|Designa o término da sequência controlada invertida.|  
|[multimap::size](../Topic/multimap::size%20\(STL-CLR\).md)|Conta o número de elementos.|  
|[multimap::swap](../dotnet/multimap-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[multimap::to\_array](../dotnet/multimap-to-array-stl-clr.md)|Copia a sequência controlada a uma nova matriz.|  
|[multimap::upper\_bound](../dotnet/multimap-upper-bound-stl-clr.md)|Localiza de extremidade do intervalo que corresponde a uma chave especificada.|  
|[multimap::value\_comp](../Topic/multimap::value_comp%20\(STL-CLR\).md)|Copia o representante de ordenação para dois valores do elemento.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|[multimap::operator\=](../dotnet/multimap-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[operador\!\= \(multimap\)](../Topic/operator!=%20\(multimap\)%20\(STL-CLR\).md)|Determina se um objeto de `multimap` não é igual a outro objeto de `multimap` .|  
|[operador\< \(multimap\)](../dotnet/operator-less-than-multimap-stl-clr.md)|Determina se um objeto de `multimap` é menor que outro objeto de `multimap` .|  
|[operador\<\= \(multimap\)](../dotnet/operator-less-or-equal-multimap-stl-clr.md)|Determina se um objeto de `multimap` é menor ou igual a outro objeto de `multimap` .|  
|[operador\=\= \(multimap\)](../dotnet/operator-equality-multimap-stl-lr.md)|Determina se um objeto de `multimap` é igual a outro objeto de `multimap` .|  
|[operador\> \(multimap\)](../dotnet/operator-greater-than-multimap-stl-clr.md)|Determina se um objeto de `multimap` é maior que outro objeto de `multimap` .|  
|[operador\>\= \(multimap\)](../Topic/operator%3E=%20\(multimap\)%20\(STL-CLR\).md)|Determina se um objeto de `multimap` é maior ou igual a outro objeto de `multimap` .|  
  
## Interfaces  
  
|Interface|Descrição|  
|---------------|---------------|  
|<xref:System.ICloneable>|Duplica um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência por meio dos elementos.|  
|<xref:System.Collections.ICollection>|Mantenha o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência por meio dos elementos digitados.|  
|<xref:System.Collections.Generic.ICollection%601>|Mantenha o grupo de elementos de tipo.|  
|ITreeKey\<, valor\>|Mantenha o contêiner genérico.|  
  
## Comentários  
 O objeto aloca e libera armazenamento para a sequência que controla como nós individuais.  Insere os elementos da \(quase\) equilibrou a árvore que mantém ordenado alterando os links entre nós, nunca copiar o conteúdo de um nó para outro.  Isso significa que você pode inserir e remover os elementos livremente sem os outros elementos de perturbação.  
  
 O objeto classifica a sequência que controla chamando um objeto armazenado delegado do tipo [multimap::key\_compare](../dotnet/multimap-key-compare-stl-clr.md).  Você pode especificar o objeto armazenado delegado quando você constrói o multimap; se você não especificar um objeto de delegação, o padrão será a comparação `operator<(key_type, key_type)`.  Você acessa esse objeto armazenado chamando a função de membro [multimap::key\_comp](../dotnet/multimap-key-comp-stl-clr.md)`()`.  
  
 Esse objeto de delegação restrita deve impor a ordenação fraco em chaves do tipo [multimap::key\_type](../dotnet/multimap-key-type-stl-clr.md).  Isso significa que, para algumas duas chaves `X` e `Y`:  
  
 `key_comp()(X, Y)` retorna o mesmo resultado booliano em cada chamada.  
  
 Se `key_comp()(X, Y)` é true, então `key_comp()(Y, X)` deve ser false.  
  
 Se `key_comp()(X, Y)` é true, então `X` seriam ordenado antes de `Y`.  
  
 Se `!key_comp()(X, Y) && !key_comp()(Y, X)` é true, então `X` e `Y` são ditos ter ordenação equivalente.  
  
 Para qualquer elemento `X` que preceder `Y` na sequência controlada, `key_comp()(Y, X)` será false. \(Para o objeto padrão de delegação, as chaves nunca diminuem em valor.\) Ao contrário da classe [map](../dotnet/map-stl-clr.md)do modelo, um objeto da classe `multimap` do modelo não exige que as chaves para todos os elementos são exclusivos. \(Dois ou mais chaves podem ter ordenação equivalente.\)  
  
 Cada elemento contém uma chave separada e um valor mapeado.  A sequência é representada de forma a permitir que a pesquisa, inserir, e a remoção de um elemento com um número arbitrário de operações proporcionais ao logaritmo o número de elementos na sequência \(hora logarítmicos\).  Além disso, inserindo um elemento não invalida iteradores, e removendo um elemento invalida apenas os iteradores que apontam no elemento removido.  
  
 Um multimap oferece suporte aos iteradores bidirecionais, o que significa que você pode avançar para os elementos adjacentes um iterador dados que designa um elemento na sequência controlada.  Um nó principal especial corresponde ao iterador retornado por [multimap::end](../dotnet/multimap-end-stl-clr.md)`()`.  Você pode diminuir este iterador para alcançar o elemento o mais recente na sequência controlada, se houver.  É possível incrementar um iterador de multimap para alcançar o nó principal, e comparará no igual a `end()`.  Mas você não pode desreferenciar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento de multimap determinado diretamente a posição numérica \-\- isso requer um iterador de acesso aleatório.  
  
 Um iterador de multimap armazena um identificador para o nó associado de multimap, por sua vez que armazena um identificador para o contêiner associado.  Você pode usar iteradores apenas com seus objetos de contêiner associados.  Um iterador de multimap permanece válido desde que o nó associado de multimap é associado a um multimap.  Além disso, um iterador válido é dereferencable \-\- você pode usá\-lo para acessar ou modificar o valor do elemento que designa \-\- contanto que não é igual a `end()`.  
  
 Apagando ou removendo um elemento chama o destruidor para seu valor armazenado.  Destruir o contêiner apaga todos os elementos.  Assim, um contêiner cujo tipo de elemento é uma classe de referência garante que nenhum elemento é maior que o contêiner.  A observe, entretanto, que manipula um contêiner faz `not` destrói seus elementos.  
  
## Requisitos  
 cliext \<\/mapa de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_map](../dotnet/hash-map-stl-clr.md)   
 [hash\_multimap](../dotnet/hash-multimap-stl-clr.md)   
 [hash\_multiset](../dotnet/hash-multiset-stl-clr.md)   
 [hash\_set](../dotnet/hash-set-stl-clr.md)   
 [map](../dotnet/map-stl-clr.md)   
 [multiset](../dotnet/multiset-stl-clr.md)   
 [set](../dotnet/set-stl-clr.md)   
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)