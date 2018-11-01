---
title: Perguntas frequentes de programação do atributo
ms.date: 10/02/2018
ms.topic: conceptual
helpviewer_keywords:
- attributed programming
- attributes [C++/CLI], frequently asked questions
- FAQs (frequently asked questions), attributed programming [C++]
ms.assetid: a1b8349f-7f51-43c4-95ea-4edb6e5f243f
ms.openlocfilehash: b273ad71c3c6eaed69fc715401219200f26f87eb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50434977"
---
# <a name="attribute-programming-faq"></a>Perguntas frequentes de programação do atributo

Este tópico responde a perguntas frequentes a seguir:

- [O que é um HRESULT?](#vcconattributeprogrammmingfaqanchor1)

- [Quando é necessário especificar o nome do parâmetro para um atributo?](#vcconattributeprogrammmingfaqanchor2)

- [Pode usar comentários em um bloco de atributo?](#vcconattributeprogrammmingfaqanchor3)

- [Como os atributos interagem com a herança?](#vcconattributeprogrammmingfaqanchor4)

- [Como usar atributos em um projeto ATL nonattributed?](#vcconattributeprogrammmingfaqanchor5)

- [Como usar um arquivo. idl em um projeto atribuído?](#vcconattributeprogrammmingfaqanchor6)

- [Posso modificar o código que é injetado por um atributo?](#vcconattributeprogrammmingfaqanchor7)

- [Como posso encaminhar declarar uma interface atribuída?](#vcconattributeprogrammmingfaqhowcaniforwarddeclareanattributedinterface)

- [Pode usar atributos em uma classe derivada de uma classe que também usa atributos?](#vcconcaniuseattributesonclassderivedfromclassthatalsousesattributesanchor)

##  <a name="vcconattributeprogrammmingfaqanchor1"></a> O que é um HRESULT?

Um HRESULT é um tipo de dados simples que geralmente é usado como um valor de retorno, atributos e ATL em geral. A tabela a seguir descreve os vários valores. Mais valores contidos no arquivo de cabeçalho Winerror. h.

|Nome|Descrição|Valor|
|----------|-----------------|-----------|
|S_OK|Operação concluída com êxito|0x00000000|
|E_UNEXPECTED|Falha inesperada|0x8000FFFF|
|E_NOTIMPL|Não implementado|0x80004001|
|E_OUTOFMEMORY|Falha ao alocar memória necessária|0x8007000E|
|E_INVALIDARG|Um ou mais argumentos são inválidos|0x80070057|
|E_NOINTERFACE|Nenhuma interface deste tipo com suporte|0x80004002|
|E_POINTER|Ponteiro inválido|0x80004003|
|E_HANDLE|Identificador inválido|0x80070006|
|E_ABORT|Operação anulada|0x80004004|
|E_FAIL|Falha não especificada|0x80004005|
|E_ACCESSDENIED|Geral erro acesso negado|0x80070005|

##  <a name="vcconattributeprogrammmingfaqanchor2"></a> Quando é necessário especificar o nome do parâmetro para um atributo?

Na maioria dos casos, se o atributo tem um único parâmetro, esse parâmetro é chamado. Esse nome não é necessário quando a inserção do atributo em seu código. Por exemplo, o seguinte uso do [agregável](aggregatable.md) atributo:

```cpp
[coclass, aggregatable(value=allowed)]
class CMyClass
{
// The class declaration
};
```

é exatamente o mesmo que:

```cpp
[coclass, aggregatable(allowed)]
class CMyClass
{
// The class declaration
};
```

No entanto, os seguintes atributos têm parâmetros sem nomeados, únicos:

||||
|-|-|-|
|[call_as](call-as.md)|[case](case-cpp.md)|[cpp_quote](cpp-quote.md)|
|[default](default-cpp.md)|[defaultvalue](defaultvalue.md)|[defaultvtable](defaultvtable.md)|
|[emitidl](emitidl.md)|[entry](entry.md)|[first_is](first-is.md)|
|[helpcontext](helpcontext.md)|[helpfile](helpfile.md)|[helpstring](helpstring.md)|
|[helpstringcontext](helpstringcontext.md)|[helpstringdll](helpstringdll.md)|[id](id.md)|
|[iid_is](iid-is.md)|[import](import.md)|[importlib](importlib.md)|
|[include](include-cpp.md)|[includelib](includelib-cpp.md)|[last_is](last-is.md)|
|[length_is](length-is.md)|[max_is](max-is.md)|[no_injected_text](no-injected-text.md)|
|[pointer_default](pointer-default.md)|[pragma](pragma.md)|[restricted](restricted.md)|
|[size_is](size-is.md)|[source](source-cpp.md)|[switch_is](switch-is.md)|
|[switch_type](switch-type.md)|[transmit_as](transmit-as.md)|[wire_marshal](wire-marshal.md)|

##  <a name="vcconattributeprogrammmingfaqanchor3"></a> Pode usar comentários em um bloco de atributo?

Você pode usar os comentários de linha única e várias linhas dentro de um bloco de atributo. No entanto, é possível usar qualquer um dos estilos de comentário entre parênteses que contém os parâmetros para um atributo.

O seguinte é permitido:

```cpp
[ coclass, progid("MyClass.CMyClass.1"), /* Multiple-line
                                       comment */
   threading("both") // Single-line comment
]
```

O exemplo a seguir não é permitida:

```cpp
[ coclass, progid("MyClass.CMyClass.1" /* Multiple-line comment */ ), threading("both" // Single-line comment)
]
```

##  <a name="vcconattributeprogrammmingfaqanchor4"></a> Como os atributos interagem com a herança?

Você pode herdar classes atribuídas e não atribuídas de outras classes, que podem se ser atribuídos ou não. O resultado de derivar de uma classe atribuída é o mesmo que derivar dessa classe depois que o provedor de atributo transformou seu código. Atributos não são transmitidos para derivado classes por meio da herança do C++. Um provedor de atributo apenas transforma o código de perto seus atributos.

##  <a name="vcconattributeprogrammmingfaqanchor5"></a> Como usar atributos em um projeto ATL nonattributed?

Você pode ter um projeto ATL nonattributed, que tem um arquivo. idl, e talvez você queira começar a adicionar objetos atribuídos. Nesse caso, use o **Assistente para adição de classe** para fornecer o código.

##  <a name="vcconattributeprogrammmingfaqanchor6"></a> Como usar um arquivo. idl em um projeto atribuído?

Você pode ter um arquivo. IDL que você deseja usar em seu projeto ATL atribuído. Nesse caso, você usaria o [importidl](importidl.md) atributo, compile o arquivo. IDL para um arquivo. h (consulte a [páginas de propriedade MIDL](../../ide/midl-property-pages.md) do projeto **páginas de propriedade** caixa de diálogo), e em seguida, inclua o arquivo. h em seu projeto.

##  <a name="vcconattributeprogrammmingfaqanchor7"></a> Posso modificar o código que é injetado por um atributo?

Alguns atributos injetam o código em seu projeto. Você pode ver o código injetado usando o [/Fx](../../build/reference/fx-merge-injected-code.md) opção de compilador. Também é possível copiar o código do arquivo injetado e cole-a no seu código-fonte. Isso permite que você modificar o comportamento do atributo. No entanto, talvez você precise modificar outras partes do seu código também.

O exemplo a seguir é o resultado de copiar o código injetado em um arquivo de código-fonte:

```cpp
// attr_injected.cpp
// compile with: comsupp.lib
#define _ATL_ATTRIBUTES 1
#include <atlbase.h>
#include <atlcom.h>

[ module(name="MyLibrary") ];

// ITestTest
[
   object, uuid("DADECE00-0FD2-46F1-BFD3-6A0579CA1BC4"), dual, helpstring("ITestTest Interface"), pointer_default(unique)
]

__interface ITestTest : IDispatch {
   [id(1), helpstring("method DoTest")]
   HRESULT DoTest([in] BSTR str);
};

// _ITestTestEvents
[
   uuid("12753B9F-DEF4-49b0-9D52-A79C371F2909"), dispinterface, helpstring("_ITestTestEvents Interface")
]

__interface _ITestTestEvents {
   [id(1), helpstring("method BeforeChange")] HRESULT BeforeChange([in] BSTR str, [in,out] VARIANT_BOOL* bCancel);
};

// CTestTest
[
   coclass, threading(apartment), vi_progid("TestATL1.TestTest"), progid("TestATL1.TestTest.1"), version(1.0), uuid("D9632007-14FA-4679-9E1C-28C9A949E784"), // this line would be commented out from original file
   // event_source("com"), // this line would be added to support injected code
   source(_ITestTestEvents), helpstring("TestTest Class")
]

class ATL_NO_VTABLE CTestTest : public ITestTest,
// the following base classes support added injected code
public IConnectionPointContainerImpl<CTestTest>,
public IConnectionPointImpl<CTestTest, &__uuidof(::_ITestTestEvents), CComDynamicUnkArray>
{
public:
   CTestTest() {
   }
   // this line would be commented out from original file
   // __event __interface _ITestTestEvents;
   DECLARE_PROTECT_FINAL_CONSTRUCT()
   HRESULT FinalConstruct() {
      return S_OK;
   }

void FinalRelease() {}

public:
   CComBSTR m_value;
   STDMETHOD(DoTest)(BSTR str) {
      VARIANT_BOOL bCancel = FALSE;
      BeforeChange(str,&bCancel);
      if (bCancel) {
          return Error("Error : Someone don't want us to change the value");
      }

   m_value =str;
   return S_OK;
    }
// the following was copied in from the injected code.
HRESULT BeforeChange(::BSTR i1,::VARIANT_BOOL* i2) {
   HRESULT hr = S_OK;
   IConnectionPointImpl<CTestTest, &__uuidof(_ITestTestEvents), CComDynamicUnkArray>* p = this;
   VARIANT rgvars[2];
   Lock();
   IUnknown** pp = p->m_vec.begin();
   Unlock();
   while (pp < p->m_vec.end()) {
      if (*pp != NULL) {
         IDispatch* pDispatch = (IDispatch*) *pp;
         ::VariantInit(&rgvars[1]);
         rgvars[1].vt = VT_BSTR;
         V_BSTR(&rgvars[1])= (BSTR) i1;
         ::VariantInit(&rgvars[0]);
         rgvars[0].vt = (VT_BOOL | VT_BYREF);
         V_BOOLREF(&rgvars[0])= (VARIANT_BOOL*) i2;
         DISPPARAMS disp = { rgvars, NULL, 2, 0 };
         VARIANT ret_val;
         hr = __ComInvokeEventHandler(pDispatch, 1, 1, &disp, &ret_val);
         if (FAILED(hr))
            break;
      }
      pp++;
   }
   return hr;
}

BEGIN_CONNECTION_POINT_MAP(CTestTest)
CONNECTION_POINT_ENTRY(__uuidof(::_ITestTestEvents))
END_CONNECTION_POINT_MAP()
// end added code section

// _ITestCtrlEvents Methods
public:
};

int main() {}
```

##  <a name="vcconattributeprogrammmingfaqhowcaniforwarddeclareanattributedinterface"></a> Como posso encaminhar declarar uma interface atribuída?

Se você for fazer uma declaração de encaminhamento de uma interface atribuída, você deve aplicar os mesmos atributos para a declaração de encaminhamento que você se aplicam à declaração de interface real. Você também deve aplicar a [exportar](export.md) atributo à declaração de encaminhamento.

##  <a name="vcconcaniuseattributesonclassderivedfromclassthatalsousesattributesanchor"></a> Pode usar atributos em uma classe derivada de uma classe que também usa atributos?

Não, não há suporte para usar atributos em uma classe derivada de uma classe que também usa atributos.

## <a name="see-also"></a>Consulte também

[Atributos C++ para COM e .NET](cpp-attributes-com-net.md)