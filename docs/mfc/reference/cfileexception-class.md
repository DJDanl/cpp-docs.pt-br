---
title: Classe CFileException | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CFile class, exceptions of
- exceptions, file type
- CFileException class
ms.assetid: f6491bb9-bfbc-42fd-a952-b33f9b62323f
caps.latest.revision: 20
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: d9064ae66f0dcd0e9f0dce0eedd8e38353f9da06
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFileException::ErrnoToException](#errnotoexception)|Retorna fazer com que o código correspondente a um número de erro de tempo de execução.|  
|[CFileException::GetErrorMessage](#geterrormessage)|Recupera a mensagem que descreve uma exceção.|  
|[CFileException::OsErrorToException](#oserrortoexception)|Retorna um código de causa correspondente a um código de erro do sistema operacional.|  
|[CFileException::ThrowErrno](#throwerrno)|Lança uma exceção de arquivo com base em um número de erro de tempo de execução.|  
|[CFileException::ThrowOsError](#throwoserror)|Lança uma exceção de arquivo com base em um número de erro do sistema operacional.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFileException::m_cause](#m_cause)|Contém código portátil correspondente a causa da exceção.|  
|[CFileException::m_lOsError](#m_loserror)|Contém o número de erro do sistema operacional relacionado.|  
|[CFileException::m_strFileName](#m_strfilename)|Contém o nome do arquivo para essa exceção.|  
  
## <a name="remarks"></a>Comentários  
 O `CFileException` classe inclui membros de dados pública que mantêm o código causa portátil e o número do erro específicos do sistema operacional. A classe também fornece funções de membro estático para lançar exceções de arquivo e retornando códigos de causa de erros de sistema operacional e erros de tempo de execução C.  
  
 `CFileException`objetos são construídos e lançados em `CFile` funções de membro e nas funções de membro de classes derivadas. Você pode acessar esses objetos dentro do escopo de um **CATCH** expressão. Para fins de portabilidade, use somente o código causa para obter o motivo de uma exceção. Para obter mais informações sobre exceções, consulte o artigo [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `CFileException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX. h  
  
##  <a name="cfileexception"></a>CFileException::CFileException  
 Constrói uma `CFileException` objeto que armazena o código de causa e o código de sistema operacional no objeto.  
  
```  
CFileException(
    int cause = CFileException::none,  
    LONG lOsError = -1,  
    LPCTSTR lpszArchiveName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cause`  
 Uma variável do tipo enumerado que indica o motivo da exceção. Consulte [CFileException::m_cause](#m_cause) para obter uma lista dos possíveis valores.  
  
 `lOsError`  
 Um motivo específicos do sistema operacional para a exceção, se disponível. O `lOsError` parâmetro fornece mais informações que `cause` does.  
  
 `lpszArchiveName`  
 Aponta para uma cadeia de caracteres que contém o nome do `CFile` objeto que causou a exceção.  
  
### <a name="remarks"></a>Comentários  
 Não use esse construtor diretamente, mas em vez disso, chame a função global [AfxThrowFileException](exception-processing.md#afxthrowfileexception).  
  
> [!NOTE]
>  A variável `lOsError` se aplica somente ao `CFile` e `CStdioFile` objetos. O `CMemFile` classe não lida com esse código de erro.  
  
##  <a name="errnotoexception"></a>CFileException::ErrnoToException  
 Converte um valor de erro de determinada biblioteca de tempo de execução em um `CFileException` erro valor enumerado.  
  
```  
static int PASCAL ErrnoToException(int nErrno);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nErrno`  
 Um código de erro inteiro conforme definido no arquivo de inclusão de tempo de execução ERRNO. H.  
  
### <a name="return-value"></a>Valor de retorno  
 Valor enumerado que corresponde a um valor de erro de determinada biblioteca de tempo de execução.  
  
### <a name="remarks"></a>Comentários  
 Consulte [CFileException::m_cause](#m_cause) para obter uma lista dos possíveis valores enumerados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCFiles&#26;](../../atl-mfc-shared/reference/codesnippet/cpp/cfileexception-class_1.cpp)]  
  
##  <a name="geterrormessage"></a>CFileException::GetErrorMessage  
 Recupera o texto que descreve uma exceção.  
  
```  
virtual BOOL GetErrorMessage(
    LPTSTR lpszError,  
    UINT nMaxError,  
    PUINT pnHelpContext = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in, out] `lpszError`  
 Ponteiro para um buffer que recebe uma mensagem de erro.  
  
 [in] `nMaxError`  
 O número máximo de caracteres que pode conter o buffer especificado. Isso inclui o caractere de terminação nula.  
  
 [in, out] `pnHelpContext`  
 Ponteiro para um inteiro sem sinal que recebe a ID do contexto de Ajuda. Se `NULL`, nenhuma ID é retornada.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método teve êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Se o buffer especificado é muito pequeno, a mensagem de erro será truncada.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa `CFileException::GetErrorMessage`.  
  
 [!code-cpp[NVC_MFCExceptions&#22;](../../mfc/codesnippet/cpp/cfileexception-class_2.cpp)]  
  
##  <a name="m_cause"></a>CFileException::m_cause  
 Contém valores definidos por um tipo enumerado de `CFileException`.  
  
```  
int m_cause;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse membro de dados é uma variável pública do tipo `int`. Os enumeradores e seus significados são os seguintes:  
  
- `CFileException::none`0: não ocorreu nenhum erro.  
  
- `CFileException::genericException`1: Ocorreu um erro não especificado.  
  
- `CFileException::fileNotFound`2: o arquivo não pôde ser localizado.  
  
- `CFileException::badPath`3: todo ou parte do caminho é inválido.  
  
- `CFileException::tooManyOpenFiles`4: o número permitido de arquivos abertos foi excedido.  
  
- `CFileException::accessDenied`5: o arquivo não pôde ser acessado.  
  
- `CFileException::invalidFile`6: Houve uma tentativa de usar um identificador de arquivo inválido.  
  
- `CFileException::removeCurrentDir`7: o diretório de trabalho atual não pode ser removido.  
  
- `CFileException::directoryFull`8: não existem mais entradas de diretório.  
  
- `CFileException::badSeek`9: Ocorreu um erro ao tentar definir o ponteiro do arquivo.  
  
- `CFileException::hardIO`10: Ocorreu um erro de hardware.  
  
- `CFileException::sharingViolation`11: SHARE. EXE não foi carregado ou uma região compartilhada estava bloqueada.  
  
- `CFileException::lockViolation`12: Houve uma tentativa de bloquear uma região que já estava bloqueada.  
  
- `CFileException::diskFull`14: o disco está cheio.  
  
- `CFileException::endOfFile`15: o final do arquivo foi atingido.  
  
    > [!NOTE]
    >  Esses enumeradores de causa de `CFileException` são diferentes dos enumeradores de causa de `CArchiveException`.  
  
    > [!NOTE]
    > O `CArchiveException::generic` foi preterido. Use `genericException` em seu lugar. Se `generic` for usado em um aplicativo e compilado com /clr, os erros de sintaxe resultantes não serão fáceis de decifrar.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[30 NVC_MFCFiles](../../atl-mfc-shared/reference/codesnippet/cpp/cfileexception-class_3.cpp)]  
  
##  <a name="m_loserror"></a>CFileException::m_lOsError  
 Contém o código de erro do sistema operacional para essa exceção.  
  
```  
LONG m_lOsError;  
```  
  
### <a name="remarks"></a>Comentários  
 Consulte o manual técnico do sistema operacional para obter uma lista dos códigos de erro. Este membro de dados é uma variável pública do tipo **longo**.  
  
##  <a name="m_strfilename"></a>CFileException::m_strFileName  
 Contém o nome do arquivo para essa condição de exceção.  
  
```  
CString m_strFileName;  
```  
  
##  <a name="oserrortoexception"></a>CFileException::OsErrorToException  
 Retorna um enumerador que corresponde a um determinado `lOsError` valor. Se o código de erro é desconhecido, a função retorna **CFileException::generic**.  
  
```  
static int PASCAL OsErrorToException(LONG lOsError);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lOsError`  
 Um código de erro específicos do sistema operacional.  
  
### <a name="return-value"></a>Valor de retorno  
 Valor enumerado que corresponde ao valor de um determinado erro do sistema operacional.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCFiles&#27;](../../atl-mfc-shared/reference/codesnippet/cpp/cfileexception-class_4.cpp)]  
  
##  <a name="throwerrno"></a>CFileException::ThrowErrno  
 Constrói uma `CFileException` objeto correspondente a um determinado `nErrno` valor e, em seguida, lança a exceção.  
  
```  
static void PASCAL ThrowErrno(int nErrno, LPCTSTR lpszFileName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nErrno`  
 Um código de erro inteiro conforme definido no arquivo de inclusão de tempo de execução ERRNO. H.  
  
 `lpszFileName`  
 Um ponteiro para a cadeia de caracteres que contém o nome do arquivo que causou a exceção, se disponível.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCFiles&#28;](../../atl-mfc-shared/reference/codesnippet/cpp/cfileexception-class_5.cpp)]  
  
##  <a name="throwoserror"></a>CFileException::ThrowOsError  
 Lança um `CFileException` correspondente para um determinado `lOsError` valor. Se o código de erro é desconhecido, a função gera uma exceção codificada como **CFileException::generic**.  
  
```  
static void PASCAL ThrowOsError(LONG lOsError, LPCTSTR lpszFileName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lOsError`  
 Um código de erro específicos do sistema operacional.  
  
 `lpszFileName`  
 Um ponteiro para a cadeia de caracteres que contém o nome do arquivo que causou a exceção, se disponível.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[29 NVC_MFCFiles](../../atl-mfc-shared/reference/codesnippet/cpp/cfileexception-class_6.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe CException](../../mfc/reference/cexception-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Processamento de exceção](../../mfc/reference/exception-processing.md)




