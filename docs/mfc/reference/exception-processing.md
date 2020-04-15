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
ms.openlocfilehash: d819c170f47ea259e776bce6db0a6971e3f54bec
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365709"
---
# <a name="exception-processing"></a>Processamento de exceção

Quando um programa é executado, uma série de condições anormais e erros chamados de "exceções" podem ocorrer. Isso pode incluir ficar sem memória, erros de alocação de recursos e falha em encontrar arquivos.

A Biblioteca de Classes da Microsoft Foundation usa um esquema de tratamento de exceções que é modelado de perto após o proposto pelo comitê de padrões da ANSI para C++. Um manipulador de exceção deve ser configurado antes de chamar uma função que possa encontrar uma situação anormal. Se a função encontrar uma condição anormal, ela lança uma exceção e o controle é passado para o manipulador de exceção.

Várias macros incluídas na Biblioteca de Classes da Microsoft Foundation configurarão manipuladores de exceção. Uma série de outras funções globais ajudam a lançar exceções especializadas e encerrar programas, se necessário. Essas macros e funções globais se enquadram nas seguintes categorias:

- Macros de exceção, que estruturam seu manipulador de exceção.

- Funções de lançamento de exceções), que geram exceções de tipos específicos.

- Funções de rescisão, que causam o término do programa.

Para exemplos e mais detalhes, consulte o artigo [Exceções](../../mfc/exception-handling-in-mfc.md).

### <a name="exception-macros"></a>Macros de exceção

|||
|-|-|
|[TRY](#try)|Designa um bloco de código para processamento de exceção.|
|[Pegar](#catch)|Designa um bloco de código para capturar uma exceção do bloco **TRY** anterior.|
|[CATCH_ALL](#catch_all)|Designa um bloco de código para capturar todas as exceções do bloco **TRY** anterior.|
|[AND_CATCH](#and_catch)|Designa um bloco de código para capturar tipos adicionais de exceção do bloco **TRY** anterior.|
|[AND_CATCH_ALL](#and_catch_all)|Designa um bloco de código para capturar todos os outros tipos adicionais de exceção lançados em um bloco **TRY** anterior.|
|[END_CATCH](#end_catch)|Termina o último **bloco de** código CATCH ou **AND_CATCH.**|
|[END_CATCH_ALL](#end_catch_all)|Termina o último bloco de código **CATCH_ALL.**|
|[Jogar](#throw)|Lança uma exceção especificada.|
|[THROW_LAST](#throw_last)|Lança a exceção atualmente manuseada para o próximo manipulador externo.|

### <a name="exception-throwing-functions"></a>Funções de arremesso de exceções

|||
|-|-|
|[AfxThrowArchiveException](#afxthrowarchiveexception)|Abre uma exceção de arquivo.|
|[AfxThrowFileException](#afxthrowfileexception)|Abre uma exceção de arquivo.|
|[AfxThrowInvalidArgException](#afxthrowinvalidargexception)|Lança uma exceção de argumento inválida.|
|[AfxThrowMemoryException](#afxthrowmemoryexception)|Lança uma exceção de memória.|
|[AfxThrowNotSupportedException](#afxthrownotsupportedexception)|Lança uma exceção não suportada.|
|[AfxThrowResourceException](#afxthrowresourceexception)|Lança uma exceção não encontrada pelo recurso do Windows.|
|[AfxThrowUserException](#afxthrowuserexception)|Lança uma exceção em uma ação de programa iniciada pelo usuário.|

O MFC fornece duas funções de lançamento de exceção especificamente para exceções oLE:

### <a name="ole-exception-functions"></a>Funções de exceção OLE

|||
|-|-|
|[AfxThrowOleDispatchException](#afxthrowoledispatchexception)|Lança uma exceção dentro de uma função de automação OLE.|
|[AfxThrowOleException](#afxthrowoleexception)|Lança uma exceção OLE.|

Para oferecer suporte às exceções do banco `CDBException` `CDaoException`de dados, as classes de banco de dados fornecem duas classes de exceção e, e funções globais para suportar os tipos de exceção:

### <a name="dao-exception-functions"></a>Funções de exceção da dao

|||
|-|-|
|[AfxThrowDAOException](#afxthrowdaoexception)|Lança um [CDaoException](../../mfc/reference/cdaoexception-class.md) do seu próprio código.|
|[AfxThrowDBException](#afxthrowdbexception)|Lança um [CDBException](../../mfc/reference/cdbexception-class.md) do seu próprio código.|

O MFC fornece a seguinte função de rescisão:

### <a name="termination-functions"></a>Funções de rescisão

|||
|-|-|
|[AfxAbort](#afxabort)|Chamado para encerrar um aplicativo quando ocorre um erro fatal.|

## <a name="try"></a><a name="try"></a>Tentar

Configura um bloco **TRY.**

```
TRY
```

### <a name="remarks"></a>Comentários

Um bloco **TRY** identifica um bloco de código que pode lançar exceções. Essas exceções são tratadas nos seguintes blocos **CATCH** e **AND_CATCH.** A recursão é permitida: exceções podem ser passadas para um bloco **TRY** externo, ignorando-as ou usando a macro THROW_LAST. Termine o bloco **TRY** com uma END_CATCH ou END_CATCH_ALL macro.

Para obter mais informações, consulte o artigo [Exceções](../../mfc/exception-handling-in-mfc.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [CATCH](#catch).

### <a name="requirements"></a>Requisitos

Cabeçalho: afx.h

## <a name="catch"></a><a name="catch"></a>Pegar

Define um bloco de código que captura o primeiro tipo de exceção lançado no bloco **TRY** anterior.

```
CATCH(exception_class, exception_object_pointer_name)
```

### <a name="parameters"></a>Parâmetros

*exception_class*<br/>
Especifica o tipo de exceção a ser testada. Para obter uma lista de classes de exceção padrão, consulte [classe CException](../../mfc/reference/cexception-class.md).

*exception_object_pointer_name*<br/>
Especifica um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome do ponteiro para acessar o objeto de exceção dentro do bloco **CATCH.** Esta variável é declarada para você.

### <a name="remarks"></a>Comentários

O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Invoque a THROW_LAST macro para deslocar o processamento para o próximo quadro de exceção externo. Termine o bloco **TRY** com uma END_CATCH macro.

Se *exception_class* for `CException`a classe, todos os tipos de exceção serão pegos. Você pode usar a função [CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof) membro para determinar qual exceção específica foi lançada. Uma maneira melhor de capturar vários tipos de exceções é usar declarações **AND_CATCH** seqüenciais, cada uma com um tipo de exceção diferente.

O ponteiro do objeto de exceção é criado pela macro. Você não precisa declarar você mesmo.

> [!NOTE]
> O bloco **CATCH** é definido como um escopo C++ delineado por aparelhos. Se você declarar variáveis neste escopo, elas serão acessíveis apenas dentro desse escopo. Isso também se aplica a *exception_object_pointer_name*.

Para obter mais informações sobre exceções e a macro CATCH, consulte o artigo [Exceções](../../mfc/exception-handling-in-mfc.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCExceptions#26](../../mfc/codesnippet/cpp/exception-processing_1.cpp)]

## <a name="catch_all"></a><a name="catch_all"></a>CATCH_ALL

Define um bloco de código que captura todos os tipos de exceção lançados no bloco **TRY** anterior.

```
CATCH_ALL(exception_object_pointer_name)
```

### <a name="parameters"></a>Parâmetros

*exception_object_pointer_name*<br/>
Especifica um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome do ponteiro `CATCH_ALL` para acessar o objeto de exceção dentro do bloco. Esta variável é declarada para você.

### <a name="remarks"></a>Comentários

O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Invoque a macro para deslocar o `THROW_LAST` processamento para o próximo quadro de exceção externo. Se você usar **CATCH_ALL,** termine o bloco **TRY** com uma END_CATCH_ALL macro.

> [!NOTE]
> O bloco **CATCH_ALL** é definido como um escopo C++ delineado por aparelhos. Se você declarar variáveis neste escopo, elas serão acessíveis apenas dentro desse escopo.

Para obter mais informações sobre exceções, consulte o artigo [Exceções](../../mfc/exception-handling-in-mfc.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [CFile::Abort](../../mfc/reference/cfile-class.md#abort).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="and_catch"></a><a name="and_catch"></a>And_catch

Define um bloco de código para capturar tipos adicionais de exceção lançados em um bloco **TRY** anterior.

```
AND_CATCH(exception_class, exception_object_pointer_name)
```

### <a name="parameters"></a>Parâmetros

*exception_class*<br/>
Especifica o tipo de exceção a ser testada. Para obter uma lista de classes de exceção padrão, consulte [classe CException](../../mfc/reference/cexception-class.md).

*exception_object_pointer_name*<br/>
Um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome do ponteiro para acessar o objeto de exceção dentro do bloco **AND_CATCH.** Esta variável é declarada para você.

### <a name="remarks"></a>Comentários

Use a macro CATCH para capturar um tipo de exceção, em seguida, a AND_CATCH macro para capturar cada tipo subseqüente. Termine o bloco **TRY** com uma END_CATCH macro.

O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Chame a THROW_LAST macro dentro do bloco **AND_CATCH** para deslocar o processamento para o próximo quadro de exceção externo. **AND_CATCH** marca o fim do catch **ou** **AND_CATCH** bloco anterior.

> [!NOTE]
> O bloco **AND_CATCH** é definido como um escopo C++ (delineado por chaves). Se você declarar variáveis neste escopo, lembre-se de que elas são acessíveis apenas dentro desse escopo. Isso também se aplica à variável *exception_object_pointer_name.*

### <a name="example"></a>Exemplo

Veja o exemplo de [CATCH](#catch).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="and_catch_all"></a><a name="and_catch_all"></a>AND_CATCH_ALL

Define um bloco de código para capturar tipos adicionais de exceção lançados em um bloco **TRY** anterior.

```
AND_CATCH_ALL(exception_object_pointer_name)
```

### <a name="parameters"></a>Parâmetros

*exception_object_pointer_name*<br/>
Um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome do ponteiro para acessar o objeto de exceção dentro do bloco **AND_CATCH_ALL.** Esta variável é declarada para você.

### <a name="remarks"></a>Comentários

Use a macro **CATCH** para capturar um tipo de exceção e, em seguida, a AND_CATCH_ALL macro para capturar todos os outros tipos subseqüentes. Se você usar AND_CATCH_ALL, termine o bloco **TRY** com uma END_CATCH_ALL macro.

O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Chame a THROW_LAST macro dentro do bloco **AND_CATCH_ALL** para deslocar o processamento para o próximo quadro de exceção externo. **AND_CATCH_ALL** marca o fim do bloco **CATCH** ou **AND_CATCH_ALL** anterior.

> [!NOTE]
> O bloco **AND_CATCH_ALL** é definido como um escopo C++ (delineado por aparelhos). Se você declarar variáveis neste escopo, lembre-se de que elas são acessíveis apenas dentro desse escopo.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="end_catch"></a><a name="end_catch"></a>End_catch

Marca o fim do último **bloco CATCH** ou **AND_CATCH.**

```
END_CATCH
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre a END_CATCH macro, consulte o artigo [Exceções](../../mfc/exception-handling-in-mfc.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="end_catch_all"></a><a name="end_catch_all"></a>End_catch_all

Marca o fim do último **bloco de CATCH_ALL88 ou** **AND_CATCH_ALL.**

```
END_CATCH_ALL
```

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="throw-mfc"></a><a name="throw"></a>LANÇAMENTO (MFC)

Lança a exceção especificada.

```
THROW(exception_object_pointer)
```

### <a name="parameters"></a>Parâmetros

*exception_object_pointer*<br/>
Aponta para um objeto `CException`de exceção derivado de .

### <a name="remarks"></a>Comentários

**O THROW** interrompe a execução do programa, passando o controle para o bloco **CATCH** associado em seu programa. Se você não tiver fornecido o bloco **CATCH,** o controle será passado para um módulo da Biblioteca de Classe da Microsoft Foundation que imprime uma mensagem de erro e sai.

Para obter mais informações, consulte o artigo [Exceções](../../mfc/exception-handling-in-mfc.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="throw_last"></a><a name="throw_last"></a>Throw_last

Joga a exceção de volta para o próximo bloco **CATCH** exterior.

```
THROW_LAST()
```

### <a name="remarks"></a>Comentários

Esta macro permite que você lance uma exceção criada localmente. Se você tentar lançar uma exceção que você acabou de pegar, ele normalmente vai sair do escopo e ser excluído. Com **THROW_LAST,** a exceção é passada corretamente para o próximo manipulador **CATCH.**

Para obter mais informações, consulte o artigo [Exceções](../../mfc/exception-handling-in-mfc.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [CFile::Abort](../../mfc/reference/cfile-class.md#abort).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="afxthrowarchiveexception"></a><a name="afxthrowarchiveexception"></a>AfxThrowArchiveException

Abre uma exceção de arquivo.

```
void  AfxThrowArchiveException(int cause, LPCTSTR lpszArchiveName);
```

### <a name="parameters"></a>Parâmetros

*Causa*<br/>
Especifica um inteiro que indica a razão da exceção. Para obter uma lista dos valores possíveis, consulte [CArchiveException::m_cause](../../mfc/reference/carchiveexception-class.md#m_cause).

*lpszArchiveName*<br/>
Aponta para uma seqüência `CArchive` contendo o nome do objeto que causou a exceção (se disponível).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="afxthrowfileexception"></a><a name="afxthrowfileexception"></a>AfxThrowFileException

Abre uma exceção de arquivo.

```
void AfxThrowFileException(
    int cause,
    LONG lOsError = -1,
    LPCTSTR lpszFileName = NULL);
```

### <a name="parameters"></a>Parâmetros

*Causa*<br/>
Especifica um inteiro que indica a razão da exceção. Para obter uma lista dos valores possíveis, consulte [CFileException::m_cause](../../mfc/reference/cfileexception-class.md#m_cause).

*lOsError*<br/>
Contém o número de erro do sistema operacional (se disponível) que declara a razão da exceção. Consulte o manual do sistema operacional para obter uma lista de códigos de erro.

*lpszFileName*<br/>
Aponta para uma seqüência contendo o nome do arquivo que causou a exceção (se disponível).

### <a name="remarks"></a>Comentários

Você é responsável por determinar a causa com base no código de erro do sistema operacional.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="afxthrowinvalidargexception"></a><a name="afxthrowinvalidargexception"></a>AfxThrowInvalidArgException

Lança uma exceção de argumento inválida.

### <a name="syntax"></a>Sintaxe

```
void AfxThrowInvalidArgException( );
```

### <a name="remarks"></a>Comentários

Esta função é chamada quando argumentos inválidos são usados.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="afxthrowmemoryexception"></a><a name="afxthrowmemoryexception"></a>Afxthrowmemoryexception

Lança uma exceção de memória.

```
void AfxThrowMemoryException();
```

### <a name="remarks"></a>Comentários

Chame essa função se as chamadas para alocadores de memória do sistema subjacentes (como **malloc** e a função [GlobalAlloc](/windows/win32/api/winbase/nf-winbase-globalalloc) Windows) falharem. Você não precisa chamá-lo de **novo** porque **o novo** lançará uma exceção de memória automaticamente se a alocação de memória falhar.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="afxthrownotsupportedexception"></a><a name="afxthrownotsupportedexception"></a>Afxthrownotsupportedexception

Lança uma exceção que é o resultado de uma solicitação de um recurso sem suporte.

```
void AfxThrowNotSupportedException();
```

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="afxthrowresourceexception"></a><a name="afxthrowresourceexception"></a>AfxThrowResourceException

Lança uma exceção de recursos.

```
void  AfxThrowResourceException();
```

### <a name="remarks"></a>Comentários

Esta função é normalmente chamada quando um recurso do Windows não pode ser carregado.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="afxthrowuserexception"></a><a name="afxthrowuserexception"></a>AfxThrowUserException

Abre uma exceção para impedir uma operação de usuário final.

```
void AfxThrowUserException();
```

### <a name="remarks"></a>Comentários

Esta função é normalmente `AfxMessageBox` chamada imediatamente depois de ter relatado um erro ao usuário.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="afxthrowoledispatchexception"></a><a name="afxthrowoledispatchexception"></a>Afxthrowoledispatchexception

Use esta função para lançar uma exceção dentro de uma função de automação OLE.

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
Um código de erro específico para sua aplicação.

*lpszDescrição*<br/>
Descrição verbal do erro.

*nDescriptionID*<br/>
ID de recurso para a descrição do erro verbal.

*nHelpID*<br/>
Um contexto de ajuda para a ajuda do seu aplicativo (. Arquivo HLP)

### <a name="remarks"></a>Comentários

As informações fornecidas a esta função podem ser exibidas pelo aplicativo de condução (Microsoft Visual Basic ou outro aplicativo cliente de automação OLE).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCExceptions#25](../../mfc/codesnippet/cpp/exception-processing_2.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="afxthrowoleexception"></a><a name="afxthrowoleexception"></a>Afxthrowoleexception

Cria um objeto `COleException` de tipo e lança uma exceção.

```
void AFXAPI AfxThrowOleException(SCODE sc);
void AFXAPI AfxThrowOleException(HRESULT hr);
```

### <a name="parameters"></a>Parâmetros

*Sc*<br/>
Um código de status OLE que indica a razão da exceção.

*Hr*<br/>
Manuseie um código de resultado que indique a razão da exceção.

### <a name="remarks"></a>Comentários

A versão que toma um HRESULT como argumento converte esse código de resultado no SCODE correspondente. Para obter mais informações sobre HRESULT e SCODE, consulte [Estrutura de Códigos de erro COM](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdao.h

## <a name="afxthrowdaoexception"></a><a name="afxthrowdaoexception"></a>AfxThrowDaoException

Chame esta função para lançar uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md) do seu próprio código.

```
void AFXAPI AfxThrowDaoException(
    int nAfxDaoError = NO_AFX_DAO_ERROR,
    SCODE scode = S_OK);
```

### <a name="parameters"></a>Parâmetros

*nAfxDaoError*<br/>
Um valor inteiro representando um código de erro estendido DAO, que pode ser um dos valores listados em [CDaoException::m_nAfxDaoError](../../mfc/reference/cdaoexception-class.md#m_nafxdaoerror).

*Scode*<br/>
Um código de erro OLE do DAO, do tipo SCODE. Para obter informações, consulte [CDaoException::m_scode](../../mfc/reference/cdaoexception-class.md#m_scode).

### <a name="remarks"></a>Comentários

O quadro `AfxThrowDaoException`também chama . Na sua chamada, você pode passar um dos parâmetros ou ambos. Por exemplo, se você quiser levantar um dos erros definidos no **CDaoException::nAfxDaoError,** mas você não se importa com o parâmetro *scode,* passe um código válido no parâmetro *nAfxDaoError* e aceite o valor padrão para *scode*.

Para obter informações sobre exceções relacionadas às `CDaoException` classes DAO do MFC, consulte a classe neste livro e o artigo [Exceções: Exceções de banco de dados](../../mfc/exceptions-database-exceptions.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdb.h

## <a name="afxthrowdbexception"></a><a name="afxthrowdbexception"></a>AfxThrowDBException

Chame esta função para lançar `CDBException` uma exceção de tipo a partir de seu próprio código.

```
void AfxThrowDBException(
    RETCODE nRetCode,
    CDatabase* pdb,
    HSTMT hstmt);
```

### <a name="parameters"></a>Parâmetros

*Nretcode*<br/>
Um valor do tipo RETCODE, definindo o tipo de erro que fez com que a exceção fosse lançada.

*Pdb*<br/>
Um ponteiro `CDatabase` para o objeto que representa a conexão de origem de dados com a qual a exceção está associada.

*hstmt*<br/>
Uma alça ODBC HSTMT que especifica a alça de declaração com a qual a exceção está associada.

### <a name="remarks"></a>Comentários

O framework `AfxThrowDBException` chama quando recebe um RETCODE ODBC de uma chamada para uma função API da ODBC e interpreta o RETCODE como uma condição excepcional, em vez de um erro esperado. Por exemplo, uma operação de acesso a dados pode falhar devido a um erro de leitura de disco.

Para obter informações sobre os valores RETCODE definidos pela ODBC, consulte o Capítulo 8, "Recuperando status e informações de erro", no SDK do Windows. Para obter informações sobre extensões MFC para esses códigos, consulte [classe CDBException](../../mfc/reference/cdbexception-class.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="afxabort"></a><a name="afxabort"></a>Afxabort

A função de rescisão padrão fornecida pela MFC.

```
void  AfxAbort();
```

### <a name="remarks"></a>Comentários

`AfxAbort`é chamado internamente por funções de membros do MFC quando há um erro fatal, como uma exceção não capturada que não pode ser tratada. Você pode `AfxAbort` chamar no caso raro quando você encontrar um erro catastrófico do qual você não pode se recuperar.

### <a name="example"></a>Exemplo

Veja o exemplo de [CATCH](#catch).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afx.h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[Classe CException](cexception-class.md)<br/>
[Classe CInvalidArgException](cinvalidargexception-class.md)
