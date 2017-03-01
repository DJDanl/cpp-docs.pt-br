---
title: "Compilador aviso (nível 4) C4121 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4121
dev_langs:
- C++
helpviewer_keywords:
- C4121
ms.assetid: 8c5b85c9-2543-426b-88bc-319c50158c7e
caps.latest.revision: 10
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: bcd26903e6d76a306b30d02b7e9a75f996be1ce9
ms.lasthandoff: 02/25/2017

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
  
 Você pode usar [#pragma pacote](../../preprocessor/pack.md) ou [/Zp](../../build/reference/zp-struct-member-alignment.md) para especificar o alinhamento da estrutura. (O compilador não gera esse aviso quando **/Zp1** for especificado.)
