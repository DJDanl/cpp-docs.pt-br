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
ms.openlocfilehash: adfe7a045e0869c13f48770e03de6de10f978a4b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50502928"
---
# <a name="comptrref-class"></a>Classe ComPtrRef

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
class ComPtrRef : public ComPtrRefBase<T>;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Um [ComPtr\<T >](../windows/comptr-class.md) tipo ou um tipo derivado dele, não simplesmente a interface representada pelo `ComPtr`.

## <a name="remarks"></a>Comentários

Representa uma referência a um objeto do tipo `ComPtr<T>`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

Nome                               | Descrição
---------------------------------- | -------------------------------------------------------------------------------------------------------------
[Comptrref:: Comptrref](#comptrref) | Inicializa uma nova instância dos `ComPtrRef` classe a partir o ponteiro especificado para outro `ComPtrRef` objeto.

### <a name="public-methods"></a>Métodos públicos

Nome                                                         | Descrição
------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------
[Comptrref:: Getaddressof](#getaddressof)                     | Recupera o endereço de um ponteiro para a interface representado pelo atual `ComPtrRef` objeto.
[Comptrref:: Releaseandgetaddressof](#releaseandgetaddressof) | Exclui o atual `ComPtrRef` do objeto e retorna um ponteiro-para-um-ponteiro para a interface que foi representada pelo `ComPtrRef` objeto.

### <a name="public-operators"></a>Operadores públicos

Nome                                                                     | Descrição
------------------------------------------------------------------------ | -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[Comptrref:: Operator InterfaceType * *](#operator-interfacetype-star-star) | Exclui o atual `ComPtrRef` do objeto e retorna um ponteiro-para-um-ponteiro para a interface que foi representada pelo `ComPtrRef` objeto.
[Comptrref:: Operator T *](#operator-t-star)                               | Retorna o valor da [PTR _](../windows/comptrrefbase-ptr-data-member.md) membro de dados do objeto ComPtrRef atual.
[Comptrref:: Operator void * *](#operator-void-star-star)                   | Exclui o atual `ComPtrRef` do objeto, converte o ponteiro para a interface que foi representado pela `ComPtrRef` objeto como um ponteiro-para-ponteiro-para `void`e, em seguida, retorna o ponteiro de conversão.
[Comptrref:: Operator *](#operator-star)                                   | Recupera o ponteiro para a interface representado pelo atual `ComPtrRef` objeto.
[Comptrref:: Operator = =](#operator-equality)                              | Indica se dois objetos `ComPtrRef` são iguais.
[Comptrref:: Operator! =](#operator-inequality)                            | Indica se dois objetos `ComPtrRef` não são iguais.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ComPtrRefBase`

`ComPtrRef`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL::Details

## <a name="comptrref"></a>Comptrref:: Comptrref

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
ComPtrRef(
   _In_opt_ T* ptr
);
```

### <a name="parameters"></a>Parâmetros

*ptr*<br/>
O valor subjacente de outro `ComPtrRef` objeto.

### <a name="remarks"></a>Comentários

Inicializa uma nova instância dos `ComPtrRef` classe a partir o ponteiro especificado para outro `ComPtrRef` objeto.

## <a name="getaddressof"></a>Comptrref:: Getaddressof

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
InterfaceType* const * GetAddressOf() const;
```

### <a name="return-value"></a>Valor de retorno

Endereço de um ponteiro para a interface representado pelo atual `ComPtrRef` objeto.

### <a name="remarks"></a>Comentários

Recupera o endereço de um ponteiro para a interface representado pelo atual `ComPtrRef` objeto.

## <a name="operator-equality"></a>Comptrref:: Operator = =

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

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

*a*<br/>
Uma referência a um objeto `ComPtrRef`.

*b*<br/>
Uma referência a outro `ComPtrRef` objeto ou um ponteiro para um tipo anônimo (`void*`).

### <a name="return-value"></a>Valor de retorno

A primeira produz do operador **verdadeira** se objeto *um* é igual ao objeto *b*; caso contrário, **false**.

Os operadores de segundo e terceiro yield **verdadeira** se objeto *um* é igual a **nullptr**; caso contrário, **false**.

Os quarto e quintas operadores produzem **verdadeira** se objeto *um* é igual ao objeto *b*; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Indica se dois objetos `ComPtrRef` são iguais.

## <a name="operator-inequality"></a>Comptrref:: Operator! =

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

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

*a*<br/>
Uma referência a um objeto `ComPtrRef`.

*b*<br/>
Uma referência a outro `ComPtrRef` objeto ou um ponteiro para um objeto anônimo (`void*`).

### <a name="return-value"></a>Valor de retorno

A primeira produz do operador **verdadeira** se objeto *um* não é igual ao objeto *b*; caso contrário, **false**.

Os operadores de segundo e terceiro yield **verdadeira** se objeto *um* não é igual a **nullptr**; caso contrário, **false**.

Os operadores de quarto e quintas yield **verdadeira** se objeto *um* não é igual ao objeto *b*; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Indica se dois objetos `ComPtrRef` não são iguais.

## <a name="operator-interfacetype-star-star"></a>Comptrref:: Operator InterfaceType * *

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator InterfaceType**();
```

### <a name="remarks"></a>Comentários

Exclui o atual `ComPtrRef` do objeto e retorna um ponteiro-para-um-ponteiro para a interface que foi representada pelo `ComPtrRef` objeto.

## <a name="operator-star"></a>Comptrref:: Operator *

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
InterfaceType* operator *();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para a interface representado pelo atual `ComPtrRef` objeto.

### <a name="remarks"></a>Comentários

Recupera o ponteiro para a interface representado pelo atual `ComPtrRef` objeto.

## <a name="operator-t-star"></a>Comptrref:: Operator T *

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator T*();
```

### <a name="remarks"></a>Comentários

Retorna o valor da [PTR _](../windows/comptrrefbase-ptr-data-member.md) membro de dados do atual `ComPtrRef` objeto.

## <a name="operator-void-star-star"></a>Comptrref:: Operator void\*\*

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
operator void**() const;
```

### <a name="remarks"></a>Comentários

Exclui o atual `ComPtrRef` do objeto, converte o ponteiro para a interface que foi representado pela `ComPtrRef` objeto como um ponteiro-para-ponteiro-para `void`e, em seguida, retorna o ponteiro de conversão.

## <a name="releaseandgetaddressof"></a>Comptrref:: Releaseandgetaddressof

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
InterfaceType** ReleaseAndGetAddressOf();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para a interface que fosse representado pelo excluídos `ComPtrRef` objeto.

### <a name="remarks"></a>Comentários

Exclui o atual `ComPtrRef` do objeto e retorna um ponteiro-para-um-ponteiro para a interface que foi representada pelo `ComPtrRef` objeto.
