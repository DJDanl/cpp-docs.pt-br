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
ms.openlocfilehash: a24f324576c872e7fe509b742aa58d6c230ec24a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212482"
---
# <a name="cexception-class"></a>Classe CException

A classe base para todas as exceções no biblioteca MFC.

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
|[CException::D excluir](#delete)|Exclui um `CException` objeto.|
|[CException:: ReportError](#reporterror)|Relata uma mensagem de erro em uma caixa de mensagem para o usuário.|

## <a name="remarks"></a>Comentários

Como `CException` é uma classe base abstrata, você não pode criar `CException` objetos diretamente; você deve criar objetos de classes derivadas. Se você precisar criar sua classe de `CException` estilo próprio, use uma das classes derivadas listadas acima como um modelo. Verifique se a classe derivada também usa `IMPLEMENT_DYNAMIC` .

As classes derivadas e suas descrições são listadas abaixo:

|||
|-|-|
|[CSimpleException](../../mfc/reference/csimpleexception-class.md)|Uma classe base para exceções do MFC de recursos críticos|
|[CInvalidArgException](../../mfc/reference/cinvalidargexception-class.md)|Condição de exceção de argumento inválida|
|[CMemoryException](../../mfc/reference/cmemoryexception-class.md)|Exceção de memória insuficiente|
|[CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)|Solicitação de uma operação sem suporte|
|[CArchiveException](../../mfc/reference/carchiveexception-class.md)|Exceção específica do arquivo|
|[CFileException](../../mfc/reference/cfileexception-class.md)|Exceção específica do arquivo|
|[CResourceException](../../mfc/reference/cresourceexception-class.md)|Recurso do Windows não encontrado ou não creatable|
|[COleException](../../mfc/reference/coleexception-class.md)|Exceção OLE|
|[CDBException](../../mfc/reference/cdbexception-class.md)|Exceção de banco de dados (ou seja, condições de exceção decorrentes de classes de banco de dados MFC baseadas em conectividade de banco de dados aberta)|
|[COleDispatchException](../../mfc/reference/coledispatchexception-class.md)|Exceção de despacho OLE (automação)|
|[CUserException](../../mfc/reference/cuserexception-class.md)|Exceção que indica que um recurso não pôde ser encontrado|
|[CDaoException](../../mfc/reference/cdaoexception-class.md)|Exceção de objeto de acesso a dados (ou seja, condições de exceção decorrentes de classes DAO)|
|[CInternetException](../../mfc/reference/cinternetexception-class.md)|Exceção da Internet (ou seja, condições de exceção decorrentes de classes da Internet).|

Essas exceções devem ser usadas com as macros [throw](exception-processing.md#throw), [THROW_LAST](exception-processing.md#throw_last), [try](exception-processing.md#try), [Catch](exception-processing.md#catch), [AND_CATCH](exception-processing.md#and_catch)e [END_CATCH](exception-processing.md#end_catch) . Para obter mais informações sobre exceções, consulte [processamento](exception-processing.md)de exceções ou consulte o artigo [tratamento de exceções (MFC)](../exception-handling-in-mfc.md).

Para capturar uma exceção específica, use a classe derivada apropriada. Para capturar todos os tipos de exceções, use `CException` e, em seguida, use [CObject:: IsKindOf](cobject-class.md#iskindof) para diferenciar as `CException` classes derivadas. Observe que `CObject::IsKindOf` funciona apenas para classes declaradas com a macro [IMPLEMENT_DYNAMIC](run-time-object-model-services.md#implement_dynamic) , a fim de aproveitar a verificação dinâmica de tipo. Qualquer `CException` classe derivada que você criar também deve usar a `IMPLEMENT_DYNAMIC` macro.

Você pode relatar detalhes sobre as exceções para o usuário chamando [GetErrorMessage](cfileexception-class.md#geterrormessage) ou [ReportError](#reporterror), duas funções de membro que funcionam com qualquer uma das `CException` classes derivadas de.

Se uma exceção for detectada por uma das macros, o `CException` objeto será excluído automaticamente; não a exclua. Se uma exceção for capturada usando uma **`catch`** palavra-chave, ela não será excluída automaticamente. Consulte o artigo [tratamento de exceções (MFC)](../exception-handling-in-mfc.md) para obter mais informações sobre quando excluir um objeto exeption.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](cobject-class.md)

`CException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="cexceptioncexception"></a><a name="cexception"></a>CException::CException

Essa função de membro constrói um `CException` objeto.

```
explicit CException(BOOL bAutoDelete);
```

### <a name="parameters"></a>parâmetros

*b_AutoDelete*<br/>
Especifique TRUE se a memória do `CException` objeto tiver sido alocada no heap. Isso fará com que o `CException` objeto seja excluído quando a `Delete` função de membro for chamada para excluir a exceção. Especifique FALSE se o `CException` objeto estiver na pilha ou for um objeto global. Nesse caso, o `CException` objeto não será excluído quando a função de `Delete` membro for chamada.

### <a name="remarks"></a>Comentários

Normalmente, você nunca precisaria chamar esse construtor diretamente. Uma função que gera uma exceção deve criar uma instância de uma `CException` classe derivada e chamar seu construtor, ou deve usar uma das funções de geração do MFC, como [AfxThrowFileException](exception-processing.md#afxthrowfileexception), para gerar um tipo predefinido. Esta documentação é fornecida apenas para fins de integridade.

## <a name="cexceptiondelete"></a><a name="delete"></a>CException::D excluir

Essa função verifica se o `CException` objeto foi criado no heap e, nesse caso, chama o **`delete`** operador no objeto.

```cpp
void Delete();
```

### <a name="remarks"></a>Comentários

Ao excluir um `CException` objeto, use a `Delete` função de membro para excluir a exceção. Não use o **`delete`** operador diretamente, pois o `CException` objeto pode ser um objeto global ou ter sido criado na pilha.

Você pode especificar se o objeto deve ser excluído quando o objeto for construído. Para obter mais informações, consulte [CException:: CException](#cexception).

Você só precisará chamar `Delete` se estiver usando o mecanismo C++ **`try`** -  **`catch`** . Se você estiver usando as macros do MFC e **tentar** **capturar**, essas macros chamarão automaticamente essa função.

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

## <a name="cexceptionreporterror"></a><a name="reporterror"></a>CException:: ReportError

Chame essa função de membro para relatar o texto de erro em uma caixa de mensagem ao usuário.

```
virtual int ReportError(
    UINT nType = MB_OK,
    UINT nMessageID = 0);
```

### <a name="parameters"></a>parâmetros

*nType*<br/>
Especifica o estilo da caixa de mensagem. Aplique qualquer combinação dos [estilos da caixa de mensagem](styles-used-by-mfc.md#message-box-styles) à caixa. Se você não especificar esse parâmetro, o padrão será MB_OK.

*nMessageID*<br/>
Especifica a ID do recurso (entrada da tabela de cadeia de caracteres) de uma mensagem a ser exibida se o objeto de exceção não tiver uma mensagem de erro. Se for 0, a mensagem "nenhuma mensagem de erro está disponível" será exibida.

### <a name="return-value"></a>Valor retornado

Um `AfxMessageBox` valor; caso contrário, 0 se não houver memória suficiente para exibir a caixa de mensagem. Consulte [AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox) para obter os possíveis valores de retorno.

### <a name="example"></a>Exemplo

Aqui está um exemplo do uso de `CException::ReportError` . Para obter outro exemplo, consulte o exemplo de [Catch](exception-processing.md#catch).

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

## <a name="see-also"></a>Confira também

[Classe CObject](cobject-class.md)<br/>
[Gráfico de hierarquia](../hierarchy-chart.md)<br/>
[Processamento de exceção](exception-processing.md)<br/>
[Como faço para: criar minhas próprias classes de exceção personalizadas](https://go.microsoft.com/fwlink/p/?linkid=128045)
