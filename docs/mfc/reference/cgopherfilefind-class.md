---
title: Classe CGopherFileFind | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CGopherFileFind
- AFXINET/CGopherFileFind
- AFXINET/CGopherFileFind::CGopherFileFind
- AFXINET/CGopherFileFind::FindFile
- AFXINET/CGopherFileFind::FindNextFile
- AFXINET/CGopherFileFind::GetCreationTime
- AFXINET/CGopherFileFind::GetLastAccessTime
- AFXINET/CGopherFileFind::GetLastWriteTime
- AFXINET/CGopherFileFind::GetLength
- AFXINET/CGopherFileFind::GetLocator
- AFXINET/CGopherFileFind::GetScreenName
- AFXINET/CGopherFileFind::IsDots
dev_langs:
- C++
helpviewer_keywords:
- CGopherFileFind [MFC], CGopherFileFind
- CGopherFileFind [MFC], FindFile
- CGopherFileFind [MFC], FindNextFile
- CGopherFileFind [MFC], GetCreationTime
- CGopherFileFind [MFC], GetLastAccessTime
- CGopherFileFind [MFC], GetLastWriteTime
- CGopherFileFind [MFC], GetLength
- CGopherFileFind [MFC], GetLocator
- CGopherFileFind [MFC], GetScreenName
- CGopherFileFind [MFC], IsDots
ms.assetid: 8465a979-6323-496d-ab4b-e81383fb999d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eae84c647f068e49136968e60bfd8bd51a528112
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37038523"
---
# <a name="cgopherfilefind-class"></a>Classe CGopherFileFind
Recursos em pesquisas de arquivos de Internet de servidores gopher.  
  
> [!NOTE]
>  As classes `CGopherConnection`, `CGopherFile`, `CGopherFileFind`, `CGopherLocator` e seus membros tenham sido substituídos porque eles não funcionam na plataforma Windows XP, mas eles continuarão a funcionar em plataformas anteriores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CGopherFileFind : public CFileFind  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGopherFileFind::CGopherFileFind](#cgopherfilefind)|Constrói um objeto `CGopherFileFind`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGopherFileFind::FindFile](#findfile)|Localiza um arquivo em um servidor gopher.|  
|[CGopherFileFind::FindNextFile](#findnextfile)|Continua uma pesquisa de arquivo de uma chamada anterior para [FindFile](#findfile).|  
|[CGopherFileFind::GetCreationTime](#getcreationtime)|Obtém a hora em que o arquivo especificado foi criado.|  
|[CGopherFileFind::GetLastAccessTime](#getlastaccesstime)|Obtém a hora em que o arquivo especificado foi acessado pela última vez.|  
|[CGopherFileFind::GetLastWriteTime](#getlastwritetime)|Obtém a hora em que o arquivo especificado foi gravado pela última.|  
|[CGopherFileFind::GetLength](#getlength)|Obtém o comprimento do arquivo localizado, em bytes.|  
|[CGopherFileFind::GetLocator](#getlocator)|Obter um `CGopherLocator` objeto.|  
|[CGopherFileFind::GetScreenName](#getscreenname)|Obtém o nome de uma tela de gopher.|  
|[CGopherFileFind::IsDots](#isdots)|Testes para os marcadores de diretório pai e o diretório atuais durante a iteração por meio de arquivos.|  
  
## <a name="remarks"></a>Comentários  
 `CGopherFileFind` inclui funções de membro que iniciar uma pesquisa, localize um arquivo e retornam o URL do arquivo.  
  
 Outras classes MFC projetados para a Internet e o arquivo local pesquisadas incluem [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md) e [CFileFind](../../mfc/reference/cfilefind-class.md). Junto com `CGopherFileFind`, essas classes fornecem um mecanismo perfeito para o usuário localizar arquivos específicos, independentemente do protocolo de servidor, tipo de arquivo ou local (um computador local ou um servidor remoto.) Observe que não há nenhuma classe do MFC para pesquisa em servidores HTTP, como HTTP não oferece suporte a manipulação direta do arquivo exigida pelas pesquisas.  
  
> [!NOTE]
> `CGopherFileFind` não suporta as seguintes funções de membro de sua classe base [CFileFind](../../mfc/reference/cfilefind-class.md):  
  
- [GetRoot](../../mfc/reference/cfilefind-class.md#getroot)  
  
- [GetFileName](../../mfc/reference/cfilefind-class.md#getfilename)  
  
- [GetFilePath](../../mfc/reference/cfilefind-class.md#getfilepath)  
  
- [GetFileTitle](../../mfc/reference/cfilefind-class.md#getfiletitle)  
  
- [GetFileURL](../../mfc/reference/cfilefind-class.md#getfileurl)  
  
 Além disso, quando usado com `CGopherFileFind`, o `CFileFind` função de membro [IsDots](../../mfc/reference/cfilefind-class.md#isdots) é sempre **FALSE**.  
  
 Para obter mais informações sobre como usar `CGopherFileFind` e as outras classes WinInet, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CFileFind](../../mfc/reference/cfilefind-class.md)  
  
 `CGopherFileFind`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxinet.h  
  
##  <a name="cgopherfilefind"></a>  CGopherFileFind::CGopherFileFind  
 Essa função de membro é chamada para construir um `CGopherFileFind` objeto.  
  
```  
explicit CGopherFileFind(
    CGopherConnection* pConnection,  
    DWORD_PTR dwContext = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pConnection*  
 Um ponteiro para um [CGopherConnection](../../mfc/reference/cgopherconnection-class.md) objeto.  
  
 *dwContext*  
 O identificador de contexto para a operação. Consulte **comentários** para obter mais informações sobre *dwContext*.  
  
### <a name="remarks"></a>Comentários  
 O valor padrão para *dwContext* é enviada pelo MFC para o `CGopherFileFind` de objeto o [CInternetSession](../../mfc/reference/cinternetsession-class.md) do objeto que criou o `CGopherFileFind` objeto. Quando você cria um `CGopherFileFind` do objeto, você pode substituir o padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status do objeto ao qual ela é identificada. Consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.  
  
##  <a name="findfile"></a>  CGopherFileFind::FindFile  
 Chame essa função de membro para localizar um arquivo gopher.  
  
```  
virtual BOOL FindFile(
    CGopherLocator& refLocator,  
    LPCTSTR pstrString,  
    DWORD dwFlags = INTERNET_FLAG_RELOAD);

 
virtual BOOL FindFile(
    LPCTSTR pstrString,  
    DWORD dwFlags = INTERNET_FLAG_RELOAD);
```  
  
### <a name="parameters"></a>Parâmetros  
 *refLocator*  
 Uma referência a um [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) objeto.  
  
 *pstrString*  
 Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo.  
  
 *dwFlags*  
 Os sinalizadores que descrevem como lidar com essa sessão. Os sinalizadores válidos são:  
  
-   INTERNET_FLAG_RELOAD obter os dados do servidor remoto, mesmo se ela está armazenada em cache localmente.  
  
-   INTERNET_FLAG_DONT_CACHE não armazenar em cache os dados, localmente ou em todos os gateways.  
  
-   Solicitar INTERNET_FLAG_SECURE transações seguras na conexão com Secure Sockets Layer ou PCT. Esse sinalizador é aplicável somente a solicitações HTTP.  
  
-   INTERNET_FLAG_USE_EXISTING se possível, reutilizar as conexões existentes com o servidor para o novo **FindFile** solicitações, em vez de criar uma nova sessão para cada solicitação.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Para obter mais informações sobre o erro, chame a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar **FindFile** para recuperar o primeiro objeto gopher, você pode chamar [FindNextFile](#findnextfile) para recuperar arquivos gopher subsequentes.  
  
##  <a name="findnextfile"></a>  CGopherFileFind::FindNextFile  
 Chamar essa função de membro para continuar uma pesquisa de arquivo iniciada com uma chamada para [CGopherFileFind::FindFile](#findfile).  
  
```  
virtual BOOL FindNextFile();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se houver mais arquivos; zero se o arquivo encontrado é o último no diretório ou se ocorreu um erro. Para obter mais informações sobre o erro, chame a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360). Se o arquivo encontrado é o último arquivo no diretório, ou se nenhuma correspondência de arquivos podem ser encontrados, o `GetLastError` função retorna ERROR_NO_MORE_FILES.  
  
##  <a name="getcreationtime"></a>  CGopherFileFind::GetCreationTime  
 Obtém a hora de criação para o arquivo atual.  
  
```  
virtual BOOL GetCreationTime(FILETIME* pTimeStamp) const;  
virtual BOOL GetCreationTime(CTime& refTime) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pTimeStamp*  
 Um ponteiro para um [FILETIME](http://msdn.microsoft.com/library/windows/desktop/ms724284) estrutura que contém a hora em que o arquivo foi criado.  
  
 *refTime*  
 Uma referência a um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; 0 se não houver êxito. `GetCreationTime` Retorna 0 somente se [FindNextFile](#findnextfile) nunca foi chamado neste `CGopherFileFind` objeto.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `GetCreationTime`.  
  
> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por essa função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de data / hora, se o sistema de arquivos subjacente ou o servidor não der suporte a manter o atributo de tempo. Consulte o [Win32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura para obter informações sobre formatos de hora. Em alguns sistemas operacionais, a hora retornada está na hora local da zona para a máquina foi o arquivo está localizado. Consulte o Win32 [FileTimeToLocalFileTime](http://msdn.microsoft.com/library/windows/desktop/ms724277) API para obter mais informações.  
  
##  <a name="getlastaccesstime"></a>  CGopherFileFind::GetLastAccessTime  
 Obtém a hora em que o arquivo especificado foi acessado pela última vez.  
  
```  
virtual BOOL GetLastAccessTime(CTime& refTime) const;  
virtual BOOL GetLastAccessTime(FILETIME* pTimeStamp) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *refTime*  
 Uma referência a um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto.  
  
 *pTimeStamp*  
 Um ponteiro para um [FILETIME](http://msdn.microsoft.com/library/windows/desktop/ms724284) estrutura que contém a hora em que o arquivo foi acessado pela última vez.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; 0 se não houver êxito. `GetLastAccessTime` Retorna 0 somente se [FindNextFile](#findnextfile) nunca foi chamado neste `CGopherFileFind` objeto.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `GetLastAccessTime`.  
  
> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por essa função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de data / hora, se o sistema de arquivos subjacente ou o servidor não der suporte a manter o atributo de tempo. Consulte o [Win32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura para obter informações sobre formatos de hora. Em alguns sistemas operacionais, a hora retornada está na hora local da zona para a máquina foi o arquivo está localizado. Consulte o Win32 [FileTimeToLocalFileTime](http://msdn.microsoft.com/library/windows/desktop/ms724277) API para obter mais informações.  
  
##  <a name="getlastwritetime"></a>  CGopherFileFind::GetLastWriteTime  
 Obtém a última vez em que o arquivo foi alterado.  
  
```  
virtual BOOL GetLastWriteTime(FILETIME* pTimeStamp) const;  
virtual BOOL GetLastWriteTime(CTime& refTime) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pTimeStamp*  
 Um ponteiro para um [FILETIME](http://msdn.microsoft.com/library/windows/desktop/ms724284) estrutura que contém a hora em que o arquivo foi gravado pela última.  
  
 *refTime*  
 Uma referência a um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; 0 se não houver êxito. `GetLastWriteTime` Retorna 0 somente se [FindNextFile](#findnextfile) nunca foi chamado neste `CGopherFileFind` objeto.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `GetLastWriteTime`.  
  
> [!NOTE]
>  Nem todos os sistemas de arquivos usam a mesma semântica para implementar o carimbo de hora retornado por essa função. Esta função pode retornar o mesmo valor retornado por outras funções de carimbo de data / hora, se o sistema de arquivos subjacente ou o servidor não der suporte a manter o atributo de tempo. Consulte o [Win32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) estrutura para obter informações sobre formatos de hora. Em alguns sistemas operacionais, a hora retornada está na hora local da zona para a máquina foi o arquivo está localizado. Consulte o Win32 [FileTimeToLocalFileTime](http://msdn.microsoft.com/library/windows/desktop/ms724277) API para obter mais informações.  
  
##  <a name="getlength"></a>  CGopherFileFind::GetLength  
 Chame essa função de membro para obter o comprimento, em bytes, do arquivo localizado.  
  
```  
virtual ULONGLONG GetLength() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento, em bytes, do arquivo localizado.  
  
### <a name="remarks"></a>Comentários  
 `GetLength` usa a estrutura de Win32 [WIN32_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa365740) para obter o valor do tamanho do arquivo em bytes.  
  
> [!NOTE]
>  A partir de MFC 7.0 `GetLength` dá suporte a tipos de inteiro de 64 bits. Código anteriormente existentes criado com esta versão mais recente da biblioteca pode resultar em avisos de truncamento.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFile::GetLength](../../mfc/reference/cfile-class.md#getlength) (a implementação da classe base).  
  
##  <a name="getlocator"></a>  CGopherFileFind::GetLocator  
 Chamar essa função de membro para obter o [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) o objeto [FindFile](#findfile) usa para localizar o arquivo gopher.  
  
```  
CGopherLocator GetLocator() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto `CGopherLocator`.  
  
##  <a name="getscreenname"></a>  CGopherFileFind::GetScreenName  
 Chame essa função de membro para obter o nome da tela gopher.  
  
```  
CString GetScreenName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome da tela gopher.  
  
##  <a name="isdots"></a>  CGopherFileFind::IsDots  
 Testes para os marcadores de diretório pai e o diretório atuais durante a iteração por meio de arquivos.  
  
```  
virtual BOOL IsDots() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o arquivo encontrado com o nome "."ou"...", que indica que o arquivo encontrado é, na verdade, um diretório. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [FindNextFile](#findnextfile) pelo menos uma vez antes de chamar `IsDots`.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CFileFind](../../mfc/reference/cfilefind-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFtpFileFind](../../mfc/reference/cftpfilefind-class.md)   
 [Classe CFileFind](../../mfc/reference/cfilefind-class.md)   
 [Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)   
 [Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)   
 [Classe CHttpFile](../../mfc/reference/chttpfile-class.md)
