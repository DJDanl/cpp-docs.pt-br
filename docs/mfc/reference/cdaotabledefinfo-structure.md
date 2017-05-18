---
title: Estrutura CDaoTableDefInfo | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDaoTableDefInfo
dev_langs:
- C++
helpviewer_keywords:
- CDaoTableDefInfo structure
- DAO (Data Access Objects), TableDefs collection
ms.assetid: c01ccebb-5615-434e-883c-4f60eac943dd
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 4d1ac5ca00f98f8c34332ce2eb1a180ab715e6ba
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cdaotabledefinfo-structure"></a>Estrutura CDaoTableDefInfo
O `CDaoTableDefInfo` estrutura contém informações sobre um objeto tabledef definida para objetos de acesso de dados (DAO).  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `m_strName`  
 Nomes de objeto tabledef exclusivamente. Para recuperar o valor dessa propriedade diretamente, chame o objeto tabledef [GetName](../../mfc/reference/cdaotabledef-class.md#getname) função de membro. Para obter mais informações, consulte o tópico "Propriedade Name" na Ajuda do DAO.  
  
 `m_bUpdatable`  
 Indica se podem ser feitas alterações à tabela. É a maneira rápida de determinar se uma tabela é atualizável abrir um `CDaoTableDef` de objeto para a tabela e chamar o objeto [CanUpdate](../../mfc/reference/cdaotabledef-class.md#canupdate) função de membro. `CanUpdate`sempre retorna zero (**TRUE**) para um objeto tabledef recém-criado e 0 (**FALSE**) para um objeto tabledef anexado. Um novo objeto tabledef pode ser anexado somente a um banco de dados para o qual o usuário atual tem permissão de gravação. Se a tabela contiver somente campos nonupdatable, `CanUpdate` retornará 0. Quando um ou mais campos são atualizáveis, `CanUpdate` retorna zero. Você pode editar apenas os campos atualizáveis. Para obter mais informações, consulte o tópico "Propriedade atualizável" na Ajuda do DAO.  
  
 `m_lAttributes`  
 Especifica as características da tabela representada pelo objeto tabledef. Para recuperar os atributos de um tabledef atuais, chame seu [GetAttributes](../../mfc/reference/cdaotabledef-class.md#getattributes) função de membro. O valor retornado pode ser uma combinação de constantes longos (usando OR bit a bit (**|**) operador):  
  
- **dbAttachExclusive** para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica a tabela é uma tabela anexada aberta para uso exclusivo.  
  
- **dbAttachSavePWD** para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que a ID de usuário e senha para a tabela vinculada são salvos com as informações de conexão.  
  
- **dbSystemObject** indica que a tabela é uma tabela do sistema fornecida pelo mecanismo de banco de dados Microsoft Jet. (Somente leitura.)  
  
- **dbHiddenObject** indica a tabela é uma tabela oculta fornecida pelo mecanismo de banco de dados Microsoft Jet (para uso temporário). (Somente leitura.)  
  
- **dbAttachedTable** indica que a tabela é uma tabela anexada do banco de dados não-ODBC, como um banco de dados Paradox.  
  
- **dbAttachedODBC** indica que a tabela é uma tabela de banco de dados ODBC, como o Microsoft SQL Server anexada.  
  
 `m_dateCreated`  
 A data e hora que a tabela foi criada. Para recuperar diretamente a data em que a tabela foi criada, chame o [GetDateCreated](../../mfc/reference/cdaotabledef-class.md#getdatecreated) função de membro de `CDaoTableDef` objeto associado à tabela. Veja os comentários abaixo para obter mais informações. Para obter informações relacionadas, consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.  
  
 `m_dateLastUpdated`  
 A data e hora da alteração mais recente feita no design da tabela. Para recuperar diretamente a data da última atualização de tabela, chame o [GetDateLastUpdated](../../mfc/reference/cdaotabledef-class.md#getdatelastupdated) função de membro de `CDaoTableDef` objeto associado à tabela. Veja os comentários abaixo para obter mais informações. Para obter informações relacionadas, consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.  
  
 *m_strSrcTableName*  
 Especifica o nome de uma tabela anexado, se houver. Para recuperar diretamente o nome da tabela de origem, chame o [GetSourceTableName](../../mfc/reference/cdaotabledef-class.md#getsourcetablename) função de membro de `CDaoTableDef` objeto associado à tabela.  
  
 `m_strConnect`  
 Fornece informações sobre a origem de um banco de dados aberto. Você pode verificar essa propriedade chamando o [GetConnect](../../mfc/reference/cdaotabledef-class.md#getconnect) a função de membro de sua `CDaoTableDef` objeto. Para obter mais informações sobre cadeias de caracteres de conexão, consulte `GetConnect`.  
  
 `m_strValidationRule`  
 Um valor que valida os dados em campos tabledef conforme eles são alterados ou adicionados a uma tabela. Há suporte somente para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet de validação. Para recuperar diretamente a regra de validação, chame o [GetValidationRule](../../mfc/reference/cdaotabledef-class.md#getvalidationrule) função de membro de `CDaoTableDef` objeto associado à tabela. Para obter informações relacionadas, consulte o tópico "Propriedade ValidationRule" na Ajuda do DAO.  
  
 `m_strValidationText`  
 Um valor que especifica o texto da mensagem que seu aplicativo deve exibir se a regra de validação especificada pela propriedade ValidationRule não for atendida. Para obter informações relacionadas, consulte o tópico "Propriedade texto de validação" na Ajuda do DAO.  
  
 *m_lRecordCount*  
 O número de registros acessados em um objeto tabledef. A configuração dessa propriedade é somente leitura. Para recuperar diretamente a contagem de registros, chame o [GetRecordCount](../../mfc/reference/cdaotabledef-class.md#getrecordcount) função de membro de `CDaoTableDef` objeto. A documentação para `GetRecordCount` descreve a contagem de registros. Observe que recuperar essa contagem pode ser uma operação demorada se a tabela contiver muitos registros.  
  
## <a name="remarks"></a>Comentários  
 Tabledef é um objeto da classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md). As referências ao primário, secundário e todos acima indicam como as informações são retornadas pelo [GetTableDefInfo](../../mfc/reference/cdaodatabase-class.md#gettabledefinfo) a função de membro na classe `CDaoDatabase`.  
  
 As informações recuperadas pelo [cdaodatabase:: Gettabledefinfo](../../mfc/reference/cdaodatabase-class.md#gettabledefinfo) função de membro é armazenada em um `CDaoTableDefInfo` estrutura. Chamar o `GetTableDefInfo` função de membro de `CDaoDatabase` objeto cuja coleção TableDefs objeto tabledef é armazenado. `CDaoTableDefInfo`também define um `Dump` compilações de função de membro no modo de depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoTableDefInfo` objeto.  
  
 As configurações de data e hora são derivadas do computador no qual a tabela base foi criada ou atualizado pela última vez. Em um ambiente multiusuário, os usuários devem obter essas configurações diretamente do servidor de arquivos para evitar discrepâncias no DateCreated e LastUpdated configurações de propriedade.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)   
 [Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)

