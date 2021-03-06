---
title: Especificando níveis de funcionalidade
ms.date: 11/06/2018
helpviewer_keywords:
- CObject class [MFC], adding functionality to derived classes
- runtime [MFC], class information
- serialization [MFC], Cobject
- dynamic creation support
- levels [MFC], functionality in CObject
- run-time class [MFC], information support
- levels [MFC]
ms.assetid: 562669ba-c858-4f66-b5f1-b3beeea4f486
ms.openlocfilehash: c3b4ecb38054748f36d75ca43e32d6447d3d2428
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62307283"
---
# <a name="specifying-levels-of-functionality"></a>Especificando níveis de funcionalidade

Este artigo descreve como adicionar os seguintes níveis de funcionalidade para seus [CObject](../mfc/reference/cobject-class.md)-classe derivada:

- Informações de classe de tempo de execução

- Suporte à criação dinâmica

- Suporte de serialização

Para obter uma descrição geral `CObject` funcionalidade, consulte o artigo [derivando uma classe de CObject](../mfc/deriving-a-class-from-cobject.md).

## <a name="to-add-run-time-class-information"></a>Para adicionar informações de classe de tempo de execução

1. Derive sua classe de `CObject`, conforme descrito em de [derivando uma classe de CObject](../mfc/deriving-a-class-from-cobject.md) artigo.

1. Use a macro DECLARE_DYNAMIC na sua declaração de classe, conforme mostrado aqui:

   [!code-cpp[NVC_MFCCObjectSample#2](../mfc/codesnippet/cpp/specifying-levels-of-functionality_1.h)]

1. Use a macro IMPLEMENT_DYNAMIC no arquivo de implementação (. CPP) da sua classe. Essa macro usa como argumentos o nome da classe e sua classe base, da seguinte maneira:

   [!code-cpp[NVC_MFCCObjectSample#3](../mfc/codesnippet/cpp/specifying-levels-of-functionality_2.cpp)]

> [!NOTE]
> Sempre coloque IMPLEMENT_DYNAMIC no arquivo de implementação (. CPP) para a sua classe. A macro IMPLEMENT_DYNAMIC deve ser avaliada apenas uma vez durante uma compilação e, portanto, não deve ser usada em um arquivo de interface (. H) que potencialmente pode ser incluído em mais de um arquivo.

## <a name="to-add-dynamic-creation-support"></a>Para adicionar suporte à criação dinâmica

1. Derive sua classe de `CObject`.

1. Use a macro DECLARE_DYNCREATE na declaração da classe.

1. Defina um construtor sem argumentos (um construtor padrão).

1. Use a macro IMPLEMENT_DYNCREATE no arquivo de implementação de classe.

## <a name="to-add-serialization-support"></a>Para adicionar suporte de serialização

1. Derive sua classe de `CObject`.

1. Substituir o `Serialize` função de membro.

   > [!NOTE]
   > Se você chamar `Serialize` diretamente, ou seja, você não deseja serializar o objeto através de um ponteiro polimórfico, omita as etapas 3 a 5.

1. Use a macro DECLARE_SERIAL na declaração da classe.

1. Defina um construtor sem argumentos (um construtor padrão).

1. Use a macro IMPLEMENT_SERIAL no arquivo de implementação de classe.

> [!NOTE]
> Um "ponteiro polimórfico" aponta para um objeto de uma classe (chamá-lo um) ou a um objeto de qualquer classe derivada de um (digamos, B). Para serializar através de um ponteiro polimórfico, a estrutura deve determinar a classe de tempo de execução do objeto que ele está serializando (B), pois ela pode ser um objeto de qualquer classe derivada de uma classe base (A).

Para obter mais detalhes sobre como habilitar a serialização quando você deriva sua classe de `CObject`, consulte os artigos [arquivos no MFC](../mfc/files-in-mfc.md) e [serialização](../mfc/serialization-in-mfc.md).

## <a name="see-also"></a>Consulte também

[Derivando uma classe de CObject](../mfc/deriving-a-class-from-cobject.md)
