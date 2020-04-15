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
ms.openlocfilehash: b859b939baef018e69b245e597eea90e608253ca
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363188"
---
# <a name="cnotsupportedexception-class"></a>Classe CNotSupportedException

Representa uma exceção que é o resultado de uma solicitação de um recurso não suportado.

## <a name="syntax"></a>Sintaxe

```
class CNotSupportedException : public CSimpleException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CNot'edException:CNot's'SaoExceto](#cnotsupportedexception)|Constrói um objeto `CNotSupportedException`.|

## <a name="remarks"></a>Comentários

Nenhuma qualificação adicional é necessária ou possível.

Para obter mais `CNotSupportedException`informações sobre o uso, consulte o artigo [Manipulação de Exceções (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cexception](../../mfc/reference/cexception-class.md)

[Csimpleexception](../../mfc/reference/csimpleexception-class.md)

`CNotSupportedException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="cnotsupportedexceptioncnotsupportedexception"></a><a name="cnotsupportedexception"></a>CNot'edException:CNot's'SaoExceto

Constrói um objeto `CNotSupportedException`.

```
CNotSupportedException();
```

### <a name="remarks"></a>Comentários

Não use este construtor diretamente, mas chame a função global [AfxThrowNotSupportedException](exception-processing.md#afxthrownotsupportedexception). para obter mais informações sobre o processamento de exceções, consulte o artigo [Manipulação de Exceções no MFC](../exception-handling-in-mfc.md).

## <a name="see-also"></a>Confira também

[Classe CException](cexception-class.md)<br/>
[Gráfico da hierarquia](../hierarchy-chart.md)
