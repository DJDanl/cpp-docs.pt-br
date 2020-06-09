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
ms.openlocfilehash: 1dffdafbd02697db5aec341fec253c84217a0faf
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619870"
---
# <a name="ole-background-mfc-implementation"></a>tela de fundo OLE: implementação MFC

Devido ao tamanho e à complexidade da API OLE bruta, chamá-la diretamente para escrever aplicativos OLE pode ser muito demorado. O objetivo da implementação de biblioteca MFC do OLE é reduzir a quantidade de trabalho que você precisa fazer para escrever aplicativos completos e compatíveis com OLE.

Este artigo explica as partes da API OLE que não foram implementadas dentro do MFC. A discussão também explica como o que é implementado é mapeado para a seção OLE do SDK do Windows.

## <a name="portions-of-ole-not-implemented-by-the-class-library"></a><a name="_core_portions_of_ole_not_implemented_by_the_class_library"></a>Partes do OLE não implementadas pela biblioteca de classes

Algumas interfaces e recursos do OLE não são fornecidos diretamente pelo MFC. Se você quiser usar esses recursos, poderá chamar a API OLE diretamente.

Interface IMoniker a `IMoniker` interface é implementada pela biblioteca de classes (por exemplo, a `COleServerItem` classe), mas não foi exposta anteriormente ao programador. Para obter mais informações sobre essa interface, consulte implementações de moniker OLE na seção OLE do SDK do Windows. No entanto, consulte também Class [CMonikerFile](reference/cmonikerfile-class.md) e [CAsyncMonikerFile](reference/casyncmonikerfile-class.md).

Interfaces IUnknown e IMarshal a `IUnknown` interface é implementada pela biblioteca de classes, mas não é exposta ao programador. A `IMarshal` interface não é implementada pela biblioteca de classes, mas é usada internamente. Os servidores de automação criados com a biblioteca de classes já têm recursos de marshaling integrados.

Os arquivos compostos de Docfile (arquivos compostos) são parcialmente suportados pela biblioteca de classes. Nenhuma das funções que manipulam diretamente arquivos compostos além da criação têm suporte. O MFC usa `COleFileStream` a classe para dar suporte à manipulação de fluxos com funções de arquivo padrão. Para obter mais informações, consulte o artigo [contêineres: arquivos compostos](containers-compound-files.md).

Os servidores em processo e os manipuladores de objetos e os manipuladores de objetos permitem a implementação de dados de edição visual ou objetos COM (Component Object Model completo) em uma DLL (biblioteca de vínculo dinâmico). Para fazer isso, você pode implementar sua DLL chamando a API OLE diretamente. No entanto, se você estiver gravando um servidor de automação e o servidor não tiver nenhuma interface do usuário, você poderá usar o AppWizard para tornar o servidor um servidor em processo e colocá-lo completamente em uma DLL. Para obter mais informações sobre esses tópicos, consulte [servidores de automação](automation-servers.md).

> [!TIP]
> A maneira mais fácil de implementar um servidor de automação é colocá-lo em uma DLL. O MFC dá suporte a essa abordagem.

Para obter mais informações sobre como as classes OLE do Microsoft Foundation implementam interfaces OLE, consulte notas técnicas do MFC [38](tn038-mfc-ole-iunknown-implementation.md), [39](tn039-mfc-ole-automation-implementation.md)e [40](tn040-mfc-ole-in-place-resizing-and-zooming.md).

## <a name="see-also"></a>Consulte também

[tela de fundo OLE](ole-background.md)<br/>
[Tela de fundo OLE: estratégias de implementação](ole-background-implementation-strategies.md)
