---
title: Modelo de Classes para matrizes, listas e mapeia | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.template
dev_langs:
- C++
helpviewer_keywords:
- arrays [MFC], classes
- template classes [MFC], for arrays/lists and maps
- list classes [MFC]
- map classes [MFC]
- template classes [MFC]
ms.assetid: a8331c4b-068a-48f8-a629-b8449601e121
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 218c5344ad8cdc1e63f3337cd031ac707fa7b5ef
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46375530"
---
# <a name="template-classes-for-arrays-lists-and-maps"></a>Classes de modelo para matrizes, listas e mapas

Essas classes de coleção são modelos cujos parâmetros de determinam os tipos de objetos armazenados em agregações. O `CArray`, `CMap`, e `CList` classes usam funções auxiliares global que geralmente devem ser personalizadas. Para obter mais informações sobre essas funções auxiliares, consulte [auxiliares da classe de coleção](../mfc/reference/collection-class-helpers.md). As classes de ponteiro tipado são wrappers para outras classes na biblioteca de classes. Ao usar esses wrappers, você inscrever-se do compilador verificação de tipo para ajudar a evitar erros. Para obter mais informações sobre como usar essas classes, consulte [coleções](../mfc/collections.md).

Essas classes fornecem modelos que você pode usar para criar matrizes, listas e mapas usando qualquer tipo que você deseja.

[CArray](../mfc/reference/carray-class.md)<br/>
Classe de modelo para fazer a matrizes de tipos arbitrários.

[CList](../mfc/reference/clist-class.md)<br/>
Classe de modelo para criar listas de tipos arbitrários.

[CMap](../mfc/reference/cmap-class.md)<br/>
Classe de modelo para fazer mapeamentos de tipos arbitrários de chave e valor.

[CTypedPtrArray](../mfc/reference/ctypedptrarray-class.md)<br/>
Classe de modelo para matrizes de tipo seguro de ponteiros.

[CTypedPtrList](../mfc/reference/ctypedptrlist-class.md)<br/>
Classe de modelo para as listas de segurança de tipos de ponteiros.

[CTypedPtrMap](../mfc/reference/ctypedptrmap-class.md)<br/>
Classe de modelo para mapas de tipo seguro com ponteiros.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)

