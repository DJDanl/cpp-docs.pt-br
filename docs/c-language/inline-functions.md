---
title: "Funções embutidas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- fast code
- inline functions, __inline keyword
- functions [C++], inline functions
ms.assetid: 00f4b2ff-8ad0-4165-9f4c-2ef157d03f31
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
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
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: cdcf109b76725855aeb6daae1628bbc6a57e6e32
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="inline-functions"></a>Funções embutidas
**Seção específica da Microsoft**  
  
 A palavra-chave `__inline` diz para o compilador substituir o código na definição de função para cada instância de uma chamada de função. No entanto, a substituição ocorre apenas ao critério do compilador. Por exemplo, o compilador não uma embute uma função se seu endereço já estiver em uso ou se for muito grande para embutir.  
  
 Para que uma função seja considerada candidata para embutir, ela deve usar a definição de função de novo estilo.  
  
 Use esse formato para especificar uma função embutida:  
  
 `__inline`*tipo*aceitação*definição de função*`;`  
  
 O uso de funções embutidas gera código mais rápido e às vezes pode gerar código menor do que a chamada de função equivalente gera pelos seguintes motivos:  
  
-   Ela poupa o tempo necessário para executar chamadas de função.  
  
-   As funções embutidas pequenas, talvez três linhas ou menos, criam menos código do que a chamada de função equivalente porque o compilador não gera código para tratar de argumentos e um valor de retorno.  
  
-   As funções geradas embutidas estão sujeitas às otimizações de código não disponíveis para funções normais porque o compilador não executa otimizações entre procedimentos.  
  
 As funções que usam `__inline` não devem ser confundidas com o código de assembler embutido. Consulte [Assembler embutido](../c-language/inline-assembler-c.md) para obter mais informações.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [inline, __inline, \__forceinline](../cpp/inline-functions-cpp.md)


