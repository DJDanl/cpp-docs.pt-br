---
title: Classe de CPtrList | Microsoft Docs
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
ms.openlocfilehash: 97eeeaaa2eea237eebda4f945f2c810268f406cd
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46384956"
---
# <a name="cptrlist-class"></a>Classe de CPtrList

Dá suporte a listas de ponteiros nulos.

## <a name="syntax"></a>Sintaxe

```
class CPtrList : public CObject
```

## <a name="members"></a>Membros

As funções membro da `CPtrList` são semelhantes às funções de membro da classe [CObList](../../mfc/reference/coblist-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObList` para obter a função específica de membro. Onde quer que você vê uma `CObject` ponteiro como um parâmetro de função ou um valor de retorno, substitua um ponteiro para **void**.

`CObject*& CObList::GetHead() const;`

por exemplo, traduz para

`void*& CPtrList::GetHead() const;`

## <a name="remarks"></a>Comentários

`CPtrList` incorpora a macro IMPLEMENT_DYNAMIC para dar suporte a acesso de tipo de tempo de execução e despejo para um `CDumpContext` objeto. Se você precisar de um despejo de elementos de lista de ponteiro individual, você deve definir a profundidade do contexto de despejo para 1 ou maior.

Listas de ponteiro não podem ser serializadas.

Quando um `CPtrList` objeto é excluído, ou quando seus elementos são removidos, somente os ponteiros são removidos, não as entidades que fazem referência.

Para obter mais informações sobre como usar `CPtrList`, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CPtrList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** & amp;lt;1}afxcoll.h

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CObList](../../mfc/reference/coblist-class.md)
