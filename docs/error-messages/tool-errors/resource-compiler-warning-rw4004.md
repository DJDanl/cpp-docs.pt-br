---
title: RW4004 de aviso do compilador de recurso | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RW4004
dev_langs:
- C++
helpviewer_keywords:
- RW4004
ms.assetid: 596b6a89-9ce7-4ba7-bdcb-e8054c7efafa
caps.latest.revision: 6
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
ms.openlocfilehash: d5f68a8c2b01ff9d32a03d6b0f96018e574d903f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="resource-compiler-warning-rw4004"></a>Aviso RW4004 (compilador de recurso)
Caracteres ASCII não é equivalente ao código de tecla virtual  
  
 Um literal de cadeia de caracteres foi usado para o código de tecla virtual em um acelerador de tipo VIRTKEY.  
  
 Esse aviso lhe permite continuar, mas lembre-se de que as teclas de aceleração geradas podem não corresponder a cadeia de caracteres que você indicou. (VIRTKEYs usar códigos de tecla diferentes de aceleradores de ASCII).  
  
 Enquanto literais de cadeia de caracteres são sintaticamente válidos, você só pode garantir que você obtenha o Acelerador que desejar usando o **VK_\* #define** valores no Windows. h.
