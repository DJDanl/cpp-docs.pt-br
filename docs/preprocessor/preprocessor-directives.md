---
title: Diretivas do pré-processador
ms.date: 08/29/2019
helpviewer_keywords:
- directives, preprocessor
- preprocessor, directives
ms.assetid: e0fc4564-b6cf-4a36-bf51-6ccd7abd0a94
ms.openlocfilehash: 86432ebf210523dd958f3258075d9e9c6d3bb4e6
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222268"
---
# <a name="preprocessor-directives"></a>Diretivas do pré-processador

As `#define` diretivas de pré-processador, como e `#ifdef`, são normalmente usadas para facilitar a alteração dos programas de origem e a sua compilação em ambientes de execução diferentes. As diretivas no arquivo de origem informam o pré-processador para executar ações específicas. Por exemplo, o pré-processador pode substituir tokens no texto, inserir o conteúdo de outros arquivos no arquivo de origem ou suprimir a compilação de parte do arquivo removendo seções de texto. As linhas do pré-processador são reconhecidas e executadas antes de expansão macro. Portanto, se uma macro se expandir em algo parecido com um comando de pré-processador, ela não será reconhecida pelo pré-processador.

As instruções de pré-processador usam o mesmo conjunto de caracteres que as instruções do arquivo de origem, com a exceção de que as sequências de escape não têm suporte. O conjunto de caracteres usado em instruções do pré-processador é igual ao conjunto de caracteres de execução. O pré-processador também reconhece valores negativos de caracteres.

O pré-processador reconhece as políticas a seguir:

|||||
|-|-|-|-|
|[#define](../preprocessor/hash-define-directive-c-cpp.md)|[#error](../preprocessor/hash-error-directive-c-cpp.md)|[#import](../preprocessor/hash-import-directive-cpp.md)|[#undef](../preprocessor/hash-undef-directive-c-cpp.md)|
|[#elif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|[#if](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|[#include](../preprocessor/hash-include-directive-c-cpp.md)|[#using](../preprocessor/hash-using-directive-cpp.md)|
|[#else](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|[#ifdef](../preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp.md)|[#line](../preprocessor/hash-line-directive-c-cpp.md)|[#endif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|
|[#ifndef](../preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp.md)|[#pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)|||

O sinal de número`#`() deve ser o primeiro caractere que não seja de espaço em branco na linha que contém a diretiva. Caracteres de espaço em branco podem aparecer entre o sinal numérico e a primeira letra da diretiva. Algumas políticas incluem argumentos ou valores. Qualquer texto que segue uma diretiva (exceto um argumento ou valor que faça parte da diretiva) deve ser precedido pelo delimitador de comentário de linha única`//`() ou colocado em delimitadores de`/* */`comentário (). As linhas que contêm diretivas de pré-processador podem ser continuadas imediatamente antes do marcador de fim de linha com uma barra invertida`\`().

As diretivas de pré-processador podem aparecer em qualquer lugar em um arquivo de origem, mas se aplicam somente ao restante do arquivo de origem, depois de aparecerem.

## <a name="see-also"></a>Consulte também

[Operadores de pré-processador](../preprocessor/preprocessor-operators.md)\
[Macros predefinidas](../preprocessor/predefined-macros.md)\
[referência de pré-processador do c/c++](../preprocessor/c-cpp-preprocessor-reference.md)
