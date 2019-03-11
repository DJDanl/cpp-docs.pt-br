---
title: Data e Hora
ms.date: 11/04/2016
helpviewer_keywords:
- time, MFC programming
- time
- MFC, date and time
- dates, MFC
ms.assetid: ecf56dc5-d418-4603-ad3e-af7e205a6403
ms.openlocfilehash: 32222b4a2a529716db2c414e0281e1b1ba16a0dd
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57739172"
---
# <a name="date-and-time"></a>Data e Hora

MFC dá suporte a várias maneiras diferentes de trabalhar com datas e horas. Elas incluem:

- Classes de tempo de uso geral. O [CTime](../atl-mfc-shared/reference/ctime-class.md) e [CTimeSpan](../atl-mfc-shared/reference/ctimespan-class.md) classes encapsulam a maioria das funcionalidades associadas com a biblioteca em tempo padrão ANSI, que é declarada no tempo. H.

- Suporte para o relógio do sistema. Com o MFC versão 3.0, foi adicionado suporte para `CTime` do Win32 `SYSTEMTIME` e `FILETIME` tipos de dados.

- Suporte para a automação [tipo de dados DATE](../atl-mfc-shared/date-type.md). Data dá suporte a data, hora e valores de data/hora. O [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md) e [COleDateTimeSpan](../atl-mfc-shared/reference/coledatetimespan-class.md) classes encapsulam essa funcionalidade. Eles funcionam com o [COleVariant](../mfc/reference/colevariant-class.md) classe usando o suporte de automação.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Data e hora: Suporte a SYSTEMTIME](../atl-mfc-shared/date-and-time-systemtime-support.md)

- [Data e hora: Suporte de automação](../atl-mfc-shared/date-and-time-automation-support.md)

- [Data e hora: Suporte de banco de dados](../atl-mfc-shared/date-and-time-database-support.md)

## <a name="see-also"></a>Consulte também

[Conceitos](../mfc/mfc-concepts.md)<br/>
[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)
