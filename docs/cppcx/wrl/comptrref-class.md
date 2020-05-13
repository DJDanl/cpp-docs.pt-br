---
title: Classe ComPtrRef
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::Details::ComPtrRef
- client/Microsoft::WRL::Details::ComPtrRef::ComPtrRef
- client/Microsoft::WRL::Details::ComPtrRef::GetAddressOf
- client/Microsoft::WRL::Details::ComPtrRef::operator==
- client/Microsoft::WRL::Details::ComPtrRef::operator!=
- client/Microsoft::WRL::Details::ComPtrRef::operator InterfaceType**
- client/Microsoft::WRL::Details::ComPtrRef::operator*
- client/Microsoft::WRL::Details::ComPtrRef::operator T*
- client/Microsoft::WRL::Details::ComPtrRef::operator void**
- client/Microsoft::WRL::Details::ComPtrRef::ReleaseAndGetAddressOf
helpviewer_keywords:
- Microsoft::WRL::Details::ComPtrRef class
- Microsoft::WRL::Details::ComPtrRef::ComPtrRef, constructor
- Microsoft::WRL::Details::ComPtrRef::GetAddressOf method
- Microsoft::WRL::Details::ComPtrRef::operator== operator
- Microsoft::WRL::Details::ComPtrRef::operator!= operator
- Microsoft::WRL::Details::ComPtrRef::operator InterfaceType** operator
- Microsoft::WRL::Details::ComPtrRef::operator* operator
- Microsoft::WRL::Details::ComPtrRef::operator T* operator
- Microsoft::WRL::Details::ComPtrRef::operator void** operator
- Microsoft::WRL::Details::ComPtrRef::ReleaseAndGetAddressOf method
ms.assetid: d6bdfd20-e977-45b4-9ac1-1b8efbdb77de
ms.openlocfilehash: df9ded817227547493c04035e0abc3d948e24495
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372631"
---
# <a name="comptrref-class"></a>Classe ComPtrRef

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
class ComPtrRef : public ComPtrRefBase<T>;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Um [ComPtr\<T>](comptr-class.md) tipo ou um tipo derivado dele, não apenas a interface representada pelo . `ComPtr`

## <a name="remarks"></a>Comentários

Representa uma referência a um `ComPtr<T>`objeto de tipo .

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                               | Descrição
---------------------------------- | -------------------------------------------------------------------------------------------------------------
[ComPtrRef::ComPtrRef](#comptrref) | Inicializa uma nova instância `ComPtrRef` da classe do ponteiro `ComPtrRef` especificado para outro objeto.

### <a name="public-methods"></a>Métodos públicos

Nome                                                         | Descrição
------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------
[ComPtrRef::GetAddressOf](#getaddressof)                     | Recupera o endereço de um ponteiro para `ComPtrRef` a interface representada pelo objeto atual.
[Comptrref::releaseAndGetAddressOf](#releaseandgetaddressof) | Exclui o `ComPtrRef` objeto atual e retorna um ponteiro para um ponteiro para `ComPtrRef` a interface representada pelo objeto.

### <a name="public-operators"></a>Operadores públicos

Nome                                                                     | Descrição
------------------------------------------------------------------------ | -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[ComPtrRef:interface tipo de operação**](#operator-interfacetype-star-star) | Exclui o `ComPtrRef` objeto atual e retorna um ponteiro para um ponteiro para `ComPtrRef` a interface representada pelo objeto.
[ComPtrRef::operador T*](#operator-t-star)                               | Retorna o valor do membro de dados [ptr_](comptrrefbase-class.md#ptr) do objeto ComPtrRef atual.
[ComPtrRef::vazio do operador**](#operator-void-star-star)                   | Exclui o `ComPtrRef` objeto atual, lança o ponteiro para a `ComPtrRef` interface representada pelo objeto como `void`um ponteiro-a-ponteiro para , e, em seguida, retorna o ponteiro do elenco.
[ComPtrRef::operador*](#operator-star)                                   | Recupera o ponteiro para a interface `ComPtrRef` representada pelo objeto atual.
[ComPtrRef::operator==](#operator-equality)                              | Indica se dois objetos `ComPtrRef` são iguais.
[ComPtrRef::operador!=](#operator-inequality)                            | Indica se dois objetos `ComPtrRef` não são iguais.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ComPtrRefBase`

`ComPtrRef`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="comptrrefcomptrref"></a><a name="comptrref"></a>ComPtrRef::ComPtrRef

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
ComPtrRef(
   _In_opt_ T* ptr
);
```

### <a name="parameters"></a>Parâmetros

*Ptr*<br/>
O valor subjacente `ComPtrRef` de outro objeto.

### <a name="remarks"></a>Comentários

Inicializa uma nova instância `ComPtrRef` da classe do ponteiro `ComPtrRef` especificado para outro objeto.

## <a name="comptrrefgetaddressof"></a><a name="getaddressof"></a>ComPtrRef::GetAddressOf

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
InterfaceType* const * GetAddressOf() const;
```

### <a name="return-value"></a>Valor retornado

Endereço de um ponteiro para a `ComPtrRef` interface representada pelo objeto atual.

### <a name="remarks"></a>Comentários

Recupera o endereço de um ponteiro para `ComPtrRef` a interface representada pelo objeto atual.

## <a name="comptrrefoperator"></a><a name="operator-equality"></a>ComPtrRef::operator==

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
bool operator==(
   const Details::ComPtrRef<ComPtr<T>>& a,
   const Details::ComPtrRef<ComPtr<U>>& b
);

bool operator==(
   const Details::ComPtrRef<ComPtr<T>>& a,
   decltype(__nullptr)
);

bool operator==(
   decltype(__nullptr),
   const Details::ComPtrRef<ComPtr<T>>& a
);

bool operator==(
   const Details::ComPtrRef<ComPtr<T>>& a,
   void* b
);

bool operator==(
   void* b,
   const Details::ComPtrRef<ComPtr<T>>& a
);
```

### <a name="parameters"></a>Parâmetros

*Um*<br/>
Uma referência a um objeto `ComPtrRef`.

*B*<br/>
Uma referência `ComPtrRef` a outro objeto, ou um`void*`ponteiro para um tipo anônimo ( ).

### <a name="return-value"></a>Valor retornado

O primeiro operador produz **verdadeiro** se o objeto *a* for igual ao objeto *b;* caso contrário, **falso**.

O segundo e terceiro operadores produzem **verdadeiro** se o objeto *a* for igual a **nulo;** caso contrário, **falso**.

O quarto e quinto operadores produzem **verdadeiro** se o objeto *a* for igual ao objeto *b*; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

Indica se dois objetos `ComPtrRef` são iguais.

## <a name="comptrrefoperator"></a><a name="operator-inequality"></a>ComPtrRef::operador!=

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
bool operator!=(
   const Details::ComPtrRef<ComPtr<T>>& a,
   const Details::ComPtrRef<ComPtr<U>>& b
);

bool operator!=(
   const Details::ComPtrRef<ComPtr<T>>& a,
   decltype(__nullptr)
);

bool operator!=(
   decltype(__nullptr),
   const Details::ComPtrRef<ComPtr<T>>& a
);

bool operator!=(
   const Details::ComPtrRef<ComPtr<T>>& a,
   void* b
);

bool operator!=(
   void* b,
   const Details::ComPtrRef<ComPtr<T>>& a
);
```

### <a name="parameters"></a>Parâmetros

*Um*<br/>
Uma referência a um objeto `ComPtrRef`.

*B*<br/>
Uma referência `ComPtrRef` a outro objeto, ou um`void*`ponteiro para um objeto anônimo ( ).

### <a name="return-value"></a>Valor retornado

O primeiro operador produz **verdadeiro** se o objeto *a* não for igual ao objeto *b;* caso contrário, **falso**.

O segundo e terceiro operadores produzem **verdadeiro** se o objeto *a* não for igual a **nulo;** caso contrário, **falso**.

O quarto e quinto operadores produzem **verdadeiro** se o objeto *a* não for igual ao objeto *b;* caso contrário, **falso**.

### <a name="remarks"></a>Comentários

Indica se dois objetos `ComPtrRef` não são iguais.

## <a name="comptrrefoperator-interfacetype"></a><a name="operator-interfacetype-star-star"></a>ComPtrRef:interface tipo de operação**

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator InterfaceType**();
```

### <a name="remarks"></a>Comentários

Exclui o `ComPtrRef` objeto atual e retorna um ponteiro para um ponteiro para `ComPtrRef` a interface representada pelo objeto.

## <a name="comptrrefoperator"></a><a name="operator-star"></a>ComPtrRef::operador*

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
InterfaceType* operator *();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para a interface `ComPtrRef` representada pelo objeto atual.

### <a name="remarks"></a>Comentários

Recupera o ponteiro para a interface `ComPtrRef` representada pelo objeto atual.

## <a name="comptrrefoperator-t"></a><a name="operator-t-star"></a>ComPtrRef::operador T*

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator T*();
```

### <a name="remarks"></a>Comentários

Retorna o valor do membro de `ComPtrRef` dados [ptr_](comptrrefbase-class.md#ptr) do objeto atual.

## <a name="comptrrefoperator-void"></a><a name="operator-void-star-star"></a>ComPtrRef::vazio do operador\*\*

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator void**() const;
```

### <a name="remarks"></a>Comentários

Exclui o `ComPtrRef` objeto atual, lança o ponteiro para a `ComPtrRef` interface representada pelo objeto como `void`um ponteiro-a-ponteiro para , e, em seguida, retorna o ponteiro do elenco.

## <a name="comptrrefreleaseandgetaddressof"></a><a name="releaseandgetaddressof"></a>Comptrref::releaseAndGetAddressOf

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
InterfaceType** ReleaseAndGetAddressOf();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para a interface que foi `ComPtrRef` representada pelo objeto excluído.

### <a name="remarks"></a>Comentários

Exclui o `ComPtrRef` objeto atual e retorna um ponteiro para um ponteiro para `ComPtrRef` a interface representada pelo objeto.
