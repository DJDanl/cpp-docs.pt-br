---
title: Intrínsecos do ARM64
description: Lista de referência de intrínsecos ARM64 com suporte do compilador do Microsoft C++ no Visual Studio.
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
helpviewer_keywords:
- __break ARM64 intrinsic
- __addx18byte ARM64 intrinsic
- __addx18word ARM64 intrinsic
- __addx18dword ARM64 intrinsic
- __addx18qword ARM64 intrinsic
- __cas8 ARM64 intrinsic
- __cas16 ARM64 intrinsic
- __cas32 ARM64 intrinsic
- __cas64 ARM64 intrinsic
- __casa8 ARM64 intrinsic
- __casa16 ARM64 intrinsic
- __casa32 ARM64 intrinsic
- __casa64 ARM64 intrinsic
- __casl8 ARM64 intrinsic
- __casl16 ARM64 intrinsic
- __casl32 ARM64 intrinsic
- __casl64 ARM64 intrinsic
- __casal8 ARM64 intrinsic
- __casal16 ARM64 intrinsic
- __casal32 ARM64 intrinsic
- __casal64 ARM64 intrinsic
- __crc32b ARM64 intrinsic
- __crc32h ARM64 intrinsic
- __crc32w ARM64 intrinsic
- __crc32d ARM64 intrinsic
- __crc32cb ARM64 intrinsic
- __crc32ch ARM64 intrinsic
- __crc32cw ARM64 intrinsic
- __crc32cd ARM64 intrinsic
- __getReg ARM64 intrinsic
- __getRegFp ARM64 intrinsic
- __getCallerReg ARM64 intrinsic
- __getCallerRegFp ARM64 intrinsic
- __hlt ARM64 intrinsic
- __incx18byte ARM64 intrinsic
- __incx18word ARM64 intrinsic
- __incx18dword ARM64 intrinsic
- __incx18qword ARM64 intrinsic
- __ldar8 ARM64 intrinsic
- __ldar16 ARM64 intrinsic
- __ldar32 ARM64 intrinsic
- __ldar64 ARM64 intrinsic
- __ldapr8 ARM64 intrinsic
- __ldapr16 ARM64 intrinsic
- __ldapr32 ARM64 intrinsic
- __ldapr64 ARM64 intrinsic
- __prefetch2 ARM64 intrinsic
- __readx18byte ARM64 intrinsic
- __readx18word ARM64 intrinsic
- __readx18dword ARM64 intrinsic
- __readx18qword ARM64 intrinsic
- __setReg ARM64 intrinsic
- __setRegFp ARM64 intrinsic
- __setCallerReg ARM64 intrinsic
- __setCallerRegFp ARM64 intrinsic
- __stlr8 ARM64 intrinsic
- __stlr16 ARM64 intrinsic
- __stlr32 ARM64 intrinsic
- __stlr64 ARM64 intrinsic
- __swp8 ARM64 intrinsic
- __swp16 ARM64 intrinsic
- __swp32 ARM64 intrinsic
- __swp64 ARM64 intrinsic
- __swpa8 ARM64 intrinsic
- __swpa16 ARM64 intrinsic
- __swpa32 ARM64 intrinsic
- __swpa64 ARM64 intrinsic
- __swpl8 ARM64 intrinsic
- __swpl16 ARM64 intrinsic
- __swpl32 ARM64 intrinsic
- __swpl64 ARM64 intrinsic
- __swpal8 ARM64 intrinsic
- __swpal16 ARM64 intrinsic
- __swpal32 ARM64 intrinsic
- __swpal64 ARM64 intrinsic
- __sys ARM64 intrinsic
- __svc ARM64 intrinsic
- __writex18byte ARM64 intrinsic
- __writex18word ARM64 intrinsic
- __writex18dword ARM64 intrinsic
- __writex18qword ARM64 intrinsic
author: sigatrev
ms.author: magardn
ms.date: 11/14/2019
ms.openlocfilehash: 13358458bf9abcf0bc6e38ca115b537abc99300a
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90039749"
---
# <a name="arm64-intrinsics"></a>Intrínsecos do ARM64

O compilador do Microsoft C++ (MSVC) torna os seguintes intrínsecos disponíveis na arquitetura do ARM64. Para obter mais informações sobre o ARM, consulte as seções arquitetura e ferramentas de desenvolvimento de software do site de [documentação do desenvolvedor ARM](https://developer.arm.com/docs) .

## <a name="neon"></a><a name="top"></a> NEON

As extensões do conjunto de instruções de vetor NEON para ARM64 fornecem recursos de Single Instruction Multiple Data (SIMD). Eles se assemelham àqueles nos conjuntos de instruções MMX e SSE vector que são comuns a processadores de arquitetura x86 e x64.

Os intrínsecos NEON têm suporte, conforme fornecido no arquivo de cabeçalho *arm64_neon. h*. O suporte do MSVC para NEON intrínsecos é semelhante ao do compilador do ARM64, que está documentado na [referência intrínseca do ARM Neon](https://static.docs.arm.com/ihi0073/c/IHI0073C_arm_neon_intrinsics_ref.pdf) no site do INFOCENTER do ARM.

## <a name="arm64-specific-intrinsics-listing"></a><a name="A"></a> Listagem de intrínsecos específicos do ARM64

|Nome da função|Instrução|Protótipo da função|
|-------------------|-----------------|------------------------|
|__break|BRK|__break void (int)|
|__addx18byte||void __addx18byte (sem sinal, caractere não assinado, caracteres não assinados)|
|__addx18word||void __addx18word (sem sinal, curto, não assinado)|
|__addx18dword||void __addx18dword (sem sinal, Long sem sinal)|
|__addx18qword||void __addx18qword (sem sinal, __int64 não assinado)|
|__cas8|CASB|__int8 não assinado __cas8 (não assinado __int8 volátil * _Target, não assinado __int8 _Comp, não assinado __int8 _Value)|
|__cas16|ESPÉCIE|__int16 não assinado __cas16 (não assinado __int16 volátil * _Target, não assinado __int16 _Comp, não assinado __int16 _Value)|
|__cas32|CAS|__int32 não assinado __cas32 (não assinado __int32 volátil * _Target, não assinado __int32 _Comp, não assinado __int32 _Value)|
|__cas64|CAS|__int64 não assinado __cas64 (não assinado __int64 volátil * _Target, não assinado __int64 _Comp, não assinado __int64 _Value)|
|__casa8|CASAB|__int8 não assinado __casa8 (não assinado __int8 volátil * _Target, não assinado __int8 _Comp, não assinado __int8 _Value)|
|__casa16|CASAH|__int16 não assinado __casa16 (não assinado __int16 volátil * _Target, não assinado __int16 _Comp, não assinado __int16 _Value)|
|__casa32|CASA|__int32 não assinado __casa32 (não assinado __int32 volátil * _Target, não assinado __int32 _Comp, não assinado __int32 _Value)|
|__casa64|CASA|__int64 não assinado __casa64 (não assinado __int64 volátil * _Target, não assinado __int64 _Comp, não assinado __int64 _Value)|
|__casl8|CASLB|__int8 não assinado __casl8 (não assinado __int8 volátil * _Target, não assinado __int8 _Comp, não assinado __int8 _Value)|
|__casl16|CASLH|__int16 não assinado __casl16 (não assinado __int16 volátil * _Target, não assinado __int16 _Comp, não assinado __int16 _Value)|
|__casl32|CASL|__int32 não assinado __casl32 (não assinado __int32 volátil * _Target, não assinado __int32 _Comp, não assinado __int32 _Value)|
|__casl64|CASL|__int64 não assinado __casl64 (não assinado __int64 volátil * _Target, não assinado __int64 _Comp, não assinado __int64 _Value)|
|__casal8|CASALB|__int8 não assinado __casal8 (não assinado __int8 volátil * _Target, não assinado __int8 _Comp, não assinado __int8 _Value)|
|__casal16|CASALH|__int16 não assinado __casal16 (não assinado __int16 volátil * _Target, não assinado __int16 _Comp, não assinado __int16 _Value)|
|__casal32|CASAL|__int32 não assinado __casal32 (não assinado __int32 volátil * _Target, não assinado __int32 _Comp, não assinado __int32 _Value)|
|__casal64|CASAL|__int64 não assinado __casal64 (não assinado __int64 volátil * _Target, não assinado __int64 _Comp, não assinado __int64 _Value)|
|__crc32b|CRC32B|__crc32b de __int32 não assinado (__int32 não assinado, __int32 não assinado)|
|__crc32h|CRC32H|__crc32h de __int32 não assinado (__int32 não assinado, __int32 não assinado)|
|__crc32w|CRC32W|__crc32w de __int32 não assinado (__int32 não assinado, __int32 não assinado)|
|__crc32d|CRC32X|__crc32d de __int32 não assinado (__int32 não assinado, __int64 não assinado)|
|__crc32cb|CRC32CB|__crc32cb de __int32 não assinado (__int32 não assinado, __int32 não assinado)|
|__crc32ch|CRC32CH|__crc32ch de __int32 não assinado (__int32 não assinado, __int32 não assinado)|
|__crc32cw|CRC32CW|__crc32cw de __int32 não assinado (__int32 não assinado, __int32 não assinado)|
|__crc32cd|CRC32CX|__crc32cd de __int32 não assinado (__int32 não assinado, __int64 não assinado)|
|__dmb|DMB|void __dmb(unsigned int `_Type`)<br /><br /> Insere uma operação de barreira de memória no fluxo de instruções. O parâmetro `_Type` especifica o tipo de restrição que a barreira impõe.<br /><br /> Para obter mais informações sobre os tipos de restrições que podem ser impostas, consulte [restrições de barreira de memória](#BarrierRestrictions).|
|__dsb|DSB|void __dsb(unsigned int _Type)<br /><br /> Insere uma operação de barreira de memória no fluxo de instruções. O parâmetro `_Type` especifica o tipo de restrição que a barreira impõe.<br /><br /> Para obter mais informações sobre os tipos de restrições que podem ser impostas, consulte [restrições de barreira de memória](#BarrierRestrictions).|
|__isb|ISB|void __isb(unsigned int _Type)<br /><br /> Insere uma operação de barreira de memória no fluxo de instruções. O parâmetro `_Type` especifica o tipo de restrição que a barreira impõe.<br /><br /> Para obter mais informações sobre os tipos de restrições que podem ser impostas, consulte [restrições de barreira de memória](#BarrierRestrictions).|
|__getReg||__getReg de __int64 não assinado (int)|
|__getRegFp||__getRegFp duplo (int)|
|__getCallerReg||__getCallerReg de __int64 não assinado (int)|
|__getCallerRegFp||__getCallerRegFp duplo (int)|
|__hvc|HVC|unsigned int __hvc(unsigned int, ...)|
|__hlt|HLT|int __hlt (sem sinal int,...)|
|__incx18byte||__incx18byte void (longo sem sinal)|
|__incx18word||__incx18word void (longo sem sinal)|
|__incx18dword||__incx18dword void (longo sem sinal)|
|__incx18qword||__incx18qword void (longo sem sinal)|
|__iso_volatile_load16||__int16 \_ _iso_volatile_load16 (const volatile \_ _int16 \* )<br /><br /> Para obter mais informações, consulte [__iso_volatile_load/Store intrínsecos](#IsoVolatileLoadStore).|
|__iso_volatile_load32||__int32 \_ _iso_volatile_load32 (const volatile \_ _int32 \* )<br /><br /> Para obter mais informações, consulte [__iso_volatile_load/Store intrínsecos](#IsoVolatileLoadStore).|
|__iso_volatile_load64||__int64 \_ _iso_volatile_load64 (const volatile \_ _int64 \* )<br /><br /> Para obter mais informações, consulte [__iso_volatile_load/Store intrínsecos](#IsoVolatileLoadStore).|
|__iso_volatile_load8||__int8 \_ _iso_volatile_load8 (const volatile \_ _int8 \* )<br /><br /> Para obter mais informações, consulte [__iso_volatile_load/Store intrínsecos](#IsoVolatileLoadStore).|
|__iso_volatile_store16||void __iso_volatile_store16 (volátil \_ _int16 \* , \_ _int16)<br /><br /> Para obter mais informações, consulte [__iso_volatile_load/Store intrínsecos](#IsoVolatileLoadStore).|
|__iso_volatile_store32||void __iso_volatile_store32 (volátil \_ _int32 \* , \_ _int32)<br /><br /> Para obter mais informações, consulte [__iso_volatile_load/Store intrínsecos](#IsoVolatileLoadStore).|
|__iso_volatile_store64||void __iso_volatile_store64 (volátil \_ _int64 \* , \_ _int64)<br /><br /> Para obter mais informações, consulte [__iso_volatile_load/Store intrínsecos](#IsoVolatileLoadStore).|
|__iso_volatile_store8||void __iso_volatile_store8 (volátil \_ _int8 \* , \_ _int8)<br /><br /> Para obter mais informações, consulte [__iso_volatile_load/Store intrínsecos](#IsoVolatileLoadStore).|
|__ldar8|LDARB|__ldar8 de __int8 não assinado (não assinado __int8 volátil * _Target)|
|__ldar16|LDARH|__ldar16 de __int16 não assinado (não assinado __int16 volátil * _Target)|
|__ldar32|LDAR|__ldar32 de __int32 não assinado (não assinado __int32 volátil * _Target)|
|__ldar64|LDAR|__ldar64 de __int64 não assinado (não assinado __int64 volátil * _Target)|
|__ldapr8|LDAPRB|__ldapr8 de __int8 não assinado (não assinado __int8 volátil * _Target)|
|__ldapr16|LDAPRH|__ldapr16 de __int16 não assinado (não assinado __int16 volátil * _Target)|
|__ldapr32|LDAP|__ldapr32 de __int32 não assinado (não assinado __int32 volátil * _Target)|
|__ldapr64|LDAP|__ldapr64 de __int64 não assinado (não assinado __int64 volátil * _Target)|
|__mulh||\___mulh de _int64 ( \_ _int64 \_ _int64)|
|__prefetch|PRFM|void __cdecl \_ _prefetch (const void \* )<br /><br /> Fornece uma `PRFM` dica de memória com a operação de pré-busca `PLDL1KEEP` para o sistema em que a memória no endereço especificado ou próximo dele pode ser acessada em breve. Alguns sistemas podem optar por otimizar para esse padrão de acesso de memória para aumentar o desempenho de runtime. No entanto, do ponto de vista da linguagem C++, a função não tem efeito observável e pode não ter nenhuma ação.|
|__prefetch2|PRFM|void __cdecl \_ _prefetch (const void \* , uint8_t prfop)<br /><br /> Fornece uma `PRFM` dica de memória com a operação de pré-busca fornecida para o sistema em que a memória no endereço especificado ou próximo dele pode ser acessada em breve. Alguns sistemas podem optar por otimizar para esse padrão de acesso de memória para aumentar o desempenho de runtime. No entanto, do ponto de vista da linguagem C++, a função não tem efeito observável e pode não ter nenhuma ação.|
|__readx18byte||__readx18byte de caracteres não assinados (longo sem sinal)|
|__readx18word||__readx18word curto não assinado (Long sem sinal)|
|__readx18dword||__readx18dword longo sem sinal (longo sem sinal)|
|__readx18qword||__readx18qword de __int64 não assinado (longo sem sinal)|
|__setReg||void __setReg (int, não assinado __int64)|
|__setRegFp||void __setRegFp (int, Double)|
|__setCallerReg||void __setCallerReg (int, não assinado __int64)|
|__setCallerRegFp||void __setCallerRegFp (int, Double)|
|__sev|SETE|void __sev(void)|
|__static_assert||void __static_assert (int, const char \* )|
|__stlr8|STLRB|void __stlr8 (não assinado __int8 volátil * _Target, __int8 não assinado _Value)|
|__stlr16|STLRH|void __stlr16 (não assinado __int16 volátil * _Target, __int16 não assinado _Value)|
|__stlr32|STLR|void __stlr32 (não assinado __int32 volátil * _Target, __int32 não assinado _Value)|
|__stlr64|STLR|void __stlr64 (não assinado __int64 volátil * _Target, __int64 não assinado _Value)|
|__swp8|SWPB|__swp8 de __int8 não assinado (não assinado __int8 volátil * _Target, __int8 sem sinal _Value)|
|__swp16|SWPH|__swp16 de __int16 não assinado (não assinado __int16 volátil * _Target, __int16 sem sinal _Value)|
|__swp32|SWP|__swp32 de __int32 não assinado (não assinado __int32 volátil * _Target, __int32 sem sinal _Value)|
|__swp64|SWP|__swp64 de __int64 não assinado (não assinado __int64 volátil * _Target, __int64 sem sinal _Value)|
|__swpa8|SWPAB|__swpa8 de __int8 não assinado (não assinado __int8 volátil * _Target, __int8 sem sinal _Value)|
|__swpa16|SWPAH|__swpa16 de __int16 não assinado (não assinado __int16 volátil * _Target, __int16 sem sinal _Value)|
|__swpa32|SWPA|__swpa32 de __int32 não assinado (não assinado __int32 volátil * _Target, __int32 sem sinal _Value)|
|__swpa64|SWPA|__swpa64 de __int64 não assinado (não assinado __int64 volátil * _Target, __int64 sem sinal _Value)|
|__swpl8|SWPLB|__swpl8 de __int8 não assinado (não assinado __int8 volátil * _Target, __int8 sem sinal _Value)|
|__swpl16|SWPLH|__swpl16 de __int16 não assinado (não assinado __int16 volátil * _Target, __int16 sem sinal _Value)|
|__swpl32|SWPL|__swpl32 de __int32 não assinado (não assinado __int32 volátil * _Target, __int32 sem sinal _Value)|
|__swpl64|SWPL|__swpl64 de __int64 não assinado (não assinado __int64 volátil * _Target, __int64 sem sinal _Value)|
|__swpal8|SWPALB|__swpal8 de __int8 não assinado (não assinado __int8 volátil * _Target, __int8 sem sinal _Value)|
|__swpal16|SWPALH|__swpal16 de __int16 não assinado (não assinado __int16 volátil * _Target, __int16 sem sinal _Value)|
|__swpal32|SWPAL|__swpal32 de __int32 não assinado (não assinado __int32 volátil * _Target, __int32 sem sinal _Value)|
|__swpal64|SWPAL|__swpal64 de __int64 não assinado (não assinado __int64 volátil * _Target, __int64 sem sinal _Value)|
|__sys|SISTEMA|__sys int não assinado (int, __int64)|
|__svc|SVC|__svc int não assinado (int sem sinal,...)|
|__wfe|WFE|void __wfe(void)|
|__wfi|WFI|void __wfi(void)|
|__writex18byte||void __writex18byte (sem sinal, caractere não assinado, caracteres não assinados)|
|__writex18word||void __writex18word (sem sinal, curto, não assinado)|
|__writex18dword||void __writex18dword (sem sinal, Long sem sinal)|
|__writex18qword||void __writex18qword (sem sinal, __int64 não assinado)|
|__umulh||__umulh de _int64 não assinado \_ (_int64 não assinado \_ , _int64 não assinado \_ )|
|_CopyDoubleFromInt64||_CopyDoubleFromInt64 duplo ( \_ _int64)|
|_CopyFloatFromInt32||_CopyFloatFromInt32 flutuante ( \_ _int32)|
|_CopyInt32FromFloat||__int32 _CopyInt32FromFloat(float)|
|_CopyInt64FromDouble||__int64 _CopyInt64FromDouble(double)|
|_CountLeadingOnes||unsigned int _CountLeadingOnes(unsigned long)|
|_CountLeadingOnes64||_CountLeadingOnes64 int não assinado (_int64 não assinado \_ )|
|_CountLeadingSigns||unsigned int _CountLeadingSigns(long)|
|_CountLeadingSigns64||_CountLeadingSigns64 int não assinado ( \_ _int64)|
|_CountLeadingZeros||unsigned int _CountLeadingZeros(unsigned long)|
|_CountLeadingZeros64||_CountLeadingZeros64 int não assinado (_int64 não assinado \_ )|
|_ReadStatusReg|MRS|\__int64 _ReadStatusReg (int)|
|_WriteStatusReg|MSR|void _WriteStatusReg (int, \_ _int64)|

[[Retornar ao início](#top)]

### <a name="memory-barrier-restrictions"></a><a name="BarrierRestrictions"></a> Restrições de barreira de memória

As funções intrínsecas `__dmb` (barreira de memória de dados), `__dsb` (barreira de sincronização de dados) e `__isb` (barreira de sincronização de instrução) usam os seguintes valores predefinidos para especificar a restrição de barreira de memória em termos do domínio de compartilhamento e o tipo de acesso que são afetados pela operação.

|Valor de restrição|Descrição|
|-----------------------|-----------------|
|_ARM64_BARRIER_SY|Sistema completo, leituras e gravações.|
|_ARM64_BARRIER_ST|Sistema completo, somente gravações.|
|_ARM64_BARRIER_LD|Sistema completo, somente leitura.|
|_ARM64_BARRIER_ISH|Compartilháveis internos, leituras e gravações.|
|_ARM64_BARRIER_ISHST|Compartilháveis internos, somente gravações.|
|_ARM64_BARRIER_ISHLD|Compartilhável interno, somente leitura.|
|_ARM64_BARRIER_NSH|Não compartilháveis, leituras e gravações.|
|_ARM64_BARRIER_NSHST|Não compartilháveis, somente gravações.|
|_ARM64_BARRIER_NSHLD|Não compartilhável, somente leitura.|
|_ARM64_BARRIER_OSH|Compartilháveis externos, leituras e gravações.|
|_ARM64_BARRIER_OSHST|Compartilháveis externos, somente gravações.|
|_ARM64_BARRIER_OSHLD|Compartilhável externo, somente leitura.|

Para `__isb` intrínseco, a única restrição atualmente válida é _ARM64_BARRIER_SY; todos os outros valores são reservados pela arquitetura.

### <a name="__iso_volatile_loadstore-intrinsics"></a><a name="IsoVolatileLoadStore"></a> __iso_volatile_load intrínsecos do/Store

Essas funções intrínsecas executam explicitamente cargas e armazenamentos que não estão sujeitos a otimizações do compilador.

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

*Value*\
O valor a ser gravado no local de memória especificado (somente intrínsecos do repositório).

#### <a name="return-value-load-intrinsics-only"></a>Valor de retorno (somente intrínsecos de carregamento)

O valor do local da memória que é especificado por *local*.

#### <a name="remarks"></a>Comentários

Você pode usar o `__iso_volatile_load8/16/32/64` e `__iso_volatile_store8/16/32/64` intrínsecos para executar explicitamente os acessos de memória que não estão sujeitos a otimizações do compilador. O compilador não pode remover, synthetizer ou alterar a ordem relativa dessas operações. No entanto, ele não gera barreiras de memória de hardware implícitas. Portanto, o hardware ainda pode reorganizar os acessos de memória observáveis entre vários threads. Mais precisamente, esses intrínsecos são equivalentes às expressões a seguir como compiladas em **/volatile: ISO**.

```cpp
int a = __iso_volatile_load32(p);    // equivalent to: int a = *(const volatile __int32*)p;
__iso_volatile_store32(p, a);        // equivalent to: *(volatile __int32*)p = a;
```

Observe que o intrínseco usa ponteiros voláteis para acomodar variáveis voláteis. No entanto, não há nenhum requisito ou recomendação para usar ponteiros voláteis como argumentos. A semântica dessas operações é exatamente a mesma se um tipo regular, não volátil, for usado.

Para obter mais informações sobre o argumento de linha de comando **/volatile: ISO** , consulte [/volatile (interpretação de palavra-chave volátil)](../build/reference/volatile-volatile-keyword-interpretation.md).

## <a name="arm64-support-for-intrinsics-from-other-architectures"></a><a name="I"></a> Suporte a ARM64 para intrínsecos de outras arquiteturas

A tabela a seguir lista intrínsecas de outras arquiteturas com suporte em plataformas ARM64. Onde o comportamento de um intrínseco em ARM64 difere do seu comportamento em outras arquiteturas de hardware, detalhes adicionais são observados.

|Nome da função|Protótipo da função|
|-------------------|------------------------|
|__assume|void __assume(int)|
|__code_seg|void __code_seg (const char \* )|
|__debugbreak|void __cdecl \_ _debugbreak (void)|
|__fastfail|__declspec (noreturn) void \_ _fastfail (sem sinal int)|
|__nop|void __nop(void)|
|__yield|void __yield (void) **Observação:**  em plataformas ARM64, essa função gera a instrução yield. Essa instrução indica que o thread está executando uma tarefa que pode ser temporariamente suspensa da execução — por exemplo, um spinlock — sem afetar negativamente o programa. Ele permite que a CPU execute outras tarefas durante os ciclos de execução que, de outra forma, seriam desperdiçados.|
|_AddressOfReturnAddress|void \* _AddressOfReturnAddress (void)|
|_BitScanForward|_BitScanForward de caracteres não assinados (_Index longo sem sinal \* , _Mask longo sem sinal)|
|_BitScanForward64|_BitScanForward64 de caracteres não assinados (_Index longos não assinados \* , _Mask de __int64 não assinado)|
|_BitScanReverse|_BitScanReverse de caracteres não assinados (_Index longo sem sinal \* , _Mask longo sem sinal)|
|_BitScanReverse64|_BitScanReverse64 de caracteres não assinados (_Index longos não assinados \* , _Mask de __int64 não assinado)|
|_bittest|_bittest de caracteres não assinados (Long const \* , Long)|
|_bittest64|_bittest64 de caracteres não assinados (__int64 const \* , __int64)|
|_bittestandcomplement|_bittestandcomplement de caracteres sem sinal (longo \* , longo)|
|_bittestandcomplement64|_bittestandcomplement64 de caracteres não assinados (__int64 \* , __int64)|
|_bittestandreset|_bittestandreset de caracteres sem sinal (longo \* , longo)|
|_bittestandreset64|_bittestandreset64 de caracteres não assinados (__int64 \* , __int64)|
|_bittestandset|_bittestandset de caracteres sem sinal (longo \* , longo)|
|_bittestandset64|_bittestandset64 de caracteres não assinados (__int64 \* , __int64)|
|_byteswap_uint64|__int64 não assinado \_ _cdecl _byteswap_uint64 (_int64 não assinado \_ )|
|_byteswap_ulong|unsigned long __cdecl _byteswap_ulong(unsigned long)|
|_byteswap_ushort|unsigned short __cdecl _byteswap_ushort(unsigned short)|
|_disable|void __cdecl _disable (void) **Observação:**  em plataformas ARM64, essa função gera a instrução `MSR DAIFCLR,#2` ; ela só está disponível como intrínseca.|
|_enable|void __cdecl _enable (void) **Observação:**  em plataformas ARM64, essa função gera a instrução `MSR DAIFSET,#2` ; ela só está disponível como intrínseca.|
|_lrotl|unsigned long __cdecl _lrotl(unsigned long, int)|
|_lrotr|unsigned long __cdecl _lrotr(unsigned long, int)|
|_ReadBarrier|void _ReadBarrier(void)|
|_ReadWriteBarrier|void _ReadWriteBarrier(void)|
|_ReturnAddress|void \* _ReturnAddress (void)|
|_rotl|unsigned int __cdecl _rotl(unsigned int _Value, int _Shift)|
|_rotl16|unsigned short _rotl16(unsigned short _Value, unsigned char _Shift)|
|_rotl64|__int64 não assinados \_ _cdecl _rotl64 (_int64 não assinado \_ _Value, int _Shift)|
|_rotl8|unsigned char _rotl8(unsigned char _Value, unsigned char _Shift)|
|_rotr|unsigned int __cdecl _rotr(unsigned int _Value, int _Shift)|
|_rotr16|unsigned short _rotr16(unsigned short _Value, unsigned char _Shift)|
|_rotr64|__int64 não assinados \_ _cdecl _rotr64 (_int64 não assinado \_ _Value, int _Shift)|
|_rotr8|unsigned char _rotr8(unsigned char _Value, unsigned char _Shift)|
|_setjmpex|int __cdecl _setjmpex(jmp_buf)|
|_WriteBarrier|void _WriteBarrier(void)|

[[Retornar ao início](#top)]

## <a name="interlocked-intrinsics"></a>Intrínsecos intercadeados

Intrínsecos sincronizados são um conjunto de intrínsecos usados para executar operações atômicas de leitura, gravação e alteração. Alguns deles são comuns a todas as plataformas. Eles são listados separadamente aqui porque há um grande número deles. Como suas definições são principalmente redundantes, é mais fácil pensar sobre elas em termos gerais. Seus nomes podem ser usados para gerar comportamentos exatos.

A tabela a seguir resume o suporte a ARM64 dos intrínsecos não desbloqueados não mais. Cada célula da tabela corresponde a um nome que é derivado acrescentando o nome da operação na célula mais à esquerda da linha e o nome do tipo na célula superior da coluna para `_Interlocked`. Por exemplo, a célula na interseção da `Xor` linha e a `8` coluna correspondem a `_InterlockedXor8` e tem suporte total. A maioria das funções com suporte oferece estes sufixos opcionais: `_acq`, `_rel`, e `_nf`. O sufixo `_acq` indica uma semântica "acquire" e o sufixo `_rel` indica uma semântica uma "release". O `_nf` sufixo ou "sem limite" é exclusivo para ARM e ARM64 e é discutido na próxima seção.

|Operação|8|16|32|64|128|P|
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

- **Completo**: dá suporte a `_acq` formulários simples,, `_rel` e `_nf` .

- **Nenhum**: sem suporte

### <a name="_nf-no-fence-suffix"></a><a name="nf_suffix"></a> sufixo de _nf (sem limite)

O `_nf` sufixo ou "sem limite" indica que a operação não se comporta como qualquer tipo de barreira de memória, em oposição às outras três formas (simples, `_acq` e `_rel` ), que se comportam como algum tipo de barreira. Um possível uso dos `_nf` formulários é manter um contador de estatísticas que é atualizado por vários threads ao mesmo tempo, mas cujo valor não é usado de outra forma enquanto vários threads estão em execução.

### <a name="list-of-interlocked-intrinsics"></a>Lista de intrínsecos intercadeados

|Nome da função|Protótipo da função|
|-------------------|------------------------|
|_InterlockedAdd|_InterlockedAdd longo (longo _volatile \* , longo)|
|_InterlockedAdd64|__int64 _InterlockedAdd64 ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedAdd64_acq|__int64 _InterlockedAdd64_acq ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedAdd64_nf|__int64 _InterlockedAdd64_nf ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedAdd64_rel|__int64 _InterlockedAdd64_rel ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedAdd_acq|_InterlockedAdd_acq longo (Long volátil \* , longo)|
|_InterlockedAdd_nf|_InterlockedAdd_nf longo (Long volátil \* , longo)|
|_InterlockedAdd_rel|_InterlockedAdd_rel longo (Long volátil \* , longo)|
|_InterlockedAnd|_InterlockedAnd longo (Long volátil \* , longo)|
|_InterlockedAnd16|_InterlockedAnd16 curto (pequeno volátil \* , curto)|
|_InterlockedAnd16_acq|_InterlockedAnd16_acq curto (pequeno volátil \* , curto)|
|_InterlockedAnd16_nf|_InterlockedAnd16_nf curto (pequeno volátil \* , curto)|
|_InterlockedAnd16_rel|_InterlockedAnd16_rel curto (pequeno volátil \* , curto)|
|_InterlockedAnd64|__int64 _InterlockedAnd64 ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedAnd64_acq|__int64 _InterlockedAnd64_acq ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedAnd64_nf|__int64 _InterlockedAnd64_nf ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedAnd64_rel|__int64 _InterlockedAnd64_rel ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedAnd8|Char _InterlockedAnd8 (Char volátil \* , Char)|
|_InterlockedAnd8_acq|Char _InterlockedAnd8_acq (Char volátil \* , Char)|
|_InterlockedAnd8_nf|Char _InterlockedAnd8_nf (Char volátil \* , Char)|
|_InterlockedAnd8_rel|Char _InterlockedAnd8_rel (Char volátil \* , Char)|
|_InterlockedAnd_acq|_InterlockedAnd_acq longo (Long volátil \* , longo)|
|_InterlockedAnd_nf|_InterlockedAnd_nf longo (Long volátil \* , longo)|
|_InterlockedAnd_rel|_InterlockedAnd_rel longo (Long volátil \* , longo)|
|_InterlockedCompareExchange|longo __cdecl _InterlockedCompareExchange (Long volátil \* , longo, longo)|
|_InterlockedCompareExchange_acq|_InterlockedCompareExchange_acq longo (Long volátil \* , longo, longo)|
|_InterlockedCompareExchange_nf|_InterlockedCompareExchange_nf longo (Long volátil \* , longo, longo)|
|_InterlockedCompareExchange_rel|_InterlockedCompareExchange_rel longo (Long volátil \* , longo, longo)|
|_InterlockedCompareExchange16|_InterlockedCompareExchange16 curto (pequeno volátil \* , curto, curto)|
|_InterlockedCompareExchange16_acq|_InterlockedCompareExchange16_acq curto (pequeno volátil \* , curto, curto)|
|_InterlockedCompareExchange16_nf|_InterlockedCompareExchange16_nf curto (pequeno volátil \* , curto, curto)|
|_InterlockedCompareExchange16_rel|_InterlockedCompareExchange16_rel curto (pequeno volátil \* , curto, curto)|
|_InterlockedCompareExchange64|__int64 _InterlockedCompareExchange64 ( \_ _int64 volátil \* , \_ _int64, \_ _int64)|
|_InterlockedCompareExchange64_acq|__int64 _InterlockedCompareExchange64_acq ( \_ _int64 volátil \* , \_ _int64, \_ _int64)|
|_InterlockedCompareExchange64_nf|__int64 _InterlockedCompareExchange64_nf ( \_ _int64 volátil \* , \_ _int64, \_ _int64)|
|_InterlockedCompareExchange64_rel|__int64 _InterlockedCompareExchange64_rel ( \_ _int64 volátil \* , \_ _int64, \_ _int64)|
|_InterlockedCompareExchange8|Char _InterlockedCompareExchange8 (Char volátil \* , Char, Char)|
|_InterlockedCompareExchange8_acq|Char _InterlockedCompareExchange8_acq (Char volátil \* , Char, Char)|
|_InterlockedCompareExchange8_nf|Char _InterlockedCompareExchange8_nf (Char volátil \* , Char, Char)|
|_InterlockedCompareExchange8_rel|Char _InterlockedCompareExchange8_rel (Char volátil \* , Char, Char)|
|_InterlockedCompareExchangePointer|void \* _InterlockedCompareExchangePointer (void \* volatile \* , void \* , void \* )|
|_InterlockedCompareExchangePointer_acq|void \* _InterlockedCompareExchangePointer_acq (void \* volatile \* , void \* , void \* )|
|_InterlockedCompareExchangePointer_nf|void \* _InterlockedCompareExchangePointer_nf (void \* volatile \* , void \* , void \* )|
|_InterlockedCompareExchangePointer_rel|void \* _InterlockedCompareExchangePointer_rel (void \* volatile \* , void \* , void \* )|
|_InterlockedCompareExchange128|_InterlockedCompareExchange128 de caracteres não assinados ( \_ _int64 \* _Destination volátil, \_ _int64 _ExchangeHigh, _int64 \_ _ExchangeLow \_ , \* _int64 _ComparandResult)|
|_InterlockedCompareExchange128_acq|_InterlockedCompareExchange128_acq de caracteres não assinados ( \_ _int64 \* _Destination volátil, \_ _int64 _ExchangeHigh, _int64 \_ _ExchangeLow \_ , \* _int64 _ComparandResult)|
|_InterlockedCompareExchange128_nf|_InterlockedCompareExchange128_nf de caracteres não assinados ( \_ _int64 \* _Destination volátil, \_ _int64 _ExchangeHigh, _int64 \_ _ExchangeLow \_ , \* _int64 _ComparandResult)|
|_InterlockedCompareExchange128_rel|_InterlockedCompareExchange128_rel de caracteres não assinados ( \_ _int64 \* _Destination volátil, \_ _int64 _ExchangeHigh, _int64 \_ _ExchangeLow \_ , \* _int64 _ComparandResult)|
|_InterlockedDecrement|longo __cdecl _InterlockedDecrement (Long volátil \* )|
|_InterlockedDecrement16|_InterlockedDecrement16 curto (pequeno volátil \* )|
|_InterlockedDecrement16_acq|_InterlockedDecrement16_acq curto (pequeno volátil \* )|
|_InterlockedDecrement16_nf|_InterlockedDecrement16_nf curto (pequeno volátil \* )|
|_InterlockedDecrement16_rel|_InterlockedDecrement16_rel curto (pequeno volátil \* )|
|_InterlockedDecrement64|__int64 _InterlockedDecrement64 ( \_ _int64 volátil \* )|
|_InterlockedDecrement64_acq|__int64 _InterlockedDecrement64_acq ( \_ _int64 volátil \* )|
|_InterlockedDecrement64_nf|__int64 _InterlockedDecrement64_nf ( \_ _int64 volátil \* )|
|_InterlockedDecrement64_rel|__int64 _InterlockedDecrement64_rel ( \_ _int64 volátil \* )|
|_InterlockedDecrement_acq|_InterlockedDecrement_acq longo (Long volátil \* )|
|_InterlockedDecrement_nf|_InterlockedDecrement_nf longo (Long volátil \* )|
|_InterlockedDecrement_rel|_InterlockedDecrement_rel longo (Long volátil \* )|
|_InterlockedExchange|longo __cdecl _InterlockedExchange (Long volátil \* _Target, Long)|
|_InterlockedExchange_acq|_InterlockedExchange_acq longo (_Target volátil longo \* , longo)|
|_InterlockedExchange_nf|_InterlockedExchange_nf longo (_Target volátil longo \* , longo)|
|_InterlockedExchange_rel|_InterlockedExchange_rel longo (_Target volátil longo \* , longo)|
|_InterlockedExchange16|_InterlockedExchange16 curto (_Target volátil pequeno \* , curto)|
|_InterlockedExchange16_acq|_InterlockedExchange16_acq curto (_Target volátil pequeno \* , curto)|
|_InterlockedExchange16_nf|_InterlockedExchange16_nf curto (_Target volátil pequeno \* , curto)|
|_InterlockedExchange16_rel|_InterlockedExchange16_rel curto (_Target volátil pequeno \* , curto)|
|_InterlockedExchange64|__int64 _InterlockedExchange64 ( \_ _int64 volátil \* _Target, \_ _int64)|
|_InterlockedExchange64_acq|__int64 _InterlockedExchange64_acq ( \_ _int64 volátil \* _Target, \_ _int64)|
|_InterlockedExchange64_nf|__int64 _InterlockedExchange64_nf ( \_ _int64 volátil \* _Target, \_ _int64)|
|_InterlockedExchange64_rel|__int64 _InterlockedExchange64_rel ( \_ _int64 volátil \* _Target, \_ _int64)|
|_InterlockedExchange8|Char _InterlockedExchange8 (Char volátil \* _Target, Char)|
|_InterlockedExchange8_acq|Char _InterlockedExchange8_acq (Char volátil \* _Target, Char)|
|_InterlockedExchange8_nf|Char _InterlockedExchange8_nf (Char volátil \* _Target, Char)|
|_InterlockedExchange8_rel|Char _InterlockedExchange8_rel (Char volátil \* _Target, Char)|
|_InterlockedExchangeAdd|longo __cdecl _InterlockedExchangeAdd (Long volátil \* , Long)|
|_InterlockedExchangeAdd16|_InterlockedExchangeAdd16 curto (pequeno volátil \* , curto)|
|_InterlockedExchangeAdd16_acq|_InterlockedExchangeAdd16_acq curto (pequeno volátil \* , curto)|
|_InterlockedExchangeAdd16_nf|_InterlockedExchangeAdd16_nf curto (pequeno volátil \* , curto)|
|_InterlockedExchangeAdd16_rel|_InterlockedExchangeAdd16_rel curto (pequeno volátil \* , curto)|
|_InterlockedExchangeAdd64|__int64 _InterlockedExchangeAdd64 ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedExchangeAdd64_acq|__int64 _InterlockedExchangeAdd64_acq ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedExchangeAdd64_nf|__int64 _InterlockedExchangeAdd64_nf ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedExchangeAdd64_rel|__int64 _InterlockedExchangeAdd64_rel ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedExchangeAdd8|Char _InterlockedExchangeAdd8 (Char volátil \* , Char)|
|_InterlockedExchangeAdd8_acq|Char _InterlockedExchangeAdd8_acq (Char volátil \* , Char)|
|_InterlockedExchangeAdd8_nf|Char _InterlockedExchangeAdd8_nf (Char volátil \* , Char)|
|_InterlockedExchangeAdd8_rel|Char _InterlockedExchangeAdd8_rel (Char volátil \* , Char)|
|_InterlockedExchangeAdd_acq|_InterlockedExchangeAdd_acq longo (Long volátil \* , longo)|
|_InterlockedExchangeAdd_nf|_InterlockedExchangeAdd_nf longo (Long volátil \* , longo)|
|_InterlockedExchangeAdd_rel|_InterlockedExchangeAdd_rel longo (Long volátil \* , longo)|
|_InterlockedExchangePointer|void \* _InterlockedExchangePointer (void \* volatile \* _Target, void \* )|
|_InterlockedExchangePointer_acq|void \* _InterlockedExchangePointer_acq (void \* volatile \* _Target, void \* )|
|_InterlockedExchangePointer_nf|void \* _InterlockedExchangePointer_nf (void \* volatile \* _Target, void \* )|
|_InterlockedExchangePointer_rel|void \* _InterlockedExchangePointer_rel (void \* volatile \* _Target, void \* )|
|_InterlockedIncrement|longo __cdecl _InterlockedIncrement (Long volátil \* )|
|_InterlockedIncrement16|_InterlockedIncrement16 curto (pequeno volátil \* )|
|_InterlockedIncrement16_acq|_InterlockedIncrement16_acq curto (pequeno volátil \* )|
|_InterlockedIncrement16_nf|_InterlockedIncrement16_nf curto (pequeno volátil \* )|
|_InterlockedIncrement16_rel|_InterlockedIncrement16_rel curto (pequeno volátil \* )|
|_InterlockedIncrement64|__int64 _InterlockedIncrement64 ( \_ _int64 volátil \* )|
|_InterlockedIncrement64_acq|__int64 _InterlockedIncrement64_acq ( \_ _int64 volátil \* )|
|_InterlockedIncrement64_nf|__int64 _InterlockedIncrement64_nf ( \_ _int64 volátil \* )|
|_InterlockedIncrement64_rel|__int64 _InterlockedIncrement64_rel ( \_ _int64 volátil \* )|
|_InterlockedIncrement_acq|_InterlockedIncrement_acq longo (Long volátil \* )|
|_InterlockedIncrement_nf|_InterlockedIncrement_nf longo (Long volátil \* )|
|_InterlockedIncrement_rel|_InterlockedIncrement_rel longo (Long volátil \* )|
|_InterlockedOr|_InterlockedOr longo (Long volátil \* , longo)|
|_InterlockedOr16|_InterlockedOr16 curto (pequeno volátil \* , curto)|
|_InterlockedOr16_acq|_InterlockedOr16_acq curto (pequeno volátil \* , curto)|
|_InterlockedOr16_nf|_InterlockedOr16_nf curto (pequeno volátil \* , curto)|
|_InterlockedOr16_rel|_InterlockedOr16_rel curto (pequeno volátil \* , curto)|
|_InterlockedOr64|__int64 _InterlockedOr64 ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedOr64_acq|__int64 _InterlockedOr64_acq ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedOr64_nf|__int64 _InterlockedOr64_nf ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedOr64_rel|__int64 _InterlockedOr64_rel ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedOr8|Char _InterlockedOr8 (Char volátil \* , Char)|
|_InterlockedOr8_acq|Char _InterlockedOr8_acq (Char volátil \* , Char)|
|_InterlockedOr8_nf|Char _InterlockedOr8_nf (Char volátil \* , Char)|
|_InterlockedOr8_rel|Char _InterlockedOr8_rel (Char volátil \* , Char)|
|_InterlockedOr_acq|_InterlockedOr_acq longo (Long volátil \* , longo)|
|_InterlockedOr_nf|_InterlockedOr_nf longo (Long volátil \* , longo)|
|_InterlockedOr_rel|_InterlockedOr_rel longo (Long volátil \* , longo)|
|_InterlockedXor|_InterlockedXor longo (Long volátil \* , longo)|
|_InterlockedXor16|_InterlockedXor16 curto (pequeno volátil \* , curto)|
|_InterlockedXor16_acq|_InterlockedXor16_acq curto (pequeno volátil \* , curto)|
|_InterlockedXor16_nf|_InterlockedXor16_nf curto (pequeno volátil \* , curto)|
|_InterlockedXor16_rel|_InterlockedXor16_rel curto (pequeno volátil \* , curto)|
|_InterlockedXor64|__int64 _InterlockedXor64 ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedXor64_acq|__int64 _InterlockedXor64_acq ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedXor64_nf|__int64 _InterlockedXor64_nf ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedXor64_rel|__int64 _InterlockedXor64_rel ( \_ _int64 volátil \* \_ _int64)|
|_InterlockedXor8|Char _InterlockedXor8 (Char volátil \* , Char)|
|_InterlockedXor8_acq|Char _InterlockedXor8_acq (Char volátil \* , Char)|
|_InterlockedXor8_nf|Char _InterlockedXor8_nf (Char volátil \* , Char)|
|_InterlockedXor8_rel|Char _InterlockedXor8_rel (Char volátil \* , Char)|
|_InterlockedXor_acq|_InterlockedXor_acq longo (Long volátil \* , longo)|
|_InterlockedXor_nf|_InterlockedXor_nf longo (Long volátil \* , longo)|
|_InterlockedXor_rel|_InterlockedXor_rel longo (Long volátil \* , longo)|

[[Retornar ao início](#top)]

### <a name="_interlockedbittest-intrinsics"></a>_interlockedbittest intrínsecos

Os intrínsecores de teste de bits intercadeados simples são comuns a todas as plataformas. ARM64 adiciona `_acq` , `_rel` e `_nf` variantes, que apenas modificam a semântica de barreira de uma operação, conforme descrito no [sufixo _nf (sem limite)](#nf_suffix) anteriormente neste artigo.

|Nome da função|Protótipo da função|
|-------------------|------------------------|
|_interlockedbittestandreset|_interlockedbittestandreset de caracteres não assinados (Long volátil \* , Long)|
|_interlockedbittestandreset_acq|_interlockedbittestandreset_acq de caracteres não assinados (Long volátil \* , Long)|
|_interlockedbittestandreset_nf|_interlockedbittestandreset_nf de caracteres não assinados (Long volátil \* , Long)|
|_interlockedbittestandreset_rel|_interlockedbittestandreset_rel de caracteres não assinados (Long volátil \* , Long)|
|_interlockedbittestandreset64|_interlockedbittestandreset64 de caracteres não assinados (__int64 volátil \* , __int64)|
|_interlockedbittestandreset64_acq|_interlockedbittestandreset64_acq de caracteres não assinados (__int64 volátil \* , __int64)|
|_interlockedbittestandreset64_nf|_interlockedbittestandreset64_nf de caracteres não assinados (__int64 volátil \* , __int64)|
|_interlockedbittestandreset64_rel|_interlockedbittestandreset64_rel de caracteres não assinados (__int64 volátil \* , __int64)|
|_interlockedbittestandset|_interlockedbittestandset de caracteres não assinados (Long volátil \* , Long)|
|_interlockedbittestandset_acq|_interlockedbittestandset_acq de caracteres não assinados (Long volátil \* , Long)|
|_interlockedbittestandset_nf|_interlockedbittestandset_nf de caracteres não assinados (Long volátil \* , Long)|
|_interlockedbittestandset_rel|_interlockedbittestandset_rel de caracteres não assinados (Long volátil \* , Long)|
|_interlockedbittestandset64|_interlockedbittestandset64 de caracteres não assinados (__int64 volátil \* , __int64)|
|_interlockedbittestandset64_acq|_interlockedbittestandset64_acq de caracteres não assinados (__int64 volátil \* , __int64)|
|_interlockedbittestandset64_nf|_interlockedbittestandset64_nf de caracteres não assinados (__int64 volátil \* , __int64)|
|_interlockedbittestandset64_rel|_interlockedbittestandset64_rel de caracteres não assinados (__int64 volátil \* , __int64)|

[[Retornar ao início](#top)]

## <a name="see-also"></a>Confira também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[Intrínsecos do ARM](arm-intrinsics.md)\
[Referência do ARM Assembler](../assembler/arm/arm-assembler-reference.md)\
[Referência da linguagem C++](../cpp/cpp-language-reference.md)
