---
title: Classe com::ptr
ms.date: 01/16/2019
ms.topic: reference
f1_keywords:
- msclr::com::ptr::ptr
- msclr::com::ptr::Attach
- msclr::com::ptr::CreateInstance
- msclr::com::ptr::Detach
- msclr::com::ptr::GetInterface
- msclr::com::ptr::QueryInterface
- msclr::com::ptr::Release
- msclr::com::ptr::operator=
- msclr::com::ptr::operator->
- msclr::com::ptr::operator!
helpviewer_keywords:
- msclr::ptr class
ms.assetid: 0144d0e4-919c-45f9-a3f8-fbc9edba32bf
ms.openlocfilehash: 9cb0ad23450d06bb314b0e2d6fa1d01784d633e2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214900"
---
# <a name="comptr-class"></a>Classe com::ptr

Um wrapper para um objeto COM que pode ser usado como um membro de uma classe CLR.  O wrapper também automatiza o gerenciamento de tempo de vida do objeto COM, liberando todas as referências de propriedade no objeto quando seu destruidor é chamado. Análogo à [Classe CComPtr](../atl/reference/ccomptr-class.md).

## <a name="syntax"></a>Sintaxe

```
template<class _interface_type>
ref class ptr;
```

### <a name="parameters"></a>parâmetros

*_interface_type*<br/>
Interface COM.

## <a name="remarks"></a>Comentários

Um `com::ptr` também pode ser usado como uma variável de função local para simplificar várias tarefas com e automatizar o gerenciamento de tempo de vida.

Um `com::ptr` não pode ser usado diretamente como um parâmetro de função; use um [operador de referência de rastreamento](../extensions/tracking-reference-operator-cpp-component-extensions.md) ou um [identificador para o operador de objeto (^)](../extensions/handle-to-object-operator-hat-cpp-component-extensions.md) em vez disso.

Um `com::ptr` não pode ser retornado diretamente de uma função; use um identificador em vez disso.

## <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` para encapsular seu objeto de membro privado `IXMLDOMDocument` .  Chamar os métodos públicos da classe resulta em chamadas para o objeto contido `IXMLDOMDocument` .  O exemplo cria uma instância de um documento XML, preenche-o com um XML simples e faz uma movimentação simplificada dos nós na árvore de documentos analisados para imprimir o XML no console.

```cpp
// comptr.cpp
// compile with: /clr /link msxml2.lib
#include <msxml2.h>
#include <msclr\com\ptr.h>

#import <msxml3.dll> raw_interfaces_only

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr;

// a ref class that uses a com::ptr to contain an
// IXMLDOMDocument object
ref class XmlDocument {
public:
   // construct the internal com::ptr with a null interface
   // and use CreateInstance to fill it
   XmlDocument(String^ progid) {
      m_ptrDoc.CreateInstance(progid);
   }

   void LoadXml(String^ xml) {
      pin_ptr<const wchar_t> pinnedXml = PtrToStringChars(xml);
      BSTR bstr = NULL;

      try {
         // load some XML into the document
         bstr = ::SysAllocString(pinnedXml);
         if (NULL == bstr) {
            throw gcnew OutOfMemoryException;
         }
         VARIANT_BOOL bIsSuccessful = false;
         // use operator -> to call IXMODOMDocument member function
         Marshal::ThrowExceptionForHR(m_ptrDoc->loadXML(bstr, &bIsSuccessful));
      }
      finally {
         ::SysFreeString(bstr);
      }
   }

   // simplified function to write just the first xml node to the console
   void WriteXml() {
      IXMLDOMNode* pNode = NULL;

      try {
         // the first child of the document is the first real xml node
         Marshal::ThrowExceptionForHR(m_ptrDoc->get_firstChild(&pNode));
         if (NULL != pNode) {
            WriteNode(pNode);
         }
      }
      finally {
         if (NULL != pNode) {
            pNode->Release();
         }
      }
   }

   // note that the destructor will call the com::ptr destructor
   // and automatically release the reference to the COM object

private:
   // simplified function that only writes the node
   void WriteNode(IXMLDOMNode* pNode) {
      BSTR bstr = NULL;

      try {
         // write out the name and text properties
         Marshal::ThrowExceptionForHR(pNode->get_nodeName(&bstr));
         String^ strName = gcnew String(bstr);
         Console::Write("<{0}>", strName);
         ::SysFreeString(bstr);
         bstr = NULL;

         Marshal::ThrowExceptionForHR(pNode->get_text(&bstr));
         Console::Write(gcnew String(bstr));
         ::SysFreeString(bstr);
         bstr = NULL;

         Console::WriteLine("</{0}>", strName);
      }
      finally {
         ::SysFreeString(bstr);
      }
   }

   com::ptr<IXMLDOMDocument> m_ptrDoc;
};

// use the ref class to handle an XML DOM Document object
int main() {
   try {
      // create the class from a progid string
      XmlDocument doc("Msxml2.DOMDocument.3.0");

      // stream some xml into the document
      doc.LoadXml("<word>persnickety</word>");

      // write the document to the console
      doc.WriteXml();
   }
   catch (Exception^ e) {
      Console::WriteLine(e);
   }
}
```

```Output
<word>persnickety</word>
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|---------|-----------|
|[PTR::p TR](#ptr)|Constrói um `com::ptr` para encapsular um objeto com.|
|[ptr::~ptr](#tilde-ptr)|Destrui um `com::ptr` .|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|---------|-----------|
|[ptr::Attach](#attach)|Anexa um objeto COM a um `com::ptr` .|
|[ptr::CreateInstance](#createInstance)|Cria uma instância de um objeto COM dentro de um `com::ptr` .|
|[ptr::Detach](#detach)|Fornece a propriedade do objeto COM, retornando um ponteiro para o objeto.|
|[ptr::GetInterface](#getInterface)|Cria uma instância de um objeto COM dentro de um `com::ptr` .|
|[ptr::QueryInterface](#queryInterface)|Consulta o objeto COM de propriedade de uma interface e anexa o resultado a outro `com::ptr` .|
|[ptr::Release](#release)|Libera Todas as referências de propriedade no objeto COM.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|---------|-----------|
|[operador:: Operator-&gt;](#operator-arrow)|Operador de acesso de membro, usado para chamar métodos no objeto COM de propriedade.|
|[PTR:: Operator =](#operator-assign)|Anexa um objeto COM a um `com::ptr` .|
|[operador PTR:: Operator &nbsp;](#operator-bool)|Operador para usar `com::ptr` em uma expressão condicional.|
|[ptr::operator!](#operator-logical-not)|Para determinar se o objeto COM pertencente é inválido.|

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho** \<msclr\com\ptr.h>

**Namespace** msclr:: com

## <a name="ptrptr"></a><a name="ptr"></a>PTR::p TR

Retorna um ponteiro para o objeto COM de propriedade.

```cpp
ptr();
ptr(
   _interface_type * p
);
```

### <a name="parameters"></a>parâmetros

*P*<br/>
Um ponteiro de interface COM.

### <a name="remarks"></a>Comentários

O Construtor no-Argument é atribuído **`nullptr`** ao identificador de objeto subjacente. Chamadas futuras para o `com::ptr` validarão o objeto interno e falharão silenciosamente até que um objeto seja criado ou anexado.

O construtor de um argumento adiciona uma referência ao objeto COM, mas não libera a referência do chamador, de modo que o chamador deve chamar `Release` no objeto com para realmente fornecer controle. Quando o `com::ptr` destruidor for chamado, ele lançará automaticamente suas referências no objeto com.

Passar `NULL` para esse construtor é o mesmo que chamar a versão no-Argument.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` para encapsular seu objeto de membro privado `IXMLDOMDocument` . Ele demonstra o uso de ambas as versões do construtor.

```cpp
// comptr_ptr.cpp
// compile with: /clr /link msxml2.lib
#include <msxml2.h>
#include <msclr\com\ptr.h>

#import <msxml3.dll> raw_interfaces_only

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr;

// a ref class that uses a com::ptr to contain an
// IXMLDOMDocument object
ref class XmlDocument {
public:
   // construct the internal com::ptr with a null interface
   // and use CreateInstance to fill it
   XmlDocument(String^ progid) {
      m_ptrDoc.CreateInstance(progid);
   }

   // construct the internal com::ptr with a COM object
   XmlDocument(IXMLDOMDocument* pDoc) : m_ptrDoc(pDoc) {}

   // note that the destructor will call the com::ptr destructor
   // and automatically release the reference to the COM object

private:
   com::ptr<IXMLDOMDocument> m_ptrDoc;
};

// use the ref class to handle an XML DOM Document object
int main() {
   IXMLDOMDocument* pDoc = NULL;

   try {
      // create an XML DOM document object
      Marshal::ThrowExceptionForHR(CoCreateInstance(CLSID_DOMDocument30, NULL,
         CLSCTX_ALL, IID_IXMLDOMDocument, (void**)&pDoc));
      // construct the ref class with the COM object
      XmlDocument doc1(pDoc);

      // or create the class from a progid string
      XmlDocument doc2("Msxml2.DOMDocument.3.0");
   }
   // doc1 and doc2 destructors are called when they go out of scope
   // and the internal com::ptr releases its reference to the COM object
   catch (Exception^ e) {
      Console::WriteLine(e);
   }
   finally {
      if (NULL != pDoc) {
         pDoc->Release();
      }
   }
}
```

## <a name="ptrptr"></a><a name="tilde-ptr"></a>PTR:: ~ ptr

Destrui um `com::ptr` .

```cpp
~ptr();
```

### <a name="remarks"></a>Comentários

Na destruição, o `com::ptr` libera Todas as referências que ela possui ao seu objeto com. Supondo que não haja nenhuma outra referência mantida ao objeto COM, o objeto COM será excluído e sua memória liberada.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` para encapsular seu objeto de membro privado `IXMLDOMDocument` .  Na `main` função, os `XmlDocument` destruidores de dois objetos serão chamados quando eles ficarem fora do escopo do **`try`** bloco, resultando no `com::ptr` destruidor subjacente que está sendo chamado, liberando todas as referências de propriedade ao objeto com.

```cpp
// comptr_dtor.cpp
// compile with: /clr /link msxml2.lib
#include <msxml2.h>
#include <msclr\com\ptr.h>

#import <msxml3.dll> raw_interfaces_only

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr;

// a ref class that uses a com::ptr to contain an
// IXMLDOMDocument object
ref class XmlDocument {
public:
   // construct the internal com::ptr with a null interface
   // and use CreateInstance to fill it
   XmlDocument(String^ progid) {
      m_ptrDoc.CreateInstance(progid);
   }

   // construct the internal com::ptr with a COM object
   XmlDocument(IXMLDOMDocument* pDoc) : m_ptrDoc(pDoc) {}

   // note that the destructor will call the com::ptr destructor
   // and automatically release the reference to the COM object

private:
   com::ptr<IXMLDOMDocument> m_ptrDoc;
};

// use the ref class to handle an XML DOM Document object
int main() {
   IXMLDOMDocument* pDoc = NULL;

   try {
      // create an XML DOM document object
      Marshal::ThrowExceptionForHR(CoCreateInstance(CLSID_DOMDocument30, NULL,
         CLSCTX_ALL, IID_IXMLDOMDocument, (void**)&pDoc));
      // construct the ref class with the COM object
      XmlDocument doc1(pDoc);

      // or create the class from a progid string
      XmlDocument doc2("Msxml2.DOMDocument.3.0");
   }
   // doc1 and doc2 destructors are called when they go out of scope
   // and the internal com::ptr releases its reference to the COM object
   catch (Exception^ e) {
      Console::WriteLine(e);
   }
   finally {
      if (NULL != pDoc) {
         pDoc->Release();
      }
   }
}
```

## <a name="ptrattach"></a><a name="attach"></a>PTR:: anexar

Anexa um objeto COM a um `com::ptr` .

```cpp
void Attach(
   _interface_type * _right
);
```

### <a name="parameters"></a>parâmetros

*_right*<br/>
O ponteiro de interface COM a ser anexado.

### <a name="exceptions"></a>Exceções

Se o `com::ptr` já possuir uma referência a um objeto com, o `Attach` lançará <xref:System.InvalidOperationException> .

### <a name="remarks"></a>Comentários

Uma chamada para `Attach` referencia o objeto com, mas não libera a referência do chamador a ele.

Passando `NULL` para `Attach` resultados em nenhuma ação executada.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` para encapsular seu objeto de membro privado `IXMLDOMDocument` . A `ReplaceDocument` função de membro primeiro chama `Release` qualquer objeto anteriormente e, em seguida, chama `Attach` para anexar um novo objeto de documento.

```cpp
// comptr_attach.cpp
// compile with: /clr /link msxml2.lib
#include <msxml2.h>
#include <msclr\com\ptr.h>

#import <msxml3.dll> raw_interfaces_only

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr;

// a ref class that uses a com::ptr to contain an
// IXMLDOMDocument object
ref class XmlDocument {
public:
   // construct the internal com::ptr with a null interface
   // and use CreateInstance to fill it
   XmlDocument(String^ progid) {
      m_ptrDoc.CreateInstance(progid);
   }

   // replace currently held COM object with another one
   void ReplaceDocument(IXMLDOMDocument* pDoc) {
      // release current document object
      m_ptrDoc.Release();
      // attach the new document object
      m_ptrDoc.Attach(pDoc);
   }

   // note that the destructor will call the com::ptr destructor
   // and automatically release the reference to the COM object

private:
   com::ptr<IXMLDOMDocument> m_ptrDoc;
};

// unmanaged function that creates a raw XML DOM Document object
IXMLDOMDocument* CreateDocument() {
   IXMLDOMDocument* pDoc = NULL;
   Marshal::ThrowExceptionForHR(CoCreateInstance(CLSID_DOMDocument30, NULL,
      CLSCTX_INPROC_SERVER, IID_IXMLDOMDocument, (void**)&pDoc));
   return pDoc;
}

// use the ref class to handle an XML DOM Document object
int main() {
   IXMLDOMDocument* pDoc = NULL;

   try {
      // create the class from a progid string
      XmlDocument doc("Msxml2.DOMDocument.3.0");

      // get another document object from unmanaged function and
      // store it in place of the one held by our ref class
      pDoc = CreateDocument();
      doc.ReplaceDocument(pDoc);
      // no further need for raw object reference
      pDoc->Release();
      pDoc = NULL;
   }
   catch (Exception^ e) {
      Console::WriteLine(e);
   }
   finally {
      if (NULL != pDoc) {
         pDoc->Release();
      }
   }
}
```

## <a name="ptrcreateinstance"></a><a name="createInstance"></a>PTR:: CreateInstance

Cria uma instância de um objeto COM dentro de um `com::ptr` .

```cpp
void CreateInstance(
   System::String ^ progid,
   LPUNKNOWN pouter,
   DWORD cls_context
);
void CreateInstance(
   System::String ^ progid,
   LPUNKNOWN pouter
);
void CreateInstance(
   System::String ^ progid
);
void CreateInstance(
   const wchar_t * progid,
   LPUNKNOWN pouter,
   DWORD cls_context
);
void CreateInstance(
   const wchar_t * progid,
   LPUNKNOWN pouter
);
void CreateInstance(
   const wchar_t * progid
);
void CreateInstance(
   REFCLSID rclsid,
   LPUNKNOWN pouter,
   DWORD cls_context
);
void CreateInstance(
   REFCLSID rclsid,
   LPUNKNOWN pouter
);
void CreateInstance(
   REFCLSID rclsid
);
```

### <a name="parameters"></a>parâmetros

*ProgID*<br/>
Uma cadeia de caracteres `ProgID`.

*pouter*<br/>
Ponteiro para a interface IUnknown do objeto de agregação (o IUnknown de controle). Se `pouter` não for especificado, `NULL` será usado.

*cls_context*<br/>
Contexto no qual o código que gerencia o objeto recém-criado será executado. Os valores são obtidos da `CLSCTX` enumeração. Se `cls_context` não for especificado, o valor CLSCTX_ALL será usado.

*rclsid*<br/>
`CLSID`associados aos dados e ao código que serão usados para criar o objeto.

### <a name="exceptions"></a>Exceções

Se o `com::ptr` já possuir uma referência a um objeto com, o `CreateInstance` lançará <xref:System.InvalidOperationException> .

Essa função chama `CoCreateInstance` e usa <xref:System.Runtime.InteropServices.Marshal.ThrowExceptionForHR%2A> para converter qualquer erro `HRESULT` em uma exceção apropriada.

### <a name="remarks"></a>Comentários

`CreateInstance`usa `CoCreateInstance` para criar uma nova instância do objeto especificado, identificada a partir de um ProgID ou um CLSID. O `com::ptr` faz referência ao objeto recém-criado e libera automaticamente todas as referências de propriedade na destruição.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` para encapsular seu objeto de membro privado `IXMLDOMDocument` . Os construtores de classe usam duas formas diferentes de `CreateInstance` para criar o objeto de documento a partir de um ProgID ou de um CLSID mais um CLSCTX.

```cpp
// comptr_createinstance.cpp
// compile with: /clr /link msxml2.lib
#include <msxml2.h>
#include <msclr\com\ptr.h>

#import <msxml3.dll> raw_interfaces_only

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr;

// a ref class that uses a com::ptr to contain an
// IXMLDOMDocument object
ref class XmlDocument {
public:
   // construct the internal com::ptr with a null interface
   // and use CreateInstance to fill it
   XmlDocument(String^ progid) {
      m_ptrDoc.CreateInstance(progid);
   }
   XmlDocument(REFCLSID clsid, DWORD clsctx) {
      m_ptrDoc.CreateInstance(clsid, NULL, clsctx);
   }

   // note that the destructor will call the com::ptr destructor
   // and automatically release the reference to the COM object

private:
   com::ptr<IXMLDOMDocument> m_ptrDoc;
};

// use the ref class to handle an XML DOM Document object
int main() {
   try {
      // create the class from a progid string
      XmlDocument doc1("Msxml2.DOMDocument.3.0");

      // or from a clsid with specific CLSCTX
      XmlDocument doc2(CLSID_DOMDocument30, CLSCTX_INPROC_SERVER);
   }
   catch (Exception^ e) {
      Console::WriteLine(e);
   }
}
```

## <a name="ptrdetach"></a><a name="detach"></a>PTR::D Etach

Fornece a propriedade do objeto COM, retornando um ponteiro para o objeto.

```cpp
_interface_type * Detach();
```

### <a name="return-value"></a>Valor retornado

O ponteiro para o objeto COM.

Se nenhum objeto for proprietário, NULL será retornado.

### <a name="exceptions"></a>Exceções

Internamente, `QueryInterface` é chamado no objeto com de propriedade e qualquer erro `HRESULT` é convertido em uma exceção pelo <xref:System.Runtime.InteropServices.Marshal.ThrowExceptionForHR%2A> .

### <a name="remarks"></a>Comentários

`Detach`Primeiro, adiciona uma referência ao objeto COM em nome do chamador e, em seguida, libera Todas as referências pertencentes ao `com::ptr` .  O chamador deve, por fim, liberar o objeto retornado para destruí-lo.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` para encapsular seu objeto de membro privado `IXMLDOMDocument` .  A `DetachDocument` função de membro chama `Detach` para fornecer a propriedade do objeto com e retornar um ponteiro para o chamador.

```cpp
// comptr_detach.cpp
// compile with: /clr /link msxml2.lib
#include <msxml2.h>
#include <msclr\com\ptr.h>

#import <msxml3.dll> raw_interfaces_only

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr;

// a ref class that uses a com::ptr to contain an
// IXMLDOMDocument object
ref class XmlDocument {
public:
   // construct the internal com::ptr with a null interface
   // and use CreateInstance to fill it
   XmlDocument(String^ progid) {
      m_ptrDoc.CreateInstance(progid);
   }

   // detach the COM object and return it
   // this releases the internal reference to the object
   IXMLDOMDocument* DetachDocument() {
      return m_ptrDoc.Detach();
   }

   // note that the destructor will call the com::ptr destructor
   // and automatically release the reference to the COM object

private:
   com::ptr<IXMLDOMDocument> m_ptrDoc;
};

// unmanaged function that loads XML into a raw XML DOM Document object
HRESULT LoadXml(IXMLDOMDocument* pDoc, BSTR bstrXml) {
   HRESULT hr = S_OK;
   VARIANT_BOOL bSuccess;
   hr = pDoc->loadXML(bstrXml, &bSuccess);
   if (S_OK == hr && !bSuccess) {
      hr = E_FAIL;
   }
   return hr;
}

// use the ref class to handle an XML DOM Document object
int main() {
   IXMLDOMDocument* pDoc = NULL;
   BSTR bstrXml = NULL;

   try {
      // create the class from a progid string
      XmlDocument doc("Msxml2.DOMDocument.3.0");

      bstrXml = ::SysAllocString(L"<word>persnickety</word>");
      if (NULL == bstrXml) {
         throw gcnew OutOfMemoryException("bstrXml");
      }
      // detach the document object from the ref class
      pDoc = doc.DetachDocument();
      // use unmanaged function and raw object to load xml
      Marshal::ThrowExceptionForHR(LoadXml(pDoc, bstrXml));
      // release document object as the ref class no longer owns it
      pDoc->Release();
      pDoc = NULL;
   }
   catch (Exception^ e) {
      Console::WriteLine(e);
   }
   finally {
      if (NULL != pDoc) {
         pDoc->Release();
      }

   }
}
```

## <a name="ptrgetinterface"></a><a name="getInterface"></a>PTR:: GetInterface

Retorna um ponteiro para o objeto COM de propriedade.

```cpp
_interface_type * GetInterface();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto COM de propriedade.

### <a name="exceptions"></a>Exceções

Internamente, `QueryInterface` é chamado no objeto com de propriedade e qualquer erro `HRESULT` é convertido em uma exceção pelo <xref:System.Runtime.InteropServices.Marshal.ThrowExceptionForHR%2A> .

### <a name="remarks"></a>Comentários

O `com::ptr` adiciona uma referência ao objeto com em nome do chamador e também mantém sua própria referência no objeto com. O chamador deve, por fim, liberar a referência no objeto retornado ou nunca será destruído.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` para encapsular seu objeto de membro privado `IXMLDOMDocument` . A `GetDocument` função de membro usa `GetInterface` para retornar um ponteiro para o objeto com.

```cpp
// comptr_getinterface.cpp
// compile with: /clr /link msxml2.lib
#include <msxml2.h>
#include <msclr\com\ptr.h>

#import <msxml3.dll> raw_interfaces_only

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr;

// a ref class that uses a com::ptr to contain an
// IXMLDOMDocument object
ref class XmlDocument {
public:
   // construct the internal com::ptr with a null interface
   // and use CreateInstance to fill it
   XmlDocument(String^ progid) {
      m_ptrDoc.CreateInstance(progid);
   }

   // add a reference to and return the COM object
   // but keep an internal reference to the object
   IXMLDOMDocument* GetDocument() {
      return m_ptrDoc.GetInterface();
   }

   // simplified function that only writes the first node
   void WriteDocument() {
      IXMLDOMNode* pNode = NULL;
      BSTR bstr = NULL;

      try {
         // use operator -> to call XML Doc member
         Marshal::ThrowExceptionForHR(m_ptrDoc->get_firstChild(&pNode));
         if (NULL != pNode) {
            // write out the xml
            Marshal::ThrowExceptionForHR(pNode->get_nodeName(&bstr));
            String^ strName = gcnew String(bstr);
            Console::Write("<{0}>", strName);
            ::SysFreeString(bstr);
            bstr = NULL;

            Marshal::ThrowExceptionForHR(pNode->get_text(&bstr));
            Console::Write(gcnew String(bstr));
            ::SysFreeString(bstr);
            bstr = NULL;

            Console::WriteLine("</{0}>", strName);
         }
      }
      finally {
         if (NULL != pNode) {
            pNode->Release();
         }
         ::SysFreeString(bstr);
      }
   }

   // note that the destructor will call the com::ptr destructor
   // and automatically release the reference to the COM object

private:
   com::ptr<IXMLDOMDocument> m_ptrDoc;
};

// unmanaged function that loads XML into a raw XML DOM Document object
HRESULT LoadXml(IXMLDOMDocument* pDoc, BSTR bstrXml) {
   HRESULT hr = S_OK;
   VARIANT_BOOL bSuccess;
   hr = pDoc->loadXML(bstrXml, &bSuccess);
   if (S_OK == hr && !bSuccess) {
      hr = E_FAIL;
   }
   return hr;
}

// use the ref class to handle an XML DOM Document object
int main() {
   IXMLDOMDocument* pDoc = NULL;
   BSTR bstrXml = NULL;

   try {
      // create the class from a progid string
      XmlDocument doc("Msxml2.DOMDocument.3.0");

      bstrXml = ::SysAllocString(L"<word>persnickety</word>");
      if (NULL == bstrXml) {
         throw gcnew OutOfMemoryException("bstrXml");
      }
      // detach the document object from the ref class
      pDoc = doc.GetDocument();
      // use unmanaged function and raw object to load xml
      Marshal::ThrowExceptionForHR(LoadXml(pDoc, bstrXml));
      // release reference to document object (but ref class still references it)
      pDoc->Release();
      pDoc = NULL;

      // call another function on the ref class
      doc.WriteDocument();
   }
   catch (Exception^ e) {
      Console::WriteLine(e);
   }
   finally {
      if (NULL != pDoc) {
         pDoc->Release();
      }

   }
}
```

```Output
<word>persnickety</word>
```

## <a name="ptrqueryinterface"></a><a name="queryInterface"></a>PTR:: QueryInterface

Consulta o objeto COM de propriedade de uma interface e anexa o resultado a outro `com::ptr` .

```cpp
template<class _other_type>
void QueryInterface(
   ptr<_other_type> % other
);
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
O `com::ptr` que obterá a interface.

### <a name="exceptions"></a>Exceções

Internamente, `QueryInterface` é chamado no objeto com de propriedade e qualquer erro `HRESULT` é convertido em uma exceção pelo <xref:System.Runtime.InteropServices.Marshal.ThrowExceptionForHR%2A> .

### <a name="remarks"></a>Comentários

Use este método para criar um wrapper COM para uma interface diferente do objeto COM de Propriedade do invólucro atual. Esse método chama `QueryInterface` o objeto com de propriedade para solicitar um ponteiro para uma interface específica do objeto com e anexa o ponteiro de interface retornado ao passado `com::ptr` .

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` para encapsular seu objeto de membro privado `IXMLDOMDocument` . A `WriteTopLevelNode` função de membro usa `QueryInterface` para preencher um local `com::ptr` com um `IXMLDOMNode` e, em seguida, passa o `com::ptr` (por referência de rastreamento) para uma função de membro particular que grava as propriedades de nome e texto do nó no console.

```cpp
// comptr_queryinterface.cpp
// compile with: /clr /link msxml2.lib
#include <msxml2.h>
#include <msclr\com\ptr.h>

#import <msxml3.dll> raw_interfaces_only

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr;

// a ref class that uses a com::ptr to contain an
// IXMLDOMDocument object
ref class XmlDocument {
public:
   // construct the internal com::ptr with a null interface
   // and use CreateInstance to fill it
   XmlDocument(String^ progid) {
      m_ptrDoc.CreateInstance(progid);
   }

   void LoadXml(String^ xml) {
      pin_ptr<const wchar_t> pinnedXml = PtrToStringChars(xml);
      BSTR bstr = NULL;

      try {
         // load some XML into our document
         bstr = ::SysAllocString(pinnedXml);
         if (NULL == bstr) {
            throw gcnew OutOfMemoryException;
         }
         VARIANT_BOOL bIsSuccessful = false;
         // use operator -> to call IXMODOMDocument member function
         Marshal::ThrowExceptionForHR(m_ptrDoc->loadXML(bstr, &bIsSuccessful));
      }
      finally {
         ::SysFreeString(bstr);
      }
   }

   // write the top level node to the console
   void WriteTopLevelNode() {
      com::ptr<IXMLDOMNode> ptrNode;

      // query for the top level node interface
      m_ptrDoc.QueryInterface(ptrNode);
      WriteNode(ptrNode);
   }

   // note that the destructor will call the com::ptr destructor
   // and automatically release the reference to the COM object

private:
   // simplified function that only writes the node
   void WriteNode(com::ptr<IXMLDOMNode> % node) {
      BSTR bstr = NULL;

      try {
         // write out the name and text properties
         Marshal::ThrowExceptionForHR(node->get_nodeName(&bstr));
         String^ strName = gcnew String(bstr);
         Console::Write("<{0}>", strName);
         ::SysFreeString(bstr);
         bstr = NULL;

         Marshal::ThrowExceptionForHR(node->get_text(&bstr));
         Console::Write(gcnew String(bstr));
         ::SysFreeString(bstr);
         bstr = NULL;

         Console::WriteLine("</{0}>", strName);
      }
      finally {
         ::SysFreeString(bstr);
      }
   }

   com::ptr<IXMLDOMDocument> m_ptrDoc;
};

// use the ref class to handle an XML DOM Document object
int main() {
   try {
      // create the class from a progid string
      XmlDocument doc("Msxml2.DOMDocument.3.0");

      // stream some xml into the document
      doc.LoadXml("<word>persnickety</word>");

      // write the document to the console
      doc.WriteTopLevelNode();
   }
   catch (Exception^ e) {
      Console::WriteLine(e);
   }
}
```

```Output
<#document>persnickety</#document>
```

## <a name="ptrrelease"></a><a name="release"></a>PTR:: versão

Libera Todas as referências de propriedade no objeto COM.

```cpp
void Release();
```

### <a name="remarks"></a>Comentários

Chamar essa função libera Todas as referências de Propriedade do objeto COM e define o identificador interno para o objeto COM **`nullptr`** .  Se nenhuma outra referência no objeto COM existir, ela será destruída.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` para encapsular seu objeto de membro privado `IXMLDOMDocument` .  A `ReplaceDocument` função de membro usa `Release` para liberar qualquer objeto de documento anterior antes de anexar o novo documento.

```cpp
// comptr_release.cpp
// compile with: /clr /link msxml2.lib
#include <msxml2.h>
#include <msclr\com\ptr.h>

#import <msxml3.dll> raw_interfaces_only

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr;

// a ref class that uses a com::ptr to contain an
// IXMLDOMDocument object
ref class XmlDocument {
public:
   // construct the internal com::ptr with a null interface
   // and use CreateInstance to fill it
   XmlDocument(String^ progid) {
      m_ptrDoc.CreateInstance(progid);
   }

   // replace currently held COM object with another one
   void ReplaceDocument(IXMLDOMDocument* pDoc) {
      // release current document object
      m_ptrDoc.Release();
      // attach the new document object
      m_ptrDoc.Attach(pDoc);
   }

   // note that the destructor will call the com::ptr destructor
   // and automatically release the reference to the COM object

private:
   com::ptr<IXMLDOMDocument> m_ptrDoc;
};

// unmanaged function that creates a raw XML DOM Document object
IXMLDOMDocument* CreateDocument() {
   IXMLDOMDocument* pDoc = NULL;
   Marshal::ThrowExceptionForHR(CoCreateInstance(CLSID_DOMDocument30, NULL,
      CLSCTX_INPROC_SERVER, IID_IXMLDOMDocument, (void**)&pDoc));
   return pDoc;
}

// use the ref class to handle an XML DOM Document object
int main() {
   IXMLDOMDocument* pDoc = NULL;

   try {
      // create the class from a progid string
      XmlDocument doc("Msxml2.DOMDocument.3.0");

      // get another document object from unmanaged function and
      // store it in place of the one held by our ref class
      pDoc = CreateDocument();
      doc.ReplaceDocument(pDoc);
      // no further need for raw object reference
      pDoc->Release();
      pDoc = NULL;
   }
   catch (Exception^ e) {
      Console::WriteLine(e);
   }
   finally {
      if (NULL != pDoc) {
         pDoc->Release();
      }
   }
}
```

## <a name="ptroperator-gt"></a><a name="operator-arrow"></a>operador:: Operator-&gt;

Operador de acesso de membro, usado para chamar métodos no objeto COM de propriedade.

```cpp
_detail::smart_com_ptr<_interface_type> operator->();
```

### <a name="return-value"></a>Valor retornado

A `smart_com_ptr` para o objeto com.

### <a name="exceptions"></a>Exceções

Internamente, `QueryInterface` é chamado no objeto com de propriedade e qualquer erro `HRESULT` é convertido em uma exceção pelo <xref:System.Runtime.InteropServices.Marshal.ThrowExceptionForHR%2A> .

### <a name="remarks"></a>Comentários

Esse operador permite chamar métodos do objeto COM de propriedade. Ele retorna um temporário `smart_com_ptr` que manipula automaticamente seu próprio `AddRef` e `Release` .

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` para encapsular seu objeto de membro privado `IXMLDOMDocument` . A `WriteDocument` função usa `operator->` para chamar o `get_firstChild` membro do objeto Document.

```cpp
// comptr_op_member.cpp
// compile with: /clr /link msxml2.lib
#include <msxml2.h>
#include <msclr\com\ptr.h>

#import <msxml3.dll> raw_interfaces_only

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr;

// a ref class that uses a com::ptr to contain an
// IXMLDOMDocument object
ref class XmlDocument {
public:
   // construct the internal com::ptr with a null interface
   // and use CreateInstance to fill it
   XmlDocument(String^ progid) {
      m_ptrDoc.CreateInstance(progid);
   }

   // add a reference to and return the COM object
   // but keep an internal reference to the object
   IXMLDOMDocument* GetDocument() {
      return m_ptrDoc.GetInterface();
   }

   // simplified function that only writes the first node
   void WriteDocument() {
      IXMLDOMNode* pNode = NULL;
      BSTR bstr = NULL;

      try {
         // use operator -> to call XML Doc member
         Marshal::ThrowExceptionForHR(m_ptrDoc->get_firstChild(&pNode));
         if (NULL != pNode) {
            // write out the xml
            Marshal::ThrowExceptionForHR(pNode->get_nodeName(&bstr));
            String^ strName = gcnew String(bstr);
            Console::Write("<{0}>", strName);
            ::SysFreeString(bstr);
            bstr = NULL;

            Marshal::ThrowExceptionForHR(pNode->get_text(&bstr));
            Console::Write(gcnew String(bstr));
            ::SysFreeString(bstr);
            bstr = NULL;

            Console::WriteLine("</{0}>", strName);
         }
      }
      finally {
         if (NULL != pNode) {
            pNode->Release();
         }
         ::SysFreeString(bstr);
      }
   }

   // note that the destructor will call the com::ptr destructor
   // and automatically release the reference to the COM object

private:
   com::ptr<IXMLDOMDocument> m_ptrDoc;
};

// unmanaged function that loads XML into a raw XML DOM Document object
HRESULT LoadXml(IXMLDOMDocument* pDoc, BSTR bstrXml) {
   HRESULT hr = S_OK;
   VARIANT_BOOL bSuccess;
   hr = pDoc->loadXML(bstrXml, &bSuccess);
   if (S_OK == hr && !bSuccess) {
      hr = E_FAIL;
   }
   return hr;
}

// use the ref class to handle an XML DOM Document object
int main() {
   IXMLDOMDocument* pDoc = NULL;
   BSTR bstrXml = NULL;

   try {
      // create the class from a progid string
      XmlDocument doc("Msxml2.DOMDocument.3.0");

      bstrXml = ::SysAllocString(L"<word>persnickety</word>");
      if (NULL == bstrXml) {
         throw gcnew OutOfMemoryException("bstrXml");
      }
      // detach the document object from the ref class
      pDoc = doc.GetDocument();
      // use unmanaged function and raw object to load xml
      Marshal::ThrowExceptionForHR(LoadXml(pDoc, bstrXml));
      // release reference to document object (but ref class still references it)
      pDoc->Release();
      pDoc = NULL;

      // call another function on the ref class
      doc.WriteDocument();
   }
   catch (Exception^ e) {
      Console::WriteLine(e);
   }
   finally {
      if (NULL != pDoc) {
         pDoc->Release();
      }

   }
}
```

```Output
<word>persnickety</word>
```

## <a name="ptroperator"></a><a name="operator-assign"></a>PTR:: Operator =

Anexa um objeto COM a um `com::ptr` .

```cpp
ptr<_interface_type> % operator=(
   _interface_type * _right
);
```

### <a name="parameters"></a>parâmetros

*_right*<br/>
O ponteiro de interface COM a ser anexado.

### <a name="return-value"></a>Valor retornado

Uma referência de rastreamento no `com::ptr` .

### <a name="exceptions"></a>Exceções

Se o `com::ptr` já possuir uma referência a um objeto com, o `operator=` lançará <xref:System.InvalidOperationException> .

### <a name="remarks"></a>Comentários

A atribuição de um objeto COM a uma `com::ptr` faz referência ao objeto com, mas não libera a referência do chamador a ele.

Esse operador tem o mesmo efeito que `Attach` .

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` para encapsular seu objeto de membro privado `IXMLDOMDocument` .  A `ReplaceDocument` função de membro primeiro chama `Release` qualquer objeto de propriedade anterior e, em seguida, usa `operator=` para anexar um novo objeto de documento.

```cpp
// comptr_op_assign.cpp
// compile with: /clr /link msxml2.lib
#include <msxml2.h>
#include <msclr\com\ptr.h>

#import <msxml3.dll> raw_interfaces_only

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr;

// a ref class that uses a com::ptr to contain an
// IXMLDOMDocument object
ref class XmlDocument {
public:
   // construct the internal com::ptr with a null interface
   // and use CreateInstance to fill it
   XmlDocument(String^ progid) {
      m_ptrDoc.CreateInstance(progid);
   }

   // replace currently held COM object with another one
   void ReplaceDocument(IXMLDOMDocument* pDoc) {
      // release current document object
      m_ptrDoc.Release();
      // attach the new document object
      m_ptrDoc = pDoc;
   }

   // note that the destructor will call the com::ptr destructor
   // and automatically release the reference to the COM object

private:
   com::ptr<IXMLDOMDocument> m_ptrDoc;
};

// unmanaged function that creates a raw XML DOM Document object
IXMLDOMDocument* CreateDocument() {
   IXMLDOMDocument* pDoc = NULL;
   Marshal::ThrowExceptionForHR(CoCreateInstance(CLSID_DOMDocument30, NULL,
      CLSCTX_INPROC_SERVER, IID_IXMLDOMDocument, (void**)&pDoc));
   return pDoc;
}

// use the ref class to handle an XML DOM Document object
int main() {
   IXMLDOMDocument* pDoc = NULL;

   try {
      // create the class from a progid string
      XmlDocument doc("Msxml2.DOMDocument.3.0");

      // get another document object from unmanaged function and
      // store it in place of the one held by the ref class
      pDoc = CreateDocument();
      doc.ReplaceDocument(pDoc);
      // no further need for raw object reference
      pDoc->Release();
      pDoc = NULL;
   }
   catch (Exception^ e) {
      Console::WriteLine(e);
   }
   finally {
      if (NULL != pDoc) {
         pDoc->Release();
      }
   }
}
```

## <a name="ptroperator-bool"></a><a name="operator-bool"></a>operador PTR:: Operator

Operador para usar `com::ptr` em uma expressão condicional.

```cpp
operator bool();
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o objeto COM pertencer for válido; **`false`** caso contrário.

### <a name="remarks"></a>Comentários

O objeto COM pertencente será válido se não for **`nullptr`** .

Esse operador converte o `_detail_class::_safe_bool` que é mais seguro do que **`bool`** porque não pode ser convertido em um tipo integral.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` para encapsular seu objeto de membro privado `IXMLDOMDocument` . A `CreateInstance` função de membro usa `operator bool` depois de criar o novo objeto de documento para determinar se ele é válido e se é gravado no console, se for.

```cpp
// comptr_op_bool.cpp
// compile with: /clr /link msxml2.lib
#include <msxml2.h>
#include <msclr\com\ptr.h>

#import <msxml3.dll> raw_interfaces_only

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr;

// a ref class that uses a com::ptr to contain an
// IXMLDOMDocument object
ref class XmlDocument {
public:
   void CreateInstance(String^ progid) {
      if (!m_ptrDoc) {
         m_ptrDoc.CreateInstance(progid);
         if (m_ptrDoc) { // uses operator bool
            Console::WriteLine("DOM Document created.");
         }
      }
   }

   // note that the destructor will call the com::ptr destructor
   // and automatically release the reference to the COM object

private:
   com::ptr<IXMLDOMDocument> m_ptrDoc;
};

// use the ref class to handle an XML DOM Document object
int main() {
   try {
      XmlDocument doc;
      // create the instance from a progid string
      doc.CreateInstance("Msxml2.DOMDocument.3.0");
   }
   catch (Exception^ e) {
      Console::WriteLine(e);
   }
}
```

```Output
DOM Document created.
```

## <a name="ptroperator"></a><a name="operator-logical-not"></a>PTR:: operador!

Para determinar se o objeto COM pertencente é inválido.

```cpp
bool operator!();
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o objeto COM pertencente for inválido; **`false`** caso contrário.

### <a name="remarks"></a>Comentários

O objeto COM pertencente será válido se não for **`nullptr`** .

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` para encapsular seu objeto de membro privado `IXMLDOMDocument` .  A `CreateInstance` função de membro usa `operator!` para determinar se um objeto de documento já é de propriedade e só cria uma nova instância se o objeto for inválido.

```cpp
// comptr_op_not.cpp
// compile with: /clr /link msxml2.lib
#include <msxml2.h>
#include <msclr\com\ptr.h>

#import <msxml3.dll> raw_interfaces_only

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr;

// a ref class that uses a com::ptr to contain an
// IXMLDOMDocument object
ref class XmlDocument {
public:
   void CreateInstance(String^ progid) {
      if (!m_ptrDoc) {
         m_ptrDoc.CreateInstance(progid);
         if (m_ptrDoc) {
            Console::WriteLine("DOM Document created.");
         }
      }
   }

   // note that the destructor will call the com::ptr destructor
   // and automatically release the reference to the COM object

private:
   com::ptr<IXMLDOMDocument> m_ptrDoc;
};

// use the ref class to handle an XML DOM Document object
int main() {
   try {
      XmlDocument doc;
      // create the instance from a progid string
      doc.CreateInstance("Msxml2.DOMDocument.3.0");
   }
   catch (Exception^ e) {
      Console::WriteLine(e);
   }
}
```

```Output
DOM Document created.
```
