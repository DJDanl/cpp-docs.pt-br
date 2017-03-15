---
title: "Modelos e resolu&#231;&#227;o de nome | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
ms.assetid: 519ba7b5-cd25-4549-865a-9a7b9dffdc28
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modelos e resolu&#231;&#227;o de nome
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em definições de modelo, há três tipos de nomes.  
  
-   Nomes declarados localmente, incluindo o nome do próprio modelo e alguns nomes declarados na definição de modelo.  
  
-   Nomes de escopo delimitador fora da definição de modelo.  
  
-   Nomes que dependem de alguma forma dos argumentos do modelo, conhecidos como nomes dependentes.  
  
 Embora os primeiros dois nomes também pertençam aos escopos de classe e função, regras especiais para a resolução de nomes são necessárias nas definições de modelo para lidar com a complexidade adicional de nomes dependentes.  Isso é porque o compilador não sabe muito sobre esses nomes até que o modelo instanciado, porque podem ser tipos completamente diferentes dependendo dos argumentos de modelo usados.  Os nomes não dependentes são pesquisados de acordo com as regras comuns e no momento da definição do modelo.  Esses nomes, sendo independentes dos argumentos de modelo, são procurados uma vez para todas as especializações de modelo.  Os nomes dependentes não são pesquisados até que o modelo seja instanciado e são pesquisados separadamente para cada especialização.  
  
 Um tipo é dependente quando depende dos argumentos do modelo.  Especificamente, um tipo é dependente quando é:  
  
-   O próprio argumento do modelo:  
  
    ```  
    T  
    ```  
  
-   Um nome qualificado com uma qualificação que inclui um tipo dependente:  
  
    ```  
    T::myType  
    ```  
  
-   Um nome qualificado se a parte não qualificada identifica um tipo dependente:  
  
    ```  
    N::T  
    ```  
  
-   Um tipo const ou volatile cujo tipo de base é um tipo dependente:  
  
    ```  
    const T  
    ```  
  
-   Um ponteiro, uma referência, uma matriz, ou um tipo de ponteiro de função baseado em um tipo dependente:  
  
    ```  
    T *, T &, T [10], T (*)()  
    ```  
  
-   Uma matriz cujo tamanho é baseado em um parâmetro do modelo:  
  
    ```  
    template <int arg> class X {  
    int x[arg] ; // dependent type  
    }  
    ```  
  
-   um tipo de modelo construído de um parâmetro do modelo:  
  
    ```  
    T<int>, MyTemplate<T>  
    ```  
  
## Dependência de tipo e dependência de valor  
 Os nomes e as expressões dependentes de um parâmetro de modelo são categorizados como dependentes de tipo ou de valor, dependendo se o parâmetro de modelo for um parâmetro de tipo ou um parâmetro de valor.  Além disso, os identificadores declarados em um modelo com um tipo dependente do argumento de modelo são considerados dependentes de valor, pois é um tipo de integral ou de enumeração inicializado com uma expressão dependente de valor.  
  
 As expressões dependentes de tipo e de valor são expressões que envolvem variáveis que são dependentes de tipo ou de valor.  Essas expressões podem ter a semântica diferente, dependendo dos parâmetros usados para o modelo.  
  
## Consulte também  
 [Modelos](../Topic/Templates%20\(C++\).md)