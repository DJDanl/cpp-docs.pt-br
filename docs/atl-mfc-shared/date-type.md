---
title: Tipo DE DATA
ms.date: 11/04/2016
f1_keywords:
- DATE
helpviewer_keywords:
- Date data type, implementing
- Date data type
- DATE type
- Date data type, about Date data type
- MFC, date and time
- hour values representation
ms.assetid: 695853ed-b614-4575-b793-b8c287372038
ms.openlocfilehash: 6fd9fde83474ff4f439c0dd3989d4dc35fe1241a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317914"
---
# <a name="date-type"></a>Tipo DE DATA

O tipo DATE é implementado usando um número de ponto flutuante de 8 bytes. Os dias são representados por incrementos de números inteiros a partir de 30 de dezembro de 1899, à meia-noite como o tempo zero. Valores de hora são expressos como o valor absoluto da parte fracionária do número. A tabela a seguir ilustra várias datas juntamente com seu equivalente numérico tipo DATE:

|Data e hora|Representação|
|-------------------|--------------------|
|30 de dezembro de 1899, meia-noite|0,00|
|1 de janeiro de 1900, meia-noite|2,00|
|4 de janeiro de 1900, meia-noite|5.00|
|4 de janeiro de 1900, 6 da manhã.|5.25|
|4 de janeiro de 1900, meio-dia|5.50|
|4 de janeiro de 1900, 21h.|5.875|

O tipo de data DATE, bem como a `COleDateTime` classe, representa datas e horários como uma linha numérica clássica. A `COleDateTime` classe contém vários métodos para manipular valores DATE, incluindo conversão para e de outros formatos de data sem acordo.

Os seguintes pontos devem ser observados ao trabalhar com esses formatos de data e hora em Automação:

- As datas são especificadas em horário local; a sincronização deve ser realizada manualmente ao trabalhar com datas em diferentes fusos horários.

- Os tipos de datas não representam o horário de verão.

- O cronograma de data torna-se descontínuo para valores de data inferiores a 0 (antes de 30 de dezembro de 1899). Isso ocorre porque a parte de número total do valor da data é tratada como assinada, enquanto a parte fracionada é tratada como não assinada. Em outras palavras, a parte de número total do valor da data pode ser positiva ou negativa, enquanto a parte fracionada do valor da data é sempre adicionada à data lógica geral. A tabela a seguir ilustra alguns exemplos:

|Data e hora|Representação|
|-------------------|--------------------|
|27 de dezembro de 1899, meia-noite|-3.00|
|28 de dezembro de 1899, meio-dia|-2.50|
|28 de dezembro de 1899, meia-noite|-2.00|
|29 de dezembro de 1899, meia-noite|-1.00|
|30 de dezembro de 1899, 18h.|-0.75|
|30 de dezembro de 1899, meio-dia|-0.50|
|30 de dezembro de 1899, 6 da manhã.|-0.25|
|30 de dezembro de 1899, meia-noite|0,00|
|30 de dezembro de 1899, 6 da manhã.|0,25|
|30 de dezembro de 1899, meio-dia|0.50|
|30 de dezembro de 1899, 18h.|0.75|
|31 de dezembro de 1899, meia-noite|1.00|
|1 de janeiro de 1900, meia-noite|2,00|
|1 de janeiro de 1900, meio-dia|2,50|
|2 de janeiro de 1900, meia-noite|3.00|

> [!CAUTION]
> Note que, como 6:00 AM é sempre representado por um valor fracionado 0,25, independentemente de o inteiro representando o dia ser positivo (após 30 de dezembro, 1899) ou negativo (antes de 30 de dezembro de 1899), uma simples comparação de pontos flutuantes classificaria erroneamente qualquer DATA representando 6:00 AM em um dia antes de 30/12/1899, mais *tarde* do que uma DATA representando 7:00 AM no mesmo dia.

Mais informações sobre problemas relacionados `COleDateTime` à DATA e tipos podem ser encontradas em [COleDateTime Class](../atl-mfc-shared/reference/coledatetime-class.md) e [Data e Hora: Suporte à automação](../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="see-also"></a>Confira também

[Data e hora](../atl-mfc-shared/date-and-time.md)<br/>
[Classe COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md)
