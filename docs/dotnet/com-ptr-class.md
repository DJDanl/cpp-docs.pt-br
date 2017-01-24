---
title: "Classe com::ptr | Microsoft Docs"
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
  - "com::ptr"
  - "msclr::com::ptr"
  - "msclr.com.ptr"
  - "com.ptr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classe ptr"
ms.assetid: 0144d0e4-919c-45f9-a3f8-fbc9edba32bf
caps.latest.revision: 10
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe com::ptr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um wrapper para um objeto COM que pode ser usado como um membro de uma classe de CLR.  O wrapper também automatiza gerenciamento do tempo de vida do objeto COM, liberando todas as referências de propriedade de objeto em seu destruidor quando é chamado.  Análoga a [Classe de CComPtr](../atl/reference/ccomptr-class.md).  
  
## Sintaxe  
  
```  
template<class _interface_type>  
ref class ptr;  
```  
  
#### Parâmetros  
 `_interface_type`  
 Interface COM.  
  
## Comentários  
 `com::ptr` também pode ser usado como uma variável local da função para simplificar mais tarefas de COM e para automatizar gerenciamento do tempo de vida.  
  
 `com::ptr` não pode ser usado diretamente como um parâmetro de função; use [Tracking Reference Operator](../windows/tracking-reference-operator-cpp-component-extensions.md) ou [Operador Handle to Object \(^\)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md) em vez disso.  
  
 `com::ptr` não pode ser diretamente retornado de uma função; use um identificador em vez disso.  
  
## Exemplo  
 Este exemplo de CLR implementa uma classe que usa `com::ptr` para encapsular o objeto de `IXMLDOMDocument` de membro particular.  Chamando métodos públicos dos resultados da classe em chamadas a `IXMLDOMDocument` contido objeto.  O exemplo a seguir cria uma instância de um documento XML, acrescenta qualquer XML simples, e faça uma exames simplificada dos nós na árvore analisada do documento para imprimir XML no console.  
  
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
  
  **\<wordpersnickety\>\<\/palavras\>**   
## Requisitos  
 msclr \<de**Arquivo de cabeçalho** \\ COM \\ ptr.h\>  
  
 msclr::com de**Namespace**  
  
## Consulte também  
 [Biblioteca de suporte do C\+\+](../dotnet/cpp-support-library.md)   
 [Membros ptr](../dotnet/ptr-members.md)