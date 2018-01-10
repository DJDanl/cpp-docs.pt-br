---
title: . Arquivos ilk como entrada de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- ILK files
- .ilk files
ms.assetid: 7324c104-9e5d-423d-b268-b59f92607bf2
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1b91d229e1c607be1ed35685ab7bfdffe2271e16
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ilk-files-as-linker-input"></a>Arquivos .Ilk como entrada de vinculador
Durante a vinculação incremental, o LINK atualiza o arquivo de status. ilk criadas durante o primeiro link incremental. Este arquivo tem o mesmo nome base do arquivo de .exe ou o arquivo. dll, e tem a. ilk de extensão. Durante os links incrementais subsequentes, LINK atualiza o arquivo. ilk. Se o arquivo. ilk estiver ausente, o LINK executa um link completo e cria um novo arquivo. ilk. Se o arquivo. ilk for usado, o LINK executa um link não incrementais. Para obter detalhes sobre a vinculação incremental, consulte o [Link incremental (/incremental)](../../build/reference/incremental-link-incrementally.md) opção.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de entrada de LINK](../../build/reference/link-input-files.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)