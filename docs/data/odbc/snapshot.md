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
ms.openlocfilehash: 5999f89156d895ff0c87c892be892c6a614a0132
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59037640"
---
# <a name="snapshot"></a>Instantâneo

Um instantâneo é um conjunto de registros que reflete uma exibição estática dos dados conforme ele existia no momento em que o instantâneo foi criado. Quando você abre o instantâneo e move para todos os registros, o conjunto de registros que ele contém e seus valores não mudam até que você recria o instantâneo chamando `Requery`.

> [!NOTE]
>  Este tópico se aplica às classes ODBC do MFC. Se você estiver usando as classes MFC DAO, em vez das classes MFC ODBC, consulte [2&gt;cdaorecordset::Open&lt;2](../../mfc/reference/cdaorecordset-class.md#open) para obter uma descrição de conjuntos de registros do tipo de instantâneo.

Você pode criar instantâneos atualizáveis ou somente leitura com as classes de banco de dados. Ao contrário de dynaset, um instantâneo atualizável não reflete as alterações para gravar valores feitas por outros usuários, mas ele reflete as atualizações e exclusões feitas pelo seu programa. Registros adicionados a um instantâneo não se tornarão visíveis para o instantâneo até que você chame `Requery`.

> [!TIP]
>  Um instantâneo é um cursor estático do ODBC. Cursores estáticos não obter uma linha de dados, na verdade, até que você rola para esse registro. Para garantir que todos os registros são recuperados imediatamente, você pode rolar até o final do seu conjunto de registros e, em seguida, role até o primeiro registro que você deseja ver. No entanto, observe que a rolagem até o final envolve a sobrecarga extra e pode reduzir o desempenho.

Instantâneos são mais eficientes quando você precisa que os dados permaneçam fixos durante suas operações, como quando você estiver gerando um relatório ou executar cálculos. Mesmo assim, a fonte de dados pode divirjam consideravelmente o instantâneo, portanto, você talvez queira recriá-lo de tempos em tempos.

Suporte a instantâneo baseia-se a biblioteca de cursores ODBC, que fornece os cursores estáticos e posicionar atualizações (necessárias para a capacidade de atualização) para qualquer driver de nível 1. A DLL da biblioteca de cursor deve ser carregado na memória para esse suporte. Quando você constrói uma `CDatabase` objeto e chame seu `OpenEx` função de membro, você deve especificar o `CDatabase::useCursorLib` opção do *dwOptions* parâmetro. Se você chamar o `Open` função de membro, a biblioteca de cursores é carregada por padrão. Se você estiver usando dynasets em vez de instantâneos, você não deseja fazer com que a biblioteca de cursores a ser carregado.

Instantâneos estão disponíveis apenas se a biblioteca de cursores ODBC foi carregada quando o `CDatabase` objeto foi construído ou o driver ODBC que você está usando dá suporte a Cursores estáticos.

> [!NOTE]
>  Para alguns drivers ODBC, os instantâneos (Cursores estáticos) podem não ser atualizáveis. Verifique a documentação do driver para tipos de cursor com suporte e os tipos de simultaneidade, que eles oferecem suporte. Para garantir que os instantâneos atualizáveis, certifique-se de carregar a biblioteca de cursores na memória quando você cria um `CDatabase` objeto. Para obter mais informações, consulte [ODBC: A biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md).

> [!NOTE]
>  Se você quiser usar instantâneos e dynasets, você deve baseá-los em dois diferentes `CDatabase` objetos (duas conexões diferentes).

Para obter mais informações sobre o compartilhamento de instantâneos de propriedades com todos os conjuntos de registros, consulte [conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md). Para obter mais informações sobre o ODBC e instantâneos, incluindo a biblioteca de cursores ODBC, consulte [ODBC](../../data/odbc/odbc-basics.md).

## <a name="see-also"></a>Consulte também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)