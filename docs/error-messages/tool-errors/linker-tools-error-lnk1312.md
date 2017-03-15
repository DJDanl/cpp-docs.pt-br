---
title: Ferramentas de vinculador LNK1312 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1312
dev_langs:
- C++
helpviewer_keywords:
- LNK1312
ms.assetid: 48284abb-d849-43fc-ab53-45aded14fd8a
caps.latest.revision: 6
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
ms.openlocfilehash: 252ef1810533ee3b527e2cbbbb789a84c81ae681
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1312"></a>Erro das Ferramentas de Vinculador LNK1312
arquivo inválido ou corrompido: incapaz de importar montagem  
  
 Ao criar um assembly, um arquivo que não seja um módulo ou assembly compilado com **/clr** foi passado para o **/ASSEMBLYMODULE** opção de vinculador.  Se você passar um arquivo de objeto para **/ASSEMBLYMODULE**, basta passar o objeto diretamente para o vinculador, em vez de para **/ASSEMBLYMODULE**.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir criou o arquivo. obj.  
  
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
