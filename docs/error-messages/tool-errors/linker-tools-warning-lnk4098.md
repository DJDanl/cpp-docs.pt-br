---
title: Aviso LNK4098 (Ferramentas de Vinculador)
ms.date: 03/26/2019
f1_keywords:
- LNK4098
helpviewer_keywords:
- LNK4098
ms.assetid: 1f1b1408-1316-4e34-80f5-6a02f2db0ac1
ms.openlocfilehash: 66cf1a1bc75405ffc9bae8158bfc8682776a8228
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62408089"
---
# <a name="linker-tools-warning-lnk4098"></a>Aviso LNK4098 (Ferramentas de Vinculador)

> defaultlib '*biblioteca*' está em conflito com o uso de outras bibliotecas; use /NODEFAULTLIB:*biblioteca*

Você está tentando vincular com bibliotecas incompatíveis.

> [!NOTE]
> Agora, as bibliotecas de tempo de execução contêm diretivas para evitar misturar tipos diferentes. Você receberá esse aviso se você tentar usar tipos diferentes ou depurar e versões de não depuração da biblioteca de tempo de execução no mesmo programa. Por exemplo, se você compilou um arquivo para usar um tipo de biblioteca de tempo de execução e o outro arquivo para usar outro tipo (por exemplo, debug versus varejo) e tentasse vinculá-los, você receberá esse aviso. Você deve compilar todos os arquivos de origem para usar a mesma biblioteca de tempo de execução. Para obter mais informações, consulte o [/MD, /MT, /LD (usar biblioteca em tempo de execução)](../../build/reference/md-mt-ld-use-run-time-library.md) opções do compilador.

Você pode usar o vinculador [/verbose: lib](../../build/reference/verbose-print-progress-messages.md) switch para descobrir quais bibliotecas que o vinculador procura. Por exemplo, quando o executável usa as bibliotecas de tempo de execução multithread e sem depuração, a lista relatada deve incluir libcmt. lib e não Libcmtd. lib, Msvcrt. lib ou Msvcrtd. lib. Você pode informar ao vinculador para ignorar as bibliotecas de tempo de execução incorretas usando [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) para cada biblioteca que você deseja ignorar.

A tabela a seguir mostra quais bibliotecas devem ser ignoradas, dependendo de qual biblioteca de tempo de execução você deseja usar. Na linha de comando, use um **/NODEFAULTLIB** opção para cada biblioteca ignorar. No IDE do Visual Studio, separar as bibliotecas para ignorar por ponto e vírgula na **ignorar bibliotecas padrão específicas** propriedade.

| Para usar esta biblioteca de tempo de execução | Ignorar essas bibliotecas |
|-----------------------------------|----------------------------|
| Multithreaded (libcmt. lib) | msvcrt.lib; libcmtd.lib; msvcrtd.lib |
| Multithreaded usando DLL (Msvcrt. lib) | libcmt.lib; libcmtd.lib; msvcrtd.lib |
| Depuração multithread (Libcmtd. lib) | libcmt.lib; msvcrt.lib; msvcrtd.lib |
| Depurar Multithreaded usando DLL (Msvcrtd. lib) | libcmt.lib; msvcrt.lib; libcmtd.lib |

Por exemplo, se você recebeu esse aviso, e você deseja criar um arquivo executável que usa a versão DLL não são de depuração das bibliotecas de tempo de execução, você pode usar as opções a seguir com a opção de vinculador:

```cmd
/NODEFAULTLIB:libcmt.lib NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrtd.lib
```