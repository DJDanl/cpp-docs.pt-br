---
title: Aviso LNK4070 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4070
dev_langs:
- C++
helpviewer_keywords:
- LNK4070
ms.assetid: f95f179a-fff9-427e-bd51-466b3934517f
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
ms.openlocfilehash: 6d8c784e4c174baaf5e5b35607973cda452e445a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4070"></a>Aviso LNK4070 (Ferramentas de Vinculador)
/Out: nome_do_arquivo diretiva em. EXP é diferente do nome de arquivo de saída 'filename'; Ignorando a diretiva  
  
 O `filename` especificado no [nome](../../build/reference/name-c-cpp.md) ou [biblioteca](../../build/reference/library.md) instrução quando foi criado o arquivo. EXP difere da saída `filename` que foi considerado por padrão ou especificado com o [/out](../../build/reference/out-output-file-name.md) opção.  
  
 Você verá esse aviso se você alterar o nome de um arquivo de saída no ambiente de desenvolvimento e onde o arquivo do projeto. def não foi atualizado. Atualize manualmente o arquivo. def para resolver esse aviso.  
  
 Um programa cliente que usa a DLL resultante poderá ter problemas.
