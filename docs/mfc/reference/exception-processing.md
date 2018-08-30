---
title: Processamento de exceção | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.macros.exceptions
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 186a6705649cee7095d3d2e4c4bb237498fdcea0
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43221265"
---
# <a name="exception-processing"></a>Processamento de exceção
Quando um programa é executado, um número de condições anormais e chamados "exceções" de erros pode ocorrer. Eles podem incluir falta de memória, erros de alocação de recursos e de falha para encontrar arquivos.  
  
 A biblioteca Microsoft Foundation Class usa um esquema de manipulação de exceção que é modelado estreitamente depois que um proposto pelo Comitê de padrões ANSI para C++. Um manipulador de exceção deve ser configurado antes de chamar uma função que pode encontrar uma situação anormal. Se a função encontrar uma condição anormal, ele gerará uma exceção e o controle é passado para o manipulador de exceção.  
  
 Várias macros incluídas com a biblioteca Microsoft Foundation Class irá configurar manipuladores de exceção. Várias outras funções globais de ajudam a gerar exceções especializadas e encerramento de programas, se necessário. Essas macros e funções globais se enquadram nas categorias a seguir:  
  
- Macros de exceção, qual estrutura o manipulador de exceção.  
  
- Exception-throwing funções), que geram exceções de tipos específicos.  
  
- Funções de encerramento que fazem com que o encerramento do programa.  
  
 Para obter mais detalhes e exemplos, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="exception-macros"></a>Macros de exceção  
  
|||  
|-|-|  
|[TENTE](#try)|Designa um bloco de código para o processamento de exceção.|  
|[CATCH](#catch)|Designa um bloco de código para capturar uma exceção do anterior **tente** bloco.|  
|[CATCH_ALL](#catch_all)|Designa um bloco de código para capturar todas as exceções de precedente **tente** bloco.|  
|[AND_CATCH](#and_catch)|Designa um bloco de código para capturar tipos adicionais de exceção do anterior **tente** bloco.|  
|[AND_CATCH_ALL](#and_catch_all)|Designa um bloco de código para capturar todos os outros tipos adicionais de exceção gerados em precedidos **tente** bloco.|  
|[END_CATCH](#end_catch)|Termina a última **CATCH** ou **AND_CATCH** bloco de código.|  
|[END_CATCH_ALL](#end_catch_all)|Termina a última **CATCH_ALL** bloco de código.|  
|[THROW](#throw)|Gera uma exceção especificada.|  
|[THROW_LAST](#throw_last)|Lança a exceção tratada no momento para o próximo manipulador externa.|  
  
### <a name="exception-throwing-functions"></a>Funções geradoras de exceções  
  
|||  
|-|-|  
|[AfxThrowArchiveException](#afxthrowarchiveexception)|Gera uma exceção de arquivo morto.|  
|[AfxThrowFileException](#afxthrowfileexception)|Gera uma exceção de arquivo.|  
|[AfxThrowInvalidArgException](#afxthrowinvalidargexception)|Gera uma exceção de argumento inválido.|
|[AfxThrowMemoryException](#afxthrowmemoryexception)|Gera uma exceção de memória.|  
|[AfxThrowNotSupportedException](#afxthrownotsupportedexception)|Lança uma exceção sem suporte.|  
|[AfxThrowResourceException](#afxthrowresourceexception)|Lança uma exceção de recurso não encontrado para Windows.|  
|[AfxThrowUserException](#afxthrowuserexception)|Gera uma exceção em uma ação iniciada pelo usuário do programa.|  
  
 MFC fornece duas funções geradoras de exceções especificamente para exceções OLE:  
  
### <a name="ole-exception-functions"></a>Funções de exceção OLE  
  
|||  
|-|-|  
|[AfxThrowOleDispatchException](#afxthrowoledispatchexception)|Gera uma exceção dentro de uma função de automação OLE.|  
|[AfxThrowOleException](#afxthrowoleexception)|Gera uma exceção de OLE.|  
  
 Para dar suporte a exceções de banco de dados, as classes de banco de dados fornecem duas classes de exceção `CDBException` e `CDaoException`e funções globais para dar suporte a tipos de exceção:  
  
### <a name="dao-exception-functions"></a>Funções de exceção do DAO  
  
|||  
|-|-|  
|[AfxThrowDAOException](#afxthrowdaoexception)|Gera uma [CDaoException](../../mfc/reference/cdaoexception-class.md) de seu próprio código.|  
|[AfxThrowDBException](#afxthrowdbexception)|Gera uma [CDBException](../../mfc/reference/cdbexception-class.md) de seu próprio código.|  
  
 MFC fornece a seguinte função de encerramento:  
  
### <a name="termination-functions"></a>Funções de encerramento  
  
|||  
|-|-|  
|[AfxAbort](#afxabort)|Chamado encerrar um aplicativo quando um erro fatal de ocorre.|  
  
##  <a name="try"></a>  TENTE  
 Configura um **tente** bloco.  
  
```   
TRY   
```  
  
### <a name="remarks"></a>Comentários  
 Um **tente** bloco identifica um bloco de código que pode lançar exceções. Essas exceções são tratadas no seguinte **CATCH** e **AND_CATCH** blocos. Recursão é permitida: exceções podem ser passadas para um outer **tente** bloco, ignorando-los ou usando a macro THROW_LAST. Final do **tente** bloco com uma macro END_CATCH ou END_CATCH_ALL.  
  
 Para obter mais informações, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CATCH](#catch).  

### <a name="requirements"></a>Requisitos
Cabeçalho: afx.h

##  <a name="catch"></a>  CATCH  
 Define um bloco de código que captura o primeiro tipo de exceção lançado anteriormente na **tente** bloco.  
  
```   
CATCH(exception_class, exception_object_pointer_name)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 *exception_class*  
 Especifica o tipo de exceção para testar. Para obter uma lista de classes de exceção padrão, consulte a classe [CException](../../mfc/reference/cexception-class.md).  
  
 *exception_object_pointer_name*  
 Especifica um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome de ponteiro para acessar o objeto de exceção dentro de **CATCH** bloco. Essa variável é declarada para você.  
  
### <a name="remarks"></a>Comentários  
 O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Chama a macro THROW_LAST para mudar o processamento para o próximo quadro de exceção externa. Final do **tente** bloco com uma macro END_CATCH.  
  
 Se *exception_class* é a classe `CException`, em seguida, todos os tipos de exceção serão capturados. Você pode usar o [CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof) a função de membro para determinar qual exceção específica foi lançada. Uma maneira melhor para capturar vários tipos de exceções é usar sequencial **AND_CATCH** instruções, cada um com um tipo de exceção diferente.  
  
 O ponteiro de objeto de exceção é criado pela macro. Você não precisa declará-la.  
  
> [!NOTE]
>  O **CATCH** bloco é definido como um escopo C++ delineado por chaves. Se você declarar variáveis nesse escopo, eles são acessíveis somente dentro desse escopo. Isso também se aplica *exception_object_pointer_name*.  
  
 Para obter mais informações sobre exceções e a macro CATCH, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCExceptions#26](../../mfc/codesnippet/cpp/exception-processing_1.cpp)]  
  
##  <a name="catch_all"></a>  CATCH_ALL  
 Define um bloco de código que captura todos os tipos de exceção lançados anteriormente na **tente** bloco.  
  
```   
CATCH_ALL(exception_object_pointer_name)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *exception_object_pointer_name*  
 Especifica um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome de ponteiro para acessar o objeto de exceção dentro de `CATCH_ALL` bloco. Essa variável é declarada para você.  
  
### <a name="remarks"></a>Comentários  
 O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Invocar o `THROW_LAST` macro para deslocar o processamento para o próximo quadro de exceção externa. Se você usar **CATCH_ALL**, final a **tente** bloco com uma macro END_CATCH_ALL.  
  
> [!NOTE]
>  O **CATCH_ALL** bloco é definido como um escopo C++ delineado por chaves. Se você declarar variáveis nesse escopo, eles são acessíveis somente dentro desse escopo.  
  
 Para obter mais informações sobre exceções, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CFile::Abort](../../mfc/reference/cfile-class.md#abort).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX. h  

##  <a name="and_catch"></a>  AND_CATCH  
 Define um bloco de código para capturar tipos adicionais de exceção gerados em precedidos **tente** bloco.  
  
```   
AND_CATCH(exception_class, exception_object_pointer_name)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *exception_class*  
 Especifica o tipo de exceção para testar. Para obter uma lista de classes de exceção padrão, consulte a classe [CException](../../mfc/reference/cexception-class.md).  
  
 *exception_object_pointer_name*  
 Um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome de ponteiro para acessar o objeto de exceção dentro de **AND_CATCH** bloco. Essa variável é declarada para você.  
  
### <a name="remarks"></a>Comentários  
 Use a macro CATCH para capturar um tipo de exceção, em seguida, a macro AND_CATCH para capturar cada tipo subsequente. Final do **tente** bloco com uma macro END_CATCH.  
  
 O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Chamar a macro THROW_LAST dentro de **AND_CATCH** bloquear o deslocamento de processamento para o próximo quadro de exceção externa. **AND_CATCH** marca o final do anterior **CATCH** ou **AND_CATCH** bloco.  
  
> [!NOTE]
>  O **AND_CATCH** bloco é definido como um escopo C++ (delimitado por chaves). Se você declarar variáveis nesse escopo, lembre-se de que eles são acessíveis somente dentro desse escopo. Isso também se aplica a *exception_object_pointer_name* variável.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CATCH](#catch).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX. h  
##  <a name="and_catch_all"></a>  AND_CATCH_ALL  
 Define um bloco de código para capturar tipos adicionais de exceção gerados em precedidos **tente** bloco.  
  
```   
AND_CATCH_ALL(exception_object_pointer_name)  
```  
  
### <a name="parameters"></a>Parâmetros  
 *exception_object_pointer_name*  
 Um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome de ponteiro para acessar o objeto de exceção dentro de **AND_CATCH_ALL** bloco. Essa variável é declarada para você.  
  
### <a name="remarks"></a>Comentários  
 Use o **CATCH** macro para capturar um tipo de exceção e, em seguida, a macro AND_CATCH_ALL para capturar todos os outros tipos subsequentes. Se você usar AND_CATCH_ALL, encerrar o **tente** bloco com uma macro END_CATCH_ALL.  
  
 O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Chamar a macro THROW_LAST dentro de **AND_CATCH_ALL** bloquear o deslocamento de processamento para o próximo quadro de exceção externa. **AND_CATCH_ALL** marca o final do anterior **CATCH** ou **AND_CATCH_ALL** bloco.  
  
> [!NOTE]
>  O **AND_CATCH_ALL** bloco é definido como um escopo C++ (delimitado por chaves). Se você declarar variáveis nesse escopo, lembre-se de que eles são acessíveis somente dentro desse escopo.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX. h  
  
##  <a name="end_catch"></a>  END_CATCH  
 Marca o fim da última **CATCH** ou **AND_CATCH** bloco.  
  
```   
END_CATCH  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre a macro END_CATCH, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX. h  
  
##  <a name="end_catch_all"></a>  END_CATCH_ALL  
 Marca o fim do último * * CATCH_ALL88 ou **AND_CATCH_ALL** bloco.  
  
```   
END_CATCH_ALL  
```  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX. h  
  
##  <a name="throw"></a>  THROW (MFC)  
 Lança a exceção especificada.  
  
```   
THROW(exception_object_pointer) 
```  
  
### <a name="parameters"></a>Parâmetros  
 *exception_object_pointer*  
 Aponta para um objeto de exceção derivado de `CException`.  
  
### <a name="remarks"></a>Comentários  
 **LANÇAR** interrompe a execução, passando o controle ao programa **CATCH** bloquear em seu programa. Se você não tiver fornecido a **CATCH** bloquear, em seguida, o controle é passado para um módulo de biblioteca Microsoft Foundation Class que imprime um erro de mensagem e sai.  
  
 Para obter mais informações, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX. h  
  
##  <a name="throw_last"></a>  THROW_LAST  
 Lança a exceção de volta para o próximo outer **CATCH** bloco.  
  
```   
THROW_LAST()   
```  
  
### <a name="remarks"></a>Comentários  
 Essa macro permite que você lançar uma exceção criada localmente. Se você tentar lançar uma exceção que você acaba de apresentar, ele será normalmente saem do escopo e ser excluído. Com o **THROW_LAST**, a exceção é passada corretamente para a próxima **CATCH** manipulador.  
  
 Para obter mais informações, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CFile::Abort](../../mfc/reference/cfile-class.md#abort).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX. h  
  
##  <a name="afxthrowarchiveexception"></a>  AfxThrowArchiveException  
 Gera uma exceção de arquivo morto.  
  
```   
void  AfxThrowArchiveException(int cause, LPCTSTR lpszArchiveName); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *cause*  
 Especifica um número inteiro que indica o motivo da exceção. Para obter uma lista dos valores possíveis, consulte [CArchiveException::m_cause](../../mfc/reference/carchiveexception-class.md#m_cause).  
  
 *lpszArchiveName*  
 Aponta para uma cadeia de caracteres que contém o nome da `CArchive` objeto que causou a exceção (se disponível).  
  
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
 *cause*  
 Especifica um número inteiro que indica o motivo da exceção. Para obter uma lista dos valores possíveis, consulte [CFileException::m_cause](../../mfc/reference/cfileexception-class.md#m_cause).  
  
 *lOsError*  
 Contém o número de erro do sistema operacional (se disponível) que indica o motivo da exceção. Consulte o manual do sistema operacional para obter uma listagem de códigos de erro.  
  
 *lpszFileName*  
 Aponta para uma cadeia de caracteres que contém o nome do arquivo que causou a exceção (se disponível).  
  
### <a name="remarks"></a>Comentários  
 Você é responsável por determinar a causa, com base no código de erro do sistema operacional.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX. h  

## <a name="afxthrowinvalidargexception"></a>  AfxThrowInvalidArgException
Gera uma exceção de argumento inválido.  
   
### <a name="syntax"></a>Sintaxe    
```
void AfxThrowInvalidArgException( );  
```  
   
### <a name="remarks"></a>Comentários  
 Essa função é chamada quando os argumentos inválidos são usados.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [Classe CInvalidArgException](cinvalidargexception-class.md)   
 [THROW](#throw)
  
  
##  <a name="afxthrowmemoryexception"></a>  AfxThrowMemoryException  
 Gera uma exceção de memória.  
  
```   
void AfxThrowMemoryException(); 
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função se chamadas para alocadores de memória de sistema subjacente (como **malloc** e o [GlobalAlloc](/windows/desktop/api/winbase/nf-winbase-globalalloc) função do Windows) falhar. Não é necessário chamá-lo para **novos** porque **novos** lançará uma exceção de memória automaticamente se a alocação de memória falhar.  
  
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
 Essa função normalmente é chamada quando um recurso do Windows não pode ser carregado.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX. h  
  
##  <a name="afxthrowuserexception"></a>  AfxThrowUserException  
 Gera uma exceção para interromper uma operação do usuário final.  
  
```   
void AfxThrowUserException(); 
```  
  
### <a name="remarks"></a>Comentários  
 Normalmente, essa função é chamada imediatamente após `AfxMessageBox` relatou um erro ao usuário.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX. h  
  
##  <a name="afxthrowoledispatchexception"></a>  AfxThrowOleDispatchException  
 Use esta função para gerar uma exceção dentro de uma função de automação OLE.  
  
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
 *wCode*  
 Um código de erro específico para seu aplicativo.  
  
 *lpszDescription*  
 Descrição textual do erro.  
  
 *nDescriptionID*  
 ID de recurso para a descrição textual do erro.  
  
 *nHelpID*  
 Um contexto de ajuda para obter ajuda do seu aplicativo (. Arquivo HLP).  
  
### <a name="remarks"></a>Comentários  
 As informações fornecidas para essa função podem ser exibidas pelo aplicativo condução (Microsoft Visual Basic ou outro aplicativo de cliente de automação OLE).  
  
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
 *SC*  
 Um código de status OLE que indica o motivo da exceção.  
  
 *hr*  
 Identificador para um código de resultado que indica o motivo da exceção.  
  
### <a name="remarks"></a>Comentários  
 A versão que usa HRESULT como um argumento converte esse código de resultado no SCODE correspondente. Para obter mais informações sobre o HRESULT e SCODE, consulte [estrutura de códigos de erro COM](/windows/desktop/com/structure-of-com-error-codes) no SDK do Windows.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  
  
##  <a name="afxthrowdaoexception"></a>  AfxThrowDaoException  
 Chame essa função para lançar uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md) de seu próprio código.  
  
```   
void AFXAPI AfxThrowDaoException(
    int nAfxDaoError = NO_AFX_DAO_ERROR,  
    SCODE scode = S_OK); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *nAfxDaoError*  
 Um valor inteiro que representa um código de erro estendido de DAO, que pode ser um dos valores listados em [CDaoException::m_nAfxDaoError](../../mfc/reference/cdaoexception-class.md#m_nafxdaoerror).  
  
 *scode*  
 Um código de erro OLE do DAO, do tipo SCODE. Para obter informações, consulte [CDaoException::m_scode](../../mfc/reference/cdaoexception-class.md#m_scode).  
  
### <a name="remarks"></a>Comentários  
 A estrutura também chama `AfxThrowDaoException`. Em sua chamada, você pode passar um dos parâmetros ou ambos. Por exemplo, se você quiser gerar um dos erros definido em **CDaoException::nAfxDaoError** , mas você não se importam o *scode* parâmetro, passar um código válido no *nAfxDaoError* parâmetro e aceitar o valor padrão para *scode*.  
  
 Para obter informações sobre as exceções relacionadas às classes DAO MFC, consulte a classe `CDaoException` este livro e o artigo [exceções: exceções de banco de dados](../../mfc/exceptions-database-exceptions.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdb. h  
  
##  <a name="afxthrowdbexception"></a>  AfxThrowDBException  
 Chame essa função para lançar uma exceção do tipo `CDBException` de seu próprio código.  
  
```  
void AfxThrowDBException(
    RETCODE nRetCode,  
    CDatabase* pdb,  
    HSTMT hstmt);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nRetCode*  
 Um valor do tipo RETCODE, definindo o tipo de erro que causou a exceção seja lançada.  
  
 *PDB*  
 Um ponteiro para o `CDatabase` objeto que representa a conexão de fonte de dados ao qual a exceção está associada.  
  
 *HSTMT*  
 Um identificador de HSTMT ODBC que especifica o identificador de instrução ao qual a exceção está associada.  
  
### <a name="remarks"></a>Comentários  
 A estrutura chama `AfxThrowDBException` quando ele recebe um RETCODE ODBC de uma chamada para uma função de API do ODBC e interpreta o RETCODE como uma condição de exceção em vez de um erro expectable. Por exemplo, uma operação de acesso de dados pode falhar devido a um erro de leitura de disco.  
  
 Para obter informações sobre os valores RETCODE definidas pelo ODBC, consulte o capítulo 8, "Recuperando informações de Status e erro", no SDK do Windows. Para obter informações sobre extensões MFC para esses códigos, consulte a classe [CDBException](../../mfc/reference/cdbexception-class.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX. h  
  
##  <a name="afxabort"></a>  AfxAbort  
 A função de encerramento padrão fornecida pelo MFC.  
  
```   
void  AfxAbort(); 
```  
  
### <a name="remarks"></a>Comentários  
 `AfxAbort` é chamado internamente por funções de membro MFC quando há um erro fatal, como uma exceção não identificada que não pode ser tratado. Você pode chamar `AfxAbort` em casos raros, quando você encontrar um erro catastrófico do qual você não pode se recuperar.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CATCH](#catch).  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX. h   
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)   
 [Classe CException](../../mfc/reference/cexception-class.md)
