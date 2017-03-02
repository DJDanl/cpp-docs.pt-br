---
title: Ferramentas de vinculador LNK2011 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2011
dev_langs:
- C++
helpviewer_keywords:
- LNK2011
ms.assetid: 04991ef5-49d5-46c7-8eee-a9d1d3fc541e
caps.latest.revision: 7
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ce5c43ca2549d42951fe046b326aed21dc74635b
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2011"></a>Erro das Ferramentas de Vinculador LNK2011
objeto precompilado não vinculado; imagem não pode executar  
  
 Se você usar cabeçalhos pré-compilados, LINK requer que todos os arquivos de objeto criados com cabeçalhos pré-compilados devem ser vinculados no. Se você tiver um arquivo de origem que você usa para gerar um cabeçalho pré-compilado para uso com outros arquivos de origem, agora você deve incluir o arquivo de objeto criado com o cabeçalho pré-compilado.  
  
 Por exemplo, se você compilar um arquivo chamado STUB.cpp para criar um cabeçalho pré-compilado para uso com outros arquivos de origem, você deve vincular com STUB.obj ou você receberá esse erro. Nas linhas de comando a seguir, linha é usada para criar um cabeçalho pré-compilado, COMMON.pch, que é usado com PROG1.cpp e PROG2.cpp nas linhas dois e três. O arquivo STUB.cpp contém apenas `#include` linhas (o mesmo `#include` linhas como PROG1.cpp e PROG2.cpp) e é usado apenas para gerar cabeçalhos pré-compilados. Na última linha, STUB.obj devem ser vinculados em evitar LNK2011.  
  
```  
cl /c /Yccommon.h stub.cpp  
cl /c /Yucommon.h prog1.cpp  
cl /c /Yucommon.h prog2.cpp  
link /out:prog.exe stub.obj prog1.obj prog2.obj  
```
