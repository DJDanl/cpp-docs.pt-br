---
title: Compilador (nível 4) de aviso C4121 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4121
dev_langs:
- C++
helpviewer_keywords:
- C4121
ms.assetid: 8c5b85c9-2543-426b-88bc-319c50158c7e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7c1cda66d120278034fc8c19ba0221be047a75eb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4121"></a>Compilador C4121 de aviso (nível 4)
'símbolo': alinhamento de um membro foi sensível a empacotamento  
  
 O compilador adicionou preenchimento para alinhar um membro da estrutura do limite de empacotamento, mas o valor de empacotamento é menor que o tamanho do membro. Por exemplo, o seguinte trecho de código gera C4121:  
  
```  
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
  
-   Alterar o tamanho de empacotamento do membro que causou o aviso ou maior. Por exemplo, neste trecho, altere `pack(2)` para `pack(4)` ou `pack(8)`.  
  
-   Reorganize as declarações de membro por tamanho, do maior para o menor. No trecho, inverta a ordem dos membros da estrutura de modo que o membro `long long` preceda `int` e `int` preceda `char`.  
  
 Esse aviso ocorre apenas quando o compilador adiciona preenchimento antes dos membros de dados. Não ocorre quando o empacotamento colocou dados em um local de memória que não está alinhado com o tipo de dados, mas nenhum preenchimento foi colocado antes do membro de dados. Quando os dados não são alinhados em limites que sejam múltiplos do tamanho dos dados, o desempenho pode ser prejudicado. As leituras e gravações de dados não alinhados causam falhas de processador em algumas arquiteturas e as falhas podem demorar mais tempo para resolver, de duas ou três ordens de magnitude. Os acessos a dados não alinhados não podem ser movidos para algumas arquiteturas RISC.  
  
 Você pode usar [#pragma pacote](../../preprocessor/pack.md) ou [/Zp](../../build/reference/zp-struct-member-alignment.md) para especificar o alinhamento de estrutura. (O compilador não gera este aviso quando **/Zp1** for especificado.)