---
title: Armazenamento de campos de bits | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 4816a241-1580-4d1c-82ed-13d359733959
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: b984448e55380dd3f2223b098a048fec57cb0ba6
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

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
