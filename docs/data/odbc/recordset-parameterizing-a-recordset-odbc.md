---
title: "Conjunto de registros: parametrizando um conjunto de registros (ODBC) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "conjunto de registros ODBC, parametrizando"
  - "parametrizando conjuntos de registros"
  - "passando parâmetros, para consultas em tempo de execução"
  - "conjuntos de registros, parametrizando"
ms.assetid: 7d1dfeb6-5ee0-45e2-aacc-63bc52a465cd
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: parametrizando um conjunto de registros (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Às vezes talvez você queira poder selecionar em tempo de execução registros, usando as informações que você calculados ou obtido do usuário final.  Os parâmetros do conjunto de registros permitem executar essa meta.  
  
 Este tópico explica:  
  
-   [A finalidade de um conjunto de registros com parâmetros](#_core_parameterized_recordsets).  
  
-   [Quando e como você pode optar por parametrizar um conjunto de registros](#_core_when_to_use_parameters).  
  
-   [Como declarar o parâmetro os membros de dados no conjunto de registros classificação](#_core_parameterizing_your_recordset_class).  
  
-   [Como transmitir informações de parâmetro a um conjunto de registros objeto em tempo de execução](#_core_passing_parameter_values_at_run_time).  
  
##  <a name="_core_parameterized_recordsets"></a> Conjuntos de registros com parâmetros  
 Um conjunto de registros com parâmetros permite passar em tempo de execução informações de parâmetro.  Isso tem dois efeitos valiosos:  
  
-   Pode resultar em um melhor velocidade de execução.  
  
-   Permite a você criar em tempo de execução uma consulta, com base nas informações não disponível em tempo de design, como as informações obtidas do usuário ou calculada em tempo de execução.  
  
 Quando você chama **Abrir** para executar a consulta, o conjunto de registros usa as informações de parâmetro para concluir a instrução de **SQL SELECT** .  É possível parametrizar todo o conjunto de registros.  
  
##  <a name="_core_when_to_use_parameters"></a> Quando usar parâmetros  
 Os usos típicos de parâmetros incluem:  
  
-   Passando argumentos de tempo de execução para uma consulta predefinida.  
  
     Para passar parâmetros para um procedimento armazenado, você deve especificar uma instrução personalizado completo ODBC **CALL** — com os espaços reservados de parâmetros — quando você chama **Abrir**, substituindo a instrução SQL padrão do conjunto de registros.  Para obter mais informações, consulte [CRecordset::Open](../Topic/CRecordset::Open.md)*na referência da biblioteca de classes* e [SQL: Personalizando a instrução SQL do conjunto de registros \(ODBC\)](../../data/odbc/sql-customizing-your-recordset’s-sql-statement-odbc.md) e [Conjunto de registros: Declarando uma classe para uma consulta predefinido \(ODBC\)](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md).  
  
-   Eficientemente executando repete tanto com informações de parâmetro diferente.  
  
     Por exemplo, a cada vez que o usuário final pesquisa informações para um aluno específico na base de dados do registro do aluno, você pode especificar o nome ou a ID do estudante como um parâmetro obtido do usuário.  Então, quando você chama a função de membro de **Requery** do conjunto de registros, a consulta seleciona apenas que o registro do aluno.  
  
     A cadeia de caracteres de filtro do conjunto de registros, armazenada em **m\_strFilter**, pode ter esta aparência:  
  
    ```  
    "StudentID = ?"  
    ```  
  
     Suponha que você obtém a ID do estudante em `strInputID`variável.  Quando você define um parâmetro a `strInputID` \(por exemplo, a ID 100 do estudante\) o valor da variável é associado ao espaço reservado para o parâmetro representado por “?” na cadeia de caracteres do filtro.  
  
     Atribuir o valor de parâmetro como segue:  
  
    ```  
    strInputID = "100";  
    ...  
    m_strParam = strInputID;  
    ```  
  
     Você não pode desejar configurar uma cadeia de caracteres de filtro da seguinte maneira:  
  
    ```  
    m_strFilter = "StudentID = 100";   // 100 is incorrectly quoted  
                                       // for some drivers  
    ```  
  
     Para uma discussão sobre como usar aspas corretamente para cadeias de caracteres de filtro, consulte [Conjunto de registros: Filtrando registros \(ODBC\)](../../data/odbc/recordset-filtering-records-odbc.md).  
  
     O valor do parâmetro é diferente a cada vez que você você consulte novamente o conjunto de registros para uma nova ID do estudante  
  
    > [!TIP]
    >  Usar um parâmetro é mais eficiente do que simplesmente um filtro.  Para um conjunto de registros com parâmetros, o base de dados deve processar uma instrução SQL **SELECIONAR** apenas uma vez.  Para um conjunto de registros filtrado sem parâmetros, a instrução de **SELECIONAR** deve ser processada cada vez que você **Requery** por um novo valor do filtro.  
  
 Para obter mais informações sobre filtros, consulte [Conjunto de registros: Filtrando registros \(ODBC\)](../../data/odbc/recordset-filtering-records-odbc.md).  
  
##  <a name="_core_parameterizing_your_recordset_class"></a> A parametrização da classe do conjunto de registros  
  
> [!NOTE]
>  Esta seção é aplicada a objetos derivados de `CRecordset` no qual a busca de linhas do volume não foi implementado.  Se você estiver usando a linha em massa que pesquisa, implemente parâmetros é um processo semelhante.  Para obter mais informações, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
 Antes de criar a sua classe do conjunto de registros, determine quais parâmetros, você precisa quais os tipos de dados são, e como o conjunto de registros usá\-los.  
  
#### Para parametrizar uma classe do conjunto de registros  
  
1.  Executar [Assistente do consumidor MFC ODBC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) de **Adicionar Classe** para criar a classe.  
  
2.  Especificar membros de dados do campo para as colunas do conjunto de registros.  
  
3.  Depois que o assistente grava a classe em um arquivo em seu projeto, vá para o arquivo de .h e adicionar manualmente um ou mais membros de dados do parâmetro à declaração da classe.  A adição de relatório poderia ser algo como o exemplo a seguir, parte de uma classe de instantâneo criado para responder à consulta “que os alunos são na classe superior?”  
  
    ```  
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
  
     Adicionar seus membros de dados do parâmetro depois dos membros de dados gerados no campo.  A convenção é anexar a palavra “Param” para cada nome de parâmetro definido pelo usuário.  
  
4.  Modifique a definição de função de membro de [DoFieldExchange](../Topic/CRecordset::DoFieldExchange.md) no arquivo .cpp.  Adicionar uma chamada de função de RFX para cada membro de dados do parâmetro que você adicionou à classe.  Para obter informações sobre como escrever suas funções de RFX, consulte [Registre o campo for Exchange: Como funciona RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  As chamadas de RFX para os parâmetros com uma única chamada para:  
  
    ```  
    pFX->SetFieldType( CFieldExchange::param );  
    // RFX calls for parameter data members  
    ```  
  
5.  No construtor da sua classe do conjunto de registros, incremente a contagem dos parâmetros, `m_nParams`.  
  
     Para obter mais informações, consulte [Registre o campo for Exchange: Trabalhando com o código do assistente](../../data/odbc/record-field-exchange-working-with-the-wizard-code.md).  
  
6.  Quando você escreve o código que cria um objeto do conjunto de registros essa classe, coloque “?” símbolo de ponto de interrogação \(\) em cada local nas cadeias de caracteres da instrução SQL no qual um parâmetro deve ser substituído.  
  
     Em tempo de execução, “?” os espaços reservados são preenchidos, em ordem, valores de parâmetro que você passa.  O primeiro membro de dados do parâmetro definido após a chamada de [SetFieldType](../Topic/CFieldExchange::SetFieldType.md) substitui o primeiro “?” na cadeia de caracteres SQL, o segundo membro de dados do parâmetro substitui o segundo? “”, e assim por diante.  
  
> [!NOTE]
>  A ordem de parâmetros é importante: a ordem das chamadas de RFX para parâmetros na função de `DoFieldExchange` deve corresponder à ordem dos espaços reservados de parâmetros na cadeia de caracteres SQL.  
  
> [!TIP]
>  A cadeia de caracteres mais provável a trabalhar é a cadeia de caracteres que você especifica \(se houver\) do membro de dados de [m\_strFilter](../Topic/CRecordset::m_strFilter.md) da classe, mas alguns drivers ODBC podem permitir parâmetros em outras cláusulas do SQL.  
  
##  <a name="_core_passing_parameter_values_at_run_time"></a> Passando valores de parâmetro em tempo de execução  
 Você deve especificar valores de parâmetro antes de chamar **Abrir** \(para um novo objeto do conjunto de registros **Requery** \) ou \(para\) existente.  
  
#### Para passar valores para um conjunto de registros objeto em tempo de execução  
  
1.  Construir o objeto do conjunto de registros.  
  
2.  Preparar uma cadeia de caracteres ou mais cadeias de caracteres, como a cadeia de caracteres de **m\_strFilter** , contendo a instrução SQL, ou partes delas.  Colocar “?” os espaços reservados onde as informações de parâmetro ele será.  
  
3.  Atribuir um valor do parâmetro de tempo de execução para cada membro de dados do parâmetro do objeto.  
  
4.  Chame a função de membro de **Abrir** \(ou **Requery**, para um conjunto de registros existente\).  
  
 Por exemplo, suponha que você deseja especificar uma cadeia de caracteres de filtro para o conjunto de registros usando as informações obtidas em tempo de execução.  Suponha que você construídas um conjunto de registros da classe `CStudentSet` anterior — `rsStudent`chamado — s e quer agora que você consulte novamente para um tipo específico de informações do aluno.  
  
```  
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
  
 O conjunto de registros contém registros para os alunos cujos registros atendem às condições especificadas pelo filtro, que foi construído dos parâmetros de tempo de execução.  Nesse caso, o conjunto de registros contém registros para todos os alunos superiores.  
  
> [!NOTE]
>  Se necessário, você pode definir o valor de um membro de dados do parâmetro como nulo, usando [SetParamNull](../Topic/CRecordset::SetParamNull.md).  É possível do mesmo modo verificar se um membro de dados do parâmetro é nulo, usando [IsFieldNull](../Topic/CRecordset::IsFieldNull.md).  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: adicionando, atualizando e excluindo registros \(ODBC\)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)   
 [Conjunto de registros: como conjuntos de registros selecionam registros \(ODBC\)](../Topic/Recordset:%20How%20Recordsets%20Select%20Records%20\(ODBC\).md)