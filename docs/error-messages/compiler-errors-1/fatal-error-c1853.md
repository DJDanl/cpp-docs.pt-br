---
title: Erro fatal C1853 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C1853
dev_langs: C++
helpviewer_keywords: C1853
ms.assetid: ceb9b4a5-92bf-4573-8a9f-3109cc7743ce
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 23b5302428fc216a8349e8cf022c184caa57202c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="fatal-error-c1853"></a>Erro fatal C1853
  
> '*filename*' arquivo de cabeçalho pré-compilado é de uma versão anterior do compilador, ou o cabeçalho pré-compilado é de C++ e você estiver usando do C (ou vice-versa)  
  
Possíveis causas:  
  
-   O cabeçalho pré-compilado foi compilado com uma versão anterior do compilador. Tente recompilar o cabeçalho com o compilador atual.  
  
-   O cabeçalho pré-compilado é de C++ e são usá-lo do C. Tente recompilar o cabeçalho para uso com C, especificando um do [/Tc](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) opções do compilador, ou alterar o sufixo do arquivo de origem para o "c". Para obter mais informações, consulte [duas escolhas para pré-compilar código](../../build/reference/creating-precompiled-header-files.md#two-choices-for-precompiling-code).