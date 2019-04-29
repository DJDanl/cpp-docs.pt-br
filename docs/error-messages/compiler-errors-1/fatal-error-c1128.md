---
title: Erro fatal C1128
ms.date: 11/04/2016
f1_keywords:
- C1128
helpviewer_keywords:
- C1128
ms.assetid: 6f9580fd-ecef-48be-9780-dcf666704279
ms.openlocfilehash: bb1d9af10084d6b3e75325450c7f13ea1683ee2e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62229040"
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