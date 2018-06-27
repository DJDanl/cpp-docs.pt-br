---
title: Noções básicas de WinInet | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- OnStatusCallback method [MFC]
- WinInet classes [MFC], displaying progress
- WinInet classes [MFC], about WinInet classes
ms.assetid: 665de5ac-e80d-427d-8d91-2ae466885940
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7061c3203436197eb1bd03ae56058e0bd0f26f9d
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36955577"
---
# <a name="wininet-basics"></a>Noções básicas de WinInet
Você pode usar WinInet para adicionar suporte FTP para baixar e carregar arquivos a partir do seu aplicativo. Você pode substituir [OnStatusCallback](../mfc/reference/cinternetsession-class.md#onstatuscallback) e usar o *dwContext* parâmetro para fornecer informações de andamento para os usuários como procurar e baixar arquivos.  
  
 Este artigo contém os seguintes tópicos:  
  
-   [Criar um navegador muito Simple](#_core_create_a_very_simple_browser)  
  
-   [Baixar uma página da Web](#_core_download_a_web_page)  
  
-   [Um arquivo FTP](#_core_ftp_a_file)  
  
-   [Recuperar uma pasta Gopher](#_core_retrieve_a_gopher_directory)  
  
-   [Exibir informações sobre o progresso durante a transferência de arquivos](#_core_display_progress_information_while_transferring_files)  
  
 Os trechos de código abaixo demonstram como criar um simple navegador, faça o download de uma página da Web, FTP, um arquivo e procurar um arquivo de gopher. Eles não são indicados como exemplos completos e não contêm tratamento de exceção.  
  
 Para obter informações adicionais sobre WinInet, consulte [extensões de Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md).  
  
##  <a name="_core_create_a_very_simple_browser"></a> Criar um navegador muito Simple  
 [!code-cpp[NVC_MFCWinInet#1](../mfc/codesnippet/cpp/wininet-basics_1.cpp)]  
  
##  <a name="_core_download_a_web_page"></a> Baixar uma página da Web  
 [!code-cpp[NVC_MFCWinInet#2](../mfc/codesnippet/cpp/wininet-basics_2.cpp)]  
  
##  <a name="_core_ftp_a_file"></a> Um arquivo FTP  
 [!code-cpp[NVC_MFCWinInet#3](../mfc/codesnippet/cpp/wininet-basics_3.cpp)]  
  
##  <a name="_core_retrieve_a_gopher_directory"></a> Recuperar uma pasta Gopher  
 [!code-cpp[NVC_MFCWinInet#4](../mfc/codesnippet/cpp/wininet-basics_4.cpp)]  
  
## <a name="use-onstatuscallback"></a>Use OnStatusCallback  
 Ao usar as classes WinInet, você pode usar o [OnStatusCallback](../mfc/reference/cinternetsession-class.md#onstatuscallback) membro do seu aplicativo [CInternetSession](../mfc/reference/cinternetsession-class.md) objeto para recuperar informações de status. Se você derivar seu próprio `CInternetSession` de objeto, substituir `OnStatusCallback`e habilitar os retornos de chamada de status, MFC chamará o `OnStatusCallback` função com informações de progresso sobre todas as atividades na sessão da Internet.  
  
 Como uma única sessão pode oferecer suporte a várias conexões (o que, durante o tempo de vida, podem executar várias operações distinct diferentes), `OnStatusCallback` precisa de um mecanismo para identificar cada alteração de status com uma determinada conexão ou transação. Esse mecanismo é fornecido pelo parâmetro de ID de contexto fornecido a muitas das funções de membro nas classes de suporte de WinInet. Esse parâmetro é sempre do tipo **DWORD** e é sempre nomeado *dwContext*.  
  
 O contexto atribuído a um determinado objeto de Internet é usado apenas para identificar a atividade faz com que o objeto no `OnStatusCallback` membro o `CInternetSession` objeto. A chamada para `OnStatusCallback` recebe vários parâmetros, esses parâmetros funcionam em conjunto para informar o seu aplicativo que progresso foi feito para a qual transação e a conexão.  
  
 Quando você cria um `CInternetSession` objeto, você pode especificar um *dwContext* parâmetro para o construtor. `CInternetSession` em si não usa a ID do contexto; em vez disso, ele passa a ID do contexto de logon em qualquer **InternetConnection**-que explicitamente não obtém uma ID do contexto de seus próprios objetos derivados. Por sua vez, os `CInternetConnection` objetos passará a ID do contexto ao longo de `CInternetFile` objetos criarem se você não especificar explicitamente um ID de contexto diferentes. Se, por outro lado, você especificar uma ID de contexto específico de sua preferência, o objeto e qualquer trabalho será associado esse ID de contexto. Você pode usar o contexto de IDs para identificar quais informações de status estão sendo fornecidas em seu `OnStatusCallback` função.  
  
##  <a name="_core_display_progress_information_while_transferring_files"></a> Exibir informações sobre o progresso durante a transferência de arquivos  
 Por exemplo, se você gravar um aplicativo que cria uma conexão com um servidor FTP para ler um arquivo e também se conecta a um servidor HTTP para uma página da Web, você terá uma `CInternetSession` objeto, duas `CInternetConnection` objetos (uma delas seria uma `CFtpSession` e o outro será um `CHttpSession`) e dois `CInternetFile` objetos (um para cada conexão). Se você usou valores padrão para o *dwContext* parâmetros, você não seria capaz de distinguir entre o `OnStatusCallback` invocações que indicam o progresso para a conexão de FTP e as chamadas que indicam o progresso para o Conexão HTTP. Se você especificar um *dwContext* ID, que mais tarde você pode testar no `OnStatusCallback`, você saberá qual operação gerou o retorno de chamada.  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas de programação de Internet MFC](../mfc/mfc-internet-programming-basics.md)   
 [Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)

