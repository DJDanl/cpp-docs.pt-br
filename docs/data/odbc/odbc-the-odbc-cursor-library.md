---
title: 'ODBC: A biblioteca de cursores ODBC'
ms.date: 11/04/2016
helpviewer_keywords:
- cursor library [ODBC]
- snapshots, support in ODBC
- timestamps, ODBC timestamp columns
- ODBC cursor library [ODBC]
- static cursors
- ODBC drivers, Level 1
- ODBC drivers, cursor support
- positioned updates
- cursors, ODBC cursor library
- Level 1 ODBC drivers
- cursor library [ODBC], snapshots
- ODBC, timestamp
- positioning cursors
ms.assetid: 6608db92-82b1-4164-bb08-78153c227be3
ms.openlocfilehash: 862303a0dc66fbd49bfcba83336ab29dfc7145c0
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59032226"
---
# <a name="odbc-the-odbc-cursor-library"></a>ODBC: A biblioteca de cursores ODBC

Este tópico descreve a biblioteca de cursores ODBC e explica como usá-lo. Para obter mais informações, consulte:

- [Drivers ODBC de nível 1 e de biblioteca de cursores](#_core_the_cursor_library_and_level_1_odbc_drivers)

- [Atualizações posicionadas e colunas de carimbo de hora](#_core_positioned_updates_and_timestamp_columns)

- [Usando a biblioteca de cursores](#_core_using_the_cursor_library)

A biblioteca de cursores ODBC é uma biblioteca de vínculo dinâmico (DLL) que reside entre o Gerenciador de Driver ODBC e o driver. Em termos ODBC, um driver mantém um cursor para manter o controle da sua posição no conjunto de registros. O cursor marca a posição no conjunto de registros para o qual você já percorreu — o registro atual.

##  <a name="_core_the_cursor_library_and_level_1_odbc_drivers"></a> Drivers ODBC de nível 1 e de biblioteca de cursores

A biblioteca de cursores ODBC fornece os seguintes novos recursos de drivers de nível 1:

- Rolagem para frente e para trás. Drivers de nível 2 não é necessário para a biblioteca de cursores porque eles já estão roláveis.

- Suporte para instantâneos. A biblioteca de cursores gerencia um buffer que contém os registros do instantâneo. Esse buffer reflete exclusões e as edições em registros, mas não as adições, exclusões ou edições de outros usuários de seu programa. Portanto, o instantâneo é apenas atual como buffer da biblioteca de cursor. O buffer também não reflete suas própria adições até que você chame `Requery`. Dynasets não use a biblioteca de cursores.

A biblioteca de cursores oferece instantâneos (Cursores estáticos), mesmo se eles normalmente não são suportados pelo driver. Se o seu driver já oferece suporte a Cursores estáticos, você precisa carregar a biblioteca de cursor para obter suporte de instantâneo. Se você usar a biblioteca de cursores, você pode usar somente os instantâneos e conjuntos de registros somente de encaminhamento. Se o driver dá suporte a dynasets (cursores KEYSET_DRIVEN) e você quiser usá-los, você não deve usar a biblioteca de cursores. Se você quiser usar instantâneos e dynasets, você deve baseá-los em dois diferentes `CDatabase` objetos (duas conexões diferentes), a menos que o driver dá suporte a ambos.

##  <a name="_core_positioned_updates_and_timestamp_columns"></a> Atualizações posicionadas e colunas de carimbo de hora

> [!NOTE]
>  Fontes de dados ODBC são acessíveis por meio de classes MFC ODBC, conforme descrito neste tópico, ou as classes de objeto de acesso a dados MFC (DAO).

> [!NOTE]
>  Se o driver ODBC dá suporte a `SQLSetPos`, quais MFC usa se estiver disponível, este tópico não se aplica a você.

A maioria dos drivers de nível 1 não dão suporte a atualizações posicionadas. Esses drivers contam com a biblioteca de cursores para emular os recursos de nível 2 drivers em relação a isso. A biblioteca de cursores emula o suporte de atualização posicionada, fazendo uma atualização pesquisada nos campos de inalterável.

Em alguns casos, um conjunto de registros pode conter uma coluna de carimbo de hora como um desses campos inalterados. Dois problemas podem surgir usando conjuntos de registros do MFC com tabelas que contêm colunas de carimbo de hora.

O primeiro problema diz respeito a instantâneos atualizáveis em tabelas com colunas de carimbo de hora. Se a tabela à qual o instantâneo está associado contiver uma coluna de carimbo de hora, você deve chamar `Requery` depois de chamar `Edit` e `Update`. Caso contrário, você não poderá editar o mesmo registro novamente. Quando você chama `Edit` e, em seguida, `Update`, o registro é gravado para a fonte de dados e a coluna de carimbo de hora é atualizada. Se você não chamar `Requery`, o valor de carimbo de hora para o registro em seu instantâneo não coincide mais com o carimbo de hora correspondente na fonte de dados. Quando você tenta atualizar o registro novamente, a fonte de dados pode não permitir a atualização devido a incompatibilidade.

O segundo problema se refere às limitações da classe [CTime](../../atl-mfc-shared/reference/ctime-class.md) quando usado com o `RFX_Date` função para transferir informações de data e hora para ou de uma tabela. Processando o `CTime` objeto impõe uma sobrecarga na forma de processamento intermediária extra durante a transferência de dados. O intervalo de datas de `CTime` objetos também podem ser muito limitado para alguns aplicativos. Uma nova versão dos `RFX_Date` função usa um ODBC *TIMESTAMP_STRUCT* parâmetro em vez de um `CTime` objeto. Para obter mais informações, consulte `RFX_Date` na [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md) no *referência da MFC*.

##  <a name="_core_using_the_cursor_library"></a> Usando a biblioteca de cursores

Quando você se conecta a uma fonte de dados — chamando [CDatabase:: Openex](../../mfc/reference/cdatabase-class.md#openex) ou [CDatabase:: Open](../../mfc/reference/cdatabase-class.md#open) — você pode especificar se deseja usar a biblioteca de cursor para a fonte de dados. Se você estará criando instantâneos na fonte de dados, especifique o `CDatabase::useCursorLib` opção a `dwOptions` parâmetro para `OpenEx` ou especificar TRUE para o *bUseCursorLib* parâmetro para `Open` (o valor padrão é TRUE). Se o driver ODBC dá suporte a dynasets e desejar abrir dynasets na fonte de dados, não use a biblioteca de cursores (mascara algumas funcionalidades de driver necessárias para dynasets). Nesse caso, não especifique `CDatabase::useCursorLib` na `OpenEx` ou especifique FALSE para o *bUseCursorLib* parâmetro em `Open`.

## <a name="see-also"></a>Consulte também

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)