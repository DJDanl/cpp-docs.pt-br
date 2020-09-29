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
ms.openlocfilehash: 5a6c1e1cca5b2cb978d6af4208377db1a2926357
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91502180"
---
# <a name="date-type"></a>Tipo de data

O tipo de data é implementado usando um número de ponto flutuante de 8 bytes. Os dias são representados por incrementos de número inteiro, começando com 30 de dezembro de 1899, como o tempo zero. Valores de hora são expressos como o valor absoluto da parte fracionária do número. A tabela a seguir ilustra várias datas junto com seu tipo de data equivalente numérico:

|Data e hora|Representação|
|-------------------|--------------------|
|30 de dezembro de 1899, meia-noite|0,00|
|1 de janeiro de 1900, meia-noite|2,00|
|4 de janeiro de 1900, meia-noite|5,00|
|4 de janeiro de 1900, 18:00|5.25|
|4 de janeiro de 1900, meio-dia|5.50|
|4 de janeiro de 1900, 9 P.M.|5,875|

O tipo de data Date, bem como a `COleDateTime` classe, representa datas e horas como uma linha de número clássico. A `COleDateTime` classe contém vários métodos para manipular valores de data, incluindo a conversão de e de outros formatos de data comuns.

Os seguintes pontos devem ser anotados ao trabalhar com esses formatos de data e hora na automação:

- As datas são especificadas na hora local; a sincronização deve ser executada manualmente ao trabalhar com datas em fusos horários diferentes.

- Os tipos de data não são contados para o horário de verão.

- A linha do tempo de data se torna descontínua para valores de data inferiores a 0 (antes de 30 de dezembro de 1899). Isso ocorre porque a parte de número inteiro do valor de data é tratada como assinada, enquanto a parte fracionária é tratada como não assinada. Em outras palavras, a parte de número inteiro do valor de data pode ser positiva ou negativa, enquanto a parte fracionária do valor de data é sempre adicionada à data lógica geral. A tabela a seguir ilustra alguns exemplos:

|Data e hora|Representação|
|-------------------|--------------------|
|27 de dezembro de 1899, meia-noite|-3, 0|
|28 de dezembro de 1899, meio-dia|-2,50|
|28 de dezembro de 1899, meia-noite|-2, 0|
|29 de dezembro de 1899, meia-noite|-1, 0|
|30 de dezembro de 1899, 18h|-0,75|
|30 de dezembro de 1899, meio-dia|-0,50|
|30 de dezembro de 1899, 18:00|-0,25|
|30 de dezembro de 1899, meia-noite|0,00|
|30 de dezembro de 1899, 18:00|0,25|
|30 de dezembro de 1899, meio-dia|0,50|
|30 de dezembro de 1899, 18h|0,75|
|31 de dezembro de 1899, meia-noite|1.00|
|1 de janeiro de 1900, meia-noite|2,00|
|1 de janeiro de 1900, meio-dia|2.50|
|2 de janeiro de 1900, meia-noite|3.00|

> [!CAUTION]
> Observe que, como 6:00 AM é sempre representado por um valor fracionário 0,25, independentemente de o inteiro que representa o dia ser positivo (após 30 de dezembro de 1899) ou negativo (antes de 30 de dezembro de 1899), uma comparação de ponto flutuante simples classificaria erroneamente qualquer data que representesse 6:00 em um dia anterior à 12/30/1899 *mais tarde* que a data que representa a 7:00.

Mais informações sobre problemas relacionados à data e aos `COleDateTime` tipos podem ser encontradas em [classe COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md) e [data e hora: suporte à automação](./date-and-time.md).

## <a name="see-also"></a>Consulte também

[Data e hora](../atl-mfc-shared/date-and-time.md)<br/>
[Classe COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md)
