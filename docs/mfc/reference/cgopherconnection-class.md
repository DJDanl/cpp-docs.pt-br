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
ms.openlocfilehash: d50aa8cac331ce44008f2b1949721495106c68e8
ms.sourcegitcommit: ecf274bcfe3a977c48745aaa243e5e731f1fdc5f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2019
ms.locfileid: "66503651"
---
# <a name="cgopherconnection-class"></a>Classe CGopherConnection

Gerencia sua conexão para um servidor gopher da Internet.

> [!NOTE]
>  As classes `CGopherConnection`, `CGopherFile`, `CGopherFileFind`, `CGopherLocator` e seus membros foram preteridos porque eles não funcionam na plataforma Windows XP, mas eles continuarão a funcionar em plataformas anteriores.

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
|[CGopherConnection::CreateLocator](#createlocator)|Cria uma [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) objeto para localizar arquivos em um servidor gopher.|
|[CGopherConnection::GetAttribute](#getattribute)|Recupera informações de atributo sobre o objeto de gopher.|
|[CGopherConnection::OpenFile](#openfile)|Abre um arquivo de gopher.|

## <a name="remarks"></a>Comentários

O serviço gopher é um dos três serviços de Internet reconhecidos pelas classes WinInet do MFC.

A classe `CGopherConnection` contém um construtor e três funções de membro adicionais que gerenciam o serviço gopher: [OpenFile](#openfile), [CreateLocator](#createlocator), e [GetAttribute](#getattribute).

Para se comunicar com um servidor gopher da Internet, você deve primeiro criar uma instância do [CInternetSession](../../mfc/reference/cinternetsession-class.md)e, em seguida, chame [CInternetSession::GetGopherConnection](../../mfc/reference/cinternetsession-class.md#getgopherconnection), que cria o `CGopherConnection` objeto e retorna um ponteiro para ele. Você nunca criará um `CGopherConnection` diretamente do objeto.

Para saber mais sobre como `CGopherConnection` funciona com as outras classes de Internet do MFC, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md). Para obter mais informações sobre como usar os outros dois com suporte dos serviços de Internet, FTP e HTTP ver as classes [CHttpConnection](../../mfc/reference/chttpconnection-class.md) e [CFtpConnection](../../mfc/reference/cftpconnection-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CInternetConnection](../../mfc/reference/cinternetconnection-class.md)

`CGopherConnection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

##  <a name="cgopherconnection"></a>  CGopherConnection::CGopherConnection

Essa função membro é chamada para construir um `CGopherConnection` objeto.

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
Um ponteiro para o relacionado [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto.

*hConnected*<br/>
O identificador do Windows da sessão atual da Internet.

*pstrServer*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do servidor FTP.

*dwContext*<br/>
O identificador de contexto para a operação. *dwContext* identifica as informações de status da operação retornadas por [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback). O padrão é definido como 1; No entanto, você pode explicitamente atribuir uma ID de contexto específico para a operação. O objeto e qualquer trabalho que será associados essa ID de contexto.

*pstrUserName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do usuário para fazer logon. Se for NULL, o padrão é anônimo.

*pstrPassword*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que especifica a senha a ser usada para fazer logon. Se os dois *pstrPassword* e *pstrUserName* forem nulos, a senha de padrão anônimo é o nome de email do usuário. Se *pstrPassword* é nulo (ou uma cadeia de caracteres vazia), mas *pstrUserName* não for nulo, uma senha em branco será usada. A tabela a seguir descreve o comportamento para as quatro configurações possíveis dos *pstrUserName* e *pstrPassword*:

|*pstrUserName*|*pstrPassword*|Nome de usuário enviado ao servidor FTP|Senha enviados ao servidor FTP|
|--------------------|--------------------|---------------------------------|---------------------------------|
|NULO ou ""|NULO ou ""|"anônimo"|Nome de email do usuário|
|Cadeia de caracteres não nula|NULO ou ""|*pstrUserName*|" "|
|Cadeia de caracteres nula não nulo|ERROR|ERROR||
|Cadeia de caracteres não nula|Cadeia de caracteres não nula|*pstrUserName*|*pstrPassword*|

*nPort*<br/>
Um número que identifica a porta TCP/IP para usar no servidor.

### <a name="remarks"></a>Comentários

Você nunca criará um `CGopherConnection` diretamente. Em vez disso, chame [CInternetSession::GetGopherConnection](../../mfc/reference/cinternetsession-class.md#getgopherconnection), que cria um `CGopherConnection` de objeto e retorna um ponteiro para ele.

##  <a name="createlocator"></a>  CGopherConnection::CreateLocator

Chame essa função de membro para criar um localizador de gopher para localizar ou identificar um arquivo em um servidor gopher.

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
Um ponteiro para uma cadeia de caracteres que contém o nome do diretório a ser recuperado ou documento gopher. Se o *pstrDisplayString* parâmetro for NULL, o diretório padrão para o servidor de gopher será retornado.

*pstrSelectorString*<br/>
Um ponteiro para a cadeia de caracteres a ser enviado para o servidor de gopher para recuperar um item seletor. *pstrSelectorString* pode ser NULL.

*dwGopherType*<br/>
Especifica se *pstrSelectorString* refere-se a um diretório ou um documento, e se a solicitação é gopher ou gopher +. Consulte os atributos para a estrutura [GOPHER_FIND_DATA](/windows/desktop/api/wininet/ns-wininet-gopher_find_dataa) no SDK do Windows.

*pstrLocator*<br/>
Um ponteiro para uma cadeia de caracteres que identifica o arquivo a ser aberto. Em geral, essa cadeia de caracteres é retornada de uma chamada para [CGopherFileFind::GetLocator](../../mfc/reference/cgopherfilefind-class.md#getlocator).

*pstrServerName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do servidor gopher.

*nPort*<br/>
O número que identifica a porta de Internet para esta conexão.

### <a name="return-value"></a>Valor de retorno

Um [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) objeto.

### <a name="remarks"></a>Comentários

A versão estática da função de membro exige que você especificar um servidor, enquanto a versão de não-estático usa o nome do servidor do objeto de conexão.

Para recuperar informações de um servidor gopher, um aplicativo deve primeiro obter um localizador de gopher. O aplicativo deve tratar, em seguida, o localizador como um token opaco (ou seja, o aplicativo pode usar o localizador, mas não diretamente manipular ou compará-la). Normalmente, o aplicativo usa o localizador de chamadas para o [CGopherFileFind::FindFile](../../mfc/reference/cgopherfilefind-class.md#findfile) a função de membro para recuperar uma parte específica de informações.

##  <a name="getattribute"></a>  CGopherConnection::GetAttribute

Chame essa função de membro para recuperar informações de atributo específico sobre um item do servidor gopher.

```
BOOL GetAttribute(
    CGopherLocator& refLocator    CString strRequestedAttributes,
    CString& strResult,);
```

### <a name="parameters"></a>Parâmetros

*refLocator*<br/>
Uma referência a um [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) objeto.

*strRequestedAttributes*<br/>
Uma cadeia delimitada por espaço especificando os nomes dos atributos solicitados.

*strResult*<br/>
Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que recebe o tipo de localizador.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamado para determinar a causa do erro.

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
Uma referência a um [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) objeto.

*dwFlags*<br/>
Qualquer combinação de sinalizadores de INTERNET_FLAG_ *. Ver [CInternetSession::OpenUrl](../../mfc/reference/cinternetsession-class.md#openurl) para obter mais informações sobre INTERNET_FLAG_\* sinalizadores.

*pstrView*<br/>
Um ponteiro para uma cadeia de caracteres de exibição de arquivo. Se existirem vários modos de exibição do arquivo no servidor, esse parâmetro especifica qual exibição de arquivo para abrir. Se *pstrView* for NULL, o modo de exibição de arquivo padrão é usado.

*dwContext*<br/>
A ID de contexto para o arquivo que está sendo aberto. Ver **Remarks** para obter mais informações sobre *dwContext*.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o [CGopherFile](../../mfc/reference/cgopherfile-class.md) objeto a ser aberto.

### <a name="remarks"></a>Comentários

Substituir a *dwContext* padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto está associado com esta operação específica do `CGopherConnection` objeto criado pelo seu [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto. O valor é retornado a [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status sobre a operação com a qual ela é identificada. Consulte o artigo [Internet primeiras etapas: O WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

## <a name="see-also"></a>Consulte também

[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFtpConnection](../../mfc/reference/cftpconnection-class.md)<br/>
[Classe CHttpConnection](../../mfc/reference/chttpconnection-class.md)<br/>
[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Classe CGopherLocator](../../mfc/reference/cgopherlocator-class.md)<br/>
[Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)<br/>
[Classe CInternetSession](../../mfc/reference/cinternetsession-class.md)
