---
title: Ferramentas de vinculador LNK1107 erro | Documentos do Microsoft
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
caps.latest.revision: 10
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
ms.openlocfilehash: f9e12cb72126a3bb3fc8c7ccdbd0d09c9cebd055
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1107"></a>Erro das Ferramentas de Vinculador LNK1107
arquivo inválido ou corrompido: não é possível ler no local  
  
 A ferramenta não pôde ler o arquivo. Recrie o arquivo.  
  
 LNK1107 também pode ocorrer se você tentar passar um módulo (extensão. dll ou. netmodule criado com [/clr:noAssembly](../../build/reference/clr-common-language-runtime-compilation.md) ou [/NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md)) para o vinculador; passar o arquivo. obj em vez disso.  
  
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
