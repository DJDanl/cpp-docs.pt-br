---
title: "Como o MFC facilita a cria&#231;&#227;o de aplicativos clientes da Internet | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "aplicativos da Internet, MFC"
  - "aplicativos cliente da Internet, MFC"
  - "MFC, aplicativos da Internet"
ms.assetid: 94437b3f-f15c-437d-b5fd-264a2efec9ab
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como o MFC facilita a cria&#231;&#227;o de aplicativos clientes da Internet
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As classes do Microsoft encapsulam as funções de extensão do Win32 a Internet \(WinInet\) de um modo que fornece um contexto familiar para programadores MFC.  MFC O fornece três classes do arquivo da Internet \([CInternetFile](../mfc/reference/cinternetfile-class.md), [CHttpFile](../Topic/CHttpFile%20Class.md), e [CGopherFile](../mfc/reference/cgopherfile-class.md)\) derivadas da classe de [CStdioFile](../Topic/CStdioFile%20Class.md) .  Não só essas classes tornam a familiar recuperando e de manipulação de dados da Internet para programadores que usaram `CStdioFile` para arquivos locais, mas com essas classes você pode controlar arquivos locais e arquivos da Internet de uma maneira consistente, transparente.  
  
 As classes de MFC WinInet oferecem a mesma funcionalidade que `CStdioFile` para os dados que são transferidos por meio da Internet.  Essas classes abstratos os protocolos da Internet para HTTP, o FTP, e o Gopher em uma interface de programação de alto nível, fornecendo um caminho rápido e direta para disponibilizar aplicativos de reconhecimento de instância.  Por exemplo, conecte\-se a um servidor FTP ainda requer várias etapas em um de nível baixo, mas como um desenvolvedor de MFC, você só precisa fazer uma chamada a `CInternetSession::GetFTPConnection` para criar essa conexão.  
  
 Além disso, as classes de MFC WinInet oferece as seguintes vantagens:  
  
-   E\/S em buffer  
  
-   Identificadores de tipo seguras para seus dados  
  
-   Parâmetros padrão para muitas funções  
  
-   Manipulação de exceção para erros comuns da Internet  
  
-   Limpeza automática de identificadores e de conexões abertas  
  
## Consulte também  
 [Extensões da Internet Win32 \(WinInet\)](../mfc/win32-internet-extensions-wininet.md)   
 [Como WinInet facilita a criação de aplicativos clientes da Internet](../mfc/how-wininet-makes-it-easier-to-create-internet-client-applications.md)