---
title: process | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- process_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], process
- process __declspec keyword
ms.assetid: 60eecc2f-4eef-4567-b9db-aaed34733023
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2c50948d613a40a03d0249e1930943ef61c855b9
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="process"></a>process
Especifica que o processo de aplicativo gerenciado deve ter uma única cópia de uma determinada variável global, variável de membro estática ou variável local estática compartilhada por todos os domínios de aplicativo no processo. Isso foi principalmente a ser usado ao compilar com **/clr: pure**, que foi substituído e será removido em uma versão futura do compilador. Ao compilar com **/clr**, variáveis globais e estáticos são por processo por padrão (não precisa usar `__declspec(process)`.  
  
 Somente uma variável global, uma variável de membro estática ou uma variável local estática de tipo nativo podem ser marcadas com `__declspec(process)`.  
  
  
 `process` só é válido durante a compilação com [/clr](../build/reference/clr-common-language-runtime-compilation.md).  
  
 Se quiser que cada domínio de aplicativo tenha sua própria cópia de uma variável global, use [appdomain](../cpp/appdomain.md).  
  
 Consulte [domínios do aplicativo e do Visual C++](../dotnet/application-domains-and-visual-cpp.md) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [__declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)