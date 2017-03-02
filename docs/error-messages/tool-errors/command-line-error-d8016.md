---
title: Erro de linha de comando D8016 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- D8016
dev_langs:
- C++
helpviewer_keywords:
- D8016
ms.assetid: eec51312-7471-4f92-94b2-d517cafc8ef5
caps.latest.revision: 11
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
ms.openlocfilehash: 79dad5a5134e91b67a395870e4ff7fa8e14066fb
ms.lasthandoff: 02/25/2017

---
# <a name="command-line-error-d8016"></a>Erro D8016 (linha de comando)
Opções de linha de comando de 'opção&1;' e a 'opção&2;' são incompatíveis  
  
 As opções de linha de comando não podem ser especificadas juntos.  
  
 Verifique as variáveis de ambiente, como CL, especificações de opção.  
  
 **/CLR** implica **/EHa**, e você não pode especificar qualquer outro **/EH** opção de compilador com **/clr**. Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
 Você pode obter D8016 após a atualização de um [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] projeto 6.0: pode permitir que o processo do Assistente de atualização de projeto **/RTC** para cada arquivo de código de origem no projeto, que substitui o **/RTC** configuração do projeto.  Para resolver, altere o **/RTC** definição para cada arquivo de código fonte no projeto para a configuração padrão, que significa que a configuração de projeto para **/RTC** entrará em vigor para cada arquivo.  
  
 Consulte [/RTC (verificações de erro de tempo de execução)](../../build/reference/rtc-run-time-error-checks.md) para obter informações sobre como alterar o **/RTC** configuração de propriedade.
