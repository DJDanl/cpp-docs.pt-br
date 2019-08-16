---
title: Data e Hora
ms.date: 08/13/2019
helpviewer_keywords:
- time, MFC programming
- time
- MFC, date and time
- dates, MFC
ms.assetid: ecf56dc5-d418-4603-ad3e-af7e205a6403
ms.openlocfilehash: 2a5e6977acfca51b8074399f6f9b3166c8a358bc
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491307"
---
# <a name="date-and-time"></a>Data e Hora

O MFC dá suporte a várias maneiras diferentes de trabalhar com datas e horas:

- Suporte para o [tipo de dados de data](../atl-mfc-shared/date-type.md)de automação. DATE dá suporte a data, hora e valores de data/hora. As classes [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md) e [COleDateTimeSpan](../atl-mfc-shared/reference/coledatetimespan-class.md) encapsulam essa funcionalidade. Eles funcionam com a classe [COleVariant](../mfc/reference/colevariant-class.md) usando o suporte de automação.

- Classes de tempo de finalidade geral. As classes [CTime](../atl-mfc-shared/reference/ctime-class.md) e [CTimeSpan](../atl-mfc-shared/reference/ctimespan-class.md) encapsulam a maior parte da funcionalidade associada à biblioteca de tempo padrão ANSI, que é declarada em tempo. T.

- Suporte para relógio do sistema. Com o MFC versão 3,0, o suporte foi `CTime` adicionado ao para `SYSTEMTIME` os `FILETIME` tipos de dados e Win32.

## <a name="date-and-time-automation-support"></a>Data e hora: Suporte à automação

A classe [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md) fornece uma maneira de representar informações de data e hora. Ele fornece granularidade mais fina e um intervalo maior do que a classe [CTime](../atl-mfc-shared/reference/ctime-class.md) . A classe [COleDateTimeSpan](../atl-mfc-shared/reference/coledatetimespan-class.md) representa o tempo decorrido, como a diferença entre dois `COleDateTime` objetos.

As `COleDateTime` classes `COleDateTimeSpan` e são projetadas para uso com `COleVariant` a classe. `COleDateTime`e `COleDateTimeSpan` também são úteis na programação de banco de dados MFC, mas podem ser usados sempre que você desejar manipular valores de data e hora. Embora a `COleDateTime` classe tenha um intervalo maior de valores e uma granularidade mais definada que a `CTime` classe, ela requer mais armazenamento `CTime`por objeto do que. Também há algumas considerações especiais ao trabalhar com o tipo de data subjacente. Para obter mais informações sobre a implementação de data, consulte [o tipo de data](../atl-mfc-shared/date-type.md).

`COleDateTime`os objetos podem ser usados para representar datas entre 1º de janeiro de 100 e 31 de dezembro de 9999. `COleDateTime`os objetos são valores de ponto flutuante, com uma resolução aproximada de 1 milissegundo. `COleDateTime`o é baseado no tipo de dados DATE, definido na documentação do MFC em [COleDateTime:: Operator Date](../atl-mfc-shared/reference/coledatetime-class.md#operator_date). A implementação real da data ultrapassa esses limites. A `COleDateTime` implementação impõe esses limites para facilitar o trabalho com a classe.

`COleDateTime`Não dá suporte a datas do Juliano. Presume-se que o calendário gregoriano seja estendido de volta no tempo para 1º de janeiro de 100.

`COleDateTime`ignora o horário de Verão (DST). O exemplo de código a seguir compara dois métodos de cálculo de um intervalo de tempo que cruza a data de alternância do horário de verão: um `COleDateTime`usando o CRT e o outro usando.

O primeiro método define dois `CTime` objetos, *time1* e *time2*, para 5 de abril e 6 de abril, respectivamente, usando as estruturas `tm` de `time_t`tipo C padrão e. O código exibe *time1* e *time2* e o período de tempo entre eles.

O segundo método cria dois `COleDateTime` objetos, `oletime1` e `oletime2`, e os define para as mesmas datas que *time1* e *time2*. Ele exibe `oletime1` e `oletime2` e o período de tempo entre eles.

O CRT calcula corretamente uma diferença de 23 horas. `COleDateTimeSpan`calcula uma diferença de 24 horas.

[!code-cpp[NVC_ATLMFC_Utilities#176](../atl-mfc-shared/codesnippet/cpp/date-and-time-automation-support_1.cpp)]

### <a name="get-the-current-time"></a>Obter a hora atual

O procedimento a seguir mostra como criar um `COleDateTime` objeto e inicializá-lo com a hora atual.

#### <a name="to-get-the-current-time"></a>Para obter a hora atual

1. Crie um objeto `COleDateTime`.

1. Chame `GetCurrentTime`.

   [!code-cpp[NVC_ATLMFC_Utilities#177](../atl-mfc-shared/codesnippet/cpp/current-time-automation-classes_1.cpp)]

### <a name="calculate-elapsed-time"></a>Calcular tempo decorrido

Este procedimento mostra como calcular a diferença entre dois `COleDateTime` objetos e obter um `COleDateTimeSpan` resultado.

#### <a name="to-calculate-elapsed-time"></a>Para calcular o tempo decorrido

1. Crie dois `COleDateTime` objetos.

1. Defina um dos `COleDateTime` objetos como a hora atual.

1. Execute uma tarefa demorada.

1. Defina o outro `COleDateTime` objeto como a hora atual.

1. Faça a diferença entre as duas vezes.

   [!code-cpp[NVC_ATLMFC_Utilities#178](../atl-mfc-shared/codesnippet/cpp/elapsed-time-automation-classes_1.cpp)]

### <a name="format-a-time"></a>Formatar uma hora

#### <a name="to-format-a-time"></a>Para formatar uma hora

Use a `Format` função membro de [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md) ou [COleDateTimeSpan](../atl-mfc-shared/reference/coledatetimespan-class.md) para criar uma cadeia de caracteres que representa a hora ou o tempo decorrido.

   [!code-cpp[NVC_ATLMFC_Utilities#179](../atl-mfc-shared/codesnippet/cpp/formatting-time-automation-classes_1.cpp)]

Para obter mais informações, consulte Class [COleVariant](../mfc/reference/colevariant-class.md).

## <a name="date-and-time-database-support"></a>Data e hora: Suporte a banco de dados

A partir da versão 4,0, a programação de banco de dados MFC usa as classes [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md) e [COleDateTimeSpan](../atl-mfc-shared/reference/coledatetimespan-class.md) para representar dados de data e hora. Essas classes, também usadas na automação, são derivadas da classe [COleVariant](../mfc/reference/colevariant-class.md). Eles fornecem um melhor suporte para o gerenciamento de dados de data e hora do que o [CTime](../atl-mfc-shared/reference/ctime-class.md) e o [CTimeSpan](../atl-mfc-shared/reference/ctimespan-class.md).

## <a name="date-and-time-systemtime-support"></a>Data e hora: Suporte do SYSTEMTIME

A classe [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md) tem construtores que aceitam tempos de sistema e arquivo do Win32.

A estrutura `FILETIME` do Win32 representa o tempo como um valor de 64 bits. É um formato mais conveniente para armazenamento interno do que uma `SYSTEMTIME` estrutura e o formato usado pelo Win32 para representar a hora da criação do arquivo. Para obter informações sobre a estrutura SYSTEMTIME, consulte [SYSTEMTIME](/windows/desktop/api/minwinbase/ns-minwinbase-systemtime). Para obter informações sobre a estrutura FILETIME, consulte [FILETIME](/windows/desktop/api/minwinbase/ns-minwinbase-filetime).

## <a name="see-also"></a>Consulte também

[Principais](../mfc/mfc-concepts.md)\
[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)
