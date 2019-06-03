---
title: Classe CException
ms.date: 11/04/2016
f1_keywords:
- CException
- AFX/CException
- AFX/CException::CException
- AFX/CException::Delete
- AFX/CException::ReportError
helpviewer_keywords:
- CException [MFC], CException
- CException [MFC], Delete
- CException [MFC], ReportError
ms.assetid: cfacf14d-bfe4-4666-a5c7-38b800512920
ms.openlocfilehash: 5942e636809e3758f34d209a3da80f0d903ab708
ms.sourcegitcommit: 28eae422049ac3381c6b1206664455dbb56cbfb6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/31/2019
ms.locfileid: "66450364"
---
# <a name="cexception-class"></a>Classe CException

A classe base para todas as exceções na biblioteca de classes Microsoft Foundation.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE CException : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CException::CException](#cexception)|Constrói um objeto `CException`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CException::Delete](#delete)|Exclui um `CException` objeto.|
|[CException::ReportError](#reporterror)|Relata uma mensagem de erro em uma caixa de mensagem para o usuário.|

## <a name="remarks"></a>Comentários

Porque `CException` é uma classe base abstrata que não é possível criar `CException` objetos diretamente; você deve criar objetos de classes derivadas. Se você precisar criar seus próprios `CException`-classe de estilo, use uma das classes derivadas listadas acima como um modelo. Certifique-se de que sua classe derivada também usa `IMPLEMENT_DYNAMIC`.

As classes derivadas e suas descrições estão listadas abaixo:

|||
|-|-|
|[CSimpleException](../../mfc/reference/csimpleexception-class.md)|Uma classe base para exceções críticas para os recursos do MFC|
|[CInvalidArgException](../../mfc/reference/cinvalidargexception-class.md)|Condição de exceção de argumento inválido|
|[CMemoryException](../../mfc/reference/cmemoryexception-class.md)|Exceção de falta de memória|
|[CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)|Solicitação para uma operação sem suporte|
|[CArchiveException](../../mfc/reference/carchiveexception-class.md)|Exceção específica do arquivo morto|
|[CFileException](../../mfc/reference/cfileexception-class.md)|Exceção de arquivo específico|
|[CResourceException](../../mfc/reference/cresourceexception-class.md)|Recursos do Windows não foi encontrado ou não pode ser criado|
|[COleException](../../mfc/reference/coleexception-class.md)|Exceção OLE|
|[CDBException](../../mfc/reference/cdbexception-class.md)|Exceção de banco de dados (ou seja, as condições de exceção decorrente para classes de banco de dados do MFC com base em Open Database Connectivity)|
|[COleDispatchException](../../mfc/reference/coledispatchexception-class.md)|Exceção de expedição (automação) do OLE|
|[CUserException](../../mfc/reference/cuserexception-class.md)|Exceção que indica que um recurso não pôde ser encontrado|
|[CDaoException](../../mfc/reference/cdaoexception-class.md)|Exceção de objeto de acesso de dados (ou seja, as condições de exceção decorrente para classes DAO)|
|[CInternetException](../../mfc/reference/cinternetexception-class.md)|Exceção de Internet (ou seja, as condições de exceção decorrente para classes de Internet).|

Essas exceções são se destina a ser usado com o [lançar](exception-processing.md#throw), [THROW_LAST](exception-processing.md#throw_last), [tente](exception-processing.md#try), [catch](exception-processing.md#catch), [and_catch](exception-processing.md#and_catch), e [end_catch](exception-processing.md#end_catch) macros. Para obter mais informações sobre exceções, consulte [processamento de exceção](exception-processing.md), ou consulte o artigo [tratamento de exceção (MFC)](../exception-handling-in-mfc.md).

Para capturar uma exceção específica, use a classe derivada apropriada. A captura todos os tipos de exceções, use `CException`e, em seguida, use [CObject::IsKindOf](cobject-class.md#iskindof) diferenciar entre os `CException`-as classes derivadas. Observe que `CObject::IsKindOf` funciona apenas em classes declaradas com o [IMPLEMENT_DYNAMIC](run-time-object-model-services.md#implement_dynamic) macro, para tirar proveito da verificação de tipo dinâmico. Qualquer `CException`-uma classe derivada que você criar deve usar o `IMPLEMENT_DYNAMIC` macro, muito.

Você pode relatar os detalhes sobre exceções para o usuário chamando [GetErrorMessage](cfileexception-class.md#geterrormessage) ou [ReportError](#reporterror), dois que funcionam com qualquer uma das funções de membro `CException`do classes derivadas.

Se uma exceção é capturada por uma das macros, o `CException` objeto é excluído automaticamente; não excluí-lo por conta própria. Se uma exceção é capturada usando um **catch** palavra-chave, ele não será excluído automaticamente. Consulte o artigo [tratamento de exceção (MFC)](../exception-handling-in-mfc.md) para obter mais informações sobre quando excluir um objeto da exceção.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](cobject-class.md)

`CException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="cexception"></a>  CException::CException

Essa função membro constrói um `CException` objeto.

```
explicit CException(BOOL bAutoDelete);
```

### <a name="parameters"></a>Parâmetros

*b_AutoDelete*<br/>
Especifique verdadeiro se a memória para o `CException` objeto foi alocado no heap. Isso fará com que o `CException` objeto a ser excluído quando o `Delete` função membro é chamada para excluir a exceção. Especifique FALSE se o `CException` objeto na pilha ou é um objeto global. Nesse caso, o `CException` não serão excluídos quando o `Delete` função membro é chamada.

### <a name="remarks"></a>Comentários

Você normalmente não precisa chamar esse construtor diretamente. Uma função que gera uma exceção deve criar uma instância de um `CException`-classe derivada e chama seu construtor, ou ele deve usar um do MFC lançar funções, como [AfxThrowFileException](exception-processing.md#afxthrowfileexception), gerem um tipo predefinido. Esta documentação é fornecida apenas para fins de integridade.

##  <a name="delete"></a>  CException::Delete

Essa função verifica se o `CException` objeto foi criado no heap e, nesse caso, ele chama o **excluir** operador no objeto.

```
void Delete();
```

### <a name="remarks"></a>Comentários

Ao excluir uma `CException` do objeto, use o `Delete` a função de membro para excluir a exceção. Não use o **exclua** operador diretamente, porque o `CException` objeto pode ser um objeto global ou ter sido criado na pilha.

Você pode especificar se o objeto deve ser excluído quando o objeto é construído. Para obter mais informações, consulte [CException::CException](#cexception).

Você só precisa chamar `Delete` se você estiver usando o C++ **tente**- **catch** mecanismo. Se você estiver usando as macros do MFC **tente** e **CATCH**, em seguida, essas macros chamará automaticamente essa função.

### <a name="example"></a>Exemplo

```cpp
CFile* pFile = NULL;
// Constructing a CFile object with this override may throw
// a CFile exception, and won't throw any other exceptions.
// Calling CString::Format() may throw a CMemoryException,
// so we have a catch block for such exceptions, too. Any
// other exception types this function throws will be
// routed to the calling function.
// Note that this example performs the same actions as the
// example for CATCH, but uses C++ try/catch syntax instead
// of using the MFC TRY/CATCH macros. This sample must use
// CException::Delete() to delete the exception objects
// before closing the catch block, while the CATCH example
// implicitly performs the deletion via the macros.
try
{
   pFile = new CFile(_T("C:\\WINDOWS\\SYSTEM.INI"),
      CFile::modeRead | CFile::shareDenyNone);
   ULONGLONG ullLength = pFile->GetLength();
   CString str;
   str.Format(_T("Your SYSTEM.INI file is %u bytes long."), ullLength);
   AfxMessageBox(str);
}
catch(CFileException* pEx)
{
   // Simply show an error message to the user.
   pEx->ReportError();
   pEx->Delete();
}
catch(CMemoryException* pEx)
{
   // We can't recover from this memory exception, so we'll
   // just terminate the app without any cleanup. Normally, an
   // an application should do everything it possibly can to
   // clean up properly and _not_ call AfxAbort().
   pEx->Delete();
   AfxAbort();
}
// If an exception occurrs in the CFile constructor,
// the language will free the memory allocated by new
// and will not complete the assignment to pFile.
// Thus, our clean-up code needs to test for NULL.
if (pFile != NULL)
{
   pFile->Close();
   delete pFile;
}
```

##  <a name="reporterror"></a>  CException::ReportError

Chame essa função de membro para o texto de erro de relatório em uma caixa de mensagem para o usuário.

```
virtual int ReportError(
    UINT nType = MB_OK,
    UINT nMessageID = 0);
```

### <a name="parameters"></a>Parâmetros

*nType*<br/>
Especifica o estilo da caixa de mensagem. Aplicar qualquer combinação da [estilos de caixa de mensagem](styles-used-by-mfc.md#message-box-styles) à caixa. Se você não especificar esse parâmetro, o padrão é MB_OK.

*nMessageID*<br/>
Especifica a ID de recurso (entrada de cadeia de caracteres) de uma mensagem a ser exibido se o objeto de exceção não tem uma mensagem de erro. Se for 0, a mensagem "nenhuma mensagem de erro está disponível" é exibida.

### <a name="return-value"></a>Valor de retorno

Um `AfxMessageBox` valor; caso contrário, 0 se não houver memória suficiente para exibir a caixa de mensagem. Ver [AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox) para os possíveis valores de retornados.

### <a name="example"></a>Exemplo

Aqui está um exemplo do uso de `CException::ReportError`. Para obter outro exemplo, consulte o exemplo de [CATCH](exception-processing.md#catch).

```cpp
CFile fileInput;
CFileException ex;

// try to open a file for reading.
// The file will certainly not
// exist because there are too many explicit
// directories in the name.

// if the call to Open() fails, ex will be
// initialized with exception
// information.  the call to ex.ReportError() will
// display an appropriate
// error message to the user, such as
// "\Too\Many\Bad\Dirs.DAT contains an
// invalid path."  The error message text will be
// appropriate for the
// file name and error condition.

if (!fileInput.Open(_T("\\Too\\Many\\Bad\\Dirs.DAT"), CFile::modeRead, &ex))
{
  ex.ReportError();
}
else
{
  // the file was opened, so do whatever work
  // with fileInput we were planning...

  fileInput.Close();
}
```

## <a name="see-also"></a>Consulte também

[Classe CObject](cobject-class.md)<br/>
[Gráfico da hierarquia](../hierarchy-chart.md)<br/>
[Processamento de exceção](exception-processing.md)<br/>
[Como faço Criar minhas próprias Classes de exceção personalizada](https://go.microsoft.com/fwlink/p/?linkid=128045)
