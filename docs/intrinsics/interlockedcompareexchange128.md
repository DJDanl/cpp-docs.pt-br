---
title: "_InterlockedCompareExchange128 | Microsoft Docs"
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
  - "_InterlockedCompareExchange128_cpp"
  - "_InterlockedCompareExchange128"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instrução cmpxchg16b"
  - "_InterlockedCompareExchange128 intrínseco"
ms.assetid: f05918fc-716a-4f6d-b746-1456d6b96c56
caps.latest.revision: 17
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _InterlockedCompareExchange128
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Executa uma comparação interligada de 128 bits e o exchange.  
  
## Sintaxe  
  
```  
unsigned char _InterlockedCompareExchange128(  
   __int64 volatile * Destination,  
   __int64 ExchangeHigh,  
   __int64 ExchangeLow,  
   __int64 * ComparandResult  
);  
```  
  
#### Parâmetros  
 \[in, out\]`Destination`  
 Ponteiro para o destino, é uma matriz de dois inteiros de 64 bits é considerado como um campo de 128 bits.  Os dados de destino devem ser 16 bytes alinhados para evitar uma falha de proteção geral.  
  
 \[in\]`ExchangeHigh`  
 Um inteiro de 64 bits que pode ser trocado com a parte superior do destino.  
  
 \[in\]`ExchangeLow`  
 Um inteiro de 64 bits que pode ser trocado com a parte inferior do destino.  
  
 \[in, out\]`ComparandResult`  
 Ponteiro para uma matriz de dois inteiros de 64 bits \(considerado como um campo de 128 bits\) para comparar com o destino.  Na saída, isso é substituído com o valor original do destino.  
  
## Valor de retorno  
 1 se comparand 128 bits é igual ao valor original do destino.  `ExchangeHigh`e `ExchangeLow` sobrescrever o destino de 128 bits.  
  
 0 se o comparand não é igual o valor original do destino.  O valor de destino é alterado e o valor de comparand é substituído com o valor de destino.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`_InterlockedCompareExchange128`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Nesse intrínsecas gera o `cmpxchg16b` instrução \(com o `lock` prefixo\) para realizar uma comparação bloqueada de 128 bits e o exchange.  As primeiras versões do hardware AMD de 64 bits não suportam essa instrução.  Para verificar o suporte de hardware para o `cmpxchg16b` instrução, chamada de `__cpuid` intrínseca com `InfoType=0x00000001 (standard function 1)`.  13 Bits de `CPUInfo[2]` \(ECX\) será 1 se a instrução é suportada.  
  
> [!NOTE]
>  O valor de `ComparandResult` sempre será substituído.  Após o `lock` instrução, neste intrínseca imediatamente copia o valor inicial de `Destination` para `ComparandResult`.  Por esse motivo, `ComparandResult` e `Destination` deve apontar para locais de memória separado para evitar comportamentos inesperados.  
  
 Embora você possa usar `_InterlockedCompareExchange128` para sincronização de thread de baixo nível, você não precisará sincronizar mais de 128 bits, se você pode usar funções de sincronização menores \(como os outros `_InterlockedCompareExchange` intrínsecos\) em vez disso.  Use `_InterlockedCompareExchange128` se você quiser acesso atômico para um valor de 128 bits na memória.  
  
 Se você executa código que usa intrínseca neste hardware não oferece suporte a `cmpxchg16b` as instruções, os resultados são imprevisíveis.  
  
 Esta rotina está disponível como um intrínseco.  
  
## Exemplo  
 Este exemplo usa `_InterlockedCompareExchange128` para substituir a palavra alta de uma matriz de dois inteiros de 64 bits com a soma de suas palavras altas e baixas e incrementar a palavra baixa.  O acesso à matriz BigInt.Int é atômico, mas este exemplo usa um único thread e ignora o bloqueio de simplicidade.  
  
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
  
  **BigInt.Int\[1\] \= 34, BigInt.Int\[0\] \= 12**   
## END Microsoft específicos  
 Copyright 2007 pela Advanced Micro dispositivos, Inc. todos os direitos reservados.  Reproduzido com permissão do Advanced Micro dispositivos, Inc.  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [\_InterlockedCompareExchange funções intrínsecas](../intrinsics/interlockedcompareexchange-intrinsic-functions.md)   
 [Conflitos com o compilador x86](../Topic/Conflicts%20with%20the%20x86%20Compiler.md)