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
ms.openlocfilehash: ddd7ca6676805e6de1b7afb5ebc77733701dfef9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372388"
---
# <a name="cinternetsession-class"></a>Classe CInternetSession

Cria e inicializa uma única ou várias sessões simultâneas da Internet e, se necessário, descreve sua conexão com um servidor proxy.

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
|[CInternetSession::Fechar](#close)|Fecha a conexão com a Internet quando a sessão de Internet é encerrada.|
|[CInternetSession::EnableStatusCallback](#enablestatuscallback)|Estabelece uma rotina de retorno de chamada de status.|
|[CInternetSession::GetContext](#getcontext)|Fecha a conexão com a Internet quando a sessão de Internet é encerrada.|
|[CInternetSession::GetCookie](#getcookie)|Devolve cookies para a URL especificada e todas as URLs pai.|
|[CInternetSession::GetCookieLength](#getcookielength)|Recupera a variável especificando o comprimento do cookie armazenado no buffer.|
|[CInternetSession::GetFtpConexão](#getftpconnection)|Abre uma sessão de FTP com um servidor. Logs no usuário.|
|[CInternetSession::GetGopherConnection](#getgopherconnection)|Abre um servidor gopher para um aplicativo que está tentando abrir uma conexão.|
|[CInternetSession::gethttpConnection](#gethttpconnection)|Abre um servidor HTTP para um aplicativo que está tentando abrir uma conexão.|
|[CInternetSession::OnStatusCallback](#onstatuscallback)|Atualiza o status de uma operação quando o retorno de chamada de status é ativado.|
|[CInternetSession::OpenURL](#openurl)|Analisa e abre uma URL.|
|[CInternetSessão::SetCookie](#setcookie)|Define um cookie para a URL especificada.|
|[CInternetSessão::SetOption](#setoption)|Define opções para a sessão da Internet.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CInternetSession::operador HINTERNET](#operator_hinternet)|Uma alça para a sessão atual da Internet.|

## <a name="remarks"></a>Comentários

Se sua conexão com a Internet deve ser mantida `CInternetSession` durante a duração de um aplicativo, você pode criar um membro da classe [CWinApp](../../mfc/reference/cwinapp-class.md).

Depois de estabelecer uma sessão na Internet, você pode chamar [OpenURL](#openurl). `CInternetSession`em seguida, analisa a URL para você chamando a função global [AfxParseURL](internet-url-parsing-globals.md#afxparseurl). Independentemente do seu `CInternetSession` tipo de protocolo, interpreta a URL e a gerencia para você. Ele pode lidar com solicitações de arquivos locais identificados com o recurso URL "file://". `OpenURL`retornará um ponteiro para um objeto [CStdioFile](../../mfc/reference/cstdiofile-class.md) se o nome que você passar for um arquivo local.

Se você abrir uma URL `OpenURL`em um servidor da Internet usando, você pode ler informações do site. Se você quiser executar ações específicas de serviço (por exemplo, HTTP, FTP ou gopher) em arquivos localizados em um servidor, você deve estabelecer a conexão apropriada com esse servidor. Para abrir um determinado tipo de conexão diretamente a um determinado serviço, use uma das seguintes funções de membro:

- [GetGopherConnection](#getgopherconnection) para abrir uma conexão com um serviço gopher.

- [ObtenhahttpConnection](#gethttpconnection) para abrir uma conexão com um serviço HTTP.

- [GetFtpConnection](#getftpconnection) para abrir uma conexão a um serviço FTP.

[SetOption](#setoption) permite definir as opções de consulta da sessão, como valores de tempo extra, número de repetições e assim por diante.

`CInternetSession`funções de membro [SetCookie,](#setcookie) [GetCookie](#getcookie)e [GetCookieLength](#getcookielength) fornecem os meios para gerenciar um banco de dados de cookies Win32, através do qual servidores e scripts mantêm informações estaduais sobre a estação de trabalho do cliente.

Para obter mais informações sobre tarefas básicas de programação da Internet, consulte o artigo [Internet First Steps: WinInet](../../mfc/wininet-basics.md). Para obter informações gerais sobre o uso das classes MFC WinInet, consulte o artigo [Programação na Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md).

> [!NOTE]
> `CInternetSession`lançará [um AfxThrowNotSupportedException](exception-processing.md#afxthrownotsupportedexception) para tipos de serviço não suportados. Apenas os seguintes tipos de serviço são suportados atualmente: FTP, HTTP, gopher e file.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;`CInternetSession`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="cinternetsessioncinternetsession"></a><a name="cinternetsession"></a>CInternetSession::CInternetSession

Essa função de membro `CInternetSession` é chamada quando um objeto é criado.

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
Um ponteiro para uma seqüência que identifica o nome do aplicativo ou entidade que chama as funções da Internet (por exemplo, "Microsoft Internet Browser"). Se *pstrAgent* for NULL (o padrão), a estrutura chamará a função global [AfxGetAppName](application-information-and-management.md#afxgetappname), que retorna uma seqüência de terminadas nula contendo o nome de um aplicativo. Alguns protocolos usam essa string para identificar seu aplicativo para o servidor.

*Dwcontext*<br/>
O identificador de contexto para a operação. *dwContext* identifica as informações de status da operação retornadas por [CInternetSession::OnStatusCallback](#onstatuscallback). O padrão é definido como 1; no entanto, você pode atribuir explicitamente um ID de contexto específico para a operação. O objeto e qualquer trabalho que ele fizer será associado a esse ID de contexto.

*Dwaccesstype*<br/>
O tipo de acesso necessário. Os seguintes são valores válidos, exatamente um dos quais pode ser fornecido:

- INTERNET_OPEN_TYPE_PRECONFIG Conecte-se usando configurações pré-configuradas no registro. Este tipo de acesso é definido como padrão. Para conectar através de um proxy TIS, defina *dwAccessType* a esse valor; em seguida, você definir o registro apropriadamente.

- INTERNET_OPEN_TYPE_DIRECT Conecte-se diretamente à Internet.

- INTERNET_OPEN_TYPE_PROXY Conecte-se através de um proxy CERN.

Para obter informações sobre como se conectar com diferentes tipos de proxies, consulte [Passos em um aplicativo típico do cliente FTP](../../mfc/steps-in-a-typical-ftp-client-application.md).

*pstrProxyName*<br/>
O nome do proxy CERN preferido se *dwAccessType* for definido como INTERNET_OPEN_TYPE_PROXY. O padrão é NULO.

*pstrProxyBypass*<br/>
Um ponteiro para uma seqüência contendo uma lista opcional de endereços de servidor. Esses endereços podem ser ignorados ao usar o acesso proxy. Se um valor NULL for fornecido, a lista de desvioserá lida no registro. Este parâmetro só é significativo se *o dwAccessType* estiver definido como INTERNET_OPEN_TYPE_PROXY.

*dwFlags*<br/>
Indica várias opções de cache. O padrão é definido como 0. Os valores possíveis incluem:

- INTERNET_FLAG_DONT_CACHE Não faça cache de dados, localmente ou em nenhum servidor gateway.

- INTERNET_FLAG_OFFLINE as operações de download são satisfeitas apenas através do cache persistente. Se o item não existir no cache, um código de erro apropriado será devolvido. Esta bandeira pode ser combinada com o operador bitwise **OR** **(&#124;). **

### <a name="remarks"></a>Comentários

`CInternetSession`é a primeira função de Internet chamada por um aplicativo. Ele inicializa estruturas internas de dados e se prepara para chamadas futuras do aplicativo.

Se nenhuma conexão com `CInternetSession` a Internet puder ser aberta, será aberta uma [AfxThrowInternetException](internet-url-parsing-globals.md#afxthrowinternetexception).

### <a name="example"></a>Exemplo

Veja o exemplo de [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md).

## <a name="cinternetsessionclose"></a><a name="close"></a>CInternetSession::Fechar

Chame esta função de membro quando `CInternetSession` seu aplicativo tiver terminado usando o objeto.

```cpp
virtual void Close();
```

### <a name="example"></a>Exemplo

Veja o exemplo de [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md).

## <a name="cinternetsessionenablestatuscallback"></a><a name="enablestatuscallback"></a>CInternetSession::EnableStatusCallback

Ligue para esta função de membro para ativar o retorno de status.

```cpp
BOOL EnableStatusCallback(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
Especifica se o retorno de chamada está ativado ou desativado. O padrão é TRUE.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, determine a causa da falha examinando o objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) lançado.

### <a name="remarks"></a>Comentários

Ao lidar com o retorno de status, você pode fornecer status sobre o progresso da operação (como resolver nome, conectar-se ao servidor e assim por diante) na barra de status do aplicativo. Exibir o status da operação é especialmente desejável durante uma operação de longo prazo.

Como os retornos de chamada ocorrem durante o processamento da solicitação, o aplicativo deve gastar o menor tempo possível no retorno de chamada para evitar a degradação do throughput de dados na rede. Por exemplo, colocar uma caixa de diálogo em um retorno de chamada pode ser uma operação tão longa que o servidor encerra a solicitação.

O retorno de chamada de status não pode ser removido enquanto houver retorno de chamada.

Para lidar com qualquer operação assíncrona, você deve criar seu próprio segmento ou usar as funções WinInet sem MFC.

## <a name="cinternetsessiongetcontext"></a><a name="getcontext"></a>CInternetSession::GetContext

Chame essa função de membro para obter o valor de contexto de uma determinada sessão de aplicativo.

```cpp
DWORD_PTR GetContext() const;
```

### <a name="return-value"></a>Valor retornado

O identificador de contexto definido pelo aplicativo.

### <a name="remarks"></a>Comentários

[OnStatusCallback](#onstatuscallback) usa o ID `GetContext` de contexto retornado para relatar o status de um determinado aplicativo. Por exemplo, quando um usuário ativa uma solicitação da Internet que envolve o retorno de informações de status, o retorno de status usa o ID de contexto para relatar o status nessa solicitação específica. Se o usuário ativar duas solicitações de Internet `OnStatusCallback` separadas que envolvem o retorno de informações de status, use os identificadores de contexto para retornar o status sobre suas solicitações correspondentes. Consequentemente, o identificador de contexto é usado para todas as operações de retorno de chamada de status, e está associado à sessão até que a sessão seja encerrada.

Para obter mais informações sobre operações assíncronas, consulte o artigo [Primeiros Passos da Internet: WinInet](../../mfc/wininet-basics.md).

## <a name="cinternetsessiongetcookie"></a><a name="getcookie"></a>CInternetSession::GetCookie

Esta função de membro implementa o comportamento da função Win32 [InternetGetCookie](/windows/win32/api/wininet/nf-wininet-internetgetcookiew), conforme descrito no SDK do Windows.

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

*PstrUrl*<br/>
Um ponteiro para uma seqüência contendo a URL.

*pstrCookieName*<br/>
Um ponteiro para uma seqüência contendo o nome do cookie para obter para a URL especificada.

*pstrCookieData*<br/>
Na primeira sobrecarga, um ponteiro para uma seqüência contendo o endereço do buffer que recebe os dados do cookie. Este valor pode ser NULO. Na segunda sobrecarga, uma referência a um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) para receber os dados do cookie.

*Dwbuflen*<br/>
A variável especificando o tamanho do buffer *pstrCookieData.* Se a função for bem-sucedida, o buffer receberá a quantidade de dados copiados para o buffer *pstrCookieData.* Se *pstrCookieData* for NULL, este parâmetro receberá um valor que especifica o tamanho do buffer necessário para copiar todos os dados do cookie.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se for bem sucedido, ou FALSO de outra forma. Se a chamada falhar, ligue para a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) para determinar a causa do erro. Os seguintes valores de erro se aplicam:

- ERROR_NO_MORE_ITEMS Não há cookie para a URL especificada e todos os seus pais.

- ERROR_INSUFFICIENT_BUFFER O valor passado em *dwBufLen* é insuficiente para copiar todos os dados do cookie. O valor devolvido em *dwBufLen* é o tamanho do buffer necessário para obter todos os dados.

### <a name="remarks"></a>Comentários

Na segunda sobrecarga, o MFC recupera os `CString` dados do cookie no objeto fornecido.

## <a name="cinternetsessiongetcookielength"></a><a name="getcookielength"></a>CInternetSession::GetCookieLength

Ligue para esta função de membro para obter o comprimento do cookie armazenado no buffer.

```cpp
static DWORD GetCookieLength(
    LPCTSTR pstrUrl,
    LPCTSTR pstrCookieName);
```

### <a name="parameters"></a>Parâmetros

*PstrUrl*<br/>
Um ponteiro para uma string contendo a URL

*pstrCookieName*<br/>
Um ponteiro para uma seqüência contendo o nome do cookie.

### <a name="return-value"></a>Valor retornado

Um valor DWORD indicando o comprimento do cookie, armazenado no buffer. Zero se nenhum cookie com o nome indicado por *pstrCookieName* existir.

### <a name="remarks"></a>Comentários

Este valor é usado por [GetCookie](#getcookie).

## <a name="cinternetsessiongetftpconnection"></a><a name="getftpconnection"></a>CInternetSession::GetFtpConexão

Ligue para esta função de membro para estabelecer `CFtpConnection` uma conexão FTP e obter um ponteiro para um objeto.

```cpp
CFtpConnection* GetFtpConnection(
    LPCTSTR pstrServer,
    LPCTSTR pstrUserName = NULL,
    LPCTSTR pstrPassword = NULL,
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER,
    BOOL bPassive = FALSE);
```

### <a name="parameters"></a>Parâmetros

*PstrServer*<br/>
Um ponteiro para uma seqüência contendo o nome do servidor FTP.

*pstrUserName*<br/>
Pointer para uma seqüência de terminadas nula que especifica o nome do usuário para fazer login. Se NULO, o padrão é anônimo.

*Pstrpassword*<br/>
Um ponteiro para uma seqüência de terminadas nula que especifica a senha a ser usada para fazer login. Se tanto *pstrPassword* quanto *pstrUserName* forem NULL, a senha anônima padrão é o nome de e-mail do usuário. Se *pstrPassword* for NULL (ou uma seqüência de string vazia) mas *pstrUserName* não for NULL, uma senha em branco será usada. A tabela a seguir descreve o comportamento das quatro configurações possíveis de *pstrUserName* e *pstrPassword*:

| *pstrUserName*  | *Pstrpassword*  | Nome de usuário enviado para servidor FTP | Senha enviada para servidor FTP |
|-----------------|-----------------|-----------------------------|-----------------------------|
|   NULO ou " "   |   NULO ou " "   |         "anônimo"         |      Nome de e-mail do usuário      |
| String não-nula |   NULO ou " "   |       *pstrUserName*        |             " "             |
|      NULO       | String não-nula |            ERROR            |            ERROR            |
| String não-nula | String não-nula |       *pstrUserName*        |       *Pstrpassword*        |

*nPort*<br/>
Um número que identifica a porta TCP/IP para usar no servidor.

*bPassivo*<br/>
Especifica o modo passivo ou ativo para esta sessão FTP. Se definido como TRUE, ele define `dwFlag` a API Win32 para INTERNET_FLAG_PASSIVE.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CFtpConnection.](../../mfc/reference/cftpconnection-class.md) Se a chamada falhar, determine a causa da falha examinando o objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) lançado.

### <a name="remarks"></a>Comentários

`GetFtpConnection`se conecta a um servidor FTP e cria `CFTPConnection` e retorna um ponteiro para um objeto. Ele não realiza nenhuma operação específica no servidor. Se você pretende ler ou gravar em arquivos, por exemplo, você deve executar essas operações como etapas separadas. Consulte as classes [CFtpConnection](../../mfc/reference/cftpconnection-class.md) e [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md) para obter informações sobre a busca de arquivos, abertura de arquivos e leitura ou escrita em arquivos. Consulte o artigo [Programação da Internet com o WinInet](../../mfc/win32-internet-extensions-wininet.md) para obter etapas na execução de tarefas comuns de conexão FTP.

### <a name="example"></a>Exemplo

Veja o exemplo de [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md).

## <a name="cinternetsessiongetgopherconnection"></a><a name="getgopherconnection"></a>CInternetSession::GetGopherConnection

Chame esta função de membro para estabelecer uma nova `CGopherConnection` conexão gopher e obter um ponteiro para um objeto.

```cpp
CGopherConnection* GetGopherConnection(
    LPCTSTR pstrServer,
    LPCTSTR pstrUserName = NULL,
    LPCTSTR pstrPassword = NULL,
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER);
```

### <a name="parameters"></a>Parâmetros

*PstrServer*<br/>
Um ponteiro para uma seqüência contendo o nome do servidor gopher.

*pstrUserName*<br/>
Um ponteiro para uma string contendo o nome de usuário.

*Pstrpassword*<br/>
Um ponteiro para uma seqüência contendo a senha de acesso.

*nPort*<br/>
Um número que identifica a porta TCP/IP para usar no servidor.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CGopherConnection.](../../mfc/reference/cgopherconnection-class.md) Se a chamada falhar, determine a causa da falha examinando o objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) lançado.

### <a name="remarks"></a>Comentários

`GetGopherConnection`conecta-se a um servidor gopher e cria `CGopherConnection` e retorna um ponteiro para um objeto. Ele não realiza nenhuma operação específica no servidor. Se você pretende ler ou gravar dados, por exemplo, você deve executar essas operações como etapas separadas. Consulte as classes [CGopherConnection,](../../mfc/reference/cgopherconnection-class.md) [CGopherFile](../../mfc/reference/cgopherfile-class.md)e [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md) para obter informações sobre a busca de arquivos, abertura de arquivos e leitura ou escrita em arquivos. Para obter informações sobre a navegação em um site FTP, consulte a função de membro [OpenURL](#openurl). Consulte o artigo [Programação da Internet com o WinInet](../../mfc/win32-internet-extensions-wininet.md) para obter etapas na execução de tarefas comuns de conexão gopher.

## <a name="cinternetsessiongethttpconnection"></a><a name="gethttpconnection"></a>CInternetSession::gethttpConnection

Ligue para esta função de membro para estabelecer `CHttpConnection` uma conexão HTTP e obtenha um ponteiro para um objeto.

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

*PstrServer*<br/>
Um ponteiro para uma seqüência contendo o nome do servidor HTTP.

*nPort*<br/>
Um número que identifica a porta TCP/IP para usar no servidor.

*pstrUserName*<br/>
Um ponteiro para uma string contendo o nome de usuário.

*Pstrpassword*<br/>
Um ponteiro para uma seqüência contendo a senha de acesso.

*Dwflags*<br/>
Qualquer combinação `INTERNET_FLAG_*` das bandeiras. Veja a tabela na seção **Observações** de [CHttpConnection::OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest) para obter uma descrição dos valores *dwFlags.*

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CHttpConnection.](../../mfc/reference/chttpconnection-class.md) Se a chamada falhar, determine a causa da falha examinando o objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) lançado.

### <a name="remarks"></a>Comentários

`GetHttpConnection`se conecta a um servidor HTTP e cria `CHttpConnection` e retorna um ponteiro a um objeto. Ele não realiza nenhuma operação específica no servidor. Se você pretende consultar um cabeçalho HTTP, por exemplo, você deve executar esta operação como uma etapa separada. Consulte as classes [CHttpConnection](../../mfc/reference/chttpconnection-class.md) e [CHttpFile](../../mfc/reference/chttpfile-class.md) para obter informações sobre operações que você pode executar usando uma conexão a um servidor HTTP. Para obter informações sobre a navegação em um site HTTP, consulte a função de membro [OpenURL](#openurl). Consulte o artigo [Programação da Internet com o WinInet](../../mfc/win32-internet-extensions-wininet.md) para obter etapas na execução de tarefas comuns de conexão HTTP.

## <a name="cinternetsessiononstatuscallback"></a><a name="onstatuscallback"></a>CInternetSession::OnStatusCallback

Essa função de membro é chamada pela framework para atualizar o status quando o retorno de status é ativado e uma operação está pendente.

```cpp
virtual void OnStatusCallback(
    DWORD_PTR dwContext,
    DWORD dwInternetStatus,
    LPVOID lpvStatusInformation,
    DWORD dwStatusInformationLength);
```

### <a name="parameters"></a>Parâmetros

*Dwcontext*<br/>
O valor de contexto fornecido pela aplicação.

*dwInternetStatus*<br/>
Um código de status que indica por que o retorno de chamada está sendo feito. Veja **observações** para uma tabela de valores possíveis.

*Lpvstatusinformation*<br/>
Um ponteiro para um buffer contendo informações pertinentes a este retorno de chamada.

*dwStatusInformationLength*<br/>
O tamanho do *lpvStatusInformation*.

### <a name="remarks"></a>Comentários

Você deve primeiro chamar [EnableStatusCallback](#enablestatuscallback) para aproveitar o retorno de status.

O *parâmetro dwInternetStatus* indica a operação que está sendo realizada e determina qual será o conteúdo do *lpvStatusInformation.* *dwStatusInformationLength* indica a duração dos dados incluídos no *lpvStatusInformation*. Os seguintes valores de status para *dwInternetStatus* são definidos da seguinte forma:

|Valor|Significado|
|-----------|-------------|
|INTERNET_STATUS_RESOLVING_NAME|Procurando o endereço IP do nome contido no *lpvStatusInformation*.|
|INTERNET_STATUS_NAME_RESOLVED|Encontrou com sucesso o endereço IP do nome contido no *lpvStatusInformation*.|
|INTERNET_STATUS_CONNECTING_TO_SERVER|Conectando-se ao endereço do soquete[(SOCKADDR)](/windows/win32/winsock/sockaddr-2)apontado por *lpvStatusInformation*.|
|INTERNET_STATUS_CONNECTED_TO_SERVER|Conectado com sucesso ao endereço do soquete (SOCKADDR) apontado por *lpvStatusInformation*.|
|INTERNET_STATUS_SENDING_REQUEST|Enviando a solicitação de informações para o servidor. O parâmetro *lpvStatusInformation* é NULL.|
|INTERNET_STATUS_ REQUEST_SENT|Enviou com sucesso a solicitação de informações para o servidor. O parâmetro *lpvStatusInformation* é NULL.|
|INTERNET_STATUS_RECEIVING_RESPONSE|Esperando o servidor responder a uma solicitação. O parâmetro *lpvStatusInformation* é NULL.|
|INTERNET_STATUS_RESPONSE_RECEIVED|Recebeu com sucesso uma resposta do servidor. O parâmetro *lpvStatusInformation* é NULL.|
|INTERNET_STATUS_CLOSING_CONNECTION|Fechando a conexão com o servidor. O parâmetro *lpvStatusInformation* é NULL.|
|INTERNET_STATUS_CONNECTION_CLOSED|Fechou com sucesso a conexão com o servidor. O parâmetro *lpvStatusInformation* é NULL.|
|INTERNET_STATUS_HANDLE_CREATED|Usado pela função API Win32 [InternetConnect](/windows/win32/api/wininet/nf-wininet-internetconnectw) para indicar que ele criou a nova alça. Isso permite que o aplicativo chame a função Win32 [internetCloseHandle](/windows/win32/api/wininet/nf-wininet-internetclosehandle) de outro segmento se a conexão estiver demorando muito. Consulte o Windows SDK para obter mais informações sobre essas funções.|
|INTERNET_STATUS_HANDLE_CLOSING|Terminou com sucesso este valor de alça.|

Substituir essa função de membro para exigir alguma ação antes que uma rotina de retorno de chamada de status seja executada.

> [!NOTE]
> Os retornos de status precisam de proteção do estado de segmento. Se você estiver usando o MFC em uma biblioteca compartilhada, adicione a seguinte linha ao início da sua substituição:

[!code-cpp[NVC_MFCHtmlHttp#8](../../mfc/reference/codesnippet/cpp/cinternetsession-class_1.cpp)]

Para obter mais informações sobre operações assíncronas, consulte o artigo [Primeiros Passos da Internet: WinInet](../../mfc/wininet-basics.md).

## <a name="cinternetsessionopenurl"></a><a name="openurl"></a>CInternetSession::OpenURL

Ligue para esta função de membro para enviar a solicitação especificada para o servidor HTTP e permitir que o cliente especifique cabeçalhos Adicionais RFC822, MIME ou HTTP para enviar junto com a solicitação.

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
Um ponteiro para o nome da URL para começar a ler. Apenas URLs que começam com arquivo:, ftp:, gopher:ou http: são suportados. Afirma se *pstrURL* é NULL.

*Dwcontext*<br/>
Um valor definido pelo aplicativo passou com a alça retornada no retorno de chamada.

*dwFlags*<br/>
As bandeiras descrevendo como lidar com essa conexão. Consulte **Observações** para obter mais informações sobre as bandeiras válidas. As bandeiras válidas são:

- INTERNET_FLAG_TRANSFER_ASCII o padrão. Transfira o arquivo como texto ASCII.

- INTERNET_FLAG_TRANSFER_BINARY Transferir o arquivo como um arquivo binário.

- INTERNET_FLAG_RELOAD obter os dados do fio, mesmo que sejam armazenados em cache local.

- INTERNET_FLAG_DONT_CACHE Não faça cache de dados, localmente ou em gateways.

- INTERNET_FLAG_SECURE Esta bandeira é aplicável apenas às solicitações HTTP. Ele solicita transações seguras no fio com Secure Sockets Layer ou PCT.

- INTERNET_OPEN_FLAG_USE_EXISTING_CONNECT Se possível, reutilize as conexões existentes ao `OpenUrl` servidor para novas solicitações geradas, em vez de criar uma nova sessão para cada solicitação de conexão.

- INTERNET_FLAG_PASSIVE usado para um site ftp. Usa semântica FTP passiva. Usado com [CInternetConnection](../../mfc/reference/cinternetconnection-class.md) de `OpenURL`.

*Pstrheaders*<br/>
Um ponteiro para uma seqüência contendo os cabeçalhos a serem enviados para o servidor HTTP.

*dwHeadersComprimento*<br/>
O comprimento, em caracteres, dos cabeçalhos adicionais. Se este é -1L e *pstrHeaders* não é NULO, então *pstrHeaders* é assumido como zero terminado e o comprimento é calculado.

### <a name="return-value"></a>Valor retornado

Retorna uma alça de arquivo apenas para serviços de Internet FTP, GOPHER, HTTP e FILE. Retorna NULO se a análise não foi bem sucedida.

O ponteiro `OpenURL` que retorna depende do tipo de serviço do *pstrURL.* A tabela abaixo ilustra os `OpenURL` possíveis ponteiros podem retornar.

|Tipo de URL|Retornos|
|--------------|-------------|
|`file://`|`CStdioFile*`|
|`http://`|`CHttpFile*`|
|`gopher://`|`CGopherFile*`|
|`ftp://`|`CInternetFile*`|

### <a name="remarks"></a>Comentários

O parâmetro *dwFlags* deve incluir INTERNET_FLAG_TRANSFER_ASCII ou INTERNET_FLAG_TRANSFER_BINARY, mas não ambos. As bandeiras restantes podem ser combinadas com o operador bitwise **OR** **(&#124;). **

`OpenURL`, que envolve a função `InternetOpenURL`Win32, permite apenas baixar, recuperar e ler os dados de um servidor da Internet. `OpenURL`não permite manipulação de arquivos em um local remoto, por isso não requer nenhum objeto [CInternetConnection.](../../mfc/reference/cinternetconnection-class.md)

Para usar funções específicas de conexão (ou seja, específicas do protocolo), como escrever para um arquivo, você deve abrir uma sessão e, em seguida, abrir um tipo específico de conexão e, em seguida, usar essa conexão para abrir um arquivo no modo desejado. Consulte `CInternetConnection` para obter mais informações sobre funções específicas de conexão.

## <a name="cinternetsessionoperator-hinternet"></a><a name="operator_hinternet"></a>CInternetSession::operador HINTERNET

Use este operador para obter o cabo do Windows para a sessão atual da Internet.

```cpp
operator HINTERNET() const;
```

## <a name="cinternetsessionsetcookie"></a><a name="setcookie"></a>CInternetSessão::SetCookie

Define um cookie para a URL especificada.

```cpp
static BOOL SetCookie(
    LPCTSTR pstrUrl,
    LPCTSTR pstrCookieName,
    LPCTSTR pstrCookieData);
```

### <a name="parameters"></a>Parâmetros

*PstrUrl*<br/>
Um ponteiro para uma seqüência de seqüência de terminadas nula que especifica a URL para a qual o cookie deve ser definido.

*pstrCookieName*<br/>
Um ponteiro para uma seqüência contendo o nome do cookie.

*pstrCookieData*<br/>
Um ponteiro para uma seqüência contendo os dados reais da seqüência para associar com a URL.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se for bem sucedido, ou FALSO de outra forma. Para obter o código de erro específico, ligue`GetLastError.`

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da mensagem Win32 [InternetSetCookie](/windows/win32/api/wininet/nf-wininet-internetsetcookiew), conforme descrito no SDK do Windows.

## <a name="cinternetsessionsetoption"></a><a name="setoption"></a>CInternetSessão::SetOption

Chame esta função de membro para definir opções para a sessão da Internet.

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

*Dwoption*<br/>
A opção de Internet para definir. Consulte [Option Flags](/windows/win32/WinInet/option-flags) no Windows SDKpara uma lista das possíveis opções.

*Lpbuffer*<br/>
Um buffer que contém a configuração de opção.

*dwBufferLength*<br/>
O comprimento do *lpBuffer* ou o tamanho do *dwValue*.

*Dwvalue*<br/>
Um DWORD que contém a configuração de opção.

*dwFlags*<br/>
Indica várias opções de cache. O padrão é definido como 0. Os valores possíveis incluem:

- INTERNET_FLAG_DONT_CACHE Não faça cache de dados, localmente ou em nenhum servidor gateway.

- INTERNET_FLAG_OFFLINE as operações de download são satisfeitas apenas através do cache persistente. Se o item não existir no cache, um código de erro apropriado será devolvido. Esta bandeira pode ser combinada com o operador bitwise **OR** **(&#124;). **

### <a name="return-value"></a>Valor retornado

Se a operação foi bem sucedida, um valor de TRUE é devolvido. Se ocorreu um erro, um valor de FALSE é devolvido. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Classe CHttpConnection](../../mfc/reference/chttpconnection-class.md)<br/>
[Classe CFtpConnection](../../mfc/reference/cftpconnection-class.md)<br/>
[Classe CGopherConnection](../../mfc/reference/cgopherconnection-class.md)
