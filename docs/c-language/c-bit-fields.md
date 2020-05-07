---
title: Campos de bit C
ms.date: 11/04/2016
helpviewer_keywords:
- bitfields
- bit fields
ms.assetid: 9faf74c4-7fd5-4b44-ad18-04485193d06e
ms.openlocfilehash: 62c982fa078182cb1902b6770f0a3713ca4ff7a8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62326489"
---
# <a name="c-bit-fields"></a>Campos de bit C

Além dos declaradores para membros de uma estrutura ou união, um declarador de estrutura também pode ser um número especificado de bits, chamado de “campo de bits”. O comprimento é definido fora do declarador do nome de campo por dois pontos. Um campo de bits é interpretado como um tipo integral.

## <a name="syntax"></a>Sintaxe

*estrutura-declaradora*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*tipo de* *Declarador*de especificador<sub>opt</sub> **:** *expressão Constant*

A *constant-expression* especifica a largura do campo em bits. O *type-specifier* do `declarator` deve ser `unsigned int`, **signed int** ou `int`, e a *constant-expression* deve ser um valor inteiro não negativo. Se o valor for zero, a declaração não tem nenhum `declarator`. As matrizes de campos de bits, os ponteiros para campos de bits, e as funções que retornam campos de bits não são permitidas. O `declarator` opcional nomeia o campo de bits. Os campos de bits só podem ser declarados como parte de uma estrutura. O operador address-of (**&**) não pode ser aplicado a componentes de campo de bits.

Não é possível fazer referência a campos de bits sem nome e seus conteúdos no tempo de execução são imprevisíveis. Podem ser usados como campos “fictícios”, para fins de alinhamento. Um campo de bits sem nome cuja largura for especificada como 0 garante que o armazenamento para o membro após *struct-declaration-list* comece em um limite `int`.

Os campos de bits devem também devem ser longos o bastante para conter o padrão de bits. Por exemplo, essas duas instruções não são válidas:

```
short a:17;        /* Illegal! */
int long y:33;     /* Illegal! */
```

Este exemplo define uma matriz de estruturas bidimensional nomeada `screen`.

```
struct
{
    unsigned short icon : 8;
    unsigned short color : 4;
    unsigned short underline : 1;
    unsigned short blink : 1;
} screen[25][80];
```

A matriz contém 2.000 elementos. Cada elemento é uma estrutura individual que contém quatro membros de campo de bits: `icon`, `color`, `underline` e `blink`. O tamanho de cada estrutura são dois bytes.

Os campos de bits têm a mesma semântica do tipo inteiro. Isso significa que um campo de bits é usado em expressões exatamente da mesma forma que uma variável do mesmo tipo de base, independentemente de quantos bits houver no campo de bits.

**Específico da Microsoft**

Os campos de bits definidos como `int` são tratados como assinados. Uma extensão da Microsoft para o padrão ANSI C permite tipos `char` e **long** (tanto **signed** como `unsigned`) para campos de bits. Os campos de bits sem nome com o tipo de base **long**, **short** ou `char` (**signed** ou `unsigned`) forçam o alinhamento a um limite apropriado para o tipo de base.

Os campos de bit são alocados em um inteiro do bit menos significativo ao bit mais significativo. No código a seguir

```
struct mybitfields
{
    unsigned short a : 4;
    unsigned short b : 5;
    unsigned short c : 7;
} test;

int main( void );
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

Como a família de processadores 8086 armazena o byte inferior dos valores inteiros antes do byte superior, o inteiro `0x01F2` acima seria armazenado na memória física como `0xF2` seguido por `0x01`.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Declarações de estrutura](../c-language/structure-declarations.md)
