---
title: Erro fatal C1128 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1128
dev_langs:
- C++
helpviewer_keywords:
- C1128
ms.assetid: 6f9580fd-ecef-48be-9780-dcf666704279
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 7c70243c6fe3acf50e46c6bdf0880ed713b4b16c
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1128"></a>Erro fatal C1128
número de seções excede o limite de formato do arquivo de objeto : compile com /bigobj  
  
 Um arquivo. obj excedeu o número de seções permitidos, uma limitação de formato de arquivo de objeto COFF.  
  
 Atingir essa limitação seção pode ser o resultado do uso de [/Gy](../../build/reference/gy-enable-function-level-linking.md) e uma compilação de depuração; **/Gy** faz com que funções entrar em suas próprias seções COMDAT. Em uma compilação de depuração, há uma seção de informações de depuração para cada função COMDAT.  
  
 C1128 também pode ser causado quando há muitas funções embutidas.  
  
 Para corrigir esse erro, divida seu arquivo de origem em vários arquivos de código fonte, compilar sem **/Gy**, ou compilando com [/bigobj (aumentar o número de seções. Os arquivos obj)](../../build/reference/bigobj-increase-number-of-sections-in-dot-obj-file.md).  Se você não compilar com **/Gy**, será necessário especificar as otimizações individualmente, pois **/O2** e **/O1** ambos implicam **/Gy**.  
  
 Se possível, compile sem informações de depuração.  
  
 Você também precisa têm instanciações específicas de modelos em arquivos de código fonte separado, em vez de fazer o compilador emitir os.  
  
 Ao portar código, C1128 provavelmente aparecerão primeiro ao usar o x64 compilador e muito mais tarde com o x86 compilador. x64 terá pelo menos 4 seções associadas a cada função compilada **/Gy** ou embutidas de modelos ou classe embutido: código pdata e depurar informações e possivelmente xdata.  X86 não terá pdata.
