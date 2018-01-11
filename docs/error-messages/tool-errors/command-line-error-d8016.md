---
title: Erro de linha de comando D8016 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: D8016
dev_langs: C++
helpviewer_keywords: D8016
ms.assetid: eec51312-7471-4f92-94b2-d517cafc8ef5
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 463de86acf0446f125b66ec1cdc3768c6238b630
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="command-line-error-d8016"></a>Erro D8016 (linha de comando)
Opções de linha de comando 'opção 1' e 'option2' são incompatíveis  
  
 As opções de linha de comando não podem ser especificadas juntos.  
  
 Verifique as variáveis de ambiente, como CL, especificações de opção.  
  
 **/CLR** implica **/EHa**, e você não pode especificar qualquer outro **/EH** opção de compilador com **/clr**. Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
 Você pode obter D8016 depois de atualizar um [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] projeto 6.0: pode permitir que o processo do Assistente de atualização de projeto **/RTC** para cada arquivo de código fonte no projeto, que substitui o **/RTC** configuração para o projeto.  Para resolver, altere o **/RTC** definição para cada arquivo de código fonte no projeto para a configuração padrão, que significa que a configuração de projeto para **/RTC** entrará em vigor para cada arquivo.  
  
 Consulte [/RTC (verificações de erro de tempo de execução)](../../build/reference/rtc-run-time-error-checks.md) para obter informações sobre como alterar o **/RTC** configuração de propriedade.