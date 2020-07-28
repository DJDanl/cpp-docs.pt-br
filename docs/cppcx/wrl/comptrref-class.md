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
ms.openlocfilehash: f92a3e14018cf8c02dec40b664b72a0956f6220e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220529"
---
# <a name="comptrref-class"></a>Classe ComPtrRef

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
class ComPtrRef : public ComPtrRefBase<T>;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Um [tipo \<T> ComPtr](comptr-class.md) ou um tipo derivado dele, não meramente a interface representada pelo `ComPtr` .

## <a name="remarks"></a>Comentários

Representa uma referência a um objeto do tipo `ComPtr<T>` .

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                               | Descrição
---------------------------------- | -------------------------------------------------------------------------------------------------------------
[ComPtrRef::ComPtrRef](#comptrref) | Inicializa uma nova instância da `ComPtrRef` classe a partir do ponteiro especificado para outro `ComPtrRef` objeto.

### <a name="public-methods"></a>Métodos públicos

Nome                                                         | Descrição
------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------
[ComPtrRef:: getaddressof](#getaddressof)                     | Recupera o endereço de um ponteiro para a interface representada pelo objeto atual `ComPtrRef` .
[ComPtrRef::ReleaseAndGetAddressOf](#releaseandgetaddressof) | Exclui o `ComPtrRef` objeto atual e retorna um ponteiro para ponteiro para a interface que foi representada pelo `ComPtrRef` objeto.

### <a name="public-operators"></a>Operadores públicos

Nome                                                                     | Descrição
------------------------------------------------------------------------ | -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[ComPtrRef:: Operator InterfaceType * *](#operator-interfacetype-star-star) | Exclui o `ComPtrRef` objeto atual e retorna um ponteiro para ponteiro para a interface que foi representada pelo `ComPtrRef` objeto.
[ComPtrRef:: Operator T *](#operator-t-star)                               | Retorna o valor do membro de dados [ptr_](comptrrefbase-class.md#ptr) do objeto ComPtrRef atual.
[ComPtrRef:: Operator void * *](#operator-void-star-star)                   | Exclui o `ComPtrRef` objeto atual, converte o ponteiro para a interface que foi representada pelo `ComPtrRef` objeto como um ponteiro para ponteiro para **`void`** e retorna o ponteiro de conversão.
[ComPtrRef:: Operator *](#operator-star)                                   | Recupera o ponteiro para a interface representada pelo objeto atual `ComPtrRef` .
[ComPtrRef:: Operator = =](#operator-equality)                              | Indica se dois objetos `ComPtrRef` são iguais.
[ComPtrRef:: Operator! =](#operator-inequality)                            | Indica se dois objetos `ComPtrRef` não são iguais.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ComPtrRefBase`

`ComPtrRef`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Client. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="comptrrefcomptrref"></a><a name="comptrref"></a>ComPtrRef::ComPtrRef

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
ComPtrRef(
   _In_opt_ T* ptr
);
```

### <a name="parameters"></a>parâmetros

*ptr*<br/>
O valor subjacente de outro `ComPtrRef` objeto.

### <a name="remarks"></a>Comentários

Inicializa uma nova instância da `ComPtrRef` classe a partir do ponteiro especificado para outro `ComPtrRef` objeto.

## <a name="comptrrefgetaddressof"></a><a name="getaddressof"></a>ComPtrRef:: getaddressof

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
InterfaceType* const * GetAddressOf() const;
```

### <a name="return-value"></a>Valor retornado

Endereço de um ponteiro para a interface representada pelo objeto atual `ComPtrRef` .

### <a name="remarks"></a>Comentários

Recupera o endereço de um ponteiro para a interface representada pelo objeto atual `ComPtrRef` .

## <a name="comptrrefoperator"></a><a name="operator-equality"></a>ComPtrRef:: Operator = =

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

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

### <a name="parameters"></a>parâmetros

*um*<br/>
Uma referência a um objeto `ComPtrRef`.

*b*<br/>
Uma referência a outro `ComPtrRef` objeto ou um ponteiro para um tipo anônimo ( **`void*`** ).

### <a name="return-value"></a>Valor retornado

O primeiro operador produz **`true`** se o objeto *a* é igual a Object *b*; caso contrário, **`false`** .

O segundo e o terceiro operadores produzem **`true`** se *o objeto a* é igual a **`nullptr`** ; caso contrário, **`false`** .

O quarto e quinto operadores produzem **`true`** se *o objeto a* é igual a Object *b*; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Indica se dois objetos `ComPtrRef` são iguais.

## <a name="comptrrefoperator"></a><a name="operator-inequality"></a>ComPtrRef:: Operator! =

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

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

### <a name="parameters"></a>parâmetros

*um*<br/>
Uma referência a um objeto `ComPtrRef`.

*b*<br/>
Uma referência a outro `ComPtrRef` objeto ou um ponteiro para um objeto anônimo ( **`void*`** ).

### <a name="return-value"></a>Valor retornado

O primeiro operador produz **`true`** se o objeto *a* não é igual a Object *b*; caso contrário, **`false`** .

O segundo e o terceiro operadores produzem **`true`** se *o objeto a* não for igual a **`nullptr`** ; caso contrário, **`false`** .

O quarto e quinto operadores produzem **`true`** se *o objeto a* não for igual ao objeto *b*; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Indica se dois objetos `ComPtrRef` não são iguais.

## <a name="comptrrefoperator-interfacetype"></a><a name="operator-interfacetype-star-star"></a>InterfaceType ComPtrRef:: Operator\*\*

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator InterfaceType**();
```

### <a name="remarks"></a>Comentários

Exclui o `ComPtrRef` objeto atual e retorna um ponteiro para ponteiro para a interface que foi representada pelo `ComPtrRef` objeto.

## <a name="comptrrefoperator"></a><a name="operator-star"></a>ComPtrRef:: Operator *

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
InterfaceType* operator *();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para a interface representada pelo objeto atual `ComPtrRef` .

### <a name="remarks"></a>Comentários

Recupera o ponteiro para a interface representada pelo objeto atual `ComPtrRef` .

## <a name="comptrrefoperator-t"></a><a name="operator-t-star"></a>ComPtrRef:: Operator T *

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator T*();
```

### <a name="remarks"></a>Comentários

Retorna o valor do membro de dados [ptr_](comptrrefbase-class.md#ptr) do objeto atual `ComPtrRef` .

## <a name="comptrrefoperator-void"></a><a name="operator-void-star-star"></a>ComPtrRef:: Operator void\*\*

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator void**() const;
```

### <a name="remarks"></a>Comentários

Exclui o `ComPtrRef` objeto atual, converte o ponteiro para a interface que foi representada pelo `ComPtrRef` objeto como um ponteiro para ponteiro para **`void`** e retorna o ponteiro de conversão.

## <a name="comptrrefreleaseandgetaddressof"></a><a name="releaseandgetaddressof"></a>ComPtrRef::ReleaseAndGetAddressOf

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
InterfaceType** ReleaseAndGetAddressOf();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para a interface que foi representada pelo objeto excluído `ComPtrRef` .

### <a name="remarks"></a>Comentários

Exclui o `ComPtrRef` objeto atual e retorna um ponteiro para ponteiro para a interface que foi representada pelo `ComPtrRef` objeto.
