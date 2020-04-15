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
ms.openlocfilehash: eade1a82b674d5ad2e91146559139445ef017180
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373708"
---
# <a name="cgopherconnection-class"></a>Classe CGopherConnection

Gerencia sua conexão a um servidor de Internet gopher.

> [!NOTE]
> As `CGopherConnection`classes `CGopherFile` `CGopherFileFind`e `CGopherLocator` seus membros foram preteridos porque não trabalham na plataforma Windows XP, mas continuarão a trabalhar em plataformas anteriores.

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
|[CGopherConnection::CreateLocator](#createlocator)|Cria um objeto [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) para encontrar arquivos em um servidor gopher.|
|[CGopherConnection::GetAttribute](#getattribute)|Recupera informações de atributos sobre o objeto gopher.|
|[CGopherConnection::OpenFile](#openfile)|Abre um arquivo gopher.|

## <a name="remarks"></a>Comentários

O serviço gopher é um dos três serviços de Internet reconhecidos pelas classes MFC WinInet.

A `CGopherConnection` classe contém um construtor e três funções adicionais de membro que gerenciam o serviço gopher: [OpenFile](#openfile), [CreateLocator](#createlocator)e [GetAttribute](#getattribute).

Para se comunicar com um servidor de Internet gopher, você deve primeiro criar uma instância de [CInternetSession](../../mfc/reference/cinternetsession-class.md)e, em seguida, chamar [CInternetSession::GetGopherConnection](../../mfc/reference/cinternetsession-class.md#getgopherconnection), que cria o `CGopherConnection` objeto e retorna um ponteiro para ele. Você nunca `CGopherConnection` cria um objeto diretamente.

Para saber mais `CGopherConnection` sobre como funciona as outras aulas de Internet do MFC, consulte o artigo [Programação na Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md). Para obter mais informações sobre o uso dos outros dois serviços de Internet suportados, FTP e HTTP consulte as classes [CHttpConnection](../../mfc/reference/chttpconnection-class.md) e [CFtpConnection](../../mfc/reference/cftpconnection-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cinternetconnection](../../mfc/reference/cinternetconnection-class.md)

`CGopherConnection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="cgopherconnectioncgopherconnection"></a><a name="cgopherconnection"></a>CGopherConnection::CGopherConnection

Esta função membro é `CGopherConnection` chamada para construir um objeto.

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
O cabo do Windows da sessão atual da Internet.

*PstrServer*<br/>
Um ponteiro para uma seqüência contendo o nome do servidor FTP.

*Dwcontext*<br/>
O identificador de contexto para a operação. *dwContext* identifica as informações de status da operação retornadas por [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback). O padrão é definido como 1; no entanto, você pode atribuir explicitamente um ID de contexto específico para a operação. O objeto e qualquer trabalho que ele fizer será associado a esse ID de contexto.

*pstrUserName*<br/>
Pointer para uma seqüência de terminadas nula que especifica o nome do usuário para fazer login. Se NULO, o padrão é anônimo.

*Pstrpassword*<br/>
Um ponteiro para uma seqüência de terminadas nula que especifica a senha a ser usada para fazer login. Se tanto *pstrPassword* quanto *pstrUserName* forem NULL, a senha anônima padrão é o nome de e-mail do usuário. Se *pstrPassword* for NULL (ou uma seqüência de string vazia) mas *pstrUserName* não for NULL, uma senha em branco será usada. A tabela a seguir descreve o comportamento das quatro configurações possíveis de *pstrUserName* e *pstrPassword*:

|*pstrUserName*|*Pstrpassword*|Nome de usuário enviado para servidor FTP|Senha enviada para servidor FTP|
|--------------------|--------------------|---------------------------------|---------------------------------|
|NULO ou " "|NULO ou " "|"anônimo"|Nome de e-mail do usuário|
|Corda não-NULA|NULO ou " "|*pstrUserName*|" "|
|Corda NULA NÃO-NULA|ERROR|ERROR||
|Corda não-NULA|Corda não-NULA|*pstrUserName*|*Pstrpassword*|

*nPort*<br/>
Um número que identifica a porta TCP/IP para usar no servidor.

### <a name="remarks"></a>Comentários

Você nunca `CGopherConnection` cria um diretamente. Em vez disso, ligue para [CInternetSession::GetGopherConnection](../../mfc/reference/cinternetsession-class.md#getgopherconnection), que cria um `CGopherConnection` objeto e retorna um ponteiro para ele.

## <a name="cgopherconnectioncreatelocator"></a><a name="createlocator"></a>CGopherConnection::CreateLocator

Chame esta função de membro para criar um localizador gopher para encontrar ou identificar um arquivo em um servidor gopher.

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
Um ponteiro para uma seqüência contendo o nome do documento ou diretório gopher a ser recuperado. Se o parâmetro *pstrDisplayString* for NULL, o diretório padrão do servidor gopher será devolvido.

*pstrSelectorString*<br/>
Um ponteiro para a seqüência de seletor a ser enviado para o servidor gopher, a fim de recuperar um item. *pstrSelectorString* pode ser NULL.

*dwGopherType*<br/>
Isso especifica se *pstrSelectorString* refere-se a um diretório ou documento, e se a solicitação é gopher ou gopher+. Veja os atributos para a estrutura [GOPHER_FIND_DATA](/windows/win32/api/wininet/ns-wininet-gopher_find_dataw) no SDK do Windows.

*pstrLocator*<br/>
Um ponteiro para uma seqüência que identifica o arquivo para abrir. Geralmente, essa seqüência é retornada de uma chamada para [CGopherFileFind::GetLocator](../../mfc/reference/cgopherfilefind-class.md#getlocator).

*pstrServerNome*<br/>
Um ponteiro para uma seqüência contendo o nome do servidor gopher.

*nPort*<br/>
O número que identifica a porta de Internet para essa conexão.

### <a name="return-value"></a>Valor retornado

Um objeto [CGopherLocator.](../../mfc/reference/cgopherlocator-class.md)

### <a name="remarks"></a>Comentários

A versão estática da função membro requer que você especifique um servidor, enquanto a versão não estática usa o nome do servidor a partir do objeto de conexão.

Para recuperar informações de um servidor gopher, um aplicativo deve primeiro obter um localizador gopher. O aplicativo deve então tratar o localizador como um token opaco (ou seja, o aplicativo pode usar o localizador, mas não manipulá-lo diretamente ou compará-lo). Normalmente, o aplicativo usa o localizador para chamadas para a função [CGopherFileFind::FindFile](../../mfc/reference/cgopherfilefind-class.md#findfile) member para recuperar uma informação específica.

## <a name="cgopherconnectiongetattribute"></a><a name="getattribute"></a>CGopherConnection::GetAttribute

Ligue para esta função de membro para recuperar informações específicas de atributo sobre um item do servidor gopher.

```
BOOL GetAttribute(
    CGopherLocator& refLocator    CString strRequestedAttributes,
    CString& strResult,);
```

### <a name="parameters"></a>Parâmetros

*árbitro*<br/>
Uma referência a um objeto [CGopherLocator.](../../mfc/reference/cgopherlocator-class.md)

*strRequestedAttributes*<br/>
Uma seqüência delimitada do espaço especificando os nomes dos atributos solicitados.

*strResult*<br/>
Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que recebe o tipo de localizador.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

## <a name="cgopherconnectionopenfile"></a><a name="openfile"></a>CGopherConnection::OpenFile

Chame esta função de membro para abrir um arquivo em um servidor gopher.

```
CGopherFile* OpenFile(
    CGopherLocator& refLocator,
    DWORD dwFlags = 0,
    LPCTSTR pstrView = NULL,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*árbitro*<br/>
Uma referência a um objeto [CGopherLocator.](../../mfc/reference/cgopherlocator-class.md)

*dwFlags*<br/>
Qualquer combinação de bandeiras INTERNET_FLAG_*. Consulte [CInternetSession::OpenUrl](../../mfc/reference/cinternetsession-class.md#openurl) para obter\* mais informações sobre INTERNET_FLAG_ bandeiras.

*pstrView*<br/>
Um ponteiro para uma seqüência de exibição de arquivo. Se existirem várias visualizações do arquivo no servidor, este parâmetro especifica qual exibição de arquivo será aberta. Se *pstrView* for NULL, a exibição de arquivo padrão será usada.

*Dwcontext*<br/>
O ID de contexto do arquivo que está sendo aberto. Consulte **Observações** para obter mais informações sobre *o dwContext*.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto [CGopherFile](../../mfc/reference/cgopherfile-class.md) a ser aberto.

### <a name="remarks"></a>Comentários

Anular o *padrão dwContext* para definir o identificador de contexto a um valor de sua escolha. O identificador de contexto está associado `CGopherConnection` a esta operação específica do objeto criado pelo objeto [CInternetSession.](../../mfc/reference/cinternetsession-class.md) O valor é devolvido ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status na operação com a qual ele é identificado. Veja o artigo [Primeiros Passos da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

## <a name="see-also"></a>Confira também

[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFtpConnection](../../mfc/reference/cftpconnection-class.md)<br/>
[Classe CHttpConnection](../../mfc/reference/chttpconnection-class.md)<br/>
[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Classe CGopherLocator](../../mfc/reference/cgopherlocator-class.md)<br/>
[Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)<br/>
[Classe CInternetSession](../../mfc/reference/cinternetsession-class.md)
