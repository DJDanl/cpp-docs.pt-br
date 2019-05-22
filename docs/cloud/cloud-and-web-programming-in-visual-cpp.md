---
title: Nuvem e programação da Web no Visual C++
ms.date: 11/04/2016
ms.assetid: b63611f1-9723-44d0-ba7f-c3ebef341313
ms.openlocfilehash: 3d71e36b6209c693940f2ebe6b5e9c73bc0c9d9d
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65708037"
---
# <a name="cloud-and-web-programming-in-visual-c"></a>Nuvem e programação da Web no Visual C++

No C++ há várias opções para conectar-se com a Web e com a nuvem.

## <a name="cloud-programming-options"></a>Opções de programação em nuvem

- [Serviços Móveis do Microsoft Azure](http://www.windowsazure.com/develop/mobile/)

  Fornece APIs nativas que podem ser usadas em aplicativos UWP (Plataforma Universal do Windows) ou aplicativos de área de trabalho do Windows para se conectar aos Serviços Móveis do Microsoft Azure. Embora a maioria dos exemplos no site sejam em C#, também é possível usar C++. Para obter mais informações, confira [Início Rápido: Como adicionar um serviço móvel usando C++](https://msdn.microsoft.com/library/windows/apps/dn263181.aspx).

- [Biblioteca de Clientes do Armazenamento do Microsoft Azure para C++](https://blogs.msdn.microsoft.com/windowsazurestorage/2015/04/29/microsoft-azure-storage-client-library-for-c-v1-0-0-general-availability/)

  A Biblioteca de Clientes do Armazenamento do Azure para C++ oferece uma API abrangente para trabalhar com o armazenamento do Azure, incluindo, entre outras, as seguintes capacidades:

  - Criar, ler, excluir e listar contêineres de blobs, tabelas e filas.
  - Criar, ler, excluir, listar e copiar blobs, além de ler e escrever intervalos de blobs.
  - Inserir, excluir, substituir, mesclar e consultar entidades em uma tabela do Azure.
  - Enfileirar e desenfileirar mensagens em uma fila do Azure.
  - Listar lentamente contêineres, blobs, tabelas e filas e consultar lentamente entidades

- [API do OneDrive](https://dev.onedrive.com/README.htm)

  A API do OneDrive fornece um conjunto de serviços HTTP para conectar seu aplicativo a arquivos e pastas no Office 365 e no SharePoint Server 2016.

- [C++ REST SDK (codinome "Casablanca")](https://github.com/Microsoft/cpprestsdk)

  Fornece uma API moderna, multiplataforma e assíncrona para interagir com serviços REST.

  - Realize chamadas REST com relação a qualquer servidor HTTP, com suporte interno para análise e serialização de documento JSON
  - É compatível com OAuth 1 e 2, incluindo um ouvinte de redirecionamento local
  - Realize conexões WebSockets com relação a serviços remotos
  - Uma API de tarefa totalmente assíncrona baseada em PPL, incluindo um threadpool interno

  É compatível com Área de Trabalho do Windows (7+), Windows Server (2012+), Plataforma Universal do Windows, Linux, OSX, Android e iOS.

- [Windows::Web::Http::HttpClient](/uwp/api/windows.web.http.httpclient)

  Uma classe de cliente HTTP do Windows Runtime modelada na classe .NET Framework do mesmo nome no namespace System.Web. `HttpClient` é completamente compatível com upload e download assíncronos por HTTP e com os filtros de pipeline que permitem a inserção de manipuladores HTTP personalizados no pipeline. O SDK do Windows inclui os filtros de exemplo para redes limitadas, autenticação OAuth e mais. Para aplicativos que direcionam apenas a Plataforma Universal do Windows, é recomendável que você use a classe `Windows::Web:HttpClient`.

- [Interface IXMLHTTPRequest2](/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2)

  Oferece uma internet COM nativa que pode ser usada em aplicativos do Windows Runtime ou de área de trabalho do Windows para se conectar à Internet por HTTP e emitir comandos GET, PUT e outros comandos HTTP. Para obter mais informações, confira [Passo a passo: como conectar usando tarefas e solicitações HTTP XML](../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md).

- [WinInet (Windows Internet)](/windows/desktop/WinInet/portal)

  A API do Windows que pode ser usada em aplicativos de área de trabalho do Windows para se conectar à Internet.

## <a name="see-also"></a>Consulte também

[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md) <br/>
[Redes e serviços Web](/windows/uwp/networking/)
