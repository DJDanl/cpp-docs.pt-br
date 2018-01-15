---
title: Classe CInternetConnection | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CInternetConnection
- AFXINET/CInternetConnection
- AFXINET/CInternetConnection::CInternetConnection
- AFXINET/CInternetConnection::GetContext
- AFXINET/CInternetConnection::GetServerName
- AFXINET/CInternetConnection::GetSession
dev_langs: C++
helpviewer_keywords:
- CInternetConnection [MFC], CInternetConnection
- CInternetConnection [MFC], GetContext
- CInternetConnection [MFC], GetServerName
- CInternetConnection [MFC], GetSession
ms.assetid: 62a5d1c3-8471-4e36-a064-48831829b2a7
caps.latest.revision: "21"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d0c20cee097ae0ba61a9106da0476541e7d7c18e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cinternetconnection-class"></a>Classe CInternetConnection
Gerencia a conexão a um servidor de Internet.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CInternetConnection : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInternetConnection::CInternetConnection](#cinternetconnection)|Constrói um objeto `CInternetConnection`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInternetConnection::GetContext](#getcontext)|Obtém a ID do contexto para este objeto de conexão.|  
|[CInternetConnection::GetServerName](#getservername)|Obtém o nome do servidor associado com a conexão.|  
|[CInternetConnection::GetSession](#getsession)|Obtém um ponteiro para o [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto associado com a conexão.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInternetConnection::operator HINTERNET](#operator_hinternet)|Um identificador para uma sessão de Internet.|  
  
## <a name="remarks"></a>Comentários  
 É a classe base para classes MFC [CFtpConnection](../../mfc/reference/cftpconnection-class.md), [CHttpConnection](../../mfc/reference/chttpconnection-class.md), e [CGopherConnection](../../mfc/reference/cgopherconnection-class.md). Cada uma dessas classes fornece funcionalidade adicional para se comunicar com o respectivo servidor gopher, HTTP ou FTP.  
  
 Para se comunicar diretamente com um servidor de Internet, você deve ter uma [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto e um `CInternetConnection` objeto.  
  
 Para saber mais sobre como as classes de WinInet trabalho, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CInternetConnection`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxinet.h  
  
##  <a name="cinternetconnection"></a>CInternetConnection::CInternetConnection  
 Essa função de membro é chamada quando um `CInternetConnection` objeto é criado.  
  
```  
CInternetConnection(
    CInternetSession* pSession,  
    LPCTSTR pstrServer,  
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER,  
    DWORD_PTR dwContext = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSession`  
 Um ponteiro para um [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto.  
  
 `pstrServer`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do servidor.  
  
 `nPort`  
 O número que identifica a porta de Internet para esta conexão.  
  
 `dwContext`  
 O identificador de contexto para o `CInternetConnection` objeto. Consulte **comentários** para obter mais informações sobre `dwContext`.  
  
### <a name="remarks"></a>Comentários  
 Você nunca chamar `CInternetConnection` por conta própria; em vez disso, chame o [CInternetSession](../../mfc/reference/cinternetsession-class.md) a função de membro para o tipo de conexão que você deseja estabelecer:  
  
- [CInternetSession::GetFtpConnection](../../mfc/reference/cinternetsession-class.md#getftpconnection)  
  
- [CInternetSession::GetHttpConnection](../../mfc/reference/cinternetsession-class.md#gethttpconnection)  
  
- [CInternetSession::GetGopherConnection](../../mfc/reference/cinternetsession-class.md#getgopherconnection)  
  
 O valor padrão para `dwContext` é enviada pelo MFC para o `CInternetConnection`-derivados do objeto do [CInternetSession](../../mfc/reference/cinternetsession-class.md) do objeto que criou o **InternetConnection**-objeto derivado. O padrão é definido como 1; No entanto, você pode atribuir um identificador de contexto específico no explicitamente o [CInternetSession](../../mfc/reference/cinternetsession-class.md#cinternetsession) construtor para a conexão. O objeto e qualquer trabalho faz será associados esse ID de contexto. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status do objeto ao qual ela é identificada. Consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.  
  
##  <a name="getcontext"></a>CInternetConnection::GetContext  
 Chame essa função de membro para obter a ID do contexto para esta sessão.  
  
```  
DWORD_PTR GetContext() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A ID do contexto de aplicativo atribuído.  
  
### <a name="remarks"></a>Comentários  
 A ID de contexto é especificada originalmente no [CInternetSession](../../mfc/reference/cinternetsession-class.md) e se propaga para `CInternetConnection`- e [CInternetFile](../../mfc/reference/cinternetfile-class.md)-classes derivadas, a menos que especificado de forma diferente na chamada para uma função que é aberta a conexão. A ID do contexto associado a qualquer operação do objeto especificado e identifica as informações de status da operação retornadas por [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback).  
  
 Para obter mais informações sobre como **GetContext** funciona com outras classes WinInet para fornecer as informações de status do usuário, consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o contexto identificador.  
  
##  <a name="getservername"></a>CInternetConnection::GetServerName  
 Chame essa função de membro para obter o nome do servidor associado a esta conexão de Internet.  
  
```  
CString GetServerName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome do servidor do qual com que esse objeto de conexão está funcionando.  
  
##  <a name="getsession"></a>CInternetConnection::GetSession  
 Chamar essa função de membro para obter um ponteiro para o `CInternetSession` objeto associado a esta conexão.  
  
```  
CInternetSession* GetSession() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto associado a este objeto de conexão de Internet.  
  
##  <a name="operator_hinternet"></a>CInternetConnection::operator HINTERNET  
 Use este operador para obter o identificador de nível de API para a sessão atual da Internet.  
  
```  
operator HINTERNET() const;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



