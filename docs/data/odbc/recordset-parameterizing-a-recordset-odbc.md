---
title: 'Conjunto de registros: Parametrizando um conjunto de registros (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- parameterizing recordsets
- ODBC recordsets, parameterizing
- recordsets, parameterizing
- passing parameters, to queries at runtime
ms.assetid: 7d1dfeb6-5ee0-45e2-aacc-63bc52a465cd
ms.openlocfilehash: df67256c54cae3e2adb054d653d3e58bb91dd631
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62397751"
---
# <a name="recordset-parameterizing-a-recordset-odbc"></a>Conjunto de registros: Parametrizando um conjunto de registros (ODBC)

Este tópico se aplica às classes ODBC do MFC.

Às vezes, você talvez queira ser capaz de selecionar os registros em tempo de execução usando informações de você ter calculado ou obtido do seu usuário final. Parâmetros de conjunto de registros permitem que você atingir esse objetivo.

Este tópico explica:

- [A finalidade de um conjunto de registros com parâmetros](#_core_parameterized_recordsets).

- [Quando e por que você pode querer parametrizar um conjunto de registros](#_core_when_to_use_parameters).

- [Como declarar membros de dados em sua classe de conjunto de registros de parâmetro](#_core_parameterizing_your_recordset_class).

- [Como passar informações de parâmetro para um objeto de conjunto de registros em tempo de execução](#_core_passing_parameter_values_at_run_time).

##  <a name="_core_parameterized_recordsets"></a> Conjuntos de registros com parâmetros

Um conjunto de registros com parâmetros permite que você passar informações de parâmetro em tempo de execução. Isso tem dois efeitos valiosos:

- Isso pode resultar em maior velocidade de execução.

- Ele permite que você criar uma consulta em tempo de execução com base nas informações não disponíveis para você em tempo de design, como informações obtidas do seu usuário ou calculados em tempo de execução.

Quando você chama `Open` para executar a consulta, o conjunto de registros usa as informações de parâmetro para concluir sua **SQL SELECT** instrução. Você pode parametrizar qualquer conjunto de registros.

##  <a name="_core_when_to_use_parameters"></a> Quando usar parâmetros

Usos típicos para os parâmetros incluem:

- Passando argumentos de tempo de execução para uma consulta predefinida.

   Para passar parâmetros para um procedimento armazenado, você deve especificar um ODBC personalizada completa **chamar** instrução — com espaços reservados de parâmetro — quando você chama `Open`, substituindo a instrução de SQL padrão do conjunto de registros. Para obter mais informações, consulte [{1&gt;crecordset::Open&lt;1](../../mfc/reference/crecordset-class.md#open) na *referência da biblioteca de classe* e [SQL: Personalizando a instrução de SQL do seu conjunto de registros (ODBC)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md) e [conjunto de registros: Declarando uma classe para uma consulta predefinida (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md).

- Executar com eficiência as diversas requeries com informações de parâmetro diferentes.

   Por exemplo, cada vez que o usuário final procura informações de um aluno específico no banco de dados de registro aluno, você pode especificar nome ou a ID do aluno como um parâmetro obtido do usuário. Em seguida, quando você chama o seu conjunto de registros `Requery` função de membro, a consulta seleciona somente o registro do aluno.

   Cadeia de caracteres de filtro de seu conjunto de registros, armazenada em `m_strFilter`, teria esta aparência:

    ```cpp
    "StudentID = ?"
    ```

   Suponha que você obtenha a ID do aluno na variável `strInputID`. Quando você define um parâmetro para `strInputID` (por exemplo, o aluno ID 100) o valor da variável é associado ao espaço reservado de parâmetro representado pelo "?" na cadeia de caracteres de filtro.

   Atribua o valor do parâmetro da seguinte maneira:

    ```cpp
    strInputID = "100";
    ...
    m_strParam = strInputID;
    ```

   Você não gostaria de configurar uma cadeia de caracteres de filtro dessa maneira:

    ```cpp
    m_strFilter = "StudentID = 100";   // 100 is incorrectly quoted
                                       // for some drivers
    ```

   Para uma discussão sobre como usar aspas corretamente para cadeias de caracteres de filtro, consulte [conjunto de registros: Filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md).

   O valor do parâmetro é diferente cada vez que você consulte novamente o conjunto de registros para uma nova ID do aluno.

   > [!TIP]
   > É mais eficiente do que simplesmente um filtro usando um parâmetro. Para um conjunto de registros com parâmetros, o banco de dados deve processar um SQL **selecionar** instrução somente uma vez. Para um conjunto de registros filtrado sem parâmetros, o **selecionar** instrução deve ser processada cada vez que você `Requery` com um novo valor de filtro.

Para obter mais informações sobre filtros, consulte [conjunto de registros: Filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md).

##  <a name="_core_parameterizing_your_recordset_class"></a> Parametrização de sua classe de conjunto de registros

> [!NOTE]
> Esta seção se aplica a objetos derivados de `CRecordset` em qual linha em massa buscando não foi implementado. Se você estiver usando a linha em massa buscando, a implementação de parâmetros é um processo semelhante. Para obter mais informações, consulte [conjunto de registros: Buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Antes de criar sua classe de conjunto de registros, determine quais parâmetros você precisa, seus tipos de dados e como o conjunto de registros utiliza.

#### <a name="to-parameterize-a-recordset-class"></a>Para parametrizar uma classe de conjunto de registros

1. Executar o [Assistente de consumidor ODBC MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) partir **Adicionar classe** para criar a classe.

1. Especifique os membros de dados de campo para colunas do conjunto de registros.

1. Depois que o assistente grava a classe em um arquivo em seu projeto, vá até o arquivo. h e adicione manualmente um ou mais membros de dados de parâmetro para a declaração de classe. A adição pode ser parecida com o exemplo a seguir, a parte de uma classe de instantâneo criado para responder à consulta "que os alunos estão na classe sênior?"

    ```cpp
    class CStudentSet : public CRecordset
    {
    // Field/Param Data
        CString m_strFirstName;
        CString m_strLastName;
        CString m_strStudentID;
        CString m_strGradYear;

        CString m_strGradYrParam;
    };
    ```

   Adicione os membros de dados de parâmetro após os membros de dados do campo gerado pelo assistente. A convenção é acrescentar a palavra "Param" para cada nome de parâmetro definidos pelo usuário.

1. Modificar a [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) definição de função de membro no arquivo. cpp. Adicione uma chamada de função RFX para cada membro de dados de parâmetro adicionado à classe. Para obter informações sobre como escrever suas funções RFX, consulte [troca de campos do registro: Como funciona RFX](../../data/odbc/record-field-exchange-how-rfx-works.md). Preceda as chamadas RFX para os parâmetros com uma única chamada para:

    ```cpp
    pFX->SetFieldType( CFieldExchange::param );
    // RFX calls for parameter data members
    ```

1. No construtor da sua classe de conjunto de registros, incrementar a contagem de parâmetros, `m_nParams`.

   Para obter informações, consulte [troca de campos do registro: Trabalhando com o código de assistente](../../data/odbc/record-field-exchange-working-with-the-wizard-code.md).

1. Quando você escreve o código que cria um objeto recordset dessa classe, coloque um "?" símbolo (ponto de interrogação) em cada local em suas cadeias de caracteres de instrução SQL em que um parâmetro deve ser substituída.

   Em tempo de execução "?" espaços reservados são preenchidos na ordem, pelos valores do parâmetro que você passar. O primeiro membro de dados de parâmetro definido após o [SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) chamada substitui o primeiro "?"na cadeia de caracteres SQL, o segundo membro de dados de parâmetro substitui a segunda"?" e assim por diante.

> [!NOTE]
> Ordem do parâmetro é importante: a ordem dos RFX chama para parâmetros em seu `DoFieldExchange` função deve corresponder à ordem dos espaços reservados de parâmetro na sua cadeia de caracteres SQL.

> [!TIP]
> A cadeia de caracteres mais provável para trabalhar com é a cadeia de caracteres que você especificar (se houver) para a classe [m_strFilter](../../mfc/reference/crecordset-class.md#m_strfilter) membro de dados, mas alguns drivers ODBC podem permitir que parâmetros em outras cláusulas SQL.

##  <a name="_core_passing_parameter_values_at_run_time"></a> Passar valores de parâmetro em tempo de execução

Você deve especificar valores de parâmetro antes de chamar `Open` (para um novo objeto de conjunto de registros) ou `Requery` (para um existente).

#### <a name="to-pass-parameter-values-to-a-recordset-object-at-run-time"></a>Para passar valores de parâmetro para um objeto de conjunto de registros em tempo de execução

1. Construa o objeto de conjunto de registros.

1. Preparar uma cadeia de caracteres ou cadeias de caracteres, como o `m_strFilter` cadeia de caracteres, que contém a instrução SQL ou partes dele. Colocar "?" espaços reservados onde as informações de parâmetro são ir.

1. Atribua um valor de parâmetro de tempo de execução para cada membro de dados de parâmetro do objeto.

1. Chame o `Open` função de membro (ou `Requery`, para um conjunto de registros existente).

Por exemplo, suponha que você deseja especificar uma cadeia de caracteres de filtro para o conjunto de registros usando as informações obtidas em tempo de execução. Suponha que você construiu um conjunto de registros da classe `CStudentSet` anteriormente — chamado `rsStudents` — e agora deseja repetir a consulta para um determinado tipo de informações dos alunos.

```cpp
// Set up a filter string with
// parameter placeholders
rsStudents.m_strFilter = "GradYear <= ?";

// Obtain or calculate parameter values
// to pass--simply assigned here
CString strGradYear = GetCurrentAcademicYear( );

// Assign the values to parameter data members
rsStudents.m_strGradYrParam = strGradYear;

// Run the query
if( !rsStudents.Requery( ) )
    return FALSE;
```

O conjunto de registros contém registros para os alunos cujos registros satisfazem as condições especificadas pelo filtro, que foi construído a partir de parâmetros de tempo de execução. Nesse caso, o conjunto de registros contém registros para todos os alunos sênior.

> [!NOTE]
>  Se necessário, você pode definir o valor de um membro de dados do parâmetro como Null, usando [SetParamNull](../../mfc/reference/crecordset-class.md#setparamnull). Da mesma forma você pode verificar a se um membro de dados de parâmetro for Null, usando [IsFieldNull](../../mfc/reference/crecordset-class.md#isfieldnull).

## <a name="see-also"></a>Consulte também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: adicionar, atualizar e excluir registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)<br/>
[Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)