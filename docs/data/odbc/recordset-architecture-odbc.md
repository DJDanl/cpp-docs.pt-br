---
title: 'Conjunto de registros: arquitetura (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- recordsets, data members
- field data members, recordset architecture
- field data members
- m_nParams data member, recordsets
- recordsets, architecture
- parameter data members in recordsets
- m_nFields data member
- ODBC recordsets, architecture
- m_nParams data member
- m_nFields data member, recordsets
ms.assetid: 47555ddb-11be-4b9e-9b9a-f2931764d298
ms.openlocfilehash: 3ed6a862cda769769cd07d2dcd72007292068dc3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367092"
---
# <a name="recordset-architecture-odbc"></a>Conjunto de registros: arquitetura (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico descreve os membros de dados que abrangem a arquitetura de um objeto de conjunto de registros:

- [Membros de dados de campo](#_core_field_data_members)

- [Membros de dados de parâmetro](#_core_parameter_data_members)

- [Como usar membros de dados m_nFields e m_nParams](#_core_using_m_nfields_and_m_nparams)

> [!NOTE]
> Este tópico aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. Se o fetch de linha em massa é implementado, a arquitetura é semelhante. Para entender as diferenças, consulte [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

## <a name="sample-class"></a><a name="_core_a_sample_class"></a> Classe de exemplo

> [!NOTE]
> O Assistente de consumidor ODBC do MFC não está disponível no Visual Studio 2019 e posterior. É possível criar um consumidor manualmente.

Quando você usa o [Assistente de consumidor ODBC MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) do assistente **Adicionar Classe** para declarar uma classe de conjunto de registros derivada de `CRecordset`, a classe resultante tem a estrutura geral mostrada na classe de exemplo a seguir:

```cpp
class CCourse : public CRecordset
{
public:
   CCourse(CDatabase* pDatabase = NULL);
   ...
   CString m_strCourseID;
   CString m_strCourseTitle;
   CString m_strIDParam;
};
```

No início da classe, o assistente grava um conjunto de [membros de dados de campo](#_core_field_data_members). Quando você cria a classe, deve especificar um ou mais membros de dados de campo. Se a classe for parametrizada, como é a classe de exemplo (com o membro de dados `m_strIDParam`), será necessário adicionar [membros de dados de parâmetro](#_core_parameter_data_members) manualmente. O assistente não dá suporte à adição de parâmetros a uma classe.

## <a name="field-data-members"></a><a name="_core_field_data_members"></a>Membros de dados de campo

Os membros mais importantes da sua classe de conjunto de registros são os membros de dados de campo. Para cada coluna selecionada na fonte de dados, a classe contém um membro de dados do tipo de dados apropriado para essa coluna. Por exemplo, a [classe de exemplo](#_core_a_sample_class) mostrada no início deste tópico tem dois membros de dados de campo, ambas do tipo `CString`, chamadas `m_strCourseID` e `m_strCourseTitle`.

Quando o conjunto de registros seleciona um conjunto de registros, a estrutura associa automaticamente as colunas do registro atual (após a chamada `Open`, o primeiro registro é o atual) aos membros de dados de campo do objeto. Ou seja, a estrutura usa o membro de dados de campo adequado como um buffer no qual armazenar o conteúdo de uma coluna de registro.

Conforme o usuário rola até um novo registro, a estrutura usa os membros de dados de campo para representar o registro atual. A estrutura atualiza os membros de dados de campo, substituindo os valores do registro anterior. Os membros de dados de campo também são usados para atualizar o registro atual e para adicionar novos. Como parte do processo de atualização de um registro, especifique os valores de atualização atribuindo-os diretamente ao membro ou membros de dados de campo adequados.

## <a name="parameter-data-members"></a><a name="_core_parameter_data_members"></a>Membros de dados de parâmetros

Se a classe é parametrizada, ela tem um ou mais membros de dados de parâmetro. Uma classe parametrizada permite que você baseie uma consulta de conjunto de registros em informações obtidas ou calculadas em tempo de execução.

Normalmente, o parâmetro ajuda a restringir a seleção, como no exemplo a seguir. Com base na [classe de exemplo](#_core_a_sample_class) no início deste tópico, o objeto de conjunto de registros pode executar a seguinte instrução SQL:

```sql
SELECT CourseID, CourseTitle FROM Course WHERE CourseID = ?
```

O “?” é um espaço reservado para um valor de parâmetro que você fornece em tempo de execução. Quando você constrói o conjunto de registros e define seu membro de dados `m_strIDParam` como MATH101, a instrução SQL eficaz para o conjunto de registros se torna:

```sql
SELECT CourseID, CourseTitle FROM Course WHERE CourseID = MATH101
```

Ao definir membros de dados de parâmetro, você informa a estrutura sobre os parâmetros na cadeia de caracteres SQL. A estrutura associa o parâmetro, que informa ao ODBC onde obter os valores a serem substituídos para o espaço reservado. No exemplo, o conjunto de registros resultante contém apenas o registro da tabela Curso com uma coluna CourseID cujo valor é MATH101. Todas as colunas especificadas deste registro são selecionadas. É possível especificar quantos parâmetros (e espaços reservados) você precisar.

> [!NOTE]
> O MFC não faz nada sozinho com os parâmetros — em particular, ele não realiza uma substituição de texto. Em vez disso, o MFC informa ao ODBC onde obter o parâmetro; o ODBC recupera os dados e realiza a parametrização necessária.

> [!NOTE]
> A ordem dos parâmetros é importante. Para obter informações sobre isso e mais informações sobre parâmetros, consulte [Recordset: Parametizando um Conjunto de Registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

## <a name="using-m_nfields-and-m_nparams"></a><a name="_core_using_m_nfields_and_m_nparams"></a> Como usar m_nFields e m_nParams

Quando um assistente escreve um construtor para sua classe, ele também inicializa o membro de dados [m_nFields](../../mfc/reference/crecordset-class.md#m_nfields), que especifica o número de [membros de dados de campo](#_core_field_data_members) na classe. Se adicionar [parâmetros](#_core_parameter_data_members) à sua classe, você também deverá adicionar uma inicialização para o membro de dados [m_nParams](../../mfc/reference/crecordset-class.md#m_nparams), que especifica o número de membros de dados de parâmetro. A estrutura usa esses valores para trabalhar com os membros de dados.

Para obter mais informações e exemplos, consulte [Record Field Exchange: Usando RFX](../../data/odbc/record-field-exchange-using-rfx.md).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: declarando uma classe para uma tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md)<br/>
[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)
