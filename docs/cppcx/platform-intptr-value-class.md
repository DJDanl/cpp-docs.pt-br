---
title: Platform::classe de valor IntPtr
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/PlatformIntPtr::IntPtr
- VCCORLIB/PlatformIntPtr::op_explicit Operator
- VCCORLIB/PlatformIntPtr::ToInt32
helpviewer_keywords:
- Platform::IntPtr Struct
ms.assetid: 6c0326e8-edfd-4e53-a963-240b845dcde8
ms.openlocfilehash: 8101fa2c82a0ac3e3b573384d14d9a7eff6ecf61
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62152729"
---
# <a name="platformintptr-value-class"></a>Platform::classe de valor IntPtr

Representa um ponteiro ou um identificador assinado e cujo tamanho é específico de plataforma (32 bits ou 64 bits).

## <a name="syntax"></a>Sintaxe

```cpp
public value struct IntPtr
```

### <a name="members"></a>Membros

IntPtr tem os seguintes membros:

|Membro|Descrição|
|------------|-----------------|
|[IntPtr::IntPtr](#ctor)|Inicializa uma nova instância de IntPtr.|
|[Operador IntPtr::op_explicit](#op-explicit)|Converte o parâmetro especificado em um IntPtr ou um ponteiro para um valor de IntPtr.|
|[IntPtr::ToInt32](#toint32)|Converte o IntPtr atual em um número inteiro de 32 bits.|

### <a name="requirements"></a>Requisitos

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Plataforma

**Metadados:** platform.winmd

## <a name="ctor"> </a> Construtor IntPtr::IntPtr

Inicializa uma nova instância de um IntPtr com o valor especificado.

### <a name="syntax"></a>Sintaxe

```cpp
IntPtr( __int64 handle-or-pointer );   IntPtr( void* value );   IntPtr( int 32-bit_value );
```

### <a name="parameters"></a>Parâmetros

*value*<br/>
Um identificador ou um ponteiro de 64 bits ou um ponteiro para um valor de 64 bits ou um valor de 32 bits que pode ser convertido em um valor de 64 bits.

## <a name="op-explicit"> </a> Operador IntPtr::op_explicit

Converte o parâmetro especificado em um IntPtr ou um ponteiro para um valor de IntPtr.

### <a name="syntax"></a>Sintaxe

```cpp
static IntPtr::operator IntPtr( void* value1);   static IntPtr::operator IntPtr( int value2);   static IntPtr::operator void*( IntPtr value3 );
```

### <a name="parameters"></a>Parâmetros

*value1*<br/>
Um ponteiro para um identificador ou IntPtr.

*value2*<br/>
Um número inteiro de 32 bits que pode ser convertido em um IntPtr.

*value3*<br/>
Um IntPtr.

### <a name="return-value"></a>Valor de retorno

O primeiro e o segundo operadores retornam um IntPtr. O terceiro operador retorna um ponteiro para o valor representado pelo IntPtr atual.

## <a name="toint32"> </a> Método IntPtr::ToInt32

Converte o IntPtr atual em um valor para um inteiro de 32 bits.

### <a name="syntax"></a>Sintaxe

```cpp
int32 IntPtr::ToInt32();
```

### <a name="return-value"></a>Valor de retorno

Um inteiro de 32 bits.

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
