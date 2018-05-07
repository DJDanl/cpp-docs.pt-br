---
title: Armazenando e carregando CObjects por meio de um arquivo morto | Microsoft Docs
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
- CObjects [MFC], loading through archives
- CArchive class [MFC], storing and loading objects
- Serialize method, vs. CArchive operators
- CObject class [MFC], CArchive objects
- CObjects [MFC]
ms.assetid: a829b6dd-bc31-47e0-8108-fbb946722db9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fe5cc426e3494117bff98577f02178709a2588f3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="storing-and-loading-cobjects-via-an-archive"></a>Armazenando e carregando CObjects por meio de um arquivo morto
Armazenando e carregando `CObject`s por meio de um arquivo morto requer considerações adicionais. Em certos casos, você deve chamar o `Serialize` função do objeto, onde o `CArchive` objeto é um parâmetro do `Serialize` chamada, em vez de usar o **< \<** ou **>>** operador o `CArchive`. O fato importante ter em mente é que o `CArchive` **>>** construções de operador de `CObject` na memória com base em `CRuntimeClass` previamente gravadas para o arquivo, o arquivo de armazenamento de informações.  
  
 Portanto, se você usar o `CArchive` **< \<** e **>>** operadores, em vez de chamar `Serialize`, depende se você *necessário* o arquivamento de carregar dinamicamente reconstruir o objeto com base em armazenada anteriormente `CRuntimeClass` informações. Use o `Serialize` função nos seguintes casos:  
  
-   Quando a desserialização do objeto, saber com antecedência a classe exata do objeto.  
  
-   Ao desserializar o objeto, você já tem memória alocada para ele.  
  
> [!CAUTION]
>  Se você carregar o objeto usando o `Serialize` função, você também deve armazenar o objeto usando o `Serialize` função. Não armazene usando o `CArchive` **<<** operador e o uso de carga, em seguida, o `Serialize` de função ou o repositório usando o `Serialize` de função e, em seguida, carregar usando **CArchive >>** operador.  
  
 O exemplo a seguir ilustra os casos:  
  
 [!code-cpp[NVC_MFCSerialization#36](../mfc/codesnippet/cpp/storing-and-loading-cobjects-via-an-archive_1.h)]  
  
 [!code-cpp[NVC_MFCSerialization#37](../mfc/codesnippet/cpp/storing-and-loading-cobjects-via-an-archive_2.cpp)]  
  
 Em resumo, se sua classe serializável define inserida **CObjec**t como um membro, você deve *não* usar o `CArchive` **< \<** e **>>** operadores para o objeto, mas deve chamar o `Serialize` function em vez disso. Além disso, se sua classe serializável define um ponteiro para um `CObject` (ou um objeto derivado de `CObject`) como um membro, mas construções esse outro objeto em seu próprio construtor, você também deve chamar `Serialize`.  
  
## <a name="see-also"></a>Consulte também  
 [Serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md)

