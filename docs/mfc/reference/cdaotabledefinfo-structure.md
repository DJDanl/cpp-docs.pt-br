---
title: Estrutura CDaoTableDefInfo
ms.date: 11/04/2016
f1_keywords:
- CDaoTableDefInfo
helpviewer_keywords:
- CDaoTableDefInfo structure [MFC]
- DAO (Data Access Objects), TableDefs collection
ms.assetid: c01ccebb-5615-434e-883c-4f60eac943dd
ms.openlocfilehash: 5785ed19c6929e19c7d376efa012dd1c059611c7
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57273695"
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

*m_strName*<br/>
Nomes de objeto tabledef exclusivamente. Para recuperar o valor dessa propriedade diretamente, chame o objeto de tabledef [GetName](../../mfc/reference/cdaotabledef-class.md#getname) função de membro. Para obter mais informações, consulte o tópico "Propriedade de nome" na Ajuda do DAO.

*m_bUpdatable*<br/>
Indica se podem ser feitas alterações à tabela. A maneira rápida de determinar se uma tabela é atualizável é abrir um `CDaoTableDef` do objeto para a tabela e chamar o objeto [CanUpdate](../../mfc/reference/cdaotabledef-class.md#canupdate) função de membro. `CanUpdate` sempre retorna não zero (TRUE) para um objeto tabledef recém-criado e 0 (FALSE) para um objeto tabledef anexado. Um novo objeto tabledef pode ser anexado somente a um banco de dados para o qual o usuário atual tem permissão de gravação. Se a tabela contiver somente campos nonupdatable, `CanUpdate` retornará 0. Quando um ou mais campos são atualizáveis, `CanUpdate` retorna não zero. Você pode editar apenas os campos atualizáveis. Para obter mais informações, consulte o tópico "Propriedade atualizável" na Ajuda do DAO.

*m_lAttributes*<br/>
Especifica as características da tabela representada pelo objeto tabledef. Para recuperar os atributos atuais de um tabledef, chame seu [GetAttributes](../../mfc/reference/cdaotabledef-class.md#getattributes) função de membro. O valor retornado pode ser uma combinação de constantes longo (usando o OR bit a bit (**&#124;**) operador):

- `dbAttachExclusive` Para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que a tabela é uma tabela anexada aberta para uso exclusivo.

- `dbAttachSavePWD` Para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que a ID de usuário e senha para a tabela vinculada são salvos com as informações de conexão.

- `dbSystemObject` Indica que a tabela é uma tabela do sistema fornecida pelo mecanismo de banco de dados Microsoft Jet. (Somente leitura.)

- `dbHiddenObject` Indica que a tabela é uma tabela ocultada fornecida pelo mecanismo de banco de dados Microsoft Jet (para uso temporário). (Somente leitura.)

- `dbAttachedTable` Indica que a tabela é uma tabela anexada de um banco de dados não-ODBC, como um banco de dados Paradox.

- `dbAttachedODBC` Indica que a tabela é uma tabela anexada de um banco de dados ODBC, como o Microsoft SQL Server.

*m_dateCreated*<br/>
A data e hora que a tabela foi criada. Para recuperar diretamente a data em que a tabela foi criada, chame o [GetDateCreated](../../mfc/reference/cdaotabledef-class.md#getdatecreated) função de membro a `CDaoTableDef` objeto associado à tabela. Consulte os comentários abaixo para obter mais informações. Para obter informações relacionadas, consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.

*m_dateLastUpdated*<br/>
A data e hora da alteração mais recente feita no design da tabela. Para recuperar diretamente a data em que a tabela foi atualizada pela última vez, chame o [GetDateLastUpdated](../../mfc/reference/cdaotabledef-class.md#getdatelastupdated) função de membro a `CDaoTableDef` objeto associado à tabela. Consulte os comentários abaixo para obter mais informações. Para obter informações relacionadas, consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.

*m_strSrcTableName*<br/>
Especifica o nome de uma tabela anexada se houver. Para recuperar diretamente o nome da tabela de origem, chame o [GetSourceTableName](../../mfc/reference/cdaotabledef-class.md#getsourcetablename) função de membro a `CDaoTableDef` objeto associado à tabela.

*m_strConnect*<br/>
Fornece informações sobre a origem de um banco de dados aberto. Você pode verificar essa propriedade chamando o [GetConnect](../../mfc/reference/cdaotabledef-class.md#getconnect) função de membro de seu `CDaoTableDef` objeto. Para obter mais informações sobre cadeias de caracteres de conexão, consulte `GetConnect`.

*m_strValidationRule*<br/>
Um valor que valida os dados em campos tabledef conforme eles são alterados ou adicionados a uma tabela. Há suporte apenas para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet de validação. Para recuperar diretamente a regra de validação, chame o [GetValidationRule](../../mfc/reference/cdaotabledef-class.md#getvalidationrule) função de membro a `CDaoTableDef` objeto associado à tabela. Para obter informações relacionadas, consulte o tópico "Propriedade de regra de validação" na Ajuda do DAO.

*m_strValidationText*<br/>
Um valor que especifica o texto da mensagem que seu aplicativo deve exibir se a regra de validação especificada pela propriedade ValidationRule não for atendida. Para obter informações relacionadas, consulte o tópico "Propriedade do texto de validação" na Ajuda do DAO.

*m_lRecordCount*<br/>
O número de registros acessados em um objeto tabledef. A configuração dessa propriedade é somente leitura. Para recuperar diretamente a contagem de registros, chame o [GetRecordCount](../../mfc/reference/cdaotabledef-class.md#getrecordcount) função de membro a `CDaoTableDef` objeto. A documentação para `GetRecordCount` descreve a contagem de registros. Observe que ao recuperar essa contagem pode ser uma operação demorada se a tabela contiver muitos registros.

## <a name="remarks"></a>Comentários

Tabledef é um objeto da classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md). As referências ao primário, secundário e todos acima indicam como as informações são retornadas pela [GetTableDefInfo](../../mfc/reference/cdaodatabase-class.md#gettabledefinfo) função de membro na classe `CDaoDatabase`.

As informações recuperadas pelo [cdaodatabase:: Gettabledefinfo](../../mfc/reference/cdaodatabase-class.md#gettabledefinfo) função de membro é armazenada em um `CDaoTableDefInfo` estrutura. Chame o `GetTableDefInfo` função de membro do `CDaoDatabase` objeto cuja coleção TableDefs objeto tabledef é armazenado. `CDaoTableDefInfo` também define um `Dump` compilações de função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoTableDefInfo` objeto.

As configurações de data e hora são derivadas do computador no qual a tabela base foi criada ou atualizado pela última vez. Em um ambiente multiusuário, os usuários devem obter essas configurações diretamente do servidor de arquivos para evitar discrepâncias no DateCreated e LastUpdated configurações de propriedade.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)
