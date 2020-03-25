---
title: Erro fatal C1128
ms.date: 11/04/2016
f1_keywords:
- C1128
helpviewer_keywords:
- C1128
ms.assetid: 6f9580fd-ecef-48be-9780-dcf666704279
ms.openlocfilehash: 64671c9abe8ed1375df1e91ca7509e6a597366ee
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80203616"
---
# <a name="fatal-error-c1128"></a>Erro fatal C1128

o número de seções excedeu o limite de formato de arquivo de objeto: compilar com/bigobj

Um arquivo. obj excedeu o número de seções permitidas, uma limitação de formato de arquivo de objeto COFF.

Atingir essa limitação de seção pode ser o resultado do uso de [/GY](../../build/reference/gy-enable-function-level-linking.md) e de uma compilação de depuração; **/GY** faz com que as funções entrem em suas próprias seções COMDAT. Em uma compilação de depuração, há uma seção de informações de depuração para cada função COMDAT.

C1128 também pode ser causado quando há muitas funções embutidas.

Para corrigir esse erro, divida o arquivo de origem em vários arquivos de código-fonte, compile sem **/GY**ou compile com [/bigobj (aumente o número de seções no. Arquivo obj)](../../build/reference/bigobj-increase-number-of-sections-in-dot-obj-file.md).  Se você não compilar com **/GY**, será necessário especificar as otimizações individualmente, já que **/O2** e **/O1** implicam **/GY**.

Se possível, compile sem informações de depuração.

Talvez você também precise ter instanciações específicas de modelos em arquivos de código-fonte separados, em vez de fazer com que o compilador os emita.

Ao portar o código, o C1128 provavelmente aparecerá primeiro ao usar o compilador x64 e muito mais tarde com o compilador x86. o x64 terá pelo menos 4 seções associadas a cada função compilada **/GY** ou embutida de modelos ou inline de classe: código, pData e informações de depuração e, possivelmente, XData.  O x86 não terá o pData.
