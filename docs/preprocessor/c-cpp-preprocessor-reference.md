---
title: Referência de pré-processador C/C++
description: Referência para o pré-processador do compilador do Microsoft C/C++ no Visual Studio.
ms.date: 09/10/2020
helpviewer_keywords:
- preprocessor
- preprocessor, reference overview
ms.assetid: e4a52843-7016-4f6d-8b40-cb1ace18f805
ms.openlocfilehash: e72146d8b88f5a4bffcaaa121f6851d740ec948b
ms.sourcegitcommit: b492516cc65120250b9ea23f96f7f63f37f99fae
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/14/2020
ms.locfileid: "90075628"
---
# <a name="cc-preprocessor-reference"></a>Referência de pré-processador C/C++

A *referência do pré-processador do C/c++* explica o pré-processador conforme ele é implementado no Microsoft C/c++. O pré-processador executa operações preliminares em arquivos do C e C++ antes de serem passados para o compilador. É possível usar o pré-processador para compilar o código condicionalmente, inserir arquivos, especificar mensagens de erro de tempo de compilação e aplicar regras de máquina específicas para seções de código.

No Visual Studio 2019, a opção de compilador [/Zc: pré-processador](../build/reference/zc-preprocessor.md) fornece um pré-processamento totalmente compatível e um pré-processador C17. Esse é o padrão quando você usa o sinalizador do compilador `/std:c11` ou `/std:c17` .

## <a name="in-this-section"></a>Nesta seção

[Pré-processador](preprocessor.md)\
Fornece uma visão geral dos pré-processadores de conformidade tradicionais e novos.

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)\
Descreve as políticas, normalmente usadas para tornar os programas de origem fáceis de alterar e de compilar em ambientes de execução diferentes.

[Operadores de pré-processador](../preprocessor/preprocessor-operators.md)\
Discute os quatro operadores específicos de pré-processadores usados no contexto da política `#define`.

[Macros predefinidas](../preprocessor/predefined-macros.md)\
Discute macros predefinidas conforme especificado pelos padrões C e C++ e pelo Microsoft C++.

[Pragmas](../preprocessor/pragma-directives-and-the-pragma-keyword.md)\
Discute pragmas, que proporcionam uma maneira para que cada compilador ofereça recursos específicos de máquinas e sistemas operacionais enquanto mantém a compatibilidade geral com as linguagens C e C++.

## <a name="related-sections"></a>Seções relacionadas

[Referência da linguagem C++](../cpp/cpp-language-reference.md)\
Fornece o material de referência para a implementação da Microsoft da linguagem C++.

[Referência da linguagem C](../c-language/c-language-reference.md)\
Fornece o material de referência para a implementação da Microsoft da linguagem C.

[Referência de Build do C/C++](../build/reference/c-cpp-building-reference.md)\
Fornece links para tópicos que discutem opções de compilador e de vinculador.

[Projetos do Visual Studio – C++](../build/creating-and-managing-visual-cpp-projects.md)\
Descreve a interface do usuário no Visual Studio que permite especificar os diretórios que o sistema do projeto procurará para localizar arquivos para o seu projeto do C++.
