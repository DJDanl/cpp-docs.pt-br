---
title: Operador IInspectable * * Comptrrefbase | Microsoft Docs
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
ms.openlocfilehash: e337f6bbc92718c839fc2bd12c9df9f0caa5d5aa
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33883453"
---
# <a name="comptrrefbaseoperator-iinspectable-operator"></a>ComPtrRefBase::operator Operador IInspectable**

Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.

## <a name="syntax"></a>Sintaxe

```cpp
operator IInspectable**() const;
```

## <a name="remarks"></a>Comentários

Converte atual [PTR _](../windows/comptrrefbase-ptr-data-member.md) membro de dados para um ponteiro-para-um-ponteiro-para a interface IInspectable.

Um erro é emitido se o ComPtrRefBase atual não deriva de IInspectable.

Essa conversão está disponível somente se **&#95; &#95;WRL_CLASSIC_COM&#95; &#95;** está definido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Classe ComPtrRefBase](../windows/comptrrefbase-class.md)   
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)