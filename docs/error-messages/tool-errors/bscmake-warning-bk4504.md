---
title: BSCMAKE aviso BK4504 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- BK4504
dev_langs:
- C++
helpviewer_keywords:
- BK4504
ms.assetid: b56ee2d4-ad44-40f4-98c0-75934ea44a6c
caps.latest.revision: 8
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
ms.openlocfilehash: efe5cf36786171c4a663fb329efbc05b91065c7f
ms.lasthandoff: 02/25/2017

---
# <a name="bscmake-warning-bk4504"></a>Aviso BK4504 (BSCMAKE)
arquivo contém muitas referências; ignorando próximas referências desta fonte  
  
 O arquivo. cpp contém mais de 64.000 referências de símbolo. Quando BSCMAKE encontrou 64.000 referências em um arquivo, ele ignora todas as referências adicionais.  
  
 Para corrigir o problema, em Dividir o arquivo em dois ou mais arquivos, cada um deles tem menos de 64.000 referências de símbolo, ou usarem o `#pragma component(browser)` diretiva de pré-processador para símbolos de limite que são gerados para determinada referências. Para obter mais informações, consulte [componente](../../preprocessor/component.md).
