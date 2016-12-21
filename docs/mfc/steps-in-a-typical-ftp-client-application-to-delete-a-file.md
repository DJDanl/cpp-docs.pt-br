---
title: "Etapas em um aplicativo cliente FTP t&#237;pico para excluir um arquivo | Microsoft Docs"
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
  - "FTP (File Transfer Protocol), aplicativos cliente"
  - "aplicativos da Internet, aplicativos cliente FTP"
  - "aplicativos cliente da Internet, Exclusão de FTP"
  - "Classes WinInet, FTP"
ms.assetid: 2c347a96-c0a4-4827-98fe-668406e552bc
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Etapas em um aplicativo cliente FTP t&#237;pico para excluir um arquivo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir mostra as etapas que você pode executar em um aplicativo cliente típico de FTP que excluísse um arquivo.  
  
|Sua meta|Ações que você faça|Efeitos|  
|--------------|-------------------------|-------------|  
|Inicia uma sessão de FTP.|Crie um objeto de [CInternetSession](../Topic/CInternetSession%20Class.md) .|Inicializa WinInet e conecte\-se ao servidor.|  
|Conectar a um servidor FTP.|Use [CInternetSession::GetFtpConnection](../Topic/CInternetSession::GetFtpConnection.md).|Retorna um objeto de [CFtpConnection](../mfc/reference/cftpconnection-class.md) .|  
|Verifique se o qual você está no diretório direito no servidor de FTP.|Use [CFtpConnection::GetCurrentDirectory](../Topic/CFtpConnection::GetCurrentDirectory.md) ou [CFtpConnection::GetCurrentDirectoryAsURL](../Topic/CFtpConnection::GetCurrentDirectoryAsURL.md).|Retorna o nome ou a URL do diretório que você está conectado atualmente no servidor, dependendo da função de membro selecionada.|  
|Altere para um novo diretório de FTP no servidor.|Use [CFtpConnection::SetCurrentDirectory](../Topic/CFtpConnection::SetCurrentDirectory.md).|Altera o diretório que você está conectado atualmente no servidor.|  
|Localizar o primeiro arquivo no diretório de FTP.|Use [CFtpFileFind::FindFile](../Topic/CFtpFileFind::FindFile.md).|Localiza o primeiro arquivo.  Retornará FALSE se nenhum arquivo é encontrado.|  
|Localize o arquivo seguinte no diretório de FTP.|Use [CFtpFileFind::FindNextFile](../Topic/CFtpFileFind::FindNextFile.md).|Localiza o próximo arquivo.  Retornará FALSE se o arquivo não for localizado.|  
|Exclua o arquivo localizado por **FindFile** ou por `FindNextFile`.|Use [CFtpConnection::Remove](../Topic/CFtpConnection::Remove.md), usando o nome de arquivo retornado por **FindFile** ou por `FindNextFile`.|Exclui o arquivo no servidor para ler ou gravar.|  
|Trate exceções.|Use a classe de [CInternetException](../mfc/reference/cinternetexception-class.md) .|Controla todos os tipos de exceção comuns da Internet.|  
|Encerra a sessão de FTP.|Disponha do objeto de [CInternetSession](../Topic/CInternetSession%20Class.md) .|Limpa automaticamente os identificadores de arquivos abertos e conexões.|  
  
## Consulte também  
 [Extensões da Internet Win32 \(WinInet\)](../mfc/win32-internet-extensions-wininet.md)   
 [Pré\-requisitos para classes clientes de Internet](../Topic/Prerequisites%20for%20Internet%20Client%20Classes.md)   
 [Escrevendo um aplicativo cliente da Internet usando classes WinInet MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)