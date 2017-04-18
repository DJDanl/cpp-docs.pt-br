---
title: "Compilador aviso (nível 1) C4041 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4041
dev_langs:
- C++
helpviewer_keywords:
- C4041
ms.assetid: 107ee9fd-4b88-4f22-a18f-a20726831095
caps.latest.revision: 7
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
ms.openlocfilehash: 0f0d14f64e67661288b26616799784df4481cd48
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4041"></a>Compilador C4041 de aviso (nível 1)
limite do compilador : encerrando saída do navegador  
  
 Informações sobre o navegador excedeu o limite do compilador.  
  
 Esse aviso pode ser causado por compilar com [/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) (informações de navegador incluindo variáveis locais).  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir, usando as seguintes soluções possíveis  
  
1.  Compile com /Fr (informações do navegador sem variáveis locais).  
  
2.  Desabilite a saída do navegador (compilar sem /FR ou /Fr).
