---
title: Integração CLR (C++/CX)
ms.date: 01/22/2017
ms.assetid: 76e213cf-2f3d-4181-b35b-9fd25d5b307c
ms.openlocfilehash: 44ef35d1a62706cae37285c06547a8b9b7deb35c
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70740289"
---
# <a name="clr-integration-ccx"></a>Integração CLR (C++/CX)

Alguns tipos de Windows Runtime recebem tratamento especial C++em/CX e os idiomas baseados no Common Language Runtime (CLR). Este artigo aborda como vários tipos em uma linguagem são mapeados para outra linguagem. Por exemplo, o CLR mapeia Windows.Foundation.IVector para System.Collections.IList, Windows.Foundation.IMap para System.Collections.IDictionary e assim por diante. Da mesma C++forma, o/CX especialmente mapeia tipos como plataforma::D Elegado e plataforma:: String.

## <a name="mapping-the-windows-runtime-to-ccx"></a>Mapeando o Windows Runtime C++para o/CX

Quando C++/CX lê um arquivo de metadados do Windows (. winmd), o compilador mapeia automaticamente os namespaces e tipos C++comuns do Windows Runtime para os namespaces e tipos do/CX. Por exemplo, o tipo `UInt32` de Windows Runtime numérico é mapeado automaticamente para. `default::uint32`

C++/CX mapeia vários outros tipos de Windows Runtime para o namespace da **plataforma** . Por exemplo, o identificador HSTRING do **Windows:: Foundation** , que representa uma cadeia de caracteres de texto Unicode somente leitura, é C++mapeado `Platform::String` para a classe/CX. Quando uma operação de Windows Runtime retorna um erro HRESULT, ela é mapeada para C++um `Platform::Exception`/CX.

O C++/CX também mapeia determinados tipos em namespaces Windows Runtime para aprimorar a funcionalidade do tipo. Para esses tipos, C++o/CX fornece construtores auxiliares e métodos que são específicos C++ do e não estão disponíveis no arquivo. winmd padrão do tipo.

A lista a seguir mostra as structs de valor que dão suporte a novos construtores e métodos auxiliares. Se você tiver gravado anteriormente um código que usa listas de inicialização de struct, altere-o para usar os construtores recém-adicionados.

**Windows::Foundation**

- Ponto

- Rect

- Tamanho

**Windows::UI**

- Cor

**Windows::UI::Xaml**

- CornerRadius

- Duração

- GridLength

- Espessura

**Windows::UI::Xaml::Interop**

- NomeDoTipo

**Windows::UI::Xaml::Media**

- Matriz

**Windows::UI::Xaml::Media::Animation**

- KeyTime

- RepeatBehavior

**Windows::UI::Xaml::Media::Media3D**

- Matrix3D

## <a name="mapping-the-clr-to-ccx"></a>Mapeando o CLR C++para/CX

Quando a Microsoft C++ ou C# os compiladores lêem um arquivo. winmd, eles mapeiam automaticamente determinados tipos no arquivo de metadados C++para os tipos de/CX ou CLR apropriados. Por exemplo, no CLR, a interface IVector\<t > é mapeada para IList\<T >. Mas, C++em/CX, a\<interface IVector T > não está mapeada para outro tipo.

IReference\<t > no Windows Runtime mapeia para o T\<anulável > no .net.

## <a name="see-also"></a>Consulte também

[Como interoperar com outras linguagens](../cppcx/interoperating-with-other-languages-c-cx.md)
