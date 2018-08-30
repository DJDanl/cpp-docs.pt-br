---
title: Visão geral da translação de arquivo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- file translation [C++], about file translation
- translation [C++]
- translation phases
- files [C++], translation
- programs [C++], lexical conventions of
- preprocessing translation phase
ms.assetid: 5036c7b7-ccff-4e2c-b052-a9ea6c71af87
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e6ef9a28af02cbb22eb4e3d2ceaad206a94d6309
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43199386"
---
# <a name="overview-of-file-translation"></a>Visão geral da translação de arquivo
Os programas C++, como os programas C, consistem em um ou mais arquivos. Cada um desses arquivos é convertido na seguinte ordem conceitual (a ordem real segue a regra “como está”: a conversão deve ocorrer como se estas etapas tivessem sido cumpridas):  
  
1. Criar tokens léxicos. O mapeamento de caracteres e o processamento trígrafo, união de linhas e de geração de tokens são executados nesta fase da conversão.  
  
2. Pré-processamento. Esta fase da conversão traz os arquivos de origem auxiliares referenciados por `#include` diretivas, lida com "stringizing" e "charizing" diretivas e executa a expansão de macro e colagem de token (consulte [diretivas do pré-processador](../preprocessor/preprocessor-directives.md) no *referência do pré-processador* para obter mais informações). O resultado da fase de pré-processamento é uma sequência de tokens que, que juntos, definem uma "unidade de conversão”.  
  
     Diretivas de pré-processador sempre começam com o sinal de número (**#**) caractere (ou seja, o primeiro caractere diferente de espaço na linha deve ser um sinal numérico). Somente uma política do pré-processador pode aparecer em uma determinada linha. Por exemplo:  
  
    ```cpp 
    #include <iostream>  // Include text of iostream in   
                         //  translation unit.  
    #define NDEBUG       // Define NDEBUG (NDEBUG contains empty   
                         //  text string).  
    ```  
  
3. Geração de código. Esta fase da conversão usa os tokens gerados na fase de pré-processamento para gerar o código do objeto.  
  
     Durante essa fase, a verificação sintática e semântica do código-fonte é executada.  
  
 Ver [fases de conversão](../preprocessor/phases-of-translation.md) na *referência de pré-processador* para obter mais informações.  
  
 O pré-processador C++ é um superconjunto estrito do pré-processador ANSI C, mas o pré-processador C++ difere em algumas instâncias. A lista a seguir descreve várias diferenças entre os pré-processadores ANSI C e C++:  
  
- Os comentários de linha única têm suporte. Ver [comentários](../cpp/comments-cpp.md) para obter mais informações.  
  
- Uma macro predefinida, `__cplusplus`, é definido somente para C++. Ver [Macros predefinidas](../preprocessor/predefined-macros.md) na *referência de pré-processador* para obter mais informações.  
  
- O pré-processador C não reconhece os operadores C++: **.** <strong>\*</strong>, **->** <strong>\*</strong>, e **::**. Ver [operadores](../cpp/cpp-built-in-operators-precedence-and-associativity.md) e [expressões](../cpp/expressions-cpp.md), para obter mais informações sobre operadores.  
  
## <a name="see-also"></a>Consulte também  
 [Convenções lexicais](../cpp/lexical-conventions.md)