---
title: Noções básicas de WinInet
ms.date: 11/04/2016
helpviewer_keywords:
- OnStatusCallback method [MFC]
- WinInet classes [MFC], displaying progress
- WinInet classes [MFC], about WinInet classes
ms.assetid: 665de5ac-e80d-427d-8d91-2ae466885940
ms.openlocfilehash: f56d2bb6e6a0b49b3d69dbcc0bf6346b72e9f7b0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50519178"
---
# <a name="wininet-basics"></a>Noções básicas de WinInet

Você pode usar o WinInet para adicionar suporte a FTP para baixar e carregar arquivos de dentro de seu aplicativo. Você pode substituir [OnStatusCallback](../mfc/reference/cinternetsession-class.md#onstatuscallback) e usar o *dwContext* parâmetro para fornecer informações de progresso para os usuários como pesquisar e baixar arquivos.

Este artigo contém os tópicos a seguir:

- [Criar um navegador muito Simple](#_core_create_a_very_simple_browser)

- [Baixar uma página da Web](#_core_download_a_web_page)

- [Um arquivo de FTP](#_core_ftp_a_file)

- [Recuperar um diretório de Gopher](#_core_retrieve_a_gopher_directory)

- [Exibir informações de progresso durante a transferência de arquivos](#_core_display_progress_information_while_transferring_files)

Os trechos de código abaixo demonstram como criar um navegador simple, baixe uma página da Web, FTP, um arquivo e procurar um arquivo de gopher. Eles não são apenas exemplos completos e não contêm tratamento de exceção.

Para obter informações adicionais sobre o WinInet, consulte [extensões de Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md).

##  <a name="_core_create_a_very_simple_browser"></a> Criar um navegador muito Simple

[!code-cpp[NVC_MFCWinInet#1](../mfc/codesnippet/cpp/wininet-basics_1.cpp)]

##  <a name="_core_download_a_web_page"></a> Baixar uma página da Web

[!code-cpp[NVC_MFCWinInet#2](../mfc/codesnippet/cpp/wininet-basics_2.cpp)]

##  <a name="_core_ftp_a_file"></a> Um arquivo de FTP

[!code-cpp[NVC_MFCWinInet#3](../mfc/codesnippet/cpp/wininet-basics_3.cpp)]

##  <a name="_core_retrieve_a_gopher_directory"></a> Recuperar um diretório de Gopher

[!code-cpp[NVC_MFCWinInet#4](../mfc/codesnippet/cpp/wininet-basics_4.cpp)]

## <a name="use-onstatuscallback"></a>Usar OnStatusCallback

Ao usar as classes WinInet, você pode usar o [OnStatusCallback](../mfc/reference/cinternetsession-class.md#onstatuscallback) membro do seu aplicativo [CInternetSession](../mfc/reference/cinternetsession-class.md) o objeto para recuperar informações de status. Se você derivar seus próprios `CInternetSession` do objeto, substituir `OnStatusCallback`e permitir retornos de chamada de status, MFC chamará seu `OnStatusCallback` função com informações de progresso sobre todas as atividades na sessão da Internet.

Porque uma única sessão pode dar suporte a várias conexões (o que, ao longo de seu tempo de vida, podem executar várias operações distintas diferentes), `OnStatusCallback` precisa de um mecanismo para identificar cada alteração de status com uma conexão específica ou a transação. Esse mecanismo é fornecido pelo parâmetro de ID de contexto fornecido para muitas das funções membro nas classes de suporte do WinInet. Esse parâmetro é sempre do tipo **DWORD** e é sempre denominado *dwContext*.

O contexto atribuído a um determinado objeto de Internet é usado apenas para identificar a atividade faz com que o objeto na `OnStatusCallback` membro o `CInternetSession` objeto. A chamada para `OnStatusCallback` recebe vários parâmetros; esses parâmetros funcionam juntos para informar ao seu aplicativo que progresso foi feito para qual transação e a conexão.

Quando você cria um `CInternetSession` objeto, você pode especificar um *dwContext* parâmetro para o construtor. `CInternetSession` em si não usa a ID de contexto; em vez disso, ele passa a ID de contexto para um **InternetConnection**-que explicitamente não obtém uma ID de contexto de seus próprios objetos derivados. Por sua vez, aqueles `CInternetConnection` objetos irá passar a ID de contexto junto a `CInternetFile` objetos que eles criam, se você não especificar explicitamente uma ID de contexto diferente. Se, por outro lado, você especificar uma ID de contexto específico de sua preferência, o objeto e nenhum trabalho será associado com essa ID de contexto. Você pode usar as IDs de contexto para identificar quais informações de status está sendo fornecidas para você em seu `OnStatusCallback` função.

##  <a name="_core_display_progress_information_while_transferring_files"></a> Exibir informações de progresso durante a transferência de arquivos

Por exemplo, se você escrever um aplicativo que cria uma conexão com um servidor FTP para ler um arquivo e também se conecta a um servidor HTTP para obter uma página da Web, você terá um `CInternetSession` object, dois `CInternetConnection` objetos (uma delas seria uma `CFtpSession` e outro seria uma `CHttpSession`) e dois `CInternetFile` objetos (um para cada conexão). Se você usou valores padrão para o *dwContext* parâmetros, você não seria capaz de distinguir entre o `OnStatusCallback` invocações que indicam o progresso para a conexão de FTP e as chamadas que indicam o progresso para o Conexão HTTP. Se você especificar uma *dwContext* ID, que posteriormente você pode testar no `OnStatusCallback`, você saberá qual operação gerou o retorno de chamada.

## <a name="see-also"></a>Consulte também

[Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)<br/>
[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)

