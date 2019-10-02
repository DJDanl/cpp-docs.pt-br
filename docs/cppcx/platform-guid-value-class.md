---
title: Platform::classe de valor Guid
ms.date: 01/15/2019
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Guid
helpviewer_keywords:
- Platform::Guid Struct
ms.assetid: 25c0bfb2-7f93-44d8-bdf4-ef4fbac3424a
ms.openlocfilehash: f63b2bb4fd5f809861622a4f6b255ee3725564b6
ms.sourcegitcommit: 4517932a67bbf2db16cfb122d3bef57a43696242
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/02/2019
ms.locfileid: "71816588"
---
# <a name="platformguid-value-class"></a>Platform::classe de valor Guid

Representa um tipo de [GUID](/previous-versions/cc317743(v%3dmsdn.10)) no sistema de tipos do Tempo de Execução do Windows.

## <a name="syntax"></a>Sintaxe

```cpp
public value struct Guid
```

### <a name="members"></a>Membros

`Platform::Guid` tem os métodos `Equals()`, `GetHashCode()` e `ToString()` derivados da [classe Platform:: Object](../cppcx/platform-object-class.md)e o método `GetTypeCode()` derivado da [classe Platform:: Type](../cppcx/platform-type-class.md). `Platform::Guid` também tem os membros a seguir.

|Membro|Descrição|
|------------|-----------------|
|[Guid](#ctor)|Inicializa uma nova instância de um `Platform::Guid`.|
|[operator==](#operator-equality)|Operador de igualdade.|
|[operator!=](#operator-inequality)|Operador de diferença.|
|[operator&lt;](#operator-less)|Operador menor que.|
|[operator()](#operator-call)|Converte uma `Platform::Guid` em uma `GUID`.|

### <a name="remarks"></a>Comentários

Para gerar um novo `Platform::Guid`, use o método estático [Windows:: Foundation:: GuidHelper:: CreateNewGuid](/uwp/api/windows.foundation.guidhelper.createnewguid#Windows_Foundation_GuidHelper_CreateNewGuid) .

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Plataforma

**Metadados:** platform.winmd

## <a name="ctor"></a>Construtores GUID:: GUID

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

*a*<br/>
Os quatro primeiros bytes do `GUID`.

*b*<br/>
Os próximos 2 bytes do `GUID`.

*c*<br/>
Os próximos 2 bytes do `GUID`.

*d*<br/>
O próximo byte do `GUID`.

*e*<br/>
O próximo byte do `GUID`.

*f*<br/>
O próximo byte do `GUID`.

*g*<br/>
O próximo byte do `GUID`.

*h*<br/>
O próximo byte do `GUID`.

*i*<br/>
O próximo byte do `GUID`.

*j*<br/>
O próximo byte do `GUID`.

*k*<br/>
O próximo byte do `GUID`.

*m*<br/>
Um `GUID` no formato de uma [estrutura de GUID](/previous-versions/cc317743(v%3dmsdn.10)).

*n*<br/>
Os 8 bytes restantes do `GUID`.

## <a name="operator-equality"></a>Operador GUID:: Operator = =

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

### <a name="return-value"></a>Valor de retorno

True se as duas instâncias `Platform::Guid` forem iguais.

### <a name="remarks"></a>Comentários

Prefira usar o operador `==` em vez do método estático [Windows:: Foundation:: GuidHelper:: Equals](/uwp/api/windows.foundation.guidhelper.equals) .

## <a name="operator-inequality"></a>Operador GUID:: Operator! =

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

### <a name="return-value"></a>Valor de retorno

True se as duas instâncias `Platform::Guid` não forem iguais.

## <a name="operator-less"></a>Operador GUID:: Operator @ no__t-1

Compara duas instâncias `Platform::Guid` para ordenação.

### <a name="syntax"></a>Sintaxe

```cpp
static bool Platform::Guid::operator<(Platform::Guid guid1, Platform::Guid guid2);
```

### <a name="parameters"></a>Parâmetros

*guid1*<br/>
O primeiro `Platform::Guid` a ser comparado.

*guid2*<br/>
O segundo `Platform::Guid` a ser comparado.

### <a name="return-value"></a>Valor de retorno

True se *guid1* for ordenado antes de *guid2*. A ordenação é lexicográfica depois de tratar cada `Platform::Guid` como se fosse uma matriz de valores sem sinal de 4 32 bits. Essa não é a ordem usada por SQL Server ou pela .NET Framework, nem é a mesma que a ordenação de lexicográfica por representação de cadeia de caracteres.

Esse operador é fornecido para que os C++ objetos `Guid` possam ser consumidos com mais facilidade pela biblioteca padrão.

## <a name="operator-call"></a>Operador GUID:: Operator ()

Converte implicitamente um `Platform::Guid` em uma [estrutura de GUID](/previous-versions/cc317743(v%3dmsdn.10)).

### <a name="syntax"></a>Sintaxe

```cpp
const GUID& Platform::Guid::operator();
```

### <a name="return-value"></a>Valor de retorno

Uma [estrutura de GUID](/previous-versions/cc317743(v%3dmsdn.10)).

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
