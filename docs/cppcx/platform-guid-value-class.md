---
title: 'Classe de valor Platform:: GUID | Microsoft Docs'
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Guid
dev_langs:
- C++
helpviewer_keywords:
- Platform::Guid Struct
ms.assetid: 25c0bfb2-7f93-44d8-bdf4-ef4fbac3424a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b09fe303cb69cb36d04d696af2b83b30b8378f70
ms.sourcegitcommit: 3a141cf07b5411d5f1fdf6cf67c4ce928cf389c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/11/2018
ms.locfileid: "49083444"
---
# <a name="platformguid-value-class"></a>Platform::classe de valor Guid

Representa um tipo de [GUID](https://msdn.microsoft.com/library/windows/desktop/aa373931) no sistema de tipos do Tempo de Execução do Windows.

## <a name="syntax"></a>Sintaxe

```cpp
public value struct Guid
```

### <a name="members"></a>Membros

O Guid possui os métodos Equals(), GetHashCode() e ToString() derivados da [Platform::Object Class](../cppcx/platform-object-class.md)e o método GetTypeCode() derivado da [Platform::Type Class](../cppcx/platform-type-class.md). Guid também tem os seguintes membros:

|Membro|Descrição|
|------------|-----------------|
|[Guid](#ctor)|Inicializa uma nova instância da estrutura Guid.|
|[operator==](#operator-equality)|Operador de igualdade.|
|[operator!=](#operator-not-equal)|Operador de diferença.|
|[operator()](#operator-call)|Converte um Guid em GUID.|

### <a name="remarks"></a>Comentários

Para ver um exemplo de como gerar um novo Platform::Guid, usando a função do Windows [CoCreateGuid](/windows/desktop/api/combaseapi/nf-combaseapi-cocreateguid), consulte [WinRT component: How to generate a GUID? (Componente WinRT: como gerar um GUID?)](http://blogs.msdn.com/b/eternalcoding/archive/2013/03/25/winrt-component-how-to-generate-a-guid.aspx)

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Platform

**Metadados:** platform.winmd

## <a name="ctor"></a> Construtores GUID:: GUID

Inicializa uma nova instância de uma estrutura Guid.

### <a name="syntax"></a>Sintaxe

```cpp
Guid(
    unsigned int a,
    unsigned short b,
    unsigned short c,
    unsigned char d,
    unsigned char e,
    unsigned char f,
    unsigned char g,
    unsigned char h,
    unsigned char i,
    unsigned char j,
    unsigned char k );

Guid(GUID m);

Guid(
    unsigned int a,
    unsigned short b,
    unsigned short c,
    Array<unsigned char>^ n );
```

### <a name="parameters"></a>Parâmetros

*a*<br/>
Os primeiros 4 bytes de GUID.

*b*<br/>
Os 2 bytes seguintes de GUID.

*c*<br/>
Os 2 bytes seguintes de GUID.

*d*<br/>
O byte seguinte de GUID.

*e*<br/>
O byte seguinte de GUID.

*f*<br/>
O byte seguinte de GUID.

*g*<br/>
O byte seguinte de GUID.

*h*<br/>
O byte seguinte de GUID.

*i*<br/>
O byte seguinte de GUID.

*j*<br/>
O byte seguinte de GUID.

*k*<br/>
O byte seguinte de GUID.

*m*<br/>
Um GUID como definido.

*n*<br/>
Os 8 bytes restantes de GUID.

## <a name="operator-equality"></a> GUID::Operator Operator = =

Compara dois guids.

### <a name="syntax"></a>Sintaxe

```cpp
Platform::Guid::operator==
```

### <a name="return-value"></a>Valor de retorno

True se dois guids forem iguais.

## <a name="operator-inequality"></a> GUID::Operator! = operador

Compara dois guids.

### <a name="syntax"></a>Sintaxe

```cpp
Platform::Guid::operator!=
```

### <a name="return-value"></a>Valor de retorno

True se dois guids não são iguais.

## <a name="operator-call"></a> Operador GUID

Converte implicitamente um [estrutura de GUID](https://msdn.microsoft.com/library/windows/desktop/aa373931)GUID para um Platform:: GUID.

### <a name="syntax"></a>Sintaxe

```cpp
Platform::Guid operator();
```

### <a name="return-value"></a>Valor de retorno

Uma estrutura de GUID.

## <a name="see-also"></a>Consulte também

[Namespace Platform](../cppcx/platform-namespace-c-cx.md)