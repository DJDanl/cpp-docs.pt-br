---
title: Linha de comando D9026 de aviso | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- D9026
dev_langs:
- C++
helpviewer_keywords:
- D9026
ms.assetid: 149fe5e3-5329-4be8-b871-49dfd423aaba
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9127ad1887d476e5460798f806c2db1ff3144de3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="command-line-warning-d9026"></a>Aviso D9026 (linha de comando)
opções se aplicam a toda a linha de comando  
  
 Uma opção foi especificada em um comando depois de um nome de arquivo especificado. A opção foi aplicada ao arquivo que o precederam.  
  
 Por exemplo, no comando  
  
```  
CL verdi.c /G5 puccini.c  
```  
  
 o arquivo VERDI.c será compilado usando a opção /G5, não o padrão de /G4.  
  
 Esse comportamento é diferente do que algumas versões anteriores, aplicados apenas as opções especificadas antes do nome do arquivo, resultando em VERDI.c sendo compilada usando/G4 e PUCCINI.c que está sendo compilada usando /G5.