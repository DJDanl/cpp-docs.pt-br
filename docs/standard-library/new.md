---
title: "&lt;new&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std::<new>"
  - "<new>"
  - "std.<new>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho new"
ms.assetid: 218e2a15-34e8-4ef3-9122-1e90eccf8559
caps.latest.revision: 18
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;new&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define vários tipos e funções que controlam a alocação e a liberação de armazenamento no controle do programa.  Ele também define componentes para relatórios de erros de gerenciamento de armazenamento.  
  
## Sintaxe  
  
```  
  
#include <new>  
  
```  
  
## Comentários  
 Algumas das funções declaradas nesse cabeçalho são substituíveis.  A implementação fornece uma versão padrão, cujo comportamento é descrito neste documento.  Um programa pode, no entanto, definir uma função com a mesma assinatura para substituir a versão padrão em tempo de vinculação.  A versão de substituição deve satisfazer os requisitos descritos neste documento.  
  
### Objetos  
  
|||  
|-|-|  
|[nothrow](../Topic/nothrow%20\(%3Cnew%3E\).md)|Fornece um objeto a ser usado como um argumento para o`nothrow`versões de**nova**e**Excluir**.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[new\_handler](../Topic/new_handler.md)|Um tipo que aponta para uma função adequada para uso como um novo manipulador.|  
  
### Funções  
  
|||  
|-|-|  
|[set\_new\_handler](../Topic/set_new_handler.md)|Instala uma função de usuário que é chamada quando novos Falha ao tentar alocar memória.|  
  
### Operadores  
  
|||  
|-|-|  
|[operador delete](../Topic/operator%20delete%20\(%3Cnew%3E\).md)|A função chamada por uma expressão de exclusão para desalocar armazenamento individual de objetos.|  
|[operador delete&#91;&#93;](../Topic/operator%20delete\(%3Cnew%3E\).md)|A função chamada por uma expressão de exclusão para desalocar o armazenamento para uma matriz de objetos.|  
|[operator new](../Topic/operator%20new%20\(%3Cnew%3E\).md)|A função chamada por uma nova expressão para alocar armazenamento para objetos individuais.|  
|[operator new&#91;&#93;](../Topic/operator%20new\(%3Cnew%3E\).md)|A função chamada por uma nova expressão para alocar armazenamento para uma matriz de objetos.|  
  
### Classes  
  
|||  
|-|-|  
|[Classe bad\_alloc](../standard-library/bad-alloc-class.md)|A classe descreve uma exceção gerada para indicar que uma solicitação de alocação não teve êxito.|  
|[Classe nothrow\_t](../standard-library/nothrow-t-structure.md)|A classe é usada como um parâmetro de função para o operador new para indicar que a função deve retornar um ponteiro nulo para relatar uma falha de alocação, em vez de lançar uma exceção.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)