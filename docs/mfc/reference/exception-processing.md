---
title: Processamento de exceção
ms.date: 11/04/2016
helpviewer_keywords:
- macros [MFC], exception handling
- DAO (Data Access Objects), exceptions [MFC]
- OLE exceptions [MFC], MFC functions
- exceptions [MFC], processing
- exception macros [MFC]
- termination functions, MFC
- MFC, exceptions
- exceptions [MFC], MFC throwing functions
ms.assetid: 26d4457c-8350-48f5-916e-78f919787c30
ms.openlocfilehash: d33da7a9bc81f9733df840a87fbbbeca1e02cc04
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502555"
---
# <a name="exception-processing"></a>Processamento de exceção

Quando um programa é executado, várias condições anormais e erros chamados "exceções" podem ocorrer. Isso pode incluir a falta de memória, erros de alocação de recursos e falha na localização de arquivos.

O biblioteca MFC usa um esquema de tratamento de exceções que é modelado com mais detalhes após o proposto pelo Comitê de C++padrões ANSI para o. Um manipulador de exceção deve ser configurado antes de chamar uma função que pode encontrar uma situação anormal. Se a função encontrar uma condição anormal, ela lançará uma exceção e o controle será passado para o manipulador de exceção.

Várias macros incluídas no biblioteca MFC configurarão manipuladores de exceção. Várias outras funções globais ajudam a gerar exceções especializadas e a encerrar programas, se necessário. Essas macros e funções globais se enquadram nas seguintes categorias:

- Macros de exceção, que estruturam seu manipulador de exceção.

- Funções de lançamento de exceção), que geram exceções de tipos específicos.

- Funções de encerramento, que causam o encerramento do programa.

Para obter exemplos e mais detalhes, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).

### <a name="exception-macros"></a>Macros de exceção

|||
|-|-|
|[TENTE](#try)|Designa um bloco de código para processamento de exceção.|
|[PEGAR](#catch)|Designa um bloco de código para capturar uma exceção do bloco **try** anterior.|
|[CATCH_ALL](#catch_all)|Designa um bloco de código para capturar todas as exceções do bloco **try** anterior.|
|[AND_CATCH](#and_catch)|Designa um bloco de código para capturar tipos de exceção adicionais do bloco **try** anterior.|
|[AND_CATCH_ALL](#and_catch_all)|Designa um bloco de código para capturar todos os outros tipos de exceção adicionais lançados em um bloco **try** anterior.|
|[END_CATCH](#end_catch)|Encerra o último bloco de código **Catch** ou **AND_CATCH** .|
|[END_CATCH_ALL](#end_catch_all)|Encerra o último bloco de código **CATCH_ALL** .|
|[THROW](#throw)|Gera uma exceção especificada.|
|[THROW_LAST](#throw_last)|Gera a exceção atualmente manipulada para o próximo manipulador externo.|

### <a name="exception-throwing-functions"></a>Funções de lançamento de exceção

|||
|-|-|
|[AfxThrowArchiveException](#afxthrowarchiveexception)|Gera uma exceção de arquivo morto.|
|[AfxThrowFileException](#afxthrowfileexception)|Gera uma exceção de arquivo.|
|[AfxThrowInvalidArgException](#afxthrowinvalidargexception)|Gera uma exceção de argumento inválido.|
|[AfxThrowMemoryException](#afxthrowmemoryexception)|Gera uma exceção de memória.|
|[AfxThrowNotSupportedException](#afxthrownotsupportedexception)|Gera uma exceção sem suporte.|
|[AfxThrowResourceException](#afxthrowresourceexception)|Gera uma exceção de recurso do Windows não encontrada.|
|[AfxThrowUserException](#afxthrowuserexception)|Gera uma exceção em uma ação de programa iniciada pelo usuário.|

O MFC fornece duas funções de lançamento de exceção especificamente para exceções OLE:

### <a name="ole-exception-functions"></a>Funções de exceção OLE

|||
|-|-|
|[AfxThrowOleDispatchException](#afxthrowoledispatchexception)|Gera uma exceção em uma função de automação OLE.|
|[AfxThrowOleException](#afxthrowoleexception)|Gera uma exceção OLE.|

Para dar suporte a exceções de banco de dados, as classes de `CDBException` banco `CDaoException`de dados fornecem duas classes de exceção, e e funções globais para dar suporte aos tipos de exceção:

### <a name="dao-exception-functions"></a>Funções de exceção do DAO

|||
|-|-|
|[AfxThrowDAOException](#afxthrowdaoexception)|Gera um [CDaoException](../../mfc/reference/cdaoexception-class.md) de seu próprio código.|
|[AfxThrowDBException](#afxthrowdbexception)|Gera um [CDBException](../../mfc/reference/cdbexception-class.md) de seu próprio código.|

O MFC fornece a seguinte função de encerramento:

### <a name="termination-functions"></a>Funções de encerramento

|||
|-|-|
|[AfxAbort](#afxabort)|Chamado para encerrar um aplicativo quando ocorre um erro fatal.|

##  <a name="try"></a>  TRY

Configura um bloco **try** .

```
TRY
```

### <a name="remarks"></a>Comentários

Um bloco **try** identifica um bloco de código que pode gerar exceções. Essas exceções são tratadas nos blocos **Catch** e **AND_CATCH** a seguir. Recursão é permitida: exceções podem ser passadas para um bloco **try** externo, seja ignorando-as ou usando a macro THROW_LAST. Finalize o bloco **try** com uma macro END_CATCH ou END_CATCH_ALL.

Para obter mais informações, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).

### <a name="example"></a>Exemplo

Consulte o exemplo de [Catch](#catch).

### <a name="requirements"></a>Requisitos

Cabeçalho: afx.h

##  <a name="catch"></a>PEGAR

Define um bloco de código que captura o primeiro tipo de exceção lançado no bloco **try** anterior.

```
CATCH(exception_class, exception_object_pointer_name)
```

### <a name="parameters"></a>Parâmetros

*exception_class*<br/>
Especifica o tipo de exceção para o qual testar. Para obter uma lista de classes de exceção padrão, consulte Class [CException](../../mfc/reference/cexception-class.md).

*exception_object_pointer_name*<br/>
Especifica um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome do ponteiro para acessar o objeto de exceção dentro do bloco **Catch** . Essa variável é declarada para você.

### <a name="remarks"></a>Comentários

O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Invoque a macro THROW_LAST para alternar o processamento para o próximo quadro de exceção externa. Finalize o bloco **try** com uma macro END_CATCH.

Se *exception_class* for a classe `CException`, todos os tipos de exceção serão capturados. Você pode usar a função de membro [CObject:: IsKindOf](../../mfc/reference/cobject-class.md#iskindof) para determinar qual exceção específica foi lançada. Uma maneira melhor de detectar vários tipos de exceções é usar instruções **AND_CATCH** sequenciais, cada uma com um tipo de exceção diferente.

O ponteiro de objeto de exceção é criado pela macro. Você não precisa declará-lo por conta própria.

> [!NOTE]
>  O bloco **Catch** é definido como um C++ escopo delimitado por chaves. Se você declarar variáveis nesse escopo, elas serão acessíveis somente dentro desse escopo. Isso também se aplica a *exception_object_pointer_name*.

Para obter mais informações sobre exceções e a macro CATCH, consulte o artigo [Exceptions](../../mfc/exception-handling-in-mfc.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCExceptions#26](../../mfc/codesnippet/cpp/exception-processing_1.cpp)]

##  <a name="catch_all"></a>  CATCH_ALL

Define um bloco de código que captura todos os tipos de exceção lançados no bloco **try** anterior.

```
CATCH_ALL(exception_object_pointer_name)
```

### <a name="parameters"></a>Parâmetros

*exception_object_pointer_name*<br/>
Especifica um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome do ponteiro para acessar o objeto de exceção `CATCH_ALL` dentro do bloco. Essa variável é declarada para você.

### <a name="remarks"></a>Comentários

O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Invoque a `THROW_LAST` macro para alternar o processamento para o próximo quadro de exceção externa. Se você usar **CATCH_ALL**, encerre o bloco **try** com uma macro END_CATCH_ALL.

> [!NOTE]
>  O bloco **CATCH_ALL** é definido como um C++ escopo delimitado por chaves. Se você declarar variáveis nesse escopo, elas serão acessíveis somente dentro desse escopo.

Para obter mais informações sobre exceções, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).

### <a name="example"></a>Exemplo

Consulte o exemplo de [testcfile:: Abort](../../mfc/reference/cfile-class.md#abort).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

##  <a name="and_catch"></a>  AND_CATCH

Define um bloco de código para capturar tipos de exceção adicionais lançados em um bloco **try** anterior.

```
AND_CATCH(exception_class, exception_object_pointer_name)
```

### <a name="parameters"></a>Parâmetros

*exception_class*<br/>
Especifica o tipo de exceção para o qual testar. Para obter uma lista de classes de exceção padrão, consulte Class [CException](../../mfc/reference/cexception-class.md).

*exception_object_pointer_name*<br/>
Um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome do ponteiro para acessar o objeto de exceção dentro do bloco **AND_CATCH** . Essa variável é declarada para você.

### <a name="remarks"></a>Comentários

Use a macro CATCH para capturar um tipo de exceção e, em seguida, a macro AND_CATCH para capturar cada tipo subsequente. Finalize o bloco **try** com uma macro END_CATCH.

O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Chame a macro THROW_LAST dentro do bloco **AND_CATCH** para alternar o processamento para o próximo quadro de exceção externa. **AND_CATCH** marca o fim do bloco **Catch** ou **AND_CATCH** anterior.

> [!NOTE]
>  O bloco **AND_CATCH** é definido como um C++ escopo (delimitado por chaves). Se você declarar variáveis nesse escopo, lembre-se de que elas são acessíveis somente dentro desse escopo. Isso também se aplica à variável *exception_object_pointer_name* .

### <a name="example"></a>Exemplo

Consulte o exemplo de [Catch](#catch).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h
##  <a name="and_catch_all"></a>  AND_CATCH_ALL

Define um bloco de código para capturar tipos de exceção adicionais lançados em um bloco **try** anterior.

```
AND_CATCH_ALL(exception_object_pointer_name)
```

### <a name="parameters"></a>Parâmetros

*exception_object_pointer_name*<br/>
Um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome do ponteiro para acessar o objeto de exceção dentro do bloco **AND_CATCH_ALL** . Essa variável é declarada para você.

### <a name="remarks"></a>Comentários

Use a macro **Catch** para capturar um tipo de exceção e, em seguida, a macro AND_CATCH_ALL para capturar todos os outros tipos subsequentes. Se você usar AND_CATCH_ALL, encerre o bloco **try** com uma macro END_CATCH_ALL.

O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Chame a macro THROW_LAST dentro do bloco **AND_CATCH_ALL** para alternar o processamento para o próximo quadro de exceção externa. **AND_CATCH_ALL** marca o fim do bloco **Catch** ou **AND_CATCH_ALL** anterior.

> [!NOTE]
>  O bloco **AND_CATCH_ALL** é definido como um C++ escopo (delimitado por chaves). Se você declarar variáveis nesse escopo, lembre-se de que elas são acessíveis somente dentro desse escopo.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

##  <a name="end_catch"></a>  END_CATCH

Marca o final do último bloco **Catch** ou **AND_CATCH** .

```
END_CATCH
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre a macro END_CATCH, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

##  <a name="end_catch_all"></a>  END_CATCH_ALL

Marca o final do último bloco **CATCH_ALL88** ou **AND_CATCH_ALL** .

```
END_CATCH_ALL
```

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

##  <a name="throw"></a>THROW (MFC)

Gera a exceção especificada.

```
THROW(exception_object_pointer)
```

### <a name="parameters"></a>Parâmetros

*exception_object_pointer*<br/>
Aponta para um objeto de exceção derivado `CException`de.

### <a name="remarks"></a>Comentários

**Throw** interrompe a execução do programa, passando o controle para o bloco **Catch** associado em seu programa. Se você não tiver fornecido o bloco **Catch** , o controle será passado para um biblioteca MFC módulo que imprime uma mensagem de erro e será encerrado.

Para obter mais informações, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

##  <a name="throw_last"></a>  THROW_LAST

Gera a exceção de volta para o próximo bloco de **Catch** externo.

```
THROW_LAST()
```

### <a name="remarks"></a>Comentários

Essa macro permite que você gere uma exceção criada localmente. Se você tentar lançar uma exceção que acabou de ser detectada, ela normalmente vai fora do escopo e será excluída. Com **THROW_LAST**, a exceção é passada corretamente para o próximo manipulador **Catch** .

Para obter mais informações, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).

### <a name="example"></a>Exemplo

Consulte o exemplo de [testcfile:: Abort](../../mfc/reference/cfile-class.md#abort).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

##  <a name="afxthrowarchiveexception"></a>  AfxThrowArchiveException

Gera uma exceção de arquivo morto.

```
void  AfxThrowArchiveException(int cause, LPCTSTR lpszArchiveName);
```

### <a name="parameters"></a>Parâmetros

*cause*<br/>
Especifica um inteiro que indica o motivo da exceção. Para obter uma lista dos valores possíveis, consulte [CArchiveException:: m_cause](../../mfc/reference/carchiveexception-class.md#m_cause).

*lpszArchiveName*<br/>
Aponta para uma cadeia de caracteres que contém o `CArchive` nome do objeto que causou a exceção (se disponível).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

##  <a name="afxthrowfileexception"></a>  AfxThrowFileException

Gera uma exceção de arquivo.

```
void AfxThrowFileException(
    int cause,
    LONG lOsError = -1,
    LPCTSTR lpszFileName = NULL);
```

### <a name="parameters"></a>Parâmetros

*cause*<br/>
Especifica um inteiro que indica o motivo da exceção. Para obter uma lista dos valores possíveis, consulte [CFileException:: m_cause](../../mfc/reference/cfileexception-class.md#m_cause).

*lOsError*<br/>
Contém o número de erro do sistema operacional (se disponível) que declara o motivo da exceção. Consulte o manual do sistema operacional para obter uma lista de códigos de erro.

*lpszFileName*<br/>
Aponta para uma cadeia de caracteres que contém o nome do arquivo que causou a exceção (se disponível).

### <a name="remarks"></a>Comentários

Você é responsável por determinar a causa com base no código de erro do sistema operacional.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

## <a name="afxthrowinvalidargexception"></a>  AfxThrowInvalidArgException

Gera uma exceção de argumento inválido.

### <a name="syntax"></a>Sintaxe

```
void AfxThrowInvalidArgException( );
```

### <a name="remarks"></a>Comentários

Essa função é chamada quando argumentos inválidos são usados.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="afxthrowmemoryexception"></a>  AfxThrowMemoryException

Gera uma exceção de memória.

```
void AfxThrowMemoryException();
```

### <a name="remarks"></a>Comentários

Chame essa função se as chamadas para alocadores de memória do sistema subjacentes (como **malloc** e a função [GlobalAlloc](/windows/win32/api/winbase/nf-winbase-globalalloc) do Windows) falharem. Você não precisa chamá-lo para **novo** porque **New** gerará uma exceção de memória automaticamente se a alocação de memória falhar.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

##  <a name="afxthrownotsupportedexception"></a>  AfxThrowNotSupportedException

Gera uma exceção que é o resultado de uma solicitação para um recurso sem suporte.

```
void AfxThrowNotSupportedException();
```

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

##  <a name="afxthrowresourceexception"></a>  AfxThrowResourceException

Gera uma exceção de recurso.

```
void  AfxThrowResourceException();
```

### <a name="remarks"></a>Comentários

Essa função é normalmente chamada quando um recurso do Windows não pode ser carregado.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

##  <a name="afxthrowuserexception"></a>  AfxThrowUserException

Gera uma exceção para interromper uma operação do usuário final.

```
void AfxThrowUserException();
```

### <a name="remarks"></a>Comentários

Essa função é normalmente chamada imediatamente depois `AfxMessageBox` de relatar um erro ao usuário.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

##  <a name="afxthrowoledispatchexception"></a>  AfxThrowOleDispatchException

Use essa função para gerar uma exceção em uma função de automação OLE.

```
void AFXAPI AfxThrowOleDispatchException(
    WORD wCode ,
    LPCSTR lpszDescription,
    UINT nHelpID = 0);

void AFXAPI AfxThrowOleDispatchException(
    WORD wCode,
    UINT nDescriptionID,
    UINT nHelpID = -1);
```

### <a name="parameters"></a>Parâmetros

*wCode*<br/>
Um código de erro específico para seu aplicativo.

*lpszDescription*<br/>
Descrição verbal do erro.

*nDescriptionID*<br/>
ID de recurso para a descrição do erro textual.

*nHelpID*<br/>
Um contexto de ajuda para a ajuda do seu aplicativo (. HLP).

### <a name="remarks"></a>Comentários

As informações fornecidas para essa função podem ser exibidas pelo aplicativo de condução (Microsoft Visual Basic ou outro aplicativo cliente de automação OLE).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCExceptions#25](../../mfc/codesnippet/cpp/exception-processing_2.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

##  <a name="afxthrowoleexception"></a>  AfxThrowOleException

Cria um objeto do tipo `COleException` e gera uma exceção.

```
void AFXAPI AfxThrowOleException(SCODE sc);
void AFXAPI AfxThrowOleException(HRESULT hr);
```

### <a name="parameters"></a>Parâmetros

*sc*<br/>
Um código de status OLE que indica o motivo da exceção.

*Human*<br/>
Identificador para um código de resultado que indica o motivo da exceção.

### <a name="remarks"></a>Comentários

A versão que recebe um HRESULT como um argumento converte esse código de resultado no SCODE correspondente. Para obter mais informações sobre HRESULT e SCODE, consulte [estrutura de códigos de erro com](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDAO. h

##  <a name="afxthrowdaoexception"></a>  AfxThrowDaoException

Chame essa função para lançar uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md) de seu próprio código.

```
void AFXAPI AfxThrowDaoException(
    int nAfxDaoError = NO_AFX_DAO_ERROR,
    SCODE scode = S_OK);
```

### <a name="parameters"></a>Parâmetros

*nAfxDaoError*<br/>
Um valor inteiro que representa um código de erro estendido do DAO, que pode ser um dos valores listados em [CDaoException:: m_nAfxDaoError](../../mfc/reference/cdaoexception-class.md#m_nafxdaoerror).

*scode*<br/>
Um código de erro OLE do DAO, do tipo SCODE. Para obter informações, consulte [CDaoException:: m_scode](../../mfc/reference/cdaoexception-class.md#m_scode).

### <a name="remarks"></a>Comentários

A estrutura também chama `AfxThrowDaoException`. Em sua chamada, você pode passar um dos parâmetros ou ambos. Por exemplo, se você quiser gerar um dos erros definidos em **CDaoException:: nAfxDaoError** , mas não se preocupa com o parâmetro *SCODE* , passe um código válido no parâmetro *nAfxDaoError* e aceite o valor padrão para *SCODE*.

Para obter informações sobre exceções relacionadas às classes do MFC DAO, consulte `CDaoException` classe neste livro e as exceções [do artigo: Exceções](../../mfc/exceptions-database-exceptions.md)de banco de dados.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDB. h

##  <a name="afxthrowdbexception"></a>  AfxThrowDBException

Chame essa função para lançar uma exceção do tipo `CDBException` de seu próprio código.

```
void AfxThrowDBException(
    RETCODE nRetCode,
    CDatabase* pdb,
    HSTMT hstmt);
```

### <a name="parameters"></a>Parâmetros

*nRetCode*<br/>
Um valor do tipo RETCODE, definindo o tipo de erro que causou a geração da exceção.

*pdb*<br/>
Um ponteiro para o `CDatabase` objeto que representa a conexão da fonte de dados à qual a exceção está associada.

*hstmt*<br/>
Um identificador ODBC HSTMT que especifica o identificador de instrução ao qual a exceção está associada.

### <a name="remarks"></a>Comentários

A estrutura chama `AfxThrowDBException` quando recebe um RETCODE ODBC de uma chamada para uma função de API ODBC e interpreta o RETCODE como uma condição excepcional em vez de um erro esperado. Por exemplo, uma operação de acesso a dados pode falhar devido a um erro de leitura de disco.

Para obter informações sobre os valores de RETCODE definidos pelo ODBC, consulte o capítulo 8, "recuperando status e informações de erro" na SDK do Windows. Para obter informações sobre extensões MFC para esses códigos, consulte Class [CDBException](../../mfc/reference/cdbexception-class.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

##  <a name="afxabort"></a>  AfxAbort

A função de encerramento padrão fornecida pelo MFC.

```
void  AfxAbort();
```

### <a name="remarks"></a>Comentários

`AfxAbort`é chamado internamente pelas funções de membro do MFC quando há um erro fatal, como uma exceção não percebida que não pode ser tratada. Você pode chamar `AfxAbort` no caso raro quando encontrar um erro catastrófico do qual não é possível recuperar.

### <a name="example"></a>Exemplo

Consulte o exemplo de [Catch](#catch).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFX. h

## <a name="see-also"></a>Consulte também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[Classe CException](cexception-class.md)<br/>
[Classe CInvalidArgException](cinvalidargexception-class.md)
