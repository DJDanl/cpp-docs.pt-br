---
title: "Classe complex | Microsoft Docs"
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
  - "complex"
  - "std::complex"
  - "std.complex"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe complex"
  - "números complexos"
ms.assetid: d6492e1c-5eba-4bc5-835b-2a88001a5868
caps.latest.revision: 18
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe complex
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um objeto que armazena dois objetos de tipo **Tipo**, um que representa a parte real de um número complexo e um que representa a parte fictícia.  
  
## Sintaxe  
  
```  
  
   template<class   
   Type  
   >  
class complex  
```  
  
## Comentários  
 Um objeto da classe **Tipo**:  
  
-   Tem um construtor, um destruidor, um construtor de impressão, e um operador de atribuição padrão públicos com comportamento convencional.  
  
-   Pode ser atribuído o inteiro ou valores de ponto flutuante, ou conversão de tipos para esses valores com comportamento convencional.  
  
-   Define os operadores aritméticos e a matemática funções, quando necessário, que é definida para os tipos de ponto flutuante com comportamento convencional.  
  
 Em particular, nenhuma diferença sutil pode existir entre a construção de cópia e a compilação da opção seguidas pela atribuição.  Nenhuma das operações em objetos da classe **Tipo** podem lançar exceções.  
  
 As especializações explícitas de classificação do modelo complexo existem para os três tipos de ponto flutuante.  Nessa implementação, um valor de qualquer outro tipo **Tipo** é typecast a **double** para cálculos reais, com o resultado de **double** atribuído de volta ao objeto armazenado do tipo **Tipo**`.`  
  
### Construtores  
  
|||  
|-|-|  
|[complexo](../Topic/complex::complex.md)|Constrói um número complexo com as partes e reais imaginárias especificadas ou como uma cópia de qualquer outro número complexo.|  
  
### Typedefs  
  
|||  
|-|-|  
|[tipo de valor](../Topic/complex::value_type.md)|Um tipo que representa o tipo de dados usado para representar as partes e reais imaginárias de um número complexo.|  
  
### Funções de membro  
  
|||  
|-|-|  
|[imag](../Topic/complex::imag.md)|Extrai o componente fictício de um número complexo.|  
|[real](../Topic/complex::real.md)|Extrai o componente real de um número complexo.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\*\=](../Topic/complex::operator*=.md)|Multiplica um número complexo de destino por um fator, que pode ser complexa ou é o mesmo tipo que são partes reais e imaginárias de número complexo.|  
|[operador\+\=](../Topic/complex::operator+=.md)|Adiciona um número em um número complexo de destino, onde o número adicionado pode ser complexa ou do mesmo tipo que são partes reais e imaginárias de número complexo ao qual ele é adicionado.|  
|[operator\-\=](../Topic/complex::operator-=1.md)|Subtrai um número de um número complexo de destino, onde o número complexo ou pode ser subtraído do mesmo tipo que são partes reais e imaginárias de número complexo ao qual ele é adicionado.|  
|[operator\/\=](../Topic/complex::operator-=2.md)|Divide um número complexo de destino por um divisor, que pode ser complexa ou é o mesmo tipo que são partes reais e imaginárias de número complexo.|  
|[operador\=](../Topic/complex::operator=.md)|Atribui um número em um número complexo de destino, onde o número atribuído pode ser complexa ou do mesmo tipo que são partes reais e imaginárias número complexo do que está sendo atribuído.|  
  
## Requisitos  
 **Cabeçalho**: \<complexo\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Membros complexos](http://msdn.microsoft.com/pt-br/d5c4466c-43a0-4817-aca1-9a5d492dae28)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)