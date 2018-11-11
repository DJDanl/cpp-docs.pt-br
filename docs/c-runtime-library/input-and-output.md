---
title: Entrada e saída
ms.date: 11/04/2016
f1_keywords:
- c.io
helpviewer_keywords:
- input routines
- I/O [CRT]
- I/O routines
- I/O [CRT], routines
- output routines
ms.assetid: 1c177301-e341-4ca0-aedc-0a87fe1c75ae
ms.openlocfilehash: 26d527f7afad544b051a2ad765af09c430782083
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50590379"
---
# <a name="input-and-output"></a>Entrada e saída

As funções de E/S leem e gravam dados de e para dispositivos e arquivos. Operações de E/S de arquivo ocorrem no modo de texto ou binário. A biblioteca em tempo de execução da Microsoft tem três tipos de funções de E/S:

- Funções [Fluxo de E/S](../c-runtime-library/stream-i-o.md) tratam os dados como um fluxo de caracteres individuais.

- Funções [E/S de baixo nível](../c-runtime-library/low-level-i-o.md) invocam o sistema operacional diretamente para a operação de nível mais baixo do que o fornecido pelo fluxo de E/S.

- Funções [Console e E/S de porta](../c-runtime-library/console-and-port-i-o.md) leem ou gravam diretamente em um console (tela e teclado) ou uma porta de E/S (como uma porta de impressora).

   > [!NOTE]
   > Como funções de fluxo são armazenadas em buffer e funções de nível inferior não são armazenadas, esses dois tipos de funções são geralmente incompatíveis. Para processar um arquivo específico, use o fluxo ou funções de nível inferior exclusivamente.

## <a name="see-also"></a>Consulte também

[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
