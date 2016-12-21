---
title: "_bittestandset, _bittestandset64 | Microsoft Docs"
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
  - "_bittestandset_cpp"
  - "_bittestandset64_cpp"
  - "_bittestandset64"
  - "_bittestandset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_bittestandset intrínseca"
  - "_bittestandset64 intrínseca"
  - "instrução BTS"
ms.assetid: 6d6c8670-fea0-4c1c-9aad-2bb842715203
caps.latest.revision: 16
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _bittestandset, _bittestandset64
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Gere uma instrução que examina o bit `b` do endereço `a` e retorna seu valor atual e define o bit como 1.  
  
## Sintaxe  
  
```  
unsigned char _bittestandset(    long *a,    long b ); unsigned char _bittestandset64(    __int64 *a,    __int64 b );  
```  
  
#### Parâmetros  
 \[in, out\] `a`  
 Um ponteiro para a memória a examinar.  
  
 \[in\] `b`  
 A posição de bit a testar.  
  
## Valor de retorno  
 O bit na posição especificada.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`_bittestandset`|x86, ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`_bittestandset64`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Essa rotina só está disponível como função intrínseca.  
  
## Exemplo  
  
```  
// bittestandset.cpp  
// processor: x86, ARM, x64  
// This example uses several of the _bittest family of intrinsics  
// to implement a Flags class that allows bit level access to an  
// integer field.  
#include <stdio.h>  
#include <intrin.h>  
  
#pragma intrinsic(_bittestandset, _bittestandreset,\  
                  _bittestandcomplement, _bittest)  
  
class Flags  
{  
private:  
    long flags;  
    long* oldValues;  
  
public:  
    Flags() : flags(0)  
    {  
        oldValues = new long[32];  
    }  
  
    ~Flags()  
    {  
        delete oldValues;  
    }  
  
    void SetFlagBit(long nBit)  
    {  
        // We omit range checks on the argument  
        oldValues[nBit] = _bittestandset(&flags, nBit);  
        printf_s("Flags: 0x%x\n", flags);  
    }  
    void ClearFlagBit(long nBit)  
    {  
        oldValues[nBit] = _bittestandreset(&flags, nBit);  
        printf_s("Flags: 0x%x\n", flags);  
    }  
    unsigned char GetFlagBit(long nBit)  
    {  
        unsigned char result = _bittest(&flags, nBit);  
        printf_s("Flags: 0x%x\n", flags);  
        return result;  
    }  
    void RestoreFlagBit(long nBit)  
    {  
        if (oldValues[nBit])  
            oldValues[nBit] = _bittestandset(&flags, nBit);  
        else  
            oldValues[nBit] = _bittestandreset(&flags, nBit);  
        printf_s("Flags: 0x%x\n", flags);       
    }  
    unsigned char ToggleBit(long nBit)  
    {  
        unsigned char result = _bittestandcomplement(&flags, nBit);  
        printf_s("Flags: 0x%x\n", flags);  
        return result;  
    }  
};  
  
int main()  
{  
    Flags f;  
    f.SetFlagBit(1);  
    f.SetFlagBit(2);  
    f.SetFlagBit(3);  
    f.ClearFlagBit(3);  
    f.ToggleBit(1);  
    f.RestoreFlagBit(2);  
}  
```  
  
  **Sinalizadores: 0x2**  
**Sinalizadores: 0x6**  
**Sinalizadores: 0xe**  
**Sinalizadores: 0x6**  
**Sinalizadores: 0x4**  
**Sinalizadores: 0x0**   
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)