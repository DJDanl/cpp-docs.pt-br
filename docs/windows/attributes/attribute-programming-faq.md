---
title: Perguntas frequentes de programação do atributo
ms.date: 10/02/2018
ms.topic: conceptual
helpviewer_keywords:
- attributed programming
- attributes [C++/CLI], frequently asked questions
- FAQs (frequently asked questions), attributed programming [C++]
ms.assetid: a1b8349f-7f51-43c4-95ea-4edb6e5f243f
ms.openlocfilehash: 4191704da2fdac849ac1ce97692c2421ba7cda41
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168377"
---
# <a name="attribute-programming-faq"></a>Perguntas frequentes de programação do atributo

Este tópico responde às seguintes perguntas frequentes:

- [O que é um HRESULT?](#vcconattributeprogrammmingfaqanchor1)

- [Quando é necessário especificar o nome do parâmetro para um atributo?](#vcconattributeprogrammmingfaqanchor2)

- [Posso usar comentários em um bloco de atributos?](#vcconattributeprogrammmingfaqanchor3)

- [Como os atributos interagem com a herança?](#vcconattributeprogrammmingfaqanchor4)

- [Como posso usar atributos em um projeto ATL não atributo?](#vcconattributeprogrammmingfaqanchor5)

- [Como posso usar um arquivo. idl em um projeto atribuído?](#vcconattributeprogrammmingfaqanchor6)

- [Posso modificar o código injetado por um atributo?](#vcconattributeprogrammmingfaqanchor7)

- [Como posso encaminhar a declaração de uma interface atribuída?](#vcconattributeprogrammmingfaqhowcaniforwarddeclareanattributedinterface)

- [Posso usar atributos em uma classe derivada de uma classe que também usa atributos?](#vcconcaniuseattributesonclassderivedfromclassthatalsousesattributesanchor)

##  <a name="what-is-an-hresult"></a><a name="vcconattributeprogrammmingfaqanchor1"></a>O que é um HRESULT?

Um HRESULT é um tipo de dados simples que geralmente é usado como um valor de retorno por atributos e ATL em geral. A tabela a seguir descreve os vários valores. Mais valores estão contidos no arquivo de cabeçalho Winerror. h.

|Nome|DESCRIÇÃO|Valor|
|----------|-----------------|-----------|
|S_OK|Operação concluída com êxito|0x00000000|
|E_UNEXPECTED|Falha inesperada|0x8000FFFF|
|{1&gt;E_NOTIMPL&lt;1}|Não implementado|0x80004001|
|E_OUTOFMEMORY|Falha ao alocar a memória necessária|0x8007000E|
|E_INVALIDARG|Um ou mais argumentos são inválidos|0x80070057|
|{1&gt;E_NOINTERFACE&lt;1}|Nenhuma interface desse tipo é suportada|0x80004002|
|{1&gt;E_POINTER&lt;1}|Ponteiro inválido|0x80004003|
|E_HANDLE|Identificador inválido|0x80070006|
|{1&gt;E_ABORT&lt;1}|Operação anulada|0x80004004|
|E_FAIL|Falha não especificada|0x80004005|
|E_ACCESSDENIED|Erro geral de acesso negado|0x80070005|

##  <a name="when-do-i-have-to-specify-the-parameter-name-for-an-attribute"></a><a name="vcconattributeprogrammmingfaqanchor2"></a>Quando é necessário especificar o nome do parâmetro para um atributo?

Na maioria dos casos, se o atributo tiver um único parâmetro, esse parâmetro será nomeado. Esse nome não é necessário ao inserir o atributo em seu código. Por exemplo, o seguinte uso do atributo [agregável](aggregatable.md) :

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

No entanto, os seguintes atributos têm parâmetros únicos e não nomeados:

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
|[size_is](size-is.md)|[origem](source-cpp.md)|[switch_is](switch-is.md)|
|[switch_type](switch-type.md)|[transmit_as](transmit-as.md)|[wire_marshal](wire-marshal.md)|

##  <a name="can-i-use-comments-in-an-attribute-block"></a><a name="vcconattributeprogrammmingfaqanchor3"></a>Posso usar comentários em um bloco de atributos?

Você pode usar comentários de linha única e de várias linhas em um bloco de atributo. No entanto, você não pode usar o estilo de comentário dentro dos parênteses que contêm os parâmetros para um atributo.

O seguinte é permitido:

```cpp
[ coclass, progid("MyClass.CMyClass.1"), /* Multiple-line
                                       comment */
   threading("both") // Single-line comment
]
```

O seguinte não é permitido:

```cpp
[ coclass, progid("MyClass.CMyClass.1" /* Multiple-line comment */ ), threading("both" // Single-line comment)
]
```

##  <a name="how-do-attributes-interact-with-inheritance"></a><a name="vcconattributeprogrammmingfaqanchor4"></a>Como os atributos interagem com a herança?

Você pode herdar as classes atribuídas e não atributos de outras classes, que podem ser atribuídas ou não. O resultado da derivação de uma classe atribuída é o mesmo que derivar dessa classe depois que o provedor de atributos tiver transformado seu código. Os atributos não são transmitidos para classes C++ derivadas por meio de herança. Um provedor de atributos transforma apenas o código na vizinhança de seus atributos.

##  <a name="how-can-i-use-attributes-in-a-nonattributed-atl-project"></a><a name="vcconattributeprogrammmingfaqanchor5"></a>Como posso usar atributos em um projeto ATL não atributo?

Você pode ter um projeto ATL não atributo, que tem um arquivo. idl, e convém começar a adicionar objetos atribuídos. Nesse caso, use o **Assistente para adicionar classe** para fornecer o código.

##  <a name="how-can-i-use-an-idl-file-in-an-attributed-project"></a><a name="vcconattributeprogrammmingfaqanchor6"></a>Como posso usar um arquivo. idl em um projeto atribuído?

Você pode ter um arquivo. idl que deseja usar em seu projeto do ATL atribuído. Nesse caso, você usaria o atributo [importidl](importidl.md) , compilará o arquivo. idl em um arquivo. h (consulte as [páginas de propriedades MIDL](../../build/reference/midl-property-pages.md) na caixa de diálogo **páginas de propriedades** do projeto) e, em seguida, incluirá o arquivo. h em seu projeto.

##  <a name="can-i-modify-code-that-is-injected-by-an-attribute"></a><a name="vcconattributeprogrammmingfaqanchor7"></a>Posso modificar o código injetado por um atributo?

Alguns atributos injetam código em seu projeto. Você pode ver o código injetado usando a opção de compilador [/FX](../../build/reference/fx-merge-injected-code.md) . Também é possível copiar o código do arquivo injetado e colá-lo no código-fonte. Isso permite que você modifique o comportamento do atributo. No entanto, talvez você precise modificar outras partes do seu código também.

O exemplo a seguir é o resultado da cópia de código injetado em um arquivo de código-fonte:

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

##  <a name="how-can-i-forward-declare-an-attributed-interface"></a><a name="vcconattributeprogrammmingfaqhowcaniforwarddeclareanattributedinterface"></a>Como posso encaminhar a declaração de uma interface atribuída?

Se você for fazer uma declaração de encaminhamento de uma interface atribuída, deverá aplicar os mesmos atributos à declaração de encaminhamento que você aplica à declaração de interface real. Você também deve aplicar o atributo [Exportar](export.md) à sua declaração de encaminhamento.

##  <a name="can-i-use-attributes-on-a-class-derived-from-a-class-that-also-uses-attributes"></a><a name="vcconcaniuseattributesonclassderivedfromclassthatalsousesattributesanchor"></a>Posso usar atributos em uma classe derivada de uma classe que também usa atributos?

Não, não há suporte para o uso de atributos em uma classe derivada de uma classe que também usa atributos.

## <a name="see-also"></a>Confira também

[Atributos C++ para COM e .NET](cpp-attributes-com-net.md)
