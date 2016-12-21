---
title: "Erro fatal RC1052 (compilador de recurso) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "RC1052"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "RC1052"
ms.assetid: 59803673-492b-44fa-80fa-df93b8aaf9fb
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal RC1052 (compilador de recurso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

limite do compilador: blocos \#if ou \#ifdef muito aninhados  
  
 O programa excedeu os níveis de aninhamento máximos permitidos para as diretivas `#if` e `#ifdef`.  
  
 Esse erro pode ser causado pela inclusão dos arquivos que usam essas diretivas de pré\-processador.  
  
 Para corrigir esse problema, reduza o número das diretivas `#if` e `#ifdef` aninhadas no seu arquivo de recurso.  Se o problema for causado por arquivos de cabeçalho incluídos no seu arquivo de recursos, reduza o número de diretivas `#if` e `#ifdef` aninhadas nos arquivos de cabeçalho.  Se isso não for possível, considere criar e incluir um novo arquivo de cabeçalho no arquivo de recursos, executando o pré\-processador nos arquivos de cabeçalho incluídos existentes.  Para obter mais informações, consulte a opção do compilador [\/P \(pré\-processar em um arquivo\)](../../build/reference/p-preprocess-to-a-file.md).