---
title: "Estrutura CDaoErrorInfo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CDaoErrorInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura CDaoErrorInfo"
  - "DAO (Objetos de Acesso a Dados), Coleção de erros"
ms.assetid: cd37ef71-b0b3-401d-bc2b-540c9147f532
caps.latest.revision: 13
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura CDaoErrorInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `CDaoErrorInfo` contém informações sobre um objeto de erro definida para objetos \(DAO\) de acesso a dados.  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 *m\_lErrorCode*  
 Um código de erro numérico de DAO.  Consulte o tópico “erros de acesso a dados Trappable” na ajuda de DAO.  
  
 *m\_strSource*  
 O nome do objeto ou do aplicativo que originalmente gerou o erro.  A propriedade da origem especifica uma expressão de cadeia de caracteres que representa o objeto que originalmente gerou o erro; a expressão é normalmente o nome da classe do objeto.  Para obter detalhes, consulte o tópico “property origem” na ajuda de DAO.  
  
 *m\_strDescription*  
 Uma cadeia de caracteres descritiva associada com um erro.  Para obter detalhes, consulte o tópico “propriedade description” na ajuda de DAO.  
  
 *m\_strHelpFile*  
 Um caminho totalmente qualificado para um arquivo de ajuda do Microsoft Windows.  Para obter detalhes, consulte o tópico “HelpContext, propriedades HelpFile” na ajuda de DAO.  
  
 *m\_lHelpContext*  
 Um ID do contexto de um tópico em um arquivo de ajuda do Microsoft Windows.  Para obter detalhes, consulte o tópico “HelpContext, propriedades HelpFile” na ajuda de DAO.  
  
## Comentários  
 O MFC não encapsula objetos de erro de DAO em uma classe.  Em vez disso, a classe de [CDaoException](../../mfc/reference/cdaoexception-class.md) fornece uma interface para acessar a coleção de erros contidas no objeto de **DBEngine** , DAO o objeto que também contém todos os espaços de trabalho.  Quando uma operação de MFC DAO gerar um objeto de `CDaoException` que você a captura, MFC preencha uma estrutura de `CDaoErrorInfo` e a armazena no membro de [m\_pErrorInfo](../Topic/CDaoException::m_pErrorInfo.md) do objeto de exceção. \(Se você escolher para chamar diretamente DAO, você deve chamar a função de membro de [GetErrorInfo](../Topic/CDaoException::GetErrorInfo.md) do objeto de exceção você mesmo para preencher `m_pErrorInfo`.\)  
  
 Para obter mais informações sobre como tratar erros de DAO, consulte o artigo [Exceções: Exceções da base de dados](../../mfc/exceptions-database-exceptions.md).  Para obter informações relacionadas, consulte o tópico “objeto erro” na ajuda de DAO.  
  
 As informações recuperadas pela função de membro de [CDaoException::GetErrorInfo](../Topic/CDaoException::GetErrorInfo.md) são armazenadas em uma estrutura de `CDaoErrorInfo` .  Examine o membro de dados de [m\_pErrorInfo](../Topic/CDaoException::m_pErrorInfo.md) de um objeto de `CDaoException` que você capture em um manipulador de exceção, ou chame `GetErrorInfo` de um objeto de `CDaoException` que você criou explicitamente para verificar os erros que podem ter ocorrido durante uma chamada direta para DAO interfaces.  `CDaoErrorInfo` também define uma função de membro de `Dump` em construções de depuração.  Você pode usar para `Dump` despejar os conteúdos de um objeto de `CDaoErrorInfo` .  
  
## Requisitos  
 **Header:** afxdao.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe de CDaoException](../../mfc/reference/cdaoexception-class.md)