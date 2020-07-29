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
ms.openlocfilehash: 71b17e777db9d6351192da7cffd075b3a64553bd
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222921"
---
# <a name="cmemoryexception-class"></a>Classe CMemoryException

Representa uma condição de exceção de memória insuficiente.

## <a name="syntax"></a>Sintaxe

```
class CMemoryException : public CSimpleException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMemoryException::CMemoryException](#cmemoryexception)|Constrói um objeto `CMemoryException`.|

## <a name="remarks"></a>Comentários

Nenhuma qualificação adicional é necessária ou possível. As exceções de memória são lançadas automaticamente pelo **`new`** . Se você escrever suas próprias funções de memória, usando `malloc` , por exemplo, você será responsável por lançar exceções de memória.

Para obter mais informações sobre `CMemoryException` o, consulte o artigo [tratamento de exceções (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

[CSimpleException](../../mfc/reference/csimpleexception-class.md)

`CMemoryException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="cmemoryexceptioncmemoryexception"></a><a name="cmemoryexception"></a>CMemoryException::CMemoryException

Constrói um objeto `CMemoryException`.

```
CMemoryException();
```

### <a name="remarks"></a>Comentários

Não use esse construtor diretamente, mas, em vez disso, chame a função global [AfxThrowMemoryException](exception-processing.md#afxthrowmemoryexception). Essa função global pode ser realizada com sucesso em uma situação de memória insuficiente porque ela constrói o objeto de exceção na memória alocada anteriormente. para obter mais informações sobre o processamento de exceções, consulte o artigo [Exceptions](../exception-handling-in-mfc.md).

## <a name="see-also"></a>Confira também

[Classe CException](cexception-class.md)<br/>
[Gráfico de hierarquia](../hierarchy-chart.md)
