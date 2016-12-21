---
title: "multiset (STL/CLR) | Microsoft Docs"
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
  - "cliext::multiset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho &lt;cliext/set&gt; [STL/CLR]"
  - "Cabeçalho &lt;set&gt; [STL/CLR]"
  - "classe multiset [STL/CLR]"
ms.assetid: 7c46e2b4-cd88-49b7-a9e6-63ad5ae7feb5
caps.latest.revision: 18
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# multiset (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um objeto que controla uma sequência de variar\- comprimento de elementos que tenha acesso bidirecional.  Você usa o contêiner `multiset` para gerenciar uma sequência de elementos como \(quase\) equilibrou a árvore ordenada de nós, cada um elemento armazenando.  
  
 Na descrição abaixo, `GValue` é o mesmo que `GKey`, que é por sua vez o mesmo que `Key` a menos que o último é um tipo de referência, nesse caso é `Key^`.  
  
## Sintaxe  
  
```  
template<typename Key>  
    ref class multiset  
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
  
## Membros  
  
|Definição de tipo|Descrição|  
|-----------------------|---------------|  
|[multiset::const\_iterator](../dotnet/multiset-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[multiset::const\_reference](../dotnet/multiset-const-reference-stl-clr.md)|O tipo de uma referência constante para um elemento.|  
|[multiset::const\_reverse\_iterator](../dotnet/multiset-const-reverse-iterator-stl-clr.md)|O tipo de um iterador invertido constante para a sequência controlada.|  
|[multiset::difference\_type](../dotnet/multiset-difference-type-stl-clr.md)|O tipo de distância de possivelmente \(assinado\) entre dois elementos.|  
|[multiset::generic\_container](../dotnet/multiset-generic-container-stl-clr.md)|O tipo de interface genérica para o contêiner.|  
|[multiset::generic\_iterator](../Topic/multiset::generic_iterator%20\(STL-CLR\).md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[multiset::generic\_reverse\_iterator](../Topic/multiset::generic_reverse_iterator%20\(STL-CLR\).md)|O tipo de um iterador de cima para baixo para a interface genérica para o contêiner.|  
|[multiset::generic\_value](../dotnet/multiset-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[multiset::iterator](../dotnet/multiset-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[multiset::key\_compare](../dotnet/multiset-key-compare-stl-clr.md)|O delegado de ordenação para duas chaves.|  
|[multiset::key\_type](../dotnet/multiset-key-type-stl-clr.md)|O tipo de uma chave classificação.|  
|[multiset::reference](../dotnet/multiset-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[multiset::reverse\_iterator](../dotnet/multiset-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a sequência controlada.|  
|[multiset::size\_type](../dotnet/multiset-size-type-stl-clr.md)|O tipo de distância \(não negativo\) de entre dois elementos.|  
|[multiset::value\_compare](../Topic/multiset::value_compare%20\(STL-CLR\).md)|O delegado de ordenação para dois valores do elemento.|  
|[multiset::value\_type](../dotnet/multiset-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função de membro|Descrição|  
|----------------------|---------------|  
|[multiset::begin](../dotnet/multiset-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[multiset::clear](../dotnet/multiset-clear-stl-clr.md)|Remove todos os elementos.|  
|[multiset::count](../dotnet/multiset-count-stl-clr.md)|Conta os elementos que correspondem a uma chave especificada.|  
|[multiset::empty](../dotnet/multiset-empty-stl-clr.md)|Testa se nenhum elemento estiver presente.|  
|[multiset::end](../dotnet/multiset-end-stl-clr.md)|Designa o término da sequência controlada.|  
|[multiset::equal\_range](../dotnet/multiset-equal-range-stl-clr.md)|Encontra variam que corresponde a uma chave especificada.|  
|[multiset::erase](../dotnet/multiset-erase-stl-clr.md)|Remove os elementos nas posições especificadas.|  
|[multiset::find](../Topic/multiset::find%20\(STL-CLR\).md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[multiset::insert](../Topic/multiset::insert%20\(STL-CLR\).md)|Adiciona os elementos.|  
|[multiset::key\_comp](../Topic/multiset::key_comp%20\(STL-CLR\).md)|Copia o representante de ordenação para duas chaves.|  
|[multiset::lower\_bound](../Topic/multiset::lower_bound%20\(STL-CLR\).md)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[multiset::make\_value](../Topic/multiset::make_value%20\(STL-CLR\).md)|Cria um objeto de valor.|  
|[multiset::multiset](../dotnet/multiset-multiset-stl-clr.md)|Cria um objeto contêiner.|  
|[multiset::rbegin](../dotnet/multiset-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[multiset::rend](../Topic/multiset::rend%20\(STL-CLR\).md)|Designa o término da sequência controlada invertida.|  
|[multiset::size](../dotnet/multiset-size-stl-clr.md)|Conta o número de elementos.|  
|[multiset::swap](../dotnet/multiset-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[multiset::to\_array](../dotnet/multiset-to-array-stl-clr.md)|Copia a sequência controlada a uma nova matriz.|  
|[multiset::upper\_bound](../dotnet/multiset-upper-bound-stl-clr.md)|Localiza de extremidade do intervalo que corresponde a uma chave especificada.|  
|[multiset::value\_comp](../dotnet/multiset-value-comp-stl-clr.md)|Copia o representante de ordenação para dois valores do elemento.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|[multiset::operator\=](../dotnet/multiset-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[operador\!\= \(multiset\)](../dotnet/operator-inequality-multiset-stl-clr.md)|Determina se um objeto de `multiset` não é igual a outro objeto de `multiset` .|  
|[operador\< \(multiset\)](../dotnet/operator-less-than-multiset-stl-clr.md)|Determina se um objeto de `multiset` é menor que outro objeto de `multiset` .|  
|[operador\<\= \(multiset\)](../Topic/operator%3C=%20\(multiset\)%20\(STL-CLR\).md)|Determina se um objeto de `multiset` é menor ou igual a outro objeto de `multiset` .|  
|[operador\=\= \(multiset\)](../Topic/operator==%20\(multiset\)%20\(STL-CLR\).md)|Determina se um objeto de `multiset` é igual a outro objeto de `multiset` .|  
|[operador\> \(multiset\)](../dotnet/operator-greater-than-multiset-stl-clr.md)|Determina se um objeto de `multiset` é maior que outro objeto de `multiset` .|  
|[operador\>\= \(multiset\)](../Topic/operator%3E=%20\(multiset\)%20\(STL-CLR\).md)|Determina se um objeto de `multiset` é maior ou igual a outro objeto de `multiset` .|  
  
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
  
 O objeto classifica a sequência que controla chamando um objeto armazenado delegado do tipo [multiset::key\_compare](../dotnet/multiset-key-compare-stl-clr.md).  Você pode especificar o objeto armazenado delegado quando você constrói o multiset; se você não especificar um objeto de delegação, o padrão será a comparação `operator<(key_type, key_type)`.  Você acessa esse objeto armazenado chamando a função de membro [multiset::key\_comp](../Topic/multiset::key_comp%20\(STL-CLR\).md)`()`.  
  
 Esse objeto de delegação restrita deve impor a ordenação fraco em chaves do tipo [multiset::key\_type](../dotnet/multiset-key-type-stl-clr.md).  Isso significa que, para algumas duas chaves `X` e `Y`:  
  
 `key_comp()(X, Y)` retorna o mesmo resultado booliano em cada chamada.  
  
 Se `key_comp()(X, Y)` é true, então `key_comp()(Y, X)` deve ser false.  
  
 Se `key_comp()(X, Y)` é true, então `X` seriam ordenado antes de `Y`.  
  
 Se `!key_comp()(X, Y) && !key_comp()(Y, X)` é true, então `X` e `Y` são ditos ter ordenação equivalente.  
  
 Para qualquer elemento `X` que preceder `Y` na sequência controlada, `key_comp()(Y, X)` será false. \(Para o objeto padrão de delegação, as chaves nunca diminuem em valor.\) Ao contrário da classe [set](../dotnet/set-stl-clr.md)do modelo, um objeto da classe `multiset` do modelo não exige que as chaves para todos os elementos são exclusivos. \(Dois ou mais chaves podem ter ordenação equivalente.\)  
  
 Cada elemento serve como um ey e um valor.  A sequência é representada de forma a permitir que a pesquisa, inserir, e a remoção de um elemento com um número arbitrário de operações proporcionais ao logaritmo o número de elementos na sequência \(hora logarítmicos\).  Além disso, inserindo um elemento não invalida iteradores, e removendo um elemento invalida apenas os iteradores que apontam no elemento removido.  
  
 Um multiset oferece suporte aos iteradores bidirecionais, o que significa que você pode avançar para os elementos adjacentes um iterador dados que designa um elemento na sequência controlada.  Um nó principal especial corresponde ao iterador retornado por [multiset::end](../dotnet/multiset-end-stl-clr.md)`()`.  Você pode diminuir este iterador para alcançar o elemento o mais recente na sequência controlada, se houver.  É possível incrementar um iterador de multiset para alcançar o nó principal, e comparará no igual a `end()`.  Mas você não pode desreferenciar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento de multiset determinado diretamente a posição numérica \-\- isso requer um iterador de acesso aleatório.  
  
 Um iterador de multiset armazena um identificador para o nó associado de multiset, por sua vez que armazena um identificador para o contêiner associado.  Você pode usar iteradores apenas com seus objetos de contêiner associados.  Um iterador de multiset permanece válido desde que o nó associado de multiset é associado a um multiset.  Além disso, um iterador válido é dereferencable \-\- você pode usá\-lo para acessar ou modificar o valor do elemento que designa \-\- contanto que não é igual a `end()`.  
  
 Apagando ou removendo um elemento chama o destruidor para seu valor armazenado.  Destruir o contêiner apaga todos os elementos.  Assim, um contêiner cujo tipo de elemento é uma classe de referência garante que nenhum elemento é maior que o contêiner.  A observe, entretanto, que manipula um contêiner faz `not` destrói seus elementos.  
  
## Requisitos  
 cliext \<\/conjunto de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_map](../dotnet/hash-map-stl-clr.md)   
 [hash\_multiset](../dotnet/hash-multiset-stl-clr.md)   
 [hash\_multiset](../dotnet/hash-multiset-stl-clr.md)   
 [hash\_set](../dotnet/hash-set-stl-clr.md)   
 [map](../dotnet/map-stl-clr.md)   
 [multiset](../dotnet/multiset-stl-clr.md)   
 [set](../dotnet/set-stl-clr.md)   
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)