---
title: Semântica de CString | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- semantics in Cstring
- CString objects, assignment semantics
- assignment statements, assigning CString objects
ms.assetid: d4023480-526f-499a-85f6-324b4de5b85f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b1638b279f0bd9ee968451ea75ec1c5549e369d9
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37886148"
---
# <a name="cstring-semantics"></a>Semântica de CString
Embora [CString](../atl-mfc-shared/reference/cstringt-class.md) objetos são objetos dinâmicos que podem crescer, eles atuam como classes simples e tipos primitivos internos. Cada `CString` objeto representa um valor exclusivo. `CString` objetos devem ser considerados como as cadeias de caracteres reais em vez de ponteiros para cadeias de caracteres.  
  
 Você pode atribuir uma `CString` objeto para outro. No entanto, quando você modifica uma das duas `CString` objetos, o outro `CString` objeto não for modificado, conforme mostrado no exemplo a seguir:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#188](../atl-mfc-shared/codesnippet/cpp/cstring-semantics_1.cpp)]  
  
 Observe no exemplo que os dois `CString` objetos são considerados "equal", porque eles representam a mesma cadeia de caracteres. O `CString` classe sobrecarrega o operador de igualdade (`==`) para comparar dois `CString` objetos com base em seu valor (conteúdo) em vez de sua identidade (endereço).  
  
## <a name="see-also"></a>Consulte também  
 [Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)

