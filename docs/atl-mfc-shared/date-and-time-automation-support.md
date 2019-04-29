---
title: 'Data e hora: Suporte de automação'
ms.date: 11/04/2016
helpviewer_keywords:
- adding dates
- calculating dates and times
- formatting [Visual Studio], dates
- dates, Automation support
- elapsed time, calculating in Automation
- COleDateTime class, Automation date/time support
- COleDateTimeSpan class, Automation date/time support
- Automation, date and time support
- formatting [Visual Studio], time
- calculations, date and time
- time [Visual Studio], Automation support
ms.assetid: 6eee94c4-943d-4ffc-bf7c-bdda89337ab0
ms.openlocfilehash: c26534189c7b6f904611e78c5d2d6d0b1d6d7382
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62235908"
---
# <a name="date-and-time-automation-support"></a>Data e hora: Suporte de automação

Este artigo descreve como tirar proveito dos serviços de biblioteca de classe relacionados ao gerenciamento de data e hora. Os procedimentos descritos incluem:

- [A hora atual](../atl-mfc-shared/current-time-automation-classes.md)

- [Calculando tempo decorrido](../atl-mfc-shared/elapsed-time-automation-classes.md)

- [Formatação de uma representação de cadeia de caracteres de data/hora](../atl-mfc-shared/formatting-time-automation-classes.md)

O [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md) classe fornece uma maneira para representar as informações de data e hora. Ele fornece uma granularidade maior e um intervalo maior que o [CTime](../atl-mfc-shared/reference/ctime-class.md) classe. O [COleDateTimeSpan](../atl-mfc-shared/reference/coledatetimespan-class.md) classe representa o tempo decorrido, como a diferença entre dois `COleDateTime` objetos.

O `COleDateTime` e `COleDateTimeSpan` classes são projetadas para ser usado com o `COleVariant` classe usada na automação. `COleDateTime` e `COleDateTimeSpan` também são úteis na programação de banco de dados do MFC, mas pode ser usados sempre que você deseja manipular valores de data e hora. Embora o `COleDateTime` classe tem uma gama maior de valores e granularidade maior do que o `CTime` classe, ela requer mais armazenamento por um objeto que `CTime`. Também há algumas considerações especiais ao trabalhar com o tipo subjacente de data. Ver [o tipo de data](../atl-mfc-shared/date-type.md) para obter mais detalhes sobre a implementação de data.

`COleDateTime` objetos podem ser usados para representar datas entre 1 de janeiro de 100 e 31 de dezembro de 9999. `COleDateTime` objetos flutuantes, os valores de ponto, com uma resolução aproximada de 1 milissegundo. `COleDateTime` se baseia no tipo de dados de data, definido na documentação do MFC sob [COleDateTime::operator data](../atl-mfc-shared/reference/coledatetime-class.md#operator_date). A implementação real da data, ultrapassa os limites. O `COleDateTime` implementação impõe esses limites para facilitar o trabalho com a classe.

`COleDateTime` não oferece suporte a datas do calendário juliano. O calendário gregoriano é assumido como para estender o de volta no tempo de 1 de janeiro de 100.

`COleDateTime` ignora o horário de verão (DST). O exemplo de código a seguir compara os dois métodos de cálculo de um período de tempo que cruza a data de mudança do horário de verão: usando um CRT e a outros usando `COleDateTime`. Horário de verão muda, na maioria dos locais, na segunda semana em abril e a terceira em outubro.

O primeiro método define dois `CTime` objetos, *tempo1* e *time2*, 5 de abril e 6 de abril, respectivamente, usando as estruturas do tipo C padrão `tm` e `time_t`. O código exibe *tempo1* e *time2* e o período de tempo entre eles.

O segundo método cria dois `COleDateTime` objetos, `oletime1` e `oletime2`e define-os para as mesmas datas como *tempo1* e *time2*. Ele exibe `oletime1` e `oletime2` e o período de tempo entre eles.

A CRT corretamente calcula uma diferença de 23 horas. `COleDateTimeSpan` calcula a diferença de 24 horas.

[!code-cpp[NVC_ATLMFC_Utilities#176](../atl-mfc-shared/codesnippet/cpp/date-and-time-automation-support_1.cpp)]

## <a name="see-also"></a>Consulte também

[Data e hora](../atl-mfc-shared/date-and-time.md)
