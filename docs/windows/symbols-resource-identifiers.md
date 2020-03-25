---
title: Identificadores de recurso (símbolos)C++()
ms.date: 02/14/2019
f1_keywords:
- vc.editors.symbol.identifiers
helpviewer_keywords:
- symbols [C++], resource identifiers
- symbols [C++], creating
- resource symbols
- symbols [C++], editing
- resource editors [C++], resource symbols
ms.assetid: 8fccc09a-0237-4a65-b9c4-57d60c59e324
ms.openlocfilehash: ba0958e455557660ef704f1c2fa570d46307082f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214390"
---
# <a name="resource-identifiers-symbols-c"></a>Identificadores de recurso (símbolos)C++()

Um símbolo é um identificador de recurso (ID) que consiste em duas partes, um nome de símbolo (cadeia de texto) mapeado para um valor de símbolo (inteiro), por exemplo:

```
IDC_EDITNAME = 5100
```

Os nomes de símbolo são geralmente chamados de identificadores.

Os símbolos fornecem uma maneira descritiva de se referir a recursos e objetos de interface do usuário, tanto no código-fonte quanto quando você está trabalhando com eles nos editores de recursos. Você pode exibir e manipular símbolos em um único local conveniente usando a [caixa de diálogo símbolos de recurso](../windows/viewing-resource-symbols.md).

À medida que seu aplicativo cresce em tamanho e sofisticação, então o número de recursos e símbolos. É difícil controlar grandes números de símbolos espalhados em vários arquivos. A caixa de diálogo **símbolos de recurso** simplifica o gerenciamento de símbolos oferecendo uma ferramenta central por meio da qual você pode:

- [Criar símbolos](../windows/creating-new-symbols.md)

- [Gerenciar símbolos](../windows/changing-a-symbol-or-symbol-name-id.md)

- [Exibir IDs de símbolo predefinidos](../windows/predefined-symbol-ids.md)

Quando você cria um novo recurso ou objeto de recurso, os [editores de recursos](../windows/resource-editors.md) fornecem um nome padrão para o recurso, por exemplo, `IDC_RADIO1`, e atribui um valor a ele. A definição nome-mais-valor é armazenada no arquivo de `Resource.h`.

> [!NOTE]
> Quando você copia recursos ou objetos de recurso de um arquivo. rc para outro, o C++ visual pode alterar o valor do símbolo do recurso transferido ou o nome e o valor do símbolo para evitar conflitos com nomes de símbolo ou valores no arquivo existente.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)<br/>
[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Editores de recursos](../windows/resource-editors.md)<br/>
