---
title: Aviso LNK4098 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4098
helpviewer_keywords:
- LNK4098
ms.assetid: 1f1b1408-1316-4e34-80f5-6a02f2db0ac1
ms.openlocfilehash: 088124fcce7cafad3fab3280ae0b3ae0d893283e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50468712"
---
# <a name="linker-tools-warning-lnk4098"></a>Aviso LNK4098 (Ferramentas de Vinculador)

conflitos do defaultlib 'library' com o usam de outras bibliotecas; Use /NODEFAULTLIB: Library

Você está tentando vincular com bibliotecas incompatíveis.

> [!NOTE]
>  Agora, as bibliotecas de tempo de execução contêm diretivas para evitar misturar tipos diferentes. Você receberá esse aviso se você tentar usar tipos diferentes ou depurar e versões de não depuração da biblioteca de tempo de execução no mesmo programa. Por exemplo, se você compilou um arquivo para usar uma biblioteca de tipo de tempo de execução e outro arquivo para usar outro tipo (por exemplo, single-thread versus multithread) e tentou vinculá-los, você receberá esse aviso. Você deve compilar todos os arquivos de origem para usar a mesma biblioteca de tempo de execução. Consulte a [usar a biblioteca de tempo de execução](../../build/reference/md-mt-ld-use-run-time-library.md) (**/MD**, **/MT**, **/LD**) opções do compilador para obter mais informações.

Você pode usar o vinculador [/verbose: lib](../../build/reference/verbose-print-progress-messages.md) switch para determinar quais bibliotecas que o vinculador está procurando. Se você receber LNK4098 e desejar criar um arquivo executável que usa, por exemplo, o thread único, bibliotecas de tempo de execução sem depuração, use o **/verbose: lib** opção para descobrir quais bibliotecas que o vinculador está procurando. O vinculador deve imprimir libc. lib e não libcmt. lib, Msvcrt. lib, libcd, Libcmtd. lib ou Msvcrtd. lib como as bibliotecas pesquisadas. Você pode informar ao vinculador para ignorar as bibliotecas de tempo de execução incorretas usando [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) para cada biblioteca que você deseja ignorar.

A tabela a seguir mostra quais bibliotecas devem ser ignoradas, dependendo de qual biblioteca de tempo de execução você deseja usar.

|Para usar esta biblioteca de tempo de execução|Ignorar essas bibliotecas|
|-----------------------------------|----------------------------|
|Single-thread (libc. lib)|libcmt. lib, Msvcrt. lib, libcd, Libcmtd. lib, Msvcrtd. lib|
|Multithreaded (libcmt. lib)|libc. lib, Msvcrt. lib, libcd, Libcmtd. lib, Msvcrtd. lib|
|Multithreaded usando DLL (Msvcrt. lib)|libc. lib, libcmt. lib, libcd, Libcmtd. lib, Msvcrtd. lib|
|Depurar Single-threaded (libcd)|libc. lib, libcmt. lib, Msvcrt. lib, Libcmtd. lib, Msvcrtd. lib|
|Depuração multithread (Libcmtd. lib)|libc. lib, libcmt. lib, Msvcrt. lib, Msvcrtd. lib e libcd|
|Depurar Multithreaded usando DLL (Msvcrtd. lib)|libc. lib, libcmt. lib, Msvcrt. lib, Libcmtd. lib e libcd|

Por exemplo, se você recebeu esse aviso, e você deseja criar um arquivo executável que usa a versão sem depuração, single-thread das bibliotecas de tempo de execução, você pode usar as opções a seguir com a opção de vinculador:

```
/NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:msvcrt.lib /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrtd.lib
```