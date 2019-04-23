---
title: 'Conjunto de registros: Arquitetura (ODBC)'
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
ms.openlocfilehash: 5904a69f81dd1fbf22171a46040da5d4f5511588
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59039644"
---
# <a name="recordset-architecture-odbc"></a>Conjunto de registros: Arquitetura (ODBC)

Este tópico se aplica às classes ODBC do MFC.

Este tópico descreve os membros de dados que compõem a arquitetura de um objeto de conjunto de registros:

- [Membros de dados de campo](#_core_field_data_members)

- [Membros de dados de parâmetro](#_core_parameter_data_members)

- [Usando membros de dados m_nFields e m_nParams](#_core_using_m_nfields_and_m_nparams)

> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa buscando não foi implementado. Se a busca de linhas em massa for implementada, a arquitetura é semelhante. Para entender as diferenças, consulte [conjunto de registros: Buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="_core_a_sample_class"></a> Classe de exemplo

Quando você usa o [Assistente de consumidor ODBC MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) de **Add Class** derivado do Assistente para declarar uma classe de conjunto de registros de `CRecordset`, a classe resultante tem a estrutura geral mostrada a seguir simple classe:

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

No início da classe, o assistente grava um conjunto de [membros de dados de campo](#_core_field_data_members). Quando você cria a classe, você deve especificar um ou mais membros de dados do campo. Se a classe for parametrizada, como o exemplo de classe é (com o membro de dados `m_strIDParam`), você deve adicionar manualmente [membros de dados do parâmetro](#_core_parameter_data_members). O assistente não oferece suporte para adicionar parâmetros para uma classe.

##  <a name="_core_field_data_members"></a> Membros de dados de campo

Os membros mais importantes da sua classe de conjunto de registros são os membros de dados do campo. Para cada coluna selecionada da fonte de dados, a classe contém um membro de dados do tipo de dados apropriado para aquela coluna. Por exemplo, o [classe de exemplo](#_core_a_sample_class) mostrado no início deste tópico tem dois membros de dados de campo, ambos do tipo `CString`, chamado `m_strCourseID` e `m_strCourseTitle`.

Quando o conjunto de registros seleciona um conjunto de registros, a estrutura automaticamente associa as colunas do registro atual (depois que o `Open` chamada, o primeiro registro é atual) para os membros de dados do campo do objeto. Ou seja, a estrutura usa o membro de dados de campo apropriado como um buffer no qual armazenar o conteúdo de uma coluna de registro.

Conforme o usuário rola para um novo registro, a estrutura usa os membros de dados de campo para representar o registro atual. O framework atualiza os membros de dados de campo, substituindo os valores do registro anterior. Os membros de campo de dados também são usados para atualizar o registro atual e para adicionar novos registros. Como parte do processo de atualização de um registro, você pode especificar os valores de atualização atribuindo valores diretamente para o membro de dados de campo apropriado ou membros.

##  <a name="_core_parameter_data_members"></a> Membros de dados de parâmetro

Se a classe for parametrizada, ele tem um ou mais membros de dados de parâmetro. Uma classe parametrizada permite que uma consulta de conjunto de registros de base nas informações obtidas ou calculados em tempo de execução.

Normalmente, o parâmetro ajuda a restringir a seleção, como no exemplo a seguir. Com base nas [classe de exemplo](#_core_a_sample_class) no início deste tópico, o objeto recordset pode executar a seguinte instrução SQL:

```sql
SELECT CourseID, CourseTitle FROM Course WHERE CourseID = ?
```

O "?" é um espaço reservado para um valor de parâmetro fornecidos por você em tempo de execução. Quando você constrói o conjunto de registros e defina seu `m_strIDParam` torna-se do membro de dados para MATH101, a instrução SQL em vigor para o conjunto de registros:

```sql
SELECT CourseID, CourseTitle FROM Course WHERE CourseID = MATH101
```

Definindo membros de dados de parâmetro, você pode dizer à estrutura sobre os parâmetros na cadeia de caracteres SQL. O framework associa o parâmetro, que permite que o ODBC Saiba onde obter os valores para substituir para o espaço reservado. No exemplo, o conjunto de registros resultante contém apenas o registro da tabela com uma coluna CourseID cujo valor é MATH101 curso. Todas as colunas especificadas desse registro são selecionadas. Você pode especificar quantos parâmetros (e espaços reservados) conforme necessário.

> [!NOTE]
>  MFC não faz nada próprio com os parâmetros — em particular, ele não realiza uma substituição de texto. Em vez disso, o MFC informa ODBC onde obter o parâmetro; ODBC recupera os dados e executa a parametrização necessária.

> [!NOTE]
>  A ordem dos parâmetros é importante. Para obter informações sobre isso e mais informações sobre parâmetros, consulte [conjunto de registros: Parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

##  <a name="_core_using_m_nfields_and_m_nparams"></a> Usando m_nFields e m_nParams

Quando um assistente grava um construtor para a sua classe, ele também inicializa o [m_nFields](../../mfc/reference/crecordset-class.md#m_nfields) membro de dados, que especifica o número de [membros de dados de campo](#_core_field_data_members) na classe. Se você adicionar qualquer [parâmetros](#_core_parameter_data_members) à sua classe, você também deve adicionar a inicialização para o [m_nParams](../../mfc/reference/crecordset-class.md#m_nparams) membro de dados, que especifica o número de membros de dados do parâmetro. A estrutura usa esses valores para trabalhar com os membros de dados.

Para obter mais informações e exemplos, consulte [troca de campos do registro: Usando RFX](../../data/odbc/record-field-exchange-using-rfx.md).

## <a name="see-also"></a>Consulte também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: Declarando uma classe para uma tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md)<br/>
[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)