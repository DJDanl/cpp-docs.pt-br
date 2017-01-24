---
title: "&lt;atomic&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "<atomic>"
  - "atomic/std::atomic_int_least32_t"
  - "atomic/std::atomic_ullong"
  - "atomic/std::atomic_ptrdiff_t"
  - "atomic/std::atomic_char16_t"
  - "atomic/std::atomic_schar"
  - "atomic/std::atomic_ulong"
  - "atomic/std::atomic_uint_fast32_t"
  - "atomic/std::atomic_uint8_t"
  - "atomic/std::atomic_int32_t"
  - "atomic/std::atomic_uint_fast64_t"
  - "atomic/std::atomic_uint32_t"
  - "atomic/std::atomic_int16_t"
  - "atomic/std::atomic_uintmax_t"
  - "atomic/std::atomic_intmax_t"
  - "atomic/std::atomic_long"
  - "atomic/std::atomic_int"
  - "atomic/std::atomic_uint_least8_t"
  - "atomic/std::atomic_size_t"
  - "atomic/std::atomic_uint_fast16_t"
  - "atomic/std::atomic_wchar_t"
  - "atomic/std::atomic_int_fast64_t"
  - "atomic/std::atomic_uint_fast8_t"
  - "atomic/std::atomic_int_fast8_t"
  - "atomic/std::atomic_intptr_t"
  - "atomic/std::atomic_uint"
  - "atomic/std::atomic_uint16_t"
  - "atomic/std::atomic_char32_t"
  - "atomic/std::atomic_uint64_t"
  - "atomic/std::atomic_ushort"
  - "atomic/std::atomic_int_least16_t"
  - "atomic/std::atomic_char"
  - "atomic/std::atomic_uint_least32_t"
  - "atomic/std::atomic_uintptr_t"
  - "atomic/std::atomic_short"
  - "atomic/std::atomic_llong"
  - "atomic/std::atomic_uint_least16_t"
  - "atomic/std::atomic_int_fast16_t"
  - "atomic/std::atomic_int_least8_t"
  - "atomic/std::atomic_int_least64_t"
  - "atomic/std::atomic_int_fast32_t"
  - "atomic/std::atomic_uchar"
  - "atomic/std::atomic_int8_t"
  - "atomic/std::atomic_int64_t"
  - "atomic/std::atomic_uint_least64_t"
dev_langs: 
  - "C++"
ms.assetid: e79a6b9f-52ff-48da-9554-654c4e1999f6
caps.latest.revision: 22
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;atomic&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define classes e classes de modelo para usar o para criar os tipos que dão suporte a operações atômicas.  
  
## Sintaxe  
  
```cpp  
#include <atomic>  
```  
  
## Comentários  
  
> [!NOTE]
>  No código que é construído usando **\/clr** ou **\/clr:pure**, este cabeçalho é bloqueado.  
  
 Uma operação atômica tem duas propriedades de chave que o ajudam a usar vários threads para manipular corretamente um objeto sem usar bloqueios de mutex.  
  
-   Como uma operação é atômica indivisível, uma segunda operação atômica no mesmo objeto de um thread diferente pode obter o estado do objeto apenas antes ou depois da primeira operação atômica.  
  
-   Com base em seu argumento de [memory\_order](../Topic/memory_order%20Enum.md) , uma operação atômica estabelece a ordenação requisitos para a visibilidade dos efeitos de outras operações atômicas no mesmo thread.  Consequentemente, inibe otimizações de compilador que violam os requisitos de solicitação.  
  
 Em algumas plataformas, talvez não seja possível implementar operações com eficiência atômicas para alguns tipos sem usar bloqueios de `mutex` .  Um tipo atômico é *lock\-partition\-id&gt livre* se nenhuma operação atômica nesse uso do tipo bloqueios.  
  
 A classe [atomic\_flag](../Topic/atomic_flag%20Structure.md) fornece um tipo atômico mínimo que contém um sinalizador de `bool` .  As operações são sempre lock\-partition\-id&gt livres.  
  
 A classe `atomic<Ty>` do modelo armazena um objeto do tipo `Ty` de argumento e fornece acesso ao do valor atômico armazenado.  Você pode criar\-lo uma instância do com qualquer tipo que possa ser copiado usando [memcpy](../c-runtime-library/reference/memcpy-wmemcpy.md) e ser testado para igualdade usando [memcmp](../c-runtime-library/reference/memcmp-wmemcmp.md).  Em particular, você pode usá\-lo com tipos definidos pelo usuário que satisfazem esses requisitos e, em muitos casos, com tipos de ponto flutuante.  
  
 O modelo também tem um conjunto de especializações para tipos integral e de uma especialização parcial para ponteiros.  Essas especializações fornecem as operações adicionais que não estão disponíveis no modelo primário.  
  
## Especializações do ponteiro  
 As especializações parciais de `atomic<Ty *>` se aplicam a todos os tipos de ponteiro.  Fornece métodos para aritmética do ponteiro.  
  
## Especializações integrais  
 As especializações de `atomic<integral>` se aplicam a todos os tipos integrais.  Fornece as operações adicionais que não estão disponíveis no modelo primário.  
  
 Cada tipo de `atomic<integral>` tem uma macro correspondente que você pode usar em `if directive` para determinar em tempo de compilação se as operações desse tipo são lock\-partition\-id&gt livres.  Se o valor de macro é zero, as operações do tipo não são lock\-partition\-id&gt livres.  Se o valor for 1, as operações poderão ser lock\-partition\-id&gt livres, e uma verificação de tempo de execução é necessária.  Se o valor for 2, as operações são lock\-partition\-id&gt livres.  Você pode usar a função `atomic_is_lock_free` para determinar o tempo de execução se as operações do tipo são lock\-partition\-id&gt livres.  
  
 Para cada um dos tipos integrais, há um tipo atômico nomeado correspondentes que gerencia um objeto desse tipo integral.  Cada tipo de `atomic_integral` tem o mesmo conjunto de funções de membro que a instanciação correspondente de `atomic<Ty>` e pode ser passado para qualquer uma das funções de membro não atômicas.  
  
|tipo de`atomic_integral`|Tipo integral|macro de`atomic_is_lock_free`|  
|------------------------------|-------------------|-----------------------------------|  
|`atomic_char`|`char`|`ATOMIC_CHAR_LOCK_FREE`|  
|`atomic_schar`|`signed char`|`ATOMIC_CHAR_LOCK_FREE`|  
|`atomic_uchar`|`unsigned char`|`ATOMIC_CHAR_LOCK_FREE`|  
|`atomic_char16_t`|`char16_t`|`ATOMIC_CHAR16_T_LOCK_FREE`|  
|`atomic_char32_t`|`char32_t`|`ATOMIC_CHAR32_T_LOCK_FREE`|  
|`atomic_wchar_t`|`wchar_t`|`ATOMIC_WCHAR_T_LOCK_FREE`|  
|`atomic_short`|`short`|`ATOMIC_SHORT_LOCK_FREE`|  
|`atomic_ushort`|`unsigned short`|`ATOMIC_SHORT_LOCK_FREE`|  
|`atomic_int`|`int`|`ATOMIC_INT_LOCK_FREE`|  
|`atomic_uint`|`unsigned int`|`ATOMIC_INT_LOCK_FREE`|  
|`atomic_long`|`long`|`ATOMIC_LONG_LOCK_FREE`|  
|`atomic_ulong`|`unsigned long`|`ATOMIC_LONG_LOCK_FREE`|  
|`atomic_llong`|`long long`|`ATOMIC_LLONG_LOCK_FREE`|  
|`atomic_ullong`|`unsigned long long`|`ATOMIC_LLONG_LOCK_FREE`|  
  
 Os nomes de Typedef existem para especializações do modelo atômico para alguns dos tipos definidos no cabeçalho \<inttypes.h.\>  
  
|Tipo atômico|Nome do Typedef|  
|------------------|---------------------|  
|`atomic_int8_t`|`atomic<int8_t>`|  
|`atomic_uint8_t`|`atomic<uint8_t>`|  
|`atomic_int16_t`|`atomic<int16_t>`|  
|`atomic_uint16_t`|`atomic<uint16_t>`|  
|`atomic_int32_t`|`atomic<int32_t>`|  
|`atomic_uint32_t`|`atomic<uint32_t>`|  
|`atomic_int64_t`|`atomic<int64_t>`|  
|`atomic_uint64_t`|`atomic<uint64_t>`|  
|`atomic_int_least8_t`|`atomic<int_least8_t>`|  
|`atomic_uint_least8_t`|`atomic<uint_least8_t>`|  
|`atomic_int_least16_t`|`atomic<int_least16_t>`|  
|`atomic_uint_least16_t`|`atomic<uint_least16_t>`|  
|`atomic_int_least32_t`|`atomic<int_least32_t>`|  
|`atomic_uint_least32_t`|`atomic<uint_least32_t>`|  
|`atomic_int_least64_t`|`atomic<int_least64_t>`|  
|`atomic_uint_least64_t`|`atomic<uint_least64_t>`|  
|`atomic_int_fast8_t`|`atomic<int_fast8_t>`|  
|`atomic_uint_fast8_t`|`atomic<uint_fast8_t>`|  
|`atomic_int_fast16_t`|`atomic<int_fast16_t>`|  
|`atomic_uint_fast16_`|`atomic<uint_fast16_t>`|  
|`atomic_int_fast32_t`|`atomic<int_fast32_t>`|  
|`atomic_uint_fast32_t`|`atomic<uint_fast32_t>`|  
|`atomic_int_fast64_t`|`atomic<int_fast64_t>`|  
|`atomic_uint_fast64_t`|`atomic<uint_fast64_t>`|  
|`atomic_intptr_t`|`atomic<intptr_t>`|  
|`atomic_uintptr_t`|`atomic<uintptr_t>`|  
|`atomic_size_t`|`atomic<size_t>`|  
|`atomic_ptrdiff_t`|`atomic<ptrdiff_t>`|  
|`atomic_intmax_t`|`atomic<intmax_t>`|  
|`atomic_uintmax_t`|`atomic<uintmax_t>`|  
  
## Structs  
  
|Nome|Descrição|  
|----------|---------------|  
|[Estrutura atomic](../standard-library/atomic-structure.md)|Descreve um objeto que executa operações atômicas em um valor armazenado.|  
|[Estrutura atomic\_flag](../Topic/atomic_flag%20Structure.md)|Descreve um objeto que define e limpa atomicamente um sinalizador de `bool`.|  
  
## Enum  
  
|Nome|Descrição|  
|----------|---------------|  
|[Enum memory\_order](../Topic/memory_order%20Enum.md)|Fornece nomes simbólicos para operações de sincronização em locais de memória.  Essas operações afetam como as atribuições em um thread se tornam visíveis em outro.|  
  
## Funções  
 Na lista a seguir, as funções que não terminam em `_explicit` têm\-nas a semântica de `_explicit`correspondente, exceto que têm os argumentos implícitos de [memory\_order](../Topic/memory_order%20Enum.md) de `memory_order_seq_cst`.  
  
|Nome|Descrição|  
|----------|---------------|  
|[Função atomic\_compare\_exchange\_strong](../Topic/atomic_compare_exchange_strong%20Function.md)|Executa uma operação *atômica de comparação e troca*.|  
|[Função atomic\_compare\_exchange\_strong\_explicit](../Topic/atomic_compare_exchange_strong_explicit%20Function.md)|Executa uma operação *atômica de comparação e troca*.|  
|[Função atomic\_compare\_exchange\_weak](../Topic/atomic_compare_exchange_weak%20Function.md)|Executa uma operação *fraca atômica de comparação e troca*.|  
|[Função atomic\_compare\_exchange\_weak\_explicit](../Topic/atomic_compare_exchange_weak_explicit%20Function.md)|Executa uma operação *fraca atômica de comparação e troca*.|  
|[Função atomic\_exchange](../Topic/atomic_exchange%20Function.md)|Substitui um valor armazenado.|  
|[Função atomic\_exchange\_explicit](../Topic/atomic_exchange_explicit%20Function.md)|Substitui um valor armazenado.|  
|[Função atomic\_fetch\_add](../Topic/atomic_fetch_add%20Function.md)|Adiciona um valor especificado para um valor armazenado existente.|  
|[Função atomic\_fetch\_add\_explicit](../Topic/atomic_fetch_add_explicit%20Function.md)|Adiciona um valor especificado para um valor armazenado existente.|  
|[Função atomic\_fetch\_and](../Topic/atomic_fetch_and%20Function.md)|Executa `and` bit a bit em um valor especificado e um valor armazenado existente.|  
|[Função atomic\_fetch\_and\_explicit](../Topic/atomic_fetch_and_explicit%20Function.md)|Executa `and` bit a bit em um valor especificado e um valor armazenado existente.|  
|[Função atomic\_fetch\_or](../Topic/atomic_fetch_or%20Function.md)|Executa `or` bit a bit em um valor especificado e um valor armazenado existente.|  
|[Função atomic\_fetch\_or\_explicit](../Topic/atomic_fetch_or_explicit%20Function.md)|Executa `or` bit a bit em um valor especificado e um valor armazenado existente.|  
|[Função atomic\_fetch\_sub](../Topic/atomic_fetch_sub%20Function.md)|Subtrai um valor especificado de um valor armazenado existente.|  
|[Função atomic\_fetch\_sub\_explicit](../Topic/atomic_fetch_sub_explicit%20Function.md)|Subtrai um valor especificado de um valor armazenado existente.|  
|[Função atomic\_fetch\_xor](../Topic/atomic_fetch_xor%20Function.md)|Executa `exclusive or` bit a bit em um valor especificado e um valor armazenado existente.|  
|[Função atomic\_fetch\_xor\_explicit](../Topic/atomic_fetch_xor_explicit%20Function.md)|Executa `exclusive or` bit a bit em um valor especificado e um valor armazenado existente.|  
|[Função atomic\_flag\_clear](../Topic/atomic_flag_clear%20Function.md)|Define o sinalizador em um objeto de `atomic_flag` a `false`.|  
|[Função atomic\_flag\_clear\_explicit](../Topic/atomic_flag_clear_explicit%20Function.md)|Define o sinalizador em um objeto de `atomic_flag` a `false`.|  
|[Função atomic\_flag\_test\_and\_set](../Topic/atomic_flag_test_and_set%20Function.md)|Define o sinalizador em um objeto de `atomic_flag` a `true`.|  
|[Função atomic\_flag\_test\_and\_set\_explicit](../Topic/atomic_flag_test_and_set_explicit%20Function.md)|Define o sinalizador em um objeto de `atomic_flag` a `true`.|  
|[Função atomic\_init](../Topic/atomic_init%20Function.md)|Define o valor armazenado em um objeto de `atomic` .|  
|[Função atomic\_is\_lock\_free](../Topic/atomic_is_lock_free%20Function.md)|Especifica se as operações atômicas em um objeto especificado são lock\-partition\-id&gt livres.|  
|[Função atomic\_load](../Topic/atomic_load%20Function.md)|Recupera um valor atômico.|  
|[Função atomic\_load\_explicit](../Topic/atomic_load_explicit%20Function.md)|Recupera um valor atômico.|  
|[Função atomic\_signal\_fence](../Topic/atomic_signal_fence%20Function.md)|Atua como *uma cerca* que estabelece a memória que os requisitos entre cercas em um thread de chamada que tem os manipuladores de sinal executados no mesmo thread.|  
|[Função atomic\_store](../Topic/atomic_store%20Function.md)|Armazena um valor atômico.|  
|[Função atomic\_store\_explicit](../Topic/atomic_store_explicit%20Function.md)|Armazena um valor atômico.|  
|[Função atomic\_thread\_fence](../Topic/atomic_thread_fence%20Function.md)|Atua como *uma cerca* que estabelece a memória que os requisitos em relação a outras cercas.|  
|[Função kill\_dependency](../Topic/kill_dependency%20Function.md)|Interrompe a cadeia possível de dependência.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)