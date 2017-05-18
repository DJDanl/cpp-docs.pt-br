---
title: BSCMAKE erro BK1513 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- BK1513
dev_langs:
- C++
helpviewer_keywords:
- BK1513
ms.assetid: 9ba87c09-8d82-4c80-b0cf-a8de63dcf9da
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 0ca3a265f2920553cfd9dc2f66dbf30365caa0af
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="bscmake-error-bk1513"></a>Erro BK1513 (BSCMAKE)
a atualização não incremental exige todos os arquivos .SBR  
  
 BSCMAKE não pode compilar um novo arquivo de informações (.bsc) do navegador porque um ou mais arquivos .sbr estão truncados. Para localizar os nomes dos arquivos. SBR truncados, leia o [BK4502](../../error-messages/tool-errors/bscmake-warning-bk4502.md) avisos que acompanham este erro.  
  
 BSCMAKE pode atualizar um arquivo .bsc com um arquivo .sbr truncado, mas não é possível compilar um novo. BSCMAKE pode criar um novo arquivo .bsc pelos seguintes motivos:  
  
-   Arquivo .bsc ausente.  
  
-   Nome de arquivo especificado incorreto para o arquivo .bsc.  
  
-   Arquivo .bsc corrompido.  
  
 Para resolver esse problema, exclua os arquivos .sbr truncados e recompile-os ou limpe a solução e refaça a compilação. (No IDE, escolha **criar**, **limpar solução**e, em seguida, escolha **criar**, **recompilar solução**.)
