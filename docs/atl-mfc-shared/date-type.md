---
title: Tipo de data | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- DATE
dev_langs:
- C++
helpviewer_keywords:
- Date data type, implementing
- Date data type
- DATE type
- Date data type, about Date data type
- MFC, date and time
- hour values representation
ms.assetid: 695853ed-b614-4575-b793-b8c287372038
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5aafed046fa5724442e30014aa5634542de0f4aa
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32358121"
---
# <a name="date-type"></a>Tipo de data
O **data** tipo é implementado usando um número de ponto flutuante de 8 bytes. Dias são representados por incrementos de números inteiros, iniciando em 30 de dezembro de 1899, meia-noite como zero hora. Os valores de hora são expressos como o valor absoluto da parte fracionária do número. A tabela a seguir ilustra várias datas junto com seus **data** equivalente numérico do tipo:  
  
|Data e Hora|Representação|  
|-------------------|--------------------|  
|30 de dezembro de 1899, meia-noite|0.00|  
|1 de janeiro de 1900, meia-noite|2.00|  
|4 de janeiro de 1900, meia-noite|5.00|  
|4 de janeiro de 1900 6h|5.25|  
|4 de janeiro de 1900, meio-dia|5.50|  
|4 de janeiro de 1900, 9: 00|5.875|  
  
 O **data** data tipo, bem como a `COleDateTime` classe representa datas e horas como uma linha de número clássica. O `COleDateTime` classe contém diversos métodos para manipular valores de data, inclusive a conversão de e para outros formatos de data comuns.  
  
 Observe os seguintes pontos ao trabalhar com esses formatos de data e hora na automação:  
  
-   As datas são especificadas na hora local; sincronização deve ser executada manualmente ao trabalhar com datas em fusos horários diferentes.  
  
-   Os tipos de data não conta para o horário de verão.  
  
-   A linha do tempo de data se torna descontínua para valores de data menor do que 0 (antes de 30 de dezembro de 1899). Isso ocorre porque a parte de número inteiro do valor de data é tratada como conectado, enquanto a parte fracionária é tratada como não assinados. Em outras palavras, a parte de número inteiro do valor de data pode ser positivo ou negativo, enquanto a parte fracionária do valor date sempre é adicionada à data geral lógica. A tabela a seguir ilustra alguns exemplos:  
  
|Data e Hora|Representação|  
|-------------------|--------------------|  
|27 de dezembro de 1899, meia-noite|-3.00|  
|28 de dezembro de 1899, meio-dia|-2.50|  
|28 de dezembro de 1899, meia-noite|-2.00|  
|29 de dezembro de 1899, meia-noite|-1.00|  
|30 de dezembro de 1899, 18h00.|-0.75|  
|30 de dezembro de 1899, meio-dia|-0.50|  
|30 de dezembro de 1899 6h|-0.25|  
|30 de dezembro de 1899, meia-noite|0.00|  
|30 de dezembro de 1899 6h|0.25|  
|30 de dezembro de 1899, meio-dia|0.50|  
|30 de dezembro de 1899, 18h00.|0.75|  
|31 de dezembro de 1899, meia-noite|1.00|  
|1 de janeiro de 1900, meia-noite|2.00|  
|1 de janeiro de 1900, meio-dia|2.50|  
|2 de janeiro de 1900, meia-noite|3.00|  
  
> [!CAUTION]
>  Observe que, como 6:00 AM sempre é representada por um valor fracionário 0,25, independentemente do inteiro que representa o dia for positivo (após 30 de dezembro de 1899) ou negativo (antes de 30 de dezembro de 1899), uma comparação de ponto flutuante simples erroneamente classificaria qualquer **data** que representa 6:00 AM em um dia anteriores a 30/12/1899 como *posteriormente* que um **data** representando 7:00 AM no mesmo dia.  
  
 Para obter mais informações sobre problemas relacionados ao **data** e `COleDateTime` tipos podem ser encontrados em [COleDateTime classe](../atl-mfc-shared/reference/coledatetime-class.md) e [data e hora: suporte de automação de](../atl-mfc-shared/date-and-time-automation-support.md).  
  
## <a name="see-also"></a>Consulte também  
 [Data e hora](../atl-mfc-shared/date-and-time.md)   
 [Classe COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md)

