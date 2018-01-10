---
title: Classe CFtpConnection | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs: C++
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
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a20ee1e3de4d5c9f61437c79bd2eda4240947947
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cftpconnection-class"></a>Classe CFtpConnection
Gerencia a sua conexão de FTP para um servidor da Internet e permite a manipulação direta de diretórios e arquivos no servidor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CFtpConnection : public CInternetConnection  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFtpConnection::CFtpConnection](#cftpconnection)|Constrói um objeto `CFtpConnection`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
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
|[CFtpConnection::SetCurrentDirectory](#setcurrentdirectory)|Define o diretório atual do FTP.|  
  
## <a name="remarks"></a>Comentários  
 O FTP é um dos três serviços de Internet reconhecidos pelas classes WinInet MFC.  
  
 Para se comunicar com um servidor FTP Internet, você deve primeiro criar uma instância de [CInternetSession](../../mfc/reference/cinternetsession-class.md)e, em seguida, crie um `CFtpConnection` objeto. Você nunca criar um `CFtpConnection` objeto diretamente; em vez disso, chame [CInternetSession::GetFtpConnection](../../mfc/reference/cinternetsession-class.md#getftpconnection), que cria o `CFtpConnection` de objeto e retorna um ponteiro para ele.  
  
 Para saber mais sobre como `CFtpConnection` funciona com as outras classes de Internet MFC, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md). Para obter mais informações sobre a comunicação com os outros dois com suporte, serviços, HTTP e gopher, consulte as classes [CHttpConnection](../../mfc/reference/chttpconnection-class.md) e [CGopherConnection](../../mfc/reference/cgopherconnection-class.md).  
  
## <a name="example"></a>Exemplo  
  Consulte o exemplo de [CFtpFileFind](../../mfc/reference/cftpfilefind-class.md) visão geral da classe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CInternetConnection](../../mfc/reference/cinternetconnection-class.md)  
  
 `CFtpConnection`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxinet.h  
  
##  <a name="cftpconnection"></a>CFtpConnection::CFtpConnection  
 Essa função de membro é chamada para construir um `CFtpConnection` objeto.  
  
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
 `pSession`  
 Um ponteiro para relacionado [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto.  
  
 `hConnected`  
 O identificador do Windows da sessão atual da Internet.  
  
 `pstrServer`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do servidor FTP.  
  
 `dwContext`  
 O identificador de contexto para a operação. `dwContext`identifica as informações de status da operação retornadas por [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback). O padrão é definido como 1; No entanto, você pode explicitamente atribuir uma ID de contexto específico para a operação. O objeto e qualquer trabalho faz será associados esse ID de contexto.  
  
 `pstrUserName`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do usuário para fazer logon. Se **nulo**, o padrão é anônimo.  
  
 `pstrPassword`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo que especifica a senha a ser usada para fazer logon. Se ambos os `pstrPassword` e `pstrUserName` são **nulo**, a senha anônima padrão é o nome de email do usuário. Se `pstrPassword` é **nulo** (ou uma cadeia de caracteres vazia), mas `pstrUserName` não é **nulo**, uma senha em branco será usada. A tabela a seguir descreve o comportamento para as quatro configurações possíveis de `pstrUserName` e `pstrPassword`:  
  
|`pstrUserName`|`pstrPassword`|Nome de usuário enviado ao servidor FTP|Senha enviada ao servidor FTP|  
|--------------------|--------------------|---------------------------------|---------------------------------|  
|**NULO** ou ""|**NULO** ou ""|"anônimo"|Nome de email do usuário|  
|Não- **nulo** cadeia de caracteres|**NULO** ou ""|`pstrUserName`|" "|  
|**NULO** não **nulo** cadeia de caracteres|**ERRO**|**ERRO**||  
|Não- **nulo** cadeia de caracteres|Não- **nulo** cadeia de caracteres|`pstrUserName`|`pstrPassword`|  
  
 `nPort`  
 Um número que identifica a porta TCP/IP para usar no servidor.  
  
 `bPassive`  
 Especifica o modo passivo ou ativo para esta sessão FTP. Se definido como **TRUE**, ele define a API do Win32 `dwFlag` para **INTERNET_FLAG_PASSIVE**.  
  
### <a name="remarks"></a>Comentários  
 Você nunca criar um `CFtpConnection` diretamente do objeto. Em vez disso, chame [CInternetSession::GetFtpConnection](../../mfc/reference/cinternetsession-class.md#getftpconnection), que cria o **CFptConnection** objeto.  
  
##  <a name="command"></a>CFtpConnection::Command  
 Envia um comando diretamente para um servidor FTP.  
  
```  
CInternetFile* Command(
    LPCTSTR pszCommand,  
    CmdResponseType eResponse = CmdRespNone,  
    DWORD dwFlags = FTP_TRANSFER_TYPE_BINARY,  
    DWORD_PTR dwContext = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszCommand`  
 Um ponteiro para uma cadeia de caracteres que contém o comando a ser enviado.  
  
 *eResponse*  
 Determina se uma resposta for esperada do servidor FTP. Pode ser um dos seguintes valores:  
  
- **CmdRespNone** nenhuma resposta é esperada.  
  
- **CmdRespRead** uma resposta é esperada.  
  
 `dwFlags`  
 Um valor que contém os sinalizadores que controlam a essa função. Para obter uma lista completa, consulte [FTPCommand](http://msdn.microsoft.com/library/windows/desktop/aa384133).  
  
 `dwContext`  
 Um ponteiro para um valor que contém um valor definido pelo aplicativo usado para identificar o contexto em retornos de chamada do aplicativo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro emula a funcionalidade do [FTPCommand](http://msdn.microsoft.com/library/windows/desktop/aa384133) de função, conforme descrito no SDK do Windows.  
  
 Se ocorrer um erro, MFC lança uma exceção do tipo [CInternetException](../../mfc/reference/cinternetexception-class.md).  
  
##  <a name="createdirectory"></a>CFtpConnection::CreateDirectory  
 Chame essa função de membro para criar um diretório no servidor conectado.  
  
```  
BOOL CreateDirectory(LPCTSTR pstrDirName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrDirName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do diretório a ser criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função do Windows [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
### <a name="remarks"></a>Comentários  
 Use `GetCurrentDirectory` para determinar o diretório de trabalho atual para essa conexão ao servidor. Não suponha que o sistema remoto conectou você para o diretório raiz.  
  
 O `pstrDirName` parâmetro pode ser um parcialmente ou um nome de arquivo totalmente qualificado relativo ao diretório atual. Uma barra invertida (\\) ou barra invertida (/) pode ser usada como separador de diretório para qualquer nome. `CreateDirectory`converte os separadores de nome de diretório para os caracteres apropriados antes de serem usadas.  
  
##  <a name="getcurrentdirectory"></a>CFtpConnection::GetCurrentDirectory  
 Chame essa função de membro para obter o nome do diretório atual.  
  
```  
BOOL GetCurrentDirectory(CString& strDirName) const;  
  
BOOL GetCurrentDirectory(
    LPTSTR pstrDirName,  
    LPDWORD lpdwLen) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `strDirName`  
 Uma referência a uma cadeia de caracteres que receberá o nome do diretório.  
  
 `pstrDirName`  
 Um ponteiro para uma cadeia de caracteres que receberá o nome do diretório.  
  
 `lpdwLen`  
 Um ponteiro para uma DWORD que contém as seguintes informações:  
  
|||  
|-|-|  
|Na entrada|O tamanho do buffer referenciado por `pstrDirName`.|  
|No retorno|O número de caracteres armazenados em `pstrDirName`. Se a função de membro falhar e ERROR_INSUFFICIENT_BUFFER for retornado, em seguida, `lpdwLen` contém o número de bytes que o aplicativo deve alocar para receber a cadeia de caracteres.|  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
### <a name="remarks"></a>Comentários  
 Para obter o nome do diretório como uma URL em vez disso, chame [GetCurrentDirectoryAsURL](#getcurrentdirectoryasurl).  
  
 Os parâmetros `pstrDirName` ou `strDirName` pode ser qualquer um dos nomes de arquivo parcialmente qualificado relativo ao diretório atual ou totalmente qualificado. Uma barra invertida (\\) ou barra invertida (/) pode ser usada como separador de diretório para qualquer nome. `GetCurrentDirectory`converte os separadores de nome de diretório para os caracteres apropriados antes de serem usadas.  
  
##  <a name="getcurrentdirectoryasurl"></a>CFtpConnection::GetCurrentDirectoryAsURL  
 Chame essa função de membro para obter o nome do diretório atual como uma URL.  
  
```  
BOOL GetCurrentDirectoryAsURL(CString& strDirName) const;  
  
BOOL GetCurrentDirectoryAsURL(
    LPTSTR pstrName,  
    LPDWORD lpdwLen) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `strDirName`  
 Uma referência a uma cadeia de caracteres que receberá o nome do diretório.  
  
 `pstrDirName`  
 Um ponteiro para uma cadeia de caracteres que receberá o nome do diretório.  
  
 `lpdwLen`  
 Um ponteiro para uma DWORD que contém as seguintes informações:  
  
|||  
|-|-|  
|Na entrada|O tamanho do buffer referenciado por `pstrDirName`.|  
|No retorno|O número de caracteres armazenados em `pstrDirName`. Se a função de membro falhar e ERROR_INSUFFICIENT_BUFFER for retornado, em seguida, `lpdwLen` contém o número de bytes que o aplicativo deve alocar para receber a cadeia de caracteres.|  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
### <a name="remarks"></a>Comentários  
 `GetCurrentDirectoryAsURL`se comporta como [GetCurrentDirectory](#getcurrentdirectory)  
  
 O parâmetro `strDirName` pode ser qualquer um dos nomes de arquivo parcialmente qualificado relativo ao diretório atual ou totalmente qualificado. Uma barra invertida (\\) ou barra invertida (/) pode ser usada como separador de diretório para qualquer nome. `GetCurrentDirectoryAsURL`converte os separadores de nome de diretório para os caracteres apropriados antes de serem usadas.  
  
##  <a name="getfile"></a>CFtpConnection::GetFile  
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
 `pstrRemoteFile`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome de um arquivo a ser recuperado do servidor FTP.  
  
 `pstrLocalFile`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome do arquivo a ser criado no sistema local.  
  
 *bFailIfExists*  
 Indica se o nome do arquivo já pode ser usado por um arquivo existente. Se o nome de arquivo local já existe, e esse parâmetro é **TRUE**, `GetFile` falhar. Caso contrário, `GetFile` apagará a cópia existente do arquivo.  
  
 `dwAttributes`  
 Indica os atributos do arquivo. Isso pode ser qualquer combinação dos sinalizadores a seguir FILE_ATTRIBUTE_ *.  
  
-   FILE_ATTRIBUTE_ARCHIVE o arquivo é um arquivo morto. Aplicativos usam esse atributo para marcar os arquivos de backup ou de remoção.  
  
-   FILE_ATTRIBUTE_COMPRESSED o arquivo ou diretório é compactado. Para um arquivo, a compactação significa que todos os dados no arquivo é compactado. Para um diretório, a compactação é o padrão para novos arquivos e subdiretórios.  
  
-   FILE_ATTRIBUTE_DIRECTORY o arquivo é um diretório.  
  
-   FILE_ATTRIBUTE_NORMAL o arquivo não tiver outros atributos definido. Esse atributo é válido somente quando usado sozinho. Todos os outros atributos de arquivo substituem FILE_ATTRIBUTE_NORMAL:  
  
-   FILE_ATTRIBUTE_HIDDEN o arquivo está oculto. Não é deve ser incluída em uma listagem de diretório comum.  
  
-   FILE_ATTRIBUTE_READONLY o arquivo é somente leitura. Aplicativos podem ler o arquivo, mas não é possível gravar nele ou excluí-lo.  
  
-   FILE_ATTRIBUTE_SYSTEM o arquivo faz parte de ou é usado exclusivamente pelo sistema operacional.  
  
-   FILE_ATTRIBUTE_TEMPORARY o arquivo está sendo usado para armazenamento temporário. Aplicativos devem gravar o arquivo apenas se absolutamente necessário. A maioria dos dados do arquivo permanece na memória sem que estão sendo liberados para a mídia porque o arquivo em breve será excluído.  
  
 `dwFlags`  
 Especifica as condições sob as quais a transferência ocorre. Esse parâmetro pode ser qualquer um do `dwFlags` valores descritos na [FtpGetFile](http://msdn.microsoft.com/library/windows/desktop/aa384157) no SDK do Windows.  
  
 `dwContext`  
 O identificador de contexto para a recuperação de arquivo. Consulte **comentários** para obter mais informações sobre `dwContext`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
### <a name="remarks"></a>Comentários  
 `GetFile`é uma rotina de alto nível que manipula todas a sobrecarga associada com a leitura de um arquivo de um servidor FTP e armazená-lo localmente. Que apenas recuperam dados de arquivo, ou que exigem fechar controle sobre a transferência de arquivo, os aplicativos devem usar `OpenFile` e [CInternetFile::Read](../../mfc/reference/cinternetfile-class.md#read) em vez disso.  
  
 Se `dwFlags` FILE_TRANSFER_TYPE_ASCII, conversão de dados de arquivo também é converte controle e formatação de caracteres equivalentes do Windows. A transferência padrão é o modo binário, onde o arquivo é baixado no mesmo formato conforme eles são armazenados no servidor.  
  
 Ambos `pstrRemoteFile` e `pstrLocalFile` pode ser qualquer um dos nomes de arquivo parcialmente qualificado relativo ao diretório atual ou totalmente qualificado. Uma barra invertida (\\) ou barra invertida (/) pode ser usada como separador de diretório para qualquer nome. `GetFile`converte os separadores de nome de diretório para os caracteres apropriados antes de serem usadas.  
  
 Substituir o `dwContext` padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto está associado essa operação específica do `CFtpConnection` objeto criado pelo seu [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto. O valor é retornado para [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status sobre a operação com a qual ela é identificada. Consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.  
  
##  <a name="openfile"></a>CFtpConnection::OpenFile  
 Chame essa função de membro para abrir um arquivo localizado em um servidor FTP para leitura ou gravação.  
  
```  
CInternetFile* OpenFile(
    LPCTSTR pstrFileName,  
    DWORD dwAccess = GENERIC_READ,  
    DWORD dwFlags = FTP_TRANSFER_TYPE_BINARY,  
    DWORD_PTR dwContext = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrFileName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo a ser aberto.  
  
 *dwAccess*  
 Determina como o arquivo será acessado. Pode ser GENERIC_READ ou GRAVAÇÃO_GENÉRICA, mas não ambos.  
  
 `dwFlags`  
 Especifica as condições sob as quais ocorrem transferências subsequentes. Isso pode ser qualquer um dos seguintes FTP_TRANSFER_ * constantes:  
  
-   FTP_TRANSFER_TYPE_ASCII o arquivo é transferido usando o método de transferência de FTP ASCII (um tipo). Converte controle e informações de formatação para equivalentes locais.  
  
-   FTP_TRANSFER_TYPE_BINARY o arquivo transfere os dados usando o método de transferência de imagem FTP's (tipo I). Os dados de transferências de arquivo exatamente como ele existem sem alterações. Este é o método de transferência padrão.  
  
 `dwContext`  
 O identificador de contexto para abrir o arquivo. Consulte **comentários** para obter mais informações sobre `dwContext`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CInternetFile](../../mfc/reference/cinternetfile-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 `OpenFile`deve ser usada nas seguintes situações:  
  
-   Um aplicativo tem dados que precisam ser enviados e criado como um arquivo no servidor de FTP, mas que os dados não estão em um arquivo local. Uma vez `OpenFile` abre um arquivo, o aplicativo usa [CInternetFile::Write](../../mfc/reference/cinternetfile-class.md#write) para enviar os dados de arquivo FTP para o servidor.  
  
-   Um aplicativo deve recuperar um arquivo do servidor e colocá-lo na memória controlada pelo aplicativo, em vez de gravação no disco. O aplicativo usa [CInternetFile::Read](../../mfc/reference/cinternetfile-class.md#read) depois de usar `OpenFile` para abrir o arquivo.  
  
-   Um aplicativo precisa de um bom nível de controle sobre uma transferência de arquivo. Por exemplo, o aplicativo pode querer exibir um progresso controle indicar o progresso do status da transferência de arquivo durante o download de um arquivo.  
  
 Depois de chamar `OpenFile` e até chamar **CInternetConnection::Close**, o aplicativo pode chamar somente [CInternetFile::Read](../../mfc/reference/cinternetfile-class.md#read), [CInternetFile::Write](../../mfc/reference/cinternetfile-class.md#write), **CInternetConnection::Close**, ou [CFtpFileFind::FindFile](../../mfc/reference/cftpfilefind-class.md#findfile). Chamadas para outras funções FTP para a mesma sessão FTP falhará e definir o código de erro para FTP_ETRANSFER_IN_PROGRESS.  
  
 O `pstrFileName` parâmetro pode ser um nome qualificado parcialmente totalmente qualificado ou relativo para o diretório atual. Uma barra invertida (\\) ou barra invertida (/) pode ser usada como separador de diretório para qualquer nome. `OpenFile`converte os separadores de nome de diretório para os caracteres apropriados antes de usá-lo.  
  
 Substituir o `dwContext` padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto está associado essa operação específica do `CFtpConnection` objeto criado pelo seu [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto. O valor é retornado para [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status sobre a operação com a qual ela é identificada. Consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.  
  
##  <a name="putfile"></a>CFtpConnection::PutFile  
 Chame essa função de membro para armazenar um arquivo em um servidor FTP.  
  
```  
BOOL PutFile(
    LPCTSTR pstrLocalFile,  
    LPCTSTR pstrRemoteFile,  
    DWORD dwFlags = FTP_TRANSFER_TYPE_BINARY,  
    DWORD_PTR dwContext = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrLocalFile`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo a enviar no sistema local.  
  
 `pstrRemoteFile`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo a ser criado no servidor FTP.  
  
 `dwFlags`  
 Especifica as condições sob as quais a transferência do arquivo ocorre. Pode ser qualquer uma das constantes FTP_TRANSFER_ * descritas em [OpenFile](#openfile).  
  
 `dwContext`  
 O identificador de contexto para colocar o arquivo. Consulte **comentários** para obter mais informações sobre `dwContext`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
### <a name="remarks"></a>Comentários  
 `PutFile`é uma rotina de alto nível que manipula todas as operações associadas ao armazenamento de um arquivo em um servidor FTP. Que só enviar dados, ou que exigem mais controle sobre a transferência de arquivo, os aplicativos devem usar [OpenFile](#openfile) e [CInternetFile::Write](../../mfc/reference/cinternetfile-class.md#write).  
  
 Substituir o `dwContext` padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto está associado essa operação específica do `CFtpConnection` objeto criado pelo seu [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto. O valor é retornado para [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status sobre a operação com a qual ela é identificada. Consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.  
  
##  <a name="remove"></a>CFtpConnection::Remove  
 Chame essa função de membro para excluir o arquivo especificado do servidor conectado.  
  
```  
BOOL Remove(LPCTSTR pstrFileName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrFileName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
### <a name="remarks"></a>Comentários  
 O `pstrFileName` parâmetro pode ser um nome qualificado parcialmente totalmente qualificado ou relativo para o diretório atual. Uma barra invertida (\\) ou barra invertida (/) pode ser usada como separador de diretório para qualquer nome. O **remover** função converte os separadores de nome de diretório para os caracteres apropriados antes de serem usadas.  
  
##  <a name="removedirectory"></a>CFtpConnection::RemoveDirectory  
 Chame essa função de membro para remover o diretório especificado do servidor conectado.  
  
```  
BOOL RemoveDirectory(LPCTSTR pstrDirName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrDirName`  
 Um ponteiro para uma cadeia de caracteres que contém o diretório a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
### <a name="remarks"></a>Comentários  
 Use [GetCurrentDirectory](#getcurrentdirectory) para determinar o diretório de trabalho atual do servidor. Não suponha que o sistema remoto conectou você para o diretório raiz.  
  
 O `pstrDirName` parâmetro pode ser um nome parcial ou totalmente qualificado relativo ao diretório atual. Uma barra invertida (\\) ou barra invertida (/) pode ser usada como separador de diretório para qualquer nome. `RemoveDirectory`converte os separadores de nome de diretório para os caracteres apropriados antes de serem usadas.  
  
##  <a name="rename"></a>CFtpConnection::Rename  
 Chame essa função de membro para renomear o arquivo especificado no servidor conectado.  
  
```  
BOOL Rename(
    LPCTSTR pstrExisting,  
    LPCTSTR pstrNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrExisting`  
 Um ponteiro para uma cadeia de caracteres que contém o nome atual do arquivo a ser renomeado.  
  
 `pstrNew`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo novo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
### <a name="remarks"></a>Comentários  
 O `pstrExisting` e `pstrNew` parâmetros podem ser um nome qualificado parcialmente totalmente qualificado ou relativo para o diretório atual. Uma barra invertida (\\) ou barra invertida (/) pode ser usada como separador de diretório para qualquer nome. **Renomear** converte os separadores de nome de diretório para os caracteres apropriados antes de serem usadas.  
  
##  <a name="setcurrentdirectory"></a>CFtpConnection::SetCurrentDirectory  
 Chame essa função de membro para alterar para um diretório diferente no servidor FTP.  
  
```  
BOOL SetCurrentDirectory(LPCTSTR pstrDirName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrDirName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do diretório.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
### <a name="remarks"></a>Comentários  
 O `pstrDirName` parâmetro pode ser um nome parcial ou totalmente qualificado relativo ao diretório atual. Uma barra invertida (\\) ou barra invertida (/) pode ser usada como separador de diretório para qualquer nome. `SetCurrentDirectory`converte os separadores de nome de diretório para os caracteres apropriados antes de serem usadas.  
  
 Use [GetCurrentDirectory](#getcurrentdirectory) para determinar o diretório de trabalho atual de um servidor FTP. Não suponha que o sistema remoto conectou você para o diretório raiz.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)   
 [Classe CInternetSession](../../mfc/reference/cinternetsession-class.md)
