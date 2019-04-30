---
title: Compilador aviso (nível 4) C4435
ms.date: 11/04/2016
ms.assetid: a04524af-2b71-4ff9-9729-d9d1d1904ed7
ms.openlocfilehash: 43c13c484d6e9accee7c4d2c58b72a4539a75c4c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391472"
---
# <a name="compiler-warning-level-4-c4435"></a>Compilador aviso (nível 4) C4435

'class1': Layout do objeto em/vd2 será alterado devido à base virtual 'class2'

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

Sob o padrão a opção de/vd1 de compilação, a classe derivada não tem um `vtordisp` campo para a base virtual indicada.  Se/vd2 ou `#pragma vtordisp(2)` está em vigor, um `vtordisp` campo será estiver presente, alterando o layout do objeto.  Isso pode levar a problemas de compatibilidade binária se interação módulos são compilados com diferentes `vtordisp` configurações.

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