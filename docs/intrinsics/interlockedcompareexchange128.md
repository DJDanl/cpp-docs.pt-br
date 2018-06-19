---
title: _InterlockedCompareExchange128 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _InterlockedCompareExchange128_cpp
- _InterlockedCompareExchange128
dev_langs:
- C++
helpviewer_keywords:
- cmpxchg16b instruction
- _InterlockedCompareExchange128 intrinsic
ms.assetid: f05918fc-716a-4f6d-b746-1456d6b96c56
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f491f59289a2e3b951e1bad60f260a801ea68bea
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33337929"
---
# <a name="interlockedcompareexchange128"></a>_InterlockedCompareExchange128
**Seção específica da Microsoft**  
  
 Executa uma comparação interligada de 128 bits e o exchange.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned char _InterlockedCompareExchange128(  
   __int64 volatile * Destination,  
   __int64 ExchangeHigh,  
   __int64 ExchangeLow,  
   __int64 * ComparandResult  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in, out] `Destination`  
 Ponteiro para o destino, o que é uma matriz de números inteiros de 64 bits é considerado como um campo de 128 bits. Os dados de destino devem ser de 16 bytes alinhados para evitar uma falha de proteção.  
  
 [in] `ExchangeHigh`  
 Um inteiro de 64 bits que pode ser trocado com a parte superior do destino.  
  
 [in] `ExchangeLow`  
 Um inteiro de 64 bits que pode ser trocado com a parte inferior do destino.  
  
 [in, out] `ComparandResult`  
 Ponteiro para uma matriz de números inteiros de 64 bits (considerado como um campo de 128 bits) para comparar com o destino.  Na saída, será substituído pelo valor original do destino.  
  
## <a name="return-value"></a>Valor de retorno  
 1 se o termo de comparação de 128 bits é igual ao valor original do destino. `ExchangeHigh` e `ExchangeLow` substituir o destino de 128 bits.  
  
 0 se o termo de comparação não é igual ao valor original do destino. O valor de destino é alterado e o valor do termo de comparação é substituído com o valor de destino.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`_InterlockedCompareExchange128`|[!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 Nesse intrínsecas gera o `cmpxchg16b` instrução (com o `lock` prefixo) para executar uma comparação bloqueada de 128 bits e o exchange. Versões anteriores do hardware AMD 64 bits não dão suporte a essa instrução. Para verificar se há suporte de hardware para o `cmpxchg16b` instrução, chamada de `__cpuid` intrínseco com `InfoType=0x00000001 (standard function 1)`. 13 de bits de `CPUInfo[2]` (ECX) é 1, se houver suporte para a instrução.  
  
> [!NOTE]
>  O valor de `ComparandResult` sempre será substituído. Após o `lock` instrução, nesse intrínseca imediatamente copia o valor inicial da `Destination` para `ComparandResult`. Por esse motivo, `ComparandResult` e `Destination` devem apontar para os locais de memória separada para evitar um comportamento inesperado.  
  
 Embora você possa usar `_InterlockedCompareExchange128` para sincronização de thread de baixo nível, você não precisa sincronizar mais de 128 bits, se você pode usar funções de sincronização menores (como outro `_InterlockedCompareExchange` intrínsecos) em vez disso. Use `_InterlockedCompareExchange128` se quiser acesso atômico como um valor de 128 bits na memória.  
  
 Se você executar o código que usa nesse intrínseco no hardware que não oferece suporte a `cmpxchg16b` instrução, os resultados são imprevisíveis.  
  
 Esta rotina está disponível apenas como um intrínseco.  
  
## <a name="example"></a>Exemplo  
 Este exemplo usa `_InterlockedCompareExchange128` para substituir a palavra alta de uma matriz de números inteiros de 64 bits com a soma de seus palavras altas e baixas e incrementar a palavra baixa. O acesso à matriz de BigInt.Int é atômico, mas este exemplo usa um único thread e ignora o bloqueio de simplicidade.  
  
```  
// cmpxchg16b.c  
// processor: x64  
// compile with: /EHsc /O2  
#include <stdio.h>  
#include <intrin.h>  
  
typedef struct _LARGE_INTEGER_128 {  
    __int64 Int[2];  
} LARGE_INTEGER_128, *PLARGE_INTEGER_128;  
  
volatile LARGE_INTEGER_128 BigInt;  
  
// This AtomicOp() function atomically performs:  
//   BigInt.Int[1] += BigInt.Int[0]  
//   BigInt.Int[0] += 1  
void AtomicOp ()  
{  
    LARGE_INTEGER_128 Comparand;  
    Comparand.Int[0] = BigInt.Int[0];  
    Comparand.Int[1] = BigInt.Int[1];  
    do {  
        ; // nothing  
    } while (_InterlockedCompareExchange128(BigInt.Int,  
                                            Comparand.Int[0] + Comparand.Int[1],  
                                            Comparand.Int[0] + 1,  
                                            Comparand.Int) == 0);  
}  
  
// In a real application, several threads contend for the value  
// of BigInt.  
// Here we focus on the compare and exchange for simplicity.  
int main(void)  
{  
   BigInt.Int[1] = 23;  
   BigInt.Int[0] = 11;  
   AtomicOp();  
   printf("BigInt.Int[1] = %d, BigInt.Int[0] = %d\n",  
      BigInt.Int[1],BigInt.Int[0]);  
}  
```  
  
```Output  
BigInt.Int[1] = 34, BigInt.Int[0] = 12  
```  
  
**Fim da seção específica da Microsoft**  
 Copyright 2007 Advanced Micro dispositivos, Inc. Todos os direitos reservados. Reproduzido com a permissão do Advanced Micro Devices, Inc.  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Funções intrínsecas _InterlockedCompareExchange](../intrinsics/interlockedcompareexchange-intrinsic-functions.md)   
 [conflitos com o compilador x86](../build/conflicts-with-the-x86-compiler.md)