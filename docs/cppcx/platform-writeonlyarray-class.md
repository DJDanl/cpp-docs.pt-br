---
title: Classe Platform::WriteOnlyArray
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::WriteOnlyArray::begin
- VCCORLIB/Platform::WriteOnlyArray::Data
- VCCORLIB/Platform::WriteOnlyArray::end
- VCCORLIB/Platform::WriteOnlyArray::FastPass
- VCCORLIB/Platform::WriteOnlyArray::Length
- VCCORLIB/Platform::WriteOnlyArray::set
helpviewer_keywords:
- Platform::WriteOnlyArray Class
ms.assetid: 92d7dd56-ec58-4b8c-88ba-9c903668b687
ms.openlocfilehash: d06ed19b7c041f9ae73f862ba521449a206aa321
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374642"
---
# <a name="platformwriteonlyarray-class"></a>Classe Platform::WriteOnlyArray

Representa uma matriz unidimensional que é usada como parâmetro de entrada quando o chamador passa uma matriz para o método para preenchimento.

Essa classe ref é declarada como particular em vccorlib.h; portanto, não é emitida nos metadados e é somente consumível em C++. Essa classe é destinada somente para uso como um parâmetro de entrada que recebe uma matriz alocada pelo chamador. Ela não pode ser construída a partir do código do usuário. Ela permite que um método C++ grave diretamente nessa matriz — um padrão que é conhecido como o padrão *FillArray* . Para obter mais informações, consulte [Array e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md).

## <a name="syntax"></a>Sintaxe

```cpp
private ref class WriteOnlyArray<T, 1>
```

### <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

Esses métodos têm acessibilidade interna — ou seja, eles são acessíveis apenas dentro do aplicativo ou componente C++.

|Nome|Descrição|
|----------|-----------------|
|[WriteOnlyArray::begin](#begin)|Um iterador que aponta para o primeiro elemento da matriz.|
|[WriteOnlyArray::Data](#data)|Um ponteiro para o buffer de dados.|
|[WriteOnlyArray::end](#end)|Um iterador que aponta para após o último elemento da matriz.|
|[WriteOnlyArray::FastPass](#fastpass)|Indica se a matriz pode usar o mecanismo FastPass, que é uma otimização executada pelo sistema de forma transparente. Não use isso em seu código|
|[WriteOnlyArray::Comprimento](#length)|Retorna o número de elementos na matriz.|
|[WriteOnlyArray::set](#set)|Define o elemento especificado para o valor especificado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`WriteOnlyArray`

### <a name="requirements"></a>Requisitos

Opção compilador: **/ZW**

**Metadados:** Platform.winmd

**Namespace:** Platform

## <a name="writeonlyarraybegin-method"></a><a name="begin"></a>WriteOnlyArray::iniciar método

Retorna um ponteiro para o primeiro elemento da matriz.

### <a name="syntax"></a>Sintaxe

```cpp
T* begin() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o primeiro elemento da matriz.

### <a name="remarks"></a>Comentários

Esse iterador pode ser usado com algoritmos STL, como `std::sort`, para operar em elementos da matriz.

## <a name="writeonlyarraydata-property"></a><a name="data"></a>WriteOnlyArray::Data Property

Ponteiro para o buffer de dados.

### <a name="syntax"></a>Sintaxe

```cpp
property T* Data{
   T* get() const;
}
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para os bytes de matriz brutos.

## <a name="writeonlyarrayend-method"></a><a name="end"></a>WriteOnlyArray::end Method

Retorna um ponteiro para após o último elemento da matriz.

### <a name="syntax"></a>Sintaxe

```cpp
T* end() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador de ponteiro para após o último elemento da matriz.

### <a name="remarks"></a>Comentários

Esse iterador pode ser usado com algoritmos STL para executar operações como `std::sort` nos elementos da matriz.

## <a name="writeonlyarrayfastpass-property"></a><a name="fastpass"></a>WriteOnlyArray::FastPass Property

Indica se a otimização FastPass interna pode ser executada. Não destinado ao uso por código de usuário.

### <a name="syntax"></a>Sintaxe

```cpp
property bool FastPass{
   bool get() const;
}
```

### <a name="return-value"></a>Valor retornado

Um valor booliano que indica se a matriz é FastPass.

## <a name="writeonlyarrayget-method"></a><a name="get"></a>WriteOnlyArray::get Method

Retorna o elemento no índice especificado.

### <a name="syntax"></a>Sintaxe

```cpp
T& get(unsigned int indexArg) const;
```

### <a name="parameters"></a>Parâmetros

*indexArg*<br/>
O índice para usar.

### <a name="return-value"></a>Valor retornado

## <a name="writeonlyarraylength-property"></a><a name="length"></a>WriteOnlyArray::Extensão de propriedade

Retorna o número de elementos na matriz alocada pelo chamador.

### <a name="syntax"></a>Sintaxe

```cpp
property unsigned int Length{
   unsigned int get() const;
}
```

### <a name="return-value"></a>Valor retornado

O número de elementos na matriz.

## <a name="writeonlyarrayset-function"></a><a name="set"></a>WriteOnlyArray::'função de conjunto

Define o valor especificado no índice especificado na matriz.

### <a name="syntax"></a>Sintaxe

```cpp
T& set(
   unsigned int indexArg,
   T valueArg);
```

### <a name="parameters"></a>Parâmetros

*indexArg*<br/>
O índice do elemento a ser definido.

*valorArg*<br/>
O valor a ser definido em `indexArg`.

### <a name="return-value"></a>Valor retornado

Uma referência ao elemento que acabou de ser definido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre como interpretar o valor hresult, consulte [Estrutura de Códigos de erro COM](/windows/win32/com/structure-of-com-error-codes).

## <a name="see-also"></a>Confira também

[Espaço de nome da plataforma](platform-namespace-c-cx.md)<br/>
[Criando componentes do Windows Runtime no C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)
