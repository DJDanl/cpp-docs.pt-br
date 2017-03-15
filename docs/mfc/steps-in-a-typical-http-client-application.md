---
title: "Etapas em um aplicativo cliente HTTP t&#237;pico | Microsoft Docs"
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
  - "aplicativos [MFC], cliente HTTP"
  - "aplicativos cliente [C++], HTTP"
  - "aplicativos cliente HTTP"
  - "Aplicativos da Internet [C++], aplicativos cliente HTTP"
  - "aplicativos cliente da Internet [C++], tabela HTTP"
  - "Classes WinInet, HTTP"
ms.assetid: f86552e8-8acd-4b23-bdc5-0c3a247ebd74
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Etapas em um aplicativo cliente HTTP t&#237;pico
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir mostra as etapas que você pode executar em um aplicativo cliente típico de HTTP:  
  
|Sua meta|Ações que você faça|Efeitos|  
|--------------|-------------------------|-------------|  
|Inicia uma sessão HTTP.|Crie um objeto de [CInternetSession](../Topic/CInternetSession%20Class.md) .|Inicializa WinInet e conecte\-se ao servidor.|  
|Conectar a um servidor HTTP.|Use [CInternetSession::GetHttpConnection](../Topic/CInternetSession::GetHttpConnection.md).|Retorna um objeto de [CHttpConnection](../mfc/reference/chttpconnection-class.md) .|  
|Abra uma solicitação HTTP.|Use [CHttpConnection::OpenRequest](../Topic/CHttpConnection::OpenRequest.md).|Retorna um objeto de [CHttpFile](../Topic/CHttpFile%20Class.md) .|  
|Enviar uma solicitação HTTP.|Use [CHttpFile::AddRequestHeaders](../Topic/CHttpFile::AddRequestHeaders.md) e [CHttpFile::SendRequest](../Topic/CHttpFile::SendRequest.md).|Localiza o arquivo.  Retornará FALSE se o arquivo não for localizado.|  
|Leitura do arquivo.|Use [CHttpFile](../Topic/CHttpFile%20Class.md).|Ler o número especificado de bytes usando um buffer que você fornece.|  
|Trate exceções.|Use a classe de [CInternetException](../mfc/reference/cinternetexception-class.md) .|Controla todos os tipos de exceção comuns da Internet.|  
|Encerra a sessão HTTP.|Disponha do objeto de [CInternetSession](../Topic/CInternetSession%20Class.md) .|Limpa automaticamente os identificadores de arquivos abertos e conexões.|  
  
## Consulte também  
 [Extensões da Internet Win32 \(WinInet\)](../mfc/win32-internet-extensions-wininet.md)   
 [Pré\-requisitos para classes clientes de Internet](../Topic/Prerequisites%20for%20Internet%20Client%20Classes.md)   
 [Escrevendo um aplicativo cliente da Internet usando classes WinInet MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)