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
ms.openlocfilehash: f1b59516d5bba13b6f5e006f91d8ebd560543b05
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372155"
---
# <a name="storing-and-loading-cobjects-via-an-archive"></a>Armazenando e carregando CObjects por meio de um arquivo morto

Armazenar e carregar `CObject`s através de um arquivo requer uma consideração extra. Em certos casos, você `Serialize` deve chamar a `CArchive` função do objeto, `Serialize` onde o objeto é ** < ** **>>** um parâmetro `CArchive`da chamada, em vez de usar o ou operador do . O fato importante a ter `CArchive` **>>** em mente `CObject` é que `CRuntimeClass` o operador constrói a memória in com base em informações previamente escritas no arquivo pelo arquivo de armazenamento.

Portanto, se você `CArchive` ** < ** usa **>>** os operadores `Serialize`e operadores, versus chamadas, depende se você *precisa* do `CRuntimeClass` arquivo de carregamento para reconstruir dinamicamente o objeto com base em informações armazenadas anteriormente. Use `Serialize` a função nos seguintes casos:

- Ao desserializar o objeto, você sabe a classe exata do objeto de antemão.

- Ao desserializar o objeto, você já tem a memória alocada para ele.

> [!CAUTION]
> Se você carregar o `Serialize` objeto usando a função, `Serialize` você também deve armazenar o objeto usando a função. Não armazene `CArchive` **<<** usando o operador `Serialize` e, em seguida, carregue usando a função, ou armazene usando a `Serialize` função e, em seguida, carregue usando o `CArchive >>` operador.

O exemplo a seguir ilustra os casos:

[!code-cpp[NVC_MFCSerialization#36](../mfc/codesnippet/cpp/storing-and-loading-cobjects-via-an-archive_1.h)]

[!code-cpp[NVC_MFCSerialization#37](../mfc/codesnippet/cpp/storing-and-loading-cobjects-via-an-archive_2.cpp)]

Em resumo, se sua classe serializável `CObject` definir um incorporado como `CArchive` ** < ** um **>>** membro, você *não* deve usar os operadores e operadores para esse objeto, mas deve chamar a `Serialize` função em vez disso. Além disso, se sua classe serializável definir um ponteiro para um `CObject` (ou um objeto derivado ) `CObject`como membro, `Serialize`mas construir este outro objeto em seu próprio construtor, você também deve chamar .

## <a name="see-also"></a>Confira também

[Serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md)
