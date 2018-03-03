---
title: Ferramentas de vinculador LNK1312 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1312
dev_langs:
- C++
helpviewer_keywords:
- LNK1312
ms.assetid: 48284abb-d849-43fc-ab53-45aded14fd8a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4d7f7b57512f58402403a50bf57176f975769573
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1312"></a>Erro das Ferramentas de Vinculador LNK1312
arquivo inválido ou corrompido: não é possível importar o assembly  
  
 Ao criar um assembly, um arquivo que não seja um módulo ou um assembly compilado com **/clr** foi passado para o **/ASSEMBLYMODULE** opção de vinculador.  Se você passou um arquivo de objeto para **/ASSEMBLYMODULE**, basta passar o objeto diretamente para o vinculador, em vez de para **/ASSEMBLYMODULE**.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir criado o arquivo. obj.  
  
```  
// LNK1312.cpp  
// compile with: /clr /LD  
public ref class A {  
public:  
   int i;  
};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK1312.  
  
```  
// LNK1312_b.cpp  
// compile with: /clr /LD /link /assemblymodule:LNK1312.obj  
// LNK1312 error expected  
public ref class M {};  
```