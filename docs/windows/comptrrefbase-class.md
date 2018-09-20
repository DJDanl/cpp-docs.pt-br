---
title: Classe ComPtrRefBase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::Details::ComPtrRefBase
dev_langs:
- C++
helpviewer_keywords:
- ComPtrRefBase class
ms.assetid: 6d344c1a-cc13-4a3f-8a0d-f167ccb9348f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3ca2cb8cdc748abcac61bd548491187095b71a3f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46415311"
---
# <a name="comptrrefbase-class"></a>Classe ComPtrRefBase

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   typename T
>
class ComPtrRefBase;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Um [ComPtr\<T >](../windows/comptr-class.md) tipo ou um tipo derivado dele, não simplesmente a interface representada pelo **ComPtr**.

## <a name="remarks"></a>Comentários

Representa a classe base para o [ComPtrRef](../windows/comptrref-class.md) classe.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`InterfaceType`|Um sinônimo para o tipo de parâmetro de modelo *T*.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador ComPtrRefBase::operator IInspectable**](../windows/comptrrefbase-operator-iinspectable-star-star-operator.md)|Converte o atual [PTR _](../windows/comptrrefbase-ptr-data-member.md) membro de dados para um ponteiro-para-um-ponteiro-para o `IInspectable` interface.|
|[Operador ComPtrRefBase::operator IUnknown**](../windows/comptrrefbase-operator-iunknown-star-star-operator.md)|Converte o atual [PTR _](../windows/comptrrefbase-ptr-data-member.md) membro de dados para um ponteiro-para-um-ponteiro-para o `IUnknown` interface.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[Membro de dados ComPtrRefBase::ptr_](../windows/comptrrefbase-ptr-data-member.md)|Ponteiro para o tipo especificado pelo parâmetro de modelo atual.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ComPtrRefBase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)