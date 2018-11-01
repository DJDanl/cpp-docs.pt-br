---
title: Tipo de data
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
ms.openlocfilehash: b8460d50a0c6cbd4b213e45c62d8d6cadae68544
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50548181"
---
# <a name="date-type"></a>Tipo de data

O tipo de data é implementado usando um número de ponto flutuante de 8 bytes. Dias são representados por incrementos de números inteiros a partir de 30 de dezembro de 1899, meia-noite como zero hora. Os valores de hora são expressos como o valor absoluto da parte fracionária do número. A tabela a seguir ilustra várias datas, juntamente com seu equivalente numérico do tipo de data:

|Data e Hora|Representação|
|-------------------|--------------------|
|30 de dezembro de 1899, meia-noite|0.00|
|1 de janeiro de 1900, meia-noite|2.00|
|4 de janeiro de 1900, meia-noite|5.00|
|4 de janeiro de 1900, 6h|5.25|
|4 de janeiro de 1900, meio-dia|5.50|
|4 de janeiro de 1900 às 21h.|5.875|

O tipo de data de data, bem como o `COleDateTime` classe representa datas e horas como uma linha número clássica. O `COleDateTime` classe contém vários métodos para manipular valores de data, incluindo a conversão de e para outros formatos de data comuns.

Os seguintes pontos devem ser observados ao trabalhar com esses formatos de data e hora na automação:

- As datas são especificadas na hora local; sincronização deve ser executada manualmente ao trabalhar com datas em fusos horários diferentes.

- Os tipos de data não contam para o horário de verão.

- A linha do tempo de data se torna descontínua para valores de data menor que 0 (antes de 30 de dezembro de 1899). Isso ocorre porque a parte de número inteiro do valor de data é tratada como assinado, enquanto a parte fracionária é tratada como não assinado. Em outras palavras, a parte de número inteiro do valor de data pode ser positivo ou negativo, enquanto a parte fracionária do valor date sempre é adicionada à data geral lógica. A tabela a seguir ilustra alguns exemplos:

|Data e Hora|Representação|
|-------------------|--------------------|
|27 de dezembro de 1899, meia-noite|-3.00|
|28 de dezembro de 1899, meio-dia|-2.50|
|28 de dezembro de 1899, meia-noite|-2.00|
|29 de dezembro de 1899, meia-noite|-1.00|
|30 de dezembro de 1899, 18h00.|-0.75|
|30 de dezembro de 1899, meio-dia|-0.50|
|30 de dezembro de 1899, 6h|-0.25|
|30 de dezembro de 1899, meia-noite|0.00|
|30 de dezembro de 1899, 6h|0.25|
|30 de dezembro de 1899, meio-dia|0.50|
|30 de dezembro de 1899, 18h00.|0.75|
|31 de dezembro de 1899, meia-noite|1.00|
|1 de janeiro de 1900, meia-noite|2.00|
|1 de janeiro de 1900, meio-dia|2,50|
|2 de janeiro de 1900, meia-noite|3.00|

> [!CAUTION]
>  Observe que, como das 6H sempre é representada por um valor fracionário 0,25, independentemente do inteiro que representa o dia é positivo (após 30 de dezembro de 1899) ou negativo (antes de 30 de dezembro de 1899), uma comparação de ponto flutuante simples seria erroneamente de classificação qualquer data que representa das 6H em um dia anterior ao 30/12/1899 como *posterior* que uma data que representa 7H00 no mesmo dia.

Para obter mais informações sobre os problemas relacionados à data e `COleDateTime` tipos podem ser encontrados sob [classe COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md) e [data e hora: suporte de automação](../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="see-also"></a>Consulte também

[Data e hora](../atl-mfc-shared/date-and-time.md)<br/>
[Classe COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md)

