---
title: "Classe duration | Microsoft Docs"
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
  - "chrono/std::chrono::duration"
dev_langs: 
  - "C++"
ms.assetid: 06b863b3-65be-4ded-a72e-6e1eb1531077
caps.latest.revision: 10
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe duration
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um tipo que contém um *intervalo de tempo*, que é um tempo decorrido entre dois pontos de tempo.  
  
## Sintaxe  
  
```  
template<  
   class Rep,  
   class Period = ratio<1>  
>  
class duration;  
template<  
   class Rep,  
   class Period  
>  
class duration;  
template<  
   class Rep,  
   class Period1,  
   class Period2  
>  
class duration  
   <duration<Rep, Period1>, Period2>;  
```  
  
## Comentários  
 O argumento de modelo `Rep` descreve o tipo que é usado para armazenar o número de marcações de clock no intervalo.  O argumento de modelo `Period` é uma instanciação de [taxa](../standard-library/ratio.md) que descreve o tamanho do intervalo que cada marcação representa.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[duration::period Typedef](http://msdn.microsoft.com/pt-br/ebf2a1b9-769f-475f-8c66-cf9ed12015f2)|Representa um sinônimo para o parâmetro de modelo `Period`.|  
|[duration::rep Typedef](http://msdn.microsoft.com/pt-br/f47b8abb-ae2c-4dc8-858a-f44695156950)|Representa um sinônimo para o parâmetro de modelo `Rep`.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor duration::duration](../Topic/duration::duration%20Constructor.md)|Constrói um objeto `duration`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método duration::count](../Topic/duration::count%20Method.md)|Retorna o número de marcações de clock no intervalo de tempo.|  
|[Método duration::max](../Topic/duration::max%20Method.md)|Estático.  Retorna o valor máximo permitido do parâmetro de modelo `Ref`.|  
|[Método duration::min](../Topic/duration::min%20Method.md)|Estático.  Retorna o menor valor permitido do parâmetro de modelo `Ref`.|  
|[Método duration::zero](../Topic/duration::zero%20Method.md)|Estático.  Aplicado, retorna `Rep`\(0\).|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador duration::operator\-](../Topic/duration::operator-%20Operator.md)|Retorna uma cópia do objeto `duration` juntamente com uma contagem negada de marcação.|  
|[Operador duration::operator\-\-](../Topic/duration::operator--%20Operator.md)|Diminui a contagem armazenada de marcação.|  
|[Operador duration::operator\=](../Topic/duration::operator=%20Operator.md)|Reduz o módulo de contagem de marcação armazenado a um valor especificado.|  
|[Operador duration::operator\*\=](../Topic/duration::operator*=%20Operator.md)|Multiplica a contagem armazenada de marcação por um valor especificado.|  
|[Operador duration::operator\/\=](../Topic/duration::operator-=%20Operator1.md)|Divide a contagem armazenada de marcação pela contagem de marcação de um objeto especificado de `duration` .|  
|[Operador duration::operator\+](../Topic/duration::operator+%20Operator.md)|Retorna `*this`.|  
|[Operador duration::operator\+\+](../Topic/duration::operator++%20Operator.md)|Aumenta a contagem armazenada de marcação.|  
|[Operador duration::operator\+\=](../Topic/duration::operator+=%20Operator.md)|Adiciona a contagem de marcação de um objeto especificado `duration` à contagem de marcação armazenada.|  
|[Operador duration::operator\-\=](../Topic/duration::operator-=%20Operator2.md)|Subtrai a contagem de marcação de um objeto de `duration` especificado da contagem de marcação armazenada.|  
  
## Requisitos  
 **Cabeçalho:** crono  
  
 **Namespace:** std::chrono  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<chrono\>](../standard-library/chrono.md)   
 [Estrutura duration\_values](../standard-library/duration-values-structure.md)