---
title: 'ODBC: Biblioteca de cursores ODBC | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3d849580ce3e9b264c854633c6bb9f274874c21d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="odbc-the-odbc-cursor-library"></a>ODBC: a biblioteca de cursores ODBC
Este tópico descreve a biblioteca de cursores ODBC e explica como usá-lo. Para obter mais informações, consulte:  
  
-   [Drivers ODBC de nível 1 e de biblioteca de cursores](#_core_the_cursor_library_and_level_1_odbc_drivers)  
  
-   [Atualizações posicionadas e colunas de carimbo de hora](#_core_positioned_updates_and_timestamp_columns)  
  
-   [Usando a biblioteca de cursores](#_core_using_the_cursor_library)  
  
 A biblioteca de cursores ODBC é uma biblioteca de vínculo dinâmico (DLL) que reside entre o Gerenciador de Driver ODBC e o driver. Em termos ODBC, um driver mantém um cursor para controlar sua posição no conjunto de registros. O cursor marca a posição no conjunto de registros para o qual você já tenha acessado — o registro atual.  
  
##  <a name="_core_the_cursor_library_and_level_1_odbc_drivers"></a>Drivers ODBC de nível 1 e de biblioteca de cursores  
 A biblioteca de cursores ODBC fornece os seguintes novos recursos de drivers de nível 1:  
  
-   Rolagem para frente e para trás. Drivers de nível 2 não é necessário para a biblioteca de cursores porque eles já estão roláveis.  
  
-   Suporte para instantâneos. A biblioteca de cursores gerencia um buffer que contém os registros do instantâneo. Esse buffer reflete seu programa exclusões e modificações feitas registros, mas não as adições, exclusões ou edições de outros usuários. Portanto, o instantâneo é apenas atual como buffer da biblioteca de cursor. O buffer também não refletir suas próprias adições até que você chame **Requery**. Dynasets não use a biblioteca de cursores.  
  
 A biblioteca de cursores permite instantâneos (Cursores estáticos) mesmo que eles normalmente não são suportados pelo driver. Se o driver já oferece suporte a Cursores estáticos, você não precisa carregar a biblioteca de cursores para obter suporte de instantâneo. Se você usar a biblioteca de cursores, você pode usar somente os instantâneos e conjuntos de registros somente de encaminhamento. Se o driver suporta dynasets (cursores KEYSET_DRIVEN) e você quiser usá-los, você não deve usar a biblioteca de cursores. Se você quiser usar instantâneos e dynasets, você deve baseá-los em dois `CDatabase` objetos (duas conexões diferentes), a menos que o driver dá suporte a ambos.  
  
##  <a name="_core_positioned_updates_and_timestamp_columns"></a>Atualizações posicionadas e colunas de carimbo de hora  
  
> [!NOTE]
>  Fontes de dados ODBC são acessíveis por meio de classes MFC ODBC, conforme descrito neste tópico, ou as classes de objeto de acesso a dados MFC (DAO).  
  
> [!NOTE]
>  Se o driver ODBC dá suporte a **SQLSetPos**, quais MFC usa se estiver disponível, este tópico não se aplica a você.  
  
 A maioria dos drivers de nível 1 não dão suporte a atualizações posicionadas. Esses drivers contam com a biblioteca de cursores para emular os recursos de nível 2 drivers nesse sentido. A biblioteca de cursores emula suporte de atualização posicionada, fazendo uma atualização pesquisada nos campos inalterados.  
  
 Em alguns casos, um conjunto de registros pode conter uma coluna de carimbo de hora como um desses campos inalterados. Dois problemas podem surgir usando conjuntos de registros do MFC com tabelas que contêm colunas de carimbo de hora.  
  
 O primeiro problema relacionado instantâneos atualizáveis em tabelas com colunas de carimbo de hora. Se a tabela à qual o instantâneo está associado contém uma coluna de carimbo de hora, você deve chamar **Requery** depois de chamar **editar** e **atualização**. Caso contrário, você não poderá editar o mesmo registro novamente. Quando você chama **editar** e **atualização**, o registro é gravado para a fonte de dados e a coluna de carimbo de hora é atualizada. Se você não chama **Requery**, o valor de carimbo de hora para o registro no seu instantâneo não coincide mais com o carimbo de hora correspondente na fonte de dados. Quando você tentar atualizar o registro novamente, a fonte de dados pode não permitir a atualização devido a incompatibilidade.  
  
 O segundo problema se refere às limitações da classe [CTime](../../atl-mfc-shared/reference/ctime-class.md) quando usado com o `RFX_Date` função para transferir informações de data e hora para ou de uma tabela. Processamento de `CTime` objeto impõe uma sobrecarga na forma de processamento extra intermediário durante a transferência de dados. O intervalo de datas de `CTime` objetos também podem ser muito limitado para alguns aplicativos. Uma nova versão do `RFX_Date` função usa um ODBC **TIMESTAMP_STRUCT** parâmetro em vez de um `CTime` objeto. Para obter mais informações, consulte `RFX_Date` na [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md) no *referência MFC*.  

  
##  <a name="_core_using_the_cursor_library"></a>Usando a biblioteca de cursores  
 Quando você se conectar a uma fonte de dados — chamando [CDatabase::OpenEx](../../mfc/reference/cdatabase-class.md#openex) ou [CDatabase::Open](../../mfc/reference/cdatabase-class.md#open) — você pode especificar se deseja usar a biblioteca de cursor para a fonte de dados. Se você estará criando instantâneos na fonte de dados, especifique o **CDatabase::useCursorLib** opção o `dwOptions` parâmetro `OpenEx` ou especifique **TRUE** para o  **bUseCursorLib** parâmetro **abrir** (o valor padrão é **TRUE**). Se o driver ODBC dá suporte a dynasets e desejar abrir dynasets na fonte de dados, não use a biblioteca de cursores (mascara algumas funcionalidades de driver necessárias para dynasets). Nesse caso, não especifique **CDatabase::useCursorLib** na `OpenEx` ou especifique **FALSE** para o **bUseCursorLib** parâmetro **abrir**.  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas de ODBC](../../data/odbc/odbc-basics.md)