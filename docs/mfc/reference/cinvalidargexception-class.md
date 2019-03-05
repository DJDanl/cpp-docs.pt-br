---
title: Classe CInvalidArgException
ms.date: 11/04/2016
f1_keywords:
- CInvalidArgException
- AFX/CInvalidArgException
- AFX/CInvalidArgException::CInvalidArgException
helpviewer_keywords:
- CInvalidArgException [MFC], CInvalidArgException
ms.assetid: e43d7c67-1157-47f8-817a-804083e8186e
ms.openlocfilehash: d2df9b482fe95ad0a13a85a51037a4cbbc28d057
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57260186"
---
# <a name="cinvalidargexception-class"></a>Classe CInvalidArgException

Essa classe representa uma condição de exceção de argumento inválido.

## <a name="syntax"></a>Sintaxe

```
class CInvalidArgException : public CSimpleException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CInvalidArgException::CInvalidArgException](#cinvalidargexception)|O construtor.|

## <a name="remarks"></a>Comentários

Um `CInvalidArgException` objeto representa uma condição de exceção de argumento inválido.

Para obter mais informações sobre o tratamento de exceção, consulte o [classe CException](../../mfc/reference/cexception-class.md) tópico e [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

[CSimpleException](../../mfc/reference/csimpleexception-class.md)

`CInvalidArgException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="cinvalidargexception"></a>  CInvalidArgException::CInvalidArgException

O construtor.

```
CInvalidArgException();
```

### <a name="remarks"></a>Comentários

Não use esse construtor diretamente. Chame a função global **AfxThrowInvalidArgException**.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CSimpleException](../../mfc/reference/csimpleexception-class.md)
