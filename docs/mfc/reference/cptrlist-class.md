---
title: Classe CPtrList
ms.date: 11/04/2016
f1_keywords:
- CPtrList
helpviewer_keywords:
- lists, generic
- CPtrList class [MFC]
- generic lists
ms.assetid: 4139a09c-4338-4f42-9eea-51336120b43c
ms.openlocfilehash: d7da4fe52d25d9ffdf6371aa40f41d7082f1165c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226835"
---
# <a name="cptrlist-class"></a>Classe CPtrList

Dá suporte a listas de ponteiros void.

## <a name="syntax"></a>Sintaxe

```
class CPtrList : public CObject
```

## <a name="members"></a>Membros

As funções de membro do `CPtrList` são semelhantes às funções de membro da classe [CObList](../../mfc/reference/coblist-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObList` para obter a função específica de membro. Sempre que você vir um `CObject` ponteiro como um parâmetro de função ou valor de retorno, substitua um ponteiro para **`void`** .

`CObject*& CObList::GetHead() const;`

por exemplo, traduz para

`void*& CPtrList::GetHead() const;`

## <a name="remarks"></a>Comentários

`CPtrList`incorpora a macro IMPLEMENT_DYNAMIC para dar suporte ao acesso de tipo em tempo de execução e despejo a um `CDumpContext` objeto. Se você precisar de um despejo de elementos de lista de ponteiros individuais, deverá definir a profundidade do contexto de despejo como 1 ou maior.

As listas de ponteiros não podem ser serializadas.

Quando um `CPtrList` objeto é excluído ou quando seus elementos são removidos, somente os ponteiros são removidos, e não as entidades que eles referenciam.

Para obter mais informações sobre como usar `CPtrList` o, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CPtrList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll. h

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CObList](../../mfc/reference/coblist-class.md)
