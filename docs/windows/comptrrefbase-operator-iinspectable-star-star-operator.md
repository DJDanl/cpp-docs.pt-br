---
title: 'Comptrrefbase:: Operator IInspectable * * operador | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::Details::ComPtrRefBase::operator IInspectable**
dev_langs:
- C++
helpviewer_keywords:
- operator IInspectable** operator
ms.assetid: 06ac1051-606c-449b-a566-cac78ca53762
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c27a1957ff6198ea68893dd9bb92f4e60b70e4f9
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46372334"
---
# <a name="comptrrefbaseoperator-iinspectable-operator"></a>Comptrrefbase:: Operator IInspectable\* \* operador

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
operator IInspectable**() const;
```

## <a name="remarks"></a>Comentários

Converte o atual [PTR _](../windows/comptrrefbase-ptr-data-member.md) membro de dados para um ponteiro-para-um-ponteiro-para o `IInspectable` interface.

Um erro será emitido se o atual **ComPtrRefBase** não deriva de `IInspectable`.

Essa conversão está disponível somente se `__WRL_CLASSIC_COM__` está definido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Classe ComPtrRefBase](../windows/comptrrefbase-class.md)<br/>
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)