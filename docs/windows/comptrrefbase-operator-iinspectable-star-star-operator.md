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
ms.openlocfilehash: 19e04f5415f9f7a736371c888dff7559df6c6c66
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39462330"
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

Essa conversão está disponível somente se **&#95; &#95;WRL_CLASSIC_COM&#95; &#95;** está definido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também
[Classe ComPtrRefBase](../windows/comptrrefbase-class.md)   
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)