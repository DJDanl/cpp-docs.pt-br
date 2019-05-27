---
title: Nuvem e programação da Web no Visual C++
ms.date: 05/14/2019
ms.assetid: b63611f1-9723-44d0-ba7f-c3ebef341313
ms.openlocfilehash: 677e9da18e8d171f523994d21bfbd0411270e3c8
ms.sourcegitcommit: bc1b14f29a02685f97c7ef5c098d16db6eaf369f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/16/2019
ms.locfileid: "65790356"
---
# <a name="cloud-and-web-programming-in-visual-c"></a>Nuvem e programação da Web no Visual C++

No C++ há várias opções para conectar-se com a Web e com a nuvem.

## <a name="microsoft-azure-sdks-and-rest-services"></a>Serviços REST e SDKs do Microsoft Azure

- [Biblioteca de Clientes do Armazenamento do Microsoft Azure para C++](https://azure.github.io/azure-storage-cpp/)

  A Biblioteca de Clientes do Armazenamento do Azure para C++ oferece uma API abrangente para trabalhar com o armazenamento do Azure, incluindo, entre outras, as seguintes capacidades:

  - Criar, ler, excluir e listar contêineres de blobs, tabelas e filas.
  - Criar, ler, excluir, listar e copiar blobs, além de ler e escrever intervalos de blobs.
  - Inserir, excluir, substituir, mesclar e consultar entidades em uma tabela do Azure.
  - Enfileirar e desenfileirar mensagens em uma fila do Azure.
  - Listar lentamente contêineres, blobs, tabelas e filas e consultar lentamente entidades

- O ANSI C99 [SDKs do Hub IoT do Azure](/azure/iot-hub/iot-hub-devguide-sdks) para a Internet das Coisas permite que os aplicativos de IoT sejam executados no dispositivo ou no back-end.

- [OneDrive e SharePoint no Microsoft Graph](https://dev.onedrive.com/README.htm)

  A API do OneDrive fornece um conjunto de serviços HTTP para conectar seu aplicativo a arquivos e pastas no Office 365 e no SharePoint Server 2016.

## <a name="windows-and-cross-platform-networking-apis"></a>APIs de rede do Windows e de multiplataforma

- [C++ REST SDK (codinome "Casablanca")](https://github.com/Microsoft/cpprestsdk)

  Fornece uma API moderna, multiplataforma e assíncrona para interagir com serviços REST.

  - Realize chamadas REST com relação a qualquer servidor HTTP, com suporte interno para análise e serialização de documento JSON
  - É compatível com OAuth 1 e 2, incluindo um ouvinte de redirecionamento local
  - Realize conexões WebSockets com relação a serviços remotos
  - Uma API de tarefa totalmente assíncrona baseada em PPL, incluindo um pool de thread interno

  É compatível com Área de Trabalho do Windows (7+), Windows Server (2012+), Plataforma Universal do Windows, Linux, OSX, Android e iOS.

- [Windows::Web::Http::HttpClient](/uwp/api/windows.web.http.httpclient)

  Uma classe de cliente HTTP do Windows Runtime modelada na classe .NET Framework do mesmo nome no namespace System.Web. `HttpClient` é completamente compatível com upload e download assíncronos por HTTP e com os filtros de pipeline que permitem a inserção de manipuladores HTTP personalizados no pipeline. O SDK do Windows inclui os filtros de exemplo para redes limitadas, autenticação OAuth e mais. Para aplicativos que direcionam apenas a Plataforma Universal do Windows, é recomendável que você use a classe `Windows::Web:HttpClient`.

- [Interface IXMLHTTPRequest2](/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2)

  Oferece uma internet COM nativa que pode ser usada em aplicativos do Windows Runtime ou de área de trabalho do Windows para se conectar à Internet por HTTP e emitir comandos GET, PUT e outros comandos HTTP. Para obter mais informações, confira [Passo a passo: como conectar usando tarefas e solicitações HTTP XML](../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md).

- [WinInet (Windows Internet)](/windows/desktop/WinInet/portal)

  A API do Windows que pode ser usada em aplicativos de área de trabalho do Windows para se conectar à Internet.

## <a name="see-also"></a>Consulte também

[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md) <br/>
[Central de Desenvolvedores do Microsoft Azure C e C++](https://azure.microsoft.com/develop/cpp/) <br/>
[Redes e serviços Web (UWP)](/windows/uwp/networking/)
