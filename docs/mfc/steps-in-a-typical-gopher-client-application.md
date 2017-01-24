---
title: "Etapas em um aplicativo cliente gopher t&#237;pico | Microsoft Docs"
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
  - "Aplicativos cliente Gopher"
  - "aplicativos da Internet, aplicativos cliente gopher"
  - "aplicativos cliente da Internet, tabela gopher"
  - "Classes WinInet, gopher"
ms.assetid: 3e4e1869-5da0-453d-8ba9-b648c894bb90
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Etapas em um aplicativo cliente gopher t&#237;pico
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir mostra as etapas que você pode executar em um aplicativo cliente típico de Gopher.  
  
|Sua meta|Ações que você faça|Efeitos|  
|--------------|-------------------------|-------------|  
|Inicia uma sessão de Gopher.|Crie um objeto de [CInternetSession](../Topic/CInternetSession%20Class.md) .|Inicializa WinInet e conecte\-se ao servidor.|  
|Conectar a um servidor de Gopher.|Use [CInternetSession::GetGopherConnection](../Topic/CInternetSession::GetGopherConnection.md).|Retorna um objeto de [CGopherConnection](../mfc/reference/cgopherconnection-class.md) .|  
|Localizar o primeiro recurso em Gopher.|Use [CGopherFileFind::FindFile](../Topic/CGopherFileFind::FindFile.md).|Localiza o primeiro arquivo.  Retornará FALSE se nenhum arquivo é encontrado.|  
|Localizar o recurso Gopher próximo no.|Use [CGopherFileFind::FindNextFile](../Topic/CGopherFileFind::FindNextFile.md).|Localiza o próximo arquivo.  Retornará FALSE se o arquivo não for localizado.|  
|Abra o arquivo localizado por **FindFile** ou por `FindNextFile` para.|Obter um localizador de [CGopherFileFind::GetLocator](../Topic/CGopherFileFind::GetLocator.md). usando Gopher  Use [CGopherConnection::OpenFile](../Topic/CGopherConnection::OpenFile.md).|Abre o arquivo especificado pelo localizador.  `OpenFile` retorna um objeto de [CGopherFile](../mfc/reference/cgopherfile-class.md) .|  
|Abra um arquivo usando um localizador de Gopher você fornece.|Crie um localizador de [CGopherConnection::CreateLocator](../Topic/CGopherConnection::CreateLocator.md). usando Gopher  Use [CGopherConnection::OpenFile](../Topic/CGopherConnection::OpenFile.md).|Abre o arquivo especificado pelo localizador.  `OpenFile` retorna um objeto de [CGopherFile](../mfc/reference/cgopherfile-class.md) .|  
|Leitura do arquivo.|Use [CGopherFile](../mfc/reference/cgopherfile-class.md).|Número de bytes especificado, usando um buffer que você fornece.|  
|Trate exceções.|Use a classe de [CInternetException](../mfc/reference/cinternetexception-class.md) .|Controla todos os tipos de exceção comuns da Internet.|  
|Encerra a sessão de Gopher.|Disponha do objeto de [CInternetSession](../Topic/CInternetSession%20Class.md) .|Limpa automaticamente os identificadores de arquivos abertos e conexões.|  
  
## Consulte também  
 [Extensões da Internet Win32 \(WinInet\)](../mfc/win32-internet-extensions-wininet.md)   
 [Pré\-requisitos para classes clientes de Internet](../Topic/Prerequisites%20for%20Internet%20Client%20Classes.md)   
 [Escrevendo um aplicativo cliente da Internet usando classes WinInet MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)