---
title: "Processamento de exceção | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.exceptions
dev_langs:
- C++
helpviewer_keywords:
- macros, exception handling
- DAO (Data Access Objects), exceptions
- OLE exceptions, MFC functions
- exceptions, processing
- exception macros
- termination functions, MFC
- MFC, exceptions
- exceptions, MFC throwing functions
ms.assetid: 26d4457c-8350-48f5-916e-78f919787c30
caps.latest.revision: 16
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
ms.sourcegitcommit: b943ef8dd652df061965fe81ecc9c08115636141
ms.openlocfilehash: fc136efaa6312edf3edfa8420411eda73e1c2468
ms.lasthandoff: 04/04/2017

---
# <a name="exception-processing"></a>Processamento de exceção
Quando um programa é executado, um número de condições anormais e erros chamados "exceções" pode ocorrer. Eles podem incluir falta de memória, erros de alocação de recurso e Falha ao localizar os arquivos.  
  
 A biblioteca Microsoft Foundation Class usa um esquema de tratamento de exceção que é modelado perto um proposto pelo Comitê de padrões ANSI para C++. Um manipulador de exceção deve ser configurado antes de chamar uma função que pode encontrar uma situação anormal. Se a função encontra uma condição anormal, ele lança uma exceção e o controle é passado para o manipulador de exceção.  
  
 Várias macros que acompanha a biblioteca Microsoft Foundation Class irá configurar manipuladores de exceção. Um número de outras funções globais ajuda a gerar exceções especializadas e encerramento de programas, se necessário. Essas macros e funções globais se enquadram nas categorias a seguir:  
  
- Macros de exceção que o manipulador de exceção de estrutura.  
  
- Exception-throwing funções), que geram exceções de tipos específicos.  
  
- Funções de encerramento que fazer com que o encerramento do programa.  
  
 Para obter mais detalhes e exemplos, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="exception-macros"></a>Macros de exceção  
  
|||  
|-|-|  
|[TENTE](#try)|Designa um bloco de código para o processamento de exceção.|  
|[CATCH](#catch)|Designa um bloco de código para capturar uma exceção de anterior **tente** bloco.|  
|[CATCH_ALL](#catch_all)|Designa um bloco de código para capturar todas as exceções de anterior **tente** bloco.|  
|[AND_CATCH](#and_catch)|Designa um bloco de código para capturar tipos adicionais de exceção de anterior **tente** bloco.|  
|[AND_CATCH_ALL](#and_catch_all)|Designa um bloco de código para capturar todos os outros tipos adicionais de exceção gerados em precedidos **tente** bloco.|  
|[END_CATCH](#end_catch)|Termina a última **CATCH** ou `AND_CATCH` bloco de código.|  
|[END_CATCH_ALL](#end_catch_all)|Termina a última `CATCH_ALL` bloco de código.|  
|[THROW](#throw)|Gera uma exceção especificada.|  
|[THROW_LAST](#throw_last)|Lança a exceção tratada no momento para o próximo manipulador externa.|  
  
### <a name="exception-throwing-functions"></a>Funções geradoras de exceções  
  
|||  
|-|-|  
|[AfxThrowArchiveException](#afxthrowarchiveexception)|Gera uma exceção de arquivo morto.|  
|[AfxThrowFileException](#afxthrowfileexception)|Lança uma exceção de arquivo.|  
|[AfxThrowInvalidArgException](#afxthrowinvalidargexception)|Gera uma exceção de argumento inválido.|
|[AfxThrowMemoryException](#afxthrowmemoryexception)|Lança uma exceção de memória.|  
|[AfxThrowNotSupportedException](#afxthrownotsupportedexception)|Lança uma exceção não suportada.|  
|[AfxThrowResourceException](#afxthrowresourceexception)|Lança uma exceção de recurso não encontrado para Windows.|  
|[AfxThrowUserException](#afxthrowuserexception)|Gera uma exceção em uma ação iniciada pelo usuário do programa.|  
  
 MFC fornece duas funções geradoras de exceções especificamente para exceções OLE:  
  
### <a name="ole-exception-functions"></a>Funções de exceção de OLE  
  
|||  
|-|-|  
|[AfxThrowOleDispatchException](#afxthrowoledispatchexception)|Gera uma exceção em uma função de automação OLE.|  
|[AfxThrowOleException](#afxthrowoleexception)|Gera uma exceção de OLE.|  
  
 Para dar suporte a exceções de banco de dados, as classes de banco de dados fornecem duas classes de exceção, `CDBException` e `CDaoException`e as funções globais para dar suporte os tipos de exceção:  
  
### <a name="dao-exception-functions"></a>Funções de exceção DAO  
  
|||  
|-|-|  
|[AfxThrowDAOException](#afxthrowdaoexception)|Gera um [CDaoException](../../mfc/reference/cdaoexception-class.md) de seu próprio código.|  
|[AfxThrowDBException](#afxthrowdbexception)|Gera um [CDBException](../../mfc/reference/cdbexception-class.md) de seu próprio código.|  
  
 MFC fornece a seguinte função de encerramento:  
  
### <a name="termination-functions"></a>Funções de encerramento  
  
|||  
|-|-|  
|[AfxAbort](#afxabort)|Chamado encerrar um aplicativo quando um erro fatal de ocorre.|  
  
##  <a name="try"></a>TENTE  
 Configura um **tente** bloco.  
  
```   
TRY   
```  
  
### <a name="remarks"></a>Comentários  
 Um **tente** bloco identifica um bloco de código que pode lançar exceções. Essas exceções são tratadas no seguinte **CATCH** e `AND_CATCH` blocos. Recursão é permitida: exceções podem ser passadas para um externa **tente** bloco, ignorando-los ou usando o `THROW_LAST` macro. Final de **tente** bloco com um `END_CATCH` ou `END_CATCH_ALL` macro.  
  
 Para obter mais informações, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CATCH](#catch).  

### <a name="requirements"></a>Requisitos
Cabeçalho: afx.h

##  <a name="catch"></a>CATCH  
 Define um bloco de código que captura o primeiro tipo de exceção gerado na anterior **tente** bloco.  
  
```   
CATCH(exception_class, exception_object_pointer_name)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 *exception_class*  
 Especifica o tipo de exceção para testar. Para obter uma lista de classes de exceção padrão, consulte a classe [CException](../../mfc/reference/cexception-class.md).  
  
 *exception_object_pointer_name*  
 Especifica um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome do ponteiro para acessar o objeto de exceção dentro de **CATCH** bloco. Essa variável é declarada para você.  
  
### <a name="remarks"></a>Comentários  
 O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Invocar o `THROW_LAST` macro para alternar o processamento para o próximo quadro de exceção externa. Final de **tente** bloco com um `END_CATCH` macro.  
  
 Se *exception_class* é a classe `CException`, em seguida, todos os tipos de exceção serão capturados. Você pode usar o [CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof) a função de membro para determinar quais específico de exceção foi lançado. Uma maneira melhor de capturar vários tipos de exceções é usar sequencial `AND_CATCH` instruções, cada um com um tipo de exceção diferente.  
  
 O ponteiro de objeto de exceção é criado pela macro. Você não precisa declará-la.  
  
> [!NOTE]
>  O **CATCH** bloco é definido como um escopo de C++ delimitado por colchetes. Se você declarar variáveis no escopo, eles são acessíveis somente dentro desse escopo. Isso também se aplica a *exception_object_pointer_name*.  
  
 Para obter mais informações sobre exceções e o **CATCH** macro, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[26 de # NVC_MFCExceptions](../../mfc/codesnippet/cpp/exception-processing_1.cpp)]  
  
##  <a name="catch_all"></a>CATCH_ALL  
 Define um bloco de código que captura todos os tipos de exceção gerados na anterior **tente** bloco.  
  
```   
CATCH_ALL(exception_object_pointer_name)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *exception_object_pointer_name*  
 Especifica um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome do ponteiro para acessar o objeto de exceção dentro de `CATCH_ALL` bloco. Essa variável é declarada para você.  
  
### <a name="remarks"></a>Comentários  
 O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Invocar o `THROW_LAST` macro para alternar o processamento para o próximo quadro de exceção externa. Se você usar `CATCH_ALL`, final do **tente** bloco com um `END_CATCH_ALL` macro.  
  
> [!NOTE]
>  O `CATCH_ALL` bloco é definido como um escopo de C++ delimitado por colchetes. Se você declarar variáveis no escopo, eles são acessíveis somente dentro desse escopo.  
  
 Para obter mais informações sobre exceções, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CFile::Abort](../../mfc/reference/cfile-class.md#abort).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  

##  <a name="and_catch"></a>AND_CATCH  
 Define um bloco de código para capturar tipos adicionais de exceção gerados em precedidos **tente** bloco.  
  
```   
AND_CATCH(exception_class, exception_object_pointer_name)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *exception_class*  
 Especifica o tipo de exceção para testar. Para obter uma lista de classes de exceção padrão, consulte a classe [CException](../../mfc/reference/cexception-class.md).  
  
 *exception_object_pointer_name*  
 Um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome do ponteiro para acessar o objeto de exceção dentro de `AND_CATCH` bloco. Essa variável é declarada para você.  
  
### <a name="remarks"></a>Comentários  
 Use o **CATCH** macro para capturar um tipo de exceção, o `AND_CATCH` macro para cada tipo subsequente catch. Final de **tente** bloco com um `END_CATCH` macro.  
  
 O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Chamar o `THROW_LAST` macro dentro de `AND_CATCH` bloquear o deslocamento de processamento para o próximo quadro de exceção externa. `AND_CATCH`marca o fim da **CATCH** ou `AND_CATCH` bloco.  
  
> [!NOTE]
>  O `AND_CATCH` bloco é definido como um escopo do C++ (delimitado por chaves). Se você declarar variáveis no escopo, lembre-se de que eles são acessíveis apenas dentro desse escopo. Isso também se aplica a *exception_object_pointer_name* variável.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CATCH](#catch).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  
##  <a name="and_catch_all"></a>AND_CATCH_ALL  
 Define um bloco de código para capturar tipos adicionais de exceção gerados em precedidos **tente** bloco.  
  
```   
AND_CATCH_ALL(exception_object_pointer_name)  
```  
  
### <a name="parameters"></a>Parâmetros  
 *exception_object_pointer_name*  
 Um nome para um ponteiro de objeto de exceção que será criado pela macro. Você pode usar o nome do ponteiro para acessar o objeto de exceção dentro de `AND_CATCH_ALL` bloco. Essa variável é declarada para você.  
  
### <a name="remarks"></a>Comentários  
 Use o **CATCH** macro para capturar um tipo de exceção, o `AND_CATCH_ALL` macro para capturar todos os outros tipos subsequentes. Se você usar `AND_CATCH_ALL`, final do **tente** bloco com um `END_CATCH_ALL` macro.  
  
 O código de processamento de exceção pode interrogar o objeto de exceção, se apropriado, para obter mais informações sobre a causa específica da exceção. Chamar o `THROW_LAST` macro dentro de `AND_CATCH_ALL` bloquear o deslocamento de processamento para o próximo quadro de exceção externa. `AND_CATCH_ALL`marca o fim da **CATCH** ou `AND_CATCH_ALL` bloco.  
  
> [!NOTE]
>  O `AND_CATCH_ALL` bloco é definido como um escopo do C++ (delimitado por colchetes). Se você declarar variáveis no escopo, lembre-se de que eles são acessíveis apenas dentro desse escopo.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  
  
##  <a name="end_catch"></a>END_CATCH  
 Marca o fim da última **CATCH** ou `AND_CATCH` bloco.  
  
```   
END_CATCH  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre o `END_CATCH` macro, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  
  
##  <a name="end_catch_all"></a>END_CATCH_ALL  
 Marca o fim da última `CATCH_ALL` ou `AND_CATCH_ALL` bloco.  
  
```   
END_CATCH_ALL  
```  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  
  
##  <a name="throw"></a>THROW (MFC)  
 Lança a exceção especificada.  
  
```   
THROW(exception_object_pointer) 
```  
  
### <a name="parameters"></a>Parâmetros  
 *exception_object_pointer*  
 Aponta para um objeto de exceção derivado de `CException`.  
  
### <a name="remarks"></a>Comentários  
 **LANÇAR** interrupções programar execução, passando o controle associados **CATCH** bloco em seu programa. Se você não forneceu o **CATCH** bloquear e, em seguida, o controle é passado para um módulo de biblioteca Microsoft Foundation Class que imprime um erro de mensagem e será encerrado.  
  
 Para obter mais informações, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  
  
##  <a name="throw_last"></a>THROW_LAST  
 Lança a exceção de volta para o próximo externa **CATCH** bloco.  
  
```   
THROW_LAST()   
```  
  
### <a name="remarks"></a>Comentários  
 Esta macro permite gerar uma exceção localmente criada. Se você tentar lançar uma exceção que você acabou de capturada, ela irá normalmente fora do escopo e ser excluída. Com `THROW_LAST`, a exceção é passada corretamente para o próximo **CATCH** manipulador.  
  
 Para obter mais informações, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CFile::Abort](../../mfc/reference/cfile-class.md#abort).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  
  
##  <a name="afxthrowarchiveexception"></a>AfxThrowArchiveException  
 Gera uma exceção de arquivo morto.  
  
```   
void  AfxThrowArchiveException(int cause, LPCTSTR lpszArchiveName); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `cause`  
 Especifica um número inteiro que indica o motivo da exceção. Para obter uma lista dos valores possíveis, consulte [CArchiveException::m_cause](../../mfc/reference/carchiveexception-class.md#m_cause).  
  
 `lpszArchiveName`  
 Aponta para uma cadeia de caracteres que contém o nome do `CArchive` objeto que causou a exceção (se disponível).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  
  
##  <a name="afxthrowfileexception"></a>AfxThrowFileException  
 Lança uma exceção de arquivo.  
  
```   
void AfxThrowFileException(
    int cause,  
    LONG lOsError = -1,  
    LPCTSTR lpszFileName = NULL); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `cause`  
 Especifica um número inteiro que indica o motivo da exceção. Para obter uma lista dos valores possíveis, consulte [CFileException::m_cause](../../mfc/reference/cfileexception-class.md#m_cause).  
  
 `lOsError`  
 Contém o número do erro do sistema operacional (se disponível) indicando o motivo da exceção. Consulte o manual do sistema operacional para obter uma lista dos códigos de erro.  
  
 `lpszFileName`  
 Aponta para uma cadeia de caracteres que contém o nome do arquivo que causou a exceção (se disponível).  
  
### <a name="remarks"></a>Comentários  
 Você é responsável por determinar a causa com base no código de erro do sistema operacional.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  

## <a name="afxthrowinvalidargexception"></a>AfxThrowInvalidArgException
Gera uma exceção de argumento inválido.  
   
### <a name="syntax"></a>Sintaxe    
```
void AfxThrowInvalidArgException( );  
```  
   
### <a name="remarks"></a>Comentários  
 Esta função é chamada quando os argumentos inválidos são usados.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [Classe CInvalidArgException](cinvalidargexception-class.md)   
 [THROW](#throw)
  
  
##  <a name="afxthrowmemoryexception"></a>AfxThrowMemoryException  
 Lança uma exceção de memória.  
  
```   
void AfxThrowMemoryException(); 
```  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função se chamadas para alocadores de memória de sistema subjacentes (como `malloc` e [GlobalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366574) função do Windows) falhar. Você não precisa chamá-lo para **novo** porque **novo** lançará uma exceção de memória automaticamente se a alocação de memória falhar.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  
  
##  <a name="afxthrownotsupportedexception"></a>AfxThrowNotSupportedException  
 Gera uma exceção que é o resultado de uma solicitação para um recurso sem suporte.  
  
```  
void AfxThrowNotSupportedException(); 
```  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  
  
##  <a name="afxthrowresourceexception"></a>AfxThrowResourceException  
 Lança uma exceção de recurso.  
  
```   
void  AfxThrowResourceException(); 
```  
  
### <a name="remarks"></a>Comentários  
 Essa função normalmente é chamada quando um recurso do Windows não pode ser carregado.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  
  
##  <a name="afxthrowuserexception"></a>AfxThrowUserException  
 Gera uma exceção para interromper uma operação do usuário final.  
  
```   
void AfxThrowUserException(); 
```  
  
### <a name="remarks"></a>Comentários  
 Normalmente, essa função é chamada imediatamente após `AfxMessageBox` relatou um erro para o usuário.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  
  
##  <a name="afxthrowoledispatchexception"></a>AfxThrowOleDispatchException  
 Use esta função para lançar uma exceção em uma função de automação OLE.  
  
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
 `wCode`  
 Um código de erro específico para seu aplicativo.  
  
 `lpszDescription`  
 Descrição textual do erro.  
  
 `nDescriptionID`  
 ID do recurso para a descrição textual do erro.  
  
 `nHelpID`  
 Um contexto de Ajuda do aplicativo (. Arquivo HLP).  
  
### <a name="remarks"></a>Comentários  
 As informações fornecidas para esta função podem ser exibidas por um aplicativo (Microsoft Visual Basic ou outro aplicativo de cliente de automação OLE).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[25 NVC_MFCExceptions](../../mfc/codesnippet/cpp/exception-processing_2.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  
  
##  <a name="afxthrowoleexception"></a>AfxThrowOleException  
 Cria um objeto do tipo `COleException` e lançará uma exceção.  
  
``` 
void AFXAPI AfxThrowOleException(SCODE sc);
void AFXAPI AfxThrowOleException(HRESULT hr); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `sc`  
 Um código de status OLE que indica o motivo da exceção.  
  
 `hr`  
 Identificador para um código de resultado que indica o motivo da exceção.  
  
### <a name="remarks"></a>Comentários  
 A versão que usa um `HRESULT` como um argumento converte esse código de resultado em correspondente `SCODE`. Para obter mais informações sobre `HRESULT` e `SCODE`, consulte [estrutura de códigos de erro COM](http://msdn.microsoft.com/library/windows/desktop/ms690088) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  
  
##  <a name="afxthrowdaoexception"></a>AfxThrowDaoException  
 Chamar essa função para gerar uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md) de seu próprio código.  
  
```   
void AFXAPI AfxThrowDaoException(
    int nAfxDaoError = NO_AFX_DAO_ERROR,  
    SCODE scode = S_OK); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `nAfxDaoError`  
 Um valor inteiro que representa um código de erro estendido de DAO, que pode ser um dos valores listado na [CDaoException::m_nAfxDaoError](../../mfc/reference/cdaoexception-class.md#m_nafxdaoerror).  
  
 *SCODE*  
 Um código de erro OLE do DAO do tipo `SCODE`. Para obter informações, consulte [CDaoException::m_scode](../../mfc/reference/cdaoexception-class.md#m_scode).  
  
### <a name="remarks"></a>Comentários  
 A estrutura também chama `AfxThrowDaoException`. Em sua chamada, você pode passar um dos parâmetros ou ambos. Por exemplo, se você quiser gerar um dos erros definido em **CDaoException::nAfxDaoError** , mas você não se importam o *scode* parâmetro, passar um código válido no `nAfxDaoError` parâmetro e aceitar o valor padrão para *scode*.  
  
 Para obter informações sobre exceções relacionadas às classes DAO MFC, consulte a classe `CDaoException` esse catálogo e o artigo [exceções: exceções de banco de dados](../../mfc/exceptions-database-exceptions.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdb.h  
  
##  <a name="afxthrowdbexception"></a>AfxThrowDBException  
 Chamar essa função para gerar uma exceção do tipo `CDBException` de seu próprio código.  
  
```  
void AfxThrowDBException(
    RETCODE nRetCode,  
    CDatabase* pdb,  
    HSTMT hstmt);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nRetCode`  
 Um valor do tipo **RETCODE**, definindo o tipo de erro que causou a exceção seja lançada.  
  
 `pdb`  
 Um ponteiro para o `CDatabase` objeto que representa a conexão de fonte de dados ao qual a exceção está associada.  
  
 `hstmt`  
 ODBC **HSTMT** identificador que especifica o identificador de instrução ao qual a exceção está associada.  
  
### <a name="remarks"></a>Comentários  
 A estrutura chama `AfxThrowDBException` quando ele recebe um ODBC **RETCODE** de uma chamada para uma API de ODBC de função e interpreta o **RETCODE** como uma condição excepcional em vez de um erro expectable. Por exemplo, uma operação de acesso de dados pode falhar devido a um erro de leitura de disco.  
  
 Para obter informações sobre o **RETCODE** valores definidos por ODBC, consulte o capítulo 8, "Recuperando informações de Status e erro", no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Para obter informações sobre extensões MFC para esses códigos, consulte a classe [CDBException](../../mfc/reference/cdbexception-class.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX  
  
##  <a name="afxabort"></a>AfxAbort  
 A função de encerramento padrão fornecida pelo MFC.  
  
```   
void  AfxAbort(); 
```  
  
### <a name="remarks"></a>Comentários  
 `AfxAbort`é chamado internamente por funções de membro MFC quando há um erro fatal, como uma exceção não identificada que não pode ser manipulada. Você pode chamar `AfxAbort` em casos raros, quando você encontrar um erro catastrófico do qual não é possível recuperar.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CATCH](#catch).  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** AFX   
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)   
 [Classe CException](../../mfc/reference/cexception-class.md)

