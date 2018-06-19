---
title: Estrutura CDaoErrorInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDaoErrorInfo
dev_langs:
- C++
helpviewer_keywords:
- CDaoErrorInfo structure [MFC]
- DAO (Data Access Objects), Errors collection
ms.assetid: cd37ef71-b0b3-401d-bc2b-540c9147f532
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4c11ebaa7d315d09cea40b4ddc94d5afff498bf7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33366623"
---
# <a name="cdaoerrorinfo-structure"></a>Estrutura CDaoErrorInfo
O `CDaoErrorInfo` estrutura contém informações sobre um objeto de erro definida para os objetos de acesso de dados (DAO).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CDaoErrorInfo  
{  
    long m_lErrorCode;  
    CString m_strSource;  
    CString m_strDescription;  
    CString m_strHelpFile;  
    long m_lHelpContext;  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *m_lErrorCode*  
 Um código de erro numérico DAO. Consulte o tópico "Dados acesso erros interceptáveis" na Ajuda do DAO.  
  
 *m_strSource*  
 O nome do objeto ou aplicativo que originalmente gerou o erro. A propriedade Source Especifica uma expressão de cadeia de caracteres que representa o objeto que originalmente gerou o erro; a expressão é normalmente o nome da classe do objeto. Para obter detalhes, consulte o tópico "Propriedade Source" na Ajuda do DAO.  
  
 *m_strDescription*  
 Uma cadeia de caracteres descritiva associada a um erro. Para obter detalhes, consulte o tópico "Propriedade Description" na Ajuda do DAO.  
  
 *m_strHelpFile*  
 Um caminho totalmente qualificado para um arquivo de Ajuda do Microsoft Windows. Para obter detalhes, consulte o tópico "HelpContext, propriedades do arquivo de Ajuda" na Ajuda do DAO.  
  
 *m_lHelpContext*  
 Uma ID de contexto para um tópico em um arquivo de Ajuda do Microsoft Windows. Para obter detalhes, consulte o tópico "HelpContext, propriedades do arquivo de Ajuda" na Ajuda do DAO.  
  
## <a name="remarks"></a>Comentários  
 MFC não encapsula os objetos de erro DAO em uma classe. Em vez disso, o [CDaoException](../../mfc/reference/cdaoexception-class.md) classe fornece uma interface para acessar a coleção de erros contida no DAO **DBEngine** objeto, o objeto que contém todos os espaços de trabalho. Quando uma operação DAO MFC gera um `CDaoException` do objeto que você capture, MFC preenche uma `CDaoErrorInfo` estrutura e armazena o objeto de exceção [m_pErrorInfo](../../mfc/reference/cdaoexception-class.md#m_perrorinfo) membro. (Se você optar por chamar DAO diretamente, você deve chamar o objeto de exceção [GetErrorInfo](../../mfc/reference/cdaoexception-class.md#geterrorinfo) função de membro para preencher `m_pErrorInfo`.)  
  
 Para obter mais informações sobre o tratamento de erros DAO, consulte o artigo [exceções: exceções de banco de dados](../../mfc/exceptions-database-exceptions.md). Para obter informações relacionadas, consulte o tópico "Objeto de erro" na Ajuda do DAO.  
  
 As informações recuperadas pelo [CDaoException::GetErrorInfo](../../mfc/reference/cdaoexception-class.md#geterrorinfo) função de membro é armazenada em um `CDaoErrorInfo` estrutura. Examine o [m_pErrorInfo](../../mfc/reference/cdaoexception-class.md#m_perrorinfo) membro de dados de um `CDaoException` objeto catch em um manipulador de exceção ou chamada `GetErrorInfo` de um `CDaoException` objeto que você criar explicitamente para verificar erros que possam ter ocorreu durante uma chamada direta às interfaces DAO. `CDaoErrorInfo` também define uma `Dump` cria a função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoErrorInfo` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe CDaoException](../../mfc/reference/cdaoexception-class.md)
