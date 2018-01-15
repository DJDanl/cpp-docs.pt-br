---
title: Classe CHttpConnection | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CHttpConnection
- AFXINET/CHttpConnection
- AFXINET/CHttpConnection::CHttpConnection
- AFXINET/CHttpConnection::OpenRequest
dev_langs: C++
helpviewer_keywords:
- CHttpConnection [MFC], CHttpConnection
- CHttpConnection [MFC], OpenRequest
ms.assetid: a402b662-c445-4988-800d-c8278551babe
caps.latest.revision: "24"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5a5236a4a957c742074a1305ba2d4359da3ed967
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="chttpconnection-class"></a>Classe CHttpConnection
Gerencia a conexão a um servidor HTTP.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CHttpConnection : public CInternetConnection  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHttpConnection::CHttpConnection](#chttpconnection)|Cria um objeto `CHttpConnection`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHttpConnection::OpenRequest](#openrequest)|Abre uma solicitação HTTP.|  
  
## <a name="remarks"></a>Comentários  
 HTTP é um dos três protocolos de servidor de Internet implementados pelas classes WinInet MFC.  
  
 A classe `CHttpConnection` contém um construtor e a função de um membro, [OpenRequest](#openrequest), que gerencia as conexões a um servidor com um protocolo HTTP.  
  
 Para se comunicar com um servidor HTTP, você deve primeiro criar uma instância de [CInternetSession](../../mfc/reference/cinternetsession-class.md)e, em seguida, crie um [CHttpConnection](#_mfc_chttpconnection) objeto. Você nunca criar um `CHttpConnection` objeto diretamente; em vez disso, chame [CInternetSession::GetHttpConnection](../../mfc/reference/cinternetsession-class.md#gethttpconnection), que cria o `CHttpConnection` de objeto e retorna um ponteiro para ele.  
  
 Para saber mais sobre como `CHttpConnection` funciona com as outras classes de Internet MFC, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md). Para obter mais informações sobre como se conectar a servidores usando os outros dois protocolos de Internet, gopher e FTP com suporte, consulte as classes [CGopherConnection](../../mfc/reference/cgopherconnection-class.md) e [CFtpConnection](../../mfc/reference/cftpconnection-class.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CInternetConnection](../../mfc/reference/cinternetconnection-class.md)  
  
 `CHttpConnection`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxinet.h  
  
##  <a name="chttpconnection"></a>CHttpConnection::CHttpConnection  
 Essa função de membro é chamada para construir um `CHttpConnection` objeto.  
  
```  
CHttpConnection(
    CInternetSession* pSession,  
    HINTERNET hConnected,  
    LPCTSTR pstrServer,  
    DWORD_PTR dwContext);

 
CHttpConnection(
    CInternetSession* pSession,  
    LPCTSTR pstrServer,  
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER,  
    LPCTSTR pstrUserName = NULL,  
    LPCTSTR pstrPassword = NULL,  
    DWORD_PTR dwContext = 1);

 
CHttpConnection(
    CInternetSession* pSession,  
    LPCTSTR pstrServer,  
    DWORD dwFlags,  
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER,  
    LPCTSTR pstrUserName = NULL,  
    LPCTSTR pstrPassword = NULL,  
    DWORD_PTR dwContext = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSession`  
 Um ponteiro para um [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto.  
  
 `hConnected`  
 Um identificador para uma conexão de Internet.  
  
 `pstrServer`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do servidor.  
  
 `dwContext`  
 O identificador de contexto para o `CInternetConnection` objeto. Consulte **comentários** para obter mais informações sobre `dwContext`.  
  
 `nPort`  
 O número que identifica a porta de Internet para esta conexão.  
  
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
  
 `dwFlags`  
 Qualquer combinação da **Flag Internet _ _\***  sinalizadores. Consulte a tabela de **comentários** seção [CHttpConnection::OpenRequest](#openrequest) para obter uma descrição de `dwFlags` valores.  
  
### <a name="remarks"></a>Comentários  
 Você nunca criar um `CHttpConnection` diretamente. Em vez disso, você cria um objeto chamando [CInternetSession::GetHttpConnection](../../mfc/reference/cinternetsession-class.md#gethttpconnection).  
  
##  <a name="openrequest"></a>CHttpConnection::OpenRequest  
 Chame essa função de membro para abrir uma conexão HTTP.  
  
```  
CHttpFile* OpenRequest(
    LPCTSTR pstrVerb,  
    LPCTSTR pstrObjectName,  
    LPCTSTR pstrReferer = NULL,  
    DWORD_PTR dwContext = 1,  
    LPCTSTR* ppstrAcceptTypes = NULL,  
    LPCTSTR pstrVersion = NULL,  
    DWORD dwFlags = INTERNET_FLAG_EXISTING_CONNECT);

 
CHttpFile* OpenRequest(
    int nVerb,  
    LPCTSTR pstrObjectName,  
    LPCTSTR pstrReferer = NULL,  
    DWORD_PTR dwContext = 1,  
    LPCTSTR* ppstrAcceptTypes = NULL,  
    LPCTSTR pstrVersion = NULL,  
    DWORD dwFlags = INTERNET_FLAG_EXISTING_CONNECT);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pstrVerb`  
 Um ponteiro para uma cadeia de caracteres que contém o verbo a ser usado na solicitação. Se `NULL`, "GET" é usado.  
  
 `pstrObjectName`  
 Um ponteiro para uma cadeia de caracteres que contém o objeto de destino do verbo especificado. Isso geralmente é um nome de arquivo, um módulo executável ou um especificador de pesquisa.  
  
 `pstrReferer`  
 Um ponteiro para uma cadeia de caracteres que especifica o endereço (URL) do documento do qual a URL na solicitação ( `pstrObjectName`) foi obtido. Se `NULL`, nenhum cabeçalho HTTP especificado.  
  
 `dwContext`  
 O identificador de contexto para o `OpenRequest` operação. Consulte a seção de comentários para obter mais informações `dwContext`.  
  
 `ppstrAcceptTypes`  
 Um ponteiro para uma matriz com terminação nula de `LPCTSTR` ponteiros em cadeias de caracteres que indica os tipos de conteúdo aceito pelo cliente. Se `ppstrAcceptTypes` é `NULL`, os servidores de interpretam o que o cliente só aceita documentos do tipo "texto / *" (ou seja, documentos de texto somente e não imagens ou outros arquivos binários). O tipo de conteúdo é equivalente a tipo_de_conteúdo variável CGI, que identifica o tipo de dados para consultas que foram anexados informações, como HTTP POST e PUT.  
  
 `pstrVersion`  
 Um ponteiro para uma cadeia de caracteres que define a versão HTTP. Se `NULL`, "HTTP/1.0" é usado.  
  
 `dwFlags`  
 Qualquer combinação dos sinalizadores Internet _ Flag _ *. Consulte a seção comentários para obter uma descrição de possíveis `dwFlags` valores.  
  
 `nVerb`  
 Um número associado ao tipo de solicitação HTTP. Pode ser um dos seguintes:  
  
|Tipo de solicitação HTTP|Valor `nVerb`|  
|-----------------------|-------------------|  
|`HTTP_VERB_POST`|0|  
|`HTTP_VERB_GET`|1|  
|`HTTP_VERB_HEAD`|2|  
|`HTTP_VERB_PUT`|3|  
|`HTTP_VERB_LINK`|4|  
|`HTTP_VERB_DELETE`|5|  
|`HTTP_VERB_UNLINK`|6|  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [CHttpFile](../../mfc/reference/chttpfile-class.md) objeto solicitado.  
  
### <a name="remarks"></a>Comentários  
 `dwFlags` pode ser um dos seguintes itens:  
  
|Sinalizador de Internet|Descrição|  
|-------------------|-----------------|  
|`INTERNET_FLAG_RELOAD`|Força um download de arquivo solicitada, objeto ou listagem de diretório do servidor de origem, não do cache.|  
|`INTERNET_FLAG_DONT_CACHE`|Não adiciona a entidade retornada para o cache.|  
|`INTERNET_FLAG_MAKE_PERSISTENT`|Adiciona a entidade retornada para o cache como uma entidade persistente. Isso significa que a limpeza do cache padrão, a verificação de consistência ou coleta de lixo não pode remover este item de cache.|  
|`INTERNET_FLAG_SECURE`|Usa segura semântica de transação. Isso se traduz em usando SSL/PCT e só é significativo em solicitações HTTP|  
|`INTERNET_FLAG_NO_AUTO_REDIRECT`|Usado somente com HTTP, especifica que redirecionamentos não devem ser automaticamente tratados em [CHttpFile::SendRequest](../../mfc/reference/chttpfile-class.md#sendrequest).|  
  
 Substituir o `dwContext` padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto está associado essa operação específica do `CHttpConnection` objeto criado pelo seu [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto. O valor é retornado para [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status sobre a operação com a qual ela é identificada. Consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.  
  
 Exceções podem ser geradas com essa função.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)   
 [Classe CHttpFile](../../mfc/reference/chttpfile-class.md)
