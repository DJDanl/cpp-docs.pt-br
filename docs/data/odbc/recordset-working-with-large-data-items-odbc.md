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
ms.openlocfilehash: b84365461ce6d45fccdf1922974feff5af93f99f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212752"
---
# <a name="recordset-working-with-large-data-items-odbc"></a>Conjunto de registros: trabalhando com itens de dados grandes (ODBC)

Este tópico aplica-se às classes ODBC do MFC e às classes do MFC DAO.

> [!NOTE]
>  Se você estiver usando as classes do MFC DAO, gerencie seus itens de dados grandes com a classe [CByteArray](../../mfc/reference/cbytearray-class.md) em vez da classe [CLongBinary](../../mfc/reference/clongbinary-class.md). Se você estiver usando as classes ODBC do MFC com a busca de linha em massa, use `CLongBinary` em vez de `CByteArray`. Para obter mais informações sobre a busca de linha em massa, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Suponha que o seu banco de dados possa armazenar grandes volumes, como bitmaps (fotografias de funcionários, mapas, imagens de produtos, objetos OLE e assim por diante). Esse tipo de dados geralmente é conhecido como um objeto binário grande (ou BLOB) porque:

- Cada valor de campo é grande.

- Ao contrário de números e outros tipos de dados simples, ele não tem tamanho previsível.

- Os dados não são formados da perspectiva do seu programa.

Este tópico explica o suporte que as classes de banco de dados fornecem para trabalhar com tais objetos.

##  <a name="managing-large-objects"></a><a name="_core_managing_large_objects"></a>Gerenciando objetos grandes

Os conjuntos de registros têm duas maneiras de resolver a dificuldade especial de gerenciar objetos binários grandes. Você pode usar a classe [CByteArray](../../mfc/reference/cbytearray-class.md) ou pode usar a classe [CLongBinary](../../mfc/reference/clongbinary-class.md). Em geral, `CByteArray` é a maneira preferida de gerenciar grandes dados binários.

`CByteArray` requer mais sobrecarga do que `CLongBinary`, mas é mais compatível, conforme descrito na [classe CByteArray](#_core_the_cbytearray_class). `CLongBinary` é descrito brevemente na [classe CLongBinary](#_core_the_clongbinary_class).

Para obter informações detalhadas sobre como usar `CByteArray` para trabalhar com itens de dados grandes, consulte a [Nota técnica 45](../../mfc/tn045-mfc-database-support-for-long-varchar-varbinary.md).

##  <a name="cbytearray-class"></a><a name="_core_the_cbytearray_class"></a>Classe CByteArray

`CByteArray` é uma das classes de coleção do MFC. Um objeto `CByteArray` armazena uma matriz dinâmica de bytes — a matriz pode crescer se necessário. A classe fornece acesso rápido por índice, como com C++ matrizes internas. `CByteArray` objetos podem ser serializados e despejados para fins de diagnóstico. A classe fornece funções de membro para obter e definir os bytes especificados, inserir e acrescentar bytes e remover um byte ou todos os bytes. Essas instalações facilitam a análise dos dados binários. Por exemplo, se o objeto binário for um objeto OLE, talvez seja necessário trabalhar com alguns bytes de cabeçalho para alcançar o objeto real.

##  <a name="using-cbytearray-in-recordsets"></a><a name="_core_using_cbytearray_in_recordsets"></a>Usando CByteArray em conjuntos de registros

Ao atribuir um membro de dados de campo de seu conjunto de registros o tipo `CByteArray`, você fornece uma base fixa da qual o [suporte RFX](../../data/odbc/record-field-exchange-rfx.md) pode gerenciar a transferência de tal objeto entre o conjunto de registros e a fonte de dados e por meio do qual você pode manipular os dados dentro do objeto. O suporte RFX precisa de um site específico para os dados recuperados, e você precisa de uma maneira de acessar os dados subjacentes.

Para obter informações detalhadas sobre como usar `CByteArray` para trabalhar com itens de dados grandes, consulte a [Nota técnica 45](../../mfc/tn045-mfc-database-support-for-long-varchar-varbinary.md).

##  <a name="clongbinary-class"></a><a name="_core_the_clongbinary_class"></a>Classe CLongBinary

Um objeto [CLongBinary](../../mfc/reference/clongbinary-class.md) é um shell simples em um identificador de `HGLOBAL` para um bloco de armazenamento alocado no heap. Quando ele vincula uma coluna de tabela que contém um objeto binário grande, o suporte RFX aloca o identificador de `HGLOBAL` quando precisa transferir os dados para o conjunto de registros e armazena o identificador no campo `CLongBinary` do conjunto de registros.

Por sua vez, você usa o identificador de `HGLOBAL`, `m_hData`, para trabalhar com os próprios dados, operando nele como faria em qualquer dado de identificador. É aí que o [CByteArray](../../mfc/reference/cbytearray-class.md) adiciona recursos.

> [!CAUTION]
>  Os objetos CLongBinary não podem ser usados como parâmetros nas chamadas de função. Além disso, sua implementação, que chama `::SQLGetData`, necessariamente reduz o desempenho de rolagem para um instantâneo rolável. Isso também pode ser verdadeiro quando você usa um `::SQLGetData` chamar a si mesmo para recuperar colunas de esquema dinâmico.

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: obtendo SUMs e outros resultados agregados (ODBC)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md)<br/>
[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)
