---
title: Opções do compilador | Microsoft Docs
ms.custom: ''
ms.date: 01/29/2018
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- cl.exe compiler
- x86 Visual C++ compiler
- ARM Visual C++ compiler
- compiler options, C++
- x64 Visual C++ compiler
ms.assetid: ed3376c8-bef4-4c9a-80e9-3b5da232644c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 76ab322dc4573863a30092b296e87e90c41619ab
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45716203"
---
# <a name="compiler-options"></a>Opção de compilador

cl.exe é uma ferramenta que controla o Microsoft Visual C++ (MSVC) C e compiladores de C++ e o vinculador. cl.exe pode ser executado apenas em sistemas operacionais que dão suporte ao Microsoft Visual Studio para Windows.

> [!NOTE]
> Você pode iniciar essa ferramenta apenas de um prompt de comando do desenvolvedor de Visual Studio. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos. Para obter mais informações, consulte [código de compilação C/C++ na linha de comando](../building-on-the-command-line.md).

Os compiladores produzem arquivos de objeto (. obj) comum objeto COFF (File Format). O vinculador gera arquivos executáveis (.exe) ou bibliotecas de vínculo dinâmico (DLLs).

Observe que todas as opções de compilador diferenciam maiusculas de minúsculas. Você pode usar uma barra invertida (`/`) ou um traço (`-`) para especificar uma opção de compilador.

Para compilar sem vincular, use o [/c](../../build/reference/c-compile-without-linking.md) opção.

## <a name="find-a-compiler-option"></a>Localizar uma opção de compilador

Para localizar uma opção de compilador específica, consulte uma das seguintes listas:

- [Opções do Compilador Listadas em Ordem Alfabética](../../build/reference/compiler-options-listed-alphabetically.md)

- [Opções de Compilador Listadas por Categoria](../../build/reference/compiler-options-listed-by-category.md)

## <a name="specify-compiler-options"></a>Especificar opções do compilador

O tópico de cada opção de compilador discute como ela pode ser definida no ambiente de desenvolvimento. Para obter informações sobre como especificar opções fora do ambiente de desenvolvimento, consulte:

- [Sintaxe de linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md)

- [Arquivos de comando de CL](../../build/reference/cl-command-files.md)

- [Variáveis de ambiente de CL](../../build/reference/cl-environment-variables.md)

## <a name="related-build-tools"></a>Ferramentas de compilação relacionadas

[Opções do vinculador](../../build/reference/linker-options.md) também afetam como o seu programa é compilado.

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](../../build/reference/c-cpp-building-reference.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[Compilação rápida](../../build/reference/fast-compilation.md)<br/>
[CL invoca o vinculador](../../build/reference/cl-invokes-the-linker.md)
