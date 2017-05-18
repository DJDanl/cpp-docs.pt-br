---
title: Linha de comando aviso D9026 | Documentos do Microsoft
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
ms.openlocfilehash: 6e6153a85437ddd61047f9eabd0071eca3900c28
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="command-line-warning-d9026"></a>Aviso D9026 (linha de comando)
opções aplicam-se à linha de comando inteira  
  
 Uma opção foi especificada em um comando após um nome de arquivo foi especificado. A opção foi aplicada ao arquivo anteriores.  
  
 Por exemplo, no comando  
  
```  
CL verdi.c /G5 puccini.c  
```  
  
 o arquivo VERDI.c será compilado usando a opção /G5, não o padrão /G4.  
  
 Esse comportamento é diferente do que algumas versões anteriores, aplicadas somente as opções especificadas antes do nome do arquivo, resultando em VERDI.c sendo compilado usando/G4 e PUCCINI.c sendo compilado usando /G5.
