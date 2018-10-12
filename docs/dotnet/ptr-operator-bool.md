---
title: 'bool PTR:: Operator | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- ptr::operator bool
- ptr.operator bool
- operator bool
- msclr::com::ptr::operator bool
- msclr.com.ptr.operator bool
dev_langs:
- C++
helpviewer_keywords:
- ptr::operator bool
ms.assetid: 31123377-6ecd-4cef-9b75-3db3996fbcd1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: dcccfd23151d2e09f1fcafeb255dd7261ae2c12a
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49163784"
---
# <a name="ptroperator-bool"></a>Bool ptr::operator

Operador para usar `com::ptr` em uma expressão condicional.

## <a name="syntax"></a>Sintaxe

```
operator bool();
```

## <a name="return-value"></a>Valor de retorno

**True** se o objeto COM propriedade é válido. **falsos** caso contrário.

## <a name="remarks"></a>Comentários

O objeto COM propriedade é válido se não for `nullptr`.

Este operador converte realmente para `_detail_class::_safe_bool` que é mais segura do que `bool` porque ele não pode ser convertido em um tipo integral.

## <a name="example"></a>Exemplo

Este exemplo implementa uma classe CLR que usa um `com::ptr` encapsular seu membro privado `IXMLDOMDocument` objeto. O `CreateInstance` função de membro usa `operator bool` depois de criar o novo objeto de documento para determinar se ele é válido e grava no console se ele for.

```
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

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho** \<msclr\com\ptr.h >

**Namespace** msclr::com

## <a name="see-also"></a>Consulte também

[Membros ptr](../dotnet/ptr-members.md)<br/>
[ptr::operator!](../dotnet/ptr-operator-logical-not.md)