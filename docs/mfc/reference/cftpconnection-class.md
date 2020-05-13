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
ms.openlocfilehash: a1fe516869aa98cc291597211eee175ef591e45d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373772"
---
# <a name="cftpconnection-class"></a>Classe CFtpConnection

Gerencia sua conexão FTP a um servidor de Internet e permite a manipulação direta de diretórios e arquivos nesse servidor.

## <a name="syntax"></a>Sintaxe

```
class CFtpConnection : public CInternetConnection
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Conexão CFtp::CFtpConexão](#cftpconnection)|Constrói um objeto `CFtpConnection`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Conexão CFtp::Comando](#command)|Envia um comando diretamente para um servidor FTP.|
|[Conexão CFtp::CreateDirectory](#createdirectory)|Cria um diretório no servidor.|
|[Conexão CFtp::GetCurrentDirectory](#getcurrentdirectory)|Obtém o diretório atual para esta conexão.|
|[Conexão CFtp::GetCurrentDirectoryAsURL](#getcurrentdirectoryasurl)|Obtém o diretório atual para essa conexão como uma URL.|
|[Conexão CFtp::GetFile](#getfile)|Obtém um arquivo do servidor conectado|
|[Conexão CFtp::OpenFile](#openfile)|Abre um arquivo no servidor conectado.|
|[Conexão CFtp::PutFile](#putfile)|Coloca um arquivo no servidor.|
|[Conexão CFtp::Remove](#remove)|Remove um arquivo do servidor.|
|[Conexão CFtp::RemoveDirectory](#removedirectory)|Remove o diretório especificado do servidor.|
|[Conexão CFtp::Renomeação](#rename)|Renomeia um arquivo no servidor.|
|[Conexão CFtp::SetCurrentDirectory](#setcurrentdirectory)|Define o diretório FTP atual.|

## <a name="remarks"></a>Comentários

FTP é um dos três serviços de Internet reconhecidos pelas classes MFC WinInet.

Para se comunicar com um servidor de Internet FTP, primeiro você `CFtpConnection` deve criar uma instância de [CInternetSession](../../mfc/reference/cinternetsession-class.md)e, em seguida, criar um objeto. Você nunca `CFtpConnection` cria um objeto diretamente; em vez disso, chame [CInternetSession::GetFtpConnection](../../mfc/reference/cinternetsession-class.md#getftpconnection), que cria o `CFtpConnection` objeto e retorna um ponteiro para ele.

Para saber mais `CFtpConnection` sobre como funciona as outras aulas de Internet do MFC, consulte o artigo [Programação na Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md). Para obter mais informações sobre como se comunicar com os outros dois serviços suportados, HTTP e gopher, consulte as classes [CHttpConnection](../../mfc/reference/chttpconnection-class.md) e [CGopherConnection](../../mfc/reference/cgopherconnection-class.md).

## <a name="example"></a>Exemplo

  Veja o exemplo na visão geral da classe [CFtpFileFind.](../../mfc/reference/cftpfilefind-class.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cinternetconnection](../../mfc/reference/cinternetconnection-class.md)

`CFtpConnection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="cftpconnectioncftpconnection"></a><a name="cftpconnection"></a>Conexão CFtp::CFtpConexão

Esta função membro é `CFtpConnection` chamada para construir um objeto.

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

*bPassivo*<br/>
Especifica o modo passivo ou ativo para esta sessão FTP. Se definido como TRUE, ele define o Win32 API *dwFlag* para INTERNET_FLAG_PASSIVE.

### <a name="remarks"></a>Comentários

Você nunca `CFtpConnection` cria um objeto diretamente. Em vez disso, chame [CInternetSession::GetFtpConnection](../../mfc/reference/cinternetsession-class.md#getftpconnection), que cria o `CFptConnection` objeto.

## <a name="cftpconnectioncommand"></a><a name="command"></a>Conexão CFtp::Comando

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
Um ponteiro para uma seqüência contendo o comando a ser enviado.

*eResposta*<br/>
Especifica se uma resposta é esperada do servidor FTP. Pode ser um dos seguintes valores:

- `CmdRespNone`Nenhuma resposta é esperada.
- `CmdRespRead`Uma resposta é esperada.
- `CmdRespWrite`Não usado.

O CmdResponseType é um membro do CFtpConnection, definido em *afxinet.h*.

*dwFlags*<br/>
Um valor contendo as bandeiras que controlam esta função. Para obter uma lista completa, consulte [FTPCommand](/windows/win32/api/wininet/nf-wininet-ftpcommandw).

*Dwcontext*<br/>
Um ponteiro para um valor que contém um valor definido por aplicativo usado para identificar o contexto do aplicativo em retornos de chamada.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro emula a funcionalidade da função [FTPCommand,](/windows/win32/api/wininet/nf-wininet-ftpcommandw) conforme descrito no SDK do Windows.

Se ocorrer um erro, o MFC lança uma exceção do tipo [CInternetException](../../mfc/reference/cinternetexception-class.md).

## <a name="cftpconnectioncreatedirectory"></a><a name="createdirectory"></a>Conexão CFtp::CreateDirectory

Chame essa função de membro para criar um diretório no servidor conectado.

```
BOOL CreateDirectory(LPCTSTR pstrDirName);
```

### <a name="parameters"></a>Parâmetros

*Pstrdirname*<br/>
Um ponteiro para uma seqüência contendo o nome do diretório para criar.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) do Windows pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Use `GetCurrentDirectory` para determinar o diretório de trabalho atual para essa conexão com o servidor. Não assuma que o sistema remoto o conectou ao diretório raiz.

O `pstrDirName` parâmetro pode ser um nome de arquivo parcialmente ou totalmente qualificado em relação ao diretório atual. Uma barra\\invertida () ou uma barra para a frente (/) podem ser usadas como separador de diretório para qualquer nome. `CreateDirectory`traduz os separadores do nome do diretório para os caracteres apropriados antes de serem usados.

## <a name="cftpconnectiongetcurrentdirectory"></a><a name="getcurrentdirectory"></a>Conexão CFtp::GetCurrentDirectory

Chame esta função de membro para obter o nome do diretório atual.

```
BOOL GetCurrentDirectory(CString& strDirName) const;

BOOL GetCurrentDirectory(
    LPTSTR pstrDirName,
    LPDWORD lpdwLen) const;
```

### <a name="parameters"></a>Parâmetros

*strDirName*<br/>
Uma referência a uma string que receberá o nome do diretório.

*Pstrdirname*<br/>
Um ponteiro para uma seqüência que receberá o nome do diretório.

*LpdwLen*<br/>
Um ponteiro para um DWORD que contém as seguintes informações:

|||
|-|-|
|Na entrada|O tamanho do buffer referenciado por *pstrDirName*.|
|No retorno|O número de caracteres armazenados *em pstrDirName*. Se a função de membro falhar e ERROR_INSUFFICIENT_BUFFER for devolvida, *lpdwLen* contém o número de bytes que o aplicativo deve alocar para receber a string.|

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Para obter o nome do diretório como URL, ligue para [GetCurrentDirectoryAsURL](#getcurrentdirectoryasurl).

Os parâmetros *pstrDirName* ou *strDirName* podem ser nomes de arquivos parcialmente qualificados em relação ao diretório atual ou totalmente qualificados. Uma barra\\invertida () ou uma barra para a frente (/) podem ser usadas como separador de diretório para qualquer nome. `GetCurrentDirectory`traduz os separadores do nome do diretório para os caracteres apropriados antes de serem usados.

## <a name="cftpconnectiongetcurrentdirectoryasurl"></a><a name="getcurrentdirectoryasurl"></a>Conexão CFtp::GetCurrentDirectoryAsURL

Chame esta função de membro para obter o nome do diretório atual como uma URL.

```
BOOL GetCurrentDirectoryAsURL(CString& strDirName) const;

BOOL GetCurrentDirectoryAsURL(
    LPTSTR pstrName,
    LPDWORD lpdwLen) const;
```

### <a name="parameters"></a>Parâmetros

*strDirName*<br/>
Uma referência a uma string que receberá o nome do diretório.

*Pstrdirname*<br/>
Um ponteiro para uma seqüência que receberá o nome do diretório.

*LpdwLen*<br/>
Um ponteiro para um DWORD que contém as seguintes informações:

|||
|-|-|
|Na entrada|O tamanho do buffer referenciado por *pstrDirName*.|
|No retorno|O número de caracteres armazenados *em pstrDirName*. Se a função de membro falhar e ERROR_INSUFFICIENT_BUFFER for devolvida, *lpdwLen* contém o número de bytes que o aplicativo deve alocar para receber a string.|

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

`GetCurrentDirectoryAsURL`comporta-se da mesma forma [que GetCurrentDirectory](#getcurrentdirectory)

O parâmetro *strDirName* pode ser parcialmente qualificado em relação ao diretório atual ou totalmente qualificado. Uma barra\\invertida () ou uma barra para a frente (/) podem ser usadas como separador de diretório para qualquer nome. `GetCurrentDirectoryAsURL`traduz os separadores do nome do diretório para os caracteres apropriados antes de serem usados.

## <a name="cftpconnectiongetfile"></a><a name="getfile"></a>Conexão CFtp::GetFile

Ligue para esta função de membro para obter um arquivo de um servidor FTP e armazená-lo na máquina local.

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
Um ponteiro para uma seqüência de terminadas nula contendo o nome de um arquivo para recuperar do servidor FTP.

*pstrLocalFile*<br/>
Um ponteiro para uma seqüência de terminadas nula contendo o nome do arquivo para criar no sistema local.

*bFailIfExiste*<br/>
Indica se o nome do arquivo já pode ser usado por um arquivo existente. Se o nome do arquivo local já existir, e este parâmetro for TRUE, `GetFile` falhará. Caso contrário, `GetFile` apagará a cópia existente do arquivo.

*dwAttributeS*<br/>
Indica os atributos do arquivo. Esta pode ser qualquer combinação das seguintes bandeiras FILE_ATTRIBUTE_*.

- FILE_ATTRIBUTE_ARCHIVE O arquivo é um arquivo de arquivo. Os aplicativos usam esse atributo para marcar arquivos para backup ou remoção.

- FILE_ATTRIBUTE_COMPRESSED O arquivo ou diretório é compactado. Para um arquivo, compactação significa que todos os dados do arquivo são compactados. Para um diretório, a compactação é o padrão para arquivos e subdiretórios recém-criados.

- FILE_ATTRIBUTE_DIRECTORY O arquivo é um diretório.

- FILE_ATTRIBUTE_NORMAL O arquivo não tem outros atributos definidos. Este atributo só é válido se usado sozinho. Todos os outros atributos de arquivo se sobrepõem FILE_ATTRIBUTE_NORMAL:

- FILE_ATTRIBUTE_HIDDEN o arquivo está escondido. Não deve ser incluído em uma listagem de diretório comum.

- FILE_ATTRIBUTE_READONLY O arquivo é apenas lido. Os aplicativos podem ler o arquivo, mas não podem gravá-lo ou excluí-lo.

- FILE_ATTRIBUTE_SYSTEM O arquivo faz parte ou é usado exclusivamente pelo sistema operacional.

- FILE_ATTRIBUTE_TEMPORARY O arquivo está sendo usado para armazenamento temporário. Os aplicativos devem escrever para o arquivo somente se absolutamente necessário. A maioria dos dados do arquivo permanece na memória sem ser liberado para a mídia porque o arquivo será excluído em breve.

*dwFlags*<br/>
Especifica as condições sob as quais a transferência ocorre. Este parâmetro pode ser qualquer um dos valores *dwFlags* descritos em [FtpGetFile](/windows/win32/api/wininet/nf-wininet-ftpgetfilew) no Windows SDK.

*Dwcontext*<br/>
O identificador de contexto para a recuperação de arquivos. Consulte **Observações** para obter mais informações sobre *o dwContext*.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

`GetFile`é uma rotina de alto nível que lida com toda a sobrecarga associada à leitura de um arquivo de um servidor FTP e armazenamento local. Os aplicativos que só recuperam dados de arquivo ou que `OpenFile` requerem controle próximo sobre a transferência de arquivos devem usar e [CInternetFile::Leia](../../mfc/reference/cinternetfile-class.md#read) em vez disso.

Se *o dwFlags* for FILE_TRANSFER_TYPE_ASCII, a tradução dos dados de arquivo também converte o controle e a formatação de caracteres em equivalentes do Windows. A transferência padrão é o modo binário, onde o arquivo é baixado no mesmo formato que é armazenado no servidor.

Tanto *pstrRemoteFile* quanto *pstrLocalFile* podem ser nomes de arquivos parcialmente qualificados em relação ao diretório atual ou totalmente qualificados. Uma barra\\invertida () ou uma barra para a frente (/) podem ser usadas como separador de diretório para qualquer nome. `GetFile`traduz os separadores do nome do diretório para os caracteres apropriados antes de serem usados.

Anular o *padrão dwContext* para definir o identificador de contexto a um valor de sua escolha. O identificador de contexto está associado `CFtpConnection` a esta operação específica do objeto criado pelo objeto [CInternetSession.](../../mfc/reference/cinternetsession-class.md) O valor é devolvido ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status na operação com a qual ele é identificado. Veja o artigo [Primeiros Passos da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

## <a name="cftpconnectionopenfile"></a><a name="openfile"></a>Conexão CFtp::OpenFile

Ligue para esta função de membro para abrir um arquivo localizado em um servidor FTP para leitura ou escrita.

```
CInternetFile* OpenFile(
    LPCTSTR pstrFileName,
    DWORD dwAccess = GENERIC_READ,
    DWORD dwFlags = FTP_TRANSFER_TYPE_BINARY,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*pstrFileName*<br/>
Um ponteiro para uma seqüência contendo o nome do arquivo a ser aberto.

*Dwaccess*<br/>
Determina como o arquivo será acessado. Pode ser GENERIC_READ ou GENERIC_WRITE, mas não ambos.

*dwFlags*<br/>
Especifica as condições sob as quais ocorrem as transferências subseqüentes. Esta pode ser qualquer uma das seguintes FTP_TRANSFER_* constantes:

- FTP_TRANSFER_TYPE_ASCII As transferências de arquivos utilizando o método de transferência FTP ASCII (Tipo A). Converte informações de controle e formatação em equivalentes locais.

- FTP_TRANSFER_TYPE_BINARY O arquivo transfere dados usando o método de transferência de imagem (Tipo I) do FTP. O arquivo transfere dados exatamente como existe, sem alterações. Este é o método de transferência padrão.

*Dwcontext*<br/>
O identificador de contexto para abrir o arquivo. Consulte **Observações** para obter mais informações sobre *o dwContext*.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CInternetFile.](../../mfc/reference/cinternetfile-class.md)

### <a name="remarks"></a>Comentários

`OpenFile`deve ser utilizado nas seguintes situações:

- Um aplicativo tem dados que precisam ser enviados e criados como um arquivo no servidor FTP, mas esses dados não estão em um arquivo local. Uma `OpenFile` vez aberto um arquivo, o aplicativo usa [CInternetFile::Write](../../mfc/reference/cinternetfile-class.md#write) para enviar os dados do arquivo FTP para o servidor.

- Um aplicativo deve recuperar um arquivo do servidor e colocá-lo em memória controlada por aplicativos, em vez de escrevê-lo em disco. O aplicativo usa [CInternetFile::Leia](../../mfc/reference/cinternetfile-class.md#read) depois de usar `OpenFile` para abrir o arquivo.

- Um aplicativo precisa de um bom nível de controle sobre uma transferência de arquivo. Por exemplo, o aplicativo pode querer exibir um controle de progresso que indique o progresso do status de transferência de arquivo ao baixar um arquivo.

Depois `OpenFile` de ligar `CInternetConnection::Close`e até ligar, o aplicativo só pode chamar [CInternetFile::Read](../../mfc/reference/cinternetfile-class.md#read), [CInternetFile::Write](../../mfc/reference/cinternetfile-class.md#write), `CInternetConnection::Close`ou [CFtpFileFind::FindFile](../../mfc/reference/cftpfilefind-class.md#findfile). As chamadas para outras funções FTP para a mesma sessão FTP falharão e definirão o código de erro para FTP_ETRANSFER_IN_PROGRESS.

O parâmetro *pstrFileName* pode ser um nome de arquivo parcialmente qualificado em relação ao diretório atual ou totalmente qualificado. Uma barra\\invertida () ou uma barra para a frente (/) podem ser usadas como separador de diretório para qualquer nome. `OpenFile`traduz os separadores do nome do diretório para os caracteres apropriados antes de usá-lo.

Anular o *padrão dwContext* para definir o identificador de contexto a um valor de sua escolha. O identificador de contexto está associado `CFtpConnection` a esta operação específica do objeto criado pelo objeto [CInternetSession.](../../mfc/reference/cinternetsession-class.md) O valor é devolvido ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status na operação com a qual ele é identificado. Veja o artigo [Primeiros Passos da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

## <a name="cftpconnectionputfile"></a><a name="putfile"></a>Conexão CFtp::PutFile

Ligue para esta função de membro para armazenar um arquivo em um servidor FTP.

```
BOOL PutFile(
    LPCTSTR pstrLocalFile,
    LPCTSTR pstrRemoteFile,
    DWORD dwFlags = FTP_TRANSFER_TYPE_BINARY,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*pstrLocalFile*<br/>
Um ponteiro para uma seqüência contendo o nome do arquivo para enviar do sistema local.

*pstrRemoteFile*<br/>
Um ponteiro para uma seqüência contendo o nome do arquivo para criar no servidor FTP.

*dwFlags*<br/>
Especifica as condições sob as quais ocorre a transferência do arquivo. Pode ser qualquer uma das constantes FTP_TRANSFER_* descritas no [OpenFile](#openfile).

*Dwcontext*<br/>
O identificador de contexto para colocar o arquivo. Consulte **Observações** para obter mais informações sobre *o dwContext*.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

`PutFile`é uma rotina de alto nível que lida com todas as operações associadas ao armazenamento de um arquivo em um servidor FTP. Os aplicativos que enviam apenas dados, ou que requerem um controle mais próximo sobre a transferência de arquivos, devem usar [OpenFile](#openfile) e [CInternetFile::Write](../../mfc/reference/cinternetfile-class.md#write).

Anular o `dwContext` padrão para definir o identificador de contexto a um valor de sua escolha. O identificador de contexto está associado `CFtpConnection` a esta operação específica do objeto criado pelo objeto [CInternetSession.](../../mfc/reference/cinternetsession-class.md) O valor é devolvido ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status na operação com a qual ele é identificado. Veja o artigo [Primeiros Passos da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

## <a name="cftpconnectionremove"></a><a name="remove"></a>Conexão CFtp::Remove

Ligue para esta função de membro para excluir o arquivo especificado do servidor conectado.

```
BOOL Remove(LPCTSTR pstrFileName);
```

### <a name="parameters"></a>Parâmetros

*pstrFileName*<br/>
Um ponteiro para uma seqüência contendo o nome do arquivo para remover.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

O parâmetro *pstrFileName* pode ser um nome de arquivo parcialmente qualificado em relação ao diretório atual ou totalmente qualificado. Uma barra\\invertida () ou uma barra para a frente (/) podem ser usadas como separador de diretório para qualquer nome. A `Remove` função traduz os separadores de nome do diretório para os caracteres apropriados antes de serem usados.

## <a name="cftpconnectionremovedirectory"></a><a name="removedirectory"></a>Conexão CFtp::RemoveDirectory

Ligue para esta função de membro para remover o diretório especificado do servidor conectado.

```
BOOL RemoveDirectory(LPCTSTR pstrDirName);
```

### <a name="parameters"></a>Parâmetros

*Pstrdirname*<br/>
Um ponteiro para uma seqüência contendo o diretório a ser removido.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Use [GetCurrentDirectory](#getcurrentdirectory) para determinar o diretório de trabalho atual do servidor. Não assuma que o sistema remoto o conectou ao diretório raiz.

O parâmetro *pstrDirName* pode ser um nome de arquivo parcial ou totalmente qualificado em relação ao diretório atual. Uma barra\\invertida () ou uma barra para a frente (/) podem ser usadas como separador de diretório para qualquer nome. `RemoveDirectory`traduz os separadores do nome do diretório para os caracteres apropriados antes de serem usados.

## <a name="cftpconnectionrename"></a><a name="rename"></a>Conexão CFtp::Renomeação

Ligue para esta função de membro para renomear o arquivo especificado no servidor conectado.

```
BOOL Rename(
    LPCTSTR pstrExisting,
    LPCTSTR pstrNew);
```

### <a name="parameters"></a>Parâmetros

*pstrExisting*<br/>
Um ponteiro para uma seqüência contendo o nome atual do arquivo a ser renomeado.

*pstrNew*<br/>
Um ponteiro para uma seqüência contendo o novo nome do arquivo.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Os *parâmetros pstrExisting* e *pstrNew* podem ser um nome de arquivo parcialmente qualificado em relação ao diretório atual ou totalmente qualificados. Uma barra\\invertida () ou uma barra para a frente (/) podem ser usadas como separador de diretório para qualquer nome. `Rename`traduz os separadores do nome do diretório para os caracteres apropriados antes de serem usados.

## <a name="cftpconnectionsetcurrentdirectory"></a><a name="setcurrentdirectory"></a>Conexão CFtp::SetCurrentDirectory

Chame esta função de membro para mudar para um diretório diferente no servidor FTP.

```
BOOL SetCurrentDirectory(LPCTSTR pstrDirName);
```

### <a name="parameters"></a>Parâmetros

*Pstrdirname*<br/>
Um ponteiro para uma seqüência contendo o nome do diretório.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

O parâmetro *pstrDirName* pode ser um nome de arquivo parcial ou totalmente qualificado em relação ao diretório atual. Uma barra\\invertida () ou uma barra para a frente (/) podem ser usadas como separador de diretório para qualquer nome. `SetCurrentDirectory`traduz os separadores do nome do diretório para os caracteres apropriados antes de serem usados.

Use [GetCurrentDirectory](#getcurrentdirectory) para determinar o diretório de trabalho atual de um servidor FTP. Não assuma que o sistema remoto o conectou ao diretório raiz.

## <a name="see-also"></a>Confira também

[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Classe CInternetSession](../../mfc/reference/cinternetsession-class.md)
