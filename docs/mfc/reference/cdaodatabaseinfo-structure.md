---
title: Estrutura CDaoDatabaseInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDaoDatabaseInfo
dev_langs:
- C++
helpviewer_keywords:
- CDaoDatabaseInfo structure [MFC]
- DAO (Data Access Objects), Databases collection
ms.assetid: 68e9e0da-8382-4fc6-8115-1b1519392ddb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0815d248b6726d830fc50af9886c729c34ba2f29
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37336464"
---
# <a name="cdaodatabaseinfo-structure"></a>Estrutura CDaoDatabaseInfo
O `CDaoDatabaseInfo` estrutura contém informações sobre um objeto de banco de dados definida para objetos de acesso de dados (DAO).  
  
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
 *m_strName*  
 Exclusivamente nomeia o objeto de banco de dados. Para recuperar diretamente essa propriedade, chame [CDaoDatabase::GetName](../../mfc/reference/cdaodatabase-class.md#getname). Para obter detalhes, consulte o tópico "Propriedade de nome" na Ajuda do DAO.  
  
 *m_bUpdatable*  
 Indica se as alterações podem ser feitas no banco de dados. Para recuperar diretamente essa propriedade, chame [CDaoDatabase::CanUpdate](../../mfc/reference/cdaodatabase-class.md#canupdate). Para obter detalhes, consulte o tópico "Propriedade atualizável" na Ajuda do DAO.  
  
 *m_bTransactions*  
 Indica se uma fonte de dados oferece suporte a transações — a gravação de uma série de alterações que poderão posteriormente ser revertidas (cancelado) ou confirmada (salvo). Se um banco de dados é baseado no mecanismo de banco de dados Microsoft Jet, a propriedade de transações é diferente de zero, e você pode usar transações. Outros mecanismos de banco de dados podem não suportar transações. Para recuperar diretamente essa propriedade, chame [CDaoDatabase::CanTransact](../../mfc/reference/cdaodatabase-class.md#cantransact). Para obter detalhes, consulte o tópico "Propriedade Transactions" na Ajuda do DAO.  
  
 *m_strVersion*  
 Indica a versão do mecanismo de banco de dados Microsoft Jet. Para recuperar o valor dessa propriedade diretamente, chame o objeto de banco de dados [GetVersion](../../mfc/reference/cdaodatabase-class.md#getversion) função de membro. Para obter detalhes, consulte o tópico "Propriedade Version" na Ajuda do DAO.  
  
 *m_lCollatingOrder*  
 Especifica a sequência da ordem de classificação em texto para comparação de cadeia de caracteres ou classificação. Os possíveis valores incluem:  
  
- `dbSortGeneral` Use a ordem de classificação geral (em inglês, francês, alemão, português, italiano e espanhol moderno).  
  
- `dbSortArabic` Use a ordem de classificação do árabe.  
  
- `dbSortCyrillic` Use a ordem de classificação de russo.  
  
- `dbSortCzech` Use a ordem de classificação Czech.  
  
- `dbSortDutch` Use a ordem de classificação holandês.  
  
- `dbSortGreek` Use a ordem de classificação grego.  
  
- `dbSortHebrew` Use a ordem de classificação em hebraico.  
  
- `dbSortHungarian` Use a ordem de classificação húngaro.  
  
- `dbSortIcelandic` Use a ordem de classificação Islandês.  
  
- `dbSortNorwdan` Use a ordem de classificação norueguês ou dinamarquês.  
  
- `dbSortPDXIntl` Use a ordem de classificação Internacional paradoxo.  
  
- `dbSortPDXNor` Use o Paradox norueguês ou ordem de classificação dinamarquês.  
  
- `dbSortPDXSwe` Use a ordem de classificação finlandês ou Paradox sueco.  
  
- `dbSortPolish` Use a ordem de classificação polonês.  
  
- `dbSortSpanish` Use a ordem de classificação do espanhol.  
  
- `dbSortSwedFin` Use a ordem de classificação finlandês ou sueco.  
  
- `dbSortTurkish` Use a ordem de classificação Turkish.  
  
- `dbSortUndefined` A ordem de classificação é desconhecido ou indefinido.  
  
 Para obter mais informações, consulte o tópico "Personalizando o Windows registro configurações para acesso a dados" na Ajuda do DAO.  
  
 *m_nQueryTimeout*  
 O número de segundos que o mecanismo de banco de dados Microsoft Jet aguarda antes de um erro de tempo limite ocorre quando uma consulta é executada em um banco de dados ODBC. O valor de tempo limite padrão é 60 segundos. Quando QueryTimeout é definido como 0, nenhum tempo limite ocorre; Isso pode fazer com que o programa pare de responder. Para recuperar o valor dessa propriedade diretamente, chame o objeto de banco de dados [GetQueryTimeout](../../mfc/reference/cdaodatabase-class.md#getquerytimeout) função de membro. Para obter detalhes, consulte o tópico "Propriedade QueryTimeout" na Ajuda do DAO.  
  
 *m_strConnect*  
 Fornece informações sobre a origem de um banco de dados aberto. Para obter informações sobre o connect cadeias de caracteres e para obter informações sobre como recuperar o valor dessa propriedade diretamente, consulte o [CDaoDatabase::GetConnect](../../mfc/reference/cdaodatabase-class.md#getconnect) função de membro. Para obter mais informações, consulte o tópico "Propriedade conectar" na Ajuda do DAO.  
  
## <a name="remarks"></a>Comentários  
 O banco de dados é um objeto DAO subjacente de um objeto MFC da classe [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md). As referências ao primário, secundário e todos acima indicam como as informações são retornadas pela [CDaoWorkspace::GetDatabaseInfo](../../mfc/reference/cdaoworkspace-class.md#getdatabaseinfo) função de membro.  
  
 As informações recuperadas pelo [CDaoWorkspace::GetDatabaseInfo](../../mfc/reference/cdaoworkspace-class.md#getdatabaseinfo) função de membro é armazenada em um `CDaoDatabaseInfo` estrutura. Chame `GetDatabaseInfo` para o `CDaoWorkspace` objeto cuja coleção de bancos de dados, o objeto de banco de dados é armazenado. `CDaoDatabaseInfo` também define um `Dump` compilações de função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoDatabaseInfo` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)   
 [Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)
