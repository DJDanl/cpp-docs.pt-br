---
title: Instantâneo
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC cursor library [ODBC], snapshots
- cursors [ODBC], static
- recordsets, snapshots
- snapshots, support in ODBC
- static cursors
- ODBC recordsets, snapshots
- cursor library [ODBC], snapshots
- snapshots
ms.assetid: b5293a52-0657-43e9-bd71-fe3785b21c7e
ms.openlocfilehash: e487b5abcc5eee4e3f4b1941100980eac4a040c8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366914"
---
# <a name="snapshot"></a>Instantâneo

Um snapshot é um conjunto de registros que reflete uma visão estática dos dados como existiam no momento em que o snapshot foi criado. Quando você abre o instantâneo e passa para todos os registros, o conjunto de registros `Requery`que ele contém e seus valores não mudam até que você reconstrua o instantâneo chamando .

> [!NOTE]
> Este tópico aplica-se às classes ODBC do MFC. Se você estiver usando as classes DaO do MFC em vez das classes MFC ODBC, consulte [CDaoRecordset::Abrir](../../mfc/reference/cdaorecordset-class.md#open) para obter uma descrição de conjuntos de registros do tipo snapshot.

Você pode criar instantâneos atualizáveis ou somente leitura com as classes de banco de dados. Ao contrário de um dynaset, um snapshot atualizável não reflete alterações nos valores de registro feitas por outros usuários, mas reflete atualizações e exclusões feitas pelo seu programa. Os registros adicionados a um instantâneo não `Requery`se tornam visíveis para o snapshot até que você ligue .

> [!TIP]
> Um instantâneo é um cursor estático ODBC. Os cursores estáticos não recebem uma linha de dados até que você role para esse registro. Para garantir que todos os registros sejam imediatamente recuperados, você pode rolar até o final do seu conjunto de discos e, em seguida, rolar até o primeiro registro que deseja ver. Note, no entanto, que rolar até o final implica sobrecarga extra e pode reduzir o desempenho.

Os snapshots são mais valiosos quando você precisa que os dados permaneçam fixos durante suas operações, como quando você está gerando um relatório ou realizando cálculos. Mesmo assim, a fonte de dados pode divergir consideravelmente do seu snapshot, então você pode querer reconstruí-lo de tempos em tempos.

O suporte ao snapshot é baseado na Biblioteca Cursor ODBC, que fornece cursores estáticos e atualizações posicionadas (necessárias para atualização) para qualquer driver de Nível 1. O DLL da biblioteca do cursor deve ser carregado na memória para este suporte. Quando você `CDatabase` constrói um `OpenEx` objeto e chama sua `CDatabase::useCursorLib` função de membro, você deve especificar a opção do parâmetro *dwOptions.* Se você `Open` chamar a função de membro, a biblioteca do cursor será carregada por padrão. Se você estiver usando dynasets em vez de snapshots, você não deseja fazer com que a biblioteca do cursor seja carregada.

Os instantâneos só estão disponíveis se a Biblioteca cursor oDBC tiver sido carregada quando o `CDatabase` objeto foi construído ou o driver ODBC que você está usando suporta cursores estáticos.

> [!NOTE]
> Para alguns drivers ODBC, instantâneos (cursores estáticos) podem não ser atualizáveis. Verifique a documentação do seu driver para os tipos de cursor suportados e os tipos de concorrência que eles suportam. Para garantir instantâneos atualizáveis, certifique-se de carregar a `CDatabase` biblioteca do cursor na memória quando criar um objeto. Para obter mais informações, consulte [ODBC: The ODBC Cursor Library](../../data/odbc/odbc-the-odbc-cursor-library.md).

> [!NOTE]
> Se você quiser usar instantâneos e dynasets, você `CDatabase` deve baseá-los em dois objetos diferentes (duas conexões diferentes).

Para obter mais informações sobre as propriedades que os snapshots compartilham com todos os conjuntos de registros, consulte [Recordset (ODBC)](../../data/odbc/recordset-odbc.md). Para obter mais informações sobre o ODBC e instantâneos, incluindo a Biblioteca Cursor da ODBC, consulte [ODBC](../../data/odbc/odbc-basics.md).

## <a name="see-also"></a>Confira também

[Conectividade de banco de dados aberto (ODBC)](../../data/odbc/open-database-connectivity-odbc.md)
