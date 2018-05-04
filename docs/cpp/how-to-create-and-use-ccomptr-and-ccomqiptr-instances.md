---
title: 'Como: criar e usar instâncias CComPtr e CComQIPtr | Microsoft Docs'
ms.custom: how-to
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: b0356cfb-12cc-4ee8-b988-8311ed1ab5e0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6c63eb1657cd00580197e0571a40e9a7545688dd
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="how-to-create-and-use-ccomptr-and-ccomqiptr-instances"></a>Como criar e usar instâncias CComPtr e CComQIPtr
Em programação clássica do Windows, bibliotecas geralmente são implementadas como objetos COM (ou mais precisamente, como servidores COM). Muitos componentes do sistema operacional Windows são implementados como servidores COM e muitos colaboradores fornecem bibliotecas neste formulário. Para obter informações sobre os conceitos básicos de COM, consulte [modelo COM (Component Object)](http://msdn.microsoft.com/en-us/3578ca42-a4b6-44b3-ad5b-aeb5fa61f3f4).  
  
 Quando você criar um objeto de modelo de objeto de componente (COM), armazenar o ponteiro de interface em um ponteiro inteligente COM, que realiza a referência de contagem por meio de chamadas para `AddRef` e `Release` no destruidor. Se você estiver usando a biblioteca de modelo ativa (ATL) ou o Microsoft Foundation Class Library (MFC), em seguida, use o `CComPtr` ponteiro inteligente. Se você não estiver usando a ATL ou do MFC, use `_com_ptr_t`. Porque não há nenhuma COM equivalente a `std::unique_ptr`, use esses ponteiros inteligentes para cenários de proprietário único e vários proprietário. Ambos `CComPtr` e `ComQIPtr` suporte mover operações que têm referências a rvalue.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como usar `CComPtr` para instanciar um objeto COM e obter ponteiros para suas interfaces. Observe que o `CComPtr::CoCreateInstance` função de membro é usada para criar o objeto COM, em vez da função do Win32 que tem o mesmo nome.  
  
 [!code-cpp[COM_smart_pointers#01](../cpp/codesnippet/CPP/how-to-create-and-use-ccomptr-and-ccomqiptr-instances_1.cpp)]  
  
 `CComPtr` e seus parentes fazem parte do ATL e são definidos em \<atlcomcli.h >. `_com_ptr_t` é declarada no \<comip.h >. O compilador cria especializações de `_com_ptr_t` quando ele gera classes de wrapper de bibliotecas de tipo.  
  
## <a name="example"></a>Exemplo  
 Também fornece ATL `CComQIPtr`, que tem uma sintaxe mais simples para consultar um objeto COM para recuperar uma interface adicional. No entanto, é recomendável `CComPtr` porque ele faz tudo que `CComQIPtr` pode fazer e é semanticamente mais consistente com ponteiros de interface COM bruto. Se você usar um `CComPtr` para consultar uma interface, o ponteiro de interface nova é colocado em um parâmetro de saída. Se a chamada falhar, será retornado um HRESULT que é o padrão comum de COM. Com `CComQIPtr`, o valor de retorno é o ponteiro em si, e se a chamada falhar, o valor de retorno HRESULT interno não pode ser acessado. Nas próximas duas linhas mostram como os mecanismos de tratamento de erros `CComPtr` e `CComQIPtr` são diferentes.  
  
 [!code-cpp[COM_smart_pointers#02](../cpp/codesnippet/CPP/how-to-create-and-use-ccomptr-and-ccomqiptr-instances_2.cpp)]  
  
## <a name="example"></a>Exemplo  
 `CComPtr` Fornece uma especialização de IDispatch que permite armazenar ponteiros para componentes de automação COM e chamar os métodos na interface por meio de associação tardia. `CComDispatchDriver` é um typedef para `CComQIPtr<IDispatch, &IIDIDispatch>`, que é implicitamente conversível em `CComPtr<IDispatch>`. Portanto, quando qualquer um desses três nomes aparece no código, é equivalente a `CComPtr<IDispatch>`. O exemplo a seguir mostra como obter um ponteiro para o modelo de objeto do Microsoft Word usando um `CComPtr<IDispatch>`.  
  
 [!code-cpp[COM_smart_pointers#03](../cpp/codesnippet/CPP/how-to-create-and-use-ccomptr-and-ccomqiptr-instances_3.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md)