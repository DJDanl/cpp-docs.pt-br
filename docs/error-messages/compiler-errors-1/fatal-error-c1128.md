---
title: Erro fatal C1128 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1128
dev_langs:
- C++
helpviewer_keywords:
- C1128
ms.assetid: 6f9580fd-ecef-48be-9780-dcf666704279
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e1d2604b17b656efab3a3575469eff6a02df960c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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