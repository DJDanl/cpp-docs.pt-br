---
title: 'SQL: Personalizando a instrução de SQL do seu conjunto de registros (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- recordsets, SQL statements
- ODBC recordsets, SQL statements
- SQL statements, customizing
- SQL statements, recordset
- customizing SQL statements
- overriding, SQL statements
- SQL, opening recordsets
ms.assetid: 72293a08-cef2-4be2-aa1c-30565fcfbaf9
ms.openlocfilehash: eabaab019ee94b0c5617573c534d920ec710e9b2
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59036189"
---
# <a name="sql-customizing-your-recordsets-sql-statement-odbc"></a>SQL: Personalizando a instrução de SQL do seu conjunto de registros (ODBC)

Este tópico explica:

- Como o framework constrói uma instrução SQL

- Como substituir a instrução SQL

> [!NOTE]
>  Essas informações se aplicam às classes ODBC do MFC. Se você estiver trabalhando com as classes MFC DAO, consulte o tópico "Comparação do banco de dados de mecanismo de SQL e ANSI SQL do Microsoft Jet" na Ajuda do DAO.

## <a name="sql-statement-construction"></a>Construção de instrução SQL

Seleção de registro principalmente em um SQL de bases de seu conjunto de registros **selecionar** instrução. Quando você declara sua classe com um assistente, ele grava uma versão de substituição do `GetDefaultSQL` função de membro que pode ter esta aparência (para uma classe de conjunto de registros chamado `CAuthors`).

```cpp
CString CAuthors::GetDefaultSQL()
{
    return "AUTHORS";
}
```

Por padrão, essa substituição retorna o nome da tabela especificada com o assistente. No exemplo, o nome da tabela é "Autores". Quando você chama o conjunto de registros mais tarde `Open` função de membro `Open` constrói um final **selecione** instrução do formulário:

```
SELECT rfx-field-list FROM table-name [WHERE m_strFilter]
       [ORDER BY m_strSort]
```

em que `table-name` é obtida chamando `GetDefaultSQL` e `rfx-field-list` é obtido de chamadas de função a RFX em `DoFieldExchange`. Isso é o que você obtém uma **selecionar** instrução, a menos que você substituí-lo com uma versão de substituição em tempo de execução, embora você também pode modificar a instrução padrão com parâmetros ou um filtro.

> [!NOTE]
>  Se você especificar um nome de coluna que contém espaços (ou pode conter uma), você deve colocar o nome entre colchetes. Por exemplo, o nome "First Name" deve ser "[nome]".

Para substituir o padrão **selecionar** instrução, passe uma cadeia de caracteres que contém uma completa **selecionar** instrução ao chamar `Open`. Em vez de construir sua própria cadeia de caracteres padrão, o conjunto de registros usa a cadeia de caracteres que você fornecer. Se a instrução de substituição contiver uma **onde** cláusula, não especifique um filtro em `m_strFilter` porque, em seguida, você teria duas instruções de filtro. Da mesma forma, se a instrução de substituição contiver uma **ORDER BY** cláusula, não especifique uma classificação em `m_strSort` para que você não terá duas instruções de classificação.

> [!NOTE]
>  Se você usar cadeias de caracteres literais em seus filtros (ou outras partes da instrução SQL), você talvez precise "quote" (coloque entre delimitadores especificados) como cadeias de caracteres com um prefixo de literal específicos de DBMS e literal sufixo caractere (ou caracteres).

Você também pode encontrar os requisitos sintáticos especiais para operações como junções externas, dependendo de seu DBMS. Use funções ODBC para obter essas informações de seu driver para o DBMS. Por exemplo, chamar `::SQLGetTypeInfo` para um tipo de dados específico, como `SQL_VARCHAR`, para solicitar o LITERAL_PREFIX e LITERAL_SUFFIX caracteres. Se você estiver escrevendo código independente de banco de dados, consulte [apêndice c: Gramática SQL](/sql/odbc/reference/appendixes/appendix-c-sql-grammar) no [referência do programador de ODBC](/sql/odbc/reference/odbc-programmer-s-reference) para informações detalhadas de sintaxe.

Um objeto recordset constrói a instrução SQL que ele usa para selecionar registros a menos que você passe uma instrução SQL personalizada. Como isso é feito depende principalmente o valor que você passe o *lpszSQL* parâmetro do `Open` função de membro.

A forma geral de um SQL **selecionar** instrução é:

```
SELECT [ALL | DISTINCT] column-list FROM table-list
    [WHERE search-condition][ORDER BY column-list [ASC | DESC]]
```

É uma maneira de adicionar o **DISTINCT** palavra-chave para a instrução de SQL do seu conjunto de registros é inserir a palavra-chave na primeira chamada de função RFX em `DoFieldExchange`. Por exemplo:

```
...
    RFX_Text(pFX, "DISTINCT CourseID", m_strCourseID);
...
```

> [!NOTE]
>  Use essa técnica somente com um conjunto de registros aberto como somente leitura.

## <a name="overriding-the-sql-statement"></a>Substituindo a instrução SQL

A tabela a seguir mostra as possibilidades para o *lpszSQL* parâmetro `Open`. Os casos na tabela são explicados a tabela a seguir.

**O parâmetro lpszSQL e a cadeia de caracteres resultante do SQL**

|Caso|O que você passe lpszSQL|Na declaração SELECT resultante|
|----------|------------------------------|------------------------------------|
|1|NULL|**SELECT** *rfx-field-list* **FROM** *table-name*<br /><br /> `CRecordset::Open` chamadas `GetDefaultSQL` para obter o nome da tabela. A cadeia de caracteres resultante é um dos casos de 2 a 5, dependendo do que `GetDefaultSQL` retorna.|
|2|Um nome de tabela|**SELECT** *rfx-field-list* **FROM** *table-name*<br /><br /> A lista de campos é obtida das instruções RFX em `DoFieldExchange`. Se `m_strFilter` e `m_strSort` não estão vazios, adiciona a **onde** e/ou **ORDER BY** cláusulas.|
|3 \*|Uma completa **selecionar** instrução, mas sem uma **onde** ou **ORDER BY** cláusula|Como aprovado. Se `m_strFilter` e `m_strSort` não estão vazios, adiciona a **onde** e/ou **ORDER BY** cláusulas.|
|4 \*|Uma completa **selecionar** instrução com um **onde** e/ou **ORDER BY** cláusula|Como aprovado. `m_strFilter` e/ou `m_strSort` deve permanecer vazio ou um filtro de duas e/ou instruções de classificação são produzidas.|
|5 \*|Uma chamada para um procedimento armazenado|Como aprovado.|

\* `m_nFields` deve ser menor ou igual ao número de colunas especificadas na **selecionar** instrução. O tipo de dados de cada coluna especificada na **selecionar** instrução deve ser o mesmo que o tipo de dados da coluna de saída RFX correspondente.

### <a name="case-1---lpszsql--null"></a>Caso 1 lpszSQL = NULL

A seleção de conjunto de registros depende de qual `GetDefaultSQL` retorna quando `CRecordset::Open` vai chamá-lo. Casos de 2 a 5 descrevem as cadeias de caracteres possíveis.

### <a name="case-2---lpszsql--a-table-name"></a>Caso 2 lpszSQL = um nome de tabela

O conjunto de registros usa registrar troca de campos (RFX) para criar a lista de colunas de nomes de coluna fornecido a RFX função chama na substituição da classe de conjunto de registros de `DoFieldExchange`. Se você usou um Assistente para declarar sua classe de conjunto de registros, neste caso, tem o mesmo resultado que caso 1 (desde que você passar o mesmo nome da tabela especificada no Assistente). Se você não usar um Assistente para gravar sua classe, caso 2 é a maneira mais simples para construir a instrução SQL.

O exemplo a seguir constrói uma instrução SQL que seleciona os registros de um aplicativo de banco de dados do MFC. Quando o framework chama o `GetDefaultSQL` função de membro, a função retorna o nome da tabela, `SECTION`.

```cpp
CString CEnrollSet::GetDefaultSQL()
{
    return "SECTION";
}
```

Para obter os nomes das colunas do SQL **selecionar** instrução, a estrutura chama o `DoFieldExchange` função de membro.

```cpp
void CEnrollSet::DoFieldExchange(CFieldExchange* pFX)
{
    pFX->SetFieldType(CFieldExchange::outputColumn);
    RFX_Text(pFX, "CourseID", m_strCourseID);
    RFX_Text(pFX, "InstructorID", m_strInstructorID);
    RFX_Text(pFX, "RoomNo", m_strRoomNo);
    RFX_Text(pFX, "Schedule", m_strSchedule);
    RFX_Text(pFX, "SectionNo", m_strSectionNo);
}
```

Ao concluir, a instrução SQL terá esta aparência:

```sql
SELECT CourseID, InstructorID, RoomNo, Schedule, SectionNo
    FROM SECTION
```

### <a name="case-3---lpszsql--a-selectfrom-statement"></a>Case 3   lpszSQL = a SELECT/FROM Statement

Especifique a lista de colunas manualmente em vez de depender RFX construí-la automaticamente. Talvez você queira fazer isso quando:

- Para especificar o **DISTINCT** seguinte palavra-chave **selecione**.

   Sua lista de colunas deve corresponder os nomes de coluna e tipos na mesma ordem conforme estão listadas no `DoFieldExchange`.

- Você tem razão para recuperar manualmente os valores de coluna usando a função ODBC `::SQLGetData` em vez de depender RFX associar e recuperar colunas para você.

   Por exemplo, convém acomodar novas colunas adicionado de um cliente do seu aplicativo para as tabelas de banco de dados depois que o aplicativo foi distribuído. Você precisará adicionar esses membros de dados do campo extra, que não eram conhecidos durante o tempo que você declarou a classe com um assistente.

   Sua lista de colunas deve corresponder os nomes de coluna e tipos na mesma ordem conforme estão listadas no `DoFieldExchange`, seguido pelos nomes das colunas associadas manualmente. Para obter mais informações, consulte [conjunto de registros: Associando dinamicamente colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

- Você deseja associar tabelas especificando várias tabelas na **FROM** cláusula.

   Para obter informações e um exemplo, consulte [conjunto de registros: Realizando uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md).

### <a name="case-4---lpszsql--selectfrom-plus-where-andor-order-by"></a>Caso 4 lpszSQL = SELECT / FROM e WHERE e/ou ORDER BY

Que tudo o que você especificar: a lista de colunas (com base nas chamadas RFX `DoFieldExchange`), a lista de tabelas e o conteúdo de um **onde** e/ou um **ORDER BY** cláusula. Se você especificar sua **onde** e/ou **ORDER BY** cláusulas dessa forma, não use `m_strFilter` e/ou `m_strSort`.

### <a name="case-5---lpszsql--a-stored-procedure-call"></a>Caso 5 lpszSQL = uma chamada de procedimento armazenado

Se você precisar chamar uma consulta predefinida (por exemplo, um procedimento armazenado em um banco de dados do Microsoft SQL Server), você deve escrever uma **chamar** instrução em passar para a cadeia de caracteres *lpszSQL*. Os assistentes não têm suporte para declarar uma classe de conjunto de registros para chamar uma consulta predefinida. Nem todas as consultas predefinidas retornam registros.

Se uma consulta predefinida não retornar registros, você pode usar o `CDatabase` função de membro `ExecuteSQL` diretamente. Para uma consulta predefinida que retornam registros, você deve escrever manualmente a RFX chama em `DoFieldExchange` para todas as colunas que o procedimento retorna. As chamadas RFX devem estar na mesma ordem e retornar os mesmos tipos, como a consulta predefinida. Para obter mais informações, consulte [conjunto de registros: Declarando uma classe para uma consulta predefinida (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md).

## <a name="see-also"></a>Consulte também

[SQL: SQL e tipos de dados do C++ (ODBC)](../../data/odbc/sql-sql-and-cpp-data-types-odbc.md)<br/>
[SQL: Fazendo chamadas SQL diretas (ODBC)](../../data/odbc/sql-making-direct-sql-calls-odbc.md)
