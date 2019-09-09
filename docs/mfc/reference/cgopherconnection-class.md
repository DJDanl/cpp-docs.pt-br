---
title: Classe CGopherConnection
ms.date: 11/04/2016
f1_keywords:
- CGopherConnection
- AFXINET/CGopherConnection
- AFXINET/CGopherConnection::CGopherConnection
- AFXINET/CGopherConnection::CreateLocator
- AFXINET/CGopherConnection::GetAttribute
- AFXINET/CGopherConnection::OpenFile
helpviewer_keywords:
- CGopherConnection [MFC], CGopherConnection
- CGopherConnection [MFC], CreateLocator
- CGopherConnection [MFC], GetAttribute
- CGopherConnection [MFC], OpenFile
ms.assetid: b5b96aea-ac99-430e-bd84-d1372b43f78f
ms.openlocfilehash: f5d655aa7fd2eb9e41c15c60a71492c24ba43c43
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69506189"
---
# <a name="cgopherconnection-class"></a>Classe CGopherConnection

Gerencia sua conexão com um servidor de Internet do Gopher.

> [!NOTE]
>  As classes `CGopherConnection`, `CGopherFile`, `CGopherFileFind` eseusmembrosforampreteridasporquenãofuncionamnaplataformaWindowsXP,mascontinuarãofuncionando`CGopherLocator` em plataformas anteriores.

## <a name="syntax"></a>Sintaxe

```
class CGopherConnection : public CInternetConnection
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CGopherConnection::CGopherConnection](#cgopherconnection)|Constrói um objeto `CGopherConnection`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CGopherConnection::CreateLocator](#createlocator)|Cria um objeto [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) para localizar arquivos em um servidor gopher.|
|[CGopherConnection::GetAttribute](#getattribute)|Recupera informações de atributo sobre o objeto Gopher.|
|[CGopherConnection::OpenFile](#openfile)|Abre um arquivo gopher.|

## <a name="remarks"></a>Comentários

O serviço gopher é um dos três serviços de Internet reconhecidos pelas classes do MFC WinInet.

A classe `CGopherConnection` contém um construtor e três funções de membro adicionais que gerenciam o serviço gopher: [OpenFile](#openfile), [CreateLocator](#createlocator)e [GetAttribute](#getattribute).

Para se comunicar com um servidor de Internet do Gopher, você deve primeiro criar uma instância de [CInternetSession](../../mfc/reference/cinternetsession-class.md)e, em seguida, chamar [CInternetSession:: GetGopherConnection](../../mfc/reference/cinternetsession-class.md#getgopherconnection), que cria o `CGopherConnection` objeto e retorna um ponteiro para ele. Você nunca cria um `CGopherConnection` objeto diretamente.

Para saber mais sobre como `CGopherConnection` o funciona com as outras classes de Internet do MFC, confira o artigo [programação da Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md). Para obter mais informações sobre como usar os outros dois serviços de Internet com suporte, FTP e HTTP, consulte as classes [CHttpConnection](../../mfc/reference/chttpconnection-class.md) e [CFtpConnection](../../mfc/reference/cftpconnection-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CInternetConnection](../../mfc/reference/cinternetconnection-class.md)

`CGopherConnection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXINET. h

##  <a name="cgopherconnection"></a>  CGopherConnection::CGopherConnection

Essa função de membro é chamada para construir `CGopherConnection` um objeto.

```
CGopherConnection(
    CInternetSession* pSession,
    HINTERNET hConnected,
    LPCTSTR pstrServer,
    DWORD_PTR dwContext);

CGopherConnection(
    CInternetSession* pSession,
    LPCTSTR pstrServer,
    LPCTSTR pstrUserName = NULL,
    LPCTSTR pstrPassword = NULL,
    DWORD_PTR dwContext = 0,
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER);
```

### <a name="parameters"></a>Parâmetros

*pSession*<br/>
Um ponteiro para o objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) relacionado.

*hConnected*<br/>
O identificador do Windows da sessão atual da Internet.

*pstrServer*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do servidor FTP.

*dwContext*<br/>
O identificador de contexto para a operação. *dwContext* identifica as informações de status da operação retornadas por [CInternetSession:: OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback). O padrão é definido como 1; no entanto, você pode atribuir explicitamente uma ID de contexto específica para a operação. O objeto e qualquer trabalho que ele faz será associado a essa ID de contexto.

*pstrUserName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do usuário para fazer logon. Se for NULL, o padrão será Anonymous.

*pstrPassword*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que especifica a senha a ser usada para fazer logon. Se *pstrPassword* e *pstrUserName* forem nulos, a senha anônima padrão será o nome de email do usuário. Se *pstrPassword* for nulo (ou uma cadeia de caracteres vazia), mas *PSTRUSERNAME* não for NULL, uma senha em branco será usada. A tabela a seguir descreve o comportamento para as quatro configurações possíveis de *pstrUserName* e *pstrPassword*:

|*pstrUserName*|*pstrPassword*|Nome de usuário enviado ao servidor FTP|Senha enviada ao servidor FTP|
|--------------------|--------------------|---------------------------------|---------------------------------|
|NULL ou ""|NULL ou ""|modo|Nome de email do usuário|
|Cadeia de caracteres não nula|NULL ou ""|*pstrUserName*|" "|
|Cadeia de caracteres não nula nula|ERROR|ERROR||
|Cadeia de caracteres não nula|Cadeia de caracteres não nula|*pstrUserName*|*pstrPassword*|

*nPort*<br/>
Um número que identifica a porta TCP/IP a ser usada no servidor.

### <a name="remarks"></a>Comentários

Você nunca cria um `CGopherConnection` diretamente. Em vez disso, chame [CInternetSession:: GetGopherConnection](../../mfc/reference/cinternetsession-class.md#getgopherconnection), que `CGopherConnection` cria um objeto e retorna um ponteiro para ele.

##  <a name="createlocator"></a>  CGopherConnection::CreateLocator

Chame essa função de membro para criar um localizador do Gopher para localizar ou identificar um arquivo em um servidor gopher.

```
CGopherLocator CreateLocator(
    LPCTSTR pstrDisplayString,
    LPCTSTR pstrSelectorString,
    DWORD dwGopherType);

static CGopherLocator CreateLocator(LPCTSTR pstrLocator);

static CGopherLocator CreateLocator(
    LPCTSTR pstrServerName,
    LPCTSTR pstrDisplayString,
    LPCTSTR pstrSelectorString,
    DWORD dwGopherType,
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER);
```

### <a name="parameters"></a>Parâmetros

*pstrDisplayString*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do documento ou diretório Gopher a ser recuperado. Se o parâmetro *pstrDisplayString* for NULL, o diretório padrão para o servidor gopher será retornado.

*pstrSelectorString*<br/>
Um ponteiro para a cadeia de caracteres do seletor a ser enviado ao servidor gopher a fim de recuperar um item. *pstrSelectorString* pode ser nulo.

*dwGopherType*<br/>
Isso especifica se *pstrSelectorString* refere-se a um diretório ou documento e se a solicitação é Gopher ou gopher +. Consulte os atributos para a estrutura [GOPHER_FIND_DATA](/windows/win32/api/wininet/ns-wininet-gopher_find_dataw) no SDK do Windows.

*pstrLocator*<br/>
Um ponteiro para uma cadeia de caracteres que identifica o arquivo a ser aberto. Em geral, essa cadeia de caracteres é retornada de uma chamada para [CGopherFileFind:: GetLocator](../../mfc/reference/cgopherfilefind-class.md#getlocator).

*pstrServerName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do servidor gopher.

*nPort*<br/>
O número que identifica a porta da Internet para esta conexão.

### <a name="return-value"></a>Valor de retorno

Um objeto [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) .

### <a name="remarks"></a>Comentários

A versão estática da função membro exige que você especifique um servidor, enquanto a versão não estática usa o nome do servidor do objeto de conexão.

Para recuperar informações de um servidor gopher, um aplicativo deve primeiro obter um localizador gopher. O aplicativo deve então tratar o localizador como um token opaco (ou seja, o aplicativo pode usar o localizador, mas não manipulá-lo ou compará-lo diretamente). Normalmente, o aplicativo usa o localizador para chamadas para a função de membro [CGopherFileFind:: FindFile](../../mfc/reference/cgopherfilefind-class.md#findfile) para recuperar uma informação específica.

##  <a name="getattribute"></a>  CGopherConnection::GetAttribute

Chame essa função de membro para recuperar informações de atributo específicas sobre um item do servidor gopher.

```
BOOL GetAttribute(
    CGopherLocator& refLocator    CString strRequestedAttributes,
    CString& strResult,);
```

### <a name="parameters"></a>Parâmetros

*refLocator*<br/>
Uma referência a um objeto [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) .

*strRequestedAttributes*<br/>
Uma cadeia de caracteres delimitada por espaço que especifica os nomes dos atributos solicitados.

*strResult*<br/>
Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que recebe o tipo de localizador.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

##  <a name="openfile"></a>  CGopherConnection::OpenFile

Chame essa função de membro para abrir um arquivo em um servidor gopher.

```
CGopherFile* OpenFile(
    CGopherLocator& refLocator,
    DWORD dwFlags = 0,
    LPCTSTR pstrView = NULL,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*refLocator*<br/>
Uma referência a um objeto [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) .

*dwFlags*<br/>
Qualquer combinação de sinalizadores INTERNET_FLAG_ *. Consulte [CInternetSession:: OpenURL](../../mfc/reference/cinternetsession-class.md#openurl) para obter mais informações sobre\* sinalizadores INTERNET_FLAG_.

*pstrView*<br/>
Um ponteiro para uma cadeia de caracteres de exibição de arquivo. Se houver várias exibições do arquivo no servidor, esse parâmetro especificará a exibição de arquivo a ser aberta. Se *pstrView* for NULL, a exibição de arquivo padrão será usada.

*dwContext*<br/>
A ID de contexto para o arquivo que está sendo aberto. Consulte **comentários** para obter mais informações sobre *dwContext*.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o objeto [CGopherFile](../../mfc/reference/cgopherfile-class.md) a ser aberto.

### <a name="remarks"></a>Comentários

Substitua o padrão *dwContext* para definir o identificador de contexto como um valor de sua escolha. O identificador de contexto é associado a essa operação específica do `CGopherConnection` objeto criado por seu objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) . O valor é retornado para [CInternetSession:: OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status na operação com a qual ele é identificado. Consulte o artigo [primeiras etapas da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

## <a name="see-also"></a>Consulte também

[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFtpConnection](../../mfc/reference/cftpconnection-class.md)<br/>
[Classe CHttpConnection](../../mfc/reference/chttpconnection-class.md)<br/>
[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Classe CGopherLocator](../../mfc/reference/cgopherlocator-class.md)<br/>
[Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)<br/>
[Classe CInternetSession](../../mfc/reference/cinternetsession-class.md)
