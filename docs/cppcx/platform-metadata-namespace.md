---
title: Namespace Platform::Metadata
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Metadata
helpviewer_keywords:
- Platform::Metadata Namespace
ms.assetid: e3e114d8-a4b0-47f0-865a-9ce9d7212e86
ms.openlocfilehash: 9626b3a9d28d28fd52a0d2295af8fda8855cd90c
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57739458"
---
# <a name="platformmetadata-namespace"></a>Namespace Platform::Metadata

Este namespace contém atributos que modificam as declarações de tipos.

## <a name="syntax"></a>Sintaxe

```cpp
namespace Platform {
   namespace Metadata {
}}
```

### <a name="members"></a>Membros

Embora esse namespace seja destinado ao uso interno, os navegadores podem exibir os seguintes membros desse namespace.

|Nome|Remark|
|----------|------------|
|Atributo|A classe base para atributos.|
|[Atributo Platform::Metadata::DefaultMemberAttribute](../cppcx/platform-metadata-defaultmemberattribute-attribute.md)|Indica a função preferencial a ser invocada dentre várias funções sobrecarregadas possíveis.|
|[Platform::Metadata::FlagsAttribute Attribute](../cppcx/platform-metadata-flagsattribute-attribute.md)Flags|Declara uma enumeração como uma enumeração de campos de bits.<br /><br /> O exemplo a seguir mostra como aplicar uma enumeração a um atributo `Flags` .<br /><br /> `[Flags] enum class MyEnumeration { enumA = 1, enumB = 2, enumC = 3}`|
|[Platform::Metadata::RuntimeClassNameAttribute](../cppcx/platform-metadata-runtimeclassname.md)|Garante que uma classe ref privada tenha um nome de classe de tempo de execução válido.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Platform`

### <a name="requirements"></a>Requisitos

**Metadados:** platform.winmd

**Namespace:** Platform:: Metadata

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](platform-namespace-c-cx.md)
