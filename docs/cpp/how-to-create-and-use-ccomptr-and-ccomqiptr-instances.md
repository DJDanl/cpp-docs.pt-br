---
title: 'Como: criar e usar instâncias CComPtr e CComQIPtr'
ms.custom: how-to
ms.date: 11/19/2019
ms.topic: conceptual
ms.assetid: b0356cfb-12cc-4ee8-b988-8311ed1ab5e0
ms.openlocfilehash: e376eab75b9b1fb4a7a271d05fe037142f22e139
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246534"
---
# <a name="how-to-create-and-use-ccomptr-and-ccomqiptr-instances"></a>Como: criar e usar instâncias CComPtr e CComQIPtr

Na programação clássica do Windows, as bibliotecas geralmente são implementadas como objetos COM (ou mais precisamente, como servidores COM). Muitos componentes do sistema operacional Windows são implementados como servidores COM, e muitos colaboradores fornecem bibliotecas neste formulário. Para obter informações sobre os fundamentos do COM, consulte [Component Object Model (com)](/windows/win32/com/component-object-model--com--portal).

Quando você cria uma instância de um objeto de Component Object Model (COM), armazena o ponteiro de interface em um ponteiro inteligente COM, que executa a contagem de referência usando chamadas para `AddRef` e `Release` no destruidor. Se você estiver usando o Active Template Library (ATL) ou o biblioteca MFC (MFC), use o ponteiro inteligente do `CComPtr`. Se você não estiver usando o ATL ou o MFC, use `_com_ptr_t`. Como não há equivalente COM para `std::unique_ptr`, use esses ponteiros inteligentes para cenários de um único proprietário e de vários proprietários. `CComPtr` e `ComQIPtr` oferecem suporte a operações de movimentação que têm referências a rvalue.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar `CComPtr` para instanciar um objeto COM e obter ponteiros para suas interfaces. Observe que a função membro `CComPtr::CoCreateInstance` é usada para criar o objeto COM, em vez da função Win32 que tem o mesmo nome.

[!code-cpp[COM_smart_pointers#01](../cpp/codesnippet/CPP/how-to-create-and-use-ccomptr-and-ccomqiptr-instances_1.cpp)]

`CComPtr` e seus parentes fazem parte da ATL e são definidos em \<atlcomcli. h >. `_com_ptr_t` é declarado em \<comip. h >. O compilador cria especializações de `_com_ptr_t` quando ele gera classes de wrapper para bibliotecas de tipos.

## <a name="example"></a>Exemplo

A ATL também fornece `CComQIPtr`, que tem uma sintaxe mais simples para consultar um objeto COM para recuperar uma interface adicional. No entanto, é recomendável `CComPtr` porque faz tudo o que `CComQIPtr` pode fazer e é semanticamente mais consistente com ponteiros de interface COM brutos. Se você usar um `CComPtr` para consultar uma interface, o novo ponteiro de interface será colocado em um parâmetro out. Se a chamada falhar, um HRESULT será retornado, que é o padrão COM típico. Com `CComQIPtr`, o valor de retorno é o próprio ponteiro e, se a chamada falhar, o valor de retorno HRESULT interno não poderá ser acessado. As duas linhas a seguir mostram como os mecanismos de tratamento de erros no `CComPtr` e `CComQIPtr` são diferentes.

[!code-cpp[COM_smart_pointers#02](../cpp/codesnippet/CPP/how-to-create-and-use-ccomptr-and-ccomqiptr-instances_2.cpp)]

## <a name="example"></a>Exemplo

`CComPtr` fornece uma especialização para IDispatch que permite armazenar ponteiros para componentes de automação COM e invocar os métodos na interface usando a associação tardia. `CComDispatchDriver` é um typedef para `CComQIPtr<IDispatch, &IIDIDispatch>`, que é implicitamente conversível para `CComPtr<IDispatch>`. Portanto, quando qualquer um desses três nomes aparece no código, ele é equivalente a `CComPtr<IDispatch>`. O exemplo a seguir mostra como obter um ponteiro para o modelo de objeto do Microsoft Word usando um `CComPtr<IDispatch>`.

[!code-cpp[COM_smart_pointers#03](../cpp/codesnippet/CPP/how-to-create-and-use-ccomptr-and-ccomqiptr-instances_3.cpp)]

## <a name="see-also"></a>Consulte também

[Ponteiros inteligentes (C++ moderno)](../cpp/smart-pointers-modern-cpp.md)
