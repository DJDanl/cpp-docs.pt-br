---
title: Estrutura atomic
ms.date: 04/20/2018
f1_keywords:
- atomic/std::atomic
ms.assetid: 261628ed-7049-41ac-99b9-cfe49f696b44
ms.openlocfilehash: 738f79f966b8b0482baf4f78120c0d690425a4bf
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88834785"
---
# <a name="atomic-structure"></a>Estrutura atomic

Descreve um objeto que executa operações atômicas em um valor armazenado do tipo *Ty*.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct atomic;
```

## <a name="members"></a>Membros

|Membro|DESCRIÇÃO|
|----------|-----------------|
|**Construtor**||
|[atômica](#atomic)|Constrói um objeto atômico.|
|**Operadores**||
|[Atomic:: Operator Ty](#op_ty)|Lê e retorna o valor armazenado. ([Atomic:: Load](#load))|
|[Atomic:: Operator =](#op_eq)|Usa um valor especificado para substituir o valor armazenado. ([Atomic:: Store](#store))|
|[Atomic:: operador + +](#op_inc)|Incrementa o valor armazenado. Usado somente por especializações integrais e de ponteiro.|
|[Atomic:: Operator + =](#op_add_eq)|Adiciona um valor especificado ao valor armazenado. Usado somente por especializações integrais e de ponteiro.|
|[Atomic:: Operator--](#op_dec)|Decrementa o valor armazenado. Usado somente por especializações integrais e de ponteiro.|
|[Atomic:: Operator-=](#op_sub_eq)|Subtrai um valor especificado do valor armazenado. Usado somente por especializações integrais e de ponteiro.|
|[&Atomic:: Operator =](#op_and_eq)|Executa um valor bit e com um e o valor armazenado. Usado somente por especializações integrais.|
|[&#124;Atomic:: Operator =](#op_or_eq)|Executa uma operação OR em um valor especificado e o valor armazenado. Usado somente por especializações integrais.|
|[Atomic:: Operator ^ =](#op_xor_eq)|Executa um OR exclusivo de bit a bit em um valor especificado e o valor armazenado. Usado somente por especializações integrais.|
|**Funções**||
|[compare_exchange_strong](#compare_exchange_strong)|Executa uma operação de *atomic_compare_and_exchange* no **`this`** e retorna o resultado.|
|[compare_exchange_weak](#compare_exchange_weak)|Executa uma operação de *weak_atomic_compare_and_exchange* no **`this`** e retorna o resultado.|
|[fetch_add](#fetch_add)|Adiciona um valor especificado ao valor armazenado.|
|[fetch_and](#fetch_and)|Executa um valor bit e com um e o valor armazenado.|
|[fetch_or](#fetch_or)|Executa uma operação OR em um valor especificado e o valor armazenado.|
|[fetch_sub](#fetch_sub)|Subtrai um valor especificado do valor armazenado.|
|[fetch_xor](#fetch_xor)|Executa um OR exclusivo de bit a bit em um valor especificado e o valor armazenado.|
|[is_lock_free](#is_lock_free)|Especifica se as operações atômicas no **`this`** estão *livres de bloqueio*. Um tipo atômico é *livre de bloqueio* se nenhuma operação atômica no tipo usar bloqueios.|
|[carga](#load)|Lê e retorna o valor armazenado.|
|[loja](#store)|Usa um valor especificado para substituir o valor armazenado.|

## <a name="remarks"></a>Comentários

O tipo *Ty* deve ser *trivialmente copiável*. Ou seja, o uso de [memcpy](../c-runtime-library/reference/memcpy-wmemcpy.md) para copiar seus bytes deve produzir um objeto *Ty* válido que compare igual ao objeto original. As funções de membro [compare_exchange_weak](#compare_exchange_weak) e [compare_exchange_strong](#compare_exchange_strong) usam [memcmp](../c-runtime-library/reference/memcmp-wmemcmp.md) para determinar se dois valores *Ty* são iguais. Essas funções não usarão um *Ty*definido `operator==` . As funções de membro de `atomic` usar `memcpy` para copiar valores do tipo *Ty*.

Uma especialização parcial, `atomic<Ty*>`, existe para todos os tipos de ponteiro. A especialização permite a adição de um deslocamento para o valor do ponteiro gerenciado ou subtração de um deslocamento dele. As operações aritméticas usam um argumento do tipo `ptrdiff_t` e ajustam esse argumento de acordo com o tamanho de *Ty* para ser consistente com a aritmética de endereço comum.

Existe uma especialização para cada tipo integral, exceto **`bool`** . Cada especialização fornece um rico conjunto de métodos para operações aritméticas e lógicas atômicas.

:::row:::
   :::column:::
      `atomic<char>`\
      `atomic<signed char>`\
      `atomic<unsigned char>`\
      `atomic<char16_t>`\
      `atomic<char32_t>`\
      `atomic<wchar_t>`\
      `atomic<short>`
   :::column-end:::
   :::column:::
      `atomic<unsigned short>`\
      `atomic<int>`\
      `atomic<unsigned int>`\
      `atomic<long>`\
      `atomic<unsigned long>`\
      `atomic<long long>`\
      `atomic<unsigned long long>`
   :::column-end:::
:::row-end:::

Especializações integrais são derivadas de tipos `atomic_integral` correspondentes. Por exemplo, `atomic<unsigned int>` é derivado de `atomic_uint`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<atomic>

**Namespace:** std

## <a name="atomicatomic"></a><a name="atomic"></a> Atomic:: Atomic

Constrói um objeto atômico.

```cpp
atomic();
atomic( const atomic& );
atomic( Ty Value ) noexcept;
```

### <a name="parameters"></a>parâmetros

*Value*\
Valor de inicialização.

### <a name="remarks"></a>Comentários

Objetos atômicos não podem ser copiados ou movidos.

Os objetos que são instanciações de Atomic \<*Ty*> podem ser inicializados somente pelo construtor que usa um argumento do tipo *Ty* e não usando a inicialização de agregação. No entanto, atomic_integral objetos só podem ser inicializados usando a inicialização de agregação.

```cpp
atomic<int> ai0 = ATOMIC_VAR_INIT(0);
atomic<int> ai1(0);
```

## <a name="atomicoperator-ty"></a><a name="op_ty"></a> Atomic:: Operator *Ty*

O operador para o tipo especificado para o modelo Atomic \<*Ty*> . Recupera o valor armazenado neste ** \* .**

```cpp
atomic<Ty>::operator Ty() const volatile noexcept;
atomic<Ty>::operator Ty() const noexcept;
```

### <a name="remarks"></a>Comentários

Esse operador aplica o `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="atomicoperator"></a><a name="op_eq"></a> Atomic:: Operator =

Armazena um valor especificado.

```cpp
Ty operator=(
   Ty Value
) volatile noexcept;
Ty operator=(
   Ty Value
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Value*\
Um objeto *Ty* .

### <a name="return-value"></a>Valor Retornado

Retorna o *valor*.

## <a name="atomicoperator"></a><a name="op_inc"></a> Atomic:: operador + +

Incrementa o valor armazenado. Usado somente por especializações integrais e de ponteiro.

```cpp
Ty atomic<Ty>::operator++(int) volatile noexcept;
Ty atomic<Ty>::operator++(int) noexcept;
Ty atomic<Ty>::operator++() volatile noexcept;
Ty atomic<Ty>::operator++() noexcept;
```

### <a name="return-value"></a>Valor Retornado

Os primeiros dois operadores retornam o valor incrementado; os dois últimos operadores retornam o valor antes do incremento. Os operadores usam o `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="atomicoperator"></a><a name="op_add_eq"></a> Atomic:: Operator + =

Adiciona um valor especificado ao valor armazenado. Usado somente por especializações integrais e de ponteiro.

```cpp
Ty atomic<Ty>::operator+=(
   Ty Value
) volatile noexcept;
Ty atomic<Ty>::operator+=(
   Ty Value
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Value*\
Um valor integral ou de ponteiro.

### <a name="return-value"></a>Valor Retornado

Um objeto *Ty* que contém o resultado da adição.

### <a name="remarks"></a>Comentários

Esse operador usa o `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="atomicoperator--"></a><a name="op_dec"></a> Atomic:: Operator--

Decrementa o valor armazenado. Usado somente por especializações integrais e de ponteiro.

```cpp
Ty atomic<Ty>::operator--(int) volatile noexcept;
Ty atomic<Ty>::operator--(int) noexcept;
Ty atomic<Ty>::operator--() volatile noexcept;
Ty atomic<Ty>::operator--() noexcept;
```

### <a name="return-value"></a>Valor Retornado

Os primeiros dois operadores retornam o valor decrementado; os dois últimos operadores retornam o valor antes do decréscimo. Os operadores usam o `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="atomicoperator-"></a><a name="op_sub_eq"></a> Atomic:: Operator-=

Subtrai um valor especificado do valor armazenado. Usado somente por especializações integrais e de ponteiro.

```cpp
Ty atomic<Ty>::operator-=(
   Ty Value
) volatile noexcept;
Ty atomic<Ty>::operator-=(
   Ty Value
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Value*\
Um valor integral ou de ponteiro.

### <a name="return-value"></a>Valor Retornado

Um objeto *Ty* que contém o resultado da subtração.

### <a name="remarks"></a>Comentários

Esse operador usa o `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="atomicoperator"></a><a name="op_and_eq"></a>&Atomic:: Operator =

Executa um valor bit e com um e o valor ** \* armazenado dele.** Usado somente por especializações integrais.

```cpp
atomic<Ty>::operator&= (
   Ty Value
) volatile noexcept;
atomic<Ty>::operator&= (
   Ty Value
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Value*\
Um valor do tipo *Ty*.

### <a name="return-value"></a>Valor Retornado

O resultado de e/.

### <a name="remarks"></a>Comentários

Esse operador executa uma operação Read-Modify-Write para substituir o valor armazenado disso ** \* por um** bit e de *valor* e o valor atual que é armazenado ** \* neste, dentro**das restrições do `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="atomicoperator124"></a><a name="op_or_eq"></a>&#124;Atomic:: Operator =

Executa uma operação OR em um valor especificado e o valor armazenado disso ** \* .** Usado somente por especializações integrais.

```cpp
atomic<Ty>::operator|= (
   Ty Value
) volatile noexcept;
atomic<Ty>::operator|= (
   Ty Value
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Value*\
Um valor do tipo *Ty*.

### <a name="return-value"></a>Valor Retornado

O resultado da operação OR.

### <a name="remarks"></a>Comentários

Esse operador executa uma operação Read-Modify-Write para substituir o valor armazenado dele ** \* por um** *valor* de bits ou bit e o valor atual que é armazenado neste ** \* , dentro**das restrições das restrições de `memory_order_seq_cst` [memory_order](atomic-enums.md) .

## <a name="atomicoperator"></a><a name="op_xor_eq"></a> Atomic:: Operator ^ =

Executa um OR exclusivo de bit a bit em um valor especificado e o valor armazenado ** \* disso.** Usado somente por especializações integrais.

```cpp
atomic<Ty>::operator^= (
   Ty Value
) volatile noexcept;
atomic<Ty>::operator^= (
   Ty Value
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Value*\
Um valor do tipo *Ty*.

### <a name="return-value"></a>Valor Retornado

O resultado do or exclusivo de bit a bit.

### <a name="remarks"></a>Comentários

Esse operador executa uma operação Read-Modify-Write para substituir o valor armazenado disso **por um OR exclusivo de bit \* ** e de- *valor e o valor atual* que é armazenado ** \* neste, dentro**das restrições das `memory_order_seq_cst` restrições de [memory_order](atomic-enums.md) .

## <a name="atomiccompare_exchange_strong"></a><a name="compare_exchange_strong"></a> Atomic:: compare_exchange_strong

Executa uma operação atômica de comparação e do Exchange sobre ** \* isso**.

```cpp
bool compare_exchange_strong(
   Ty& Exp,
   Ty Value,
   memory_order Order1,
   memory_order Order2
) volatile noexcept;
bool compare_exchange_strong(
   Ty& Exp,
   Ty Value,
   memory_order Order1,
   memory_order Order2
) noexcept;
bool compare_exchange_strong(
   Ty& Exp,
   Ty Value,
   memory_order Order1 = memory_order_seq_cst
) volatile noexcept;
bool compare_exchange_strong(
   Ty& Exp,
   Ty Value,
   memory_order Order1 = memory_order_seq_cst
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Exp*\
Um valor do tipo *Ty*.

*Value*\
Um valor do tipo *Ty*.

*Order1*\
Primeiro `memory_order` argumento.

*Order2*\
Segundo argumento `memory_order`.

### <a name="return-value"></a>Valor Retornado

Um **`bool`** valor que indica o resultado da comparação de valores.

### <a name="remarks"></a>Comentários

Essa operação ** \* atômica de comparação** e do Exchange compara o valor que é armazenado com *exp*. Se os valores forem iguais, a operação substituirá o valor que é armazenado com o *valor* usando uma operação Read-Modify-Write e aplicando as ** \* restrições de ordem** de memória que são especificadas por *Order1*. Se os valores não forem iguais, a operação usará o valor que é armazenado ** \* nele para** substituir *exp* e aplica as restrições de ordem de memória que são especificadas por *Order2*.

Sobrecargas que não têm um segundo `memory_order` usam um *Order2* implícito com base no valor de *Order1*. Se *Order1* for `memory_order_acq_rel` , *Order2* será `memory_order_acquire` . Se *Order1* for `memory_order_release` , *Order2* será `memory_order_relaxed` . Em todos os outros casos, *Order2* é igual a *Order1*.

Para sobrecargas que usam dois `memory_order` parâmetros, o valor de *Order2* não deve ser `memory_order_release` ou `memory_order_acq_rel` e não deve ser mais forte que o valor de *Order1*.

## <a name="atomiccompare_exchange_weak"></a><a name="compare_exchange_weak"></a> Atomic:: compare_exchange_weak

Executa uma operação de comparação atômica frágil e do Exchange sobre ** \* isso**.

```cpp
bool compare_exchange_weak(
   Ty& Exp,
   Ty Value,
   memory_order Order1,
   memory_order Order2
) volatile noexcept;
bool compare_exchange_weak(
   Ty& Exp,
   Ty Value,
   memory_order Order1,
   memory_order Order2
) noexcept;
bool compare_exchange_weak(
   Ty& Exp,
   Ty Value,
   memory_order Order1 = memory_order_seq_cst
) volatile noexcept;
bool compare_exchange_weak(
   Ty& Exp,
   Ty Value,
   memory_order Order1 = memory_order_seq_cst
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Exp*\
Um valor do tipo *Ty*.

*Value*\
Um valor do tipo *Ty*.

*Order1*\
Primeiro `memory_order` argumento.

*Order2*\
Segundo argumento `memory_order`.

### <a name="return-value"></a>Valor Retornado

Um **`bool`** valor que indica o resultado da comparação de valores.

### <a name="remarks"></a>Comentários

Essa operação ** \* atômica de comparação** e do Exchange compara o valor que é armazenado com *exp*. Se os valores forem iguais, a operação substituirá o valor que é armazenado com o*valor* usando uma operação Read-Modify-Write e aplicando as ** \* restrições de ordem** de memória que são especificadas por *Order1*. Se os valores não forem iguais, a operação usará o valor que é armazenado ** \* nele para** substituir *exp* e aplica as restrições de ordem de memória que são especificadas por *Order2*.

Uma operação de comparar e trocar atômica fraca executará uma troca se os valores comparados forem iguais. Se os valores não forem iguais, a operação não será garantida para executar uma troca.

Sobrecargas que não têm um segundo `memory_order` usam um *Order2* implícito com base no valor de *Order1*. Se *Order1* for `memory_order_acq_rel` , *Order2* será `memory_order_acquire` . Se *Order1* for `memory_order_release` , *Order2* será `memory_order_relaxed` . Em todos os outros casos, *Order2* é igual a *Order1*.

Para sobrecargas que usam dois `memory_order` parâmetros, o valor de *Order2* não deve ser `memory_order_release` ou `memory_order_acq_rel` e não deve ser mais forte que o valor de *Order1*.

## <a name="atomicexchange"></a><a name="exchange"></a> Atomic:: Exchange

Usa um valor especificado para substituir o valor armazenado disso ** \* .**

```cpp
Ty atomic<Ty>::exchange(
   Ty Value,
   memory_order Order = memory_order_seq_cst
) volatile noexcept;
Ty atomic<Ty>::exchange(
   Ty Value,
   memory_order Order = memory_order_seq_cst
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Value*\
Um valor do tipo *Ty*.

*Ordene*\
Um `memory_order`.

### <a name="return-value"></a>Valor Retornado

O valor armazenado disso ** \* antes da** troca.

### <a name="remarks"></a>Comentários

Esta operação executa uma operação Read-Modify-Write para usar o *valor* para substituir o valor armazenado ** \* nele, dentro**das restrições de memória que são especificadas por *Order*.

## <a name="atomicfetch_add"></a><a name="fetch_add"></a> Atomic:: fetch_add

Busca o valor armazenado nele e ** \* , em seguida, adiciona**um valor especificado ao valor armazenado.

```cpp
Ty atomic<Ty>::fetch_add (
   Ty Value,
   memory_order Order = memory_order_seq_cst
) volatile noexcept;
Ty atomic<Ty>::fetch_add (
   Ty Value,
   memory_order Order = memory_order_seq_cst
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Value*\
Um valor do tipo *Ty*.

*Ordene*\
Um `memory_order`.

### <a name="return-value"></a>Valor Retornado

Um objeto *Ty* que contém o valor armazenado nele ** \* antes da** adição.

### <a name="remarks"></a>Comentários

O `fetch_add` método executa uma operação Read-Modify-Write para adicionar o *valor* atomicamente ao valor armazenado e ** \* **aplica as restrições de memória especificadas por *Order*.

## <a name="atomicfetch_and"></a><a name="fetch_and"></a> Atomic:: fetch_and

Executa um valor de bit e um e um valor existente que é armazenado nesse ** \* .**

```cpp
Ty atomic<Ty>::fetch_and (
   Ty Value,
   memory_order Order = memory_order_seq_cst
) volatile noexcept;
Ty atomic<Ty>::fetch_and (
   Ty Value,
   memory_order Order = memory_order_seq_cst
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Value*\
Um valor do tipo *Ty*.

*Ordene*\
Um `memory_order`.

### <a name="return-value"></a>Valor Retornado

Um objeto *Ty* que contém o resultado da e/.

### <a name="remarks"></a>Comentários

O `fetch_and` método executa uma operação Read-Modify-Write para substituir o valor armazenado dele ** \* ** por um bit e de *valor* e o valor atual que é armazenado nele, ** \* **dentro das restrições de memória que são especificadas por *ordem*.

## <a name="atomicfetch_or"></a><a name="fetch_or"></a> Atomic:: fetch_or

Executa uma operação ** \* or em um**valor e um valor existente que é armazenado nesse.

```cpp
Ty atomic<Ty>::fetch_or (
   Ty Value,
   memory_order Order = memory_order_seq_cst
) volatile noexcept;
Ty atomic<Ty>::fetch_or (
   Ty Value,
   memory_order Order = memory_order_seq_cst
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Value*\
Um valor do tipo *Ty*.

*Ordene*\
Um `memory_order`.

### <a name="return-value"></a>Valor Retornado

Um objeto *Ty* que contém o resultado da operação OR.

### <a name="remarks"></a>Comentários

O `fetch_or` método executa uma operação Read-Modify-Write para substituir o valor armazenado dele ** \* ** por um *valor* de bits ou bit e o valor atual que é armazenado nesse ** \* **, dentro das restrições de memória que são especificadas por *ordem*.

## <a name="atomicfetch_sub"></a><a name="fetch_sub"></a> Atomic:: fetch_sub

Subtrai um valor especificado do valor armazenado.

```cpp
Ty atomic<Ty>::fetch_sub (
   Ty Value,
   memory_order Order = memory_order_seq_cst
) volatile noexcept;
Ty atomic<Ty>::fetch_sub (
   Ty Value,
   memory_order Order = memory_order_seq_cst
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Value*\
Um valor do tipo *Ty*.

*Ordene*\
Um `memory_order`.

### <a name="return-value"></a>Valor Retornado

Um objeto *Ty* que contém o resultado da subtração.

### <a name="remarks"></a>Comentários

O `fetch_sub` método executa uma operação Read-Modify-Write para subtrair *Value* atomicamente o valor do valor ** \* **armazenado, dentro das restrições de memória que são especificadas por *Order*.

## <a name="atomicfetch_xor"></a><a name="fetch_xor"></a> Atomic:: fetch_xor

Executa um OR exclusivo de bit a ** \* bit em um**valor e um valor existente que é armazenado nesse.

```cpp
Ty atomic<Ty>::fetch_xor (
   Ty Value,
   memory_order Order = memory_order_seq_cst
) volatile noexcept;
Ty atomic<Ty>::fetch_xor (
   Ty Value,
   memory_order Order = memory_order_seq_cst
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Value*\
Um valor do tipo *Ty*.

*Ordene*\
Um `memory_order`.

### <a name="return-value"></a>Valor Retornado

Um objeto *Ty* que contém o resultado do or exclusivo de bit a bit.

### <a name="remarks"></a>Comentários

O `fetch_xor` método executa uma operação Read-Modify-Write para substituir o valor armazenado dele ** \* ** por um OR exclusivo de bit e *Value* de-valor e o valor atual que é ** \* **armazenado nele e aplica as restrições de memória que são especificadas por *ordem*.

## <a name="atomicis_lock_free"></a><a name="is_lock_free"></a> Atomic:: is_lock_free

Especifica se as operações atômicas ** \* neste são de** bloqueio livre.

```cpp
bool is_lock_free() const volatile noexcept;
```

### <a name="return-value"></a>Valor Retornado

true se as operações atômicas sobre ** \* isso** estiverem livres de bloqueio; caso contrário, false.

### <a name="remarks"></a>Comentários

Um tipo atômico é livre de bloqueio se nenhuma operação atômica no tipo usar bloqueios.

## <a name="atomicload"></a><a name="load"></a> Atomic:: Load

Recupera o valor armazenado neste ** \* , dentro**das restrições de memória especificadas.

```cpp
Ty atomic::load(
   memory_order Order = memory_order_seq_cst
) const volatile noexcept;
Ty atomic::load(
   memory_order Order = memory_order_seq_cst
) const noexcept;
```

### <a name="parameters"></a>parâmetros

*Ordene*\
Um `memory_order`. A *ordem* não deve ser `memory_order_release` ou `memory_order_acq_rel` .

### <a name="return-value"></a>Valor Retornado

O valor recuperado que é armazenado neste ** \* .**

## <a name="atomicstore"></a><a name="store"></a> Atomic:: Store

Armazena um valor especificado.

```cpp
void atomic<Ty>::store(
   Ty Value,
   memory_order Order = memory_order_seq_cst
) volatile noexcept;
void atomic<Ty>::store(
   Ty Value,
   memory_order Order = memory_order_seq_cst
) noexcept;
```

### <a name="parameters"></a>parâmetros

*Value*\
Um objeto *Ty* .

*Ordene*\
Uma `memory_order` restrição.

### <a name="remarks"></a>Comentários

Essa função de membro armazena atomicamente o *valor* em **`*this`** , dentro das restrições de memória que são especificadas por *ordem*.

## <a name="see-also"></a>Confira também

[\<atomic>](../standard-library/atomic.md)\
[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
