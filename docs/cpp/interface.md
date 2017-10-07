---
title: interface | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __interface_cpp
dev_langs:
- C++
helpviewer_keywords:
- __interface keyword [C++]
ms.assetid: ca5d400b-d6d8-4ba2-89af-73f67e5ec056
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: e502574b9d55238d6f9aed33949e06db3ec6349d
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="interface"></a>__interface
**Seção específica da Microsoft**  
  
 Uma interface do Visual C++ pode ser definida da seguinte maneira:  
  
-   Ela pode herdar de zero ou mais interfaces base.  
  
-   Ela não pode herdar de uma classe base.  
  
-   Ela pode conter apenas métodos virtuais puros e públicos.  
  
-   Ela não pode conter construtores, destruidores ou operadores.  
  
-   Ela não pode conter métodos estáticos.  
  
-   Ela não pode conter membros de dados; as propriedades são permitidas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
modifier  
 __interface interface-name {interface-definition};  
```  
  
## <a name="remarks"></a>Comentários  
 C++ de [classe](../cpp/class-cpp.md) ou [struct](../cpp/struct-cpp.md) podem ser implementados com essas regras, mas `__interface` impõe-los.  
  
 Por exemplo, o seguinte é uma definição de interface de exemplo:  
  
```  
__interface IMyInterface {  
   HRESULT CommitX();  
   HRESULT get_X(BSTR* pbstrName);  
};  
```  
  
 Para obter informações sobre interfaces gerenciadas, consulte [classe de interface](../windows/interface-class-cpp-component-extensions.md).  
  
 Observe que você não precisa indicar explicitamente que as funções `CommitX` e `get_X` são puramente virtuais. Uma declaração equivalente para a primeira função seria:  
  
```  
virtual HRESULT CommitX() = 0;  
```  
  
 `__interface`indica o [novtable](../cpp/novtable.md) `__declspec` modificador.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como usar as propriedades declaradas em uma interface.  
  
```  
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
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Atributos de interface](../windows/interface-attributes.md)
