---
title: Identificadores de recursos (Símbolos) (C++)
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
ms.openlocfilehash: c6b3cf7d3edfc870164645632bb07bf49c792a48
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359893"
---
# <a name="resource-identifiers-symbols-c"></a>Identificadores de recursos (Símbolos) (C++)

Um símbolo é um identificador de recursos (ID) que consiste em duas partes, um nome símbolo (seqüência de texto) mapeado para um valor símbolo (inteiro), por exemplo:

```cpp
IDC_EDITNAME = 5100
```

Nomes de símbolos são mais frequentemente referidos como identificadores.

Os símbolos fornecem uma maneira descritiva de se referir a recursos e objetos de interface de usuário, tanto no seu código fonte quanto enquanto você está trabalhando com eles nos editores de recursos. Você pode visualizar e manipular símbolos em um lugar conveniente usando a [caixa de diálogo Símbolos de recursos](../windows/viewing-resource-symbols.md).

À medida que sua aplicação cresce em tamanho e sofisticação, também cresce seu número de recursos e símbolos. Rastrear um grande número de símbolos espalhados por vários arquivos pode ser difícil. A caixa de diálogo **Símbolos** de recursos simplifica o gerenciamento de símbolos oferecendo uma ferramenta central através da qual você pode:

- [Criar símbolos](../windows/creating-new-symbols.md)

- [Gerenciar símbolos](../windows/changing-a-symbol-or-symbol-name-id.md)

- [Exibir IDs de símbolo predefinidos](../windows/predefined-symbol-ids.md)

Quando você cria um novo recurso ou objeto de recurso, os [editores de recursos](../windows/resource-editors.md) fornecem um nome padrão para o recurso, por exemplo, `IDC_RADIO1`e atribuem um valor a ele. A definição de nome mais valor `Resource.h` é armazenada no arquivo.

> [!NOTE]
> Quando você estiver copiando recursos ou objetos de recurso de um arquivo .rc para outro, o Visual C++ pode alterar o valor do símbolo do recurso transferido, ou nome e valor do símbolo, para evitar conflitos com nomes ou valores de símbolos no arquivo existente.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)<br/>
[Arquivos de recursos](../windows/resource-files-visual-studio.md)<br/>
[Editores de recursos](../windows/resource-editors.md)<br/>
