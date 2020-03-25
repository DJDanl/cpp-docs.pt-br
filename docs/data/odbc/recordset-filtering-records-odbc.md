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
ms.openlocfilehash: 2e742ee02e142fd87df3f149379d9971c4acd166
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212896"
---
# <a name="recordset-filtering-records-odbc"></a>Conjunto de registros: filtrando registros (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica como filtrar um conjunto de registros para que ele selecione apenas um determinado subconjunto dos registros disponíveis. Por exemplo, talvez você queira selecionar apenas as seções de classe de um curso específico, como MATH101. Um filtro é um critério de pesquisa definido pelo conteúdo de uma cláusula SQL **Where** . Quando a estrutura a anexa à instrução SQL do conjunto de registros, a cláusula **Where** restringe a seleção.

Você deve estabelecer um filtro de objeto Recordset depois de construir o objeto, mas antes de chamar sua função de membro `Open` (ou antes de chamar a função de membro `Requery` para um objeto Recordset existente cuja função de membro `Open` foi chamada anteriormente).

#### <a name="to-specify-a-filter-for-a-recordset-object"></a>Para especificar um filtro para um objeto Recordset

1. Construa um novo objeto Recordset (ou prepare-se para chamar `Requery` para um objeto existente).

1. Defina o valor do membro de dados do [m_strFilter](../../mfc/reference/crecordset-class.md#m_strfilter) do objeto.

   O filtro é uma cadeia de caracteres terminada em nulo que contém o conteúdo da cláusula **Where** do SQL, mas não a palavra-chave **Where**. Por exemplo, use:

    ```
    m_pSet->m_strFilter = "CourseID = 'MATH101'";
    ```

   não

    ```
    m_pSet->m_strFilter = "WHERE CourseID = 'MATH101'";
    ```

    > [!NOTE]
    >  A cadeia de caracteres literal "MATH101" é mostrada com aspas simples acima. Na especificação ODBC SQL, aspas simples são usadas para denotar um literal de cadeia de caracteres. Verifique a documentação do driver ODBC para os requisitos de cotação do DBMS nessa situação. Essa sintaxe também é discutida ainda mais próximo ao final deste tópico.

1. Defina quaisquer outras opções necessárias, como ordem de classificação, modo de bloqueio ou parâmetros. A especificação de um parâmetro é especialmente útil. Para obter informações sobre como parametrizar o filtro, consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

1. Chame `Open` para o novo objeto (ou `Requery` para um objeto aberto anteriormente).

> [!TIP]
>  Usar parâmetros em seu filtro é potencialmente o método mais eficiente para recuperar registros.

> [!TIP]
>  Os filtros do conjunto de registros são úteis para [unir](../../data/odbc/recordset-performing-a-join-odbc.md) tabelas e usar [parâmetros](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) com base nas informações obtidas ou calculadas em tempo de execução.

O conjunto de registros seleciona somente os registros que atendem ao critério de pesquisa especificado. Por exemplo, para especificar o filtro do curso descrito acima (supondo que uma variável `strCourseID` definida atualmente, por exemplo, para "MATH101"), faça o seguinte:

```
// Using the recordset pointed to by m_pSet

// Set the filter
m_pSet->m_strFilter = "CourseID = " + strCourseID;

// Run the query with the filter in place
if ( m_pSet->Open( CRecordset::snapshot, NULL, CRecordset::readOnly ) )

// Use the recordset
```

O conjunto de registros contém registros para todas as seções de classe para MATH101.

Observe como a cadeia de caracteres de filtro foi definida no exemplo acima, usando uma variável de cadeia de caracteres. Esse é o uso típico. Mas suponha que você queria especificar o valor literal 100 para a ID do curso. O código a seguir mostra como definir a cadeia de caracteres de filtro corretamente com um valor literal:

```
m_strFilter = "StudentID = '100'";   // correct
```

Observe o uso de caracteres de aspas simples; Se você definir a cadeia de caracteres de filtro diretamente, a cadeia de caracteres de filtro **não**será:

```
m_strFilter = "StudentID = 100";   // incorrect for some drivers
```

A cotação mostrada acima está em conformidade com a especificação ODBC, mas alguns DBMSs podem exigir outros caracteres de aspas. Para obter mais informações, consulte [SQL: Personalizando a instrução SQL do conjunto de registros (ODBC)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).

> [!NOTE]
>  Se você optar por substituir a cadeia de caracteres SQL padrão do conjunto de registros passando sua própria cadeia de caracteres SQL para `Open`, não deverá definir um filtro se a cadeia de caracteres personalizada tiver uma cláusula **Where** . Para obter mais informações sobre como substituir o SQL padrão, consulte [SQL: Personalizando a instrução SQL do conjunto de registros (ODBC)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: classificando registros (ODBC)](../../data/odbc/recordset-sorting-records-odbc.md)<br/>
[Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)<br/>
[Conjunto de registros: como conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md)<br/>
[Conjunto de registros: bloqueando registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)
