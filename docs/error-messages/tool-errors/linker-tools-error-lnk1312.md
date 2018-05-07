---
title: Ferramentas de vinculador LNK1312 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1312
dev_langs:
- C++
helpviewer_keywords:
- LNK1312
ms.assetid: 48284abb-d849-43fc-ab53-45aded14fd8a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 748276ed8fa459c41174f23d32bcef127cbdd510
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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