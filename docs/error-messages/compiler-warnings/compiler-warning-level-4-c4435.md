---
title: Aviso do compilador (nível 4) C4435
ms.date: 11/04/2016
f1_keywords:
- C4435
helpviewer_keywords:
- C4435
ms.assetid: a04524af-2b71-4ff9-9729-d9d1d1904ed7
ms.openlocfilehash: 0ff545d3de3ef173cdbfd99d7714890e8631ce7a
ms.sourcegitcommit: 8762a3f9b5476b4dee03f0ee8064ea606550986e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/04/2019
ms.locfileid: "74810665"
---
# <a name="compiler-warning-level-4-c4435"></a>Aviso do compilador (nível 4) C4435

'class1' : layout do objeto em /vd2 será alterado devido à base virtual 'class2'

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

Na opção de compilação padrão de/vd1, a classe derivada não tem um campo `vtordisp` para a base virtual indicada.  Se/vd2 ou `#pragma vtordisp(2)` estiver em vigor, um campo `vtordisp` estará presente, alterando o layout do objeto.  Isso pode levar a problemas de compatibilidade binária se os módulos de interação forem compilados com diferentes configurações de `vtordisp`.

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

[vtordisp](../../preprocessor/vtordisp.md)<br/>
[/vd (desabilitar deslocamentos de construção)](../../build/reference/vd-disable-construction-displacements.md)