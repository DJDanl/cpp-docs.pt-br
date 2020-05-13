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
ms.openlocfilehash: b28b6e84043b85a8117694a67ff5fff13e7c786b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372369"
---
# <a name="cinvalidargexception-class"></a>Classe CInvalidArgException

Esta classe representa uma condição de exceção de argumento inválida.

## <a name="syntax"></a>Sintaxe

```
class CInvalidArgException : public CSimpleException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CInvalidArgException::CInvalidArgException](#cinvalidargexception)|O construtor.|

## <a name="remarks"></a>Comentários

Um `CInvalidArgException` objeto representa uma condição de exceção de argumento inválida.

Para obter mais informações sobre o tratamento de exceções, consulte o tópico [CException Class](../../mfc/reference/cexception-class.md) e [o MFC (Exception Handling)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cexception](../../mfc/reference/cexception-class.md)

[Csimpleexception](../../mfc/reference/csimpleexception-class.md)

`CInvalidArgException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="cinvalidargexceptioncinvalidargexception"></a><a name="cinvalidargexception"></a>CInvalidArgException::CInvalidArgException

O construtor.

```
CInvalidArgException();
```

### <a name="remarks"></a>Comentários

Não utilize este construtor diretamente; chamar a função global **AfxThrowInvalidArgException**.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CSimpleException](../../mfc/reference/csimpleexception-class.md)
