---
title: 'SQL: personalizando a instrução SQL do conjunto de registros (ODBC)'
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
ms.openlocfilehash: 083d268d2b2f2eef072809b1afde9d6ea34f6996
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374513"
---
# <a name="sql-customizing-your-recordsets-sql-statement-odbc"></a>SQL: personalizando a instrução SQL do conjunto de registros (ODBC)

Este tópico explica:

- Como o framework constrói uma declaração SQL

- Como substituir a declaração SQL

> [!NOTE]
> Essas informações aplicam-se às classes ODBC do MFC. Se você estiver trabalhando com as classes DAO do MFC, consulte o tópico "Comparação do Microsoft Jet Database Engine SQL e DOSI SQL" na Ajuda da DAO.

## <a name="sql-statement-construction"></a>Construção de Declaração SQL

Seu conjunto de registros baseia a seleção de registros principalmente em uma declaração SQL **SELECT.** Quando você declara sua classe com um assistente, `GetDefaultSQL` ele escreve uma versão sobreposta da `CAuthors`função de membro que se parece com algo assim (para uma classe de recordset chamada ).

```cpp
CString CAuthors::GetDefaultSQL()
{
    return "AUTHORS";
}
```

Por padrão, essa substituição retorna o nome da tabela especificado com o assistente. No exemplo, o nome da tabela é "AUTORES". Quando você chama mais tarde `Open` a `Open` função de membro do recordset, constrói uma declaração **SELECT** final do formulário:

```
SELECT rfx-field-list FROM table-name [WHERE m_strFilter]
       [ORDER BY m_strSort]
```

onde `table-name` é obtido `GetDefaultSQL` por `rfx-field-list` chamada e é obtido a `DoFieldExchange`partir das chamadas de função RFX em . Isso é o que você recebe para uma declaração **SELECT,** a menos que você substituí-la por uma versão sobreposta em tempo de execução, embora você também possa modificar a declaração padrão com parâmetros ou um filtro.

> [!NOTE]
> Se você especificar um nome de coluna que contenha (ou possa conter) espaços, você deve envolver o nome em colchetes quadrados. Por exemplo, o nome "Primeiro Nome" deve ser "[Primeiro Nome]".

Para substituir a declaração **SELECT** padrão, passe uma seqüência contendo uma declaração **SELECT** completa quando você chamar `Open`. Em vez de construir sua própria seqüência padrão, o conjunto de registros usa a string que você fornece. Se a instrução de substituição contiver uma `m_strFilter` cláusula **WHERE,** não especifique um filtro porque você teria duas instruções de filtro. Da mesma forma, se a sua instrução de substituição `m_strSort` contiver uma cláusula **ORDEM POR,** não especifique um tipo para que você não tenha duas declarações de classificação.

> [!NOTE]
> Se você usar strings literais em seus filtros (ou outras partes da instrução SQL), você pode ter que "citar" (enclose in delimiters especificados) tais strings com um prefixo literal específico do DBMS e caractere sufixo literal (ou caracteres).

Você também pode encontrar requisitos sintáticos especiais para operações como adesões externas, dependendo do seu DBMS. Use funções ODBC para obter essas informações do driver para o DBMS. Por exemplo, `::SQLGetTypeInfo` solicite um determinado `SQL_VARCHAR`tipo de dados, como, para solicitar a LITERAL_PREFIX e LITERAL_SUFFIX caracteres. Se você estiver escrevendo código independente de banco de dados, consulte [Oapêndice C: Gramática SQL](/sql/odbc/reference/appendixes/appendix-c-sql-grammar) na [Referência do Programador ODBC](/sql/odbc/reference/odbc-programmer-s-reference) para obter informações detalhadas sobre sintaxe.

Um objeto de conjunto de registros constrói a declaração SQL que ele usa para selecionar registros, a menos que você passe uma declaração SQL personalizada. Como isso é feito depende principalmente do valor que você passa no parâmetro `Open` *lpszSQL* da função membro.

A forma geral de uma declaração SQL **SELECT** é:

```
SELECT [ALL | DISTINCT] column-list FROM table-list
    [WHERE search-condition][ORDER BY column-list [ASC | DESC]]
```

Uma maneira de adicionar a palavra-chave **DISTINCT** à declaração SQL do seu conjunto de `DoFieldExchange`discos é incorporar a palavra-chave na primeira chamada de função RFX em . Por exemplo:

```
...
    RFX_Text(pFX, "DISTINCT CourseID", m_strCourseID);
...
```

> [!NOTE]
> Use esta técnica apenas com um conjunto de registros aberto como somente leitura.

## <a name="overriding-the-sql-statement"></a>Sobrepondo a Declaração SQL

A tabela a seguir mostra as possibilidades do parâmetro `Open` *lpszSQL* para . Os casos na tabela são explicados seguindo a tabela.

**O parâmetro lpszSQL e a seqüência SQL resultante**

|Caixa|O que você passa em lpszSQL|A declaração SELECT resultante|
|----------|------------------------------|------------------------------------|
|1|NULO|**SELECIONE** *rfx-field-list* **DO** nome da *tabela*<br /><br /> `CRecordset::Open`chamadas `GetDefaultSQL` para obter o nome da tabela. A seqüência resultante é um dos casos `GetDefaultSQL` 2 a 5, dependendo do que retorna.|
|2|Um nome de tabela|**SELECIONE** *rfx-field-list* **DO** nome da *tabela*<br /><br /> A lista de campo é retirada `DoFieldExchange`das instruções RFX em . Se `m_strFilter` `m_strSort` e não estiverem vazios, adiciona as cláusulas **ONDE** e/ou **ORDEM POR.**|
|3\*|Uma declaração **SELECT completa,** mas sem uma cláusula **WHERE** ou **ORDER BY**|Como passou. Se `m_strFilter` `m_strSort` e não estiverem vazios, adiciona as cláusulas **ONDE** e/ou **ORDEM POR.**|
|4\*|Uma declaração **SELECT** completa com uma cláusula **WHERE** e/ou **ORDER BY**|Como passou. `m_strFilter`e/ou `m_strSort` deve permanecer vazio, ou duas instruções de filtro e/ou classificação são produzidas.|
|5\*|Uma chamada para um procedimento armazenado|Como passou.|

\*`m_nFields` deve ser menor ou igual ao número de colunas especificadas na declaração **SELECT.** O tipo de dados de cada coluna especificada na instrução **SELECT** deve ser o mesmo que o tipo de dados da coluna de saída RFX correspondente.

### <a name="case-1---lpszsql--null"></a>Caso 1 lpszSQL = NULL

A seleção do `GetDefaultSQL` conjunto `CRecordset::Open` de registros depende do que retorna quando o chama. Os casos 2 a 5 descrevem as possíveis cordas.

### <a name="case-2---lpszsql--a-table-name"></a>Caso 2 lpszSQL = um nome de tabela

O conjunto de registros usa o Record Field Exchange (RFX) para construir a lista de colunas a `DoFieldExchange`partir dos nomes das colunas fornecidas nas chamadas de função RFX na substituição da classe recordset de . Se você usou um assistente para declarar sua classe de conjunto de registros, este caso tem o mesmo resultado do caso 1 (desde que você passe o mesmo nome de tabela que você especificou no assistente). Se você não usar um assistente para escrever sua classe, o caso 2 é a maneira mais simples de construir a declaração SQL.

O exemplo a seguir constrói uma declaração SQL que seleciona registros de um aplicativo de banco de dados MFC. Quando o framework `GetDefaultSQL` chama a função de membro, `SECTION`a função retorna o nome da tabela, .

```cpp
CString CEnrollSet::GetDefaultSQL()
{
    return "SECTION";
}
```

Para obter os nomes das colunas para a declaração `DoFieldExchange` SQL **SELECT,** o framework chama a função de membro.

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

Quando concluída, a declaração SQL fica assim:

```sql
SELECT CourseID, InstructorID, RoomNo, Schedule, SectionNo
    FROM SECTION
```

### <a name="case-3---lpszsql--a-selectfrom-statement"></a>Caso 3 lpszSQL = uma declaração SELECT/FROM

Você especifica a lista de colunas manualmente em vez de confiar no RFX para construí-la automaticamente. Você pode querer fazer isso quando:

- Deseja especificar a palavra-chave **DISTINTA** seguindo **SELECT**.

   Sua lista de colunas deve corresponder aos nomes e `DoFieldExchange`tipos da coluna na mesma ordem em que estão listados .

- Você tem razão para recuperar manualmente valores `::SQLGetData` de coluna usando a função ODBC em vez de depender do RFX para vincular e recuperar colunas para você.

   Você pode, por exemplo, querer acomodar novas colunas que um cliente do seu aplicativo adicionou às tabelas do banco de dados depois que o aplicativo foi distribuído. Você precisa adicionar esses membros de dados de campo extra, que não eram conhecidos no momento em que você declarou a classe com um assistente.

   Sua lista de colunas deve corresponder aos nomes e `DoFieldExchange`tipos da coluna na mesma ordem em que estão listados, seguido sinuosos os nomes das colunas vinculadas manualmente. Para obter mais informações, consulte [Recordset: Dynamically Binding Data Columns (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

- Você deseja participar de tabelas especificando várias tabelas na cláusula **FROM.**

   Para obter informações e um exemplo, consulte [Recordset: Realizando uma Adesão (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md).

### <a name="case-4---lpszsql--selectfrom-plus-where-andor-order-by"></a>Caso 4 lpszSQL = SELECT/FROM Plus ONDE e/ou ORDEM POR

Você especifica tudo: a lista de colunas `DoFieldExchange`(com base nas chamadas RFX), a lista de tabelas e o conteúdo de uma cláusula **WHERE** e/ou **ORDER BY.** Se você especificar suas cláusulas **WHERE** e/ou `m_strFilter` ORDER **BY** desta forma, não use e/ou `m_strSort`.

### <a name="case-5---lpszsql--a-stored-procedure-call"></a>Caso 5 lpszSQL = uma chamada de procedimento armazenado

Se você precisar chamar uma consulta predefinida (como um procedimento armazenado em um banco de dados do Microsoft SQL Server), você deve escrever uma declaração **CALL** na seqüência que você passar para *lpszSQL*. Os assistentes não suportam declarar uma classe de configuração de registro para chamar uma consulta predefinida. Nem todas as consultas predefinidas retornam registros.

Se uma consulta predefinida não retornar registros, `CDatabase` você `ExecuteSQL` poderá usar a função de membro diretamente. Para uma consulta predefinida que faça os registros de retorno, `DoFieldExchange` você também deve gravar manualmente as chamadas RFX para quaisquer colunas que o procedimento retorna. As chamadas RFX devem estar na mesma ordem e retornar os mesmos tipos, como a consulta predefinida. Para obter mais informações, consulte [Recordset: Declarando uma classe para uma consulta predefinida (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md).

## <a name="see-also"></a>Confira também

[SQL: tipos de dados SQL e C++ (ODBC)](../../data/odbc/sql-sql-and-cpp-data-types-odbc.md)<br/>
[SQL: fazendo chamadas SQL diretas (ODBC)](../../data/odbc/sql-making-direct-sql-calls-odbc.md)
