---
title: Platform::classe de valor Guid
ms.date: 01/15/2019
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Guid
helpviewer_keywords:
- Platform::Guid Struct
ms.assetid: 25c0bfb2-7f93-44d8-bdf4-ef4fbac3424a
ms.openlocfilehash: 7c3b89ff238b1cb5ee9fbb71e83d20f571e656a3
ms.sourcegitcommit: 89d9e1cb08fa872483d1cde98bc2a7c870e505e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "82031531"
---
# <a name="platformguid-value-class"></a>Platform::classe de valor Guid

Representa um tipo [GUID](/windows/win32/api/guiddef/ns-guiddef-guiddef-guidno no sistema do tipo Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
public value struct Guid
```

### <a name="members"></a>Membros

`Platform::Guid`tem `Equals()`os `GetHashCode()`métodos e `ToString()` métodos derivados da [Plataforma::Classe de Objetos](../cppcx/platform-object-class.md)e do `GetTypeCode()` método derivado da [Plataforma::Tipo Classe](../cppcx/platform-type-class.md). `Platform::Guid`também tem os seguintes membros.

|Membro|Descrição|
|------------|-----------------|
|[Guid](#ctor)|Inicializa uma nova instância de um `Platform::Guid`.|
|[operador==](#operator-equality)|Operador Equals.|
|[operador!=](#operator-inequality)|Operador not equals.|
|[Operador&lt;](#operator-less)|Operador less than.|
|[operador()](#operator-call)|Converte uma `Platform::Guid` em uma `GUID`.|

### <a name="remarks"></a>Comentários

Para gerar `Platform::Guid`um novo, use o [Windows::Foundation::GuidHelper::CreateNewGuid](/uwp/api/windows.foundation.guidhelper.createnewguid) método estático.

### <a name="requirements"></a>Requisitos

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Platform

**Metadados:** platform.winmd

## <a name="guidguid-constructors"></a><a name="ctor"></a>Guid::Construções Orientais

Inicializa uma nova instância de um `Platform::Guid`.

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

*Um*<br/>
Os primeiros 4 bytes do `GUID`.

*B*<br/>
Os próximos dois bytes do `GUID`.

*C*<br/>
Os próximos dois bytes do `GUID`.

*D*<br/>
O próximo byte do `GUID`.

*e*<br/>
O próximo byte do `GUID`.

*F*<br/>
O próximo byte do `GUID`.

*G*<br/>
O próximo byte do `GUID`.

*H*<br/>
O próximo byte do `GUID`.

*Eu*<br/>
O próximo byte do `GUID`.

*J*<br/>
O próximo byte do `GUID`.

*K*<br/>
O próximo byte do `GUID`.

*M*<br/>
A `GUID` na forma de uma [estrutura GUID](/windows/win32/api/guiddef/ns-guiddef-guid).

*n*<br/>
Os 8 bytes `GUID`restantes do .

## <a name="guidoperator-operator"></a><a name="operator-equality"></a>Guia::operador== Operador

Compara duas instâncias de `Platform::Guid` quanto à igualdade.

### <a name="syntax"></a>Sintaxe

```cpp
static bool Platform::Guid::operator==(Platform::Guid guid1, Platform::Guid guid2);
```

### <a name="parameters"></a>Parâmetros

*guid1*<br/>
O primeiro `Platform::Guid` a ser comparado.

*guid2*<br/>
O segundo `Platform::Guid` a ser comparado.

### <a name="return-value"></a>Valor retornado

Verdade se `Platform::Guid` as duas instâncias são iguais.

### <a name="remarks"></a>Comentários

Prefira `==` usar o operador em vez do [Windows::Foundation::GuidHelper::Iguala método estático.](/uwp/api/windows.foundation.guidhelper.equals)

## <a name="guidoperator-operator"></a><a name="operator-inequality"></a>Guia::operador!= Operador

Compara a desigualdade de duas instâncias `Platform::Guid`.

### <a name="syntax"></a>Sintaxe

```cpp
static bool Platform::Guid::operator!=(Platform::Guid guid1, Platform::Guid guid2);
```

### <a name="parameters"></a>Parâmetros

*guid1*<br/>
O primeiro `Platform::Guid` a ser comparado.

*guid2*<br/>
O segundo `Platform::Guid` a ser comparado.

### <a name="return-value"></a>Valor retornado

Verdade se `Platform::Guid` as duas instâncias não forem iguais.

## <a name="guidoperatorlt-operator"></a><a name="operator-less"></a>Guia::Operador&lt; operador

Compara `Platform::Guid` duas instâncias para encomendar.

### <a name="syntax"></a>Sintaxe

```cpp
static bool Platform::Guid::operator<(Platform::Guid guid1, Platform::Guid guid2);
```

### <a name="parameters"></a>Parâmetros

*guid1*<br/>
O primeiro `Platform::Guid` a ser comparado.

*guid2*<br/>
O segundo `Platform::Guid` a ser comparado.

### <a name="return-value"></a>Valor retornado

Verdade se *guid1* é ordenado antes *de guid2*. A ordem é lexicográfica `Platform::Guid` depois de tratar cada um como se fosse uma matriz de quatro valores não assinados de 32 bits. Este não é o pedido usado pelo SQL Server ou pelo .NET Framework, nem é o mesmo que o pedido lexicográfico por representação de strings.

Este operador é fornecido `Guid` para que os objetos possam ser mais facilmente consumidos pela biblioteca padrão C++.

## <a name="guidoperator-operator"></a><a name="operator-call"></a>Guid::operador() Operador

Implicitly converts a `Platform::Guid` to a [GUID structure](/windows/win32/api/guiddef/ns-guiddef-guid).

### <a name="syntax"></a>Sintaxe

```cpp
const GUID& Platform::Guid::operator();
```

### <a name="return-value"></a>Valor retornado

Uma [estrutura GUID](/windows/win32/api/guiddef/ns-guiddef-guid).

## <a name="see-also"></a>Confira também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
