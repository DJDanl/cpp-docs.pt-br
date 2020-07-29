---
title: Classe CAdapt
ms.date: 11/04/2016
f1_keywords:
- CAdapt
- ATLCOMCLI/ATL::CAdapt
- ATLCOMCLI/ATL::CAdapt::CAdapt
- ATLCOMCLI/ATL::CAdapt::m_T
helpviewer_keywords:
- address-of operator
- adapter objects
- '& operator, address-of operator'
- CAdapt class
ms.assetid: 0bb695a5-72fe-43d1-8f39-7e4da6e34765
ms.openlocfilehash: 2ea8fc8a26642abf593c7f4df3928ff90e66e2b3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229994"
---
# <a name="cadapt-class"></a>Classe CAdapt

Este modelo é usado para incluir classes que redefinem o operador address-of para retornar algo diferente do endereço do objeto.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class CAdapt
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo adaptado.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAdapt::CAdapt](#cadapt)|O construtor.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAdapt:: Operator const T&](#operator_const_t_amp)|Retorna uma **`const`** referência a `m_T` .|
|[Operador CAdapt:: Operator T&](#operator_t_amp)|Retorna uma referência para `m_T`.|
|[Operador CAdapt:: Operator <](#operator_lt)|Compara um objeto do tipo adaptado com `m_T`.|
|[CAdapt:: Operator =](#operator_eq)|Atribui um objeto do tipo adaptado a `m_T`.|
|[CAdapt:: Operator = =](#operator_eq_eq)|Compara um objeto do tipo adaptado com `m_T`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAdapt:: m_T](#m_t)|Os dados que estão sendo adaptados.|

## <a name="remarks"></a>Comentários

`CAdapt` é um modelo simples usado para incluir classes que redefinem o operador address-of (`operator &`) para retornar algo diferente do endereço do objeto. Exemplos dessas classes incluem as classes `CComBSTR`, `CComPtr` e `CComQIPtr` do ATL, e a classe de suporte ao COM do compilador, `_com_ptr_t`. Todas essas classes redefinem o operador address-of para retornar o endereço de um de seus membros de dados (um BSTR no caso de `CComBSTR` , e um ponteiro de interface no caso das outras classes).

`CAdapt`a função principal do é ocultar o operador de endereço definido pela classe *T*, mas ainda manter as características da classe adaptada. `CAdapt`fulfils essa função segurando um membro público, [m_T](#m_t), do tipo *T*e definindo operadores de conversão, operadores de comparação e um construtor de cópia para permitir que as especializações `CAdapt` sejam tratadas como se fossem objetos do tipo *T*.

A classe de adaptador `CAdapt` é útil porque algumas classes do estilo contêiner esperam poder obter os endereços de seus objetos contidos usando o operador address-of. A redefinição do operador address-of pode confundir esse requisito, normalmente causando erros de compilação e evitando o uso do tipo não adaptado com classes que o esperam como “apenas trabalho”. `CAdapt` fornece uma maneira de contornar esses problemas.

Normalmente, você usará `CAdapt` quando quiser armazenar objetos `CComBSTR`, `CComPtr`, `CComQIPtr` ou `_com_ptr_t` em um o estilo de contêiner. Isso era o geralmente necessário para contêineres da biblioteca padrão C++ antes do suporte para o padrão C++11, mas os contêineres da biblioteca padrão C++11 funcionam automaticamente com tipos que sobrecarregaram `operator&()`. A biblioteca padrão realiza isso internamente usando [std:: AddressOf](../../standard-library/memory-functions.md#addressof) para obter os endereços verdadeiros dos objetos.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcomcli. h

## <a name="cadaptcadapt"></a><a name="cadapt"></a>CAdapt::CAdapt

Os construtores permitem que um objeto de adaptador seja construído padrão, copiado de um objeto do tipo adaptado ou copiado de outro objeto de adaptador.

```cpp
CAdapt();
CAdapt(const T& rSrc);
CAdapt(const CAdapt& rSrCA);
CAdapt(T&& rSrCA);  // (Visual Studio 2017)
CAdapt(CAdapt<T>&& rSrCA) noexcept; // (Visual Studio 2017)
```

### <a name="parameters"></a>parâmetros

*rSrc*<br/>
Uma variável do tipo que está sendo adaptado para ser copiada para o objeto de adaptador recém-criado.

*rSrCA*<br/>
Um objeto de adaptador cujos dados contidos devem ser copiados (ou movidos) para o objeto de adaptador recém-criado.

## <a name="cadaptm_t"></a><a name="m_t"></a>CAdapt:: m_T

Mantém os dados sendo adaptados.

```cpp
T m_T;
```

### <a name="remarks"></a>Comentários

Esse **`public`** membro de dados pode ser acessado direta ou indiretamente com o [operador const T&](#operator_const_t_amp) e o [operador t&](#operator_t_amp).

## <a name="cadaptoperator-const-tamp"></a><a name="operator_const_t_amp"></a>CAdapt:: Operator const T&amp;

Retorna uma **`const`** referência ao membro de [m_T](#m_t) , permitindo que o objeto de adaptador seja tratado como se fosse um objeto do tipo *T*.

```cpp
operator const T&() const;
```

### <a name="return-value"></a>Valor retornado

Uma **`const`** referência a `m_T` .

## <a name="cadaptoperator-tamp"></a><a name="operator_t_amp"></a>Operador CAdapt:: Operator T&amp;

Retorna uma referência ao membro de [m_T](#m_t) , permitindo que o objeto de adaptador seja tratado como se fosse um objeto do tipo *T*.

```cpp
operator T&();
```

### <a name="return-value"></a>Valor retornado

Uma referência a `m_T`.

## <a name="cadaptoperator-lt"></a><a name="operator_lt"></a>Operador CAdapt::&lt;

Compara um objeto do tipo adaptado com [m_T](#m_t).

```cpp
bool operator<(const T& rSrc) const;
```

### <a name="parameters"></a>parâmetros

*rSrc*<br/>
Uma referência ao objeto a ser comparado.

### <a name="return-value"></a>Valor retornado

O resultado da comparação entre `m_T` e *rsrc*.

## <a name="cadaptoperator-"></a><a name="operator_eq"></a>CAdapt:: Operator =

O operador de atribuição atribui o argumento, *rsrc*, ao membro de dados [m_T](#m_t) e retorna o objeto do adaptador atual.

```cpp
CAdapt& operator= (const T& rSrc);
CAdapt& operator= (T&& rSrCA); // (Visual Studio 2017)
CAdapt& operator= (CAdapt<T>&& rSrCA) noexcept; // (Visual Studio 2017)
```

### <a name="parameters"></a>parâmetros

*rSrc*<br/>
Uma referência a um objeto do tipo adaptado a ser copiado.

*rSrCA*<br/>
Uma referência a um objeto a ser movido.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto atual.

## <a name="cadaptoperator-"></a><a name="operator_eq_eq"></a>CAdapt:: Operator = =

Compara um objeto do tipo adaptado com [m_T](#m_t).

```cpp
bool operator== (const T& rSrc) const;
```

### <a name="parameters"></a>parâmetros

*rSrc*<br/>
Uma referência ao objeto a ser comparado.

### <a name="return-value"></a>Valor retornado

O resultado da comparação entre *m_T* e *rsrc*.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
