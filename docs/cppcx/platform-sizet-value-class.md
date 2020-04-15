---
title: Platform::classe de valor SizeT
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/PlatformSizeT::SizeT constructor
helpviewer_keywords:
- Platform::SizeT Struct
ms.assetid: 0803612c-8ba1-430c-9b7b-1bebae88608d
ms.openlocfilehash: 5add9212dc2655bc37cd357741073f855b009bde
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81322156"
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

**Namespace:** Platform

**Metadados:** platform.winmd

## <a name="sizetsizet-constructor"></a><a name="ctor"></a>TamanhoT::Construtor SizeT

Inicializa uma nova instância de SizeT com o valor especificado.

### <a name="syntax"></a>Sintaxe

```cpp
SizeT( uint32 value1 );   SizeT( void* value2 );
```

### <a name="parameters"></a>Parâmetros

*valor1*<br/>
Um valor de 32 bits sem sinal.

*valor2*<br/>
Ponteiro para um valor de 32 bits sem sinal.

## <a name="see-also"></a>Confira também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
