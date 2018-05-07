---
title: RW4004 de aviso do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RW4004
dev_langs:
- C++
helpviewer_keywords:
- RW4004
ms.assetid: 596b6a89-9ce7-4ba7-bdcb-e8054c7efafa
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 94bd1c043ac5660c5cb8fc8b2bfa1dd2f6968b55
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="resource-compiler-warning-rw4004"></a>Aviso RW4004 (compilador de recurso)
Caracteres ASCII não equivalente ao código de tecla virtual  
  
 Uma cadeia de caracteres literal foi usada para o código de tecla virtual em um acelerador de tipo VIRTKEY.  
  
 Esse aviso permite que você continuar, mas lembre-se de que as teclas de aceleração geradas podem não corresponder a cadeia de caracteres indicado. (VIRTKEYs usar códigos de tecla diferentes de aceleradores de ASCII.)  
  
 Enquanto os literais de cadeia de caracteres são sintaticamente válidos, você só pode garantir que você obtenha o acelerador desejado, usando o **VK_\* #define** valores no Windows. h.