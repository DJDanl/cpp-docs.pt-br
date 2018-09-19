---
title: Compilador aviso (nível 4) C4435 | Microsoft Docs
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
ms.openlocfilehash: 7c9a69e0d899e1a79c1d91b7c18c0eacaf66d32a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46027291"
---
# <a name="compiler-warning-level-4-c4435"></a>Compilador aviso (nível 4) C4435

'class1' : layout do objeto em /vd2 será alterado devido à base virtual 'class2'

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