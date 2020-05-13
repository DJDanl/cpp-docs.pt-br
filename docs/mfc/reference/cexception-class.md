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
ms.openlocfilehash: 93901f6f92ee79bd893b2ec0d1e341e77749d951
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753184"
---
# <a name="cexception-class"></a>Classe CException

A classe base para todas as exceções na Biblioteca de Classes da Microsoft Foundation.

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
|[CException::'Erro de relatório](#reporterror)|Relata uma mensagem de erro em uma caixa de mensagem para o usuário.|

## <a name="remarks"></a>Comentários

Porque `CException` é uma classe base `CException` abstrata, você não pode criar objetos diretamente; você deve criar objetos de classes derivadas. Se você precisar criar `CException`sua própria classe de estilo, use uma das classes derivadas listadas acima como um modelo. Certifique-se de que sua `IMPLEMENT_DYNAMIC`classe derivada também usa .

As classes derivadas e suas descrições estão listadas abaixo:

|||
|-|-|
|[Csimpleexception](../../mfc/reference/csimpleexception-class.md)|Uma classe base para exceções mfc críticas de recursos|
|[Cinvalidargexception](../../mfc/reference/cinvalidargexception-class.md)|Condição de exceção de argumento inválida|
|[Cmemoryexception](../../mfc/reference/cmemoryexception-class.md)|Exceção fora da memória|
|[Cnotsupportedexception](../../mfc/reference/cnotsupportedexception-class.md)|Solicitação de uma operação sem suporte|
|[Carchiveexception](../../mfc/reference/carchiveexception-class.md)|Exceção específica do arquivo|
|[Cfileexception](../../mfc/reference/cfileexception-class.md)|Exceção específica de arquivo|
|[Cresourceexception](../../mfc/reference/cresourceexception-class.md)|Recurso do Windows não encontrado ou não creatable|
|[Coleexception](../../mfc/reference/coleexception-class.md)|Exceção oLE|
|[Cdbexception](../../mfc/reference/cdbexception-class.md)|Exceção de banco de dados (ou seja, condições de exceção decorrentes de classes de banco de dados MFC baseadas em conectividade de banco de dados aberto)|
|[Coledispatchexception](../../mfc/reference/coledispatchexception-class.md)|Exceção de despacho OLE (automação)|
|[Cuserexception](../../mfc/reference/cuserexception-class.md)|Exceção que indica que um recurso não pôde ser encontrado|
|[Cdaoexception](../../mfc/reference/cdaoexception-class.md)|Exceção de objeto de acesso a dados (ou seja, condições de exceção decorrentes de classes DAO)|
|[Cinternetexception](../../mfc/reference/cinternetexception-class.md)|Exceção da Internet (ou seja, condições de exceção decorrentes de aulas de Internet).|

Essas exceções destinam-se a ser utilizadas com as macros [THROW](exception-processing.md#throw), [THROW_LAST](exception-processing.md#throw_last), [try](exception-processing.md#try), [catch](exception-processing.md#catch), [and_catch](exception-processing.md#and_catch)e [end_catch.](exception-processing.md#end_catch) Para obter mais informações sobre exceções, consulte [Processamento de Exceções](exception-processing.md)ou consulte o artigo [Manipulação de Exceções (MFC)](../exception-handling-in-mfc.md).

Para obter uma exceção específica, use a classe derivada apropriada. Para capturar todos os tipos `CException`de exceções, use e use [CObject::IsKindOf](cobject-class.md#iskindof) para diferenciar entre `CException`classes derivadas. Note `CObject::IsKindOf` que funciona apenas para classes declaradas com o [IMPLEMENT_DYNAMIC](run-time-object-model-services.md#implement_dynamic) macro, a fim de aproveitar a verificação do tipo dinâmico. Qualquer `CException`classe derivada que você `IMPLEMENT_DYNAMIC` criar deve usar a macro também.

Você pode relatar detalhes sobre exceções ao usuário chamando [GetErrorMessage](cfileexception-class.md#geterrormessage) ou [ReportError](#reporterror), duas funções de membro que funcionam com qualquer uma das `CException`classes derivadas.

Se uma exceção for capturada por `CException` uma das macros, o objeto será excluído automaticamente; não apague você mesmo. Se uma exceção for capturada usando uma palavra-chave **de captura,** ela não será automaticamente excluída. Consulte o artigo [Manipulação de Exceções (MFC)](../exception-handling-in-mfc.md) para obter mais informações sobre quando excluir um objeto de exepção.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](cobject-class.md)

`CException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="cexceptioncexception"></a><a name="cexception"></a>CException::CException

Esta função membro `CException` constrói um objeto.

```
explicit CException(BOOL bAutoDelete);
```

### <a name="parameters"></a>Parâmetros

*b_AutoDelete*<br/>
Especifique TRUE `CException` se a memória do objeto tiver sido alocada no heap. Isso fará `CException` com que o objeto `Delete` seja excluído quando a função membro for chamada para excluir a exceção. Especifique `CException` FALSO se o objeto estiver na pilha ou se for um objeto global. Neste caso, `CException` o objeto não será `Delete` excluído quando a função membro for chamada.

### <a name="remarks"></a>Comentários

Você normalmente nunca precisaria chamar este construtor diretamente. Uma função que lança uma exceção `CException`deve criar uma instância de uma classe derivada e chamar seu construtor, ou deve usar uma das funções de lançamento do MFC, como [AfxThrowFileException,](exception-processing.md#afxthrowfileexception)para lançar um tipo predefinido. Esta documentação é fornecida apenas para a completude.

## <a name="cexceptiondelete"></a><a name="delete"></a>CException::Delete

Esta função verifica se `CException` o objeto foi criado no heap e, se for o caso, ele chama o operador **de exclusão** no objeto.

```cpp
void Delete();
```

### <a name="remarks"></a>Comentários

Ao excluir `CException` um objeto, `Delete` use a função membro para excluir a exceção. Não use o operador de `CException` **exclusão** diretamente, porque o objeto pode ser um objeto global ou ter sido criado na pilha.

Você pode especificar se o objeto deve ser excluído quando o objeto é construído. Para obter mais informações, consulte [CException::CException](#cexception).

Você só precisa `Delete` ligar se estiver usando o mecanismo de- **captura** **c++.** Se você estiver usando as macros MFC **TRY** e **CATCH,** essas macros chamarão automaticamente essa função.

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

## <a name="cexceptionreporterror"></a><a name="reporterror"></a>CException::'Erro de relatório

Ligue para esta função de membro para relatar o texto de erro em uma caixa de mensagem para o usuário.

```
virtual int ReportError(
    UINT nType = MB_OK,
    UINT nMessageID = 0);
```

### <a name="parameters"></a>Parâmetros

*nType*<br/>
Especifica o estilo da caixa de mensagens. Aplique qualquer combinação dos estilos da [caixa de mensagem](styles-used-by-mfc.md#message-box-styles) na caixa. Se você não especificar esse parâmetro, o padrão será MB_OK.

*nMessageID*<br/>
Especifica o ID de recurso (entrada da tabela de strings) de uma mensagem a ser exibida se o objeto de exceção não tiver uma mensagem de erro. Se 0, a mensagem "Nenhuma mensagem de erro está disponível" é exibida.

### <a name="return-value"></a>Valor retornado

Um `AfxMessageBox` valor; caso contrário 0 se não houver memória suficiente para exibir a caixa de mensagens. Consulte [AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox) para obter os possíveis valores de retorno.

### <a name="example"></a>Exemplo

Aqui está um exemplo `CException::ReportError`do uso de . Por outro exemplo, veja o exemplo de [CATCH](exception-processing.md#catch).

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
[Gráfico da hierarquia](../hierarchy-chart.md)<br/>
[Processamento de exceção](exception-processing.md)<br/>
[Como faço: criar minhas próprias classes de exceção personalizadas](https://go.microsoft.com/fwlink/p/?linkid=128045)
