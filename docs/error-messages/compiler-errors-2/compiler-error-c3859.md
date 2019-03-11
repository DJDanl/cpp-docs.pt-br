---
title: Erro do compilador C3859
ms.date: 03/08/2019
f1_keywords:
- C3859
helpviewer_keywords:
- C3859
ms.assetid: 40e93b25-4393-4467-90de-035434a665c7
ms.openlocfilehash: 9b20224207ba797c6ee93c06404e4d90c3d02525
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57738643"
---
# <a name="compiler-error-c3859"></a>Erro do compilador C3859

> intervalo de memória virtual para PCH excedido; recompile com uma opção de linha de comando de '-Zm*valor*' ou superior

A memória virtual alocada para o cabeçalho pré-compilado é muito pequena para a quantidade de dados que o compilador está tentando colocar nele. A partir do Visual Studio 2015, o **/Zm** recomendação só é significativa ao usar o `#pragma hdrstop` diretiva. Em outros casos, é um erro artificial que indique problemas de pressão de memória virtual do Windows.

Se o cabeçalho pré-compilado usa um `#pragma hdrstop` diretriz, use o **/Zm** sinalizador do compilador para especificar um valor maior para o arquivo de cabeçalho pré-compilado. Caso contrário, considere a redução do número de processos de compilação paralela em sua compilação. Para obter mais informações, consulte [/Zm (especificar pré-compilado cabeçalho alocação de limite de memória)](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md).
