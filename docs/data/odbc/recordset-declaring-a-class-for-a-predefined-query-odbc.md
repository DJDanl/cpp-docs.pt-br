---
title: 'Conjunto de registros: Declarando uma classe para uma consulta predefinida (ODBC) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- ODBC recordsets, queries
- predefined queries and recordsets
- stored procedures, and recordsets
- recordsets, predefined queries
- recordsets, stored procedures
ms.assetid: d27c4df9-dad2-4484-ba72-92ab0c8ff928
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 8ecdc146610fe20dcc007d6b1223d7108e1ee595
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="recordset-declaring-a-class-for-a-predefined-query-odbc"></a>Conjunto de registros: declarando uma classe para uma consulta predefinida (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Este tópico explica como criar uma classe de conjunto de registros para uma consulta predefinida (às vezes chamada de um procedimento armazenado, como Microsoft SQL Server).  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa busca não foi implementada. Se a busca de linhas em massa é implementada, o processo é muito semelhante. Para entender as diferenças entre conjuntos de registros que implementam a busca de linhas em massa e os que não, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
 Alguns sistemas de gerenciamento de banco de dados (DBMSs) permitem que você crie uma consulta predefinida e chamá-lo a partir de seus programas como uma função. A consulta tem um nome, pode levar a parâmetros e pode retornar registros. O procedimento neste tópico descreve como chamar uma consulta predefinida que retorna registros (e talvez usa parâmetros).  
  
 As classes de banco de dados não dão suporte a consultas predefinidas de atualização. A diferença entre uma consulta predefinida do instantâneo e uma consulta predefinida dynaset não é capacidade de atualização, mas se as alterações feitas por outros usuários (ou outros conjuntos de registros em seu programa) são visíveis em seu conjunto de registros.  
  
> [!TIP]
>  Não é necessário um conjunto de registros para chamar uma consulta predefinida que não retorna registros. Preparar a instrução SQL, conforme descrito abaixo, mas executá-lo chamando o `CDatabase` função de membro [ExecuteSQL](../../mfc/reference/cdatabase-class.md#executesql).  
  
 Você pode criar uma classe de conjunto de registros único para gerenciar a chamar uma consulta predefinida, mas você deve fazer parte do trabalho. Os assistentes não dão suporte a criação de uma classe especificamente para essa finalidade.  
  
#### <a name="to-create-a-class-for-calling-a-predefined-query-stored-procedure"></a>Para criar uma classe para chamar uma consulta predefinida (procedimento armazenado)  
  
1.  Use o [Assistente de consumidor ODBC MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) de **Adicionar classe** para criar uma classe de conjunto de registros para a tabela que contribui mais colunas retornadas pela consulta. Isso fornece um ponto de partida.  
  
2.  Adicione manualmente os membros de dados de campo para todas as colunas de todas as tabelas que a consulta retorna, mas que o assistente não tiver criado para você.  
  
     Por exemplo, se a consulta retorna três colunas de duas tabelas adicionais, adicione membros de dados de campo seis (dos tipos de dados apropriado) à classe.  
  
3.  Adicionar manualmente [RFX](../../data/odbc/record-field-exchange-rfx.md) chamadas de função no [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) adicionado de função de membro da classe, um correspondente ao tipo de dados de cada membro de dados do campo.  
  
    ```  
    Immediately before these RFX calls, call <MSHelp:link keywords="_mfc_CFieldExchange.3a3a.SetFieldType" TABINDEX="0">SetFieldType</MSHelp:link>, as shown here:   
    pFX->SetFieldType( CFieldExchange::outputColumn );  
    ```  
  
    > [!NOTE]
    >  Você deve saber os tipos de dados e a ordem das colunas retornadas no resultado definido. A ordem da função RFX chamadas em `DoFieldExchange` deve corresponder à ordem das colunas do conjunto de resultados.  
  
4.  Adicione manualmente as inicializações para os novos membros de dados de campo no construtor da classe de conjunto de registros.  
  
     Você também deve incrementar o valor de inicialização para o [m_nFields](../../mfc/reference/crecordset-class.md#m_nfields) membro de dados. O assistente grava a inicialização, mas ele aborda apenas os membros de dados do campo adiciona para você. Por exemplo:  
  
    ```  
    m_nFields += 6;  
    ```  
  
     Alguns tipos de dados não devem ser inicializados aqui, por exemplo, `CLongBinary` ou matrizes de bytes.  
  
5.  Se a consulta usa parâmetros, adicione um membro de dados para cada parâmetro, uma chamada de função RFX para cada e uma inicialização para cada parâmetro.  
  
6.  Você deve incrementar `m_nParams` para cada parâmetro adicionado, como você fez `m_nFields` para adicionar campos na etapa 4 deste procedimento. Para obter mais informações, consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).  
  
7.  Grave manualmente uma cadeia de caracteres da instrução SQL da seguinte forma:  
  
    ```  
    {CALL proc-name [(? [, ?]...)]}  
    ```  
  
     onde **chamar** é uma palavra-chave do ODBC, **nome proc** é o nome da consulta, como é conhecido na fonte de dados e o "?" itens são espaços reservados para os valores de parâmetro que você fornecer para o conjunto de registros em tempo de execução (se houver) . O exemplo a seguir prepara um espaço reservado para um parâmetro:  
  
    ```  
    CString mySQL = "{CALL Delinquent_Accts (?)}";  
    ```  
  
8.  No código que abre o conjunto de registros, defina os valores do parâmetro do conjunto de registros de membros de dados e, em seguida, chame o **abrir** função de membro, passando a cadeia de caracteres SQL o **lpszSQL** parâmetro. Ou, em vez disso, substitua a cadeia de caracteres retornada pelo `GetDefaultSQL` a função de membro em sua classe.  
  
 Os exemplos a seguir mostram o procedimento para chamar uma consulta predefinida, denominada `Delinquent_Accts`, que usa um parâmetro para um número de vendas regional. Esta consulta retorna três colunas: `Acct_No`, `L_Name`, `Phone`. São todas as colunas da tabela Customers.  
  
 O conjunto de registros a seguir especifica os membros de dados de campo para as colunas que a consulta retorna e um parâmetro para as vendas Distrito número solicitado em tempo de execução.  
  
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
  
 Esta declaração de classe é como o assistente grava, exceto para o `m_lDistParam` membro adicionado manualmente. Outros membros não são mostrados aqui.  
  
 O exemplo a seguir mostra as inicializações dos membros de dados do `CDelinquents` construtor.  
  
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
  
 Observe as inicializações para [m_nFields](../../mfc/reference/crecordset-class.md#m_nfields) e [m_nParams](../../mfc/reference/crecordset-class.md#m_nparams). Inicializa o assistente `m_nFields`; inicializar `m_nParams`.  
  
 O exemplo a seguir mostra as funções RFX em `CDelinquents::DoFieldExchange`:  
  
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
  
 Além de fazer as chamadas RFX para as três colunas retornadas, esse código gerencia a associação de parâmetro que passar em tempo de execução. O parâmetro é marcado para o `Dist_No` coluna (número regional).  
  
 O exemplo a seguir mostra como configurar a cadeia de caracteres do SQL e como usá-lo para abrir o conjunto de registros.  
  
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
  
 Esse código cria um instantâneo, passa um parâmetro obtido anteriormente do usuário e chama a consulta predefinida. Quando a consulta é executada, ela retorna registros para a região de vendas especificada. Cada registro contém colunas para o número da conta, o sobrenome do cliente e o número de telefone do cliente.  
  
> [!TIP]
>  Você talvez queira manipular um valor de retorno (parâmetro de saída) de um procedimento armazenado. Para obter mais informações e um exemplo, consulte [CFieldExchange::SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype).  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Repetindo consulta a um conjunto de registros (ODBC)](../../data/odbc/recordset-requerying-a-recordset-odbc.md)   
 [Conjunto de registros: Declarando uma classe para uma tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md)   
 [Conjunto de registros: realizando uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md)