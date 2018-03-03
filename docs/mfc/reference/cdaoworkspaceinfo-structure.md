---
title: Estrutura CDaoWorkspaceInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDaoWorkspaceInfo
dev_langs:
- C++
helpviewer_keywords:
- CDaoWorkspaceInfo structure [MFC]
- DAO (Data Access Objects), Workspaces collection
ms.assetid: a1f4b25e-f9c6-4196-b075-d1df99c54124
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7e154e2672a9410af979c2e5aa0f6fb0aba7a50f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdaoworkspaceinfo-structure"></a>Estrutura CDaoWorkspaceInfo
O `CDaoWorkspaceInfo` estrutura contém informações sobre um espaço de trabalho definida para acesso de banco de dados de objetos (DAO) de acesso de dados.  
  
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
 `m_strName`  
 Exclusivamente nomeia o objeto de espaço de trabalho. Para recuperar o valor dessa propriedade diretamente, chame do objeto [GetName](../../mfc/reference/cdaoquerydef-class.md#getname) função de membro. Para obter mais informações, consulte o tópico "Propriedade de nome" na Ajuda do DAO.  
  
 *m_strUserName*  
 Um valor que representa o proprietário de um objeto de espaço de trabalho. Para obter informações relacionadas, consulte o tópico "Propriedade de nome de usuário" na Ajuda do DAO.  
  
 *m_bIsolateODBCTrans*  
 Um valor que indica se várias transações que envolvem o mesmo banco de dados ODBC são isoladas. Para obter mais informações, consulte [CDaoWorkspace::SetIsolateODBCTrans](../../mfc/reference/cdaoworkspace-class.md#setisolateodbctrans). Para obter informações relacionadas, consulte o tópico "Propriedade IsolateODBCTrans" na Ajuda do DAO.  
  
## <a name="remarks"></a>Comentários  
 O espaço de trabalho é um objeto da classe [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md). As referências para o primário, secundário e todos os acima indicam como as informações são retornadas pelo [GetWorkspaceInfo](../../mfc/reference/cdaoworkspace-class.md#getworkspaceinfo) a função de membro na classe `CDaoWorkspace`.  
  
 As informações recuperadas pelo [CDaoWorkspace::GetWorkspaceInfo](../../mfc/reference/cdaoworkspace-class.md#getworkspaceinfo) função de membro é armazenada em um `CDaoWorkspaceInfo` estrutura. `CDaoWorkspaceInfo`também define uma `Dump` cria a função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoWorkspaceInfo` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)
