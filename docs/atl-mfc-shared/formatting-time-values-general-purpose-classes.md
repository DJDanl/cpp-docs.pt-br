---
title: 'Formatando valores temporais: Classes de uso geral'
ms.date: 11/04/2016
helpviewer_keywords:
- dates, calculating intervals
- elapsed time, string representation
- time [C++], formatting
- formatting [C++], time
ms.assetid: 7fcfee24-f874-4a4d-95b3-adc19a0f2df0
ms.openlocfilehash: 48290adbc3e0e7f3cbe9a5a8e0569a5b61833e8c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50478657"
---
# <a name="formatting-time-values-general-purpose-classes"></a>Formatando valores temporais: Classes de uso geral

O procedimento a seguir mostra como formatar valores de tempo.

#### <a name="to-format-a-string-representation-of-a-time-or-elapsed-time"></a>Para formatar uma representação de cadeia de caracteres de uma hora ou o tempo decorrido

Use o `Format` função de membro de qualquer um de [CTime](../atl-mfc-shared/reference/ctime-class.md) ou [CTimeSpan](../atl-mfc-shared/reference/ctimespan-class.md) classes para criar um caractere de cadeia de caracteres representação do tempo ou tempo decorrido, conforme mostrado no exemplo a seguir.

   [!code-cpp[NVC_ATLMFC_Utilities#175](../atl-mfc-shared/codesnippet/cpp/formatting-time-values-general-purpose-classes_1.cpp)]

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Data geral e da programação de tempo no MFC](../atl-mfc-shared/date-and-time.md)

- [Trabalhando com SYSTEMTIME](../atl-mfc-shared/date-and-time-systemtime-support.md)

- [Suporte de automação de data e a programação de tempo](../atl-mfc-shared/date-and-time-automation-support.md)

