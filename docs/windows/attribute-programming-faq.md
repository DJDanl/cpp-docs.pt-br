---
title: Perguntas Frequentes de programação do atributo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- attributed programming
- attributes [C++], frequently asked questions
- FAQs (frequently asked questions), attributed programming [C++]
ms.assetid: a1b8349f-7f51-43c4-95ea-4edb6e5f243f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 35b57c8813778cf0bbf8efbfcbee8466074b87f0
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33862358"
---
# <a name="attribute-programming-faq"></a>Perguntas frequentes de programação do atributo
Este tópico responde a perguntas frequentes a seguir:  
  
-   [O que é um HRESULT?](#vcconattributeprogrammmingfaqanchor1)  
  
-   [Quando é necessário especificar o nome do parâmetro para um atributo?](#vcconattributeprogrammmingfaqanchor2)  
  
-   [Pode usar comentários em um bloco de atributo?](#vcconattributeprogrammmingfaqanchor3)  
  
-   [Como os atributos interagem com herança?](#vcconattributeprogrammmingfaqanchor4)  
  
-   [Como usar atributos em um projeto ATL nonattributed?](#vcconattributeprogrammmingfaqanchor5)  
  
-   [Como usar um arquivo. idl em um projeto atribuído?](#vcconattributeprogrammmingfaqanchor6)  
  
-   [Posso modificar o código que é injetado por um atributo?](#vcconattributeprogrammmingfaqanchor7)  
  
-   [Como eu declaro encaminhar uma interface atribuída?](#vcconattributeprogrammmingfaqhowcaniforwarddeclareanattributedinterface)  
  
-   [Pode usar atributos em uma classe derivada de uma classe que também usa atributos?](#vcconcaniuseattributesonclassderivedfromclassthatalsousesattributesanchor)  
  
##  <a name="vcconattributeprogrammmingfaqanchor1"></a> O que é um HRESULT?  
 Um `HRESULT` é um tipo de dados simples que geralmente é usado como um valor de retorno por atributos e ATL em geral. A tabela a seguir descreve os vários valores. Mais valores contidos no arquivo de cabeçalho Winerror. h.  
  
|Nome|Descrição|Valor|  
|----------|-----------------|-----------|  
|S_OK|Operação bem-sucedida|0x00000000|  
|E_UNEXPECTED|Falha inesperada|0x8000FFFF|  
|E_NOTIMPL|Não implementado|0x80004001|  
|E_OUTOFMEMORY|Falha ao alocar memória necessária|0x8007000E|  
|E_INVALIDARG|Um ou mais argumentos são inválidos|0x80070057|  
|E_NOINTERFACE|Não há suporte para essa interface|0x80004002|  
|E_POINTER|Ponteiro inválido|0x80004003|  
|E_HANDLE|Identificador inválido|0x80070006|  
|E_ABORT|Operação anulada|0x80004004|  
|E_FAIL|Falha não especificada|0x80004005|  
|E_ACCESSDENIED|Geral erro de acesso negado|0x80070005|  
  
##  <a name="vcconattributeprogrammmingfaqanchor2"></a> Quando é necessário especificar o nome do parâmetro para um atributo?  
 Na maioria dos casos, se o atributo tem um único parâmetro, esse parâmetro é chamado. Esse nome não é necessário ao inserir o atributo no seu código. Por exemplo, o seguinte uso do [agregável](../windows/aggregatable.md) atributo:  
  
```  
[coclass, aggregatable(value=allowed)]  
class CMyClass  
{  
// The class declaration  
};  
```  
  
 é exatamente o mesmo que:  
  
```  
[coclass, aggregatable(allowed)]  
class CMyClass  
{  
// The class declaration  
};  
```  
  
 No entanto, os seguintes atributos têm parâmetros único, sem nome:  
  
||||  
|-|-|-|  
|[call_as](../windows/call-as.md)|[case](../windows/case-cpp.md)|[cpp_quote](../windows/cpp-quote.md)|  
|[default](../windows/default-cpp.md)|[defaultvalue](../windows/defaultvalue.md)|[defaultvtable](../windows/defaultvtable.md)|  
|[emitidl](../windows/emitidl.md)|[entry](../windows/entry.md)|[first_is](../windows/first-is.md)|  
|[helpcontext](../windows/helpcontext.md)|[helpfile](../windows/helpfile.md)|[helpstring](../windows/helpstring.md)|  
|[helpstringcontext](../windows/helpstringcontext.md)|[helpstringdll](../windows/helpstringdll.md)|[id](../windows/id.md)|  
|[iid_is](../windows/iid-is.md)|[import](../windows/import.md)|[importlib](../windows/importlib.md)|  
|[include](../windows/include-cpp.md)|[includelib](../windows/includelib-cpp.md)|[last_is](../windows/last-is.md)|  
|[length_is](../windows/length-is.md)|[max_is](../windows/max-is.md)|[no_injected_text](../windows/no-injected-text.md)|  
|[pointer_default](../windows/pointer-default.md)|[pragma](../windows/pragma.md)|[restricted](../windows/restricted.md)|  
|[size_is](../windows/size-is.md)|[Código-fonte](../windows/source-cpp.md)|[switch_is](../windows/switch-is.md)|  
|[switch_type](../windows/switch-type.md)|[transmit_as](../windows/transmit-as.md)|[wire_marshal](../windows/wire-marshal.md)|  
  
##  <a name="vcconattributeprogrammmingfaqanchor3"></a> Pode usar comentários em um bloco de atributo?  
 Você pode usar comentários de linha única e de várias linhas em um bloco de atributo. No entanto, você não pode usar o estilo de comentário entre parênteses, mantendo os parâmetros para um atributo.  
  
 É permitido o seguinte:  
  
```  
[ coclass,  
   progid("MyClass.CMyClass.1"), /* Multiple-line  
                                       comment */  
   threading("both") // Single-line comment  
]  
```  
  
 O exemplo a seguir não é permitido:  
  
```  
[ coclass,  
   progid("MyClass.CMyClass.1" /* Multiple-line comment */ ),  
   threading("both" // Single-line comment)  
]  
```  
  
##  <a name="vcconattributeprogrammmingfaqanchor4"></a> Como os atributos interagem com herança?  
 Você pode herdar classes atribuídos e unattributed de outras classes, que podem se atribuído, ou não. O resultado de derivar de uma classe atribuída é igual a derivação de classe depois que o provedor de atributo transformou seu código. Atributos não são transmitidos para derivado classes por meio da herança de C++. Um provedor de atributo apenas transforma código perto seus atributos.  
  
##  <a name="vcconattributeprogrammmingfaqanchor5"></a> Como usar atributos em um projeto ATL nonattributed?  
 Você pode ter um projeto ATL nonattributed, que tem um arquivo. idl, e talvez você queira começar a adicionar objetos atribuídos. Nesse caso, use o Assistente para Adicionar classe de fornecer o código.  
  
##  <a name="vcconattributeprogrammmingfaqanchor6"></a> Como usar um arquivo. idl em um projeto atribuído?  
 Você pode ter um arquivo. IDL que você deseja usar em seu projeto ATL atribuído. Nesse caso, você usaria o [importidl](../windows/importidl.md) atributo, compile o arquivo IDL para um arquivo. h (consulte o [páginas de propriedade MIDL](../ide/midl-property-pages.md) na caixa de diálogo páginas de propriedades do projeto) e, em seguida, inclua o arquivo. h em seu projeto .  
  
##  <a name="vcconattributeprogrammmingfaqanchor7"></a> Posso modificar o código que é injetado por um atributo?  
 Alguns atributos injetar código no seu projeto. Você pode ver o código injetado usando o [/Fx](../build/reference/fx-merge-injected-code.md) opção de compilador. Também é possível copiar o código do arquivo injetado e colá-lo em seu código-fonte. Isso permite que você modifique o comportamento do atributo. No entanto, você precisará modificar outras partes do seu código.  
  
 O exemplo a seguir é o resultado de copiar o código injetado em um arquivo de código de origem:  
  
```  
// attr_injected.cpp  
// compile with: comsupp.lib  
#define _ATL_ATTRIBUTES 1  
#include <atlbase.h>  
#include <atlcom.h>  
  
[ module(name="MyLibrary") ];  
  
// ITestTest  
[   
   object,  
   uuid("DADECE00-0FD2-46F1-BFD3-6A0579CA1BC4"),  
   dual,  
   helpstring("ITestTest Interface"),  
   pointer_default(unique)  
]  
  
__interface ITestTest : IDispatch {  
   [id(1), helpstring("method DoTest")]   
   HRESULT DoTest([in] BSTR str);  
};  
  
// _ITestTestEvents  
[  
   uuid("12753B9F-DEF4-49b0-9D52-A79C371F2909"),  
   dispinterface,  
   helpstring("_ITestTestEvents Interface")  
]  
  
__interface _ITestTestEvents {  
   [id(1), helpstring("method BeforeChange")] HRESULT BeforeChange([in] BSTR str, [in,out] VARIANT_BOOL* bCancel);  
};  
  
// CTestTest  
[  
   coclass,  
   threading(apartment),  
   vi_progid("TestATL1.TestTest"),  
   progid("TestATL1.TestTest.1"),  
   version(1.0),  
   uuid("D9632007-14FA-4679-9E1C-28C9A949E784"),  
   // this line would be commented out from original file  
   // event_source("com"),  
   // this line would be added to support injected code  
   source(_ITestTestEvents),  
   helpstring("TestTest Class")  
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
  
##  <a name="vcconattributeprogrammmingfaqhowcaniforwarddeclareanattributedinterface"></a> Como eu declaro encaminhar uma interface atribuída?  
 Se você pretende fazer uma declaração de encaminhamento de uma interface atribuída, você deve aplicar os mesmos atributos para a declaração de encaminhamento que você aplicar a declaração da interface real. Você também deve aplicar o [exportar](../windows/export.md) a declaração de encaminhamento de atributo.  
  
##  <a name="vcconcaniuseattributesonclassderivedfromclassthatalsousesattributesanchor"></a> Pode usar atributos em uma classe derivada de uma classe que também usa atributos?  
 Não, não há suporte para usando atributos em uma classe derivada de uma classe que também usa atributos.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../windows/attributed-programming-concepts.md)