---
title: 'Conjunto de registros: Trabalhando com itens de dados grandes (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- BLOB (binary large object), recordsets
- ODBC recordsets, binary large objects
- recordsets, binary large objects
- binary large objects
- CLongBinary class, using in recordsets
ms.assetid: 3e80b5a8-b6e7-43c6-a816-e54befc513a3
ms.openlocfilehash: 3ba8d4af5b0781c425dd3b1223e2208b279f055e
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59033038"
---
# <a name="recordset-working-with-large-data-items-odbc"></a>Conjunto de registros: Trabalhando com itens de dados grandes (ODBC)

Este tópico aplica-se para as classes MFC ODBC e as classes MFC DAO.

> [!NOTE]
>  Se você estiver usando as classes MFC DAO, gerenciar os seus itens de dados grandes com a classe [CByteArray](../../mfc/reference/cbytearray-class.md) em vez da classe [CLongBinary](../../mfc/reference/clongbinary-class.md). Se você estiver usando as classes MFC ODBC com a busca de linhas em massa, use `CLongBinary` em vez de `CByteArray`. Para obter mais informações sobre a busca de linhas em massa, consulte [conjunto de registros: Buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Suponha que seu banco de dados pode armazenar grandes partes de dados, como bitmaps (fotografias de funcionário, mapas, imagens de produtos, objetos OLE e assim por diante). Esse tipo de dados é conhecido como um objeto binário grande (ou BLOB) porque:

- Cada valor de campo é grande.

- Diferentemente de números e outros tipos de dados simples, ela tem nenhum tamanho previsível.

- Os dados são formless da perspectiva do seu programa.

Este tópico explica o suporte as classes de banco de dados fornecem para trabalhar com esses objetos.

##  <a name="_core_managing_large_objects"></a> Gerenciamento de objetos grandes

Conjuntos de registros tem duas maneiras de resolver a dificuldade especial de gerenciar objetos binários grandes. Você pode usar a classe [CByteArray](../../mfc/reference/cbytearray-class.md) ou você pode usar a classe [CLongBinary](../../mfc/reference/clongbinary-class.md). Em geral, `CByteArray` é a maneira preferencial para gerenciar dados binários grandes.

`CByteArray` exige mais sobrecarga do que `CLongBinary` , mas tem mais capacidade, conforme descrito em [a classe CByteArray](#_core_the_cbytearray_class). `CLongBinary` é descrito resumidamente além [a classe CLongBinary](#_core_the_clongbinary_class).

Para obter informações detalhadas sobre como usar `CByteArray` para trabalhar com itens de dados grandes, consulte [45 de observação técnica](../../mfc/tn045-mfc-database-support-for-long-varchar-varbinary.md).

##  <a name="_core_the_cbytearray_class"></a> Classe CByteArray

`CByteArray` é uma das classes de coleção MFC. Um `CByteArray` objeto armazena uma matriz dinâmica de bytes — a matriz pode crescer, se necessário. A classe fornece acesso rápido por índice, assim como ocorre com matrizes de C++ internos. `CByteArray` objetos podem ser serializados e despejados para fins de diagnóstico. A classe fornece funções de membro para obter e definir os bytes especificados, inserindo e acrescentar bytes e remoção de um byte ou todos os bytes. Essas instalações tornar os dados binários mais fácil de análise. Por exemplo, se o objeto binário for um objeto OLE, você talvez precise trabalhar com alguns bytes de cabeçalho para alcançar o objeto real.

##  <a name="_core_using_cbytearray_in_recordsets"></a> Usando CByteArray em conjuntos de registros

Fornecendo o tipo de um membro de dados do campo de seu conjunto de registros `CByteArray`, você fornecer uma base fixa [RFX](../../data/odbc/record-field-exchange-rfx.md) pode gerenciar a transferência de tal objeto entre seu conjunto de registros e a fonte de dados e por meio do qual você pode manipular o dados de dentro do objeto. RFX precisa de um site específico para os dados recuperados, e você precisa de uma maneira de acessar os dados subjacentes.

Para obter informações detalhadas sobre como usar `CByteArray` para trabalhar com itens de dados grandes, consulte [45 de observação técnica](../../mfc/tn045-mfc-database-support-for-long-varchar-varbinary.md).

##  <a name="_core_the_clongbinary_class"></a> Classe CLongBinary

Um [CLongBinary](../../mfc/reference/clongbinary-class.md) objeto é um shell simple em torno de um `HGLOBAL` lidar com a um bloco de armazenamento alocado no heap. Quando ele se vincula a uma coluna de tabela que contém um objeto binário grande, RFX aloca a `HGLOBAL` tratar quando ele precisa transferir os dados para o conjunto de registros e armazena o identificador no `CLongBinary` campo do conjunto de registros.

Por sua vez, você usa o `HGLOBAL` tratar, `m_hData`, para trabalhar com os dados em si, operar nele, como você faria em qualquer manipular dados. É aí que [CByteArray](../../mfc/reference/cbytearray-class.md) adiciona recursos.

> [!CAUTION]
>  Objetos de CLongBinary não podem ser usados como parâmetros nas chamadas de função. Além disso, sua implementação, que chama `::SQLGetData`, necessariamente reduz o desempenho de rolagem para um instantâneo rolável. Isso também pode ser true ao usar um `::SQLGetData` chamar por conta própria para recuperar colunas do esquema dinâmico.

## <a name="see-also"></a>Consulte também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: Obtendo SUMs e outros resultados agregados (ODBC)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md)<br/>
[Registrar troca de campos (RFX)](../../data/odbc/record-field-exchange-rfx.md)