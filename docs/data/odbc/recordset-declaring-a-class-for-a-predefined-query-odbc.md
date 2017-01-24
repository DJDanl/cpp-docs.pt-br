---
title: "Conjunto de registros: declarando uma classe para uma consulta predefinida (ODBC) | Microsoft Docs"
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
  - "conjunto de registros ODBC, consultas"
  - "consultas predefinidos e conjuntos de registros"
  - "conjuntos de registros, consultas predefinidas"
  - "conjuntos de registros, procedimentos armazenados"
  - "procedimentos armazenados, e conjunto de registros"
ms.assetid: d27c4df9-dad2-4484-ba72-92ab0c8ff928
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: declarando uma classe para uma consulta predefinida (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Este tópico explica como criar uma classe do conjunto de registros para uma consulta predefinido \(às vezes chamada de um procedimento armazenado, como no Microsoft SQL Server\).  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` no qual a busca de linhas do volume não foi implementado.  Se buscar em massa de linha é implementado, o processo é muito semelhante.  Para entender as diferenças entre clusters de registros que linha do volume de implementar à busca e aqueles que não, para ver [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
 Alguns sistemas de gerenciamento da base de dados \(DBMSs\) permitem que você crie uma consulta predefinida e denomine\-a de seus programas como uma função.  A consulta tem um nome, pode levar parâmetros, e pode retornar registros.  O procedimento deste tópico descreve como chamar uma consulta predefinida que registros de retorna \(e talvez usa parâmetros\).  
  
 As classes de base de dados do não oferecem suporte a consultas atualizar predefinidas.  A diferença entre um instantâneo predefinidas a consulta e uma consulta predefinida dynaset não é updateability mas se as alterações feitas por outros usuários \(ou outros conjuntos de registros em seu programa\) são visíveis no conjunto de registros.  
  
> [!TIP]
>  Você não precisa de um conjunto de registros de chamar uma consulta predefinida que não retorna registros.  Preparar a instrução SQL como descrito abaixo, mas a execução chamando a função de membro [ExecuteSQL](../Topic/CDatabase::ExecuteSQL.md)de `CDatabase` .  
  
 Você pode criar uma única classe do conjunto de registros para gerenciar chamar uma consulta predefinida, mas você deve realizar o trabalho você mesmo.  Os assistentes não oferecem suporte à criação de uma classe especificamente para essa finalidade.  
  
#### Para criar uma classe para chamar uma consulta predefinido \(procedimento armazenado\)  
  
1.  Use [Assistente do consumidor MFC ODBC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) de **Adicionar Classe** para criar uma classe do conjunto de registros para a tabela que contribui com a maioria das colunas retornadas pela consulta.  Isso fornece um avanço.  
  
2.  Adicionar manualmente membros de dados do campo para todas as colunas das tabelas que a consulta retorna mas que o assistente não tenha criado para você.  
  
     Por exemplo, se a consulta retorna três colunas cada uma das duas tabelas adicionais, adicione seis membros de dados do campo \(tipos de dados apropriados\) para a classe.  
  
3.  Adicionar manualmente chamadas de função de [RFX](../../data/odbc/record-field-exchange-rfx.md) na função de membro de [DoFieldExchange](../Topic/CRecordset::DoFieldExchange.md) da classe, uma que corresponde ao tipo de dados de cada membro de dados do campo adicionado.  
  
    ```  
    Immediately before these RFX calls, call <MSHelp:link keywords="_mfc_CFieldExchange.3a3a.SetFieldType" TABINDEX="0">SetFieldType</MSHelp:link>, as shown here:   
    pFX->SetFieldType( CFieldExchange::outputColumn );  
    ```  
  
    > [!NOTE]
    >  Você deve saber os tipos de dados e a ordem das colunas retornadas no conjunto de resultados.  A ordem das chamadas de função de RFX em `DoFieldExchange` deve corresponder à ordem das colunas do conjunto de resultados.  
  
4.  Adicionar manualmente inicializações para os novos membros de dados do campo no construtor de classe do conjunto de registros.  
  
     Você também deve aumentar o valor de inicialização do membro de dados de [m\_nFields](../Topic/CRecordset::m_nFields.md) .  O assistente grava a inicialização, mas abrangem somente os membros de dados do campo que adiciona para você.  Por exemplo:  
  
    ```  
    m_nFields += 6;  
    ```  
  
     Alguns tipos de dados não devem ser inicializados aqui, por exemplo, `CLongBinary` ou matrizes de bytes.  
  
5.  Se a consulta usa parâmetros, adicione um membro de dados para cada parâmetro, uma chamada de função de RFX para cada uma, e uma inicialização de cada um.  
  
6.  Você deve aumentar `m_nParams` para cada parâmetro é adicionado, como você fez `m_nFields` para campos adicionados na etapa 4 deste procedimento.  Para obter mais informações, consulte [Conjunto de registros: A parametrização de um conjunto de registros \(ODBC\)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).  
  
7.  Escreva manualmente uma cadeia de caracteres da instrução SQL com o seguinte formato:  
  
    ```  
    {CALL proc-name [(? [, ?]...)]}  
    ```  
  
     onde **CALL** é uma palavra\-chave do ODBC, **proc\-name** é o nome da consulta como se sabe na fonte de dados, e “?” os itens são espaços reservados para valores de parâmetro fornecidos ao conjunto de registros em tempo de execução \(se houver\).  O exemplo a seguir prepara um espaço reservado para um parâmetro:  
  
    ```  
    CString mySQL = "{CALL Delinquent_Accts (?)}";  
    ```  
  
8.  No código que abre o conjunto de registros, defina os valores dos membros de dados do parâmetro do conjunto de registros e chame a função de membro de **Abrir** , passando a cadeia de caracteres SQL para o parâmetro de **lpszSQL** .  Ou então, substitua a cadeia de caracteres retornada pela função de membro de `GetDefaultSQL` em sua classe.  
  
 Os exemplos a seguir mostram o procedimento para chamar uma consulta predefinida, `Delinquent_Accts`nomeado, que usa um parâmetro para um número de distrito de vendas.  Essa consulta retorna três colunas: `Acct_No`, `L_Name`, `Phone`.  Todas as colunas são da tabela Customers.  
  
 O seguinte conjunto de registros especifica membros de dados do campo para as colunas retornadas pela consulta e um parâmetro para o número de distrito de vendas solicitou em tempo de execução.  
  
```  
class CDelinquents : public CRecordset  
{  
// Field/Param Data  
    LONG m_lAcct_No;  
    CString m_strL_Name;  
    CString m_strPhone;  
    LONG m_lDistParam;  
    // ...  
};  
```  
  
 Esta declaração de classe é como o assistente a gravação, com exceção do membro de `m_lDistParam` adicionado manualmente.  Outros membros não são mostrados aqui.  
  
 O exemplo a seguir mostra as inicializações para os membros de dados no construtor de `CDelinquents` .  
  
```  
CDelinquents::CDelinquents(CDatabase* pdb)  
   : CRecordset(pdb)  
{  
    // Wizard-generated params:  
    m_lAcct_No = 0;  
    m_strL_Name = "";  
    m_strPhone = "";  
    m_nFields = 3;  
    // User-defined params:  
    m_nParams = 1;  
    m_lDistParam = 0;  
}  
```  
  
 Observe as inicializações para [m\_nFields](../Topic/CRecordset::m_nFields.md) e [m\_nParams](../Topic/CRecordset::m_nParams.md).  O assistente inicializa `m_nFields`; você inicializa `m_nParams`.  
  
 O exemplo a seguir mostra as funções de RFX em `CDelinquents::DoFieldExchange`:  
  
```  
void CDelinquents::DoFieldExchange(CFieldExchange* pFX)  
{  
    pFX->SetFieldType(CFieldExchange::outputColumn);  
    RFX_Long(pFX, "Acct_No", m_lAcct_No);  
    RFX_Text(pFX, "L_Name", m_strL_Name);  
    RFX_Text(pFX, "Phone", m_strPhone);  
    pFX->SetFieldType(CFieldExchange::param);  
    RFX_Long(pFX, "Dist_No", m_lDistParam);  
}  
```  
  
 Além de fazer chamadas de RFX para as três colunas retornadas, esse código gerencia associar o parâmetro que você passa em tempo de execução.  O parâmetro é fechado à coluna de `Dist_No` \(número de distrito\).  
  
 O exemplo seguinte mostra como configurar a cadeia de caracteres SQL e como usá\-la para abrir o conjunto de registros.  
  
```  
// Construct a CDelinquents recordset object  
CDelinquents rsDel( NULL );  
CString strSQL = "{CALL Delinquent_Accts (?)}"  
// Specify a parameter value (obtained earlier from the user)  
rsDel.m_lDistParam = lDistrict;  
// Open the recordset and run the query  
if( rsDel.Open( CRecordset::snapshot, strSQL ) )  
    // Use the recordset ...  
```  
  
 Esse código cria um instantâneo, passa um parâmetro anterior obtido do usuário, e chame a consulta predefinida.  Quando a consulta é executada, retorna registros para o distrito especificado de vendas.  Cada registro contém colunas para o número de conta, o sobrenome do cliente, e o número de telefone de cliente.  
  
> [!TIP]
>  Talvez você queira tratar um valor de retorno \(parâmetro de saída\) de um procedimento armazenado.  Para obter mais informações e um exemplo, consulte [CFieldExchange::SetFieldType](../Topic/CFieldExchange::SetFieldType.md).  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: repetindo consulta a um conjunto de registros \(ODBC\)](../../data/odbc/recordset-requerying-a-recordset-odbc.md)   
 [Conjunto de registros: declarando uma classe para uma tabela \(ODBC\)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md)   
 [Conjunto de registros: realizando uma junção \(ODBC\)](../Topic/Recordset:%20Performing%20a%20Join%20\(ODBC\).md)