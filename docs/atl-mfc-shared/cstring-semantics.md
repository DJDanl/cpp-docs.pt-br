---
title: Semântica de CString
ms.date: 11/04/2016
helpviewer_keywords:
- semantics in Cstring
- CString objects, assignment semantics
- assignment statements, assigning CString objects
ms.assetid: d4023480-526f-499a-85f6-324b4de5b85f
ms.openlocfilehash: f563b24a9df61a91711433a4e4987f8f800545ff
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50657789"
---
# <a name="cstring-semantics"></a>Semântica de CString

Embora [CString](../atl-mfc-shared/reference/cstringt-class.md) objetos são objetos dinâmicos que podem crescer, eles atuam como classes simples e tipos primitivos internos. Cada `CString` objeto representa um valor exclusivo. `CString` objetos devem ser considerados como as cadeias de caracteres reais em vez de ponteiros para cadeias de caracteres.

Você pode atribuir uma `CString` objeto para outro. No entanto, quando você modifica uma das duas `CString` objetos, o outro `CString` objeto não for modificado, conforme mostrado no exemplo a seguir:

[!code-cpp[NVC_ATLMFC_Utilities#188](../atl-mfc-shared/codesnippet/cpp/cstring-semantics_1.cpp)]

Observe no exemplo que os dois `CString` objetos são considerados "equal", porque eles representam a mesma cadeia de caracteres. O `CString` classe sobrecarrega o operador de igualdade (`==`) para comparar dois `CString` objetos com base em seu valor (conteúdo) em vez de sua identidade (endereço).

## <a name="see-also"></a>Consulte também

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)

