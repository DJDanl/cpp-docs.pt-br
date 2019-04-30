---
title: Platform::Metadata::RuntimeClassName
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Metadata::RuntimeClassName
helpviewer_keywords:
- RuntimeClassName
- Platform::Metadata::RuntimeClassName
ms.assetid: fdef8f85-ab94-4edd-ba50-ee0da9358ff6
ms.openlocfilehash: d3de753c3a8897058333e02ce4294a0780d5b818
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62387572"
---
# <a name="platformmetadataruntimeclassname"></a>Platform::Metadata::RuntimeClassName

Quando aplicado a uma definição de classe, garante que uma classe privada retorne um nome válido da função GetRuntimeClassName.

## <a name="syntax"></a>Sintaxe

```cpp
[Platform::Metadata::RuntimeClassName] name
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
O nome de um tipo público existente que ainda é visível no Tempo de Execução do Windows.

### <a name="remarks"></a>Comentários

Use esse atributo em classes ref privadas para especificar um nome de tipo de tempo de execução personalizado e/ou quando o nome existente não atendem aos requisitos. Especifique como nome uma interface pública que a classe implementará.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar o atributo. Neste exemplo, o nome do tipo de tempo de execução de HellowWorldImpl é Test::Native::MyComponent::IHelloWorld

```cpp
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
