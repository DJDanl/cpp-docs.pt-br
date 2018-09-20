---
title: Classe CInvalidArgException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CInvalidArgException
- AFX/CInvalidArgException
- AFX/CInvalidArgException::CInvalidArgException
dev_langs:
- C++
helpviewer_keywords:
- CInvalidArgException [MFC], CInvalidArgException
ms.assetid: e43d7c67-1157-47f8-817a-804083e8186e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cff0727f1d194982ad76d24b0a91875448ea45c0
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46389786"
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
