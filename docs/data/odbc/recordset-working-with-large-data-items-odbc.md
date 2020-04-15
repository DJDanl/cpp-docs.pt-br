---
title: 'Conjunto de registros: trabalhando com itens de dados grandes (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- BLOB (binary large object), recordsets
- ODBC recordsets, binary large objects
- recordsets, binary large objects
- binary large objects
- CLongBinary class, using in recordsets
ms.assetid: 3e80b5a8-b6e7-43c6-a816-e54befc513a3
ms.openlocfilehash: 872fa7229738314b86b6ae6c0d5dc5a5562b27f1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360609"
---
# <a name="recordset-working-with-large-data-items-odbc"></a>Conjunto de registros: trabalhando com itens de dados grandes (ODBC)

Este tópico se aplica tanto às classes MFC ODBC quanto às classes DaO do MFC.

> [!NOTE]
> Se você estiver usando as classes DAO do MFC, gerencie seus itens de dados grandes com [cbytearray](../../mfc/reference/cbytearray-class.md) de classe em vez de [classe CLongBinary](../../mfc/reference/clongbinary-class.md). Se você estiver usando as classes MFC ODBC `CLongBinary` com `CByteArray`busca de linha em massa, use em vez de . Para obter mais informações sobre a busca de linhas em massa, consulte [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Suponha que seu banco de dados possa armazenar grandes pedaços de dados, como bitmaps (fotografias de funcionários, mapas, fotos de produtos, objetos OLE e assim por diante). Esse tipo de dados é frequentemente referido como um Objeto Grande Binário (ou BLOB) porque:

- Cada valor de campo é grande.

- Ao contrário de números e outros tipos de dados simples, ele não tem tamanho previsível.

- Os dados são sem forma da perspectiva do seu programa.

Este tópico explica o suporte que as classes de banco de dados fornecem para trabalhar com tais objetos.

## <a name="managing-large-objects"></a><a name="_core_managing_large_objects"></a>Gerenciamento de objetos grandes

Os conjuntos de registros têm duas maneiras de resolver a dificuldade especial de gerenciar objetos binários grandes. Você pode usar a classe [CByteArray](../../mfc/reference/cbytearray-class.md) ou pode usar a classe [CLongBinary](../../mfc/reference/clongbinary-class.md). Em geral, `CByteArray` é a maneira preferida de gerenciar grandes dados binários.

`CByteArray`requer mais `CLongBinary` sobrecarga do que é mais capaz, como descrito na [Classe CByteArray](#_core_the_cbytearray_class). `CLongBinary`é descrito brevemente em [The CLongBinary Class](#_core_the_clongbinary_class).

Para obter informações `CByteArray` detalhadas sobre o uso para trabalhar com itens de dados grandes, consulte [Nota Técnica 45](../../mfc/tn045-mfc-database-support-for-long-varchar-varbinary.md).

## <a name="cbytearray-class"></a><a name="_core_the_cbytearray_class"></a>Classe CByteArray

`CByteArray`é uma das classes de coleção do MFC. Um `CByteArray` objeto armazena uma matriz dinâmica de bytes — a matriz pode crescer se necessário. A classe fornece acesso rápido por índice, como acontece com os arrays C++ incorporados. `CByteArray`objetos podem ser serializados e despejados para fins diagnósticos. A classe fornece funções de membro para obter e definir bytes especificados, inserir e anexar bytes e remover um byte ou todos os bytes. Essas facilidades facilitam a análise dos dados binários. Por exemplo, se o objeto binário é um objeto OLE, você pode ter que trabalhar através de alguns bytes de cabeçalho para alcançar o objeto real.

## <a name="using-cbytearray-in-recordsets"></a><a name="_core_using_cbytearray_in_recordsets"></a>Usando CByteArray em conjuntos de registros

Ao fornecer a um membro de `CByteArray`dados de campo do seu conjunto de registros o tipo, você fornece uma base fixa a partir da qual o [RFX](../../data/odbc/record-field-exchange-rfx.md) pode gerenciar a transferência de tal objeto entre seu conjunto de registros e a fonte de dados e através do qual você pode manipular os dados dentro do objeto. O RFX precisa de um site específico para dados recuperados, e você precisa de uma maneira de acessar os dados subjacentes.

Para obter informações `CByteArray` detalhadas sobre o uso para trabalhar com itens de dados grandes, consulte [Nota Técnica 45](../../mfc/tn045-mfc-database-support-for-long-varchar-varbinary.md).

## <a name="clongbinary-class"></a><a name="_core_the_clongbinary_class"></a>Classe CLongBinary

Um objeto [CLongBinary](../../mfc/reference/clongbinary-class.md) é um `HGLOBAL` simples shell em torno de uma alça para um bloco de armazenamento alocado no heap. Quando ele liga uma coluna de tabela contendo um objeto `HGLOBAL` grande binário, o RFX aloca a alça quando `CLongBinary` precisa transferir os dados para o conjunto de registros e armazena a alça no campo do conjunto de registros.

Por sua vez, `HGLOBAL` você `m_hData`usa o cabo, para trabalhar com os dados em si, operando-os como você faria em qualquer conjunto de dados de manipulação. É aqui que [o CByteArray](../../mfc/reference/cbytearray-class.md) adiciona recursos.

> [!CAUTION]
> Os objetos CLongBinary não podem ser usados como parâmetros em chamadas de função. Além disso, sua implementação, que chama, `::SQLGetData`necessariamente retarda o desempenho de rolagem para um instantâneo rolável. Isso também pode ser verdade `::SQLGetData` quando você usa uma chamada para recuperar colunas dinâmicas de esquema.

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: obtendo SUMs e outros resultados agregados (ODBC)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md)<br/>
[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)
