---
title: Referência de pré-processador C/C++
description: Referência para o pré-processador do compilador do Microsoft C/C++ no Visual Studio.
ms.date: 09/10/2020
helpviewer_keywords:
- preprocessor
- preprocessor, reference overview
ms.assetid: e4a52843-7016-4f6d-8b40-cb1ace18f805
ms.openlocfilehash: e53f7270a71e5e7c3f456be7d55d49eaf352aecb
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90040737"
---
# <a name="cc-preprocessor-reference"></a>Referência de pré-processador C/C++

A *referência do pré-processador do C/c++* explica o pré-processador conforme ele é implementado no Microsoft C/c++. O pré-processador executa operações preliminares em arquivos do C e C++ antes de serem passados para o compilador. É possível usar o pré-processador para compilar o código condicionalmente, inserir arquivos, especificar mensagens de erro de tempo de compilação e aplicar regras de máquina específicas para seções de código.

No Visual Studio 2019, a opção de compilador [/experimental: pré-processador](../build/reference/experimental-preprocessor.md) permite uma nova implementação do pré-processador. A nova implementação ainda está em andamento e, portanto, é considerada experimental. A intenção é, eventualmente, ser compatível com C99, C11 e C++ 20. Para obter mais informações, consulte [visão geral do MSVC New pré-processador](preprocessor-experimental-overview.md).

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
