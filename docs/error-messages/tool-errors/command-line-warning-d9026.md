---
title: Linha de comando D9026 de aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- D9026
dev_langs:
- C++
helpviewer_keywords:
- D9026
ms.assetid: 149fe5e3-5329-4be8-b871-49dfd423aaba
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9e2d99573ee46c51178cc2fe995fa0f526b800f9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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