---
title: Classe CResourceException
ms.date: 11/04/2016
f1_keywords:
- CResourceException
- AFXWIN/CResourceException
- AFXWIN/CResourceException::CResourceException
helpviewer_keywords:
- CResourceException [MFC], CResourceException
ms.assetid: af6ae043-d124-4bfd-b35e-7bb0db67d289
ms.openlocfilehash: aa7fd6e2caa15a256cec2eae5ede6c6e47cd1518
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50632669"
---
# <a name="cresourceexception-class"></a>Classe CResourceException

Gerado quando o Windows não podem localizar ou alocar um recurso solicitado.

## <a name="syntax"></a>Sintaxe

```
class CResourceException : public CSimpleException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CResourceException::CResourceException](#cresourceexception)|Constrói um objeto `CResourceException`.|

## <a name="remarks"></a>Comentários

Sem qualificação adicional é necessário ou possíveis.

Para obter mais informações sobre como usar `CResourceException`, consulte o artigo [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

[CSimpleException](../../mfc/reference/csimpleexception-class.md)

`CResourceException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="cresourceexception"></a>  CResourceException::CResourceException

Constrói um objeto `CResourceException`.

```
CResourceException();
```

### <a name="remarks"></a>Comentários

Não use esse construtor diretamente, mas em vez disso, chame a função global [AfxThrowResourceException](exception-processing.md#afxthrowresourceexception). Para obter mais informações sobre exceções, consulte o artigo [tratamento de exceções em MFC](../exception-handling-in-mfc.md).

## <a name="see-also"></a>Consulte também

[Classe CException](cexception-class.md)<br/>
[Gráfico da hierarquia](../hierarchy-chart.md)

