---
title: Recurso compilador Erro Fatal RC1052 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RC1052
dev_langs:
- C++
helpviewer_keywords:
- RC1052
ms.assetid: 59803673-492b-44fa-80fa-df93b8aaf9fb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6e0651f8c2b48ea69e7137ffa3415ddaffd8fe44
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="resource-compiler-fatal-error-rc1052"></a>Erro fatal RC1052 (compilador de recurso)
limite do compilador: blocos #if ou #ifdef muito aninhados  
  
 O programa excedeu os níveis de aninhamento máximos permitidos para as diretivas `#if` e `#ifdef`.  
  
 Esse erro pode ser causado pela inclusão dos arquivos que usam essas diretivas de pré-processador.  
  
 Para corrigir esse problema, reduza o número das diretivas `#if` e `#ifdef` aninhadas no seu arquivo de recurso. Se o problema for causado por arquivos de cabeçalho incluídos no seu arquivo de recursos, reduza o número de diretivas `#if` e `#ifdef` aninhadas nos arquivos de cabeçalho. Se isso não for possível, considere criar e incluir um novo arquivo de cabeçalho no arquivo de recursos, executando o pré-processador nos arquivos de cabeçalho incluídos existentes. Para obter mais informações, consulte o [/P (pré-processar em um arquivo)](../../build/reference/p-preprocess-to-a-file.md) opção de compilador.