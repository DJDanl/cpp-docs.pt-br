---
title: Erro das Ferramentas de Vinculador LNK2004
ms.date: 11/04/2016
f1_keywords:
- LNK2004
helpviewer_keywords:
- LNK2004
ms.assetid: 07645371-e67b-4a2c-b0e0-dde24c94ef7e
ms.openlocfilehash: 0d26ab12c5b82d52b7dcbb176d9bfa033d7ddfee
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194831"
---
# <a name="linker-tools-error-lnk2004"></a>Erro das Ferramentas de Vinculador LNK2004

o estouro relativo de GP foi transcorretivo para ' destino '; a seção curta ' section ' é muito grande ou está fora do intervalo.

A seção era muito grande.

Para resolver esse erro, reduza o tamanho da seção curta, colocando explicitamente os dados nas seções longas por meio de #pragma seção (". sectionname", leitura, gravação, longo) e usando `__declspec(allocate(".sectionname"))` em definições de dados e declarações.  Por exemplo,

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

Você também pode mover dados logicamente agrupados para sua própria estrutura que será uma coleção de dados com mais de 8 bytes, que o compilador irá alocar em uma seção de dados longos.  Por exemplo,

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
