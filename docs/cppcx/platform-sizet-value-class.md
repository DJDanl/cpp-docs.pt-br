---
title: Platform::classe de valor SizeT
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/PlatformSizeT::SizeT constructor
helpviewer_keywords:
- Platform::SizeT Struct
ms.assetid: 0803612c-8ba1-430c-9b7b-1bebae88608d
ms.openlocfilehash: 7f81cb9e1fc2ef7a74cb3878c369e4d7d14e3d90
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62330104"
---
# <a name="platformsizet-value-class"></a>Platform::classe de valor SizeT

Representa o tamanho de um objeto. SizeT é um tipo de dados sem sinal.

## <a name="syntax"></a>Sintaxe

```cpp
public ref class SizeT sealed : ValueType
```

### <a name="members"></a>Membros

|Membro|Descrição|
|------------|-----------------|
|[Construtor SizeT::SizeT](#ctor)|Inicializa uma nova instância da classe com o valor especificado.|

### <a name="requirements"></a>Requisitos

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Plataforma

**Metadados:** platform.winmd

## <a name="ctor"></a>  Construtor sizet:: Sizet

Inicializa uma nova instância de SizeT com o valor especificado.

### <a name="syntax"></a>Sintaxe

```cpp
SizeT( uint32 value1 );   SizeT( void* value2 );
```

### <a name="parameters"></a>Parâmetros

*value1*<br/>
Um valor de 32 bits sem sinal.

*value2*<br/>
Ponteiro para um valor de 32 bits sem sinal.

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
