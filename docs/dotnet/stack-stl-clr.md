---
title: "stack (STL/CLR) | Microsoft Docs"
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
  - "cliext::stack"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho &lt;cliext/stack&gt; [STL/CLR]"
  - "Cabeçalho &lt;stack&gt; [STL/CLR]"
  - "classe de pilha [STL/CLR]"
ms.assetid: 6ee96b9f-8a33-4cf7-b7e0-6535c24bdefb
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# stack (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um objeto que controla uma sequência de variar\- comprimento dos elementos com último no primeiro em expansão acesso.  Você usa o adaptador `stack` do contêiner para gerenciar um contêiner subjacente como uma pilha de envio \- para baixo.  
  
 Na descrição abaixo, `GValue` é o mesmo que `Value` a menos que o último é um tipo de referência, nesse caso é `Value^`.  Da mesma forma, `GContainer` é o mesmo que `Container` a menos que o último é um tipo de referência, nesse caso é `Container^`.  
  
## Sintaxe  
  
```  
template<typename Value,  
    typename Container>  
    ref class stack  
        :   public  
        System::ICloneable,  
        Microsoft::VisualC::StlClr::IStack<GValue, GContainer>  
    { ..... };  
```  
  
#### Parâmetros  
 Valor  
 O tipo de um elemento na sequência controlada.  
  
 Contêiner  
 O tipo de contêiner subjacente.  
  
## Membros  
  
|Definição de tipo|Descrição|  
|-----------------------|---------------|  
|[stack::const\_reference](../dotnet/stack-const-reference-stl-clr.md)|O tipo de uma referência constante para um elemento.|  
|[stack::container\_type](../dotnet/stack-container-type-stl-clr.md)|O tipo de contêiner subjacente.|  
|[stack::difference\_type](../dotnet/stack-difference-type-stl-clr.md)|O tipo de uma distância assinada entre dois elementos.|  
|[stack::generic\_container](../Topic/stack::generic_container%20\(STL-CLR\).md)|O tipo de interface genérica para o adaptador do contêiner.|  
|[stack::generic\_value](../dotnet/stack-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o adaptador do contêiner.|  
|[stack::reference](../dotnet/stack-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[stack::size\_type](../dotnet/stack-size-type-stl-clr.md)|O tipo de uma distância assinada entre dois elementos.|  
|[stack::value\_type](../dotnet/stack-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função de membro|Descrição|  
|----------------------|---------------|  
|[stack::assign](../Topic/stack::assign%20\(STL-CLR\).md)|Substitui todos os elementos.|  
|[stack::empty](../dotnet/stack-empty-stl-clr.md)|Testa se nenhum elemento estiver presente.|  
|[stack::get\_container](../Topic/stack::get_container%20\(STL-CLR\).md)|Acessa o contêiner subjacente.|  
|[stack::pop](../Topic/stack::pop%20\(STL-CLR\).md)|Remove o elemento pela última vez.|  
|[stack::push \(STL\/CLR\)](../dotnet/stack-push-stl-clr.md)|Adiciona um novo elemento a última vez.|  
|[stack::size](../dotnet/stack-size-stl-clr.md)|Conta o número de elementos.|  
|[stack::stack](../dotnet/stack-stack-stl-clr.md)|Cria um objeto contêiner.|  
|[stack::top](../dotnet/stack-top-stl-clr.md)|Acessa o elemento pela última vez.|  
|[stack::to\_array](../dotnet/stack-to-array-stl-clr.md)|Copia a sequência controlada a uma nova matriz.|  
  
|Propriedade|Descrição|  
|-----------------|---------------|  
|[stack::top\_item](../dotnet/stack-top-item-stl-clr.md)|Acessa o elemento pela última vez.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|[stack::operator\=](../dotnet/stack-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[operador\!\= \(stack\)](../dotnet/operator-inequality-stack-stl-clr.md)|Determina se um objeto de `stack` não é igual a outro objeto de `stack` .|  
|[operador\< \(stack\)](../dotnet/operator-less-than-stack-stl-clr.md)|Determina se um objeto de `stack` é menor que outro objeto de `stack` .|  
|[operador\<\= \(stack\)](../dotnet/operator-less-or-equal-stack-stl-clr.md)|Determina se um objeto de `stack` é menor ou igual a outro objeto de `stack` .|  
|[operador\=\= \(stack\)](../dotnet/operator-equality-stack-stl-clr.md)|Determina se um objeto de `stack` é igual a outro objeto de `stack` .|  
|[operador\> \(stack\)](../dotnet/operator-greater-than-stack-stl-clr.md)|Determina se um objeto de `stack` é maior que outro objeto de `stack` .|  
|[operador\>\= \(stack\)](../Topic/operator%3E=%20\(stack\)%20\(STL-CLR\).md)|Determina se um objeto de `stack` é maior ou igual a outro objeto de `stack` .|  
  
## Interfaces  
  
|Interface|Descrição|  
|---------------|---------------|  
|<xref:System.ICloneable>|Duplica um objeto.|  
|IStackValue\<, contêineres\>|Mantenha o adaptador genérico do contêiner.|  
  
## Comentários  
 O objeto aloca e libera armazenamento para a sequência que controla por meio de um contêiner subjacente, o tipo `Container`, que armazena os elementos de `Value` e cresce sob demanda.  O objeto restringe o acesso ao envio por push e a aparecer apenas o elemento o último, implementando a última na primeira em expansão fila \(também conhecida como uma fila de LIFO, ou a pilha\).  
  
## Requisitos  
 cliext \<\/pilha de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [deque](../dotnet/deque-stl-clr.md)   
 [list](../dotnet/list-stl-clr.md)   
 [priority\_queue](../Topic/priority_queue%20\(STL-CLR\).md)   
 [queue](../Topic/queue%20\(STL-CLR\).md)   
 [vector](../dotnet/vector-stl-clr.md)   
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)