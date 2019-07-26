---
title: Estrutura atomic
ms.date: 04/20/2018
f1_keywords:
- atomic/std::atomic
ms.assetid: 261628ed-7049-41ac-99b9-cfe49f696b44
ms.openlocfilehash: 1b3b60d71fcdf68fdf215820535c3bfb3d4dfb2b
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68456739"
---
# <a name="atomic-structure"></a>Estrutura atomic

Descreve um objeto que executa operações atômicas em um valor armazenado do tipo *Ty*.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct atomic;
```

## <a name="members"></a>Membros

|Membro|Descrição|
|----------|-----------------|
|**Construtor**||
|[atomic](#atomic)|Constrói um objeto atômico.|
|**Operadores**||
|[Atomic:: Operator Ty](#op_ty)|Lê e retorna o valor armazenado. ([Atomic:: Load](#load))|
|[atomic::operator=](#op_eq)|Usa um valor especificado para substituir o valor armazenado. ([atomic::store](#store))|
|[Atomic:: operador + +](#op_inc)|Incrementa o valor armazenado. Usado somente por especializações integrais e de ponteiro.|
|[atomic::operator+=](#op_add_eq)|Adiciona um valor especificado ao valor armazenado. Usado somente por especializações integrais e de ponteiro.|
|[atomic::operator--](#op_dec)|Decrementa o valor armazenado. Usado somente por especializações integrais e de ponteiro.|
|[atomic::operator-=](#op_sub_eq)|Subtrai um valor especificado do valor armazenado. Usado somente por especializações integrais e de ponteiro.|
|[atomic::operator&=](#op_and_eq)|Executa um valor bit e com um e o valor armazenado. Usado somente por especializações integrais.|
|[Atomic:: Operator&#124;=](#op_or_eq)|Executa uma operação OR em um valor especificado e o valor armazenado. Usado somente por especializações integrais.|
|[atomic::operator^=](#op_xor_eq)|Executa um OR exclusivo de bit a bit em um valor especificado e o valor armazenado. Usado somente por especializações integrais.|
|**Funções**||
|[compare_exchange_strong](#compare_exchange_strong)|Executa uma operação *atomic_compare_and_exchange* e **retorna** o resultado.|
|[compare_exchange_weak](#compare_exchange_weak)|Executa uma operação *weak_atomic_compare_and_exchange* e **retorna** o resultado.|
|[fetch_add](#fetch_add)|Adiciona um valor especificado ao valor armazenado.|
|[fetch_and](#fetch_and)|Executa um valor bit e com um e o valor armazenado.|
|[fetch_or](#fetch_or)|Executa uma operação OR em um valor especificado e o valor armazenado.|
|[fetch_sub](#fetch_sub)|Subtrai um valor especificado do valor armazenado.|
|[fetch_xor](#fetch_xor)|Executa um OR exclusivo de bit a bit em um valor especificado e o valor armazenado.|
|[is_lock_free](#is_lock_free)|Especifica se as operações atômicas **neste são de** *bloqueio livre*. Um tipo atômico é *livre de bloqueio* se nenhuma operação atômica no tipo usar bloqueios.|
|[load](#load)|Lê e retorna o valor armazenado.|
|[repositório](#store)|Usa um valor especificado para substituir o valor armazenado.|

## <a name="remarks"></a>Comentários

O tipo *Ty* deve ser *trivialmente copiável*. Ou seja, o uso de [memcpy](../c-runtime-library/reference/memcpy-wmemcpy.md) para copiar seus bytes deve produzir um objeto *Ty* válido que compare igual ao objeto original. As funções de membro [compare_exchange_weak](#compare_exchange_weak) e [compare_exchange_strong](#compare_exchange_strong) usam [memcmp](../c-runtime-library/reference/memcmp-wmemcmp.md) para determinar se dois valores *Ty* são iguais. Essas funções não usarão um *Ty*definido `operator==`. As funções de membro `atomic` de `memcpy` usar para copiar valores do tipo *Ty*.

Uma especialização parcial **,\<Atomic \*Ty >** , existe para todos os tipos de ponteiro. A especialização permite a adição de um deslocamento para o valor do ponteiro gerenciado ou subtração de um deslocamento dele. As operações aritméticas usam um argumento do `ptrdiff_t` tipo e ajustam esse argumento de acordo com o tamanho de *Ty* para ser consistente com a aritmética de endereço comum.

Existe uma especialização para cada tipo integral, exceto **bool**. Cada especialização fornece um rico conjunto de métodos para operações aritméticas e lógicas atômicas.

||||
|-|-|-|
|**atomic\<char>**|**>\<de caracteres com sinal atômico**|**>\<de caracteres Atomic não assinados**|
|**atomic\<char16_t>**|**atomic\<char32_t>**|**atomic\<wchar_t>**|
|**atomic\<short>**|**>\<curto sem sinal atômico**|**atomic\<int>**|
|**>\<INT não assinados atômicos**|**atomic\<long>**|**>\<longo sem sinal atômico**|
|**>\<longo muito atômica**|**longo\<Long não assinado Atomic >**|

Especializações integrais são derivadas de tipos `atomic_integral` correspondentes. Por exemplo, **a\<> int não assinada atômica** é derivada `atomic_uint`de.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> atômica

**Namespace:** std

## <a name="atomic"></a>Atomic:: Atomic

Constrói um objeto atômico.

```cpp
atomic();
atomic( const atomic& );
atomic( Ty Value ) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Valor*\
Valor de inicialização.

### <a name="remarks"></a>Comentários

Objetos atômicos não podem ser copiados ou movidos.

Os objetos que são instanciações de\<Atomic*Ty*> podem ser inicializados somente pelo construtor que usa um argumento do tipo *Ty* e não usando a inicialização de agregação. No entanto, os objetos atomic_integral podem ser inicializados somente usando a inicialização de agregação.

```cpp
atomic<int> ai0 = ATOMIC_VAR_INIT(0);
atomic<int> ai1(0);
```

## <a name="op_ty"></a>Atomic:: Operator *Ty*

O operador para o tipo especificado para o modelo, Atomic\<*Ty*>. Recupera o valor armazenado neste  **\*.**

```cpp
atomic<Ty>::operator Ty() const volatile noexcept;
atomic<Ty>::operator Ty() const noexcept;
```

### <a name="remarks"></a>Comentários

Esse operador aplica o `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="op_eq"></a> atomic::operator=

Armazena um valor especificado.

```cpp
Ty operator=(
   Ty Value
) volatile noexcept;
Ty operator=(
   Ty Value
) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Valor*\
Um objeto *Ty* .

### <a name="return-value"></a>Valor de retorno

Retorna o *valor*.

## <a name="op_inc"></a>Atomic:: operador + +

Incrementa o valor armazenado. Usado somente por especializações integrais e de ponteiro.

```cpp
Ty atomic<Ty>::operator++(int) volatile noexcept;
Ty atomic<Ty>::operator++(int) noexcept;
Ty atomic<Ty>::operator++() volatile noexcept;
Ty atomic<Ty>::operator++() noexcept;
```

### <a name="return-value"></a>Valor de retorno

Os primeiros dois operadores retornam o valor incrementado; os dois últimos operadores retornam o valor antes do incremento. Os operadores usam o `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="op_add_eq"></a>Atomic:: Operator + =

Adiciona um valor especificado ao valor armazenado. Usado somente por especializações integrais e de ponteiro.

```cpp
Ty atomic<Ty>::operator+=(
   Ty Value
) volatile noexcept;
Ty atomic<Ty>::operator+=(
   Ty Value
) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Valor*\
Um valor integral ou de ponteiro.

### <a name="return-value"></a>Valor de retorno

Um objeto *Ty* que contém o resultado da adição.

### <a name="remarks"></a>Comentários

Esse operador usa o `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="op_dec"></a>Atomic:: Operator--

Decrementa o valor armazenado. Usado somente por especializações integrais e de ponteiro.

```cpp
Ty atomic<Ty>::operator--(int) volatile noexcept;
Ty atomic<Ty>::operator--(int) noexcept;
Ty atomic<Ty>::operator--() volatile noexcept;
Ty atomic<Ty>::operator--() noexcept;
```

### <a name="return-value"></a>Valor de retorno

Os primeiros dois operadores retornam o valor decrementado; os dois últimos operadores retornam o valor antes do decréscimo. Os operadores usam o `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="op_sub_eq"></a>Atomic:: Operator-=

Subtrai um valor especificado do valor armazenado. Usado somente por especializações integrais e de ponteiro.

```cpp
Ty atomic<Ty>::operator-=(
   Ty Value
) volatile noexcept;
Ty atomic<Ty>::operator-=(
   Ty Value
) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Valor*\
Um valor integral ou de ponteiro.

### <a name="return-value"></a>Valor de retorno

Um objeto *Ty* que contém o resultado da subtração.

### <a name="remarks"></a>Comentários

Esse operador usa o `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="op_and_eq"></a>& Atomic:: Operator =

Executa um valor bit e com um e o valor  **\*armazenado dele.** Usado somente por especializações integrais.

```cpp
atomic<Ty>::operator&= (
   Ty Value
) volatile noexcept;
atomic<Ty>::operator&= (
   Ty Value
) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Valor*\
Um valor do tipo *Ty*.

### <a name="return-value"></a>Valor de retorno

O resultado de e/.

### <a name="remarks"></a>Comentários

Esse operador executa uma operação de leitura-modificação-gravação para substituir o valor armazenado  **\*disso por um** bit e de *valor* e o valor atual que é armazenado neste  **\*, dentro**das restrições do `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="op_or_eq"></a>Atomic:: Operator&#124;=

Executa uma operação OR em um valor especificado e o valor armazenado disso  **\*.** Usado somente por especializações integrais.

```cpp
atomic<Ty>::operator|= (
   Ty Value
) volatile noexcept;
atomic<Ty>::operator|= (
   Ty Value
) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Valor*\
Um valor do tipo *Ty*.

### <a name="return-value"></a>Valor de retorno

O resultado da operação OR.

### <a name="remarks"></a>Comentários

Esse operador executa uma operação Read-Modify-Write para substituir o valor armazenado dele  **\*por um** *valor* de bits ou bit e o valor atual que é armazenado neste  **\*, dentro**das restrições do `memory_order_seq_cst`restrições de [memory_order](atomic-enums.md) .

## <a name="op_xor_eq"></a>Atomic:: Operator ^ =

Executa um OR exclusivo de bit a bit em um valor especificado e o valor armazenado  **\*disso.** Usado somente por especializações integrais.

```cpp
atomic<Ty>::operator^= (
   Ty Value
) volatile noexcept;
atomic<Ty>::operator^= (
   Ty Value
) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Valor*\
Um valor do tipo *Ty*.

### <a name="return-value"></a>Valor de retorno

O resultado do or exclusivo de bit a bit.

### <a name="remarks"></a>Comentários

Esse operador executa uma operação Read-Modify-Write para substituir o valor  **\*armazenado dele por** um OR exclusivo de *bit e de* -valor e o valor atual que é armazenado  **\*neste, dentro**das restrições do restrições de [memory_order.](atomic-enums.md) `memory_order_seq_cst`

## <a name="compare_exchange_strong"></a> atomic::compare_exchange_strong

Executa uma operação atômica de comparação e do Exchange sobre  **\*isso**.

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

### <a name="parameters"></a>Parâmetros

*Exp*\
Um valor do tipo *Ty*.

*Valor*\
Um valor do tipo *Ty*.

*Order1*\
Primeiro `memory_order` argumento.

*Order2*\
Segundo argumento `memory_order`.

### <a name="return-value"></a>Valor de retorno

Um **bool** que indica o resultado da comparação de valor.

### <a name="remarks"></a>Comentários

Essa operação atômica de comparação e do Exchange compara o valor que é  **\*armazenado** com *exp*. Se os valores forem iguais, a operação substituirá o valor que é armazenado  **\*com** o *valor* usando uma operação Read-Modify-Write e aplicando as restrições de ordem de memória que são especificadas por *Order1*. Se os valores não forem iguais, a operação usará o valor que é armazenado  **\*nele para** substituir *exp* e aplica as restrições de ordem de memória que são especificadas por *Order2*.

Sobrecargas que não têm um segundo `memory_order` usam um *Order2* implícito com base no valor de *Order1*. Se *Order1* for `memory_order_acq_rel`, *Order2* será `memory_order_acquire`. Se *Order1* for `memory_order_release`, *Order2* será `memory_order_relaxed`. Em todos os outros casos, *Order2* é igual a *Order1*.

Para sobrecargas que usam dois `memory_order` parâmetros, o valor de *Order2* não deve ser `memory_order_release` ou `memory_order_acq_rel`e não deve ser mais forte que o valor de *Order1*.

## <a name="compare_exchange_weak"></a> atomic::compare_exchange_weak

Executa uma operação de comparação atômica frágil e do Exchange sobre  **\*isso**.

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

### <a name="parameters"></a>Parâmetros

*Exp*\
Um valor do tipo *Ty*.

*Valor*\
Um valor do tipo *Ty*.

*Order1*\
Primeiro `memory_order` argumento.

*Order2*\
Segundo argumento `memory_order`.

### <a name="return-value"></a>Valor de retorno

Um **bool** que indica o resultado da comparação de valor.

### <a name="remarks"></a>Comentários

Essa operação atômica de comparação e do Exchange compara o valor que é  **\*armazenado** com *exp*. Se os valores forem iguais, a operação substituirá o valor que é armazenado  **\*com** o*valor* usando uma operação Read-Modify-Write e aplicando as restrições de ordem de memória que são especificadas por *Order1*. Se os valores não forem iguais, a operação usará o valor que é armazenado  **\*nele para** substituir *exp* e aplica as restrições de ordem de memória que são especificadas por *Order2*.

Uma operação de comparação atômica fraca e do Exchange executa uma troca se os valores comparados forem iguais. Se os valores não forem iguais, a operação não será garantida para executar uma troca.

Sobrecargas que não têm um segundo `memory_order` usam um *Order2* implícito com base no valor de *Order1*. Se *Order1* for `memory_order_acq_rel`, *Order2* será `memory_order_acquire`. Se *Order1* for `memory_order_release`, *Order2* será `memory_order_relaxed`. Em todos os outros casos, *Order2* é igual a *Order1*.

Para sobrecargas que usam dois `memory_order` parâmetros, o valor de *Order2* não deve ser `memory_order_release` ou `memory_order_acq_rel`e não deve ser mais forte que o valor de *Order1*.

## <a name="exchange"></a> atomic::exchange

Usa um valor especificado para substituir o valor  **\*armazenado disso.**

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

### <a name="parameters"></a>Parâmetros

*Valor*\
Um valor do tipo *Ty*.

*Ordene*\
Um `memory_order`.

### <a name="return-value"></a>Valor de retorno

O valor  **\*armazenado disso antes da** troca.

### <a name="remarks"></a>Comentários

Esta operação executa uma operação Read-Modify-Write para usar o *valor* para substituir o valor armazenado  **\*nele, dentro**das restrições de memória que são especificadas por *Order*.

## <a name="fetch_add"></a> atomic::fetch_add

Busca o valor  **\*armazenado nele e**, em seguida, adiciona um valor especificado ao valor armazenado.

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

### <a name="parameters"></a>Parâmetros

*Valor*\
Um valor do tipo *Ty*.

*Ordene*\
Um `memory_order`.

### <a name="return-value"></a>Valor de retorno

Um objeto *Ty* que contém o valor armazenado nele  **\*antes da** adição.

### <a name="remarks"></a>Comentários

O `fetch_add` método executa uma operação Read-Modify-Write para adicionar  **\*** o *valor* atomicamente ao valor armazenado e aplica as restrições de memória especificadas por *Order*.

## <a name="fetch_and"></a> atomic::fetch_and

Executa um valor de bit e um e um valor existente que é armazenado nesse  **\*.**

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

### <a name="parameters"></a>Parâmetros

*Valor*\
Um valor do tipo *Ty*.

*Ordene*\
Um `memory_order`.

### <a name="return-value"></a>Valor de retorno

Um objeto *Ty* que contém o resultado da e/.

### <a name="remarks"></a>Comentários

O `fetch_and` método executa uma operação Read-Modify-Write para substituir o valor armazenado dele  **\*por um** bit e de *valor* e o valor atual que é armazenado  **\*nele, dentro**da memória restrições que são especificadas por *ordem*.

## <a name="fetch_or"></a>Atomic:: fetch_or

Executa uma operação OR em um valor e um valor existente que é armazenado nesse  **\*.**

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

### <a name="parameters"></a>Parâmetros

*Valor*\
Um valor do tipo *Ty*.

*Ordene*\
Um `memory_order`.

### <a name="return-value"></a>Valor de retorno

Um objeto *Ty* que contém o resultado da operação OR.

### <a name="remarks"></a>Comentários

O `fetch_or` método executa uma operação Read-Modify-Write para substituir o valor armazenado dele  **\*por um** *valor* de bits ou bit e o valor atual que é armazenado nele  **\*, dentro**da memória restrições que são especificadas por *ordem*.

## <a name="fetch_sub"></a> atomic::fetch_sub

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

### <a name="parameters"></a>Parâmetros

*Valor*\
Um valor do tipo *Ty*.

*Ordene*\
Um `memory_order`.

### <a name="return-value"></a>Valor de retorno

Um objeto *Ty* que contém o resultado da subtração.

### <a name="remarks"></a>Comentários

O `fetch_sub` método executa uma operação Read-Modify-Write para *subtrair* atomicamente  **\*** o valor do valor armazenado, dentro das restrições de memória que são especificadas por *Order*.

## <a name="fetch_xor"></a>Atomic:: fetch_xor

Executa um OR exclusivo de bit a bit em um valor e um valor existente que é armazenado  **\*nesse.**

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

### <a name="parameters"></a>Parâmetros

*Valor*\
Um valor do tipo *Ty*.

*Ordene*\
Um `memory_order`.

### <a name="return-value"></a>Valor de retorno

Um objeto *Ty* que contém o resultado do or exclusivo de bit a bit.

### <a name="remarks"></a>Comentários

O `fetch_xor` método executa uma operação Read-Modify-Write para substituir o valor  **\*armazenado dele por** um OR exclusivo de bit e de *valor* e o valor atual que é armazenado  **\*nesse e**aplica o restrições de memória que são especificadas por *ordem*.

## <a name="is_lock_free"></a>Atomic:: is_lock_free

Especifica se as operações atômicas  **\*neste são de** bloqueio livre.

```cpp
bool is_lock_free() const volatile noexcept;
```

### <a name="return-value"></a>Valor de retorno

true se as operações atômicas sobre  **\*isso** estiverem livres de bloqueio; caso contrário, false.

### <a name="remarks"></a>Comentários

Um tipo atômico é livre de bloqueio se nenhuma operação atômica nesse tipo usar bloqueios.

## <a name="load"></a>Atomic:: Load

Recupera o valor armazenado neste  **\*, dentro**das restrições de memória especificadas.

```cpp
Ty atomic::load(
   memory_order Order = memory_order_seq_cst
) const volatile noexcept;
Ty atomic::load(
   memory_order Order = memory_order_seq_cst
) const noexcept;
```

### <a name="parameters"></a>Parâmetros

*Ordene*\
Um `memory_order`. A *ordem* não deve `memory_order_release` ser `memory_order_acq_rel`ou.

### <a name="return-value"></a>Valor de retorno

O valor recuperado que é armazenado neste  **\*.**

## <a name="store"></a>Atomic:: Store

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

### <a name="parameters"></a>Parâmetros

*Valor*\
Um objeto *Ty* .

*Ordene*\
Uma `memory_order` restrição.

### <a name="remarks"></a>Comentários

Essa função de membro armazena atomicamente o `*this` *valor* em, dentro das restrições de memória que são especificadas por *ordem*.

## <a name="see-also"></a>Consulte também

[\<atomic>](../standard-library/atomic.md)\
[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
