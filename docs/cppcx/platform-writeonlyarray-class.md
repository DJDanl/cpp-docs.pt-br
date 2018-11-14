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
ms.openlocfilehash: ff339bc2b144e22d7177638424dd8e617eecfb3b
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51330601"
---
# <a name="platformwriteonlyarray-class"></a>Classe Platform::WriteOnlyArray

Representa uma matriz unidimensional que é usada como parâmetro de entrada quando o chamador passa uma matriz para o método para preenchimento.

Essa classe ref é declarada como particular em vccorlib.h; portanto, não é emitida nos metadados e é somente consumível em C++. Essa classe é destinada somente para uso como um parâmetro de entrada que recebe uma matriz alocada pelo chamador. Ela não pode ser construída a partir do código do usuário. Ela permite que um método C++ grave diretamente nessa matriz — um padrão que é conhecido como o padrão *FillArray* . Para obter mais informações, consulte [matriz e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md).

## <a name="syntax"></a>Sintaxe

```cpp
private ref class WriteOnlyArray<T, 1>
```

### <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

Esses métodos têm acessibilidade interna — ou seja, eles são acessíveis apenas dentro do aplicativo ou componente C++.

|Nome|Descrição|
|----------|-----------------|
|[Writeonlyarray:: begin](#begin)|Um iterador que aponta para o primeiro elemento da matriz.|
|[Writeonlyarray:: data](#data)|Um ponteiro para o buffer de dados.|
|[Writeonlyarray:: end](#end)|Um iterador que aponta para após o último elemento da matriz.|
|[Writeonlyarray:: Fastpass](#fastpass)|Indica se a matriz pode usar o mecanismo FastPass, que é uma otimização executada pelo sistema de forma transparente. Não use isso em seu código|
|[Writeonlyarray:: Length](#length)|Retorna o número de elementos na matriz.|
|[Writeonlyarray:: Set](#set)|Define o elemento especificado para o valor especificado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`WriteOnlyArray`

### <a name="requirements"></a>Requisitos

Opção do compilador: **/ZW**

**Metadados:** Platform.winmd

**Namespace:** Platform

## <a name="begin"></a>  Método WriteOnlyArray::begin

Retorna um ponteiro para o primeiro elemento da matriz.

### <a name="syntax"></a>Sintaxe

```cpp
T* begin() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o primeiro elemento da matriz.

### <a name="remarks"></a>Comentários

Esse iterador pode ser usado com algoritmos STL, como `std::sort`, para operar em elementos da matriz.

## <a name="data"></a>  Propriedade WriteOnlyArray::Data

Ponteiro para o buffer de dados.

### <a name="syntax"></a>Sintaxe

```cpp
property T* Data{
   T* get() const;
}
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para os bytes de matriz brutos.

## <a name="end"></a>  Método WriteOnlyArray::end

Retorna um ponteiro para após o último elemento da matriz.

### <a name="syntax"></a>Sintaxe

```cpp
T* end() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador de ponteiro para após o último elemento da matriz.

### <a name="remarks"></a>Comentários

Esse iterador pode ser usado com algoritmos STL para executar operações como `std::sort` nos elementos da matriz.

## <a name="fastpass"></a>  Propriedade WriteOnlyArray::FastPass

Indica se a otimização FastPass interna pode ser executada. Não destinado ao uso por código de usuário.

### <a name="syntax"></a>Sintaxe

```cpp
property bool FastPass{
   bool get() const;
}
```

### <a name="return-value"></a>Valor de retorno

Um valor booliano que indica se a matriz é FastPass.

## <a name="get"></a>  Método writeonlyarray:: Get

Retorna o elemento no índice especificado.

### <a name="syntax"></a>Sintaxe

```cpp
T& get(unsigned int indexArg) const;
```

### <a name="parameters"></a>Parâmetros

*indexArg*<br/>
O índice a ser usado.

### <a name="return-value"></a>Valor de retorno

## <a name="length"></a>  Propriedade WriteOnlyArray::Length

Retorna o número de elementos na matriz alocada pelo chamador.

### <a name="syntax"></a>Sintaxe

```cpp
property unsigned int Length{
   unsigned int get() const;
}
```

### <a name="return-value"></a>Valor de retorno

O número de elementos na matriz.

## <a name="set"></a>  Função WriteOnlyArray::set

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

*valueArg*<br/>
O valor a ser definido em `indexArg`.

### <a name="return-value"></a>Valor de retorno

Uma referência ao elemento que acabou de ser definido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre como interpretar o valor HRESULT, consulte [estrutura de códigos de erro COM](/windows/desktop/com/structure-of-com-error-codes).

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](platform-namespace-c-cx.md)<br/>
[Criando componentes de tempo de execução do Windows em C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)