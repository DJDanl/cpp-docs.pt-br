---
title: Armazenamento de campos de bits
ms.date: 11/04/2016
ms.assetid: 4816a241-1580-4d1c-82ed-13d359733959
ms.openlocfilehash: 7aa6e02c347ff14bb0552320567b343c7215ebc7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50499080"
---
# <a name="storage-of-bit-fields"></a>Armazenamento de campos de bits

**ANSI 3.5.2.1** A ordem de alocação de campos de bits dentro de um int

Os campos de bit são alocados em um inteiro do bit menos significativo ao bit mais significativo. No código a seguir

```
struct mybitfields
{
   unsigned a : 4;
   unsigned b : 5;
   unsigned c : 7;
} test;

int main( void )
{
   test.a = 2;
   test.b = 31;
   test.c = 0;
}
```

os bits seriam organizados como segue:

```
00000001 11110010
cccccccb bbbbaaaa
```

Como os processadores 80x86 armazenam o byte inferior de valores inteiros antes do byte superior, o inteiro 0x01F2 acima seria armazenado na memória física como 0xF2 seguido por 0x01.

## <a name="see-also"></a>Consulte também

[Estruturas, uniões, enumerações e campos de bit](../c-language/structures-unions-enumerations-and-bit-fields.md)