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
ms.openlocfilehash: e494285f33cf282d7b7515aac374ec86ef3036b7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372487"
---
# <a name="comptr-class"></a>Classe com::ptr

Um invólucro para um objeto COM que pode ser usado como membro de uma classe CLR.  O invólucro também automatiza o gerenciamento vitalício do objeto COM, liberando todas as referências próprias no objeto quando seu destructor é chamado. Análogo à [classe CComPtr](../atl/reference/ccomptr-class.md).

## <a name="syntax"></a>Sintaxe

```
template<class _interface_type>
ref class ptr;
```

### <a name="parameters"></a>Parâmetros

*_interface_type*<br/>
Interface COM.

## <a name="remarks"></a>Comentários

A `com::ptr` também pode ser usado como uma variável de função local para simplificar várias tarefas COM e automatizar o gerenciamento de vida.

A `com::ptr` não pode ser usado diretamente como parâmetro de função; use um [operador de referência de rastreamento](../extensions/tracking-reference-operator-cpp-component-extensions.md) ou uma alça para operador de objeto [(^)](../extensions/handle-to-object-operator-hat-cpp-component-extensions.md) em vez disso.

A `com::ptr` não pode ser diretamente devolvido de uma função; use uma alça em vez disso.

## <a name="example"></a>Exemplo

Este exemplo implementa uma classe `com::ptr` CLR que `IXMLDOMDocument` usa um para envolver seu objeto membro privado.  Chamar os métodos públicos da classe resulta em chamadas para o objeto contido. `IXMLDOMDocument`  A amostra cria uma instância de um documento XML, preenche-o com algum XML simples e faz uma caminhada simplificada dos nódulos na árvore de documentos analisado para imprimir o XML no console.

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
|[ptr::ptr](#ptr)|Constrói um `com::ptr` para embrulhar um objeto COM.|
|[ptr::~ptr](#tilde-ptr)|Destrói a. `com::ptr`|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|---------|-----------|
|[ptr::Attach](#attach)|Anexa um objeto COM `com::ptr`a um .|
|[ptr::CreateInstance](#createInstance)|Cria uma instância de um `com::ptr`objeto COM dentro de um .|
|[ptr::Detach](#detach)|Desiste da propriedade do objeto COM, devolvendo um ponteiro para o objeto.|
|[ptr::GetInterface](#getInterface)|Cria uma instância de um `com::ptr`objeto COM dentro de um .|
|[ptr::QueryInterface](#queryInterface)|Consulta o objeto COM de propriedade para uma `com::ptr`interface e anexa o resultado a outra .|
|[ptr::Release](#release)|Libera todas as referências de propriedade no objeto COM.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|---------|-----------|
|[ptr::operador-&gt;](#operator-arrow)|Operador de acesso ao membro, usado para chamar métodos no objeto COM de propriedade.|
|[ptr::operador=](#operator-assign)|Anexa um objeto COM `com::ptr`a um .|
|[ptr::operador&nbsp;bool](#operator-bool)|Operador para `com::ptr` uso em uma expressão condicional.|
|[ptr::operator!](#operator-logical-not)|Operador para determinar se o objeto COM de propriedade é inválido.|

## <a name="requirements"></a>Requisitos

Arquivo \< **de cabeçalho** msclr\com\ptr.h>

**Namespace** msclr::com

## <a name="ptrptr"></a><a name="ptr"></a>ptr::ptr

Retorna um ponteiro para o objeto COM próprio.

```cpp
ptr();
ptr(
   _interface_type * p
);
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Um ponteiro de interface COM.

### <a name="remarks"></a>Comentários

O construtor sem argumentos atribui `nullptr` à alça do objeto subjacente. As chamadas `com::ptr` futuras para o validarão o objeto interno e falharão silenciosamente até que um objeto seja criado ou anexado.

O construtor de um argumento adiciona uma referência ao objeto COM, mas não libera a `Release` referência do chamador, então o chamador deve chamar o objeto COM para realmente desistir do controle. Quando `com::ptr`o destructor 'é chamado, ele liberará automaticamente suas referências no objeto COM.

Passar `NULL` para este construtor é o mesmo que chamar a versão sem argumentos.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe `com::ptr` CLR que `IXMLDOMDocument` usa um para envolver seu objeto membro privado. Ele demonstra o uso de ambas as versões do construtor.

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

## <a name="ptrptr"></a><a name="tilde-ptr"></a>ptr::~ptr

Destrói a. `com::ptr`

```cpp
~ptr();
```

### <a name="remarks"></a>Comentários

Sobre a `com::ptr` destruição, as liberações todas as referências que possui ao seu objeto COM. Supondo que não haja outras referências mantidas no objeto COM, o objeto COM será excluído e sua memória liberada.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe `com::ptr` CLR que `IXMLDOMDocument` usa um para envolver seu objeto membro privado.  Na `main` função, os `XmlDocument` destruidores dos dois objetos serão chamados quando eles saem do escopo `try` do `com::ptr` bloco, resultando na chamada dedestruição subjacente, liberando todas as referências próprias ao objeto COM.

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

## <a name="ptrattach"></a><a name="attach"></a>ptr::Anexar

Anexa um objeto COM `com::ptr`a um .

```cpp
void Attach(
   _interface_type * _right
);
```

### <a name="parameters"></a>Parâmetros

*_right*<br/>
O ponteiro de interface COM para anexar.

### <a name="exceptions"></a>Exceções

Se `com::ptr` o já possui uma referência `Attach` a <xref:System.InvalidOperationException>um objeto COM, lança .

### <a name="remarks"></a>Comentários

Uma chamada `Attach` para referenciar o objeto COM, mas não libera a referência do chamador a ele.

Passando `NULL` `Attach` para resultados em nenhuma ação sendo tomada.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe `com::ptr` CLR que `IXMLDOMDocument` usa um para envolver seu objeto membro privado. A `ReplaceDocument` função membro `Release` primeiro chama qualquer objeto `Attach` anteriormente possuído e, em seguida, chama para anexar um novo objeto de documento.

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

## <a name="ptrcreateinstance"></a><a name="createInstance"></a>ptr::CreateInstance

Cria uma instância de um `com::ptr`objeto COM dentro de um .

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

### <a name="parameters"></a>Parâmetros

*Progid*<br/>
Uma cadeia de caracteres `ProgID`.

*pouter*<br/>
Ponteiro para a interface IUnknown do objeto agregado (o iUnknown controlador). Se `pouter` não for especificado, `NULL` é usado.

*cls_context*<br/>
Contexto em que o código que gerencia o objeto recém-criado será executado. Os valores são `CLSCTX` retirados da enumeração. Se `cls_context` não for especificado, o valor CLSCTX_ALL é usado.

*Rclsid*<br/>
`CLSID`associado com os dados e códigos que serão usados para criar o objeto.

### <a name="exceptions"></a>Exceções

Se `com::ptr` o já possui uma referência `CreateInstance` a <xref:System.InvalidOperationException>um objeto COM, lança .

Esta função `CoCreateInstance` chama <xref:System.Runtime.InteropServices.Marshal.ThrowExceptionForHR%2A> e usa `HRESULT` para converter qualquer erro em uma exceção apropriada.

### <a name="remarks"></a>Comentários

`CreateInstance`usa `CoCreateInstance` para criar uma nova instância do objeto especificado, identificado a partir de um ProgID ou de um CLSID. As `com::ptr` referências ao objeto recém-criado e liberarão automaticamente todas as referências de propriedade após a destruição.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe `com::ptr` CLR que `IXMLDOMDocument` usa um para envolver seu objeto membro privado. Os construtores de classe usam `CreateInstance` duas formas diferentes de criar o objeto do documento a partir de um ProgID ou de um CLSID mais um CLSCTX.

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

## <a name="ptrdetach"></a><a name="detach"></a>ptr::Detach

Desiste da propriedade do objeto COM, devolvendo um ponteiro para o objeto.

```cpp
_interface_type * Detach();
```

### <a name="return-value"></a>Valor retornado

O ponteiro para o objeto COM.

Se nenhum objeto for possuído, NULL é devolvido.

### <a name="exceptions"></a>Exceções

Internamente, `QueryInterface` é chamado sobre o objeto `HRESULT` COM de propriedade <xref:System.Runtime.InteropServices.Marshal.ThrowExceptionForHR%2A>e qualquer erro é convertido em exceção por .

### <a name="remarks"></a>Comentários

`Detach`primeiro adiciona uma referência ao objeto COM em nome do chamador `com::ptr`e, em seguida, libera todas as referências de propriedade do .  O chamador deve finalmente liberar o objeto devolvido para destruí-lo.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe `com::ptr` CLR que `IXMLDOMDocument` usa um para envolver seu objeto membro privado.  A `DetachDocument` função `Detach` membro pede para desistir da propriedade do objeto COM e retornar um ponteiro ao chamador.

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

## <a name="ptrgetinterface"></a><a name="getInterface"></a>ptr::GetInterface

Retorna um ponteiro para o objeto COM próprio.

```cpp
_interface_type * GetInterface();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto COM próprio.

### <a name="exceptions"></a>Exceções

Internamente, `QueryInterface` é chamado sobre o objeto `HRESULT` COM de propriedade <xref:System.Runtime.InteropServices.Marshal.ThrowExceptionForHR%2A>e qualquer erro é convertido em exceção por .

### <a name="remarks"></a>Comentários

O `com::ptr` adiciona uma referência ao objeto COM em nome do chamador e também mantém sua própria referência no objeto COM. O chamador deve finalmente liberar a referência sobre o objeto devolvido ou nunca será destruído.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe `com::ptr` CLR que `IXMLDOMDocument` usa um para envolver seu objeto membro privado. A `GetDocument` função `GetInterface` membro é usa para retornar um ponteiro ao objeto COM.

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

## <a name="ptrqueryinterface"></a><a name="queryInterface"></a>ptr::QueryInterface

Consulta o objeto COM de propriedade para uma `com::ptr`interface e anexa o resultado a outra .

```cpp
template<class _other_type>
void QueryInterface(
   ptr<_other_type> % other
);
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
O `com::ptr` que vai obter a interface.

### <a name="exceptions"></a>Exceções

Internamente, `QueryInterface` é chamado sobre o objeto `HRESULT` COM de propriedade <xref:System.Runtime.InteropServices.Marshal.ThrowExceptionForHR%2A>e qualquer erro é convertido em exceção por .

### <a name="remarks"></a>Comentários

Use este método para criar um invólucro COM para uma interface diferente do objeto COM de propriedade do invólucro atual. Este método `QueryInterface` chama através do objeto COM de propriedade para solicitar um ponteiro a uma interface específica `com::ptr`do objeto COM e anexa o ponteiro de interface retornado ao pass-in .

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe `com::ptr` CLR que `IXMLDOMDocument` usa um para envolver seu objeto membro privado. A `WriteTopLevelNode` função `QueryInterface` membro usa `com::ptr` para `IXMLDOMNode` preencher um `com::ptr` local com um e, em seguida, passa o (por referência de rastreamento) para uma função de membro privado que grava as propriedades de nome e texto do nó para o console.

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

## <a name="ptrrelease"></a><a name="release"></a>ptr::Liberação

Libera todas as referências de propriedade no objeto COM.

```cpp
void Release();
```

### <a name="remarks"></a>Comentários

Chamar essa função libera todas as referências de propriedade no objeto `nullptr`COM e define a alça interna para o objeto COM para .  Se não houver outras referências sobre o objeto COM, ele será destruído.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe `com::ptr` CLR que `IXMLDOMDocument` usa um para envolver seu objeto membro privado.  A `ReplaceDocument` função `Release` membro usa para liberar qualquer objeto de documento anterior antes de anexar o novo documento.

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

## <a name="ptroperator-gt"></a><a name="operator-arrow"></a>ptr::operador-&gt;

Operador de acesso ao membro, usado para chamar métodos no objeto COM de propriedade.

```cpp
_detail::smart_com_ptr<_interface_type> operator->();
```

### <a name="return-value"></a>Valor retornado

A `smart_com_ptr` para o objeto COM.

### <a name="exceptions"></a>Exceções

Internamente, `QueryInterface` é chamado sobre o objeto `HRESULT` COM de propriedade <xref:System.Runtime.InteropServices.Marshal.ThrowExceptionForHR%2A>e qualquer erro é convertido em exceção por .

### <a name="remarks"></a>Comentários

Este operador permite que você chame métodos do objeto COM de propriedade. Ele retorna `smart_com_ptr` um temporário que lida `AddRef` `Release`automaticamente com o seu próprio e .

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe `com::ptr` CLR que `IXMLDOMDocument` usa um para envolver seu objeto membro privado. A `WriteDocument` função `operator->` é `get_firstChild` usa para chamar o membro do objeto do documento.

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

## <a name="ptroperator"></a><a name="operator-assign"></a>ptr::operador=

Anexa um objeto COM `com::ptr`a um .

```cpp
ptr<_interface_type> % operator=(
   _interface_type * _right
);
```

### <a name="parameters"></a>Parâmetros

*_right*<br/>
O ponteiro de interface COM para anexar.

### <a name="return-value"></a>Valor retornado

Uma referência de `com::ptr`rastreamento no .

### <a name="exceptions"></a>Exceções

Se `com::ptr` o já possui uma referência `operator=` a <xref:System.InvalidOperationException>um objeto COM, lança .

### <a name="remarks"></a>Comentários

Atribuir um objeto COM `com::ptr` a um objeto com, mas não liberar a referência do chamador a ele.

Este operador tem o `Attach`mesmo efeito que .

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe `com::ptr` CLR que `IXMLDOMDocument` usa um para envolver seu objeto membro privado.  A `ReplaceDocument` função membro `Release` primeiro chama qualquer objeto `operator=` anteriormente possuído e, em seguida, usa para anexar um novo objeto de documento.

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

## <a name="ptroperator-bool"></a><a name="operator-bool"></a>ptr::operador bool

Operador para `com::ptr` uso em uma expressão condicional.

```cpp
operator bool();
```

### <a name="return-value"></a>Valor retornado

`true`se o objeto COM de propriedade for válido; `false` caso contrário.

### <a name="remarks"></a>Comentários

O objeto COM de propriedade é `nullptr`válido se não for .

Este operador converte-se `_detail_class::_safe_bool` `bool` para o que é mais seguro do que porque não pode ser convertido em um tipo integral.

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe `com::ptr` CLR que `IXMLDOMDocument` usa um para envolver seu objeto membro privado. A `CreateInstance` função `operator bool` membro usa depois de criar o novo objeto de documento para determinar se ele é válido e grava no console se for.

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

## <a name="ptroperator"></a><a name="operator-logical-not"></a>ptr::operador!

Operador para determinar se o objeto COM de propriedade é inválido.

```cpp
bool operator!();
```

### <a name="return-value"></a>Valor retornado

`true`se o objeto COM de propriedade for inválido; `false` caso contrário.

### <a name="remarks"></a>Comentários

O objeto COM de propriedade é `nullptr`válido se não for .

### <a name="example"></a>Exemplo

Este exemplo implementa uma classe `com::ptr` CLR que `IXMLDOMDocument` usa um para envolver seu objeto membro privado.  A `CreateInstance` função `operator!` membro é usa para determinar se um objeto de documento já é de propriedade e só cria uma nova instância se o objeto for inválido.

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
