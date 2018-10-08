---
title: 'Data e hora: suporte a SYSTEMTIME | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- SYSTEMTIME
dev_langs:
- C++
helpviewer_keywords:
- system time
- FILETIME structure, with CTime class
- time [C++], formatting
- SYSTEMTIME structure
- dates [C++], MFC
- formatting [C++], time
ms.assetid: 201528e4-2ffa-48fc-af8f-203aa86d942a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2a4628d2db9c454bb689d4eb8316b77986588047
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48860479"
---
# <a name="date-and-time-systemtime-support"></a>Data e hora: suporte a SYSTEMTIME

O [CTime](../atl-mfc-shared/reference/ctime-class.md) classe tem construtores que aceitam os horários de sistema e o arquivo do Win32. Se você usa objetos `CTime` para esse fim, deve modificar sua inicialização de acordo, conforme descrito neste artigo.

Para obter informações sobre a estrutura SYSTEMTIME, consulte [SYSTEMTIME](../mfc/reference/systemtime-structure1.md). Para obter informações sobre a estrutura FILETIME, consulte [FILETIME](../mfc/reference/filetime-structure.md).

O MFC ainda oferece construtores `CTime` que usam argumentos de tempo no estilo MS-DOS, mas a partir do MFC versão 3.0 a classe `CTime` também oferece suporte a um construtor que usa uma estrutura `SYSTEMTIME` do Win32 e outra que usa uma estrutura `FILETIME` do Win32.

Os novos construtores `CTime` são:

- CTime (SYSTEMTIME const & `sysTime`);

- CTime (FILETIME const & `fileTime`);

O *fileTime* parâmetro é uma referência a um Win32 `FILETIME` estrutura, que representa a hora como um valor de 64 bits, um formato mais conveniente para armazenamento interno do que um `SYSTEMTIME` estrutura e o formato usado pelo Win32 para representam a hora de criação do arquivo.

Se seu código contiver um objeto `CTime` inicializado com a hora do sistema, você deverá usar o construtor `SYSTEMTIME` no Win32.

Você provavelmente não usará `CTime` `FILETIME` inicialização diretamente. Se você usar um `CFile` objeto para manipular um arquivo [cfile:: getStatus](../mfc/reference/cfile-class.md#getstatus) recupera o carimbo de hora do arquivo para você por meio de uma `CTime` objeto inicializado com um `FILETIME` estrutura.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Data geral e da programação de tempo no MFC](../atl-mfc-shared/date-and-time.md)

- [Suporte de automação de data e a programação de tempo](../atl-mfc-shared/date-and-time-automation-support.md)

## <a name="see-also"></a>Consulte também

[Data e hora](../atl-mfc-shared/date-and-time.md)
