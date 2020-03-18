---
title: Armazenando e carregando CObjects por meio de um arquivo morto
ms.date: 11/04/2016
helpviewer_keywords:
- CObjects [MFC], loading through archives
- CArchive class [MFC], storing and loading objects
- Serialize method, vs. CArchive operators
- CObject class [MFC], CArchive objects
- CObjects [MFC]
ms.assetid: a829b6dd-bc31-47e0-8108-fbb946722db9
ms.openlocfilehash: 368421a86d6ff6fc70455edd0ea9a32e05645007
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446371"
---
# <a name="storing-and-loading-cobjects-via-an-archive"></a>Armazenando e carregando CObjects por meio de um arquivo morto

O armazenamento e o carregamento `CObject`s por meio de um arquivo requer uma consideração extra. Em determinados casos, você deve chamar a função `Serialize` do objeto, em que o objeto `CArchive` é um parâmetro da chamada `Serialize`, em oposição ao uso do **<\<** ou **>>** operador da `CArchive`. O fato importante a ter em mente é que o operador `CArchive` **>>** constrói a `CObject` na memória com base em `CRuntimeClass` informações gravadas anteriormente no arquivo pelo arquivamento de armazenamento.

Portanto, se você usar o `CArchive` **<\<** e os operadores de **>>** , em vez de chamar `Serialize`, dependerá se você *precisa* do arquivo de carregamento para reconstruir dinamicamente o objeto com base em informações de `CRuntimeClass` armazenadas anteriormente. Use a função `Serialize` nos seguintes casos:

- Ao desserializar o objeto, você sabe a classe exata do objeto com antecedência.

- Ao desserializar o objeto, você já tem memória alocada para ele.

> [!CAUTION]
>  Se você carregar o objeto usando a função `Serialize`, também deverá armazenar o objeto usando a função `Serialize`. Não armazene usando o operador `CArchive` **<<** e, em seguida, carregue usando a função `Serialize`, ou armazene usando a função `Serialize` e, em seguida, carregue usando o operador `CArchive >>`.

O exemplo a seguir ilustra os casos:

[!code-cpp[NVC_MFCSerialization#36](../mfc/codesnippet/cpp/storing-and-loading-cobjects-via-an-archive_1.h)]

[!code-cpp[NVC_MFCSerialization#37](../mfc/codesnippet/cpp/storing-and-loading-cobjects-via-an-archive_2.cpp)]

Em resumo, se sua classe serializável definir um `CObject` inserido como um membro, você *não* deverá usar o `CArchive` **<\<** e os operadores de **>>** para esse objeto, mas deverá chamar a função `Serialize` em vez disso. Além disso, se sua classe serializável definir um ponteiro para um `CObject` (ou um objeto derivado de `CObject`) como um membro, mas construir esse outro objeto em seu próprio construtor, você também deverá chamar `Serialize`.

## <a name="see-also"></a>Consulte também

[Serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md)
