---
title: 'Conjunto de registros: Parametrizando um conjunto de registros (ODBC) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- parameterizing recordsets
- ODBC recordsets, parameterizing
- recordsets, parameterizing
- passing parameters, to queries at runtime
ms.assetid: 7d1dfeb6-5ee0-45e2-aacc-63bc52a465cd
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: e282bf795435d21264ff4ab62575b9315781a0e0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="recordset-parameterizing-a-recordset-odbc"></a>Conjunto de registros: parametrizando um conjunto de registros (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Às vezes, convém poder selecionar registros em tempo de execução usando informações de você ter calculado ou obtido do seu usuário final. Parâmetros de conjunto de registros permitem atingir essa meta.  
  
 Este tópico explica:  
  
-   [A finalidade de um conjunto de registros com parâmetros](#_core_parameterized_recordsets).  
  
-   [Quando e por que talvez você queira parametrizar um conjunto de registros](#_core_when_to_use_parameters).  
  
-   [Como declarar membros de dados em sua classe de conjunto de registros de parâmetro](#_core_parameterizing_your_recordset_class).  
  
-   [Como passar informações de parâmetro para um objeto de conjunto de registros em tempo de execução](#_core_passing_parameter_values_at_run_time).  
  
##  <a name="_core_parameterized_recordsets"></a>Conjuntos de registros com parâmetros  
 Um conjunto de registros com parâmetros permite passar informações de parâmetro em tempo de execução. Isso tem dois efeitos importante:  
  
-   Isso pode resultar em maior velocidade de execução.  
  
-   Ele permite que você criar uma consulta em tempo de execução, com base nas informações não disponíveis para você em tempo de design, como informações obtidas do usuário ou calculados em tempo de execução.  
  
 Quando você chama **abrir** para executar a consulta, o conjunto de registros usa as informações de parâmetro para concluir sua **SQL SELECT** instrução. Você pode parametrizar qualquer conjunto de registros.  
  
##  <a name="_core_when_to_use_parameters"></a>Quando usar parâmetros  
 Usos típicos para parâmetros incluem:  
  
-   Passando argumentos de tempo de execução para uma consulta predefinida.  
  
     Para passar parâmetros para um procedimento armazenado, você deve especificar um ODBC personalizada completa **chamar** instrução — com espaços reservados de parâmetros — quando você chama **abrir**, substituindo a instrução SQL do conjunto de registros padrão. Para obter mais informações, consulte [CRecordset::Open](../../mfc/reference/crecordset-class.md#open) no *referência da biblioteca de classe* e [SQL: SQL instrução (ODBC do Personalizando seu conjunto de registros)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md) e [ Conjunto de registros: Declarando uma classe para uma consulta predefinida (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md).  

  
-   Executar várias requeries com informações de parâmetro diferente de forma eficiente.  
  
     Por exemplo, cada vez que o usuário final procura informações para um aluno específico no banco de dados de registro dos alunos, você pode especificar nome ou a identificação do aluno como um parâmetro obtido do usuário. Em seguida, quando você chama o conjunto de registros **Requery** função de membro, a consulta seleciona somente o registro que student.  
  
     Cadeia de caracteres de filtro de seu conjunto de registros, armazenada em **m_strFilter**, pode ter esta aparência:  
  
    ```  
    "StudentID = ?"  
    ```  
  
     Suponha que você obtenha a ID do estudante na variável `strInputID`. Quando você define um parâmetro `strInputID` (por exemplo, o aluno ID 100), o valor da variável é associado para o espaço reservado de parâmetro representado pelo "?" na cadeia de caracteres de filtro.  
  
     Atribua o valor do parâmetro da seguinte maneira:  
  
    ```  
    strInputID = "100";  
    ...  
    m_strParam = strInputID;  
    ```  
  
     Você não deseja configurar uma cadeia de caracteres de filtro dessa forma:  
  
    ```  
    m_strFilter = "StudentID = 100";   // 100 is incorrectly quoted  
                                       // for some drivers  
    ```  
  
     Para obter uma discussão de como usar aspas corretamente para cadeias de caracteres de filtro, consulte [conjunto de registros: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md).  
  
     O valor do parâmetro é diferente cada vez que repetir o conjunto de registros para uma nova ID de estudante.  
  
    > [!TIP]
    >  Usando um parâmetro é mais eficiente do que simplesmente um filtro. Para um conjunto de registros com parâmetros, o banco de dados deve processar um SQL **selecione** instrução apenas uma vez. Para um conjunto de registros filtrado sem parâmetros, o **selecione** instrução deve ser processada sempre que você **Requery** com um novo valor de filtro.  
  
 Para obter mais informações sobre filtros, consulte [conjunto de registros: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md).  
  
##  <a name="_core_parameterizing_your_recordset_class"></a>Parametrizando sua classe de conjunto de registros  
  
> [!NOTE]
>  Esta seção se aplica a objetos derivados de `CRecordset` em qual linha em massa busca não foi implementada. Se você estiver usando a linha em massa busca, Implementando parâmetros é um processo semelhante. Para obter mais informações, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
 Antes de criar sua classe de conjunto de registros, determine quais parâmetros que você precisa, seus tipos de dados e como o conjunto de registros usa-los.  
  
#### <a name="to-parameterize-a-recordset-class"></a>Para parametrizar uma classe de conjunto de registros  
  
1.  Execute o [Assistente de consumidor ODBC MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) de **Adicionar classe** para criar a classe.  
  
2.  Especifique os membros de dados de campo para colunas do conjunto de registros.  
  
3.  Depois que o assistente grava a classe de um arquivo em seu projeto, vá para o arquivo. h e adicionar manualmente um ou mais membros de dados de parâmetro para a declaração de classe. A adição algo parecido com o exemplo a seguir, a parte de uma classe de instantâneo criado para responder a consulta "que os alunos são na classe sênior?"  
  
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
  
     Adicione os membros de dados do parâmetro após os membros de dados do campo geradas pelo assistente. A convenção é acrescentar a palavra "Param" para cada nome de parâmetro definidos pelo usuário.  
  
4.  Modificar o [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) definição de função de membro no arquivo. cpp. Adicione uma chamada de função RFX para cada membro de dados do parâmetro adicionado à classe. Para obter informações sobre como escrever funções RFX, consulte [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md). Preceda as chamadas RFX para os parâmetros com uma única chamada para:  
  
    ```  
    pFX->SetFieldType( CFieldExchange::param );  
    // RFX calls for parameter data members  
    ```  
  
5.  No construtor da classe do conjunto de registros, incrementa a contagem de parâmetros, `m_nParams`.  
  
     Para obter informações, consulte [registrar troca de campos: Trabalhando com o código do assistente](../../data/odbc/record-field-exchange-working-with-the-wizard-code.md).  
  
6.  Quando você escreve o código que cria um objeto de conjunto de registros dessa classe, coloque um "?" símbolo (ponto de interrogação) em cada local em suas cadeias de caracteres de instrução SQL em que um parâmetro é a ser substituído.  
  
     Em tempo de execução "?" espaços reservados são preenchidos, em ordem, pelos valores de parâmetro você transmitir. O primeiro membro de dados do parâmetro definido após o [SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) chamada substitui a primeira "?"na cadeia de caracteres SQL, o segundo membro de dados do parâmetro substitui a segunda"?", e assim por diante.  
  
> [!NOTE]
>  Ordem do parâmetro é importante: a ordem de RFX chamadas para parâmetros em seu `DoFieldExchange` função deve corresponder à ordem dos espaços reservados de parâmetro em sua cadeia de caracteres SQL.  
  
> [!TIP]

>  A cadeia de caracteres mais provável para trabalhar com é a cadeia de caracteres que você especificar (se houver) para a classe [m_strFilter](../../mfc/reference/crecordset-class.md#m_strfilter) membro de dados, mas alguns drivers ODBC podem permitir que parâmetros em outras cláusulas SQL.  
  
##  <a name="_core_passing_parameter_values_at_run_time"></a>Passando valores de parâmetro em tempo de execução  
 Você deve especificar valores de parâmetro antes de chamar **abrir** (para um novo objeto de conjunto de registros) ou **Requery** (por um já existente).  
  
#### <a name="to-pass-parameter-values-to-a-recordset-object-at-run-time"></a>Para passar valores de parâmetro para um objeto de conjunto de registros em tempo de execução  
  
1.  Construa o objeto de conjunto de registros.  
  
2.  Preparar uma cadeia de caracteres ou cadeias de caracteres, como o **m_strFilter** cadeia de caracteres que contém a instrução SQL ou partes dele. Colocar "?" espaços reservados onde as informações de parâmetro são ir.  
  
3.  Atribua um valor de parâmetro de tempo de execução para cada membro de dados do parâmetro do objeto.  
  
4.  Chamar o **abrir** função de membro (ou **Requery**, para um conjunto de registros existente).  
  
 Por exemplo, suponha que você deseja especificar uma cadeia de caracteres de filtro para o conjunto de registros usando as informações obtidas em tempo de execução. Suponha que você ter criado um conjunto de registros da classe `CStudentSet` anteriormente — chamado `rsStudents` — e agora deseja repetir a consulta para um determinado tipo de informações do aluno.  
  
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
  
 O conjunto de registros contém registros para os alunos cujos registros atendem às condições especificadas pelo filtro, que foi construído a partir de parâmetros de tempo de execução. Nesse caso, o conjunto de registros contém registros para todos os alunos sênior.  
  
> [!NOTE]
>  Se necessário, você pode definir o valor de um membro de dados do parâmetro como Null, usando [SetParamNull](../../mfc/reference/crecordset-class.md#setparamnull). Você pode verificar da mesma forma se um membro de dados de parâmetro for Null, usando [IsFieldNull](../../mfc/reference/crecordset-class.md#isfieldnull).  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)   
 [Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)