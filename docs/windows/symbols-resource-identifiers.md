---
title: Identificadores de recurso (símbolos) (C++)
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
ms.openlocfilehash: 63971ba381394bcaf905d614496511b7aa0d01f3
ms.sourcegitcommit: b4645761ce5acf8c2fc7a662334dd5a471ea976d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/07/2019
ms.locfileid: "57563310"
---
# <a name="resource-identifiers-symbols-c"></a>Identificadores de recurso (símbolos) (C++)

Um símbolo é um identificador de recurso (ID) que consiste em duas partes, um nome de símbolo (cadeia de caracteres de texto) mapeado para um valor de símbolo (inteiro), por exemplo:

```
IDC_EDITNAME = 5100
```

Nomes de símbolos são geralmente denominados identificadores.

Símbolos fornecem uma maneira descritiva de fazer referência a recursos e objetos de interface do usuário, no seu código-fonte e enquanto estiver trabalhando com eles nos editores de recursos. Você pode exibir e manipular símbolos em um local conveniente usando o [caixa de diálogo símbolos de recurso](../windows/viewing-resource-symbols.md).

À medida que seu aplicativo crescer em tamanho e a sofisticação e aumenta seu número de recursos e símbolos. Grande número de símbolos espalhados em vários arquivos de rastreamento pode ser difícil. O **símbolos de recurso** caixa de diálogo simplifica o gerenciamento de símbolo, oferecendo uma ferramenta central por meio do qual você pode:

- [Crie símbolos](../windows/creating-new-symbols.md)

- [Gerenciar símbolos](../windows/changing-a-symbol-or-symbol-name-id.md)

- [Exibir IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)

Quando você cria um novo recurso ou objeto de recurso, o [editores de recursos](../windows/resource-editors.md) forneça um nome padrão para o recurso, por exemplo, `IDC_RADIO1`e atribuir um valor a ela. A definição de mais valor name é armazenada no `Resource.h` arquivo.

> [!NOTE]
> Quando você estiver copiando recursos ou objetos de recurso de um arquivo. RC para outro, o Visual C++ pode alterar o recurso transferido símbolo valor, ou o nome do símbolo e, para evitar conflitos com nomes de símbolos ou os valores no arquivo existente.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)<br/>
[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Editores de recursos](../windows/resource-editors.md)<br/>