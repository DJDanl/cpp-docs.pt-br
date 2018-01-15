---
title: "Semântica de CString | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs: C++
helpviewer_keywords:
- semantics in Cstring
- CString objects, assignment semantics
- assignment statements, assigning CString objects
ms.assetid: d4023480-526f-499a-85f6-324b4de5b85f
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 394e459a46003e3f1baccff7dd4c76f40b73e354
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cstring-semantics"></a>Semântica de CString
Embora [CString](../atl-mfc-shared/reference/cstringt-class.md) objetos são objetos dinâmicos que podem crescer, eles atuam como classes simples e tipos primitivos internos. Cada `CString` objeto representa um valor exclusivo. `CString`objetos devem ser considerados como as cadeias de caracteres reais em vez de ponteiros para cadeias de caracteres.  
  
 Você pode atribuir uma **CString** objeto para outro. No entanto, quando você modificar um dos dois `CString` objetos, o outro `CString` objeto não é modificado, conforme mostrado pelo exemplo a seguir:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#188](../atl-mfc-shared/codesnippet/cpp/cstring-semantics_1.cpp)]  
  
 Observe que no exemplo que os dois `CString` objetos são considerados "iguais", porque eles representam a mesma cadeia de caracteres. O `CString` classe sobrecarrega o operador de igualdade (`==`) para comparar dois `CString` objetos com base em seu valor (conteúdo) em vez de sua identidade (endereço).  
  
## <a name="see-also"></a>Consulte também  
 [Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)

