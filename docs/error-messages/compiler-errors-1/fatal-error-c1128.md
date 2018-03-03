---
title: Erro fatal C1128 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1128
dev_langs:
- C++
helpviewer_keywords:
- C1128
ms.assetid: 6f9580fd-ecef-48be-9780-dcf666704279
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 22b53914fba8ab5d5c31d8f7ed0a2e3db52aad5d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fatal-error-c1128"></a>Erro fatal C1128
número de seções excedeu o limite de formato de arquivo de objeto: compile com /bigobj  
  
 Um arquivo. obj excedeu o número de seções permitidos, uma limitação de formato de arquivo de objeto COFF.  
  
 Atingir essa limitação de seção pode ser o resultado do uso de [/Gy](../../build/reference/gy-enable-function-level-linking.md) e uma compilação de depuração; **/Gy** faz com que funções ir para suas próprias seções COMDAT. Em uma compilação de depuração, há uma seção de informações de depuração para cada função COMDAT.  
  
 C1128 também pode ser causado quando há muitas funções embutidas.  
  
 Para corrigir esse erro, divida o arquivo de origem em vários arquivos de código fonte, compilar sem **/Gy**, ou compile com [/bigobj (aumentar o número de seções no. Arquivo obj)](../../build/reference/bigobj-increase-number-of-sections-in-dot-obj-file.md).  Se você não compilar com **/Gy**, será necessário especificar as otimizações individualmente, pois **/O2** e **/O1** ambos implicam **/Gy**.  
  
 Se possível, compile sem informações de depuração.  
  
 Você também precisa ter instâncias específicas dos modelos nos arquivos de código fonte separado, em vez de fazer o compilador emite-los.  
  
 Ao portar código, C1128 provavelmente aparecerão primeiro ao usar o x64 compilador e muito mais tarde com x86 compilador. x64 terá pelo menos 4 seções associadas a cada função compilada **/Gy** ou embutida de modelos ou classe embutida: código pdata e informações e, possivelmente, xdata de depuração.  X86 não terá pdata.