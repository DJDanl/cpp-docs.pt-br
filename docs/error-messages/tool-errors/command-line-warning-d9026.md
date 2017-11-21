---
title: Linha de comando D9026 de aviso | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: D9026
dev_langs: C++
helpviewer_keywords: D9026
ms.assetid: 149fe5e3-5329-4be8-b871-49dfd423aaba
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: eead2bc96a24fd86b123ab4853bfc8ea01166804
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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