---
title: Platform::Metadata::RuntimeClassName | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Metadata::RuntimeClassName
helpviewer_keywords:
- RuntimeClassName
- Platform::Metadata::RuntimeClassName
ms.assetid: fdef8f85-ab94-4edd-ba50-ee0da9358ff6
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 297a5089af7db43d837934e864e0925cd7b34a3d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="platformmetadataruntimeclassname"></a>Platform::Metadata::RuntimeClassName
Quando aplicado a uma definição de classe, garante que uma classe privada retorne um nome válido da função GetRuntimeClassName.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[Platform::Metadata::RuntimeClassName] name  
```  
  
#### <a name="parameters"></a>Parâmetros  
 name  
  
 O nome de um tipo público existente que ainda é visível no Tempo de Execução do Windows.  
  
### <a name="remarks"></a>Comentários  
 Use esse atributo em classes ref privadas para especificar um nome de tipo de tempo de execução personalizado e/ou quando o nome existente não atendem aos requisitos. Especifique como nome uma interface pública que a classe implementará.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como usar o atributo. Neste exemplo, o nome do tipo de tempo de execução de HellowWorldImpl é Test::Native::MyComponent::IHelloWorld  
  
```  
  
namespace Test  
{  
    namespace Native  
    {  
        namespace MyComponent  
        {  
            public interface class IHelloWorld  
            {  
                Platform::String^ SayHello();  
            };  
  
            private ref class HelloWorldImpl sealed :[Platform::Metadata::RuntimeClassName] IHelloWorld  
            {  
            public:  
                HelloWorldImpl();  
                virtual Platform::String^ SayHello();  
            };  
  
            Platform::String^ HelloWorldImpl::SayHello()  
            {  
                return L"Hello World!";  
            }  
        }  
    }  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Platform::Metadata](../cppcx/platform-metadata-namespace.md)