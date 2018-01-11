---
title: Aviso LNK4099 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4099
dev_langs: C++
helpviewer_keywords: LNK4099
ms.assetid: 358170a4-07cd-43fe-918f-82c32757ffc5
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 364c2f9303707328ebf3bdf3284398e6d4f9f0d7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4099"></a>Aviso LNK4099 (Ferramentas de Vinculador)
PDB 'filename' não foi encontrado com o 'objeto/biblioteca' ou 'path'; Vinculando objeto quando sem informação de depuração  
  
 O vinculador não pôde localizar o arquivo. PDB. Copiá-lo para o diretório que contém `object/library`.  
  
 Para localizar o nome do arquivo. PDB associado ao arquivo de objeto:  
  
1.  Extrair um arquivo de objeto de biblioteca com [lib](../../build/reference/lib-reference.md) **/extract:**`objectname`**. obj** `xyz` **. lib**.  
  
2.  Verifique o caminho para o arquivo. PDB com **dumpbin /section:.debug$ T /rawdata** `objectname` **. obj**.  
  
 Você também pode compilar com [/Z7](../../build/reference/z7-zi-zi-debug-information-format.md), portanto, o pdb não precisa ser usado, ou remova o [/Debug](../../build/reference/debug-generate-debug-info.md) opção de vinculador se você não tem arquivos. PDB para os objetos que você está vinculando.