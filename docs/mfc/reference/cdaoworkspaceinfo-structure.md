---
title: Estrutura CDaoWorkspaceInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDaoWorkspaceInfo
dev_langs:
- C++
helpviewer_keywords:
- CDaoWorkspaceInfo structure [MFC]
- DAO (Data Access Objects), Workspaces collection
ms.assetid: a1f4b25e-f9c6-4196-b075-d1df99c54124
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f46bfec2d74b0d1fd292b3c9852ba8ea568329a2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46441753"
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
