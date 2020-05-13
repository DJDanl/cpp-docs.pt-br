---
title: 'Conjunto de registros: filtrando registros (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- data [MFC], filtering
- recordsets [C++], filtering
- filtering recordsets
- ODBC recordsets [C++], filtering records
- filters [C++], recordset object
ms.assetid: 5c075f37-c837-464d-90c1-d028a9d1c175
ms.openlocfilehash: 56b8c4f52ec294f58a760e1309d32aa81286ddec
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367014"
---
# <a name="recordset-filtering-records-odbc"></a>Conjunto de registros: filtrando registros (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica como filtrar um conjunto de registros para que ele selecione apenas um subconjunto específico dos registros disponíveis. Por exemplo, você pode querer selecionar apenas as seções de classe para um determinado curso, como MATH101. Um filtro é uma condição de pesquisa definida pelo conteúdo de uma cláusula SQL **WHERE.** Quando o framework o anexa à declaração SQL do conjunto de registros, a cláusula **WHERE** restringe a seleção.

Você deve estabelecer o filtro de um objeto de conjunto `Open` de registros depois de `Requery` construir o objeto, mas antes `Open` de chamar sua função de membro (ou antes de chamar a função de membro para um objeto de conjunto de registros existente cuja função de membro foi chamada anteriormente).

#### <a name="to-specify-a-filter-for-a-recordset-object"></a>Para especificar um filtro para um objeto de conjunto de registros

1. Construa um novo objeto de `Requery` conjunto de registros (ou prepare-se para chamar para um objeto existente).

1. Defina o valor do membro de dados [m_strFilter](../../mfc/reference/crecordset-class.md#m_strfilter) do objeto.

   O filtro é uma seqüência de terminação nula que contém o conteúdo da cláusula SQL **WHERE,** mas não a palavra-chave **WHERE**. Por exemplo, use:

    ```
    m_pSet->m_strFilter = "CourseID = 'MATH101'";
    ```

   não

    ```
    m_pSet->m_strFilter = "WHERE CourseID = 'MATH101'";
    ```

    > [!NOTE]
    >  A seqüência literal "MATH101" é mostrada com aspas simples acima. Na especificação ODBC SQL, aspas únicas são usadas para denotar uma seqüência de caracteres literal. Verifique a documentação do driver ODBC para os requisitos de cotação do seu DBMS nesta situação. Essa sintaxe também é discutida mais perto do fim deste tópico.

1. Defina as outras opções necessárias, como ordem de classificação, modo de bloqueio ou parâmetros. Especificar um parâmetro é especialmente útil. Para obter informações sobre como parametrizar seu filtro, consulte [Recordset: Parametizando um Conjunto de Registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

1. Chamada `Open` para o novo `Requery` objeto (ou para um objeto aberto anteriormente).

> [!TIP]
> O uso de parâmetros no filtro é potencialmente o método mais eficiente para recuperar registros.

> [!TIP]
> Os filtros recordset são úteis para [juntar](../../data/odbc/recordset-performing-a-join-odbc.md) tabelas e para usar [parâmetros](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) com base nas informações obtidas ou calculadas no tempo de execução.

O conjunto de registros seleciona apenas os registros que atendem à condição de pesquisa especificada. Por exemplo, para especificar o filtro `strCourseID` de curso descrito acima (assumindo uma variável atualmente definida, por exemplo, para "MATH101"), faça o seguinte:

```
// Using the recordset pointed to by m_pSet

// Set the filter
m_pSet->m_strFilter = "CourseID = " + strCourseID;

// Run the query with the filter in place
if ( m_pSet->Open( CRecordset::snapshot, NULL, CRecordset::readOnly ) )

// Use the recordset
```

O conjunto de registros contém registros de todas as seções de classe para MATH101.

Observe como a seqüência de filtro foi definida no exemplo acima, usando uma variável de string. Este é o uso típico. Mas suponha que você queria especificar o valor literal 100 para o id curso. O código a seguir mostra como definir a seqüência de filtro corretamente com um valor literal:

```
m_strFilter = "StudentID = '100'";   // correct
```

Observe o uso de caracteres de citação única; se você definir a seqüência do filtro diretamente, a seqüência do filtro **não**é:

```
m_strFilter = "StudentID = 100";   // incorrect for some drivers
```

A citação mostrada acima está em conformidade com a especificação ODBC, mas alguns DBMSs podem exigir outros caracteres de citação. Para obter mais informações, consulte [SQL: Personalizando a Declaração SQL (ODBC) do seu recordset](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).

> [!NOTE]
> Se você optar por substituir a seqüência SQL padrão do conjunto `Open`de registros passando sua própria seqüência de SQL para , você não deve definir um filtro se a sua seqüência personalizada tiver uma cláusula **WHERE.** Para obter mais informações sobre como sobrepor o SQL padrão, consulte [SQL: Personalizando a Declaração SQL (ODBC) do seu recordset](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: classificando registros (ODBC)](../../data/odbc/recordset-sorting-records-odbc.md)<br/>
[Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)<br/>
[Conjunto de registros: como conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md)<br/>
[Conjunto de registros: bloqueando registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)
