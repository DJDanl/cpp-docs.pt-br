---
title: ptr::QueryInterface
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- ptr.QueryInterface
- ptr::QueryInterface
- msclr::com::ptr::QueryInterface
- msclr.com.ptr.QueryInterface
helpviewer_keywords:
- QueryInterface method
ms.assetid: c2619517-3fde-493b-b12d-da8f62d5d803
ms.openlocfilehash: f596a26213ad75bc835b01e69fe57cece580f8ae
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50677442"
---
# <a name="ptrqueryinterface"></a>ptr::QueryInterface

O objeto COM propriedade de uma interface de consulta e anexa o resultado para outro `com::ptr`.

## <a name="syntax"></a>Sintaxe

```
template<class _other_type>
void QueryInterface(
   ptr<_other_type> % other
);
```

#### <a name="parameters"></a>Parâmetros

*other*<br/>
O `com::ptr` que receberá a interface.

## <a name="exceptions"></a>Exceções

Internamente, `QueryInterface` é chamado no objeto COM propriedade e qualquer erro `HRESULT` é convertido em uma exceção por <xref:System.Runtime.InteropServices.Marshal.ThrowExceptionForHR%2A>.

## <a name="remarks"></a>Comentários

Use esse método para criar um invólucro COM para uma interface diferente do objeto COM propriedade wrapper atual. Este método chama `QueryInterface` por meio do objeto COM propriedade para solicitar um ponteiro para uma interface específica do COM do objeto e anexa o ponteiro de interface devolvido ao passado `com::ptr`.

## <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` encapsular seu membro privado `IXMLDOMDocument` objeto. O `WriteTopLevelNode` função de membro usa `QueryInterface` para preencher uma local `com::ptr` com um `IXMLDOMNode` e, em seguida, passa o `com::ptr` (pela referência de rastreamento) para uma função de membro privado que grava as propriedades de nome e o texto do nó no console.

```
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

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho** \<msclr\com\ptr.h >

**Namespace** msclr::com

## <a name="see-also"></a>Consulte também

[Membros ptr](../dotnet/ptr-members.md)<br/>
[ptr::GetInterface](../dotnet/ptr-getinterface.md)