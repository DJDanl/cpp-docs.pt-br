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
ms.openlocfilehash: 3e5433e2d1ddf94f23a3f483a8857e3032c27be3
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42538776"
---
# <a name="interlockedcompareexchange128"></a>_InterlockedCompareExchange128
**Seção específica da Microsoft**  
  
 Executa um 128 bits comparação e troca sincronizada.  
  
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
 Ponteiro para o destino, que é uma matriz de dois inteiros de 64 bits é considerado como um campo de 128 bits. Os dados de destino devem ser de 16 bytes alinhado para evitar uma falha geral de proteção.  
  
 [in] `ExchangeHigh`  
 Um inteiro de 64 bits que pode ser trocado com a parte alta de destino.  
  
 [in] `ExchangeLow`  
 Um inteiro de 64 bits que pode ser trocado com a parte inferior do destino.  
  
 [in, out] `ComparandResult`  
 Ponteiro para uma matriz de dois inteiros de 64 bits (considerado como um campo de 128 bits) a ser comparado com o destino.  Na saída, isso será substituído com o valor original de destino.  
  
## <a name="return-value"></a>Valor de retorno  
 1 se o termo de comparação de 128 bits é igual ao valor original do destino. `ExchangeHigh` e `ExchangeLow` substituir o destino de 128 bits.  
  
 0 se o termo de comparação não é igual ao valor original de destino. O valor de destino é alterado e o valor do termo de comparação é substituído com o valor de destino.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`_InterlockedCompareExchange128`|X64|  
  
 **Arquivo de cabeçalho** \<intrin. h >  
  
## <a name="remarks"></a>Comentários  
 Esse intrínseco gera o `cmpxchg16b` instrução (com o `lock` prefixo) para executar a comparação bloqueada de 128 bits e o exchange. As versões anteriores do hardware AMD de 64 bits não dão suporte a essa instrução. Para verificar se há suporte de hardware para o `cmpxchg16b` instrução, a chamada a `__cpuid` intrínseco com `InfoType=0x00000001 (standard function 1)`. 13 bits de `CPUInfo[2]` (ECX) é 1, se houver suporte para a instrução.  
  
> [!NOTE]
>  O valor de `ComparandResult` sempre será substituído. Após o `lock` instrução, intrínseca imediatamente copia o valor inicial de `Destination` para `ComparandResult`. Por esse motivo, `ComparandResult` e `Destination` deve apontar para os locais de memória separados para evitar comportamento inesperado.  
  
 Embora você possa usar `_InterlockedCompareExchange128` para a sincronização de thread de baixo nível, você precisa sincronizar mais de 128 bits, se você pode usar funções de sincronização menores (como o outro `_InterlockedCompareExchange` intrínsecos) em vez disso. Use `_InterlockedCompareExchange128` se quiser acesso atômico como um valor de 128 bits na memória.  
  
 Se você executar o código que usa esse intrínseco no hardware que não oferece suporte a `cmpxchg16b` instrução, os resultados serão imprevisíveis.  
  
 Essa rotina só está disponível como um intrínseco.  
  
## <a name="example"></a>Exemplo  
 Este exemplo usa `_InterlockedCompareExchange128` para substituir a palavra alta de uma matriz de dois inteiros de 64 bits com a soma de suas palavras altas e baixos e incrementar a palavra baixa. O acesso à matriz de BigInt.Int é atômico, mas este exemplo usa um único thread e ignora o bloqueio para manter a simplicidade.  
  
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
 Copyright 2007 por dispositivos Micro avançada, Inc. Todos os direitos reservados. Reproduzido com a permissão do Advanced Micro dispositivos, Inc.  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Funções intrínsecas interlockedcompareexchange](../intrinsics/interlockedcompareexchange-intrinsic-functions.md)   
 [conflitos com o compilador x86](../build/conflicts-with-the-x86-compiler.md)