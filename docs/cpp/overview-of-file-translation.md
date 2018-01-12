---
title: "Visão geral da translação de arquivo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- file translation [C++], about file translation
- translation [C++]
- translation phases
- files [C++], translation
- programs [C++], lexical conventions of
- preprocessing translation phase
ms.assetid: 5036c7b7-ccff-4e2c-b052-a9ea6c71af87
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a088d2da30aa77f477f3f6e5064b6b98170e953b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="overview-of-file-translation"></a>Visão geral da translação de arquivo
Os programas C++, como os programas C, consistem em um ou mais arquivos. Cada um desses arquivos é convertido na seguinte ordem conceitual (a ordem real segue a regra “como está”: a conversão deve ocorrer como se estas etapas tivessem sido cumpridas):  
  
1.  Criar tokens léxicos. O mapeamento de caracteres e o processamento trígrafo, união de linhas e de geração de tokens são executados nesta fase da conversão.  
  
2.  Pré-processamento. Nesta fase de tradução coloca nos arquivos de origem auxiliares referenciados por `#include` diretivas, manipula "stringizing" e "caracterização" diretivas e executa a expansão de macro e colagem de token (consulte [diretivas de pré-processador](../preprocessor/preprocessor-directives.md) no *referência de pré-processador* para obter mais informações). O resultado da fase de pré-processamento é uma sequência de tokens que, que juntos, definem uma "unidade de conversão”.  
  
     Diretivas de pré-processador sempre começam com o sinal de número (**#**) caractere (isto é, o primeiro caractere de espaço não brancas na linha deve ser um sinal de número). Somente uma política do pré-processador pode aparecer em uma determinada linha. Por exemplo:  
  
    ```  
    #include <iostream>  // Include text of iostream in   
                         //  translation unit.  
    #define NDEBUG       // Define NDEBUG (NDEBUG contains empty   
                         //  text string).  
    ```  
  
3.  Geração de código. Esta fase da conversão usa os tokens gerados na fase de pré-processamento para gerar o código do objeto.  
  
     Durante essa fase, a verificação sintática e semântica do código-fonte é executada.  
  
 Consulte [fases de tradução](../preprocessor/phases-of-translation.md) no *referência de pré-processador* para obter mais informações.  
  
 O pré-processador C++ é um superconjunto estrito do pré-processador ANSI C, mas o pré-processador C++ difere em algumas instâncias. A lista a seguir descreve várias diferenças entre os pré-processadores ANSI C e C++:  
  
-   Os comentários de linha única têm suporte. Consulte [comentários](../cpp/comments-cpp.md) para obter mais informações.  
  
-   Uma macro predefinida, **cplusplus**, é definida somente para C++. Consulte [Macros predefinidas](../preprocessor/predefined-macros.md) no *referência de pré-processador* para obter mais informações.  
  
-   O pré-processador C não reconhece os operadores C++: **.\*** ,  **-> \*** , e `::`. Consulte [operadores](../cpp/cpp-built-in-operators-precedence-and-associativity.md) e [expressões](../cpp/expressions-cpp.md), para obter mais informações sobre operadores.  
  
## <a name="see-also"></a>Consulte também  
 [Convenções lexicais](../cpp/lexical-conventions.md)