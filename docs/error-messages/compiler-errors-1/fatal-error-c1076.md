---
title: Erro fatal C1076 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1076
dev_langs:
- C++
helpviewer_keywords:
- C1076
ms.assetid: 84ac1180-3e8a-48e8-9f77-7f18a778b964
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 2e912cc4910ab1362719d94f374f145e90747e69
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1076"></a>Erro fatal C1076
limite do compilador: limite do heap interno atingido; use /Zm para especificar um limite maior  
  
 Esse erro pode ser causado por muitos símbolos ou por muitas instanciações do modelo.  
  
 Para resolver esse erro:  
  
1.  Use o [/Zm](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md) opção para definir o limite de memória do compilador para o valor especificado no [C3859](../../error-messages/compiler-errors-2/compiler-error-c3859.md) mensagem de erro. Para obter mais informações que inclui definir esse valor no [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)], consulte a seção de comentários em [/Zm (especificar pré-compilado cabeçalho alocação de limite de memória)](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md).  
  
2.  Se você estiver usando os compiladores hospedados de 32 bits em um sistema operacional de 64 bits, use os compiladores hospedados de 64 bits. Para obter mais informações, consulte [como: habilitar um 64-Bit Visual C++ conjunto de ferramentas na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md).  
  
3.  Elimine arquivos de inclusão desnecessários.  
  
4.  Elimine variáveis globais desnecessárias, por exemplo, alocando memória dinamicamente em vez de declarar uma matriz grande.  
  
5.  Elimine declarações não usadas.  
  
6.  Divida funções grandes em funções menores.  
  
7.  Divida classes grandes em classes menores.  
  
8.  Divida o arquivo atual em arquivos menores.  
  
 Se C1076 ocorre imediatamente depois do início da compilação, o valor especificado para **/Zm** provavelmente é muito alto para o programa. Reduzir a **/Zm** valor.
