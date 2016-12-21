---
title: "ptr::Attach | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "msclr::com::ptr::Attach"
  - "ptr::Attach"
  - "ptr.Attach"
  - "msclr.com.ptr.Attach"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Attach"
ms.assetid: 81d930de-cb2a-4c30-9bd6-94d65942c47a
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ptr::Attach
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Anexa um objeto à `com::ptr`.  
  
## Sintaxe  
  
```  
void Attach(  
   _interface_type * _right  
);  
```  
  
#### Parâmetros  
 `_right`  
 O ponteiro da interface COM a ser anexada.  
  
## Exceções  
 Se `com::ptr` já tiver uma referência a um objeto COM, `Attach` gerencie <xref:System.InvalidOperationException>.  
  
## Comentários  
 Uma chamada para `Attach` faz referência ao objeto COM o mas não libera a referência do chamador a ele.  
  
 Passe `NULL` a `Attach` resulta em nenhuma ação que está sendo executada.  
  
## Exemplo  
 Este exemplo de CLR implementa uma classe que usa `com::ptr` para encapsular o objeto de `IXMLDOMDocument` de membro particular.  De `ReplaceDocument` da função de membro as chamadas `Release` primeiro em qualquer objeto anteriormente de propriedade e chamar `Attach` para anexar um objeto de documento novo.  
  
```  
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
  
## Requisitos  
 msclr \<de**Arquivo de cabeçalho** \\ COM \\ ptr.h\>  
  
 msclr::com de**Namespace**  
  
## Consulte também  
 [Membros ptr](../dotnet/ptr-members.md)   
 [ptr::operator\=](../dotnet/ptr-operator-assign.md)   
 [ptr::Release](../dotnet/ptr-release.md)