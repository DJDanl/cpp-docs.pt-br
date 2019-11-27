---
title: Estrutura CDaoErrorInfo
ms.date: 09/17/2019
f1_keywords:
- CDaoErrorInfo
helpviewer_keywords:
- CDaoErrorInfo structure [MFC]
- DAO (Data Access Objects), Errors collection
ms.assetid: cd37ef71-b0b3-401d-bc2b-540c9147f532
ms.openlocfilehash: 8d731c8e8bea1adc850ab3c00c7688b9f8c9b819
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74304231"
---
# <a name="cdaoerrorinfo-structure"></a>Estrutura CDaoErrorInfo

A estrutura de `CDaoErrorInfo` contém informações sobre um objeto de erro definido para DAO (objetos de acesso a dados). O DAO 3,6 é a versão final e é considerado obsoleto.

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

O MFC não encapsula objetos de erro DAO em uma classe. Em vez disso, a classe [CDaoException](../../mfc/reference/cdaoexception-class.md) fornece uma interface para acessar a coleção de erros contida no objeto `DBEngine` do DAO, o objeto que também contém todos os espaços de trabalho. Quando uma operação do MFC DAO gera um objeto `CDaoException` que você captura, o MFC preenche uma estrutura de `CDaoErrorInfo` e a armazena no membro [m_pErrorInfo](../../mfc/reference/cdaoexception-class.md#m_perrorinfo) do objeto de exceção. (Se você optar por chamar o DAO diretamente, deverá chamar a função de membro [GetErrorInfo](../../mfc/reference/cdaoexception-class.md#geterrorinfo) do objeto de exceção por conta própria para preencher `m_pErrorInfo`.)

Para obter mais informações sobre como lidar com erros do DAO, consulte o artigo [exceções: exceções de banco de dados](../../mfc/exceptions-database-exceptions.md). Para obter informações relacionadas, consulte o tópico "objeto de erro" na ajuda do DAO.

As informações recuperadas pela função de membro [CDaoException:: GetErrorInfo](../../mfc/reference/cdaoexception-class.md#geterrorinfo) são armazenadas em uma estrutura de `CDaoErrorInfo`. Examine o [m_pErrorInfo](../../mfc/reference/cdaoexception-class.md#m_perrorinfo) membro de dados de um objeto `CDaoException` que você captura um manipulador de exceção ou chame `GetErrorInfo` de um objeto `CDaoException` que você cria explicitamente para verificar erros que podem ter ocorrido durante uma chamada direta para as interfaces DAO. `CDaoErrorInfo` também define uma função de membro de `Dump` em compilações de depuração. Você pode usar `Dump` para despejar o conteúdo de um objeto `CDaoErrorInfo`.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** AFXDAO. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[Classe CDaoException](../../mfc/reference/cdaoexception-class.md)
