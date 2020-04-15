---
title: 'tela de fundo OLE: implementação MFC'
ms.date: 11/04/2016
f1_keywords:
- IMarshall
- IMoniker
helpviewer_keywords:
- MFC libraries, implementing
- OLE MFC library implementation
- OLE IMarshal interface
- IMoniker interface, MFC
- IMarshall class [MFC]
- OLE, compound files
- OLE IMoniker interface
- OLE IUnknown
ms.assetid: 2b67016a-d78e-4d60-925f-c28ec8fb6180
ms.openlocfilehash: 25c98c3683a8656bb5188f22d0464d25a4901f49
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364527"
---
# <a name="ole-background-mfc-implementation"></a>tela de fundo OLE: implementação MFC

Devido ao tamanho e complexidade da API OLE bruta, chamá-la diretamente para escrever aplicativos OLE pode ser muito demorado. O objetivo da implementação da Microsoft Foundation Class Library do OLE é reduzir a quantidade de trabalho que você tem que fazer para escrever aplicativos completos e capazes de OLE.

Este artigo explica as partes da API OLE que não foram implementadas dentro do MFC. A discussão também explica como o que é implementado mapeia para a seção OLE do Windows SDK.

## <a name="portions-of-ole-not-implemented-by-the-class-library"></a><a name="_core_portions_of_ole_not_implemented_by_the_class_library"></a>Partes do OLE não implementadas pela Biblioteca de Classe

Algumas interfaces e recursos do OLE não são fornecidos diretamente pelo MFC. Se você quiser usar esses recursos, você pode chamar a API OLE diretamente.

Interface IMoniker `IMoniker` A interface é implementada pela biblioteca `COleServerItem` de classes (por exemplo, a classe), mas não foi exposta anteriormente ao programador. Para obter mais informações sobre esta interface, consulte Implementações de apelidoo OLE na seção OLE do Windows SDK. No entanto, consulte também a classe [CMonikerFile](../mfc/reference/cmonikerfile-class.md) e [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md).

Interfaces IUnknown e `IUnknown` IMarshal A interface é implementada pela biblioteca de classes, mas não está exposta ao programador. A `IMarshal` interface não é implementada pela biblioteca de classes, mas é usada internamente. Os servidores de automação construídos usando a biblioteca de classes já possuem recursos de empacotamento incorporados.

Arquivos compostos docfiles (Arquivos compostos) Os arquivos compostos são parcialmente suportados pela biblioteca de classes. Nenhuma das funções que manipulam diretamente arquivos compostos além da criação são suportadas. O MFC `COleFileStream` usa classe para suportar a manipulação de fluxos com funções de arquivo padrão. Para obter mais informações, consulte o artigo [Containers: Compound Files](../mfc/containers-compound-files.md).

Servidores em processo e manipuladores de objetos Servidores e manipuladores de objetos permitem a implementação de dados de edição visual ou objetos COM (Component Object Model, modelo de objeto componente completo) completos em uma biblioteca de links dinâmicos (DLL). Para fazer isso, você pode implementar sua DLL ligando diretamente para a API OLE. No entanto, se você estiver escrevendo um servidor de automação e seu servidor não tiver interface de usuário, você pode usar o AppWizard para tornar seu servidor um servidor em processo e colocá-lo completamente em um DLL. Para obter mais informações sobre esses [tópicos,](../mfc/automation-servers.md)consulte Servidores de Automação .

> [!TIP]
> A maneira mais fácil de implementar um servidor de Automação é colocá-lo em um DLL. O MFC apoia essa abordagem.

Para obter mais informações sobre como as classes OLE da Microsoft Foundation implementam interfaces OLE, consulte Notas Técnicas MFC [38](../mfc/tn038-mfc-ole-iunknown-implementation.md), [39](../mfc/tn039-mfc-ole-automation-implementation.md)e [40](../mfc/tn040-mfc-ole-in-place-resizing-and-zooming.md).

## <a name="see-also"></a>Confira também

[tela de fundo OLE](../mfc/ole-background.md)<br/>
[Tela de fundo OLE: estratégias de implementação](../mfc/ole-background-implementation-strategies.md)
