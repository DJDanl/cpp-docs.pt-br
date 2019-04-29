---
title: Integração CLR (C++/CX)
ms.date: 01/22/2017
ms.assetid: 76e213cf-2f3d-4181-b35b-9fd25d5b307c
ms.openlocfilehash: df0c5e9cfaf9a4148c8d16b68ee04b4e9ce82e6a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62257771"
---
# <a name="clr-integration-ccx"></a>Integração CLR (C++/CX)

Alguns tipos de tempo de execução do Windows recebem tratamento especial no C++/CX e os idiomas que são baseados no common language runtime (CLR). Este artigo aborda como vários tipos em uma linguagem são mapeados para outra linguagem. Por exemplo, o CLR mapeia Windows.Foundation.IVector para System.Collections.IList, Windows.Foundation.IMap para System.Collections.IDictionary e assim por diante. Da mesma forma, C++/CX mapeia tipos como Platform:: delegate e Platform:: String.

## <a name="mapping-the-windows-runtime-to-ccx"></a>Mapeando o tempo de execução do Windows para C++/CX

Quando C++/CX lê um arquivo de metadados (. winmd) do Windows, o compilador automaticamente mapeia namespaces comuns do Windows Runtime e tipos para C++/CX namespaces e tipos. Por exemplo, o tipo de tempo de execução do Windows numérico `UInt32` é mapeada automaticamente para `default::uint32`.

C++/CX mapeia vários outros tipos de tempo de execução do Windows para o **plataforma** namespace. Por exemplo, o **Windows:: Foundation** identificação HSTRING, que representa uma cadeia de texto Unicode somente leitura, é mapeada para o C++/CX `Platform::String` classe. Quando uma operação de tempo de execução do Windows retorna um erro HRESULT, ele é mapeado para um C++/CX `Platform::Exception`.

O C++/CX também mapeia determinados tipos nos namespaces de tempo de execução do Windows para aprimorar a funcionalidade do tipo. Para esses tipos, C++/CX fornece construtores e métodos que são específicos para auxiliares C++ e não estão disponíveis no arquivo. winmd padrão do tipo.

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

## <a name="mapping-the-clr-to-ccx"></a>Mapeamento do CLR para C++/CX

Quando o Visual C++ ou C# compiladores ler um arquivo. winmd, eles mapeiam automaticamente determinados tipos no arquivo de metadados apropriado C++/CX ou tipos de CLR. Por exemplo, no CLR, o IVector\<T > interface é mapeada para IList\<T >. Mas em C++/CX, o IVector\<T > interface não está mapeado para outro tipo.

IReference\<T > no tempo de execução do Windows mapeia para Nullable\<T > no .NET.

## <a name="see-also"></a>Consulte também

[Como interoperar com outras linguagens](../cppcx/interoperating-with-other-languages-c-cx.md)
