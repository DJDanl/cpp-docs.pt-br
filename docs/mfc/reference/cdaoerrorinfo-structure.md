---
title: Estrutura CDaoErrorInfo
ms.date: 09/17/2019
f1_keywords:
- CDaoErrorInfo
helpviewer_keywords:
- CDaoErrorInfo structure [MFC]
- DAO (Data Access Objects), Errors collection
ms.assetid: cd37ef71-b0b3-401d-bc2b-540c9147f532
ms.openlocfilehash: a7b273bd2aa6b428bf795c1842455b8bfe187cc8
ms.sourcegitcommit: 2f96e2fda591d7b1b28842b2ea24e6297bcc3622
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2019
ms.locfileid: "71096142"
---
# <a name="cdaoerrorinfo-structure"></a>Estrutura CDaoErrorInfo

A `CDaoErrorInfo` estrutura contém informações sobre um objeto de erro definido para DAO (objetos de acesso a dados).
O DAO 3,6 é a versão final e é considerado obsoleto.


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
Um código de erro do DAO numérico. Consulte o tópico "erros de acesso a dados interceptáveis" na ajuda do DAO.

*m_strSource*<br/>
O nome do objeto ou aplicativo que originalmente gerou o erro. A propriedade Source especifica uma expressão de cadeia de caracteres que representa o objeto que gerou originalmente o erro; a expressão é geralmente o nome da classe do objeto. Para obter detalhes, consulte o tópico "propriedade de origem" na ajuda do DAO.

*m_strDescription*<br/>
Uma cadeia de caracteres descritiva associada a um erro. Para obter detalhes, consulte o tópico "propriedade de descrição" na ajuda do DAO.

*m_strHelpFile*<br/>
Um caminho totalmente qualificado para um arquivo de ajuda do Microsoft Windows. Para obter detalhes, consulte o tópico "HelpContext, propriedades do HelpFile" na ajuda do DAO.

*m_lHelpContext*<br/>
Uma ID de contexto para um tópico em um arquivo de ajuda do Microsoft Windows. Para obter detalhes, consulte o tópico "HelpContext, propriedades do HelpFile" na ajuda do DAO.

## <a name="remarks"></a>Comentários

O MFC não encapsula objetos de erro DAO em uma classe. Em vez disso, a classe [CDaoException](../../mfc/reference/cdaoexception-class.md) fornece uma interface para acessar a coleção de erros contida `DBEngine` no objeto DAO, o objeto que também contém todos os espaços de trabalho. Quando uma operação do MFC DAO gera `CDaoException` um objeto que você captura, o MFC `CDaoErrorInfo` preenche uma estrutura e a armazena no membro [m_pErrorInfo](../../mfc/reference/cdaoexception-class.md#m_perrorinfo) do objeto de exceção. (Se você optar por chamar o DAO diretamente, deverá chamar a função de membro [GetErrorInfo](../../mfc/reference/cdaoexception-class.md#geterrorinfo) do objeto de exceção para `m_pErrorInfo`preencher.)

Para obter mais informações sobre como lidar com erros do DAO [, consulte o artigo exceções: Exceções](../../mfc/exceptions-database-exceptions.md)de banco de dados. Para obter informações relacionadas, consulte o tópico "objeto de erro" na ajuda do DAO.

As informações recuperadas pela função de membro [CDaoException:: GetErrorInfo](../../mfc/reference/cdaoexception-class.md#geterrorinfo) são armazenadas `CDaoErrorInfo` em uma estrutura. Examine o membro de dados [m_pErrorInfo](../../mfc/reference/cdaoexception-class.md#m_perrorinfo) de `CDaoException` um objeto que você captura em um manipulador de exceção ou `GetErrorInfo` chame de `CDaoException` um objeto que você criar explicitamente para verificar os erros que podem ter ocorrido durante uma chamada direta para as interfaces DAO. `CDaoErrorInfo`também define uma `Dump` função de membro em compilações de depuração. Você pode usar `Dump` para despejar o conteúdo de `CDaoErrorInfo` um objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[Classe CDaoException](../../mfc/reference/cdaoexception-class.md)
