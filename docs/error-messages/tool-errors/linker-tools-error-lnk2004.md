---
title: Erro das Ferramentas de Vinculador LNK2004
ms.date: 11/04/2016
f1_keywords:
- LNK2004
helpviewer_keywords:
- LNK2004
ms.assetid: 07645371-e67b-4a2c-b0e0-dde24c94ef7e
ms.openlocfilehash: 8088494106aa702fda0497fa431e48267167a185
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160413"
---
# <a name="linker-tools-error-lnk2004"></a>Erro das Ferramentas de Vinculador LNK2004

estouro de conserto relativo GP para 'target'; breve seção 'seção' é muito grande ou fora do intervalo.

A seção era muito grande.

Para resolver esse erro, reduzir o tamanho da seção curta, seja explicitamente colocar dados nas seções longo por meio da seção #pragma (".sectionname", leitura, gravação, longo) e usando `__declspec(allocate(".sectionname"))` em declarações e definições de dados.  Por exemplo,

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

Você também pode mover os dados agrupados logicamente em sua própria estrutura que será uma coleção de dados maiores que 8 bytes, que o compilador alocará uma seção de dados longos.  Por exemplo,

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