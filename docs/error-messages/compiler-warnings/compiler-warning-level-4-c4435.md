---
title: "Compilador aviso (nível 4) C4435 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
dev_langs:
- C++
ms.assetid: a04524af-2b71-4ff9-9729-d9d1d1904ed7
caps.latest.revision: 2
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
ms.openlocfilehash: 0d419a4e96ee0716e710b93ce0fa93276ec858aa
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4435"></a>Compilador C4435 de aviso (nível 4)
'class1' : layout do objeto em /vd2 será alterado devido à base virtual 'class2'  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
 Sob o padrão compilar a opção de /vd1, a classe derivada não tem um `vtordisp` campo base virtual indicada.  Se /vd2 ou `#pragma vtordisp(2)` está em vigor, um `vtordisp` campo estará presente, alterando o layout do objeto.  Isso pode levar a problemas de compatibilidade binária se interação módulos são compilados com diferentes `vtordisp` configurações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4435.  
  
```cpp  
// C4435.cpp  
// compile with: /c /W4  
#pragma warning(default : 4435)  
class A  
{  
public:  
    virtual ~A() {}  
};  
  
class B : public virtual A  // C4435  
{};  
```  
  
## <a name="see-also"></a>Consulte também  
 [vtordisp](../../preprocessor/vtordisp.md)   
 [/VD (desabilitar deslocamentos de construção)](../../build/reference/vd-disable-construction-displacements.md)
