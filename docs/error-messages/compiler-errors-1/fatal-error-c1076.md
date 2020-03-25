---
title: Erro fatal C1076
ms.date: 03/08/2019
f1_keywords:
- C1076
helpviewer_keywords:
- C1076
ms.assetid: 84ac1180-3e8a-48e8-9f77-7f18a778b964
ms.openlocfilehash: ca5117342d406983e8cba675c2589d2431d09d38
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80204172"
---
# <a name="fatal-error-c1076"></a>Erro fatal C1076

> limite do compilador: limite do heap interno atingido; use /Zm para especificar um limite maior

Esse erro pode ser causado por muitos símbolos ou por muitas instanciações do modelo. A partir do Visual Studio 2015, essa mensagem pode resultar da pressão de memória virtual do Windows causada por muitos processos de compilação paralelos. Nesse caso, a recomendação para usar a opção **/ZM** deve ser ignorada, a menos que você esteja usando uma diretiva `#pragma hdrstop`.

Para solucionar este erro:

1. Se o cabeçalho pré-compilado usar uma diretiva `#pragma hdrstop`, use a opção [/ZM](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md) para definir o limite de memória do compilador para o valor especificado na mensagem de erro [C3859](../../error-messages/compiler-errors-2/compiler-error-c3859.md) . Para obter mais informações que incluem como definir esse valor no Visual Studio, consulte a seção comentários em [/ZM (especificar limite de alocação de memória de cabeçalho pré-compilado)](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md).

1. Considere reduzir o número de processos paralelos especificados usando a opção **/maxcpucount** para o MSBuild. EXE em conjunto com a opção **/MP** para CL. EXE. Para obter mais informações, consulte [problemas e recomendações de cabeçalho pré-compilado (PCH)](https://devblogs.microsoft.com/cppblog/precompiled-header-pch-issues-and-recommendations/).

1. Se você estiver usando os compiladores hospedados de 32 bits em um sistema operacional de 64 bits, use os compiladores hospedados de 64 bits. Para obter mais informações, consulte [como habilitar um conjunto de ferramentas do Visual C++ de 64 bits na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md).

1. Elimine arquivos de inclusão desnecessários.

1. Elimine variáveis globais desnecessárias, por exemplo, alocando memória dinamicamente em vez de declarar uma matriz grande.

1. Elimine declarações não usadas.

Se C1076 ocorrer imediatamente após o início da compilação, o valor especificado para **/ZM** provavelmente será muito alto para o seu programa. Reduza o valor de **/ZM** .
