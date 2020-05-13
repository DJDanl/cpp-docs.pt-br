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
ms.openlocfilehash: 557bfe1cc41c3dda65bd95d7d687820c0b9862b7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368325"
---
# <a name="cresourceexception-class"></a>Classe CResourceException

Gerado quando o Windows não pode encontrar ou alocar um recurso solicitado.

## <a name="syntax"></a>Sintaxe

```
class CResourceException : public CSimpleException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CResourceException::CResourceException](#cresourceexception)|Constrói um objeto `CResourceException`.|

## <a name="remarks"></a>Comentários

Nenhuma qualificação adicional é necessária ou possível.

Para obter mais `CResourceException`informações sobre o uso, consulte o artigo [Manipulação de Exceções (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cexception](../../mfc/reference/cexception-class.md)

[Csimpleexception](../../mfc/reference/csimpleexception-class.md)

`CResourceException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cresourceexceptioncresourceexception"></a><a name="cresourceexception"></a>CResourceException::CResourceException

Constrói um objeto `CResourceException`.

```
CResourceException();
```

### <a name="remarks"></a>Comentários

Não use este construtor diretamente, mas chame a função global [AfxThrowResourceException](exception-processing.md#afxthrowresourceexception). para obter mais informações sobre exceções, consulte o artigo [Manipulação de Exceções em MFC](../exception-handling-in-mfc.md).

## <a name="see-also"></a>Confira também

[Classe CException](cexception-class.md)<br/>
[Gráfico da hierarquia](../hierarchy-chart.md)
