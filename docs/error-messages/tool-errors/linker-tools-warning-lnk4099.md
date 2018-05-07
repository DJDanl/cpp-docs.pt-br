---
title: Aviso LNK4099 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4099
dev_langs:
- C++
helpviewer_keywords:
- LNK4099
ms.assetid: 358170a4-07cd-43fe-918f-82c32757ffc5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 22764705b35b2e882c5a03e819c9812d084dc118
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-warning-lnk4099"></a>Aviso LNK4099 (Ferramentas de Vinculador)
PDB 'filename' não foi encontrado com o 'objeto/biblioteca' ou 'path'; Vinculando objeto quando sem informação de depuração  
  
 O vinculador não pôde localizar o arquivo. PDB. Copiá-lo para o diretório que contém `object/library`.  
  
 Para localizar o nome do arquivo. PDB associado ao arquivo de objeto:  
  
1.  Extrair um arquivo de objeto de biblioteca com [lib](../../build/reference/lib-reference.md) **/extract:**`objectname`**. obj** `xyz` **. lib**.  
  
2.  Verifique o caminho para o arquivo. PDB com **dumpbin /section:.debug$ T /rawdata** `objectname` **. obj**.  
  
 Você também pode compilar com [/Z7](../../build/reference/z7-zi-zi-debug-information-format.md), portanto, o pdb não precisa ser usado, ou remova o [/Debug](../../build/reference/debug-generate-debug-info.md) opção de vinculador se você não tem arquivos. PDB para os objetos que você está vinculando.