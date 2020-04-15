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
ms.openlocfilehash: 2d1025ca33d5641982ba52f1ac539db85df3bfd5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373887"
---
# <a name="cfileexception-class"></a>Classe CFileException

Representa uma condição de exceção relacionada a arquivos.

## <a name="syntax"></a>Sintaxe

```
class CFileException : public CException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileException::CFileException](#cfileexception)|Constrói um objeto `CFileException`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileException::ErrnoToException](#errnotoexception)|Retorna código de causa correspondente a um número de erro de tempo de execução.|
|[CFileException::GetErrorMessage](#geterrormessage)|Recupera a mensagem descrevendo uma exceção.|
|[CFileException::OsErrorToException](#oserrortoexception)|Retorna um código de causa correspondente a um código de erro do sistema operacional.|
|[CFileException::ThrowErrno](#throwerrno)|Lança uma exceção de arquivo com base em um número de erro de tempo de execução.|
|[CFileException::ThrowosError](#throwoserror)|Lança uma exceção de arquivo com base em um número de erro do sistema operacional.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileException::m_cause](#m_cause)|Contém código portátil correspondente à causa de exceção.|
|[CFileException::m_lOsError](#m_loserror)|Contém o número de erro relacionado do sistema operacional.|
|[CFileException::m_strFileName](#m_strfilename)|Contém o nome do arquivo para esta exceção.|

## <a name="remarks"></a>Comentários

A `CFileException` classe inclui membros de dados públicos que possuem o código de causa portátil e o número de erro específico do sistema operacional. A classe também fornece funções de membro estático para jogar exceções de arquivos e para códigos de causa de retorno tanto para erros do sistema operacional quanto para erros de tempo de execução C.

`CFileException`objetos são construídos `CFile` e jogados em funções de membros e em funções de membros de classes derivadas. Você pode acessar esses objetos no escopo de uma expressão **CATCH.** Para portabilidade, use apenas o código de causa para obter o motivo de uma exceção. Para obter mais informações sobre exceções, consulte o artigo [Manipulação de Exceções (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cexception](../../mfc/reference/cexception-class.md)

`CFileException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="cfileexceptioncfileexception"></a><a name="cfileexception"></a>CFileException::CFileException

Constrói um `CFileException` objeto que armazena o código de causa e o código do sistema operacional no objeto.

```
CFileException(
    int cause = CFileException::none,
    LONG lOsError = -1,
    LPCTSTR lpszArchiveName = NULL);
```

### <a name="parameters"></a>Parâmetros

*Causa*<br/>
Uma variável de tipo enumerada que indica a razão da exceção. Consulte [CFileException::m_cause](#m_cause) para obter uma lista dos valores possíveis.

*lOsError*<br/>
Uma razão específica do sistema operacional para a exceção, se disponível. O parâmetro *lOsError* fornece mais informações do que *a causa.*

*lpszArchiveName*<br/>
Aponta para uma string contendo `CFile` o nome do objeto causando a exceção.

### <a name="remarks"></a>Comentários

Não use este construtor diretamente, mas chame a função global [AfxThrowFileException](exception-processing.md#afxthrowfileexception).

> [!NOTE]
> A variável *lOsError* aplica-se apenas a `CFile` objetos e `CStdioFile` objetos. A `CMemFile` classe não lida com este código de erro.

## <a name="cfileexceptionerrnotoexception"></a><a name="errnotoexception"></a>CFileException::ErrnoToException

Converte um determinado valor de erro `CFileException` de biblioteca em tempo de execução para um valor de erro enumerado.

```
static int PASCAL ErrnoToException(int nErrno);
```

### <a name="parameters"></a>Parâmetros

*nErrno*<br/>
Um código de erro inteiro definido no tempo de execução inclui o arquivo ERRNO. H.

### <a name="return-value"></a>Valor retornado

Valor enumerado que corresponde a um determinado valor de erro de biblioteca em tempo de execução.

### <a name="remarks"></a>Comentários

Consulte [CFileException::m_cause](#m_cause) para obter uma lista dos possíveis valores enumerados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#26](../../atl-mfc-shared/reference/codesnippet/cpp/cfileexception-class_1.cpp)]

## <a name="cfileexceptiongeterrormessage"></a><a name="geterrormessage"></a>CFileException::GetErrorMessage

Recupera texto que descreve uma exceção.

```
virtual BOOL GetErrorMessage(
    LPTSTR lpszError,
    UINT nMaxError,
    PUINT pnHelpContext = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*lpszError*<br/>
[dentro, fora] Ponteiro para um buffer que recebe uma mensagem de erro.

*nMaxError*<br/>
[em] O número máximo de caracteres que o buffer especificado pode conter. Isso inclui o caráter nulo final.

*pnHelpContext*<br/>
[dentro, fora] Pointer para um inteiro não assinado que recebe o ID de contexto de ajuda. Se, `NULL`nenhuma id é devolvida.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método foi bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Se o buffer especificado for muito pequeno, a mensagem de erro será truncada.

### <a name="example"></a>Exemplo

O exemplo a seguir usa `CFileException::GetErrorMessage`.

[!code-cpp[NVC_MFCExceptions#22](../../mfc/codesnippet/cpp/cfileexception-class_2.cpp)]

## <a name="cfileexceptionm_cause"></a><a name="m_cause"></a>CFileException::m_cause

Contém valores definidos por um tipo enumerado de `CFileException`.

```
int m_cause;
```

### <a name="remarks"></a>Comentários

Este membro de dados é uma variável pública de tipo **int**. Os enumeradores e seus significados são os seguintes:

- `CFileException::none`0: Não ocorreu nenhum erro.

- `CFileException::genericException`1: Ocorreu um erro não especificado.

- `CFileException::fileNotFound`2: O arquivo não pôde ser localizado.

- `CFileException::badPath`3: Tudo ou parte do caminho é inválido.

- `CFileException::tooManyOpenFiles`4: O número permitido de arquivos abertos foi excedido.

- `CFileException::accessDenied`5: O arquivo não pôde ser acessado.

- `CFileException::invalidFile`6: Houve uma tentativa de usar uma alça de arquivo inválida.

- `CFileException::removeCurrentDir`7: O diretório de trabalho atual não pode ser removido.

- `CFileException::directoryFull`8: Não há mais entradas de diretório.

- `CFileException::badSeek`9: Houve um erro ao tentar definir o ponteiro do arquivo.

- `CFileException::hardIO`10: Houve um erro de hardware.

- `CFileException::sharingViolation`11: SHARE. Exe não estava carregado, ou uma região compartilhada estava trancada.

- `CFileException::lockViolation`12: Houve uma tentativa de bloquear uma região que já estava trancada.

- `CFileException::diskFull`14: O disco está cheio.

- `CFileException::endOfFile`15: O fim do arquivo foi alcançado.

    > [!NOTE]
    >  Esses enumeradores de causa de `CFileException` são diferentes dos enumeradores de causa de `CArchiveException`.

    > [!NOTE]
    > O `CArchiveException::generic` foi preterido. Use `genericException` em vez disso. Se **o genérico** for usado em um aplicativo e construído com /clr, os erros de sintaxe resultantes não são fáceis de decifrar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#30](../../atl-mfc-shared/reference/codesnippet/cpp/cfileexception-class_3.cpp)]

## <a name="cfileexceptionm_loserror"></a><a name="m_loserror"></a>CFileException::m_lOsError

Contém o código de erro do sistema operacional para esta exceção.

```
LONG m_lOsError;
```

### <a name="remarks"></a>Comentários

Consulte o manual técnico do sistema operacional para obter uma lista de códigos de erro. Este membro de dados é uma variável pública do tipo LONG.

## <a name="cfileexceptionm_strfilename"></a><a name="m_strfilename"></a>CFileException::m_strFileName

Contém o nome do arquivo para esta condição de exceção.

```
CString m_strFileName;
```

## <a name="cfileexceptionoserrortoexception"></a><a name="oserrortoexception"></a>CFileException::OsErrorToException

Retorna um enumerador que corresponde a um determinado valor *de erro de lOsError.* Se o código de erro for `CFileException::generic`desconhecido, a função retorna .

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

## <a name="cfileexceptionthrowerrno"></a><a name="throwerrno"></a>CFileException::ThrowErrno

Constrói um `CFileException` objeto correspondente a um determinado valor *nErrno* e, em seguida, lança a exceção.

```
static void PASCAL ThrowErrno(int nErrno, LPCTSTR lpszFileName = NULL);
```

### <a name="parameters"></a>Parâmetros

*nErrno*<br/>
Um código de erro inteiro definido no tempo de execução inclui o arquivo ERRNO. H.

*lpszFileName*<br/>
Um ponteiro para a seqüência contendo o nome do arquivo que causou a exceção, se disponível.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#28](../../atl-mfc-shared/reference/codesnippet/cpp/cfileexception-class_5.cpp)]

## <a name="cfileexceptionthrowoserror"></a><a name="throwoserror"></a>CFileException::ThrowosError

Lança `CFileException` um correspondente a um determinado valor *de erro de iOs.* Se o código de erro for desconhecido, a `CFileException::generic`função lançará uma exceção codificada como .

```
static void PASCAL ThrowOsError(LONG lOsError, LPCTSTR lpszFileName = NULL);
```

### <a name="parameters"></a>Parâmetros

*lOsError*<br/>
Um código de erro específico do sistema operacional.

*lpszFileName*<br/>
Um ponteiro para a seqüência contendo o nome do arquivo que causou a exceção, se disponível.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#29](../../atl-mfc-shared/reference/codesnippet/cpp/cfileexception-class_6.cpp)]

## <a name="see-also"></a>Confira também

[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Processamento de exceção](../../mfc/reference/exception-processing.md)
