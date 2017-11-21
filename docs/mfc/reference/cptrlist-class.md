---
title: Classe CPtrList | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: CPtrList
dev_langs: C++
helpviewer_keywords:
- lists, generic
- CPtrList class [MFC]
- generic lists
ms.assetid: 4139a09c-4338-4f42-9eea-51336120b43c
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: c9a7d32e202c7184ecbf974dc095c223686d6dff
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cptrlist-class"></a>Classe CPtrList
Oferece suporte a listas de ponteiros void.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPtrList : public CObject  
```  
  
## <a name="members"></a>Membros  
 As funções de membro de `CPtrList` são semelhantes às funções de membro da classe [CObList](../../mfc/reference/coblist-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObList` para obter a função específica de membro. Sempre que você vê um `CObject` ponteiro como um parâmetro de função ou o valor de retorno, substitua um ponteiro para `void`.  
  
 `CObject*& CObList::GetHead() const;`  
  
 por exemplo, traduz para  
  
 `void*& CPtrList::GetHead() const;`  
  
## <a name="remarks"></a>Comentários  
 `CPtrList`incorpora o `IMPLEMENT_DYNAMIC` macro para dar suporte ao acesso de tipo de tempo de execução e despejo para um `CDumpContext` objeto. Se você precisar de um despejo de elementos da lista de ponteiro individual, você deve definir a profundidade do contexto de despejo para 1 ou superior.  
  
 Listas de ponteiro não podem ser serializadas.  
  
 Quando um `CPtrList` objeto é excluído, ou quando seus elementos são removidos, somente os ponteiros são removidos, não as entidades que fazem referência.  
  
 Para obter mais informações sobre como usar `CPtrList`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CPtrList`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcoll.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CObList](../../mfc/reference/coblist-class.md)
