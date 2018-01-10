---
title: C2692 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2692
dev_langs: C++
helpviewer_keywords: C2692
ms.assetid: 02ade3b4-b757-448b-b065-d7d71bc3f441
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9253bf70204bfded06189b6688405cabc43bdcf9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2692"></a>C2692 de erro do compilador
'function_name': funções totalmente prototipadas são necessárias no compilador C com o ' / clr' opção  
  
 Quando estiver compilando para .NET de código gerenciado, o compilador C requer declarações de função de ANSI. Além disso, se uma função não usa nenhum parâmetro, ele deve declarar explicitamente `void` como o tipo de parâmetro.