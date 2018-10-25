---
title: Classe CNotSupportedException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CNotSupportedException
- AFX/CNotSupportedException
- AFX/CNotSupportedException::CNotSupportedException
dev_langs:
- C++
helpviewer_keywords:
- CNotSupportedException [MFC], CNotSupportedException
ms.assetid: e517391b-eb94-4c39-ae32-87b45bf7d624
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b52151dba90c0cfd0ed834e2ef351838d598eb90
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50068796"
---
# <a name="cnotsupportedexception-class"></a>Classe CNotSupportedException

Representa uma exceção que é o resultado de uma solicitação para um recurso sem suporte.

## <a name="syntax"></a>Sintaxe

```
class CNotSupportedException : public CSimpleException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

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

