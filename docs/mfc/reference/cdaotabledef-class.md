---
title: "Classe de CDaoTableDef | Microsoft Docs"
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
  - "CDaoTableDef"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDaoTableDef"
  - "banco de dados classes [C++], DAO"
  - "tabelas de banco de dados [C++], definição de tabela anexado"
  - "tabelas de banco de dados [C++], definição de tabela de base"
  - "tabledefs [C++]"
ms.assetid: 7c5d2254-8475-43c4-8a6c-2d32ead194c9
caps.latest.revision: 24
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDaoTableDef
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa a definição armazenada de uma tabela de base ou uma tabela anexado.  
  
## Sintaxe  
  
```  
class CDaoTableDef : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoTableDef::CDaoTableDef](../Topic/CDaoTableDef::CDaoTableDef.md)|Constrói um objeto de **CDaoTableDef** .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoTableDef::Append](../Topic/CDaoTableDef::Append.md)|Adiciona uma nova tabela ao banco de dados.|  
|[CDaoTableDef::CanUpdate](../Topic/CDaoTableDef::CanUpdate.md)|Retorna diferente de zero se a tabela pode ser atualizada \(você pode alterar a definição dos campos ou propriedades da tabela\).|  
|[CDaoTableDef::Close](../Topic/CDaoTableDef::Close.md)|Fecha um tabledef aberto.|  
|[CDaoTableDef::Create](../Topic/CDaoTableDef::Create.md)|Cria uma tabela que pode ser adicionada ao banco de dados usando [acrescentar](../Topic/CDaoTableDef::Append.md).|  
|[CDaoTableDef::CreateField](../Topic/CDaoTableDef::CreateField.md)|Chamado para criar um campo para uma tabela.|  
|[CDaoTableDef::CreateIndex](../Topic/CDaoTableDef::CreateIndex.md)|Chamado para criar um índice para uma tabela.|  
|[CDaoTableDef::DeleteField](../Topic/CDaoTableDef::DeleteField.md)|Chamado para excluir um campo de uma tabela.|  
|[CDaoTableDef::DeleteIndex](../Topic/CDaoTableDef::DeleteIndex.md)|Chamado para excluir um índice de uma tabela.|  
|[CDaoTableDef::GetAttributes](../Topic/CDaoTableDef::GetAttributes.md)|Retorna um valor que indica uma ou mais características de um objeto de `CDaoTableDef` .|  
|[CDaoTableDef::GetConnect](../Topic/CDaoTableDef::GetConnect.md)|Retorna um valor que fornece informações sobre a origem de uma tabela.|  
|[CDaoTableDef::GetDateCreated](../Topic/CDaoTableDef::GetDateCreated.md)|Retorna a data e a hora que a tabela de base subjacente um objeto de `CDaoTableDef` foi criada.|  
|[CDaoTableDef::GetDateLastUpdated](../Topic/CDaoTableDef::GetDateLastUpdated.md)|Retorna a data e hora da alteração mais recente feita ao design da tabela de base.|  
|[CDaoTableDef::GetFieldCount](../Topic/CDaoTableDef::GetFieldCount.md)|Retorna um valor que representa o número de campos na tabela.|  
|[CDaoTableDef::GetFieldInfo](../Topic/CDaoTableDef::GetFieldInfo.md)|Retorna tipos específicos de informações sobre os campos na tabela.|  
|[CDaoTableDef::GetIndexCount](../Topic/CDaoTableDef::GetIndexCount.md)|Retorna o número de índices para a tabela.|  
|[CDaoTableDef::GetIndexInfo](../Topic/CDaoTableDef::GetIndexInfo.md)|Retorna tipos específicos de informações sobre os índices para a tabela.|  
|[CDaoTableDef::GetName](../Topic/CDaoTableDef::GetName.md)|Retorna o nome definido pelo usuário da tabela.|  
|[CDaoTableDef::GetRecordCount](../Topic/CDaoTableDef::GetRecordCount.md)|Retorna o número de registros na tabela.|  
|[CDaoTableDef::GetSourceTableName](../Topic/CDaoTableDef::GetSourceTableName.md)|Retorna um valor que especifica o nome da tabela no banco de dados de origem.|  
|[CDaoTableDef::GetValidationRule](../Topic/CDaoTableDef::GetValidationRule.md)|Retorna um valor que valida os dados em um campo que é modificado ou adicionado a uma tabela.|  
|[CDaoTableDef::GetValidationText](../Topic/CDaoTableDef::GetValidationText.md)|Retorna um valor que especifica o texto de mensagem que seu aplicativo exibe se o valor de um objeto do campo não satisfaz a regra de validação especificada.|  
|[CDaoTableDef::IsOpen](../Topic/CDaoTableDef::IsOpen.md)|Retorna diferente de zero se a tabela é aberta.|  
|[CDaoTableDef::Open](../Topic/CDaoTableDef::Open.md)|Abre um tabledef armazenado existente na coleção de TableDef de banco de dados.|  
|[CDaoTableDef::RefreshLink](../Topic/CDaoTableDef::RefreshLink.md)|Atualiza informações de conexão para uma tabela anexado.|  
|[CDaoTableDef::SetAttributes](../Topic/CDaoTableDef::SetAttributes.md)|Define um valor que indica uma ou mais características de um objeto de `CDaoTableDef` .|  
|[CDaoTableDef::SetConnect](../Topic/CDaoTableDef::SetConnect.md)|Define um valor que fornece informações sobre a origem de uma tabela.|  
|[CDaoTableDef::SetName](../Topic/CDaoTableDef::SetName.md)|Define o nome da tabela.|  
|[CDaoTableDef::SetSourceTableName](../Topic/CDaoTableDef::SetSourceTableName.md)|Define um valor que especifica o nome de uma tabela anexado no banco de dados de origem.|  
|[CDaoTableDef::SetValidationRule](../Topic/CDaoTableDef::SetValidationRule.md)|Define um valor que valida os dados em um campo que é modificado ou adicionado a uma tabela.|  
|[CDaoTableDef::SetValidationText](../Topic/CDaoTableDef::SetValidationText.md)|Define um valor que especifica o texto de mensagem que seu aplicativo exibe se o valor de um objeto do campo não satisfaz a regra de validação especificada.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoTableDef::m\_pDAOTableDef](../Topic/CDaoTableDef::m_pDAOTableDef.md)|Um ponteiro para a interface de DAO que é subjacente ao objeto de tabledef.|  
|[CDaoTableDef::m\_pDatabase](../Topic/CDaoTableDef::m_pDatabase.md)|O banco de dados de origem para a tabela.|  
  
## Comentários  
 Cada objeto de banco de dados de DAO mantém uma coleção, TableDefs chamado, que contém todos os objetos salvos de tabledef de DAO.  
  
 Você manipula a definição de tabela usando um objeto de `CDaoTableDef` .  Por exemplo, você pode:  
  
-   Examine a estrutura do campo e de índice da tabela local, anexado, ou externa em um banco de dados.  
  
-   Chamar funções de membro de `SetConnect` e de `SetSourceTableName` para tabelas anexados, e use a função de membro de `RefreshLink` para atualizar conexões para tabelas anexados.  
  
-   Chame a função de membro de `CanUpdate` para determinar se você pode editar definições de campo da tabela.  
  
-   Obter ou definir condições de validação usando `GetValidationRule` e `SetValidationRule`, e as funções de membro de `GetValidationText` e de `SetValidationText` .  
  
-   Use a função de membro de **Abrir** para criar uma tabela, um dynaset\-, ou um objeto de `CDaoRecordset` de instantâneo\- tipo.  
  
    > [!NOTE]
    >  As classes de banco de dados de DAO são distintas de classes do banco de dados MFC baseado em Open Database Connectivity \(ODBC\).  Todos os nomes de classe de banco de dados de DAO têm o prefixo “CDao”.  Você ainda pode acessar fontes de dados ODBC com as classes de DAO; as classes de DAO geralmente oferecem recursos superiores como são específicas para o mecanismo de banco de dados Microsoft Jet.  
  
### Para usar objetos de tabledef para trabalhar com uma tabela existente ou criar uma nova tabela  
  
1.  Em todos os casos, primeiro criar um objeto de `CDaoTableDef` , fornecendo um ponteiro para um objeto de [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) que pertence à tabela.  
  
2.  Faça a seguir, dependendo do que você deseja:  
  
    -   Para usar um existente salvar a tabela, chama a função de membro de [Abrir](../Topic/CDaoTableDef::Open.md) do objeto de tabledef, fornecendo o nome da tabela salvo.  
  
    -   Para criar uma nova tabela, chame a função de membro de [Criar](../Topic/CDaoTableDef::Create.md) do objeto de tabledef, fornecendo o nome da tabela.  Chame [CreateField](../Topic/CDaoTableDef::CreateField.md) e [CreateIndex](../Topic/CDaoTableDef::CreateIndex.md) para adicionar campos e índices à tabela.  
  
    -   Chame [acrescentar](../Topic/CDaoTableDef::Append.md) para salvar a tabela adicionando um à coleção de TableDefs de banco de dados.  **Criar** coloca o tabledef em um estado aberto, logo após chamando **Criar** que você não chama **Abrir**.  
  
        > [!TIP]
        >  A maneira mais fácil de criar tabelas salvos é criá\-las e os armazena no seu banco de dados usando o Microsoft Access.  Em seguida você pode abri\-los e usar em seu código MFC.  
  
 Para usar o objeto de tabledef você abriu ou criado, cria e abre um objeto de `CDaoRecordset` , especificando o nome de tabledef com um valor de **dbOpenTable** no parâmetro de `nOpenType` .  
  
 Para usar um objeto de tabledef para criar um objeto de `CDaoRecordset` , você normalmente cria ou abre um tabledef conforme descrito acima, então constrói um objeto do conjunto de registros, passando um ponteiro ao objeto de tabledef quando você chama [CDaoRecordset::Open](../Topic/CDaoRecordset::Open.md).  O tabledef que você passa deve estar em um estado aberto.  Para obter mais informações, consulte a classe [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).  
  
 Quando você terminar de usar um objeto de tabledef, chame a função de membro de [Fechar](../Topic/CDaoRecordset::Close.md) ; destrua no objeto de tabledef.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CDaoTableDef`  
  
## Requisitos  
 **Cabeçalho:** afxdao.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)   
 [Classe de CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)