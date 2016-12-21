---
title: "&lt;valarray&gt; | Microsoft Docs"
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
  - "std.<valarray>"
  - "valarray/std::<valarray>"
  - "std::<valarray>"
  - "<valarray>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho valarray"
ms.assetid: 30835415-21c1-4801-8f24-6bbef7dd8ecd
caps.latest.revision: 19
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;valarray&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define o valarray de classe de modelo e várias classes de modelo e de suporte funções.  
  
## Sintaxe  
  
```  
  
#include <valarray>  
  
```  
  
## Comentários  
 Essas funções e classes de modelo são permitidas latitude incomuns por razões de desempenho aprimorado.  Especificamente, qualquer tipo de retorno de função**valarray \<**T1**\>**pode retornar um objeto de outro tipo T2.  Nesse caso, qualquer função que aceita um ou mais argumentos de tipo**valarray \<**T2**\>**deve ter sobrecargas que aceitam arbitrárias combinações desses argumentos, cada substituída por um argumento do tipo T2.  
  
### Funções  
  
|||  
|-|-|  
|[abs](../Topic/abs%20\(%3Cvalarray%3E\).md)|Opera nos elementos de uma entrada valarray, retornando um valarray cujos elementos são iguais ao valor absoluto dos elementos de valarray de entrada.|  
|[acos](../Topic/acos%20\(%3Cvalarray%3E\).md)|Opera nos elementos de uma entrada valarray, retornando um valarray cujos elementos são iguais para o arco cosseno dos elementos de valarray de entrada.|  
|[asin](../Topic/asin%20\(%3Cvalarray%3E\).md)|Opera nos elementos de uma entrada valarray, retornando um valarray cujos elementos são iguais para o arco seno dos elementos de valarray de entrada.|  
|[atan](../Topic/atan%20\(%3Cvalarray%3E\).md)|Opera nos elementos de uma entrada valarray, retornando um valarray cujos elementos são iguais ao valor principal de tangente dos elementos de valarray de entrada.|  
|[atan2](../Topic/atan2%20\(%3Cvalarray%3E\).md)|Retorna um valarray cujos elementos são iguais para o arco tangente do cartesiano componentes especificados por uma combinação de constantes e elementos de valarrays.|  
|[cos](../Topic/cos%20\(%3Cvalarray%3E\).md)|Opera nos elementos de uma entrada valarray, retornando um valarray cujos elementos são iguais para o cosseno dos elementos de valarray de entrada.|  
|[cosh](../Topic/cosh%20\(%3Cvalarray%3E\).md)|Opera nos elementos de uma entrada valarray, retornando um valarray cujos elementos são iguais para o cosseno hiperbólico dos elementos de valarray de entrada.|  
|[exp](../Topic/exp%20\(%3Cvalarray%3E\).md)|Opera nos elementos de uma entrada valarray, retornando um valarray cujos elementos são iguais a natural do exponencial dos elementos de valarray de entrada.|  
|[log](../Topic/log%20\(%3Cvalarray%3E\).md)|Opera nos elementos de uma entrada valarray, retornando um valarray cujos elementos são iguais para o logaritmo natural dos elementos de valarray de entrada.|  
|[log10](../Topic/log10%20\(%3Cvalarray%3E\).md)|Opera nos elementos de uma entrada valarray, retornando um valarray cujos elementos são iguais a base 10 ou logaritmo comum dos elementos de valarray de entrada.|  
|[pow](../Topic/pow%20\(%3Cvalarray%3E\).md)|Opera nos elementos de entrada valarrays e constantes, retornando um valarray cujos elementos são iguais a uma base especificada pelos elementos de uma entrada valarray ou uma constante elevada a um expoente especificado pelos elementos de uma entrada valarray ou uma constante.|  
|[sin](../Topic/sin%20\(%3Cvalarray%3E\).md)|Opera nos elementos de uma entrada valarray, retornando um valarray cujos elementos são iguais para o seno dos elementos de valarray de entrada.|  
|[sinh](../Topic/sinh%20\(%3Cvalarray%3E\).md)|Opera nos elementos de uma entrada valarray, retornando um valarray cujos elementos são iguais para o seno hiperbólico dos elementos de valarray de entrada.|  
|[sqrt](../Topic/sqrt%20\(%3Cvalarray%3E\).md)|Opera nos elementos de uma entrada valarray, retornando um valarray cujos elementos são iguais a raiz quadrada de elementos de valarray de entrada.|  
|[swap](../Topic/swap%20\(%3Cvalarray%3E\).md)||  
|[tan](../Topic/tan%20\(%3Cvalarray%3E\).md)|Opera nos elementos de uma entrada valarray, retornando um valarray cujos elementos são iguais a tangente dos elementos de valarray de entrada.|  
|[tanh](../Topic/tanh%20\(%3Cvalarray%3E\).md)|Opera nos elementos de uma entrada valarray, retornando um valarray cujos elementos são iguais a tangente hiperbólica dos elementos de valarray de entrada.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\!\=](../Topic/operator!=%20\(%3Cvalarray%3E\).md)|Testa se os elementos correspondentes das duas valarrays tamanhos igual são diferente ou se todos os elementos de um valarray são desiguais um valor especificado do tipo de elemento do valarray.|  
|[operator%](../Topic/operator%25.md)|Obtém o resto da divisão os elementos correspondentes das duas valarrays tamanhos igual ou da divisão de um valarray por um valor especificado do tipo de elemento da valarray ou da divisão de um valor especificado por um valarray.|  
|[operator&](../Topic/operator&.md)|Obtém o bit a bit**AND**entre elementos correspondentes das duas valarrays tamanhos igual ou entre um valarray e um valor do tipo de elemento especificado.|  
|[operador & &](../Topic/operator&&.md)|Obtém a lógica**AND**entre elementos correspondentes das duas valarrays tamanhos igual ou entre um valarray e um valor especificado do tipo de elemento do valarray.|  
|[Operador \>](../Topic/operator%3E%20\(%3Cvalarray%3E\).md)|Testa se os elementos de um valarray são maiores que os elementos de um valarray de tamanho igual ou se todos os elementos de um valarray são maiores ou menores que um valor especificado do tipo de elemento do valarray.|  
|[Operador \>\=](../Topic/operator%3E=%20\(%3Cvalarray%3E\).md)|Testa se os elementos de um valarray são maiores ou iguais aos elementos de um valarray de tamanho igual ou se todos os elementos de um valarray são maiores do que ou igual a ou menor ou igual ao valor especificado.|  
|[Operador \>\>](../Topic/operator%3E%3E%20\(%3Cvalarray%3E\).md)|Os bits para cada elemento de um valarray um número especificado de posições ou por um valor em especificado por um segundo valarray de turnos de direito.|  
|[operador \<](../Topic/operator%3C%20\(%3Cvalarray%3E\).md)|Testa se os elementos de um valarray são menores do que os elementos de um valarray de tamanho igual ou se todos os elementos de um valarray são maiores ou menores que um valor especificado.|  
|[Operador \<\=](../Topic/operator%3C=%20\(%3Cvalarray%3E\).md)|Testa se os elementos de um valarray são menores ou iguais aos elementos de um valarray de tamanho igual ou se todos os elementos de um valarray são maiores do que ou igual a ou menor ou igual ao valor especificado.|  
|[Operador \<\<](../Topic/operator%3C%3C%20\(%3Cvalarray%3E\).md)|Esquerda desloca os bits para cada elemento de um valarray um número especificado de posições ou por um valor em especificado por um segundo valarray.|  
|[operator\*](../Topic/operator*%20\(%3Cvalarray%3E\).md)|Obtém o produto em entre elementos correspondentes de dois valarrays de tamanhos igual ou entre um valarray um valor especificado do tipo de elemento do valarray.|  
|[operator\+](../Topic/operator+%20\(%3Cvalarray%3E\).md)|Obtém a soma em entre elementos correspondentes de dois valarrays de tamanhos igual ou entre um valarray um valor especificado do tipo de elemento do valarray.|  
|[operator\-](../Topic/operator-%20\(%3Cvalarray%3E\)2.md)|Obtém a diferença em entre elementos correspondentes de dois valarrays de tamanhos igual ou entre um valarray um valor especificado do tipo de elemento do valarray.|  
|[operador \/](../Topic/operator-%20\(%3Cvalarray%3E\)1.md)|Obtém o quociente em entre elementos correspondentes de dois valarrays de tamanhos igual ou entre um valarray um valor especificado do tipo de elemento do valarray.|  
|[operator\=\=](../Topic/operator==%20\(%3Cvalarray%3E\).md)|Testes sejam os elementos correspondentes das duas valarrays igual tamanhos igual ou se estão todos os elementos de um valarray igual a um valor especificado do tipo de elemento do valarray.|  
|[operator^](../Topic/operator%5E.md)|Obtém o bit a bit exclusivo`OR`entre elementos correspondentes das duas valarrays tamanhos igual ou entre um valarray e um valor do tipo de elemento especificado.|  
|[operator&#124;](../Topic/operator%7C.md)|Obtém o bit a bit`OR`entre elementos correspondentes das duas valarrays tamanhos igual ou entre um valarray e um valor do tipo de elemento especificado.|  
|[Operator &#124; &#124;](../Topic/operator%7C%7C.md)|Obtém a lógica`OR`entre elementos correspondentes das duas valarrays tamanhos igual ou entre um valarray e um valor especificado do tipo de elemento do valarray.|  
  
### Classes  
  
|||  
|-|-|  
|[Classe gslice](../Topic/gslice%20Class.md)|Uma classe de utilitário para valarray é usado para definir fatias multidimensionais de um valarray.|  
|[Classe gslice\_array](../standard-library/gslice-array-class.md)|Uma classe de modelo interno, auxiliar que oferece suporte a objetos de fatia geral, fornecendo operações entre matrizes de subconjunto definidas pela fatia geral de um valarray.|  
|[Classe indirect\_array](../standard-library/indirect-array-class.md)|Uma classe de modelo interno, auxiliar que oferece suporte a objetos que são subconjuntos de valarrays fornecendo operações entre matrizes de subconjunto definidos especificando um subconjunto dos índices de valarray um pai.|  
|[Classe mask\_array](../Topic/mask_array%20Class.md)|Uma classe de modelo interno, auxiliar que oferece suporte a objetos que são subconjuntos de valarrays pai, especificado com uma expressão booleana, fornecendo operações entre as matrizes de subconjunto.|  
|[Classe slice](../Topic/slice%20Class.md)|Uma classe de utilitário para valarray é usado para definir unidimensionais, semelhante ao vetor, subconjuntos de um valarray.|  
|[Classe slice\_array](../standard-library/slice-array-class.md)|Uma classe de modelo interno, auxiliar que oferece suporte a objetos de fatia, fornecendo operações entre matrizes de subconjunto definidas pela fatia de um valarray.|  
|[Classe valarray](../standard-library/valarray-class.md)|A classe de modelo descreve um objeto que controla uma sequência de elementos do tipo**tipo**que são armazenados como uma matriz e projetado para executar operações matemáticas em alta velocidade, otimizadas para desempenho computacional.|  
  
### Especializações  
  
|||  
|-|-|  
|[valarray \< bool \> classe](../Topic/valarray%3Cbool%3E%20Class.md)|Uma versão especializada do modelo classe valarray \<**tipo**\> para elementos do tipo`bool`.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)