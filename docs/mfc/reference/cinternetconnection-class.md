---
title: Classe CInternetConnection
ms.date: 11/04/2016
f1_keywords:
- CInternetConnection
- AFXINET/CInternetConnection
- AFXINET/CInternetConnection::CInternetConnection
- AFXINET/CInternetConnection::GetContext
- AFXINET/CInternetConnection::GetServerName
- AFXINET/CInternetConnection::GetSession
helpviewer_keywords:
- CInternetConnection [MFC], CInternetConnection
- CInternetConnection [MFC], GetContext
- CInternetConnection [MFC], GetServerName
- CInternetConnection [MFC], GetSession
ms.assetid: 62a5d1c3-8471-4e36-a064-48831829b2a7
ms.openlocfilehash: 6649986f279e010a833b31157922cb4fd1ea8613
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372420"
---
# <a name="cinternetconnection-class"></a>Classe CInternetConnection

Gerencia sua conexão a um servidor de Internet.

## <a name="syntax"></a>Sintaxe

```
class CInternetConnection : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Conexão CInternet::Conexão CInternet](#cinternetconnection)|Constrói um objeto `CInternetConnection`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Conexão CInternet::GetContext](#getcontext)|Obtém o ID de contexto para este objeto de conexão.|
|[Conexão CInternet::GetServerName](#getservername)|Obtém o nome do servidor associado à conexão.|
|[Conexão CInternet::GetSession](#getsession)|Obtém um ponteiro para o objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) associado à conexão.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CConexão de Internet::operador HINTERNET](#operator_hinternet)|Uma alça para uma sessão de Internet.|

## <a name="remarks"></a>Comentários

É a classe base para classes MFC [CFtpConnection,](../../mfc/reference/cftpconnection-class.md) [CHttpConnection](../../mfc/reference/chttpconnection-class.md)e [CGopherConnection](../../mfc/reference/cgopherconnection-class.md). Cada uma dessas classes fornece funcionalidade adicional para se comunicar com o respectivo servidor FTP, HTTP ou gopher.

Para se comunicar diretamente com um servidor da Internet, `CInternetConnection` você deve ter um objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) e um objeto.

Para saber mais sobre como funcionam as aulas do WinInet, consulte o artigo [Programação na Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CInternetConnection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="cinternetconnectioncinternetconnection"></a><a name="cinternetconnection"></a>Conexão CInternet::Conexão CInternet

Essa função de membro `CInternetConnection` é chamada quando um objeto é criado.

```
CInternetConnection(
    CInternetSession* pSession,
    LPCTSTR pstrServer,
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*pSession*<br/>
Um ponteiro para um objeto [CInternetSession.](../../mfc/reference/cinternetsession-class.md)

*PstrServer*<br/>
Um ponteiro para uma seqüência contendo o nome do servidor.

*nPort*<br/>
O número que identifica a porta da Internet para essa conexão.

*Dwcontext*<br/>
O identificador de `CInternetConnection` contexto para o objeto. Consulte **Observações** para obter mais informações sobre *o dwContext*.

### <a name="remarks"></a>Comentários

Você nunca `CInternetConnection` se chama; em vez disso, chame a função de membro [CInternetSession](../../mfc/reference/cinternetsession-class.md) para o tipo de conexão que deseja estabelecer:

- [CInternetSession::GetFtpConexão](../../mfc/reference/cinternetsession-class.md#getftpconnection)

- [CInternetSession::gethttpConnection](../../mfc/reference/cinternetsession-class.md#gethttpconnection)

- [CInternetSession::GetGopherConnection](../../mfc/reference/cinternetsession-class.md#getgopherconnection)

O valor padrão para *dwContext* é `CInternetConnection`enviado pelo MFC para o objeto derivado do objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) que criou o objeto derivado da **InternetConnection.** O padrão é definido como 1; no entanto, você pode atribuir explicitamente um identificador de contexto específico no construtor [CInternetSession](../../mfc/reference/cinternetsession-class.md#cinternetsession) para a conexão. O objeto e qualquer trabalho que ele fizer será associado a esse ID de contexto. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status no objeto com o qual ele é identificado. Veja o artigo [Primeiros Passos da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

## <a name="cinternetconnectiongetcontext"></a><a name="getcontext"></a>Conexão CInternet::GetContext

Chame esta função de membro para obter o ID de contexto para esta sessão.

```
DWORD_PTR GetContext() const;
```

### <a name="return-value"></a>Valor retornado

O ID de contexto atribuído pelo aplicativo.

### <a name="remarks"></a>Comentários

O ID de contexto é originalmente especificado no `CInternetConnection` [CInternetSession](../../mfc/reference/cinternetsession-class.md) e se propaga para - e [CInternetFile](../../mfc/reference/cinternetfile-class.md)-derived classes, a menos que especificado de forma diferente na chamada para uma função que abre a conexão. O ID de contexto está associado a qualquer operação do objeto dado e identifica as informações de status da operação retornadas por [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback).

Para obter mais `GetContext` informações sobre como funciona com outras classes WinInet para dar informações sobre o status do usuário, consulte o artigo [Primeiros Passos da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

## <a name="cinternetconnectiongetservername"></a><a name="getservername"></a>Conexão CInternet::GetServerName

Ligue para esta função de membro para obter o nome do servidor associado a esta conexão com a Internet.

```
CString GetServerName() const;
```

### <a name="return-value"></a>Valor retornado

O nome do servidor com o que este objeto de conexão está trabalhando.

## <a name="cinternetconnectiongetsession"></a><a name="getsession"></a>Conexão CInternet::GetSession

Ligue para esta função de `CInternetSession` membro para obter um ponteiro para o objeto que está associado a esta conexão.

```
CInternetSession* GetSession() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) associado a este objeto de conexão à Internet.

## <a name="cinternetconnectionoperator-hinternet"></a><a name="operator_hinternet"></a>CConexão de Internet::operador HINTERNET

Use este operador para obter o cabo de nível de API para a sessão atual da Internet.

```
operator HINTERNET() const;
```

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
