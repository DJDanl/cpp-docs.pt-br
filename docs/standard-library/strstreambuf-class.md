---
title: "Classe strstreambuf | Microsoft Docs"
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
  - "std.strstreambuf"
  - "strstreambuf"
  - "std::strstreambuf"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe strstreambuf"
ms.assetid: b040b8ea-0669-4eba-8908-6a9cc159c54b
caps.latest.revision: 25
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe strstreambuf
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um buffer de fluxo que controla a transmissão de elementos em uma sequência de elementos armazenados em uma `char` objeto array.  
  
## Sintaxe  
  
```  
  
class strstreambuf : public streambuf  
  
```  
  
## Comentários  
 Dependendo de como o objeto é construído, ele pode ser alocado, estendido e liberado conforme necessário para acomodar alterações na sequência.  
  
 Um objeto da classe `strstreambuf` armazena vários bits de informações sobre o modo como seus `strstreambuf` modo. Esses bits indicam se a sequência controlada:  
  
-   Foi alocado e precisa ser eventualmente liberado.  
  
-   Pode ser modificado.  
  
-   É extensível, realocando armazenamento.  
  
-   Foi congelada e, portanto, precisa ser descongelado antes que o objeto é destruído ou liberado \(se alocados\) por uma agência diferente do objeto.  
  
 Uma sequência controlada que é congelada não pode ser modificada ou estendida, independentemente do estado desses bits de modo separado.  
  
 O objeto também armazena ponteiros para as duas funções que controlam `strstreambuf` alocação. Se eles forem ponteiros nulos, o objeto desenvolvem seu próprio método de alocar e liberar o armazenamento para a sequência controlada.  
  
> [!NOTE]
>  Essa classe foi preterida. Considere o uso de [stringbuf](../Topic/stringbuf.md) ou [wstringbuf](../Topic/wstringbuf.md) em vez disso.  
  
### Construtores  
  
|||  
|-|-|  
|[strstreambuf](../Topic/strstreambuf::strstreambuf.md)|Constrói um objeto do tipo `strstreambuf`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[Congelamento](../Topic/strstreambuf::freeze.md)|Faz com que um buffer de fluxo para estar disponível por meio de operações de buffer de fluxo.|  
|[estouro](../Topic/strstreambuf::overflow.md)|Uma função virtual protegida que pode ser chamada quando um novo caractere é inserido em um buffer cheio.|  
|[pbackfail](../Topic/strstreambuf::pbackfail.md)|Uma função de membro virtual protegida que tenta colocar um elemento de volta no fluxo de entrada e torná\-lo o elemento atual \(apontado pelo ponteiro de próxima\).|  
|[pcount](../Topic/strstreambuf::pcount.md)|Retorna uma contagem do número de elementos escritos para a sequência controlada.|  
|[seekoff](../Topic/strstreambuf::seekoff.md)|Uma função de membro virtual protegida que tenta alterar as posições atuais para os fluxos controlados.|  
|[seekpos](../Topic/strstreambuf::seekpos.md)|Uma função de membro virtual protegida que tenta alterar as posições atuais para os fluxos controlados.|  
|[STR](../Topic/strstreambuf::str.md)|Chamadas [Congelar](../Topic/strstreambuf::freeze.md), e, em seguida, retorna um ponteiro para o início da sequência controlada.|  
|[estouro negativo](../Topic/strstreambuf::underflow.md)|Uma função virtual protegida para extrair o elemento atual do fluxo de entrada.|  
  
## Requisitos  
 **Cabeçalho:** \< strstream \>  
  
 **Namespace:** std  
  
## Consulte também  
 [streambuf](../Topic/streambuf.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)