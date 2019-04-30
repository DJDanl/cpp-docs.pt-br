---
title: Classe CNotSupportedException
ms.date: 11/04/2016
f1_keywords:
- CNotSupportedException
- AFX/CNotSupportedException
- AFX/CNotSupportedException::CNotSupportedException
helpviewer_keywords:
- CNotSupportedException [MFC], CNotSupportedException
ms.assetid: e517391b-eb94-4c39-ae32-87b45bf7d624
ms.openlocfilehash: c3af508cd39e277ca4ae0a9aad5e639f66edc53b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62407920"
---
# <a name="cnotsupportedexception-class"></a>Classe CNotSupportedException

Representa uma exceção que é o resultado de uma solicitação para um recurso sem suporte.

## <a name="syntax"></a>Sintaxe

```
class CNotSupportedException : public CSimpleException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CNotSupportedException::CNotSupportedException](#cnotsupportedexception)|Constrói um objeto `CNotSupportedException`.|

## <a name="remarks"></a>Comentários

Sem qualificação adicional é necessário ou possíveis.

Para obter mais informações sobre como usar `CNotSupportedException`, consulte o artigo [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

[CSimpleException](../../mfc/reference/csimpleexception-class.md)

`CNotSupportedException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="cnotsupportedexception"></a>  CNotSupportedException::CNotSupportedException

Constrói um objeto `CNotSupportedException`.

```
CNotSupportedException();
```

### <a name="remarks"></a>Comentários

Não use esse construtor diretamente, mas em vez disso, chame a função global [AfxThrowNotSupportedException](exception-processing.md#afxthrownotsupportedexception). Para obter mais informações sobre o processamento de exceção, consulte o artigo [tratamento de exceções em MFC](../exception-handling-in-mfc.md).

## <a name="see-also"></a>Consulte também

[Classe CException](cexception-class.md)<br/>
[Gráfico da hierarquia](../hierarchy-chart.md)
