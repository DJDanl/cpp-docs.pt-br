---
title: 'ODBC: a biblioteca de cursores ODBC'
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
ms.openlocfilehash: 51524604cad34ace18ffda2b5f48cc3c5fd89ad7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213090"
---
# <a name="odbc-the-odbc-cursor-library"></a>ODBC: a biblioteca de cursores ODBC

Este tópico descreve a biblioteca de cursores ODBC e explica como usá-la. Para obter mais informações, consulte:

- [Biblioteca de cursores e drivers ODBC de nível 1](#_core_the_cursor_library_and_level_1_odbc_drivers)

- [Atualizações posicionadas e colunas de carimbo de data/hora](#_core_positioned_updates_and_timestamp_columns)

- [Usando a biblioteca de cursores](#_core_using_the_cursor_library)

A biblioteca de cursores ODBC é uma DLL (biblioteca de vínculo dinâmico) que reside entre o Gerenciador de driver ODBC e o driver. Em termos de ODBC, um driver mantém um cursor para acompanhar sua posição no conjunto de registros. O cursor marca a posição no conjunto de registros para o qual você já rolou — o registro atual.

##  <a name="cursor-library-and-level-1-odbc-drivers"></a><a name="_core_the_cursor_library_and_level_1_odbc_drivers"></a>Biblioteca de cursores e drivers ODBC de nível 1

A biblioteca de cursores ODBC fornece aos drivers de nível 1 os seguintes novos recursos:

- Rolagem para frente e para trás. Os drivers de nível 2 não precisam da biblioteca de cursores porque já estão roláveis.

- Suporte para instantâneos. A biblioteca de cursores gerencia um buffer que contém os registros do instantâneo. Esse buffer reflete as exclusões e edições do programa em registros, mas não as adições, exclusões ou edições de outros usuários. Portanto, o instantâneo é apenas o atual como o buffer da biblioteca de cursores. O buffer também não reflete suas próprias adições até que você chame `Requery`. Os dynasets não usam a biblioteca de cursores.

A biblioteca de cursores fornece instantâneos (cursores estáticos) mesmo que eles normalmente não tenham suporte do seu driver. Se o driver já der suporte a cursores estáticos, não será necessário carregar a biblioteca de cursores para obter suporte de instantâneo. Se você usar a biblioteca de cursores, poderá usar somente instantâneos e conjuntos de registros somente de encaminhamento. Se o driver oferecer suporte a dynasets (KEYSET_DRIVEN cursores) e você quiser usá-los, você não deverá usar a biblioteca de cursores. Se você quiser usar instantâneos e dynasets, deverá baseá-los em dois objetos de `CDatabase` diferentes (duas conexões diferentes), a menos que o driver ofereça suporte a ambos.

##  <a name="positioned-updates-and-timestamp-columns"></a><a name="_core_positioned_updates_and_timestamp_columns"></a>Atualizações posicionadas e colunas de carimbo de data/hora

> [!NOTE]
>  As fontes de dados ODBC podem ser acessadas por meio das classes ODBC do MFC, conforme descrito neste tópico ou por meio das classes DAO (objeto de acesso a dados) do MFC.

> [!NOTE]
>  Se o driver ODBC oferecer suporte a `SQLSetPos`, que o MFC usará se estiver disponível, este tópico não se aplicará a você.

A maioria dos drivers de nível 1 não oferece suporte a atualizações posicionadas. Esses drivers dependem da biblioteca de cursores para emular os recursos dos drivers de nível 2 nesse aspecto. A biblioteca de cursores emula o suporte à atualização posicionada fazendo uma atualização pesquisada nos campos inalterados.

Em alguns casos, um conjunto de registros pode conter uma coluna de carimbo de data/hora como um dos campos inalterados. Dois problemas surgem no uso de conjuntos de registros do MFC com tabelas que contêm colunas de carimbo de data/hora.

O primeiro problema diz respeito a instantâneos atualizáveis em tabelas com colunas timestamp. Se a tabela à qual o instantâneo está associado contiver uma coluna de carimbo de data/hora, você deverá chamar `Requery` depois de chamar `Edit` e `Update`. Caso contrário, talvez você não consiga editar o mesmo registro novamente. Quando você chama `Edit` e, em seguida, `Update`, o registro é gravado na fonte de dados e a coluna timestamp é atualizada. Se você não chamar `Requery`, o valor do carimbo de data/hora do registro em seu instantâneo não corresponderá mais ao carimbo de data/hora correspondente na fonte de dados. Quando você tenta atualizar o registro novamente, a fonte de dados pode não permitir a atualização devido à incompatibilidade.

O segundo problema se refere a limitações da classe [CTime](../../atl-mfc-shared/reference/ctime-class.md) quando usado com a função `RFX_Date` para transferir informações de data e hora de ou para uma tabela. O processamento do objeto `CTime` impõe alguma sobrecarga na forma de processamento intermediário extra durante a transferência de dados. O intervalo de datas de objetos `CTime` também pode ser muito limitado para alguns aplicativos. Uma nova versão da função `RFX_Date` usa um parâmetro ODBC *TIMESTAMP_STRUCT* em vez de um objeto `CTime`. Para obter mais informações, consulte `RFX_Date` em [macros e globais](../../mfc/reference/mfc-macros-and-globals.md) na *referência do MFC*.

##  <a name="using-the-cursor-library"></a><a name="_core_using_the_cursor_library"></a>Usando a biblioteca de cursores

Quando você se conecta a uma fonte de dados — chamando [CDatabase:: OpenEx](../../mfc/reference/cdatabase-class.md#openex) ou [CDatabase:: Open](../../mfc/reference/cdatabase-class.md#open) — você pode especificar se deseja usar a biblioteca de cursores para a fonte de dados. Se você for criar instantâneos nessa fonte de dados, especifique a opção `CDatabase::useCursorLib` no parâmetro `dwOptions` como `OpenEx` ou especifique TRUE para o parâmetro *bUseCursorLib* como `Open` (o valor padrão é true). Se o driver ODBC oferecer suporte a dynasets e você quiser abrir os dynasets na fonte de dados, não use a biblioteca de cursores (ele mascara algumas funcionalidades de driver necessárias para os dynasets). Nesse caso, não especifique `CDatabase::useCursorLib` em `OpenEx` ou especifique FALSE para o parâmetro *bUseCursorLib* no `Open`.

## <a name="see-also"></a>Confira também

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)
