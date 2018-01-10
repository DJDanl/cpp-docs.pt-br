---
title: "Rotinas do tratamento de exceções | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: c.exceptions
dev_langs: C++
helpviewer_keywords: exception handling, routines
ms.assetid: f60548c6-850a-4e1e-a79b-a2a6a541ab62
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 95ecbc69dd9cbd86bd7891c79f115442f659ff94
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exception-handling-routines"></a>Rotinas do tratamento de exceções
Use as funções de tratamento de exceção do C++ para recuperar eventos inesperados durante a execução do programa.  
  
### <a name="exception-handling-functions"></a>Funções de tratamento de exceção  
  
|Função|Use|  
|--------------|---------|  
|[_set_se_translator](../c-runtime-library/reference/set-se-translator.md)|Trata exceções do Win32 (exceções de C estruturadas) como exceções C++|  
|[set_terminate](../c-runtime-library/reference/set-terminate-crt.md)|Instala sua própria rotina de terminação a ser chamada por `terminate`|  
|[set_unexpected](../c-runtime-library/reference/set-unexpected-crt.md)|Instala sua própria função de terminação a ser chamada por `unexpected`|  
|[terminate](../c-runtime-library/reference/terminate-crt.md)|Chamado automaticamente em determinadas circunstâncias após a exceção ser lançada. A `terminate` função chama `abort` ou uma função especificada usando `set_terminate`|  
|[unexpected](../c-runtime-library/reference/unexpected-crt.md)|Chama `terminate` ou uma função especificada usando `set_unexpected`. A função `unexpected` não é usada na implementação atual de tratamento de exceção em Microsoft C++|  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)