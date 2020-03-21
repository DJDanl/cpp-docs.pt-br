---
title: 'Conjunto de registros: declarando uma classe para uma consulta predefinida (ODBC)'
ms.date: 05/09/2019
helpviewer_keywords:
- ODBC recordsets, queries
- predefined queries and recordsets
- stored procedures, and recordsets
- recordsets, predefined queries
- recordsets, stored procedures
ms.assetid: d27c4df9-dad2-4484-ba72-92ab0c8ff928
ms.openlocfilehash: 6338de99bf9c3e19e6e15ffbe0bcf5caab066ed8
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079830"
---
# <a name="recordset-declaring-a-class-for-a-predefined-query-odbc"></a>Conjunto de registros: declarando uma classe para uma consulta predefinida (ODBC)

> [!NOTE]
> O Assistente de consumidor ODBC do MFC não está disponível no Visual Studio 2019 e posterior. É possível criar um consumidor manualmente.

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica como criar uma classe de conjunto de registros para uma consulta predefinida (às vezes chamada de um procedimento armazenado, como no Microsoft SQL Server).

> [!NOTE]
>  Este tópico aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. Se o fetch de linha em massa for implementado, o processo será muito semelhante. Para entender as diferenças entre os conjuntos de registros que implementam a busca de linha em massa e os que não têm, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Alguns DBMs (sistemas de gerenciador de banco de dados) permitem que você crie uma consulta predefinida e chame-a dos seus programas como uma função. A consulta tem um nome, pode usar parâmetro e retornar registros. O procedimento neste tópico descreve como chamar uma consulta predefinida que retorna resultados (e talvez usa parâmetros).

As classes do banco de dados não dão suporte à atualização de consultas predefinidas. A diferença entre uma consulta predefinida de instantâneo e uma consulta predefinida dynaset não é a capacidade de atualização, mas se as alterações feitas por outros usuários (ou outros conjuntos de registros em seu programa) estão visíveis em seu conjunto de registros.

> [!TIP]
>  Não é necessário um conjunto de registros para chamar uma consulta predefinida que não retorna registros. Prepare a instrução SQL conforme descrito abaixo, mas execute-a chamado a função de membro `CDatabase`[ExecuteSQL](../../mfc/reference/cdatabase-class.md#executesql).

É possível criar uma única classe de conjunto de registros para gerenciar a chamada de uma consulta predefinida, mas é necessário realizar um pouco do trabalho sozinho. Os assistentes não dão suporte à criação de uma classe especificamente para essa finalidade.

#### <a name="to-create-a-class-for-calling-a-predefined-query-stored-procedure"></a>Para criar uma classe para chamar uma consulta predefinida (procedimento armazenado)

1. Use o [Assistente de consumidor ODBC MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) de **Adicionar Classe** para criar uma classe de conjunto de registros para a tabela que contribui com o máximo de colunas retornadas pela consulta. Isso oferece a você um ponto de partida.

1. Adicione membros de dados de campo manualmente para quaisquer colunas de quaisquer tabelas retornadas pela consulta, mas que o assistente não criou para você.

   Por exemplo, se a consulta retornar três colunas cada de duas tabelas adicionais, adicione seis membros de dados de campo (do tipo de dados adequado) à classe.

1. Adicionar manualmente as chamadas de função [RFX](../../data/odbc/record-field-exchange-rfx.md) na função de membro [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) da classe, uma correspondente ao tipo de dados de cada membro de dados de campo adicionado.

    ```cpp
    Immediately before these RFX calls, call <MSHelp:link keywords="_mfc_CFieldExchange.3a3a.SetFieldType" TABINDEX="0">SetFieldType</MSHelp:link>, as shown here:
    pFX->SetFieldType( CFieldExchange::outputColumn );
    ```

    > [!NOTE]
    >  É necessário conhecer os tipos de dados e a ordem de colunas retornadas no conjunto de resultados. A ordem das chamadas de função RFX em `DoFieldExchange` deve corresponder à ordem das colunas do conjunto de resultados.

1. Adicione manualmente inicializações dos novos membros de dados de campo no construtor da classe do conjunto de registros.

   Também é necessário incrementar o valor de inicialização do membro de dados [m_nFields](../../mfc/reference/crecordset-class.md#m_nfields). O assistente escreve a inicialização, mas só abrange os membros de dados de campo adicionados para você. Por exemplo:

    ```cpp
    m_nFields += 6;
    ```

   Alguns tipos de dados não devem ser inicializados aqui, por exemplo, `CLongBinary` ou matriz de bytes.

1. Se a consulta usar parâmetros, adicione um membro de dados de parâmetro, uma chamada de função RFX e uma inicialização para cada parâmetro.

1. É necessário incrementar `m_nParams` para cada parâmetro adicionado, como você fez `m_nFields` para os campos adicionados na etapa 4 deste procedimento. Para obter mais informações, consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

1. Escreva manualmente uma cadeia de caracteres da instrução SQL com o seguinte formulário:

    ```
    {CALL proc-name [(? [, ?]...)]}
    ```

   em que **CALL** é uma palavra-chave ODBC, **proc-name** é o nome da consulta como é conhecido na fonte de dados e os itens "?" são espaços reservados para os valores de parâmetro fornecidos ao conjunto de registros em tempo de execução (se houver). O exemplo a seguir prepara um espaço reservado para um parâmetro:

    ```
    CString mySQL = "{CALL Delinquent_Accts (?)}";
    ```

1. No código que abre o conjunto de registros, defina os valores dos membros de dados de parâmetro do conjunto de registros e, em seguida, chame a função de membro `Open` passando sua cadeia de caracteres SQL para o parâmetro *lpszSQL*. Ou, em vez disso, substitua a cadeia de caracteres retornada pela função de membro `GetDefaultSQL` em sua classe.

Os exemplos a seguir mostram o procedimento para chamar uma consulta predefinida, chamada `Delinquent_Accts`, que usa um parâmetro para um número de distrito de vendas. Esta consulta retorna três colunas: `Acct_No`, `L_Name`, `Phone`. Todas as colunas vêm da tabela Clientes.

O conjunto de registros a seguir especifica membros de dados de campo para as colunas que a consulta retorna e um parâmetro para o número de distrito de vendas solicitado em tempo de execução.

```cpp
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

Esta declaração de classe é como o assistente a escreve, exceto pelo membro `m_lDistParam` adicionado manualmente. Outros membros não são mostrados aqui.

O próximo exemplo mostra as inicializações dos membros de dados no construtor `CDelinquents`.

```cpp
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

Observe as inicializações para [m_nFields](../../mfc/reference/crecordset-class.md#m_nfields) e [m_nParams](../../mfc/reference/crecordset-class.md#m_nparams). O assistente inicializa `m_nFields`; você inicializa `m_nParams`.

O próximo exemplo mostra as funções RFX em `CDelinquents::DoFieldExchange`:

```cpp
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

Além de marcar as chamadas RFX para as três colunas retornadas, esse código gerencia a associação do parâmetro que você passa em tempo de execução. O parâmetro é ligado à coluna `Dist_No` (número de distrito).

O exemplo a seguir mostra como configurar a cadeia de caracteres SQL e como usá-la para abrir o conjunto de registros.

```cpp
// Construct a CDelinquents recordset object
CDelinquents rsDel( NULL );
CString strSQL = "{CALL Delinquent_Accts (?)}"
// Specify a parameter value (obtained earlier from the user)
rsDel.m_lDistParam = lDistrict;
// Open the recordset and run the query
if( rsDel.Open( CRecordset::snapshot, strSQL ) )
    // Use the recordset ...
```

Esse código constrói um instantâneo, passa-o para um parâmetro obtido anteriormente do usuário e chama a consulta predefinida. Quando a consulta é executada, ela retorna registros para o distrito de vendas especificado. Cada registro contém colunas para o número da conta e para o sobrenome e o número de telefone do cliente.

> [!TIP]
>  Convém manipular um valor retornado (parâmetro de saída) de um procedimento armazenado. Para saber mais e obter um exemplo, confira [CFieldExchange::SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: repetindo consulta a um conjunto de registros (ODBC)](../../data/odbc/recordset-requerying-a-recordset-odbc.md)<br/>
[Conjunto de registros: declarando uma classe para uma tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md)<br/>
[Conjunto de registros: realizando uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md)