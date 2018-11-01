---
title: Definindo opções do compilador
ms.date: 11/04/2016
helpviewer_keywords:
- compiler options, setting
- cl.exe compiler, setting options
ms.assetid: 4b079f5b-0017-4124-aad6-0d2b58e427e0
ms.openlocfilehash: 62a6c7913a088f9b986a09b205e4fb9bb350581a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50602183"
---
# <a name="setting-compiler-options"></a>Definindo opções do compilador

As opções de compilador C e C++ podem ser definidas no ambiente de desenvolvimento ou na linha de comando.

## <a name="in-the-development-environment"></a>No ambiente de desenvolvimento

Você pode definir opções do compilador para cada projeto na sua **páginas de propriedade** caixa de diálogo. No painel esquerdo, selecione **propriedades de configuração**, **C/C++** e, em seguida, escolha a categoria de opção de compilador. O tópico para cada opção de compilador descreve como ela pode ser definida e onde ela se encontra no ambiente de desenvolvimento. Ver [opções do compilador](../../build/reference/compiler-options.md) para obter uma lista completa.

## <a name="outside-the-development-environment"></a>Fora do ambiente de desenvolvimento

Você pode definir opções de compilador (CL.exe):

- [Na linha de comando](../../build/reference/compiler-command-line-syntax.md)

- [Em arquivos de comando](../../build/reference/cl-command-files.md)

- [Na variável de ambiente CL](../../build/reference/cl-environment-variables.md)

As opções especificadas na variável de ambiente CL são usadas cada vez que você invoca o CL. Se um arquivo de comando é nomeado na variável de ambiente CL ou na linha de comando, as opções especificadas no arquivo de comando são usadas. Em vez da linha de comando ou da variável de ambiente CL, um arquivo de comando permite que você use várias linhas de opções e nomes de arquivo.

As opções de compilador são processadas “da esquerda para a direita” e, quando um conflito é detectado, a última opção (na extrema direita) vence. A variável de ambiente CL é processada antes da linha de comando. Então, nos conflitos entre o CL e a linha de comando, a linha de comando terá precedência.

## <a name="additional-compiler-topics"></a>Tópicos adicionais de compilador

- [Compilação rápida](../../build/reference/fast-compilation.md)

- [CL invoca o vinculador](../../build/reference/cl-invokes-the-linker.md)

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](../../build/reference/c-cpp-building-reference.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)