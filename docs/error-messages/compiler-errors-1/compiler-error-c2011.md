---
title: C2011 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2011
dev_langs:
- C++
helpviewer_keywords:
- C2011
ms.assetid: 992c9d51-e850-4d53-b86b-02e73b38249c
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
ms.openlocfilehash: ed0aa8e9db0829716765128c9d409de9852808e1
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2011"></a>C2011 de erro do compilador
'identifier': 'type' Digite redefinição  
  
 O identificador já foi definido como `type`. Verifique se há redefinições do identificador.  
  
 Você também pode obter C2011 se você importar um arquivo de cabeçalho ou biblioteca de tipos mais de uma vez no mesmo arquivo. Para evitar várias inclusões dos tipos definidos em um arquivo de cabeçalho, use incluem proteções ou `#pragma` [quando](../../preprocessor/once.md) diretiva no arquivo de cabeçalho.  
  
 Se você precisar localizar a declaração do tipo redefinido inicial, você pode usar o [/p](../../build/reference/p-preprocess-to-a-file.md) sinalizador do compilador para gerar a saída pré-processada passadas para o compilador. Você pode usar as ferramentas de pesquisa de texto para localizar ocorrências do identificador redefinido no arquivo de saída.  
  
 O exemplo a seguir gera C2011 e mostra uma maneira de corrigir:  
  
```  
// C2011.cpp  
// compile with: /c  
struct S;  
union S;   // C2011  
union S2;   // OK  
```
