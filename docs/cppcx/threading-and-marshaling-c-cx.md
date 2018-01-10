---
title: Threading e Marshaling (C + + CX) | Microsoft Docs
ms.custom: 
ms.date: 12/30/2016
ms.prod: windows-client-threshold
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4451
helpviewer_keywords:
- threading issues, C++/CX
- agility, C++/CX
- C++/CX, threading issues
ms.assetid: 83e9ca1d-5107-4194-ae6f-e01bd928c614
caps.latest.revision: "17"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 74a00ece1e1853346b88c0340b32911618a9ff24
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="threading-and-marshaling-ccx"></a>Threading e marshaling (C++/CX)
Na grande maioria dos casos, as instâncias de classes de tempo de execução do Windows, como os objetos C++ padrão, podem ser acessadas de qualquer thread. Essas classes são chamadas de "agile". No entanto, um pequeno número de classes de tempo de execução do Windows que acompanham o Windows não é Agile e deve ser mais consumido como objetos COM que os objetos C++ padrão. Não é necessário ser um especialista em COM para usar classes não agile, mas é preciso levar em consideração o modelo de threading da classe e seu comportamento de marshaling. Este artigo fornece informações básicas e orientação para os cenários raros em que é necessário consumir uma instância de uma classe não agile.  
  
## <a name="threading-model-and-marshaling-behavior"></a>Modelo de threading e comportamento de marshaling  
 Uma classe de tempo de execução do Windows pode dar suporte a acesso de thread simultâneo de várias maneiras, conforme indicado pelos dois atributos aplicados a ela:  
  
-   O atributo`ThreadingModel` pode ter um dos valores —STA, MTA ou Both, conforme definido pela enumeração `ThreadingModel` .  
  
-   O atributo`MarshallingBehavior` pode ter um dos valores — Agile, None ou Standard, conforme definido pela enumeração `MarshallingType` .  
  
 O atributo `ThreadingModel` especifica onde a classe é carregada quando ativada: somente em um contexto de thread da interface de usuário (STA), somente em um contexto de thread de segundo plano (MTA) ou no contexto da thread que cria o objeto (Both). Os valores do atributo `MarshallingBehavior` fazem referência ao modo de comportamento do objeto em diversos contextos de threading. Na maioria dos casos, você não precisa entender esses valores detalhadamente.  Das classes fornecidas pela API do Windows, cerca de 90% têm `ThreadingModel`=Both e `MarshallingType`=Agile. Isso significa que podem manipular detalhes de threading de baixo nível de modo transparente e eficiente.   Quando você usa `ref new` para criar uma classe "agile", pode chamar métodos nela a partir do thread de aplicativo principal ou de um ou mais threads de trabalho.  Em outras palavras, você pode usar uma classe agile — quer ela tenha sido fornecida pelo Windows ou por um terceiro — de qualquer lugar no código. Você não tem que se preocupar com o modelo de threading ou o comportamento de marshaling da classe.  
  
## <a name="consuming-windows-runtime-components"></a>Consumindo componentes do Windows Runtime  
 Quando você cria um aplicativo de plataforma Universal do Windows, você pode interagir com componentes agile e não agile. Quando você interage com componentes não agile, pode receber o aviso a seguir.  
  
### <a name="compiler-warning-when-consuming-non-agile-classes-c4451"></a>Aviso do compilador durante o consumo de classes não agile (C4451)  
 Por várias razões, algumas classes não podem ser agile. Se você estiver acessando instâncias de classes não agile, tanto de um thread de interface de usuário quanto de um thread de segundo plano, tome ainda mais cuidado para verificar o comportamento correto em tempo de execução. O compilador do Visual C++ emite avisos quando você instancia uma classe de tempo de execução não agile no seu aplicativo no escopo global ou declare um tipo não agile como um membro da classe em uma classe ref que é marcada como agile.  
  
 Das classes não agile, a maneira mais fácil de lidar com isso são aqueles que têm `ThreadingModel`=Both e `MarshallingType`=Standard.  Você pode tornar essas classes agile usando simplesmente a classe auxiliar `Agile<T>` .   O exemplo a seguir mostra uma declaração de um objeto não agile do tipo `Windows::Security::Credentials::UI::CredentialPickerOptions^`e o aviso do compilador emitido em virtude disso.  
  
```  
  
ref class MyOptions  
    {  
    public:  
        property Windows::Security::Credentials::UI::CredentialPickerOptions^ Options  
  
        {  
            Windows::Security::Credentials::UI::CredentialPickerOptions^ get()   
            {  
                return _myOptions;  
            }  
        }  
    private:  
        Windows::Security::Credentials::UI::CredentialPickerOptions^ _myOptions;  
    };  
```  
  
 Aqui está o aviso que é emitido:  
  
> `Warning 1 warning C4451: 'Platform::Agile<T>::_object' : Usage of ref class 'Windows::Security::Credentials::UI::CredentialPickerOptions' inside this context can lead to invalid marshaling of object across contexts. Consider using 'Platform::Agile<Windows::Security::Credentials::UI::CredentialPickerOptions>' instead`  
  
 Quando você adiciona uma referência — no escopo do membro ou no escopo global — a um objeto que tem um comportamento marshaling de "Standard", o compilador emite um aviso que o aconselha a encapsular o tipo em `Platform::Agile<T>`: `Consider using 'Platform::Agile<Windows::Security::Credentials::UI::CredentialPickerOptions>' instead` Se você usar `Agile<T>`, poderá consumir a classe como qualquer outra classe agile. Use `Platform::Agile<T>` nessas circunstâncias:  
  
-   A variável não agile é declarada no escopo global.  
  
-   A variável não agile é declarada no escopo da classe e há uma possibilidade de o código de consumo ocultar o ponteiro — ou seja, usá-lo em um apartment diferente, sem o marshaling correto.  
  
 Caso nenhuma dessas condições se aplique, você poderá marcar a classe continente como não agile. Em outras palavras, você deve diretamente armazenar objetos não agile apenas em classes não agile e manter objetos não agile via Platform:: Agile\<T > em classes agile.  
  
 O exemplo a seguir mostra como você pode utilizar o `Agile<T>` para poder ignorar o aviso com segurança.  
  
```  
  
#include <agile.h>  
ref class MyOptions  
    {  
    public:  
        property Windows::Security::Credentials::UI::CredentialPickerOptions^ Options  
  
        {  
            Windows::Security::Credentials::UI::CredentialPickerOptions^ get()   
            {  
                return m_myOptions.Get();  
            }  
        }  
    private:  
        Platform::Agile<Windows::Security::Credentials::UI::CredentialPickerOptions^> m_myOptions;  
  
    };  
  
```  
  
 Observe que `Agile` não pode ser passado como um parâmetro ou um valor de retorno em uma classe ref. O método `Agile<T>::Get()` retorna um handle-to-object (^) que você pode passar na ABI (interface binária do aplicativo) em um método ou propriedade pública.  
  
 No Visual C++, quando você cria uma referência a uma classe de tempo de execução do Windows no processo que tem um comportamento marshaling de "None", o compilador emite o aviso C4451, mas não sugere que você considere o uso `Platform::Agile<T>`.  O compilador não pode oferecer nenhuma ajuda além desse aviso, portanto, é sua responsabilidade usar a classe corretamente e verificar se seu código chama componentes do STA somente do thread da interface do usuário e componentes MTA somente de um thread de segundo plano.  
  
## <a name="authoring-agile-windows-runtime-components"></a>Criação de componentes de tempo de execução do Windows agile  
 Quando você define uma classe ref no C + + CX, ela é agile por padrão — ou seja, tem `ThreadingModel`= Both e `MarshallingType`= Agile.  Se você estiver usando as [!INCLUDE[cppwrl](../cppcx/includes/cppwrl-md.md)], poderá tornar sua classe agile derivando de `FtmBase`, que usa o `FreeThreadedMarshaller`.  Se você criar uma classe que tenha `ThreadingModel`=Both ou `ThreadingModel`=MTA, verifique se a classe é thread-safe. Para obter mais informações, veja [Criar e consumir objetos (WRL)](http://msdn.microsoft.com/en-us/d5e42216-e888-4f1f-865a-b5ccd0def73e).  
  
 Você pode modificar o modelo de threading e o comportamento de marshaling de uma classe ref. No entanto, se você fizer alterações que tornem a classe não agile, deverá entender as implicações associadas a essas alterações.  
  
 O exemplo a seguir mostra como aplicar `MarshalingBehavior` e `ThreadingModel` atributos a uma classe de tempo de execução em uma biblioteca de classes de tempo de execução do Windows. Quando um aplicativo usa a DLL e a palavra-chave `ref new` para ativar um objeto de classe `MySTAClass` , o objeto é ativado em um single-threaded apartment e não oferece suporte para marshaling.  
  
```  
using namespace Windows::Foundation::Metadata;  
using namespace Platform;  
  
[Threading(ThreadingModel::STA)]  
[MarshalingBehavior(MarshalingType::None)]   
public ref class MySTAClass  
{  
};  
  
```  
 
 Uma classe não lacrada deve ter configurações de atributo marshaling e threading para que o compilador possa verificar se as classes derivadas têm o mesmo valor para esses atributos. Se a classe não tiver as configurações explicitamente definidas, o compilador gerará um erro e não compilará. Qualquer classe derivada de uma classe não lacrada gera um erro do compilador em qualquer um destes casos:  
  
-   Os atributos `ThreadingModel` e `MarshallingBehavior` não são definidos na classe derivada.  
  
-   Os valores dos atributos `ThreadingModel` e `MarshallingBehavior` na classe derivada não coincidem aos da classe base.  
  
 Threading e marshaling informações necessárias por um componente de tempo de execução do Windows de terceiros é especificado nas informações de registro de manifesto do aplicativo para o componente. Recomendamos que você torne todos os componentes de tempo de execução do Windows agile. Isso assegura que o código de cliente possa chamar seu componente de qualquer thread no aplicativo e aprimora o desempenho dessas chamadas, pois elas são chamadas diretas que não têm marshaling. Se você criar uma classe dessa maneira, o código de cliente não terá que usar `Platform::Agile<T>` para consumir sua classe.  
  
## <a name="see-also"></a>Consulte também  
 [ThreadingModel](http://msdn.microsoft.com/library/windows/apps/xaml/windows.foundation.metadata.threadingmodel.aspx)   
 [MarshallingBehavior](http://msdn.microsoft.com/library/windows/apps/xaml/windows.foundation.metadata.marshalingbehaviorattribute.aspx)