---
title: Erro M6203 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: M6203
dev_langs: C++
helpviewer_keywords: M6203
ms.assetid: bd7fdd1c-83e4-4d6a-901e-10a0308bf5be
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 0ac2e84cb3b8c05bf2b71411c406490d3f266383
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="math-error-m6203"></a>Erro M6203 (Math)
'function': erro de overflow  
  
 O resultado de determinada função era muito grande para ser representado.  
  
 Esse erro chama o `_matherr` função com o tipo de erro, o nome da função e seus argumentos. Você pode reescrever o `_matherr` função para personalizar o tratamento de certos erros de matemática de ponto flutuante de tempo de execução.