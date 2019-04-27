---
title: 'Tela de fundo OLE: Implementação do MFC'
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
ms.openlocfilehash: f793c7d7303a49057e46c32eb658ea7eea8e9ccc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62186723"
---
# <a name="ole-background-mfc-implementation"></a>Tela de fundo OLE: Implementação do MFC

Devido ao tamanho e da complexidade do OLE API básica, chamá-lo diretamente para escrever aplicativos OLE pode ser muito demorado. O objetivo da implementação da biblioteca Microsoft Foundation Class OLE é reduzir a quantidade de trabalho que você precisa fazer para escrever aplicativos completos, compatíveis com OLE.

Este artigo explica as partes da API OLE que não foram implementadas dentro do MFC. A discussão também explica como o que é implementado é mapeada para a seção OLE do SDK do Windows.

##  <a name="_core_portions_of_ole_not_implemented_by_the_class_library"></a> Partes do OLE não implementada pela biblioteca de classes

Algumas interfaces e recursos do OLE não são fornecidos diretamente pelo MFC. Se você quiser usar esses recursos, você pode chamar a API OLE diretamente.

IMoniker Interface a `IMoniker` interface é implementada pela biblioteca de classes (por exemplo, o `COleServerItem` classe), mas anteriormente não expostos para o programador. Para obter mais informações sobre essa interface, consulte OLE Moniker implementações na seção OLE do SDK do Windows. No entanto, também consulte classe [CMonikerFile](../mfc/reference/cmonikerfile-class.md) e [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md).

IUnknown e Interfaces IMarshal o `IUnknown` interface é implementada pela biblioteca de classes, mas não é exposto para o programador. O `IMarshal` interface não é implementada pela biblioteca de classes, mas é usada internamente. Servidores de automação criados usando a biblioteca de classes de já tem marshaling recursos incorporados.

Arquivos compostos de DOCFILES (arquivos compostos) têm suporte parcial pela biblioteca de classes. Nenhuma das funções que manipulam diretamente os arquivos compostos além da criação têm suporte. Classe do MFC usa `COleFileStream` para dar suporte à manipulação de fluxos com funções de arquivo padrão. Para obter mais informações, consulte o artigo [contêineres: Composta arquivos](../mfc/containers-compound-files.md).

Servidores em processo de servidores em processo e manipuladores de objeto e manipuladores de objeto permitem a implementação de edição visual de dados ou objetos de modelo de objeto de componente (COM) completo em uma biblioteca de vínculo dinâmico (DLL). Para fazer isso, você pode implementar sua DLL chamando a API OLE diretamente. No entanto, se você estiver escrevendo um servidor de automação e o servidor não tem nenhuma interface do usuário, você pode usar o AppWizard para tornar seu servidor de um servidor em processo e coloque-o completamente em uma DLL. Para obter mais informações sobre esses tópicos, consulte [servidores de automação](../mfc/automation-servers.md).

> [!TIP]
>  A maneira mais fácil de implementar um servidor de automação é colocá-lo em uma DLL. MFC é compatível com essa abordagem.

Para obter mais informações sobre como as Microsoft Foundation classes OLE implementam interfaces OLE, consulte Observações técnicas MFC [38](../mfc/tn038-mfc-ole-iunknown-implementation.md), [39](../mfc/tn039-mfc-ole-automation-implementation.md), e [40](../mfc/tn040-mfc-ole-in-place-resizing-and-zooming.md).

## <a name="see-also"></a>Consulte também

[Tela de fundo OLE](../mfc/ole-background.md)<br/>
[Tela de fundo OLE: estratégias de implementação](../mfc/ole-background-implementation-strategies.md)
