---
title: Estrutura atômica | Microsoft Docs
ms.custom: ''
ms.date: 04/20/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- atomic/std::atomic
dev_langs:
- C++
ms.assetid: 261628ed-7049-41ac-99b9-cfe49f696b44
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0e5982fc303362a9636c4bf1b0e2d89c6aa05031
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38962352"
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
|[operador Atomic:: Ty](#op_ty)|Lê e retorna o valor armazenado. ([Atomic:: Load](#load))|
|[operador Atomic:: =](#op_eq)|Usa um valor especificado para substituir o valor armazenado. ([atomic::store](#store))|
|[operador Atomic:: + +](#op_inc)|Incrementa o valor armazenado. Usado somente por especializações integrais e de ponteiro.|
|[operador Atomic:: =](#op_add_eq)|Adiciona um valor especificado ao valor armazenado. Usado somente por especializações integrais e de ponteiro.|
|[operador Atomic:: –](#op_dec)|Decrementa o valor armazenado. Usado somente por especializações integrais e de ponteiro.|
|[operador Atomic:: =](#op_sub_eq)|Subtrai um valor especificado do valor armazenado. Usado somente por especializações integrais e de ponteiro.|
|[operador Atomic:: & =](#op_and_eq)|Executa um bit a bit e de um valor especificado e o valor armazenado. Usado somente por especializações integrais.|
|[operador Atomic::&#124;=](#op_or_eq)|Executa um bit a bit ou em um valor especificado e o valor armazenado. Usado somente por especializações integrais.|
|[operador Atomic:: ^ =](#op_xor_eq)|Executa um exclusivo bit a bit ou em um valor especificado e o valor armazenado. Usado somente por especializações integrais.|
|**Funções**||
|[compare_exchange_strong](#compare_exchange_strong)|Executa um *atomic_compare_and_exchange* operação no **isso** e retorna o resultado.|
|[compare_exchange_weak](#compare_exchange_weak)|Executa um *weak_atomic_compare_and_exchange* operação no **isso** e retorna o resultado.|
|[fetch_add](#fetch_add)|Adiciona um valor especificado ao valor armazenado.|
|[fetch_and](#fetch_and)|Executa um bit a bit e de um valor especificado e o valor armazenado.|
|[fetch_or](#fetch_or)|Executa um bit a bit ou em um valor especificado e o valor armazenado.|
|[fetch_sub](#fetch_sub)|Subtrai um valor especificado do valor armazenado.|
|[fetch_xor](#fetch_xor)|Executa um exclusivo bit a bit ou em um valor especificado e o valor armazenado.|
|[is_lock_free](#is_lock_free)|Especifica se operações atômicas **isso** são *livre de bloqueio*. Um tipo atômico é *livre de bloqueio* se nenhuma operação atômica no tipo usar bloqueios.|
|[load](#load)|Lê e retorna o valor armazenado.|
|[repositório](#store)|Usa um valor especificado para substituir o valor armazenado.|

## <a name="remarks"></a>Comentários

O tipo *Ty* deve ser *trivialmente copiável*. Ou seja, usando [memcpy](../c-runtime-library/reference/memcpy-wmemcpy.md) copiar seus bytes deve produzir uma validade *Ty* objeto que compara como igual ao objeto original. O [compare_exchange_weak](#compare_exchange_weak) e [compare_exchange_strong](#compare_exchange_strong) funções membro usam [memcmp](../c-runtime-library/reference/memcmp-wmemcmp.md) para determinar se dois *Ty* valores são iguais. Essas funções não usará uma *Ty*-definido `operator==`. As funções membro da `atomic` usar `memcpy` para copiar valores do tipo *Ty*.

Uma especialização parcial, **atômica\<Ty \* >** , existe para todos os tipos de ponteiro. A especialização permite a adição de um deslocamento para o valor do ponteiro gerenciado ou subtração de um deslocamento dele. Operações aritméticas obtêm um argumento do tipo `ptrdiff_t` e ajustam esse argumento de acordo com o tamanho de *Ty* para ser consistente com endereço comum aritmético.

Existe uma especialização para cada tipo integral, exceto **bool**. Cada especialização fornece um rico conjunto de métodos para operações aritméticas e lógicas atômicas.

||||
|-|-|-|
|**Atomic\<char >**|**Atomic\<assinado char >**|**Atomic\<unsigned char >**|
|**Atomic\<char16_t >**|**Atomic\<char32_t >**|**Atomic\<wchar_t >**|
|**Atomic\<curta >**|**Atomic\<unsigned short >**|**Atomic\<int >**|
|**Atomic\<unsigned int >**|**Atomic\<longo >**|**Atomic\<unsigned long >**|
|**Atomic\<longo longo >**|**Atomic\<longo longo sem sinal >**|

Especializações integrais são derivadas de tipos `atomic_integral` correspondentes. Por exemplo, **atômica\<unsigned int >** é derivado de `atomic_uint`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<atomic >

**Namespace:** std

## <a name="atomic"></a> Atomic:: Atomic

Constrói um objeto atômico.

```cpp
atomic();
atomic( const atomic& );
atomic( Ty Value ) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Value*<br/>
Valor de inicialização.

### <a name="remarks"></a>Comentários

Os objetos atômicos não podem ser copiados ou movidos.

Objetos que são instanciações de atômicas\<*Ty*> podem ser inicializados somente pelo construtor que aceita um argumento do tipo *Ty* e não usando a inicialização de agregação. No entanto, objetos atomic_integral podem ser inicializados somente usando a inicialização de agregação.

```cpp
atomic<int> ai0 = ATOMIC_VAR_INIT(0);
atomic<int> ai1(0);
```

## <a name="op_ty"></a> operador Atomic:: *Ty*

O operador para o tipo especificado para o modelo atômico\<*Ty*>. Recupera o valor armazenado em  **\*isso**.

```cpp
atomic<Ty>::operator Ty() const volatile noexcept;
atomic<Ty>::operator Ty() const noexcept;
```

### <a name="remarks"></a>Comentários

Esse operador aplica-se a `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="op_eq"></a> operador Atomic:: =

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

*Value*<br/>
Um *Ty* objeto.

### <a name="return-value"></a>Valor de retorno

Retorna *valor*.

## <a name="op_inc"></a> operador Atomic:: + +

Incrementa o valor armazenado. Usado somente por especializações integrais e de ponteiro.

```cpp
Ty atomic<Ty>::operator++(int) volatile noexcept;
Ty atomic<Ty>::operator++(int) noexcept;
Ty atomic<Ty>::operator++() volatile noexcept;
Ty atomic<Ty>::operator++() noexcept;
```

### <a name="return-value"></a>Valor de retorno

Os primeiros dois operadores retornam o valor incrementado; os últimos dois operadores retornam o valor antes do incremento. Usam os operadores de `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="op_add_eq"></a> operador Atomic:: =

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

*Value*<br/>
Um valor integral ou ponteiro.

### <a name="return-value"></a>Valor de retorno

Um *Ty* objeto que contém o resultado da adição.

### <a name="remarks"></a>Comentários

Esse operador usa o `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="op_dec"></a> operador Atomic:: –

Decrementa o valor armazenado. Usado somente por especializações integrais e de ponteiro.

```cpp
Ty atomic<Ty>::operator--(int) volatile noexcept;
Ty atomic<Ty>::operator--(int) noexcept;
Ty atomic<Ty>::operator--() volatile noexcept;
Ty atomic<Ty>::operator--() noexcept;
```

### <a name="return-value"></a>Valor de retorno

Os primeiros dois operadores retornam o valor diminuído; os últimos dois operadores retornam o valor antes do decremento. Usam os operadores de `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="op_sub_eq"></a> operador Atomic:: =

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

*Value*<br/>
Um valor integral ou ponteiro.

### <a name="return-value"></a>Valor de retorno

Um *Ty* objeto que contém o resultado da subtração.

### <a name="remarks"></a>Comentários

Esse operador usa o `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="op_and_eq"></a> operador Atomic:: & =

Executa um bit a bit em um valor especificado e o valor armazenado de  **\*isso**. Usado somente por especializações integrais.

```cpp
atomic<Ty>::operator&= (
   Ty Value
) volatile noexcept;
atomic<Ty>::operator&= (
   Ty Value
) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Value*<br/>
Um valor do tipo *Ty*.

### <a name="return-value"></a>Valor de retorno

O resultado da operação bit a bit e.

### <a name="remarks"></a>Comentários

Este operador executa uma operação de leitura, gravação e alteração para substituir o valor armazenado de  **\*isso** com um bit a bit e de *valor* e o valor atual armazenado em  **\*isso**, dentro das restrições da `memory_order_seq_cst` [memory_order](atomic-enums.md).

## <a name="op_or_eq"></a> operador Atomic::&#124;=

Executa um bit a bit ou em um valor especificado e o valor armazenado de  **\*isso**. Usado somente por especializações integrais.

```cpp
atomic<Ty>::operator|= (
   Ty Value
) volatile noexcept;
atomic<Ty>::operator|= (
   Ty Value
) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Value*<br/>
Um valor do tipo *Ty*.

### <a name="return-value"></a>Valor de retorno

O resultado da operação bit a bit ou.

### <a name="remarks"></a>Comentários

Este operador executa uma operação de leitura, gravação e alteração para substituir o valor armazenado de  **\*isso** com um bit a bit ou de *valor* e o valor atual armazenado em  **\*isso**, dentro das restrições da `memory_order_seq_cst` [memory_order](atomic-enums.md) restrições.

## <a name="op_xor_eq"></a> operador Atomic:: ^ =

Executa um exclusivo bit a bit ou em um valor especificado e o valor armazenado de  **\*isso**. Usado somente por especializações integrais.

```cpp
atomic<Ty>::operator^= (
   Ty Value
) volatile noexcept;
atomic<Ty>::operator^= (
   Ty Value
) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Value*<br/>
Um valor do tipo *Ty*.

### <a name="return-value"></a>Valor de retorno

O resultado de bit a bit exclusivo ou.

### <a name="remarks"></a>Comentários

Este operador executa uma operação de leitura, gravação e alteração para substituir o valor armazenado de  **\*isso** com um bit a bit exclusivo ou de *valor* e o valor atual armazenado em  **\*isso**, dentro das restrições da `memory_order_seq_cst` [memory_order](atomic-enums.md) restrições.

## <a name="compare_exchange_strong"></a> Atomic:: compare_exchange_strong

Executa uma operação de comparação e troca atômica em  **\*isso**.

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

*Exp*<br/>
Um valor do tipo *Ty*.

*Value*<br/>
Um valor do tipo *Ty*.

*Diffgr:ID="Order1*<br/>
Primeiro `memory_order` argumento.

*Order2*<br/>
Segundo argumento `memory_order`.

### <a name="return-value"></a>Valor de retorno

Um **bool** que indica o resultado da comparação de valor.

### <a name="remarks"></a>Comentários

Essa operação de comparação e troca atômica compara o valor armazenado no  **\*isso** com *Exp*. Se os valores forem iguais, a operação substitui o valor que é armazenado no  **\*isso** com *valor* usando uma operação de leitura, gravação e alteração e aplicando as restrições de ordem de memória são especificado pelo *diffgr:ID="Order1*. Se os valores não forem iguais, a operação usa o valor que é armazenado no  **\*isso** substituir *Exp* e aplica as restrições de ordem de memória que são especificadas pelo *Order2* .

Sobrecargas que não têm uma segunda `memory_order` usar implícito *Order2* que se baseia no valor de *diffgr:ID="Order1*. Se *diffgr:ID="Order1* é `memory_order_acq_rel`, *Order2* é `memory_order_acquire`. Se *diffgr:ID="Order1* é `memory_order_release`, *Order2* é `memory_order_relaxed`. Em todos os outros casos, *Order2* é igual a *diffgr:ID="Order1*.

Para sobrecargas que usam dois `memory_order` parâmetros, o valor da *Order2* não deve ser `memory_order_release` ou `memory_order_acq_rel`e não deve ser maior que o valor de *diffgr:ID="Order1*.

## <a name="compare_exchange_weak"></a> Atomic:: compare_exchange_weak

Executa uma operação de comparação e troca atômica fraca em  **\*isso**.

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

*Exp*<br/>
Um valor do tipo *Ty*.

*Value*<br/>
Um valor do tipo *Ty*.

*Diffgr:ID="Order1*<br/>
Primeiro `memory_order` argumento.

*Order2*<br/>
Segundo argumento `memory_order`.

### <a name="return-value"></a>Valor de retorno

Um **bool** que indica o resultado da comparação de valor.

### <a name="remarks"></a>Comentários

Essa operação de comparação e troca atômica compara o valor armazenado no  **\*isso** com *Exp*. Se os valores forem iguais, a operação substitui o valor que é armazenado no  **\*isso** com*valor* usando uma operação de leitura, gravação e alteração e aplicando as restrições de ordem de memória são especificado pelo *diffgr:ID="Order1*. Se os valores não forem iguais, a operação usa o valor que é armazenado no  **\*isso** substituir *Exp* e aplica as restrições de ordem de memória que são especificadas pelo *Order2* .

Comparar um atômica fraca e operação do exchange executará uma troca se os valores comparados forem iguais. Se os valores não forem iguais, a operação não é garantida para executar uma troca.

Sobrecargas que não têm uma segunda `memory_order` usar implícito *Order2* que se baseia no valor de *diffgr:ID="Order1*. Se *diffgr:ID="Order1* é `memory_order_acq_rel`, *Order2* é `memory_order_acquire`. Se *diffgr:ID="Order1* é `memory_order_release`, *Order2* é `memory_order_relaxed`. Em todos os outros casos, *Order2* é igual a *diffgr:ID="Order1*.

Para sobrecargas que usam dois `memory_order` parâmetros, o valor da *Order2* não deve ser `memory_order_release` ou `memory_order_acq_rel`e não deve ser maior que o valor de *diffgr:ID="Order1*.

## <a name="exchange"></a> Atomic:: Exchange

Usa um valor especificado para substituir o valor armazenado de  **\*isso**.

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

*Value*<br/>
Um valor do tipo *Ty*.

*Ordem*<br/>
Um `memory_order`.

### <a name="return-value"></a>Valor de retorno

O valor armazenado de  **\*isso** antes da troca.

### <a name="remarks"></a>Comentários

Esta operação executa uma operação de leitura, gravação e alteração para usar *valor* para substituir o valor armazenado em  **\*isso**, dentro das restrições de memória que são especificadas pelo  *Ordem*.

## <a name="fetch_add"></a> Atomic:: fetch_add

Busca o valor armazenado no  **\*isso**e, em seguida, adiciona um valor especificado para o valor armazenado.

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

*Value*<br/>
Um valor do tipo *Ty*.

*Ordem*<br/>
Um `memory_order`.

### <a name="return-value"></a>Valor de retorno

Um *Ty* que contém o valor armazenado no objeto  **\*isso** antes da adição.

### <a name="remarks"></a>Comentários

O `fetch_add` método executa uma operação de leitura-modify-write para adicionar atomicamente *valor* para o valor armazenado na  **\*isso**e aplica as restrições de memória que são especificadas pelo *Ordem*.

## <a name="fetch_and"></a> Atomic:: fetch_and

Executa um bit a bit e em um valor e um valor existente que é armazenado no  **\*isso**.

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

*Value*<br/>
Um valor do tipo *Ty*.

*Ordem*<br/>
Um `memory_order`.

### <a name="return-value"></a>Valor de retorno

Um *Ty* objeto que contém o resultado de bit a bit e.

### <a name="remarks"></a>Comentários

O `fetch_and` método executa uma operação de leitura, gravação e alteração para substituir o valor armazenado de  **\*isso** com um bit a bit e de *valor* e o valor atual armazenado no  **\*isso**, dentro das restrições de memória que são especificadas por *ordem*.

## <a name="fetch_or"></a> Atomic:: fetch_or

Executa um bit a bit ou em um valor e um valor existente que é armazenado no  **\*isso**.

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

*Value*<br/>
Um valor do tipo *Ty*.

*Ordem*<br/>
Um `memory_order`.

### <a name="return-value"></a>Valor de retorno

Um *Ty* objeto que contém o resultado de bit a bit ou.

### <a name="remarks"></a>Comentários

O `fetch_or` método executa uma operação de leitura, gravação e alteração para substituir o valor armazenado de  **\*isso** com um bit a bit ou de *valor* e o valor atual armazenado no  **\*isso**, dentro das restrições de memória que são especificadas por *ordem*.

## <a name="fetch_sub"></a> Atomic:: fetch_sub

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

*Value*<br/>
Um valor do tipo *Ty*.

*Ordem*<br/>
Um `memory_order`.

### <a name="return-value"></a>Valor de retorno

Um *Ty* objeto que contém o resultado da subtração.

### <a name="remarks"></a>Comentários

O `fetch_sub` método executa uma operação de leitura, gravação e alteração para subtrair atomicamente *valor* do valor armazenado na  **\*isso**, dentro das restrições de memória que são especificadas pelo *Ordem*.

## <a name="fetch_xor"></a> Atomic:: fetch_xor

Executa um exclusivo bit a bit ou em um valor e um valor existente que é armazenado no  **\*isso**.

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

*Value*<br/>
Um valor do tipo *Ty*.

*Ordem*<br/>
Um `memory_order`.

### <a name="return-value"></a>Valor de retorno

Um *Ty* objeto que contém o resultado de bit a bit exclusivo ou.

### <a name="remarks"></a>Comentários

O `fetch_xor` método executa uma operação de leitura, gravação e alteração para substituir o valor armazenado de  **\*isso** com um bit a bit exclusivo ou de *valor* e o valor atual armazenado em  **\*isso**e aplica as restrições de memória que são especificadas por *ordem*.

## <a name="is_lock_free"></a> Atomic:: is_lock_free

Especifica se operações atômicas  **\*isso** são sem bloqueio.

```cpp
bool is_lock_free() const volatile noexcept;
```

### <a name="return-value"></a>Valor de retorno

True se atômica operações nos  **\*isso** são bloqueio livre; caso contrário, false.

### <a name="remarks"></a>Comentários

Um tipo atômico será livre de bloqueio se nenhuma operação atômica no tipo usar bloqueios.

## <a name="load"></a> Atomic:: Load

Recupera o valor armazenado em  **\*isso**, dentro das restrições de memória especificado.

```cpp
Ty atomic::load(
   memory_order Order = memory_order_seq_cst
) const volatile noexcept;
Ty atomic::load(
   memory_order Order = memory_order_seq_cst
) const noexcept;
```

### <a name="parameters"></a>Parâmetros

*Ordem*<br/>
Um `memory_order`. *Ordem* não deve ser `memory_order_release` ou `memory_order_acq_rel`.

### <a name="return-value"></a>Valor de retorno

O valor recuperado armazenado em  **\*isso**.

## <a name="store"></a> Atomic:: Store

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

*Value*<br/>
Um *Ty* objeto.

*Ordem*<br/>
Um `memory_order` restrição.

### <a name="remarks"></a>Comentários

Essa função membro armazena atomicamente *valor* na `*this`, dentro das restrições de memória que são especificadas por *ordem*.

## <a name="see-also"></a>Consulte também

[\<atomic>](../standard-library/atomic.md)<br/>
[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
