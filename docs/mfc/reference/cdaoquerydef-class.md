---
title: "Classe de CDaoQueryDef | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CDaoQueryDef"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDaoQueryDef"
  - "consultas [Visual Studio], definindo"
  - "Objetos de QueryDef"
ms.assetid: 9676a4a3-c712-44d4-8c5d-d1cc78288d3a
caps.latest.revision: 24
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDaoQueryDef
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma definição de consulta, ou “,” querydef geralmente um salvo em um banco de dados.  
  
## Sintaxe  
  
```  
class CDaoQueryDef : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoQueryDef::CDaoQueryDef](../Topic/CDaoQueryDef::CDaoQueryDef.md)|Constrói um objeto de **CDaoQueryDef** .  Próxima chamada **Abrir** ou **Criar**, dependendo das suas necessidades.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoQueryDef::Append](../Topic/CDaoQueryDef::Append.md)|Acrescenta o querydef à coleção de QueryDefs de banco de dados como uma consulta salva.|  
|[CDaoQueryDef::CanUpdate](../Topic/CDaoQueryDef::CanUpdate.md)|Retorna diferente de zero se a consulta pode atualizar o banco de dados.|  
|[CDaoQueryDef::Close](../Topic/CDaoQueryDef::Close.md)|Fecha o objeto de querydef.  Destrua o objeto C\+\+ quando você terminar com ele.|  
|[CDaoQueryDef::Create](../Topic/CDaoQueryDef::Create.md)|Cria o objeto subjacente de querydef de DAO.  Use o querydef como uma consulta temporária, ou a chamada para **Acrescentar** salve\-o no banco de dados.|  
|[CDaoQueryDef::Execute](../Topic/CDaoQueryDef::Execute.md)|Executa a consulta definida pelo objeto de querydef.|  
|[CDaoQueryDef::GetConnect](../Topic/CDaoQueryDef::GetConnect.md)|Retorna a cadeia de conexão associado com o querydef.  a cadeia de conexão identifica a fonte de dados.  \(Para passagem consultas SQL; apenas se não uma cadeia de caracteres vazia.\)|  
|[CDaoQueryDef::GetDateCreated](../Topic/CDaoQueryDef::GetDateCreated.md)|Retorna a data que a consulta salva foi criada.|  
|[CDaoQueryDef::GetDateLastUpdated](../Topic/CDaoQueryDef::GetDateLastUpdated.md)|Retorna a data que a consulta salva foi atualizado à última vez.|  
|[CDaoQueryDef::GetFieldCount](../Topic/CDaoQueryDef::GetFieldCount.md)|Retorna o número de campos definidos por querydef.|  
|[CDaoQueryDef::GetFieldInfo](../Topic/CDaoQueryDef::GetFieldInfo.md)|Retorna informações sobre um campo especificado definido na consulta.|  
|[CDaoQueryDef::GetName](../Topic/CDaoQueryDef::GetName.md)|Retorna o nome de querydef.|  
|[CDaoQueryDef::GetODBCTimeout](../Topic/CDaoQueryDef::GetODBCTimeout.md)|Retorna o valor de tempo limite usado por ODBC \(para uma consulta ODBC\) quando o querydef é executado.  Isso determina quanto tempo permitir a ação de consulta concluir.|  
|[CDaoQueryDef::GetParameterCount](../Topic/CDaoQueryDef::GetParameterCount.md)|Retorna o número de parâmetros definidos para a consulta.|  
|[CDaoQueryDef::GetParameterInfo](../Topic/CDaoQueryDef::GetParameterInfo.md)|Retorna informações sobre um parâmetro especificado para a consulta.|  
|[CDaoQueryDef::GetParamValue](../Topic/CDaoQueryDef::GetParamValue.md)|Retorna o valor de um parâmetro especificado para a consulta.|  
|[CDaoQueryDef::GetRecordsAffected](../Topic/CDaoQueryDef::GetRecordsAffected.md)|Retorna o número de registros afetados por uma consulta ação.|  
|[CDaoQueryDef::GetReturnsRecords](../Topic/CDaoQueryDef::GetReturnsRecords.md)|Retorna diferente de zero se a consulta definida pelo querydef retorna registros.|  
|[CDaoQueryDef::GetSQL](../Topic/CDaoQueryDef::GetSQL.md)|Retorna a cadeia de caracteres SQL que especifica a consulta definida pelo querydef.|  
|[CDaoQueryDef::GetType](../Topic/CDaoQueryDef::GetType.md)|Retorna o tipo de consulta: excluir, atualizar, acrescente, bastará \- tabela, e assim por diante.|  
|[CDaoQueryDef::IsOpen](../Topic/CDaoQueryDef::IsOpen.md)|Retorna diferente de zero se o querydef está aberto e pode ser executado.|  
|[CDaoQueryDef::Open](../Topic/CDaoQueryDef::Open.md)|Abre um querydef armazenado existente na coleção de QueryDefs de banco de dados.|  
|[CDaoQueryDef::SetConnect](../Topic/CDaoQueryDef::SetConnect.md)|Defina a cadeia de conexão para passar uma consulta SQL em uma fonte de dados ODBC.|  
|[CDaoQueryDef::SetName](../Topic/CDaoQueryDef::SetName.md)|Define o nome da consulta salva, substituindo o nome em uso quando o querydef foi criado.|  
|[CDaoQueryDef::SetODBCTimeout](../Topic/CDaoQueryDef::SetODBCTimeout.md)|Defina o valor de tempo limite usado por ODBC \(para uma consulta ODBC\) quando o querydef é executado.|  
|[CDaoQueryDef::SetParamValue](../Topic/CDaoQueryDef::SetParamValue.md)|Defina o valor de um parâmetro especificado para a consulta.|  
|[CDaoQueryDef::SetReturnsRecords](../Topic/CDaoQueryDef::SetReturnsRecords.md)|Especifica se o querydef retorna registros.  Defina esse atributo a **Verdadeiro** só é válido para passagem consultas SQL.|  
|[CDaoQueryDef::SetSQL](../Topic/CDaoQueryDef::SetSQL.md)|Defina a cadeia de caracteres SQL que especifica a consulta definida pelo querydef.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoQueryDef::m\_pDAOQueryDef](../Topic/CDaoQueryDef::m_pDAOQueryDef.md)|Um ponteiro para a interface para OLE o objeto subjacente de querydef de DAO.|  
|[CDaoQueryDef::m\_pDatabase](../Topic/CDaoQueryDef::m_pDatabase.md)|Um ponteiro para o objeto de `CDaoDatabase` com que o querydef está associado.  O querydef pode ser salvo no banco de dados ou não.|  
  
## Comentários  
 Um querydef é um objeto de acesso a dados que contém a instrução SQL que descreve uma consulta, e suas propriedades, como “data” e “criada de tempo limite ODBC.” Você também pode criar objetos temporários de querydef sem o salva, mas é conveniente — e muito mais eficiente — salvar consultas geralmente usado em um banco de dados.  Um objeto de [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) mantém uma coleção, chamada a coleção de QueryDefs, que contém seus querydefs salvos.  
  
> [!NOTE]
>  As classes de banco de dados de DAO são distintas de classes do banco de dados MFC baseado em Open Database Connectivity \(ODBC\).  Todos os nomes de classe de banco de dados de DAO têm o prefixo “CDao”.  Você ainda pode acessar fontes de dados ODBC com as classes de DAO.  Em geral, as classes MFC com base em DAO mais são capazes das classes MFC baseado em ODBC; as classes base DAO\- podem acessar os dados, incluindo através dos drivers ODBC, através de seu próprio mecanismo de banco de dados.  As classes base DAO\- também suporta operações language \(DDL\) de definição de dados, como adicionar tabelas por meio de classes, sem precisar chamar diretamente DAO.  
  
## Uso  
 Objetos de querydef de uso para trabalhar com uma consulta salva existente ou criar uma nova consulta salva ou a consulta temporária:  
  
1.  Em todos os casos, primeiro criar um objeto de `CDaoQueryDef` , fornecendo um ponteiro para o objeto de [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) que pertence à consulta.  
  
2.  Faça a seguir, dependendo do que você deseja:  
  
    -   Para usar um existente salvar a consulta, chama a função de membro de [Abrir](../Topic/CDaoQueryDef::Open.md) do objeto de querydef, fornecendo o nome da consulta salva.  
  
    -   Para criar uma nova consulta salva, chame a função de membro de [Criar](../Topic/CDaoQueryDef::Create.md) do objeto de querydef, fornecendo o nome da consulta.  Chame o [acrescentar](../Topic/CDaoQueryDef::Append.md) para salvar a consulta adicionando um à coleção de QueryDefs de banco de dados.  **Criar** coloca o querydef em um estado aberto, logo após chamando **Criar** que você não chama **Abrir**.  
  
    -   Para criar um querydef temporário, chame **Criar**.  Passar uma cadeia de caracteres vazia para o nome da consulta.  Não chamar **Acrescentar**.  
  
 Quando você terminar de usar um objeto de querydef, chame a função de membro de [Fechar](../Topic/CDaoQueryDef::Close.md) ; destrua no objeto de querydef.  
  
> [!TIP]
>  A maneira mais fácil de criar consultas salvas é criá\-las e os armazena no seu banco de dados usando o Microsoft Access.  Em seguida você pode abri\-los e usar em seu código MFC.  
  
## Fins  
 Você pode usar um objeto de querydef para algumas das finalidades:  
  
-   Para criar um objeto de `CDaoRecordset`  
  
-   Para chamar a função de membro de **Executar** do objeto para executar uma consulta diretamente ação ou uma passagem consulta SQL  
  
 Você pode usar um objeto de querydef para qualquer tipo de consulta, incluindo selecione, de ação de tabela de referência, cruzada de excluir, atualizar, acrescentar\-lo, de bastará \- tabela, de definição de dados, de passagem SQL, e de união de consultas em massa.  O tipo de consulta é determinado pelo conteúdo da instrução SQL que você fornece.  Para obter informações sobre tipos de consulta, consulte **Executar** e funções de membro de [GetType](../Topic/CDaoQueryDef::GetType.md) .  Os conjuntos de registros são normalmente usadas para consultas retornando linhas, geralmente aquelas que **usam o SELECT…**  A palavra\-chave.  **Executar** é mais comumente usado para operações em massa.  Para obter mais informações, consulte [Executar](../Topic/CDaoQueryDef::Execute.md) e [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).  
  
## Querydefs e conjuntos de registros  
 Para usar um objeto de querydef para criar um objeto de `CDaoRecordset` , você normalmente cria ou abre um querydef como descrito acima.  Construir em um objeto do conjunto de registros, passando um ponteiro ao objeto de querydef quando você chama [CDaoRecordset::Open](../Topic/CDaoRecordset::Open.md).  O querydef que você passa deve estar em um estado aberto.  Para obter mais informações, consulte a classe [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).  
  
 Você não pode usar um querydef para criar um conjunto de registros \(o uso mais comum para um querydef\) a menos que está em um estado aberto.  Coloque o querydef em um estado aberta chamando **Abrir** ou **Criar**.  
  
## Bancos de dados externos  
 Os objetos de Querydef é a maneira preferencial para usar o dialeto do SQL nativo de um mecanismo de banco de dados externo.  Por exemplo, você pode criar uma consulta SQL transacionar \(usada no Microsoft SQL Server\) e armazená\-las em um objeto de querydef.  Quando você precisar usar uma consulta SQL não com o mecanismo de banco de dados Microsoft Jet, você deve fornecer uma cadeia de conexão que aponta para a fonte de dados externa.  Consultas com cadeias de conexão válidos ignorar o mecanismo de banco de dados e passe a consulta diretamente para o servidor de banco de dados externa para processamento.  
  
> [!TIP]
>  A maneira preferencial para trabalhar com tabelas ODBC é anexar\-las a um banco de dados Microsoft Jet \(.MDB\).  
  
 Para informações relacionadas, consulte os tópicos de “objeto QueryDef”, “coleção QueryDefs,” e “objeto” CdbDatabase no DAO SDK.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CDaoQueryDef`  
  
## Requisitos  
 **Cabeçalho:** afxdao.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)   
 [Classe de CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)   
 [Classe de CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)   
 [Classe de CDaoException](../../mfc/reference/cdaoexception-class.md)