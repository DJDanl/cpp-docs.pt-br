---
title: "Classe de CHttpConnection | Microsoft Docs"
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
  - "CHttpConnection"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CHttpConnection"
  - "conectar-se aos servidores"
  - "conectar-se aos servidores, Servidores HTTP"
  - "conexões [C++], HTTP"
  - "Conexões HTTP"
  - "Servidores HTTP, se conectar a"
  - "Conexões a internet, HTTP"
  - "Protocolos de Internet"
  - "Protocolos de Internet, HTTP"
  - "Servidor da Internet, HTTP"
  - "protocolos, HTTP"
  - "servidores, se conectar a"
ms.assetid: a402b662-c445-4988-800d-c8278551babe
caps.latest.revision: 24
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CHttpConnection
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencia sua conexão a um servidor HTTP.  
  
## Sintaxe  
  
```  
class CHttpConnection : public CInternetConnection  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHttpConnection::CHttpConnection](../Topic/CHttpConnection::CHttpConnection.md)|Cria um objeto de `CHttpConnection` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHttpConnection::OpenRequest](../Topic/CHttpConnection::OpenRequest.md)|Abre uma solicitação HTTP.|  
  
## Comentários  
 HTTP é um dos três protocolos de servidor da Internet implementados pelas classes MFC WinInet.  
  
 A classe `CHttpConnection` contém um construtor e uma função de membro, [OpenRequest](../Topic/CHttpConnection::OpenRequest.md), que gerencia conexões em um servidor com um protocolo HTTP.  
  
 Para se comunicar com um servidor HTTP, você deve primeiro criar uma instância de [CInternetSession](../Topic/CInternetSession%20Class.md)e em seguida, cria um objeto de [CHttpConnection](#_mfc_chttpconnection) .  Você nunca cria um objeto de `CHttpConnection` diretamente; em vez de isso, [CInternetSession::GetHttpConnection](../Topic/CInternetSession::GetHttpConnection.md)chamada, que cria o objeto de `CHttpConnection` e ela retorna um ponteiro.  
  
 Para saber mais sobre como `CHttpConnection` trabalhar com as outras classes MFC Internet, consulte o artigo [Internet que programa com WinInet](../../mfc/win32-internet-extensions-wininet.md).  Para obter mais informações sobre conectar aos outros dois servidores usando protocolos suporte da Internet, o Gopher e FTP, consulte as classes [CGopherConnection](../../mfc/reference/cgopherconnection-class.md) e [CFtpConnection](../../mfc/reference/cftpconnection-class.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CInternetConnection](../Topic/CInternetConnection%20Class.md)  
  
 `CHttpConnection`  
  
## Requisitos  
 **Cabeçalho:** afxinet.h  
  
## Consulte também  
 [Classe de CInternetConnection](../Topic/CInternetConnection%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CInternetConnection](../Topic/CInternetConnection%20Class.md)   
 [Classe de CHttpFile](../Topic/CHttpFile%20Class.md)