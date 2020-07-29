---
title: Classe enable_shared_from_this
ms.date: 11/04/2016
f1_keywords:
- memory/std::enable_shared_from_this
helpviewer_keywords:
- enable_shared_from_this class
- enable_shared_from_this
ms.assetid: 9237603d-22e2-421f-b070-838ac006baf5
ms.openlocfilehash: 9b417eabdaf6002724a0fa947dd97dea6f0df0a5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217773"
---
# <a name="enable_shared_from_this-class"></a>Classe enable_shared_from_this

Ajuda a gerar um `shared_ptr`.

## <a name="syntax"></a>Sintaxe

```cpp
class enable_shared_from_this {
public:
    shared_ptr<Ty>
        shared_from_this();
    shared_ptr<const Ty> shared_from_this() const;
    weak_ptr<T> weak_from_this() noexcept;
    weak_ptr<T const> weak_from_this() const noexcept;
protected:
    enable_shared_from_this();
    enable_shared_from_this(const enable_shared_from_this&);
    enable_shared_from_this& operator=(const enable_shared_from_this&);
    ~enable_shared_from_this();
};
```

### <a name="parameters"></a>parâmetros

*Ty*\
O tipo controlado pelo ponteiro compartilhado.

## <a name="remarks"></a>Comentários

Os objetos derivados de `enable_shared_from_this` podem usar os métodos `shared_from_this` nas funções de membro para criar proprietários de instância [shared_ptr](../standard-library/shared-ptr-class.md) que compartilham a propriedade com proprietários `shared_ptr` existentes. Caso contrário, se você criar um novo `shared_ptr` usando **`this`** , ele será diferente dos `shared_ptr` proprietários existentes, o que pode levar a referências inválidas ou fazer com que o objeto seja excluído mais de uma vez.

Os construtores, o destruidor e o operador de atribuição são protegidos para evitar o uso indevido acidental. O tipo de argumento de modelo *Ty* deve ser o tipo da classe derivada.

Para obter um exemplo de uso, consulte [enable_shared_from_this::shared_from_this](#shared_from_this).

## <a name="shared_from_this"></a><a name="shared_from_this"></a>shared_from_this

Gera um `shared_ptr` que compartilha a propriedade da instância com proprietários `shared_ptr` existentes.

```cpp
shared_ptr<T> shared_from_this();
shared_ptr<const T> shared_from_this() const;
```

### <a name="remarks"></a>Comentários

Quando você deriva objetos da classe base `enable_shared_from_this`, as funções de membro de modelo `shared_from_this` retornam um objeto de [Classe shared_ptr](../standard-library/shared-ptr-class.md) que compartilha a propriedade dessa instância com os proprietários `shared_ptr` existentes. Caso contrário, se você criar um novo a `shared_ptr` partir do **`this`** , ele será distinto dos `shared_ptr` proprietários existentes, o que pode levar a referências inválidas ou fazer com que o objeto seja excluído mais de uma vez. O comportamento será indefinido se você chamar `shared_from_this` em uma instância que já não pertence a um objeto `shared_ptr`.

### <a name="example"></a>Exemplo

```cpp
// std_memory_shared_from_this.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

using namespace std;

struct base : public std::enable_shared_from_this<base>
{
    int val;
    shared_ptr<base> share_more()
    {
        return shared_from_this();
    }
};

int main()
{
    auto sp1 = make_shared<base>();
    auto sp2 = sp1->share_more();

    sp1->val = 3;
    cout << "sp2->val == " << sp2->val << endl;
    return 0;
}
```

```Output
sp2->val == 3
```

## <a name="weak_from_this"></a><a name="weak_from_this"></a>weak_from_this

```cpp
weak_ptr<T> weak_from_this() noexcept;
weak_ptr<T const> weak_from_this() const noexcept;
```
