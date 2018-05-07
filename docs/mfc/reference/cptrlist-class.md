---
title: Classe CPtrList | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CPtrList
dev_langs:
- C++
helpviewer_keywords:
- lists, generic
- CPtrList class [MFC]
- generic lists
ms.assetid: 4139a09c-4338-4f42-9eea-51336120b43c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1a143fd99a79212ed0078f06b334ab6ae0964b3f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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
 `CPtrList` incorpora o `IMPLEMENT_DYNAMIC` macro para dar suporte ao acesso de tipo de tempo de execução e despejo para um `CDumpContext` objeto. Se você precisar de um despejo de elementos da lista de ponteiro individual, você deve definir a profundidade do contexto de despejo para 1 ou superior.  
  
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
