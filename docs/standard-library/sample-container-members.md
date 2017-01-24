---
title: "Exemplos de Membros de Recipiente | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes de contêiner"
ms.assetid: dc5a1998-a31b-4adf-b888-8abe5b87a4e0
caps.latest.revision: 9
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Exemplos de Membros de Recipiente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Este tópico está na documentação do Visual C\+\+ como um exemplo nonfunctional contêineres usados na biblioteca padrão C\+\+.  Para obter mais informações, consulte [Contêineres STL](../standard-library/stl-containers.md).  
  
## Referência  
  
## Typedefs  
  
|||  
|-|-|  
|[const\_iterator](../standard-library/container-class-const-iterator.md)|Descreve um objeto que pode servir como um iterador constante para a sequência controlada.|  
|[const\_reference](../standard-library/container-class-const-reference.md)|Descreve um objeto que pode servir como uma constante referência a um elemento de sequência controlada.|  
|[const\_reverse\_iterator](../standard-library/container-class-const-reverse-iterator.md)|Descreve um objeto que pode servir como um iterador invertido constante para a sequência controlada.|  
|[difference\_type](../Topic/Container%20Class::difference_type.md)|Descreve um objeto que pode representar a diferença entre os endereços de todos os dois elementos na sequência controlada.|  
|[iterador](../standard-library/container-class-iterator.md)|Descreve um objeto que pode servir como um iterador para a sequência controlada.|  
|[referência](../Topic/Container%20Class::reference.md)|Descreve um objeto que pode servir como uma referência a um elemento de sequência controlada.|  
|[reverse\_iterator](../standard-library/container-class-reverse-iterator.md)|Descreve um objeto que pode servir como um iterador de cima para baixo para a sequência controlada.|  
|[size\_type](../standard-library/container-class-size-type.md)|Descreve um objeto que pode representar o comprimento de qualquer sequência controlada.|  
|[tipo de valor](../standard-library/container-class-value-type.md)|Atua um sinônimo para o parâmetro **Ty**do modelo.|  
  
## Funções de membro  
  
|||  
|-|-|  
|[iniciar](../standard-library/container-class-begin.md)|Retorna um iterador que aponta no primeiro elemento da sequência \(ou apenas além do de uma sequência vazia\).|  
|[limpar](../standard-library/container-class-clear.md)|Chama [erase](../standard-library/container-class-erase.md)\( [inicie](../standard-library/container-class-begin.md), [extremidade](../Topic/Container%20Class::end.md)\).|  
|[vazio](../standard-library/container-class-empty.md)|Retorna **true** para uma sequência vazia controlada.|  
|[end](../Topic/Container%20Class::end.md)|Retorna um iterador que aponta apenas além de término da sequência.|  
|[apagar](../standard-library/container-class-erase.md)|Apaga um elemento.|  
|[max\_size](../standard-library/container-class-max-size.md)|Retorna o comprimento da sequência mais longa em que o objeto pode controlar, no momento constantes independentemente do comprimento da sequência controlada.|  
|[rbegin](../Topic/Container%20Class::rbegin.md)|Retorna um iterador invertido que aponta apenas além de término da sequência, controlada por meio da designação do início da sequência inversa.|  
|[alugado](../standard-library/container-class-rend.md)|A função de membro retorna um iterador invertido que aponta no primeiro elemento da sequência \(ou apenas além do de uma sequência vazia\), designando o término da sequência inversa.|  
|[size](../standard-library/container-class-size.md)|Retorna o comprimento da sequência controlada, no momento constantes independentemente do comprimento da sequência controlada.|  
|[troca](../Topic/Container%20Class::swap.md)|Alterna entre as sequências controladas **\*this** e `_Right`.|