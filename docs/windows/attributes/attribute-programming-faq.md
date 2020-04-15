---
title: Perguntas frequentes de programação do atributo
ms.date: 10/02/2018
ms.topic: conceptual
helpviewer_keywords:
- attributed programming
- attributes [C++/CLI], frequently asked questions
- FAQs (frequently asked questions), attributed programming [C++]
ms.assetid: a1b8349f-7f51-43c4-95ea-4edb6e5f243f
ms.openlocfilehash: 6c1762994d2cb109e86397bb0a5db1258cf33be2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376056"
---
# <a name="attribute-programming-faq"></a>Perguntas frequentes de programação do atributo

Este tópico responde às seguintes perguntas frequentes:

- [O que é um HRESULT?](#vcconattributeprogrammmingfaqanchor1)

- [Quando terei que especificar o nome do parâmetro para um atributo?](#vcconattributeprogrammmingfaqanchor2)

- [Posso usar comentários em um bloco de atributos?](#vcconattributeprogrammmingfaqanchor3)

- [Como os atributos interagem com a herança?](#vcconattributeprogrammmingfaqanchor4)

- [Como posso usar atributos em um projeto ATL não atribuído?](#vcconattributeprogrammmingfaqanchor5)

- [Como posso usar um arquivo .idl em um projeto atribuído?](#vcconattributeprogrammmingfaqanchor6)

- [Posso modificar o código que é injetado por um atributo?](#vcconattributeprogrammmingfaqanchor7)

- [Como posso encaminhar declarar uma interface atribuída?](#vcconattributeprogrammmingfaqhowcaniforwarddeclareanattributedinterface)

- [Posso usar atributos em uma classe derivada de uma classe que também usa atributos?](#vcconcaniuseattributesonclassderivedfromclassthatalsousesattributesanchor)

## <a name="what-is-an-hresult"></a><a name="vcconattributeprogrammmingfaqanchor1"></a>O que é um HRESULT?

Um HRESULT é um tipo de dados simples que é frequentemente usado como um valor de retorno por atributos e ATL em geral. A tabela a seguir descreve os vários valores. Mais valores estão contidos no arquivo de cabeçalho winerror.h.

|Nome|Descrição|Valor|
|----------|-----------------|-----------|
|S_OK|Operação concluída com êxito|0x00000000|
|E_UNEXPECTED|Falha inesperada|0x8000FFFF|
|E_NOTIMPL|Não implementado|0x80004001|
|E_OUTOFMEMORY|Falha ao alocar a memória necessária|0x8007000E|
|E_INVALIDARG|Um ou mais argumentos são inválidos|0x80070057|
|E_NOINTERFACE|Nenhuma interface suportada|0x80004002|
|E_POINTER|Ponteiro inválido|0x80004003|
|E_HANDLE|Alça inválida|0x80070006|
|E_ABORT|Operação abortada|0x80004004|
|E_FAIL|Falha não especificada|0x80004005|
|E_ACCESSDENIED|Erro negado de acesso geral|0x80070005|

## <a name="when-do-i-have-to-specify-the-parameter-name-for-an-attribute"></a><a name="vcconattributeprogrammmingfaqanchor2"></a>Quando terei que especificar o nome do parâmetro para um atributo?

Na maioria dos casos, se o atributo tiver um único parâmetro, esse parâmetro é nomeado. Este nome não é necessário ao inserir o atributo em seu código. Por exemplo, o seguinte uso do atributo [agregador:](aggregatable.md)

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
|[call_as](call-as.md)|[Caso](case-cpp.md)|[cpp_quote](cpp-quote.md)|
|[Padrão](default-cpp.md)|[Defaultvalue](defaultvalue.md)|[defaultvtable](defaultvtable.md)|
|[emitidl](emitidl.md)|[Entrada](entry.md)|[first_is](first-is.md)|
|[helpcontext](helpcontext.md)|[Helpfile](helpfile.md)|[helpstring](helpstring.md)|
|[helpstringcontext](helpstringcontext.md)|[helpstringdll](helpstringdll.md)|[id](id.md)|
|[iid_is](iid-is.md)|[Importação](import.md)|[importlib](importlib.md)|
|[Incluem](include-cpp.md)|[includelib](includelib-cpp.md)|[last_is](last-is.md)|
|[length_is](length-is.md)|[max_is](max-is.md)|[no_injected_text](no-injected-text.md)|
|[pointer_default](pointer-default.md)|[pragma](pragma.md)|[Restrito](restricted.md)|
|[size_is](size-is.md)|[Fonte](source-cpp.md)|[switch_is](switch-is.md)|
|[switch_type](switch-type.md)|[transmit_as](transmit-as.md)|[wire_marshal](wire-marshal.md)|

## <a name="can-i-use-comments-in-an-attribute-block"></a><a name="vcconattributeprogrammmingfaqanchor3"></a>Posso usar comentários em um bloco de atributos?

Você pode usar comentários de linha única e de várias linhas dentro de um bloco de atributos. No entanto, você não pode usar nenhum dos estilos de comentário dentro dos parênteses segurando os parâmetros de um atributo.

É permitido:

```cpp
[ coclass, progid("MyClass.CMyClass.1"), /* Multiple-line
                                       comment */
   threading("both") // Single-line comment
]
```

O seguinte é proibido:

```cpp
[ coclass, progid("MyClass.CMyClass.1" /* Multiple-line comment */ ), threading("both" // Single-line comment)
]
```

## <a name="how-do-attributes-interact-with-inheritance"></a><a name="vcconattributeprogrammmingfaqanchor4"></a>Como os atributos interagem com a herança?

Você pode herdar classes atribuídas e não atribuídas de outras classes, que podem ser atribuídas ou não. O resultado de derivação de uma classe atribuída é o mesmo que deriva dessa classe depois que o provedor de atributos transformou seu código. Os atributos não são transmitidos para classes derivadas através da herança C++. Um provedor de atributos só transforma código nas proximidades de seus atributos.

## <a name="how-can-i-use-attributes-in-a-nonattributed-atl-project"></a><a name="vcconattributeprogrammmingfaqanchor5"></a>Como posso usar atributos em um projeto ATL não atribuído?

Você pode ter um projeto ATL não atribuído, que tem um arquivo .idl, e você pode querer começar a adicionar objetos atribuídos. Neste caso, use o **Assistente adicionar classe** para fornecer o código.

## <a name="how-can-i-use-an-idl-file-in-an-attributed-project"></a><a name="vcconattributeprogrammmingfaqanchor6"></a>Como posso usar um arquivo .idl em um projeto atribuído?

Você pode ter um arquivo .idl que deseja usar em seu projeto atribuído ao ATL. Neste caso, você usaria o atributo [importidl,](importidl.md) compilaria o arquivo .idl em um arquivo .h (consulte as [páginas de propriedade MIDL](../../build/reference/midl-property-pages.md) na caixa de diálogo Páginas de **propriedade** do projeto) e, em seguida, incluiria o arquivo .h em seu projeto.

## <a name="can-i-modify-code-that-is-injected-by-an-attribute"></a><a name="vcconattributeprogrammmingfaqanchor7"></a>Posso modificar o código que é injetado por um atributo?

Alguns atributos injetam código em seu projeto. Você pode ver o código injetado usando a opção [/Fx](../../build/reference/fx-merge-injected-code.md) compilador. Também é possível copiar o código do arquivo injetado e colá-lo em seu código-fonte. Isso permite modificar o comportamento do atributo. No entanto, você pode ter que modificar outras partes do seu código também.

A seguinte amostra é o resultado da cópia do código injetado em um arquivo de código fonte:

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

## <a name="how-can-i-forward-declare-an-attributed-interface"></a><a name="vcconattributeprogrammmingfaqhowcaniforwarddeclareanattributedinterface"></a>Como posso encaminhar declarar uma interface atribuída?

Se você vai fazer uma declaração antecipada de uma interface atribuída, você deve aplicar os mesmos atributos à declaração de encaminhamento que você aplica à declaração de interface real. Você também deve aplicar o atributo [de exportação](export.md) à sua declaração de avanço.

## <a name="can-i-use-attributes-on-a-class-derived-from-a-class-that-also-uses-attributes"></a><a name="vcconcaniuseattributesonclassderivedfromclassthatalsousesattributesanchor"></a>Posso usar atributos em uma classe derivada de uma classe que também usa atributos?

Não, o uso de atributos em uma classe derivada de uma classe que também usa atributos não é suportado.

## <a name="see-also"></a>Confira também

[Atributos C++ para COM e .NET](cpp-attributes-com-net.md)
