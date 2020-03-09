---
title: Classe CFileException
ms.date: 11/04/2016
f1_keywords:
- CFileException
- AFX/CFileException
- AFX/CFileException::CFileException
- AFX/CFileException::ErrnoToException
- AFX/CFileException::GetErrorMessage
- AFX/CFileException::OsErrorToException
- AFX/CFileException::ThrowErrno
- AFX/CFileException::ThrowOsError
- AFX/CFileException::m_cause
- AFX/CFileException::m_lOsError
- AFX/CFileException::m_strFileName
helpviewer_keywords:
- CFileException [MFC], CFileException
- CFileException [MFC], ErrnoToException
- CFileException [MFC], GetErrorMessage
- CFileException [MFC], OsErrorToException
- CFileException [MFC], ThrowErrno
- CFileException [MFC], ThrowOsError
- CFileException [MFC], m_cause
- CFileException [MFC], m_lOsError
- CFileException [MFC], m_strFileName
ms.assetid: f6491bb9-bfbc-42fd-a952-b33f9b62323f
ms.openlocfilehash: a3514c76d4136fe2bc0b096cc382e6f7f4dd3392
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78855244"
---
# <a name="cfileexception-class"></a>Classe CFileException

Representa uma condição de exceção relacionada a arquivo.

## <a name="syntax"></a>Sintaxe

```
class CFileException : public CException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CFileException::CFileException](#cfileexception)|Constrói um objeto `CFileException`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CFileException::ErrnoToException](#errnotoexception)|Retorna o código que corresponde a um número de erro em tempo de execução.|
|[CFileException:: GetErrorMessage](#geterrormessage)|Recupera a mensagem que descreve uma exceção.|
|[CFileException::OsErrorToException](#oserrortoexception)|Retorna um código de causa correspondente a um código de erro do sistema operacional.|
|[CFileException::ThrowErrno](#throwerrno)|Gera uma exceção de arquivo com base em um número de erro de tempo de execução.|
|[CFileException::ThrowOsError](#throwoserror)|Gera uma exceção de arquivo com base em um número de erro do sistema operacional.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CFileException:: m_cause](#m_cause)|Contém código portátil correspondente à causa da exceção.|
|[CFileException:: m_lOsError](#m_loserror)|Contém o número de erro do sistema operacional relacionado.|
|[CFileException:: m_strFileName](#m_strfilename)|Contém o nome do arquivo para esta exceção.|

## <a name="remarks"></a>Comentários

A classe `CFileException` inclui membros de dados públicos que contêm o código de causa portátil e o número de erro específico do sistema operacional. A classe também fornece funções de membro estático para lançar exceções de arquivo e para retornar códigos de causa para erros de sistema operacional e erros de tempo de execução de C.

`CFileException` objetos são construídos e lançados em funções de membro `CFile` e em funções de membro de classes derivadas. Você pode acessar esses objetos dentro do escopo de uma expressão **Catch** . Para portabilidade, use apenas o código de causa para obter o motivo de uma exceção. Para obter mais informações sobre exceções, consulte o artigo [tratamento de exceções (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

`CFileException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="cfileexception"></a>CFileException::CFileException

Constrói um objeto `CFileException` que armazena o código de causa e o código do sistema operacional no objeto.

```
CFileException(
    int cause = CFileException::none,
    LONG lOsError = -1,
    LPCTSTR lpszArchiveName = NULL);
```

### <a name="parameters"></a>Parâmetros

*causa*<br/>
Uma variável de tipo enumerada que indica o motivo da exceção. Consulte [CFileException:: m_cause](#m_cause) para obter uma lista dos valores possíveis.

*lOsError*<br/>
Um motivo específico do sistema operacional para a exceção, se disponível. O parâmetro *lOsError* fornece mais informações do que a *causa* .

*lpszArchiveName*<br/>
Aponta para uma cadeia de caracteres que contém o nome do objeto `CFile` que está causando a exceção.

### <a name="remarks"></a>Comentários

Não use esse construtor diretamente, mas, em vez disso, chame a função global [AfxThrowFileException](exception-processing.md#afxthrowfileexception).

> [!NOTE]
>  A variável *lOsError* só se aplica a objetos `CFile` e `CStdioFile`. A classe `CMemFile` não trata esse código de erro.

##  <a name="errnotoexception"></a>CFileException::ErrnoToException

Converte um determinado valor de erro de biblioteca em tempo de execução em um `CFileException` valor de erro enumerado.

```
static int PASCAL ErrnoToException(int nErrno);
```

### <a name="parameters"></a>Parâmetros

*nErrno*<br/>
Um código de erro inteiro, conforme definido no tempo de execução, inclui o arquivo ERRNO. T.

### <a name="return-value"></a>Valor retornado

Valor enumerado que corresponde a um determinado valor de erro de biblioteca em tempo de execução.

### <a name="remarks"></a>Comentários

Consulte [CFileException:: m_cause](#m_cause) para obter uma lista dos possíveis valores enumerados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#26](../../atl-mfc-shared/reference/codesnippet/cpp/cfileexception-class_1.cpp)]

##  <a name="geterrormessage"></a>CFileException:: GetErrorMessage

Recupera o texto que descreve uma exceção.

```
virtual BOOL GetErrorMessage(
    LPTSTR lpszError,
    UINT nMaxError,
    PUINT pnHelpContext = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*lpszError*<br/>
[entrada, saída] Ponteiro para um buffer que recebe uma mensagem de erro.

*nMaxError*<br/>
no O número máximo de caracteres que o buffer especificado pode conter. Isso inclui o caractere nulo de terminação.

*pnHelpContext*<br/>
[entrada, saída] Ponteiro para um inteiro sem sinal que recebe a ID de contexto da ajuda. Se `NULL`, nenhuma ID será retornada.

### <a name="return-value"></a>Valor retornado

TRUE se o método foi bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o buffer especificado for muito pequeno, a mensagem de erro será truncada.

### <a name="example"></a>Exemplo

O exemplo a seguir usa `CFileException::GetErrorMessage`.

[!code-cpp[NVC_MFCExceptions#22](../../mfc/codesnippet/cpp/cfileexception-class_2.cpp)]

##  <a name="m_cause"></a>CFileException:: m_cause

Contém valores definidos por um tipo enumerado de `CFileException`.

```
int m_cause;
```

### <a name="remarks"></a>Comentários

Esse membro de dados é uma variável pública do tipo **int**. Os enumeradores e seus significados são os seguintes:

- `CFileException::none` 0: nenhum erro ocorreu.

- `CFileException::genericException` 1: ocorreu um erro não especificado.

- `CFileException::fileNotFound` 2: o arquivo não pôde ser localizado.

- `CFileException::badPath` 3: todo ou parte do caminho é inválido.

- `CFileException::tooManyOpenFiles` 4: o número permitido de arquivos abertos foi excedido.

- `CFileException::accessDenied` 5: o arquivo não pôde ser acessado.

- `CFileException::invalidFile` 6: houve uma tentativa de usar um identificador de arquivo inválido.

- `CFileException::removeCurrentDir` 7: o diretório de trabalho atual não pode ser removido.

- `CFileException::directoryFull` 8: não há mais entradas de diretório.

- `CFileException::badSeek` 9: erro ao tentar definir o ponteiro do arquivo.

- `CFileException::hardIO` 10: ocorreu um erro de hardware.

- `CFileException::sharingViolation` 11: compartilhar. O EXE não foi carregado ou uma região compartilhada foi bloqueada.

- `CFileException::lockViolation` 12: houve uma tentativa de bloquear uma região que já estava bloqueada.

- `CFileException::diskFull` 14: o disco está cheio.

- `CFileException::endOfFile` 15: o final do arquivo foi atingido.

    > [!NOTE]
    >  Esses enumeradores de causa de `CFileException` são diferentes dos enumeradores de causa de `CArchiveException`.

    > [!NOTE]
    > O `CArchiveException::generic` foi preterido. Use `genericException` em vez disso. Se **genérico** for usado em um aplicativo e compilado com/CLR, os erros de sintaxe resultantes não serão fáceis de decifrar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#30](../../atl-mfc-shared/reference/codesnippet/cpp/cfileexception-class_3.cpp)]

##  <a name="m_loserror"></a>CFileException:: m_lOsError

Contém o código de erro do sistema operacional para esta exceção.

```
LONG m_lOsError;
```

### <a name="remarks"></a>Comentários

Consulte o manual técnico do sistema operacional para obter uma lista de códigos de erro. Esse membro de dados é uma variável pública do tipo LONG.

##  <a name="m_strfilename"></a>CFileException:: m_strFileName

Contém o nome do arquivo para esta condição de exceção.

```
CString m_strFileName;
```

##  <a name="oserrortoexception"></a>CFileException::OsErrorToException

Retorna um enumerador que corresponde a um determinado valor de *lOsError* . Se o código de erro for desconhecido, a função retornará `CFileException::generic`.

```
static int PASCAL OsErrorToException(LONG lOsError);
```

### <a name="parameters"></a>Parâmetros

*lOsError*<br/>
Um código de erro específico do sistema operacional.

### <a name="return-value"></a>Valor retornado

Valor enumerado que corresponde a um determinado valor de erro do sistema operacional.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#27](../../atl-mfc-shared/reference/codesnippet/cpp/cfileexception-class_4.cpp)]

##  <a name="throwerrno"></a>CFileException::ThrowErrno

Constrói um objeto `CFileException` correspondente a um determinado valor *nErrno* e, em seguida, gera a exceção.

```
static void PASCAL ThrowErrno(int nErrno, LPCTSTR lpszFileName = NULL);
```

### <a name="parameters"></a>Parâmetros

*nErrno*<br/>
Um código de erro inteiro, conforme definido no tempo de execução, inclui o arquivo ERRNO. T.

*lpszFileName*<br/>
Um ponteiro para a cadeia de caracteres que contém o nome do arquivo que causou a exceção, se disponível.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#28](../../atl-mfc-shared/reference/codesnippet/cpp/cfileexception-class_5.cpp)]

##  <a name="throwoserror"></a>CFileException::ThrowOsError

Gera um `CFileException` correspondente a um determinado valor *lOsError* . Se o código de erro for desconhecido, a função lançará uma exceção codificada como `CFileException::generic`.

```
static void PASCAL ThrowOsError(LONG lOsError, LPCTSTR lpszFileName = NULL);
```

### <a name="parameters"></a>Parâmetros

*lOsError*<br/>
Um código de erro específico do sistema operacional.

*lpszFileName*<br/>
Um ponteiro para a cadeia de caracteres que contém o nome do arquivo que causou a exceção, se disponível.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#29](../../atl-mfc-shared/reference/codesnippet/cpp/cfileexception-class_6.cpp)]

## <a name="see-also"></a>Veja também

[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Processamento de exceção](../../mfc/reference/exception-processing.md)
