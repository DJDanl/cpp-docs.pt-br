---
title: Nuvem e programação da Web no Visual C++
ms.date: 11/04/2016
ms.assetid: b63611f1-9723-44d0-ba7f-c3ebef341313
ms.openlocfilehash: ec5999a90701c427a3b7166803ee79a4a5cd19b2
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57414480"
---
# <a name="cloud-and-web-programming-in-visual-c"></a>Nuvem e programação da Web no Visual C++

No C++ há várias opções para conectar-se com a Web e com a nuvem.

## <a name="cloud-programming-options"></a>Opções de programação em nuvem

- [Windows Azure serviços móveis](http://www.windowsazure.com/develop/mobile/)

  Fornece APIs nativas que você pode usar em aplicativos de plataforma Universal do Windows (UWP) ou em aplicativos da área de trabalho do Windows para se conectar aos serviços móveis do Windows Azure. Embora a maioria dos exemplos no site está em c#, você também pode usar C++. Para obter mais informações, confira [Início Rápido: Adicionando um serviço móvel usando C++](https://msdn.microsoft.com/library/windows/apps/dn263181.aspx).

- [Biblioteca de cliente de armazenamento do Microsoft Azure para C++](https://blogs.msdn.microsoft.com/windowsazurestorage/2015/04/29/microsoft-azure-storage-client-library-for-c-v1-0-0-general-availability/)

  A biblioteca de cliente de armazenamento do Azure para C++ fornece uma API abrangente para trabalhar com o armazenamento do Azure, incluindo, dentre as seguintes capacidades:

  - Criar, ler, excluir e listar os contêineres de blob, tabelas e filas.
  - Criar, ler, excluir, lista e copie blobs de adição de leitura e gravação de intervalos de blob.
  - INSERT, delete, replace, mesclagem e consultar entidades em uma tabela do Azure.
  - Enfileirar e retirar da fila de mensagens em uma fila do Azure.
  - Listar lentamente contêineres, blobs, tabelas e filas e lentamente consultar entidades

- [API do OneDrive](https://dev.onedrive.com/README.htm)

  A API do OneDrive fornece um conjunto de serviços HTTP para conectar seu aplicativo a arquivos e pastas no Office 365 e SharePoint Server 2016.

- [C++ REST SDK (codinome "Casablanca")](https://github.com/Microsoft/cpprestsdk)

  Fornece uma API moderna, assíncrona, de plataforma cruzada para interagir com os serviços REST.

  - Realizar chamadas REST em relação a qualquer servidor HTTP, com suporte interno para o documento JSON de análise e serialização
  - Dá suporte a OAuth 1 e 2, incluindo um ouvinte de local de redirecionamento
  - Fazer conexões de WebSocket em relação aos serviços remotos
  - Uma tarefa totalmente assíncrona com base no PPL, incluindo um threadpool internos de API

  Dá suporte à área de trabalho do Windows (7 +), Windows Server (2012 +), plataforma Universal do Windows, Linux, OSX, Android e iOS.

- [Windows::Web::Http::HttpClient](/uwp/api/windows.web.http.httpclient)

  Uma classe de cliente HTTP de tempo de execução do Windows modelada na classe do .NET Framework, o mesmo nome no namespace System. Web. `HttpClient` completamente assíncrona dá suporte a carregar e baixar via HTTP e filtros de pipeline que permitem a inserção de manipuladores HTTP personalizados no pipeline. O SDK do Windows inclui filtros de exemplo para redes limitadas, a autenticação OAuth e muito mais. Para aplicativos que se destinam apenas plataforma Universal do Windows, é recomendável que você use o `Windows::Web:HttpClient` classe.

- [Interface IXMLHTTPRequest2](/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2)

  Fornece uma interface COM nativa que você pode usar em aplicativos de tempo de execução do Windows ou aplicativos da área de trabalho do Windows para se conectar à Internet via HTTP e emitir um GET, PUT e outro comandos HTTP. Para obter mais informações, confira [Passo a passo: Conexão usando tarefas e solicitações HTTP XML](../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md).

- [Windows Internet (WinInet)](/windows/desktop/WinInet/portal)

  API do Windows que você pode usar em aplicativos da área de trabalho do Windows para se conectar à Internet.

## <a name="see-also"></a>Consulte também

[Visual C++](../visual-cpp-in-visual-studio.md) <br/>
[Redes e serviços da web](/windows/uwp/networking/)
