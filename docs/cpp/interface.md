---
title: __interface
ms.date: 05/07/2019
f1_keywords:
- __interface_cpp
helpviewer_keywords:
- __interface keyword [C++]
ms.assetid: ca5d400b-d6d8-4ba2-89af-73f67e5ec056
ms.openlocfilehash: 7c95e3700b4124c4793e0214ed3b06ecfeee72f1
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65222083"
---
# <a name="interface"></a>__interface

**Seção específica da Microsoft**

Microsoft C++ interface pode ser definida da seguinte maneira:

- Ela pode herdar de zero ou mais interfaces base.

- Ela não pode herdar de uma classe base.

- Ela pode conter apenas métodos virtuais puros e públicos.

- Ela não pode conter construtores, destruidores ou operadores.

- Ela não pode conter métodos estáticos.

- Ela não pode conter membros de dados; as propriedades são permitidas.

## <a name="syntax"></a>Sintaxe

```
modifier __interface interface-name {interface-definition};
```

## <a name="remarks"></a>Comentários

Um C++ [classe](../cpp/class-cpp.md) ou [struct](../cpp/struct-cpp.md) poderia ser implementado com essas regras, mas **interface** impõe-los.

Por exemplo, o seguinte é uma definição de interface de exemplo:

```cpp
__interface IMyInterface {
   HRESULT CommitX();
   HRESULT get_X(BSTR* pbstrName);
};
```

Para obter informações sobre as interfaces gerenciadas, consulte [classe de interface](../extensions/interface-class-cpp-component-extensions.md).

Observe que você não precisa indicar explicitamente que as funções `CommitX` e `get_X` são puramente virtuais. Uma declaração equivalente para a primeira função seria:

```cpp
virtual HRESULT CommitX() = 0;
```

**interface** implica a [novtable](../cpp/novtable.md) **declspec** modificador.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar as propriedades declaradas em uma interface.

```cpp
// deriv_interface.cpp
#define _ATL_ATTRIBUTES 1
#include <atlbase.h>
#include <atlcom.h>
#include <string.h>
#include <comdef.h>
#include <stdio.h>

[module(name="test")];

[ object, uuid("00000000-0000-0000-0000-000000000001"), library_block ]
__interface IFace {
   [ id(0) ] int int_data;
   [ id(5) ] BSTR bstr_data;
};

[ coclass, uuid("00000000-0000-0000-0000-000000000002") ]
class MyClass : public IFace {
private:
    int m_i;
    BSTR m_bstr;

public:
    MyClass()
    {
        m_i = 0;
        m_bstr = 0;
    }

    ~MyClass()
    {
        if (m_bstr)
            ::SysFreeString(m_bstr);
    }

    int get_int_data()
    {
        return m_i;
    }

    void put_int_data(int _i)
    {
        m_i = _i;
    }

    BSTR get_bstr_data()
    {
        BSTR bstr = ::SysAllocString(m_bstr);
        return bstr;
    }

    void put_bstr_data(BSTR bstr)
    {
        if (m_bstr)
            ::SysFreeString(m_bstr);
        m_bstr = ::SysAllocString(bstr);
    }
};

int main()
{
    _bstr_t bstr("Testing");
    CoInitialize(NULL);
    CComObject<MyClass>* p;
    CComObject<MyClass>::CreateInstance(&p);
    p->int_data = 100;
    printf_s("p->int_data = %d\n", p->int_data);
    p->bstr_data = bstr;
    printf_s("bstr_data = %S\n", p->bstr_data);
}
```

```Output
p->int_data = 100
bstr_data = Testing
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Atributos de interface](../windows/attributes/interface-attributes.md)