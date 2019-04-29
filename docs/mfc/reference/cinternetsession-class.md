---
title: Classe CInternetSession
ms.date: 06/20/2018
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
helpviewer_keywords:
- CInternetSession [MFC], CInternetSession
- CInternetSession [MFC], Close
- CInternetSession [MFC], EnableStatusCallback
- CInternetSession [MFC], GetContext
- CInternetSession [MFC], GetCookie
- CInternetSession [MFC], GetCookieLength
- CInternetSession [MFC], GetFtpConnection
- CInternetSession [MFC], GetGopherConnection
- CInternetSession [MFC], GetHttpConnection
- CInternetSession [MFC], OnStatusCallback
- CInternetSession [MFC], OpenURL
- CInternetSession [MFC], SetCookie
- CInternetSession [MFC], SetOption
ms.assetid: ef54feb4-9d0f-4e65-a45d-7a4cf6c40e51
ms.openlocfilehash: 5ad1a1a0dde32358828d58a8f237337c4f62f3e5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62345585"
---
# <a name="cinternetsession-class"></a>Classe CInternetSession

Cria e inicializa uma ou várias sessões simultâneas da Internet e, se necessário, descreve sua conexão a um servidor proxy.

## <a name="syntax"></a>Sintaxe

```cpp
class CInternetSession : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CInternetSession::CInternetSession](#cinternetsession)|Constrói um objeto `CInternetSession`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CInternetSession::Close](#close)|Fecha a conexão de Internet quando a sessão de Internet é encerrada.|
|[CInternetSession::EnableStatusCallback](#enablestatuscallback)|Estabelece uma rotina de retorno de chamada de status.|
|[CInternetSession::GetContext](#getcontext)|Fecha a conexão de Internet quando a sessão de Internet é encerrada.|
|[CInternetSession::GetCookie](#getcookie)|Retorna os cookies para a URL especificada e todos os seu pai URLs.|
|[CInternetSession::GetCookieLength](#getcookielength)|Recupera a variável especificando o comprimento do cookie armazenado no buffer.|
|[CInternetSession::GetFtpConnection](#getftpconnection)|Abre uma sessão FTP com um servidor. Logon do usuário.|
|[CInternetSession::GetGopherConnection](#getgopherconnection)|Abre um servidor gopher para um aplicativo que está tentando abrir uma conexão.|
|[CInternetSession::GetHttpConnection](#gethttpconnection)|Abre um servidor HTTP para um aplicativo que está tentando abrir uma conexão.|
|[CInternetSession::OnStatusCallback](#onstatuscallback)|Atualiza o status de uma operação quando retorno de chamada de status está habilitado.|
|[CInternetSession::OpenURL](#openurl)|Analisa e abre uma URL.|
|[CInternetSession::SetCookie](#setcookie)|Define um cookie para a URL especificada.|
|[CInternetSession::SetOption](#setoption)|Define as opções para a sessão de Internet.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CInternetSession::operator HINTERNET](#operator_hinternet)|Um identificador para a sessão atual da Internet.|

## <a name="remarks"></a>Comentários

Se sua conexão de Internet deve ser mantida para a duração de um aplicativo, você pode criar uma `CInternetSession` membro da classe [CWinApp](../../mfc/reference/cwinapp-class.md).

Depois de estabelecer uma sessão da Internet, você pode chamar [OpenURL](#openurl). `CInternetSession` em seguida, analisa a URL para você, chamando a função global [AfxParseURL](internet-url-parsing-globals.md#afxparseurl). Independentemente do seu tipo de protocolo, `CInternetSession` interpreta a URL e gerenciá-la para você. Ele pode lidar com solicitações de arquivos locais identificados com o recurso de URL "file://". `OpenURL` retornará um ponteiro para um [CStdioFile](../../mfc/reference/cstdiofile-class.md) se o nome que você a passar de objeto é um arquivo local.

Se você abre uma URL em um servidor de Internet usando `OpenURL`, você pode ler informações do site. Se você quiser executar ações específicas de serviço (por exemplo, HTTP, FTP ou gopher) nos arquivos localizados em um servidor, você deve estabelecer a conexão apropriada com o servidor. Para abrir um determinado tipo de conexão diretamente para um serviço específico, use uma das seguintes funções de membro:

- [GetGopherConnection](#getgopherconnection) para abrir uma conexão a um serviço de gopher.

- [GetHttpConnection](#gethttpconnection) para abrir uma conexão para um serviço HTTP.

- [GetFtpConnection](#getftpconnection) para abrir uma conexão com um serviço de FTP.

[SetOption](#setoption) permite que você defina as opções de consulta de sua sessão, como valores de tempo limite, o número de repetições e assim por diante.

`CInternetSession` funções de membro [SetCookie](#setcookie), [GetCookie](#getcookie), e [GetCookieLength](#getcookielength) fornecem os meios para gerenciar um banco de dados de cookie do Win32, por meio do qual mantêm servidores e scripts informações de estado sobre a estação de trabalho do cliente.

Para obter mais informações sobre tarefas básicas de programação da Internet, consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md). Para obter informações gerais sobre como usar as classes WinInet do MFC, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).

> [!NOTE]
> `CInternetSession` lançará uma [AfxThrowNotSupportedException](exception-processing.md#afxthrownotsupportedexception) para tipos de serviço sem suporte. Somente os seguintes tipos de serviço são atualmente suportados: FTP, HTTP, gopher e arquivo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;`CInternetSession`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="cinternetsession"></a> CInternetSession::CInternetSession

Essa função membro é chamada quando um `CInternetSession` objeto é criado.

```cpp
CInternetSession(
    LPCTSTR pstrAgent = NULL,
    DWORD_PTR dwContext = 1,
    DWORD dwAccessType = PRE_CONFIG_INTERNET_ACCESS,
    LPCTSTR pstrProxyName = NULL,
    LPCTSTR pstrProxyBypass = NULL,
    DWORD dwFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*pstrAgent*<br/>
Um ponteiro para uma cadeia de caracteres que identifica o nome do aplicativo ou da entidade para chamar as funções de Internet (por exemplo, "Microsoft navegador da Internet"). Se *pstrAgent* for NULL (o padrão), a estrutura chama a função global [AfxGetAppName](application-information-and-management.md#afxgetappname), que retorna uma cadeia de caracteres terminada em nulo que contém o nome de um aplicativo. Alguns protocolos de usam essa cadeia de caracteres para identificar seu aplicativo para o servidor.

*dwContext*<br/>
O identificador de contexto para a operação. *dwContext* identifica as informações de status da operação retornadas por [CInternetSession::OnStatusCallback](#onstatuscallback). O padrão é definido como 1; No entanto, você pode explicitamente atribuir uma ID de contexto específico para a operação. O objeto e qualquer trabalho que será associados essa ID de contexto.

*dwAccessType*<br/>
O tipo de acesso necessário. Os seguintes valores são válidos, exatamente um dos quais pode ser fornecido:

- Conectar INTERNET_OPEN_TYPE_PRECONFIG usando pré-configurada configurações no registro. Esse tipo de acesso é definido como o padrão. Para se conectar por meio de um proxy TIS, defina *dwAccessType* a este valor; você, em seguida, defina o registro corretamente.

- INTERNET_OPEN_TYPE_DIRECT se conectar diretamente à Internet.

- INTERNET_OPEN_TYPE_PROXY conectar por meio de um proxy CERN.

Para obter informações sobre como se conectar com tipos diferentes de proxies, consulte [as etapas em um aplicativo de cliente FTP típico](../../mfc/steps-in-a-typical-ftp-client-application.md).

*pstrProxyName*<br/>
O nome do proxy CERN preferencial se *dwAccessType* é definido como INTERNET_OPEN_TYPE_PROXY. O padrão é NULL.

*pstrProxyBypass*<br/>
Um ponteiro para uma cadeia de caracteres que contém uma lista opcional de endereços do servidor. Esses endereços podem ser ignorados ao usar o acesso ao proxy. Se um valor nulo for fornecido, será possível ler a lista de bypass do registro. Esse parâmetro será significativo somente se *dwAccessType* é definido como INTERNET_OPEN_TYPE_PROXY.

*dwFlags*<br/>
Indica várias opções de cache. O padrão é definido como 0. Os valores possíveis incluem:

- INTERNET_FLAG_DONT_CACHE não armazenar em cache os dados, localmente ou em todos os servidores gateway.

- Baixar INTERNET_FLAG_OFFLINE operações são atendidas por meio de cache persistente. Se o item não existe no cache, um código de erro apropriado será retornado. Este sinalizador pode ser combinado com o bit a bit **ou** ( **&#124;**) operador.

### <a name="remarks"></a>Comentários

`CInternetSession` a primeira função de Internet é chamada por um aplicativo. Ele inicializa as estruturas de dados internas e o prepara para futuras chamadas do aplicativo.

Se nenhuma conexão de Internet pode ser aberto, `CInternetSession` lança uma [AfxThrowInternetException](internet-url-parsing-globals.md#afxthrowinternetexception).

### <a name="example"></a>Exemplo

Veja o exemplo de [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md).

## <a name="close"></a>  CInternetSession::Close

Chame essa função de membro quando seu aplicativo tiver terminado de usar o `CInternetSession` objeto.

```cpp
virtual void Close();
```

### <a name="example"></a>Exemplo

Veja o exemplo de [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md).

## <a name="enablestatuscallback"></a>  CInternetSession::EnableStatusCallback

Chame essa função de membro para habilitar o retorno de chamada de status.

```cpp
BOOL EnableStatusCallback(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
Especifica se o retorno de chamada está habilitado ou desabilitado. O padrão é TRUE.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0. Se a chamada falhar, determinar a causa da falha, examinando o lançada [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto.

### <a name="remarks"></a>Comentários

Ao manipular o retorno de chamada de status, você pode fornecer o status sobre o progresso da operação (como resolução de nome, se conectar ao servidor e assim por diante) na barra de status do aplicativo. Exibir o status da operação é especialmente desejável durante uma operação de longo prazo.

Como os retornos de chamada ocorrerem durante o processamento da solicitação, o aplicativo deve passar o menor tempo possível no retorno de chamada para evitar a degradação da taxa de transferência de dados para a rede. Por exemplo, a colocação de uma caixa de diálogo em um retorno de chamada pode ser uma operação demorada que o servidor encerra a solicitação.

O retorno de chamada de status não pode ser removido enquanto qualquer retorno de chamada está pendentes.

Para lidar com quaisquer operações de forma assíncrona, você deve criar seu próprio thread ou usar as funções de WinInet sem MFC.

## <a name="getcontext"></a>  CInternetSession::GetContext

Chame essa função de membro para obter o valor de contexto para uma sessão de aplicativo específico.

```cpp
DWORD_PTR GetContext() const;
```

### <a name="return-value"></a>Valor de retorno

O aplicativo contexto definido pelo identificador.

### <a name="remarks"></a>Comentários

[OnStatusCallback](#onstatuscallback) usa a ID do contexto retornada por `GetContext` para relatar o status de um aplicativo específico. Por exemplo, quando um usuário ativa uma solicitação de Internet que envolve a retornar informações de status, o retorno de chamada de status usa a ID de contexto para relatar o status na solicitação específica. Se o usuário ativa dois separado Internet solicita que os dois envolvem a retornar informações de status, `OnStatusCallback` usa os identificadores de contexto para retornar o status sobre suas solicitações correspondentes. Consequentemente, o identificador de contexto é usado para todas as operações de retorno de chamada de status, e ele está associado com a sessão até que a sessão seja encerrada.

Para obter mais informações sobre as operações assíncronas, consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md).

## <a name="getcookie"></a>  CInternetSession::GetCookie

Essa função membro implementa o comportamento da função Win32 [InternetGetCookie](/windows/desktop/api/wininet/nf-wininet-internetgetcookiea), conforme descrito no SDK do Windows.

```cpp
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

*pstrUrl*<br/>
Um ponteiro para uma cadeia de caracteres que contém a URL.

*pstrCookieName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do cookie para obter a URL especificada.

*pstrCookieData*<br/>
Na primeira sobrecarga, um ponteiro para uma cadeia de caracteres que contém o endereço do buffer que recebe os dados do cookie. Esse valor pode ser NULL. Na segunda sobrecarga, uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto para receber os dados do cookie.

*dwBufLen*<br/>
A variável especificando o tamanho do *pstrCookieData* buffer. Se a função for bem-sucedida, o buffer recebe a quantidade de dados copiados para o *pstrCookieData* buffer. Se *pstrCookieData* for NULL, esse parâmetro recebe um valor que especifica o tamanho do buffer necessário para copiar todos os dados de cookie.

### <a name="return-value"></a>Valor de retorno

Caso contrário, retornará TRUE se for bem-sucedido, ou FALSE. Se a chamada falhar, chame a função Win32 [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360) para determinar a causa do erro. Os valores de erro a seguir se aplicam:

- ERROR_NO_MORE_ITEMS não há nenhum cookie para a URL especificada e todos os seus pais.

- ERROR_INSUFFICIENT_BUFFER o valor passado *dwBufLen* não é suficiente para copiar todos os dados de cookie. O valor retornado em *dwBufLen* é o tamanho do buffer necessário para obter todos os dados.

### <a name="remarks"></a>Comentários

Na segunda sobrecarga, o MFC recupera os dados do cookie em fornecido `CString` objeto.

## <a name="getcookielength"></a>  CInternetSession::GetCookieLength

Chame essa função de membro para obter o tamanho do cookie armazenado no buffer.

```cpp
static DWORD GetCookieLength(
    LPCTSTR pstrUrl,
    LPCTSTR pstrCookieName);
```

### <a name="parameters"></a>Parâmetros

*pstrUrl*<br/>
Um ponteiro para uma cadeia de caracteres que contém a URL

*pstrCookieName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do cookie.

### <a name="return-value"></a>Valor de retorno

Um valor DWORD que indica o comprimento de cookie, armazenados no buffer. Zero se nenhum cookie com o nome indicado por *pstrCookieName* existe.

### <a name="remarks"></a>Comentários

Esse valor é usado pelo [GetCookie](#getcookie).

## <a name="getftpconnection"></a>  CInternetSession::GetFtpConnection

Chame essa função de membro para estabelecer uma conexão de FTP e obter um ponteiro para um `CFtpConnection` objeto.

```cpp
CFtpConnection* GetFtpConnection(
    LPCTSTR pstrServer,
    LPCTSTR pstrUserName = NULL,
    LPCTSTR pstrPassword = NULL,
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER,
    BOOL bPassive = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pstrServer*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do servidor FTP.

*pstrUserName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do usuário para fazer logon. Se for NULL, o padrão é anônimo.

*pstrPassword*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que especifica a senha a ser usada para fazer logon. Se os dois *pstrPassword* e *pstrUserName* forem nulos, a senha de padrão anônimo é o nome de email do usuário. Se *pstrPassword* é nulo (ou uma cadeia de caracteres vazia), mas *pstrUserName* não for nulo, uma senha em branco será usada. A tabela a seguir descreve o comportamento para as quatro configurações possíveis dos *pstrUserName* e *pstrPassword*:

| *pstrUserName*  | *pstrPassword*  | Nome de usuário enviado ao servidor FTP | Senha enviados ao servidor FTP |
|-----------------|-----------------|-----------------------------|-----------------------------|
|   NULO ou ""   |   NULO ou ""   |         "anônimo"         |      Nome de email do usuário      |
| Cadeia de caracteres não nula |   NULO ou ""   |       *pstrUserName*        |             " "             |
|      NULL       | Cadeia de caracteres não nula |            ERROR            |            ERROR            |
| Cadeia de caracteres não nula | Cadeia de caracteres não nula |       *pstrUserName*        |       *pstrPassword*        |

*nPort*<br/>
Um número que identifica a porta TCP/IP para usar no servidor.

*bPassive*<br/>
Especifica o modo passivo ou ativo para esta sessão FTP. Se definido como TRUE, define a API do Win32 `dwFlag` para INTERNET_FLAG_PASSIVE.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um [CFtpConnection](../../mfc/reference/cftpconnection-class.md) objeto. Se a chamada falhar, determinar a causa da falha, examinando o lançada [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto.

### <a name="remarks"></a>Comentários

`GetFtpConnection` conecta-se a um servidor FTP e cria e retorna um ponteiro para um `CFTPConnection` objeto. Ele não executa qualquer operação específica no servidor. Por exemplo, se você pretende ler ou gravar em arquivos, você deve executar essas operações como etapas separadas. Consulte as classes [CFtpConnection](../../mfc/reference/cftpconnection-class.md) e [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md) para obter informações sobre como procurar por arquivos, abrir arquivos e ler ou gravar em arquivos. Consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md) para etapas para realizar tarefas comuns de conexão de FTP.

### <a name="example"></a>Exemplo

Veja o exemplo de [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md).

## <a name="getgopherconnection"></a>  CInternetSession::GetGopherConnection

Chame essa função de membro para estabelecer uma nova conexão de gopher e obter um ponteiro para um `CGopherConnection` objeto.

```cpp
CGopherConnection* GetGopherConnection(
    LPCTSTR pstrServer,
    LPCTSTR pstrUserName = NULL,
    LPCTSTR pstrPassword = NULL,
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER);
```

### <a name="parameters"></a>Parâmetros

*pstrServer*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do servidor gopher.

*pstrUserName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome de usuário.

*pstrPassword*<br/>
Um ponteiro para uma cadeia de caracteres que contém a senha de acesso.

*nPort*<br/>
Um número que identifica a porta TCP/IP para usar no servidor.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um [CGopherConnection](../../mfc/reference/cgopherconnection-class.md) objeto. Se a chamada falhar, determinar a causa da falha, examinando o lançada [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto.

### <a name="remarks"></a>Comentários

`GetGopherConnection` conecta a um servidor gopher e cria e retorna um ponteiro para um `CGopherConnection` objeto. Ele não executa qualquer operação específica no servidor. Por exemplo, se você pretende ler ou gravar dados, você deve executar essas operações como etapas separadas. Consulte as classes [CGopherConnection](../../mfc/reference/cgopherconnection-class.md), [CGopherFile](../../mfc/reference/cgopherfile-class.md), e [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md) para obter informações sobre como procurar por arquivos, abrir arquivos e ler ou gravar em arquivos. Para obter informações sobre a navegação de um site FTP, consulte a função de membro [OpenURL](#openurl). Consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md) para etapas para realizar tarefas comuns de conexão de gopher.

## <a name="gethttpconnection"></a>  CInternetSession::GetHttpConnection

Chame essa função de membro para estabelecer uma conexão HTTP e obter um ponteiro para um `CHttpConnection` objeto.

```cpp
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

*pstrServer*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do servidor HTTP.

*nPort*<br/>
Um número que identifica a porta TCP/IP para usar no servidor.

*pstrUserName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome de usuário.

*pstrPassword*<br/>
Um ponteiro para uma cadeia de caracteres que contém a senha de acesso.

*dwflags*<br/>
Qualquer combinação da `INTERNET_FLAG_*` sinalizadores. Consulte a tabela a **comentários** seção [CHttpConnection::OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest) para obter uma descrição *dwFlags* valores.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um [CHttpConnection](../../mfc/reference/chttpconnection-class.md) objeto. Se a chamada falhar, determinar a causa da falha, examinando o lançada [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto.

### <a name="remarks"></a>Comentários

`GetHttpConnection` conecta-se a um servidor HTTP e cria e retorna um ponteiro para um `CHttpConnection` objeto. Ele não executa qualquer operação específica no servidor. Se você pretende consultar um cabeçalho HTTP, por exemplo, você deve realizar essa operação como uma etapa separada. Consulte as classes [CHttpConnection](../../mfc/reference/chttpconnection-class.md) e [CHttpFile](../../mfc/reference/chttpfile-class.md) para obter informações sobre as operações que você pode executar usando uma conexão a um servidor HTTP. Para obter informações sobre a navegação de um site HTTP, consulte a função de membro [OpenURL](#openurl). Consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md) para etapas para realizar tarefas comuns de conexão HTTP.

## <a name="onstatuscallback"></a>  CInternetSession::OnStatusCallback

Essa função membro é chamada pelo framework para atualizar o status quando o retorno de chamada de status está habilitado e uma operação está pendente.

```cpp
virtual void OnStatusCallback(
    DWORD_PTR dwContext,
    DWORD dwInternetStatus,
    LPVOID lpvStatusInformation,
    DWORD dwStatusInformationLength);
```

### <a name="parameters"></a>Parâmetros

*dwContext*<br/>
O valor de contexto fornecido pelo aplicativo.

*dwInternetStatus*<br/>
Um código de status que indica por que o retorno de chamada está sendo feito. Ver **comentários** para uma tabela de valores possíveis.

*lpvStatusInformation*<br/>
Um ponteiro para um buffer que contém informações pertinentes para esse retorno de chamada.

*dwStatusInformationLength*<br/>
O tamanho de *lpvStatusInformation*.

### <a name="remarks"></a>Comentários

Você deve primeiro chamar [EnableStatusCallback](#enablestatuscallback) para tirar proveito de retorno de chamada de status.

O *dwInternetStatus* parâmetro indica a operação que está sendo executada e determina que o conteúdo da *lpvStatusInformation* será. *dwStatusInformationLength* indica o comprimento dos dados incluídos no *lpvStatusInformation*. O status a seguir, os valores para *dwInternetStatus* são definidos da seguinte maneira:

|Valor|Significado|
|-----------|-------------|
|INTERNET_STATUS_RESOLVING_NAME|Procurando o endereço IP do nome contido em *lpvStatusInformation*.|
|INTERNET_STATUS_NAME_RESOLVED|Encontrado com sucesso o endereço IP do nome contido em *lpvStatusInformation*.|
|INTERNET_STATUS_CONNECTING_TO_SERVER|Conectar-se para o endereço de soquete ([SOCKADDR](/windows/desktop/winsock/sockaddr-2)) apontado por *lpvStatusInformation*.|
|INTERNET_STATUS_CONNECTED_TO_SERVER|Conectado com êxito para o endereço de soquete (SOCKADDR) apontado por *lpvStatusInformation*.|
|INTERNET_STATUS_SENDING_REQUEST|Enviando a solicitação de informações para o servidor. O *lpvStatusInformation* parâmetro for nulo.|
|INTERNET_STATUS_ REQUEST_SENT|Enviado com êxito a solicitação de informações para o servidor. O *lpvStatusInformation* parâmetro for nulo.|
|INTERNET_STATUS_RECEIVING_RESPONSE|Aguardando o servidor a responder a uma solicitação. O *lpvStatusInformation* parâmetro for nulo.|
|INTERNET_STATUS_RESPONSE_RECEIVED|Com êxito, recebeu uma resposta do servidor. O *lpvStatusInformation* parâmetro for nulo.|
|INTERNET_STATUS_CLOSING_CONNECTION|Fechando a conexão ao servidor. O *lpvStatusInformation* parâmetro for nulo.|
|INTERNET_STATUS_CONNECTION_CLOSED|Fechado com êxito a conexão ao servidor. O *lpvStatusInformation* parâmetro for nulo.|
|INTERNET_STATUS_HANDLE_CREATED|Usado pela função de API do Win32 [InternetConnect](/windows/desktop/api/wininet/nf-wininet-internetconnecta) para indicar que ele tenha criado o novo identificador. Isso permite que a função de chamada do Win32 application [InternetCloseHandle](/windows/desktop/api/wininet/nf-wininet-internetclosehandle) de outro thread se conectar estiver demorando muito. Consulte o SDKfor do Windows para obter mais informações sobre essas funções.|
|INTERNET_STATUS_HANDLE_CLOSING|Esse valor de identificador foi encerrado com êxito.|

Substitua essa função de membro para exigir alguma ação antes de uma rotina de retorno de chamada de status é executada.

> [!NOTE]
> Retornos de chamada de status precisam de proteção de estado de thread. Se você estiver usando o MFC em uma biblioteca compartilhada, adicione a seguinte linha ao início de sua substituição:

[!code-cpp[NVC_MFCHtmlHttp#8](../../mfc/reference/codesnippet/cpp/cinternetsession-class_1.cpp)]

Para obter mais informações sobre as operações assíncronas, consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md).

## <a name="openurl"></a>  CInternetSession::OpenURL

Chame esse membro de função para enviar a solicitação especificada para o servidor HTTP e permitir que o cliente especifique RFC822 adicionais, MIME ou cabeçalhos HTTP para enviar junto com a solicitação.

```cpp
CStdioFile* OpenURL(
    LPCTSTR pstrURL,
    DWORD_PTR dwContext = 1,
    DWORD dwFlags = INTERNET_FLAG_TRANSFER_ASCII,
    LPCTSTR pstrHeaders = NULL,
    DWORD dwHeadersLength = 0);
```

### <a name="parameters"></a>Parâmetros

*pstrURL*<br/>
Um ponteiro para o nome da URL para iniciar a leitura. Apenas as URLs a partir do arquivo:, ftp:, gopher:, ou http: têm suporte. Declara se *pstrURL* é NULL.

*dwContext*<br/>
Um valor definido pelo aplicativo passado com o identificador retornado no retorno de chamada.

*dwFlags*<br/>
Os sinalizadores que descrevem como lidar com essa conexão. Ver **comentários** para obter mais informações sobre os sinalizadores válidos. Os sinalizadores válidos são:

- INTERNET_FLAG_TRANSFER_ASCII o padrão. Transfira o arquivo como texto ASCII.

- INTERNET_FLAG_TRANSFER_BINARY transfira o arquivo como um arquivo binário.

- INTERNET_FLAG_RELOAD obter os dados de transmissão, mesmo se ela é armazenada em cache localmente.

- INTERNET_FLAG_DONT_CACHE não armazenar em cache os dados, localmente ou em todos os gateways.

- INTERNET_FLAG_SECURE esse sinalizador é aplicável somente solicitações HTTP. Ele solicita transações seguras durante a transmissão com Secure Sockets Layer ou PCT.

- INTERNET_OPEN_FLAG_USE_EXISTING_CONNECT se possível, reutilize as conexões existentes para o servidor para novas solicitações geradas pelo `OpenUrl` em vez de criar uma nova sessão para cada solicitação de conexão.

- INTERNET_FLAG_PASSIVE usado para um site FTP. Usa semântica de FTP passivo. Usado com [CInternetConnection](../../mfc/reference/cinternetconnection-class.md) de `OpenURL`.

*pstrHeaders*<br/>
Um ponteiro para uma cadeia de caracteres que contém os cabeçalhos sejam enviados para o servidor HTTP.

*dwHeadersLength*<br/>
O comprimento, em caracteres, dos cabeçalhos adicionais. Quando se trata de-1l e *pstrHeaders* não for nulo, então *pstrHeaders* é considerado como zero encerrada e o comprimento será calculado.

### <a name="return-value"></a>Valor de retorno

Retorna um identificador de arquivo FTP, GOPHER, HTTP e da Internet do tipo de arquivo somente para serviços. Retorna NULL se a análise foi bem-sucedida.

O ponteiro que `OpenURL` retorna depende *pstrURL*do tipo de serviço. A tabela a seguir ilustra os ponteiros possíveis `OpenURL` pode retornar.

|Tipo de URL|Retorna|
|--------------|-------------|
|file://|`CStdioFile*`|
|http://|`CHttpFile*`|
|Gopher://|`CGopherFile*`|
|ftp://|`CInternetFile*`|

### <a name="remarks"></a>Comentários

O parâmetro *dwFlags* deve incluir INTERNET_FLAG_TRANSFER_ASCII ou INTERNET_FLAG_TRANSFER_BINARY, mas não ambos. Os sinalizadores restantes podem ser combinados com o bit a bit **ou** operador ( **&#124;**).

`OpenURL`, que encapsula a função Win32 `InternetOpenURL`, permite somente download, recuperar e ler os dados de um servidor de Internet. `OpenURL` permite que nenhuma manipulação de arquivos em um local remoto, para que ele não requer nenhuma [CInternetConnection](../../mfc/reference/cinternetconnection-class.md) objeto.

Usar conexão específica (ou seja, específicas de protocolo) funções, como gravar em um arquivo, você deve abrir uma sessão, em seguida, abrir um determinado tipo de conexão e usar essa conexão para abrir um arquivo no modo desejado. Consulte `CInternetConnection` para obter mais informações sobre funções específicas da conexão.

## <a name="operator_hinternet"></a>  CInternetSession::operator HINTERNET

Use este operador para obter o identificador do Windows para a sessão atual da Internet.

```cpp
operator HINTERNET() const;
```

## <a name="setcookie"></a>  CInternetSession::SetCookie

Define um cookie para a URL especificada.

```cpp
static BOOL SetCookie(
    LPCTSTR pstrUrl,
    LPCTSTR pstrCookieName,
    LPCTSTR pstrCookieData);
```

### <a name="parameters"></a>Parâmetros

*pstrUrl*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que especifica a URL para o qual o cookie deve ser definido.

*pstrCookieName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do cookie.

*pstrCookieData*<br/>
Um ponteiro para uma cadeia de caracteres que contém os dados de cadeia de caracteres real a ser associado com a URL.

### <a name="return-value"></a>Valor de retorno

Caso contrário, retornará TRUE se for bem-sucedido, ou FALSE. Para obter o código de erro específica, chame `GetLastError.`

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [InternetSetCookie](/windows/desktop/api/wininet/nf-wininet-internetsetcookiea), conforme descrito no SDK do Windows.

## <a name="setoption"></a>  CInternetSession::SetOption

Chame essa função de membro para definir opções para a sessão de Internet.

```cpp
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

*dwOption*<br/>
A opção de Internet para definir. Ver [sinalizadores de opção](/windows/desktop/WinInet/option-flags) no SDKfor Windows uma lista das opções possíveis.

*lpBuffer*<br/>
Um buffer que contém a configuração da opção.

*dwBufferLength*<br/>
O comprimento da *lpBuffer* ou o tamanho dos *dwValue*.

*dwValue*<br/>
Um DWORD que contém a configuração da opção.

*dwFlags*<br/>
Indica várias opções de cache. O padrão é definido como 0. Os valores possíveis incluem:

- INTERNET_FLAG_DONT_CACHE não armazenar em cache os dados, localmente ou em todos os servidores gateway.

- Baixar INTERNET_FLAG_OFFLINE operações são atendidas por meio de cache persistente. Se o item não existe no cache, um código de erro apropriado será retornado. Este sinalizador pode ser combinado com o bit a bit **ou** ( **&#124;**) operador.

### <a name="return-value"></a>Valor de retorno

Se a operação foi bem-sucedida, um valor TRUE será retornado. Se ocorreu um erro, um valor FALSE será retornado. Se a chamada falhar, a função Win32 [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Classe CHttpConnection](../../mfc/reference/chttpconnection-class.md)<br/>
[Classe CFtpConnection](../../mfc/reference/cftpconnection-class.md)<br/>
[Classe CGopherConnection](../../mfc/reference/cgopherconnection-class.md)
