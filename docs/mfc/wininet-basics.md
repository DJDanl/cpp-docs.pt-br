---
title: Noções básicas de WinInet
ms.date: 11/04/2016
helpviewer_keywords:
- OnStatusCallback method [MFC]
- WinInet classes [MFC], displaying progress
- WinInet classes [MFC], about WinInet classes
ms.assetid: 665de5ac-e80d-427d-8d91-2ae466885940
ms.openlocfilehash: b989e5c3df63ee7b5129d01468a0f869772ed286
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367331"
---
# <a name="wininet-basics"></a>Noções básicas de WinInet

Você pode usar o WinInet para adicionar suporte ftp para baixar e carregar arquivos de dentro do seu aplicativo. Você pode substituir [o OnStatusCallback](../mfc/reference/cinternetsession-class.md#onstatuscallback) e usar o parâmetro *dwContext* para fornecer informações de progresso aos usuários à medida que você pesquisa e baixa arquivos.

Este artigo contém os seguintes tópicos:

- [Crie um navegador muito simples](#_core_create_a_very_simple_browser)

- [Baixe uma página da Web](#_core_download_a_web_page)

- [FTP a Arquivo](#_core_ftp_a_file)

- [Recupere um Diretório Gopher](#_core_retrieve_a_gopher_directory)

- [Exibir informações de progresso durante a transferência de arquivos](#_core_display_progress_information_while_transferring_files)

Os trechos de código abaixo demonstram como criar um navegador simples, baixar uma página da Web, FTP um arquivo e procurar um arquivo gopher. Eles não são feitos como exemplos completos e nem todos contêm tratamento de exceção.

Para obter informações adicionais sobre o WinInet, consulte [Win32 Internet Extensions (WinInet)](../mfc/win32-internet-extensions-wininet.md).

## <a name="create-a-very-simple-browser"></a><a name="_core_create_a_very_simple_browser"></a>Crie um navegador muito simples

[!code-cpp[NVC_MFCWinInet#1](../mfc/codesnippet/cpp/wininet-basics_1.cpp)]

## <a name="download-a-web-page"></a><a name="_core_download_a_web_page"></a>Baixe uma página da Web

[!code-cpp[NVC_MFCWinInet#2](../mfc/codesnippet/cpp/wininet-basics_2.cpp)]

## <a name="ftp-a-file"></a><a name="_core_ftp_a_file"></a>FTP a Arquivo

[!code-cpp[NVC_MFCWinInet#3](../mfc/codesnippet/cpp/wininet-basics_3.cpp)]

## <a name="retrieve-a-gopher-directory"></a><a name="_core_retrieve_a_gopher_directory"></a>Recupere um Diretório Gopher

[!code-cpp[NVC_MFCWinInet#4](../mfc/codesnippet/cpp/wininet-basics_4.cpp)]

## <a name="use-onstatuscallback"></a>Use OnStatusCallback

Ao usar as classes WinInet, você pode usar o membro [OnStatusCallback](../mfc/reference/cinternetsession-class.md#onstatuscallback) do objeto [CInternetSession](../mfc/reference/cinternetsession-class.md) do seu aplicativo para recuperar informações de status. Se você derivar seu `CInternetSession` `OnStatusCallback`próprio objeto, substituir e ativar retornos `OnStatusCallback` de status, o MFC chamará sua função com informações de progresso sobre todas as atividades nessa sessão da Internet.

Como uma única sessão pode suportar várias conexões (que, ao `OnStatusCallback` longo de sua vida útil, podem realizar muitas operações distintas), precisa de um mecanismo para identificar cada alteração de status com uma determinada conexão ou transação. Esse mecanismo é fornecido pelo parâmetro de iD de contexto dado a muitas das funções de membro nas classes de suporte do WinInet. Este parâmetro é sempre do tipo **DWORD** e é sempre chamado *dwContext*.

O contexto atribuído a um determinado objeto da Internet é usado `OnStatusCallback` apenas `CInternetSession` para identificar a atividade que o objeto causa no membro do objeto. A chamada `OnStatusCallback` para receber vários parâmetros; esses parâmetros trabalham juntos para dizer ao seu aplicativo que progresso foi feito para qual transação e conexão.

Quando você `CInternetSession` cria um objeto, você pode especificar um parâmetro *dwContext* para o construtor. `CInternetSession`em si não usa o ID de contexto; em vez disso, ele passa o ID de contexto para qualquer objeto derivado da **InternetConnection**que não obtenha explicitamente um ID de contexto próprio. Por sua `CInternetConnection` vez, esses objetos passarão o ID de contexto junto aos `CInternetFile` objetos que eles criam se você não especificar explicitamente um ID de contexto diferente. Se, por outro lado, você especificar um ID de contexto específico próprio, o objeto e qualquer trabalho que ele fizer serão associados a esse ID de contexto. Você pode usar os IDs de contexto para identificar `OnStatusCallback` quais informações de status estão sendo dadas a você em sua função.

## <a name="display-progress-information-while-transferring-files"></a><a name="_core_display_progress_information_while_transferring_files"></a>Exibir informações de progresso durante a transferência de arquivos

Por exemplo, se você escrever um aplicativo que cria uma conexão com um servidor FTP para ler um arquivo `CInternetSession` e `CInternetConnection` também se conectar `CFtpSession` a um servidor `CHttpSession`HTTP para obter uma página da Web, você terá um objeto, dois objetos (um seria um e o outro seria um), e dois `CInternetFile` objetos (um para cada conexão). Se você usou valores padrão para os parâmetros *dwContext,* você não seria capaz de distinguir entre as `OnStatusCallback` invocações que indicam progresso para a conexão FTP e as invocações que indicam progresso para a conexão HTTP. Se você especificar um *dwContext* ID, `OnStatusCallback`que você pode testar posteriormente, você saberá qual operação gerou o retorno de chamada.

## <a name="see-also"></a>Confira também

[Noções básicas de programação da Internet Do MFC](../mfc/mfc-internet-programming-basics.md)<br/>
[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)
