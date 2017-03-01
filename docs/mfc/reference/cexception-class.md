---
title: Classe CException | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CException
dev_langs:
- C++
helpviewer_keywords:
- COleDispatchException class, base class
- CException class
- exceptions, classes for
- CInternetException class, base class
- macros, exception handling
- CNotSupportedException class, base class
- CFileException class, base class
- CDBException class, base class
- CArchiveException class, base class
- CUserException class
- CDaoException class, base class
- CMemoryException class, base class
- COleException class, base class
- CResourceException class, base class
ms.assetid: cfacf14d-bfe4-4666-a5c7-38b800512920
caps.latest.revision: 22
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 4cbb69ff79a1b201260d83b1bd568b63519a33b5
ms.lasthandoff: 02/25/2017

---
# <a name="cexception-class"></a>Classe CException
A classe base para todas as exceções na biblioteca Microsoft Foundation Class.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class AFX_NOVTABLE CException : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CException::CException](#cexception)|Constrói um objeto `CException`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CException::Delete](#delete)|Exclui um `CException` objeto.|  
|[CException::ReportError](#reporterror)|Relata uma mensagem de erro em uma caixa de mensagem para o usuário.|  
  
## <a name="remarks"></a>Comentários  
 Porque `CException` é uma classe base abstrata não é possível criar `CException` objetos diretamente, você deve criar objetos de classes derivadas. Se você precisa criar seu próprio `CException`-classe de estilo, use uma das classes derivadas listadas acima como um modelo. Certifique-se de que sua classe derivada também usa `IMPLEMENT_DYNAMIC`.  
  
 As classes derivadas e suas descrições são listadas abaixo:  
  
|||  
|-|-|  
|[CSimpleException](../../mfc/reference/csimpleexception-class.md)|Uma classe base para exceções recursos críticos do MFC|  
|[CInvalidArgException](../../mfc/reference/cinvalidargexception-class.md)|Condição de exceção de argumento inválido|  
|[CMemoryException](../../mfc/reference/cmemoryexception-class.md)|Exceção de memória insuficiente|  
|[CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)|Solicitação de operação sem suporte|  
|[CArchiveException](../../mfc/reference/carchiveexception-class.md)|Exceção de arquivo específicos|  
|[CFileException](../../mfc/reference/cfileexception-class.md)|Exceção de arquivo específicos|  
|[CResourceException](../../mfc/reference/cresourceexception-class.md)|Recursos do Windows não foi encontrado ou não criáveis|  
|[COleException](../../mfc/reference/coleexception-class.md)|Exceção de OLE|  
|[CDBException](../../mfc/reference/cdbexception-class.md)|Exceção de banco de dados (ou seja, as condições de exceção resultante para classes de banco de dados MFC com base em Open Database Connectivity)|  
|[COleDispatchException](../../mfc/reference/coledispatchexception-class.md)|Exceção de expedição (automação) OLE|  
|[CUserException](../../mfc/reference/cuserexception-class.md)|Exceção que indica que um recurso não pôde ser encontrado|  
|[CDaoException](../../mfc/reference/cdaoexception-class.md)|Exceção de objeto de acesso de dados (ou seja, as condições de exceção resultante para classes DAO)|  
|[CInternetException](../../mfc/reference/cinternetexception-class.md)|Exceção de Internet (ou seja, as condições de exceção resultante para classes de Internet).|  
  
 Essas exceções destinam-se a ser usada com a [lançar](exception-processing.md#throw), [THROW_LAST](exception-processing.md#throw_last), [tente](exception-processing.md#try), [catch](exception-processing.md#catch), [and_catch](exception-processing.md#and_catch), e [end_catch](exception-processing.md#end_catch) macros. Para obter mais informações sobre exceções, consulte [o processamento de exceções](exception-processing.md), ou consulte o artigo [tratamento de exceção (MFC)](../exception-handling-in-mfc.md).  
  
 Para capturar uma exceção específica, use a classe derivada apropriada. A captura todos os tipos de exceções, use `CException`e use [CObject::IsKindOf](cobject-class.md#iskindof) diferenciar `CException`-classes derivadas. Observe que `CObject::IsKindOf` funciona somente para classes declaradas com o [IMPLEMENT_DYNAMIC](run-time-object-model-services.md#implement_dynamic) macro, para aproveitar a verificação de tipo dinâmico. Qualquer `CException`-classe derivada que você criar deve usar o `IMPLEMENT_DYNAMIC` macro muito.  
  
 Você pode relatar os detalhes sobre exceções para o usuário chamando [GetErrorMessage](cfileexception-class.md#geterrormessage) ou [ReportError](#reporterror), duas funções de membro que funcionam com qualquer um dos `CException`de classes derivadas.  
  
 Se uma exceção é detectada por uma das macros, o `CException` objeto é excluído automaticamente; não excluí-lo por conta própria. Se uma exceção é capturada usando um **catch** palavra-chave, ela não é excluída automaticamente. Consulte o artigo [tratamento de exceção (MFC)](../exception-handling-in-mfc.md) para obter mais informações sobre quando você excluir um objeto de exceção.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](cobject-class.md)  
  
 `CException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h  
  
##  <a name="a-namecexceptiona--cexceptioncexception"></a><a name="cexception"></a>CException::CException  
 Essa função de membro constrói uma `CException` objeto.  
  
```  
explicit CException(BOOL bAutoDelete);
```  
  
### <a name="parameters"></a>Parâmetros  
 *b_AutoDelete*  
 Especifique **TRUE** se a memória para a `CException` objeto foi alocado no heap. Isso fará com que o `CException` objeto a ser excluído quando o **excluir** função de membro é chamada para remover a exceção. Especifique **FALSE** se o `CException` objeto na pilha ou é um objeto global. Nesse caso, o `CException` objeto não será excluído quando o **excluir** é chamada de função de membro.  
  
### <a name="remarks"></a>Comentários  
 Você normalmente não precisa chamar esse construtor diretamente. Uma função que lança uma exceção deve criar uma instância de um `CException`-classe derivada e chama seu construtor, ou ele deve usar uma do MFC lançar funções, como [AfxThrowFileException](exception-processing.md#afxthrowfileexception), para gerar um tipo predefinido. Esta documentação é fornecida somente para fins de exatidão.  
  
##  <a name="a-namedeletea--cexceptiondelete"></a><a name="delete"></a>CException::Delete  
 Essa função verifica se o **CException** objeto foi criado na pilha e, em caso afirmativo, ele chama o **excluir** operador no objeto.  
  
```  
void Delete();
```  
  
### <a name="remarks"></a>Comentários  
 Ao excluir uma **CException** de objeto, use o **excluir** a função de membro para excluir a exceção. Não use o **excluir** operador diretamente, pois o `CException` objeto pode ser um objeto global ou foram criadas na pilha.  
  
 Você pode especificar se o objeto deve ser excluído quando o objeto é construído. Para obter mais informações, consulte [CException::CException](#cexception).  
  
 Você só precisa chamar **excluir** se você estiver usando o C++ **tente**- **catch** mecanismo. Se você estiver usando as macros MFC **tente** e **CATCH**, essas macros serão automaticamente chamar essa função.  
  
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
  
##  <a name="a-namereporterrora--cexceptionreporterror"></a><a name="reporterror"></a>CException::ReportError  
 Chame essa função de membro para texto de erro de relatório em uma caixa de mensagem para o usuário.  
  
```  
virtual int ReportError(
    UINT nType = MB_OK,  
    UINT nMessageID = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nType`  
 Especifica o estilo da caixa de mensagem. Aplique qualquer combinação da [estilos de caixa de mensagem](message-box-styles.md) à caixa. Se você não especificar esse parâmetro, o padrão é **MB_OK**.  
  
 *nMessageID*  
 Especifica a ID de recurso (entrada de cadeia de caracteres) de uma mensagem a ser exibida se o objeto de exceção não tiver uma mensagem de erro. Se for 0, a mensagem "nenhuma mensagem de erro está disponível" é exibida.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `AfxMessageBox` valor; caso contrário, 0 se não houver memória suficiente para exibir a caixa de mensagem. Consulte [AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox) para retornar valores possíveis.  
  
### <a name="example"></a>Exemplo  
 Aqui está um exemplo do uso de `CException::ReportError`. Outro exemplo, consulte o exemplo para [CATCH](exception-processing.md#catch).  
  
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
 [Classe CObject](cobject-class.md)   
 [Gráfico de hierarquia](../hierarchy-chart.md)   
 [Processamento de exceção](exception-processing.md)   
 [Como fazer: criar minhas próprias Classes de exceção personalizada](http://go.microsoft.com/fwlink/linkid=128045)



