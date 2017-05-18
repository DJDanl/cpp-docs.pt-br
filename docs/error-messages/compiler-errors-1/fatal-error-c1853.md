---
title: Erro fatal C1853 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1853
dev_langs:
- C++
helpviewer_keywords:
- C1853
ms.assetid: ceb9b4a5-92bf-4573-8a9f-3109cc7743ce
caps.latest.revision: 10
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d312a819b5e91386d805635fdd588b72ee842cfe
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1853"></a>Erro fatal C1853
arquivo de cabeçalho pré-compilado 'filename' é de uma versão anterior do compilador, ou o cabeçalho pré-compilado é C++ e você estiver usando do C (ou vice-versa)  
  
 Possíveis causas:  
  
-   O cabeçalho pré-compilado foi compilado com uma versão anterior do compilador. Tente recompilar o cabeçalho com o compilador atual.  
  
-   O cabeçalho pré-compilado é C++ e estiver usando-o de C. Tente recompilar o cabeçalho para uso com C, especificando um do [/Tc](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) opções do compilador ou alterar o sufixo do arquivo de origem como "c". Para obter mais informações, consulte [duas escolhas para pré-compilar código](../../build/reference/two-choices-for-precompiling-code.md).
