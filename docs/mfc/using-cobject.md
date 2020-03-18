---
title: Usando CObject
ms.date: 11/04/2016
helpviewer_keywords:
- examples [MFC], CObject
- root base class for MFC
- derived classes [MFC], from CObject
- MFC, base class
- CObject class [MFC]
ms.assetid: d0cd19bb-2856-4b41-abbc-620fd64cb223
ms.openlocfilehash: b5399f02819407a529fd5ec66d4f5acbb16ca002
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79441930"
---
# <a name="using-cobject"></a>Usando CObject

[CObject](../mfc/reference/cobject-class.md) é a classe base raiz para a maioria das biblioteca MFC (MFC). A classe `CObject` contém muitos recursos úteis que talvez você queira incorporar em seus próprios objetos de programa, incluindo suporte de serialização, informações de classe em tempo de execução e saída de diagnóstico de objeto. Se você derivar sua classe de `CObject`, sua classe poderá explorar esses recursos de `CObject`.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer

- [Derive uma classe de CObject](../mfc/deriving-a-class-from-cobject.md)

- [Adicionar suporte para informações de classe de tempo de execução, criação dinâmica e serialização à minha classe derivada](../mfc/specifying-levels-of-functionality.md)

- [Acessar informações de classe de tempo de execução](../mfc/accessing-run-time-class-information.md)

- [Criar objetos dinamicamente](../mfc/dynamic-object-creation.md)

- [Despejar os dados do objeto para fins de diagnóstico](/previous-versions/visualstudio/visual-studio-2010/sc15kz85(v=vs.100))

- Validar o estado interno do objeto (consulte [MFC ASSERT_VALID e CObject:: AssertValid](reference/diagnostic-services.md#assert_valid))

- [Fazer com que a classe se Serialize para o armazenamento persistente](../mfc/serialization-in-mfc.md)

- Veja uma lista de [perguntas](../mfc/cobject-class-frequently-asked-questions.md) frequentes sobre o CObject

## <a name="see-also"></a>Consulte também

[Conceitos](../mfc/mfc-concepts.md)<br/>
[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)<br/>
[Estrutura CRuntimeClass](../mfc/reference/cruntimeclass-structure.md)<br/>
[Arquivos](../mfc/files-in-mfc.md)<br/>
[Serialização](../mfc/serialization-in-mfc.md)
