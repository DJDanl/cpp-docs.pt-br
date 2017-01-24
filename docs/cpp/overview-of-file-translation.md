---
title: "Vis&#227;o geral da transla&#231;&#227;o de arquivo | Microsoft Docs"
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
helpviewer_keywords: 
  - "tradução de arquivo [C++], sobre tradução de arquivo"
  - "Arquivos  [C++], tradução"
  - "pré-processando fase de tradução"
  - "programas [C++], convenções lexicais de"
  - "tradução [C++]"
  - "fases de tradução"
ms.assetid: 5036c7b7-ccff-4e2c-b052-a9ea6c71af87
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vis&#227;o geral da transla&#231;&#227;o de arquivo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os programas C\+\+, como os programas C, consistem em um ou mais arquivos.  Cada um desses arquivos é convertido na seguinte ordem conceitual \(a ordem real segue a regra “como está”: a conversão deve ocorrer como se estas etapas tivessem sido cumpridas\):  
  
1.  Criar tokens léxicos.  O mapeamento de caracteres e o processamento trígrafo, união de linhas e de geração de tokens são executados nesta fase da conversão.  
  
2.  Pré\-processamento.  Esta fase da conversão traz os arquivos de origem auxiliares referenciados pelas políticas `#include`, lida com as políticas "stringizing” e "charizing”, e executa a colagem de tokens e a expansão de macros \(consulte [Diretivas do pré\-processador](../preprocessor/preprocessor-directives.md) na *Referência do pré\-processador* para obter mais informações\).  O resultado da fase de pré\-processamento é uma sequência de tokens que, que juntos, definem uma "unidade de conversão”.  
  
     As políticas do pré\-processador sempre começam com o caractere de sinal numérico \(**\#**\) \(isto é, o primeiro caractere não de espaço em branco na linha deve ser um sinal numérico\).  Somente uma política do pré\-processador pode aparecer em uma determinada linha.  Por exemplo:  
  
    ```  
    #include <iostream>  // Include text of iostream in   
                         //  translation unit.  
    #define NDEBUG       // Define NDEBUG (NDEBUG contains empty   
                         //  text string).  
    ```  
  
3.  Geração de código.  Esta fase da conversão usa os tokens gerados na fase de pré\-processamento para gerar o código do objeto.  
  
     Durante essa fase, a verificação sintática e semântica do código\-fonte é executada.  
  
 Consulte [Fases de conversão](../preprocessor/phases-of-translation.md) na *Referência do pré\-processador* para obter mais informações.  
  
 O pré\-processador C\+\+ é um superconjunto estrito do pré\-processador ANSI C, mas o pré\-processador C\+\+ difere em algumas instâncias.  A lista a seguir descreve várias diferenças entre os pré\-processadores ANSI C e C\+\+:  
  
-   Os comentários de linha única têm suporte.  Consulte [Comentários](../cpp/comments-cpp.md) para obter mais informações.  
  
-   Uma macro predefinida, **\_\_cplusplus**, é definida somente para C\+\+.  Consulte [Macros predefinidas](../preprocessor/predefined-macros.md) na *Referência do pré\-processador* para obter mais informações.  
  
-   O pré\-processador C não reconhece os operadores C\+\+: **.\***, **–\>\*** e `::`.  Consulte [Operadores](../cpp/cpp-built-in-operators-precedence-and-associativity.md) e [Expressões](../cpp/expressions-cpp.md) para obter mais informações sobre operadores.  
  
## Consulte também  
 [Convenções lexicais](../cpp/lexical-conventions.md)