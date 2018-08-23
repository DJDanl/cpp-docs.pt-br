---
title: Classe CriticalSection | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::CriticalSection
dev_langs:
- C++
helpviewer_keywords:
- CriticalSection class
ms.assetid: f2e0a024-71a3-4f6b-99ea-d93a4a608ac4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: cab1beeaa3ce54899d1a052e4972bd7e7f52bb57
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42592443"
---
# <a name="criticalsection-class"></a>Classe CriticalSection

Representa um objeto de seção crítica.

## <a name="syntax"></a>Sintaxe

```cpp
class CriticalSection;
```

## <a name="members"></a>Membros

### <a name="constructor"></a>Construtor

|Nome|Descrição|
|----------|-----------------|
|[Construtor CriticalSection::CriticalSection](../windows/criticalsection-criticalsection-constructor.md)|Inicializa um objeto de sincronização que é semelhante a um objeto de mutex, mas pode ser usado por apenas os threads de um único processo.|
|[Destruidor CriticalSection::~CriticalSection](../windows/criticalsection-tilde-criticalsection-destructor.md)|Realiza o desligamento e destrói o atual **CriticalSection** objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Método CriticalSection::TryLock](../windows/criticalsection-trylock-method.md)|Tenta inserir uma seção crítica sem bloqueio. Se a chamada for bem-sucedida, o thread de chamada se apropria de seção crítica.|
|[Método CriticalSection::Lock](../windows/criticalsection-lock-method.md)|Aguarda até que propriedade do objeto especificado de seção crítica. A função retorna quando o thread de chamada é concedido a propriedade.|
|[Método CriticalSection::IsValid](../windows/criticalsection-isvalid-method.md)|Indica se a seção crítica atual é válida.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[Membro de dados CriticalSection::cs_](../windows/criticalsection-cs-data-member.md)|Declara um membro de dados da seção crítica.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CriticalSection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)