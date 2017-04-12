---
title: Erro fatal C1047 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C1047
dev_langs:
- C++
helpviewer_keywords:
- C1047
ms.assetid: e1bbbc6b-a5bc-4c23-8203-488120a0ec78
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 5b23d0dd38806e613f0066002cc73b143956225c
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1047"></a>Erro fatal C1047
O arquivo de objeto ou biblioteca 'arquivo' foi criado com um compilador mais antigo que outros objetos. reconstrução antigos objetos e bibliotecas  
  
 C1047 é causado quando os arquivos de objeto ou bibliotecas criada com **/LTCG** são vinculados juntos, mas onde os arquivos de objeto e as bibliotecas são criadas com versões diferentes do conjunto de ferramentas do Visual C++.  
  
 Isso pode acontecer se você começar a usar uma nova versão do compilador, mas não uma reconstrução limpar arquivos existentes do objeto ou bibliotecas.  
  
 Para resolver C1047, recompile todos os arquivos de objeto ou bibliotecas.
