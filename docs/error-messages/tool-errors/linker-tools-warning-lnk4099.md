---
title: Aviso LNK4099 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4099
dev_langs:
- C++
helpviewer_keywords:
- LNK4099
ms.assetid: 358170a4-07cd-43fe-918f-82c32757ffc5
caps.latest.revision: 9
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
ms.openlocfilehash: 7de3ce64ca3a9c5a5b0738888b6c83b4694bd895
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4099"></a>Aviso LNK4099 (Ferramentas de Vinculador)
PDB 'filename' não foi encontrado com '/ Biblioteca de objetos' ou 'caminho'; Vinculando objeto como se nenhuma informação de depuração  
  
 O vinculador não pôde localizar o arquivo. PDB. Copie para o diretório que contém `object/library`.  
  
 Para localizar o nome do arquivo. PDB associado ao arquivo de objeto:  
  
1.  Extrair um arquivo de objeto de biblioteca com [lib](../../build/reference/lib-reference.md) **/extract:**`objectname`**. obj** `xyz` **. lib**.  
  
2.  Verifique o caminho para o arquivo. PDB com **dumpbin /section:.debug$ T /rawdata** `objectname` **. obj**.  
  
 Você também pode compilar com [/Z7](../../build/reference/z7-zi-zi-debug-information-format.md), portanto, o pdb não precisa ser usada, ou remover o [/Debug](../../build/reference/debug-generate-debug-info.md) opção de vinculador se você não tiver arquivos. PDB para os objetos que você está vinculando.
