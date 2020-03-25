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
ms.openlocfilehash: 62b5952f3052a3248175ce7892b1cf4615f1dd17
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212687"
---
# <a name="snapshot"></a>Instantâneo

Um instantâneo é um conjunto de registros que reflete uma exibição estática dos dados como eles existiam no momento em que o instantâneo foi criado. Quando você abre o instantâneo e move para todos os registros, o conjunto de registros que ele contém e seus valores não são alterados até que você reconstrua o instantâneo chamando `Requery`.

> [!NOTE]
>  Este tópico aplica-se às classes ODBC do MFC. Se você estiver usando as classes DAO do MFC em vez das classes ODBC do MFC, consulte [CDaoRecordset:: Open](../../mfc/reference/cdaorecordset-class.md#open) para obter uma descrição de conjuntos de registros do tipo instantâneo.

Você pode criar instantâneos atualizáveis ou somente leitura com as classes de banco de dados. Ao contrário de um dynaset, um instantâneo atualizável não reflete as alterações nos valores de registro feitos por outros usuários, mas reflete as atualizações e exclusões feitas por seu programa. Os registros adicionados a um instantâneo não se tornam visíveis para o instantâneo até que você chame `Requery`.

> [!TIP]
>  Um instantâneo é um cursor estático ODBC. Os cursores estáticos não obtêm realmente uma linha de dados até que você role para esse registro. Para garantir que todos os registros sejam recuperados imediatamente, role até o final do conjunto de registros e role até o primeiro registro que você deseja ver. No entanto, observe que a rolagem para o final envolve sobrecarga extra e pode reduzir o desempenho.

Os instantâneos são mais valiosos quando você precisa que os dados permaneçam fixos durante suas operações, como quando você está gerando um relatório ou realizando cálculos. Mesmo assim, a fonte de dados pode divergir consideravelmente do seu instantâneo, portanto, talvez você queira recriá-lo de tempos em tempos.

O suporte a instantâneos é baseado na biblioteca de cursores ODBC, que fornece cursores estáticos e atualizações posicionadas (necessárias para a atualização) para qualquer driver de nível 1. A DLL da biblioteca de cursores deve ser carregada na memória para esse suporte. Quando você constrói um objeto `CDatabase` e chama sua função de membro `OpenEx`, você deve especificar a opção `CDatabase::useCursorLib` do parâmetro *dwOptions* . Se você chamar a função de membro `Open`, a biblioteca de cursores será carregada por padrão. Se você estiver usando dynasets em vez de instantâneos, não deseja que a biblioteca de cursores seja carregada.

Os instantâneos só estarão disponíveis se a biblioteca de cursores ODBC tiver sido carregada quando o objeto de `CDatabase` foi construído ou se o driver ODBC que você está usando dá suporte a cursores estáticos.

> [!NOTE]
>  Para alguns drivers ODBC, os instantâneos (cursores estáticos) podem não ser atualizáveis. Verifique a documentação do driver para tipos de cursor com suporte e os tipos de simultaneidade aos quais eles dão suporte. Para garantir instantâneos atualizáveis, certifique-se de carregar a biblioteca de cursores na memória ao criar um objeto de `CDatabase`. Para obter mais informações, consulte [ODBC: a biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md).

> [!NOTE]
>  Se você quiser usar instantâneos e dynasets, deverá baseá-los em dois objetos de `CDatabase` diferentes (duas conexões diferentes).

Para obter mais informações sobre o compartilhamento de instantâneos de propriedades com todos os conjuntos de registros, consulte [Recordset (ODBC)](../../data/odbc/recordset-odbc.md). Para obter mais informações sobre ODBC e instantâneos, incluindo a biblioteca de cursores ODBC, consulte [ODBC](../../data/odbc/odbc-basics.md).

## <a name="see-also"></a>Confira também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)
