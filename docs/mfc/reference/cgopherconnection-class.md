---
title: Classe CGopherConnection | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CGopherConnection
- AFXINET/CGopherConnection
- AFXINET/CGopherConnection::CGopherConnection
- AFXINET/CGopherConnection::CreateLocator
- AFXINET/CGopherConnection::GetAttribute
- AFXINET/CGopherConnection::OpenFile
dev_langs:
- C++
helpviewer_keywords:
- CGopherConnection [MFC], CGopherConnection
- CGopherConnection [MFC], CreateLocator
- CGopherConnection [MFC], GetAttribute
- CGopherConnection [MFC], OpenFile
ms.assetid: b5b96aea-ac99-430e-bd84-d1372b43f78f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d669ebc954b73d848e22dc373704ab3434074274
ms.sourcegitcommit: 9239c52c05e5cd19b6a72005372179587a47a8e4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2018
---
# <a name="cgopherconnection-class"></a>Classe CGopherConnection
Gerencia a conexão para um servidor de Internet gopher.  
  
> [!NOTE]
>  As classes `CGopherConnection`, `CGopherFile`, `CGopherFileFind`, `CGopherLocator` e seus membros tenham sido substituídos porque eles não funcionam na plataforma Windows XP, mas eles continuarão a funcionar em plataformas anteriores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CGopherConnection : public CInternetConnection  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGopherConnection::CGopherConnection](#cgopherconnection)|Constrói um objeto `CGopherConnection`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGopherConnection::CreateLocator](#createlocator)|Cria um [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) objeto para localizar arquivos em um servidor gopher.|  
|[CGopherConnection::GetAttribute](#getattribute)|Recupera informações de atributo sobre o objeto gopher.|  
|[CGopherConnection::OpenFile](#openfile)|Abre um arquivo gopher.|  
  
## <a name="remarks"></a>Comentários  
 O serviço gopher é um dos três serviços de Internet reconhecidos pelas classes WinInet MFC.  
  
 A classe `CGopherConnection` contém um construtor e três funções de membro adicionais que gerencia o serviço gopher: [OpenFile](#openfile), [CreateLocator](#createlocator), e [GetAttribute](#getattribute).  
  
 Para se comunicar com um servidor de Internet gopher, você deve primeiro criar uma instância de [CInternetSession](../../mfc/reference/cinternetsession-class.md)e, em seguida, chame [CInternetSession::GetGopherConnection](../../mfc/reference/cinternetsession-class.md#getgopherconnection), que cria o `CGopherConnection` objeto e retorna um ponteiro para ele. Você nunca criar um `CGopherConnection` diretamente do objeto.  
  
 Para saber mais sobre como `CGopherConnection` funciona com as outras classes de Internet MFC, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md). Para obter mais informações sobre como usar os outros dois com suporte a serviços de Internet, FTP e HTTP ver as classes [CHttpConnection](../../mfc/reference/chttpconnection-class.md) e [CFtpConnection](../../mfc/reference/cftpconnection-class.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CInternetConnection](../../mfc/reference/cinternetconnection-class.md)  
  
 `CGopherConnection`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxinet.h  
  
##  <a name="cgopherconnection"></a>  CGopherConnection::CGopherConnection  
 Essa função de membro é chamada para construir um `CGopherConnection` objeto.  
  
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
 `pSession`  
 Um ponteiro para relacionado [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto.  
  
 `hConnected`  
 O identificador do Windows da sessão atual da Internet.  
  
 `pstrServer`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do servidor FTP.  
  
 `dwContext`  
 O identificador de contexto para a operação. `dwContext` identifica as informações de status da operação retornadas por [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback). O padrão é definido como 1; No entanto, você pode explicitamente atribuir uma ID de contexto específico para a operação. O objeto e qualquer trabalho faz será associados esse ID de contexto.  
  
 `pstrUserName`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do usuário para fazer logon. Se **nulo**, o padrão é anônimo.  
  
 `pstrPassword`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo que especifica a senha a ser usada para fazer logon. Se ambos os `pstrPassword` e `pstrUserName` são **nulo**, a senha anônima padrão é o nome de email do usuário. Se `pstrPassword` é **nulo** (ou uma cadeia de caracteres vazia), mas `pstrUserName` não é **nulo**, uma senha em branco será usada. A tabela a seguir descreve o comportamento para as quatro configurações possíveis de `pstrUserName` e `pstrPassword`:  
  
|`pstrUserName`|`pstrPassword`|Nome de usuário enviado ao servidor FTP|Senha enviada ao servidor FTP|  
|--------------------|--------------------|---------------------------------|---------------------------------|  
|**NULO** ou ""|**NULO** ou ""|"anônimo"|Nome de email do usuário|  
|Não- **nulo** cadeia de caracteres|**NULO** ou ""|`pstrUserName`|" "|  
|**NULO** não **nulo** cadeia de caracteres|**ERROR**|**ERROR**||  
|Não- **nulo** cadeia de caracteres|Não- **nulo** cadeia de caracteres|`pstrUserName`|`pstrPassword`|  
  
 `nPort`  
 Um número que identifica a porta TCP/IP para usar no servidor.  
  
### <a name="remarks"></a>Comentários  
 Você nunca criar um `CGopherConnection` diretamente. Em vez disso, chame [CInternetSession::GetGopherConnection](../../mfc/reference/cinternetsession-class.md#getgopherconnection), que cria um `CGopherConnection` de objeto e retorna um ponteiro para ele.  
  
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
 `pstrDisplayString`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do documento gopher ou diretório a ser recuperado. Se o `pstrDisplayString` parâmetro é **nulo**, o diretório padrão para o servidor gopher será retornado.  
  
 `pstrSelectorString`  
 Um ponteiro para a cadeia de caracteres do seletor para ser enviado ao servidor gopher para recuperar um item. `pstrSelectorString` pode ser **nulo**.  
  
 *dwGopherType*  
 Especifica se `pstrSelectorString` refere-se a um diretório ou um documento, e se a solicitação é gopher ou gopher +. Consulte os atributos para a estrutura [GOPHER_FIND_DATA](http://msdn.microsoft.com/library/windows/desktop/aa384215) no SDK do Windows.  
  
 `pstrLocator`  
 Um ponteiro para uma cadeia de caracteres que identifica o arquivo a ser aberto. Geralmente, essa cadeia de caracteres é retornada de uma chamada para [CGopherFileFind::GetLocator](../../mfc/reference/cgopherfilefind-class.md#getlocator).  
  
 *pstrServerName*  
 Um ponteiro para uma cadeia de caracteres que contém o nome do servidor gopher.  
  
 `nPort`  
 O número que identifica a porta de Internet para esta conexão.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 A versão estática da função de membro exige que você especificar um servidor, enquanto a versão de não-estático usa o nome do servidor do objeto de conexão.  
  
 Para recuperar informações de um servidor gopher, um aplicativo deve primeiro obter um localizador de gopher. O aplicativo trate o localizador como um token opaco (ou seja, o aplicativo pode usar o localizador, mas não diretamente manipular ou compará-lo). Normalmente, o aplicativo usa o localizador de chamadas para o [CGopherFileFind::FindFile](../../mfc/reference/cgopherfilefind-class.md#findfile) função de membro para recuperar uma informação específica.  
  
##  <a name="getattribute"></a>  CGopherConnection::GetAttribute  
 Chame essa função de membro para recuperar informações de atributo específico sobre um item do servidor gopher.  
  
```  
BOOL GetAttribute(
    CGopherLocator& refLocator    CString strRequestedAttributes,  
    CString& strResult,);
```  
  
### <a name="parameters"></a>Parâmetros  
 `refLocator`  
 Uma referência a um [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) objeto.  
  
 *strRequestedAttributes*  
 Uma cadeia delimitada por espaço especificando os nomes dos atributos solicitados.  
  
 `strResult`  
 Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que recebe o tipo de localizador.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
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
 `refLocator`  
 Uma referência a um [CGopherLocator](../../mfc/reference/cgopherlocator-class.md) objeto.  
  
 `dwFlags`  
 Qualquer combinação dos sinalizadores INTERNET_FLAG_ *. Consulte [CInternetSession::OpenUrl](../../mfc/reference/cinternetsession-class.md#openurl) para obter mais informações sobre INTERNET_FLAG_\* sinalizadores.  
  
 `pstrView`  
 Um ponteiro para uma cadeia de caracteres de exibição do arquivo. Se existirem vários modos de exibição do arquivo no servidor, esse parâmetro especifica qual modo de exibição para abrir o arquivo. Se `pstrView` é **nulo**, a exibição de arquivo padrão é usada.  
  
 `dwContext`  
 A ID do contexto para o arquivo que está sendo aberto. Consulte **comentários** para obter mais informações sobre `dwContext`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [CGopherFile](../../mfc/reference/cgopherfile-class.md) objeto a ser aberto.  
  
### <a name="remarks"></a>Comentários  
 Substituir o `dwContext` padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto está associado essa operação específica do `CGopherConnection` objeto criado pelo seu [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto. O valor é retornado para [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status sobre a operação com a qual ela é identificada. Consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFtpConnection](../../mfc/reference/cftpconnection-class.md)   
 [Classe CHttpConnection](../../mfc/reference/chttpconnection-class.md)   
 [Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)   
 [Classe CGopherLocator](../../mfc/reference/cgopherlocator-class.md)   
 [Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)   
 [Classe CInternetSession](../../mfc/reference/cinternetsession-class.md)
