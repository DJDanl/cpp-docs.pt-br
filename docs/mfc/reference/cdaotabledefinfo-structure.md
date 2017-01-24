---
title: "Estrutura CDaoTableDefInfo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CDaoTableDefInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura CDaoTableDefInfo"
  - "DAO (Objetos de Acesso a Dados), Coleção TableDefs"
ms.assetid: c01ccebb-5615-434e-883c-4f60eac943dd
caps.latest.revision: 13
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura CDaoTableDefInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `CDaoTableDefInfo` contém informações sobre um objeto de tabledef definido para objetos \(DAO\) de acesso a dados.  
  
## Sintaxe  
  
```  
  
      struct CDaoTableDefInfo  
{  
   CString m_strName;               // Primary  
   BOOL m_bUpdatable;               // Primary  
   long m_lAttributes;              // Primary  
   COleDateTime m_dateCreated;      // Secondary  
   COleDateTime m_dateLastUpdated;  // Secondary  
   CString m_strSrcTableName;       // Secondary  
   CString m_strConnect;            // Secondary  
   CString m_strValidationRule;     // All  
   CString m_strValidationText;     // All  
   long m_lRecordCount;             // All  
};  
```  
  
#### Parâmetros  
 `m_strName`  
 Nomear exclusivamente o objeto de tabledef.  Para recuperar diretamente o valor dessa propriedade, chame a função de membro de [GetName](../Topic/CDaoTableDef::GetName.md) do objeto de tabledef.  Para obter mais informações, consulte o tópico “propriedade nome” na ajuda de DAO.  
  
 `m_bUpdatable`  
 Indica se as alterações podem ser feitas na tabela.  O modo rápido para determinar se uma tabela é atualizável é abrir um objeto de `CDaoTableDef` para a tabela e chamar a função de membro de [CanUpdate](../Topic/CDaoTableDef::CanUpdate.md) do objeto.  `CanUpdate` sempre retorna diferente de zero \(**Verdadeiro**\) para um objeto e um 0 recém\-criados de tabledef \(**Falso**\) para um objeto de tabledef anexado.  Um novo objeto de tabledef pode ser anexados a um base de dados para o qual o usuário atual tem permissão de gravação.  Se a tabela contiver somente campos nonupdatable, retorna 0 de `CanUpdate` .  Quando um ou mais campos são atualizáveis, `CanUpdate` retorna diferente de zero.  Você pode editar apenas os campos atualizáveis.  Para obter mais informações, consulte o tópico “propriedade atualizável” na ajuda de DAO.  
  
 `m_lAttributes`  
 Especifica as características da tabela representada pelo objeto de tabledef.  Para recuperar os atributos atuais de um tabledef, chame a função de membro de [GetAttributes](../Topic/CDaoTableDef::GetAttributes.md) .  O valor retornado pode ser uma combinação dessas constantes de execução longa \(se usar bit a bit OR \(  **&#124;**operador\)\):  
  
-   **dbAttachExclusive** para as bases de dados que usam o mecanismo de base de dados do Microsoft Jet, indica que a tabela é uma tabela anexado aberta para uso exclusivo.  
  
-   **dbAttachSavePWD** para as bases de dados que usam o mecanismo de base de dados do Microsoft Jet, indica que o ID de usuário e uma senha para a tabela anexada são salvas com as informações de conexão.  
  
-   **dbSystemObject** indica que a tabela é uma tabela do sistema fornecida pelo mecanismo de base de dados do Microsoft Jet. \(Somente leitura.\)  
  
-   **dbHiddenObject** indica que a tabela é uma tabela oculta fornecida pelo mecanismo de base de dados do Microsoft Jet \(para uso temporário\). \(Somente leitura.\)  
  
-   **dbAttachedTable** indica que a tabela é anexado uma tabela de um base de dados não ODBC, como um base de dados de paradox.  
  
-   **dbAttachedODBC** indica que a tabela é anexado uma tabela de uma base de dados de ODBC, como Microsoft SQL Server.  
  
 `m_dateCreated`  
 A data e a hora em que a tabela foi criada.  Para recuperar diretamente a data em que a tabela foi criada, chamará a função de membro de [GetDateCreated](../Topic/CDaoTableDef::GetDateCreated.md) do objeto de `CDaoTableDef` associado à tabela.  Consulte os comentários abaixo para obter mais informações.  Para obter informações relacionadas, consulte o tópico “DateCreated, propriedades de LastUpdated” na ajuda de DAO.  
  
 `m_dateLastUpdated`  
 A data e a hora da alteração mais recente feita ao design da tabela.  Para recuperar diretamente a data em que a tabela foi atualizado, chame a função de membro de [GetDateLastUpdated](../Topic/CDaoTableDef::GetDateLastUpdated.md) do objeto de `CDaoTableDef` associado à tabela.  Consulte os comentários abaixo para obter mais informações.  Para obter informações relacionadas, consulte o tópico “DateCreated, propriedades de LastUpdated” na ajuda de DAO.  
  
 *m\_strSrcTableName*  
 Especifica o nome de uma tabela anexado se houver.  Para recuperar diretamente o nome da tabela de origem, chame a função de membro de [GetSourceTableName](../Topic/CDaoTableDef::GetSourceTableName.md) do objeto de `CDaoTableDef` associado à tabela.  
  
 `m_strConnect`  
 Fornece informações sobre a origem de um base de dados aberto.  Você pode verificar essa propriedade chamando a função de membro de [GetConnect](../Topic/CDaoTableDef::GetConnect.md) do objeto de `CDaoTableDef` .  Para obter mais informações sobre a conexão cadeias de caracteres, consulte `GetConnect`.  
  
 `m_strValidationRule`  
 Um valor que valida os dados em tabledef coloca a medida que eles são alterados ou adicionados a uma tabela.  A validação tem suporte apenas para as bases de dados que usam o mecanismo de base de dados do Microsoft Jet.  Para recuperar diretamente a regra de validação, chame a função de membro de [GetValidationRule](../Topic/CDaoTableDef::GetValidationRule.md) do objeto de `CDaoTableDef` associado à tabela.  Para obter informações relacionadas, consulte o tópico “propriedade ValidationRule” na ajuda de DAO.  
  
 `m_strValidationText`  
 Um valor que especifica o texto da mensagem que seu aplicativo deve exibir se a regra de validação especificada pela propriedade de ValidationRule não for satisfeita.  Para obter informações relacionadas, consulte o tópico “propriedade ValidationText” na ajuda de DAO.  
  
 *m\_lRecordCount*  
 O número de registros acessado em um objeto de tabledef.  Essa configuração de propriedade é somente leitura.  Para recuperar diretamente a contagem de registros, chame a função de membro de [GetRecordCount](../Topic/CDaoTableDef::GetRecordCount.md) do objeto de `CDaoTableDef` .  A documentação de `GetRecordCount` descreve a contagem de registros mais.  Observe que recupera esta contagem pode ser uma operação demorada se a tabela contiver muitos registros.  
  
## Comentários  
 O tabledef é um objeto da classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md).  As referências à primário, secundário, e todas as anterior indicam como as informações são retornadas pela função de membro de [GetTableDefInfo](../Topic/CDaoDatabase::GetTableDefInfo.md) na classe `CDaoDatabase`.  
  
 As informações recuperadas pela função de membro de [CDaoDatabase::GetTableDefInfo](../Topic/CDaoDatabase::GetTableDefInfo.md) são armazenadas em uma estrutura de `CDaoTableDefInfo` .  Chame a função de membro de `GetTableDefInfo` do objeto de `CDaoDatabase` em cuja coleção de TableDefs o objeto de tabledef é armazenado.  `CDaoTableDefInfo` também define uma função de membro de `Dump` em construções de depuração.  Você pode usar para `Dump` despejar os conteúdos de um objeto de `CDaoTableDefInfo` .  
  
 As configurações de data e hora são derivadas do computador em que a tabela base foi criada ou o atualizado pela última vez.  Em um ambiente multiusuário, os usuários devem obter essas configurações diretamente do usuário do arquivo para evitar discrepâncias nas configurações de propriedade de DateCreated e de LastUpdated.  
  
## Requisitos  
 **Header:** afxdao.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe de CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)   
 [Classe de CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)   
 [CDaoTableDef::CanUpdate](../Topic/CDaoTableDef::CanUpdate.md)   
 [CDaoTableDef::GetAttributes](../Topic/CDaoTableDef::GetAttributes.md)   
 [CDaoTableDef::GetDateCreated](../Topic/CDaoTableDef::GetDateCreated.md)   
 [CDaoTableDef::GetDateLastUpdated](../Topic/CDaoTableDef::GetDateLastUpdated.md)   
 [CDaoTableDef::GetRecordCount](../Topic/CDaoTableDef::GetRecordCount.md)   
 [CDaoTableDef::GetSourceTableName](../Topic/CDaoTableDef::GetSourceTableName.md)   
 [CDaoTableDef::GetValidationRule](../Topic/CDaoTableDef::GetValidationRule.md)   
 [CDaoTableDef::GetValidationText](../Topic/CDaoTableDef::GetValidationText.md)