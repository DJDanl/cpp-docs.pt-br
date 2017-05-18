---
title: Ferramentas de vinculador LNK2004 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2004
dev_langs:
- C++
helpviewer_keywords:
- LNK2004
ms.assetid: 07645371-e67b-4a2c-b0e0-dde24c94ef7e
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f66c3eda90f3d0f9149d70418cb40f08b3b94df7
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2004"></a>Erro das Ferramentas de Vinculador LNK2004
estouro de ajuste relativo de GP ' destino '; breve seção 'seção' é muito grande ou fora do intervalo.  
  
 A seção era muito grande.  
  
 Para resolver esse erro, reduza o tamanho da seção curto, seja explicitamente colocar dados na seção longa via seção #pragma (".sectionname", leitura, gravação, longo) e usando `__declspec(allocate(".sectionname"))` em declarações e definições de dados.  Por exemplo,  
  
```  
#pragma section(".data$mylong", read, write, long)  
__declspec(allocate(".data$mylong"))  
char    rg0[1] = { 1 };  
char    rg1[2] = { 1 };  
char    rg2[4] = { 1 };  
char    rg3[8] = { 1 };  
char    rg4[16] = { 1 };  
char    rg5[32] = { 1 };  
```  
  
 Você também pode mover dados agrupados logicamente em sua própria estrutura que será um conjunto de dados maiores que 8 bytes, que o compilador alocará em uma seção de dados longos.  Por exemplo,  
  
```  
// from this...  
int     w1  = 23;  
int     w2 = 46;  
int     w3 = 23*3;  
int     w4 = 23*4;  
  
// to this...  
struct X {  
    int     w1;  
    int     w2;  
    int     w3;  
    int     w4;  
} x  = { 23, 23*2, 23*3, 23*4 };  
  
```  
  
 Esse erro é seguido por um erro fatal `LNK1165`.
