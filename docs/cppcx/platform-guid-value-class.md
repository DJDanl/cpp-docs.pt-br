---
title: Platform::classe de valor Guid
ms.date: 01/15/2019
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Guid
helpviewer_keywords:
- Platform::Guid Struct
ms.assetid: 25c0bfb2-7f93-44d8-bdf4-ef4fbac3424a
ms.openlocfilehash: ad71ed4965a3dd4846c9ba5d8ed2627ed8f7e056
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54334645"
---
# <a name="platformguid-value-class"></a>Platform::classe de valor Guid

Representa um tipo de [GUID](https://msdn.microsoft.com/library/windows/desktop/aa373931) no sistema de tipos do Tempo de Execução do Windows.

## <a name="syntax"></a>Sintaxe

```cpp
public value struct Guid
```

### <a name="members"></a>Membros

`Platform::Guid` tem o `Equals()`, `GetHashCode()`, e `ToString()` métodos derivam a [classe Platform:: Object](../cppcx/platform-object-class.md)e o `GetTypeCode()` método derivado a [classe Platform:: Type](../cppcx/platform-type-class.md). `Platform::Guid` também tem os seguintes membros.

|Membro|Descrição|
|------------|-----------------|
|[Guid](#ctor)|Inicializa uma nova instância de um `Platform::Guid`.|
|[operator==](#operator-equality)|Operador de igualdade.|
|[operator!=](#operator-inequality)|Operador de diferença.|
|[operator&lt;](#operator-less)|Operador menor que.|
|[operator()](#operator-call)|Converte uma `Platform::Guid` em uma `GUID`.|

### <a name="remarks"></a>Comentários

Para obter um exemplo de como gerar um novo `Platform::Guid` usando a função do Windows [CoCreateGuid](/windows/desktop/api/combaseapi/nf-combaseapi-cocreateguid), consulte [componente WinRT: Como gerar um GUID?](https://www.eternalcoding.com/?p=383)

### <a name="requirements"></a>Requisitos

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Plataforma

**Metadados:** platform.winmd

## <a name="ctor"></a> Construtores GUID:: GUID

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
Os primeiros 4 bytes do `GUID`.

*b*<br/>
Os 2 bytes do `GUID`.

*c*<br/>
Os 2 bytes do `GUID`.

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
Um `GUID` no formulário de uma [estrutura de GUID](https://msdn.microsoft.com/library/windows/desktop/aa373931).

*n*<br/>
8 bytes restantes de `GUID`.

## <a name="operator-equality"></a> GUID::Operator Operator = =

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

True se os dois `Platform::Guid` instâncias são iguais.

## <a name="operator-inequality"></a> GUID::Operator! = operador

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

True se os dois `Platform::Guid` instâncias não forem iguais.

## <a name="operator-less"></a> GUID::Operator&lt; operador

Compara dois `Platform::Guid` instâncias para ordenação.

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

True se *guid1* é ordenado antes *guid2*. A ordenação é lexicográfica após tratando cada `Platform::Guid` como se fosse uma matriz de quatro valores sem sinal de 32 bits. Isso não é a ordem usada pelo SQL Server ou o .NET Framework, nem o mesmo que a ordem lexicográfica pela representação de cadeia de caracteres.

Esse operador é fornecido para que `Guid` objetos podem ser mais facilmente consumidos pela biblioteca padrão C++.

## <a name="operator-call"></a> Operador GUID

Converte implicitamente um `Platform::Guid` para um [estrutura de GUID](https://msdn.microsoft.com/library/windows/desktop/aa373931).

### <a name="syntax"></a>Sintaxe

```cpp
const GUID& Platform::Guid::operator();
```

### <a name="return-value"></a>Valor de retorno

Um [estrutura de GUID](https://msdn.microsoft.com/library/windows/desktop/aa373931).

## <a name="see-also"></a>Consulte também

[Namespace Platform](../cppcx/platform-namespace-c-cx.md)
