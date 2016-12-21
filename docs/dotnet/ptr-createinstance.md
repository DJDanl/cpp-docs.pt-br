---
title: "ptr::CreateInstance | Microsoft Docs"
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
  - "ptr.CreateInstance"
  - "msclr::com::ptr::CreateInstance"
  - "msclr.com.ptr.CreateInstance"
  - "ptr::CreateInstance"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ptr::CreateInstance"
ms.assetid: 9e8e4c4c-1651-4839-8829-5857d74470fe
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ptr::CreateInstance
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria uma instância de um objeto COM dentro de `com::ptr`.  
  
## Sintaxe  
  
```  
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
  
#### Parâmetros  
 `progid`  
 Uma cadeia de caracteres de `ProgID` .  
  
 `pouter`  
 Ponteiro para a interface IUnknown do objeto de agregação \(o IUnknown de controle\).  Se `pouter` não for especificado, `NULL` será usado.  
  
 `cls_context`  
 Contexto no qual o código que gerencia o objeto recém\-criado será executado.  Os valores são tirados de enumeração de `CLSCTX` .  Se `cls_context` não for especificado, o valor CLSCTX\_ALL será usado.  
  
 `rclsid`  
 `CLSID` associado aos dados e o código que serão usados para criar o objeto.  
  
## Exceções  
 Se `com::ptr` já tiver uma referência a um objeto COM, `CreateInstance` gerencie <xref:System.InvalidOperationException>.  
  
 Este chamadas de função `CoCreateInstance` e usa <xref:System.Runtime.InteropServices.Marshal.ThrowExceptionForHR%2A> converter qualquer erro `HRESULT` a uma exceção apropriada.  
  
## Comentários  
 usa `CoCreateInstance` de`CreateInstance` criar uma nova instância do objeto especificado, identificada de ProgID ou de CLSID.  `com::ptr` referencia o objeto recém\-criado e libera automaticamente todas as referências possuídos em cima de destruição.  
  
## Exemplo  
 Este exemplo de CLR implementa uma classe que usa `com::ptr` para encapsular o objeto de `IXMLDOMDocument` de membro particular.  Os formatos diferentes de uso dos dois construtores da classe de `CreateInstance` para criar o objeto de documento de ProgID ou CLSID mais de um CLSCTX.  
  
```  
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
  
## Requisitos  
 msclr \<de**Arquivo de cabeçalho** \\ COM \\ ptr.h\>  
  
 msclr::com de**Namespace**  
  
## Consulte também  
 [Membros ptr](../dotnet/ptr-members.md)