---
title: Referência de compilador MSVC C/C++ - Visual Studio
description: Opções de conjunto de ferramentas do compilador MSVC.
ms.date: 12/10/2018
helpviewer_keywords:
- cl.exe compiler
- cl.exe compiler, setting options
ms.assetid: f3eef5ab-d0be-4fb2-90f9-927e6ed58736
ms.openlocfilehash: 2269ba69cea2702ff190c791eb6753acb3619f7d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62294142"
---
# <a name="compiling-a-cc-project"></a>Compilar um projeto C/C++

Opções de compilador C e C++ podem ser definidas no IDE do Visual Studio ou na linha de comando. 

## <a name="in-visual-studio"></a>No Visual Studio

Você pode definir opções do compilador para cada projeto no seu Visual Studio **páginas de propriedade** caixa de diálogo. No painel esquerdo, selecione **propriedades de configuração**, **C/C++** e, em seguida, escolha a categoria de opção de compilador. O tópico para cada opção de compilador descreve como ela pode ser definida e onde ela se encontra no ambiente de desenvolvimento. Ver [opções do compilador MSVC](compiler-options.md) para obter uma lista completa.

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

Para obter informações sobre como escolher a arquitetura de host e de destino do compilador, consulte [C++ configurar projetos para 64 bits, x64 destinos](../configuring-programs-for-64-bit-visual-cpp.md).

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](c-cpp-building-reference.md)
