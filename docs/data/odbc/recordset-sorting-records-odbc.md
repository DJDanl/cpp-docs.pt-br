---
title: 'Conjunto de registros: classificando registros (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- sorting data, recordset data
- ODBC recordsets, sorting
- recordsets, sorting
ms.assetid: b40b152e-0a91-452e-be7b-e5bc27f744c7
ms.openlocfilehash: 8b4deea1d8cbd4abe01ccc7a4114131378abe463
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366921"
---
# <a name="recordset-sorting-records-odbc"></a>Conjunto de registros: classificando registros (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica como classificar seu conjunto de registros. Você pode especificar uma ou mais colunas sobre as quais basear o tipo, e você pode especificar ordem ascendente ou descendente (**ASC** ou **DESC**; **ASC** é o padrão) para cada coluna especificada. Por exemplo, se você especificar duas colunas, os registros serão classificados primeiro na primeira coluna nomeada e, em seguida, na segunda coluna nomeada. Uma cláusula SQL **ORDER BY** define um tipo. Quando o framework anexa a cláusula **ORDER BY** à consulta SQL do conjunto de registros, a cláusula controla o pedido da seleção.

Você deve estabelecer a ordem de classificação de um conjunto `Open` de registros depois de `Requery` construir o objeto, mas `Open` antes de chamar sua função de membro (ou antes de chamar a função de membro para um objeto de conjunto de registros existente cuja função de membro foi chamada anteriormente).

#### <a name="to-specify-a-sort-order-for-a-recordset-object"></a>Para especificar uma ordem de classificação para um objeto de conjunto de registros

1. Construa um novo objeto de `Requery` conjunto de registros (ou prepare-se para chamar para um já existente).

1. Defina o valor do membro de dados [m_strSort](../../mfc/reference/crecordset-class.md#m_strsort) do objeto.

   O tipo é uma seqüência de nulos. Contém o conteúdo da cláusula **ORDEM POR,** mas não a palavra-chave **ORDEM POR**. Por exemplo, use:

    ```
    recordset.m_strSort = "LastName DESC, FirstName DESC";
    ```

   não

    ```
    recordset.m_strSort = "ORDER BY LastName DESC, FirstName DESC";
    ```

1. Defina as outras opções necessárias, como filtro, modo de bloqueio ou parâmetros.

1. Chamada `Open` para o novo `Requery` objeto (ou para um objeto existente).

Os registros selecionados são ordenados conforme especificado. Por exemplo, para classificar um conjunto de registros de estudantes em ordem decrescente por sobrenome, em seguida, primeiro nome, faça o seguinte:

```cpp
// Construct the recordset
CStudentSet rsStudent( NULL );
// Set the sort
rsStudent.m_strSort = "LastName DESC, FirstName DESC";
// Run the query with the sort in place
rsStudent.Open( );
```

O conjunto de registros contém todos os registros estudantis, classificados em ordem decrescente (Z a A) pelo sobrenome, em seguida, pelo primeiro nome.

> [!NOTE]
> Se você optar por substituir a seqüência SQL padrão do conjunto `Open`de registros, passando sua própria seqüência de sql para , não defina uma espécie se sua seqüência personalizada tiver uma cláusula **ORDER BY.**

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md)<br/>
[Conjunto de registros: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md)
