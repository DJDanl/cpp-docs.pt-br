---
title: "Classe de CGopherConnection | Microsoft Docs"
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
  - "CGopherConnection"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CGopherConnection"
  - "conectar-se aos servidores"
  - "conectar-se aos servidores, servidores de Gopher"
  - "protocolo de Gopher"
  - "o servidor de Gopher"
  - "Conexões a internet, Gopher"
  - "Servidor da Internet, Gopher"
  - "protocolos, Gopher"
  - "servidores, se conectar a"
  - "serviços, Gopher"
ms.assetid: b5b96aea-ac99-430e-bd84-d1372b43f78f
caps.latest.revision: 21
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CGopherConnection
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencia sua conexão a um servidor da Internet de Gopher.  
  
> [!NOTE]
>  As classes `CGopherConnection`, `CGopherFile`, `CGopherFileFind`, `CGopherLocator` e seus membros foram substituídas porque não funcionam na plataforma Windows XP, mas continuarão a funcionar nas plataformas anteriores.  
  
## Sintaxe  
  
```  
class CGopherConnection : public CInternetConnection  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CGopherConnection::CGopherConnection](../Topic/CGopherConnection::CGopherConnection.md)|Constrói um objeto de `CGopherConnection` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CGopherConnection::CreateLocator](../Topic/CGopherConnection::CreateLocator.md)|Cria um objeto de [CGopherLocator](../Topic/CGopherLocator%20Class.md) para localizar arquivos em um servidor de Gopher.|  
|[CGopherConnection::GetAttribute](../Topic/CGopherConnection::GetAttribute.md)|Recupera informações de atributo sobre o objeto de Gopher.|  
|[CGopherConnection::OpenFile](../Topic/CGopherConnection::OpenFile.md)|Abre um arquivo de Gopher.|  
  
## Comentários  
 O serviço de Gopher é um dos três serviços de Internet reconhecidos pelas classes MFC WinInet.  
  
 A classe `CGopherConnection` contém um construtor e três funções de membro adicionais que gerenciar o serviço de Gopher: [OpenFile](../Topic/CGopherConnection::OpenFile.md), [CreateLocator](../Topic/CGopherConnection::CreateLocator.md), e [GetAttribute](../Topic/CGopherConnection::GetAttribute.md).  
  
 Para se comunicar com um servidor da Internet de Gopher, você deve primeiro criar uma instância de [CInternetSession](../Topic/CInternetSession%20Class.md)em seguida, chame [CInternetSession::GetGopherConnection](../Topic/CInternetSession::GetGopherConnection.md), que cria o objeto de `CGopherConnection` e ela retorna um ponteiro.  Você nunca cria um objeto de `CGopherConnection` diretamente.  
  
 Para saber mais sobre como `CGopherConnection` trabalhar com as outras classes MFC Internet, consulte o artigo [Internet que programa com WinInet](../../mfc/win32-internet-extensions-wininet.md).  Para obter mais informações sobre como usar dois outros serviços de Internet HTTP e suporte FTP, consulte as classes [CHttpConnection](../../mfc/reference/chttpconnection-class.md) e [CFtpConnection](../../mfc/reference/cftpconnection-class.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CInternetConnection](../Topic/CInternetConnection%20Class.md)  
  
 `CGopherConnection`  
  
## Requisitos  
 **Cabeçalho:** afxinet.h  
  
## Consulte também  
 [Classe de CInternetConnection](../Topic/CInternetConnection%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CFtpConnection](../../mfc/reference/cftpconnection-class.md)   
 [Classe de CHttpConnection](../../mfc/reference/chttpconnection-class.md)   
 [Classe de CInternetConnection](../Topic/CInternetConnection%20Class.md)   
 [Classe de CGopherLocator](../Topic/CGopherLocator%20Class.md)   
 [Classe de CGopherFile](../../mfc/reference/cgopherfile-class.md)   
 [Classe de CInternetSession](../Topic/CInternetSession%20Class.md)