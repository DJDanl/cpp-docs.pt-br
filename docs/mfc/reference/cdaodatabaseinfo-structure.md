---
title: Estrutura CDaoDatabaseInfo
ms.date: 09/17/2019
f1_keywords:
- CDaoDatabaseInfo
helpviewer_keywords:
- CDaoDatabaseInfo structure [MFC]
- DAO (Data Access Objects), Databases collection
ms.assetid: 68e9e0da-8382-4fc6-8115-1b1519392ddb
ms.openlocfilehash: 60972aa3ecaef4d38c9a0d0ecc70477796aa37aa
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74304253"
---
# <a name="cdaodatabaseinfo-structure"></a>Estrutura CDaoDatabaseInfo

A estrutura de `CDaoDatabaseInfo` contém informações sobre um objeto de banco de dados definido para DAO (Data Access Objects). O DAO 3,6 é a versão final e é considerado obsoleto.

## <a name="syntax"></a>Sintaxe

```
struct CDaoDatabaseInfo
{
    CString m_strName;       // Primary
    BOOL m_bUpdatable;       // Primary
    BOOL m_bTransactions;    // Primary
    CString m_strVersion;    // Secondary
    long m_lCollatingOrder;  // Secondary
    short m_nQueryTimeout;   // Secondary
    CString m_strConnect;    // All
};
```

#### <a name="parameters"></a>Parâmetros

*m_strName*<br/>
Nomeia exclusivamente o objeto de banco de dados. Para recuperar diretamente essa propriedade, chame [CDaoDatabase:: GetName](../../mfc/reference/cdaodatabase-class.md#getname). Para obter detalhes, consulte o tópico "propriedade de nome" na ajuda do DAO.

*m_bUpdatable*<br/>
Indica se as alterações podem ser feitas no banco de dados. Para recuperar diretamente essa propriedade, chame [CDaoDatabase:: CanUpdate](../../mfc/reference/cdaodatabase-class.md#canupdate). Para obter detalhes, consulte o tópico "Propriedade atualizável" na ajuda do DAO.

*m_bTransactions*<br/>
Indica se uma fonte de dados dá suporte a transações — a gravação de uma série de alterações que podem ser revertidas posteriormente (canceladas) ou confirmadas (salvas). Se um banco de dados for baseado no mecanismo de banco de dados do Microsoft Jet, a propriedade transações será diferente de zero e você poderá usar transações. Outros mecanismos de banco de dados podem não dar suporte a transações. Para recuperar diretamente essa propriedade, chame [CDaoDatabase:: CanTransact](../../mfc/reference/cdaodatabase-class.md#cantransact). Para obter detalhes, consulte o tópico "Propriedade Transactions" na ajuda do DAO.

*m_strVersion*<br/>
Indica a versão do mecanismo de banco de dados do Microsoft Jet. Para recuperar o valor dessa propriedade diretamente, chame a função de membro [GetVersion](../../mfc/reference/cdaodatabase-class.md#getversion) do objeto de banco de dados. Para obter detalhes, consulte o tópico "propriedade da versão" na ajuda do DAO.

*m_lCollatingOrder*<br/>
Especifica a sequência da ordem de classificação no texto para comparação ou classificação de cadeia de caracteres. Os possíveis valores incluem:

- `dbSortGeneral` use a ordem de classificação geral (Inglês, francês, alemão, Português, italiano e espanhol moderno).

- `dbSortArabic` usar a ordem de classificação árabe.

- `dbSortCyrillic` usar a ordem de classificação russa.

- `dbSortCzech` usar a ordem de classificação em tcheco.

- `dbSortDutch` usar a ordem de classificação holandesa.

- `dbSortGreek` usar a ordem de classificação de grego.

- `dbSortHebrew` usar a ordem de classificação em Hebraico.

- `dbSortHungarian` usar a ordem de classificação húngara.

- `dbSortIcelandic` usar a ordem de classificação islandês.

- `dbSortNorwdan` usar a ordem de classificação Norueguês ou dinamarquês.

- `dbSortPDXIntl` usar a ordem de classificação internacional do Paradox.

- `dbSortPDXNor` usar a ordem de classificação do Paradox norueguês ou dinamarquês.

- `dbSortPDXSwe` usar a ordem de classificação do Paradox sueco ou finlandês.

- `dbSortPolish` usar a ordem de classificação em polonês.

- `dbSortSpanish` usar a ordem de classificação em espanhol.

- `dbSortSwedFin` usar a ordem de classificação sueca ou finlandês.

- `dbSortTurkish` usar a ordem de classificação em Turco.

- `dbSortUndefined` a ordem de classificação é indefinida ou desconhecida.

Para obter mais informações, consulte o tópico "Personalizando configurações do registro do Windows para acesso a dados" na ajuda do DAO.

*m_nQueryTimeout*<br/>
O número de segundos que o mecanismo de banco de dados do Microsoft Jet aguarda antes de ocorrer um erro de tempo limite quando uma consulta é executada em um banco de dados ODBC. O valor de tempo limite padrão é 60 segundos. Quando QueryTimeout é definido como 0, nenhum tempo limite ocorre; Isso pode fazer com que o programa pare de responder. Para recuperar o valor dessa propriedade diretamente, chame a função de membro [getQueryTimeout](../../mfc/reference/cdaodatabase-class.md#getquerytimeout) do objeto de banco de dados. Para obter detalhes, consulte o tópico "Propriedade QueryTimeout" na ajuda do DAO.

*m_strConnect*<br/>
Fornece informações sobre a origem de um banco de dados aberto. Para obter informações sobre cadeias de conexão e obter informações sobre como recuperar o valor dessa propriedade diretamente, consulte a função de membro [CDaoDatabase:: GetConnect](../../mfc/reference/cdaodatabase-class.md#getconnect) . Para obter mais informações, consulte o tópico "conectar Propriedade" na ajuda do DAO.

## <a name="remarks"></a>Comentários

O banco de dados é um objeto DAO subjacente a um objeto MFC da classe [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md). As referências a primário, secundário e todos acima indicam como as informações são retornadas pela função de membro [CDaoWorkspace:: GetDatabaseInfo](../../mfc/reference/cdaoworkspace-class.md#getdatabaseinfo) .

As informações recuperadas pela função de membro [CDaoWorkspace:: GetDatabaseInfo](../../mfc/reference/cdaoworkspace-class.md#getdatabaseinfo) são armazenadas em uma estrutura de `CDaoDatabaseInfo`. Chame `GetDatabaseInfo` para o objeto `CDaoWorkspace` na coleção de bancos de dados em que o objeto Database está armazenado. `CDaoDatabaseInfo` também define uma função de membro de `Dump` em compilações de depuração. Você pode usar `Dump` para despejar o conteúdo de um objeto `CDaoDatabaseInfo`.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** AFXDAO. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)
