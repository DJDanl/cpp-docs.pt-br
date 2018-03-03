---
title: Recurso compilador Erro Fatal RC1052 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RC1052
dev_langs:
- C++
helpviewer_keywords:
- RC1052
ms.assetid: 59803673-492b-44fa-80fa-df93b8aaf9fb
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0546441022d8e2b487d83e291574020665cdaf4c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="resource-compiler-fatal-error-rc1052"></a>Erro fatal RC1052 (compilador de recurso)
limite do compilador: blocos #if ou #ifdef muito aninhados  
  
 O programa excedeu os níveis de aninhamento máximos permitidos para as diretivas `#if` e `#ifdef`.  
  
 Esse erro pode ser causado pela inclusão dos arquivos que usam essas diretivas de pré-processador.  
  
 Para corrigir esse problema, reduza o número das diretivas `#if` e `#ifdef` aninhadas no seu arquivo de recurso. Se o problema for causado por arquivos de cabeçalho incluídos no seu arquivo de recursos, reduza o número de diretivas `#if` e `#ifdef` aninhadas nos arquivos de cabeçalho. Se isso não for possível, considere criar e incluir um novo arquivo de cabeçalho no arquivo de recursos, executando o pré-processador nos arquivos de cabeçalho incluídos existentes. Para obter mais informações, consulte o [/P (pré-processar em um arquivo)](../../build/reference/p-preprocess-to-a-file.md) opção de compilador.