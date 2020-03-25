---
title: 'Conjunto de registros: parametrizando um conjunto de registros (ODBC)'
ms.date: 05/09/2019
helpviewer_keywords:
- parameterizing recordsets
- ODBC recordsets, parameterizing
- recordsets, parameterizing
- passing parameters, to queries at runtime
ms.assetid: 7d1dfeb6-5ee0-45e2-aacc-63bc52a465cd
ms.openlocfilehash: ec4198c283700daa2e02e2507b9874eaf02858e9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212804"
---
# <a name="recordset-parameterizing-a-recordset-odbc"></a>Conjunto de registros: parametrizando um conjunto de registros (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Às vezes, talvez convenha poder selecionar registros em tempo de execução usando informações que você calculou ou obteve de seu usuário final. Os parâmetros de conjunto de registros permitem que você atinja essa meta.

Este tópico explica:

- [A finalidade de um conjunto de registros com parâmetros](#_core_parameterized_recordsets).

- [Quando e por que talvez convenha parametrizar um conjunto de registros](#_core_when_to_use_parameters).

- [Como declarar membros de dados de parâmetro em sua classe de conjunto de registros](#_core_parameterizing_your_recordset_class).

- [Como passar informações de parâmetro para um objeto de conjunto de registros em tempo de execução](#_core_passing_parameter_values_at_run_time).

##  <a name="parameterized-recordsets"></a><a name="_core_parameterized_recordsets"></a> Conjuntos de registros com parâmetros

Um conjunto de registros com parâmetros permite que você passe informações em tempo de execução. Ele tem dois efeitos valiosos:

- Pode resultar em uma melhor velocidade de execução.

- Permite que você crie uma consulta em tempo de execução, com base em informações não disponíveis para você em tempo de design, como informações obtidas do seu usuário ou calculadas em tempo de execução.

Quando você chama `Open` para executar a consulta, o conjunto de registros usa as informações de parâmetro para concluir sua instrução **SELECT SQL**. É possível parametrizar qualquer conjunto de registros.

##  <a name="when-to-use-parameters"></a><a name="_core_when_to_use_parameters"></a> Quando usar parâmetros

Os usos típicos de parâmetros incluem:

- Passar argumentos de tempo de execução para uma consulta predefinida.

   Para passar parâmetros para um procedimento armazenado, é necessário especificar uma instrução **CALL** ODBC completa e personalizada – com espaços reservados de parâmetro – quando você chama `Open`, substituindo a instrução SQL padrão do conjunto de registros. Para obter mais informações, consulte [CRecordset:: Open](../../mfc/reference/crecordset-class.md#open) na *biblioteca de classes Reference* e [SQL: Personalizando a instrução SQL do conjunto de registros (ODBC)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md) e o [conjunto de registros: declarando uma classe para uma consulta predefinida (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md).

- Executar com eficiência inúmeras repetições de consulta com diferentes informações de parâmetro.

   Por exemplo, cada vez que seu usuário final pesquisa informações para um aluno específico no banco de dados de registro de aluno, você pode especificar o nome ou a ID do aluno como um parâmetro obtido do usuário. Em seguida, quando você chama a função de membro `Requery` do seu conjunto de registros, a consulta seleciona apenas o registro desse aluno.

   As cadeias de caracteres de filtro do conjunto de registros, armazenadas em `m_strFilter`, podem ter esta aparência:

    ```cpp
    "StudentID = ?"
    ```

   Suponha que você obtenha a ID do aluno na variável `strInputID`. Quando você define um parâmetro como `strInputID` (por exemplo, a ID 100 do aluno), o valor da variável está associado ao espaço reservado do parâmetro representado pelo “?” na cadeia de caracteres de filtro.

   Atribua o valor de parâmetro da seguinte maneira:

    ```cpp
    strInputID = "100";
    ...
    m_strParam = strInputID;
    ```

   Não conviria configurar uma cadeia de caracteres de filtro desta maneira:

    ```cpp
    m_strFilter = "StudentID = 100";   // 100 is incorrectly quoted
                                       // for some drivers
    ```

   Para obter uma discussão sobre como usar aspas corretamente para cadeias de caracteres de filtro, consulte conjunto de registros [: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md).

   O valor do parâmetro é diferente a cada vez que você repete a consulta do conjunto de registros para uma nova ID de aluno.

   > [!TIP]
   > Usar um parâmetro é mais eficiente do que simplesmente um filtro. Para ver um conjunto de registros com parâmetros, o banco de dados deve processar uma instrução **SELECT** SQL somente uma vez. Para um conjunto de registros filtrado sem parâmetros, a instrução **SELECT** deve ser processada cada vez que você `Requery` com um novo valor de filtro.

Para obter mais informações sobre filtros, consulte [Recordset: Filtering Records (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md).

##  <a name="parameterizing-your-recordset-class"></a><a name="_core_parameterizing_your_recordset_class"></a> Como parametrizar sua classe de conjunto de registros

> [!NOTE]
> Esta seção aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. Se você está usando o fetch de linha em massa, implementar parâmetros é um processo semelhante. Para obter mais informações, consulte conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Antes de criar sua classe de conjunto de registros, determine quais parâmetros são necessários, quais são seus tipos de dados e como o conjunto de registros os usa.

#### <a name="to-parameterize-a-recordset-class"></a>Para parametrizar uma classe de conjunto de registros

> [!NOTE]
> O Assistente de consumidor ODBC do MFC não está disponível no Visual Studio 2019 e posterior. Ainda é possível criar essa funcionalidade manualmente.

1. Execute o [Assistente de consumidor ODBC MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) de **Adicionar Classe** para criar a classe.

1. Especifique membros de dados de campo para as colunas do conjunto de registros.

1. Depois que o assistente escrever a classe em um arquivo em seu projeto, acesse o arquivo .h e adicione manualmente um ou mais membros de dados de parâmetro à declaração de classe. A adição pode ter uma aparência semelhante à do exemplo a seguir, parte de uma classe de instantâneo criada para responder à consulta “Quais alunos estão na classe sênior?”

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

   Adicione seus membros de dados de parâmetro após os membros de dados de campo gerados pelo assistente. A convenção é acrescentar a palavra “Param” a cada nome de parâmetro definido pelo usuário.

1. Modifique a definição de função de membro [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) no arquivo .cpp. Adicione uma chamada de função RFX para cada membro de dados de parâmetro adicionado à classe. Para obter informações sobre como escrever suas funções do suporte RFX, consulte [gravar campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md). Preceda as chamadas RFX para os parâmetros com uma única chamada para:

    ```cpp
    pFX->SetFieldType( CFieldExchange::param );
    // RFX calls for parameter data members
    ```

1. No construtor de sua classe de conjunto de registros, incremente a contagem de parâmetros, `m_nParams`.

   Para obter informações, consulte [gravar campo Exchange: trabalhando com o código do assistente](../../data/odbc/record-field-exchange-working-with-the-wizard-code.md).

1. Ao escrever o código que cria um objeto de conjunto de registros dessa classe, insira um símbolo “?” (ponto de interrogação) em cada local em suas cadeias de caracteres de instrução SQL em que um parâmetro deve ser substituído.

   Em tempo de execução, os espaços reservados “?” são preenchidos, em ordem, pelos valores de parâmetro passados. O primeiro membro de dados de parâmetro definido após a chamada [SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) substitui o primeiro "?"na cadeia de caracteres SQL, o segundo membro de dados de parâmetro substitui o segundo"?" e assim por diante.

> [!NOTE]
> A ordem de parâmetros é importante: a ordem das chamadas RFX para parâmetros em sua função `DoFieldExchange` deve corresponder à ordem dos espaços reservados de parâmetro em sua cadeia de caracteres SQL.

> [!TIP]
> A cadeia de caracteres com a qual há mais probabilidade de se trabalhar é a cadeia de caracteres especificada (se houver) para o membro de dados [m_strFilter](../../mfc/reference/crecordset-class.md#m_strfilter) da classe, mas alguns drivers ODBC podem permitir parâmetros em outras cláusulas SQL.

##  <a name="passing-parameter-values-at-run-time"></a><a name="_core_passing_parameter_values_at_run_time"></a> Como passar valores de parâmetro em tempo de execução

É necessário especificar valores de parâmetro antes de chamar `Open` (para um novo objeto de conjunto de registros) ou `Requery` (para um existente).

#### <a name="to-pass-parameter-values-to-a-recordset-object-at-run-time"></a>Para passar valores de parâmetro para um objeto de conjunto de registros em tempo de execução

1. Construa o objeto de conjunto de registros.

1. Prepare uma cadeia ou cadeias de caracteres, como a cadeia de caracteres `m_strFilter` que contém a instrução SQL ou partes dela. Coloque os espaços reservados "?" onde as informações de parâmetro devem ir.

1. Atribua um valor de parâmetro de tempo de execução a cada membro de dados de parâmetro do objeto.

1. Chame a função de membro `Open` (ou `Requery`, para um conjunto de registros existente).

Por exemplo, suponha que você quer especificar uma cadeia de caracteres de filtro para seu conjunto de registros que usa informações obtidas em tempo de execução. Suponha que você construiu um conjunto de registros da classe `CStudentSet` anteriormente — chamado `rsStudents` — e agora deseja repetir a consulta dele para um tipo específico de informações dos alunos.

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

O conjunto de registros contém registros para os alunos cujos registros atendem às condições especificadas pelo filtro, que foi construído com base em parâmetros de tempo de execução. Nesse caso, o conjunto de registros contém registros para todos os alunos seniores.

> [!NOTE]
>  Se necessário, é possível definir o valor de um membro de dados de parâmetro como Null, usando [SetParamNull](../../mfc/reference/crecordset-class.md#setparamnull). Da mesma forma, é possível verificar se um membro de dados de parâmetro é Null usando [IsFieldNull](../../mfc/reference/crecordset-class.md#isfieldnull).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)<br/>
[Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)
