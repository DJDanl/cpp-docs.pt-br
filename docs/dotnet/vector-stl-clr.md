---
title: "vector (STL/CLR) | Microsoft Docs"
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
  - "cliext::vector"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho &lt;cliext/vector&gt; [STL/CLR]"
  - "Cabeçalho &lt;vector&gt; [STL/CLR]"
  - "classe vector [STL/CLR]"
ms.assetid: f90060d5-097a-4e9d-9a26-a634b5b9c6c2
caps.latest.revision: 18
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# vector (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um objeto que controla uma sequência de variar\- comprimento dos elementos que tem de acesso aleatório.  Você usa o contêiner `vector` para gerenciar uma sequência de elementos como um bloco contínuo de armazenamento.  O bloco é implementado como uma matriz que cresça sob demanda.  
  
 Na descrição abaixo, `GValue` é o mesmo que `Value` a menos que o último é um tipo de referência, nesse caso é `Value^`.  
  
## Sintaxe  
  
```  
template<typename Value>  
    ref class vector  
        :   public  
        System::ICloneable,  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<GValue>,  
        System::Collections::Generic::ICollection<GValue>,  
        System::Collections::Generic::IList<GValue>,  
        Microsoft::VisualC::StlClr::IVector<GValue>  
    { ..... };  
```  
  
#### Parâmetros  
 Valor  
 O tipo de um elemento na sequência controlada.  
  
## Membros  
  
|Definição de tipo|Descrição|  
|-----------------------|---------------|  
|[vector::const\_iterator](../dotnet/vector-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[vector::const\_reference](../dotnet/vector-const-reference-stl-clr.md)|O tipo de uma referência constante para um elemento.|  
|[vector::const\_reverse\_iterator](../dotnet/vector-const-reverse-iterator-stl-clr.md)|O tipo de um iterador invertido constante para a sequência controlada.|  
|[vector::difference\_type](../dotnet/vector-difference-type-stl-clr.md)|O tipo de uma distância assinada entre dois elementos.|  
|[vector::generic\_container](../dotnet/vector-generic-container-stl-clr.md)|O tipo de interface genérica para o contêiner.|  
|[vector::generic\_iterator](../dotnet/vector-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[vector::generic\_reverse\_iterator](../Topic/vector::generic_reverse_iterator%20\(STL-CLR\).md)|O tipo de um iterador de cima para baixo para a interface genérica para o contêiner.|  
|[vector::generic\_value](../dotnet/vector-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[vector::iterator](../dotnet/vector-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[vector::reference](../dotnet/vector-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[vector::reverse\_iterator](../dotnet/vector-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a sequência controlada.|  
|[vector::size\_type](../dotnet/vector-size-type-stl-clr.md)|O tipo de uma distância assinada entre dois elementos.|  
|[vector::value\_type](../Topic/vector::value_type%20\(STL-CLR\).md)|O tipo de um elemento.|  
  
|Função de membro|Descrição|  
|----------------------|---------------|  
|[vector::assign](../Topic/vector::assign%20\(STL-CLR\).md)|Substitui todos os elementos.|  
|[vector::at](../dotnet/vector-at-stl-clr.md)|Acessa um elemento em uma posição especificada.|  
|[vector::back](../dotnet/vector-back-stl-clr.md)|Acessa o elemento pela última vez.|  
|[vector::begin](../dotnet/vector-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[vector::capacity](../dotnet/vector-capacity-stl-clr.md)|Informa o tamanho de armazenamento alocado para o contêiner.|  
|[vector::clear](../dotnet/vector-clear-stl-clr.md)|Remove todos os elementos.|  
|[vector::empty](../Topic/vector::empty%20\(STL-CLR\).md)|Testa se nenhum elemento estiver presente.|  
|[vector::end](../dotnet/vector-end-stl-clr.md)|Designa o término da sequência controlada.|  
|[vector::erase](../dotnet/vector-erase-stl-clr.md)|Remove os elementos nas posições especificadas.|  
|[vector::front](../dotnet/vector-front-stl-clr.md)|Acessa o primeiro elemento.|  
|[vector::insert](../Topic/vector::insert%20\(STL-CLR\).md)|Adiciona os elementos em uma posição especificada.|  
|[vector::pop\_back](../Topic/vector::pop_back%20\(STL-CLR\).md)|Remove o elemento pela última vez.|  
|[vector::push\_back](../dotnet/vector-push-back-stl-clr.md)|Adiciona um novo elemento a última vez.|  
|[vector::rbegin](../dotnet/vector-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[vector::rend](../dotnet/vector-rend-stl-clr.md)|Designa o término da sequência controlada invertida.|  
|[vector::reserve](../Topic/vector::reserve%20\(STL-CLR\).md)|Garante que uma capacidade mínima de crescimento do contêiner.|  
|[vector::resize](../Topic/vector::resize%20\(STL-CLR\).md)|Altera o número de elementos.|  
|[vector::size](../dotnet/vector-size-stl-clr.md)|Conta o número de elementos.|  
|[vector::swap](../dotnet/vector-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[vector::to\_array](../dotnet/vector-to-array-stl-clr.md)|Copia a sequência controlada a uma nova matriz.|  
|[vector::vector](../dotnet/vector-vector-stl-clr.md)|Cria um objeto contêiner.|  
  
|Propriedade|Descrição|  
|-----------------|---------------|  
|[vector::back\_item](../dotnet/vector-back-item-stl-clr.md)|Acessa o elemento pela última vez.|  
|[vector::front\_item](../dotnet/vector-front-item-stl-clr.md)|Acessa o primeiro elemento.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|[vector::operator\=](../dotnet/vector-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[vector::operator](../dotnet/vector-operator-stl-clr.md)|Acessa um elemento em uma posição especificada.|  
|[operador\!\= \(vector\)](../Topic/operator!=%20\(vector\)%20\(STL-CLR\).md)|Determina se um objeto de `vector` não é igual a outro objeto de `vector` .|  
|[operador\< \(vector\)](../dotnet/operator-less-than-vector-stl-clr.md)|Determina se um objeto de `vector` é menor que outro objeto de `vector` .|  
|[operador\<\= \(vector\)](../dotnet/operator-less-or-equal-vector-stl-clr.md)|Determina se um objeto de `vector` é menor ou igual a outro objeto de `vector` .|  
|[operador\=\= \(vector\)](../Topic/operator==%20\(vector\)%20\(STL-CLR\).md)|Determina se um objeto de `vector` é igual a outro objeto de `vector` .|  
|[operador\> \(vector\)](../dotnet/operator-greater-than-vector-stl-clr.md)|Determina se um objeto de `vector` é maior que outro objeto de `vector` .|  
|[operador\>\= \(vector\) \(STL\/CLR\)](../Topic/operator%3E=%20\(vector\)%20\(STL-CLR\).md)|Determina se um objeto de `vector` é maior ou igual a outro objeto de `vector` .|  
  
## Interfaces  
  
|Interface|Descrição|  
|---------------|---------------|  
|<xref:System.ICloneable>|Duplica um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência por meio dos elementos.|  
|<xref:System.Collections.ICollection>|Mantenha o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência por meio dos elementos digitados.|  
|<xref:System.Collections.Generic.ICollection%601>|Mantenha o grupo de elementos de tipo.|  
|<xref:System.Collections.Generic.IList%601>|Manter ordenou o grupo de elementos de tipo.|  
|IVectorValue\<\>|Mantenha o contêiner genérico.|  
  
## Comentários  
 O objeto aloca e libera armazenamento para a sequência que controla armazenada com uma matriz de elementos de `Value` , que cresça sob demanda.  O crescimento ocorre de forma que o custo de acrescentar um novo elemento são amortizados tempo constantes.  Ou é o custo de adicionar elementos na extremidade não aumentam, em média, porque o comprimento da sequência controlada obtém maior.  Assim, um vetor é uma boa candidata para o contêiner subjacente da classe [stack](../dotnet/stack-stl-clr.md)do modelo.  
  
 `vector` oferece suporte aos iteradores de acesso aleatório, que significa você pode recorrer a um determinado elemento diretamente a posição numérica, contando de zero do primeiro elemento \(\) para a frente, a [vector::size](../dotnet/vector-size-stl-clr.md)`() - 1` para o elemento \(\) na última vez.  Isso também significa que um vetor é uma boa candidata para o contêiner subjacente da classe [priority\_queue](../Topic/priority_queue%20\(STL-CLR\).md)do modelo.  
  
 Um iterador de vetor armazena um identificador para o objeto associado de vetor, junto com a diferença que designa do elemento.  Você pode usar iteradores apenas com seus objetos de contêiner associados.  A diferença de um elemento de vetor é a mesma que sua posição.  
  
 Inserir ou apagar os elementos podem alterar o valor do elemento armazenado em uma posição especificada, assim o valor designado por um iterador também pode ser alterada. \(O contêiner pode ter que copiar para cima ou para baixo nos elementos para criar um orifício antes de uma inserção ou para preencher um orifício depois de um erase.\) Entretanto, um iterador de vetor permanece válido desde que a diferença está no intervalo `[0,` [vector::size](../dotnet/vector-size-stl-clr.md)`()]`.  Além disso, um iterador permanece válido dereferencable \-\- você pode usá\-lo para acessar ou modificar o valor do elemento que designa \-\- desde que a tendência não é igual a `size()`.  
  
 Apagando ou removendo um elemento chama o destruidor para seu valor armazenado.  Destruir o contêiner apaga todos os elementos.  Assim, um contêiner cujo tipo de elemento é uma classe de referência garante que nenhum elemento é maior que o contêiner.  A observe, entretanto, que manipula um contêiner faz `not` destrói seus elementos.  
  
## Requisitos  
 cliext \<\/vetor de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [deque](../dotnet/deque-stl-clr.md)   
 [list](../dotnet/list-stl-clr.md)   
 [priority\_queue](../Topic/priority_queue%20\(STL-CLR\).md)   
 [queue](../Topic/queue%20\(STL-CLR\).md)   
 [stack](../dotnet/stack-stl-clr.md)   
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)