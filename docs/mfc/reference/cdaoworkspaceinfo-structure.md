---
title: Estrutura CDaoWorkspaceInfo
ms.date: 11/04/2016
f1_keywords:
- CDaoWorkspaceInfo
helpviewer_keywords:
- CDaoWorkspaceInfo structure [MFC]
- DAO (Data Access Objects), Workspaces collection
ms.assetid: a1f4b25e-f9c6-4196-b075-d1df99c54124
ms.openlocfilehash: e47df7323d130bee2a378a4cf7dcae8001641f6e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50562806"
---
# <a name="cdaoworkspaceinfo-structure"></a>Estrutura CDaoWorkspaceInfo

O `CDaoWorkspaceInfo` estrutura contém informações sobre um espaço de trabalho definido para acesso de banco de dados de objetos (DAO) de acesso de dados.

## <a name="syntax"></a>Sintaxe

```
struct CDaoWorkspaceInfo
{
    CString m_strName;           // Primary
    CString m_strUserName;       // Secondary
    BOOL m_bIsolateODBCTrans;    // All
};
```

#### <a name="parameters"></a>Parâmetros

*m_strName*<br/>
Exclusivamente nomeia o objeto de espaço de trabalho. Para recuperar o valor dessa propriedade diretamente, chame o objeto de querydef [GetName](../../mfc/reference/cdaoquerydef-class.md#getname) função de membro. Para obter mais informações, consulte o tópico "Propriedade de nome" na Ajuda do DAO.

*m_strUserName*<br/>
Um valor que representa o proprietário de um objeto de espaço de trabalho. Para obter informações relacionadas, consulte o tópico "Propriedade do nome de usuário" na Ajuda do DAO.

*m_bIsolateODBCTrans*<br/>
Um valor que indica se várias transações que envolvem o mesmo banco de dados ODBC são isoladas. Para obter mais informações, consulte [CDaoWorkspace::SetIsolateODBCTrans](../../mfc/reference/cdaoworkspace-class.md#setisolateodbctrans). Para obter informações relacionadas, consulte o tópico "Propriedade IsolateODBCTrans" na Ajuda do DAO.

## <a name="remarks"></a>Comentários

O espaço de trabalho é um objeto da classe [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md). As referências ao primário, secundário e todos acima indicam como as informações são retornadas pela [GetWorkspaceInfo](../../mfc/reference/cdaoworkspace-class.md#getworkspaceinfo) função de membro na classe `CDaoWorkspace`.

As informações recuperadas pelo [CDaoWorkspace::GetWorkspaceInfo](../../mfc/reference/cdaoworkspace-class.md#getworkspaceinfo) função de membro é armazenada em um `CDaoWorkspaceInfo` estrutura. `CDaoWorkspaceInfo` também define um `Dump` compilações de função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoWorkspaceInfo` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)
