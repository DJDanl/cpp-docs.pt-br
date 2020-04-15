---
title: Intrínsecos do ARM64
description: Uma lista dos intrínsecos ARM64 suportados pelo compilador Microsoft C++.
f1_keywords:
- __break
- __addx18byte
- __addx18word
- __addx18dword
- __addx18qword
- __cas8
- __cas16
- __cas32
- __cas64
- __casa8
- __casa16
- __casa32
- __casa64
- __casl8
- __casl16
- __casl32
- __casl64
- __casal8
- __casal16
- __casal32
- __casal64
- __crc32b
- __crc32h
- __crc32w
- __crc32d
- __crc32cb
- __crc32ch
- __crc32cw
- __crc32cd
- __getReg
- __getRegFp
- __getCallerReg
- __getCallerRegFp
- __hlt
- __incx18byte
- __incx18word
- __incx18dword
- __incx18qword
- __ldar8
- __ldar16
- __ldar32
- __ldar64
- __ldapr8
- __ldapr16
- __ldapr32
- __ldapr64
- __prefetch2
- __readx18byte
- __readx18word
- __readx18dword
- __readx18qword
- __setReg
- __setRegFp
- __setCallerReg
- __setCallerRegFp
- __stlr8
- __stlr16
- __stlr32
- __stlr64
- __swp8
- __swp16
- __swp32
- __swp64
- __swpa8
- __swpa16
- __swpa32
- __swpa64
- __swpl8
- __swpl16
- __swpl32
- __swpl64
- __swpal8
- __swpal16
- __swpal32
- __swpal64
- __sys
- __svc
- __writex18byte
- __writex18word
- __writex18dword
- __writex18qword
author: sigatrev
ms.author: magardn
ms.date: 11/14/2019
ms.openlocfilehash: 196518439445824ddf5a7a841b30eb816251ba60
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368213"
---
# <a name="arm64-intrinsics"></a>Intrínsecos do ARM64

O compilador Microsoft C++ (MSVC) disponibiliza os seguintes intrínsecos na arquitetura ARM64. Para obter mais informações sobre a ARM, consulte as seções Ferramentas de Arquitetura e Desenvolvimento de Software do site [da ARM Developer Documentation.](https://developer.arm.com/docs)

## <a name="neon"></a><a name="top"></a>Neon

As extensões do conjunto de instruções vetoriais NEON para o ARM64 fornecem recursos SIMD (Single Instruction Multiple Data, dados múltiplos de instrução única). Eles se assemelham aos dos conjuntos de instruções vetorial MMX e SSE que são comuns aos processadores de arquitetura x86 e x64.

Os intrínsecos NEON são suportados, conforme fornecido no arquivo de cabeçalho *arm64_neon.h*. O suporte msvc para intrínsecas NEON se assemelha ao do compilador ARM64, que está documentado no [ARM NEON Intrínseca Reference](https://static.docs.arm.com/ihi0073/c/IHI0073C_arm_neon_intrinsics_ref.pdf) no site arm Infocenter.

## <a name="arm64-specific-intrinsics-listing"></a><a name="A"></a>Listagem de intrínsecas específicas do ARM64

|Nome da função|Instrução|Protótipo da função|
|-------------------|-----------------|------------------------|
|__break|Brk|vazio __break(int)|
|__addx18byte||vazio __addx18byte (char longo não assinado, não assinado)|
|__addx18word||vazio __addx18word (longo não assinado, curto não assinado)|
|__addx18dword||vazio __addx18dword (longo não assinado, longo não assinado)|
|__addx18qword||vazio __addx18qword (__int64 longas não assinadas e não assinadas)|
|__cas8|CASB|__cas8 de __int8 não assinados (_Target __int8 volátil não assinado* _Target, _Comp de __int8 não assinado, _Value de __int8 não assinado)|
|__cas16|Dinheiro|__int16 __cas16 não assinado (_Target __int16 volátil não assinado* _Target, _Comp __int16 não assinado, _Value de __int16 não assinado)|
|__cas32|CAS|__int32 não assinado __cas32(_Target __int32 volátil não assinado* _Target, _Comp __int32 não assinado, _Value de __int32 não assinado)|
|__cas64|CAS|__cas64 de __int64 não assinados (_Target __int64 volátil sem assinatura* __int64, _Comp __int64 não assinado, _Value __int64 não assinados)|
|__casa8|CASAB|__casa8 de __int8 não assinado (_Target __int8 volátil não assinado* _Comp, _Comp __int8 sem assinatura, _Value de __int8 não assinado)|
|__casa16|CASAH|__casa16 de __int16 não assinados (_Target __int16 volátil não assinado* _Comp, _Comp sem __int16 assinatura, _Value de __int16 não assinados)|
|__casa32|CASA|__casa32 de __int32 não assinados (_Target __int32 não assinados, _Comp __int32 sem assinatura, _Value de __int32 não assinados)|
|__casa64|CASA|__int64 não assinado __casa64 (_Target __int64 volátil não assinado* _Target, _Comp __int64 sem assinatura, _Value de __int64 não assinado)|
|__casl8|CASLB|__casl8 de __int8 não assinados (_Target __int8 volátil não assinado* _Target, _Comp __int8 não assinado, __int8 sem assinatura _Value)|
|__casl16|CASLH|__int16 sem assinatura __casl16 (_Target _Target __int16 volátil sem assinatura, _Comp __int16 não assinado, _Value de __int16 sem assinatura)|
|__casl32|CASL|__int32 sem assinatura __casl32 (_Target não assinado __int32 volátil* _Comp, _Comp __int32 não assinado, _Value de __int32 não assinado)|
|__casl64|CASL|__casl64 de __int64 não assinados (_Target __int64 volátil não assinado* _Target, _Comp __int64 sem assinatura, __int64 sem assinatura _Value)|
|__casal8|CASALB|__casal8 de __int8 não assinados (_Target __int8 volátil não assinado* _Comp, _Comp de __int8 não assinado, _Value de __int8 não assinados)|
|__casal16|CASALH|__casal16 não __int16 assinadas _Target(_Target __int16 volátil s _Comp __int16em assinatura* sem assinatura, sem assinatura, _Value __int16 não assinada)|
|__casal32|CASAL|__casal32 __int32 não assinados (_Target __int32 volátil não __int32 assinado* _Comp, _Comp sem assinatura, __int32 sem assinatura _Value)|
|__casal64|CASAL|__casal64 de __int64 não assinados (_Target __int64 volátil não assinado* _Value, _Comp _Value de __int64 __int64 não assinado, sem assinatura)|
|__crc32b|CRC32B|__crc32b de __int32 não assinado (__int32 não assinado, __int32 não assinado)|
|__crc32h|CRC32H|__crc32h de __int32 não assinado (__int32 não assinado, __int32 não assinado)|
|__crc32w|CRC32W|__crc32w de __int32 não assinado (__int32 não assinado, __int32 não assinado)|
|__crc32d|CRC32X|__crc32d de __int32 não assinado (__int32 não assinado, __int64 não assinado)|
|__crc32cb|CRC32CB|__crc32cb de __int32 não assinado (__int32 não assinado, __int32 não assinado)|
|__crc32ch|CRC32CH|__crc32ch de __int32 não assinado (__int32 não assinado, __int32 não assinado)|
|__crc32cw|CRC32CW|__crc32cw de __int32 não assinado (__int32 não assinado, __int32 não assinado)|
|__crc32cd|CRC32CX|__crc32cd de __int32 não assinado (__int32 não assinado, __int64 não assinado)|
|__dmb|DMB|void __dmb(unsigned int `_Type`)<br /><br /> Insere uma operação de barreira de memória no fluxo de instruções. O parâmetro `_Type` especifica o tipo de restrição que a barreira impõe.<br /><br /> Para obter mais informações sobre os tipos de restrições que podem ser aplicadas, consulte [restrições de barreira de memória](#BarrierRestrictions).|
|__dsb|DSB|void __dsb(unsigned int _Type)<br /><br /> Insere uma operação de barreira de memória no fluxo de instruções. O parâmetro `_Type` especifica o tipo de restrição que a barreira impõe.<br /><br /> Para obter mais informações sobre os tipos de restrições que podem ser aplicadas, consulte [restrições de barreira de memória](#BarrierRestrictions).|
|__isb|ISB|void __isb(unsigned int _Type)<br /><br /> Insere uma operação de barreira de memória no fluxo de instruções. O parâmetro `_Type` especifica o tipo de restrição que a barreira impõe.<br /><br /> Para obter mais informações sobre os tipos de restrições que podem ser aplicadas, consulte [restrições de barreira de memória](#BarrierRestrictions).|
|__getReg||__getReg __int64 não assinados|
|__getRegFp||__getRegFp duplo (int)|
|__getCallerReg||__getCallerReg __int64 não assinados|
|__getCallerRegFp||__getCallerRegFp duplo (int)|
|__hvc|HVC|unsigned int __hvc(unsigned int, ...)|
|__hlt|Hlt|int __hlt (int não assinado, ...)|
|__incx18byte||vazio __incx18byte (longo não assinado)|
|__incx18word||vazio __incx18word (longo não assinado)|
|__incx18dword||vazio __incx18dword (longo não assinado)|
|__incx18qword||vazio __incx18qword (longo não assinado)|
|__iso_volatile_load16||_iso_volatile_load16 \___int16 (_int16 \_ \*voláteis const)<br /><br /> Para obter mais informações, consulte [intrínsecos __iso_volatile_load/loja](#IsoVolatileLoadStore).|
|__iso_volatile_load32||_iso_volatile_load32 \___int32 (_int32 \_ \*voláteis const)<br /><br /> Para obter mais informações, consulte [intrínsecos __iso_volatile_load/loja](#IsoVolatileLoadStore).|
|__iso_volatile_load64||_iso_volatile_load64 \___int64 (_int64 \_ \*voláteis const)<br /><br /> Para obter mais informações, consulte [intrínsecos __iso_volatile_load/loja](#IsoVolatileLoadStore).|
|__iso_volatile_load8||_iso_volatile_load8 \___int8 (_int8 \_ \*voláteis const)<br /><br /> Para obter mais informações, consulte [intrínsecos __iso_volatile_load/loja](#IsoVolatileLoadStore).|
|__iso_volatile_store16||__iso_volatile_store16 vazio \_ \*(_int16 \_volátil , _int16)<br /><br /> Para obter mais informações, consulte [intrínsecos __iso_volatile_load/loja](#IsoVolatileLoadStore).|
|__iso_volatile_store32||__iso_volatile_store32 vazio \_ \*(_int32 \_voláteis , _int32)<br /><br /> Para obter mais informações, consulte [intrínsecos __iso_volatile_load/loja](#IsoVolatileLoadStore).|
|__iso_volatile_store64||__iso_volatile_store64 vazio \_ \*(_int64 \_voláteis , _int64)<br /><br /> Para obter mais informações, consulte [intrínsecos __iso_volatile_load/loja](#IsoVolatileLoadStore).|
|__iso_volatile_store8||__iso_volatile_store8 vazio \_ \*(_int8 \_voláteis , _int8)<br /><br /> Para obter mais informações, consulte [intrínsecos __iso_volatile_load/loja](#IsoVolatileLoadStore).|
|__ldar8|LDARB|__ldar8 de __int8 não assinado (_Target __int8 volátil não assinado)|
|__ldar16|LDARH|__ldar16 de __int16 não assinado (_Target __int16 volátil* não assinado)|
|__ldar32|LDAR|__ldar32 de __int32 não assinado (_Target __int32 volátil não assinado)|
|__ldar64|LDAR|__ldar64 de __int64 não assinado (_Target __int64 volátil não assinado)|
|__ldapr8|LDAPRB|__ldapr8 __int8 não assinado (_Target __int8 volátil não assinado)|
|__ldapr16|LDAPRH|__ldapr16 de __int16 não assinado (_Target volátil __int16 não assinado sem assinatura)|
|__ldapr32|LDAPR|__ldapr32 de __int32 não assinado (_Target __int32 volátil não assinado)|
|__ldapr64|LDAPR|__ldapr64 de __int64 não assinado (_Target __int64 volátil não assinado*|
|__mulh||\___mulh _int64\__int64, \__int64|
|__prefetch|PRFM|vazio \___cdecl _prefetch (vazio \*const)<br /><br /> Fornece `PRFM` uma dica de memória `PLDL1KEEP` com a operação de pré-busca ao sistema que a memória em ou perto do endereço especificado pode ser acessada em breve. Alguns sistemas podem optar por otimizar para esse padrão de acesso de memória para aumentar o desempenho de runtime. No entanto, do ponto de vista da linguagem C++, a função não tem efeito observável e pode não ter nenhuma ação.|
|__prefetch2|PRFM|vazio \___cdecl _prefetch(vazio \*const , uint8_t prfop)<br /><br /> Fornece `PRFM` uma dica de memória com a operação de pré-busca fornecida ao sistema que a memória em ou perto do endereço especificado pode ser acessada em breve. Alguns sistemas podem optar por otimizar para esse padrão de acesso de memória para aumentar o desempenho de runtime. No entanto, do ponto de vista da linguagem C++, a função não tem efeito observável e pode não ter nenhuma ação.|
|__readx18byte||char não assinado __readx18byte (não assinado longo)|
|__readx18word||__readx18word curto não assinado (longo não assinado)|
|__readx18dword||__readx18dword longo não assinado (longo não assinado)|
|__readx18qword||__readx18qword de __int64 não assinado (não assinado longo)|
|__setReg||vazio __setReg(int, __int64 não assinado)|
|__setRegFp||vazio __setRegFp (int, duplo)|
|__setCallerReg||vazio __setCallerReg (int, __int64 não assinado)|
|__setCallerRegFp||vazio __setCallerRegFp (int, duplo)|
|__sev|SETE|void __sev(void)|
|__static_assert||vazio __static_assert(int, const char \*)|
|__stlr8|STLRB|__stlr8 vazio (_Target __int8 volátil* não assinado, _Value __int8 sem assinatura)|
|__stlr16|STLRH|vazio __stlr16 (_Target __int16 volátil* não assinado* _Target, __int16 não assinado _Value)|
|__stlr32|STLR|vazio __stlr32 (_Target __int32 volátil* não assinado, _Value de __int32 não assinado)|
|__stlr64|STLR|vazio __stlr64 (__int64 _Target volátil* não assinado, _Value __int64 não assinado)|
|__swp8|SWPB|__swp8 de __int8 não assinados (_Target __int8 volátil não assinado* _Value, sem assinatura __int8)|
|__swp16|SWPH|__swp16 de __int16 não assinados (_Target __int16 volátil* não assinados, sem assinatura __int16 _Value)|
|__swp32|Swp|__swp32 __int32 não assinado (_Target __int32 volátil* não assinado, _Value de __int32 não assinado)|
|__swp64|Swp|__swp64 de __int64 não assinados (_Target __int64 volátil* não assinado, _Value __int64 sem assinatura)|
|__swpa8|SWPAB|__swpa8 de __int8 não assinado (_Target __int8 volátil* não assinado, __int8 sem assinatura _Value)|
|__swpa16|SWPAH|__swpa16 de __int16 não assinados (_Target __int16 volátil não assinado* _Value, sem assinatura __int16)|
|__swpa32|SWPA|__swpa32 de __int32 não assinados (_Target __int32 volátil* não assinado, _Value __int32 não assinado)|
|__swpa64|SWPA|__swpa64 de __int64 não assinados (_Target __int64 volátil* não assinado, _Value de __int64 não assinados)|
|__swpl8|SWPLB|__swpl8 __int8 não assinados (_Target __int8 volátil* não assinado, _Value __int8 não assinado)|
|__swpl16|SWPLH|__swpl16 de __int16 não assinados (_Target __int16 volátil* não assinado, _Value de __int16 não assinados)|
|__swpl32|SWPL|__swpl32 de __int32 não assinados (_Target __int32 volátil* não assinados, _Value __int32 sem assinatura)|
|__swpl64|SWPL|__swpl64 __int64 não assinados (_Target _Target __int64 volátil não assinado* s __int64em assinatura _Value)|
|__swpal8|SWPALB|__swpal8 de __int8 não assinado (_Target __int8 volátil não _Value __int8 assinado* não assinado)|
|__swpal16|SWPALH|__swpal16 de __int16 não assinado (_Target __int16 volátil* não assinado, __int16 sem assinatura _Value)|
|__swpal32|SWPAL|__swpal32 de __int32 não assinado (_Target __int32 volátil* não assinado, __int32 sem assinatura _Value)|
|__swpal64|SWPAL|__swpal64 de __int64 não assinados (_Target __int64 não assinados, s _Value __int64em assinatura)|
|__sys|Sys|int __sys não assinado(int, __int64)|
|__svc|SVC|int não assinado __svc (int não assinado, ...)|
|__wfe|WFE|void __wfe(void)|
|__wfi|WFI|void __wfi(void)|
|__writex18byte||vazio __writex18byte (char longo não assinado, não assinado)|
|__writex18word||vazio __writex18word (longo não assinado, curto não assinado)|
|__writex18dword||vazio __writex18dword (longo não assinado, longo não assinado)|
|__writex18qword||vazio __writex18qword (__int64 longas e não assinadas não assinadas)|
|__umulh||_int64 \_sem assinatura \___umulh (_int64 \_não assinado, _int64 não assinado)|
|_CopyDoubleFromInt64||_CopyDoubleFromInt64 duplo\_(_int64)|
|_CopyFloatFromInt32||_CopyFloatFromInt32 flutuante\_(_int32)|
|_CopyInt32FromFloat||__int32 _CopyInt32FromFloat(float)|
|_CopyInt64FromDouble||__int64 _CopyInt64FromDouble(double)|
|_CountLeadingOnes||unsigned int _CountLeadingOnes(unsigned long)|
|_CountLeadingOnes64||_CountLeadingOnes64 int não assinado \_(_int64 não assinado)|
|_CountLeadingSigns||unsigned int _CountLeadingSigns(long)|
|_CountLeadingSigns64||int _CountLeadingSigns64 não\_assinado (_int64)|
|_CountLeadingZeros||unsigned int _CountLeadingZeros(unsigned long)|
|_CountLeadingZeros64||_CountLeadingZeros64 int não assinado \_(_int64 não assinado)|
|_ReadStatusReg|MRS|\__int64 _ReadStatusReg(int)|
|_WriteStatusReg|MSR|vazio _WriteStatusReg(int, \__int64)|

[[Voltar ao topo](#top)]

### <a name="memory-barrier-restrictions"></a><a name="BarrierRestrictions"></a>Restrições de barreira de memória

As funções intrínsecas `__dmb` (barreira de memória de dados), `__dsb` (barreira de sincronização de dados) e `__isb` (barreira de sincronização de instruções) usam os seguintes valores predefinidos para especificar a restrição da barreira de memória em termos do domínio de compartilhamento e do tipo de acesso que são afetados pela operação.

|Valor de restrição|Descrição|
|-----------------------|-----------------|
|_ARM64_BARRIER_SY|Sistema completo, leituras e gravações.|
|_ARM64_BARRIER_ST|Sistema completo, somente gravações.|
|_ARM64_BARRIER_LD|Sistema completo, somente leitura.|
|_ARM64_BARRIER_ISH|Compartilháveis internos, leituras e gravações.|
|_ARM64_BARRIER_ISHST|Compartilháveis internos, somente gravações.|
|_ARM64_BARRIER_ISHLD|Sharable interior, somente leitura.|
|_ARM64_BARRIER_NSH|Não compartilháveis, leituras e gravações.|
|_ARM64_BARRIER_NSHST|Não compartilháveis, somente gravações.|
|_ARM64_BARRIER_NSHLD|Não sharable, somente leitura.|
|_ARM64_BARRIER_OSH|Compartilháveis externos, leituras e gravações.|
|_ARM64_BARRIER_OSHST|Compartilháveis externos, somente gravações.|
|_ARM64_BARRIER_OSHLD|Sharable exterior, somente leitura.|

Para `__isb` o intrínseco, a única restrição válida atualmente é _ARM64_BARRIER_SY; todos os outros valores são reservados pela arquitetura.

### <a name="__iso_volatile_loadstore-intrinsics"></a><a name="IsoVolatileLoadStore"></a>intrínseca de __iso_volatile_load/loja

Essas funções intrínsecas executam explicitamente cargas e lojas que não estão sujeitas a otimizações de compiladores.

```C
__int16 __iso_volatile_load16(const volatile __int16 * Location);
__int32 __iso_volatile_load32(const volatile __int32 * Location);
__int64 __iso_volatile_load64(const volatile __int64 * Location);
__int8 __iso_volatile_load8(const volatile __int8 * Location);

void __iso_volatile_store16(volatile __int16 * Location, __int16 Value);
void __iso_volatile_store32(volatile __int32 * Location, __int32 Value);
void __iso_volatile_store64(volatile __int64 * Location, __int64 Value);
void __iso_volatile_store8(volatile __int8 * Location, __int8 Value);
```

#### <a name="parameters"></a>Parâmetros

*Localização*\
O endereço de um local de memória para ler ou gravar.

*Valor*\
O valor para escrever no local de memória especificado (apenas intrínsecas de armazenamento).

#### <a name="return-value-load-intrinsics-only"></a>Valor de retorno (somente intrínsecos à carga)

O valor do local de memória especificado por *Localização*.

#### <a name="remarks"></a>Comentários

Você pode `__iso_volatile_load8/16/32/64` usar `__iso_volatile_store8/16/32/64` os intrínsecos para executar explicitamente acessos de memória que não estão sujeitos a otimizações de compiladores. O compilador não pode remover, sintetizar ou alterar a ordem relativa dessas operações. No entanto, não gera barreiras implícitas de memória de hardware. Portanto, o hardware ainda pode reorganizar os acessos de memória observáveis entre vários threads. Mais precisamente, esses intrínsecos são equivalentes às seguintes expressões compiladas em **/volátil:iso**.

```cpp
int a = __iso_volatile_load32(p);    // equivalent to: int a = *(const volatile __int32*)p;
__iso_volatile_store32(p, a);        // equivalent to: *(volatile __int32*)p = a;
```

Observe que o intrínseco usa ponteiros voláteis para acomodar variáveis voláteis. No entanto, não há nenhuma exigência ou recomendação para usar ponteiros voláteis como argumentos. A semântica dessas operações é exatamente a mesma se um tipo regular, não volátil, for usado.

Para obter mais informações sobre o argumento **/volátil:iso** command-line, consulte [/volátil (interpretação volátil de palavras-chave)](../build/reference/volatile-volatile-keyword-interpretation.md).

## <a name="arm64-support-for-intrinsics-from-other-architectures"></a><a name="I"></a>Suporte ARM64 para intrínsecos de outras arquiteturas

A tabela a seguir lista intrínsecas de outras arquiteturas que são suportadas em plataformas ARM64. Quando o comportamento de um intrínseco no ARM64 difere de seu comportamento em outras arquiteturas de hardware, detalhes adicionais são observados.

|Nome da função|Protótipo da função|
|-------------------|------------------------|
|__assume|void __assume(int)|
|__code_seg|__code_seg anular (const char) \*|
|__debugbreak|vazio \___cdecl _debugbreak (vazio)|
|__fastfail|__declspec (sem \_retorno) _fastfail nulo (int não assinado)|
|__nop|void __nop(void)|
|__yield|vazio __yield(vazio) **Nota:** Nas plataformas ARM64, esta função gera a instrução YIELD. Essa instrução indica que o segmento está executando uma tarefa que pode ser temporariamente suspensa da execução — por exemplo, um spinlock — sem afetar negativamente o programa. Ele permite que a CPU execute outras tarefas durante os ciclos de execução que de outra forma seriam desperdiçados.|
|_AddressOfReturnAddress|vazio \* _AddressOfReturnAddress (vazio)|
|_BitScanForward|_BitScanForward de char não \* assinado (_Index longo sem assinatura, _Mask longo sem assinatura)|
|_BitScanForward64|char _BitScanForward64 não assinado \* (_Index longo sem assinatura, _Mask de __int64 não assinado)|
|_BitScanReverse|char _BitScanReverse não assinado \* (_Index longo sem assinatura, _Mask longo sem assinatura)|
|_BitScanReverse64|char _BitScanReverse64 não assinado \* (_Index longo não assinado, __int64 sem assinatura _Mask)|
|_bittest|char sem assinatura _bittest \*(const longo, longo)|
|_bittest64|char _bittest64 não assinado \*(__int64 const , __int64)|
|_bittestandcomplement|char não assinado \*_bittestandcomplement (longo, longo)|
|_bittestandcomplement64|char _bittestandcomplement64(__int64, \*__int64)|
|_bittestandreset|char não assinado \*_bittestandreset (longo, longo)|
|_bittestandreset64|char _bittestandreset64(__int64, \*__int64)|
|_bittestandset|char não assinado \*_bittestandset (longo, longo)|
|_bittestandset64|char _bittestandset64(__int64, \*__int64)|
|_byteswap_uint64|__int64 \_sem assinatura _cdecl \__byteswap_uint64 (_int64 não assinado)|
|_byteswap_ulong|unsigned long __cdecl _byteswap_ulong(unsigned long)|
|_byteswap_ushort|unsigned short __cdecl _byteswap_ushort(unsigned short)|
|_disable|anular __cdecl _disable(vazio) **Nota:** Nas plataformas ARM64, esta função gera a instrução; `MSR DAIFCLR,#2` só está disponível como intrínseco.|
|_enable|anular __cdecl _enable (vazio) **Nota:** Nas plataformas ARM64, esta função gera a instrução; `MSR DAIFSET,#2` só está disponível como intrínseco.|
|_lrotl|unsigned long __cdecl _lrotl(unsigned long, int)|
|_lrotr|unsigned long __cdecl _lrotr(unsigned long, int)|
|_ReadBarrier|void _ReadBarrier(void)|
|_ReadWriteBarrier|void _ReadWriteBarrier(void)|
|_ReturnAddress|vazio \* _ReturnAddress (vazio)|
|_rotl|unsigned int __cdecl _rotl(unsigned int _Value, int _Shift)|
|_rotl16|unsigned short _rotl16(unsigned short _Value, unsigned char _Shift)|
|_rotl64|_rotl64 de \__cdecl __int64 \_não assinados (_Value _int64 não assinado, _Shift int)|
|_rotl8|unsigned char _rotl8(unsigned char _Value, unsigned char _Shift)|
|_rotr|unsigned int __cdecl _rotr(unsigned int _Value, int _Shift)|
|_rotr16|unsigned short _rotr16(unsigned short _Value, unsigned char _Shift)|
|_rotr64|__int64 \__rotr64 _cdecl _rotr64 \_sem assinatura (_Value _int64 não assinados, int _Shift)|
|_rotr8|unsigned char _rotr8(unsigned char _Value, unsigned char _Shift)|
|_setjmpex|int __cdecl _setjmpex(jmp_buf)|
|_WriteBarrier|void _WriteBarrier(void)|

[[Voltar ao topo](#top)]

## <a name="interlocked-intrinsics"></a>Intrínsecos interbloqueados

Intrínsecos sincronizados são um conjunto de intrínsecos usados para executar operações atômicas de leitura, gravação e alteração. Alguns deles são comuns a todas as plataformas. Eles estão listados separadamente aqui porque há um grande número deles. Como suas definições são redundantes, é mais fácil pensar neles em termos gerais. Seus nomes podem ser usados para gerar comportamentos exatos.

A tabela a seguir resume o suporte ARM64 dos intrínsecos intertravados não bittest. Cada célula da tabela corresponde a um nome que é derivado acrescentando o nome da operação na célula mais à esquerda da linha e o nome do tipo na célula superior da coluna para `_Interlocked`. Por exemplo, a célula no `Xor` cruzamento `8` da linha `_InterlockedXor8` e da coluna corresponde e é totalmente suportada. A maioria das funções com suporte oferece estes sufixos opcionais: `_acq`, `_rel`, e `_nf`. O sufixo `_acq` indica uma semântica "acquire" e o sufixo `_rel` indica uma semântica uma "release". O `_nf` sufixo "sem cerca" é exclusivo do ARM e do ARM64 e é discutido na próxima seção.

||8|16|32|64|128|P|
|-|-------|--------|--------|--------|-------|-------|
|Adicionar|Nenhum|Nenhum|Completo|Completo|Nenhum|Nenhum|
|And|Completo|Completo|Completo|Completo|Nenhum|Nenhum|
|CompareExchange|Completo|Completo|Completo|Completo|Completo|Completo|
|Decremento|Nenhum|Completo|Completo|Completo|Nenhum|Nenhum|
|Exchange|Completo|Completo|Completo|Completo|Nenhum|Completo|
|ExchangeAdd|Completo|Completo|Completo|Completo|Nenhum|Nenhum|
|Incremento|Nenhum|Completo|Completo|Completo|Nenhum|Nenhum|
|Ou|Completo|Completo|Completo|Completo|Nenhum|Nenhum|
|Xor|Completo|Completo|Completo|Completo|Nenhum|Nenhum|

Chave:

- **Completo:** suporta formas simples, `_acq` `_rel`e `_nf` formas.

- **Nenhum**: Não suportado

### <a name="_nf-no-fence-suffix"></a><a name="nf_suffix"></a>sufixo _nf (sem cerca)

O `_nf` sufixo "sem cerca" indica que a operação não se comporta como qualquer tipo de `_acq`barreira `_rel`de memória, em contraste com as outras três formas (simples, e ), que se comportam como uma espécie de barreira. Um possível uso `_nf` dos formulários é manter um contador de estatísticas que é atualizado por vários segmentos ao mesmo tempo, mas cujo valor não é usado de outra forma enquanto vários segmentos estão sendo executados.

### <a name="list-of-interlocked-intrinsics"></a>Lista de intrínsecos interbloqueados

|Nome da função|Protótipo da função|
|-------------------|------------------------|
|_InterlockedAdd|_InterlockedAdd longo (longo _volatile, \*longo)|
|_InterlockedAdd64|__int64\__InterlockedAdd64(_int64 \* \_volátil , _int64)|
|_InterlockedAdd64_acq|__int64 _InterlockedAdd64_acq\__int64 \* \__int64|
|_InterlockedAdd64_nf|_InterlockedAdd64_nf\___int64(_int64 \* \_volátil , _int64)|
|_InterlockedAdd64_rel|_InterlockedAdd64_rel\___int64(_int64 \* \_volátil , _int64)|
|_InterlockedAdd_acq|longo _InterlockedAdd_acq (longo volátil, \*longo)|
|_InterlockedAdd_nf|longo _InterlockedAdd_nf (longo volátil, \*longo)|
|_InterlockedAdd_rel|longo _InterlockedAdd_rel (longo volátil, \*longo)|
|_InterlockedAnd|longo_InterlockedAnd (longo \*volátil, longo)|
|_InterlockedAnd16|_InterlockedAnd16 curto (curto volátil, \*curto)|
|_InterlockedAnd16_acq|_InterlockedAnd16_acq curto (curto volátil, \*curto)|
|_InterlockedAnd16_nf|_InterlockedAnd16_nf curto (curto volátil, \*curto)|
|_InterlockedAnd16_rel|_InterlockedAnd16_rel curto (curto volátil, \*curto)|
|_InterlockedAnd64|_InterlockedAnd64\___int64(_int64 \* \_volátil , _int64)|
|_InterlockedAnd64_acq|_InterlockedAnd64_acq\___int64(_int64 \* \_volátil , _int64)|
|_InterlockedAnd64_nf|_InterlockedAnd64_nf\___int64(_int64 \* \_volátil , _int64)|
|_InterlockedAnd64_rel|__int64\__InterlockedAnd64_rel(_int64 \* \_volátil , _int64)|
|_InterlockedAnd8|char _InterlockedAnd8 (char volátil, \*char)|
|_InterlockedAnd8_acq|char _InterlockedAnd8_acq (char volátil, \*char)|
|_InterlockedAnd8_nf|char _InterlockedAnd8_nf (char volátil, \*char)|
|_InterlockedAnd8_rel|char _InterlockedAnd8_rel (char volátil, \*char)|
|_InterlockedAnd_acq|longo _InterlockedAnd_acq (longo volátil, \*longo)|
|_InterlockedAnd_nf|longo _InterlockedAnd_nf (longo volátil, \*longo)|
|_InterlockedAnd_rel|longo _InterlockedAnd_rel (longo volátil, \*longo)|
|_InterlockedCompareExchange|longo __cdecl _InterlockedCompareExchange \*(longo volátil, longo, longo)|
|_InterlockedCompareExchange_acq|longo_InterlockedCompareExchange_acq (longo \*volátil, longo, longo)|
|_InterlockedCompareExchange_nf|longo _InterlockedCompareExchange_nf (longo volátil, \*longo, longo)|
|_InterlockedCompareExchange_rel|longo _InterlockedCompareExchange_rel (longo volátil, \*longo, longo)|
|_InterlockedCompareExchange16|_InterlockedCompareExchange16 curto (curto volátil, \*curto, curto)|
|_InterlockedCompareExchange16_acq|_InterlockedCompareExchange16_acq curto (curto volátil, \*curto, curto)|
|_InterlockedCompareExchange16_nf|_InterlockedCompareExchange16_nf curto (curto volátil, \*curto, curto)|
|_InterlockedCompareExchange16_rel|_InterlockedCompareExchange16_rel curto (curto volátil, \*curto, curto)|
|_InterlockedCompareExchange64|_InterlockedCompareExchange64 __int64\__int64 \* \__int64, \__int64)|
|_InterlockedCompareExchange64_acq|_InterlockedCompareExchange64_acq\___int64(_int64 \* \_volátil \_, _int64, _int64)|
|_InterlockedCompareExchange64_nf|__int64 _InterlockedCompareExchange64_nf\__int64 \* \__int64 \__int64|
|_InterlockedCompareExchange64_rel|__int64\__InterlockedCompareExchange64_rel( \*_int64 \_volátil, _int64, \__int64)|
|_InterlockedCompareExchange8|char _InterlockedCompareExchange8 (char volátil, \*char, char)|
|_InterlockedCompareExchange8_acq|char _InterlockedCompareExchange8_acq (char volátil, \*char, char)|
|_InterlockedCompareExchange8_nf|char _InterlockedCompareExchange8_nf (char volátil, \*char, char)|
|_InterlockedCompareExchange8_rel|char _InterlockedCompareExchange8_rel (char volátil, \*char, char)|
|_InterlockedCompareExchangePointer|vazio \* _InterlockedCompareExchangePointer \* (vazio \* \*volátil, \*vazio, vazio)|
|_InterlockedCompareExchangePointer_acq|vazio \* _InterlockedCompareExchangePointer_acq \* (vazio \* \*volátil, \*vazio, vazio)|
|_InterlockedCompareExchangePointer_nf|vazio \* _InterlockedCompareExchangePointer_nf \* (vazio \* \*volátil, \*vazio, vazio)|
|_InterlockedCompareExchangePointer_rel|vazio \* _InterlockedCompareExchangePointer_rel \* (vazio \* \*volátil, \*vazio, vazio)|
|_InterlockedCompareExchange128|char _InterlockedCompareExchange128 não\_assinado \* (_int64 _Destination \_volátil, \_ \__ExchangeHigh _int64, _int64 _ExchangeLow, _int64 \* _ComparandResult)|
|_InterlockedCompareExchange128_acq|char _InterlockedCompareExchange128_acq não\_assinado \* (_int64 _Destination voláteis, \__ExchangeHigh _int64, \__ExchangeLow _int64, \__int64 \* _ComparandResult)|
|_InterlockedCompareExchange128_nf|_InterlockedCompareExchange128_nf de char\_não \* assinado \_(_int64 \__Destination \_volátil, _ExchangeHigh _int64, _ExchangeLow _int64, \* _int64 _ComparandResult)|
|_InterlockedCompareExchange128_rel|_InterlockedCompareExchange128_rel de char\_não \* assinado \_(_int64 \__Destination \_volátil, _ExchangeHigh _int64, _int64 _ExchangeLow, _int64 \* _ComparandResult)|
|_InterlockedDecrement|_InterlockedDecrement de __cdecl \*longo (longo volátil)|
|_InterlockedDecrement16|_InterlockedDecrement16 curto (curto volátil) \*|
|_InterlockedDecrement16_acq|_InterlockedDecrement16_acq curto (curto volátil) \*|
|_InterlockedDecrement16_nf|curto _InterlockedDecrement16_nf (curto volátil) \*|
|_InterlockedDecrement16_rel|_InterlockedDecrement16_rel curto (curto volátil) \*|
|_InterlockedDecrement64|__int64 _InterlockedDecrement64(\_ \*_int64 volátil)|
|_InterlockedDecrement64_acq|_InterlockedDecrement64_acq\___int64(_int64 \*volátil)|
|_InterlockedDecrement64_nf|__int64 _InterlockedDecrement64_nf(\_ \*_int64 volátil)|
|_InterlockedDecrement64_rel|_InterlockedDecrement64_rel __int64(\_ \*_int64 volátil)|
|_InterlockedDecrement_acq|longo _InterlockedDecrement_acq (longo volátil) \*|
|_InterlockedDecrement_nf|_InterlockedDecrement_nf longo (longo volátil) \*|
|_InterlockedDecrement_rel|longo _InterlockedDecrement_rel (longo volátil) \*|
|_InterlockedExchange|_InterlockedExchange __cdecl longo \* (_Target voláteis longos, longos)|
|_InterlockedExchange_acq|longo _InterlockedExchange_acq (longo _Target volátil, \* longo)|
|_InterlockedExchange_nf|longo _InterlockedExchange_nf (longo _Target voláteis, \* longo)|
|_InterlockedExchange_rel|longo _InterlockedExchange_rel (longo _Target volátil, \* longo)|
|_InterlockedExchange16|_InterlockedExchange16 curto (_Target volátil \* curto, curto)|
|_InterlockedExchange16_acq|_InterlockedExchange16_acq curto (_Target volátil \* curto, curto)|
|_InterlockedExchange16_nf|_InterlockedExchange16_nf curto (_Target volátil \* curto, curto)|
|_InterlockedExchange16_rel|_InterlockedExchange16_rel curto (_Target volátil \* curto, curto)|
|_InterlockedExchange64|_InterlockedExchange64 __int64(\_ \* _int64 \__Target volátil, _int64)|
|_InterlockedExchange64_acq|__int64 _InterlockedExchange64_acq\__int64 \* _Target \_volátil, _int64)|
|_InterlockedExchange64_nf|__int64 _InterlockedExchange64_nf\__int64 \* _Target \_volátil, _int64)|
|_InterlockedExchange64_rel|_InterlockedExchange64_rel __int64\__int64 \* _Target \_volátil, _int64)|
|_InterlockedExchange8|char _InterlockedExchange8 (char _Target volátil, \* char)|
|_InterlockedExchange8_acq|char _InterlockedExchange8_acq (char volátil \* _Target, char)|
|_InterlockedExchange8_nf|char _InterlockedExchange8_nf (char _Target volátil, \* char)|
|_InterlockedExchange8_rel|char _InterlockedExchange8_rel (char _Target volátil, \* char)|
|_InterlockedExchangeAdd|longo __cdecl _InterlockedExchangeAdd \*(longo volátil, longo)|
|_InterlockedExchangeAdd16|_InterlockedExchangeAdd16 curto (curto volátil, \*curto)|
|_InterlockedExchangeAdd16_acq|_InterlockedExchangeAdd16_acq curto (curto volátil, \*curto)|
|_InterlockedExchangeAdd16_nf|_InterlockedExchangeAdd16_nf curto (curto volátil, \*curto)|
|_InterlockedExchangeAdd16_rel|_InterlockedExchangeAdd16_rel curto (curto volátil, \*curto)|
|_InterlockedExchangeAdd64|_InterlockedExchangeAdd64 __int64(\_ \*_int64 \_volátil , _int64)|
|_InterlockedExchangeAdd64_acq|_InterlockedExchangeAdd64_acq __int64(\_ \*_int64 \_volátil , _int64)|
|_InterlockedExchangeAdd64_nf|__int64\__InterlockedExchangeAdd64_nf(_int64 \* \_volátil , _int64)|
|_InterlockedExchangeAdd64_rel|__int64 _InterlockedExchangeAdd64_rel\__int64 \* \__int64|
|_InterlockedExchangeAdd8|char _InterlockedExchangeAdd8 (char volátil, \*char)|
|_InterlockedExchangeAdd8_acq|char _InterlockedExchangeAdd8_acq (char volátil, \*char)|
|_InterlockedExchangeAdd8_nf|char _InterlockedExchangeAdd8_nf (char volátil, \*char)|
|_InterlockedExchangeAdd8_rel|char _InterlockedExchangeAdd8_rel (char volátil \*, char)|
|_InterlockedExchangeAdd_acq|longo _InterlockedExchangeAdd_acq (longo volátil, \*longo)|
|_InterlockedExchangeAdd_nf|_InterlockedExchangeAdd_nf longo (longo volátil, \*longo)|
|_InterlockedExchangeAdd_rel|longo _InterlockedExchangeAdd_rel (longo volátil, \*longo)|
|_InterlockedExchangePointer|vazio \* _InterlockedExchangePointer \* (vazio \* volátil \*_Target, vazio )|
|_InterlockedExchangePointer_acq|vazio \* _InterlockedExchangePointer_acq \* (vazio \* volátil \*_Target, vazio )|
|_InterlockedExchangePointer_nf|vazio \* _InterlockedExchangePointer_nf \* (vazio \* volátil \*_Target, vazio )|
|_InterlockedExchangePointer_rel|vazio \* _InterlockedExchangePointer_rel \* (vazio _Target voláteis, \* vazio) \*|
|_InterlockedIncrement|longo __cdecl _InterlockedIncrement \*(longo volátil)|
|_InterlockedIncrement16|_InterlockedIncrement16 curto (curto volátil) \*|
|_InterlockedIncrement16_acq|_InterlockedIncrement16_acq curto (curto volátil) \*|
|_InterlockedIncrement16_nf|_InterlockedIncrement16_nf curto (curto volátil) \*|
|_InterlockedIncrement16_rel|_InterlockedIncrement16_rel curto (curto volátil) \*|
|_InterlockedIncrement64|_InterlockedIncrement64\__int64 \*__int64|
|_InterlockedIncrement64_acq|\__int64 \*__int64 _InterlockedIncrement64_acq|
|_InterlockedIncrement64_nf|_InterlockedIncrement64_nf\___int64(_int64 \*volátil)|
|_InterlockedIncrement64_rel|_InterlockedIncrement64_rel __int64(\_ \*_int64 volátil )|
|_InterlockedIncrement_acq|longo _InterlockedIncrement_acq (longo volátil) \*|
|_InterlockedIncrement_nf|longo _InterlockedIncrement_nf (longo volátil) \*|
|_InterlockedIncrement_rel|_InterlockedIncrement_rel longo (longo volátil) \*|
|_InterlockedOr|_InterlockedOr longo (longo volátil, \*longo)|
|_InterlockedOr16|_InterlockedOr16 curto (curto volátil, \*curto)|
|_InterlockedOr16_acq|_InterlockedOr16_acq curto (curto volátil, \*curto)|
|_InterlockedOr16_nf|_InterlockedOr16_nf curto (curto volátil, \*curto)|
|_InterlockedOr16_rel|_InterlockedOr16_rel curto (curto volátil, \*curto)|
|_InterlockedOr64|__int64 _InterlockedOr64(\_ \*_int64 \_volátil , _int64)|
|_InterlockedOr64_acq|_InterlockedOr64_acq __int64\__int64 \* \__int64|
|_InterlockedOr64_nf|__int64\__InterlockedOr64_nf( \*_int64 \_volátil , _int64)|
|_InterlockedOr64_rel|_InterlockedOr64_rel\___int64(_int64 \* \_volátil , _int64)|
|_InterlockedOr8|char _InterlockedOr8 (char volátil, \*char)|
|_InterlockedOr8_acq|char _InterlockedOr8_acq (char volátil, \*char)|
|_InterlockedOr8_nf|char _InterlockedOr8_nf (char volátil, \*char)|
|_InterlockedOr8_rel|char _InterlockedOr8_rel (char volátil, \*char)|
|_InterlockedOr_acq|longo _InterlockedOr_acq (longo volátil, \*longo)|
|_InterlockedOr_nf|_InterlockedOr_nf longo (longo volátil, \*longo)|
|_InterlockedOr_rel|longo _InterlockedOr_rel (longo volátil, \*longo)|
|_InterlockedXor|_InterlockedXor longo (longo volátil, \*longo)|
|_InterlockedXor16|_InterlockedXor16 curto (curto volátil, \*curto)|
|_InterlockedXor16_acq|_InterlockedXor16_acq curto (curto volátil, \*curto)|
|_InterlockedXor16_nf|_InterlockedXor16_nf curto (curto volátil, \*curto)|
|_InterlockedXor16_rel|_InterlockedXor16_rel curto (curto volátil, \*curto)|
|_InterlockedXor64|__int64 _InterlockedXor64(\_ \*_int64 \_volátil , _int64)|
|_InterlockedXor64_acq|_InterlockedXor64_acq __int64\__int64 \* \__int64 _int64|
|_InterlockedXor64_nf|__int64 _InterlockedXor64_nf(\_ \*_int64 \_volátil , _int64)|
|_InterlockedXor64_rel|_InterlockedXor64_rel\___int64(_int64 \* \_volátil , _int64)|
|_InterlockedXor8|char _InterlockedXor8 (char volátil, \*char)|
|_InterlockedXor8_acq|char _InterlockedXor8_acq (char volátil, \*char)|
|_InterlockedXor8_nf|char _InterlockedXor8_nf (char volátil, \*char)|
|_InterlockedXor8_rel|char _InterlockedXor8_rel (char volátil, \*char)|
|_InterlockedXor_acq|_InterlockedXor_acq longo (longo volátil, \*longo)|
|_InterlockedXor_nf|longo _InterlockedXor_nf (longo volátil, \*longo)|
|_InterlockedXor_rel|longo _InterlockedXor_rel (longo volátil, \*longo)|

[[Voltar ao topo](#top)]

### <a name="_interlockedbittest-intrinsics"></a>intrínsecos _interlockedbittest

Os intrínsecos de teste de bits interbloqueados simples são comuns a todas as plataformas. ARM64 `_acq`adiciona `_rel`, `_nf` e variantes, que apenas modificam a semântica de barreira de uma operação, como descrito em [_nf (sem cerca) Sufixo](#nf_suffix) no início deste artigo.

|Nome da função|Protótipo da função|
|-------------------|------------------------|
|_interlockedbittestandreset|char não assinado _interlockedbittestandreset \*(longo volátil, longo)|
|_interlockedbittestandreset_acq|char não assinado _interlockedbittestandreset_acq \*(longo volátil, longo)|
|_interlockedbittestandreset_nf|char não assinado _interlockedbittestandreset_nf \*(longo volátil, longo)|
|_interlockedbittestandreset_rel|char não assinado _interlockedbittestandreset_rel \*(longo volátil, longo)|
|_interlockedbittestandreset64|char _interlockedbittestandreset64 não assinado \*(__int64 volátil , __int64)|
|_interlockedbittestandreset64_acq|char _interlockedbittestandreset64_acq não assinado(__int64 volátil \*, __int64)|
|_interlockedbittestandreset64_nf|char _interlockedbittestandreset64_nf não assinado \*(__int64 volátil , __int64)|
|_interlockedbittestandreset64_rel|_interlockedbittestandreset64_rel de char não \*assinado(__int64 volátil , __int64)|
|_interlockedbittestandset|char não assinado _interlockedbittestandset \*(longo volátil, longo)|
|_interlockedbittestandset_acq|char não assinado _interlockedbittestandset_acq \*(longo volátil, longo)|
|_interlockedbittestandset_nf|char não assinado _interlockedbittestandset_nf \*(longo volátil, longo)|
|_interlockedbittestandset_rel|char não assinado _interlockedbittestandset_rel \*(longo volátil, longo)|
|_interlockedbittestandset64|char _interlockedbittestandset64 não assinado \*(__int64 volátil, __int64)|
|_interlockedbittestandset64_acq|char _interlockedbittestandset64_acq não assinado(__int64 volátil \*, __int64)|
|_interlockedbittestandset64_nf|char _interlockedbittestandset64_nf não assinado \*(__int64 volátil , __int64)|
|_interlockedbittestandset64_rel|_interlockedbittestandset64_rel char não assinado \*(__int64 volátil, __int64)|

[[Voltar ao topo](#top)]

## <a name="see-also"></a>Confira também

[Intrínseca do compilador](../intrinsics/compiler-intrinsics.md)\
[Intrínseca arm](arm-intrinsics.md)\
[Referência do montador ARM](../assembler/arm/arm-assembler-reference.md)\
[Referência em linguagem C++](../cpp/cpp-language-reference.md)
