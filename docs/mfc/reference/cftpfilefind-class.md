---
title: Classe CFtpFileFind | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CFtpFileFind
- AFXINET/CFtpFileFind
- AFXINET/CFtpFileFind::CFtpFileFind
- AFXINET/CFtpFileFind::FindFile
- AFXINET/CFtpFileFind::FindNextFile
- AFXINET/CFtpFileFind::GetFileURL
dev_langs:
- C++
helpviewer_keywords:
- CFtpFileFind [MFC], CFtpFileFind
- CFtpFileFind [MFC], FindFile
- CFtpFileFind [MFC], FindNextFile
- CFtpFileFind [MFC], GetFileURL
ms.assetid: 9667cf01-657f-4b11-b9db-f11e5a7b4e4c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6b8cf828ab0373c3bd09d22af5f2ced702cc68aa
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37336013"
---
# <a name="cftpfilefind-class"></a>Classe CFtpFileFind
Auxílios em pesquisas de arquivos de Internet de servidores FTP.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CFtpFileFind : public CFileFind  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFtpFileFind::CFtpFileFind](#cftpfilefind)|Constrói um objeto `CFtpFileFind`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFtpFileFind::FindFile](#findfile)|Localiza um arquivo em um servidor FTP.|  
|[CFtpFileFind::FindNextFile](#findnextfile)|Continua uma pesquisa de arquivo de uma chamada anterior a [FindFile](#findfile).|  
|[CFtpFileFind::GetFileURL](#getfileurl)|Obtém a URL, incluindo o caminho do arquivo encontrado.|  
  
## <a name="remarks"></a>Comentários  
 `CFtpFileFind` inclui funções de membro que iniciar uma pesquisa, localize um arquivo e retornam a URL ou outras informações descritivas sobre o arquivo.  
  
 Outras classes do MFC projetados para a Internet e o arquivo local pesquisadas incluem [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md) e [CFileFind](../../mfc/reference/cfilefind-class.md). Junto com `CFtpFileFind`, essas classes fornecem um mecanismo perfeito para o cliente encontre arquivos específicos, independentemente do servidor de protocolo ou tipo de arquivo (um computador local ou um servidor remoto). Observe que não há nenhuma classe do MFC para pesquisa em servidores HTTP, como HTTP não dá suporte a manipulação direta do arquivo necessária para pesquisas.  
  
 Para obter mais informações sobre como usar `CFtpFileFind` e as outras classes WinInet, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
## <a name="example"></a>Exemplo  
 O código a seguir demonstra como enumerar todos os arquivos no diretório atual do servidor FTP.  
  
 [!code-cpp[NVC_MFCWinInet#8](../../mfc/codesnippet/cpp/cftpfilefind-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CFileFind](../../mfc/reference/cfilefind-class.md)  
  
 `CFtpFileFind`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxinet.h  
  
##  <a name="cftpfilefind"></a>  CFtpFileFind::CFtpFileFind  
 Essa função membro é chamada para construir um `CFtpFileFind` objeto.  
  
```  
explicit CFtpFileFind(
    CFtpConnection* pConnection,  
    DWORD_PTR dwContext = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pConnection*  
 Um ponteiro para um `CFtpConnection` objeto. Você pode obter uma conexão de FTP chamando [CInternetSession::GetFtpConnection](../../mfc/reference/cinternetsession-class.md#getftpconnection).  
  
 *dwContext*  
 O identificador de contexto para o `CFtpFileFind` objeto. Ver **comentários** para obter mais informações sobre esse parâmetro.  
  
### <a name="remarks"></a>Comentários  
 O valor padrão para *dwContext* é enviado pelo MFC para o `CFtpFileFind` objeto o [CInternetSession](../../mfc/reference/cinternetsession-class.md) do objeto que criou o `CFtpFileFind` objeto. Você pode substituir o padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status no objeto com a qual ela é identificada. Consulte o artigo [primeiras etapas de Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo na visão geral de classe no início deste tópico.  
  
##  <a name="findfile"></a>  CFtpFileFind::FindFile  
 Chame essa função de membro para localizar um arquivo FTP.  
  
```  
virtual BOOL FindFile(
    LPCTSTR pstrName = NULL,  
    DWORD dwFlags = INTERNET_FLAG_RELOAD);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pstrName*  
 Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo para localizar. Se for NULL, a chamada executará uma pesquisa de curinga (*).  
  
 *dwFlags*  
 Os sinalizadores que descrevem como lidar com esta sessão. Esses sinalizadores podem ser combinados com o operador OR bit a bit (&#124;) e são da seguinte maneira:  
  
-   INTERNET_FLAG_RELOAD obter os dados de transmissão, mesmo se ela é armazenada em cache localmente. Isso é o sinalizador de padrão.  
  
-   INTERNET_FLAG_DONT_CACHE não armazenar em cache os dados, localmente ou em todos os gateways.  
  
-   INTERNET_FLAG_RAW_DATA substituir o padrão para retornar os dados brutos ( [WIN32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estruturas para FTP).  
  
-   INTERNET_FLAG_SECURE protege transações durante a transmissão com Secure Sockets Layer ou PCT. Esse sinalizador é aplicável somente a solicitações HTTP.  
  
-   INTERNET_FLAG_EXISTING_CONNECT se possível, reutilize as conexões existentes para o servidor para o novo `FindFile` solicitações em vez de criar uma nova sessão para cada solicitação.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0. Para obter outras informações de erro, chame a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar `FindFile` para recuperar o primeiro arquivo FTP, você pode chamar [FindNextFile](#findnextfile) para recuperar os arquivos subsequentes de FTP.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo anterior neste tópico.  
  
##  <a name="findnextfile"></a>  CFtpFileFind::FindNextFile  
 Chame essa função de membro para continuar uma pesquisa de arquivo iniciada com uma chamada para o [FindFile](#findfile) função de membro.  
  
```  
virtual BOOL FindNextFile();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se não houver mais arquivos; zero se o arquivo encontrado é o último no diretório ou se ocorreu um erro. Para obter outras informações de erro, chame a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360). Se o arquivo encontrado é o último arquivo no diretório, ou se nenhuma correspondência de arquivos podem ser encontrados, o `GetLastError` função retorna ERROR_NO_MORE_FILES.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar essa função pelo menos uma vez antes de chamar qualquer função de atributo (consulte [CFileFind::FindNextFile](../../mfc/reference/cfilefind-class.md#findnextfile)).  
  
 `FindNextFile` encapsula a função Win32 [FindNextFile](http://msdn.microsoft.com/library/windows/desktop/aa364428).  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo neste tópico.  
  
##  <a name="getfileurl"></a>  CFtpFileFind::GetFileURL  
 Chame essa função de membro para obter a URL do arquivo especificado.  
  
```  
CString GetFileURL() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O arquivo e caminho do localizador de recurso Universal (URL).  
  
### <a name="remarks"></a>Comentários  
 `GetFileURL` é semelhante à função de membro [CFileFind::GetFilePath](../../mfc/reference/cfilefind-class.md#getfilepath), exceto que ele retorna a URL na forma `ftp://moose/dir/file.txt`.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CFileFind](../../mfc/reference/cfilefind-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)   
 [Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)   
 [Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)   
 [Classe CHttpFile](../../mfc/reference/chttpfile-class.md)
