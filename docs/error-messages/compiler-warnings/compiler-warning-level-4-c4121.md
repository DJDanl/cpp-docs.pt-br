---
title: Aviso do compilador (nível 4) C4121
ms.date: 11/04/2016
f1_keywords:
- C4121
helpviewer_keywords:
- C4121
ms.assetid: 8c5b85c9-2543-426b-88bc-319c50158c7e
ms.openlocfilehash: bafa16cbad2cb0a2475cae5a98c608096e296442
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541614"
---
# <a name="compiler-warning-level-4-c4121"></a>Aviso do compilador (nível 4) C4121

'símbolo': alinhamento de um membro foi sensível a empacotamento

O compilador adicionou preenchimento para alinhar um membro da estrutura do limite de empacotamento, mas o valor de empacotamento é menor que o tamanho do membro. Por exemplo, o seguinte snippet de código gera C4121:

```cpp
// C4121.cpp
// compile with: /W4 /c
#pragma pack(2)
struct s
{
   char a;
   int b; // C4121
   long long c;
};
```

Para corrigir esse problema, faça um das seguintes alterações:

- Alterar o tamanho de empacotamento do membro que causou o aviso ou maior. Por exemplo, neste snippet, altere `pack(2)` para `pack(4)` ou `pack(8)`.

- Reorganize as declarações de membro por tamanho, do maior para o menor. No snippet, inverta a ordem dos membros da estrutura de modo que o membro `long long` preceda `int` e `int` preceda `char`.

Esse aviso ocorre apenas quando o compilador adiciona preenchimento antes dos membros de dados. Não ocorre quando o empacotamento colocou dados em um local de memória que não está alinhado com o tipo de dados, mas nenhum preenchimento foi colocado antes do membro de dados. Quando os dados não são alinhados em limites que sejam múltiplos do tamanho dos dados, o desempenho pode ser prejudicado. As leituras e gravações de dados não alinhados causam falhas de processador em algumas arquiteturas e as falhas podem demorar mais tempo para resolver, de duas ou três ordens de magnitude. Os acessos a dados não alinhados não podem ser movidos para algumas arquiteturas RISC.

Você pode usar [#pragma Pack](../../preprocessor/pack.md) ou [/ZP](../../build/reference/zp-struct-member-alignment.md) para especificar o alinhamento da estrutura. (O compilador não gera esse aviso quando **/Zp1** é especificado.)