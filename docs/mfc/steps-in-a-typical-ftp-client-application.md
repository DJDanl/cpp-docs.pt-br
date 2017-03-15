---
title: "Etapas em um aplicativo cliente FTP t&#237;pico | Microsoft Docs"
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
  - "FTP (File Transfer Protocol)"
  - "FTP (File Transfer Protocol), aplicativos cliente"
  - "aplicativos da Internet, aplicativos cliente FTP"
  - "aplicativos cliente da Internet, Tabela FTP"
  - "Classes WinInet, FTP"
ms.assetid: 70bed7b5-6040-40d1-bc77-702e63a698f2
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Etapas em um aplicativo cliente FTP t&#237;pico
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um aplicativo cliente típico de FTP [CInternetSession](../Topic/CInternetSession%20Class.md) e cria um objeto de [CFtpConnection](../mfc/reference/cftpconnection-class.md) .  Observe que essas classes MFC WinInet não controla de fato as configurações do tipo de proxy; Faz o IIS.  
  
 Além disso, consulte esses artigos da Base de Dados de Conhecimento:  
  
-   HOWTO: FTP com o proxy CERN\- baseado WinInet usando a API \(ID de artigo: Q166961\)  
  
-   EXEMPLO: FTP com o proxy com senha protegida com base CERN\- \(ID de artigo: Q216214\)  
  
-   O gerenciador de serviços de Internet não mostra serviços instalados do proxy \(ID de artigo: Q216802\)  
  
 A tabela a seguir mostra as etapas que você pode executar em um aplicativo cliente típico de FTP.  
  
|Sua meta|Ações que você faça|Efeitos|  
|--------------|-------------------------|-------------|  
|Inicia uma sessão de FTP.|Crie um objeto de [CInternetSession](../Topic/CInternetSession%20Class.md) .|Inicializa WinInet e conecte\-se ao servidor.|  
|Conectar a um servidor FTP.|Use [CInternetSession::GetFtpConnection](../Topic/CInternetSession::GetFtpConnection.md).|Retorna um objeto de [CFtpConnection](../mfc/reference/cftpconnection-class.md) .|  
|Altere para um novo diretório de FTP no servidor.|Use [CFtpConnection::SetCurrentDirectory](../Topic/CFtpConnection::SetCurrentDirectory.md).|Altera o diretório que você está conectado atualmente no servidor.|  
|Localizar o primeiro arquivo no diretório de FTP.|Use [CFtpFileFind::FindFile](../Topic/CFtpFileFind::FindFile.md).|Localiza o primeiro arquivo.  Retornará FALSE se nenhum arquivo é encontrado.|  
|Localize o arquivo seguinte no diretório de FTP.|Use [CFtpFileFind::FindNextFile](../Topic/CFtpFileFind::FindNextFile.md).|Localiza o próximo arquivo.  Retornará FALSE se o arquivo não for localizado.|  
|Abra o arquivo localizado por **FindFile** ou por `FindNextFile` para ler ou gravar.|Use [CFtpConnection::OpenFile](../Topic/CFtpConnection::OpenFile.md), usando o nome de arquivo retornado por [FindFile](../Topic/CFtpFileFind::FindFile.md) ou por [FindNextFile](../Topic/CFtpFileFind::FindNextFile.md).|Abre o arquivo no servidor para ler ou gravar.  Retorna um objeto de [CInternetFile](../mfc/reference/cinternetfile-class.md) .|  
|De leitura ou gravação no arquivo.|Use [CInternetFile::Read](../Topic/CInternetFile::Read.md) ou [CInternetFile::Write](../Topic/CInternetFile::Write.md).|Leituras ou gravações o número de bytes especificado, usando um buffer você fornece.|  
|Trate exceções.|Use a classe de [CInternetException](../mfc/reference/cinternetexception-class.md) .|Controla todos os tipos de exceção comuns da Internet.|  
|Encerra a sessão de FTP.|Disponha do objeto de [CInternetSession](../Topic/CInternetSession%20Class.md) .|Limpa automaticamente os identificadores de arquivos abertos e conexões.|  
  
## Consulte também  
 [Extensões da Internet Win32 \(WinInet\)](../mfc/win32-internet-extensions-wininet.md)   
 [Pré\-requisitos para classes clientes de Internet](../Topic/Prerequisites%20for%20Internet%20Client%20Classes.md)   
 [Escrevendo um aplicativo cliente da Internet usando classes WinInet MFC](../mfc/writing-an-internet-client-application-using-mfc-wininet-classes.md)