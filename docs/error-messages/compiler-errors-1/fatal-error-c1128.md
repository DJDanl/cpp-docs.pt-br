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
ms.openlocfilehash: 8a0b0c308811b642e0064304cab0688215ac949a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46079642"
---
# <a name="fatal-error-c1128"></a>Erro fatal C1128

número de seções excedeu o limite de formato de arquivo de objeto: compile com /bigobj

Um arquivo. obj excedeu o número de seções permitidos, uma limitação de formato de arquivo de objeto COFF.

Alcançar essa limitação de seção pode ser o resultado do uso [/Gy](../../build/reference/gy-enable-function-level-linking.md) e uma compilação de depuração; **/Gy** faz com que funções entrar em suas próprias seções COMDAT. Em uma compilação de depuração, há uma seção de informações de depuração para cada função COMDAT.

C1128 também pode ser causado quando há muitas funções de embutidas.

Para corrigir esse erro, divida seu arquivo de origem em vários arquivos de código-fonte, compilado sem **/Gy**, ou compilando com [/bigobj (aumentar número de seções no. Arquivo obj)](../../build/reference/bigobj-increase-number-of-sections-in-dot-obj-file.md).  Se você não compilar com **/Gy**, você precisará especificar as otimizações individualmente, pois **/O2** e **/O1** ambos implicam **/Gy**.

Se possível, compile sem informações de depuração.

Você também precisará ter instanciações específicas de modelos em arquivos de código fonte separado, em vez de fazer o compilador emita-los.

Ao portar o código, C1128 provavelmente aparecerão primeiro quando usando x64, o compilador e muito mais tarde com x86 compilador. x64 terá pelo menos 4 seções associadas com cada função compilada **/Gy** ou embutido de modelos ou classe embutido: código pdata e depurar informações e possivelmente xdata.  X86 não terá pdata.