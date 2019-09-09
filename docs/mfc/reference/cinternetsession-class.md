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
ms.openlocfilehash: c9b8eaf51820dfcd08c1390c8645978fa403931d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505840"
---
# <a name="cinternetsession-class"></a>Classe CInternetSession

Cria e Inicializa uma única ou várias sessões de Internet simultâneas e, se necessário, descreve sua conexão com um servidor proxy.

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
|[CInternetSession::Close](#close)|Fecha a conexão com a Internet quando a sessão de Internet é encerrada.|
|[CInternetSession::EnableStatusCallback](#enablestatuscallback)|Estabelece uma rotina de retorno de chamada de status.|
|[CInternetSession::GetContext](#getcontext)|Fecha a conexão com a Internet quando a sessão de Internet é encerrada.|
|[CInternetSession::GetCookie](#getcookie)|Retorna cookies para a URL especificada e todas as suas URLs pai.|
|[CInternetSession::GetCookieLength](#getcookielength)|Recupera a variável especificando o comprimento do cookie armazenado no buffer.|
|[CInternetSession::GetFtpConnection](#getftpconnection)|Abre uma sessão FTP com um servidor. Faz logon no usuário.|
|[CInternetSession::GetGopherConnection](#getgopherconnection)|Abre um servidor gopher para um aplicativo que está tentando abrir uma conexão.|
|[CInternetSession::GetHttpConnection](#gethttpconnection)|Abre um servidor HTTP para um aplicativo que está tentando abrir uma conexão.|
|[CInternetSession::OnStatusCallback](#onstatuscallback)|Atualiza o status de uma operação quando o retorno de chamada de status está habilitado.|
|[CInternetSession::OpenURL](#openurl)|Analisa e abre uma URL.|
|[CInternetSession::SetCookie](#setcookie)|Define um cookie para a URL especificada.|
|[CInternetSession::SetOption](#setoption)|Define opções para a sessão da Internet.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CInternetSession:: Operator HINTERNET](#operator_hinternet)|Um identificador para a sessão da Internet atual.|

## <a name="remarks"></a>Comentários

Se sua conexão com a Internet deve ser mantida durante o período de um aplicativo, você pode `CInternetSession` criar um membro da classe [CWinApp](../../mfc/reference/cwinapp-class.md).

Depois de estabelecer uma sessão de Internet, você pode chamar [OpenURL](#openurl). `CInternetSession`em seguida, analisa a URL para você chamando a função global [AfxParseURL](internet-url-parsing-globals.md#afxparseurl). Independentemente de seu tipo de protocolo `CInternetSession` , o interpreta a URL e a gerencia para você. Ele pode lidar com solicitações de arquivos locais identificados com o recurso de URL "file://". `OpenURL`retornará um ponteiro para um objeto [CStdioFile](../../mfc/reference/cstdiofile-class.md) se o nome que você passar for um arquivo local.

Se você abrir uma URL em um servidor de Internet `OpenURL`usando o, poderá ler as informações do site. Se você quiser executar ações específicas do serviço (por exemplo, HTTP, FTP ou gopher) em arquivos localizados em um servidor, deverá estabelecer a conexão apropriada com esse servidor. Para abrir um determinado tipo de conexão diretamente a um serviço específico, use uma das seguintes funções de membro:

- [GetGopherConnection](#getgopherconnection) abrir uma conexão com um serviço gopher.

- [GetHttpConnection](#gethttpconnection) abrir uma conexão com um serviço http.

- [GetFtpConnection](#getftpconnection) abrir uma conexão com um serviço FTP.

[SetOption](#setoption) permite que você defina as opções de consulta da sua sessão, como valores de tempo limite, número de repetições e assim por diante.

`CInternetSession`as funções de membro [SetCookie](#setcookie), [GetCookie](#getcookie)e [GetCookieLength](#getcookielength) fornecem os meios para gerenciar um banco de dados de cookie Win32, por meio do qual os servidores e scripts mantêm informações de estado sobre a estação de trabalho do cliente.

Para obter mais informações sobre tarefas básicas de programação da Internet, [consulte o artigo primeiras etapas da Internet: WinInet](../../mfc/wininet-basics.md). Para obter informações gerais sobre como usar as classes do MFC WinInet, consulte o artigo [programação da Internet com o WinInet](../../mfc/win32-internet-extensions-wininet.md).

> [!NOTE]
> `CInternetSession`gerará um [AfxThrowNotSupportedException](exception-processing.md#afxthrownotsupportedexception) para tipos de serviço sem suporte. No momento, há suporte apenas para os seguintes tipos de serviço: FTP, HTTP, Gopher e arquivo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;`CInternetSession`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXINET. h

## <a name="cinternetsession"></a> CInternetSession::CInternetSession

Essa função de membro é chamada quando `CInternetSession` um objeto é criado.

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
Um ponteiro para uma cadeia de caracteres que identifica o nome do aplicativo ou da entidade que chama as funções da Internet (por exemplo, "navegador da Internet da Microsoft"). Se *pstrAgent* for NULL (o padrão), a estrutura chamará a função global [AfxGetAppName](application-information-and-management.md#afxgetappname), que retorna uma cadeia de caracteres terminada em nulo que contém o nome de um aplicativo. Alguns protocolos usam essa cadeia de caracteres para identificar seu aplicativo para o servidor.

*dwContext*<br/>
O identificador de contexto para a operação. *dwContext* identifica as informações de status da operação retornadas por [CInternetSession:: OnStatusCallback](#onstatuscallback). O padrão é definido como 1; no entanto, você pode atribuir explicitamente uma ID de contexto específica para a operação. O objeto e qualquer trabalho que ele faz será associado a essa ID de contexto.

*dwAccessType*<br/>
O tipo de acesso necessário. Os valores a seguir são válidos, exatamente um dos quais pode ser fornecido:

- INTERNET_OPEN_TYPE_PRECONFIG Conecte-se usando configurações pré-configuradas no registro. Esse tipo de acesso é definido como o padrão. Para se conectar por meio de um proxy TIS, defina *dwAccessType* para esse valor; em seguida, defina o registro adequadamente.

- INTERNET_OPEN_TYPE_DIRECT conectar-se diretamente à Internet.

- INTERNET_OPEN_TYPE_PROXY Conecte-se por meio de um proxy de CERN.

Para obter informações sobre como se conectar a diferentes tipos de proxies, consulte [etapas em um aplicativo cliente de FTP típico](../../mfc/steps-in-a-typical-ftp-client-application.md).

*pstrProxyName*<br/>
O nome do proxy CERN preferencial se *dwAccessType* for definido como INTERNET_OPEN_TYPE_PROXY. O padrão é NULL.

*pstrProxyBypass*<br/>
Um ponteiro para uma cadeia de caracteres que contém uma lista opcional de endereços de servidor. Esses endereços podem ser ignorados ao usar o acesso ao proxy. Se um valor nulo for fornecido, a lista de bypass será lida no registro. Esse parâmetro só será significativo se *dwAccessType* estiver definido como INTERNET_OPEN_TYPE_PROXY.

*dwFlags*<br/>
Indica várias opções de cache. O padrão é definido como 0. Os valores possíveis incluem:

- O INTERNET_FLAG_DONT_CACHE não armazena em cache os dados, seja localmente ou em qualquer servidor de gateway.

- As operações de download do INTERNET_FLAG_OFFLINE são satisfeitas somente por meio do cache persistente. Se o item não existir no cache, um código de erro apropriado será retornado. Esse sinalizador pode ser combinado com o **&#124;** operador **or () de OR bit** .

### <a name="remarks"></a>Comentários

`CInternetSession`é a primeira função de Internet chamada por um aplicativo. Ele inicializa estruturas de dados internas e se prepara para chamadas futuras do aplicativo.

Se nenhuma conexão com a Internet puder ser `CInternetSession` aberta, o lançará um [AfxThrowInternetException](internet-url-parsing-globals.md#afxthrowinternetexception).

### <a name="example"></a>Exemplo

Consulte o exemplo de [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md).

## <a name="close"></a>  CInternetSession::Close

Chame essa função de membro quando seu aplicativo terminar de usar `CInternetSession` o objeto.

```cpp
virtual void Close();
```

### <a name="example"></a>Exemplo

Consulte o exemplo de [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md).

## <a name="enablestatuscallback"></a>  CInternetSession::EnableStatusCallback

Chame essa função de membro para habilitar o retorno de chamada de status.

```cpp
BOOL EnableStatusCallback(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
Especifica se o retorno de chamada está habilitado ou desabilitado. O padrão é TRUE.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, determine a causa da falha examinando o objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) gerado.

### <a name="remarks"></a>Comentários

Ao lidar com o retorno de chamada de status, você pode fornecer o status sobre o progresso da operação (como resolução de nome, conexão com o servidor e assim por diante) na barra de status do aplicativo. A exibição do status da operação é especialmente desejável durante uma operação de longo prazo.

Como os retornos de chamada ocorrem durante o processamento da solicitação, o aplicativo deve gastar o menor tempo possível no retorno de chamada para evitar a degradação da taxa de transferência de dados para a rede. Por exemplo, colocar uma caixa de diálogo em um retorno de chamada pode ser uma operação demorada que o servidor encerra a solicitação.

O retorno de chamada de status não pode ser removido, contanto que qualquer retorno de chamada esteja pendente.

Para tratar quaisquer operações de forma assíncrona, você deve criar seu próprio thread ou usar as funções do WinInet sem MFC.

## <a name="getcontext"></a>  CInternetSession::GetContext

Chame essa função de membro para obter o valor de contexto para uma sessão de aplicativo específica.

```cpp
DWORD_PTR GetContext() const;
```

### <a name="return-value"></a>Valor de retorno

O identificador de contexto definido pelo aplicativo.

### <a name="remarks"></a>Comentários

[OnStatusCallback](#onstatuscallback) usa a ID de contexto retornada `GetContext` pelo para relatar o status de um aplicativo específico. Por exemplo, quando um usuário ativa uma solicitação da Internet que envolve o retorno de informações de status, o retorno de chamada de status usa a ID de contexto para relatar o status nessa solicitação específica. Se o usuário ativar duas solicitações de Internet separadas que envolvem o retorno de informações `OnStatusCallback` de status, o usará os identificadores de contexto para retornar o status sobre suas solicitações correspondentes. Consequentemente, o identificador de contexto é usado para todas as operações de retorno de chamada de status e é associado à sessão até que a sessão seja encerrada.

Para obter mais informações sobre operações assíncronas, [consulte o artigo etapas da Internet primeiro: WinInet](../../mfc/wininet-basics.md).

## <a name="getcookie"></a>  CInternetSession::GetCookie

Essa função de membro implementa o comportamento da função [InternetGetCookie](/windows/win32/api/wininet/nf-wininet-internetgetcookiew)do Win32, conforme descrito no SDK do Windows.

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
Na primeira sobrecarga, um ponteiro para uma cadeia de caracteres que contém o endereço do buffer que recebe os dados do cookie. Esse valor pode ser nulo. Na segunda sobrecarga, uma referência a um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) para receber os dados do cookie.

*dwBufLen*<br/>
A variável que especifica o tamanho do buffer *pstrCookieData* . Se a função for realizada com sucesso, o buffer receberá a quantidade de dados copiados para o buffer *pstrCookieData* . Se *pstrCookieData* for NULL, esse parâmetro receberá um valor que especifica o tamanho do buffer necessário para copiar todos os dados do cookie.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro se for bem-sucedido ou FALSE caso contrário. Se a chamada falhar, chame [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) da função Win32 para determinar a causa do erro. Os seguintes valores de erro se aplicam:

- ERROR_NO_MORE_ITEMS não há nenhum cookie para a URL especificada e todos os seus pais.

- ERROR_INSUFFICIENT_BUFFER o valor passado em *dwBufLen* é insuficiente para copiar todos os dados do cookie. O valor retornado em *dwBufLen* é o tamanho do buffer necessário para obter todos os dados.

### <a name="remarks"></a>Comentários

Na segunda sobrecarga, o MFC recupera os dados do cookie para o `CString` objeto fornecido.

## <a name="getcookielength"></a>  CInternetSession::GetCookieLength

Chame essa função de membro para obter o comprimento do cookie armazenado no buffer.

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

Um valor DWORD que indica o comprimento do cookie, armazenado no buffer. Zero se nenhum cookie com o nome indicado por *pstrCookieName* existir.

### <a name="remarks"></a>Comentários

Esse valor é usado pelo [GetCookie](#getcookie).

## <a name="getftpconnection"></a>  CInternetSession::GetFtpConnection

Chame essa função de membro para estabelecer uma conexão FTP e obter um ponteiro para `CFtpConnection` um objeto.

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
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do usuário para fazer logon. Se for NULL, o padrão será Anonymous.

*pstrPassword*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que especifica a senha a ser usada para fazer logon. Se *pstrPassword* e *pstrUserName* forem nulos, a senha anônima padrão será o nome de email do usuário. Se *pstrPassword* for nulo (ou uma cadeia de caracteres vazia), mas *PSTRUSERNAME* não for NULL, uma senha em branco será usada. A tabela a seguir descreve o comportamento para as quatro configurações possíveis de *pstrUserName* e *pstrPassword*:

| *pstrUserName*  | *pstrPassword*  | Nome de usuário enviado ao servidor FTP | Senha enviada ao servidor FTP |
|-----------------|-----------------|-----------------------------|-----------------------------|
|   NULL ou ""   |   NULL ou ""   |         modo         |      Nome de email do usuário      |
| Cadeia de caracteres não nula |   NULL ou ""   |       *pstrUserName*        |             " "             |
|      NULL       | Cadeia de caracteres não nula |            ERROR            |            ERROR            |
| Cadeia de caracteres não nula | Cadeia de caracteres não nula |       *pstrUserName*        |       *pstrPassword*        |

*nPort*<br/>
Um número que identifica a porta TCP/IP a ser usada no servidor.

*bPassive*<br/>
Especifica o modo passivo ou ativo para esta sessão de FTP. Se definido como true, ele definirá a API `dwFlag` do Win32 como INTERNET_FLAG_PASSIVE.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um objeto [CFtpConnection](../../mfc/reference/cftpconnection-class.md) . Se a chamada falhar, determine a causa da falha examinando o objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) gerado.

### <a name="remarks"></a>Comentários

`GetFtpConnection`conecta-se a um servidor FTP e cria e retorna um ponteiro para `CFTPConnection` um objeto. Ele não executa nenhuma operação específica no servidor. Se você pretende ler ou gravar em arquivos, por exemplo, você deve executar essas operações como etapas separadas. Consulte as classes [CFtpConnection](../../mfc/reference/cftpconnection-class.md) e [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md) para obter informações sobre como procurar arquivos, abrir arquivos e ler ou gravar em arquivos. Consulte o artigo [programação da Internet com o WinInet](../../mfc/win32-internet-extensions-wininet.md) para ver as etapas em executando tarefas comuns de conexão de FTP.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md).

## <a name="getgopherconnection"></a>  CInternetSession::GetGopherConnection

Chame essa função de membro para estabelecer uma nova conexão gopher e obter um ponteiro para `CGopherConnection` um objeto.

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
Um número que identifica a porta TCP/IP a ser usada no servidor.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um objeto [CGopherConnection](../../mfc/reference/cgopherconnection-class.md) . Se a chamada falhar, determine a causa da falha examinando o objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) gerado.

### <a name="remarks"></a>Comentários

`GetGopherConnection`conecta-se a um servidor gopher e cria e retorna um ponteiro para `CGopherConnection` um objeto. Ele não executa nenhuma operação específica no servidor. Se você pretende ler ou gravar dados, por exemplo, você deve executar essas operações como etapas separadas. Consulte as classes [CGopherConnection](../../mfc/reference/cgopherconnection-class.md), [CGopherFile](../../mfc/reference/cgopherfile-class.md)e [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md) para obter informações sobre como procurar arquivos, abrir arquivos e ler ou gravar em arquivos. Para obter informações sobre como procurar um site FTP, consulte a função membro [OpenURL](#openurl). Consulte o artigo [programação da Internet com o WinInet](../../mfc/win32-internet-extensions-wininet.md) para ver as etapas em executando tarefas comuns de conexão do Gopher.

## <a name="gethttpconnection"></a>  CInternetSession::GetHttpConnection

Chame essa função de membro para estabelecer uma conexão http e obter um ponteiro para `CHttpConnection` um objeto.

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
Um número que identifica a porta TCP/IP a ser usada no servidor.

*pstrUserName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome de usuário.

*pstrPassword*<br/>
Um ponteiro para uma cadeia de caracteres que contém a senha de acesso.

*dwflags*<br/>
Qualquer combinação dos `INTERNET_FLAG_*` sinalizadores. Consulte a tabela na seção **comentários** de [CHttpConnection:: OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest) para obter uma descrição dos valores de *dwFlags* .

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um objeto [CHttpConnection](../../mfc/reference/chttpconnection-class.md) . Se a chamada falhar, determine a causa da falha examinando o objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) gerado.

### <a name="remarks"></a>Comentários

`GetHttpConnection`conecta-se a um servidor http e cria e retorna um ponteiro para `CHttpConnection` um objeto. Ele não executa nenhuma operação específica no servidor. Se você pretende consultar um cabeçalho HTTP, por exemplo, você deve executar essa operação como uma etapa separada. Consulte as classes [CHttpConnection](../../mfc/reference/chttpconnection-class.md) e [CHttpFile](../../mfc/reference/chttpfile-class.md) para obter informações sobre as operações que você pode executar usando uma conexão com um servidor http. Para obter informações sobre como procurar um site HTTP, consulte a função membro [OpenURL](#openurl). Consulte o artigo [programação da Internet com o WinInet](../../mfc/win32-internet-extensions-wininet.md) para ver as etapas em executando tarefas comuns de conexão http.

## <a name="onstatuscallback"></a>  CInternetSession::OnStatusCallback

Essa função de membro é chamada pelo Framework para atualizar o status quando o retorno de chamada de status é habilitado e uma operação está pendente.

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
Um código de status que indica por que o retorno de chamada está sendo feito. Consulte **comentários** para obter uma tabela de valores possíveis.

*lpvStatusInformation*<br/>
Um ponteiro para um buffer que contém informações pertinentes a esse retorno de chamada.

*dwStatusInformationLength*<br/>
O tamanho de *lpvStatusInformation*.

### <a name="remarks"></a>Comentários

Você deve primeiro chamar [EnableStatusCallback](#enablestatuscallback) para tirar proveito do retorno de chamada de status.

O parâmetro *dwInternetStatus* indica a operação que está sendo executada e determina qual será o conteúdo de *lpvStatusInformation* . *dwStatusInformationLength* indica o comprimento dos dados incluídos em *lpvStatusInformation*. Os valores de status a seguir para *dwInternetStatus* são definidos da seguinte maneira:

|Valor|Significado|
|-----------|-------------|
|INTERNET_STATUS_RESOLVING_NAME|Procurando o endereço IP do nome contido em *lpvStatusInformation*.|
|INTERNET_STATUS_NAME_RESOLVED|O endereço IP do nome contido no *lpvStatusInformation*foi encontrado com êxito.|
|INTERNET_STATUS_CONNECTING_TO_SERVER|Conectando-se ao endereço de soquete ([SOCKADDR](/windows/win32/winsock/sockaddr-2)) apontado por *lpvStatusInformation*.|
|INTERNET_STATUS_CONNECTED_TO_SERVER|Conectado com êxito ao endereço de soquete (SOCKADDR) apontado por *lpvStatusInformation*.|
|INTERNET_STATUS_SENDING_REQUEST|Enviando a solicitação de informações para o servidor. O parâmetro *lpvStatusInformation* é nulo.|
|INTERNET_STATUS_ REQUEST_SENT|Solicitação de informações enviada com êxito para o servidor. O parâmetro *lpvStatusInformation* é nulo.|
|INTERNET_STATUS_RECEIVING_RESPONSE|Aguardando o servidor responder a uma solicitação. O parâmetro *lpvStatusInformation* é nulo.|
|INTERNET_STATUS_RESPONSE_RECEIVED|Resposta do servidor recebida com êxito. O parâmetro *lpvStatusInformation* é nulo.|
|INTERNET_STATUS_CLOSING_CONNECTION|Fechando a conexão com o servidor. O parâmetro *lpvStatusInformation* é nulo.|
|INTERNET_STATUS_CONNECTION_CLOSED|Conexão com o servidor fechada com êxito. O parâmetro *lpvStatusInformation* é nulo.|
|INTERNET_STATUS_HANDLE_CREATED|Usado pela função de API do Win32 [InternetConnect](/windows/win32/api/wininet/nf-wininet-internetconnectw) para indicar que criou o novo identificador. Isso permite que o aplicativo chame a função do Win32 [InternetCloseHandle](/windows/win32/api/wininet/nf-wininet-internetclosehandle) de outro thread se a conexão estiver demorando muito. Consulte o Windows SDKfor mais informações sobre essas funções.|
|INTERNET_STATUS_HANDLE_CLOSING|Valor do identificador encerrado com êxito.|

Substitua essa função de membro para exigir alguma ação antes que uma rotina de retorno de chamada de status seja executada.

> [!NOTE]
> Os retornos de chamada de status precisam de proteção de estado de thread. Se você estiver usando o MFC em uma biblioteca compartilhada, adicione a seguinte linha ao início da sua substituição:

[!code-cpp[NVC_MFCHtmlHttp#8](../../mfc/reference/codesnippet/cpp/cinternetsession-class_1.cpp)]

Para obter mais informações sobre operações assíncronas, [consulte o artigo etapas da Internet primeiro: WinInet](../../mfc/wininet-basics.md).

## <a name="openurl"></a>  CInternetSession::OpenURL

Chame essa função de membro para enviar a solicitação especificada ao servidor HTTP e permitir que o cliente especifique cabeçalhos RFC822, MIME ou HTTP adicionais para enviar junto com a solicitação.

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
Um ponteiro para o nome da URL para começar a leitura. Somente as URLs que começam com file:, FTP:, gopher: ou http: têm suporte. Asserts se *pstrURL* for nulo.

*dwContext*<br/>
Um valor definido pelo aplicativo passado com o identificador retornado no retorno de chamada.

*dwFlags*<br/>
Os sinalizadores que descrevem como lidar com essa conexão. Consulte **comentários** para obter mais informações sobre os sinalizadores válidos. Os sinalizadores válidos são:

- INTERNET_FLAG_TRANSFER_ASCII o padrão. Transfira o arquivo como texto ASCII.

- INTERNET_FLAG_TRANSFER_BINARY transferir o arquivo como um arquivo binário.

- INTERNET_FLAG_RELOAD obter os dados da transmissão, mesmo se ele estiver armazenado em cache localmente.

- O INTERNET_FLAG_DONT_CACHE não armazena em cache os dados, seja localmente ou em qualquer gateway.

- INTERNET_FLAG_SECURE Esse sinalizador é aplicável somente a solicitações HTTP. Ele solicita transações seguras na transmissão com protocolo SSL ou PCT.

- INTERNET_OPEN_FLAG_USE_EXISTING_CONNECT se possível, reutilize as conexões existentes para o servidor para novas solicitações geradas pelo `OpenUrl` em vez de criar uma nova sessão para cada solicitação de conexão.

- INTERNET_FLAG_PASSIVE usado para um site FTP. Usa a semântica de FTP passiva. Usado com [CInternetConnection](../../mfc/reference/cinternetconnection-class.md) de `OpenURL`.

*pstrHeaders*<br/>
Um ponteiro para uma cadeia de caracteres que contém os cabeçalhos a serem enviados ao servidor HTTP.

*dwHeadersLength*<br/>
O comprimento, em caracteres, dos cabeçalhos adicionais. Se isso for-1L e *pstrHeaders* for não nulo, *pstrHeaders* será considerado como terminação zero e o comprimento será calculado.

### <a name="return-value"></a>Valor de retorno

Retorna um identificador de arquivo somente para serviços de Internet FTP, GOPHER, HTTP e tipo de arquivo. Retornará NULL se a análise não tiver sido bem-sucedida.

O ponteiro que `OpenURL` retorna depende do tipo de serviço de *pstrURL*. A tabela a seguir ilustra os possíveis `OpenURL` ponteiros podem retornar.

|Tipo de URL|Retorna|
|--------------|-------------|
|file://|`CStdioFile*`|
|http://|`CHttpFile*`|
|gopher://|`CGopherFile*`|
|ftp://|`CInternetFile*`|

### <a name="remarks"></a>Comentários

O parâmetro *dwFlags* deve incluir INTERNET_FLAG_TRANSFER_ASCII ou INTERNET_FLAG_TRANSFER_BINARY, mas não ambos. Os sinalizadores restantes podem ser combinados com **o operador OR** () **&#124;** de bits ().

`OpenURL`, que encapsula a função `InternetOpenURL`do Win32, permite apenas baixar, recuperar e ler os dados de um servidor de Internet. `OpenURL`Não permite nenhuma manipulação de arquivo em um local remoto, portanto, não requer nenhum objeto [CInternetConnection](../../mfc/reference/cinternetconnection-class.md) .

Para usar funções específicas de conexão (ou seja, específicas de protocolo), como gravar em um arquivo, você deve abrir uma sessão e, em seguida, abrir um determinado tipo de conexão e, em seguida, usar essa conexão para abrir um arquivo no modo desejado. Consulte `CInternetConnection` para obter mais informações sobre funções específicas de conexão.

## <a name="operator_hinternet"></a>Operador CInternetSession:: Operator HINTERNET

Use esse operador para obter o identificador do Windows para a sessão atual da Internet.

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
Um ponteiro para uma cadeia de caracteres terminada em nulo que especifica a URL para a qual o cookie deve ser definido.

*pstrCookieName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do cookie.

*pstrCookieData*<br/>
Um ponteiro para uma cadeia de caracteres que contém os dados de cadeia de caracteres reais a serem associados à URL.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro se for bem-sucedido ou FALSE caso contrário. Para obter o código de erro específico, chame`GetLastError.`

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [InternetSetCookie](/windows/win32/api/wininet/nf-wininet-internetsetcookiew)do Win32, conforme descrito na SDK do Windows.

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
A opção da Internet a ser definida. Consulte [sinalizadores de opção](/windows/win32/WinInet/option-flags) no SDKfor do Windows uma lista das possíveis opções.

*lpBuffer*<br/>
Um buffer que contém a configuração de opção.

*dwBufferLength*<br/>
O comprimento de *lpBuffer* ou o tamanho de *dwValue*.

*dwValue*<br/>
Um DWORD que contém a configuração de opção.

*dwFlags*<br/>
Indica várias opções de cache. O padrão é definido como 0. Os valores possíveis incluem:

- O INTERNET_FLAG_DONT_CACHE não armazena em cache os dados, seja localmente ou em qualquer servidor de gateway.

- As operações de download do INTERNET_FLAG_OFFLINE são satisfeitas somente por meio do cache persistente. Se o item não existir no cache, um código de erro apropriado será retornado. Esse sinalizador pode ser combinado com o **&#124;** operador **or () de OR bit** .

### <a name="return-value"></a>Valor de retorno

Se a operação foi bem-sucedida, um valor de TRUE será retornado. Se ocorrer um erro, um valor de FALSE será retornado. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Classe CHttpConnection](../../mfc/reference/chttpconnection-class.md)<br/>
[Classe CFtpConnection](../../mfc/reference/cftpconnection-class.md)<br/>
[Classe CGopherConnection](../../mfc/reference/cgopherconnection-class.md)
