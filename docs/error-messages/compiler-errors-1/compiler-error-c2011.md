---
title: C2011 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2011
dev_langs:
- C++
helpviewer_keywords:
- C2011
ms.assetid: 992c9d51-e850-4d53-b86b-02e73b38249c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c599d6add1fa51c6aae7f04019eacdc94f11bb15
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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