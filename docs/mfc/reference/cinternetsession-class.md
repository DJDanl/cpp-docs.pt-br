---
title: Classe CInternetSession | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CInternetSession
- AFXINET/CInternetSession
- AFXINET/CInternetSession::CInternetSession
- AFXINET/CInternetSession::Close
- AFXINET/CInternetSession::EnableStatusCallback
- AFXINET/CInternetSession::GetContext
- AFXINET/CInternetSession::GetCookie
- AFXINET/CInternetSession::GetCookieLength
- AFXINET/CInternetSession::GetFtpConnection
- AFXINET/CInternetSession::GetGopherConnection
- AFXINET/CInternetSession::GetHttpConnection
- AFXINET/CInternetSession::OnStatusCallback
- AFXINET/CInternetSession::OpenURL
- AFXINET/CInternetSession::SetCookie
- AFXINET/CInternetSession::SetOption
dev_langs:
- C++
helpviewer_keywords:
- CInternetSession class
- Internet sessions
ms.assetid: ef54feb4-9d0f-4e65-a45d-7a4cf6c40e51
caps.latest.revision: 25
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
ms.openlocfilehash: caec3ae416dc82d49fc0051f0d9d1d2e021e0ba5
ms.lasthandoff: 02/25/2017

---
# <a name="cinternetsession-class"></a>Classe CInternetSession
Cria e inicializa uma única ou várias sessões simultâneas de Internet e, se necessário, descreve a conexão a um servidor proxy.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CInternetSession : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInternetSession::CInternetSession](#cinternetsession)|Constrói um objeto `CInternetSession`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInternetSession::Close](#close)|Fecha a conexão de Internet quando a sessão da Internet é finalizado.|  
|[CInternetSession::EnableStatusCallback](#enablestatuscallback)|Estabelece uma rotina de retorno de chamada de status.|  
|[CInternetSession::GetContext](#getcontext)|Fecha a conexão de Internet quando a sessão da Internet é finalizado.|  
|[CInternetSession::GetCookie](#getcookie)|Retorna os cookies para a URL especificada e todos os seus pais URLs.|  
|[CInternetSession::GetCookieLength](#getcookielength)|Recupera a variável especificando o comprimento do cookie armazenado no buffer.|  
|[CInternetSession::GetFtpConnection](#getftpconnection)|Abre uma sessão FTP com um servidor. Logon do usuário.|  
|[CInternetSession::GetGopherConnection](#getgopherconnection)|Abre um servidor gopher para um aplicativo que está tentando abrir uma conexão.|  
|[CInternetSession::GetHttpConnection](#gethttpconnection)|Abre um servidor HTTP para um aplicativo que está tentando abrir uma conexão.|  
|[CInternetSession::OnStatusCallback](#onstatuscallback)|Atualiza o status de uma operação quando o retorno de chamada de status está habilitado.|  
|[CInternetSession::OpenURL](#openurl)|Analisa e abre uma URL.|  
|[CInternetSession::SetCookie](#setcookie)|Define um cookie para a URL especificada.|  
|[CInternetSession::SetOption](#setoption)|Define as opções para a sessão de Internet.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInternetSession::operator HINTERNET](#operator_hinternet)|Um identificador para a sessão atual da Internet.|  
  
## <a name="remarks"></a>Comentários  
 Se sua conexão de Internet deve ser mantido para a duração de um aplicativo, você pode criar um `CInternetSession` membro da classe [CWinApp](../../mfc/reference/cwinapp-class.md).  
  
 Depois de ter estabelecido uma sessão da Internet, você pode chamar [OpenURL](#openurl). `CInternetSession`em seguida, analisa o URL para você, chamando a função global [AfxParseURL](http://msdn.microsoft.com/library/505c717e-aa52-4106-8522-eedff3d9bbae). Independentemente do seu tipo de protocolo, `CInternetSession` interpreta a URL e gerenciá-la para você. Ele pode manipular solicitações para arquivos locais identificados com o recurso de URL "file://". `OpenURL`Retorna um ponteiro para um [CStdioFile](../../mfc/reference/cstdiofile-class.md) se o nome que você a passar de objeto é um arquivo local.  
  
 Se você abrir uma URL em um servidor de Internet usando `OpenURL`, você pode ler informações do site. Se você quiser executar ações específicas do serviço (por exemplo, HTTP, FTP ou gopher) localizados em um servidor de arquivos, você deve estabelecer a conexão apropriada com o servidor. Para abrir um determinado tipo de conexão diretamente para um serviço específico, use uma das seguintes funções de membro:  
  
- [GetGopherConnection](#getgopherconnection) para abrir uma conexão a um serviço gopher.  
  
- [GetHttpConnection](#gethttpconnection) para abrir uma conexão para um serviço HTTP.  
  
- [GetFtpConnection](#getftpconnection) para abrir uma conexão com um serviço de FTP.  
  
 [SetOption](#setoption) permite que você defina as opções de consulta de sua sessão, como valores de tempo limite, o número de repetições e assim por diante.  
  
 `CInternetSession`funções de membro [SetCookie](#setcookie), [GetCookie](#getcookie), e [GetCookieLength](#getcookielength) fornecem os meios para gerenciar um banco de dados de cookie do Win32, por meio dos quais servidores e scripts mantêm informações de estado sobre a estação de trabalho cliente.  
  
 Para obter mais informações sobre tarefas básicas de programação da Internet, consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md). Para obter informações gerais sobre como usar as classes WinInet MFC, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
> [!NOTE]
> `CInternetSession`lança um [AfxThrowNotSupportedException](exception-processing.md#afxthrownotsupportedexception) para tipos de serviço sem suporte. Somente os seguintes tipos de serviço são suportados atualmente: HTTP, FTP, gopher e arquivo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CInternetSession`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxinet.h  
  
##  <a name="cinternetsession"></a>CInternetSession::CInternetSession  
 Essa função de membro é chamada quando uma `CInternetSession` objeto é criado.  
  
```  
CInternetSession(
    LPCTSTR pstrAgent = NULL,  
    DWORD_PTR dwContext = 1,  
    DWORD dwAccessType = PRE_CONFIG_INTERNET_ACCESS,  
    LPCTSTR pstrProxyName = NULL,  
    LPCTSTR pstrProxyBypass = NULL,  
    DWORD dwFlags = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrAgent`  
 Um ponteiro para uma cadeia de caracteres que identifica o nome do aplicativo ou da entidade chamando as funções de Internet (por exemplo, "Microsoft Internet navegador"). Se `pstrAgent` é **nulo** (o padrão), a estrutura chama a função global [AfxGetAppName](application-information-and-management.md#afxgetappname), que retorna uma cadeia de caracteres terminada em nulo que contém o nome do aplicativo. Alguns protocolos usam essa cadeia de caracteres para identificar seu aplicativo para o servidor.  
  
 `dwContext`  
 O identificador de contexto para a operação. `dwContext`identifica as informações de status da operação retornadas por [CInternetSession::OnStatusCallback](#onstatuscallback). O padrão é definido como 1; No entanto, você pode explicitamente atribuir uma ID de contexto específico para a operação. O objeto e qualquer trabalho faz será associados essa ID de contexto.  
  
 `dwAccessType`  
 O tipo de acesso necessário. Estes são valores válidos, exatamente um dos quais pode ser fornecido:  
  
- **INTERNET_OPEN_TYPE_PRECONFIG** conectar usando configurações predefinidas no registro. Esse tipo de acesso é definido como padrão. Para se conectar por meio de um proxy TIS, defina `dwAccessType` a esse valor, você, em seguida, defina o registro corretamente.  
  
- `INTERNET_OPEN_TYPE_DIRECT`Conecte-se diretamente à Internet.  
  
- `INTERNET_OPEN_TYPE_PROXY`Conectar-se através de um proxy CERN.  
  
 Para obter informações sobre como se conectar com tipos diferentes de proxies, consulte [as etapas em um aplicativo de cliente FTP típico](../../mfc/steps-in-a-typical-ftp-client-application.md).  
  
 *pstrProxyName*  
 O nome do proxy CERN preferencial se `dwAccessType` é definido como `INTERNET_OPEN_TYPE_PROXY`. O padrão é **nulo**.  
  
 *pstrProxyBypass*  
 Um ponteiro para uma cadeia de caracteres que contém uma lista opcional de endereços do servidor. Esses endereços podem ser ignorados ao usar o acesso ao proxy. Se um **nulo** valor for fornecido, a lista de ignoráveis serão lidos do registro. Esse parâmetro é significativo somente se `dwAccessType` é definido como `INTERNET_OPEN_TYPE_PROXY`.  
  
 `dwFlags`  
 Indica as várias opções de cache. O padrão é definido como 0. Os valores possíveis incluem:  
  
- `INTERNET_FLAG_DONT_CACHE`Não armazenar em cache os dados localmente ou em todos os servidores gateway.  
  
- `INTERNET_FLAG_OFFLINE`Operações de download estiver satisfeito por meio de cache persistente. Se o item não existe no cache, é retornado um código de erro apropriado. Este sinalizador pode ser combinado com o bit a bit `OR` ( **|**) operador.  
  
### <a name="remarks"></a>Comentários  
 **CInternetSession** é a primeira função de Internet chamada por um aplicativo. Ele inicializa as estruturas de dados internas e prepara para futuras chamadas do aplicativo.  
  
 Se nenhuma conexão de Internet pode ser aberto, `CInternetSession` lança um [AfxThrowInternetException](http://msdn.microsoft.com/library/c9645b10-9541-48b2-8b0c-94ca33fed3cb).  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md).  
  
##  <a name="close"></a>CInternetSession::Close  
 Chame essa função de membro quando seu aplicativo tiver terminado de usar o `CInternetSession` objeto.  
  
```  
virtual void Close();
```  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md).  
  
##  <a name="enablestatuscallback"></a>CInternetSession::EnableStatusCallback  
 Chame essa função de membro para habilitar o retorno de chamada de status.  
  
```  
BOOL EnableStatusCallback(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEnable`  
 Especifica se o retorno de chamada está habilitado ou desabilitado. O padrão é **TRUE**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, determine a causa da falha examinando o lançada [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Ao manipular o retorno de chamada de status, você pode fornecer o status sobre o progresso da operação (como resolução de nome, conectando-se ao servidor e assim por diante) na barra de status do aplicativo. Exibir o status da operação é especialmente desejável durante uma operação de longo prazo.  
  
 Como retornos de chamada ocorrerem durante o processamento da solicitação, o aplicativo deve gastar tempo menor possível no retorno de chamada para evitar a degradação da taxa de transferência de dados para a rede. Por exemplo, colocar uma caixa de diálogo em um retorno de chamada pode ser uma operação demorada que o servidor encerra a solicitação.  
  
 O retorno de chamada de status não pode ser removido enquanto qualquer retorno de chamada está pendentes.  
  
 Para lidar com quaisquer operações de forma assíncrona, você deve criar seu próprio thread ou usar as funções WinInet sem MFC.  
  
##  <a name="getcontext"></a>CInternetSession::GetContext  
 Chame essa função de membro para obter o valor de contexto para uma sessão de aplicativo específico.  
  
```  
DWORD_PTR GetContext() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O aplicativo contexto definido pelo identificador.  
  
### <a name="remarks"></a>Comentários  
 [OnStatusCallback](#onstatuscallback) usa a ID do contexto retornada por **GetContext** para informar o status de um aplicativo específico. Por exemplo, quando um usuário ativa uma solicitação de Internet que envolve a retornar informações de status, o retorno de chamada de status usa a ID do contexto para informar o status nessa solicitação específica. Se o usuário ativa separada duas solicitações de Internet que ambos envolvem retornando informações de status, `OnStatusCallback` usa os identificadores de contexto para retornar o status sobre suas solicitações correspondentes. Consequentemente, o identificador de contexto é usado para todas as operações de retorno de chamada de status e é associada à sessão até que a sessão será encerrada.  
  
 Para obter mais informações sobre as operações assíncronas, consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md).  
  
##  <a name="getcookie"></a>CInternetSession::GetCookie  
 Essa função de membro implementa o comportamento da função Win32 [InternetGetCookie](http://msdn.microsoft.com/library/windows/desktop/aa384710), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
static BOOL GetCookie(
    LPCTSTR pstrUrl,  
    LPCTSTR pstrCookieName,  
    LPTSTR pstrCookieData,  
    DWORD dwBufLen);

 
static BOOL GetCookie(
    LPCTSTR pstrUrl,  
    LPCTSTR pstrCookieName,  
    CString& strCookieData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrUrl`  
 Um ponteiro para uma cadeia de caracteres que contém a URL.  
  
 `pstrCookieName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do cookie para obter a URL especificada.  
  
 `pstrCookieData`  
 Na primeira sobrecarga, um ponteiro para uma cadeia de caracteres que contém o endereço do buffer que recebe os dados de cookie. Esse valor pode ser **nulo**. Na segunda sobrecarga, uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto para receber os dados de cookie.  
  
 `dwBufLen`  
 Especifica o tamanho da variável de `pstrCookieData` buffer. Se a função obtiver êxito, o buffer recebe a quantidade de dados copiados para o `pstrCookieData` buffer. Se `pstrCookieData` é **nulo**, esse parâmetro recebe um valor que especifica o tamanho do buffer necessário para copiar todos os dados de cookie.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** se for bem-sucedido, ou **FALSE** caso contrário. Se a chamada falhar, chame a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) para determinar a causa do erro. Os valores de erro a seguir se aplicam:  
  
- **ERROR_NO_MORE_ITEMS** não há nenhum cookie para a URL especificada e todos os seus pais.  
  
- **ERROR_INSUFFICIENT_BUFFER** o valor passado em `dwBufLen` não é suficiente para copiar todos os dados de cookie. O valor retornado no `dwBufLen` é o tamanho do buffer necessário obter todos os dados.  
  
### <a name="remarks"></a>Comentários  
 A segunda sobrecarga, MFC recupera os dados do cookie em fornecido `CString` objeto.  
  
##  <a name="getcookielength"></a>CInternetSession::GetCookieLength  
 Chame essa função de membro para obter o tamanho do cookie armazenado no buffer.  
  
```  
static DWORD GetCookieLength(
    LPCTSTR pstrUrl,  
    LPCTSTR pstrCookieName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrUrl`  
 Um ponteiro para uma cadeia de caracteres que contém a URL  
  
 `pstrCookieName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do cookie.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `DWORD` valor que indica o comprimento do cookie, armazenado no buffer. Zero se nenhum cookie com o nome indicado pelo `pstrCookieName` existe.  
  
### <a name="remarks"></a>Comentários  
 Esse valor é usado por [GetCookie](#getcookie).  
  
##  <a name="getftpconnection"></a>CInternetSession::GetFtpConnection  
 Chame essa função de membro para estabelecer uma conexão FTP e obter um ponteiro para um `CFtpConnection` objeto.  
  
```  
CFtpConnection* GetFtpConnection(
    LPCTSTR pstrServer,  
    LPCTSTR pstrUserName = NULL,  
    LPCTSTR pstrPassword = NULL,  
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER,  
    BOOL bPassive = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrServer`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do servidor FTP.  
  
 `pstrUserName`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do usuário para fazer logon. Se **nulo**, o padrão é anônimo.  
  
 `pstrPassword`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo que especifica a senha a ser usada para fazer logon. Se ambos os `pstrPassword` e `pstrUserName` são **nulo**, a senha anônima padrão é o nome de email do usuário. Se `pstrPassword` é **nulo** (ou uma cadeia de caracteres vazia), mas `pstrUserName` não é **nulo**, é usada uma senha em branco. A tabela a seguir descreve o comportamento para as quatro configurações possíveis de `pstrUserName` e `pstrPassword`:  
  
|`pstrUserName`|`pstrPassword`|Nome de usuário enviado ao servidor FTP|Senha enviada ao servidor FTP|  
|--------------------|--------------------|---------------------------------|---------------------------------|  
|**NULO** ou ""|**NULO** ou ""|"anônimo"|Nome de email do usuário|  
|Não- **nulo** cadeia de caracteres|**NULO** ou ""|`pstrUserName`|" "|  
|**NULO** não - **nulo** cadeia de caracteres|**ERRO**|**ERRO**||  
|Não- **nulo** cadeia de caracteres|Não- **nulo** cadeia de caracteres|`pstrUserName`|`pstrPassword`|  
  
 `nPort`  
 Um número que identifica a porta TCP/IP para usar no servidor.  
  
 `bPassive`  
 Especifica o modo passivo ou ativo para esta sessão FTP. Se definido como **TRUE**, ele define a API do Win32 `dwFlag` para **INTERNET_FLAG_PASSIVE**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CFtpConnection](../../mfc/reference/cftpconnection-class.md) objeto. Se a chamada falhar, determine a causa da falha examinando o lançada [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 `GetFtpConnection`conecta-se a um servidor FTP e cria e retorna um ponteiro para um **CFTPConnection** objeto. Ele não executa qualquer operação específica no servidor. Por exemplo, se você pretende ler ou gravar em arquivos, você deve executar essas operações como etapas distintas. Consulte as classes [CFtpConnection](../../mfc/reference/cftpconnection-class.md) e [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md) para obter informações sobre como procurar por arquivos, abrir arquivos e ler ou gravar em arquivos. Consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md) para etapas para realizar tarefas comuns de conexão de FTP.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md).  
  
##  <a name="getgopherconnection"></a>CInternetSession::GetGopherConnection  
 Chame essa função de membro para estabelecer uma nova conexão gopher e obter um ponteiro para um `CGopherConnection` objeto.  
  
```  
CGopherConnection* GetGopherConnection(
    LPCTSTR pstrServer,  
    LPCTSTR pstrUserName = NULL,  
    LPCTSTR pstrPassword = NULL,  
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrServer`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do servidor gopher.  
  
 `pstrUserName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome de usuário.  
  
 `pstrPassword`  
 Um ponteiro para uma cadeia de caracteres que contém a senha de acesso.  
  
 `nPort`  
 Um número que identifica a porta TCP/IP para usar no servidor.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CGopherConnection](../../mfc/reference/cgopherconnection-class.md) objeto. Se a chamada falhar, determine a causa da falha examinando o lançada [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 `GetGopherConnection`conecta a um servidor gopher, cria e retorna um ponteiro para um `CGopherConnection` objeto. Ele não executa qualquer operação específica no servidor. Por exemplo, se você pretende ler ou gravar dados, você deve executar essas operações como etapas distintas. Consulte as classes [CGopherConnection](../../mfc/reference/cgopherconnection-class.md), [CGopherFile](../../mfc/reference/cgopherfile-class.md), e [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md) para obter informações sobre como procurar por arquivos, abrir arquivos e ler ou gravar em arquivos. Para obter informações sobre a navegação de um site FTP, consulte a função de membro [OpenURL](#openurl). Consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md) para etapas para realizar tarefas comuns de conexão gopher.  
  
##  <a name="gethttpconnection"></a>CInternetSession::GetHttpConnection  
 Chame essa função de membro para estabelecer uma conexão HTTP e obter um ponteiro para um `CHttpConnection` objeto.  
  
```  
CHttpConnection* GetHttpConnection(
    LPCTSTR pstrServer,  
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER,  
    LPCTSTR pstrUserName = NULL,  
    LPCTSTR pstrPassword = NULL);

 
CHttpConnection* GetHttpConnection(
    LPCTSTR pstrServer,  
    DWORD dwFlags,  
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER,  
    LPCTSTR pstrUserName = NULL,  
    LPCTSTR pstrPassword = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrServer`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do servidor HTTP.  
  
 `nPort`  
 Um número que identifica a porta TCP/IP para usar no servidor.  
  
 `pstrUserName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome de usuário.  
  
 `pstrPassword`  
 Um ponteiro para uma cadeia de caracteres que contém a senha de acesso.  
  
 *dwFlags*  
 Qualquer combinação de **Flag Internet _ _\* ** sinalizadores. Consulte a tabela de **comentários** seção [CHttpConnection::OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest) para obter uma descrição de `dwFlags` valores.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CHttpConnection](../../mfc/reference/chttpconnection-class.md) objeto. Se a chamada falhar, determine a causa da falha examinando o lançada [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 `GetHttpConnection`conecta-se a um servidor HTTP e cria e retorna um ponteiro para um `CHttpConnection` objeto. Ele não executa qualquer operação específica no servidor. Por exemplo, se você pretende consultar um cabeçalho HTTP, você deve executar essa operação como uma etapa separada. Consulte as classes [CHttpConnection](../../mfc/reference/chttpconnection-class.md) e [CHttpFile](../../mfc/reference/chttpfile-class.md) para obter informações sobre as operações que você pode executar usando uma conexão a um servidor HTTP. Para obter informações sobre a navegação de um site HTTP, consulte a função de membro [OpenURL](#openurl). Consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md) para etapas para realizar tarefas comuns de conexão HTTP.  
  
##  <a name="onstatuscallback"></a>CInternetSession::OnStatusCallback  
 Essa função de membro é chamada pela estrutura para atualizar o status quando o retorno de chamada de status é habilitado e uma operação está pendente.  
  
```  
virtual void OnStatusCallback(
    DWORD_PTR dwContext,  
    DWORD dwInternetStatus,  
    LPVOID lpvStatusInformation,  
    DWORD dwStatusInformationLength);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwContext`  
 O valor de contexto fornecido pelo aplicativo.  
  
 `dwInternetStatus`  
 Um código de status que indica por que o retorno de chamada está sendo feito. Consulte **comentários** para uma tabela de valores possíveis.  
  
 `lpvStatusInformation`  
 Um ponteiro para um buffer que contém informações pertinentes para esse retorno de chamada.  
  
 `dwStatusInformationLength`  
 O tamanho do `lpvStatusInformation`.  
  
### <a name="remarks"></a>Comentários  
 Você deve primeiro chamar [EnableStatusCallback](#enablestatuscallback) para tirar proveito do retorno de chamada de status.  
  
 O `dwInternetStatus` parâmetro indica a operação que está sendo executada e determina que o conteúdo de `lpvStatusInformation` será. `dwStatusInformationLength`indica o comprimento dos dados incluídos em `lpvStatusInformation`. Os seguintes status valores para `dwInternetStatus` são definidos da seguinte maneira:  
  
|Valor|Significado|  
|-----------|-------------|  
|`INTERNET_STATUS_RESOLVING_NAME`|Procura o endereço IP do nome contido no `lpvStatusInformation`.|  
|`INTERNET_STATUS_NAME_RESOLVED`|Encontrado com sucesso o endereço IP do nome contido no `lpvStatusInformation`.|  
|`INTERNET_STATUS_CONNECTING_TO_SERVER`|Conectar-se para o endereço de soquete ( [SOCKADDR](../../mfc/reference/sockaddr-structure.md)) apontada por `lpvStatusInformation`.|  
|`INTERNET_STATUS_CONNECTED_TO_SERVER`|Conectado com êxito para o endereço de soquete ( `SOCKADDR`) apontada por `lpvStatusInformation`.|  
|`INTERNET_STATUS_SENDING_REQUEST`|Enviar a solicitação de informações para o servidor. O `lpvStatusInformation` parâmetro é **nulo**.|  
|**INTERNET_STATUS_ REQUEST_SENT**|Enviado com êxito a solicitação de informações para o servidor. O `lpvStatusInformation` parâmetro é **nulo**.|  
|`INTERNET_STATUS_RECEIVING_RESPONSE`|Aguardando o servidor responder a uma solicitação. O `lpvStatusInformation` parâmetro é **nulo**.|  
|`INTERNET_STATUS_RESPONSE_RECEIVED`|Recebida uma resposta do servidor. O `lpvStatusInformation` parâmetro é **nulo**.|  
|`INTERNET_STATUS_CLOSING_CONNECTION`|Fechando a conexão ao servidor. O `lpvStatusInformation` parâmetro é **nulo**.|  
|`INTERNET_STATUS_CONNECTION_CLOSED`|Fechada com êxito a conexão com o servidor. O `lpvStatusInformation` parâmetro é **nulo**.|  
|`INTERNET_STATUS_HANDLE_CREATED`|Usado pela função de API do Win32 [InternetConnect](http://msdn.microsoft.com/library/windows/desktop/aa384363) para indicar que foi criada a nova alça. Isso permite que a função de chamada Win32 application [InternetCloseHandle](http://msdn.microsoft.com/library/windows/desktop/aa384350) de outro thread se conectar está demorando muito. Consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]para obter mais informações sobre essas funções.|  
|`INTERNET_STATUS_HANDLE_CLOSING`|Encerrado com êxito esse valor de identificador.|  
  
 Substitua essa função de membro para exigir alguma ação antes de uma rotina de retorno de chamada de status é executada.  
  
> [!NOTE]
>  Retornos de chamada de status precisam de proteção do estado de thread. Se você estiver usando o MFC em uma biblioteca compartilhada, adicione a seguinte linha ao início da sua substituição:  
  
 [!code-cpp[NVC_MFCHtmlHttp n º&8;](../../mfc/reference/codesnippet/cpp/cinternetsession-class_1.cpp)]  
  
 Para obter mais informações sobre as operações assíncronas, consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md).  
  
##  <a name="openurl"></a>CInternetSession::OpenURL  
 Chame esse membro de função para enviar a solicitação especificada para o servidor HTTP e permitem que o cliente especificar RFC822 adicionais, MIME ou cabeçalhos HTTP para enviar junto com a solicitação.  
  
```  
CStdioFile* OpenURL(
    LPCTSTR pstrURL,  
    DWORD_PTR dwContext = 1,  
    DWORD dwFlags = INTERNET_FLAG_TRANSFER_ASCII,  
    LPCTSTR pstrHeaders = NULL,  
    DWORD dwHeadersLength = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pstrURL*  
 Um ponteiro para o nome da URL para iniciar a leitura. Somente URLs começando com o arquivo:, ftp:, gopher:, ou http: têm suporte. **DECLARAÇÕES** se *pszURL* é **nulo**.  
  
 `dwContext`  
 Um valor definido pelo aplicativo passado com o identificador retornado no retorno de chamada.  
  
 `dwFlags`  
 Os sinalizadores que descrevem como lidar com essa conexão. Consulte **comentários** para obter mais informações sobre os sinalizadores válidos. Os sinalizadores válidos são:  
  
- **INTERNET_FLAG_TRANSFER_ASCII** o padrão. Transfira o arquivo como texto ASCII.  
  
- **INTERNET_FLAG_TRANSFER_BINARY** transferir o arquivo como um arquivo binário.  
  
- `INTERNET_FLAG_RELOAD`Obter os dados de conexão mesmo se ela é armazenada em cache localmente.  
  
- `INTERNET_FLAG_DONT_CACHE`Não armazenar em cache os dados localmente ou em todos os gateways.  
  
- `INTERNET_FLAG_SECURE`Esse sinalizador é aplicável apenas a solicitações HTTP. Ele solicita transações seguras na conexão com Secure Sockets Layer ou PERC  
  
- **INTERNET_OPEN_FLAG_USE_EXISTING_CONNECT** reutilizar se possível, as conexões existentes para o servidor para novas solicitações geradas pelo **OpenUrl** em vez de criar uma nova sessão para cada solicitação de conexão.  
  
- **INTERNET_FLAG_PASSIVE** usado para um site FTP. Usa a semântica de FTP passivo. Usado com [CInternetConnection](../../mfc/reference/cinternetconnection-class.md) de `OpenURL`.  
  
 `pstrHeaders`  
 Um ponteiro para uma cadeia de caracteres que contém os cabeçalhos para serem enviadas para o servidor HTTP.  
  
 *dwHeadersLength*  
 O comprimento, em caracteres, dos cabeçalhos adicionais. Quando se trata de-1l e `pstrHeaders` não **nulo**, em seguida, `pstrHeaders` é considerado zero encerrada e o comprimento é calculado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um identificador de arquivo para somente os serviços FTP, GOPHER, HTTP e tipo de arquivo de Internet. Retorna **nulo** se a análise foi bem-sucedida.  
  
 O ponteiro que `OpenURL` retorna depende *pszURL*do tipo de serviço. A tabela a seguir ilustra os ponteiros possíveis `OpenURL` pode retornar.  
  
|Tipo de URL|Retorna|  
|--------------|-------------|  
|file://|**CStdioFile\***|  
|http://|**CHttpFile\***|  
|Gopher://|**CGopherFile\***|  
|FTP: / /|**CInternetFile\***|  
  
### <a name="remarks"></a>Comentários  
 O parâmetro `dwFlags` deve incluir **INTERNET_FLAG_TRANSFER_ASCII** ou **INTERNET_FLAG_TRANSFER_BINARY**, mas não ambos. Os sinalizadores restantes podem ser combinados com o bit a bit `OR` operador ( **|**).  
  
 `OpenURL`, que encapsula a função Win32 **InternetOpenURL**, permite baixar apenas, recuperar e ler os dados de um servidor de Internet. `OpenURL`não permite não requer nenhuma manipulação de arquivo em um local remoto, [CInternetConnection](../../mfc/reference/cinternetconnection-class.md) objeto.  
  
 Usar conexão específica (ou seja, específicos de protocolo) funções, como gravar um arquivo, você deve abrir uma sessão, em seguida, abrir um determinado tipo de conexão e usar essa conexão para abrir um arquivo no modo desejado. Consulte `CInternetConnection` para obter mais informações sobre funções específicas de conexão.  
  
##  <a name="operator_hinternet"></a>CInternetSession::operator HINTERNET  
 Use esse operador para obter o identificador do Windows para a sessão atual da Internet.  
  
```  
operator HINTERNET() const;  
```  
  
##  <a name="setcookie"></a>CInternetSession::SetCookie  
 Define um cookie para a URL especificada.  
  
```  
static BOOL SetCookie(
    LPCTSTR pstrUrl,  
    LPCTSTR pstrCookieName,  
    LPCTSTR pstrCookieData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrUrl`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo que especifica a URL para o qual o cookie deve ser definido.  
  
 `pstrCookieName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do cookie.  
  
 `pstrCookieData`  
 Um ponteiro para uma cadeia de caracteres que contém os dados de cadeia de caracteres real para associar a URL.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** se for bem-sucedido, ou **FALSE** caso contrário. Para obter o código de erro específico, chame **GetLastError.**  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [InternetSetCookie](http://msdn.microsoft.com/library/windows/desktop/aa385107), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setoption"></a>CInternetSession::SetOption  
 Chame essa função de membro para definir opções para a sessão de Internet.  
  
```  
BOOL SetOption(
    DWORD dwOption,  
    LPVOID lpBuffer,  
    DWORD dwBufferLength,  
    DWORD dwFlags = 0);

 
BOOL SetOption(
    DWORD dwOption,  
    DWORD dwValue,  
    DWORD dwFlags = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwOption`  
 A opção de Internet de definir. Consulte [sinalizadores de opção](http://msdn.microsoft.com/library/windows/desktop/aa385328) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]para obter uma lista das opções possíveis.  
  
 `lpBuffer`  
 Um buffer que contém a configuração da opção.  
  
 *dwBufferLength*  
 O comprimento de `lpBuffer` ou o tamanho de `dwValue`.  
  
 `dwValue`  
 Um `DWORD` que contém a configuração da opção.  
  
 `dwFlags`  
 Indica as várias opções de cache. O padrão é definido como 0. Os valores possíveis incluem:  
  
- `INTERNET_FLAG_DONT_CACHE`Não armazenar em cache os dados localmente ou em todos os servidores gateway.  
  
- `INTERNET_FLAG_OFFLINE`Operações de download estiver satisfeito por meio de cache persistente. Se o item não existe no cache, é retornado um código de erro apropriado. Este sinalizador pode ser combinado com o bit a bit `OR` ( **|**) operador.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a operação foi bem-sucedida, um valor de **TRUE** é retornado. Se ocorrer um erro, um valor de **FALSE** é retornado. Se a chamada falhar, a função do Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)   
 [Classe CHttpConnection](../../mfc/reference/chttpconnection-class.md)   
 [Classe CFtpConnection](../../mfc/reference/cftpconnection-class.md)   
 [Classe CGopherConnection](../../mfc/reference/cgopherconnection-class.md)

