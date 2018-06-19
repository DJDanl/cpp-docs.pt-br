---
title: 'Data e hora: SYSTEMTIME suporte | Microsoft Docs'
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
ms.openlocfilehash: ecbfd517a0fd535a23920ae21d03f1756babc113
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32355394"
---
# <a name="date-and-time-systemtime-support"></a>Data e hora: suporte SYSTEMTIME
O [CTime](../atl-mfc-shared/reference/ctime-class.md) classe tem construtores que aceitem tempos de sistema e arquivos do Win32. Se você usa objetos `CTime` para esse fim, deve modificar sua inicialização de acordo, conforme descrito neste artigo.  
  
 Para obter informações sobre a estrutura SYSTEMTIME, consulte [SYSTEMTIME](../mfc/reference/systemtime-structure1.md). Para obter informações sobre a estrutura FILETIME, consulte [FILETIME](../mfc/reference/filetime-structure.md).  
  
 O MFC ainda oferece construtores `CTime` que usam argumentos de tempo no estilo MS-DOS, mas a partir do MFC versão 3.0 a classe `CTime` também oferece suporte a um construtor que usa uma estrutura `SYSTEMTIME` do Win32 e outra que usa uma estrutura `FILETIME` do Win32.  
  
 Os novos construtores `CTime` são:  
  
-   CTime (SYSTEMTIME const & `sysTime`);  
  
-   CTime (FILETIME const & `fileTime`);  
  
 O parâmetro `fileTime` é uma referência à estrutura `FILETIME` Win32, que representa o tempo como um valor de 64 bits, um formato mais conveniente para o armazenamento interno do que uma estrutura `SYSTEMTIME` e o formato usado pelo Win32 para representar o momento da criação do arquivo.  
  
 Se seu código contiver um objeto `CTime` inicializado com a hora do sistema, você deverá usar o construtor `SYSTEMTIME` no Win32.  
  
 Você provavelmente não usará `CTime` `FILETIME` inicialização diretamente. Se você usar um `CFile` objeto para manipular um arquivo, [CFile::GetStatus](../mfc/reference/cfile-class.md#getstatus) recupera o carimbo de hora do arquivo para você por meio de um `CTime` objeto inicializado com um `FILETIME` estrutura.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Data geral e a programação de tempo em MFC](../atl-mfc-shared/date-and-time.md)  
  
-   [Suporte de automação de data e a programação de tempo](../atl-mfc-shared/date-and-time-automation-support.md)  
  
-   [Classes de uso geral para a data e a programação de tempo](../atl-mfc-shared/date-and-time-general-purpose-classes.md)  
  
## <a name="see-also"></a>Consulte também  
 [Data e hora](../atl-mfc-shared/date-and-time.md)

