---
title: "A nuvem e Web programação no Visual C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-azure
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: b63611f1-9723-44d0-ba7f-c3ebef341313
caps.latest.revision: "13"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3aaf02f645ae61c75fb4ede3f5bc8e820039d1cc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cloud-and-web-programming-in-visual-c"></a>Nuvem e programação da Web no Visual C++
No C++ há várias opções para conectar-se com a Web e com a nuvem.  
  
 [Windows Azure serviços móveis](http://www.windowsazure.com/develop/mobile/)  
 Fornece as APIs nativas que você pode usar em aplicativos da Windows Store ou em aplicativos de área de trabalho do Windows para se conectar a serviços móveis do Windows Azure. Embora a maioria dos exemplos no site está em c#, você também pode usar C++. Para obter mais informações, consulte [início rápido: adicionando um serviço móvel usando C++](http://msdn.microsoft.com/library/windows/apps/dn263181.aspx).  

 [Biblioteca de cliente de armazenamento do Microsoft Azure para C++](https://blogs.msdn.microsoft.com/windowsazurestorage/2015/04/29/microsoft-azure-storage-client-library-for-c-v1-0-0-general-availability/)  
 A biblioteca de cliente de armazenamento do Azure para C++ fornece uma API abrangente para trabalhar com o armazenamento do Azure, incluindo, mas não limitado para os seguintes recursos:

- Criar, ler, excluir e listar contêineres de blob, tabelas e filas.
- Criar, ler, excluir, adição de blobs de lista e cópia de leitura e gravação intervalos de blob.
- INSERT, delete, replace, mesclagem e consultar entidades em uma tabela do Azure.
- Enqueue e dequeue mensagens em uma fila do Azure.
- Lista lentamente contêineres, blobs, tabelas e filas e lentamente consultar entidades

[OneDrive API](https://dev.onedrive.com/README.htm)  
 A API do OneDrive fornece um conjunto de serviços HTTP para conectar seu aplicativo a arquivos e pastas no Office 365 e o SharePoint Server 2016.

[C++ REST SDK (codinome "Casablanca")](https://github.com/Microsoft/cpprestsdk)  
Fornece uma API moderna, multiplataforma e assíncrona para interagir com serviços REST.

-   Realizar chamadas REST em relação a qualquer servidor HTTP, com o suporte interno para análise de documentos JSON e serialização
-   Oferece suporte ao OAuth 1 e 2, incluindo um ouvinte de local de redirecionamento
-   Fazer conexões WebSocket em relação aos serviços remotos
-   Uma tarefa assíncrona totalmente API com base no PPL, incluindo um threadpool interno

Dá suporte a área de trabalho do Windows (7 +), Windows Server (2012 +), a plataforma Universal do Windows, Linux, OSX, Android e iOS. 
  
[Windows::Web::http::HttpClient](https://msdn.microsoft.com/en-us/library/windows/apps/windows.web.http.httpclient.aspx)  
 Uma classe de cliente HTTP de tempo de execução do Windows são modeladas na classe do .NET Framework, o mesmo nome no namespace System. Web. `HttpClient`totalmente assíncrona dá suporte ao carregar e baixar via HTTP e filtros de pipeline que permitem a inserção de manipuladores HTTP personalizados no pipeline. O SDK do Windows inclui filtros de exemplo para redes limitados, a autenticação OAuth e muito mais. Para aplicativos que se destinam apenas plataforma Universal do Windows, é recomendável que você use o `Windows::Web:HttpClient` classe. 
  
[Interface IXMLHTTPRequest2](http://msdn.microsoft.com/library/windows/apps/hh831151.aspx)  
 Fornece uma interface COM nativo que você pode usar em aplicativos da Windows Store ou em aplicativos de área de trabalho do Windows para se conectar à Internet via HTTP e o problema GET, PUT e outros comandos HTTP. Para obter mais informações, consulte [passo a passo: conectando usando tarefas e solicitações HTTP XML](../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md).  
  
[Windows Internet (WinInet)](http://msdn.microsoft.com/library/windows/desktop/aa385331\(v=vs.85\).aspx)  
 API do Windows que você pode usar em aplicativos de área de trabalho do Windows para se conectar à Internet.  
  
## <a name="see-also"></a>Consulte também  
 [Visual C++](../visual-cpp-in-visual-studio.md)   
 [Conexões de rede e serviços da web (aplicativos da Windows Store usando c# /VB/c + + e XAML)](http://msdn.microsoft.com/library/windows/apps/br229573.aspx)