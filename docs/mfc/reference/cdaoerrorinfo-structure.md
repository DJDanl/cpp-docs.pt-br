---
title: Estrutura CDaoErrorInfo
ms.date: 11/04/2016
f1_keywords:
- CDaoErrorInfo
helpviewer_keywords:
- CDaoErrorInfo structure [MFC]
- DAO (Data Access Objects), Errors collection
ms.assetid: cd37ef71-b0b3-401d-bc2b-540c9147f532
ms.openlocfilehash: dd9610fce88c18ac42de81ed712492766ee705de
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399833"
---
# <a name="cdaoerrorinfo-structure"></a>Estrutura CDaoErrorInfo

O `CDaoErrorInfo` estrutura contém informações sobre um objeto de erro definida para objetos de acesso de dados (DAO).

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

*m_lErrorCode*<br/>
Um código de erro numérico do DAO. Consulte o tópico "Dados acesso erros interceptáveis" na Ajuda do DAO.

*m_strSource*<br/>
O nome do objeto ou aplicativo que originalmente gerou o erro. A propriedade de origem Especifica uma expressão de cadeia de caracteres que representa o objeto que originalmente gerou o erro; a expressão é normalmente o nome da classe do objeto. Para obter detalhes, consulte o tópico "Propriedade do código-fonte" na Ajuda do DAO.

*m_strDescription*<br/>
Uma cadeia de caracteres descritiva associada a um erro. Para obter detalhes, consulte o tópico "Propriedade Description" na Ajuda do DAO.

*m_strHelpFile*<br/>
Um caminho totalmente qualificado para um arquivo de Ajuda do Microsoft Windows. Para obter detalhes, consulte o tópico "Propriedades HelpContext, HelpFile" na Ajuda do DAO.

*m_lHelpContext*<br/>
Uma ID de contexto para um tópico em um arquivo de Ajuda do Microsoft Windows. Para obter detalhes, consulte o tópico "Propriedades HelpContext, HelpFile" na Ajuda do DAO.

## <a name="remarks"></a>Comentários

MFC não encapsula os objetos de erro DAO em uma classe. Em vez disso, o [CDaoException](../../mfc/reference/cdaoexception-class.md) classe fornece uma interface para acessar a coleção de erros contida no DAO `DBEngine` objeto, o objeto que também contém todos os espaços de trabalho. Quando uma operação de MFC DAO gera uma `CDaoException` do objeto que você capturar, MFC preenche uma `CDaoErrorInfo` estrutura e o armazena no objeto de exceção [m_pErrorInfo](../../mfc/reference/cdaoexception-class.md#m_perrorinfo) membro. (Se você optar por chamar diretamente o DAO, você deve chamar o objeto de exceção [GetErrorInfo](../../mfc/reference/cdaoexception-class.md#geterrorinfo) função de membro por conta própria para preencher `m_pErrorInfo`.)

Para obter mais informações sobre tratamento de erros do DAO, consulte o artigo [exceções: Exceções de banco de dados](../../mfc/exceptions-database-exceptions.md). Para obter informações relacionadas, consulte o tópico "Objeto de erro" na Ajuda do DAO.

As informações recuperadas pelo [CDaoException::GetErrorInfo](../../mfc/reference/cdaoexception-class.md#geterrorinfo) função de membro é armazenada em um `CDaoErrorInfo` estrutura. Examine a [m_pErrorInfo](../../mfc/reference/cdaoexception-class.md#m_perrorinfo) membro de dados de uma `CDaoException` objeto catch em um manipulador de exceção ou chamada `GetErrorInfo` de um `CDaoException` objeto que você criar explicitamente para verificar os erros que podem ter durante uma chamada direta para as interfaces DAO. `CDaoErrorInfo` também define um `Dump` compilações de função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoErrorInfo` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[Classe CDaoException](../../mfc/reference/cdaoexception-class.md)
