---
title: Opções do compilador MSVC
ms.date: 05/06/2019
helpviewer_keywords:
- cl.exe compiler
- x86 MSVC compiler
- ARM MSVC compiler
- compiler options, C++
- x64 MSVC compiler
ms.assetid: ed3376c8-bef4-4c9a-80e9-3b5da232644c
ms.openlocfilehash: ab41a5de027f28b361937e58fb179fd72db54e4e
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221744"
---
# <a name="compiler-options"></a>Opção de compilador

cl.exe é uma ferramenta que controla o Microsoft C++ (MSVC) C e C++ vinculador e compiladores. cl.exe pode ser executado apenas em sistemas operacionais que dão suporte ao Microsoft Visual Studio para Windows.

> [!NOTE]
> Você pode iniciar essa ferramenta apenas de um prompt de comando do desenvolvedor de Visual Studio. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos. Para obter mais informações, consulte [usar o conjunto de ferramentas da linha de comando MSVC](../building-on-the-command-line.md).

Os compiladores produzem arquivos de objeto (. obj) comum objeto COFF (File Format). O vinculador gera arquivos executáveis (.exe) ou bibliotecas de vínculo dinâmico (DLLs).

Observe que todas as opções de compilador diferenciam maiusculas de minúsculas. Você pode usar uma barra invertida (`/`) ou um traço (`-`) para especificar uma opção de compilador.

Para compilar sem vincular, use o [/c](c-compile-without-linking.md) opção.

## <a name="find-a-compiler-option"></a>Localizar uma opção de compilador

Para localizar uma opção de compilador específica, consulte uma das seguintes listas:

- [Opções do Compilador Listadas em Ordem Alfabética](compiler-options-listed-alphabetically.md)

- [Opções de Compilador Listadas por Categoria](compiler-options-listed-by-category.md)

## <a name="specify-compiler-options"></a>Especificar opções do compilador

O tópico de cada opção de compilador discute como ela pode ser definida no ambiente de desenvolvimento. Para obter informações sobre como especificar opções fora do ambiente de desenvolvimento, consulte:

- [Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)

- [Arquivos de comando de CL](cl-command-files.md)

- [Variáveis de ambiente de CL](cl-environment-variables.md)

## <a name="related-build-tools"></a>Ferramentas de compilação relacionadas

[Opções do vinculador MSVC](linker-options.md) também afetam como o seu programa é compilado.

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](c-cpp-building-reference.md)<br/>
[CL invoca o vinculador](cl-invokes-the-linker.md)
