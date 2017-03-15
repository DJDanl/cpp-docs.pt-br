---
title: "ptr::QueryInterface | Microsoft Docs"
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
  - "ptr.QueryInterface"
  - "ptr::QueryInterface"
  - "msclr::com::ptr::QueryInterface"
  - "msclr.com.ptr.QueryInterface"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método QueryInterface"
ms.assetid: c2619517-3fde-493b-b12d-da8f62d5d803
caps.latest.revision: 11
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ptr::QueryInterface
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Consulta COM o objeto de propriedade para uma interface e anexa o resultado para outro `com::ptr`.  
  
## Sintaxe  
  
```  
template<class _other_type>  
void QueryInterface(  
   ptr<_other_type> % other  
);  
```  
  
#### Parâmetros  
 `other`  
 `com::ptr` que obterá a interface.  
  
## Exceções  
 Internamente, `QueryInterface` é chamado COM o objeto de propriedade e qualquer erro `HRESULT` é convertido em uma exceção por <xref:System.Runtime.InteropServices.Marshal.ThrowExceptionForHR%2A>.  
  
## Comentários  
 Use esse método para criar um wrapper de COM para uma interface diferente do objeto COM de propriedade do wrapper atual.  Esse método chama `QueryInterface` por meio do objeto COM de propriedade para solicitar um ponteiro para uma interface específica do objeto COM e anexa o ponteiro retornado da interface para o passado `com::ptr`.  
  
## Exemplo  
 Este exemplo de CLR implementa uma classe que usa `com::ptr` para encapsular o objeto de `IXMLDOMDocument` de membro particular.  A função de membro de `WriteTopLevelNode` usa `QueryInterface` para preencher `com::ptr` local com `IXMLDOMNode` e passa `com::ptr` \(\) para localizar a referência a uma função de membro particular que grava as propriedades de nome e de texto de nó no console.  
  
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
  
  **\<\#documentpersnickety\/\#document\>\<\>**   
## Requisitos  
 msclr \<de**Arquivo de cabeçalho** \\ COM \\ ptr.h\>  
  
 msclr::com de**Namespace**  
  
## Consulte também  
 [Membros ptr](../dotnet/ptr-members.md)   
 [ptr::GetInterface](../dotnet/ptr-getinterface.md)