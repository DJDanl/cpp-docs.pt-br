---
title: "No&#231;&#245;es b&#225;sicas de WinInet | Microsoft Docs"
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
  - "Método OnStatusCallback"
  - "Classes WinInet, sobre classes WinInet"
  - "Classes WinInet, exibindo andamento"
ms.assetid: 665de5ac-e80d-427d-8d91-2ae466885940
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# No&#231;&#245;es b&#225;sicas de WinInet
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar WinInet para adicionar suporte de FTP para baixar e carregar arquivos de dentro de seu aplicativo.  Você pode substituir [OnStatusCallback](../Topic/CInternetSession::OnStatusCallback.md) e usar o parâmetro de `dwContext` para fornecer informações de progresso para os usuários como você procura por e baixa arquivos.  
  
 Este artigo contém os seguintes tópicos:  
  
-   [Crie um navegador muito simples](#_core_create_a_very_simple_browser)  
  
-   [Baixar uma página da Web](#_core_download_a_web_page)  
  
-   [Arquivo FTP](#_core_ftp_a_file)  
  
-   [Recuperar um diretório de Gopher](#_core_retrieve_a_gopher_directory)  
  
-   [Exibir informações de progresso quando transferir o arquivo](#_core_display_progress_information_while_transferring_files)  
  
 Os trechos de código a seguir demonstram como criar um navegador simples, para baixar uma página da Web, FTP um arquivo, e pesquisa de um arquivo de Gopher.  Não têm significados como os exemplos completos e nem todos contêm a manipulação de exceção.  
  
 Para obter informações adicionais sobre como WinInet, consulte [Extensões do Win32 a Internet \(WinInet\)](../mfc/win32-internet-extensions-wininet.md).  
  
##  <a name="_core_create_a_very_simple_browser"></a> Crie um navegador muito simples  
 [!CODE [NVC_MFCWinInet#1](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCWinInet#1)]  
  
##  <a name="_core_download_a_web_page"></a> Baixar uma página da Web  
 [!CODE [NVC_MFCWinInet#2](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCWinInet#2)]  
  
##  <a name="_core_ftp_a_file"></a> Arquivo FTP  
 [!CODE [NVC_MFCWinInet#3](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCWinInet#3)]  
  
##  <a name="_core_retrieve_a_gopher_directory"></a> Recuperar um diretório de Gopher  
 [!CODE [NVC_MFCWinInet#4](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCWinInet#4)]  
  
## Use OnStatusCallback  
 Quando usar o WinInet classificará, você pode usar o membro de [OnStatusCallback](../Topic/CInternetSession::OnStatusCallback.md) do objeto de [CInternetSession](../Topic/CInternetSession%20Class.md) do seu aplicativo para recuperar informações de status.  Se você deriva seu próprio objeto de `CInternetSession` , substitui `OnStatusCallback`, e habilita retornos de chamada de status, o MFC chamará a função de `OnStatusCallback` com informações de progresso sobre qualquer atividade nessa sessão da Internet.  
  
 Como uma única sessão pode dar suporte a várias conexões \(que, em seu tempo de vida, podem executar muitas operações distintas diferentes\), `OnStatusCallback` precisa de um mecanismo de identificar cada alteração de status com uma conexão ou uma transação específica.  O mecanismo é fornecido pelo parâmetro de ID do contexto determinado a muitas das funções de membro o suporte de WinInet classifica.  Esse parâmetro é do tipo sempre `DWORD` e é chamado sempre `dwContext`.  
  
 O contexto atribuído a um objeto da Internet de detalhes é usado para identificar apenas a atividade as causas do objeto no membro de `OnStatusCallback` do objeto de `CInternetSession` .  A chamada para `OnStatusCallback` receber vários parâmetros; esses parâmetros funcionam em conjunto para informar ao seu aplicativo que progresso foi feito para que a transação e conexão.  
  
 Quando você cria um objeto de `CInternetSession` , você pode especificar um parâmetro de `dwContext` para o construtor.  `CInternetSession` próprio não usa o ID do contexto; em vez disso, passa a ID de contexto sobre a qualquer **InternetConnection**\- os objetos derivados que não obtêm explicitamente um ID do contexto de seus próprios.  Por sua vez, esses objetos de `CInternetConnection` transmitirão a ID do contexto desde a objetos de `CInternetFile` criam se você não especificar explicitamente outra ID de contexto  Se, por outro lado, especifique uma ID específico de sua escolha, o objeto de contexto e qualquer trabalho que faz será associado à ID do contexto  Você pode usar as IDs de contexto para identificar quais informações de status que está sendo determinada na função de `OnStatusCallback` .  
  
##  <a name="_core_display_progress_information_while_transferring_files"></a> Exibir informações de progresso quando transferir o arquivo  
 Por exemplo, se você escrever um aplicativo que cria uma conexão com um servidor FTP para ler um arquivo e também para se conectar a um servidor HTTP para obter uma página da Web, você terá um objeto de `CInternetSession` , dois objetos de `CInternetConnection` \(seria um **CFtpSession** e o outro será **CHttpSession**\), e dois objetos de `CInternetFile` \(um para cada conexão\).  Se você usou valores padrão para os parâmetros de `dwContext` , você não pode distinguir entre invocações de `OnStatusCallback` que indica o progresso para a conexão de FTP e as invocações que indica o progresso para a conexão HTTP.  Se você especificar uma ID de `dwContext` , que você pode testar posteriormente em `OnStatusCallback`, você aprenderá operação que gerou o retorno de chamada.  
  
## Consulte também  
 [Noções básicas de programação da Internet MFC](../mfc/mfc-internet-programming-basics.md)   
 [Extensões da Internet Win32 \(WinInet\)](../mfc/win32-internet-extensions-wininet.md)