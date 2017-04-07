---
title: Classe CFtpFileFind | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
- CFtpFileFind class
- file searches [C++]
ms.assetid: 9667cf01-657f-4b11-b9db-f11e5a7b4e4c
caps.latest.revision: 23
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 6e84282cc2f22e813ea44318d497c7e32e3280d8
ms.lasthandoff: 02/25/2017

---
# <a name="cftpfilefind-class"></a>Classe CFtpFileFind
Ajuda a pesquisas de arquivos de Internet de servidores FTP.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CFtpFileFind : public CFileFind  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
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
 `CFtpFileFind`inclui funções de membro que iniciar uma pesquisa, localize um arquivo e retornam a URL ou outras informações descritivas sobre o arquivo.  
  
 Outras classes MFC projetados para a Internet e o arquivo local pesquisadas incluem [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md) e [CFileFind](../../mfc/reference/cfilefind-class.md). Junto com `CFtpFileFind`, essas classes fornecem um mecanismo uniforme para o cliente localizar arquivos específicos, independentemente do servidor de protocolo ou tipo de arquivo (um computador local ou um servidor remoto). Observe que não há nenhuma classe do MFC para pesquisa em servidores HTTP, como HTTP não oferece suporte a manipulação direta do arquivo necessária para pesquisas.  
  
 Para obter mais informações sobre como usar `CFtpFileFind` e de outras classes WinInet, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
## <a name="example"></a>Exemplo  
 O código a seguir demonstra como enumerar todos os arquivos no diretório atual do servidor FTP.  
  
 [!code-cpp[NVC_MFCWinInet n º&8;](../../mfc/codesnippet/cpp/cftpfilefind-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CFileFind](../../mfc/reference/cfilefind-class.md)  
  
 `CFtpFileFind`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxinet.h  
  
##  <a name="cftpfilefind"></a>CFtpFileFind::CFtpFileFind  
 Essa função de membro é chamada para construir uma `CFtpFileFind` objeto.  
  
```  
explicit CFtpFileFind(
    CFtpConnection* pConnection,  
    DWORD_PTR dwContext = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pConnection`  
 Um ponteiro para um `CFtpConnection` objeto. Você pode obter uma conexão FTP chamando [CInternetSession::GetFtpConnection](../../mfc/reference/cinternetsession-class.md#getftpconnection).  
  
 `dwContext`  
 O identificador de contexto para o `CFtpFileFind` objeto. Consulte **comentários** para obter mais informações sobre esse parâmetro.  
  
### <a name="remarks"></a>Comentários  
 O valor padrão para `dwContext` é enviada pelo MFC para o `CFtpFileFind` de objeto o [CInternetSession](../../mfc/reference/cinternetsession-class.md) do objeto que criou o `CFtpFileFind` objeto. Você pode substituir o padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status no objeto ao qual ela é identificada. Consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo na visão geral de classe neste tópico.  
  
##  <a name="findfile"></a>CFtpFileFind::FindFile  
 Chame essa função de membro para localizar um arquivo FTP.  
  
```  
virtual BOOL FindFile(
    LPCTSTR pstrName = NULL,  
    DWORD dwFlags = INTERNET_FLAG_RELOAD);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo para localizar. Se **nulo**, a chamada executará uma pesquisa de curinga (*).  
  
 `dwFlags`  
 Os sinalizadores que descrevem como lidar com essa sessão. Esses sinalizadores podem ser combinados com o operador OR bit a bit (|) e são da seguinte maneira:  
  
-   INTERNET_FLAG_RELOAD obter os dados de conexão mesmo se ela é armazenada em cache localmente. Esse é o padrão.  
  
-   INTERNET_FLAG_DONT_CACHE não armazenar em cache os dados localmente ou em todos os gateways.  
  
-   INTERNET_FLAG_RAW_DATA substituir o padrão para retornar os dados brutos ( [WIN32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estruturas para FTP).  
  
-   INTERNET_FLAG_SECURE protege transações durante a transmissão com Secure Sockets Layer ou PERC Esse sinalizador é aplicável apenas a solicitações HTTP.  
  
-   INTERNET_FLAG_EXISTING_CONNECT se possível, reutilizar as conexões existentes para o servidor para novos **FindFile** solicitações em vez de criar uma nova sessão para cada solicitação.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Para obter mais informações sobre o erro, chame a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar **FindFile** para recuperar o primeiro arquivo FTP, você pode chamar [FindNextFile](#findnextfile) para recuperar os arquivos subsequentes de FTP.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo anterior neste tópico.  
  
##  <a name="findnextfile"></a>CFtpFileFind::FindNextFile  
 Chame essa função de membro para continuar uma pesquisa de arquivo iniciada por uma chamada para o [FindFile](#findfile) função de membro.  
  
```  
virtual BOOL FindNextFile();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se houver mais arquivos; zero se o arquivo encontrado é o último no diretório ou se ocorreu um erro. Para obter mais informações sobre o erro, chame a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360). Se o arquivo encontrado é o último arquivo no diretório ou se nenhuma correspondência de arquivos podem ser encontrados, o `GetLastError` função retorna ERROR_NO_MORE_FILES.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar essa função pelo menos uma vez antes de chamar qualquer função de atributo (consulte [CFileFind::FindNextFile](../../mfc/reference/cfilefind-class.md#findnextfile)).  
  
 `FindNextFile`encapsula a função Win32 [FindNextFile](http://msdn.microsoft.com/library/windows/desktop/aa364428).  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo neste tópico.  
  
##  <a name="getfileurl"></a>CFtpFileFind::GetFileURL  
 Chame essa função de membro para obter a URL do arquivo especificado.  
  
```  
CString GetFileURL() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O arquivo e o caminho do localizador de recursos Universal (URL).  
  
### <a name="remarks"></a>Comentários  
 `GetFileURL`é semelhante à função de membro [CFileFind::GetFilePath](../../mfc/reference/cfilefind-class.md#getfilepath), exceto que ela retorna a URL na forma `ftp://moose/dir/file.txt`.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CFileFind](../../mfc/reference/cfilefind-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)   
 [Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)   
 [Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)   
 [Classe CHttpFile](../../mfc/reference/chttpfile-class.md)

