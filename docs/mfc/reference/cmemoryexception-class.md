---
title: Classe CMemoryException
ms.date: 11/04/2016
f1_keywords:
- CMemoryException
- AFX/CMemoryException
- AFX/CMemoryException::CMemoryException
helpviewer_keywords:
- CMemoryException [MFC], CMemoryException
ms.assetid: 9af0ed57-d12a-45ca-82b5-c910a60f7edf
ms.openlocfilehash: e4a399ffb4c0d2161479ed7c84e66eb58a9260ab
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50552835"
---
# <a name="cmemoryexception-class"></a>Classe CMemoryException

Representa uma condição de exceção de falta de memória.

## <a name="syntax"></a>Sintaxe

```
class CMemoryException : public CSimpleException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMemoryException::CMemoryException](#cmemoryexception)|Constrói um objeto `CMemoryException`.|

## <a name="remarks"></a>Comentários

Sem qualificação adicional é necessário ou possíveis. Exceções de memória são geradas automaticamente pelo **novo**. Se você escrever suas próprias funções de memória, usando `malloc`, por exemplo, você é responsável por gerar exceções de memória.

Para obter mais informações sobre `CMemoryException`, consulte o artigo [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

[CSimpleException](../../mfc/reference/csimpleexception-class.md)

`CMemoryException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="cmemoryexception"></a>  CMemoryException::CMemoryException

Constrói um objeto `CMemoryException`.

```
CMemoryException();
```

### <a name="remarks"></a>Comentários

Não use esse construtor diretamente, mas em vez disso, chame a função global [AfxThrowMemoryException](exception-processing.md#afxthrowmemoryexception). Essa função global pode ter êxito em uma situação de falta de memória, pois ele constrói o objeto de exceção de memória alocado anteriormente. Para obter mais informações sobre o processamento de exceção, consulte o artigo [exceções](../exception-handling-in-mfc.md).

## <a name="see-also"></a>Consulte também

[Classe CException](cexception-class.md)<br/>
[Gráfico da hierarquia](../hierarchy-chart.md)

