---
title: "Classe index | Microsoft Docs"
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
  - "amp/Concurrency::index"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura index"
ms.assetid: cbe79b08-0ba7-474c-9828-f1a71da39eb3
caps.latest.revision: 20
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe index
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Define um ponto de índice *N* dimensional.  
  
## Sintaxe  
  
```  
template <  
   int _Rank  
>  
class index;  
```  
  
#### Parâmetros  
 `_Rank`  
 A classificação, ou número de dimensões.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor index::index](../Topic/index::index%20Constructor.md)|Inicializa uma nova instância da classe `index`.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador index::operator\-\-](../Topic/index::operator--%20Operator.md)|Decrementa cada elemento do objeto `index`.|  
|[Operador index::operator\(mod\)\=](../Topic/index::operator\(mod\)=%20Operator.md)|Calcula o módulo \(resto\) de cada elemento no objeto `index` quando esse elemento é dividido por um número.|  
|[Operador index::operator\*\=](../Topic/index::operator*=%20Operator.md)|Multiplica cada elemento do objeto `index` por um número.|  
|[Operador index::operator\/\=](../Topic/index::operator-=%20Operator2.md)|Divide cada elemento do objeto `index` por um número.|  
|[Operador index::operator](../Topic/index::operatorOperator.md)|Retorna o elemento que está no índice especificado.|  
|[Operador index::operator\+\+](../Topic/index::operator++%20Operator.md)|Incrementa cada elemento do objeto `index`.|  
|[Operador index::operator\+\=](../Topic/index::operator+=%20Operator.md)|Adiciona o número especificado a cada elemento do objeto `index`.|  
|[Operador index::operator\=](../Topic/index::operator=%20Operator.md)|Copia o conteúdo do objeto `index` especificado para esse outro.|  
|[Operador index::operator\-\=](../Topic/index::operator-=%20Operator1.md)|Subtrai o número especificado de cada elemento do objeto `index`.|  
  
### Constantes públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Constante index::rank](../Topic/index::rank%20Constant.md)|Armazena a classificação do objeto `index`.|  
  
## Hierarquia de Herança  
 `index`  
  
## Comentários  
 A estrutura `index` representa um vetor de coordenadas de *N* inteiros que especifica uma posição única em um espaço *N* dimensional.  Os valores no vetor são ordenados do mais significativo para o menos significativo.  Você pode recuperar os valores dos componentes usando [Operador index::operator\=](../Topic/index::operator=%20Operator.md).  
  
## Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  
  
## Consulte também  
 [Namespace Concurrency \(C\+\+ AMP\)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)