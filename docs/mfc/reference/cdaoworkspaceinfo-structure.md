---
title: Estrutura CDaoWorkspaceInfo | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDaoWorkspaceInfo
dev_langs:
- C++
helpviewer_keywords:
- CDaoWorkspaceInfo structure
- DAO (Data Access Objects), Workspaces collection
ms.assetid: a1f4b25e-f9c6-4196-b075-d1df99c54124
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
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 44c1ce365a1eecdb2a500998c082c6a9245dffb2
ms.lasthandoff: 02/25/2017

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
 `m_strName`  
 Nomes exclusivamente o objeto do espaço de trabalho. Para recuperar o valor dessa propriedade diretamente, chame o objeto querydef [GetName](../../mfc/reference/cdaoquerydef-class.md#getname) função de membro. Para obter mais informações, consulte o tópico "Propriedade Name" na Ajuda do DAO.  
  
 *m_strUserName*  
 Um valor que representa o proprietário de um objeto de espaço de trabalho. Para obter informações relacionadas, consulte o tópico "Propriedade UserName" na Ajuda do DAO.  
  
 *m_bIsolateODBCTrans*  
 Um valor que indica se várias transações que envolvem o mesmo banco de dados ODBC são isoladas. Para obter mais informações, consulte [CDaoWorkspace::SetIsolateODBCTrans](../../mfc/reference/cdaoworkspace-class.md#setisolateodbctrans). Para obter informações relacionadas, consulte o tópico "Propriedade IsolateODBCTrans" na Ajuda do DAO.  
  
## <a name="remarks"></a>Comentários  
 O espaço de trabalho é um objeto da classe [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md). As referências ao primário, secundário e todos acima indicam como as informações são retornadas pelo [GetWorkspaceInfo](../../mfc/reference/cdaoworkspace-class.md#getworkspaceinfo) a função de membro na classe `CDaoWorkspace`.  
  
 As informações recuperadas pelo [CDaoWorkspace::GetWorkspaceInfo](../../mfc/reference/cdaoworkspace-class.md#getworkspaceinfo) função de membro é armazenada em um `CDaoWorkspaceInfo` estrutura. `CDaoWorkspaceInfo`também define um `Dump` compilações de função de membro no modo de depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoWorkspaceInfo` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)

