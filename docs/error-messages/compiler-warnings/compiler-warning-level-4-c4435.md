---
title: Compilador (nível 4) de aviso C4435 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
dev_langs:
- C++
ms.assetid: a04524af-2b71-4ff9-9729-d9d1d1904ed7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 72c29bd6d9ffdb4eabb036c61d85a6572cef8fe2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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
 [/vd (desabilitar deslocamentos de construção)](../../build/reference/vd-disable-construction-displacements.md)