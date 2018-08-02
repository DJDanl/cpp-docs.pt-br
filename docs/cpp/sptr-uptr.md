---
title: sptr, uptr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __uptr_cpp
- __sptr_cpp
dev_langs:
- C++
helpviewer_keywords:
- __sptr modifier
- __uptr modifier
ms.assetid: c7f5f3b2-9106-4a0b-a6de-d1588ab153ed
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7e059b8144518f3d0cacdde5d7f438c04b7933a2
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39467864"
---
# <a name="sptr-uptr"></a>__sptr, __uptr
**Seção específica da Microsoft**  
 Use o **sptr** ou **uptr** modificador em uma declaração de ponteiro de 32 bits para especificar como o compilador converte um ponteiro de 32 bits em um ponteiro de 64 bits. Um ponteiro de 32 bits é convertido, por exemplo, quando ele é atribuído a uma variável de ponteiro de 64 bits ou sua referência é cancelada em uma plataforma de 64 bits.  
  
 A documentação da Microsoft para o suporte de plataformas de 64 bits às vezes chama o bit mais significativo de um ponteiro de 32 bits de bit de sinal. Por padrão, o compilador usa a extensão de sinal para converter um ponteiro de 32 bits em um ponteiro de 64 bits. Ou seja, os 32 bits menos significativos do ponteiro de 64 bits são definidos como o valor do ponteiro de 32 bits e os 32 bits mais significativos são definidos como o valor do bit de sinal do ponteiro de 32 bits. Essa conversão gera resultados corretos se o bit de sinal for 0, mas não se o bit de sinal for 1. Por exemplo, o endereço de 32 bits 0x7FFFFFFF produz o endereço de 64 bits 0x000000007FFFFFFF equivalente, mas o endereço de 32 bits 0x80000000 é alterado incorretamente para 0xFFFFFFFF80000000.  
  
 O **sptr**, ou ponteiro assinado, modificador Especifica que uma conversão de ponteiro define os bits mais significativos de um ponteiro de 64 bits para o bit de sinal do ponteiro de 32 bits. O **uptr**, ou ponteiro sem sinal, o modificador Especifica que uma conversão define os bits mais significativos como zero. O declarações a seguir mostram os **sptr** e **uptr** modificadores usados com dois ponteiros não qualificados, dois ponteiros qualificados com o [__ptr32](../cpp/ptr32-ptr64.md) tipo e uma função parâmetro.  
  
```cpp 
int * __sptr psp;  
int * __uptr pup;  
int * __ptr32 __sptr psp32;  
int * __ptr32 __uptr pup32;  
void MyFunction(char * __uptr __ptr32 myValue);  
```  
  
 Use o **sptr** e **uptr** modificadores com declarações de ponteiro. Use os modificadores na posição de um [qualificador de tipo de ponteiro](../c-language/pointer-declarations.md), que significa que o modificador deve vir após o asterisco. Você não pode usar os modificadores com [ponteiros para membros](../cpp/pointers-to-members.md). Os modificadores não afetam as declarações que não são de ponteiro.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir declara ponteiros de 32 bits que usam o **sptr** e **uptr** modificadores, atribui cada ponteiro de 32 bits a uma variável de ponteiro de 64 bits e, em seguida, exibe o valor hexadecimal de cada 64 - ponteiro de bit. O exemplo é criado com o compilador nativo de 64 bits e executado em uma plataforma de 64 bits.  
  
```cpp  
// sptr_uptr.cpp  
// processor: x64  
#include "stdio.h"  
  
int main()  
{  
    void *        __ptr64 p64;  
    void *        __ptr32 p32d; //default signed pointer  
    void * __sptr __ptr32 p32s; //explicit signed pointer  
    void * __uptr __ptr32 p32u; //explicit unsigned pointer  
  
// Set the 32-bit pointers to a value whose sign bit is 1.  
    p32d = reinterpret_cast<void *>(0x87654321);  
    p32s = p32d;  
    p32u = p32d;  
  
// The printf() function automatically displays leading zeroes with each 32-bit pointer. These are unrelated   
// to the __sptr and __uptr modifiers.   
    printf("Display each 32-bit pointer (as an unsigned 64-bit pointer):\n");  
    printf("p32d:       %p\n", p32d);   
    printf("p32s:       %p\n", p32s);  
    printf("p32u:       %p\n", p32u);  
  
    printf("\nDisplay the 64-bit pointer created from each 32-bit pointer:\n");  
    p64 = p32d;   
    printf("p32d: p64 = %p\n", p64);  
    p64 = p32s;  
    printf("p32s: p64 = %p\n", p64);  
    p64 = p32u;  
    printf("p32u: p64 = %p\n", p64);  
    return 0;  
}  
```  
  
```Output  
Display each 32-bit pointer (as an unsigned 64-bit pointer):  
p32d:       0000000087654321  
p32s:       0000000087654321  
p32u:       0000000087654321  
  
Display the 64-bit pointer created from each 32-bit pointer:  
p32d: p64 = FFFFFFFF87654321  
p32s: p64 = FFFFFFFF87654321  
p32u: p64 = 0000000087654321  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md)