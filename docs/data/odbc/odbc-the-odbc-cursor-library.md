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
ms.openlocfilehash: 13640dd2a8593057bef708a45dfc8471ba212563
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367189"
---
# <a name="odbc-the-odbc-cursor-library"></a>ODBC: a biblioteca de cursores ODBC

Este tópico descreve a Biblioteca do Cursor oDBC e explica como usá-la. Para obter mais informações, consulte:

- [Biblioteca cursor e drivers ODBC nível 1](#_core_the_cursor_library_and_level_1_odbc_drivers)

- [Atualizações posicionadas e colunas de carimbo de tempo](#_core_positioned_updates_and_timestamp_columns)

- [Usando a Biblioteca cursor](#_core_using_the_cursor_library)

A Biblioteca Cursor ODBC é uma biblioteca de link dinâmico (DLL) que reside entre o Gerenciador de Driver oDBC e o driver. Em termos ODBC, um motorista mantém um cursor para manter o controle de sua posição no conjunto de registros. O cursor marca a posição no conjunto de registros para o qual você já rolou — o registro atual.

## <a name="cursor-library-and-level-1-odbc-drivers"></a><a name="_core_the_cursor_library_and_level_1_odbc_drivers"></a>Biblioteca cursor e drivers ODBC nível 1

A Biblioteca Cursor ODBC oferece aos drivers de nível 1 os seguintes novos recursos:

- Rolagem para frente e para trás. Os drivers de nível 2 não precisam da biblioteca do cursor porque já são roláveis.

- Suporte para instantâneos. A biblioteca do cursor gerencia um buffer contendo os registros do snapshot. Este buffer reflete as exclusões e edições do seu programa para registros, mas não as adições, exclusões ou edições de outros usuários. Portanto, o instantâneo é tão atual quanto o buffer da biblioteca do cursor. O buffer também não reflete suas próprias adições até que você ligue `Requery`. Os dynasets não usam a biblioteca do cursor.

A biblioteca do cursor oferece instantâneos (cursores estáticos) mesmo que eles não sejam normalmente suportados pelo driver. Se o driver já suporta cursores estáticos, você não precisa carregar a biblioteca do cursor para obter suporte a instantâneos. Se você usar a biblioteca do cursor, você poderá usar apenas instantâneos e conjuntos de registros somente para a frente. Se o driver suportar dynasets (KEYSET_DRIVEN cursores) e você quiser usá-los, você não deve usar a biblioteca do cursor. Se você quiser usar instantâneos e dynasets, você `CDatabase` deve baseá-los em dois objetos diferentes (duas conexões diferentes) a menos que o driver suporte ambos.

## <a name="positioned-updates-and-timestamp-columns"></a><a name="_core_positioned_updates_and_timestamp_columns"></a>Atualizações posicionadas e colunas de carimbo de tempo

> [!NOTE]
> As fontes de dados ODBC são acessíveis através das classes MFC ODBC, conforme descrito neste tópico, ou através das classes DAO (Data Access Object, objeto de acesso de dados do MFC).

> [!NOTE]
> Se o driver ODBC for `SQLSetPos`suportado , que o MFC usa se disponível, este tópico não se aplica a você.

A maioria dos drivers de Nível 1 não suporta atualizações posicionadas. Esses drivers dependem da biblioteca do cursor para emular as capacidades dos drivers nível 2 a esse respeito. A biblioteca do cursor emula o suporte à atualização posicionada fazendo uma atualização pesquisada nos campos imutáveis.

Em alguns casos, um conjunto de registros pode conter uma coluna de carimbo de tempo como um desses campos imutáveis. Dois problemas surgem no uso de conjuntos de registros MFC com tabelas que contêm colunas de carimbo de tempo.

O primeiro problema diz respeito a instantâneos atualizáveis em tabelas com colunas de carimbo de tempo. Se a tabela à qual seu snapshot está vinculado `Requery` contiver `Edit` uma `Update`coluna de carimbo de data e hora, você deve ligar depois de ligar e . Se não, você pode não ser capaz de editar o mesmo registro novamente. Quando você `Edit` liga `Update`e, em seguida, o registro é gravado na fonte de dados e a coluna carimbo de tempo é atualizada. Se você não `Requery`ligar, o valor do carimbo de tempo para o registro em seu snapshot não corresponde mais ao carimbo de tempo correspondente na fonte de dados. Quando você tentar atualizar o registro novamente, a fonte de dados pode proibir a atualização por causa da incompatibilidade.

O segundo problema diz respeito a limitações `RFX_Date` do [Classe CTime](../../atl-mfc-shared/reference/ctime-class.md) quando usado com a função para transferir informações de data e hora para ou a partir de uma tabela. O processamento `CTime` do objeto impõe algumas sobrecargas na forma de processamento intermediário extra durante a transferência de dados. O intervalo `CTime` de datas de objetos também pode ser muito limitador para alguns aplicativos. Uma nova versão `RFX_Date` da função leva um parâmetro de `CTime` *TIMESTAMP_STRUCT* ODBC em vez de um objeto. Para obter mais `RFX_Date` informações, consulte [Em Macros e Globals](../../mfc/reference/mfc-macros-and-globals.md) na *Referência MFC*.

## <a name="using-the-cursor-library"></a><a name="_core_using_the_cursor_library"></a>Usando a Biblioteca cursor

Quando você se conecta a uma fonte de dados — ligando para [CDatabase::OpenEx](../../mfc/reference/cdatabase-class.md#openex) ou [CDatabase::Open](../../mfc/reference/cdatabase-class.md#open) — você pode especificar se deve usar a biblioteca do cursor para a fonte de dados. Se você estiver criando instantâneos nessa fonte `CDatabase::useCursorLib` de `dwOptions` dados, `OpenEx` especifique a opção no parâmetro `Open` ou especifique TRUE para o parâmetro *bUseCursorLib* para (o valor padrão é TRUE). Se o driver ODBC suportar dynasets e você quiser abrir dynasets na fonte de dados, não use a biblioteca do cursor (ela mascara algumas funcionalidades de driver necessárias para dynasets). Nesse caso, não `CDatabase::useCursorLib` `OpenEx` especifique ou especifique FALSE `Open`para o parâmetro *bUseCursorLib* em .

## <a name="see-also"></a>Confira também

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)
