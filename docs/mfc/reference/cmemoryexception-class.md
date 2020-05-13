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
ms.openlocfilehash: 375b4227a25ae4c18cfd263eff4c3ec13f1304e1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370004"
---
# <a name="cmemoryexception-class"></a>Classe CMemoryException

Representa uma condição de exceção fora da memória.

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

Nenhuma qualificação adicional é necessária ou possível. As exceções de memória são lançadas automaticamente por **novos**. Se você escrever suas próprias `malloc`funções de memória, usando , por exemplo, então você é responsável por lançar exceções de memória.

Para obter `CMemoryException`mais informações, consulte o artigo [Manipulação de Exceções (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cexception](../../mfc/reference/cexception-class.md)

[Csimpleexception](../../mfc/reference/csimpleexception-class.md)

`CMemoryException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="cmemoryexceptioncmemoryexception"></a><a name="cmemoryexception"></a>CMemoryException::CMemoryException

Constrói um objeto `CMemoryException`.

```
CMemoryException();
```

### <a name="remarks"></a>Comentários

Não use este construtor diretamente, mas sim chame a função global [AfxThrowMemoryException](exception-processing.md#afxthrowmemoryexception). esta função global pode ter sucesso em uma situação fora da memória porque constrói o objeto de exceção na memória previamente alocada. para obter mais informações sobre o processamento de exceções, consulte as [exceções](../exception-handling-in-mfc.md)do artigo .

## <a name="see-also"></a>Confira também

[Classe CException](cexception-class.md)<br/>
[Gráfico da hierarquia](../hierarchy-chart.md)
