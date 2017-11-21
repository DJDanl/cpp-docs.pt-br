---
title: BSCMAKE erro BK1513 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: BK1513
dev_langs: C++
helpviewer_keywords: BK1513
ms.assetid: 9ba87c09-8d82-4c80-b0cf-a8de63dcf9da
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 3111d6823ed439aa9b26aead84c76de6bc403f9f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="bscmake-error-bk1513"></a>Erro BK1513 (BSCMAKE)
a atualização não incremental exige todos os arquivos .SBR  
  
 BSCMAKE não pode compilar um novo arquivo de informações (.bsc) do navegador porque um ou mais arquivos .sbr estão truncados. Para localizar os nomes dos arquivos. SBR truncados, leia o [BK4502](../../error-messages/tool-errors/bscmake-warning-bk4502.md) avisos que acompanham esse erro.  
  
 BSCMAKE pode atualizar um arquivo .bsc com um arquivo .sbr truncado, mas não é possível compilar um novo. BSCMAKE pode criar um novo arquivo .bsc pelos seguintes motivos:  
  
-   Arquivo .bsc ausente.  
  
-   Nome de arquivo especificado incorreto para o arquivo .bsc.  
  
-   Arquivo .bsc corrompido.  
  
 Para resolver esse problema, exclua os arquivos .sbr truncados e recompile-os ou limpe a solução e refaça a compilação. (No IDE, escolha **criar**, **limpar solução**e, em seguida, escolha **criar**, **recompilar solução**.)