---
title: C2011 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2011
dev_langs:
- C++
helpviewer_keywords:
- C2011
ms.assetid: 992c9d51-e850-4d53-b86b-02e73b38249c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 898a724f022a81f590ec1f8165de9752de6c1d0b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33166631"
---
# <a name="compiler-error-c2011"></a>C2011 de erro do compilador
'Identificador': 'type' tipo de redefinição  
  
 O identificador já foi definido como `type`. Verifique se há redefinições do identificador.  
  
 Você também pode obter C2011 se você importar um arquivo de cabeçalho ou biblioteca de tipos mais de uma vez no mesmo arquivo. Para evitar várias inclusões dos tipos definidos em um arquivo de cabeçalho, use inclua protege ou `#pragma` [quando](../../preprocessor/once.md) diretiva no arquivo de cabeçalho.  
  
 Se você precisar localizar a declaração inicial do tipo redefinido, você pode usar o [/p](../../build/reference/p-preprocess-to-a-file.md) sinalizador do compilador para gerar a saída pré-processada passadas para o compilador. Você pode usar as ferramentas de pesquisa de texto para localizar instâncias do identificador redefinido no arquivo de saída.  
  
 O exemplo a seguir gera C2011 e mostra uma maneira de corrigir isso:  
  
```  
// C2011.cpp  
// compile with: /c  
struct S;  
union S;   // C2011  
union S2;   // OK  
```