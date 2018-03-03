---
title: Ferramentas de vinculador LNK1107 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1107
dev_langs:
- C++
helpviewer_keywords:
- LNK1107
ms.assetid: a37a893d-5efa-4eba-8f40-6c5518b4b9d0
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fae412de31163aa1b5248af43227042cd04563ba
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1107"></a>Erro das Ferramentas de Vinculador LNK1107
arquivo inválido ou corrompido: não é possível ler no local  
  
 A ferramenta não foi possível ler o arquivo. Recrie o arquivo.  
  
 LNK1107 também pode ocorrer se você tentar passar um módulo (extensão de arquivo. dll ou. netmodule criado com [/clr:noAssembly](../../build/reference/clr-common-language-runtime-compilation.md) ou [/NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md)) para o vinculador; passe o arquivo. obj em vez disso.  
  
 Se você compilar o exemplo a seguir:  
  
```  
// LNK1107.cpp  
// compile with: /clr /LD  
public ref class MyClass {  
public:  
   void Test(){}  
};  
```  
  
 e, em seguida, especifique **link LNK1107.dll** na linha de comando, você obterá LNK1107.  Para resolver o erro, especifique **link LNK1107.obj** em vez disso.