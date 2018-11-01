---
title: Classe com::ptr
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- com::ptr
- msclr::com::ptr
- msclr.com.ptr
- com.ptr
helpviewer_keywords:
- ptr class
ms.assetid: 0144d0e4-919c-45f9-a3f8-fbc9edba32bf
ms.openlocfilehash: c4d5818698f553fe1d003aab6ca3c7f31e85f843
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50665355"
---
# <a name="comptr-class"></a>Classe com::ptr

Um wrapper para um objeto COM que pode ser usado como um membro de uma classe CLR.  O wrapper também automatiza o gerenciamento de tempo de vida do objeto COM, liberando referências de todas as propriedade no objeto quando seu destruidor é chamado. Análogo à [classe CComPtr](../atl/reference/ccomptr-class.md).

## <a name="syntax"></a>Sintaxe

```
template<class _interface_type>
ref class ptr;
```

#### <a name="parameters"></a>Parâmetros

*_interface_type*<br/>
Interface COM.

## <a name="remarks"></a>Comentários

Um `com::ptr` também pode ser usado como uma variável de função local para simplificar as tarefas COM vários e para automatizar o gerenciamento de tempo de vida.

Um `com::ptr` não pode ser usado diretamente como um parâmetro de função; use um [operador de referência de rastreamento](../windows/tracking-reference-operator-cpp-component-extensions.md) ou uma [operador Handle to Object (^)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md) em vez disso.

Um `com::ptr` não pode ser retornado diretamente de uma função; use um identificador em seu lugar.

## <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` encapsular seu membro privado `IXMLDOMDocument` objeto.  Chamando os métodos públicos da classe resulta em chamadas para independente `IXMLDOMDocument` objeto.  O exemplo cria uma instância de um documento XML, preenche-o com algum XML simple e faz uma movimentação simplificada de nós na árvore do documento analisado para imprimir o XML no console.

```
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

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho** \<msclr\com\ptr.h >

**Namespace** msclr::com

## <a name="see-also"></a>Consulte também

[Biblioteca de suporte do C++](../dotnet/cpp-support-library.md)<br/>
[Membros ptr](../dotnet/ptr-members.md)