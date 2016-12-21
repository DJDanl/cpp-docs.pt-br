---
title: "&lt; numeric &gt; | Microsoft Docs"
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
  - "std::<numeric>"
  - "std.<numeric>"
  - "<numeric>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "cabeçalho < numeric >"
ms.assetid: 6d6ccb94-48cc-479b-b4a9-bd9c78d4896a
caps.latest.revision: 23
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt; numeric &gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define as funções de modelo de contêiner que executam algoritmos para processamento numérico.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <numeric>  
```  
  
## <a name="remarks"></a>Comentários  
 Os algoritmos se parecem com os algoritmos da STL (Biblioteca de Modelos Padrão), porém, fazem parte da Biblioteca Padrão do C++. Entretanto, eles são compatíveis com a STL e, como os algoritmos da STL, podem funcionar em uma variedade de estruturas de dados. Isso inclui classes de contêiner STL — por exemplo, [vetor](../standard-library/vector-class.md) e [lista](../standard-library/list-class.md), e estruturas de dados definido pelo programa e matrizes de elementos que atendem aos requisitos de um determinado algoritmo. Os algoritmos atingem esse nível de generalidade acessando e percorrendo os elementos de um contêiner indiretamente pelos iteradores. Os algoritmos processam intervalos de iteradores que geralmente são especificados pelas respectivas posições de início ou fim. Os intervalos referenciados devem ser válidos no sentido de que todos os ponteiros nos intervalos devem ser desreferenciáveis e dentro das sequências de cada intervalo, e a última posição deve ser acessível desde a primeira por meio de incrementação.  
  
 Os algoritmos estendem as ações que têm suporte pelas funções membro e operações de cada um dos contêineres da STL e permitem a interação com diferentes tipos de objeto de contêiner ao mesmo tempo.  
  
### <a name="functions"></a>Funções  
  
|||  
|-|-|  
|[Acumular](../Topic/%3Cnumeric%3E%20functions.md#accumulate)|Calcula a soma de todos os elementos em um intervalo especificado, incluindo qualquer valor inicial, calculando somas parciais sucessivas ou calcula o resultado de resultados parciais sucessivos que são obtidos usando uma operação binária especificada no lugar da operação de soma.|  
|[adjacent_difference](../Topic/%3Cnumeric%3E%20functions.md#adjacent_difference)|Calcula as diferenças sucessivas entre cada elemento e seu predecessor em um intervalo de entrada e gera os resultados em um intervalo de destino ou calcula o resultado de um procedimento generalizado, em que a operação de diferença é substituída por outra operação binária especificada.|  
|[inner_product](../Topic/%3Cnumeric%3E%20functions.md#inner_product)|Calcula a soma do produto em relação ao elemento de dois intervalos e a adiciona a um valor inicial especificado ou calcula o resultado de um procedimento generalizado, em que as operações de produto e a soma são substituídas por outras operações binárias especificadas.|  
|[iota](../Topic/%3Cnumeric%3E%20functions.md#iota)|Armazena um valor inicial, começando com o primeiro elemento e preenchendo com incrementos sucessivos do valor (`value++`) em cada um dos elementos no intervalo `[first, last)`.|  
|[partial_sum](../Topic/%3Cnumeric%3E%20functions.md#partial_sum)|Calcula uma série de somas em um intervalo de entrada do primeiro elemento por meio de **º elemento e armazena o resultado de cada soma no **ésimo elemento de um intervalo de destino, ou calcula o resultado de um procedimento generalizado, em que a operação de soma é substituída por outra operação binária especificada.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de modelos padrão](../misc/standard-template-library.md)

