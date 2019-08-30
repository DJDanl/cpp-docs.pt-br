---
title: Classe CFtpConnection
ms.date: 08/29/2019
f1_keywords:
- CFtpConnection
- AFXINET/CFtpConnection
- AFXINET/CFtpConnection::CFtpConnection
- AFXINET/CFtpConnection::Command
- AFXINET/CFtpConnection::CreateDirectory
- AFXINET/CFtpConnection::GetCurrentDirectory
- AFXINET/CFtpConnection::GetCurrentDirectoryAsURL
- AFXINET/CFtpConnection::GetFile
- AFXINET/CFtpConnection::OpenFile
- AFXINET/CFtpConnection::PutFile
- AFXINET/CFtpConnection::Remove
- AFXINET/CFtpConnection::RemoveDirectory
- AFXINET/CFtpConnection::Rename
- AFXINET/CFtpConnection::SetCurrentDirectory
helpviewer_keywords:
- CFtpConnection [MFC], CFtpConnection
- CFtpConnection [MFC], Command
- CFtpConnection [MFC], CreateDirectory
- CFtpConnection [MFC], GetCurrentDirectory
- CFtpConnection [MFC], GetCurrentDirectoryAsURL
- CFtpConnection [MFC], GetFile
- CFtpConnection [MFC], OpenFile
- CFtpConnection [MFC], PutFile
- CFtpConnection [MFC], Remove
- CFtpConnection [MFC], RemoveDirectory
- CFtpConnection [MFC], Rename
- CFtpConnection [MFC], SetCurrentDirectory
ms.assetid: 5e3a0501-8893-49cf-a3d5-0628d8d6b936
ms.openlocfilehash: 94ee4cb938ee061470282eb2f08a94d83c908805
ms.sourcegitcommit: e10a5feea193c249ddc5a6faba48e7c6d8784e73
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/30/2019
ms.locfileid: "70177274"
---
# <a name="cftpconnection-class"></a>Classe CFtpConnection

Gerencia a conexão FTP para um servidor de Internet e permite a manipulação direta de diretórios e arquivos nesse servidor.

## <a name="syntax"></a>Sintaxe

```
class CFtpConnection : public CInternetConnection
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFtpConnection::CFtpConnection](#cftpconnection)|Constrói um objeto `CFtpConnection`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFtpConnection::Command](#command)|Envia um comando diretamente para um servidor FTP.|
|[CFtpConnection::CreateDirectory](#createdirectory)|Cria um diretório no servidor.|
|[CFtpConnection::GetCurrentDirectory](#getcurrentdirectory)|Obtém o diretório atual para esta conexão.|
|[CFtpConnection::GetCurrentDirectoryAsURL](#getcurrentdirectoryasurl)|Obtém o diretório atual para esta conexão como uma URL.|
|[CFtpConnection::GetFile](#getfile)|Obtém um arquivo do servidor conectado|
|[CFtpConnection::OpenFile](#openfile)|Abre um arquivo no servidor conectado.|
|[CFtpConnection::PutFile](#putfile)|Coloca um arquivo no servidor.|
|[CFtpConnection::Remove](#remove)|Remove um arquivo do servidor.|
|[CFtpConnection::RemoveDirectory](#removedirectory)|Remove o diretório especificado do servidor.|
|[CFtpConnection::Rename](#rename)|Renomeia um arquivo no servidor.|
|[CFtpConnection::SetCurrentDirectory](#setcurrentdirectory)|Define o diretório de FTP atual.|

## <a name="remarks"></a>Comentários

O FTP é um dos três serviços de Internet reconhecidos pelas classes do MFC WinInet.

Para se comunicar com um servidor de Internet FTP, você deve primeiro criar uma instância de [CInternetSession](../../mfc/reference/cinternetsession-class.md)e, em `CFtpConnection` seguida, criar um objeto. Você nunca cria um `CFtpConnection` objeto diretamente; em vez disso, chame [CInternetSession:: GetFtpConnection](../../mfc/reference/cinternetsession-class.md#getftpconnection), que `CFtpConnection` cria o objeto e retorna um ponteiro para ele.

Para saber mais sobre como `CFtpConnection` o funciona com as outras classes de Internet do MFC, confira o artigo [programação da Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md). Para obter mais informações sobre como se comunicar com os outros dois serviços com suporte, HTTP e Gopher, consulte as classes [CHttpConnection](../../mfc/reference/chttpconnection-class.md) e [CGopherConnection](../../mfc/reference/cgopherconnection-class.md).

## <a name="example"></a>Exemplo

  Consulte o exemplo na visão geral da classe [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md) .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CInternetConnection](../../mfc/reference/cinternetconnection-class.md)

`CFtpConnection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXINET. h

##  <a name="cftpconnection"></a>  CFtpConnection::CFtpConnection

Essa função de membro é chamada para construir `CFtpConnection` um objeto.

```
CFtpConnection(
    CInternetSession* pSession,
    HINTERNET hConnected,
    LPCTSTR pstrServer,
    DWORD_PTR dwContext);

CFtpConnection(
    CInternetSession* pSession,
    LPCTSTR pstrServer,
    LPCTSTR pstrUserName = NULL,
    LPCTSTR pstrPassword = NULL,
    DWORD_PTR dwContext = 0,
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER,
    BOOL bPassive = FALSE);
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

*bPassive*<br/>
Especifica o modo passivo ou ativo para esta sessão de FTP. Se definido como TRUE, ele definirá a API do Win32 *dwFlag* para INTERNET_FLAG_PASSIVE.

### <a name="remarks"></a>Comentários

Você nunca cria um `CFtpConnection` objeto diretamente. Em vez disso, chame [CInternetSession:: GetFtpConnection](../../mfc/reference/cinternetsession-class.md#getftpconnection), que `CFptConnection` cria o objeto.

##  <a name="command"></a>  CFtpConnection::Command

Envia um comando diretamente para um servidor FTP.

```
CInternetFile* Command(
    LPCTSTR pszCommand,
    CmdResponseType eResponse = CmdRespNone,
    DWORD dwFlags = FTP_TRANSFER_TYPE_BINARY,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*pszCommand*<br/>
Um ponteiro para uma cadeia de caracteres que contém o comando a ser enviado.

*eResponse*<br/>
Especifica se uma resposta é esperada do servidor FTP. Pode ser um dos seguintes valores:

- `CmdRespNone`Nenhuma resposta é esperada.
- `CmdRespRead`Uma resposta é esperada.
- `CmdRespWrite`Não usado.

O CmdResponseType é um membro de CFtpConnection, definido em *AFXINET. h*.

*dwFlags*<br/>
Um valor que contém os sinalizadores que controlam essa função. Para obter uma lista completa, consulte [FTPCommand](/windows/win32/api/wininet/nf-wininet-ftpcommandw).

*dwContext*<br/>
Um ponteiro para um valor que contém um valor definido pelo aplicativo usado para identificar o contexto do aplicativo em retornos de chamada.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade da função [FTPCommand](/windows/win32/api/wininet/nf-wininet-ftpcommandw) , conforme descrito na SDK do Windows.

Se ocorrer um erro, o MFC lançará uma exceção do tipo [CInternetException](../../mfc/reference/cinternetexception-class.md).

##  <a name="createdirectory"></a>  CFtpConnection::CreateDirectory

Chame essa função de membro para criar um diretório no servidor conectado.

```
BOOL CreateDirectory(LPCTSTR pstrDirName);
```

### <a name="parameters"></a>Parâmetros

*pstrDirName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do diretório a ser criado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) do Windows poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Use `GetCurrentDirectory` para determinar o diretório de trabalho atual para esta conexão com o servidor. Não assuma que o sistema remoto o conectou ao diretório raiz.

O `pstrDirName` parâmetro pode ser um nome de arquivo parcialmente ou totalmente qualificado relativo ao diretório atual. Uma barra invertida\\() ou uma barra (/) pode ser usada como o separador de diretório para um dos nomes. `CreateDirectory`traduz os separadores de nome de diretório para os caracteres apropriados antes que eles sejam usados.

##  <a name="getcurrentdirectory"></a>  CFtpConnection::GetCurrentDirectory

Chame essa função de membro para obter o nome do diretório atual.

```
BOOL GetCurrentDirectory(CString& strDirName) const;

BOOL GetCurrentDirectory(
    LPTSTR pstrDirName,
    LPDWORD lpdwLen) const;
```

### <a name="parameters"></a>Parâmetros

*strDirName*<br/>
Uma referência a uma cadeia de caracteres que receberá o nome do diretório.

*pstrDirName*<br/>
Um ponteiro para uma cadeia de caracteres que receberá o nome do diretório.

*lpdwLen*<br/>
Um ponteiro para um DWORD que contém as seguintes informações:

|||
|-|-|
|Na entrada|O tamanho do buffer referenciado por *pstrDirName*.|
|No retorno|O número de caracteres armazenados em *pstrDirName*. Se a função de membro falhar e ERROR_INSUFFICIENT_BUFFER for retornado, *lpdwLen* conterá o número de bytes que o aplicativo deve alocar para receber a cadeia de caracteres.|

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Para obter o nome do diretório como uma URL, chame [GetCurrentDirectoryAsURL](#getcurrentdirectoryasurl).

Os parâmetros *pstrDirName* ou *strDirName* podem ser nomes de e totalmente qualificados em relação ao diretório atual ou completamente qualificados. Uma barra invertida\\() ou uma barra (/) pode ser usada como o separador de diretório para um dos nomes. `GetCurrentDirectory`traduz os separadores de nome de diretório para os caracteres apropriados antes que eles sejam usados.

##  <a name="getcurrentdirectoryasurl"></a>  CFtpConnection::GetCurrentDirectoryAsURL

Chame essa função de membro para obter o nome do diretório atual como uma URL.

```
BOOL GetCurrentDirectoryAsURL(CString& strDirName) const;

BOOL GetCurrentDirectoryAsURL(
    LPTSTR pstrName,
    LPDWORD lpdwLen) const;
```

### <a name="parameters"></a>Parâmetros

*strDirName*<br/>
Uma referência a uma cadeia de caracteres que receberá o nome do diretório.

*pstrDirName*<br/>
Um ponteiro para uma cadeia de caracteres que receberá o nome do diretório.

*lpdwLen*<br/>
Um ponteiro para um DWORD que contém as seguintes informações:

|||
|-|-|
|Na entrada|O tamanho do buffer referenciado por *pstrDirName*.|
|No retorno|O número de caracteres armazenados em *pstrDirName*. Se a função de membro falhar e ERROR_INSUFFICIENT_BUFFER for retornado, *lpdwLen* conterá o número de bytes que o aplicativo deve alocar para receber a cadeia de caracteres.|

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

`GetCurrentDirectoryAsURL`comporta-se da mesma forma que [GetCurrentDirectory](#getcurrentdirectory)

O parâmetro *strDirName* pode ser nomes de requalificados parcialmente relativos ao diretório atual ou totalmente qualificado. Uma barra invertida\\() ou uma barra (/) pode ser usada como o separador de diretório para um dos nomes. `GetCurrentDirectoryAsURL`traduz os separadores de nome de diretório para os caracteres apropriados antes que eles sejam usados.

##  <a name="getfile"></a>  CFtpConnection::GetFile

Chame essa função de membro para obter um arquivo de um servidor FTP e armazená-lo no computador local.

```
BOOL GetFile(
    LPCTSTR pstrRemoteFile,
    LPCTSTR pstrLocalFile,
    BOOL bFailIfExists = TRUE,
    DWORD dwAttributes = FILE_ATTRIBUTE_NORMAL,
    DWORD dwFlags = FTP_TRANSFER_TYPE_BINARY,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*pstrRemoteFile*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome de um arquivo a ser recuperado do servidor FTP.

*pstrLocalFile*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do arquivo a ser criado no sistema local.

*bFailIfExists*<br/>
Indica se o nome do arquivo já pode ser usado por um arquivo existente. Se o nome do arquivo local já existir e esse parâmetro for true, `GetFile` o falhará. Caso contrário `GetFile` , apagará a cópia existente do arquivo.

*dwAttributes*<br/>
Indica os atributos do arquivo. Isso pode ser qualquer combinação dos seguintes sinalizadores FILE_ATTRIBUTE_ *.

- FILE_ATTRIBUTE_ARCHIVE o arquivo é um arquivo morto. Os aplicativos usam esse atributo para marcar arquivos para backup ou remoção.

- FILE_ATTRIBUTE_COMPRESSED o arquivo ou diretório está compactado. Para um arquivo, a compactação significa que todos os dados no arquivo estão compactados. Para um diretório, a compactação é o padrão para arquivos e subdiretórios recém-criados.

- FILE_ATTRIBUTE_DIRECTORY o arquivo é um diretório.

- FILE_ATTRIBUTE_NORMAL o arquivo não tem nenhum outro atributo definido. Esse atributo é válido somente se usado sozinho. Todos os outros atributos de arquivo substituem FILE_ATTRIBUTE_NORMAL:

- FILE_ATTRIBUTE_HIDDEN o arquivo está oculto. Ele não deve ser incluído em uma listagem de diretório comum.

- FILE_ATTRIBUTE_READONLY o arquivo é somente leitura. Os aplicativos podem ler o arquivo, mas não podem gravar nele nem excluí-lo.

- FILE_ATTRIBUTE_SYSTEM o arquivo é parte do ou é usado exclusivamente pelo sistema operacional.

- FILE_ATTRIBUTE_TEMPORARY o arquivo está sendo usado para armazenamento temporário. Os aplicativos devem gravar no arquivo somente se for absolutamente necessário. A maioria dos dados do arquivo permanece na memória sem ser liberada para a mídia porque o arquivo será excluído em breve.

*dwFlags*<br/>
Especifica as condições sob as quais a transferência ocorre. Esse parâmetro pode ser qualquer um dos valores de *dwFlags* descritos em [FtpGetFile](/windows/win32/api/wininet/nf-wininet-ftpgetfilew) no SDK do Windows.

*dwContext*<br/>
O identificador de contexto para a recuperação de arquivo. Consulte **comentários** para obter mais informações sobre *dwContext*.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

`GetFile`é uma rotina de alto nível que manipula toda a sobrecarga associada à leitura de um arquivo de um servidor FTP e seu armazenamento local. Os aplicativos que só recuperam dados de arquivo ou que exigem controle de fechamento sobre a transferência de `OpenFile` arquivo devem usar e [CInternetFile:: Read](../../mfc/reference/cinternetfile-class.md#read) em vez disso.

Se *dwFlags* for FILE_TRANSFER_TYPE_ASCII, a conversão de dados de arquivo também converterá os caracteres de controle e formatação em equivalentes do Windows. A transferência padrão é o modo binário, no qual o arquivo é baixado no mesmo formato que é armazenado no servidor.

Tanto o *pstrRemoteFile* quanto o *pstrLocalFile* podem ser nomes de filequalificados parcialmente relativos ao diretório atual ou totalmente qualificados. Uma barra invertida\\() ou uma barra (/) pode ser usada como o separador de diretório para um dos nomes. `GetFile`traduz os separadores de nome de diretório para os caracteres apropriados antes que eles sejam usados.

Substitua o padrão *dwContext* para definir o identificador de contexto como um valor de sua escolha. O identificador de contexto é associado a essa operação específica do `CFtpConnection` objeto criado por seu objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) . O valor é retornado para [CInternetSession:: OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status na operação com a qual ele é identificado. Consulte o artigo [primeiras etapas da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

##  <a name="openfile"></a>  CFtpConnection::OpenFile

Chame essa função de membro para abrir um arquivo localizado em um servidor FTP para leitura ou gravação.

```
CInternetFile* OpenFile(
    LPCTSTR pstrFileName,
    DWORD dwAccess = GENERIC_READ,
    DWORD dwFlags = FTP_TRANSFER_TYPE_BINARY,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*pstrFileName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo a ser aberto.

*dwAccess*<br/>
Determina como o arquivo será acessado. Pode ser GENERIC_READ ou GENERIC_WRITE, mas não ambos.

*dwFlags*<br/>
Especifica as condições sob as quais as transferências subsequentes ocorrem. Isso pode ser qualquer uma das seguintes constantes FTP_TRANSFER_ *:

- FTP_TRANSFER_TYPE_ASCII as transferências de arquivo usando o método de transferência de FTP ASCII (tipo A). Converte as informações de controle e formatação em equivalentes locais.

- FTP_TRANSFER_TYPE_BINARY o arquivo transfere os dados usando o método de transferência da imagem (tipo I) do FTP. O arquivo transfere os dados exatamente como eles existem, sem alterações. Esse é o método de transferência padrão.

*dwContext*<br/>
O identificador de contexto para abrir o arquivo. Consulte **comentários** para obter mais informações sobre *dwContext*.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um objeto [CInternetFile](../../mfc/reference/cinternetfile-class.md) .

### <a name="remarks"></a>Comentários

`OpenFile`deve ser usado nas seguintes situações:

- Um aplicativo tem dados que precisam ser enviados e criados como um arquivo no servidor FTP, mas esses dados não estão em um arquivo local. Quando `OpenFile` o abre um arquivo, o aplicativo usa [CInternetFile:: Write](../../mfc/reference/cinternetfile-class.md#write) para enviar os dados do arquivo FTP para o servidor.

- Um aplicativo deve recuperar um arquivo do servidor e colocá-lo na memória controlada pelo aplicativo, em vez de gravá-lo no disco. O aplicativo usa [CInternetFile:: Read](../../mfc/reference/cinternetfile-class.md#read) depois de `OpenFile` usar para abrir o arquivo.

- Um aplicativo precisa de um nível de controle fino sobre uma transferência de arquivo. Por exemplo, o aplicativo pode querer exibir um controle de progresso indicando o progresso do status de transferência de arquivo durante o download de um arquivo.

Depois de `OpenFile` chamar e até `CInternetConnection::Close`chamar, o aplicativo só pode chamar [CInternetFile:: Read](../../mfc/reference/cinternetfile-class.md#read), [CInternetFile:: Write](../../mfc/reference/cinternetfile-class.md#write), `CInternetConnection::Close`ou [CFtpFileFind:: FindFile](../../mfc/reference/cftpfilefind-class.md#findfile). As chamadas para outras funções de FTP para a mesma sessão de FTP falharão e definirão o código de erro como FTP_ETRANSFER_IN_PROGRESS.

O parâmetro *pstrFileName* pode ser um nome de arquivo parcialmente qualificado relativo ao diretório atual ou totalmente qualificado. Uma barra invertida\\() ou uma barra (/) pode ser usada como o separador de diretório para um dos nomes. `OpenFile`traduz os separadores de nome de diretório para os caracteres apropriados antes de usá-lo.

Substitua o padrão *dwContext* para definir o identificador de contexto como um valor de sua escolha. O identificador de contexto é associado a essa operação específica do `CFtpConnection` objeto criado por seu objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) . O valor é retornado para [CInternetSession:: OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status na operação com a qual ele é identificado. Consulte o artigo [primeiras etapas da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

##  <a name="putfile"></a>  CFtpConnection::PutFile

Chame essa função de membro para armazenar um arquivo em um servidor FTP.

```
BOOL PutFile(
    LPCTSTR pstrLocalFile,
    LPCTSTR pstrRemoteFile,
    DWORD dwFlags = FTP_TRANSFER_TYPE_BINARY,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*pstrLocalFile*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo a ser enviado do sistema local.

*pstrRemoteFile*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo a ser criado no servidor FTP.

*dwFlags*<br/>
Especifica as condições sob as quais a transferência do arquivo ocorre. Pode ser qualquer uma das constantes FTP_TRANSFER_ * descritas em [OpenFile](#openfile).

*dwContext*<br/>
O identificador de contexto para colocar o arquivo. Consulte **comentários** para obter mais informações sobre *dwContext*.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

`PutFile`é uma rotina de alto nível que manipula todas as operações associadas ao armazenamento de um arquivo em um servidor FTP. Os aplicativos que enviam apenas dados ou que exigem mais controle sobre a transferência de arquivo devem usar [OpenFile](#openfile) e [CInternetFile:: Write](../../mfc/reference/cinternetfile-class.md#write).

Substitua o `dwContext` padrão para definir o identificador de contexto como um valor de sua escolha. O identificador de contexto é associado a essa operação específica do `CFtpConnection` objeto criado por seu objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) . O valor é retornado para [CInternetSession:: OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status na operação com a qual ele é identificado. Consulte o artigo [primeiras etapas da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

##  <a name="remove"></a>  CFtpConnection::Remove

Chame essa função de membro para excluir o arquivo especificado do servidor conectado.

```
BOOL Remove(LPCTSTR pstrFileName);
```

### <a name="parameters"></a>Parâmetros

*pstrFileName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo a ser removido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

O parâmetro *pstrFileName* pode ser um nome de arquivo parcialmente qualificado relativo ao diretório atual ou totalmente qualificado. Uma barra invertida\\() ou uma barra (/) pode ser usada como o separador de diretório para um dos nomes. A `Remove` função converte os separadores de nome de diretório nos caracteres apropriados antes que eles sejam usados.

##  <a name="removedirectory"></a>  CFtpConnection::RemoveDirectory

Chame essa função de membro para remover o diretório especificado do servidor conectado.

```
BOOL RemoveDirectory(LPCTSTR pstrDirName);
```

### <a name="parameters"></a>Parâmetros

*pstrDirName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o diretório a ser removido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Use [GetCurrentDirectory](#getcurrentdirectory) para determinar o diretório de trabalho atual do servidor. Não assuma que o sistema remoto o conectou ao diretório raiz.

O parâmetro *pstrDirName* pode ser um nome de arquivo parcialmente ou totalmente qualificado relativo ao diretório atual. Uma barra invertida\\() ou uma barra (/) pode ser usada como o separador de diretório para um dos nomes. `RemoveDirectory`traduz os separadores de nome de diretório para os caracteres apropriados antes que eles sejam usados.

##  <a name="rename"></a>  CFtpConnection::Rename

Chame essa função de membro para renomear o arquivo especificado no servidor conectado.

```
BOOL Rename(
    LPCTSTR pstrExisting,
    LPCTSTR pstrNew);
```

### <a name="parameters"></a>Parâmetros

*pstrExisting*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome atual do arquivo a ser renomeado.

*pstrNew*<br/>
Um ponteiro para uma cadeia de caracteres que contém o novo nome do arquivo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Os parâmetros *pstrExisting* e *pstrNew* podem ser um nome de arquivo parcialmente qualificado relativo ao diretório atual ou totalmente qualificado. Uma barra invertida\\() ou uma barra (/) pode ser usada como o separador de diretório para um dos nomes. `Rename`traduz os separadores de nome de diretório para os caracteres apropriados antes que eles sejam usados.

##  <a name="setcurrentdirectory"></a>  CFtpConnection::SetCurrentDirectory

Chame essa função de membro para alterar para um diretório diferente no servidor FTP.

```
BOOL SetCurrentDirectory(LPCTSTR pstrDirName);
```

### <a name="parameters"></a>Parâmetros

*pstrDirName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do diretório.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

O parâmetro *pstrDirName* pode ser um nome de arquivo parcialmente ou totalmente qualificado relativo ao diretório atual. Uma barra invertida\\() ou uma barra (/) pode ser usada como o separador de diretório para um dos nomes. `SetCurrentDirectory`traduz os separadores de nome de diretório para os caracteres apropriados antes que eles sejam usados.

Use [GetCurrentDirectory](#getcurrentdirectory) para determinar o diretório de trabalho atual de um servidor FTP. Não assuma que o sistema remoto o conectou ao diretório raiz.

## <a name="see-also"></a>Consulte também

[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Classe CInternetSession](../../mfc/reference/cinternetsession-class.md)
