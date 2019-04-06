---
title: 'Conjunto de registros: Filtrando registros (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- data [MFC], filtering
- recordsets [C++], filtering
- filtering recordsets
- ODBC recordsets [C++], filtering records
- filters [C++], recordset object
ms.assetid: 5c075f37-c837-464d-90c1-d028a9d1c175
ms.openlocfilehash: 050524df840be28d661da89d04b685a44238f88c
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59041209"
---
# <a name="recordset-filtering-records-odbc"></a>Conjunto de registros: Filtrando registros (ODBC)

Este tópico se aplica às classes ODBC do MFC.

Este tópico explica como filtrar um conjunto de registros para que ele seleciona apenas um subconjunto específico de registros disponíveis. Por exemplo, você talvez queira selecionar apenas as seções de classe para um curso específico, como MATH101. Um filtro é um critério de pesquisa definido pelo conteúdo de um SQL **onde** cláusula. Quando o framework acrescenta à instrução de SQL do conjunto de registros, o **onde** cláusula restringe a seleção.

Você deve estabelecer o filtro do conjunto de registros de um objeto depois de construir o objeto, mas antes de chamar seus `Open` função de membro (ou antes de chamar o `Requery` função de membro para um conjunto de registros existente do objeto cuja `Open` tem de função de membro foi chamado anteriormente).

#### <a name="to-specify-a-filter-for-a-recordset-object"></a>Para especificar um filtro para um objeto recordset

1. Criar um novo objeto de conjunto de registros (ou se prepare para chamar `Requery` para um objeto existente).

1. Definir o valor do objeto [m_strFilter](../../mfc/reference/crecordset-class.md#m_strfilter) membro de dados.

   O filtro é uma cadeia de caracteres terminada em nulo que contém o conteúdo do SQL **onde** cláusula, mas não a palavra-chave **onde**. Por exemplo, use:

    ```
    m_pSet->m_strFilter = "CourseID = 'MATH101'";
    ```

   not

    ```
    m_pSet->m_strFilter = "WHERE CourseID = 'MATH101'";
    ```

    > [!NOTE]
    >  A cadeia de caracteres literal "MATH101" é mostrada com aspas simples acima. Na especificação do ODBC SQL, aspas simples são usadas para indicar um literal de cadeia de caracteres. Verifique a documentação do driver ODBC para os requisitos de aspas do DBMS nessa situação. Essa sintaxe também é discutido mais perto do final deste tópico.

1. Defina quaisquer outras opções que você precisa, como ordem de classificação, o modo de bloqueio ou parâmetros. Especificando um parâmetro é especialmente útil. Para obter informações sobre a parametrização de seu filtro, consulte [conjunto de registros: Parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

1. Chame `Open` para o novo objeto (ou `Requery` para um objeto aberto anteriormente).

> [!TIP]
>  Usar parâmetros em seu filtro potencialmente é o método mais eficiente para recuperação de registros.

> [!TIP]
>  Filtros de conjunto de registros são úteis para [unindo](../../data/odbc/recordset-performing-a-join-odbc.md) tabelas e para usar [parâmetros](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) com base nas informações obtidas ou calculados em tempo de execução.

O conjunto de registros seleciona somente os registros que atendem à condição de pesquisa especificado. Por exemplo especificar o filtro de curso descrita acima (supondo que uma variável `strCourseID` definido no momento, por exemplo, para "MATH101"), faça o seguinte:

```
// Using the recordset pointed to by m_pSet

// Set the filter
m_pSet->m_strFilter = "CourseID = " + strCourseID;

// Run the query with the filter in place
if ( m_pSet->Open( CRecordset::snapshot, NULL, CRecordset::readOnly ) )

// Use the recordset
```

O conjunto de registros contém registros para todas as seções de classe para MATH101.

Observe como a cadeia de caracteres de filtro foi definida no exemplo acima, usando uma variável de cadeia de caracteres. Este é o uso típico. Mas suponha que você queira especificar o valor literal 100 para a ID do curso. O código a seguir mostra como definir a cadeia de caracteres de filtro corretamente com um valor literal:

```
m_strFilter = "StudentID = '100'";   // correct
```

Observe o uso de caracteres de aspas simples; Se você definir a cadeia de caracteres de filtro diretamente, a cadeia de caracteres de filtro é **não**:

```
m_strFilter = "StudentID = 100";   // incorrect for some drivers
```

A delimitação mostrado acima está em conformidade com a especificação de ODBC, mas alguns DBMSs podem exigir outros caracteres de aspas. Para obter mais informações, consulte [SQL: Personalizando a instrução de SQL do seu conjunto de registros (ODBC)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).

> [!NOTE]
>  Se você optar por substituir a cadeia de caracteres do conjunto de registros padrão SQL passando sua própria cadeia de caracteres SQL para `Open`, você não deve definir um filtro se sua cadeia de caracteres personalizada tem uma **onde** cláusula. Para obter mais informações sobre como substituir o padrão SQL, consulte [SQL: Personalizando a instrução de SQL do seu conjunto de registros (ODBC)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).

## <a name="see-also"></a>Consulte também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: Classificando registros (ODBC)](../../data/odbc/recordset-sorting-records-odbc.md)<br/>
[Conjunto de registros: Como conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)<br/>
[Conjunto de registros: Como conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md)<br/>
[Conjunto de registros: Bloqueio de registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)