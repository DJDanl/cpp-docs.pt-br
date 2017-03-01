---
title: Recurso compilador Erro Fatal RC1052 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RC1052
dev_langs:
- C++
helpviewer_keywords:
- RC1052
ms.assetid: 59803673-492b-44fa-80fa-df93b8aaf9fb
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 246cdb1f2858e18a3663fe9cc52c9de80e1f8237
ms.lasthandoff: 02/25/2017

---
# <a name="resource-compiler-fatal-error-rc1052"></a>Erro fatal RC1052 (compilador de recurso)
limite do compilador: blocos #if ou #ifdef muito aninhados  
  
 O programa excedeu os níveis de aninhamento máximos permitidos para as diretivas `#if` e `#ifdef`.  
  
 Esse erro pode ser causado pela inclusão dos arquivos que usam essas diretivas de pré-processador.  
  
 Para corrigir esse problema, reduza o número das diretivas `#if` e `#ifdef` aninhadas no seu arquivo de recurso. Se o problema for causado por arquivos de cabeçalho incluídos no seu arquivo de recursos, reduza o número de diretivas `#if` e `#ifdef` aninhadas nos arquivos de cabeçalho. Se isso não for possível, considere criar e incluir um novo arquivo de cabeçalho no arquivo de recursos, executando o pré-processador nos arquivos de cabeçalho incluídos existentes. Para obter mais informações, consulte o [/P (pré-processar em um arquivo)](../../build/reference/p-preprocess-to-a-file.md) opção de compilador.
