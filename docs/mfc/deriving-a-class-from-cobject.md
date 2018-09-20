---
title: Derivando uma classe de CObject | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CObject
dev_langs:
- C++
helpviewer_keywords:
- DECLARE_DYNCREATE macro [MFC]
- DECLARE_SERIAL macro [MFC]
- macros [MFC], serialization
- serialization [MFC], macros
- DECLARE_DYNAMIC macro [MFC]
- derived classes [MFC], from CObject
- CObject class [MFC], deriving serializable classes
- CObject class [MFC], deriving from
ms.assetid: 5ea4ea41-08b5-4bd8-b247-c5de8c152a27
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 177d4160972f521eeeaee56087c29e18433be87e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46440220"
---
# <a name="deriving-a-class-from-cobject"></a>Derivando uma classe de CObject

Este artigo descreve as etapas mínimas necessárias para derivar uma classe de [CObject](../mfc/reference/cobject-class.md). Outros `CObject` artigos de classe descrevem as etapas necessárias para tirar proveito de determinado `CObject` recursos, como a serialização e suporte de depuração de diagnóstico.

Nas discussões de `CObject`, os termos "interface file" e "arquivo de implementação" são usados com frequência. O arquivo de interface (geralmente chamado de arquivo de cabeçalho, ou. Arquivo do H) contém a declaração de classe e quaisquer outras informações necessárias para usar a classe. O arquivo de implementação (ou). Arquivo CPP) contém a definição de classe, bem como o código que implementa as funções de membro de classe. Por exemplo, para uma classe chamada `CPerson`, você normalmente criaria um arquivo de interface chamado pessoa. H e um arquivo de implementação chamado pessoa. CPP. No entanto, para algumas classes pequenas que não serão compartilhados entre aplicativos, às vezes, é mais fácil combinar a interface e implementação em um único. Arquivo CPP.

Você pode escolher entre quatro níveis de funcionalidade ao derivar uma classe de `CObject`:

- Funcionalidade básica: não há suporte para serialização ou informações de classe de tempo de execução, mas inclui gerenciamento de diagnóstico de memória.

- Funcionalidade básica mais suporte para informações de classe de tempo de execução.

- Mais suporte para informações de classe de tempo de execução e criação dinâmica de funcionalidade básica.

- Funcionalidade básica mais suporte para informações de classe de tempo de execução, a criação dinâmica e a serialização.

Classes desenvolvidas para reutilização (aquelas que servirá como classes base mais tarde) devem incluir pelo menos o suporte de classe de tempo de execução e suporte de serialização, se há previsão de qualquer necessidade de serialização futuros.

Escolha o nível de funcionalidade usando macros de declaração e implementação específicas na declaração e implementação das classes que derivam de `CObject`.

A tabela a seguir mostra a relação entre as macros usadas para dar suporte à serialização e informações de tempo de execução.

### <a name="macros-used-for-serialization-and-run-time-information"></a>Usado para serialização e informações de tempo de execução de macros

|Macro usada|CObject::IsKindOf|CRuntimeClass::<br /><br /> CreateObject|CArchive::operator >><br /><br /> CArchive::operator <<|
|----------------|-----------------------|--------------------------------------|-------------------------------------------------------|
|Básico `CObject` funcionalidade|Não|Não|Não|
|`DECLARE_DYNAMIC`|Sim|Não|Não|
|`DECLARE_DYNCREATE`|Sim|Sim|Não|
|`DECLARE_SERIAL`|Sim|Sim|Sim|

#### <a name="to-use-basic-cobject-functionality"></a>Para usar a funcionalidade básica de CObject

1. Use a sintaxe de C++ normal para derivar a classe de `CObject` (ou de uma classe derivada de `CObject`).

     O exemplo a seguir mostra o caso mais simples, a derivação de uma classe de `CObject`:

     [!code-cpp[NVC_MFCCObjectSample#1](../mfc/codesnippet/cpp/deriving-a-class-from-cobject_1.h)]

Normalmente, no entanto, você talvez queira substituir algumas das `CObject`de funções de membro para manipular as especificidades de sua nova classe. Por exemplo, normalmente, talvez queira substituir a `Dump` função de `CObject` para fornecer saída de depuração para o conteúdo da sua classe. Para obter detalhes sobre como substituir `Dump`, consulte o artigo [diagnóstico: despejar o conteúdo de objeto](/previous-versions/visualstudio/visual-studio-2010/sc15kz85\(v=vs.100\)). Você talvez também queira substituir a `AssertValid` função de `CObject` para fornecer teste personalizado para validar a consistência dos membros de dados de objetos de classe. Para obter uma descrição de como substituir `AssertValid`, consulte [MFC ASSERT_VALID e CObject::assertvalid&lt;1}](/previous-versions/visualstudio/visual-studio-2010/38z04tfa\(v=vs.100\)).

O artigo [especificando níveis de funcionalidade](../mfc/specifying-levels-of-functionality.md) descreve como especificar outros níveis de funcionalidade, incluindo informações de classe de tempo de execução, a criação de objeto dinâmico e a serialização.

## <a name="see-also"></a>Consulte também

[Usando CObject](../mfc/using-cobject.md)

