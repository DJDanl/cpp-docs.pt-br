---
title: PTR::CreateInstance | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- ptr.CreateInstance
- msclr::com::ptr::CreateInstance
- msclr.com.ptr.CreateInstance
- ptr::CreateInstance
dev_langs:
- C++
helpviewer_keywords:
- ptr::CreateInstance
ms.assetid: 9e8e4c4c-1651-4839-8829-5857d74470fe
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: dd4ba56b92150046b986f2b101f6a004c114bf28
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33161698"
---
# <a name="ptrcreateinstance"></a>ptr::CreateInstance
Cria uma instância de um objeto COM em um `com::ptr`.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `progid`  
 Uma cadeia de caracteres `ProgID`.  
  
 `pouter`  
 Ponteiro para a interface de IUnknown do objeto de agregação (IUnknown controlador). Se `pouter` não for especificado, `NULL` é usado.  
  
 `cls_context`  
 Contexto no qual o código que gerencia o objeto recém-criado será executado. Os valores são tirados de `CLSCTX` enumeração. Se `cls_context` não for especificado, o valor CLSCTX_ALL é usado.  
  
 `rclsid`  
 `CLSID` associado a dados e o código que será usado para criar o objeto.  
  
## <a name="exceptions"></a>Exceções  
 Se o `com::ptr` já possui uma referência a um objeto COM, `CreateInstance` lança <xref:System.InvalidOperationException>.  
  
 Esta função chama `CoCreateInstance` e usa <xref:System.Runtime.InteropServices.Marshal.ThrowExceptionForHR%2A> para converter qualquer erro `HRESULT` para uma exceção apropriada.  
  
## <a name="remarks"></a>Comentários  
 `CreateInstance` usa `CoCreateInstance` para criar uma nova instância do objeto especificado, identificado um ProgID ou CLSID. O `com::ptr` faz referência ao objeto recém-criado e liberará automaticamente todos os proprietários referências após a destruição.  
  
## <a name="example"></a>Exemplo  
 Este exemplo implementa uma classe CLR que usa um `com::ptr` para incluir o membro privado `IXMLDOMDocument` objeto. Os construtores de classe usam duas formas diferentes de `CreateInstance` para criar o objeto de documento a partir de ProgID ou CLSID mais um CLSCTX.  
  
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
  
## <a name="requirements"></a>Requisitos  
 **Arquivo de cabeçalho** \<msclr\com\ptr.h >  
  
 **Namespace** msclr::com  
  
## <a name="see-also"></a>Consulte também  
 [Membros ptr](../dotnet/ptr-members.md)