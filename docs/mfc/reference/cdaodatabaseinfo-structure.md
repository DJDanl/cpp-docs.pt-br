---
title: Estrutura CDaoDatabaseInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDaoDatabaseInfo
dev_langs:
- C++
helpviewer_keywords:
- CDaoDatabaseInfo structure [MFC]
- DAO (Data Access Objects), Databases collection
ms.assetid: 68e9e0da-8382-4fc6-8115-1b1519392ddb
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 085d0e525cb00c9fffb3698080194da92a6dbb8a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdaodatabaseinfo-structure"></a>Estrutura CDaoDatabaseInfo
O `CDaoDatabaseInfo` estrutura contém informações sobre um objeto de banco de dados definida para os objetos de acesso de dados (DAO).  
  
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
 `m_strName`  
 Exclusivamente nomeia o objeto de banco de dados. Para recuperar diretamente essa propriedade, chame [CDaoDatabase::GetName](../../mfc/reference/cdaodatabase-class.md#getname). Para obter detalhes, consulte o tópico "Propriedade de nome" na Ajuda do DAO.  
  
 `m_bUpdatable`  
 Indica se podem ser feitas alterações no banco de dados. Para recuperar diretamente essa propriedade, chame [CDaoDatabase::CanUpdate](../../mfc/reference/cdaodatabase-class.md#canupdate). Para obter detalhes, consulte o tópico "Propriedade atualizável" na Ajuda do DAO.  
  
 *m_bTransactions*  
 Indica se uma fonte de dados oferece suporte a transações — a gravação de uma série de alterações pode posteriormente ser revertida (cancelado) ou confirmada (salvo). Se um banco de dados é baseado no mecanismo de banco de dados do Microsoft Jet, a propriedade de transações é diferente de zero, e você pode usar transações. Outros mecanismos de banco de dados podem não suportar transações. Para recuperar diretamente essa propriedade, chame [CDaoDatabase::CanTransact](../../mfc/reference/cdaodatabase-class.md#cantransact). Para obter detalhes, consulte o tópico "Propriedade Transactions" na Ajuda do DAO.  
  
 *m_strVersion*  
 Indica a versão do mecanismo de banco de dados Microsoft Jet. Para recuperar o valor dessa propriedade diretamente, chame o objeto de banco de dados [GetVersion](../../mfc/reference/cdaodatabase-class.md#getversion) função de membro. Para obter detalhes, consulte o tópico "Propriedade Version" na Ajuda do DAO.  
  
 `m_lCollatingOrder`  
 Especifica a sequência da ordem de classificação no texto de comparação de cadeia de caracteres ou classificação. Os possíveis valores incluem:  
  
- **dbSortGeneral** usar a ordem de classificação geral (inglês, francês, alemão, português, italiano e espanhol moderno).  
  
- **dbSortArabic** usar a ordem de classificação árabe.  
  
- **dbSortCyrillic** usar a ordem de classificação russo.  
  
- **dbSortCzech** usar a ordem de classificação tcheco.  
  
- **dbSortDutch** usar a ordem de classificação holandês.  
  
- **dbSortGreek** usar a ordem de classificação grego.  
  
- **dbSortHebrew** usam a ordem de classificação em hebraico.  
  
- **dbSortHungarian** usar a ordem de classificação húngara.  
  
- **dbSortIcelandic** usar a ordem de classificação Islandês.  
  
- **dbSortNorwdan** usar a ordem de classificação norueguês ou dinamarquês.  
  
- **dbSortPDXIntl** usar a ordem de classificação internacional Paradox.  
  
- **dbSortPDXNor** usar Paradox norueguês ou ordem de classificação dinamarquês.  
  
- **dbSortPDXSwe** usar a ordem de classificação finlandês ou sueco Paradox.  
  
- **dbSortPolish** usar a ordem de classificação polonês.  
  
- **dbSortSpanish** usam a ordem de classificação do espanhol.  
  
- **dbSortSwedFin** usar a ordem de classificação finlandês ou sueco.  
  
- **dbSortTurkish** usar a ordem de classificação turco.  
  
- **dbSortUndefined** a ordem de classificação é desconhecido ou indefinido.  
  
 Para obter mais informações, consulte o tópico "Personalizando Windows registro as configurações de acesso a dados" na Ajuda do DAO.  
  
 *m_nQueryTimeout*  
 O número de segundos que o mecanismo de banco de dados Microsoft Jet aguarda antes de um erro de tempo limite ocorre quando uma consulta é executada em um banco de dados ODBC. O valor de tempo limite padrão é 60 segundos. Quando QueryTimeout é definido como 0, não haverá tempo limite; Isso pode causar o programa pare de responder. Para recuperar o valor dessa propriedade diretamente, chame o objeto de banco de dados [GetQueryTimeout](../../mfc/reference/cdaodatabase-class.md#getquerytimeout) função de membro. Para obter detalhes, consulte o tópico "Propriedade QueryTimeout" na Ajuda do DAO.  
  
 `m_strConnect`  
 Fornece informações sobre a origem de um banco de dados aberto. Para obter informações sobre conexão cadeias de caracteres e para obter informações sobre como recuperar o valor dessa propriedade diretamente, consulte o [CDaoDatabase::GetConnect](../../mfc/reference/cdaodatabase-class.md#getconnect) função de membro. Para obter mais informações, consulte o tópico "Propriedade conectar" na Ajuda do DAO.  
  
## <a name="remarks"></a>Comentários  
 O banco de dados é um objeto DAO subjacente de um objeto MFC da classe [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md). As referências para o primário, secundário e todos os acima indicam como as informações são retornadas pelo [CDaoWorkspace::GetDatabaseInfo](../../mfc/reference/cdaoworkspace-class.md#getdatabaseinfo) função de membro.  
  
 As informações recuperadas pelo [CDaoWorkspace::GetDatabaseInfo](../../mfc/reference/cdaoworkspace-class.md#getdatabaseinfo) função de membro é armazenada em um `CDaoDatabaseInfo` estrutura. Chamar `GetDatabaseInfo` para o `CDaoWorkspace` objeto cuja coleção de bancos de dados do objeto de banco de dados está armazenado. `CDaoDatabaseInfo`também define uma `Dump` cria a função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoDatabaseInfo` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)   
 [Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)
