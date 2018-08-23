---
title: Integração CLR (C++ c++ /CX) | Microsoft Docs
ms.custom: ''
ms.date: 01/22/2017
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: 76e213cf-2f3d-4181-b35b-9fd25d5b307c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 527ce8beaf5fb08d0642026336be193e3b39d73b
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42581118"
---
# <a name="clr-integration-ccx"></a>Integração CLR (C++/CX)
Alguns tipos de tempo de execução do Windows recebem tratamento especial no C + + c++ /CX e os idiomas que são baseados no common language runtime (CLR). Este artigo aborda como vários tipos em uma linguagem são mapeados para outra linguagem. Por exemplo, o CLR mapeia Windows.Foundation.IVector para System.Collections.IList, Windows.Foundation.IMap para System.Collections.IDictionary e assim por diante. Da mesma forma, C + + c++ /CX mapeia tipos como Platform:: delegate e Platform:: String.  
  
## <a name="mapping-the-windows-runtime-to-ccx"></a>Mapeando o tempo de execução do Windows para C + + c++ /CX  
 Quando C + + c++ /CLI CX lê um arquivo de metadados (. winmd) do Windows, o compilador mapeia automaticamente namespaces comuns do Windows Runtime e tipos para C + + c++ /CLI CX namespaces e tipos. Por exemplo, o tipo de tempo de execução do Windows numérico `UInt32` é mapeada automaticamente para `default::uint32`.  
  
 C + + c++ /CLI CX mapeia vários outros tipos de tempo de execução do Windows para o **plataforma** namespace. Por exemplo, o **Windows:: Foundation** identificador HSTRING, que representa uma cadeia de texto Unicode somente leitura, é mapeado para o C + + c++ /CLI CX `Platform::String` classe. Quando uma operação de tempo de execução do Windows retorna um erro HRESULT, ele é mapeado para um C + + c++ /CX `Platform::Exception`. Para obter mais informações, consulte [Built-in Types](http://msdn.microsoft.com/en-us/acc196fd-09da-4882-b554-6c94685ec75f).  
  
 O C + + c++ /CX também mapeia determinados tipos nos namespaces de tempo de execução do Windows para aprimorar a funcionalidade do tipo. Para esses tipos C + +, c++ /CLI CX fornece construtores e métodos que são específicas do C++ e não estão disponíveis no arquivo. winmd padrão do tipo auxiliares.  
  
 A lista a seguir mostra as structs de valor que dão suporte a novos construtores e métodos auxiliares. Se você tiver gravado anteriormente um código que usa listas de inicialização de struct, altere-o para usar os construtores recém-adicionados.  
  
 **Windows::Foundation**  
  
-   Ponto  
  
-   Rect  
  
-   Tamanho  
  
 **Windows::UI**  
  
-   Cor  
  
 **Windows::UI::Xaml**  
  
-   CornerRadius  
  
-   Duração  
  
-   GridLength  
  
-   Espessura  
  
 **Windows::UI::Xaml::Interop**  
  
1.  NomeDoTipo  
  
 **Windows::UI::Xaml::Media**  
  
-   Matriz  
  
 **Windows::UI::Xaml::Media::Animation**  
  
-   KeyTime  
  
-   RepeatBehavior  
  
 **Windows::UI::Xaml::Media::Media3D**  
  
-   Matrix3D  
  
## <a name="mapping-the-clr-to-ccx"></a>Mapeamento do CLR para C + + c++ /CX  
 Quando os compiladores do Visual C++ ou c# lê um arquivo. winmd, eles mapeiam automaticamente determinados tipos no arquivo de metadados apropriado C + + / tipos CX ou CLR. Por exemplo, no CLR, o IVector\<T > interface é mapeada para IList\<T >. Mas no C + + c++ /CLI CX, o IVector\<T > interface não está mapeado para outro tipo.  
  
 IReference\<T > no tempo de execução do Windows mapeia para Nullable\<T > no .NET.  
  
## <a name="see-also"></a>Consulte também  
 [Interoperando com outras linguagens](../cppcx/interoperating-with-other-languages-c-cx.md)