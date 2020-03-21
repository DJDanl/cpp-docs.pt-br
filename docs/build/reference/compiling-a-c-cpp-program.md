---
title: MSVC C/C++ referência do compilador-Visual Studio
description: Opções do conjunto de ferramentas do compilador MSVC.
ms.date: 12/10/2018
helpviewer_keywords:
- cl.exe compiler
- cl.exe compiler, setting options
ms.assetid: f3eef5ab-d0be-4fb2-90f9-927e6ed58736
ms.openlocfilehash: c75176b139895d7b00d88aca1c58604b47386894
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80077375"
---
# <a name="compiling-a-cc-project"></a>Compilando um CC++ /projeto

As opções C++ de compilador e C podem ser definidas no IDE do Visual Studio ou na linha de comando.

## <a name="in-visual-studio"></a>No Visual Studio

Você pode definir opções de compilador para cada projeto em sua caixa de diálogo **páginas de propriedades** do Visual Studio. No painel esquerdo, selecione **Propriedades de configuração**, **C/C++**  e, em seguida, escolha a categoria de opção do compilador. O tópico para cada opção de compilador descreve como ela pode ser definida e onde ela se encontra no ambiente de desenvolvimento. Consulte [Opções do compilador MSVC](compiler-options.md) para obter uma lista completa.

## <a name="from-the-command-line"></a>Na linha de comando

Você pode definir opções de compilador (CL.exe):

- [Na linha de comando](compiler-command-line-syntax.md)

- [Em arquivos de comando](cl-command-files.md)

- [Na variável de ambiente CL](cl-environment-variables.md)

As opções especificadas na variável de ambiente CL são usadas cada vez que você invoca o CL. Se um arquivo de comando é nomeado na variável de ambiente CL ou na linha de comando, as opções especificadas no arquivo de comando são usadas. Em vez da linha de comando ou da variável de ambiente CL, um arquivo de comando permite que você use várias linhas de opções e nomes de arquivo.

As opções de compilador são processadas “da esquerda para a direita” e, quando um conflito é detectado, a última opção (na extrema direita) vence. A variável de ambiente CL é processada antes da linha de comando. Então, nos conflitos entre o CL e a linha de comando, a linha de comando terá precedência.

## <a name="additional-compiler-topics"></a>Tópicos adicionais de compilador

- [Opções do compilador MSVC](compiler-options.md)

- [Arquivos de cabeçalho pré-compilado](../creating-precompiled-header-files.md)

- [CL invoca o vinculador](cl-invokes-the-linker.md)

Para obter informações sobre como escolher o host do compilador e a arquitetura de destino, consulte [Configurar C++ projetos para destinos de 64 bits e x64](../configuring-programs-for-64-bit-visual-cpp.md).

## <a name="see-also"></a>Confira também

[Referência de compilação C/C++](c-cpp-building-reference.md)
