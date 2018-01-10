---
title: "Diretivas de pré-processador | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- directives, preprocessor
- preprocessor, directives
ms.assetid: e0fc4564-b6cf-4a36-bf51-6ccd7abd0a94
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5d2aa241a4a5ee077bc2b69b021241f3fcfda5a0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="preprocessor-directives"></a>Diretivas de pré-processador
Diretivas de pré-processador, tais como `#define` e **#ifdef**, normalmente são usados para fazer a programas de software fácil alterar e compilar em ambientes de execução diferentes. As políticas no arquivo de origem mandam o pré-processador realizar ações específicas. Por exemplo, o pré-processador pode substituir tokens no texto, inserir o conteúdo de outros arquivos no arquivo de origem ou suprimir a compilação de parte do arquivo removendo seções de texto. As linhas do pré-processador são reconhecidas e executadas antes de expansão macro. Portanto, se uma macro se expandir até algo que se pareça com um comando do pré-processador, esse comando não será reconhecido pelo pré-processador.  
  
 As instruções do pré-processador usam o mesmo conjunto de caracteres das instruções de arquivo de origem, com exceção das sequências de escape, que não têm suporte. O conjunto de caracteres usado em instruções de pré-processador é igual a [conjunto de caracteres de execução](http://msdn.microsoft.com/en-us/a7901c61-524d-47c6-beb6-d9dacc2e72ed). O pré-processador também reconhece valores negativos de caracteres.  
  
 O pré-processador reconhece as políticas a seguir:  
  
|||||  
|-|-|-|-|  
|[#define](../preprocessor/hash-define-directive-c-cpp.md)|[#error](../preprocessor/hash-error-directive-c-cpp.md)|[#import](../preprocessor/hash-import-directive-cpp.md)|[#undef](../preprocessor/hash-undef-directive-c-cpp.md)|  
|[#elif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|[#if](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|[#include](../preprocessor/hash-include-directive-c-cpp.md)|[#using](../preprocessor/hash-using-directive-cpp.md)|  
|[#else](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|[#ifdef](../preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp.md)|[#line](../preprocessor/hash-line-directive-c-cpp.md)|[#endif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|  
|[#ifndef](../preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp.md)|[#pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)|||  
  
 O sinal de número (**#**) deve ser o primeiro caractere de espaço não brancas na linha que contém a diretiva; caracteres de espaço em branco podem aparecer entre o sinal de número e a primeira letra da diretiva. Algumas políticas incluem argumentos ou valores. Qualquer texto que segue uma diretiva (exceto um argumento ou um valor que é parte da diretiva) deve ser precedido pelo delimitador de comentário de linha única (**//**) ou colocados entre os delimitadores de comentário ( **/ \* \*/**). Linhas que contêm as diretivas de pré-processador podem ser continuadas precedendo imediatamente o marcador de fim de linha com uma barra invertida (**\\**).  
  
 As políticas do pré-processador podem aparecer em qualquer lugar do arquivo de origem, mas se aplicam somente ao restante dele.  
  
## <a name="see-also"></a>Consulte também  
 [Operadores de pré-processador](../preprocessor/preprocessor-operators.md)   
 [Macros predefinidas](../preprocessor/predefined-macros.md)   
 [Referência de pré-processador do C/C++](../preprocessor/c-cpp-preprocessor-reference.md)