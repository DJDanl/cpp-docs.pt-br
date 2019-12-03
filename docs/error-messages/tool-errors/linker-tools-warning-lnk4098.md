---
title: Aviso LNK4098 (Ferramentas de Vinculador)
description: Descreve como as bibliotecas incompatíveis causam o aviso das ferramentas do vinculador LNK4098 e como usar o/NODEFAULTLIB para corrigi-lo.
ms.date: 12/02/2019
f1_keywords:
- LNK4098
helpviewer_keywords:
- LNK4098
ms.assetid: 1f1b1408-1316-4e34-80f5-6a02f2db0ac1
ms.openlocfilehash: 9d0c7da0614651a98d5ed4f3bd3676c7d837ce67
ms.sourcegitcommit: d0504e2337bb671e78ec6dd1c7b05d89e7adf6a7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/02/2019
ms.locfileid: "74682938"
---
# <a name="linker-tools-warning-lnk4098"></a>Aviso LNK4098 (Ferramentas de Vinculador)

> defaultlib '*library*' está em conflito com o uso de outros bibliotecas; usar/NODEFAULTLIB:*biblioteca*

Você está tentando vincular com bibliotecas incompatíveis.

> [!NOTE]
> As bibliotecas de tempo de execução agora contêm diretivas para evitar a mistura de tipos diferentes. Você receberá esse aviso se tentar usar diferentes tipos ou versões de depuração e não depurar da biblioteca de tempo de execução no mesmo programa. Por exemplo, se você compilou um arquivo para usar um tipo de biblioteca de tempo de execução e outro arquivo para usar outro tipo (por exemplo, depurar versus varejo) e tentar vinculá-los, você receberá esse aviso. Você deve compilar todos os arquivos de origem para usar a mesma biblioteca de tempo de execução. Para obter mais informações, consulte Opções do compilador [/MD,/MT,/LD (use a biblioteca de tempo de execução)](../../build/reference/md-mt-ld-use-run-time-library.md) .

Você pode usar a opção [/verbose: lib](../../build/reference/verbose-print-progress-messages.md) do vinculador para descobrir quais bibliotecas o vinculador pesquisa. Por exemplo, quando o executável usa as bibliotecas de tempo de execução multithreaded e não-Debug, a lista relatada deve incluir LIBCMT. lib, e não LIBCMTD. lib, MSVCRT. lib ou MSVCRTD. lib. Você pode dizer ao vinculador para ignorar as bibliotecas de tempo de execução incorretas usando [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) para cada biblioteca que você deseja ignorar.

A tabela a seguir mostra quais bibliotecas devem ser ignoradas dependendo de qual biblioteca de tempo de execução você deseja usar. Na linha de comando, use uma opção **/NODEFAULTLIB** para cada biblioteca a ser ignorada. No IDE do Visual Studio, separe as bibliotecas a serem ignoradas por ponto e vírgula na propriedade **Ignorar bibliotecas padrão específicas** .

| Para usar esta biblioteca de tempo de execução | Ignorar essas bibliotecas |
|-----------------------------------|----------------------------|
| Multi-threaded (LIBCMT. lib) | msvcrt. lib; LIBCMTD. lib; MSVCRTD. lib |
| Multithread usando DLL (msvcrt. lib) | LIBCMT. lib; LIBCMTD. lib; MSVCRTD. lib |
| Depurar multithreaded (LIBCMTD. lib) | LIBCMT. lib; msvcrt. lib; MSVCRTD. lib |
| Depurar multithread usando DLL (MSVCRTD. lib) | LIBCMT. lib; msvcrt. lib; LIBCMTD. lib |

Por exemplo, se você recebeu esse aviso e deseja criar um arquivo executável que usa a versão de DLL que não é de depuração das bibliotecas de tempo de execução, poderá usar as seguintes opções com o vinculador:

```cmd
/NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrtd.lib
```
