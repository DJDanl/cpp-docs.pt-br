---
title: 'Conjunto de registros: classificando registros (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- sorting data, recordset data
- ODBC recordsets, sorting
- recordsets, sorting
ms.assetid: b40b152e-0a91-452e-be7b-e5bc27f744c7
ms.openlocfilehash: 4bbe635cdda9152be6ba178b863147db93b7c706
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212739"
---
# <a name="recordset-sorting-records-odbc"></a>Conjunto de registros: classificando registros (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica como classificar seu conjunto de registros. Você pode especificar uma ou mais colunas nas quais basear a classificação e pode especificar ordem crescente ou decrescente (**ASC** ou **desc**; **ASC** é o padrão) para cada coluna especificada. Por exemplo, se você especificar duas colunas, os registros serão classificados primeiro na primeira coluna denominada e, em seguida, na segunda coluna denominada. Uma cláusula SQL **order by** define uma classificação. Quando a estrutura acrescenta a cláusula **order by** à consulta SQL do conjunto de registros, a cláusula controla a ordenação da seleção.

Você deve estabelecer a ordem de classificação de um conjunto de registros depois de construir o objeto, mas antes de chamar sua função de membro de `Open` (ou antes de chamar a função de membro `Requery` para um objeto Recordset existente cuja função de membro `Open` foi chamada anteriormente).

#### <a name="to-specify-a-sort-order-for-a-recordset-object"></a>Para especificar uma ordem de classificação para um objeto de conjunto de registros

1. Construa um novo objeto Recordset (ou prepare-se para chamar `Requery` para um existente).

1. Defina o valor do membro de dados do [m_strSort](../../mfc/reference/crecordset-class.md#m_strsort) do objeto.

   A classificação é uma cadeia de caracteres terminada em nulo. Ele contém o conteúdo da cláusula **order by** , mas não a palavra-chave **order by**. Por exemplo, use:

    ```
    recordset.m_strSort = "LastName DESC, FirstName DESC";
    ```

   não

    ```
    recordset.m_strSort = "ORDER BY LastName DESC, FirstName DESC";
    ```

1. Defina quaisquer outras opções necessárias, como um filtro, modo de bloqueio ou parâmetros.

1. Chame `Open` para o novo objeto (ou `Requery` para um objeto existente).

Os registros selecionados são ordenados conforme especificado. Por exemplo, para classificar um conjunto de registros de alunos em ordem decrescente por sobrenome e, em seguida, o nome, faça o seguinte:

```cpp
// Construct the recordset
CStudentSet rsStudent( NULL );
// Set the sort
rsStudent.m_strSort = "LastName DESC, FirstName DESC";
// Run the query with the sort in place
rsStudent.Open( );
```

O conjunto de registros contém todos os registros de aluno, classificados em ordem decrescente (Z a A) por sobrenome e, em seguida, por nome.

> [!NOTE]
>  Se você optar por substituir a cadeia de caracteres SQL padrão do conjunto de registros passando sua própria cadeia de caracteres SQL para `Open`, não defina uma classificação se a cadeia de caracteres personalizada tiver uma cláusula **order by** .

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md)<br/>
[Conjunto de registros: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md)
