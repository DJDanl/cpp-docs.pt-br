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
ms.openlocfilehash: bea07361a292ee5e7cde99cedad2d5ac4c8a53aa
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32374265"
---
# <a name="compiler-options"></a>Opção de compilador

cl.exe é uma ferramenta que controla o Microsoft Visual C++ (MSVC) C e compiladores C++ e o vinculador. cl.exe pode ser executado apenas em sistemas operacionais que dão suporte ao Microsoft Visual Studio para Windows.

> [!NOTE]  
> Você pode iniciar essa ferramenta somente de um prompt de comando do Visual Studio developer. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos. Para obter mais informações, consulte [código C/C++ compilar na linha de comando](../building-on-the-command-line.md).

Os compiladores produzem arquivos de objeto (. obj) do formato de arquivo de objeto comum (COFF). O vinculador produz arquivos executáveis (.exe) ou bibliotecas de vínculo dinâmico (DLLs).

Observe que todas as opções de compilador diferenciam maiusculas de minúsculas. Você pode usar uma barra invertida (`/`) ou um traço (`-`) para especificar uma opção de compilador.

Para compilar sem vinculação, use o [/c](../../build/reference/c-compile-without-linking.md) opção.

## <a name="find-a-compiler-option"></a>Localizar uma opção de compilador

Para localizar uma opção de compilador específica, consulte uma das listas a seguir:

- [Opções do Compilador Listadas em Ordem Alfabética](../../build/reference/compiler-options-listed-alphabetically.md)

- [Opções de Compilador Listadas por Categoria](../../build/reference/compiler-options-listed-by-category.md)

## <a name="specify-compiler-options"></a>Especifique as opções do compilador

O tópico de cada opção de compilador discute como ele pode ser definido no ambiente de desenvolvimento. Para obter informações sobre como especificar opções fora do ambiente de desenvolvimento, consulte:

- [Sintaxe de linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md)

- [Arquivos de comando de CL](../../build/reference/cl-command-files.md)

- [Variáveis de ambiente de CL](../../build/reference/cl-environment-variables.md)

## <a name="related-build-tools"></a>Ferramentas de compilação relacionados

[Opções do vinculador](../../build/reference/linker-options.md) também afetam como o programa é criado.

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](../../build/reference/c-cpp-building-reference.md)  
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)  
[Compilação rápida](../../build/reference/fast-compilation.md)  
[CL invoca o vinculador](../../build/reference/cl-invokes-the-linker.md)  
