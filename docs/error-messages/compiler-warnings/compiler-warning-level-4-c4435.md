---
title: "Compilador (nível 4) de aviso C4435 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
dev_langs: C++
ms.assetid: a04524af-2b71-4ff9-9729-d9d1d1904ed7
caps.latest.revision: "2"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7136cfb61a7452b7e835030216d08f064874df8b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4435"></a>Compilador C4435 de aviso (nível 4)
'class1' : layout do objeto em /vd2 será alterado devido à base virtual 'class2'  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
 Sob o padrão a opção de /vd1 de compilação, a classe derivada não tem um `vtordisp` campo para a base virtual indicada.  Se /vd2 ou `#pragma vtordisp(2)` está em vigor, um `vtordisp` campo estará presente, alterar o layout do objeto.  Isso pode levar a problemas de compatibilidade binária se módulos de interação são compilados com diferentes `vtordisp` configurações.  
  
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