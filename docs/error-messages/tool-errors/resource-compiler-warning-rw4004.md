---
title: RW4004 de aviso do compilador de recurso | Microsoft Docs
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0249f7d01ee344f0fa17bdc39e58e9fce26c9b25
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="resource-compiler-warning-rw4004"></a>Aviso RW4004 (compilador de recurso)
Caracteres ASCII não equivalente ao código de tecla virtual  
  
 Uma cadeia de caracteres literal foi usada para o código de tecla virtual em um acelerador de tipo VIRTKEY.  
  
 Esse aviso permite que você continuar, mas lembre-se de que as teclas de aceleração geradas podem não corresponder a cadeia de caracteres indicado. (VIRTKEYs usar códigos de tecla diferentes de aceleradores de ASCII.)  
  
 Enquanto os literais de cadeia de caracteres são sintaticamente válidos, você só pode garantir que você obtenha o acelerador desejado, usando o **VK_\* #define** valores no Windows. h.