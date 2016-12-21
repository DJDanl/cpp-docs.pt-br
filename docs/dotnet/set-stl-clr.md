---
title: "set (STL/CLR) | Microsoft Docs"
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
  - "cliext::set"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho &lt;cliext/set&gt; [STL/CLR]"
  - "Cabeçalho &lt;set&gt; [STL/CLR]"
  - "definir classe [STL/CLR]"
ms.assetid: 27d3628c-741a-43a7-bef1-5085536f679e
caps.latest.revision: 18
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# set (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um objeto que controla uma sequência de variar\- comprimento de elementos que tenha acesso bidirecional.  Você usa o contêiner `set` para gerenciar uma sequência de elementos como \(quase\) equilibrou a árvore ordenada de nós, cada um elemento armazenando.  
  
 Na descrição abaixo, `GValue` é o mesmo que `GKey`, que é por sua vez o mesmo que `Key` a menos que o último é um tipo de referência, nesse caso é `Key^`.  
  
## Sintaxe  
  
```  
template<typename Key>  
    ref class set  
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
|[set::const\_iterator](../dotnet/set-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[set::const\_reference](../dotnet/set-const-reference-stl-clr.md)|O tipo de uma referência constante para um elemento.|  
|[set::const\_reverse\_iterator](../dotnet/set-const-reverse-iterator-stl-clr.md)|O tipo de um iterador invertido constante para a sequência controlada.|  
|[set::difference\_type](../dotnet/set-difference-type-stl-clr.md)|O tipo de distância de possivelmente \(assinado\) entre dois elementos.|  
|[set::generic\_container](../dotnet/set-generic-container-stl-clr.md)|O tipo de interface genérica para o contêiner.|  
|[set::generic\_iterator](../dotnet/set-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[set::generic\_reverse\_iterator](../Topic/set::generic_reverse_iterator%20\(STL-CLR\).md)|O tipo de um iterador de cima para baixo para a interface genérica para o contêiner.|  
|[set::generic\_value](../dotnet/set-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[set::iterator](../Topic/set::iterator%20\(STL-CLR\).md)|O tipo de um iterador para a sequência controlada.|  
|[set::key\_compare](../dotnet/set-key-compare-stl-clr.md)|O delegado de ordenação para duas chaves.|  
|[set::key\_type](../dotnet/set-key-type-stl-clr.md)|O tipo de uma chave classificação.|  
|[set::reference](../dotnet/set-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[set::reverse\_iterator](../dotnet/set-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a sequência controlada.|  
|[set::size\_type](../Topic/set::size_type%20\(STL-CLR\).md)|O tipo de distância \(não negativo\) de entre dois elementos.|  
|[set::value\_compare](../Topic/set::value_compare%20\(STL-CLR\).md)|O delegado de ordenação para dois valores do elemento.|  
|[set::value\_type](../dotnet/set-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função de membro|Descrição|  
|----------------------|---------------|  
|[set::begin](../dotnet/set-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[set::clear](../Topic/set::clear%20\(STL-CLR\).md)|Remove todos os elementos.|  
|[set::count](../dotnet/set-count-stl-clr.md)|Conta os elementos que correspondem a uma chave especificada.|  
|[set::empty](../dotnet/set-empty-stl-clr.md)|Testa se nenhum elemento estiver presente.|  
|[set::end](../dotnet/set-end-stl-clr.md)|Designa o término da sequência controlada.|  
|[set::equal\_range](../dotnet/set-equal-range-stl-clr.md)|Encontra variam que corresponde a uma chave especificada.|  
|[set::erase](../Topic/set::erase%20\(STL-CLR\).md)|Remove os elementos nas posições especificadas.|  
|[set::find](../dotnet/set-find-stl-clr.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[set::insert](../Topic/set::insert%20\(STL-CLR\).md)|Adiciona os elementos.|  
|[set::key\_comp](../dotnet/set-key-comp-stl-clr.md)|Copia o representante de ordenação para duas chaves.|  
|[set::lower\_bound](../Topic/set::lower_bound%20\(STL-CLR\).md)|Localiza o início do intervalo que corresponde a uma chave especificada.|  
|[set::make\_value](../dotnet/set-make-value-stl-clr.md)|Cria um objeto de valor.|  
|[set::rbegin](../dotnet/set-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[set::rend](../dotnet/set-rend-stl-clr.md)|Designa o término da sequência controlada invertida.|  
|[set::set](../Topic/set::set%20\(STL-CLR\).md)|Cria um objeto contêiner.|  
|[set::size](../dotnet/set-size-stl-clr.md)|Conta o número de elementos.|  
|[set::swap](../dotnet/set-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[set::to\_array](../dotnet/set-to-array-stl-clr.md)|Copia a sequência controlada a uma nova matriz.|  
|[set::upper\_bound](../Topic/set::upper_bound%20\(STL-CLR\).md)|Localiza de extremidade do intervalo que corresponde a uma chave especificada.|  
|[set::value\_comp](../dotnet/set-value-comp-stl-clr.md)|Copia o representante de ordenação para dois valores do elemento.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|[set::operator\=](../dotnet/set-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[operador\!\= \(set\)](../dotnet/operator-inequality-set-stl-clr.md)|Determina se um objeto de `set` não é igual a outro objeto de `set` .|  
|[operador\< \(set\)](../dotnet/operator-less-than-set-stl-clr.md)|Determina se um objeto de `set` é menor que outro objeto de `set` .|  
|[operador\<\= \(set\)](../dotnet/operator-less-or-equal-set-stl-clr.md)|Determina se um objeto de `set` é menor ou igual a outro objeto de `set` .|  
|[operador\=\= \(set\)](../dotnet/operator-equality-set-stl-clr.md)|Determina se um objeto de `set` é igual a outro objeto de `set` .|  
|[operador\> \(set\)](../Topic/operator%3E%20\(set\)%20\(STL-CLR\).md)|Determina se um objeto de `set` é maior que outro objeto de `set` .|  
|[operador\>\= \(set\)](../dotnet/operator-greater-or-equal-set-stl-clr.md)|Determina se um objeto de `set` é maior ou igual a outro objeto de `set` .|  
  
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
  
 O objeto classifica a sequência que controla chamando um objeto armazenado delegado do tipo [set::key\_compare](../dotnet/set-key-compare-stl-clr.md).  Você pode especificar o objeto armazenado delegado quando você constrói o conjunto; se você não especificar um objeto de delegação, o padrão será a comparação `operator<(key_type, key_type)`.  Você acessa esse objeto armazenado chamando a função de membro [set::key\_comp](../dotnet/set-key-comp-stl-clr.md)`()`.  
  
 Esse objeto de delegação restrita deve impor a ordenação fraco em chaves do tipo [set::key\_type](../dotnet/set-key-type-stl-clr.md).  Isso significa que, para algumas duas chaves `X` e `Y`:  
  
 `key_comp()(X, Y)` retorna o mesmo resultado booliano em cada chamada.  
  
 Se `key_comp()(X, Y)` é true, então `key_comp()(Y, X)` deve ser false.  
  
 Se `key_comp()(X, Y)` é true, então `X` seriam ordenado antes de `Y`.  
  
 Se `!key_comp()(X, Y) && !key_comp()(Y, X)` é true, então `X` e `Y` são ditos ter ordenação equivalente.  
  
 Para qualquer elemento `X` que preceder `Y` na sequência controlada, `key_comp()(Y, X)` será false. \(Para o objeto padrão de delegação, as chaves nunca diminuem em valor.\) Ao contrário da classe [set](../dotnet/set-stl-clr.md)do modelo, um objeto da classe `set` do modelo não exige que as chaves para todos os elementos são exclusivos. \(Dois ou mais chaves podem ter ordenação equivalente.\)  
  
 Cada elemento serve como um ey e um valor.  A sequência é representada de forma a permitir que a pesquisa, inserir, e a remoção de um elemento com um número arbitrário de operações proporcionais ao logaritmo o número de elementos na sequência \(hora logarítmicos\).  Além disso, inserindo um elemento não invalida iteradores, e removendo um elemento invalida apenas os iteradores que apontam no elemento removido.  
  
 Um conjunto da suporte aos iteradores bidirecionais, o que significa que você pode avançar para os elementos adjacentes um iterador dados que designa um elemento na sequência controlada.  Um nó principal especial corresponde ao iterador retornado por [set::end](../dotnet/set-end-stl-clr.md)`()`.  Você pode diminuir este iterador para alcançar o elemento o mais recente na sequência controlada, se houver.  É possível incrementar um iterador ajustado para alcançar o nó principal, e comparará no igual a `end()`.  Mas você não pode desreferenciar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um determinado elemento definir diretamente a posição numérica \-\- isso requer um iterador de acesso aleatório.  
  
 Um iterador ajustado armazena um identificador para o nó ajustado associado, por sua vez que armazena um identificador para o contêiner associado.  Você pode usar iteradores apenas com seus objetos de contêiner associados.  Um iterador ajustado permanece válido desde que o nó do conjunto associado é associado a um conjunto.  Além disso, um iterador válido é dereferencable \-\- você pode usá\-lo para acessar ou modificar o valor do elemento que designa \-\- contanto que não é igual a `end()`.  
  
 Apagando ou removendo um elemento chama o destruidor para seu valor armazenado.  Destruir o contêiner apaga todos os elementos.  Assim, um contêiner cujo tipo de elemento é uma classe de referência garante que nenhum elemento é maior que o contêiner.  A observe, entretanto, que manipula um contêiner faz `not` destrói seus elementos.  
  
## Requisitos  
 cliext \<\/conjunto de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_map](../dotnet/hash-map-stl-clr.md)   
 [hash\_set](../dotnet/hash-set-stl-clr.md)   
 [hash\_set](../dotnet/hash-set-stl-clr.md)   
 [hash\_set](../dotnet/hash-set-stl-clr.md)   
 [map](../dotnet/map-stl-clr.md)   
 [set](../dotnet/set-stl-clr.md)   
 [set](../dotnet/set-stl-clr.md)   
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)