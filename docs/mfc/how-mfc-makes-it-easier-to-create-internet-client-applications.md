---
title: Como o MFC facilita a criação de aplicativos clientes da Internet
ms.date: 11/04/2016
helpviewer_keywords:
- Internet client applications [MFC], MFC
- Internet applications [MFC], MFC
- MFC, Internet applications
ms.assetid: 94437b3f-f15c-437d-b5fd-264a2efec9ab
ms.openlocfilehash: 71b72a3079cd0d0c87289c1813c09a24d9f75c89
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618553"
---
# <a name="how-mfc-makes-it-easier-to-create-internet-client-applications"></a>Como o MFC facilita a criação de aplicativos clientes da Internet

O MFC encapsulam as funções do protocolo WinInet (Internet Extension) do Win32 de uma maneira que fornece um contexto familiar para os programadores do MFC. O MFC fornece três classes de arquivos de Internet ([CInternetFile](reference/cinternetfile-class.md), [CHttpFile](reference/chttpfile-class.md)e [CGopherFile](reference/cgopherfile-class.md)) derivadas da classe [CStdioFile](reference/cstdiofile-class.md) . Não apenas essas classes tornam a recuperação e a manipulação de dados da Internet familiares aos programadores que usaram `CStdioFile` arquivos locais, mas com essas classes você pode manipular arquivos locais e arquivos da Internet de maneira consistente e transparente.

As classes do MFC WinInet fornecem a mesma funcionalidade que os `CStdioFile` dados transferidos pela Internet. Essas classes abstraem os protocolos de Internet para HTTP, FTP e Gopher em uma interface de programação de aplicativo de alto nível, fornecendo um caminho rápido e direto para tornar os aplicativos cientes da Internet. Por exemplo, conectar-se a um servidor FTP ainda requer várias etapas em um nível baixo, mas como um desenvolvedor MFC, você só precisa fazer uma chamada para `CInternetSession::GetFTPConnection` para criar essa conexão.

Além disso, as classes do MFC WinInet oferecem as seguintes vantagens:

- E/s em buffer

- Identificadores de tipo seguro para seus dados

- Parâmetros padrão para muitas funções

- Tratamento de exceção para erros comuns da Internet

- Limpeza automática de identificadores e conexões abertas

## <a name="see-also"></a>Consulte também

[Extensões da Internet Win32 (WinInet)](win32-internet-extensions-wininet.md)<br/>
[Como o WinInet facilita a criação de aplicativos cliente da Internet](how-wininet-makes-it-easier-to-create-internet-client-applications.md)
