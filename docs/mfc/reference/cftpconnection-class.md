---
title: "Classe de CFtpConnection | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CFtpConnection"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFtpConnection"
  - "Protocolo FTP (FTP), estabelecendo conexões"
  - "Conexões a internet, FTP"
  - "Serviços de Internet, FTP"
ms.assetid: 5e3a0501-8893-49cf-a3d5-0628d8d6b936
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CFtpConnection
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencia sua conexão FTP para um servidor da Internet e permite tratamento direta de diretórios e arquivos no servidor.  
  
## Sintaxe  
  
```  
class CFtpConnection : public CInternetConnection  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFtpConnection::CFtpConnection](../Topic/CFtpConnection::CFtpConnection.md)|Constrói um objeto de `CFtpConnection` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFtpConnection::Command](../Topic/CFtpConnection::Command.md)|Envia um comando diretamente a um servidor FTP.|  
|[CFtpConnection::CreateDirectory](../Topic/CFtpConnection::CreateDirectory.md)|Cria um diretório no servidor.|  
|[CFtpConnection::GetCurrentDirectory](../Topic/CFtpConnection::GetCurrentDirectory.md)|Obtém o diretório atual para a conexão.|  
|[CFtpConnection::GetCurrentDirectoryAsURL](../Topic/CFtpConnection::GetCurrentDirectoryAsURL.md)|Obtém o diretório atual para a conexão como um URL.|  
|[CFtpConnection::GetFile](../Topic/CFtpConnection::GetFile.md)|Obtém um arquivo de servidor conectado|  
|[CFtpConnection::OpenFile](../Topic/CFtpConnection::OpenFile.md)|Abrir um arquivo no servidor conectado.|  
|[CFtpConnection::PutFile](../Topic/CFtpConnection::PutFile.md)|Coloca um arquivo no servidor.|  
|[CFtpConnection::Remove](../Topic/CFtpConnection::Remove.md)|Remove um arquivo de servidor.|  
|[CFtpConnection::RemoveDirectory](../Topic/CFtpConnection::RemoveDirectory.md)|Remove o diretório especificado do servidor.|  
|[CFtpConnection::Rename](../Topic/CFtpConnection::Rename.md)|Renomeia um arquivo no servidor.|  
|[CFtpConnection::SetCurrentDirectory](../Topic/CFtpConnection::SetCurrentDirectory.md)|Define o diretório atual FTP.|  
  
## Comentários  
 FTP é um dos três serviços de Internet reconhecidos pelas classes MFC WinInet.  
  
 Para se comunicar com um servidor FTP Internet, você deve primeiro criar uma instância de [CInternetSession](../Topic/CInternetSession%20Class.md)e em seguida, cria um objeto de `CFtpConnection` .  Você nunca cria um objeto de `CFtpConnection` diretamente; em vez de isso, [CInternetSession::GetFtpConnection](../Topic/CInternetSession::GetFtpConnection.md)chamada, que cria o objeto de `CFtpConnection` e ela retorna um ponteiro.  
  
 Para saber mais sobre como `CFtpConnection` trabalhar com as outras classes MFC Internet, consulte o artigo [Internet que programa com WinInet](../../mfc/win32-internet-extensions-wininet.md).  Para obter mais informações sobre a comunicação com dois outros serviços HTTP suportados, e o Gopher, consulte as classes [CHttpConnection](../../mfc/reference/chttpconnection-class.md) e [CGopherConnection](../../mfc/reference/cgopherconnection-class.md).  
  
## Exemplo  
 Consulte o exemplo na visão geral da classe de [CFtpFileFind](../Topic/CFtpFileFind%20Class.md) .  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CInternetConnection](../Topic/CInternetConnection%20Class.md)  
  
 `CFtpConnection`  
  
## Requisitos  
 **Cabeçalho:** afxinet.h  
  
## Consulte também  
 [Classe de CInternetConnection](../Topic/CInternetConnection%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CInternetConnection](../Topic/CInternetConnection%20Class.md)   
 [Classe de CInternetSession](../Topic/CInternetSession%20Class.md)