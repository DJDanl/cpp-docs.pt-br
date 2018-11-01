---
title: ptr::~ptr
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- msclr.com.ptr.~ptr
- ptr.~ptr
- msclr::com.ptr::~ptr
- ~ptr
- ptr::~ptr
helpviewer_keywords:
- ptr::~ptr
ms.assetid: 5f644aa5-fe66-4992-a5f8-13ec1292c949
ms.openlocfilehash: 452876fb2b377048b3916e61d39467e2279cd4ad
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50618058"
---
# <a name="ptrptr"></a>ptr::~ptr

Destructs um `com::ptr`.

## <a name="syntax"></a>Sintaxe

```
~ptr();
```

## <a name="remarks"></a>Comentários

Na destruição, o `com::ptr` libera todas as referências que possui a seu objeto COM. Supondo que não há nenhuma outra referência mantida para o objeto COM, o objeto COM será excluído e sua memória liberada.

## <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` encapsular seu membro privado `IXMLDOMDocument` objeto.  No `main` função, os dois `XmlDocument` destruidores de objetos serão chamados quando eles saem do escopo a `try` bloco, resultando em subjacente `com::ptr` destructor seja chamado, liberando possuídas todas as referências para o COM objeto.

```
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

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho** \<msclr\com\ptr.h >

**Namespace** msclr::com

## <a name="see-also"></a>Consulte também

[Membros ptr](../dotnet/ptr-members.md)<br/>
[ptr::ptr](../dotnet/ptr-ptr.md)<br/>
[ptr::CreateInstance](../dotnet/ptr-createinstance.md)