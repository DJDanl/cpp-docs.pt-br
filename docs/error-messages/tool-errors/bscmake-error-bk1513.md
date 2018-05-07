---
title: BSCMAKE erro BK1513 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- BK1513
dev_langs:
- C++
helpviewer_keywords:
- BK1513
ms.assetid: 9ba87c09-8d82-4c80-b0cf-a8de63dcf9da
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 93664a1224b85ec808805da0172aec408e875bc9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="bscmake-error-bk1513"></a>Erro BK1513 (BSCMAKE)
a atualização não incremental exige todos os arquivos .SBR  
  
 BSCMAKE não pode compilar um novo arquivo de informações (.bsc) do navegador porque um ou mais arquivos .sbr estão truncados. Para localizar os nomes dos arquivos. SBR truncados, leia o [BK4502](../../error-messages/tool-errors/bscmake-warning-bk4502.md) avisos que acompanham esse erro.  
  
 BSCMAKE pode atualizar um arquivo .bsc com um arquivo .sbr truncado, mas não é possível compilar um novo. BSCMAKE pode criar um novo arquivo .bsc pelos seguintes motivos:  
  
-   Arquivo .bsc ausente.  
  
-   Nome de arquivo especificado incorreto para o arquivo .bsc.  
  
-   Arquivo .bsc corrompido.  
  
 Para resolver esse problema, exclua os arquivos .sbr truncados e recompile-os ou limpe a solução e refaça a compilação. (No IDE, escolha **criar**, **limpar solução**e, em seguida, escolha **criar**, **recompilar solução**.)